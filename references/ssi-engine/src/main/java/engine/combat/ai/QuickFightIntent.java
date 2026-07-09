package engine.combat.ai;

import java.util.Optional;

/**
 * One decision produced by {@link QuickFightPlanner}: what the auto-fighting
 * combatant wants to do next. Pure data — nothing here executes.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr010.cs {@code PlayerQuickFight} (sub_3504B), where each of these
 * kinds is an action the routine performs inline. This port splits decision
 * from execution: COAB attacks/moves/casts on the spot, the planner emits the
 * intent and the executor (integrator wiring) performs it and calls
 * {@code plan} again while the turn has delay/moves left.</p>
 */
public final class QuickFightIntent {
	public enum Kind {
		/** COAB {@code ovr025.clear_actions} paths: nothing to do, spend the turn. */
		END_TURN,
		/** COAB {@code ovr025.guarding} via {@code TryGuarding} (sub_361F7). */
		GUARD,
		/** COAB {@code ovr014.AttackTarget} dispatch in {@code sub_35DB1} (sweep included, executor's call). */
		ATTACK,
		/** COAB {@code moralFailureEscape} (sub_359D1) advance branch: step toward the target. */
		MOVE_TOWARD,
		/**
		 * COAB {@code moralFailureEscape} panic branch: run for the map edge,
		 * escaping via {@code ovr014.flee_battle} when clear ground is found
		 * (see {@link QuickFightPlanner#assessFleeEscape}).
		 */
		FLEE,
		/** COAB {@code FleeCheck_001} (sub_3637F): {@code RemoveFromCombat("Surrenders", unconscious)}. */
		SURRENDER,
		/** COAB {@code sub_35DB1} party-side {@code ovr025.bandage(true)} branch. */
		BANDAGE,
		/** COAB {@code ovr010.turn_undead} / {@code ovr014.turns_undead} against the target. */
		TURN_UNDEAD,
		/** COAB {@code PlayerQuickFight} {@code actions.spell_id > 0} branch ({@code ovr023.sub_5D2E1}). */
		CAST_QUEUED_SPELL,
		/** COAB {@code sub_3560B} pick ({@code ovr014.spell_menu3} with QuickFight.True). */
		CAST_SPELL,
		/** COAB {@code sub_354AA} pick ({@code ovr020.UseMagicItem} on the chosen charged item). */
		USE_ITEM_SPELL,
		/**
		 * COAB {@code sub_35DB1} ranged-weapon-with-adjacent-enemy branch:
		 * re-run weapon selection ({@code AI_items_selection}) before fighting on.
		 */
		SWITCH_WEAPON
	}

	private final Kind kind;
	private final QuickFightCombatantView target;
	private final int spellId;

	private QuickFightIntent(Kind kind, QuickFightCombatantView target, int spellId) {
		this.kind = kind;
		this.target = target;
		this.spellId = spellId;
	}

	public static QuickFightIntent endTurn() {
		return new QuickFightIntent(Kind.END_TURN, null, 0);
	}

	public static QuickFightIntent guard() {
		return new QuickFightIntent(Kind.GUARD, null, 0);
	}

	public static QuickFightIntent attack(QuickFightCombatantView target) {
		return new QuickFightIntent(Kind.ATTACK, target, 0);
	}

	public static QuickFightIntent moveToward(QuickFightCombatantView target) {
		return new QuickFightIntent(Kind.MOVE_TOWARD, target, 0);
	}

	public static QuickFightIntent flee() {
		return new QuickFightIntent(Kind.FLEE, null, 0);
	}

	public static QuickFightIntent surrender() {
		return new QuickFightIntent(Kind.SURRENDER, null, 0);
	}

	public static QuickFightIntent bandage() {
		return new QuickFightIntent(Kind.BANDAGE, null, 0);
	}

	public static QuickFightIntent turnUndead(QuickFightCombatantView target) {
		return new QuickFightIntent(Kind.TURN_UNDEAD, target, 0);
	}

	public static QuickFightIntent castQueuedSpell(int spellId) {
		return new QuickFightIntent(Kind.CAST_QUEUED_SPELL, null, spellId);
	}

	public static QuickFightIntent castSpell(int spellId) {
		return new QuickFightIntent(Kind.CAST_SPELL, null, spellId);
	}

	public static QuickFightIntent useItemSpell(int spellId) {
		return new QuickFightIntent(Kind.USE_ITEM_SPELL, null, spellId);
	}

	public static QuickFightIntent switchWeapon() {
		return new QuickFightIntent(Kind.SWITCH_WEAPON, null, 0);
	}

	public Kind kind() {
		return kind;
	}

	/** Present for {@link Kind#ATTACK}, {@link Kind#MOVE_TOWARD} and {@link Kind#TURN_UNDEAD}. */
	public Optional<QuickFightCombatantView> target() {
		return Optional.ofNullable(target);
	}

	/** Spell id for the cast/use kinds, 0 otherwise. */
	public int spellId() {
		return spellId;
	}

	@Override
	public String toString() {
		StringBuilder out = new StringBuilder(kind.name());
		if (target != null) {
			out.append(" target=").append(target.id());
		}
		if (spellId != 0) {
			out.append(" spell=").append(spellId);
		}
		return out.toString();
	}
}
