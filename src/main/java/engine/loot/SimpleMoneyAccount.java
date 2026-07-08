package engine.loot;

/**
 * Reference {@link MoneyAccount} implementation backed by a {@link MoneyPool}
 * and a fixed carry capacity, tracking used capacity as one unit per coin —
 * matching the {@code Player.weight}/{@code AddWeight}/{@code RemoveWeight}
 * treatment of coins in COAB (https://github.com/simeonpilgrim/coab, commit
 * 9dc46f1); see {@link MoneyAccount}'s javadoc. Not itself a COAB
 * port (COAB's real capacity math, ovr022.cs {@code get_max_load}, folds in encumbrance
 * from stats/items this package does not model); provided as a convenience for
 * callers and tests that just need a working account.
 */
public final class SimpleMoneyAccount implements MoneyAccount {

	private final MoneyPool money;
	private int capacityRemaining;

	public SimpleMoneyAccount(CurrencyFlavor flavor, int capacity) {
		this.money = new MoneyPool(flavor);
		this.capacityRemaining = capacity;
	}

	@Override
	public int coins(int denomination) {
		return money.getCoins(denomination);
	}

	@Override
	public void addCoins(int denomination, int amount) {
		money.addCoins(denomination, amount);
		capacityRemaining -= amount;
	}

	@Override
	public void removeCoins(int denomination, int amount) {
		addCoins(denomination, -amount);
	}

	@Override
	public int capacityRemaining() {
		return capacityRemaining;
	}

	/** Read-only view of the backing pool, for assertions. */
	public MoneyPool money() {
		return money;
	}
}
