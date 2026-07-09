package engine.combat;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import java.nio.file.Files;
import java.nio.file.Path;

import org.junit.Assume;
import org.junit.Test;

import engine.combat.CombatAssetLoader.Assets;

public class CombatAssetLoaderTest {
	private static final Path GAME_DIR = Path.of("generated/liveplay/first_map_capture/game");

	@Test
	public void loadsOriginalCombatAssetsWhenLocalGameFilesArePresent() throws Exception {
		Assume.assumeTrue(Files.exists(GAME_DIR.resolve("MARSCOM.DAX")));
		Assume.assumeTrue(Files.exists(GAME_DIR.resolve("CPIC1.DAX")));
		Assume.assumeTrue(Files.exists(GAME_DIR.resolve("BORDERS.DAX")));

		Assets assets = CombatAssetLoader.load(GAME_DIR);

		assertTrue(assets.marsTiles().size() >= 42);
		assertTrue(assets.venusTiles().size() >= 44);
		assertTrue(assets.cpicSprites().size() >= 100);
		assertTrue(assets.borders().size() >= 12);
		assertNotNull(assets.cpic(139)); // ratwurst-like creature used by the vertical slice
		assertNotNull(assets.cpic(1));   // party humanoid sprite
	}
}
