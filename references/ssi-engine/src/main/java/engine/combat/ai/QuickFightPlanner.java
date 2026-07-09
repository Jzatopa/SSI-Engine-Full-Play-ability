package engine.combat.ai;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.OptionalInt;

/**
 * Quick-fight (auto-combat) decision flow: given a read-only view of the
 * battle, produce the acting combatant's next {@link QuickFightIntent}. The
 * planner never executes anything.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr010.cs {@code PlayerQuickFight} (sub_3504B) and the decision
 * helpers it calls: {@code FleeCheck_001} (sub_3637F), {@code sub_354AA}
 * (charged-item scan), {@code turn_undead}, {@code sub_3560B} (known-spell
 * scan), {@code sub_35DB1} (target/attack loop), {@code moralFailureEscape}
 * (sub_359D1), {@code TryGuarding} (sub_361F7); plus engine/ovr014.cs
 * {@code find_target} (sub_41E44), {@code FindLowestE9Target} (sub_3F433),
 * {@code calc_enemy_health_percentage} (sub_40E00), {@code MaxOppositionMoves}
 * (sub_40E8F) and the {@code flee_battle} escape decision. Checks are kept in
 * COAB's order; what COAB performs inline becomes an intent here and the
 * executor is expected to call {@link #plan} again while the turn has delay
 * and movement left, mirroring COAB's own re-looping.</p>
 *
 * <p>Target memory: COAB persists {@code actions.target} on the combatant;
 * this planner keeps the equivalent per-actor map internally, so one planner
 * instance should live for the duration of one combat.</p>
 *
 * <p>Deviations, labeled per the reuse policy:</p>
 * <ul>
 * <li>Keyboard handling ({@code process_input_in_monsters_turn}) and all
 * display calls are UI, not ported.</li>
 * <li>The {@code actions.field_15} sway-pattern re-roll and the
 * {@code data_2B8}/{@code CanMove} direction stepping are movement execution;
 * the planner emits {@link QuickFightIntent.Kind#MOVE_TOWARD}/
 * {@link QuickFightIntent.Kind#FLEE} and leaves stepping (including
 * {@code flee_battle} when panic reaches clear ground — see
 * {@link #assessFleeEscape}) to the executor.</li>
 * <li>{@code AI_items_selection} (sub_36673) weapon re-readying before the
 * attack loop is deferred; only the explicit mid-loop branch that COAB stops
 * on (ranged weapon with an adjacent enemy) is surfaced, as
 * {@link QuickFightIntent.Kind#SWITCH_WEAPON}.</li>
 * <li>{@code ovr024.CheckAffectsEffect} morale/affect hooks inside
 * {@code FleeCheck_001} and {@code sub_35DB1} are skipped until the affect
 * system lands.</li>
 * <li>{@code ovr014.can_attack_target} (sub_40F1F): for a quick-fighting
 * combatant COAB short-circuits to true (the interactive "Attack Ally"
 * confirmation only runs when {@code quick_fight != True}), so target
 * eligibility here is exactly the opposing-team filter of
 * {@code BuildNearTargets}.</li>
 * <li>Attack resolution ({@code AttackTarget}, {@code TrySweepAttack},
 * {@code RecalcAttacksReceived}, ammo bookkeeping) belongs to the attack
 * track; the planner stops at {@link QuickFightIntent.Kind#ATTACK}.</li>
 * </ul>
 */
public final class QuickFightPlanner {
	/** COAB {@code sub_35DB1} gives up after 20 loop iterations and guards. */
	static final int ATTACK_LOOP_LIMIT = 20;

	/** COAB {@code ovr014.flee_battle} escape decision. */
	public enum FleeOutcome {
		/** {@code RemoveFromCombat("Got Away", running)}. */
		ESCAPES,
		/** "Escape is blocked". */
		BLOCKED
	}

	private final QuickFightBattleView view;
	private final DiceRoller dice;
	private final SpellcastJudge spellcastJudge;
	private final Map<Integer, Integer> rememberedTargetIds = new HashMap<>();

	public QuickFightPlanner(QuickFightBattleView view, DiceRoller dice) {
		this(view, dice, SpellcastJudge.NONE);
	}

	public QuickFightPlanner(QuickFightBattleView view, DiceRoller dice, SpellcastJudge spellcastJudge) {
		this.view = view;
		this.dice = dice;
		this.spellcastJudge = spellcastJudge;
	}

	/**
	 * COAB {@code ovr010.PlayerQuickFight} (sub_3504B), one decision per call,
	 * checks in the original order: out-of-combat bail-out, morale
	 * ({@code FleeCheck_001} — may surrender), charged items
	 * ({@code sub_354AA}), the queued spell, turning undead, spell selection
	 * ({@code sub_3560B}), then the target/attack loop ({@code find_target} +
	 * {@code sub_35DB1}) with {@code TryGuarding} as the fallback.
	 */
	public QuickFightIntent plan(QuickFightCombatantView self) {
		if (!self.inCombat()) {
			// PlayerQuickFight: in_combat == false -> clear_actions and done.
			return QuickFightIntent.endTurn();
		}

		MoraleCheck morale = fleeCheck(self);
		if (morale.surrendered) {
			return QuickFightIntent.surrender();
		}

		OptionalInt itemSpell = chooseItemSpell(self);
		if (itemSpell.isPresent()) {
			return QuickFightIntent.useItemSpell(itemSpell.getAsInt());
		}

		if (self.queuedSpellId() > 0) {
			return QuickFightIntent.castQueuedSpell(self.queuedSpellId());
		}

		Optional<QuickFightCombatantView> undead = turnUndeadTarget(self);
		if (undead.isPresent()) {
			return QuickFightIntent.turnUndead(undead.get());
		}

		OptionalInt spell = chooseSpell(self);
		if (spell.isPresent()) {
			return QuickFightIntent.castSpell(spell.getAsInt());
		}

		// PlayerQuickFight tail loop: find_target(false, 1, 0xff) then sub_35DB1,
		// else TryGuarding.
		if (findTarget(self, false, true, 0xFF) && self.delayLeft() > 0 && self.inCombat()) {
			return attackLoopIntent(self, morale);
		}
		return tryGuarding(self);
	}

	/** Remembered target id for an actor (COAB {@code actions.target}), for tests and integration. */
	public Optional<Integer> rememberedTargetId(int actorId) {
		return Optional.ofNullable(rememberedTargetIds.get(actorId));
	}

	/**
	 * COAB {@code ovr014.flee_battle} escape decision (the executor calls this
	 * when a {@link QuickFightIntent.Kind#FLEE} panic run reaches clear
	 * ground): free escape when no enemy remains within 255 squares; otherwise
	 * escape when the fastest opponent's half-move is less than the runner's,
	 * a 1d2 == 1 coin flip on a tie, else blocked.
	 */
	public FleeOutcome assessFleeEscape(QuickFightCombatantView self) {
		if (view.enemiesWithin(self, 0xFF, false).isEmpty()) {
			return FleeOutcome.ESCAPES;
		}
		int ownHalfMoves = self.movementPoints() / 2;
		int oppositionHalfMoves = maxOppositionMoves(self);
		if (oppositionHalfMoves < ownHalfMoves) {
			return FleeOutcome.ESCAPES;
		}
		if (oppositionHalfMoves == ownHalfMoves && dice.roll(2) == 1) {
			return FleeOutcome.ESCAPES;
		}
		return FleeOutcome.BLOCKED;
	}

	private static final class MoraleCheck {
		boolean moralFailure;
		boolean surrendered;
		/** COAB {@code gbl.monster_morale} as last assigned by FleeCheck_001 (0 when untouched). */
		int monsterMorale;
	}

	/**
	 * COAB {@code ovr010.FleeCheck_001} (sub_3637F). Forced fleeing always
	 * fails morale. An AI-controlled combatant doubles its morale score
	 * (clamped to 0 above 102), fails the personal check when that is below
	 * its own lost-health percentage (or zero), then re-checks against the
	 * enemy team's health versus the encounter's base morale; a cornered
	 * combatant (opposition at most half as fast) breaks, a smart one
	 * (Int > 5) surrenders instead. Deviation, labeled: the two
	 * {@code CheckAffectsEffect(Morale)} hook calls are skipped until the
	 * affect system lands; {@code RemoveAttackersAffects} is execution and is
	 * left to the executor.
	 */
	private MoraleCheck fleeCheck(QuickFightCombatantView self) {
		MoraleCheck result = new MoraleCheck();
		if (self.forcedFleeing()) {
			result.moralFailure = true;
			return result;
		}
		if (!self.npcControlled()) {
			return result;
		}
		int monsterMorale = self.moraleScore() << 1;
		if (monsterMorale > 102) {
			monsterMorale = 0;
		}
		int lostHealthPercent = 100 - ((self.hitPointsCurrent() * 100) / self.hitPointsMax());
		if (monsterMorale < lostHealthPercent || monsterMorale == 0) {
			monsterMorale = enemyTeamHealthPercentage();
			if (monsterMorale < (100 - view.battleBaseMorale()) || monsterMorale == 0
				|| self.team() == QuickFightTeam.OURS) {

				if (maxOppositionMoves(self) <= self.movementPoints() / 2) {
					result.moralFailure = true;
				} else if (self.intelligence() > 5) {
					result.surrendered = true;
				}
			}
		}
		result.monsterMorale = monsterMorale;
		return result;
	}

	/**
	 * COAB {@code ovr014.calc_enemy_health_percentage} (sub_40E00): the enemy
	 * team's remaining health as {@code ((20 * current) / max) * 5}, counting
	 * out-of-combat enemies' maximums but not their current points. Both
	 * sides' morale reads this same enemy-team number, as in COAB. Deviation,
	 * labeled: COAB keeps the previous global when the enemy team has no hit
	 * points at all; this port returns 100 in that degenerate case.
	 */
	private int enemyTeamHealthPercentage() {
		int maxTotal = 0;
		int currentTotal = 0;
		for (QuickFightCombatantView combatant : view.combatants()) {
			if (combatant.team() == QuickFightTeam.ENEMY) {
				if (combatant.inCombat()) {
					currentTotal += combatant.hitPointsCurrent();
				}
				maxTotal += combatant.hitPointsMax();
			}
		}
		if (maxTotal <= 0) {
			return 100;
		}
		return ((20 * currentTotal) / maxTotal) * 5;
	}

	/**
	 * COAB {@code ovr014.MaxOppositionMoves} (sub_40E8F): the largest
	 * half-move among opposing combatants still in combat.
	 */
	private int maxOppositionMoves(QuickFightCombatantView self) {
		int maxMoves = 0;
		for (QuickFightCombatantView combatant : view.combatants()) {
			if (combatant.team() == self.team().opposite() && combatant.inCombat()) {
				maxMoves = Math.max(combatant.movementPoints() / 2, maxMoves);
			}
		}
		return maxMoves;
	}

	/**
	 * COAB {@code ovr010.sub_354AA}: the charged-item (wand) scan. Gated on
	 * {@code can_use}, surviving enemies, and — quirk preserved — an area
	 * where spellcasting is forbidden. Rolls 1d7 for how many priorities to
	 * try, walks priorities downward from 7, and per priority takes the first
	 * readied item spell the {@link SpellcastJudge} accepts; a hit at a lower
	 * priority overwrites an earlier one exactly as COAB's loop does.
	 */
	private OptionalInt chooseItemSpell(QuickFightCombatantView self) {
		if (!self.canUseItems() || !opposingTeamRemains(self) || !view.areaForbidsSpells()) {
			return OptionalInt.empty();
		}
		OptionalInt best = OptionalInt.empty();
		int prioritiesToTry = dice.roll(7);
		for (int i = 0; i < prioritiesToTry; i++) {
			int priority = 7 - i;
			for (int spellId : self.readiedItemSpellIds()) {
				if (spellId > 0 && spellcastJudge.shouldCast(priority, spellId, self)) {
					best = OptionalInt.of(spellId);
					break;
				}
			}
		}
		return best;
	}

	/** COAB {@code teamCount} reads in sub_354AA/sub_3560B: any opposing combatant left. */
	private boolean opposingTeamRemains(QuickFightCombatantView self) {
		for (QuickFightCombatantView combatant : view.combatants()) {
			if (combatant.team() == self.team().opposite() && combatant.inCombat()) {
				return true;
			}
		}
		return false;
	}

	/**
	 * COAB {@code ovr010.turn_undead} gate plus {@code ovr014.FindLowestE9Target}
	 * (sub_3F433): one attempt per combat, class-gated (flavor hook), against
	 * the non-fleeing opposing combatant with the lowest positive turning rank
	 * below 13 within 255 squares. Ties keep the first (nearest-first) find,
	 * matching COAB's strict {@code <} scan. The turning-table resolution in
	 * {@code ovr014.turns_undead} is rules math and stays with the executor.
	 */
	private Optional<QuickFightCombatantView> turnUndeadTarget(QuickFightCombatantView self) {
		if (self.hasTurnedUndead() || !self.canTurnUndead()) {
			return Optional.empty();
		}
		QuickFightCombatantView lowest = null;
		int minRank = 13;
		for (QuickFightCombatantView target : view.enemiesWithin(self, 0xFF, false)) {
			if (!target.forcedFleeing() && target.undeadRank() > 0 && target.undeadRank() < minRank) {
				minRank = target.undeadRank();
				lowest = target;
			}
		}
		return Optional.ofNullable(lowest);
	}

	/**
	 * COAB {@code ovr010.sub_3560B}: the known-spell scan. Gated on a
	 * non-empty castable list and either AI control or the
	 * {@code AutoPCsCastMagic} toggle, plus surviving enemies. Rolls 1d7 for
	 * the number of priority passes; each pass makes up to three random picks
	 * from the learnt list and keeps the first the {@link SpellcastJudge}
	 * accepts at the current minimum priority, which starts at 7 and drops per
	 * pass.
	 */
	private OptionalInt chooseSpell(QuickFightCombatantView self) {
		int[] spells = self.canCastSpells() ? self.learntSpellIds() : new int[0];
		if (spells.length == 0 || !(self.npcControlled() || view.autoPartyCastsMagic())
			|| !opposingTeamRemains(self)) {

			return OptionalInt.empty();
		}
		int spellId = 0;
		int priority = 7;
		int passes = dice.roll(7);
		for (int pass = 1; pass <= passes && spellId == 0; pass++) {
			for (int attempt = 1; attempt < 4 && spellId == 0; attempt++) {
				int candidate = spells[dice.roll(spells.length) - 1];
				if (spellcastJudge.shouldCast(priority, candidate, self)) {
					spellId = candidate;
				}
			}
			priority--;
		}
		return spellId > 0 ? OptionalInt.of(spellId) : OptionalInt.empty();
	}

	/**
	 * COAB {@code ovr014.find_target} (sub_41E44). Keeps the remembered
	 * target when it is still an opposing, in-combat, visible combatant.
	 * Otherwise scans in up to two passes — the second with walls ignored —
	 * making at most 20 random picks from the near-target list per pass; a
	 * pick is accepted if visible, or without a visibility check on the
	 * wall-ignoring pass when {@code acceptThroughWalls} (COAB
	 * {@code arg_2 != 0}) is set. {@code clearTarget} drops the remembered
	 * target first and, as in COAB, suppresses the wall-ignoring second pass.
	 */
	private boolean findTarget(QuickFightCombatantView self, boolean clearTarget, boolean acceptThroughWalls,
		int maxRange) {

		QuickFightCombatantView target = rememberedTarget(self);
		if (clearTarget
			|| (target != null && (target.team() == self.team() || !target.inCombat() || !view.canSee(self, target)))) {
			rememberedTargetIds.remove(self.id());
			target = null;
		}
		if (target != null) {
			return true;
		}

		boolean found = false;
		boolean ignoreWalls = false;
		for (int pass = 1; pass <= 2 && !found; pass++) {
			if (pass == 2) {
				if (clearTarget) {
					break;
				}
				ignoreWalls = true;
			}
			int tryCount = ATTACK_LOOP_LIMIT;
			List<QuickFightCombatantView> nearTargets = new ArrayList<>(view.enemiesWithin(self, maxRange, ignoreWalls));
			while (tryCount > 0 && !found && !nearTargets.isEmpty()) {
				tryCount--;
				QuickFightCombatantView candidate = nearTargets.get(dice.roll(nearTargets.size()) - 1);
				if ((acceptThroughWalls && ignoreWalls) || view.canSee(self, candidate)) {
					found = true;
					rememberedTargetIds.put(self.id(), candidate.id());
				} else {
					nearTargets.remove(candidate);
				}
			}
		}
		return found;
	}

	private QuickFightCombatantView rememberedTarget(QuickFightCombatantView self) {
		Integer targetId = rememberedTargetIds.get(self.id());
		if (targetId == null) {
			return null;
		}
		for (QuickFightCombatantView combatant : view.combatants()) {
			if (combatant.id() == targetId) {
				return combatant;
			}
		}
		rememberedTargetIds.remove(self.id());
		return null;
	}

	/**
	 * COAB {@code ovr010.sub_35DB1}, reshaped from an execute-until-done loop
	 * into a single next intent: bandage a dying teammate first (party side),
	 * run from a failed morale check while moves remain and the turn is a
	 * normal one (delay strictly between 0 and 20), attack the remembered
	 * target when it is visible and reachable within weapon range, otherwise
	 * work the near-target list — switching weapons when a ranged (non-melee)
	 * weapon faces an adjacent enemy, attacking an adjacent or visible pick,
	 * advancing on a re-acquired distant target, or guarding when nothing is
	 * available. The pick-retry churn keeps COAB's 20-iteration cap.
	 */
	private QuickFightIntent attackLoopIntent(QuickFightCombatantView self, MoraleCheck morale) {
		if (self.team() == QuickFightTeam.OURS && view.anyPartyTeammateDying()) {
			return QuickFightIntent.bandage();
		}
		if (morale.moralFailure && self.movePointsLeft() > 0 && self.delayLeft() > 0 && self.delayLeft() < 20) {
			return moveOrFleeIntent(self, morale);
		}

		int range = weaponRange(self);

		for (int counter = 1; counter <= ATTACK_LOOP_LIMIT; counter++) {
			QuickFightCombatantView target = rememberedTarget(self);
			if (target != null && (!target.inCombat() || target.team() == QuickFightTeam.OURS)) {
				target = null;
			}
			if (target != null && view.canSee(self, target)) {
				OptionalInt steps = view.pathStepsTo(self, target);
				if (steps.isPresent() && steps.getAsInt() / 2 <= range) {
					return QuickFightIntent.attack(target);
				}
			}

			List<QuickFightCombatantView> nearTargets = view.enemiesWithin(self, range, false);
			if (nearTargets.isEmpty()) {
				if (findTarget(self, false, false, 0xFF)) {
					return moveOrFleeIntent(self, morale);
				}
				return tryGuarding(self);
			}

			QuickFightCombatantView pick = nearTargets.get(dice.roll(nearTargets.size()) - 1);
			if (self.hasRangedWeapon() && !self.hasRangedMeleeWeapon()
				&& !view.enemiesWithin(self, 1, false).isEmpty()) {

				return QuickFightIntent.switchWeapon();
			}
			if (view.distanceTo(self, pick) == 1 || view.canSee(self, pick)) {
				rememberedTargetIds.put(self.id(), pick.id());
				return QuickFightIntent.attack(pick);
			}
			// No usable pick this iteration; COAB's loop rolls again, up to 20 times.
		}
		return tryGuarding(self);
	}

	/**
	 * COAB {@code sub_35DB1} weapon-range setup: item-table range minus one,
	 * clamped back to 1 when unarmed or degenerate (0, 0xFF or -1).
	 */
	private int weaponRange(QuickFightCombatantView self) {
		int range = self.primaryWeaponRawRange() - 1;
		if (range == 0 || range == 0xFF || range == -1) {
			range = 1;
		}
		return range;
	}

	/**
	 * COAB {@code ovr010.moralFailureEscape} (sub_359D1), the movement gate
	 * and direction choice only: needs half a move and remaining delay; an
	 * AI-controlled combatant on the party's side also needs the enemy team's
	 * health at or below 1d100 + the morale carried out of
	 * {@code FleeCheck_001} (enemy-side combatants always pass); an unarmored
	 * fragile caster that has not failed morale stands and guards. A failed
	 * morale check runs for the map edge ({@link QuickFightIntent.Kind#FLEE});
	 * otherwise the combatant advances on the remembered target
	 * ({@code getTargetDirection} step). The {@code data_2B8} sway stepping,
	 * stuck-direction bookkeeping ({@code byte_1AB18/19}) and poison-cloud
	 * costs are movement execution, left to the executor.
	 */
	private QuickFightIntent moveOrFleeIntent(QuickFightCombatantView self, MoraleCheck morale) {
		if (!(self.movePointsLeft() / 2 > 0 && self.delayLeft() > 0)) {
			return tryGuarding(self);
		}
		boolean moraleGate = !self.npcControlled()
			|| enemyTeamHealthPercentage() <= dice.roll(100) + morale.monsterMorale
			|| self.team() == QuickFightTeam.ENEMY;
		if (!moraleGate) {
			return tryGuarding(self);
		}
		if (!(morale.moralFailure || self.wearsArmor() || !self.fragileCaster())) {
			return tryGuarding(self);
		}
		if (morale.moralFailure) {
			return QuickFightIntent.flee();
		}
		QuickFightCombatantView target = rememberedTarget(self);
		if (target == null) {
			// Defensive: COAB only reaches here with a target set; treat as guard.
			return tryGuarding(self);
		}
		return QuickFightIntent.moveToward(target);
	}

	/**
	 * COAB {@code ovr010.TryGuarding} (sub_361F7): a held combatant, a ranged
	 * attacker or a spent turn just clears the action; anyone else guards.
	 */
	private QuickFightIntent tryGuarding(QuickFightCombatantView self) {
		if (self.held() || self.hasRangedWeapon() || self.delayLeft() == 0) {
			return QuickFightIntent.endTurn();
		}
		return QuickFightIntent.guard();
	}
}
