package engine.time;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

/**
 * Conformance tests for the COAB-ported game clock semantics
 * (ovr021.NormalizeClock + ovr021.step_game_time, coab commit 9dc46f1).
 */
public class GameClockTest {

	@Test
	public void minuteOnesCarryIntoMinuteTens() {
		GameClock clock = new GameClock();
		clock.set(GameClock.SLOT_MINUTES_ONES, 9);

		clock.stepGameTime(GameClock.SLOT_MINUTES_ONES, 1);

		assertEquals(0, clock.get(GameClock.SLOT_MINUTES_ONES));
		assertEquals(1, clock.get(GameClock.SLOT_MINUTES_TENS));
		assertEquals(10, clock.minutes());
	}

	@Test
	public void minuteCarryCascadesThroughHourIntoDayInOnePass() {
		// 23:59 + 1 minute = day+1, 00:00 -- the ascending pass carries all the way up.
		GameClock clock = new GameClock();
		clock.set(GameClock.SLOT_MINUTES_ONES, 9);
		clock.set(GameClock.SLOT_MINUTES_TENS, 5);
		clock.set(GameClock.SLOT_HOURS, 23);
		clock.set(GameClock.SLOT_DAYS, 4);

		clock.stepGameTime(GameClock.SLOT_MINUTES_ONES, 1);

		assertEquals(0, clock.minutes());
		assertEquals(0, clock.hours());
		assertEquals(5, clock.get(GameClock.SLOT_DAYS));
	}

	@Test
	public void dayCarriesIntoSlot5AtRadix30AndSlot5CarriesIntoSlot6AtRadix12() {
		GameClock clock = new GameClock();
		clock.set(GameClock.SLOT_DAYS, 29);
		clock.set(GameClock.SLOT_YEARS, 11);

		clock.stepGameTime(GameClock.SLOT_DAYS, 1);

		assertEquals(0, clock.get(GameClock.SLOT_DAYS));
		assertEquals(0, clock.get(GameClock.SLOT_YEARS));
		assertEquals(1, clock.get(GameClock.SLOT_FIELD_198));
	}

	@Test
	public void slot6ReachingItsRadixAgesThePartyWithoutResetting() {
		int[] aged = { 0 };
		GameClock clock = new GameClock(() -> aged[0]++);
		clock.set(GameClock.SLOT_FIELD_198, 0xFF);

		clock.stepGameTime(GameClock.SLOT_FIELD_198, 1);

		assertEquals(1, aged[0]);
		// Faithful to the C#: slot 6 is not reduced when it triggers aging...
		assertEquals(0x100, clock.get(GameClock.SLOT_FIELD_198));

		// ...so every further normalize pass ages the party again.
		clock.normalize();
		assertEquals(2, aged[0]);
		assertEquals(0x100, clock.get(GameClock.SLOT_FIELD_198));
	}

	@Test
	public void agingHookNotFiredBelowSlot6Radix() {
		int[] aged = { 0 };
		GameClock clock = new GameClock(() -> aged[0]++);
		clock.set(GameClock.SLOT_FIELD_198, 0xFE);

		clock.stepGameTime(GameClock.SLOT_FIELD_198, 1);

		assertEquals(0, aged[0]);
		assertEquals(0xFF, clock.get(GameClock.SLOT_FIELD_198));
	}

	@Test
	public void normalizeSubtractsOnlyOneRadixPerPass() {
		// A slot more than one radix over its limit needs multiple passes;
		// NormalizeClock's single ascending pass subtracts once per slot.
		GameClock clock = new GameClock();
		clock.set(GameClock.SLOT_TICKS, 25);

		clock.normalize();
		assertEquals(15, clock.get(GameClock.SLOT_TICKS));
		assertEquals(1, clock.get(GameClock.SLOT_MINUTES_ONES));

		clock.normalize();
		assertEquals(5, clock.get(GameClock.SLOT_TICKS));
		assertEquals(2, clock.get(GameClock.SLOT_MINUTES_ONES));
	}

	@Test
	public void stepGameTimeNormalizesAfterEveryIncrement() {
		// step_game_time(1, 5) from 00:08: per-increment normalization keeps
		// each slot within one radix at all times -- ends at 00:13.
		GameClock clock = new GameClock();
		clock.set(GameClock.SLOT_MINUTES_ONES, 8);

		clock.stepGameTime(GameClock.SLOT_MINUTES_ONES, 5);

		assertEquals(3, clock.get(GameClock.SLOT_MINUTES_ONES));
		assertEquals(1, clock.get(GameClock.SLOT_MINUTES_TENS));
		assertEquals(13, clock.minutes());
	}

	@Test
	public void stepGameTimeOnHoursRollsDays() {
		GameClock clock = new GameClock();
		clock.set(GameClock.SLOT_HOURS, 22);

		clock.stepGameTime(GameClock.SLOT_HOURS, 5);

		assertEquals(3, clock.hours());
		assertEquals(1, clock.get(GameClock.SLOT_DAYS));
	}

	@Test
	public void tickCarryProducesMinutes() {
		GameClock clock = new GameClock();

		clock.stepGameTime(GameClock.SLOT_TICKS, 10);

		assertEquals(0, clock.get(GameClock.SLOT_TICKS));
		assertEquals(1, clock.get(GameClock.SLOT_MINUTES_ONES));
	}

	@Test
	public void toMinutesMatchesCheckAffectsTimingOutConversion() {
		assertEquals(5, GameClock.toMinutes(GameClock.SLOT_MINUTES_ONES, 5));
		assertEquals(10, GameClock.toMinutes(GameClock.SLOT_MINUTES_TENS, 1));
		assertEquals(120, GameClock.toMinutes(GameClock.SLOT_HOURS, 2));
		assertEquals(1440, GameClock.toMinutes(GameClock.SLOT_DAYS, 1));
		// Slots 0 and 1 pass through unchanged, as the C# while-loop does.
		assertEquals(7, GameClock.toMinutes(GameClock.SLOT_TICKS, 7));
	}

	@Test
	public void radixTableMatchesCoabWord1A13C() {
		assertEquals(10, GameClock.radix(GameClock.SLOT_TICKS));
		assertEquals(10, GameClock.radix(GameClock.SLOT_MINUTES_ONES));
		assertEquals(6, GameClock.radix(GameClock.SLOT_MINUTES_TENS));
		assertEquals(24, GameClock.radix(GameClock.SLOT_HOURS));
		assertEquals(30, GameClock.radix(GameClock.SLOT_DAYS));
		assertEquals(12, GameClock.radix(GameClock.SLOT_YEARS));
		assertEquals(0x100, GameClock.radix(GameClock.SLOT_FIELD_198));
	}
}
