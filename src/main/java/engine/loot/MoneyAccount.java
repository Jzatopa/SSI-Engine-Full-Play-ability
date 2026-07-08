package engine.loot;

/**
 * A party member's money-holding side, as seen by the pool distribution
 * operations in {@link TreasurePool}.
 *
 * <p>Ported from the {@code Player.Money} (a {@code MoneySet}) plus
 * {@code Player.weight}/{@code AddWeight}/{@code RemoveWeight} pairing COAB
 * threads through ovr022.cs's money-transfer helpers ({@code willOverload},
 * {@code PickupCoins}, {@code share_pooled}, {@code poolMoney}): every coin
 * transfer both changes a denomination count and consumes/frees one unit of
 * carry capacity per coin (COAB weighs every coin type equally — {@code
 * AddWeight(num_coins)} does not multiply by a per-denomination unit weight).
 * {@link #capacityRemaining()} corresponds to COAB's
 * {@code get_max_load(player) - player.weight}, recomputed fresh by callers
 * after each mutation (as COAB does by calling {@code willOverload} again
 * inside its loops) rather than cached.</p>
 *
 * <p>Implementations decide how coins map to a real character sheet; this
 * package only needs the read/write/capacity surface below.</p>
 */
public interface MoneyAccount {

	/** Current amount held of the given denomination. */
	int coins(int denomination);

	/** Adds {@code amount} (may be negative) to the given denomination. */
	void addCoins(int denomination, int amount);

	/** Removes {@code amount} of the given denomination (equivalent to {@code addCoins(denomination, -amount)}). */
	void removeCoins(int denomination, int amount);

	/** Remaining carry capacity, in coin units (one coin of any denomination costs one unit). */
	int capacityRemaining();
}
