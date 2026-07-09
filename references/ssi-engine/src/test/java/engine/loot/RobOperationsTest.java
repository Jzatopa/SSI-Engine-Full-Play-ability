package engine.loot;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Arrays;
import java.util.List;
import java.util.PrimitiveIterator;
import java.util.stream.IntStream;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported rob mechanics
 * (ovr003.CMD_Rob, ovr008.RobMoney, ovr008.RobItems, Classes/MoneySet.ScaleAll,
 * coab commit 9dc46f1).
 */
public class RobOperationsTest {

	private static final class FakeItem implements LootItem {
		private final String name;
		private final int weight;

		FakeItem(String name, int weight) {
			this.name = name;
			this.weight = weight;
		}

		@Override
		public int weight() {
			return weight;
		}

		@Override
		public String toString() {
			return name;
		}
	}

	private static java.util.function.IntSupplier rolls(int... values) {
		PrimitiveIterator.OfInt iterator = IntStream.of(values).iterator();
		return iterator::nextInt;
	}

	// --- lossScale: ovr003.CMD_Rob (sub_27F76) percentage math ---

	@Test
	public void lossScaleMatchesCmdRobFormula() {
		assertEquals(0.75, RobOperations.lossScale(25), 0.0);
		assertEquals(1.0, RobOperations.lossScale(0), 0.0);
		assertEquals(0.0, RobOperations.lossScale(100), 0.0);
	}

	// --- scaleMoney: ovr008.RobMoney (sub_31DEF) / MoneySet.ScaleAll ---

	@Test
	public void scaleMoneyTruncatesEachCoinDenominationAndSkipsGemsAndJewelry() {
		MoneyPool pool = new MoneyPool(AdndCoinage.INSTANCE);
		pool.setCoins(AdndCoinage.COPPER, 9);
		pool.setCoins(AdndCoinage.GOLD, 7);
		pool.setCoins(AdndCoinage.PLATINUM, 1);
		pool.setCoins(AdndCoinage.GEMS, 3);
		pool.setCoins(AdndCoinage.JEWELRY, 2);

		boolean scaled = RobOperations.scaleMoney(pool, 0.5, AdndCoinage.COIN_DENOMINATIONS);

		assertTrue(scaled);
		// (int)(9 * 0.5) = 4, (int)(7 * 0.5) = 3, (int)(1 * 0.5) = 0 — truncation, not rounding
		assertEquals(4, pool.getCoins(AdndCoinage.COPPER));
		assertEquals(3, pool.getCoins(AdndCoinage.GOLD));
		assertEquals(0, pool.getCoins(AdndCoinage.PLATINUM));
		// Gems and Jewelry are outside MoneySet.ScaleAll's Copper..Platinum loop: untouched
		assertEquals(3, pool.getCoins(AdndCoinage.GEMS));
		assertEquals(2, pool.getCoins(AdndCoinage.JEWELRY));
	}

	@Test
	public void scaleMoneyReportsWhetherAnyScaledDenominationWasPositive() {
		MoneyPool empty = new MoneyPool(AdndCoinage.INSTANCE);
		assertFalse(RobOperations.scaleMoney(empty, 0.5, AdndCoinage.COIN_DENOMINATIONS));

		MoneyPool gemsOnly = new MoneyPool(AdndCoinage.INSTANCE);
		gemsOnly.setCoins(AdndCoinage.GEMS, 5);
		// gems are not a scaled denomination, so nothing scaled
		assertFalse(RobOperations.scaleMoney(gemsOnly, 0.5, AdndCoinage.COIN_DENOMINATIONS));
	}

	@Test
	public void scaleMoneySingleArgOverloadScalesEveryFlavorDenomination() {
		MoneyPool pool = new MoneyPool(SingleCurrencyFlavor.INSTANCE);
		pool.setCoins(SingleCurrencyFlavor.CREDITS, 101);

		boolean scaled = RobOperations.scaleMoney(pool, RobOperations.lossScale(25));

		assertTrue(scaled);
		// (int)(101 * 0.75) = 75
		assertEquals(75, pool.getCoins(SingleCurrencyFlavor.CREDITS));
	}

	// --- robItems: ovr008.RobItems (sub_31F1C) ---

	@Test
	public void robItemsStealsOnRollAtOrBelowChanceAndKeepsAbove() {
		FakeItem a = new FakeItem("a", 1);
		FakeItem b = new FakeItem("b", 1);
		FakeItem c = new FakeItem("c", 1);

		// chance 40: roll 40 stolen (<= is inclusive), roll 41 kept, roll 1 stolen
		RobItemsResult<FakeItem> result = RobOperations.robItems(Arrays.asList(a, b, c), 40, rolls(40, 41, 1));

		assertEquals(Arrays.asList(a, c), result.stolen());
		assertEquals(List.of(b), result.kept());
	}

	@Test
	public void robItemsReducesChanceBy50ForItemsHeavierThan24() {
		// chance 60 -> 10 for the heavy item; roll 10 still steals it
		FakeItem heavy = new FakeItem("heavy", 25);
		RobItemsResult<FakeItem> stolen = RobOperations.robItems(List.of(heavy), 60, rolls(10));
		assertEquals(List.of(heavy), stolen.stolen());

		// roll 11 misses the reduced chance
		RobItemsResult<FakeItem> kept = RobOperations.robItems(List.of(heavy), 60, rolls(11));
		assertEquals(List.of(heavy), kept.kept());

		// chance <= 50 collapses to 0: even a roll of 1 cannot steal
		RobItemsResult<FakeItem> safe = RobOperations.robItems(List.of(heavy), 50, rolls(1));
		assertEquals(List.of(heavy), safe.kept());
	}

	@Test
	public void robItemsReducesChanceBy90ForItemsHeavierThan255() {
		// chance 95 -> 5; roll 5 steals
		FakeItem anvil = new FakeItem("anvil", 256);
		RobItemsResult<FakeItem> stolen = RobOperations.robItems(List.of(anvil), 95, rolls(5));
		assertEquals(List.of(anvil), stolen.stolen());

		// chance <= 90 collapses to 0
		RobItemsResult<FakeItem> safe = RobOperations.robItems(List.of(anvil), 90, rolls(1));
		assertEquals(List.of(anvil), safe.kept());
	}

	@Test
	public void robItemsWeightReductionPersistsForLaterItemsCoabQuirk() {
		// COAB's robChance is a mutated local: after the heavy item halves it,
		// the following light item is judged against the reduced chance too.
		FakeItem heavy = new FakeItem("heavy", 30);
		FakeItem light = new FakeItem("light", 1);

		// chance 60 -> 10 at the heavy item and stays 10; roll 11 vs the light item misses,
		// where the original chance of 60 would have stolen it.
		RobItemsResult<FakeItem> result = RobOperations.robItems(Arrays.asList(heavy, light), 60, rolls(11, 11));

		assertEquals(Arrays.asList(heavy, light), result.kept());
		assertTrue(result.stolen().isEmpty());
	}

	@Test
	public void robItemsPreservesOriginalOrderInBothResultLists() {
		FakeItem a = new FakeItem("a", 1);
		FakeItem b = new FakeItem("b", 1);
		FakeItem c = new FakeItem("c", 1);
		FakeItem d = new FakeItem("d", 1);

		RobItemsResult<FakeItem> result = RobOperations.robItems(Arrays.asList(a, b, c, d), 50,
			rolls(1, 100, 2, 99));

		assertEquals(Arrays.asList(a, c), result.stolen());
		assertEquals(Arrays.asList(b, d), result.kept());
	}
}
