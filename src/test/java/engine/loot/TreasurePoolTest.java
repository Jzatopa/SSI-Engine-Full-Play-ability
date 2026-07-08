package engine.loot;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Arrays;
import java.util.List;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported treasure pool mechanics
 * (ovr003.CMD_Treasure, ovr006.share_pooled/poolMoney/distributeNpcTreasure,
 * ovr022.PickupCoins, coab commit 9dc46f1).
 */
public class TreasurePoolTest {

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

	// --- fromScriptedTreasure: ovr003.CMD_Treasure coin-setting loop + fixed item block ---

	@Test
	public void fromScriptedTreasureSetsEachDenominationAndSeedsItems() {
		FakeItem sword = new FakeItem("sword", 10);
		FakeItem shield = new FakeItem("shield", 20);

		TreasurePool<FakeItem> pool = TreasurePool.fromScriptedTreasure(AdndCoinage.INSTANCE,
			new int[] { 5, 0, 0, 12, 0, 0, 0 }, Arrays.asList(sword, shield));

		assertEquals(5, pool.money().getCoins(AdndCoinage.COPPER));
		assertEquals(12, pool.money().getCoins(AdndCoinage.GOLD));
		assertEquals(0, pool.money().getCoins(AdndCoinage.PLATINUM));
		assertEquals(Arrays.asList(sword, shield), pool.items());
		assertTrue(pool.anyMoney());
		assertTrue(pool.anyItems());
	}

	@Test
	public void fromScriptedTreasureIgnoresExtraCoinAmountsAndLeavesRestAtZero() {
		TreasurePool<FakeItem> pool = TreasurePool.fromScriptedTreasure(SingleCurrencyFlavor.INSTANCE,
			new int[] { 7, 99, 99 }, List.of());

		assertEquals(7, pool.money().getCoins(SingleCurrencyFlavor.CREDITS));
		assertEquals(1, pool.money().denominationCount());
		assertFalse(pool.anyItems());
	}

	// --- collectFromParty: ovr022.poolMoney ---

	@Test
	public void collectFromPartyMovesEveryMembersMoneyIntoThePoolAndClearsThem() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		SimpleMoneyAccount a = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 1000);
		SimpleMoneyAccount b = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 1000);
		a.addCoins(AdndCoinage.GOLD, 5);
		b.addCoins(AdndCoinage.SILVER, 2);

		pool.collectFromParty(Arrays.asList(a, b));

		assertEquals(5, pool.money().getCoins(AdndCoinage.GOLD));
		assertEquals(2, pool.money().getCoins(AdndCoinage.SILVER));
		assertEquals(0, a.coins(AdndCoinage.GOLD));
		assertEquals(0, b.coins(AdndCoinage.SILVER));
		// pooling frees carried weight, matching Player.RemoveWeight alongside Money.ClearAll
		assertEquals(1000, a.capacityRemaining());
		assertEquals(1000, b.capacityRemaining());
	}

	// --- take: ovr022.PickupCoins (sub_59AA0) ---

	@Test
	public void takeTransfersUpToPoolAvailableAndCapsAtRecipientCapacity() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 10);
		SimpleMoneyAccount recipient = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 5);

		int taken = pool.take(recipient, AdndCoinage.GOLD, 3);

		assertEquals(3, taken);
		assertEquals(3, recipient.coins(AdndCoinage.GOLD));
		assertEquals(7, pool.money().getCoins(AdndCoinage.GOLD));
		assertEquals(2, recipient.capacityRemaining());
	}

	@Test
	public void takeIsFullyRejectedWhenAmountExceedsCapacityNoPartialFill() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 10);
		SimpleMoneyAccount recipient = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 2);

		int taken = pool.take(recipient, AdndCoinage.GOLD, 5);

		assertEquals(0, taken);
		assertEquals(0, recipient.coins(AdndCoinage.GOLD));
		assertEquals(10, pool.money().getCoins(AdndCoinage.GOLD));
	}

	@Test
	public void takeIsCappedByPoolAvailableEvenWithRoomToSpare() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 1);
		SimpleMoneyAccount recipient = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 100);

		int taken = pool.take(recipient, AdndCoinage.GOLD, 5);

		assertEquals(1, taken);
		assertEquals(1, recipient.coins(AdndCoinage.GOLD));
		assertEquals(0, pool.money().getCoins(AdndCoinage.GOLD));
	}

	// --- takeItem: ovr006.take_items_treasure (sub_2DDFC) accept-or-keep shape ---

	@Test
	public void takeItemRemovesFromPoolOnlyWhenAccepted() {
		FakeItem sword = new FakeItem("sword", 10);
		FakeItem anvil = new FakeItem("anvil", 500);
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.addItems(Arrays.asList(sword, anvil));

		boolean swordAccepted = pool.takeItem(sword, item -> true);
		boolean anvilAccepted = pool.takeItem(anvil, item -> false); // simulated overload

		assertTrue(swordAccepted);
		assertFalse(anvilAccepted);
		assertEquals(List.of(anvil), pool.items());
	}

	// --- share: ovr022.share_pooled ---

	@Test
	public void shareSplitsEvenlyAndAssignsPerRecipientRemainderHighestDenominationFirst() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 10);
		pool.money().setCoins(AdndCoinage.SILVER, 5);

		SimpleMoneyAccount p1 = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 1000);
		SimpleMoneyAccount p2 = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 1000);
		SimpleMoneyAccount p3 = new SimpleMoneyAccount(AdndCoinage.INSTANCE, 1000);

		pool.share(Arrays.asList(p1, p2, p3));

		// 10 gold / 3 = 3 each, remainder 1 -> first recipient in list order gets the extra gold.
		assertEquals(4, p1.coins(AdndCoinage.GOLD));
		assertEquals(3, p2.coins(AdndCoinage.GOLD));
		assertEquals(3, p3.coins(AdndCoinage.GOLD));

		// 5 silver / 3 = 1 each, remainder 2 -> first two recipients in list order get the extra silver.
		assertEquals(2, p1.coins(AdndCoinage.SILVER));
		assertEquals(2, p2.coins(AdndCoinage.SILVER));
		assertEquals(1, p3.coins(AdndCoinage.SILVER));

		// fully distributed: nothing left in the pool
		assertEquals(0, pool.money().getCoins(AdndCoinage.GOLD));
		assertEquals(0, pool.money().getCoins(AdndCoinage.SILVER));
	}

	@Test
	public void shareOverflowFromAnOverloadedRecipientSpillsToLaterRecipientsInASecondPass() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(SingleCurrencyFlavor.INSTANCE);
		pool.money().setCoins(SingleCurrencyFlavor.CREDITS, 10);

		SimpleMoneyAccount cramped = new SimpleMoneyAccount(SingleCurrencyFlavor.INSTANCE, 2);
		SimpleMoneyAccount roomy = new SimpleMoneyAccount(SingleCurrencyFlavor.INSTANCE, 1000);

		pool.share(Arrays.asList(cramped, roomy));

		// each = 5; cramped can only hold 2 of its 5-coin share, so it gets 2 and the
		// 3-coin shortfall becomes leftover that roomy absorbs in the second pass.
		assertEquals(2, cramped.coins(SingleCurrencyFlavor.CREDITS));
		assertEquals(8, roomy.coins(SingleCurrencyFlavor.CREDITS));
		assertEquals(0, pool.money().getCoins(SingleCurrencyFlavor.CREDITS));
	}

	@Test
	public void shareLeavesUnplaceableMoneyInThePoolWhenNoRecipientHasRoom() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(SingleCurrencyFlavor.INSTANCE);
		pool.money().setCoins(SingleCurrencyFlavor.CREDITS, 5);

		SimpleMoneyAccount full = new SimpleMoneyAccount(SingleCurrencyFlavor.INSTANCE, 0);

		pool.share(List.of(full));

		assertEquals(0, full.coins(SingleCurrencyFlavor.CREDITS));
		assertEquals(5, pool.money().getCoins(SingleCurrencyFlavor.CREDITS));
	}

	@Test
	public void shareWithNoRecipientsIsANoOp() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(SingleCurrencyFlavor.INSTANCE);
		pool.money().setCoins(SingleCurrencyFlavor.CREDITS, 5);

		pool.share(List.of());

		assertEquals(5, pool.money().getCoins(SingleCurrencyFlavor.CREDITS));
	}

	// --- applyNpcShare: ovr006.distributeNpcTreasure (sub_2E50E) ---

	@Test
	public void applyNpcShareTruncatesToZeroWhenNpcPartsAreFewerThanTotalParts() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 10);
		pool.money().setCoins(AdndCoinage.GEMS, 4);

		boolean scaled = pool.applyNpcShare(1, 3, AdndCoinage.COIN_DENOMINATIONS);

		assertTrue(scaled);
		// integer division 1/3 == 0 -> gold zeroed, matching the preserved COAB quirk
		assertEquals(0, pool.money().getCoins(AdndCoinage.GOLD));
		// gems are outside COIN_DENOMINATIONS and are never touched by NPC share reduction
		assertEquals(4, pool.money().getCoins(AdndCoinage.GEMS));
	}

	@Test
	public void applyNpcShareLeavesPoolUnchangedWhenNpcPartsEqualTotalParts() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 10);

		pool.applyNpcShare(3, 3, AdndCoinage.COIN_DENOMINATIONS);

		assertEquals(10, pool.money().getCoins(AdndCoinage.GOLD));
	}

	// --- discardRemainder: ovr006.AfterCombatExpAndTreasure / ovr003.CMD_ClearMonsters ---

	@Test
	public void discardRemainderClearsBothMoneyAndItems() {
		TreasurePool<FakeItem> pool = new TreasurePool<>(AdndCoinage.INSTANCE);
		pool.money().setCoins(AdndCoinage.GOLD, 10);
		pool.addItems(List.of(new FakeItem("ring", 1)));

		pool.discardRemainder();

		assertFalse(pool.anyMoney());
		assertFalse(pool.anyItems());
	}
}
