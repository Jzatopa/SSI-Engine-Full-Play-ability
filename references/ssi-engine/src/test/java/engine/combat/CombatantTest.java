package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import engine.combat.Combatant.HealthStatus;
import engine.combat.Combatant.Side;

/**
 * Conformance tests for the COAB-ported damage/dying semantics
 * (ovr025.damage_player + ovr009.BattleRoundChecks, coab commit 9dc46f1).
 */
public class CombatantTest {

	private static Combatant tenHitPointFighter() {
		return new Combatant(1, "A", Side.PARTY, 10, 5, 10, 1, 2, 3, CombatPosition.of(1, 1), "test");
	}

	@Test
	public void partialDamageReducesHitPointsAndStaysOkay() {
		Combatant fighter = tenHitPointFighter();

		assertEquals(4, fighter.applyDamage(4));

		assertEquals(6, fighter.hitPoints());
		assertEquals(HealthStatus.OKAY, fighter.healthStatus());
		assertTrue(fighter.isAlive());
	}

	@Test
	public void exactZeroKnocksUnconscious() {
		Combatant fighter = tenHitPointFighter();

		fighter.applyDamage(10);

		assertEquals(0, fighter.hitPoints());
		assertEquals(HealthStatus.UNCONSCIOUS, fighter.healthStatus());
		assertFalse(fighter.isAlive());
		assertEquals(0, fighter.bleeding());
	}

	@Test
	public void overkillWithinNineLeavesDyingWithBleedingAtOverkill() {
		Combatant fighter = tenHitPointFighter();

		fighter.applyDamage(13);

		assertEquals(0, fighter.hitPoints());
		assertEquals(HealthStatus.DYING, fighter.healthStatus());
		assertEquals(3, fighter.bleeding());
		assertFalse(fighter.isAlive());
	}

	@Test
	public void overkillPastNineKillsOutright() {
		Combatant fighter = tenHitPointFighter();

		fighter.applyDamage(20);

		assertEquals(HealthStatus.DEAD, fighter.healthStatus());
		assertFalse(fighter.isAlive());
	}

	@Test
	public void dyingCombatantBleedsOutWhenBleedingExceedsNine() {
		Combatant fighter = tenHitPointFighter();
		fighter.applyDamage(17); // dying, bleeding 7

		assertFalse(fighter.bleedOneRound()); // 8
		assertFalse(fighter.bleedOneRound()); // 9
		assertTrue(fighter.bleedOneRound()); // 10 > 9 -> dead

		assertEquals(HealthStatus.DEAD, fighter.healthStatus());
	}

	@Test
	public void bleedingTickOnlyAppliesToDyingCombatants() {
		Combatant okay = tenHitPointFighter();
		assertFalse(okay.bleedOneRound());
		assertEquals(HealthStatus.OKAY, okay.healthStatus());

		Combatant unconscious = tenHitPointFighter();
		unconscious.applyDamage(10);
		assertFalse(unconscious.bleedOneRound());
		assertEquals(HealthStatus.UNCONSCIOUS, unconscious.healthStatus());
	}

	@Test
	public void healingRevivesDyingButNotDead() {
		Combatant dying = tenHitPointFighter();
		dying.applyDamage(13);
		assertEquals(2, dying.heal(2));
		assertEquals(HealthStatus.OKAY, dying.healthStatus());
		assertEquals(0, dying.bleeding());
		assertTrue(dying.isAlive());

		Combatant dead = tenHitPointFighter();
		dead.applyDamage(20);
		assertEquals(0, dead.heal(5));
		assertEquals(HealthStatus.DEAD, dead.healthStatus());
	}

	@Test
	public void copyPreservesHealthStatusAndBleeding() {
		Combatant fighter = tenHitPointFighter();
		fighter.applyDamage(13);

		Combatant copy = fighter.copy();

		assertEquals(HealthStatus.DYING, copy.healthStatus());
		assertEquals(3, copy.bleeding());
		assertEquals(0, copy.hitPoints());
	}
}
