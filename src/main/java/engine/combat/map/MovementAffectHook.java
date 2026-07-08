package engine.combat.map;

/**
 * Extension point for status-effect adjustments to a computed movement
 * budget (haste, slow, webbed/held, and similar).
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit
 * 9dc46f1), engine/ovr014.cs {@code CalcMoves} (sub_3E124), which calls
 * {@code ovr024.CheckAffectsEffect(player, CheckType.Movement)} after setting
 * {@code gbl.halfActionsLeft = moves * 2}, bracketed by {@code
 * gbl.resetMovesLeft = true; ...; gbl.resetMovesLeft = false;}. That affect
 * dispatch is AD&D-specific and belongs with the rest of this engine's
 * affects system, not this package, so it is exposed as a hook. The default
 * implementation is the identity function (no affects applied).</p>
 */
public interface MovementAffectHook {
	MovementAffectHook IDENTITY = (combatantId, halfActionsLeft, resetMode) -> halfActionsLeft;

	/**
	 * @param combatantId opaque integrator key, as passed to {@link
	 *        CombatMovementBudget#calcMovementBudget(int)}.
	 * @param halfActionsLeft the freshly computed movement budget, in COAB's
	 *        half-tile units (COAB {@code gbl.halfActionsLeft}).
	 * @param resetMode mirrors COAB's {@code gbl.resetMovesLeft} being true
	 *        for the duration of this call: the budget was just (re)rolled
	 *        for a new round rather than decremented mid-round.
	 * @return the adjusted budget.
	 */
	int adjustHalfActionsLeft(int combatantId, int halfActionsLeft, boolean resetMode);
}
