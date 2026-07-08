package engine.combat.map;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.HashSet;
import java.util.Set;

import org.junit.Test;

import engine.combat.CombatPosition;

/**
 * Conformance tests for the COAB-ported reachability/line-of-sight semantics
 * (engine/ovr032.cs, coab commit 9dc46f1): {@code buildMapCache}, {@code
 * MapCacheGet}, both {@code canReachTarget} overloads, {@code
 * canReachTargetCalc}, {@code CanSeeCombatant} and {@code
 * FindCombatantDirection}.
 *
 * <p>Expected values for {@link CombatMapService#canSeeCombatant} are derived
 * by hand-evaluating the ported switch-case formulas directly (not from
 * geometric intuition), since this is a faithful port of decompiled integer
 * arithmetic rather than a from-scratch field-of-view implementation.</p>
 */
public class CombatMapServiceTest {

	/** Open grid with a settable set of high-wall tiles, all other tiles flat. */
	private static final class SyntheticBattlefield implements TileTraits {
		private static final int FLAT_EYE_HEIGHT = 1;
		private static final int WALL_HEIGHT = 99;

		private final Set<Long> walls = new HashSet<>();

		void addWall(int x, int y) {
			walls.add(key(x, y));
		}

		@Override
		public int eyeHeight(int x, int y) {
			return FLAT_EYE_HEIGHT;
		}

		@Override
		public int wallBlockHeight(int x, int y) {
			return walls.contains(key(x, y)) ? WALL_HEIGHT : 0;
		}

		private static long key(int x, int y) {
			return ((long) y << 32) | (x & 0xffffffffL);
		}
	}

	// --- reach() / canReachTargetCalc -------------------------------------

	@Test
	public void openStraightLineIsFullyReachableWithDistanceInDoubledUnits() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(5, 0);

		ReachResult result = service.reach(attacker, target, false);

		assertTrue(result.reach());
		assertEquals(10, result.range()); // 5 tiles * 2 units/orthogonal step
		assertEquals(target, result.target());
	}

	@Test
	public void openDiagonalLineCostsThreeUnitsPerTile() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(3, 3);

		ReachResult result = service.reach(attacker, target, false);

		assertTrue(result.reach());
		assertEquals(9, result.range()); // 3 diagonal tiles * 3 units/diagonal step
		assertEquals(target, result.target());
	}

	@Test
	public void wallBetweenAttackerAndTargetBlocksReachAtTheWallTile() {
		SyntheticBattlefield board = new SyntheticBattlefield();
		board.addWall(2, 2);
		CombatMapService service = new CombatMapService(board);

		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(3, 3);

		ReachResult result = service.reach(attacker, target, false);

		assertFalse(result.reach());
		assertEquals(CombatPosition.of(2, 2), result.target());
		assertEquals(6, result.range()); // steps accumulated before the wall tile was checked
	}

	@Test
	public void wallAtTheTargetTileItselfStillBlocks() {
		SyntheticBattlefield board = new SyntheticBattlefield();
		board.addWall(3, 0);
		CombatMapService service = new CombatMapService(board);

		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(3, 0);

		ReachResult result = service.reach(attacker, target, false);

		assertFalse(result.reach());
		assertEquals(target, result.target());
	}

	@Test
	public void ignoreWallsBypassesBlockingTiles() {
		SyntheticBattlefield board = new SyntheticBattlefield();
		board.addWall(2, 2);
		CombatMapService service = new CombatMapService(board);

		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(3, 3);

		ReachResult result = service.reach(attacker, target, true);

		assertTrue(result.reach());
		assertEquals(target, result.target());
		assertEquals(9, result.range());
	}

	@Test
	public void samePositionIsAlwaysReachableUnlessSelfBlocked() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition p = CombatPosition.of(10, 10);

		ReachResult result = service.reach(p, p, false);

		assertTrue(result.reach());
		assertEquals(0, result.range());
		assertEquals(p, result.target());
	}

	@Test
	public void wallModeIsCachedIndependentlyOfIgnoreWallsMode() {
		SyntheticBattlefield board = new SyntheticBattlefield();
		board.addWall(2, 2);
		CombatMapService service = new CombatMapService(board);
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(3, 3);

		ReachResult blocked = service.reach(attacker, target, false);
		ReachResult bypassed = service.reach(attacker, target, true);

		assertFalse(blocked.reach());
		assertTrue(bypassed.reach());
	}

	// --- canReachTarget overloads -------------------------------------------

	@Test
	public void pointOverloadReturnsTargetWhenUnobstructed() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(5, 0);

		assertEquals(target, service.canReachTarget(attacker, target, false));
	}

	@Test
	public void pointOverloadReturnsBlockingTileWhenObstructed() {
		SyntheticBattlefield board = new SyntheticBattlefield();
		board.addWall(3, 0);
		CombatMapService service = new CombatMapService(board);
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(5, 0);

		assertEquals(CombatPosition.of(3, 0), service.canReachTarget(attacker, target, false));
	}

	@Test
	public void rangeOverloadRejectsWhenBeyondCallerMaximum() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(10, 0); // 20 raw units

		RangeCheckResult result = service.canReachTarget(attacker, target, 5, false);

		assertFalse(result.reachable());
		assertEquals(5, result.range()); // untouched caller maximum, mirroring the by-ref C# semantics
	}

	@Test
	public void rangeOverloadAcceptsAndReportsActualRangeWhenWithinCallerMaximum() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(10, 0); // 20 raw units

		RangeCheckResult result = service.canReachTarget(attacker, target, 15, false);

		assertTrue(result.reachable());
		assertEquals(20, result.range());
	}

	// --- canSeeCombatant -----------------------------------------------------

	@Test
	public void directionSentinelsAreAlwaysVisibleRegardlessOfPosition() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition a = CombatPosition.of(0, 0);
		CombatPosition b = CombatPosition.of(49, 24);

		assertTrue(service.canSeeCombatant(CombatMapService.DIRECTION_OMNIDIRECTIONAL, a, b));
		assertTrue(service.canSeeCombatant(CombatMapService.DIRECTION_ANY, a, b));
	}

	@Test
	public void sameTileIsAlwaysVisible() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition p = CombatPosition.of(5, 5);

		for (int dir = 0; dir < 8; dir++) {
			assertTrue("direction " + dir, service.canSeeCombatant(dir, p, p));
		}
	}

	@Test
	public void facingTileIsAlwaysVisible() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition observer = CombatPosition.of(5, 5);
		CombatPosition directlyNorth = CombatPosition.of(5, 4);

		assertTrue(service.canSeeCombatant(0, directlyNorth, observer));
	}

	@Test
	public void targetAheadInFacingDirectionIsVisible() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition observer = CombatPosition.of(5, 5);
		CombatPosition farNorth = CombatPosition.of(5, 2);

		assertTrue(service.canSeeCombatant(0, farNorth, observer));
	}

	@Test
	public void targetDirectlyBehindFacingDirectionIsNotVisible() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition observer = CombatPosition.of(5, 5);
		CombatPosition behind = CombatPosition.of(5, 8);

		assertFalse(service.canSeeCombatant(0, behind, observer));
	}

	@Test
	public void targetDueEastIsNotVisibleWhileFacingNorth() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition observer = CombatPosition.of(5, 5);
		CombatPosition east = CombatPosition.of(8, 5);

		assertFalse(service.canSeeCombatant(0, east, observer));
	}

	@Test
	public void targetDueEastIsVisibleWhileFacingEast() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition observer = CombatPosition.of(5, 5);
		CombatPosition east = CombatPosition.of(8, 5);

		assertTrue(service.canSeeCombatant(2, east, observer));
	}

	/**
	 * Exact boundary of case 0's first disjunct ({@code ay <= (facingX - ax) +
	 * facingY}): with observer (5,5) facing north (facingX=5, facingY=4), the
	 * point (6,3) lands exactly on {@code ay == (facingX-ax)+facingY} (3 ==
	 * (5-6)+4). The ported {@code <=} must include it; one tile further south
	 * (6,4) must fall just outside.
	 */
	@Test
	public void caseZeroBoundaryIsInclusiveExactlyAtTheEdgeAndExclusiveOneTilePastIt() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition observer = CombatPosition.of(5, 5);
		CombatPosition onBoundary = CombatPosition.of(6, 3);
		CombatPosition pastBoundary = CombatPosition.of(6, 4);

		assertTrue(service.canSeeCombatant(0, onBoundary, observer));
		assertFalse(service.canSeeCombatant(0, pastBoundary, observer));
	}

	@Test(expected = IllegalArgumentException.class)
	public void outOfRangeDirectionThrows() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		service.canSeeCombatant(9, CombatPosition.of(0, 0), CombatPosition.of(1, 1));
	}

	// --- findCombatantDirection -----------------------------------------------

	@Test
	public void findCombatantDirectionReturnsFirstMatchingDirectionInSequence() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(5, 5);
		CombatPosition target = CombatPosition.of(5, 2); // north; direction 0 sees it first

		assertEquals(0, service.findCombatantDirection(target, attacker));
	}

	@Test
	public void findCombatantDirectionScansPastNonMatchingDirectionsFirst() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(5, 5);
		CombatPosition target = CombatPosition.of(8, 5); // due east; directions 0 and 1 miss, 2 hits

		assertEquals(2, service.findCombatantDirection(target, attacker));
	}

	/**
	 * Board-wide invariant of the ported scan: the returned direction is
	 * always the first d in 0..8 whose {@code canSeeCombatant(d, ...)} is
	 * true, and it always sees the target (direction 8 sees everything, so
	 * COAB's fallback of returning 8 after a failed 0-7 scan preserves the
	 * invariant even if the geometry ever left a gap).
	 */
	@Test
	public void findCombatantDirectionAlwaysReturnsFirstSeeingDirectionAcrossTheBoard() {
		CombatMapService service = new CombatMapService(new SyntheticBattlefield());
		CombatPosition attacker = CombatPosition.of(25, 12);

		for (int y = 0; y < 25; y++) {
			for (int x = 0; x < 50; x++) {
				CombatPosition target = CombatPosition.of(x, y);
				int dir = service.findCombatantDirection(target, attacker);
				assertTrue("dir in 0..8 for " + target, dir >= 0 && dir <= 8);
				assertTrue("returned direction sees " + target, service.canSeeCombatant(dir, target, attacker));
				for (int earlier = 0; earlier < dir; earlier++) {
					assertFalse("direction " + earlier + " must not see " + target + " before " + dir,
						service.canSeeCombatant(earlier, target, attacker));
				}
			}
		}
	}

	// --- buildMapCache ---------------------------------------------------------

	@Test(timeout = 60000)
	public void buildMapCacheWarmsCacheConsistentlyWithLazyReach() {
		SyntheticBattlefield board = new SyntheticBattlefield();
		board.addWall(2, 2);
		CombatMapService service = new CombatMapService(board);

		service.buildMapCache();

		CombatPosition attacker = CombatPosition.of(0, 0);
		CombatPosition target = CombatPosition.of(3, 3);

		ReachResult warmed = service.reach(attacker, target, false);
		assertFalse(warmed.reach());
		assertEquals(CombatPosition.of(2, 2), warmed.target());

		ReachResult warmedIgnoreWalls = service.reach(attacker, target, true);
		assertTrue(warmedIgnoreWalls.reach());
	}
}
