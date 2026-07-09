package engine.combat.attack;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import engine.combat.Combatant;
import engine.combat.Combatant.Side;
import engine.combat.CombatPosition;

/**
 * Focused tests for the {@link CombatantAttackerView}/{@link CombatantDefenderView}
 * adapter pair: fields Combatant genuinely supplies (thac0, armorClass,
 * synthesized damage-range weapon) must map through, and every field
 * Combatant has no decoded data for must return the documented neutral
 * value.
 */
public class CombatantAttackViewsTest {

	private static Combatant combatant(int thac0, int armorClass, int damageMin, int damageMax) {
		return new Combatant(
			1, "TEST", Side.PARTY, 30, armorClass, thac0, damageMin, damageMax, 6,
			CombatPosition.of(10, 10), "test fixture");
	}

	@Test
	public void attackerViewConvertsDescendingThac0ToAscendingBonusAndSynthesizesDamageRangeAsASingleDie() {
		Combatant attacker = combatant(14, 4, 6, 12);
		CombatantAttackerView view = new CombatantAttackerView(attacker);

		// Descending THAC0 14 -> ascending to-hit bonus (baseline 20) = 6.
		assertEquals(CombatantAttackerView.GOLD_BOX_ASCENDING_AC_BASELINE - 14, view.thac0());
		assertEquals(6, view.thac0());
		assertEquals(1, view.weaponDiceCountNormal());
		assertEquals(7, view.weaponDiceSizeNormal()); // 12 - 6 + 1
		assertEquals(5, view.weaponBonusNormal()); // 6 - 1
		// 1..7 + 5 spans exactly [6, 12], matching Combatant's damage range.
		assertEquals(6, 1 + view.weaponBonusNormal());
		assertEquals(12, view.weaponDiceSizeNormal() + view.weaponBonusNormal());
		// Large-grip fields mirror normal since Combatant has no separate large-weapon stat.
		assertEquals(view.weaponDiceCountNormal(), view.weaponDiceCountLarge());
		assertEquals(view.weaponDiceSizeNormal(), view.weaponDiceSizeLarge());
		assertEquals(view.weaponBonusNormal(), view.weaponBonusLarge());
	}

	@Test
	public void attackerViewReturnsNeutralValuesForEveryUndecodedField() {
		CombatantAttackerView view = new CombatantAttackerView(combatant(14, 4, 6, 12));

		assertEquals(0, view.strengthScore());
		assertEquals(0, view.strengthPercentile());
		assertEquals(0, view.dexterityScore());
		assertFalse(view.strengthBonusApplies());
		assertEquals(0, view.thiefSkillLevel());
		assertFalse(view.weaponAppliesDexterityToHit());
		assertFalse(view.canBackstabWithCurrentWeapon());
		assertEquals(0, view.weaponMagicPlus());
		assertFalse(view.racialWeaponToHitBonus());
		assertEquals(0, view.teamToHitBonus());
		assertFalse(view.isRangedWeapon());
		assertEquals(0, view.rangedWeaponRange());
		assertEquals(1, view.attacksCount());
		assertFalse(view.rangedAttackItemResolved());
		assertEquals(0, view.rangedWeaponNumberAttacks());
		assertEquals(0, view.rangedAmmoCount());
		assertFalse(view.actionsField8());
		// Neutral-true: every Combatant is treated as wielding a basic melee weapon.
		assertTrue(view.weaponIsMelee());
		assertTrue(view.hasEquippedWeapon());
	}

	@Test
	public void defenderViewConvertsDescendingArmorClassToAscendingAndMapsHitPoints() {
		Combatant defender = combatant(14, 4, 6, 12);
		defender.applyDamage(9);
		CombatantDefenderView view = new CombatantDefenderView(defender);

		// Descending AC 4 -> ascending AC (baseline 20) = 16, same baseline as the attacker view.
		assertEquals(CombatantAttackerView.GOLD_BOX_ASCENDING_AC_BASELINE - 4, view.armorClass());
		assertEquals(16, view.armorClass());
		assertEquals(16, view.armorClassBehind());
		assertEquals(21, view.currentHitPoints());
	}

	@Test
	public void ascendingConversionReproducesDescendingHitRuleExactly() {
		// For any thac0/AC/roll, resolver hit (roll+bonus >= ascendingAc) must
		// equal the descending Gold Box rule roll >= thac0 - AC, across 2..19
		// (the resolver's own nat-1/nat-20 quirks live outside this range).
		int[] thac0s = { 10, 14, 18, 20 };
		int[] acs = { -2, 0, 4, 8 };
		for (int thac0 : thac0s) {
			for (int ac : acs) {
				CombatantAttackerView atk = new CombatantAttackerView(combatant(thac0, 10, 1, 4));
				CombatantDefenderView def = new CombatantDefenderView(combatant(14, ac, 1, 4));
				int bonus = atk.thac0(); // neutral ruleset: no other to-hit terms
				for (int roll = 2; roll <= 19; roll++) {
					boolean resolverHit = roll + bonus >= def.armorClass();
					boolean descendingHit = roll >= thac0 - ac;
					assertEquals("thac0=" + thac0 + " ac=" + ac + " roll=" + roll,
						descendingHit, resolverHit);
				}
			}
		}
	}

	@Test
	public void defenderViewReturnsNeutralValuesForEveryUndecodedField() {
		CombatantDefenderView view = new CombatantDefenderView(combatant(14, 4, 6, 12));

		assertFalse(view.isHeld());
		assertEquals(0, view.attacksReceivedThisRound());
		assertEquals(0, view.directionChangesThisRound());
		assertFalse(view.attackerSharesFacingDirection());
		assertEquals(0, view.positionFlags());
		assertEquals(0, view.rangeToAttacker());
	}
}
