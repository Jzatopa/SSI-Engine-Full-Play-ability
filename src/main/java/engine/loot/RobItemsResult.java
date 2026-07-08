package engine.loot;

import java.util.Collections;
import java.util.List;

/**
 * Outcome of {@link RobOperations#robItems}: which items survived and which
 * were stolen, in original iteration order. Ported from COAB
 * (https://github.com/simeonpilgrim/coab, commit 9dc46f1), ovr008.cs
 * {@code RobItems} (sub_31F1C) — as a return value, a deliberate deviation
 * from COAB's in-place {@code List.RemoveAll}, so callers keep ownership of
 * their item list mutation.
 */
public final class RobItemsResult<I extends LootItem> {

	private final List<I> kept;
	private final List<I> stolen;

	RobItemsResult(List<I> kept, List<I> stolen) {
		this.kept = Collections.unmodifiableList(kept);
		this.stolen = Collections.unmodifiableList(stolen);
	}

	/** Items the player still has, in original order. */
	public List<I> kept() {
		return kept;
	}

	/** Items removed by the robbery, in original order. */
	public List<I> stolen() {
		return stolen;
	}
}
