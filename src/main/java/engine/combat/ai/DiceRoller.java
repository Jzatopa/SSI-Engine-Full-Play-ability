package engine.combat.ai;

import java.util.Random;

/**
 * Injected dice source for the quick-fight planner.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * engine/ovr024.cs {@code roll_dice(sides, count)}; every call site in the
 * quick-fight decision flow uses {@code count == 1}, so only the single-die
 * form is exposed. Tests inject a scripted implementation for determinism;
 * production wiring can use {@link #seeded(long)} (deterministic given the
 * seed, but not the original RNG stream — same labeled deviation as
 * {@code engine.combat.CombatTurnQueue}).</p>
 */
public interface DiceRoller {
	/** Uniform roll in {@code 1..sides}, mirroring COAB {@code roll_dice(sides, 1)}. */
	int roll(int sides);

	static DiceRoller seeded(long seed) {
		Random random = new Random(seed);
		return sides -> random.nextInt(sides) + 1;
	}
}
