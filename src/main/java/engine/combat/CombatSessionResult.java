package engine.combat;

/**
 * Result returned by a combat UI/resolver back to the VM bridge.
 */
public final class CombatSessionResult {
	private final int combatResult;
	private final CombatState state;
	private final String transcript;
	private final boolean victory;
	private final boolean defeat;
	private final int actions;
	private final boolean interactive;
	private final String resolverName;

	private CombatSessionResult(
		int combatResult,
		CombatState state,
		String transcript,
		boolean victory,
		boolean defeat,
		int actions,
		boolean interactive,
		String resolverName
	) {
		this.combatResult = combatResult;
		this.state = state;
		this.transcript = transcript == null ? "" : transcript;
		this.victory = victory;
		this.defeat = defeat;
		this.actions = actions;
		this.interactive = interactive;
		this.resolverName = resolverName == null ? "unknown" : resolverName;
	}

	public static CombatSessionResult of(
		int combatResult,
		CombatState state,
		String transcript,
		int actions,
		boolean interactive,
		String resolverName
	) {
		return new CombatSessionResult(
			combatResult,
			state,
			transcript,
			state != null && state.phase() == CombatState.Phase.VICTORY,
			state != null && state.phase() == CombatState.Phase.DEFEAT,
			actions,
			interactive,
			resolverName
		);
	}

	public int combatResult() {
		return combatResult;
	}

	public CombatState state() {
		return state;
	}

	public String transcript() {
		return transcript;
	}

	public boolean victory() {
		return victory;
	}

	public boolean defeat() {
		return defeat;
	}

	public int actions() {
		return actions;
	}

	public boolean interactive() {
		return interactive;
	}

	public String resolverName() {
		return resolverName;
	}
}
