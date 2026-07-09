package engine.combat;

import java.util.Objects;

/**
 * Immutable coordinate in the recovered Matrix Cubed combat battlefield buffer.
 *
 * <p>The recovered combat board is represented by {@link BattlefieldBuffer} as a
 * 50 x 25 tile field with a seven-byte header.  Coordinates here use the same
 * zero-based column/row convention as that buffer.</p>
 */
public final class CombatPosition {
	private final int x;
	private final int y;

	private CombatPosition(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public static CombatPosition of(int x, int y) {
		if (!isInside(x, y)) {
			throw new IllegalArgumentException("Combat position outside battlefield: (" + x + "," + y + ")");
		}
		return new CombatPosition(x, y);
	}

	public static boolean isInside(int x, int y) {
		return x >= 0 && x < BattlefieldBuffer.WIDTH && y >= 0 && y < BattlefieldBuffer.HEIGHT;
	}

	public int x() {
		return x;
	}

	public int y() {
		return y;
	}

	public CombatPosition translate(int dx, int dy) {
		return CombatPosition.of(x + dx, y + dy);
	}

	public int manhattanDistance(CombatPosition other) {
		return Math.abs(x - other.x) + Math.abs(y - other.y);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof CombatPosition)) {
			return false;
		}
		CombatPosition other = (CombatPosition) obj;
		return x == other.x && y == other.y;
	}

	@Override
	public int hashCode() {
		return Objects.hash(x, y);
	}

	@Override
	public String toString() {
		return "(" + x + "," + y + ")";
	}
}
