package engine.combat;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public final class RecoveredBattlefieldGenerator {
	public enum Terrain {
		MARS("MARSCOM.DAX", 1), VENUS("VENUSCOM.DAX", 1);

		private final String tileFile;
		private final int blockId;

		Terrain(String tileFile, int blockId) {
			this.tileFile = tileFile;
			this.blockId = blockId;
		}

		public String tileFile() {
			return tileFile;
		}

		public int blockId() {
			return blockId;
		}
	}

	public static final class Options {
		public Terrain terrain = Terrain.MARS;
		public int sectorX = 0;
		public int sectorY = 0;
		public int global4006 = 1;
		public int global4007 = 3;
	}

	public static final class GeneratedBattlefield {
		private final BattlefieldBuffer buffer;
		private final Options options;
		private final List<String> evidence;

		private GeneratedBattlefield(BattlefieldBuffer buffer, Options options, List<String> evidence) {
			this.buffer = buffer;
			this.options = options;
			this.evidence = List.copyOf(evidence);
		}

		public BattlefieldBuffer buffer() {
			return buffer;
		}

		public Options options() {
			return options;
		}

		public List<String> evidence() {
			return evidence;
		}

		public Map<Integer, Integer> tileHistogram() {
			return buffer.histogram();
		}
	}

	public GeneratedBattlefield generate(Options options) {
		BattlefieldBuffer buffer = new BattlefieldBuffer();
		List<String> evidence = new ArrayList<>();
		evidence.add("Buffer shape from recovered writes: 7-byte header + 50 columns x 25 rows.");
		evidence.add("Tile write primitive ported from GAME.OVR 0000:db35 / file offset 56125.");

		writeE3ab(buffer, options, evidence);
		writeE2f5(buffer, options, evidence);

		return new GeneratedBattlefield(buffer, copy(options), evidence);
	}

	private void writeE3ab(BattlefieldBuffer buffer, Options options, List<String> evidence) {
		if (options.global4006 != 1) {
			return;
		}
		evidence.add("Applied recovered 0000:e3ab branch for global 0x4006 == 1: local tile cluster 0x18/0x19.");
		writeDb35(buffer, options, 0x18, 0, 3);
		writeDb35(buffer, options, 0x18, 0, 4);
		writeDb35(buffer, options, 0x19, 1, 3);
		writeDb35(buffer, options, 0x19, 1, 4);
	}

	private void writeE2f5(BattlefieldBuffer buffer, Options options, List<String> evidence) {
		if (options.global4007 == 1) {
			evidence.add("Applied recovered 0000:e2f5 branch for global 0x4007 == 1: repeated 0x1a/0x1b/0x1c run.");
			for (int local = 2; local <= 4; local++) {
				writeDb35(buffer, options, 0x1b, local, local - 1);
				writeDb35(buffer, options, 0x1c, local, local);
				writeDb35(buffer, options, 0x1a, local, local + 1);
			}
		} else if (options.global4007 == 3) {
			evidence.add("Applied recovered 0000:e2f5 branch for global 0x4007 == 3: explicit 0x1b/0x1d/0x22/0x25/0x26/0x23/0x24 placements.");
			writeDb35(buffer, options, 0x1b, 2, 1);
			writeDb35(buffer, options, 0x1d, 2, 2);
			writeDb35(buffer, options, 0x22, 2, 3);
			writeDb35(buffer, options, 0x25, 3, 2);
			writeDb35(buffer, options, 0x26, 3, 3);
			writeDb35(buffer, options, 0x23, 4, 4);
			writeDb35(buffer, options, 0x24, 4, 5);
		}
	}

	private void writeDb35(BattlefieldBuffer buffer, Options options, int rawTile, int localY, int localX) {
		int x = options.sectorX * 6 + options.sectorY * 5 + 0x15 + localX;
		int y = options.sectorY * 5 + 10 + localY;
		buffer.setOriginalRawTile(x, y, rawTile);
	}

	private Options copy(Options options) {
		Options copy = new Options();
		copy.terrain = options.terrain;
		copy.sectorX = options.sectorX;
		copy.sectorY = options.sectorY;
		copy.global4006 = options.global4006;
		copy.global4007 = options.global4007;
		return copy;
	}
}
