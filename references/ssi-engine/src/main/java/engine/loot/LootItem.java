package engine.loot;

/**
 * Identity of a lootable item, as seen by this package.
 *
 * <p>Contract ported from COAB (https://github.com/simeonpilgrim/coab, commit
 * 9dc46f1): item equality/removal from a {@link TreasurePool} is by object
 * identity (matching COAB's {@code List<Item>.Remove}/{@code RemoveAll} over
 * reference types in ovr006.take_items_treasure and ovr008.RobItems) — this
 * interface adds only the one data point
 * the ported loot mechanics read directly: {@link #weight()}, used by
 * {@link RobOperations#robItems} (ported from ovr008.RobItems, sub_31F1C) to
 * scale theft chance for heavy items. Everything else about an item (type,
 * name, bonus, value) is out of scope for this package and belongs to whatever
 * item catalog the caller supplies.</p>
 */
public interface LootItem {

	/** Item weight in the same units COAB's {@code Item.weight} uses (encumbrance points). */
	int weight();
}
