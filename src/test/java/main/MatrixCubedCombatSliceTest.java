package main;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.io.File;

import org.junit.Assume;
import org.junit.Test;

public class MatrixCubedCombatSliceTest {
	private static final String GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";

	@Test
	public void loadsRamWarriorFromOriginalFilesAndResolves() throws Exception {
		Assume.assumeTrue(new File(GAME_DIR, "MON0CHA.DAX").exists());

		MatrixCubedCombatSlice.CombatReport report = MatrixCubedCombatSlice.run(GAME_DIR, 52, 52017L);

		assertEquals("RAM WARRIOR", report.enemyName);
		assertTrue(report.victory);
		assertEquals(0, report.combatResult);
		assertTrue(report.render().contains("Source: MON0CHA.DAX block 52"));
	}
}
