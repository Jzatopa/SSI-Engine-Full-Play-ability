package engine.combat;

import java.util.List;

/**
 * A single VM/ECL combat handoff.
 *
 * <p>The VM builds a CombatState, wraps it in a session, then hands it to a
 * CombatUiBridge.  The bridge may resolve headlessly for tests/CI or present
 * an interactive UI and block until victory/defeat.</p>
 */
public final class CombatSession {
	private final String source;
	private final CombatState state;
	private final List<CombatEncounterFactory.MonsterSeed> monsterSeeds;

	private CombatSession(String source, CombatState state, List<CombatEncounterFactory.MonsterSeed> monsterSeeds) {
		this.source = source == null ? "unknown" : source;
		this.state = state;
		this.monsterSeeds = List.copyOf(monsterSeeds);
	}

	public static CombatSession eclCombat(CombatState state, List<CombatEncounterFactory.MonsterSeed> monsterSeeds) {
		return new CombatSession("ECL COMBAT", state, monsterSeeds);
	}

	public String source() {
		return source;
	}

	public CombatState state() {
		return state;
	}

	public List<CombatEncounterFactory.MonsterSeed> monsterSeeds() {
		return monsterSeeds;
	}
}
