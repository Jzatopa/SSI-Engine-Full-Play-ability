package engine.time;

/**
 * The Gold Box game-world clock: seven counter slots with mixed radices,
 * normalized by single ascending carry passes.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * {@code engine/ovr021.cs}:</p>
 * <ul>
 * <li>{@code NormalizeClock} (sub_58317): one ascending pass over slots 0..6
 * against the radix table {@code word_1A13C} = {10, 10, 6, 24, 30, 12, 0x100}.
 * A slot at or above its radix carries 1 into the next slot and subtracts the
 * radix <em>once</em>; slot 6 does not carry or subtract -- instead every
 * party member's age is incremented (see {@link PartyAgingHook}). Because the
 * pass ascends, a carry can cascade all the way up within a single call, but
 * a slot more than one radix over its limit needs multiple passes.</li>
 * <li>{@code step_game_time} (sub_583FA): reads the seven clock words, then
 * {@code amount} times increments the chosen slot by 1 and runs a full
 * {@code NormalizeClock} pass, then writes the words back and calls
 * {@code CheckAffectsTimingOut(time_slot, amount)}.</li>
 * </ul>
 *
 * <p>Slot layout, per COAB {@code Classes/Area1.cs} field names for the words
 * {@code step_game_time} reads at area offsets 0x18C..0x198 (index i maps to
 * offset {@code (0x6A00 + (0x4BC6 + i) * 2) & 0xFFFF}):</p>
 * <ul>
 * <li>slot 0 -- {@code field_18C}, unnamed in COAB, radix 10 (a sub-minute
 * tick counter; ten of these make one minute)</li>
 * <li>slot 1 -- {@code time_minutes_ones}, radix 10</li>
 * <li>slot 2 -- {@code time_minutes_tens}, radix 6 (so minutes run 00-59)</li>
 * <li>slot 3 -- {@code time_hour}, radix 24</li>
 * <li>slot 4 -- {@code time_day}, radix 30</li>
 * <li>slot 5 -- {@code time_year} (COAB's name; note its radix is 12, which
 * reads like a month counter -- kept as COAB names it, not re-interpreted)</li>
 * <li>slot 6 -- {@code field_198}, unnamed in COAB, radix 0x100; reaching the
 * radix triggers party aging and the value is deliberately <em>not</em>
 * reduced, exactly as the C# behaves</li>
 * </ul>
 *
 * <p>Adaptations, labeled per the reuse policy: the clock owns its seven
 * values directly instead of reading/writing them through the area's word
 * array each step -- an integrator syncing with {@code engine.VirtualMemory}
 * copies the slots in and out around {@link #stepGameTime(int, int)}.
 * {@code CheckAffectsTimingOut} (spell/affect duration expiry) walks player
 * affect lists and belongs to a later pass; only its pure slot-to-minutes
 * conversion is ported, as {@link #toMinutes(int, int)}, so an integrator can
 * wire expiry to the same quantity COAB computes.</p>
 */
public final class GameClock {

	/** COAB {@code field_18C}: sub-minute ticks, radix 10 (unnamed in the C#). */
	public static final int SLOT_TICKS = 0;
	/** COAB {@code time_minutes_ones}, radix 10. */
	public static final int SLOT_MINUTES_ONES = 1;
	/** COAB {@code time_minutes_tens}, radix 6. */
	public static final int SLOT_MINUTES_TENS = 2;
	/** COAB {@code time_hour}, radix 24. */
	public static final int SLOT_HOURS = 3;
	/** COAB {@code time_day}, radix 30. */
	public static final int SLOT_DAYS = 4;
	/** COAB {@code time_year}; radix 12 in the {@code word_1A13C} table (see class javadoc). */
	public static final int SLOT_YEARS = 5;
	/** COAB {@code field_198} (unnamed): radix 0x100, overflow ages the party without resetting. */
	public static final int SLOT_FIELD_198 = 6;

	public static final int SLOT_COUNT = 7;

	/** COAB {@code ovr021.timeScales} (word_1A13C). */
	private static final int[] TIME_SCALES = { 10, 10, 6, 24, 30, 12, 0x100 };

	/**
	 * Invoked when slot 6 reaches its radix during a normalize pass. COAB's
	 * {@code NormalizeClock} increments {@code player.age} for every member of
	 * {@code gbl.TeamList} at this point; the clock does not know the party,
	 * so the integrator wires this to its roster.
	 */
	public interface PartyAgingHook {
		void agePartyOneStep();
	}

	private static final PartyAgingHook NO_AGING = () -> {
	};

	private final int[] values = new int[SLOT_COUNT];
	private final PartyAgingHook agingHook;

	public GameClock() {
		this(NO_AGING);
	}

	public GameClock(PartyAgingHook agingHook) {
		this.agingHook = agingHook;
	}

	/** Radix of {@code slot} in COAB's {@code timeScales} table. */
	public static int radix(int slot) {
		return TIME_SCALES[slot];
	}

	/** Current value of {@code slot} (0..6). */
	public int get(int slot) {
		return values[slot];
	}

	/** Sets {@code slot} (0..6) to {@code value}; no normalization is applied. */
	public void set(int slot, int value) {
		values[slot] = value;
	}

	/** Convenience: {@code time_minutes_tens * 10 + time_minutes_ones}, as COAB's clock display computes minutes. */
	public int minutes() {
		return values[SLOT_MINUTES_TENS] * 10 + values[SLOT_MINUTES_ONES];
	}

	/** Convenience: {@code time_hour}. */
	public int hours() {
		return values[SLOT_HOURS];
	}

	/**
	 * One {@code NormalizeClock} (sub_58317) pass: ascending over slots 0..6,
	 * each slot at or above its radix carries 1 upward and subtracts its radix
	 * once. Slot 6 neither carries nor subtracts; it fires the
	 * {@link PartyAgingHook} instead (and will fire again on every subsequent
	 * pass while still at or above 0x100 -- faithful to the C#).
	 */
	public void normalize() {
		for (int i = 0; i < SLOT_COUNT; i++) {
			if (values[i] >= TIME_SCALES[i]) {
				if (i != SLOT_FIELD_198) {
					values[i + 1] += 1;
					values[i] -= TIME_SCALES[i];
				} else {
					agingHook.agePartyOneStep();
				}
			}
		}
	}

	/**
	 * {@code step_game_time} (sub_583FA): advances {@code slot} by
	 * {@code amount}, one unit at a time with a full {@link #normalize()} pass
	 * after each increment (so carries never accumulate more than one radix).
	 */
	public void stepGameTime(int slot, int amount) {
		for (int i = 1; i <= amount; i++) {
			values[slot] += 1;
			normalize();
		}
	}

	/**
	 * The slot-to-minutes conversion from COAB {@code CheckAffectsTimingOut}
	 * (sub_5801E): {@code steps} units of {@code slot}, multiplied down
	 * through the radix table to slot-1 (minutes-ones) units. E.g. 1 hour step
	 * = 60 minutes, 1 day step = 1440. For slots 0 and 1 the value is returned
	 * unchanged, exactly as the C# loop ({@code while (timeSlot > 1)}) does.
	 */
	public static int toMinutes(int slot, int steps) {
		int minutes = steps;
		int s = slot;
		while (s > 1) {
			minutes *= TIME_SCALES[s - 1];
			s -= 1;
		}
		return minutes;
	}
}
