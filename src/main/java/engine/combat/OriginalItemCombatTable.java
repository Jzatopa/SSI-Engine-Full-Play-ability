package engine.combat;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/** Loads the original 39x9-byte ITEMS table used at runtime as DAT_0000_536e. */
public final class OriginalItemCombatTable {
	public static final int RECORD_SIZE = 9;
	public static final int EXPECTED_RECORD_COUNT = 39;

	public static final class Record {
		private final int itemPointer;
		private final byte[] raw;

		private Record(int itemPointer, byte[] raw) {
			this.itemPointer = itemPointer;
			this.raw = raw;
		}

		public int itemPointer() { return itemPointer; }
		public int unsignedByte(int offset) {
			if (offset < 0 || offset >= RECORD_SIZE) throw new IndexOutOfBoundsException("ITEMS byte " + offset);
			return Byte.toUnsignedInt(raw[offset]);
		}
		public byte[] raw() { return Arrays.copyOf(raw, raw.length); }
		public String rawHex() {
			StringBuilder out = new StringBuilder();
			for (int i = 0; i < raw.length; i++) {
				if (i > 0) out.append(' ');
				out.append(String.format("%02x", unsignedByte(i)));
			}
			return out.toString();
		}
	}

	private final List<Record> records;

	private OriginalItemCombatTable(List<Record> records) {
		this.records = List.copyOf(records);
	}

	public static OriginalItemCombatTable load(Path gameDir) throws IOException {
		Path path = gameDir.resolve("ITEMS");
		byte[] data = Files.readAllBytes(path);
		if (data.length != EXPECTED_RECORD_COUNT * RECORD_SIZE) {
			throw new IOException("Expected ITEMS to contain 39x9 bytes, got " + data.length + " at " + path);
		}
		List<Record> records = new ArrayList<>();
		for (int index = 0; index < EXPECTED_RECORD_COUNT; index++) {
			records.add(new Record(index, Arrays.copyOfRange(data, index * RECORD_SIZE, (index + 1) * RECORD_SIZE)));
		}
		return new OriginalItemCombatTable(records);
	}

	public Record recordForItemPointer(int itemPointer) {
		if (itemPointer < 0 || itemPointer >= records.size()) {
			throw new IllegalArgumentException("ITEM0 itemptr outside original ITEMS table: " + itemPointer);
		}
		return records.get(itemPointer);
	}

	public List<Record> records() { return Collections.unmodifiableList(records); }

	public String evidenceBoundary() {
		return "Original ITEMS bytes loaded with proven itemptr*9 alignment; numeric field names and score weights remain unresolved.";
	}
}
