package engine.combat.map;

/**
 * Result of a bounded reachability check against a caller-supplied maximum
 * range.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * engine/ovr032.cs {@code canReachTarget(ref int range, Point target, Point
 * attacker)}. That C# overload uses {@code range} as both an input (the
 * caller's maximum, in whole tiles) and an output (the actual distance walked,
 * in COAB's raw step units — see {@link ReachResult#range()}); Java has no
 * by-ref primitives, so this record carries both directions of that value
 * explicitly. When the walk exceeds the caller's maximum the original leaves
 * {@code range} untouched at the input value and returns false without ever
 * inspecting {@code reach} — {@link #reachable()} mirrors that early-exit
 * false, and {@link #range()} mirrors the untouched value.</p>
 *
 * @param reachable true only if the walk stayed within the caller's maximum
 *        range and was not blocked by a wall.
 * @param range COAB's output {@code range}: the raw step count of the walk
 *        (see {@link ReachResult#range()}) when the walk was evaluated, or the
 *        caller's original maximum, untouched, when the walk was rejected
 *        purely for exceeding that maximum before a block/reach outcome was
 *        considered.
 */
public record RangeCheckResult(boolean reachable, int range) {
}
