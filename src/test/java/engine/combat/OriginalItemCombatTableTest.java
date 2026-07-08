package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertThrows;
import static org.junit.Assert.assertTrue;

import java.nio.file.Path;

import org.junit.Test;

public class OriginalItemCombatTableTest {
	private static final Path GAME_DIR = Path.of("/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX");

	@Test
	public void loadsOriginalItemsWithProvenItemPointerAlignment() throws Exception {
		OriginalItemCombatTable table = OriginalItemCombatTable.load(GAME_DIR);

		assertEquals(39, table.records().size());
		assertEquals("00 00 00 00 00 00 00 00 00", table.recordForItemPointer(0).rawHex());
		assertEquals("00 04 00 00 01 03 00 00 00", table.recordForItemPointer(1).rawHex());
		assertEquals(3, table.recordForItemPointer(1).unsignedByte(5));
		assertTrue(table.evidenceBoundary().contains("unresolved"));
	}

	@Test
	public void rejectsItemPointersOutsideOriginalTable() throws Exception {
		OriginalItemCombatTable table = OriginalItemCombatTable.load(GAME_DIR);
		assertThrows(IllegalArgumentException.class, () -> table.recordForItemPointer(39));
	}
}
