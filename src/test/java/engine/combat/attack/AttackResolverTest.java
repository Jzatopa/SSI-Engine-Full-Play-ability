package engine.combat.attack;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.PrimitiveIterator;
import java.util.function.IntSupplier;
import java.util.stream.IntStream;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported attack resolution
 * (ovr024.CanHitTarget/PC_CanHitTarget, ovr025.CalculateAttackValues,
 * ovr014.AttackTarget01/CanBackStabTarget slices; coab commit 9dc46f1).
 * Deterministic via injected d20 suppliers.
 */
public class AttackResolverTest {

	private static IntSupplier rolls(int... values) {
		PrimitiveIterator.OfInt iterator = IntStream.of(values).iterator();
		return iterator::nextInt;
	}

	/** Mutable read-only-view fake; defaults model an unarmed, bonus-free attacker. */
	private static final class FakeAttacker implements AttackerView {
		int thac0 = 10;
		int strengthScore = 10;
		int strengthPercentile = 0;
		int dexterityScore = 10;
		boolean strengthBonusApplies = true;
		int thiefSkillLevel = 0;
		boolean weaponIsMelee = false;
		boolean weaponAppliesDexterityToHit = false;
		boolean hasEquippedWeapon = false;
		boolean canBackstabWithCurrentWeapon = false;
		int weaponBonusNormal = 0;
		int weaponBonusLarge = 0;
		int weaponDiceCountNormal = 1;
		int weaponDiceSizeNormal = 2;
		int weaponDiceCountLarge = 1;
		int weaponDiceSizeLarge = 2;
		int weaponMagicPlus = 0;
		boolean racialWeaponToHitBonus = false;
		int teamToHitBonus = 0;
		boolean isRangedWeapon = false;
		int rangedWeaponRange = 0;
		int attacksCount = 1;
		boolean rangedAttackItemResolved = false;
		int rangedWeaponNumberAttacks = 0;
		int rangedAmmoCount = 0;
		boolean actionsField8 = false;

		@Override
		public int thac0() {
			return thac0;
		}

		@Override
		public int strengthScore() {
			return strengthScore;
		}

		@Override
		public int strengthPercentile() {
			return strengthPercentile;
		}

		@Override
		public int dexterityScore() {
			return dexterityScore;
		}

		@Override
		public boolean strengthBonusApplies() {
			return strengthBonusApplies;
		}

		@Override
		public int thiefSkillLevel() {
			return thiefSkillLevel;
		}

		@Override
		public boolean weaponIsMelee() {
			return weaponIsMelee;
		}

		@Override
		public boolean weaponAppliesDexterityToHit() {
			return weaponAppliesDexterityToHit;
		}

		@Override
		public boolean hasEquippedWeapon() {
			return hasEquippedWeapon;
		}

		@Override
		public boolean canBackstabWithCurrentWeapon() {
			return canBackstabWithCurrentWeapon;
		}

		@Override
		public int weaponBonusNormal() {
			return weaponBonusNormal;
		}

		@Override
		public int weaponBonusLarge() {
			return weaponBonusLarge;
		}

		@Override
		public int weaponDiceCountNormal() {
			return weaponDiceCountNormal;
		}

		@Override
		public int weaponDiceSizeNormal() {
			return weaponDiceSizeNormal;
		}

		@Override
		public int weaponDiceCountLarge() {
			return weaponDiceCountLarge;
		}

		@Override
		public int weaponDiceSizeLarge() {
			return weaponDiceSizeLarge;
		}

		@Override
		public int weaponMagicPlus() {
			return weaponMagicPlus;
		}

		@Override
		public boolean racialWeaponToHitBonus() {
			return racialWeaponToHitBonus;
		}

		@Override
		public int teamToHitBonus() {
			return teamToHitBonus;
		}

		@Override
		public boolean isRangedWeapon() {
			return isRangedWeapon;
		}

		@Override
		public int rangedWeaponRange() {
			return rangedWeaponRange;
		}

		@Override
		public int attacksCount() {
			return attacksCount;
		}

		@Override
		public boolean rangedAttackItemResolved() {
			return rangedAttackItemResolved;
		}

		@Override
		public int rangedWeaponNumberAttacks() {
			return rangedWeaponNumberAttacks;
		}

		@Override
		public int rangedAmmoCount() {
			return rangedAmmoCount;
		}

		@Override
		public boolean actionsField8() {
			return actionsField8;
		}
	}

	/** Mutable read-only-view fake; defaults model an untouched, unheld target. */
	private static final class FakeDefender implements DefenderView {
		int armorClass = 10;
		int armorClassBehind = 8;
		int currentHitPoints = 12;
		boolean isHeld = false;
		int attacksReceivedThisRound = 0;
		int directionChangesThisRound = 0;
		boolean attackerSharesFacingDirection = false;
		int positionFlags = 0;
		int rangeToAttacker = 1;

		@Override
		public int armorClass() {
			return armorClass;
		}

		@Override
		public int armorClassBehind() {
			return armorClassBehind;
		}

		@Override
		public int currentHitPoints() {
			return currentHitPoints;
		}

		@Override
		public boolean isHeld() {
			return isHeld;
		}

		@Override
		public int attacksReceivedThisRound() {
			return attacksReceivedThisRound;
		}

		@Override
		public int directionChangesThisRound() {
			return directionChangesThisRound;
		}

		@Override
		public boolean attackerSharesFacingDirection() {
			return attackerSharesFacingDirection;
		}

		@Override
		public int positionFlags() {
			return positionFlags;
		}

		@Override
		public int rangeToAttacker() {
			return rangeToAttacker;
		}
	}

	// -- ovr024.CanHitTarget (sub_641DD) --

	@Test
	public void canHitTargetNaturalOneAlwaysMissesRegardlessOfBonus() {
		AttackResolver.AttackRollResult result = AttackResolver.canHitTarget(10, 100, rolls(1));
		assertFalse(result.hit());
		assertEquals(1, result.rawAttackRoll());
		assertEquals(1, result.correctedAttackRoll());
	}

	@Test
	public void canHitTargetNaturalTwentyIsCorrectedToOneHundred() {
		AttackResolver.AttackRollResult result = AttackResolver.canHitTarget(50, 0, rolls(20));
		assertTrue(result.hit());
		assertEquals(20, result.rawAttackRoll());
		assertEquals(100, result.correctedAttackRoll());
		assertEquals(100, result.totalToHitValue());
	}

	@Test
	public void canHitTargetUsesStrictlyGreaterComparison() {
		// COAB quirk: sub_641DD hits on (roll + bonus) > ac, so an exact tie misses...
		assertFalse(AttackResolver.canHitTarget(10, 0, rolls(10)).hit());
		assertTrue(AttackResolver.canHitTarget(10, 0, rolls(11)).hit());
	}

	// -- ovr024.PC_CanHitTarget (sub_64245) --

	@Test
	public void pcCanHitTargetUsesGreaterOrEqualComparisonUnlikeCanHitTarget() {
		// ...while sub_64245 hits on (roll + bonuses) >= target_ac: an exact tie hits.
		assertTrue(AttackResolver.pcCanHitTarget(10, 0, 0, rolls(10)).hit());
		assertFalse(AttackResolver.pcCanHitTarget(10, 0, 0, rolls(9)).hit());
	}

	@Test
	public void pcCanHitTargetNaturalOneMissesEvenWithHugeBonuses() {
		AttackResolver.AttackRollResult result = AttackResolver.pcCanHitTarget(5, 50, 50, rolls(1));
		assertFalse(result.hit());
		assertEquals(1, result.correctedAttackRoll());
	}

	@Test
	public void pcCanHitTargetAddsHitBonusAndTeamBonus() {
		// roll 5 + hitBonus 3 + team 2 = 10 >= ac 10.
		AttackResolver.AttackRollResult result = AttackResolver.pcCanHitTarget(10, 3, 2, rolls(5));
		assertTrue(result.hit());
		assertEquals(10, result.totalToHitValue());
	}

	@Test
	public void pcCanHitTargetNaturalTwentyBeatsAbsurdArmorClass() {
		assertTrue(AttackResolver.pcCanHitTarget(90, 0, 0, rolls(20)).hit());
	}

	// -- ovr025.CalculateAttackValues (sub_66023) bonus assembly --

	@Test
	public void toHitBonusAssemblesThac0DexStrengthMagicAndRacialBonuses() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 10;
		attacker.weaponAppliesDexterityToHit = true;
		attacker.dexterityScore = 18; // AD&D DexReactionAdj: +3
		attacker.weaponIsMelee = true;
		attacker.strengthScore = 18;
		attacker.strengthPercentile = 75; // group 20 -> strengthHitBonus +2
		attacker.weaponMagicPlus = 2;
		attacker.racialWeaponToHitBonus = true;

		assertEquals(10 + 3 + 2 + 2 + 1, AttackResolver.toHitBonus(attacker, AdndAttackRuleset.INSTANCE));
	}

	@Test
	public void toHitBonusSkipsDexAndStrengthWhenWeaponFlagsAbsent() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 10;
		attacker.weaponAppliesDexterityToHit = false;
		attacker.dexterityScore = 18;
		attacker.weaponIsMelee = false; // e.g. a bow: no strength to-hit in ovr025
		attacker.strengthScore = 18;
		attacker.strengthPercentile = 75;

		assertEquals(10, AttackResolver.toHitBonus(attacker, AdndAttackRuleset.INSTANCE));
	}

	@Test
	public void neutralRulesetLeavesOnlyThac0AndItemBonuses() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 12;
		attacker.weaponAppliesDexterityToHit = true;
		attacker.dexterityScore = 18;
		attacker.weaponIsMelee = true;
		attacker.strengthScore = 18;
		attacker.strengthPercentile = 100;
		attacker.weaponMagicPlus = 1;

		assertEquals(13, AttackResolver.toHitBonus(attacker, NeutralAttackRuleset.INSTANCE));
		assertEquals(1, AttackResolver.damageBonus(attacker, NeutralAttackRuleset.INSTANCE));
	}

	@Test
	public void damageBonusExcludesRacialToHitBonusQuirk() {
		// COAB quirk: the elvish +1 lands after attack1_DamageBonus is already
		// assigned in CalculateAttackValues, so it reaches to-hit only.
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		attacker.weaponBonusNormal = 1;
		attacker.weaponIsMelee = true;
		attacker.strengthScore = 18;
		attacker.strengthPercentile = 75; // group 20 -> strengthDamBonus +3
		attacker.weaponMagicPlus = 2;
		attacker.racialWeaponToHitBonus = true;

		assertEquals(1 + 3 + 2, AttackResolver.damageBonus(attacker, AdndAttackRuleset.INSTANCE));
		assertEquals(0 + 2 + 2 + 1, AttackResolver.toHitBonus(attacker, AdndAttackRuleset.INSTANCE));
	}

	@Test
	public void largeWeaponSwapReplacesOnlyTheFlatWeaponBonusComponent() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.weaponBonusNormal = 1;
		attacker.weaponBonusLarge = 4;

		// AttackTarget01: damageBonus -= bonusNormal; damageBonus += bonusLarge.
		assertEquals(9, AttackResolver.applyLargeWeaponDamageSwap(6, attacker));
	}

	// -- ovr014.CanBackStabTarget (sub_408D7) --

	@Test
	public void backstabRequiresWeaponGateFacingAndPositionFlags() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.canBackstabWithCurrentWeapon = true;
		FakeDefender defender = new FakeDefender();
		defender.attacksReceivedThisRound = 2;
		defender.attackerSharesFacingDirection = true;
		defender.positionFlags = 1; // (field_DE & 0x7F) <= 1

		assertTrue(AttackResolver.canBackStabTarget(attacker, defender));

		defender.attacksReceivedThisRound = 1; // must be > 1
		assertFalse(AttackResolver.canBackStabTarget(attacker, defender));

		defender.attacksReceivedThisRound = 2;
		defender.positionFlags = 2; // (field_DE & 0x7F) > 1
		assertFalse(AttackResolver.canBackStabTarget(attacker, defender));

		defender.positionFlags = 1;
		defender.attackerSharesFacingDirection = false;
		assertFalse(AttackResolver.canBackStabTarget(attacker, defender));

		defender.attackerSharesFacingDirection = true;
		attacker.canBackstabWithCurrentWeapon = false;
		assertFalse(AttackResolver.canBackStabTarget(attacker, defender));
	}

	@Test
	public void backstabPositionFlagCheckMasksHighBit() {
		// (field_DE & 0x7F) <= 1: 0x80 and 0x81 pass the mask even though raw values are large.
		FakeAttacker attacker = new FakeAttacker();
		attacker.canBackstabWithCurrentWeapon = true;
		FakeDefender defender = new FakeDefender();
		defender.attacksReceivedThisRound = 2;
		defender.attackerSharesFacingDirection = true;
		defender.positionFlags = 0x81;

		assertTrue(AttackResolver.canBackStabTarget(attacker, defender));
	}

	// -- ovr014.AttackTarget01 (sub_3F4EB) per-swing resolution --

	@Test
	public void resolveSwingUsesFrontArmorClassByDefault() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		FakeDefender defender = new FakeDefender();
		defender.armorClass = 10;
		defender.armorClassBehind = 8;

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(10));

		assertEquals(10, outcome.targetArmorClass());
		assertTrue(outcome.hit()); // 10 >= 10
		assertFalse(outcome.behindAttack());
		assertFalse(outcome.backstab());
		assertEquals(1, outcome.backstabDamageMultiplier());
	}

	@Test
	public void resolveSwingBehindAttackRequestedUsesBehindArmorClass() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		FakeDefender defender = new FakeDefender();
		defender.armorClass = 10;
		defender.armorClassBehind = 8;

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, true, rolls(9));

		assertEquals(8, outcome.targetArmorClass());
		assertTrue(outcome.behindAttack());
		assertTrue(outcome.hit()); // 9 >= 8
	}

	@Test
	public void resolveSwingAutoBehindQuirkAfterFacingChurn() {
		// AttackTarget01: AttacksReceived > 1, attacker in the target's facing,
		// directionChanges > 4 => treated as a behind attack without being requested.
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		FakeDefender defender = new FakeDefender();
		defender.armorClass = 10;
		defender.armorClassBehind = 8;
		defender.attacksReceivedThisRound = 2;
		defender.attackerSharesFacingDirection = true;
		defender.directionChangesThisRound = 5;

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(8));

		assertTrue(outcome.behindAttack());
		assertEquals(8, outcome.targetArmorClass());

		defender.directionChangesThisRound = 4; // boundary: must be > 4
		AttackOutcome frontal = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(8));
		assertFalse(frontal.behindAttack());
		assertEquals(10, frontal.targetArmorClass());
	}

	@Test
	public void resolveSwingBackstabUsesBehindAcMinusFourAndThiefMultiplier() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		attacker.canBackstabWithCurrentWeapon = true;
		attacker.thiefSkillLevel = 9; // ((9 - 1) / 4) + 2 = 4
		FakeDefender defender = new FakeDefender();
		defender.armorClass = 12;
		defender.armorClassBehind = 10;
		defender.attacksReceivedThisRound = 2;
		defender.attackerSharesFacingDirection = true;
		defender.positionFlags = 0;

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(6));

		assertTrue(outcome.backstab());
		assertEquals(10 - 4, outcome.targetArmorClass());
		assertTrue(outcome.hit()); // 6 >= 6
		assertEquals(4, outcome.backstabDamageMultiplier());
	}

	@Test
	public void resolveSwingAddsRangedDefenseBonusToTargetAc() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		attacker.isRangedWeapon = true;
		attacker.rangedWeaponRange = 13; // oneThird = 4
		FakeDefender defender = new FakeDefender();
		defender.armorClass = 10;
		defender.rangeToAttacker = 9; // > 4 twice: +2 then +3

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(14));

		assertEquals(15, outcome.targetArmorClass());
		assertFalse(outcome.hit()); // 14 < 15
	}

	@Test
	public void resolveSwingLargeWeaponDiceWhenDefenderPositionFlagsDemandIt() {
		FakeAttacker attacker = new FakeAttacker();
		attacker.thac0 = 0;
		attacker.hasEquippedWeapon = true;
		attacker.weaponDiceCountNormal = 1;
		attacker.weaponDiceSizeNormal = 8;
		attacker.weaponDiceCountLarge = 2;
		attacker.weaponDiceSizeLarge = 6;
		attacker.weaponBonusNormal = 1;
		attacker.weaponBonusLarge = 3;
		FakeDefender defender = new FakeDefender();
		defender.positionFlags = 3; // (3 & 7) > 1

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(20));

		assertEquals(2, outcome.damageDiceCount());
		assertEquals(6, outcome.damageDiceSize());
		assertEquals(3, outcome.damageBonus()); // 1 (normal) - 1 + 3 (large)
	}

	@Test
	public void resolveSwingNormalDiceWithoutEquippedWeaponEvenWithLargeFlags() {
		// AttackTarget01 checks primaryWeapon != null before the field_DE dice swap.
		FakeAttacker attacker = new FakeAttacker();
		attacker.hasEquippedWeapon = false;
		attacker.weaponDiceCountNormal = 1;
		attacker.weaponDiceSizeNormal = 2;
		attacker.weaponDiceCountLarge = 9;
		attacker.weaponDiceSizeLarge = 9;
		FakeDefender defender = new FakeDefender();
		defender.positionFlags = 0xFF;

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(10));

		assertEquals(1, outcome.damageDiceCount());
		assertEquals(2, outcome.damageDiceSize());
	}

	@Test
	public void resolveSwingHeldTargetHitsEvenOnNaturalOneQuirk() {
		// AttackTarget01's loop body: PC_CanHitTarget(...) || target.IsHeld().
		FakeAttacker attacker = new FakeAttacker();
		FakeDefender defender = new FakeDefender();
		defender.isHeld = true;

		AttackOutcome outcome = AttackResolver.resolveSwing(attacker, defender, NeutralAttackRuleset.INSTANCE, false, rolls(1));

		assertTrue(outcome.hit());
		assertEquals(1, outcome.rawAttackRoll());
		assertFalse(outcome.slaysHelpless());
	}

	// -- ovr014.AttackTarget01 held-target short-circuit --

	@Test
	public void slayHelplessOutcomeAppliesCurrentHitPointsPlusFive() {
		FakeDefender defender = new FakeDefender();
		defender.currentHitPoints = 12;

		AttackOutcome outcome = AttackResolver.slayHelplessOutcome(defender);

		assertTrue(outcome.hit());
		assertTrue(outcome.slaysHelpless());
		assertEquals(17, outcome.damageBonus());
		assertEquals(0, outcome.damageDiceCount());
		assertEquals(0, outcome.damageDiceSize());
		assertEquals(1, outcome.backstabDamageMultiplier());
	}
}
