package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import common.FileMap;
import data.ContentType;
import data.ResourceLoader;
import data.character.AbstractCharacter;
import data.character.BuckRogersEmbeddedItem;
import data.character.BuckRogersItemCatalogBlock;
import data.character.BuckRogersMonsterInventoryBlock;
import data.character.CharacterBuckRogers;
import data.character.CharacterValues;

public class RecoveredItemOptionSelectorTest {
	private static final Path GAME_DIR = Path.of("/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX");

	@Test
	public void mapsOnlyEquippedRecoveredItemsThroughOriginalItems() throws Exception {
		AbstractCharacter.configValues(CharacterValues.BUCK_ROGERS);
		ResourceLoader resources = new ResourceLoader(new FileMap(GAME_DIR.toString()));
		CharacterBuckRogers monster = resources.find(52, CharacterBuckRogers.class, ContentType.MONCHA).get();
		BuckRogersItemCatalogBlock catalog = resources.find(1, BuckRogersItemCatalogBlock.class, ContentType.ITEM).get();
		BuckRogersMonsterInventoryBlock inventory = resources.find(52, BuckRogersMonsterInventoryBlock.class, ContentType.MONITM).get();
		monster.attachRecoveredItems(inventory.recoveredItems(catalog));
		List<BuckRogersEmbeddedItem> items = new ArrayList<>();
		monster.getItems().filter(BuckRogersEmbeddedItem.class::isInstance)
			.map(BuckRogersEmbeddedItem.class::cast).forEach(items::add);
		RecoveredItemOptionSelector selector = new RecoveredItemOptionSelector(OriginalItemCombatTable.load(GAME_DIR));

		assertEquals(2, selector.equippedOptions(items).size());
		assertTrue(selector.evidenceSummary(items).contains("through ITEMS"));
		assertTrue(selector.evidenceSummary(items).contains("damage, range, and dispatch remain unresolved"));
		CombatEncounterFactory.MonsterSeed seed = new SsiEclCombatAdapter(
			new EclCombatBridge(), OriginalItemCombatTable.load(GAME_DIR)).toSeed(52, monster);
		assertTrue(seed.evidence().contains("Original equipped-item option walk mapped 2 item(s) through ITEMS"));
	}
}
