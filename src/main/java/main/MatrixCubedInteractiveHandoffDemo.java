package main;

import java.nio.file.Path;
import java.util.List;

import engine.combat.CombatEncounterFactory;
import engine.combat.EclCombatBridge;

/**
 * Demo for the interactive VM combat handoff scaffold.
 *
 * <p>In a graphical environment this uses SwingCombatUiBridge.  In a headless
 * environment it automatically falls back to the deterministic resolver and
 * still returns COMBAT_RESULT through the same bridge API.</p>
 */
public final class MatrixCubedInteractiveHandoffDemo {
	private static final Path DEFAULT_GAME_DIR = Path.of("../../generated/liveplay/first_map_capture/game");

	private MatrixCubedInteractiveHandoffDemo() {
	}

	public static void main(String[] args) {
		Path gameDir = args.length > 0 ? Path.of(args[0]) : DEFAULT_GAME_DIR;
		EclCombatBridge bridge = new EclCombatBridge(
			new CombatEncounterFactory(),
			new SwingCombatUiBridge(gameDir)
		);
		EclCombatBridge.EclCombatResult result = bridge.resolve(List.of(
			CombatEncounterFactory.MonsterSeed.ratwurst(),
			CombatEncounterFactory.MonsterSeed.ratwurst(),
			CombatEncounterFactory.MonsterSeed.ratwurst(),
			CombatEncounterFactory.MonsterSeed.ratwurst()
		));
		System.out.print(result.transcript());
		System.out.println("Resolver used: " + result.resolverName());
		System.out.println("Interactive: " + result.interactive());
	}
}
