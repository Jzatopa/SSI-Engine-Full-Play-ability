package engine.combat.map;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported movement-budget semantics
 * (engine/ovr014.cs CalcMoves + engine/ovr025.cs calc_movement, coab commit
 * 9dc46f1).
 */
public class CombatMovementBudgetTest {

	/** Fixed-value traits for one synthetic combatant (any id maps to the same values). */
	private static final class FixedTraits implements MovementTraits {
		int movementRate = 12;
		int carriedWeight = 0;
		int maxEncumbrance = 1000;
		boolean inCombat = true;
		int outOfCombatBonus = 0;

		@Override
		public int movementRate(int combatantId) {
			return movementRate;
		}

		@Override
		public int carriedWeight(int combatantId) {
			return carriedWeight;
		}

		@Override
		public int maxEncumbrance(int combatantId) {
			return maxEncumbrance;
		}

		@Override
		public boolean isInCombat(int combatantId) {
			return inCombat;
		}

		@Override
		public int outOfCombatMovementBonus(int combatantId) {
			return outOfCombatBonus;
		}
	}

	private static final int ANY_ID = 1;

	// --- deriveEncumbranceAdjustedMovementRate (ovr025.calc_movement) ---------

	@Test
	public void underEncumbranceLimitKeepsFullMovementRate() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.carriedWeight = 900;
		traits.maxEncumbrance = 1000;

		assertEquals(12, new CombatMovementBudget(traits).deriveEncumbranceAdjustedMovementRate(ANY_ID));
	}

	@Test
	public void overloadWithinFirstBandKeepsFullMovementRate() {
		// COAB tolerates overload 0..0x200 (512) with no penalty.
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.carriedWeight = 1000 + 0x200;
		traits.maxEncumbrance = 1000;

		assertEquals(12, new CombatMovementBudget(traits).deriveEncumbranceAdjustedMovementRate(ANY_ID));
	}

	@Test
	public void overloadInSecondBandCapsMovementAtNine() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.carriedWeight = 1000 + 0x201;
		traits.maxEncumbrance = 1000;

		assertEquals(9, new CombatMovementBudget(traits).deriveEncumbranceAdjustedMovementRate(ANY_ID));
	}

	@Test
	public void overloadInThirdBandCapsMovementAtSix() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.carriedWeight = 1000 + 0x400;
		traits.maxEncumbrance = 1000;

		assertEquals(6, new CombatMovementBudget(traits).deriveEncumbranceAdjustedMovementRate(ANY_ID));
	}

	@Test
	public void overloadBeyondAllBandsCapsMovementAtThree() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.carriedWeight = 1000 + 0x401;
		traits.maxEncumbrance = 1000;

		assertEquals(3, new CombatMovementBudget(traits).deriveEncumbranceAdjustedMovementRate(ANY_ID));
	}

	@Test
	public void encumbranceBandNeverRaisesASlowerBaseRate() {
		// COAB only lowers movement (if moves < player.movement); a base rate
		// of 6 stays 6 even when the band value would be 9.
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 6;
		traits.carriedWeight = 1000 + 0x300;
		traits.maxEncumbrance = 1000;

		assertEquals(6, new CombatMovementBudget(traits).deriveEncumbranceAdjustedMovementRate(ANY_ID));
	}

	// --- calcMovementBudget (ovr014.CalcMoves) --------------------------------

	@Test
	public void inCombatBudgetIsTwiceTheMovementRate() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.inCombat = true;
		traits.outOfCombatBonus = 5; // must be ignored while in combat

		assertEquals(24, new CombatMovementBudget(traits).calcMovementBudget(ANY_ID));
	}

	@Test
	public void outOfCombatBonusIsAddedBeforeDoubling() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;
		traits.inCombat = false;
		traits.outOfCombatBonus = 4;

		assertEquals(32, new CombatMovementBudget(traits).calcMovementBudget(ANY_ID));
	}

	@Test
	public void movesBelowOneClampToOneBeforeDoubling() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 3;
		traits.inCombat = false;
		traits.outOfCombatBonus = -10;

		assertEquals(2, new CombatMovementBudget(traits).calcMovementBudget(ANY_ID));
	}

	@Test
	public void movesAboveNinetySixClampToOneNotNinetySix() {
		// COAB quirk preserved: the out-of-range branch sets moves = 1, so an
		// oversized rate collapses to the minimum, not the maximum.
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 97;

		assertEquals(2, new CombatMovementBudget(traits).calcMovementBudget(ANY_ID));
	}

	@Test
	public void movesOfExactlyNinetySixAreAccepted() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 96;

		assertEquals(192, new CombatMovementBudget(traits).calcMovementBudget(ANY_ID));
	}

	@Test
	public void affectHookReceivesFreshBudgetInResetModeAndItsResultIsReturned() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 12;

		int[] observed = new int[2]; // [0] = halfActions passed in, [1] = resetMode count
		MovementAffectHook haste = (combatantId, halfActionsLeft, resetMode) -> {
			observed[0] = halfActionsLeft;
			if (resetMode) {
				observed[1]++;
			}
			return halfActionsLeft * 2; // haste-style doubling
		};

		assertEquals(48, new CombatMovementBudget(traits, haste).calcMovementBudget(ANY_ID));
		assertEquals(24, observed[0]);
		assertEquals(1, observed[1]);
	}

	@Test
	public void defaultHookIsIdentity() {
		FixedTraits traits = new FixedTraits();
		traits.movementRate = 9;

		assertEquals(18, new CombatMovementBudget(traits).calcMovementBudget(ANY_ID));
	}
}
