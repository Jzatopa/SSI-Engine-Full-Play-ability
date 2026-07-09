package engine.combat.attack;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported targeting rules
 * (ovr014.can_attack_target sub_40F1F, ovr014.RangedDefenseBonus sub_3FCED;
 * coab commit 9dc46f1).
 */
public class AttackTargetingRulesTest {

	// -- ovr014.can_attack_target (sub_40F1F) --

	@Test
	public void oppositeTeamTargetIsAlwaysAttackableWithoutPrompt() {
		AttackTargetingRules.AttackPermission permission = AttackTargetingRules.canAttackTarget(true, false, () -> {
			throw new AssertionError("confirmation prompt must not be consulted for an enemy target");
		});
		assertTrue(permission.allowed());
		assertFalse(permission.triggersAllyTeamSwitch());
	}

	@Test
	public void quickFightAttackerSkipsAllyPromptEvenAgainstAlly() {
		AttackTargetingRules.AttackPermission permission = AttackTargetingRules.canAttackTarget(false, true, () -> {
			throw new AssertionError("confirmation prompt must not be consulted under quick fight");
		});
		assertTrue(permission.allowed());
		assertFalse(permission.triggersAllyTeamSwitch());
	}

	@Test
	public void decliningAllyPromptDeniesTheAttack() {
		AttackTargetingRules.AttackPermission permission = AttackTargetingRules.canAttackTarget(false, false, () -> false);
		assertFalse(permission.allowed());
		assertFalse(permission.triggersAllyTeamSwitch());
	}

	@Test
	public void confirmingAllyPromptAllowsAttackAndFlagsTheTeamSwitch() {
		// COAB then flips every okey NPC ally to CombatTeam.Enemy; the flag
		// tells the integrator to apply that battlefield-wide mutation.
		AttackTargetingRules.AttackPermission permission = AttackTargetingRules.canAttackTarget(false, false, () -> true);
		assertTrue(permission.allowed());
		assertTrue(permission.triggersAllyTeamSwitch());
	}

	// -- ovr014.RangedDefenseBonus (sub_3FCED) --

	@Test
	public void meleeAttackerGrantsNoRangedDefenseBonus() {
		assertEquals(0, AttackTargetingRules.rangedDefenseBonus(false, 13, 9));
	}

	@Test
	public void shortRangeShotGrantsNoBonus() {
		// weapon range 13 -> oneThird = (13 - 1) / 3 = 4; range 4 is within the first band.
		assertEquals(0, AttackTargetingRules.rangedDefenseBonus(true, 13, 4));
	}

	@Test
	public void midRangeShotGrantsPlusTwo() {
		// range 5..8 exceeds oneThird once: +2.
		assertEquals(2, AttackTargetingRules.rangedDefenseBonus(true, 13, 5));
		assertEquals(2, AttackTargetingRules.rangedDefenseBonus(true, 13, 8));
	}

	@Test
	public void longRangeShotGrantsPlusFiveAndNoThirdStep() {
		// range 9 exceeds oneThird twice: +2 then +3 = +5; there is no third
		// step in COAB, so even absurd ranges stay at +5.
		assertEquals(5, AttackTargetingRules.rangedDefenseBonus(true, 13, 9));
		assertEquals(5, AttackTargetingRules.rangedDefenseBonus(true, 13, 100));
	}

	@Test
	public void weaponRangeOneQuirkMakesEveryPositiveRangeLongRange() {
		// Quirk: range 1 weapon -> oneThirdRange = 0, so any shot at range >= 1
		// (even point blank at 1) trips both steps immediately.
		assertEquals(5, AttackTargetingRules.rangedDefenseBonus(true, 1, 1));
		assertEquals(0, AttackTargetingRules.rangedDefenseBonus(true, 1, 0));
	}
}
