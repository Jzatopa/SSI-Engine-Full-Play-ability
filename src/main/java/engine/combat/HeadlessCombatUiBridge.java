package engine.combat;

import java.util.List;

/**
 * Deterministic fallback/CI combat resolver for VM handoff tests.
 *
 * <p>This is the old EclCombatBridge auto-resolver extracted behind the
 * CombatUiBridge interface.  Interactive builds can swap this for a Swing or
 * SSI Engine UI bridge without changing the VM COMBAT opcode path.</p>
 */
public final class HeadlessCombatUiBridge implements CombatUiBridge {
	private final long seed;
	private final int maxActions;

	public HeadlessCombatUiBridge() {
		this(52017L, 500);
	}

	public HeadlessCombatUiBridge(long seed, int maxActions) {
		this.seed = seed;
		this.maxActions = maxActions;
	}

	@Override
	public CombatSessionResult resolve(CombatSession session) {
		CombatState state = session.state();
		CombatController controller = new CombatController(state, seed);
		int actions = 0;

		while (!controller.isCombatOver() && actions < maxActions) {
			actions++;
			if (state.current() == null) {
				controller.endTurn();
			} else if (state.current().side() == Combatant.Side.MONSTER) {
				controller.resolveMonsterTurn();
			} else {
				List<Combatant> targets = state.livingMonsters();
				if (targets.isEmpty()) {
					break;
				}
				controller.setCursor(targets.get(0).position());
				controller.attackCursor();
			}
		}

		if (!controller.isCombatOver()) {
			state.addEvidence("HeadlessCombatUiBridge: max action limit reached; marking combat unresolved/defeat.");
		}

		int combatResult = state.combatResult();
		if (combatResult < 0) {
			combatResult = 1;
		}

		return CombatSessionResult.of(
			combatResult,
			state,
			renderTranscript(session, state, actions, combatResult),
			actions,
			false,
			"HeadlessCombatUiBridge"
		);
	}

	private String renderTranscript(CombatSession session, CombatState state, int actions, int combatResult) {
		StringBuilder out = new StringBuilder();
		out.append("GOLD BOX COMBAT SESSION\n");
		out.append("Resolver: HeadlessCombatUiBridge\n");
		out.append("Source: ").append(session.source()).append('\n');
		out.append("Phase: ").append(state.phase()).append("  COMBAT_RESULT=").append(combatResult).append("  Actions=")
			.append(actions).append('\n');
		out.append("Current: ").append(state.current() == null ? "(none)" : state.current()).append('\n');
		out.append("Combatants:\n");
		for (Combatant combatant : state.combatants()) {
			out.append("  - ").append(combatant).append('\n');
		}
		out.append("Log:\n");
		for (String line : state.log()) {
			out.append("  ").append(line).append('\n');
		}
		out.append("Evidence:\n");
		for (String line : state.evidence()) {
			out.append("  - ").append(line).append('\n');
		}
		out.append("Boundary: headless resolver is a deterministic VM fallback.  Interactive builds should inject a Swing/SSI bridge to let the player resolve this same CombatState.\n");
		return out.toString();
	}
}
