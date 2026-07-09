package main;

import engine.combat.CombatState;
import engine.combat.Combatant;
import engine.combat.CombatPosition;

/**
 * Console demo for Java Combat Runtime State Pass 1.
 *
 * <p>This intentionally does not require original assets.  It creates the
 * recovered battlefield buffer, places a screenshot-inspired Ratwurst encounter,
 * performs one deterministic movement and one deterministic attack, and prints
 * the state summary.  The Swing/asset renderer can consume the same
 * CombatState object in a later pass.</p>
 */
public final class MatrixCubedCombatStateDemo {
	private MatrixCubedCombatStateDemo() {
	}

	public static void main(String[] args) {
		CombatState state = CombatState.ratwurstVerticalSlice();
		System.out.print(state.renderSummary());

		Combatant current = state.current();
		if (current != null) {
			state.moveCurrentTo(CombatPosition.of(current.position().x() + 1, current.position().y()));
			Combatant target = state.livingMonsters().isEmpty() ? null : state.livingMonsters().get(0);
			if (target != null) {
				state.attack(target, 17);
			}
			state.endTurn();
		}

		System.out.println();
		System.out.println("After deterministic smoke action:");
		for (String line : state.log()) {
			System.out.println("  " + line);
		}
		System.out.println("Current phase: " + state.phase() + "  result=" + state.combatResult());
	}
}
