package engine.combat;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import data.character.BuckRogersEmbeddedItem;

/** Statically proven subset of GAME.OVR's equipped-item option walk. */
public final class RecoveredItemOptionSelector {
	public record Option(BuckRogersEmbeddedItem item, OriginalItemCombatTable.Record combatRecord) {
		public int family() { return combatRecord.unsignedByte(0); }
		public int familyOneScore() {
			return combatRecord.unsignedByte(2) + item.signedPayloadByte(4);
		}
	}

	private final OriginalItemCombatTable table;

	public RecoveredItemOptionSelector(OriginalItemCombatTable table) {
		if (table == null) throw new IllegalArgumentException("table must not be null");
		this.table = table;
	}

	public List<Option> equippedOptions(List<BuckRogersEmbeddedItem> items) {
		List<Option> result = new ArrayList<>();
		if (items == null) return result;
		for (BuckRogersEmbeddedItem item : items) {
			if (item != null && item.isEquipped()) {
				result.add(new Option(item, table.recordForItemPointer(item.itemPointer())));
			}
		}
		return List.copyOf(result);
	}

	/**
	 * GAME.OVR 0000:d3bf keeps the first family-1 item with the greatest
	 * ITEMS byte 2 + signed runtime item byte +0x32 (ITEM0 payload byte 4).
	 */
	public Optional<Option> preferredFamilyOne(List<BuckRogersEmbeddedItem> items) {
		Option best = null;
		int bestScore = Integer.MIN_VALUE;
		for (Option option : equippedOptions(items)) {
			if (option.family() == 1 && option.familyOneScore() > bestScore) {
				best = option;
				bestScore = option.familyOneScore();
			}
		}
		return Optional.ofNullable(best);
	}

	public String evidenceSummary(List<BuckRogersEmbeddedItem> items) {
		List<Option> options = equippedOptions(items);
		Optional<Option> preferred = preferredFamilyOne(items);
		String selection = preferred
			.map(option -> "family-1 preferred itemptr " + option.item().itemPointer()
				+ " score " + option.familyOneScore())
			.orElse("no equipped family-1 candidate");
		return "Original equipped-item option walk mapped " + options.size() + " item(s) through ITEMS; "
			+ selection + ". Category-0 scoring, damage, range, and dispatch remain unresolved.";
	}
}
