package engine.combat;

import java.util.ArrayList;
import java.util.Collections;
import java.util.EnumSet;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.function.IntSupplier;
import java.util.function.ToIntFunction;

/**
 * Delay-based initiative turn order for one combat.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * which translates the original Gold Box engine per overlay:</p>
 * <ul>
 * <li>{@code ovr014.CalculateInitiative} (sub_3E000): each round every
 * combatant rolls {@code delay = 1d6 + reaction adjustment}, minimum 1; a
 * surprised side takes -6; a result below 0 or above 20 becomes 0, meaning no
 * turn this round.</li>
 * <li>{@code ovr009.FindNextCombatant} (sub_331BC): the combatant with the
 * highest remaining delay acts next; equal delays are contested by a fresh
 * 1d100 per scan. Acting clears the delay to 0 ({@code Action.Clear}); the
 * round ends when every delay is 0.</li>
 * <li>{@code ovr009.delay_menu} case 'D': delaying sets the delay to 1, so the
 * combatant re-enters the pool at lowest priority and may act again last.</li>
 * </ul>
 *
 * <p>Adaptations, labeled per the reuse policy: dead combatants are skipped in
 * the scan and roll 0 (COAB removes them from its combatant list instead); the
 * reaction adjustment is a universal hook defaulting to 0 — COAB's AD&D
 * {@code ovr025.DexReactionAdj} table belongs to a ruleset flavor and the Buck
 * Rogers table is not yet recovered; surprise applies to the first round only,
 * mirroring {@code MainCombatLoop} zeroing {@code area2_ptr.field_596} after
 * the first initiative pass; the RNG is a seeded {@link Random} (deterministic
 * given the seed, but not the original RNG stream). Casting-delay values
 * ({@code delay = 20} paths) arrive with the spell/skill pass.</p>
 */
public final class CombatTurnQueue {
	private static final long DEFAULT_SEED = 0;

	private final List<Combatant> order;
	private final Map<Combatant, Integer> delays = new IdentityHashMap<>();
	private final Random random;
	private final ToIntFunction<Combatant> reactionAdjustment;
	private final Set<Combatant.Side> surprisedFirstRound;
	private int round = 1;
	private Combatant current;

	public CombatTurnQueue(List<Combatant> combatants) {
		this(combatants, DEFAULT_SEED);
	}

	public CombatTurnQueue(List<Combatant> combatants, long seed) {
		this(combatants, seed, c -> 0, Set.of());
	}

	public CombatTurnQueue(List<Combatant> combatants, long seed, ToIntFunction<Combatant> reactionAdjustment,
		Set<Combatant.Side> surprisedFirstRound) {

		this.order = new ArrayList<>(combatants);
		this.random = new Random(seed);
		this.reactionAdjustment = reactionAdjustment;
		this.surprisedFirstRound = surprisedFirstRound.isEmpty() ? EnumSet.noneOf(Combatant.Side.class)
			: EnumSet.copyOf(surprisedFirstRound);
		rollInitiative(true);
		this.current = selectNext();
		advanceRoundUntilSelectable();
	}

	public List<Combatant> order() {
		return Collections.unmodifiableList(order);
	}

	public int round() {
		return round;
	}

	/** Remaining initiative delay for this round; 0 means the combatant's turn is spent. */
	public int delay(Combatant combatant) {
		return delays.getOrDefault(combatant, 0);
	}

	public Combatant current() {
		if (current != null && !current.isAlive()) {
			delays.put(current, 0);
			current = selectNext();
			advanceRoundUntilSelectable();
		}
		return current;
	}

	/**
	 * Ends the current combatant's turn (delay cleared to 0, as COAB's
	 * {@code Action.Clear} does after acting) and selects the next combatant,
	 * starting a new round with fresh initiative when every delay is spent.
	 */
	public Combatant advance() {
		if (current != null) {
			delays.put(current, 0);
		}
		current = selectNext();
		advanceRoundUntilSelectable();
		return current();
	}

	/**
	 * COAB's Delay action: the current combatant keeps a delay of 1 and may be
	 * selected again this round after everyone with a higher delay has acted.
	 */
	public Combatant delayCurrent() {
		if (current != null) {
			delays.put(current, 1);
		}
		current = selectNext();
		advanceRoundUntilSelectable();
		return current();
	}

	public boolean hasLivingCombatant() {
		for (Combatant combatant : order) {
			if (combatant.isAlive()) {
				return true;
			}
		}
		return false;
	}

	private void advanceRoundUntilSelectable() {
		while (current == null && hasLivingCombatant()) {
			round++;
			for (Combatant combatant : order) {
				combatant.clearActed();
			}
			rollInitiative(false);
			current = selectNext();
		}
	}

	private void rollInitiative(boolean firstRound) {
		for (Combatant combatant : order) {
			delays.put(combatant, combatant.isAlive() ? rollDelay(combatant, firstRound) : 0);
		}
	}

	// COAB ovr014.CalculateInitiative (sub_3E000) delay math.
	private int rollDelay(Combatant combatant, boolean firstRound) {
		int delay = rollDice(6) + reactionAdjustment.applyAsInt(combatant);
		if (delay < 1) {
			delay = 1;
		}
		if (firstRound && surprisedFirstRound.contains(combatant.side())) {
			delay -= 6;
		}
		if (delay < 0 || delay > 20) {
			delay = 0;
		}
		return delay;
	}

	private int rollDice(int sides) {
		return random.nextInt(sides) + 1;
	}

	private Combatant selectNext() {
		return scanNext(order, delays, () -> rollDice(100));
	}

	/**
	 * COAB ovr009.FindNextCombatant (sub_331BC) selection scan, quirk included:
	 * a strictly higher delay always wins because the scan resets the roll
	 * threshold before comparing; equal delays are contested by d100 with later
	 * combatants winning roll ties.
	 */
	static Combatant scanNext(List<Combatant> order, Map<Combatant, Integer> delays, IntSupplier d100) {
		Combatant selected = null;
		int maxDelay = 0;
		int maxRoll = 0;
		for (Combatant combatant : order) {
			if (!combatant.isAlive()) {
				continue;
			}
			int roll = d100.getAsInt();
			int delay = delays.getOrDefault(combatant, 0);
			if (delay > maxDelay) {
				maxRoll = roll;
			}
			if (delay >= maxDelay && roll >= maxRoll) {
				maxRoll = roll;
				maxDelay = delay;
				selected = combatant;
			}
		}
		return maxDelay == 0 ? null : selected;
	}
}
