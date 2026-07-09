package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import engine.combat.Combatant.Side;

public class CombatControllerTest {
	@Test
	public void contextualActionMovesPartyMemberToOpenCursor() {
		CombatController controller = new CombatController(CombatState.ratwurstVerticalSlice(), 1L);
		advanceUntilPartyTurn(controller);
		Combatant active = controller.state().current();
		CombatPosition target = adjacentFreeCell(controller.state(), active);

		controller.setCursor(target);
		CombatController.Action action = controller.contextualAction();

		assertEquals(CombatController.Action.MOVED, action);
		assertEquals(target, controller.state().current().position());
	}

	@Test
	public void attackCursorAttacksEnemyAndAdvancesTurn() {
		CombatController controller = new CombatController(CombatState.ratwurstVerticalSlice(), 52017L);
		Combatant attacker = controller.state().current();
		Combatant enemy = controller.state().livingCombatants().stream()
			.filter(c -> c.side() != attacker.side())
			.findFirst().orElseThrow();

		controller.setCursor(enemy.position());
		CombatController.Action action = controller.attackCursor();

		assertEquals(CombatController.Action.ATTACKED, action);
		assertTrue(enemy.hitPoints() < enemy.maxHitPoints());
		// Acting spends the attacker's initiative delay, so the turn passed on.
		assertNotEquals(attacker, controller.state().current());
	}

	@Test
	public void selectNextEnemyMovesCursorOntoLivingEnemy() {
		CombatController controller = new CombatController(CombatState.ratwurstVerticalSlice(), 1L);
		advanceUntilPartyTurn(controller);

		controller.selectNextEnemy();

		assertTrue(controller.state().livingMonsters().stream()
			.anyMatch(m -> m.position().equals(controller.cursor())));
	}

	@Test
	public void monsterTurnCanAutoResolveWithoutUi() {
		CombatController controller = new CombatController(CombatState.ratwurstVerticalSlice(), 3L);

		int guard = 0;
		while (controller.state().current().side() != Side.MONSTER && guard++ < 50) {
			controller.endTurn();
		}
		assertEquals(Side.MONSTER, controller.state().current().side());

		CombatController.Action action = controller.resolveMonsterTurn();

		assertEquals(CombatController.Action.MONSTER_ACTED, action);
	}

	@Test
	public void debugVictoryForcesCombatResultVictory() {
		CombatController controller = new CombatController(CombatState.ratwurstVerticalSlice(), 3L);

		CombatController.Action action = controller.forceVictoryForDebug();

		assertEquals(CombatController.Action.COMBAT_OVER, action);
		assertEquals(CombatState.Phase.VICTORY, controller.state().phase());
		assertEquals(0, controller.state().combatResult());
		assertTrue(controller.state().log().stream().anyMatch(s -> s.contains("DEV VICTORY")));
	}

	private static void advanceUntilPartyTurn(CombatController controller) {
		int guard = 0;
		while (controller.state().current().side() != Side.PARTY && guard++ < 50) {
			controller.endTurn();
		}
		assertEquals(Side.PARTY, controller.state().current().side());
	}

	private static CombatPosition adjacentFreeCell(CombatState state, Combatant active) {
		int[][] steps = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int[] step : steps) {
			int x = active.position().x() + step[0];
			int y = active.position().y() + step[1];
			if (CombatPosition.isInside(x, y) && state.occupantAt(CombatPosition.of(x, y)).isEmpty()) {
				return CombatPosition.of(x, y);
			}
		}
		throw new IllegalStateException("no free cell adjacent to " + active);
	}
}
