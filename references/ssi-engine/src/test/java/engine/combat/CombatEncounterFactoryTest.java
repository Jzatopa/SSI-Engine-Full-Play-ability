package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

import engine.combat.RecoveredBattlefieldGenerator.Options;
import engine.combat.RecoveredBattlefieldGenerator.Terrain;

public class CombatEncounterFactoryTest {
	@Test
	public void createsCombatStateFromEclMonsterSeeds() {
		CombatEncounterFactory.MonsterSeed seed = new CombatEncounterFactory.MonsterSeed(
			52, "RAM WARRIOR", 30, 5, 13, 3, 8, 6, "test seed"
		);

		CombatState state = new CombatEncounterFactory().create(List.of(seed));

		assertEquals(6, state.livingParty().size());
		assertEquals(1, state.livingMonsters().size());
		assertEquals("RAM WARRIOR", state.livingMonsters().get(0).name());
		assertEquals(30, state.livingMonsters().get(0).maxHitPoints());
		assertTrue(state.evidence().stream().anyMatch(s -> s.contains("CombatEncounterFactory")));
	}

	@Test
	public void usesVmPartySeedsWhenProvided() {
		CombatEncounterFactory.MonsterSeed monster = new CombatEncounterFactory.MonsterSeed(
			52, "RAM WARRIOR", 30, 5, 13, 3, 8, 6, "test monster"
		);
		CombatEncounterFactory.PartySeed party = new CombatEncounterFactory.PartySeed(
			1, "BUCK", 44, 3, 12, 4, 9, 7, "test party"
		);

		CombatState state = new CombatEncounterFactory().create(List.of(monster), List.of(party));

		assertEquals(1, state.livingParty().size());
		assertEquals("BUCK", state.livingParty().get(0).name());
		assertEquals(44, state.livingParty().get(0).maxHitPoints());
		assertTrue(state.evidence().stream().anyMatch(s -> s.contains("VM party member seed")));
	}

	@Test
	public void preservesRecoveredBattlefieldTerrainOptions() {
		CombatEncounterFactory.MonsterSeed monster = new CombatEncounterFactory.MonsterSeed(
			52, "RAM WARRIOR", 30, 5, 13, 3, 8, 6, "test monster"
		);
		Options options = new Options();
		options.terrain = Terrain.VENUS;

		CombatState state = new CombatEncounterFactory().create(List.of(monster), List.of(), options);

		assertEquals(Terrain.VENUS, state.battlefieldOptions().terrain);
		assertTrue(state.evidence().stream().anyMatch(s -> s.contains("VENUSCOM.DAX")));
	}
}
