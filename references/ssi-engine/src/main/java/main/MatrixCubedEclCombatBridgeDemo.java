package main;

import java.util.List;

import engine.combat.CombatEncounterFactory;
import engine.combat.EclCombatBridge;

/**
 * Headless demo for the ECL combat bridge.
 *
 * <p>This does not load original files.  It demonstrates the same bridge that
 * VirtualMachine COMBAT now uses: ECL-style monster seeds -> CombatState ->
 * deterministic resolver -> COMBAT_RESULT.</p>
 */
public final class MatrixCubedEclCombatBridgeDemo {
	private MatrixCubedEclCombatBridgeDemo() {
	}

	public static void main(String[] args) {
		CombatEncounterFactory.MonsterSeed ratwurst = CombatEncounterFactory.MonsterSeed.ratwurst();
		EclCombatBridge.EclCombatResult result = new EclCombatBridge()
			.resolve(List.of(ratwurst, ratwurst, ratwurst, ratwurst));
		System.out.print(result.transcript());
	}
}
