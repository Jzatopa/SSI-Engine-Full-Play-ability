package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class RecoveredEnemyTacticsTest {
	@Test
	public void remembersValidSelectedTarget() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		Combatant actor = state.livingMonsters().get(0);
		RecoveredEnemyTactics tactics = new RecoveredEnemyTactics();

		Combatant selected = tactics.selectTarget(state, actor).orElseThrow();

		assertEquals(selected.id(), tactics.rememberedTargetId(actor.id()).orElseThrow().intValue());
		assertEquals(selected, tactics.selectTarget(state, actor).orElseThrow());
	}

	@Test
	public void invalidatesDeadRememberedTarget() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		Combatant actor = state.livingMonsters().get(0);
		RecoveredEnemyTactics tactics = new RecoveredEnemyTactics();
		Combatant first = tactics.selectTarget(state, actor).orElseThrow();
		first.applyDamage(first.hitPoints());

		Combatant replacement = tactics.selectTarget(state, actor).orElseThrow();

		assertTrue(replacement.isAlive());
		assertTrue(replacement.id() != first.id());
		assertEquals(replacement.id(), tactics.rememberedTargetId(actor.id()).orElseThrow().intValue());
	}

	@Test
	public void preservesOriginalTwentyAttemptBound() {
		assertEquals(20, RecoveredEnemyTactics.ORIGINAL_CANDIDATE_ATTEMPT_LIMIT);
	}
}
