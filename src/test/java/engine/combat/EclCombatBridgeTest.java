package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

public class EclCombatBridgeTest {
	@Test
	public void resolvesEclMonsterSeedsToGoldBoxCombatResult() {
		CombatEncounterFactory.MonsterSeed weak = new CombatEncounterFactory.MonsterSeed(
			1, "TEST MONSTER", 8, 10, 20, 1, 1, 4, "weak deterministic test monster"
		);

		EclCombatBridge.EclCombatResult result = new EclCombatBridge(new CombatEncounterFactory(), 52017L)
			.resolve(List.of(weak));

		assertEquals(0, result.combatResult());
		assertTrue(result.victory());
		assertTrue(result.transcript().contains("COMBAT_RESULT=0"));
		assertTrue(result.state().evidence().stream().anyMatch(s -> s.contains("ECL/VM monster seed")));
	}
}
