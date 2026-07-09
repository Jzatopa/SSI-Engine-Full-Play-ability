package engine.combat;

import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

/**
 * Evidence-bounded target memory and candidate selection for automated combatants.
 *
 * <p>Recovered GAME.OVR routines at file offsets 52000 and 55309 prove that an
 * automated actor retains a target pointer, validates it, and bounds candidate
 * search at {@code 0x14} (20) attempts. The exact original candidate score is
 * still unresolved, so ordering here is an explicit distance/HP/id fallback.</p>
 */
public final class RecoveredEnemyTactics {
	public static final int ORIGINAL_CANDIDATE_ATTEMPT_LIMIT = 0x14;

	private final Map<Integer, Integer> rememberedTargetIds = new HashMap<>();

	public Optional<Combatant> selectTarget(CombatState state, Combatant actor) {
		if (state == null || actor == null || !actor.isAlive()) {
			return Optional.empty();
		}
		Integer rememberedId = rememberedTargetIds.get(actor.id());
		if (rememberedId != null) {
			Optional<Combatant> remembered = validEnemies(state, actor).stream()
				.filter(candidate -> candidate.id() == rememberedId)
				.findFirst();
			if (remembered.isPresent()) {
				return remembered;
			}
			rememberedTargetIds.remove(actor.id());
		}

		Optional<Combatant> selected = validEnemies(state, actor).stream()
			.limit(ORIGINAL_CANDIDATE_ATTEMPT_LIMIT)
			.min(Comparator
				.comparingInt((Combatant candidate) -> actor.position().manhattanDistance(candidate.position()))
				.thenComparingInt(Combatant::hitPoints)
				.thenComparingInt(Combatant::id));
		selected.ifPresent(target -> rememberedTargetIds.put(actor.id(), target.id()));
		return selected;
	}

	public Optional<Integer> rememberedTargetId(int actorId) {
		return Optional.ofNullable(rememberedTargetIds.get(actorId));
	}

	private List<Combatant> validEnemies(CombatState state, Combatant actor) {
		return state.livingCombatants().stream()
			.filter(candidate -> candidate.side() != actor.side())
			.toList();
	}
}
