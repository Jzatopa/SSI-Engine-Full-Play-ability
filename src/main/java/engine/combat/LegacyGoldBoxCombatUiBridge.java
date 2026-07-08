package engine.combat;

/**
 * Compatibility resolver for titles whose tactical combat has not yet been
 * reconstructed. It preserves SSI Engine's former COMBAT_RESULT=0 behavior
 * instead of applying Matrix-specific battlefield rules to another game.
 */
public final class LegacyGoldBoxCombatUiBridge implements CombatUiBridge {
	@Override
	public CombatSessionResult resolve(CombatSession session) {
		session.state().addEvidence(
			"LegacyGoldBoxCombatUiBridge: title-specific tactical combat is not implemented; preserved legacy success result.");
		return CombatSessionResult.of(
			0,
			session.state(),
			"Gold Box tactical combat is not implemented for this profile; legacy COMBAT_RESULT=0 preserved.",
			0,
			false,
			"LegacyGoldBoxCombatUiBridge"
		);
	}
}
