package data.character;

import java.util.Arrays;

import character.Item;
import character.ItemType;
import shared.CustomGoldboxString;
import shared.GoldboxString;

/** ITEM0-derived payload at the aligned offset of a MON0ITM record. */
public final class BuckRogersEmbeddedItem implements Item {
	public static final int EQUIPPED_FLAG_OFFSET = 6;
	public static final int QUANTITY_OFFSET = 10;
	private enum RawTemplateType implements ItemType { UNRESOLVED }

	private final int templateIndex;
	private final int itemPointer;
	private final int initializerOffset;
	private final byte[] raw;

	BuckRogersEmbeddedItem(int templateIndex, int initializerOffset, byte[] raw) {
		this.templateIndex = templateIndex;
		this.initializerOffset = initializerOffset;
		this.raw = Arrays.copyOf(raw, raw.length);
		this.itemPointer = Byte.toUnsignedInt(raw[0]);
	}

	public int templateIndex() { return templateIndex; }
	public int itemPointer() { return itemPointer; }
	public int initializerOffset() { return initializerOffset; }
	public byte[] raw() { return Arrays.copyOf(raw, raw.length); }
	public boolean isEquipped() { return (Byte.toUnsignedInt(raw[EQUIPPED_FLAG_OFFSET]) & 0x80) != 0; }
	public int quantity() { return Byte.toUnsignedInt(raw[QUANTITY_OFFSET]); }
	public int signedPayloadByte(int offset) {
		if (offset < 0 || offset >= raw.length) throw new IndexOutOfBoundsException("ITEM0 payload byte " + offset);
		return raw[offset];
	}

	@Override
	public GoldboxString getName() {
		return new CustomGoldboxString("ITEM0 TEMPLATE " + templateIndex);
	}

	@Override
	public ItemType getType() { return RawTemplateType.UNRESOLVED; }
}
