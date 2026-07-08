package engine.loot;

import java.util.Arrays;

/**
 * A mutable multi-denomination amount of money.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * Classes/MoneySet.cs {@code MoneySet}: {@link #getCoins}/{@link #setCoins}/
 * {@link #addCoins} port {@code GetCoins}/{@code SetCoins}/{@code AddCoins};
 * {@link #clearAll} ports {@code ClearAll}; {@link #anyMoney} ports
 * {@code AnyMoney}; {@link #mergeFrom} ports the {@code operator+} overload,
 * which COAB uses in-place as {@code gbl.pooled_money += player.Money}.</p>
 *
 * <p>Generalized beyond the original: COAB hard-codes 7 coin slots (Copper..
 * Jewelry). This class instead sizes itself from an injected
 * {@link CurrencyFlavor}, so the same pool implementation serves both the
 * AD&amp;D coin set ({@link AdndCoinage}) and a single-currency flavor
 * ({@link SingleCurrencyFlavor}).</p>
 */
public final class MoneyPool {

	private final CurrencyFlavor flavor;
	private final int[] amounts;

	public MoneyPool(CurrencyFlavor flavor) {
		this.flavor = flavor;
		this.amounts = new int[flavor.denominationCount()];
	}

	public CurrencyFlavor flavor() {
		return flavor;
	}

	public int denominationCount() {
		return amounts.length;
	}

	public int getCoins(int denomination) {
		return amounts[denomination];
	}

	public void setCoins(int denomination, int amount) {
		amounts[denomination] = amount;
	}

	public void addCoins(int denomination, int amount) {
		amounts[denomination] += amount;
	}

	/** Ported from MoneySet.ClearAll: zeroes every denomination. */
	public void clearAll() {
		Arrays.fill(amounts, 0);
	}

	/** Ported from MoneySet.AnyMoney: true if any denomination holds a positive amount. */
	public boolean anyMoney() {
		for (int amount : amounts) {
			if (amount > 0) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Ported from MoneySet's {@code operator+}, applied in place (COAB always uses
	 * the operator as an accumulating {@code +=} onto {@code gbl.pooled_money}).
	 * Denominations beyond the shorter of the two pools are left untouched.
	 */
	public void mergeFrom(MoneyPool other) {
		int n = Math.min(amounts.length, other.amounts.length);
		for (int i = 0; i < n; i++) {
			amounts[i] += other.amounts[i];
		}
	}

	/** Defensive copy of the current amounts, indexed by denomination. Test/debug use. */
	public int[] snapshot() {
		return amounts.clone();
	}
}
