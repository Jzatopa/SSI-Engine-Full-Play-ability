package engine.combat;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Optional;

import engine.combat.Combatant.Side;
import engine.combat.RecoveredBattlefieldGenerator.GeneratedBattlefield;
import engine.combat.RecoveredBattlefieldGenerator.Options;
import engine.combat.attack.AttackOutcome;
import engine.combat.attack.AttackResolver;
import engine.combat.attack.CombatantAttackerView;
import engine.combat.attack.CombatantDefenderView;
import engine.combat.attack.NeutralAttackRuleset;

/**
 * First stateful Java combat runtime layer for Matrix Cubed.
 *
 * <p>This is intentionally a vertical-slice state object, not a claim of exact
 * original combat equivalence.  It wires together the recovered battlefield
 * buffer with stateful party/monster placement, turn order, movement,
 * targeting and combat-result semantics.  It is designed to replace the
 * earlier stateless combat demos and give the Java engine a concrete object
 * that UI, ECL callbacks and future recovered formulas can all share.</p>
 */
public final class CombatState {
	public enum Phase {
		PARTY_TURN, MONSTER_TURN, VICTORY, DEFEAT, UNRESOLVED,
		/** Combat timed out: no attack for {@link #NO_ACTION_ROUND_LIMIT} rounds (COAB battle01 check). */
		EXPIRED
	}

	public static final class AttackResult {
		private final Combatant attacker;
		private final Combatant defender;
		private final int roll;
		private final int needed;
		private final boolean hit;
		private final int damage;
		private final Phase phaseAfter;

		private AttackResult(Combatant attacker, Combatant defender, int roll, int needed, boolean hit, int damage, Phase phaseAfter) {
			this.attacker = attacker;
			this.defender = defender;
			this.roll = roll;
			this.needed = needed;
			this.hit = hit;
			this.damage = damage;
			this.phaseAfter = phaseAfter;
		}

		public Combatant attacker() {
			return attacker;
		}

		public Combatant defender() {
			return defender;
		}

		public int roll() {
			return roll;
		}

		public int needed() {
			return needed;
		}

		public boolean hit() {
			return hit;
		}

		public int damage() {
			return damage;
		}

		public Phase phaseAfter() {
			return phaseAfter;
		}

		@Override
		public String toString() {
			return attacker.name() + " rolls " + roll + " vs " + needed + (hit ? " hit " + defender.name() + " for " + damage : " miss");
		}
	}

	/**
	 * Rounds without any attack before combat expires, from COAB
	 * {@code Gbl.combat_round_no_action_value} (coab commit 9dc46f1);
	 * initialized at battle setup ({@code ovr011}) and re-armed by every
	 * attack ({@code ovr014.AttackTarget}).
	 */
	public static final int NO_ACTION_ROUND_LIMIT = 15;

	/** Extension point for per-round effect ticks (COAB ovr024.CheckAffectsEffect slot). */
	public interface RoundEndHook {
		void onRoundEnd(CombatState state, int endedRound);
	}

	private final BattlefieldBuffer battlefield;
	private final Options battlefieldOptions;
	private final List<Combatant> combatants;
	private final CombatTurnQueue turnQueue;
	private final List<String> evidence;
	private final List<String> log = new ArrayList<>();
	private final List<RoundEndHook> roundEndHooks = new ArrayList<>();
	private Phase phase;
	private int lastCheckedRound;
	private int noActionLimitRound;

	private CombatState(BattlefieldBuffer battlefield, Options battlefieldOptions, List<Combatant> combatants, List<String> evidence) {
		this.battlefield = battlefield;
		this.battlefieldOptions = battlefieldOptions;
		this.combatants = new ArrayList<>(combatants);
		this.turnQueue = new CombatTurnQueue(this.combatants);
		this.evidence = new ArrayList<>(evidence);
		this.phase = phaseFor(turnQueue.current());
		this.lastCheckedRound = turnQueue.round();
		this.noActionLimitRound = turnQueue.round() + NO_ACTION_ROUND_LIMIT;
		log.add("COMBAT STATE READY: " + this.combatants.size() + " combatants on recovered 50x25 battlefield.");
	}

	public static CombatState fromRecoveredBattlefield(GeneratedBattlefield generated, List<Combatant> party, List<Combatant> monsters) {
		List<Combatant> all = new ArrayList<>();
		for (Combatant combatant : party) {
			all.add(combatant.copy());
		}
		for (Combatant combatant : monsters) {
			all.add(combatant.copy());
		}
		List<String> evidence = new ArrayList<>(generated.evidence());
		evidence.add("CombatState Pass 1: stateful placement/turn/move/attack layer; formulas remain visible scaffolding.");
		evidence.add("Combat result mapping follows Gold Box convention observed in existing Java slice: 0=victory, 1=defeat/unresolved.");
		return new CombatState(generated.buffer(), generated.options(), all, evidence);
	}

	public static CombatState ratwurstVerticalSlice() {
		return ratwurstVerticalSlice(new RecoveredBattlefieldGenerator.Options());
	}

	public static CombatState ratwurstVerticalSlice(Options options) {
		RecoveredBattlefieldGenerator generator = new RecoveredBattlefieldGenerator();
		GeneratedBattlefield generated = generator.generate(options == null ? new RecoveredBattlefieldGenerator.Options() : options);
		List<Combatant> party = new CombatEncounterFactory().defaultParty();
		List<Combatant> monsters = List.of(
			Combatant.ratwurst(101, CombatPosition.of(11, 8)),
			Combatant.ratwurst(102, CombatPosition.of(11, 14)),
			Combatant.ratwurst(103, CombatPosition.of(20, 8)),
			Combatant.ratwurst(104, CombatPosition.of(20, 14))
		);
		CombatState state = fromRecoveredBattlefield(generated, party, monsters);
		state.evidence.add("Ratwurst vertical slice mirrors the supplied Matrix Cubed combat screenshot: RATWURST HP 52 AC 4.");
		return state;
	}

	public BattlefieldBuffer battlefield() {
		return battlefield;
	}

	public Options battlefieldOptions() {
		return battlefieldOptions;
	}

	public List<Combatant> combatants() {
		return Collections.unmodifiableList(combatants);
	}

	public List<Combatant> livingCombatants() {
		List<Combatant> result = new ArrayList<>();
		for (Combatant combatant : combatants) {
			if (combatant.isAlive()) {
				result.add(combatant);
			}
		}
		return result;
	}

	public List<Combatant> livingParty() {
		return livingBySide(Side.PARTY);
	}

	public List<Combatant> livingMonsters() {
		return livingBySide(Side.MONSTER);
	}

	public Combatant current() {
		return turnQueue.current();
	}

	public int round() {
		return turnQueue.round();
	}

	public Phase phase() {
		return phase;
	}

	public int combatResult() {
		if (phase == Phase.VICTORY) {
			return 0;
		}
		if (phase == Phase.DEFEAT || phase == Phase.EXPIRED) {
			return 1;
		}
		return -1;
	}

	/** Round at which combat expires unless an attack re-arms the limit. */
	public int noActionLimitRound() {
		return noActionLimitRound;
	}

	public void addRoundEndHook(RoundEndHook hook) {
		if (hook != null) {
			roundEndHooks.add(hook);
		}
	}

	public List<String> evidence() {
		return Collections.unmodifiableList(evidence);
	}

	public void addEvidence(String line) {
		if (line != null && !line.isBlank()) {
			evidence.add(line);
		}
	}

	public List<String> log() {
		return Collections.unmodifiableList(log);
	}

	public Optional<Combatant> occupantAt(CombatPosition position) {
		for (Combatant combatant : combatants) {
			if (combatant.isAlive() && combatant.position().equals(position)) {
				return Optional.of(combatant);
			}
		}
		return Optional.empty();
	}

	public boolean canMoveCurrentTo(CombatPosition target) {
		Combatant active = current();
		if (active == null || !active.isAlive() || active.hasActed()) {
			return false;
		}
		if (occupantAt(target).isPresent()) {
			return false;
		}
		return active.position().manhattanDistance(target) <= active.movement();
	}

	public boolean moveCurrentTo(CombatPosition target) {
		Combatant active = current();
		if (!canMoveCurrentTo(target)) {
			log.add("MOVE BLOCKED: " + (active == null ? "no active combatant" : active.name()) + " -> " + target);
			return false;
		}
		CombatPosition before = active.position();
		active.moveTo(target);
		log.add("MOVE: " + active.name() + " " + before + " -> " + target);
		return true;
	}

	public void forceVictory(String reason) {
		for (Combatant combatant : combatants) {
			if (combatant.side() == Side.MONSTER && combatant.isAlive()) {
				// Overkill past the dying window so debug kills are DEAD, not unconscious.
				combatant.applyDamage(combatant.hitPoints() + 10);
			}
		}
		String evidenceLine = reason == null || reason.isBlank() ? "CombatState forceVictory dev resolver used." : reason;
		evidence.add(evidenceLine);
		log.add("DEV VICTORY: " + evidenceLine);
		updatePhase();
	}

	/**
	 * Resolves one attack via the ported COAB {@code engine.combat.attack}
	 * package ({@link AttackResolver#resolveSwing}) instead of the earlier
	 * scaffold hit/damage formula. {@link CombatantAttackerView} /
	 * {@link CombatantDefenderView} bridge {@link Combatant}'s decoded
	 * fields (thac0, armorClass, damage range) onto the resolver's richer
	 * view interfaces, returning the documented neutral value for every
	 * field Combatant does not genuinely supply (ability scores, magic
	 * bonuses, ranged/backstab data, facing, ...). {@link
	 * NeutralAttackRuleset} is used deliberately -- Matrix Cubed's own
	 * ability-score-to-combat-bonus formulas are not evidence-backed, so no
	 * AD&D flavor is applied.
	 *
	 * <p>Both the to-hit roll and the single damage die are driven by the
	 * one {@code roll} parameter this API accepts (clamped to 1..20): the
	 * to-hit check feeds it to the resolver's injected d20 supplier as-is,
	 * and the damage die reuses the same value ({@code ((roll - 1) % dieSize) + 1})
	 * against the resolver's returned dice shape, since {@link
	 * CombatantAttackerView} always synthesizes a single die sized to the
	 * combatant's damage range. This keeps the existing single-roll,
	 * seed-deterministic test contract; a future multi-swing/ranged wire
	 * would need a separate damage-roll supplier.</p>
	 */
	public AttackResult attack(Combatant defender, int roll) {
		Combatant attacker = current();
		if (attacker == null || defender == null) {
			throw new IllegalStateException("No attacker or defender available.");
		}
		if (!attacker.isAlive()) {
			throw new IllegalStateException("Dead combatant cannot attack.");
		}
		if (!defender.isAlive()) {
			throw new IllegalStateException("Cannot attack dead defender.");
		}
		if (attacker.side() == defender.side()) {
			throw new IllegalArgumentException("Cannot attack friendly target.");
		}
		int boundedRoll = Math.max(1, Math.min(20, roll));

		CombatantAttackerView attackerView = new CombatantAttackerView(attacker);
		CombatantDefenderView defenderView = new CombatantDefenderView(defender);
		AttackOutcome outcome = AttackResolver.resolveSwing(
			attackerView, defenderView, NeutralAttackRuleset.INSTANCE, false, () -> boundedRoll);

		boolean hit = outcome.hit();
		int flatBonus = outcome.totalToHitValue() - outcome.correctedAttackRoll();
		int needed = Math.max(1, outcome.targetArmorClass() - flatBonus);

		int damage = 0;
		if (hit) {
			int dieSize = Math.max(1, outcome.damageDiceSize());
			int dieValue = ((boundedRoll - 1) % dieSize) + 1;
			int perDie = outcome.damageDiceCount() * dieValue;
			damage = Math.max(0, perDie + outcome.damageBonus()) * outcome.backstabDamageMultiplier();
			defender.applyDamage(damage);
		}
		attacker.markActed();
		// Every attack re-arms the no-action expiry (COAB ovr014.AttackTarget).
		noActionLimitRound = turnQueue.round() + NO_ACTION_ROUND_LIMIT;
		updatePhase();
		AttackResult result = new AttackResult(attacker, defender, boundedRoll, needed, hit, damage, phase);
		log.add("ATTACK: " + result);
		return result;
	}

	public Combatant endTurn() {
		Combatant before = current();
		if (before != null) {
			before.markActed();
		}
		Combatant next = turnQueue.advance();
		runPendingRoundChecks();
		updatePhase();
		log.add("TURN: " + (next == null ? "none" : next.name()) + " round " + turnQueue.round());
		return next;
	}

	public String renderSummary() {
		StringBuilder out = new StringBuilder();
		out.append("Matrix Cubed Java CombatState Pass 1\n");
		out.append("Phase: ").append(phase).append("  CombatResult: ").append(combatResult()).append("  Round: ").append(round()).append('\n');
		out.append("Battlefield: ").append(BattlefieldBuffer.WIDTH).append("x").append(BattlefieldBuffer.HEIGHT).append(" + ")
			.append(BattlefieldBuffer.HEADER_SIZE).append("-byte header\n");
		out.append("Current: ").append(current() == null ? "(none)" : current()).append('\n');
		out.append("Combatants:\n");
		for (Combatant combatant : combatants) {
			out.append("  - ").append(combatant).append('\n');
		}
		out.append("Evidence:\n");
		for (String line : evidence) {
			out.append("  - ").append(line).append('\n');
		}
		out.append("Boundary: stateful combat screen is now represented in Java; original initiative, movement-cost, hit/damage formulas still require DOS/GAME.OVR validation.\n");
		return out.toString();
	}

	private List<Combatant> livingBySide(Side side) {
		List<Combatant> result = new ArrayList<>();
		for (Combatant combatant : combatants) {
			if (combatant.side() == side && combatant.isAlive()) {
				result.add(combatant);
			}
		}
		return result;
	}

	private void runPendingRoundChecks() {
		while (lastCheckedRound < turnQueue.round()) {
			int endedRound = lastCheckedRound;
			lastCheckedRound++;
			endOfRound(endedRound);
		}
	}

	/**
	 * End-of-round bookkeeping ported from COAB {@code ovr009.BattleRoundChecks}
	 * (battle01): effect-tick hooks, bleeding progression for dying combatants
	 * (dead past 9), the teammate-dying warning that COAB raises through its
	 * bandage check, and the no-action expiry. Game-time stepping, poison
	 * clouds, the bandage action itself, and enemy-health morale recalculation
	 * arrive with the effect/AI passes.
	 */
	private void endOfRound(int endedRound) {
		for (RoundEndHook hook : roundEndHooks) {
			hook.onRoundEnd(this, endedRound);
		}
		boolean teammateDying = false;
		for (Combatant combatant : combatants) {
			if (combatant.healthStatus() == Combatant.HealthStatus.DYING) {
				if (combatant.bleedOneRound()) {
					log.add("BLEED OUT: " + combatant.name() + " has died (round " + endedRound + ").");
				} else if (combatant.side() == Side.PARTY) {
					teammateDying = true;
				}
			}
		}
		if (teammateDying) {
			log.add("ROUND " + endedRound + ": Your Teammate is Dying");
		}
		updatePhase();
		if (phase != Phase.VICTORY && phase != Phase.DEFEAT && turnQueue.round() >= noActionLimitRound) {
			phase = Phase.EXPIRED;
			log.add("COMBAT EXPIRED: no attack for " + NO_ACTION_ROUND_LIMIT + " rounds (round " + turnQueue.round() + ").");
		}
	}

	private void updatePhase() {
		if (phase == Phase.EXPIRED) {
			return;
		}
		if (livingParty().isEmpty()) {
			phase = Phase.DEFEAT;
			return;
		}
		if (livingMonsters().isEmpty()) {
			phase = Phase.VICTORY;
			return;
		}
		phase = phaseFor(turnQueue.current());
	}

	private Phase phaseFor(Combatant combatant) {
		if (combatant == null) {
			return Phase.UNRESOLVED;
		}
		return combatant.side() == Side.PARTY ? Phase.PARTY_TURN : Phase.MONSTER_TURN;
	}
}
