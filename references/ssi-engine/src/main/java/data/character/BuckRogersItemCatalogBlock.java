package data.character;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.annotation.Nonnull;

import common.ByteBufferWrapper;
import data.Content;
import data.ContentType;

/** Original ITEM0.DAX block 1 split into 16-byte templates. */
public final class BuckRogersItemCatalogBlock extends Content {
	public static final int TEMPLATE_SIZE = 16;
	private final List<byte[]> templates;

	public BuckRogersItemCatalogBlock(@Nonnull ByteBufferWrapper data, @Nonnull ContentType type) {
		if (data.capacity() % TEMPLATE_SIZE != 0) {
			throw new IllegalArgumentException("ITEM0 block size is not divisible by 16: " + data.capacity());
		}
		templates = new ArrayList<>();
		byte[] bytes = data.array();
		for (int offset = 0; offset < data.capacity(); offset += TEMPLATE_SIZE) {
			templates.add(Arrays.copyOfRange(bytes, offset, offset + TEMPLATE_SIZE));
		}
	}

	public int size() { return templates.size(); }
	public byte[] template(int index) { return Arrays.copyOf(templates.get(index), TEMPLATE_SIZE); }
	int exactIndex(byte[] candidate) {
		for (int index = 0; index < templates.size(); index++) {
			if (Arrays.equals(templates.get(index), candidate)) return index;
		}
		return -1;
	}

	int stableFieldIndex(byte[] candidate) {
		int result = -1;
		for (int index = 0; index < templates.size(); index++) {
			byte[] template = templates.get(index);
			boolean matches = true;
			for (int offset = 0; offset < TEMPLATE_SIZE; offset++) {
				if (offset != BuckRogersEmbeddedItem.EQUIPPED_FLAG_OFFSET
					&& offset != BuckRogersEmbeddedItem.QUANTITY_OFFSET
					&& template[offset] != candidate[offset]) {
					matches = false;
					break;
				}
			}
			if (matches) {
				if (result >= 0) return -1;
				result = index;
			}
		}
		return result;
	}
}
