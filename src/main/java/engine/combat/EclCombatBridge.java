package engine.combat;

import java.util.ArrayList;
import java.util.List;

/**
 * Executes an ECL-triggered combat through a pluggable combat handoff path.
 *
 * <p>The VM/ECL layer builds a real {@link CombatState}, wraps it in a
 * {@link CombatSession}, and resolves it through a {@link CombatUiBridge}.
 * The default bridge is headless/deterministic for tests and CI.  OpenClaw can
 * inject a Swing or SSI Engine UI bridge so the player resolves the exact same
 * state interactively.</p>
 */
public final class EclCombatBridge {
	public static final class EclCombatResult {
		private final int combatResult;
		private final CombatState state;
		private final String transcript;
		private final boolean victory;
		private final boolean defeat;
		private final int actions;
		private final boolean interactive;
		private final String resolverName;

		private EclCombatResult(CombatSessionResult result) {
			this.combatResult = result.combatResult();
			this.state = result.state();
			this.transcript = result.transcript();
			this.victory = result.victory();
			this.defeat = result.defeat();
			this.actions = result.actions();
			this.interactive = result.interactive();
			this.resolverName = result.resolverName();
		}

		public int combatResult() { return combatResult; }
		public CombatState state() { return state; }
		public String transcript() { return transcript; }
		public boolean victory() { return victory; }
		public boolean defeat() { return defeat; }
		public int actions() { return actions; }
		public boolean interactive() { return interactive; }
		public String resolverName() { return resolverName; }
	}

	private final CombatEncounterFactory encounterFactory;
	private final CombatUiBridge uiBridge;
	private CombatState lastCombatState;
	private CombatSession lastSession;
	private CombatSessionResult lastSessionResult;

	public EclCombatBridge() {
		this(new CombatEncounterFactory(), new HeadlessCombatUiBridge());
	}

	public EclCombatBridge(CombatEncounterFactory encounterFactory, long seed) {
		this(encounterFactory, new HeadlessCombatUiBridge(seed, 500));
	}

	public EclCombatBridge(CombatEncounterFactory encounterFactory, CombatUiBridge uiBridge) {
		if (encounterFactory == null) {
			throw new IllegalArgumentException("encounterFactory must not be null");
		}
		if (uiBridge == null) {
			throw new IllegalArgumentException("uiBridge must not be null");
		}
		this.encounterFactory = encounterFactory;
		this.uiBridge = uiBridge;
	}

	public CombatState lastCombatState() {
		return lastCombatState;
	}

	public CombatSession lastSession() {
		return lastSession;
	}

	public CombatSessionResult lastSessionResult() {
		return lastSessionResult;
	}

	public EclCombatResult resolve(List<CombatEncounterFactory.MonsterSeed> monsters) {
		return resolve(monsters, List.of());
	}

	public EclCombatResult resolve(List<CombatEncounterFactory.MonsterSeed> monsters,
		List<CombatEncounterFactory.PartySeed> party) {
		List<CombatEncounterFactory.MonsterSeed> seeds = monsters == null || monsters.isEmpty()
			? List.of(CombatEncounterFactory.MonsterSeed.ratwurst())
			: List.copyOf(monsters);
		List<CombatEncounterFactory.PartySeed> partySeeds = party == null ? List.of() : List.copyOf(party);
		CombatState state = encounterFactory.create(seeds, partySeeds);
		CombatSession session = CombatSession.eclCombat(state, seeds);
		lastCombatState = state;
		lastSession = session;

		CombatSessionResult result = uiBridge.resolve(session);
		lastSessionResult = result;
		return new EclCombatResult(result);
	}

	public EclCombatResult resolveSingle(CombatEncounterFactory.MonsterSeed monster) {
		List<CombatEncounterFactory.MonsterSeed> monsters = new ArrayList<>();
		monsters.add(monster);
		return resolve(monsters);
	}
}
