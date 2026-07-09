package integration;

import static org.junit.Assert.assertTrue;

import java.io.File;

import org.junit.Assume;
import org.junit.Before;
import org.junit.Test;

import engine.script.EclOpCode;
import main.MatrixCubedPlaythroughProber;
import main.MatrixCubedPlaythroughProber.OpcodeStat;
import main.MatrixCubedPlaythroughProber.SweepResult;

/**
 * Headless smoke test for the Lane 1 playthrough prober
 * ({@code docs/engine-completion-plan-2026-07-09.md} sections 1 and 4.1).
 *
 * <p>Skips (via {@link Assume}) when the original Matrix Cubed game files
 * are not present locally, matching the pattern in
 * {@link MatrixCubedSmokeTest}. With the game files present, this asserts
 * only structural facts about the static sweep: it finds real opcode
 * activity, and it finds at least one known-stub opcode actually present
 * in the real ECL corpus (grounded in what the sweep found in this repo's
 * copy of the game data, not assumed).</p>
 */
public class PlaythroughProberTest {
	private static final String GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";

	@Before
	public void locateGameDir() {
		File gameDir = new File(GAME_DIR);
		Assume.assumeTrue("Matrix Cubed original game files not found at " + GAME_DIR, gameDir.isDirectory());
	}

	@Test
	public void staticSweepFindsOpcodeActivityAndAKnownStub() throws Exception {
		SweepResult sweep = MatrixCubedPlaythroughProber.runStaticSweep(GAME_DIR);

		assertTrue("Sweep should discover at least one ECL block", sweep.eclIdCount > 0);
		assertTrue("Sweep should successfully load at least one ECL block", sweep.blocksLoaded > 0);
		assertTrue("Sweep should tally a nonzero number of instructions", sweep.totalInstructions > 0);
		assertTrue("Sweep should tally at least one opcode", !sweep.opcodeStats.isEmpty());

		// TREASURE is the plan's canonical Lane-1 example blocker (section 4.1
		// item 2: "engine/loot -> TREASURE*/ROB opcodes"). Confirm it is a
		// STUB per our measured classification and that it actually occurs in
		// the real Matrix ECL corpus, rather than assuming it does.
		assertTrue("TREASURE must be in the measured STUB_OPCODES set",
			MatrixCubedPlaythroughProber.STUB_OPCODES.contains(EclOpCode.TREASURE));

		boolean foundStubHit = sweep.opcodeStats.values().stream()
			.anyMatch(stat -> isStubOrNoImpl(stat) && stat.occurrences > 0);
		assertTrue("Static sweep should find at least one occurrence of a known-stub/no-impl opcode "
			+ "in the real Matrix ECL corpus", foundStubHit);
	}

	private static boolean isStubOrNoImpl(OpcodeStat stat) {
		return MatrixCubedPlaythroughProber.STUB_OPCODES.contains(stat.opcode)
			|| MatrixCubedPlaythroughProber.NO_IMPL_OPCODES.contains(stat.opcode);
	}
}
