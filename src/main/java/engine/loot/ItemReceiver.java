package engine.loot;

/**
 * Accepts (or rejects) a single item handed to it from a {@link TreasurePool}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1):
 * the accept/reject contract ovr006.cs {@code take_items_treasure} (sub_2DDFC)
 * uses around {@code ovr007.PlayerAddItem}:
 * {@code bool willOverload = ovr007.PlayerAddItem(item); if (willOverload == false) { items_pointer.Remove(item); }}
 * — an item is taken off the pool only if the recipient had room for it. This
 * interface flips the boolean's sense for Java readability ({@link #receive}
 * returns {@code true} on success, where COAB's {@code willOverload} is
 * {@code true} on failure); the underlying capacity/overload decision itself
 * (COAB's {@code ovr007.PlayerAddItem}, not read as part of this port) is left
 * entirely to the caller's implementation.</p>
 */
public interface ItemReceiver<I extends LootItem> {

	/** Attempts to add {@code item}; returns true if accepted (and therefore removed from the pool). */
	boolean receive(I item);
}
