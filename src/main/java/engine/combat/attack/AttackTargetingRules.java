package engine.combat.attack;

import java.util.function.BooleanSupplier;

/**
 * Pure decision logic for whether an attack is allowed and for the ranged
 * defense AC bonus, ported from COAB (https://github.com/simeonpilgrim/coab,
 * commit 9dc46f1) engine/ovr014.cs: {@code can_attack_target} (sub_40F1F) and
 * {@code RangedDefenseBonus} (sub_3FCED).
 *
 * <p>Both functions are display/side-effect-free in their decision core;
 * COAB's UI confirmation prompt and team-reassignment side effect are pushed
 * to the caller (see {@link #canAttackTarget}'s javadoc).</p>
 */
public final class AttackTargetingRules {

	private AttackTargetingRules() {
	}

	/**
	 * Result of {@link #canAttackTarget}.
	 *
	 * @param allowed whether the attack may proceed
	 * @param triggersAllyTeamSwitch true only when the ally-attack confirmation branch was taken and
	 *   returned true. COAB's {@code can_attack_target} then flips every NPC ally
	 *   ({@code health_status == okey && control_morale >= Control.NPC_Base}) to
	 *   {@code CombatTeam.Enemy} and clears their target, plus calls
	 *   {@code ovr025.CountCombatTeamMembers()}. That mutation touches every combatant on the
	 *   field, not just the attacker/defender pair this package models read-only, so it is
	 *   deliberately left to the integrator to apply when this flag is true.
	 */
	public record AttackPermission(boolean allowed, boolean triggersAllyTeamSwitch) {
		static final AttackPermission ALLOWED_NO_SWITCH = new AttackPermission(true, false);
		static final AttackPermission DENIED = new AttackPermission(false, false);
		static final AttackPermission ALLOWED_WITH_SWITCH = new AttackPermission(true, true);
	}

	/**
	 * Ported from COAB {@code ovr014.can_attack_target} (sub_40F1F).
	 *
	 * @param targetOnOppositeTeam COAB {@code target.OppositeTeam() == attacker.combat_team}
	 * @param attackerQuickFight COAB {@code attacker.quick_fight == QuickFight.True}
	 * @param confirmAllyAttack COAB {@code ovr027.yes_no(gbl.defaultMenuColors, "Attack Ally: ") == 'Y'}
	 *   -- the UI confirmation prompt, pushed to the caller as a supplier so this package stays
	 *   display-free; only invoked when the first two checks both fail
	 */
	public static AttackPermission canAttackTarget(
		boolean targetOnOppositeTeam,
		boolean attackerQuickFight,
		BooleanSupplier confirmAllyAttack
	) {
		if (targetOnOppositeTeam || attackerQuickFight) {
			return AttackPermission.ALLOWED_NO_SWITCH;
		}
		if (!confirmAllyAttack.getAsBoolean()) {
			return AttackPermission.DENIED;
		}
		return AttackPermission.ALLOWED_WITH_SWITCH;
	}

	/**
	 * Ported from COAB {@code ovr014.RangedDefenseBonus} (sub_3FCED): an
	 * attacker using a ranged weapon grants the target a growing AC bonus the
	 * farther out the shot, in two discrete steps (+2 then +3, so the maximum
	 * possible total is +5 -- there is no third step in the original).
	 *
	 * @param attackerHasRangedWeapon COAB {@code ovr025.is_weapon_ranged(attacker)}
	 * @param attackerWeaponRange COAB {@code ItemDataTable[primaryWeapon.type].range}, meaningful
	 *   only when {@code attackerHasRangedWeapon}
	 * @param rangeToTarget COAB {@code ovr025.getTargetRange(target, attacker)}
	 */
	public static int rangedDefenseBonus(boolean attackerHasRangedWeapon, int attackerWeaponRange, int rangeToTarget) {
		if (!attackerHasRangedWeapon) {
			return 0;
		}
		int oneThirdRange = (attackerWeaponRange - 1) / 3;
		int range = rangeToTarget;
		int acAdjustment = 0;
		if (range > oneThirdRange) {
			range -= oneThirdRange;
			acAdjustment += 2;
		}
		if (range > oneThirdRange) {
			range -= oneThirdRange;
			acAdjustment += 3;
		}
		return acAdjustment;
	}
}
