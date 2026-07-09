package engine.party;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

import engine.party.NpcTreasureShare.MoneyPool;
import engine.party.NpcTreasureShare.Result;

/**
 * Conformance tests for the COAB-ported NPC treasure split
 * (ovr006.distributeNpcTreasure + MoneySet.ScaleAll, coab commit 9dc46f1).
 */
public class NpcTreasureShareTest {

	private static final class FakeMember implements NpcCharacter {
		private final int controlMorale;
		private final int shareCount;
		private final boolean healthy;

		private FakeMember(int controlMorale, int shareCount, boolean healthy) {
			this.controlMorale = controlMorale;
			this.shareCount = shareCount;
			this.healthy = healthy;
		}

		@Override
		public int npcId() {
			return 0;
		}

		@Override
		public void setNpcId(int npcId) {
		}

		@Override
		public String name() {
			return "M";
		}

		@Override
		public int controlMorale() {
			return controlMorale;
		}

		@Override
		public void setControlMorale(int controlMorale) {
		}

		@Override
		public int iconId() {
			return 0;
		}

		@Override
		public void setIconId(int iconId) {
		}

		@Override
		public int npcTreasureShareCount() {
			return shareCount;
		}

		@Override
		public boolean isHealthy() {
			return healthy;
		}
	}

	/** COAB MoneySet.ScaleAll: scales each plain coin type, reports whether any held money. */
	private static final class FakePool implements MoneyPool {
		private int[] coins;
		private Double appliedScale;

		private FakePool(int... coins) {
			this.coins = coins;
		}

		@Override
		public boolean scaleAll(double scale) {
			appliedScale = scale;
			boolean didScale = false;
			for (int i = 0; i < coins.length; i++) {
				didScale = didScale || coins[i] > 0;
				coins[i] = (int) (coins[i] * scale);
			}
			return didScale;
		}
	}

	private static FakeMember playerCharacter() {
		return new FakeMember(0x30, 0, true);
	}

	private static FakeMember healthyNpc(int shareCount) {
		return new FakeMember(NpcPartyService.NPC_CONTROL_BASE + 3, shareCount, true);
	}

	private static FakeMember downedNpc(int shareCount) {
		return new FakeMember(NpcPartyService.NPC_CONTROL_BASE + 3, shareCount, false);
	}

	@Test
	public void healthyNpcSharesCountTowardBothTotalsOthersCountAsOne() {
		Result result = NpcTreasureShare.distribute(
			List.of(playerCharacter(), playerCharacter(), healthyNpc(2), downedNpc(3)),
			new FakePool());

		// NPC parts: 2. Total: 2 (npc) + 1 + 1 (PCs) + 1 (downed NPC counts as one).
		assertEquals(2, result.npcParts());
		assertEquals(5, result.totalParts());
	}

	@Test
	public void shareCountsAreMaskedToThreeBits() {
		Result result = NpcTreasureShare.distribute(List.of(healthyNpc(9)), new FakePool());

		// 9 & 7 = 1, per the C#'s "& 7".
		assertEquals(1, result.npcParts());
		assertEquals(1, result.totalParts());
	}

	@Test
	public void integerDivisionZeroesThePoolWhenNpcsHoldAMinorityOfParts() {
		// Faithful COAB quirk: npcParts / totalParts is integer division, so
		// 1/3 becomes scale 0 and every plain coin is wiped.
		FakePool pool = new FakePool(100, 50);

		Result result = NpcTreasureShare.distribute(
			List.of(playerCharacter(), playerCharacter(), healthyNpc(1)), pool);

		assertEquals(0.0, pool.appliedScale, 0.0);
		assertEquals(0, pool.coins[0]);
		assertEquals(0, pool.coins[1]);
		assertTrue(result.treasureTaken());
	}

	@Test
	public void allNpcPartyScalesByOneLeavingThePoolIntact() {
		// npcParts == totalParts -> integer scale 1, pool unchanged.
		FakePool pool = new FakePool(100);

		Result result = NpcTreasureShare.distribute(List.of(healthyNpc(1), healthyNpc(2)), pool);

		assertEquals(1.0, pool.appliedScale, 0.0);
		assertEquals(100, pool.coins[0]);
		assertTrue(result.treasureTaken());
	}

	@Test
	public void noNpcPartsLeavesThePoolUntouched() {
		FakePool pool = new FakePool(100);

		Result result = NpcTreasureShare.distribute(
			List.of(playerCharacter(), downedNpc(3)), pool);

		assertEquals(0, result.npcParts());
		assertFalse(result.treasureTaken());
		assertEquals(100, pool.coins[0]);
		// ScaleAll was never invoked (COAB guards with npcParts > 0).
		assertEquals(null, pool.appliedScale);
	}

	@Test
	public void emptyPoolTakesNothingAndNamesNoTakers() {
		FakePool pool = new FakePool(0, 0);

		Result result = NpcTreasureShare.distribute(
			List.of(playerCharacter(), healthyNpc(1)), pool);

		assertFalse(result.treasureTaken());
		assertTrue(result.takers().isEmpty());
	}

	@Test
	public void takersAreHealthyNpcsWithNonZeroShares() {
		FakePool pool = new FakePool(100);
		NpcCharacter taker = healthyNpc(2);
		NpcCharacter zeroShare = healthyNpc(0);
		NpcCharacter downed = downedNpc(3);

		Result result = NpcTreasureShare.distribute(
			List.of(playerCharacter(), taker, zeroShare, downed), pool);

		assertTrue(result.treasureTaken());
		assertEquals(List.of(taker), result.takers());
	}
}
