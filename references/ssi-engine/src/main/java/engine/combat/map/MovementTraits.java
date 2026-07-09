package engine.combat.map;

/**
 * Hook the integrator implements to supply the per-combatant inputs {@link
 * CombatMovementBudget} needs.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit
 * 9dc46f1), engine/ovr014.cs {@code CalcMoves} (sub_3E124) and
 * engine/ovr025.cs {@code calc_movement} (sub_663C4). COAB reads these values
 * directly off its {@code Player}/{@code gbl} globals; this engine has no
 * Matrix Cubed {@code Player} equivalent yet, so every value is a hook rather
 * than a hardcoded field lookup. {@code combatantId} is an opaque integrator
 * key (e.g. a roster index) — this package attaches no meaning to it beyond
 * routing it back through these calls.</p>
 */
public interface MovementTraits {
	/**
	 * The combatant's current movement rate, in whole tiles per round (COAB
	 * {@code player.movement}). For {@link
	 * CombatMovementBudget#deriveEncumbranceAdjustedMovementRate(int)} this is
	 * the un-encumbered base rate; for {@link
	 * CombatMovementBudget#calcMovementBudget(int)} it is expected to already
	 * be the encumbrance-adjusted rate the integrator persisted from a prior
	 * {@code deriveEncumbranceAdjustedMovementRate} call, mirroring COAB
	 * running {@code calc_movement} (during stat recalculation) before {@code
	 * CalcMoves} (during initiative) as two separate passes over the same
	 * {@code player.movement} field.
	 */
	int movementRate(int combatantId);

	/**
	 * Total carried weight, in COAB's encumbrance units (COAB {@code
	 * player.weight}: item weights plus coin weight). Used only by {@link
	 * CombatMovementBudget#deriveEncumbranceAdjustedMovementRate(int)}.
	 */
	int carriedWeight(int combatantId);

	/**
	 * Maximum unencumbered carry weight before movement is reduced (COAB
	 * {@code ovr025.max_encumberance}, an AD&D strength-score table). That
	 * table is ruleset-specific and not ported here — the integrator supplies
	 * whatever encumbrance-capacity rule Matrix Cubed uses. Used only by
	 * {@link CombatMovementBudget#deriveEncumbranceAdjustedMovementRate(int)}.
	 */
	int maxEncumbrance(int combatantId);

	/** COAB {@code player.in_combat}. Used only by {@link CombatMovementBudget#calcMovementBudget(int)}. */
	boolean isInCombat(int combatantId);

	/**
	 * Movement bonus applied only when the combatant is not in combat (COAB
	 * {@code gbl.area2_ptr.field_6E4}, an area/exploration-mode movement
	 * modifier). Used only by {@link CombatMovementBudget#calcMovementBudget(int)}.
	 */
	int outOfCombatMovementBonus(int combatantId);
}
