package data.character;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.nio.ByteBuffer;
import java.util.Arrays;

import common.ByteBufferWrapper;
import common.FileMap;
import data.ContentType;
import data.ResourceLoader;
import engine.combat.CombatEncounterFactory;
import engine.combat.SsiEclCombatAdapter;

import org.junit.Test;

public class BuckRogersMonsterInventoryBlockTest {
	private static final String GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";

	@Test
	public void recoversStableItemFieldsAndMutableStateInMonster52Records() {
		ResourceLoader resources = new ResourceLoader(new FileMap(GAME_DIR));
		BuckRogersItemCatalogBlock catalog = resources.find(1, BuckRogersItemCatalogBlock.class, ContentType.ITEM).get();
		BuckRogersMonsterInventoryBlock inventory = resources.find(52, BuckRogersMonsterInventoryBlock.class, ContentType.MONITM).get();

		assertEquals(91, catalog.size());
		assertEquals(310, inventory.size());
		assertEquals(5, inventory.recordCount());
		assertEquals(1, inventory.exactEmbeddedItems(catalog).size());
		assertEquals(4, inventory.recoveredItems(catalog).size());
		BuckRogersEmbeddedItem item = inventory.exactEmbeddedItems(catalog).get(0);
		assertEquals(39, item.templateIndex());
		assertEquals(3, item.itemPointer());
		assertEquals(232, item.initializerOffset());
		BuckRogersEmbeddedItem equipped = inventory.recoveredItems(catalog).get(0);
		assertEquals(49, equipped.templateIndex());
		assertTrue(equipped.isEquipped());
		assertEquals(50, equipped.quantity());
	}

	@Test
	public void ignoresExactTemplateBytesOutsideAlignedRecordPayload() {
		ResourceLoader resources = new ResourceLoader(new FileMap(GAME_DIR));
		BuckRogersItemCatalogBlock catalog = resources.find(1, BuckRogersItemCatalogBlock.class, ContentType.ITEM).get();
		byte[] record = new byte[BuckRogersMonsterInventoryBlock.RECORD_SIZE];
		System.arraycopy(catalog.template(39), 0, record, 0, BuckRogersItemCatalogBlock.TEMPLATE_SIZE);
		Arrays.fill(record, BuckRogersMonsterInventoryBlock.ITEM_PAYLOAD_OFFSET, record.length, (byte) 0xFF);
		BuckRogersMonsterInventoryBlock inventory = new BuckRogersMonsterInventoryBlock(
			new ByteBufferWrapper(ByteBuffer.wrap(record)), ContentType.MONITM);

		assertTrue(inventory.exactEmbeddedItems(catalog).isEmpty());
	}

	@Test
	public void missingMonsterInventoryBlockDoesNotBecomeSyntheticInventory() {
		ResourceLoader resources = new ResourceLoader(new FileMap(GAME_DIR));
		assertFalse(resources.find(47, BuckRogersMonsterInventoryBlock.class, ContentType.MONITM).isPresent());
	}

	@Test
	public void characterAcceptsEvidenceWithoutClaimingEquippedState() throws Exception {
		FileMap files = new FileMap(GAME_DIR);
		ResourceLoader resources = new ResourceLoader(files);
		AbstractCharacter.configValues(CharacterValues.BUCK_ROGERS);
		CharacterBuckRogers character = resources.find(52, CharacterBuckRogers.class, ContentType.MONCHA).get();
		CharacterBuckRogers withoutInventory = resources.find(52, CharacterBuckRogers.class, ContentType.MONCHA).get();
		BuckRogersItemCatalogBlock catalog = resources.find(1, BuckRogersItemCatalogBlock.class, ContentType.ITEM).get();
		BuckRogersMonsterInventoryBlock inventory = resources.find(52, BuckRogersMonsterInventoryBlock.class, ContentType.MONITM).get();
		character.attachRecoveredItems(inventory.recoveredItems(catalog));

		assertEquals(4, character.getItems().size());
		assertTrue(character.getItems().get(0) instanceof BuckRogersEmbeddedItem);
		assertTrue(character.isEquipped(character.getItems().get(0)));
		CombatEncounterFactory.MonsterSeed seed = new SsiEclCombatAdapter().toSeed(52, character);
		CombatEncounterFactory.MonsterSeed seedWithoutInventory = new SsiEclCombatAdapter().toSeed(52, withoutInventory);
		assertTrue(seed.evidence(), seed.evidence().contains("template 49 itemptr 11 equipped true quantity 50"));
		assertTrue(seed.evidence().contains("equipped bit and quantity come from original GAME.OVR"));
		assertEquals(seedWithoutInventory.damageMin(), seed.damageMin());
		assertEquals(seedWithoutInventory.damageMax(), seed.damageMax());
	}
}
