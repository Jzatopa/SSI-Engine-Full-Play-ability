package engine.combat.map;

import java.util.Objects;

/**
 * Per-round movement budget derivation.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit
 * 9dc46f1):</p>
 * <ul>
 * <li>{@link #deriveEncumbranceAdjustedMovementRate(int)} — engine/ovr025.cs
 * {@code calc_movement} (sub_663C4): caps the combatant's movement rate based
 * on how far carried weight exceeds the encumbrance-free capacity.</li>
 * <li>{@link #calcMovementBudget(int)} — engine/ovr014.cs {@code CalcMoves}
 * (sub_3E124): turns a movement rate into this round's half-tile action
 * budget, applying an out-of-combat bonus, clamping to COAB's [1, 96] range,
 * and running the movement-affects hook.</li>
 * </ul>
 *
 * <p>In COAB these are two separate engine passes over the same {@code
 * player.movement} field — {@code calc_movement} runs during stat
 * recalculation ({@code ovr025.reclac_player_values}) and persists its result
 * into {@code player.movement}; {@code CalcMoves} runs later, during
 * initiative, and reads whatever {@code player.movement} was left holding.
 * This port preserves that separation: {@link
 * #deriveEncumbranceAdjustedMovementRate(int)} does not mutate anything (it
 * is read-only over game state, per this package's contract) and returns the
 * value the integrator should persist; {@link #calcMovementBudget(int)} reads
 * {@link MovementTraits#movementRate(int)} expecting that persisted value to
 * already be in place, exactly as COAB's {@code CalcMoves} expects {@code
 * player.movement} to already reflect the last {@code calc_movement} call.</p>
 *
 * <p>Where COAB's {@code calc_movement} would additionally have been fed by
 * {@code ovr025.CalcArmorWeightEffect} (an AD&D armor-slot movement penalty
 * applied to {@code player.movement} before {@code calc_movement} runs) and
 * COAB's {@code CalcMoves} triggers AD&D haste/slow affects via {@code
 * CheckAffectsEffect}, both are ruleset-specific and are not ported here:
 * armor weight effects are the integrator's responsibility to fold into
 * {@link MovementTraits#movementRate(int)} before calling in, and affects are
 * the {@link MovementAffectHook} extension point.</p>
 */
public final class CombatMovementBudget {
	private final MovementTraits traits;
	private final MovementAffectHook affectHook;

	public CombatMovementBudget(MovementTraits traits) {
		this(traits, MovementAffectHook.IDENTITY);
	}

	public CombatMovementBudget(MovementTraits traits, MovementAffectHook affectHook) {
		this.traits = Objects.requireNonNull(traits, "traits");
		this.affectHook = Objects.requireNonNull(affectHook, "affectHook");
	}

	/**
	 * Ported from COAB engine/ovr025.cs {@code calc_movement} (sub_663C4).
	 * Read-only: returns the effective rate rather than writing back to a
	 * {@code player.movement} field, since this package never mutates
	 * combatant state — the integrator is responsible for persisting the
	 * result if it should carry forward to later rounds.
	 */
	public int deriveEncumbranceAdjustedMovementRate(int combatantId) {
		int baseMovementRate = traits.movementRate(combatantId);
		int carriedWeight = traits.carriedWeight(combatantId);
		int maxEncumbrance = traits.maxEncumbrance(combatantId);

		int overload = carriedWeight - maxEncumbrance;
		if (overload < 0) {
			overload = 0;
		}

		int moves;
		if (overload >= 0 && overload <= 0x200) {
			moves = baseMovementRate;
		} else if (overload >= 0x201 && overload <= 0x300) {
			moves = 9;
		} else if (overload >= 0x301 && overload <= 0x400) {
			moves = 6;
		} else {
			moves = 3;
		}

		int effectiveMovement = baseMovementRate;
		if (moves < baseMovementRate) {
			effectiveMovement = moves;
		}
		return effectiveMovement;
	}

	/**
	 * Ported from COAB engine/ovr014.cs {@code CalcMoves} (sub_3E124).
	 *
	 * @return this round's movement budget, in COAB's half-tile units (COAB
	 *         {@code gbl.halfActionsLeft}).
	 */
	public int calcMovementBudget(int combatantId) {
		int moves = traits.movementRate(combatantId);

		if (!traits.isInCombat(combatantId)) {
			moves += traits.outOfCombatMovementBonus(combatantId);
		}

		if (moves < 1 || moves > 96) {
			moves = 1;
		}

		int halfActionsLeft = moves * 2;

		// COAB brackets the affects dispatch with gbl.resetMovesLeft = true / false;
		// resetMode = true mirrors that bracket (see MovementAffectHook).
		halfActionsLeft = affectHook.adjustHalfActionsLeft(combatantId, halfActionsLeft, true);

		return halfActionsLeft;
	}
}
