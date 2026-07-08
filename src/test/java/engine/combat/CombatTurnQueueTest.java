package engine.combat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.PrimitiveIterator;
import java.util.Set;
import java.util.stream.IntStream;

import org.junit.Test;

import engine.combat.Combatant.Side;

/**
 * Conformance tests for the COAB-ported initiative/turn-order semantics
 * (ovr014.CalculateInitiative + ovr009.FindNextCombatant, coab commit 9dc46f1).
 */
public class CombatTurnQueueTest {

	private static Combatant fighter(int id, String name, Side side, int x) {
		return new Combatant(id, name, side, 10, 5, 10, 1, 2, 3, CombatPosition.of(x, 1), "test");
	}

	private static IntSupplierFromSequence rolls(int... values) {
		return new IntSupplierFromSequence(values);
	}

	private static final class IntSupplierFromSequence implements java.util.function.IntSupplier {
		private final PrimitiveIterator.OfInt iterator;

		private IntSupplierFromSequence(int... values) {
			this.iterator = IntStream.of(values).iterator();
		}

		@Override
		public int getAsInt() {
			return iterator.nextInt();
		}
	}

	@Test
	public void firstRoundDelaysFollowInitiativeBoundsAndCurrentHasMaxDelay() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.PARTY, 2);
		Combatant c = fighter(3, "C", Side.MONSTER, 3);
		CombatTurnQueue queue = new CombatTurnQueue(List.of(a, b, c), 42L);

		int max = 0;
		for (Combatant combatant : queue.order()) {
			int delay = queue.delay(combatant);
			assertTrue("1d6 with adjustment 0 must land in 1..6, got " + delay, delay >= 1 && delay <= 6);
			max = Math.max(max, delay);
		}
		assertNotNull(queue.current());
		assertEquals(max, queue.delay(queue.current()));
		assertEquals(1, queue.round());
	}

	@Test
	public void strictlyHigherDelayWinsRegardlessOfTiebreakRoll() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.PARTY, 2);
		Map<Combatant, Integer> delays = new IdentityHashMap<>();
		delays.put(a, 3);
		delays.put(b, 5);

		// A rolls the maximum d100, B rolls the minimum; B's higher delay must still win.
		assertEquals(b, CombatTurnQueue.scanNext(List.of(a, b), delays, rolls(100, 1)));
	}

	@Test
	public void equalDelaysAreContestedByD100WithLaterRollTiesWinning() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.PARTY, 2);
		Map<Combatant, Integer> delays = new IdentityHashMap<>();
		delays.put(a, 4);
		delays.put(b, 4);

		// COAB's scan keeps roll >= max_roll, so an equal later roll takes the turn.
		assertEquals(b, CombatTurnQueue.scanNext(List.of(a, b), delays, rolls(50, 50)));
		assertEquals(a, CombatTurnQueue.scanNext(List.of(a, b), delays, rolls(50, 49)));
	}

	@Test
	public void scanYieldsNoCombatantWhenEveryDelayIsSpent() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.MONSTER, 2);
		Map<Combatant, Integer> delays = new IdentityHashMap<>();
		delays.put(a, 0);
		delays.put(b, 0);

		assertNull(CombatTurnQueue.scanNext(List.of(a, b), delays, rolls(10, 90)));
	}

	@Test
	public void deadCombatantsAreSkippedByTheScan() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.MONSTER, 2);
		a.applyDamage(100);
		Map<Combatant, Integer> delays = new IdentityHashMap<>();
		delays.put(a, 6);
		delays.put(b, 2);

		assertEquals(b, CombatTurnQueue.scanNext(List.of(a, b), delays, rolls(75)));
	}

	@Test
	public void actingConsumesDelayAndRoundAdvancesWhenAllDelaysAreSpent() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.MONSTER, 2);
		CombatTurnQueue queue = new CombatTurnQueue(List.of(a, b), 7L);

		Combatant first = queue.current();
		Combatant second = queue.advance();
		assertEquals(0, queue.delay(first));
		assertNotEquals(first, second);
		assertEquals(1, queue.round());

		queue.advance();
		assertEquals(2, queue.round());
		assertNotNull(queue.current());
		assertTrue(queue.delay(queue.current()) >= 1);
	}

	@Test
	public void delayedCombatantActsLastButStillActsThisRound() {
		// Reaction adjustment +10 for B forces B's delay (11..16) above A's (1..6),
		// making selection deterministic without depending on the seed.
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.MONSTER, 2);
		CombatTurnQueue queue = new CombatTurnQueue(List.of(a, b), 5L, c -> c.id() == 2 ? 10 : 0, Set.of());

		assertEquals(b, queue.current());
		assertEquals(a, queue.advance());

		// A delays: keeps delay 1 and, with nobody else pending, acts again this round.
		assertEquals(a, queue.delayCurrent());
		assertEquals(1, queue.delay(a));
		assertEquals(1, queue.round());

		assertEquals(b, queue.advance());
		assertEquals(2, queue.round());
	}

	@Test
	public void surprisedSideNeverActsInTheFirstRound() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.PARTY, 2);
		Combatant m1 = fighter(3, "M1", Side.MONSTER, 3);
		Combatant m2 = fighter(4, "M2", Side.MONSTER, 4);
		CombatTurnQueue queue = new CombatTurnQueue(List.of(a, b, m1, m2), 11L, c -> 0, Set.of(Side.MONSTER));

		// 1d6 - 6 is never positive, so surprised monsters roll delay 0 in round 1.
		assertEquals(0, queue.delay(m1));
		assertEquals(0, queue.delay(m2));
		int guard = 0;
		while (queue.round() == 1 && guard++ < 10) {
			assertEquals(Side.PARTY, queue.current().side());
			queue.advance();
		}
		assertEquals(2, queue.round());
		assertTrue(queue.delay(m1) >= 1);
		assertTrue(queue.delay(m2) >= 1);
	}

	@Test
	public void singleSurvivorKeepsTakingTurnsAcrossRounds() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		Combatant b = fighter(2, "B", Side.MONSTER, 2);
		b.applyDamage(100);
		CombatTurnQueue queue = new CombatTurnQueue(List.of(a, b), 3L);

		assertEquals(a, queue.current());
		assertEquals(a, queue.advance());
		assertEquals(a, queue.advance());
		assertEquals(3, queue.round());
	}

	@Test
	public void queueWithNoLivingCombatantsYieldsNoCurrent() {
		Combatant a = fighter(1, "A", Side.PARTY, 1);
		a.applyDamage(100);
		CombatTurnQueue queue = new CombatTurnQueue(List.of(a), 3L);

		assertNull(queue.current());
		assertNull(queue.advance());
	}
}
