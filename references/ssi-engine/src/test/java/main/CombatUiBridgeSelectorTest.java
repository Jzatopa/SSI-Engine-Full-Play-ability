package main;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.nio.file.Path;

import org.junit.Test;

import engine.combat.LegacyGoldBoxCombatUiBridge;

public class CombatUiBridgeSelectorTest {
	@Test
	public void selectsMatrixBridgeOnlyForMatrixCubed() {
		Path gameDir = Path.of("game-data");
		assertTrue(CombatUiBridgeSelector.select("Buck Rogers - Matrix Cubed", gameDir).isPresent());
		assertEquals(LegacyGoldBoxCombatUiBridge.class,
			CombatUiBridgeSelector.select("Curse of the Azure Bonds", gameDir).get().getClass());
		assertEquals(LegacyGoldBoxCombatUiBridge.class,
			CombatUiBridgeSelector.select("Buck Rogers - Countdown to Doomsday", gameDir).get().getClass());
	}
}
