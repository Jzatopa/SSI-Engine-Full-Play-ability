package engine.combat.attack;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

/**
 * Conformance tests for the AD&D reference ruleset tables
 * (ovr025.player_strength_group / strengthHitBonus / strengthDamBonus /
 * DexAcBonus / DexReactionAdj; coab commit 9dc46f1), plus the neutral hook.
 * AD&D flavor tables are reference values only, NOT Matrix Cubed evidence.
 */
public class AdndAttackRulesetTest {

	private final AdndAttackRuleset adnd = AdndAttackRuleset.INSTANCE;

	// -- ovr025.player_strength_group --

	@Test
	public void strengthGroupPassesOrdinaryScoresThrough() {
		assertEquals(3, AdndAttackRuleset.strengthGroup(3, 0));
		assertEquals(17, AdndAttackRuleset.strengthGroup(17, 55));
	}

	@Test
	public void strengthGroupFoldsExceptionalPercentileBands() {
		assertEquals(18, AdndAttackRuleset.strengthGroup(18, 0));
		assertEquals(19, AdndAttackRuleset.strengthGroup(18, 1));
		assertEquals(19, AdndAttackRuleset.strengthGroup(18, 50));
		assertEquals(20, AdndAttackRuleset.strengthGroup(18, 51));
		assertEquals(20, AdndAttackRuleset.strengthGroup(18, 75));
		assertEquals(21, AdndAttackRuleset.strengthGroup(18, 76));
		assertEquals(21, AdndAttackRuleset.strengthGroup(18, 90));
		assertEquals(22, AdndAttackRuleset.strengthGroup(18, 91));
		assertEquals(22, AdndAttackRuleset.strengthGroup(18, 99));
		assertEquals(23, AdndAttackRuleset.strengthGroup(18, 100));
	}

	@Test
	public void strengthGroupShiftsGiantStrengthByFive() {
		assertEquals(24, AdndAttackRuleset.strengthGroup(19, 0));
		assertEquals(30, AdndAttackRuleset.strengthGroup(25, 0));
	}

	@Test(expected = IllegalArgumentException.class)
	public void strengthGroupRejectsScoresCoabThrowsOn() {
		AdndAttackRuleset.strengthGroup(26, 0);
	}

	@Test(expected = IllegalArgumentException.class)
	public void strengthGroupRejectsNegativePercentileAtEighteen() {
		AdndAttackRuleset.strengthGroup(18, -1);
	}

	// -- ovr025.strengthHitBonus --

	@Test
	public void strengthToHitBonusMatchesCoabTable() {
		assertEquals(-3, adnd.strengthToHitBonus(3, 0, true));
		assertEquals(-2, adnd.strengthToHitBonus(5, 0, true));
		assertEquals(-1, adnd.strengthToHitBonus(7, 0, true));
		assertEquals(0, adnd.strengthToHitBonus(10, 0, true));
		assertEquals(0, adnd.strengthToHitBonus(16, 0, true));
		assertEquals(1, adnd.strengthToHitBonus(17, 0, true));
		assertEquals(1, adnd.strengthToHitBonus(18, 50, true)); // group 19
		assertEquals(2, adnd.strengthToHitBonus(18, 75, true)); // group 20
		assertEquals(3, adnd.strengthToHitBonus(18, 100, true)); // group 23
		assertEquals(4, adnd.strengthToHitBonus(21, 0, true)); // group 26
		assertEquals(7, adnd.strengthToHitBonus(25, 0, true)); // group 30 -> 30 - 23
	}

	@Test
	public void strengthBonusesZeroWhenGateFlagFalse() {
		// COAB field_125 == 0 zeroes both strength tables regardless of score.
		assertEquals(0, adnd.strengthToHitBonus(18, 100, false));
		assertEquals(0, adnd.strengthDamageBonus(18, 100, false));
	}

	// -- ovr025.strengthDamBonus --

	@Test
	public void strengthDamageBonusMatchesCoabTable() {
		assertEquals(-2, adnd.strengthDamageBonus(2, 0, true));
		assertEquals(-1, adnd.strengthDamageBonus(5, 0, true));
		assertEquals(0, adnd.strengthDamageBonus(15, 0, true));
		assertEquals(1, adnd.strengthDamageBonus(16, 0, true));
		assertEquals(1, adnd.strengthDamageBonus(17, 0, true));
		assertEquals(2, adnd.strengthDamageBonus(18, 0, true)); // group 18 -> 18 - 16
		assertEquals(3, adnd.strengthDamageBonus(18, 50, true)); // group 19
		assertEquals(6, adnd.strengthDamageBonus(18, 100, true)); // group 23 -> 23 - 17
		assertEquals(12, adnd.strengthDamageBonus(24, 0, true)); // group 29
		assertEquals(14, adnd.strengthDamageBonus(25, 0, true)); // group 30
	}

	// -- ovr025.DexAcBonus (stat_bonus) --

	@Test
	public void dexterityArmorClassBonusMatchesCoabTable() {
		assertEquals(-4, adnd.dexterityArmorClassBonus(1));
		assertEquals(-4, adnd.dexterityArmorClassBonus(3));
		assertEquals(-3, adnd.dexterityArmorClassBonus(4));
		assertEquals(-1, adnd.dexterityArmorClassBonus(6));
		assertEquals(0, adnd.dexterityArmorClassBonus(7));
		assertEquals(0, adnd.dexterityArmorClassBonus(14));
		assertEquals(1, adnd.dexterityArmorClassBonus(15));
		assertEquals(4, adnd.dexterityArmorClassBonus(18));
		assertEquals(4, adnd.dexterityArmorClassBonus(20));
		assertEquals(5, adnd.dexterityArmorClassBonus(21));
		assertEquals(6, adnd.dexterityArmorClassBonus(25));
	}

	// -- ovr025.DexReactionAdj --

	@Test
	public void dexterityReactionBonusMatchesCoabTable() {
		assertEquals(-4, adnd.dexterityReactionToHitBonus(0));
		assertEquals(-4, adnd.dexterityReactionToHitBonus(2));
		assertEquals(-3, adnd.dexterityReactionToHitBonus(3));
		assertEquals(-1, adnd.dexterityReactionToHitBonus(5));
		assertEquals(0, adnd.dexterityReactionToHitBonus(6));
		assertEquals(0, adnd.dexterityReactionToHitBonus(15));
		assertEquals(1, adnd.dexterityReactionToHitBonus(16));
		assertEquals(3, adnd.dexterityReactionToHitBonus(18));
		assertEquals(3, adnd.dexterityReactionToHitBonus(20));
		assertEquals(4, adnd.dexterityReactionToHitBonus(21));
		assertEquals(5, adnd.dexterityReactionToHitBonus(25));
	}

	@Test
	public void dexTablesDeliberatelyDisagreeAtTheLowEnd() {
		// Quirk pinned: DexAcBonus penalizes 4..6 as (stat - 7) while
		// DexReactionAdj penalizes 3..5 as (stat - 6); the two COAB tables
		// use shifted bands and must not be merged.
		assertEquals(-3, adnd.dexterityArmorClassBonus(4));
		assertEquals(-2, adnd.dexterityReactionToHitBonus(4));
		assertEquals(0, adnd.dexterityArmorClassBonus(0)); // 0 falls through DexAcBonus
		assertEquals(-4, adnd.dexterityReactionToHitBonus(0)); // but not DexReactionAdj
	}

	// -- neutral hook --

	@Test
	public void neutralRulesetReturnsZeroEverywhere() {
		NeutralAttackRuleset neutral = NeutralAttackRuleset.INSTANCE;
		assertEquals(0, neutral.strengthToHitBonus(25, 100, true));
		assertEquals(0, neutral.strengthDamageBonus(25, 100, true));
		assertEquals(0, neutral.dexterityArmorClassBonus(25));
		assertEquals(0, neutral.dexterityReactionToHitBonus(25));
	}
}
