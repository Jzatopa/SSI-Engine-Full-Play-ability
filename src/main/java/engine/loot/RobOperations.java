package engine.loot;

import java.util.ArrayList;
import java.util.List;
import java.util.function.IntSupplier;

/**
 * Money-scaling and item-theft mechanics for a script-triggered "rob" event.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1):</p>
 * <ul>
 * <li>{@code ovr003.CMD_Rob} (sub_27F76): reads a loss percentage {@code var_2}
 * and converts it to a multiplicative scale via
 * {@code (100 - var_2) / 100.0} — ported as {@link #lossScale}.</li>
 * <li>{@code ovr008.RobMoney} (sub_31DEF): {@code player.Money.ScaleAll(scale)}
 * — ported as {@link #scaleMoney}, generalized to take the set of denominations
 * to scale rather than hard-coding AD&amp;D's Copper..Platinum range (see
 * {@link AdndCoinage#COIN_DENOMINATIONS} and the note below).</li>
 * <li>{@code ovr008.RobItems} (sub_31F1C): a probabilistic item-loss pass,
 * ported as {@link #robItems}.</li>
 * </ul>
 *
 * <p>{@code MoneySet.ScaleAll} (Classes/MoneySet.cs), which both {@code RobMoney}
 * and {@code ovr006.distributeNpcTreasure} call, only scales Copper..Platinum —
 * Gems and Jewelry are never reduced by robbery or NPC hireling shares in COAB.
 * That AD&amp;D-specific denomination choice is captured as data
 * ({@link AdndCoinage#COIN_DENOMINATIONS}) rather than baked into this class, so
 * a non-AD&amp;D flavor (e.g. {@link SingleCurrencyFlavor}) can scale all of its
 * denominations instead by calling the single-argument {@link #scaleMoney}
 * overload.</p>
 */
public final class RobOperations {

	private RobOperations() {
	}

	/**
	 * Ported from ovr003.CMD_Rob (sub_27F76): {@code double percentage = (100 - var_2) / 100.0;}
	 * where {@code var_2} is the percentage of money lost (0-100).
	 */
	public static double lossScale(int lossPercent) {
		return (100 - lossPercent) / 100.0;
	}

	/**
	 * Ported from ovr008.RobMoney (sub_31DEF) / MoneySet.ScaleAll, restricted to
	 * the given denominations. Each scaled denomination is truncated via Java's
	 * {@code (int)} cast, matching COAB's {@code (int)(money[coin] * scale)}.
	 *
	 * @return true if any of the given denominations held a positive amount
	 *         before scaling (mirrors {@code MoneySet.ScaleAll}'s {@code didScale}
	 *         return value).
	 */
	public static boolean scaleMoney(MoneyPool pool, double scale, int[] denominations) {
		boolean anyPositive = false;
		for (int denomination : denominations) {
			anyPositive = anyPositive || pool.getCoins(denomination) > 0;
			pool.setCoins(denomination, (int) (pool.getCoins(denomination) * scale));
		}
		return anyPositive;
	}

	/** {@link #scaleMoney(MoneyPool, double, int[])} over every denomination the pool's flavor defines. */
	public static boolean scaleMoney(MoneyPool pool, double scale) {
		int[] all = new int[pool.denominationCount()];
		for (int i = 0; i < all.length; i++) {
			all[i] = i;
		}
		return scaleMoney(pool, scale, all);
	}

	/**
	 * Ported from ovr008.RobItems (sub_31F1C): a single pass over {@code items},
	 * rolling 1d100 per item against {@code robChance} to decide theft.
	 *
	 * <p>Preserves a COAB quirk verbatim: {@code robChance} is a plain local that
	 * a heavy item's weight check permanently reduces for the rest of the pass —
	 * it is not reset between items. In COAB's source:</p>
	 * <pre>
	 * if (item.weight > 255) robChance = (robChance > 90) ? robChance - 90 : 0;
	 * else if (item.weight > 24) robChance = (robChance > 50) ? robChance - 50 : 0;
	 * return (roll_dice(100, 1) &lt;= robChance);
	 * </pre>
	 * so once a heavy item is seen, every later item in the list is judged
	 * against the already-reduced chance, even if lighter. This is preserved
	 * as-is (not a deliberate deviation) because the ordering-dependence is part
	 * of the original engine's observable behavior.</p>
	 *
	 * @param items     items to test, in COAB's original iteration order
	 * @param robChance base percent chance (0-100) an item is stolen
	 * @param d100      1d100 source (inclusive 1-100), injected for determinism
	 */
	public static <I extends LootItem> RobItemsResult<I> robItems(List<I> items, int robChance, IntSupplier d100) {
		List<I> kept = new ArrayList<>();
		List<I> stolen = new ArrayList<>();
		int chance = robChance;

		for (I item : items) {
			if (item.weight() > 255) {
				chance = chance > 90 ? chance - 90 : 0;
			} else if (item.weight() > 24) {
				chance = chance > 50 ? chance - 50 : 0;
			}

			if (d100.getAsInt() <= chance) {
				stolen.add(item);
			} else {
				kept.add(item);
			}
		}

		return new RobItemsResult<>(kept, stolen);
	}
}
