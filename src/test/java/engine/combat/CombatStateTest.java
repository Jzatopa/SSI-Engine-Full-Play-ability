package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

import engine.combat.Combatant.Side;
import engine.combat.RecoveredBattlefieldGenerator.GeneratedBattlefield;
import engine.combat.RecoveredBattlefieldGenerator.Options;
import engine.combat.RecoveredBattlefieldGenerator.Terrain;

public class CombatStateTest {
	@Test
	public void ratwurstVerticalSliceCreatesStatefulCombatOnRecoveredBattlefield() {
		CombatState state = CombatState.ratwurstVerticalSlice();

		assertEquals(10, state.combatants().size());
		assertEquals(6, state.livingParty().size());
		assertEquals(4, state.livingMonsters().size());
		assertEquals(-1, state.combatResult());
		assertEquals(7 + 50 * 25, state.battlefield().toByteArray().length);
		// Turn order is initiative-based (COAB port); whoever won the first
		// scan is current and the phase must match that combatant's side.
		assertNotNull(state.current());
		assertEquals(state.current().side() == Side.PARTY ? CombatState.Phase.PARTY_TURN : CombatState.Phase.MONSTER_TURN,
			state.phase());
		assertTrue(state.renderSummary().contains("Ratwurst vertical slice"));
	}

	@Test
	public void moveCurrentRejectsOccupiedOrOutOfRangeCells() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		Combatant active = state.current();
		Combatant other = state.livingCombatants().stream()
			.filter(c -> c != active)
			.findFirst().orElseThrow();

		assertFalse(state.moveCurrentTo(other.position()));

		int reach = active.movement() + 1;
		int farX = CombatPosition.isInside(active.position().x() + reach, active.position().y())
			? active.position().x() + reach
			: active.position().x() - reach;
		assertFalse(state.moveCurrentTo(CombatPosition.of(farX, active.position().y())));

		CombatPosition near = adjacentFreeCell(state, active);
		assertTrue(state.moveCurrentTo(near));
		assertEquals(near, state.current().position());
	}

	@Test
	public void attackMarksCurrentActedAndDamagesEnemy() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		Combatant enemy = state.livingCombatants().stream()
			.filter(c -> c.side() != state.current().side())
			.findFirst().orElseThrow();

		CombatState.AttackResult result = state.attack(enemy, 20);

		assertTrue(result.hit());
		assertTrue(result.damage() > 0);
		assertTrue(enemy.hitPoints() < enemy.maxHitPoints());
		assertTrue(state.current().hasActed());
		assertEquals(state.current().side() == Side.PARTY ? CombatState.Phase.PARTY_TURN : CombatState.Phase.MONSTER_TURN,
			result.phaseAfter());
		assertEquals(-1, state.combatResult());
	}

	@Test
	public void killingAllMonstersSetsGoldBoxVictoryResult() {
		Options options = new Options();
		GeneratedBattlefield generated = new RecoveredBattlefieldGenerator().generate(options);
		Combatant hero = new Combatant(1, "HERO", Side.PARTY, 30, 4, 5, 60, 60, 6, CombatPosition.of(10, 10), "test hero");
		Combatant monster = new Combatant(2, "MONSTER", Side.MONSTER, 12, 10, 20, 1, 1, 4, CombatPosition.of(11, 10), "test monster");
		CombatState state = CombatState.fromRecoveredBattlefield(generated, List.of(hero), List.of(monster));

		if (state.current().side() != Side.PARTY) {
			state.endTurn();
		}
		state.attack(state.livingMonsters().get(0), 20);

		assertEquals(CombatState.Phase.VICTORY, state.phase());
		assertEquals(0, state.combatResult());
		assertTrue(state.livingMonsters().isEmpty());
	}

	@Test
	public void dyingPartyMemberBleedsOutAcrossRoundsAndLogsWarning() {
		GeneratedBattlefield generated = new RecoveredBattlefieldGenerator().generate(new Options());
		Combatant heroA = new Combatant(1, "HERO-A", Side.PARTY, 10, 4, 5, 1, 2, 6, CombatPosition.of(10, 10), "test");
		Combatant heroB = new Combatant(2, "HERO-B", Side.PARTY, 10, 4, 5, 1, 2, 6, CombatPosition.of(12, 10), "test");
		Combatant monster = new Combatant(3, "MONSTER", Side.MONSTER, 30, 10, 20, 1, 1, 4, CombatPosition.of(11, 10), "test");
		CombatState state = CombatState.fromRecoveredBattlefield(generated, List.of(heroA, heroB), List.of(monster));
		Combatant dying = state.livingParty().get(0);
		dying.applyDamage(17); // overkill 7 -> DYING with bleeding 7

		int guard = 0;
		while (dying.healthStatus() == Combatant.HealthStatus.DYING && guard++ < 40) {
			state.endTurn();
		}

		assertEquals(Combatant.HealthStatus.DEAD, dying.healthStatus());
		assertTrue(state.log().stream().anyMatch(s -> s.contains("Your Teammate is Dying")));
		assertTrue(state.log().stream().anyMatch(s -> s.contains("BLEED OUT: " + dying.name())));
	}

	@Test
	public void combatExpiresAfterFifteenRoundsWithoutAnAttack() {
		GeneratedBattlefield generated = new RecoveredBattlefieldGenerator().generate(new Options());
		Combatant hero = new Combatant(1, "HERO", Side.PARTY, 30, 4, 5, 1, 2, 6, CombatPosition.of(10, 10), "test");
		Combatant monster = new Combatant(2, "MONSTER", Side.MONSTER, 30, 10, 20, 1, 1, 4, CombatPosition.of(11, 10), "test");
		CombatState state = CombatState.fromRecoveredBattlefield(generated, List.of(hero), List.of(monster));

		int guard = 0;
		while (state.phase() != CombatState.Phase.EXPIRED && guard++ < 100) {
			state.endTurn();
		}

		assertEquals(CombatState.Phase.EXPIRED, state.phase());
		assertEquals(1, state.combatResult());
		assertTrue(state.round() >= CombatState.NO_ACTION_ROUND_LIMIT);
	}

	@Test
	public void attackReArmsTheNoActionLimit() {
		CombatState state = CombatState.ratwurstVerticalSlice();
		int initialLimit = state.noActionLimitRound();
		state.endTurn();
		state.endTurn();
		state.endTurn();

		Combatant enemy = state.livingCombatants().stream()
			.filter(c -> c.side() != state.current().side())
			.findFirst().orElseThrow();
		state.attack(enemy, 20);

		assertEquals(state.round() + CombatState.NO_ACTION_ROUND_LIMIT, state.noActionLimitRound());
		assertTrue(state.noActionLimitRound() >= initialLimit);
	}

	@Test
	public void roundEndHookFiresOncePerCompletedRound() {
		GeneratedBattlefield generated = new RecoveredBattlefieldGenerator().generate(new Options());
		Combatant hero = new Combatant(1, "HERO", Side.PARTY, 30, 4, 5, 1, 2, 6, CombatPosition.of(10, 10), "test");
		Combatant monster = new Combatant(2, "MONSTER", Side.MONSTER, 30, 10, 20, 1, 1, 4, CombatPosition.of(11, 10), "test");
		CombatState state = CombatState.fromRecoveredBattlefield(generated, List.of(hero), List.of(monster));
		List<Integer> endedRounds = new java.util.ArrayList<>();
		state.addRoundEndHook((s, endedRound) -> endedRounds.add(endedRound));

		int guard = 0;
		while (state.round() < 4 && guard++ < 20) {
			state.endTurn();
		}

		assertEquals(List.of(1, 2, 3), endedRounds);
	}

	@Test
	public void ratwurstVerticalSlicePreservesBattlefieldOptions() {
		Options options = new Options();
		options.terrain = Terrain.VENUS;

		CombatState state = CombatState.ratwurstVerticalSlice(options);

		assertEquals(Terrain.VENUS, state.battlefieldOptions().terrain);
		assertTrue(state.renderSummary().contains("Ratwurst vertical slice"));
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
