package engine.combat.map;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import engine.combat.BattlefieldBuffer;
import engine.combat.CombatPosition;

/**
 * Battlefield reachability and line-of-sight queries for combat.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * engine/ovr032.cs: {@code buildMapCache}, {@code MapCacheGet}, both {@code
 * canReachTarget} overloads, {@code canReachTargetCalc} (sub_733F1), {@code
 * CanSeeCombatant} (sub_7354A) and {@code FindCombatantDirection}. This class
 * is read-only over game state: it never mutates a combatant or the
 * battlefield, only answers queries against a {@link TileTraits} the
 * integrator supplies.</p>
 *
 * <p>COAB's coordinate space and this service's are the same shape:
 * {@code Point.MapMaxX}/{@code MapMaxY} are 50 and 25, matching {@code
 * engine.combat.BattlefieldBuffer}'s 50 x 25 tile grid, so
 * {@code engine.combat.CombatPosition} is reused directly as the coordinate
 * type.</p>
 */
public final class CombatMapService {
	// COAB gbl.MapDirectionXDelta / MapDirectionYDelta (unk_189A6 / unk_189AF,
	// seg600:2696 / seg600:269F). Index 8 ("no direction") is never actually
	// read: CanSeeCombatant returns true for direction 8 before indexing these.
	private static final int[] DIRECTION_X = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
	private static final int[] DIRECTION_Y = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };

	/** COAB's "no facing constraint" direction sentinel used by CanSeeCombatant. */
	public static final int DIRECTION_OMNIDIRECTIONAL = 8;
	/** COAB's alternate "always visible" sentinel (0xff) accepted by CanSeeCombatant. */
	public static final int DIRECTION_ANY = 0xff;

	private static final int BOARD_CELLS = BattlefieldBuffer.WIDTH * BattlefieldBuffer.HEIGHT;

	private final TileTraits tiles;
	// COAB static MapReach[,,] mapReachCache (ovr032.cs). A HashMap keyed by
	// (target index, attacker index, ignoreWalls) stands in for COAB's
	// preallocated 50*25 x 50*25 x 2 array — a labeled deviation to avoid a
	// ~3.1M-slot eager array allocation; behavior (lazily computed, then
	// cached forever) is identical.
	private final Map<Long, ReachResult> cache = new HashMap<>();

	public CombatMapService(TileTraits tiles) {
		this.tiles = Objects.requireNonNull(tiles, "tiles");
	}

	/**
	 * Eagerly warms the reachability cache for every (attacker, target,
	 * ignoreWalls) combination on the board.
	 *
	 * <p>Ported from COAB engine/ovr032.cs {@code buildMapCache}. In COAB that
	 * method is commented out (dead code) and its inner loop calls {@code
	 * canReachTargetCalc} with a stale parameter list that no longer matches
	 * the live signature used by {@code MapCacheGet} elsewhere in the same
	 * file. Labeled deviation: this port reconstructs {@code buildMapCache}'s
	 * evident intent — eagerly populate every cache slot for both wall modes
	 * — using the maintained {@link #reach(CombatPosition, CombatPosition,
	 * boolean)} path instead of the stale reference, since {@code
	 * MapCacheGet}'s lazy fill (which this port also implements, in {@link
	 * #reach}) is what COAB actually exercises at runtime.</p>
	 */
	public void buildMapCache() {
		for (int y1 = 0; y1 < BattlefieldBuffer.HEIGHT; y1++) {
			for (int x1 = 0; x1 < BattlefieldBuffer.WIDTH; x1++) {
				CombatPosition attacker = CombatPosition.of(x1, y1);
				for (int y2 = 0; y2 < BattlefieldBuffer.HEIGHT; y2++) {
					for (int x2 = 0; x2 < BattlefieldBuffer.WIDTH; x2++) {
						CombatPosition target = CombatPosition.of(x2, y2);
						reach(attacker, target, false);
						reach(attacker, target, true);
					}
				}
			}
		}
	}

	/**
	 * Cached reachability/line-of-sight walk from {@code attacker} to {@code
	 * target}. Ported from COAB engine/ovr032.cs {@code MapCacheGet}, folded
	 * together with the cache-miss call into {@code canReachTargetCalc}.
	 *
	 * @param ignoreWalls when true, walls never block the walk (COAB's {@code
	 *        groundTilesMap.ignoreWalls} / {@code field_6}).
	 */
	public ReachResult reach(CombatPosition attacker, CombatPosition target, boolean ignoreWalls) {
		Objects.requireNonNull(attacker, "attacker");
		Objects.requireNonNull(target, "target");

		long key = cacheKey(attacker, target, ignoreWalls);
		ReachResult cached = cache.get(key);
		if (cached != null) {
			return cached;
		}

		ReachResult computed = canReachTargetCalc(attacker, target, ignoreWalls);
		cache.put(key, computed);
		return computed;
	}

	/**
	 * Ported from COAB engine/ovr032.cs {@code canReachTarget(ref Point
	 * target, Point attacker)}. Returns the resolved point the walk actually
	 * reached: {@code target} itself when unobstructed, or the last tile
	 * before a blocking wall.
	 *
	 * <p>Deviation: COAB reads {@code ignoreWalls} off a shared global (
	 * {@code gbl.mapToBackGroundTile.ignoreWalls}); this port takes it as an
	 * explicit parameter since this service holds no such global state.</p>
	 */
	public CombatPosition canReachTarget(CombatPosition attacker, CombatPosition target, boolean ignoreWalls) {
		return reach(attacker, target, ignoreWalls).target();
	}

	/**
	 * Ported from COAB engine/ovr032.cs {@code canReachTarget(ref int range,
	 * Point target, Point attacker)}.
	 *
	 * @param maxRangeTiles caller's maximum range, in whole tiles (COAB's
	 *        by-ref {@code range} input).
	 * @see RangeCheckResult
	 */
	public RangeCheckResult canReachTarget(CombatPosition attacker, CombatPosition target, int maxRangeTiles,
		boolean ignoreWalls) {

		ReachResult mr = reach(attacker, target, ignoreWalls);

		if (mr.range() > (maxRangeTiles * 2) + 1) {
			return new RangeCheckResult(false, maxRangeTiles);
		}

		return new RangeCheckResult(mr.reach(), mr.range());
	}

	/**
	 * Whether {@code playerB}, facing {@code direction}, can see {@code
	 * playerA}. Ported from COAB engine/ovr032.cs {@code CanSeeCombatant}
	 * (sub_7354A).
	 *
	 * @param direction 0-7 compass direction (0 = north, clockwise), or
	 *        {@link #DIRECTION_OMNIDIRECTIONAL} / {@link #DIRECTION_ANY} for
	 *        "always visible regardless of facing".
	 */
	public boolean canSeeCombatant(int direction, CombatPosition playerA, CombatPosition playerB) {
		Objects.requireNonNull(playerA, "playerA");
		Objects.requireNonNull(playerB, "playerB");

		// COAB checks playerA/playerB.MapInBounds() here. CombatPosition's
		// factory already guarantees both are always in bounds, so that guard
		// can never observably fire in this port and is omitted (labeled
		// deviation).

		if (direction == DIRECTION_ANY || direction == DIRECTION_OMNIDIRECTIONAL) {
			return true;
		}
		if (direction < 0 || direction > 7) {
			throw new IllegalArgumentException("Unexpected direction: " + direction);
		}

		int facingX = playerB.x() + DIRECTION_X[direction];
		int facingY = playerB.y() + DIRECTION_Y[direction];

		if (playerB.equals(playerA) || (facingX == playerA.x() && facingY == playerA.y())) {
			return true;
		}

		int ax = playerA.x();
		int ay = playerA.y();

		switch (direction) {
			case 0:
				return (ax >= facingX && ay <= ((facingX - ax) + facingY))
					|| (ax <= facingX && ay <= ((ax - facingX) + facingY));

			case 1:
				return (ax >= facingX && ay <= ((facingX - ax) + facingY))
					|| (ax >= ((facingX - facingY) + ay) && ay <= facingY);

			case 2:
				return (ax >= (facingX + facingY - ay) && ay <= facingY)
					|| (ax >= (facingX + ay - facingY) && ay >= facingY);

			case 3:
				return (ax >= ((facingX + ay) - facingY) && ay >= facingY)
					|| (ax >= facingX && ay >= ((ax - facingX) + facingY));

			case 4:
				return (ax >= facingX && ay >= ((ax - facingX) + facingY))
					|| (ax <= facingX && ay >= ((facingX - ax) + facingY));

			case 5:
				return (ax <= facingX && ay >= ((facingX - ax) + facingY))
					|| (ax <= ((facingX + facingY) - ay) && ay >= facingY);

			case 6:
				return (ax <= ((facingX + facingY) - ay) && ay >= facingY)
					|| (ax <= ((facingX + ay) - facingY) && ay <= facingY);

			case 7:
				return (ax <= ((facingX + ay) - facingY) && ay <= facingY)
					|| (ax <= facingX && ay <= ((ax - facingX) + facingY));

			default:
				throw new IllegalStateException("Unreachable direction: " + direction);
		}
	}

	/**
	 * Scans directions 0-7 for the first one from which {@code attacker} can
	 * see {@code target}, returning 8 ({@link #DIRECTION_OMNIDIRECTIONAL}) if
	 * none of them do. Ported from COAB engine/ovr032.cs {@code
	 * FindCombatantDirection}.
	 */
	public int findCombatantDirection(CombatPosition target, CombatPosition attacker) {
		int dir = 0;
		while (!canSeeCombatant(dir, target, attacker) && dir < 8) {
			dir++;
		}
		return dir;
	}

	/**
	 * Ported from COAB engine/ovr032.cs {@code canReachTargetCalc} (sub_733F1),
	 * COAB's {@code Struct_1D1BC} indexer plus {@code gbl.BackGroundTiles}
	 * lookups replaced by direct {@link TileTraits} calls.
	 */
	private ReachResult canReachTargetCalc(CombatPosition attacker, CombatPosition target, boolean ignoreWalls) {
		// var_19: walks the real board tiles from attacker to target.
		CombatStepPath sightPath = new CombatStepPath();
		// var_31: walks a flat "sight elevation" profile pinned at the
		// attacker's own eye height — it has no board coordinates of its own.
		CombatStepPath heightPath = new CombatStepPath();

		final int maxRange = (256 * 2) + 1;

		sightPath.attackerX = attacker.x();
		sightPath.attackerY = attacker.y();
		sightPath.targetX = target.x();
		sightPath.targetY = target.y();
		sightPath.calculateDeltas();

		int attackerEyeHeight = tiles.eyeHeight(attacker.x(), attacker.y());

		heightPath.attackerX = 0;
		heightPath.attackerY = attackerEyeHeight;
		heightPath.targetX = Math.max(sightPath.diffX, sightPath.diffY);
		heightPath.targetY = attackerEyeHeight;
		heightPath.calculateDeltas();

		while (true) {
			int wallHeight = tiles.wallBlockHeight(sightPath.currentX, sightPath.currentY);

			if (!ignoreWalls && wallHeight > heightPath.currentY) {
				return new ReachResult(false, sightPath.steps, CombatPosition.of(sightPath.currentX, sightPath.currentY));
			}

			// COAB comment: "range is for cache hard coded to 256, thus
			// max_range = 513, so skip this" — on this 50 x 25 board the
			// walk can never exceed ~150 steps, so this never fires. Kept for
			// fidelity with the ported control flow.
			if (sightPath.steps > maxRange) {
				return new ReachResult(false, sightPath.steps, CombatPosition.of(sightPath.currentX, sightPath.currentY));
			}

			heightPath.step();
			boolean stepped = sightPath.step();
			if (!stepped) {
				break;
			}
		}

		return new ReachResult(true, sightPath.steps, target);
	}

	private static long cacheKey(CombatPosition attacker, CombatPosition target, boolean ignoreWalls) {
		int attackerIndex = attacker.y() * BattlefieldBuffer.WIDTH + attacker.x();
		int targetIndex = target.y() * BattlefieldBuffer.WIDTH + target.x();
		// Mirrors COAB's mapReachCache[(target...), (attacker...), ignoreWalls]
		// index order.
		long key = ((long) targetIndex * BOARD_CELLS + attackerIndex) * 2;
		return ignoreWalls ? key + 1 : key;
	}
}
