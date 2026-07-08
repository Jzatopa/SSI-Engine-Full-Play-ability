package engine.combat;

/**
 * Pluggable combat handoff target for the VM.
 *
 * <p>Implementations may auto-resolve, show Swing, show SSI Engine UI, or
 * delegate to a future network/tooling harness.  The VM only needs a
 * CombatSessionResult with COMBAT_RESULT semantics.</p>
 */
public interface CombatUiBridge {
	CombatSessionResult resolve(CombatSession session);
}
