package engine.combat.map;

/**
 * Incremental Bresenham-style walker between two integer points.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * {@code Classes/SteppingPath.cs} ({@code Step} is sub_7324C, {@code
 * CalculateDeltas} is sub_731A5).</p>
 *
 * <p>COAB's {@code canReachTargetCalc} (ovr032.cs, sub_733F1) reuses this same
 * generic (x, y) stepper for two different walks: one over real battlefield
 * tiles from attacker to target, and one over an abstract "sight elevation"
 * profile that has no board coordinates of its own. This class therefore
 * works in raw mutable ints rather than {@code engine.combat.CombatPosition},
 * matching COAB's reuse of its generic {@code Point} for both purposes.
 * Package-private: it is an implementation detail of {@link CombatMapService}
 * and is not part of this package's public surface.</p>
 *
 * <p>Deviation: COAB's {@code steps} and {@code direction} fields are {@code
 * byte} (0-255, wrapping on overflow). This port widens them to {@code int}
 * (no wraparound). On the 50 x 25 board {@link CombatMapService} operates
 * over, the maximum possible step count is well under 256, so this is not
 * observable for that board size; it would diverge from COAB only for a board
 * large enough to overflow a byte.</p>
 */
final class CombatStepPath {
	int attackerX;
	int attackerY;
	int targetX;
	int targetY;

	int currentX;
	int currentY;

	int diffX;
	int diffY;

	private int deltaCount;
	private int signX;
	private int signY;

	int steps;
	int direction;

	private static final int[] DIRECTIONS = { 7, 0, 1, 6, 8, 2, 5, 4, 3, 8 };

	/** Ported from COAB SteppingPath.CalculateDeltas (sub_731A5). */
	void calculateDeltas() {
		currentX = attackerX;
		currentY = attackerY;

		int tmpX = targetX - attackerX;
		int tmpY = targetY - attackerY;
		diffX = Math.abs(tmpX);
		diffY = Math.abs(tmpY);

		signX = Integer.signum(tmpX);
		signY = Integer.signum(tmpY);

		deltaCount = 0;
		steps = 0;
	}

	/**
	 * Ported from COAB SteppingPath.Step (sub_7324C).
	 *
	 * @return whether a step was actually taken (false once the walk has
	 *         already arrived at the target).
	 */
	boolean step() {
		boolean stepMade = false;
		int indexX = 1;
		int indexY = 1;

		if (diffX >= diffY) {
			if (currentX != targetX) {
				currentX += signX;
				deltaCount += diffY * 2;
				steps += 2;

				indexX = signX + 1;

				if (deltaCount >= diffX) {
					currentY += signY;
					deltaCount -= diffX * 2;
					steps += 1;

					indexY = signY + 1;
				}

				stepMade = true;
			}
		} else if (currentY != targetY) {
			currentY += signY;
			deltaCount += diffX * 2;
			steps += 2;

			indexY = signY + 1;

			if (deltaCount >= diffY) {
				currentX += signX;
				deltaCount -= diffY * 2;
				steps += 1;

				indexX = signX + 1;
			}

			stepMade = true;
		}

		direction = DIRECTIONS[(indexY * 3) + indexX];

		return stepMade;
	}
}
