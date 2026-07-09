package engine.combat.map;

import engine.combat.CombatPosition;

/**
 * Result of a reachability/line-of-sight walk between two battlefield tiles.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * engine/ovr032.cs, nested class {@code MapReach} used by
 * {@code canReachTargetCalc} (sub_733F1) and cached by {@code MapCacheGet}.</p>
 *
 * @param reach whether the sight line reached {@code target} without being
 *        blocked by a wall (COAB {@code MapReach.reach}).
 * @param range raw step count of the walk, in the same doubled/diagonal-aware
 *        units COAB's {@link engine.combat.map} package's stepping path
 *        produces (2 per orthogonal step, 3 per diagonal step; divide by 2 for
 *        whole-tile distance). This is the distance actually walked, which for
 *        a blocked line is the distance to the blocking tile, not to
 *        {@code target} (COAB {@code MapReach.range}).
 * @param target the position the walk actually reached: {@code target} itself
 *        if {@code reach} is true, otherwise the last tile stepped onto before
 *        the wall blocked further travel (COAB {@code MapReach.target}).
 */
public record ReachResult(boolean reach, int range, CombatPosition target) {
}
