package engine.combat.map;

/**
 * Hook the integrator implements to expose battlefield tile attributes used by
 * {@link CombatMapService} for line-of-sight blocking.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * engine/ovr032.cs canReachTargetCalc (sub_733F1). COAB reads two fields off a
 * fixed 64-entry {@code gbl.BackGroundTiles} table indexed by ground tile
 * code:</p>
 * <ul>
 * <li>{@code field_1} — the "eye height" of the tile the attacker stands on,
 * used once at the start of the walk as the constant sight-line elevation.</li>
 * <li>{@code field_2} — the "wall height" of each tile the sight line steps
 * through; if it exceeds the attacker's eye height, the line is blocked
 * (unless walls are being ignored).</li>
 * </ul>
 *
 * <p>Those two fields belong to a specific Gold Box game's background-tile
 * table (AD&D Pool of Radiance-family tile semantics in COAB). This engine
 * does not know Matrix Cubed's tile table or its wall/height encoding, so the
 * integrator must supply it here rather than have one invented. Coordinates
 * are the same zero-based column/row convention as
 * {@code engine.combat.BattlefieldBuffer} (50 x 25).</p>
 */
public interface TileTraits {
	/**
	 * Eye height of the tile at (x, y). Ported from COAB's
	 * {@code gbl.BackGroundTiles[tile].field_1}, read only for the
	 * attacker's own tile in {@code canReachTargetCalc}.
	 */
	int eyeHeight(int x, int y);

	/**
	 * Wall/blocking height of the tile at (x, y). Ported from COAB's
	 * {@code gbl.BackGroundTiles[tile].field_2}, compared against the
	 * attacker's eye height for every tile the sight line steps through.
	 */
	int wallBlockHeight(int x, int y);
}
