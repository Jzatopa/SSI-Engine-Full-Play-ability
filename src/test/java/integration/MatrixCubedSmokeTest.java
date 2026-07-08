package integration;

import static character.CharacterGender.FEMALE;
import static character.CharacterGender.MALE;
import static character.buckrogers.CharacterClassBuckRogers.ROCKETJOCK;
import static character.buckrogers.CharacterClassBuckRogers.WARRIOR;
import static character.buckrogers.CharacterRaceBuckRogers.MARTIAN;
import static character.buckrogers.CharacterRaceBuckRogers.TERRAN;
import static java.nio.file.StandardOpenOption.CREATE;
import static java.nio.file.StandardOpenOption.READ;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;
import static java.nio.file.StandardOpenOption.WRITE;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.io.File;
import java.nio.channels.FileChannel;
import java.nio.file.Files;
import java.nio.file.Path;

import org.junit.Assume;
import org.junit.Before;
import org.junit.Test;

import character.ClassSelection;
import common.FileMap;
import data.ResourceLoader;
import data.character.AbstractCharacter;
import engine.EngineConfiguration;
import engine.VirtualMemory;
import engine.character.CharacterSheetImpl;
import engine.character.PlayerDataFactory;
import engine.character.PlayerDataType;
import io.vavr.control.Try;
import main.MatrixCubedCombatScene;
import main.MatrixCubedCombatScene.Result;

/**
 * Headless end-to-end smoke test for Buck Rogers: Matrix Cubed.
 *
 * <p>Drives as much of the real game loop as is practical without a display:
 * game-data detection, character creation/party setup through the real
 * {@link PlayerDataFactory}, the real ECL/VM opcode path into the COMBAT
 * handler (via {@link MatrixCubedCombatScene#runToCombat}, which shares the
 * same VM/ECL/EclCombatBridge wiring as the interactive build), and a
 * save/load round trip through {@link VirtualMemory#saveTo} /
 * {@link VirtualMemory#loadFrom} (the same primitives {@code SaveHandler} and
 * {@code LoadHandler} use).</p>
 *
 * <p>This is the regression net for the ongoing combat-porting effort. All
 * tests skip via {@link Assume} when the original game files are not present
 * locally, matching the pattern in {@link LocalGoldBoxCompatibilityTest} and
 * {@code main.MatrixCubedCombatSliceTest}. Assertions are deliberately
 * structural (a party was created, combat resolved to a known
 * {@code COMBAT_RESULT}, saved files round-trip) rather than pinned to
 * specific gameplay values that have not been independently confirmed
 * against the original binary.</p>
 */
public class MatrixCubedSmokeTest {
	private static final String GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";

	private File gameDir;

	@Before
	public void locateGameDir() {
		gameDir = new File(GAME_DIR);
		Assume.assumeTrue("Matrix Cubed original game files not found at " + GAME_DIR, gameDir.isDirectory());
	}

	@Test
	public void gameDataDetectsAsBuckRogersMatrixCubed() throws Exception {
		EngineConfiguration cfg = new EngineConfiguration(new FileMap(gameDir.getAbsolutePath()));

		assertEquals("Buck Rogers - Matrix Cubed", cfg.getGameName());
		assertEquals(PlayerDataType.BUCK_ROGERS, cfg.getCharacterFormat());
	}

	@Test
	public void characterCreationBuildsAPlayablePartyOfTwo() throws Exception {
		FileMap files = new FileMap(gameDir.getAbsolutePath());
		EngineConfiguration cfg = new EngineConfiguration(files);
		AbstractCharacter.configValues(cfg.getCharacterValues());
		PlayerDataFactory playerDataFactory = new PlayerDataFactory(new ResourceLoader(files), cfg);
		VirtualMemory memory = new VirtualMemory(cfg);

		AbstractCharacter hero = playerDataFactory.createCharacter(TERRAN, MALE, ClassSelection.of(WARRIOR));
		hero.setName("BUCK");
		memory.addPartyMember(new CharacterSheetImpl(cfg.getFlavor(), hero));

		AbstractCharacter second = playerDataFactory.createCharacter(MARTIAN, FEMALE, ClassSelection.of(ROCKETJOCK));
		second.setName("WILMA");
		memory.addPartyMember(new CharacterSheetImpl(cfg.getFlavor(), second));

		assertEquals(2, memory.getPartyMemberCount());
		assertEquals("BUCK", memory.getPartyMemberAsCharacterSheet(0).getName().toString());
		assertEquals("WILMA", memory.getPartyMemberAsCharacterSheet(1).getName().toString());
		assertTrue(memory.getPartyMemberAsCharacterSheet(0).getClassDescription().toString().contains("WARRIOR"));
		assertTrue(memory.getPartyMemberAsCharacterSheet(1).getRaceDescription().toString().contains("MARTIAN"));
	}

	@Test
	public void eclScriptDrivesRealVmThroughLoadMonIntoResolvedCombat() throws Exception {
		Result result = MatrixCubedCombatScene.runToCombat(gameDir.getAbsolutePath(),
			party -> party.addMember(TERRAN, MALE, ClassSelection.of(WARRIOR), "BUCK"));

		int combatResult = result.memory().getCombatResult();
		assertTrue("COMBAT_RESULT should be a resolved value (0=victory, 1=other), was " + combatResult,
			combatResult == 0 || combatResult == 1);
		assertEquals(1, result.memory().getPartyMemberCount());
		assertEquals("BUCK", result.memory().getPartyMemberAsCharacterSheet(0).getName().toString());
	}

	@Test
	public void saveThenLoadRoundTripsPartyAndEngineState() throws Exception {
		FileMap files = new FileMap(gameDir.getAbsolutePath());
		EngineConfiguration cfg = new EngineConfiguration(files);
		AbstractCharacter.configValues(cfg.getCharacterValues());
		PlayerDataFactory playerDataFactory = new PlayerDataFactory(new ResourceLoader(files), cfg);

		VirtualMemory original = new VirtualMemory(cfg);
		AbstractCharacter hero = playerDataFactory.createCharacter(TERRAN, MALE, ClassSelection.of(WARRIOR));
		hero.setName("BUCK");
		original.addPartyMember(new CharacterSheetImpl(cfg.getFlavor(), hero));

		AbstractCharacter second = playerDataFactory.createCharacter(MARTIAN, FEMALE, ClassSelection.of(ROCKETJOCK));
		second.setName("WILMA");
		original.addPartyMember(new CharacterSheetImpl(cfg.getFlavor(), second));

		original.setCurrentECL(17);
		original.setAreaValues(3, 2, 1);
		original.setCombatResult(0);

		Path savesDir = Files.createTempDirectory("matrix-cubed-smoke-save");
		File saveGame = new File(savesDir.toFile(), "savegame.dat");

		// Write, mirroring engine.input.SaveHandler's writeCharacter/writeMemory.
		for (int i = 0; i < original.getPartyMemberCount(); i++) {
			File charFile = new File(savesDir.toFile(), String.format("chrdate%d.dat", i + 1));
			FileChannel fc = FileChannel.open(charFile.toPath(), CREATE, WRITE, TRUNCATE_EXISTING);
			try {
				original.writePartyMember(i, fc);
			} finally {
				fc.close();
			}
		}
		FileChannel saveFc = FileChannel.open(saveGame.toPath(), CREATE, WRITE, TRUNCATE_EXISTING);
		try {
			original.saveTo(saveFc);
		} finally {
			saveFc.close();
		}

		assertTrue("savegame.dat should be non-empty after saving", saveGame.length() > 0);
		for (int i = 0; i < original.getPartyMemberCount(); i++) {
			File charFile = new File(savesDir.toFile(), String.format("chrdate%d.dat", i + 1));
			assertTrue(charFile.getName() + " should exist after saving", charFile.isFile());
			assertTrue(charFile.getName() + " should be non-empty after saving", charFile.length() > 0);
		}

		// Read back into a fresh VirtualMemory, mirroring engine.input.LoadHandler's
		// readMemory/readCharacter (minus the Engine/UI plumbing LoadHandler also drives).
		VirtualMemory reloaded = new VirtualMemory(cfg);
		FileChannel loadFc = FileChannel.open(saveGame.toPath(), READ);
		try {
			reloaded.loadFrom(loadFc);
		} finally {
			loadFc.close();
		}
		for (int i = 0; i < 8; i++) {
			File charFile = new File(savesDir.toFile(), String.format("chrdate%d.dat", i + 1));
			if (!charFile.isFile()) {
				break;
			}
			Try<AbstractCharacter> loaded = playerDataFactory.loadCharacter(charFile);
			assertTrue("chrdate" + (i + 1) + ".dat should decode back into a character", loaded.isSuccess());
			reloaded.addPartyMember(new CharacterSheetImpl(cfg.getFlavor(), loaded.get()));
		}

		assertEquals(original.getPartyMemberCount(), reloaded.getPartyMemberCount());
		assertEquals("BUCK", reloaded.getPartyMemberAsCharacterSheet(0).getName().toString());
		assertEquals("WILMA", reloaded.getPartyMemberAsCharacterSheet(1).getName().toString());
		assertEquals(17, reloaded.getCurrentECL());
		assertEquals(3, reloaded.getAreaValue(0));
		assertEquals(2, reloaded.getAreaValue(1));
		assertEquals(1, reloaded.getAreaValue(2));
		assertEquals(original.getCombatResult(), reloaded.getCombatResult());
	}
}
