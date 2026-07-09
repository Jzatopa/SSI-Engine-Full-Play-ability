package data.character;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.annotation.Nonnull;

import common.ByteBufferWrapper;
import data.Content;
import data.ContentType;

/**
 * MON0ITM block split into evidence-backed 62-byte inventory records.
 * ITEM0 matching ignores only the original-code-proven mutable equipped and
 * quantity bytes. The first 46 bytes and all other payload differences remain unresolved.
 */
public final class BuckRogersMonsterInventoryBlock extends Content {
	public static final int RECORD_SIZE = 62;
	public static final int ITEM_PAYLOAD_OFFSET = 46;
	private final byte[] records;

	public BuckRogersMonsterInventoryBlock(@Nonnull ByteBufferWrapper data, @Nonnull ContentType type) {
		if (data.capacity() % RECORD_SIZE != 0) {
			throw new IllegalArgumentException("MON0ITM block size is not divisible by 62: " + data.capacity());
		}
		records = Arrays.copyOf(data.array(), data.capacity());
	}

	public List<BuckRogersEmbeddedItem> recoveredItems(BuckRogersItemCatalogBlock catalog) {
		List<BuckRogersEmbeddedItem> result = new ArrayList<>();
		for (int recordOffset = 0; recordOffset < records.length; recordOffset += RECORD_SIZE) {
			int offset = recordOffset + ITEM_PAYLOAD_OFFSET;
			byte[] candidate = Arrays.copyOfRange(records, offset,
				offset + BuckRogersItemCatalogBlock.TEMPLATE_SIZE);
			int templateIndex = catalog.stableFieldIndex(candidate);
			if (templateIndex >= 0) result.add(new BuckRogersEmbeddedItem(templateIndex, offset, candidate));
		}
		return List.copyOf(result);
	}

	/** Retained for callers that specifically need the older byte-exact subset. */
	public List<BuckRogersEmbeddedItem> exactEmbeddedItems(BuckRogersItemCatalogBlock catalog) {
		return recoveredItems(catalog).stream()
			.filter(item -> catalog.exactIndex(item.raw()) >= 0).toList();
	}

	public int size() { return records.length; }
	public int recordCount() { return records.length / RECORD_SIZE; }
}
