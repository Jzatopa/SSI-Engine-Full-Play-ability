package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

public class CombatUiBridgeTest {
	@Test
	public void headlessBridgeReturnsSessionResultAndTranscript() {
		CombatEncounterFactory.MonsterSeed weak = new CombatEncounterFactory.MonsterSeed(
			1, "TEST MONSTER", 8, 10, 20, 1, 1, 4, "weak deterministic test monster"
		);
		CombatState state = new CombatEncounterFactory().create(List.of(weak));
		CombatSession session = CombatSession.eclCombat(state, List.of(weak));

		CombatSessionResult result = new HeadlessCombatUiBridge(52017L, 100).resolve(session);

		assertEquals(0, result.combatResult());
		assertEquals("HeadlessCombatUiBridge", result.resolverName());
		assertFalse(result.interactive());
		assertTrue(result.victory());
		assertTrue(result.transcript().contains("COMBAT_RESULT=0"));
		assertNotNull(result.state());
	}

	@Test
	public void eclCombatBridgeDelegatesToInjectedUiBridge() {
		CombatUiBridge fake = session -> CombatSessionResult.of(
			0,
			session.state(),
			"fake interactive handoff",
			0,
			true,
			"FakeCombatUiBridge"
		);

		EclCombatBridge.EclCombatResult result = new EclCombatBridge(new CombatEncounterFactory(), fake)
			.resolve(List.of(CombatEncounterFactory.MonsterSeed.ratwurst()));

		assertEquals(0, result.combatResult());
		assertTrue(result.interactive());
		assertEquals("FakeCombatUiBridge", result.resolverName());
		assertTrue(result.transcript().contains("fake interactive"));
	}

	@Test
	public void legacyBridgePreservesPreReconstructionCombatSuccess() {
		CombatEncounterFactory.MonsterSeed monster = new CombatEncounterFactory.MonsterSeed(
			1, "UNIVERSAL TEST", 20, 5, 15, 2, 5, 6, "profile-neutral test"
		);
		EclCombatBridge.EclCombatResult result = new EclCombatBridge(
			new CombatEncounterFactory(), new LegacyGoldBoxCombatUiBridge()).resolve(List.of(monster));

		assertEquals(0, result.combatResult());
		assertEquals("LegacyGoldBoxCombatUiBridge", result.resolverName());
		assertFalse(result.interactive());
		assertTrue(result.transcript().contains("legacy COMBAT_RESULT=0"));
	}
}
