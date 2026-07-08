package engine.loot;

/**
 * Describes a game's money model as an ordered list of denominations.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * Classes/MoneySet.cs: the original engine hard-codes a 7-denomination AD&amp;D
 * coin set (Copper, Silver, Electrum, Gold, Platinum, Gems, Jewelry). This
 * interface generalizes that shape so {@link MoneyPool} and the loot
 * distribution operations in this package are not tied to AD&amp;D coinage —
 * see {@link AdndCoinage} for the ported flavor and {@link SingleCurrencyFlavor}
 * for a candidate Buck Rogers "credits" flavor.</p>
 */
public interface CurrencyFlavor {

	/** Number of distinct denominations this flavor tracks. */
	int denominationCount();

	/** Display name of the denomination at {@code index}, in {@code [0, denominationCount())}. */
	String denominationName(int index);
}
