package engine.combat.ai;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Deque;
import java.util.List;
import java.util.OptionalInt;

import org.junit.Test;

/**
 * Pins {@link QuickFightPlanner} to the COAB decision branches it ports
 * (https://github.com/simeonpilgrim/coab, commit 9dc46f1). Each test names
 * the engine/ovr010.cs or engine/ovr014.cs branch it exercises. Dice are a
 * scripted queue (default roll 1) and geometry is stubbed per enemy, so every
 * test is deterministic.
 */
public class QuickFightPlannerTest {

	/** Scripted dice: pops the queue, defaulting to 1, capped at {@code sides}. */
	private static final class ScriptedDice implements DiceRoller {
		private final Deque<Integer> rolls = new ArrayDeque<>();

		ScriptedDice(int... scripted) {
			for (int roll : scripted) {
				rolls.add(roll);
			}
		}

		@Override
		public int roll(int sides) {
			int roll = rolls.isEmpty() ? 1 : rolls.poll();
			return Math.min(roll, sides);
		}
	}

	private static final class StubCombatant implements QuickFightCombatantView {
		final int id;
		QuickFightTeam team;
		boolean inCombat = true;
		int hitPointsCurrent = 10;
		int hitPointsMax = 10;
		int movementPoints = 6;
		int movePointsLeft = 6;
		int delayLeft = 5;
		boolean forcedFleeing;
		boolean held;
		int intelligence = 10;
		boolean npcControlled;
		int moraleScore;
		boolean wearsArmor;
		boolean fragileCaster;
		boolean canTurnUndead;
		boolean hasTurnedUndead;
		int undeadRank;
		int queuedSpellId;
		boolean canCastSpells;
		boolean canUseItems;
		boolean hasRangedWeapon;
		boolean hasRangedMeleeWeapon;
		int primaryWeaponRawRange;
		int[] learntSpellIds = new int[0];
		int[] readiedItemSpellIds = new int[0];
		/** Squares from the acting combatant, walls respected; null = unreachable. */
		Integer distWalls;
		/** Squares from the acting combatant, walls ignored; null = unreachable. */
		Integer distNoWalls;
		boolean visible = true;

		StubCombatant(int id, QuickFightTeam team) {
			this.id = id;
			this.team = team;
		}

		StubCombatant at(int walkDistance) {
			this.distWalls = walkDistance;
			this.distNoWalls = walkDistance;
			return this;
		}

		@Override
		public int id() {
			return id;
		}

		@Override
		public boolean inCombat() {
			return inCombat;
		}

		@Override
		public QuickFightTeam team() {
			return team;
		}

		@Override
		public int hitPointsCurrent() {
			return hitPointsCurrent;
		}

		@Override
		public int hitPointsMax() {
			return hitPointsMax;
		}

		@Override
		public int movementPoints() {
			return movementPoints;
		}

		@Override
		public int movePointsLeft() {
			return movePointsLeft;
		}

		@Override
		public int delayLeft() {
			return delayLeft;
		}

		@Override
		public boolean forcedFleeing() {
			return forcedFleeing;
		}

		@Override
		public boolean held() {
			return held;
		}

		@Override
		public int intelligence() {
			return intelligence;
		}

		@Override
		public boolean npcControlled() {
			return npcControlled;
		}

		@Override
		public int moraleScore() {
			return moraleScore;
		}

		@Override
		public boolean wearsArmor() {
			return wearsArmor;
		}

		@Override
		public boolean fragileCaster() {
			return fragileCaster;
		}

		@Override
		public boolean canTurnUndead() {
			return canTurnUndead;
		}

		@Override
		public boolean hasTurnedUndead() {
			return hasTurnedUndead;
		}

		@Override
		public int undeadRank() {
			return undeadRank;
		}

		@Override
		public int queuedSpellId() {
			return queuedSpellId;
		}

		@Override
		public boolean canCastSpells() {
			return canCastSpells;
		}

		@Override
		public boolean canUseItems() {
			return canUseItems;
		}

		@Override
		public boolean hasRangedWeapon() {
			return hasRangedWeapon;
		}

		@Override
		public boolean hasRangedMeleeWeapon() {
			return hasRangedMeleeWeapon;
		}

		@Override
		public int primaryWeaponRawRange() {
			return primaryWeaponRawRange;
		}

		@Override
		public int[] learntSpellIds() {
			return learntSpellIds;
		}

		@Override
		public int[] readiedItemSpellIds() {
			return readiedItemSpellIds;
		}
	}

	private static final class StubBattle implements QuickFightBattleView {
		final List<QuickFightCombatantView> combatants = new ArrayList<>();
		int battleBaseMorale;
		boolean areaForbidsSpells;
		boolean autoPartyCastsMagic;
		boolean anyPartyTeammateDying;

		StubBattle(StubCombatant... all) {
			for (StubCombatant combatant : all) {
				combatants.add(combatant);
			}
		}

		@Override
		public List<QuickFightCombatantView> combatants() {
			return combatants;
		}

		@Override
		public boolean canSee(QuickFightCombatantView self, QuickFightCombatantView target) {
			return target == self || ((StubCombatant) target).visible;
		}

		@Override
		public List<QuickFightCombatantView> enemiesWithin(QuickFightCombatantView self, int maxRange,
			boolean ignoreWalls) {

			List<StubCombatant> near = new ArrayList<>();
			for (QuickFightCombatantView combatant : combatants) {
				StubCombatant stub = (StubCombatant) combatant;
				Integer distance = ignoreWalls ? stub.distNoWalls : stub.distWalls;
				if (stub.team != self.team() && stub.inCombat && distance != null && distance <= maxRange) {
					near.add(stub);
				}
			}
			near.sort(Comparator
				.comparingInt((StubCombatant stub) -> ignoreWalls ? stub.distNoWalls : stub.distWalls)
				.thenComparingInt(stub -> stub.id));
			return new ArrayList<>(near);
		}

		@Override
		public OptionalInt pathStepsTo(QuickFightCombatantView self, QuickFightCombatantView target) {
			Integer distance = ((StubCombatant) target).distWalls;
			return distance == null ? OptionalInt.empty() : OptionalInt.of(distance * 2);
		}

		@Override
		public int distanceTo(QuickFightCombatantView self, QuickFightCombatantView target) {
			Integer distance = ((StubCombatant) target).distNoWalls;
			return distance == null ? QuickFightCombatantView.UNREACHABLE : distance;
		}

		@Override
		public int battleBaseMorale() {
			return battleBaseMorale;
		}

		@Override
		public boolean areaForbidsSpells() {
			return areaForbidsSpells;
		}

		@Override
		public boolean autoPartyCastsMagic() {
			return autoPartyCastsMagic;
		}

		@Override
		public boolean anyPartyTeammateDying() {
			return anyPartyTeammateDying;
		}
	}

	private static StubCombatant meleePc(int id) {
		return new StubCombatant(id, QuickFightTeam.OURS);
	}

	private static StubCombatant enemy(int id, int distance) {
		return new StubCombatant(id, QuickFightTeam.ENEMY).at(distance);
	}

	// --- PlayerQuickFight top-level branches (ovr010.cs sub_3504B) ---

	/** Pins PlayerQuickFight's {@code in_combat == false} bail-out (clear_actions, done). */
	@Test
	public void outOfCombatActorEndsTurn() {
		StubCombatant self = meleePc(1);
		self.inCombat = false;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, enemy(2, 1)), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.END_TURN, planner.plan(self).kind());
	}

	/** Pins the sub_35DB1 attack dispatch: remembered target visible and reachable within weapon range. */
	@Test
	public void attacksAdjacentVisibleEnemy() {
		StubCombatant self = meleePc(1);
		StubCombatant foe = enemy(2, 1);
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, foe), new ScriptedDice());

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.ATTACK, intent.kind());
		assertEquals(2, intent.target().orElseThrow().id());
	}

	/** Pins find_target's (sub_41E44) keep-remembered-target branch: a valid target survives new dice. */
	@Test
	public void keepsRememberedTargetWhileValid() {
		StubCombatant self = meleePc(1);
		StubCombatant near = enemy(2, 1);
		StubCombatant alsoNear = enemy(3, 1);
		StubBattle battle = new StubBattle(self, near, alsoNear);
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice(2));

		assertEquals(3, planner.plan(self).target().orElseThrow().id());
		// Dice now default to 1 (would pick id 2), but actions.target is kept.
		assertEquals(3, planner.plan(self).target().orElseThrow().id());
		assertEquals(Integer.valueOf(3), planner.rememberedTargetId(1).orElseThrow());
	}

	/** Pins find_target's invalidation branch: an out-of-combat target is dropped and replaced. */
	@Test
	public void dropsRememberedTargetWhenTargetLeavesCombat() {
		StubCombatant self = meleePc(1);
		StubCombatant near = enemy(2, 1);
		StubCombatant alsoNear = enemy(3, 1);
		StubBattle battle = new StubBattle(self, near, alsoNear);
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice(2));

		assertEquals(3, planner.plan(self).target().orElseThrow().id());
		alsoNear.inCombat = false;

		assertEquals(2, planner.plan(self).target().orElseThrow().id());
	}

	// --- sub_35DB1 movement / fallback branches ---

	/**
	 * Pins sub_35DB1's empty-near-target branch: find_target(0, 0xff) re-acquires
	 * the distant enemy and moralFailureEscape advances on it.
	 */
	@Test
	public void advancesOnDistantVisibleEnemy() {
		StubCombatant self = meleePc(1);
		StubCombatant far = enemy(2, 5);
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, far), new ScriptedDice());

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.MOVE_TOWARD, intent.kind());
		assertEquals(2, intent.target().orElseThrow().id());
	}

	/**
	 * Pins moralFailureEscape's (sub_359D1) fragile-caster condition: an unarmored
	 * magic-user that has not failed morale guards instead of closing in.
	 */
	@Test
	public void fragileCasterStandsAndGuardsInsteadOfClosing() {
		StubCombatant self = meleePc(1);
		self.fragileCaster = true;
		self.wearsArmor = false;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, enemy(2, 5)), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.GUARD, planner.plan(self).kind());
	}

	/** Pins PlayerQuickFight's else-branch into TryGuarding (sub_361F7) guarding path. */
	@Test
	public void guardsWhenNoEnemies() {
		StubCombatant self = meleePc(1);
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.GUARD, planner.plan(self).kind());
	}

	/** Pins TryGuarding's ranged-weapon condition: clear the action instead of guarding. */
	@Test
	public void rangedAttackerEndsTurnInsteadOfGuarding() {
		StubCombatant self = meleePc(1);
		self.hasRangedWeapon = true;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.END_TURN, planner.plan(self).kind());
	}

	/** Pins TryGuarding's IsHeld condition. */
	@Test
	public void heldActorEndsTurn() {
		StubCombatant self = meleePc(1);
		self.held = true;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.END_TURN, planner.plan(self).kind());
	}

	// --- FleeCheck_001 (sub_3637F) morale branches ---

	/** Pins FleeCheck_001's forced-fleeing branch feeding moralFailureEscape's panic run. */
	@Test
	public void forcedFleeingActorPanics() {
		StubCombatant self = meleePc(1);
		self.forcedFleeing = true;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, enemy(2, 1)), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.FLEE, planner.plan(self).kind());
	}

	private static StubCombatant woundedNpcMonster() {
		StubCombatant self = new StubCombatant(1, QuickFightTeam.ENEMY).at(0);
		self.npcControlled = true;
		self.moraleScore = 0; // morale 0 always fails the personal check
		self.hitPointsCurrent = 2; // enemy-team health 20% clears the second gate
		return self;
	}

	/** Pins FleeCheck_001's cornered branch: opposition at most half as fast, morale breaks. */
	@Test
	public void corneredNpcBreaksAndFlees() {
		StubCombatant self = woundedNpcMonster();
		StubCombatant pc = new StubCombatant(2, QuickFightTeam.OURS).at(1);
		pc.movementPoints = 6; // half 3 <= self half 3 -> cornered
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, pc), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.FLEE, planner.plan(self).kind());
	}

	/** Pins FleeCheck_001's surrender branch: escape impossible and Int > 5. */
	@Test
	public void smartNpcSurrendersWhenOutrun() {
		StubCombatant self = woundedNpcMonster();
		self.intelligence = 10;
		StubCombatant pc = new StubCombatant(2, QuickFightTeam.OURS).at(1);
		pc.movementPoints = 20; // half 10 > self half 3 -> cannot flee
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, pc), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.SURRENDER, planner.plan(self).kind());
	}

	/** Pins FleeCheck_001's Int <= 5 fall-through: no surrender, no break, fight on. */
	@Test
	public void dimNpcFightsOnInsteadOfSurrendering() {
		StubCombatant self = woundedNpcMonster();
		self.intelligence = 3;
		StubCombatant pc = new StubCombatant(2, QuickFightTeam.OURS).at(1);
		pc.movementPoints = 20;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, pc), new ScriptedDice());

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.ATTACK, intent.kind());
		assertEquals(2, intent.target().orElseThrow().id());
	}

	// --- turn undead and spell/item selection ---

	/**
	 * Pins ovr010.turn_undead's gate and ovr014.FindLowestE9Target: lowest positive
	 * rank wins, fleeing undead are skipped.
	 */
	@Test
	public void turnsUndeadWithLowestRankSkippingFleeing() {
		StubCombatant self = meleePc(1);
		self.canTurnUndead = true;
		StubCombatant skeleton = enemy(2, 2);
		skeleton.undeadRank = 3;
		StubCombatant fleeingZombie = enemy(3, 2);
		fleeingZombie.undeadRank = 1;
		fleeingZombie.forcedFleeing = true;
		StubCombatant ghoul = enemy(4, 3);
		ghoul.undeadRank = 2;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, skeleton, fleeingZombie, ghoul),
			new ScriptedDice());

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.TURN_UNDEAD, intent.kind());
		assertEquals(4, intent.target().orElseThrow().id());
	}

	/** Pins PlayerQuickFight's ordering: the queued spell fires before the turn-undead check. */
	@Test
	public void queuedSpellTakesPriorityOverTurningUndead() {
		StubCombatant self = meleePc(1);
		self.canTurnUndead = true;
		self.queuedSpellId = 42;
		StubCombatant skeleton = enemy(2, 2);
		skeleton.undeadRank = 3;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, skeleton), new ScriptedDice());

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.CAST_QUEUED_SPELL, intent.kind());
		assertEquals(42, intent.spellId());
	}

	/** Pins sub_3560B's random-pick priority loop with an injected SpellcastJudge. */
	@Test
	public void castsJudgedSpellFromLearntList() {
		StubCombatant self = meleePc(1);
		self.npcControlled = true;
		self.moraleScore = 51; // morale 102 passes the personal check at full health
		self.canCastSpells = true;
		self.learntSpellIds = new int[] { 7, 9 };
		StubBattle battle = new StubBattle(self, enemy(2, 1));
		SpellcastJudge judge = (minPriority, spellId, caster) -> spellId == 9;
		// roll(7)=3 passes, roll(2)=2 picks index 1 -> spell 9 at priority 7.
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice(3, 2), judge);

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.CAST_SPELL, intent.kind());
		assertEquals(9, intent.spellId());
	}

	/** Pins sub_3560B's control gate: quick-fought PCs cast only with AutoPCsCastMagic on. */
	@Test
	public void partyMemberCastsOnlyWithAutoMagicToggle() {
		SpellcastJudge judge = (minPriority, spellId, caster) -> spellId == 9;

		StubCombatant self = meleePc(1);
		self.canCastSpells = true;
		self.learntSpellIds = new int[] { 7, 9 };
		StubBattle battle = new StubBattle(self, enemy(2, 1));
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice(3, 2), judge);
		assertEquals(QuickFightIntent.Kind.ATTACK, planner.plan(self).kind());

		battle.autoPartyCastsMagic = true;
		planner = new QuickFightPlanner(battle, new ScriptedDice(3, 2), judge);
		assertEquals(QuickFightIntent.Kind.CAST_SPELL, planner.plan(self).kind());
	}

	/** Pins sub_354AA's gate quirk: charged items are only considered where spellcasting is forbidden. */
	@Test
	public void usesChargedItemOnlyWhereSpellsForbidden() {
		SpellcastJudge judge = (minPriority, spellId, caster) -> true;

		StubCombatant self = meleePc(1);
		self.canUseItems = true;
		self.readiedItemSpellIds = new int[] { 5 };
		StubBattle battle = new StubBattle(self, enemy(2, 1));
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice(), judge);
		assertEquals(QuickFightIntent.Kind.ATTACK, planner.plan(self).kind());

		battle.areaForbidsSpells = true;
		planner = new QuickFightPlanner(battle, new ScriptedDice(), judge);
		QuickFightIntent intent = planner.plan(self);
		assertEquals(QuickFightIntent.Kind.USE_ITEM_SPELL, intent.kind());
		assertEquals(5, intent.spellId());
	}

	/**
	 * Pins sub_354AA's loop quirk, deliberately preserved: a hit at a lower
	 * priority overwrites the earlier, higher-priority pick.
	 */
	@Test
	public void chargedItemScanLetsLowerPriorityOverwrite() {
		StubCombatant self = meleePc(1);
		self.canUseItems = true;
		self.readiedItemSpellIds = new int[] { 5, 8 };
		StubBattle battle = new StubBattle(self, enemy(2, 1));
		battle.areaForbidsSpells = true;
		SpellcastJudge judge = (minPriority, spellId, caster) ->
			(minPriority == 7 && spellId == 5) || (minPriority == 6 && spellId == 8);
		// roll(7)=7: scan priorities 7..1; 5 hits at 7, then 8 overwrites at 6.
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice(7), judge);

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.USE_ITEM_SPELL, intent.kind());
		assertEquals(8, intent.spellId());
	}

	// --- sub_35DB1 near-target list branches ---

	/** Pins sub_35DB1's ranged-with-adjacent-enemy branch: re-run weapon selection. */
	@Test
	public void switchesWeaponWhenRangedAttackerCrowded() {
		StubCombatant self = meleePc(1);
		self.hasRangedWeapon = true;
		self.hasRangedMeleeWeapon = false;
		self.primaryWeaponRawRange = 4; // weapon range 3
		StubCombatant adjacent = enemy(2, 1);
		adjacent.visible = false;
		StubCombatant near = enemy(3, 2);
		near.visible = false;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, adjacent, near), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.SWITCH_WEAPON, planner.plan(self).kind());
	}

	/**
	 * Pins two branches at once: find_target's second pass (arg_2 != 0 accepts an
	 * unseen target through walls) and sub_35DB1's getTargetRange == 1 attack of
	 * an adjacent enemy that cannot be seen.
	 */
	@Test
	public void attacksAdjacentUnseenEnemyByTouch() {
		StubCombatant self = meleePc(1);
		StubCombatant unseen = enemy(2, 1);
		unseen.visible = false;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, unseen), new ScriptedDice());

		QuickFightIntent intent = planner.plan(self);

		assertEquals(QuickFightIntent.Kind.ATTACK, intent.kind());
		assertEquals(2, intent.target().orElseThrow().id());
	}

	/**
	 * Pins sub_35DB1's dead-end fallback: near list empty and find_target(arg_2=0)
	 * refuses an unseen wall-blocked enemy, so the combatant guards.
	 */
	@Test
	public void guardsWhenOnlyEnemyIsWalledOffAndUnseen() {
		StubCombatant self = meleePc(1);
		StubCombatant walledOff = new StubCombatant(2, QuickFightTeam.ENEMY);
		walledOff.distWalls = null; // unreachable with walls respected
		walledOff.distNoWalls = 5;
		walledOff.visible = false;
		QuickFightPlanner planner = new QuickFightPlanner(new StubBattle(self, walledOff), new ScriptedDice());

		assertEquals(QuickFightIntent.Kind.GUARD, planner.plan(self).kind());
	}

	/** Pins sub_35DB1's party-side bandage branch and its combat_team == Ours gate. */
	@Test
	public void bandagesDyingTeammateBeforeFighting() {
		StubCombatant self = meleePc(1);
		StubBattle battle = new StubBattle(self, enemy(2, 1));
		battle.anyPartyTeammateDying = true;
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice());
		assertEquals(QuickFightIntent.Kind.BANDAGE, planner.plan(self).kind());

		// Enemy-side combatants never bandage: same flag, attack instead.
		StubCombatant monster = new StubCombatant(3, QuickFightTeam.ENEMY);
		StubCombatant pc = new StubCombatant(4, QuickFightTeam.OURS).at(1);
		StubBattle enemyBattle = new StubBattle(monster, pc);
		enemyBattle.anyPartyTeammateDying = true;
		planner = new QuickFightPlanner(enemyBattle, new ScriptedDice());
		assertEquals(QuickFightIntent.Kind.ATTACK, planner.plan(monster).kind());
	}

	// --- ovr014.flee_battle escape decision ---

	/** Pins ovr014.flee_battle's gets-away logic, including the 1d2 tie-break. */
	@Test
	public void fleeEscapeAssessmentMatchesFleeBattle() {
		StubCombatant self = meleePc(1);

		// No enemies within 255: free escape.
		assertEquals(QuickFightPlanner.FleeOutcome.ESCAPES,
			new QuickFightPlanner(new StubBattle(self), new ScriptedDice()).assessFleeEscape(self));

		// Faster opposition blocks.
		StubCombatant fast = enemy(2, 3);
		fast.movementPoints = 20;
		assertEquals(QuickFightPlanner.FleeOutcome.BLOCKED,
			new QuickFightPlanner(new StubBattle(self, fast), new ScriptedDice()).assessFleeEscape(self));

		// Slower opposition cannot catch the runner.
		StubCombatant slow = enemy(2, 3);
		slow.movementPoints = 2;
		assertEquals(QuickFightPlanner.FleeOutcome.ESCAPES,
			new QuickFightPlanner(new StubBattle(self, slow), new ScriptedDice()).assessFleeEscape(self));

		// Equal speed: 1d2 == 1 escapes, 2 is blocked.
		StubCombatant matched = enemy(2, 3);
		matched.movementPoints = self.movementPoints;
		assertEquals(QuickFightPlanner.FleeOutcome.ESCAPES,
			new QuickFightPlanner(new StubBattle(self, matched), new ScriptedDice(1)).assessFleeEscape(self));
		assertEquals(QuickFightPlanner.FleeOutcome.BLOCKED,
			new QuickFightPlanner(new StubBattle(self, matched), new ScriptedDice(2)).assessFleeEscape(self));
	}

	/** The planner must never mutate the view: sanity check on a full plan call. */
	@Test
	public void planningLeavesViewUntouched() {
		StubCombatant self = meleePc(1);
		StubCombatant foe = enemy(2, 1);
		StubBattle battle = new StubBattle(self, foe);
		QuickFightPlanner planner = new QuickFightPlanner(battle, new ScriptedDice());

		planner.plan(self);

		assertTrue(self.inCombat);
		assertTrue(foe.inCombat);
		assertEquals(10, foe.hitPointsCurrent);
		assertEquals(2, battle.combatants.size());
	}
}
