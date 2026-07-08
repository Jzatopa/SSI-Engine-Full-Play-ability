package engine.combat;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

import org.junit.Test;

import engine.combat.RecoveredBattlefieldGenerator.GeneratedBattlefield;
import engine.combat.RecoveredBattlefieldGenerator.Options;

public class RecoveredBattlefieldGeneratorTest {
	@Test
	public void writesDb35TransformedTileCodesIntoOriginalBufferShape() {
		Options options = new Options();
		options.sectorX = 0;
		options.sectorY = 0;
		options.global4006 = 1;
		options.global4007 = 3;

		GeneratedBattlefield generated = new RecoveredBattlefieldGenerator().generate(options);
		BattlefieldBuffer buffer = generated.buffer();

		assertEquals(7 + 50 * 25, buffer.toByteArray().length);
		assertEquals(0x19, buffer.getTileCode(24, 10));
		assertEquals(0x1A, buffer.getTileCode(25, 11));
		assertEquals(0x1C, buffer.getTileCode(22, 12));
		assertEquals(0x23, buffer.getTileCode(24, 12));
		assertEquals(0x26, buffer.getTileCode(23, 13));
		assertEquals(0x27, buffer.getTileCode(24, 13));
		assertEquals(0x24, buffer.getTileCode(25, 14));
		assertEquals(0x25, buffer.getTileCode(26, 14));
		assertEquals(11, buffer.histogram().values().stream().mapToInt(Integer::intValue).sum());
	}

	@Test
	public void sectorGlobalsShiftTheSameRecoveredPattern() {
		Options left = new Options();
		left.sectorX = 0;
		left.sectorY = 0;
		left.global4006 = 0;
		left.global4007 = 1;

		Options shifted = new Options();
		shifted.sectorX = 1;
		shifted.sectorY = 1;
		shifted.global4006 = 0;
		shifted.global4007 = 1;

		BattlefieldBuffer leftBuffer = new RecoveredBattlefieldGenerator().generate(left).buffer();
		BattlefieldBuffer shiftedBuffer = new RecoveredBattlefieldGenerator().generate(shifted).buffer();

		assertEquals(0x1C, leftBuffer.getTileCode(22, 12));
		assertEquals(0x1C, shiftedBuffer.getTileCode(33, 17));
		assertArrayEquals(new int[] { 0x1B, 0x1C, 0x1D }, leftBuffer.histogram().keySet().stream().mapToInt(Integer::intValue).toArray());
	}
}
