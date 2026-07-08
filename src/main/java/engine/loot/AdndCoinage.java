package engine.loot;

/**
 * The AD&amp;D 7-denomination coin set (Copper, Silver, Electrum, Gold,
 * Platinum, Gems, Jewelry), as the COAB-ported {@link CurrencyFlavor}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * Classes/MoneySet.cs {@code Money}: denomination indices/names and the
 * {@code per_copper} conversion table ({1, 10, 100, 200, 1000} for Copper..
 * Platinum). {@link #goldWorth} ports {@code MoneySet.GetGoldWorth};
 * {@link #expWorth} ports {@code MoneySet.GetExpWorth} (gold worth plus 250
 * exp per gem and 2200 exp per jewelry item).</p>
 *
 * <p>This is AD&amp;D/Gold-Box flavor content, not Matrix Cubed evidence —
 * Buck Rogers uses a single credits currency (see {@link SingleCurrencyFlavor})
 * and Matrix credit semantics have not been independently recovered.</p>
 */
public final class AdndCoinage implements CurrencyFlavor {

	public static final int COPPER = 0;
	public static final int SILVER = 1;
	public static final int ELECTRUM = 2;
	public static final int GOLD = 3;
	public static final int PLATINUM = 4;
	public static final int GEMS = 5;
	public static final int JEWELRY = 6;

	private static final String[] NAMES = {
		"Copper", "Silver", "Electrum", "Gold", "Platinum", "Gems", "Jewelry"
	};

	/** Copper-equivalent value of one unit of Copper..Platinum, ported from MoneySet.per_copper. */
	private static final int[] PER_COPPER = { 1, 10, 100, 200, 1000 };

	/**
	 * Denominations COAB treats as liquid coinage subject to robbery scaling and
	 * NPC-hireling share reduction (MoneySet.ScaleAll iterates Copper..Platinum
	 * only). Gems and Jewelry are excluded — COAB does not scale them down.
	 */
	public static final int[] COIN_DENOMINATIONS = { COPPER, SILVER, ELECTRUM, GOLD, PLATINUM };

	public static final AdndCoinage INSTANCE = new AdndCoinage();

	private AdndCoinage() {
	}

	@Override
	public int denominationCount() {
		return 7;
	}

	@Override
	public String denominationName(int index) {
		return NAMES[index];
	}

	/**
	 * Ported from MoneySet.GetGoldWorth: sums Copper..Platinum converted to copper
	 * via {@link #PER_COPPER}, then integer-divides by the copper-per-gold rate.
	 */
	public int goldWorth(MoneyPool pool) {
		int copperValue = 0;
		for (int coin = COPPER; coin <= PLATINUM; coin++) {
			copperValue += pool.getCoins(coin) * PER_COPPER[coin];
		}
		return copperValue / PER_COPPER[GOLD];
	}

	/**
	 * Ported from MoneySet.GetExpWorth: gold worth plus 250 exp per Gem and 2200
	 * exp per Jewelry item.
	 */
	public int expWorth(MoneyPool pool) {
		int total = goldWorth(pool);
		total += pool.getCoins(GEMS) * 250;
		total += pool.getCoins(JEWELRY) * 2200;
		return total;
	}
}
