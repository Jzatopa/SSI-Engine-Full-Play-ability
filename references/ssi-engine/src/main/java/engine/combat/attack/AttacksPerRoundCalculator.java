package engine.combat.attack;

/**
 * Attacks-per-round recalculation, ported from COAB
 * (https://github.com/simeonpilgrim/coab, commit 9dc46f1) engine/ovr014.cs:
 * {@code reclac_attacks} (sub_3EDD4) and {@code ThisRoundActionCount} (sub_3EF0D).
 */
public final class AttacksPerRoundCalculator {

	private AttacksPerRoundCalculator() {
	}

	/**
	 * Inputs to {@link #recalcAttacks}, mirroring the COAB {@code Player}
	 * fields {@code reclac_attacks} reads.
	 *
	 * @param attacksCount COAB {@code player.attacksCount}: base attacks-per-round
	 * @param previousAttack1AttacksLeft COAB {@code player.attack1_AttacksLeft} as read at the
	 *   very top of {@code reclac_attacks}, i.e. before this recalculation (COAB local {@code origAttacks})
	 * @param rangedAttackItemResolved COAB {@code ovr025.is_weapon_ranged(player) &&
	 *   ovr025.GetCurrentAttackItem(out rangedItem, player)}
	 * @param rangedWeaponNumberAttacks COAB {@code ItemDataTable[primaryWeapon.type].numberAttacks},
	 *   meaningful only when {@code rangedAttackItemResolved}
	 * @param rangedAmmoCount COAB {@code rangedItem.count}, meaningful only when {@code rangedAttackItemResolved}
	 * @param roundIsOdd COAB {@code (gbl.combat_round & 1) == 1}
	 * @param actionsField8 COAB {@code player.actions.field_8}; see {@link AttackerView#actionsField8()}
	 */
	public record AttackRoundInputs(
		int attacksCount,
		int previousAttack1AttacksLeft,
		boolean rangedAttackItemResolved,
		int rangedWeaponNumberAttacks,
		int rangedAmmoCount,
		boolean roundIsOdd,
		boolean actionsField8
	) {
	}

	public static AttackRoundInputs inputsFrom(AttackerView attacker, int previousAttack1AttacksLeft, boolean roundIsOdd) {
		return new AttackRoundInputs(
			attacker.attacksCount(),
			previousAttack1AttacksLeft,
			attacker.rangedAttackItemResolved(),
			attacker.rangedWeaponNumberAttacks(),
			attacker.rangedAmmoCount(),
			roundIsOdd,
			attacker.actionsField8()
		);
	}

	/**
	 * Ported from COAB {@code ovr014.ThisRoundActionCount} (sub_3EF0D): half
	 * actions round up on odd combat rounds before halving, so an attacker
	 * with an odd number of half-actions gets the extra one on odd rounds and
	 * loses it on even rounds.
	 */
	public static int thisRoundActionCount(int halfActionsLeft, boolean roundIsOdd) {
		int value = halfActionsLeft;
		if (roundIsOdd) {
			value++;
		}
		return value / 2;
	}

	/**
	 * Ported from COAB {@code ovr014.reclac_attacks} (sub_3EDD4).
	 *
	 * <p>Quirk preserved faithfully: {@code player.attack1_AttacksLeft} is
	 * unconditionally reset to {@code player.attacksCount} at the very top of
	 * the original function, before the recalculated {@code attacks} value is
	 * computed. If the final guard ({@code !field_8 || attacks < origAttacks ||
	 * (field_8 && attacks < origAttacks*2 && !foundRanged)}) does NOT hold,
	 * the function leaves {@code attack1_AttacksLeft} at that early reset
	 * value (plain {@code attacksCount}) rather than at either the freshly
	 * computed {@code attacks} or the original {@code origAttacks} -- the
	 * returned value in that branch is deliberately
	 * {@link AttackRoundInputs#attacksCount()}, not the recalculated count.</p>
	 *
	 * <p>{@code CheckAffectsEffect(player, CheckType.Movement)}, which COAB
	 * runs between assembling {@code halfActionsLeft} and computing
	 * {@code attacks}, is a spell/item-effect hook out of this package's
	 * scope; it is elided (equivalent to no active effect adjusting the
	 * half-actions pool).</p>
	 */
	public static int recalcAttacks(AttackRoundInputs inputs) {
		int origAttacks = inputs.previousAttack1AttacksLeft();
		int resetAttacksLeft = inputs.attacksCount();

		boolean foundRanged = inputs.rangedAttackItemResolved();
		int halfActionsLeft;
		if (foundRanged) {
			halfActionsLeft = Math.max(2, inputs.rangedWeaponNumberAttacks());
		} else {
			halfActionsLeft = resetAttacksLeft;
		}

		int attacks = thisRoundActionCount(halfActionsLeft, inputs.roundIsOdd());

		if (foundRanged) {
			int rangedAmmo = Math.max(1, inputs.rangedAmmoCount());
			if (rangedAmmo < attacks && inputs.rangedAmmoCount() > 0) {
				attacks = rangedAmmo;
			}
		}

		boolean applyRecalculated = !inputs.actionsField8()
			|| attacks < origAttacks
			|| (inputs.actionsField8() && attacks < (origAttacks * 2) && !foundRanged);

		return applyRecalculated ? attacks : resetAttacksLeft;
	}
}
