package integration;

import static data.ContentType.MONCHA;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.io.File;

import org.junit.Assume;
import org.junit.Test;

import common.FileMap;
import data.ContentFile;
import data.Resource;
import data.ResourceLoader;
import data.character.AbstractCharacter;
import data.character.CharacterForgottenRealms;
import engine.EngineConfiguration;
import engine.character.PlayerDataFactory;
import engine.character.PlayerDataType;
import engine.combat.CombatEncounterFactory;
import engine.combat.EclCombatBridge;
import engine.combat.SsiEclCombatAdapter;
import main.CombatUiBridgeSelector;

/** Optional integration tests backed by user-supplied original game files. */
public class LocalGoldBoxCompatibilityTest {
	private static final String DEFAULT_CURSE_DIR = "/home/jzatopa/Downloads/curseoftheazurebonds";
	private static final String[][] ADDITIONAL_GAMES = {
		{"Pool of Radiance", "/home/jzatopa/Downloads/v22.1.0/poolrad"},
		{"Pools of Darkness", "/home/jzatopa/Downloads/v22.1.0/pod"},
		{"Secret of the Silver Blades", "/home/jzatopa/Downloads/v22.1.0/ssb"}
	};

	@Test
	public void curseProfileAndAllKnownContentFilesLoad() throws Exception {
		File dir = curseDir();
		Assume.assumeTrue(dir.isDirectory());
		EngineConfiguration config = assertGameLoads("Curse of the Azure Bonds", dir);
		assertEquals(PlayerDataType.FORGOTTEN_REALMS, config.getCharacterFormat());
	}

	@Test
	public void additionalLocalAdndProfilesAndKnownContentFilesLoad() throws Exception {
		for (String[] game : ADDITIONAL_GAMES) {
			File dir = new File(game[1]);
			Assume.assumeTrue(dir.isDirectory());
			EngineConfiguration config = assertGameLoads(game[0], dir);
			assertEquals(PlayerDataType.FORGOTTEN_REALMS, config.getCharacterFormat());
		}
	}

	@Test
	public void curseMonsterMapsThroughUniversalCombatSeedWithoutBuckTypes() throws Exception {
		File dir = curseDir();
		Assume.assumeTrue(dir.isDirectory());

		FileMap files = new FileMap(dir.getAbsolutePath());
		EngineConfiguration config = new EngineConfiguration(files);
		AbstractCharacter.configValues(config.getCharacterValues());
		ResourceLoader resources = new ResourceLoader(files);
		PlayerDataFactory characters = new PlayerDataFactory(resources, config);
		java.util.List<AbstractCharacter> monsters = new java.util.ArrayList<>();
		for (int monsterId : resources.idsFor(MONCHA)) {
			Resource<? extends AbstractCharacter> loaded = characters.loadCharacter(monsterId);
			assertTrue("Could not load Curse monster " + monsterId, loaded.isPresentAndSuccess());
			assertTrue(loaded.get() instanceof CharacterForgottenRealms);
			CombatEncounterFactory.MonsterSeed mapped = new SsiEclCombatAdapter().toSeed(monsterId, loaded.get());
			assertEquals(monsterId, mapped.sourceId());
			assertTrue(mapped.hitPoints() > 0);
			monsters.add(loaded.get());
		}
		assertFalse(monsters.isEmpty());

		int monsterId = resources.idsFor(MONCHA).head();
		CombatEncounterFactory.MonsterSeed seed = new SsiEclCombatAdapter().toSeed(monsterId, monsters.get(0));
		assertEquals(monsterId, seed.sourceId());
		assertTrue(seed.hitPoints() > 0);
		assertFalse(seed.evidence().contains("MON0CHA"));
		assertTrue(seed.evidence().contains("title-specific inventory"));

		EclCombatBridge bridge = new EclCombatBridge(new CombatEncounterFactory(),
			CombatUiBridgeSelector.select(config.getGameName(), dir.toPath()).get());
		EclCombatBridge.EclCombatResult result = new SsiEclCombatAdapter(bridge)
			.resolveQueued(java.util.List.of(monsters.get(0)));
		assertEquals(0, result.combatResult());
		assertEquals("LegacyGoldBoxCombatUiBridge", result.resolverName());
	}

	private static File curseDir() {
		String configured = System.getProperty("ssi.test.curse.dir",
			System.getenv().getOrDefault("SSI_CURSE_DIR", DEFAULT_CURSE_DIR));
		return new File(configured);
	}

	private static EngineConfiguration assertGameLoads(String expectedName, File dir) throws Exception {
		FileMap files = new FileMap(dir.getAbsolutePath());
		EngineConfiguration config = new EngineConfiguration(files);
		assertEquals(expectedName, config.getGameName());
		File[] children = dir.listFiles();
		assertTrue(children != null);
		for (File child : children) {
			if (child.isFile() && ContentFile.isKnown(child)) {
				assertTrue("Could not decode " + child, ContentFile.create(child).isSuccess());
			}
		}
		return config;
	}
}
