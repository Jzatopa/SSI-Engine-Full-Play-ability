package engine.loot;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported AD&amp;D currency model
 * (Classes/MoneySet.cs Money.per_copper, MoneySet.GetGoldWorth,
 * MoneySet.GetExpWorth, plus MoneyPool's ported MoneySet operations,
 * coab commit 9dc46f1).
 */
public class AdndCoinageTest {

	// --- goldWorth: MoneySet.GetGoldWorth via Money.per_copper {1, 10, 100, 200, 1000} ---

	@Test
	public void goldWorthConvertsEachCoinTypeAtItsPerCopperRate() {
		MoneyPool pool = new MoneyPool(AdndCoinage.INSTANCE);
		pool.setCoins(AdndCoinage.COPPER, 200);
		assertEquals(1, AdndCoinage.INSTANCE.goldWorth(pool));

		pool.clearAll();
		pool.setCoins(AdndCoinage.SILVER, 20); // 200 copper
		assertEquals(1, AdndCoinage.INSTANCE.goldWorth(pool));

		pool.clearAll();
		pool.setCoins(AdndCoinage.ELECTRUM, 2); // 200 copper
		assertEquals(1, AdndCoinage.INSTANCE.goldWorth(pool));

		pool.clearAll();
		pool.setCoins(AdndCoinage.PLATINUM, 1); // 1000 copper
		assertEquals(5, AdndCoinage.INSTANCE.goldWorth(pool));
	}

	@Test
	public void goldWorthTruncatesFractionalGoldViaIntegerDivision() {
		MoneyPool pool = new MoneyPool(AdndCoinage.INSTANCE);
		pool.setCoins(AdndCoinage.PLATINUM, 1); // 1000
		pool.setCoins(AdndCoinage.GOLD, 1); // 200
		pool.setCoins(AdndCoinage.ELECTRUM, 1); // 100
		pool.setCoins(AdndCoinage.SILVER, 1); // 10
		pool.setCoins(AdndCoinage.COPPER, 9); // 9

		// 1319 copper / 200 per gold = 6 (remainder discarded)
		assertEquals(6, AdndCoinage.INSTANCE.goldWorth(pool));
	}

	@Test
	public void goldWorthIgnoresGemsAndJewelry() {
		MoneyPool pool = new MoneyPool(AdndCoinage.INSTANCE);
		pool.setCoins(AdndCoinage.GEMS, 10);
		pool.setCoins(AdndCoinage.JEWELRY, 10);

		assertEquals(0, AdndCoinage.INSTANCE.goldWorth(pool));
	}

	// --- expWorth: MoneySet.GetExpWorth (gold worth + 250/gem + 2200/jewelry) ---

	@Test
	public void expWorthAddsGemAndJewelryPremiumsToGoldWorth() {
		MoneyPool pool = new MoneyPool(AdndCoinage.INSTANCE);
		pool.setCoins(AdndCoinage.COPPER, 400); // 2 gold worth
		pool.setCoins(AdndCoinage.GEMS, 2); // 500
		pool.setCoins(AdndCoinage.JEWELRY, 1); // 2200

		assertEquals(2702, AdndCoinage.INSTANCE.expWorth(pool));
	}

	// --- MoneyPool ported MoneySet operations ---

	@Test
	public void mergeFromAccumulatesLikeCoabPooledMoneyPlusEquals() {
		MoneyPool pooled = new MoneyPool(AdndCoinage.INSTANCE);
		pooled.setCoins(AdndCoinage.GOLD, 3);

		MoneyPool monsterMoney = new MoneyPool(AdndCoinage.INSTANCE);
		monsterMoney.setCoins(AdndCoinage.GOLD, 4);
		monsterMoney.setCoins(AdndCoinage.GEMS, 1);

		pooled.mergeFrom(monsterMoney);

		assertEquals(7, pooled.getCoins(AdndCoinage.GOLD));
		assertEquals(1, pooled.getCoins(AdndCoinage.GEMS));
		// source is not mutated (COAB's operator+ builds a new set)
		assertEquals(4, monsterMoney.getCoins(AdndCoinage.GOLD));
	}

	@Test
	public void anyMoneyAndClearAllMatchMoneySetSemantics() {
		MoneyPool pool = new MoneyPool(AdndCoinage.INSTANCE);
		assertFalse(pool.anyMoney());

		// AnyMoney checks all 7 slots including Jewelry
		pool.setCoins(AdndCoinage.JEWELRY, 1);
		assertTrue(pool.anyMoney());

		pool.clearAll();
		assertFalse(pool.anyMoney());
		assertEquals(0, pool.getCoins(AdndCoinage.JEWELRY));
	}

	@Test
	public void denominationNamesMatchCoabMoneyNames() {
		String[] expected = { "Copper", "Silver", "Electrum", "Gold", "Platinum", "Gems", "Jewelry" };
		assertEquals(expected.length, AdndCoinage.INSTANCE.denominationCount());
		for (int i = 0; i < expected.length; i++) {
			assertEquals(expected[i], AdndCoinage.INSTANCE.denominationName(i));
		}
	}
}
