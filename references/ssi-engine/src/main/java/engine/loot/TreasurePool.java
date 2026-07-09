package engine.loot;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * A shared, temporary pool of money and items — the "treasure on the ground"
 * a script-triggered treasure event or post-combat loot hands to the party.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * mirroring {@code gbl.pooled_money} (a {@code MoneySet}) and
 * {@code gbl.items_pointer} (a {@code List<Item>}) together with the
 * operations the engine runs over them:</p>
 * <ul>
 * <li>{@link #fromScriptedTreasure} ports {@code ovr003.CMD_Treasure}
 * (load_item)'s coin-setting loop
 * ({@code for (coin = 0; coin < 7; coin++) pooled_money.SetCoins(coin, ...)})
 * and its fixed-item-block branch ({@code block_id < 0x80}: load a DAX item
 * block and add each item to the pool).</li>
 * <li>{@link #collectFromParty} ports {@code ovr022.poolMoney}: every
 * player-controlled party member's money moves into the pool and their
 * personal money/weight is cleared.</li>
 * <li>{@link #take} ports {@code ovr022.PickupCoins} (sub_59AA0).</li>
 * <li>{@link #takeItem} ports the accept-or-keep shape of
 * {@code ovr006.take_items_treasure} (sub_2DDFC).</li>
 * <li>{@link #share} ports {@code ovr022.share_pooled}: an even split across
 * the party with per-denomination remainder handling.</li>
 * <li>{@link #applyNpcShare} ports {@code ovr006.distributeNpcTreasure}
 * (sub_2E50E)'s pool-scaling step.</li>
 * <li>{@link #discardRemainder} ports the pattern COAB uses when a treasure
 * screen closes with the party choosing not to (or unable to) take
 * everything: {@code ovr006.AfterCombatExpAndTreasure} clears
 * {@code items_pointer} unconditionally after {@code distributeCombatTreasure}
 * returns, and clears both {@code items_pointer} and {@code pooled_money} on a
 * party flee; {@code ovr003.CMD_ClearMonsters} does the same when the next
 * encounter starts.</li>
 * </ul>
 *
 * <p><b>Deliberately not ported:</b> {@code ovr003.CMD_Treasure}'s randomized
 * magic-item branch ({@code block_id >= 0x80}: a chain of {@code roll_dice}
 * lookups against AD&amp;D {@code ItemType} values — longswords, scrolls,
 * potions, wands, rings, bracers, shields) is content generation tied to a
 * specific AD&amp;D item catalog this package does not model (see
 * {@link LootItem}'s narrow identity contract). A caller wanting that table
 * needs to port it separately, above this package's boundary, against a real
 * item catalog.</p>
 */
public final class TreasurePool<I extends LootItem> {

	private final MoneyPool money;
	private final List<I> items = new ArrayList<>();

	public TreasurePool(CurrencyFlavor flavor) {
		this.money = new MoneyPool(flavor);
	}

	/**
	 * Ported from ovr003.CMD_Treasure (load_item): sets each denomination from
	 * {@code coinAmounts} (indexed the same way the script's opcode arguments
	 * are, one per denomination) and seeds the pool with {@code fixedItems} — the
	 * caller-resolved equivalent of COAB loading a fixed DAX item block. Extra
	 * entries in {@code coinAmounts} beyond the flavor's denomination count are
	 * ignored; missing entries leave the corresponding denomination at 0.
	 */
	public static <I extends LootItem> TreasurePool<I> fromScriptedTreasure(CurrencyFlavor flavor,
		int[] coinAmounts, List<I> fixedItems) {

		TreasurePool<I> pool = new TreasurePool<>(flavor);
		int count = Math.min(coinAmounts.length, flavor.denominationCount());
		for (int i = 0; i < count; i++) {
			pool.money.setCoins(i, coinAmounts[i]);
		}
		pool.items.addAll(fixedItems);
		return pool;
	}

	public MoneyPool money() {
		return money;
	}

	public List<I> items() {
		return Collections.unmodifiableList(items);
	}

	public boolean anyMoney() {
		return money.anyMoney();
	}

	public boolean anyItems() {
		return !items.isEmpty();
	}

	/** Adds items directly to the pool (e.g. monster drops), matching COAB's {@code items_pointer.Add(...)} calls. */
	public void addItems(List<I> newItems) {
		items.addAll(newItems);
	}

	/**
	 * Ported from ovr022.poolMoney: moves every member's money into this pool and
	 * zeroes it out on their side. {@code party} should already be filtered to
	 * whichever members COAB's {@code control_morale == PC_Base || PC_Berzerk}
	 * check selects (i.e. player-controlled characters, not hirelings/NPCs) —
	 * that filter is game-state the caller owns, not this package.
	 */
	public void collectFromParty(List<? extends MoneyAccount> party) {
		int n = money.denominationCount();
		for (MoneyAccount member : party) {
			for (int d = 0; d < n; d++) {
				int amount = member.coins(d);
				if (amount != 0) {
					money.addCoins(d, amount);
					member.removeCoins(d, amount);
				}
			}
		}
	}

	/**
	 * Ported from ovr022.PickupCoins (sub_59AA0): transfers up to {@code amount}
	 * of {@code denomination} from the pool to {@code recipient}.
	 *
	 * <p>Matches COAB exactly: if {@code amount} exceeds the recipient's
	 * remaining capacity the take is fully rejected (no partial fill — COAB
	 * shows "Overloaded" and transfers nothing), returning 0. Otherwise the
	 * amount actually taken is capped at what the pool holds.</p>
	 *
	 * @return the amount actually transferred (0 if rejected for capacity)
	 */
	public int take(MoneyAccount recipient, int denomination, int amount) {
		if (amount > recipient.capacityRemaining()) {
			return 0;
		}
		int available = money.getCoins(denomination);
		int transferred = Math.min(amount, available);
		money.addCoins(denomination, -transferred);
		recipient.addCoins(denomination, transferred);
		return transferred;
	}

	/**
	 * Ported from the accept-or-keep shape of ovr006.take_items_treasure
	 * (sub_2DDFC): offers {@code item} to {@code receiver}; if accepted, the item
	 * is removed from the pool (by identity, matching {@code List.Remove}).
	 *
	 * @return true if {@code receiver} accepted the item
	 */
	public boolean takeItem(I item, ItemReceiver<I> receiver) {
		boolean accepted = receiver.receive(item);
		if (accepted) {
			items.remove(item);
		}
		return accepted;
	}

	/**
	 * Ported from ovr022.share_pooled: splits every denomination evenly across
	 * {@code recipients}, distributing the per-recipient remainder coin (if any)
	 * to whichever recipients still have room, highest-value denomination first
	 * (COAB iterates {@code coin = 6} down to {@code 0}, i.e. Jewelry before
	 * Copper; this port iterates denomination index {@code n-1} down to
	 * {@code 0}, generalizing the same "highest denomination first" order).
	 *
	 * <p>Two-pass remainder handling, exactly as COAB does it:</p>
	 * <ol>
	 * <li>Each recipient gets {@code pooled / partySize} of a denomination if
	 * they have full room for it; if there's a per-recipient remainder unit
	 * ({@code pooled % partySize} spread one-at-a-time) and they still have room
	 * for one more coin, they get it too. A recipient without room for their
	 * full share instead gets whatever fits, and the shortfall is added back
	 * into the leftover pool for that denomination.</li>
	 * <li>Any leftover pool amount per denomination (from step 1's shortfalls
	 * and unclaimed remainder units) is then dumped onto recipients in list
	 * order, filling each one's remaining capacity before moving to the next,
	 * until the leftover is exhausted or no one has room left.</li>
	 * </ol>
	 * <p>Whatever still could not be placed (no one had room) stays in the pool
	 * — {@link #money()} reflects it afterward, exactly like COAB leaving the
	 * unplaced remainder in {@code gbl.pooled_money} at the end of
	 * {@code share_pooled}.</p>
	 *
	 * <p>If {@code recipients} is empty this is a no-op (COAB's
	 * {@code GetPartyCount()} feeding a division assumes at least one party
	 * member and is not guarded here either; callers must not call this with no
	 * recipients).</p>
	 */
	public void share(List<? extends MoneyAccount> recipients) {
		if (recipients.isEmpty()) {
			return;
		}

		int n = money.denominationCount();
		int partySize = recipients.size();
		int[] each = new int[n];
		int[] remainder = new int[n];

		for (int d = 0; d < n; d++) {
			int pooled = money.getCoins(d);
			if (pooled > 0) {
				each[d] = pooled / partySize;
				remainder[d] = pooled % partySize;
			}
		}

		for (MoneyAccount recipient : recipients) {
			for (int d = n - 1; d >= 0; d--) {
				int capacity = recipient.capacityRemaining();
				if (each[d] <= capacity) {
					if (each[d] > 0) {
						recipient.addCoins(d, each[d]);
					}
					if (remainder[d] > 0 && recipient.capacityRemaining() >= 1) {
						recipient.addCoins(d, 1);
						remainder[d] -= 1;
					}
				} else {
					int overflow = Math.min(each[d], capacity);
					if (overflow > 0) {
						recipient.addCoins(d, overflow);
					}
					remainder[d] += each[d] - overflow;
				}
			}
		}

		for (int d = n - 1; d >= 0; d--) {
			if (remainder[d] <= 0) {
				continue;
			}
			for (MoneyAccount recipient : recipients) {
				int capacity = recipient.capacityRemaining();
				if (capacity <= 0) {
					continue;
				}
				if (remainder[d] > capacity) {
					recipient.addCoins(d, capacity);
					remainder[d] -= capacity;
				} else {
					recipient.addCoins(d, remainder[d]);
					remainder[d] = 0;
				}
			}
		}

		for (int d = 0; d < n; d++) {
			money.setCoins(d, remainder[d]);
		}
	}

	/**
	 * Ported from ovr006.distributeNpcTreasure (sub_2E50E)'s pool-scaling step:
	 * {@code gbl.pooled_money.ScaleAll(npcParts / totalParts)}. {@code npcParts}
	 * and {@code totalParts} are the caller-computed sums of
	 * {@code npcTreasureShareCount & 7} for controlled hirelings versus every
	 * party member (COAB's {@code control_morale}/{@code health_status}
	 * filtering is game state this package does not own).
	 *
	 * <p>Preserves a COAB quirk verbatim: {@code npcParts / totalParts} is
	 * computed as integer division before use as the {@code double} scale
	 * argument, so the pool is only reduced at all when {@code npcParts >=
	 * totalParts}; any smaller ratio truncates to a scale of exactly 0 (which
	 * would zero the pool, not leave it unchanged) — this port keeps that
	 * exact truncation.</p>
	 *
	 * @param denominations which denominations to scale (pass
	 *                      {@link AdndCoinage#COIN_DENOMINATIONS} to match COAB's
	 *                      AD&amp;D behavior, which exempts Gems/Jewelry)
	 * @return true if any of {@code denominations} held a positive amount before scaling
	 */
	public boolean applyNpcShare(int npcParts, int totalParts, int[] denominations) {
		double scale = npcParts / totalParts;
		return RobOperations.scaleMoney(money, scale, denominations);
	}

	/**
	 * Clears both the money pool and the item list, matching COAB's treatment of
	 * unclaimed treasure once the treasure screen is left behind (see the class
	 * javadoc for the specific COAB call sites this generalizes).
	 */
	public void discardRemainder() {
		money.clearAll();
		items.clear();
	}
}
