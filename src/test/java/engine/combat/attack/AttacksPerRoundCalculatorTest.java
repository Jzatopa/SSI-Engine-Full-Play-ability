package engine.combat.attack;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

import engine.combat.attack.AttacksPerRoundCalculator.AttackRoundInputs;

/**
 * Conformance tests for the COAB-ported attacks-per-round recalculation
 * (ovr014.reclac_attacks sub_3EDD4, ovr014.ThisRoundActionCount sub_3EF0D;
 * coab commit 9dc46f1).
 */
public class AttacksPerRoundCalculatorTest {

	private static AttackRoundInputs melee(int attacksCount, int prevAttacksLeft, boolean roundIsOdd, boolean field8) {
		return new AttackRoundInputs(attacksCount, prevAttacksLeft, false, 0, 0, roundIsOdd, field8);
	}

	private static AttackRoundInputs ranged(int attacksCount, int prevAttacksLeft, int numberAttacks, int ammoCount,
		boolean roundIsOdd, boolean field8) {
		return new AttackRoundInputs(attacksCount, prevAttacksLeft, true, numberAttacks, ammoCount, roundIsOdd, field8);
	}

	// -- ovr014.ThisRoundActionCount (sub_3EF0D) --

	@Test
	public void oddRoundsRoundHalfActionsUpEvenRoundsDown() {
		// 3 half-actions = 1.5 attacks/round: the extra swing lands on odd rounds.
		assertEquals(2, AttacksPerRoundCalculator.thisRoundActionCount(3, true));
		assertEquals(1, AttacksPerRoundCalculator.thisRoundActionCount(3, false));
		assertEquals(1, AttacksPerRoundCalculator.thisRoundActionCount(2, true));
		assertEquals(1, AttacksPerRoundCalculator.thisRoundActionCount(2, false));
		assertEquals(1, AttacksPerRoundCalculator.thisRoundActionCount(1, true));
		assertEquals(0, AttacksPerRoundCalculator.thisRoundActionCount(1, false));
	}

	// -- ovr014.reclac_attacks (sub_3EDD4) --

	@Test
	public void meleeAttackerGetsHalvedAttackCountPerRoundParity() {
		assertEquals(2, AttacksPerRoundCalculator.recalcAttacks(melee(3, 3, true, false)));
		assertEquals(1, AttacksPerRoundCalculator.recalcAttacks(melee(3, 3, false, false)));
	}

	@Test
	public void rangedWeaponFloorsHalfActionsAtTwo() {
		// numberAttacks < 2 is raised to 2: one attack per round on any parity.
		assertEquals(1, AttacksPerRoundCalculator.recalcAttacks(ranged(1, 1, 1, 20, false, false)));
		assertEquals(1, AttacksPerRoundCalculator.recalcAttacks(ranged(1, 1, 1, 20, true, false)));
	}

	@Test
	public void rangedAttacksClampToAmmunition() {
		// numberAttacks 6 on an odd round = 3 attacks, but only 2 rounds of ammo.
		assertEquals(3, AttacksPerRoundCalculator.recalcAttacks(ranged(3, 3, 6, 20, true, false)));
		assertEquals(2, AttacksPerRoundCalculator.recalcAttacks(ranged(3, 3, 6, 2, true, false)));
	}

	@Test
	public void zeroAmmoQuirkDoesNotClampAttacks() {
		// Quirk pinned from sub_3EDD4: rangedAmmo is floored at 1 but the
		// clamp only applies when rangedItem.count > 0 -- with count == 0 the
		// computed attack count passes through unclamped (the empty item is
		// consumed elsewhere in COAB, not here).
		assertEquals(3, AttacksPerRoundCalculator.recalcAttacks(ranged(3, 3, 6, 0, true, false)));
	}

	@Test
	public void field8FalseAlwaysAppliesTheRecalculatedCount() {
		assertEquals(1, AttacksPerRoundCalculator.recalcAttacks(melee(3, 1, false, false)));
	}

	@Test
	public void field8TrueKeepsRecalculationWhenAttacksDropBelowPrevious() {
		// attacks (1, even round) < origAttacks (3): the guard's middle clause applies it.
		assertEquals(1, AttacksPerRoundCalculator.recalcAttacks(melee(3, 3, false, true)));
	}

	@Test
	public void field8TrueResetQuirkReturnsBaseAttacksCountNotEitherCandidate() {
		// Quirk pinned from sub_3EDD4: attack1_AttacksLeft is reset to
		// attacksCount at the top of the function. With field_8 set,
		// origAttacks = 1 and recalculated attacks = 2 (odd round), the final
		// guard fails (2 >= 1, and 2 >= 1*2), so the function leaves the
		// early reset in place: the result is attacksCount (3), which is
		// neither the previous value (1) nor the recalculated value (2).
		assertEquals(3, AttacksPerRoundCalculator.recalcAttacks(melee(3, 1, true, true)));
	}

	@Test
	public void field8TrueRangedNeverTakesTheDoubledPreviousClause() {
		// Third guard clause requires foundRanged == false; with a ranged
		// weapon, attacks < origAttacks*2 alone must not apply the recalc.
		// numberAttacks 4, even round -> attacks 2; origAttacks 2 -> 2 < 4
		// would pass the melee clause, but ranged falls back to the reset
		// value (attacksCount).
		assertEquals(5, AttacksPerRoundCalculator.recalcAttacks(ranged(5, 2, 4, 20, false, true)));
	}

	@Test
	public void inputsFromViewMirrorsAttackerFacts() {
		AttackRoundInputs inputs = AttacksPerRoundCalculator.inputsFrom(new AttackerView() {
			@Override
			public int thac0() {
				return 0;
			}

			@Override
			public int strengthScore() {
				return 0;
			}

			@Override
			public int strengthPercentile() {
				return 0;
			}

			@Override
			public int dexterityScore() {
				return 0;
			}

			@Override
			public boolean strengthBonusApplies() {
				return false;
			}

			@Override
			public int thiefSkillLevel() {
				return 0;
			}

			@Override
			public boolean weaponIsMelee() {
				return false;
			}

			@Override
			public boolean weaponAppliesDexterityToHit() {
				return false;
			}

			@Override
			public boolean hasEquippedWeapon() {
				return true;
			}

			@Override
			public boolean canBackstabWithCurrentWeapon() {
				return false;
			}

			@Override
			public int weaponBonusNormal() {
				return 0;
			}

			@Override
			public int weaponBonusLarge() {
				return 0;
			}

			@Override
			public int weaponDiceCountNormal() {
				return 1;
			}

			@Override
			public int weaponDiceSizeNormal() {
				return 6;
			}

			@Override
			public int weaponDiceCountLarge() {
				return 1;
			}

			@Override
			public int weaponDiceSizeLarge() {
				return 8;
			}

			@Override
			public int weaponMagicPlus() {
				return 0;
			}

			@Override
			public boolean racialWeaponToHitBonus() {
				return false;
			}

			@Override
			public int teamToHitBonus() {
				return 0;
			}

			@Override
			public boolean isRangedWeapon() {
				return true;
			}

			@Override
			public int rangedWeaponRange() {
				return 13;
			}

			@Override
			public int attacksCount() {
				return 4;
			}

			@Override
			public boolean rangedAttackItemResolved() {
				return true;
			}

			@Override
			public int rangedWeaponNumberAttacks() {
				return 6;
			}

			@Override
			public int rangedAmmoCount() {
				return 2;
			}

			@Override
			public boolean actionsField8() {
				return false;
			}
		}, 4, true);

		assertEquals(4, inputs.attacksCount());
		assertEquals(4, inputs.previousAttack1AttacksLeft());
		assertEquals(true, inputs.rangedAttackItemResolved());
		assertEquals(6, inputs.rangedWeaponNumberAttacks());
		assertEquals(2, inputs.rangedAmmoCount());
		assertEquals(true, inputs.roundIsOdd());
		assertEquals(false, inputs.actionsField8());
		assertEquals(2, AttacksPerRoundCalculator.recalcAttacks(inputs));
	}
}
