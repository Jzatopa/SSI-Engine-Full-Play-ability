package engine.combat.attack;

import java.util.ArrayList;
import java.util.List;

/**
 * Sweep-attack target selection, ported from COAB
 * (https://github.com/simeonpilgrim/coab, commit 9dc46f1) engine/ovr014.cs:
 * {@code TrySweepAttack} (sub_3EF3D).
 *
 * <p>COAB's version also performs the sweep (recalculating attacks-received,
 * consuming the attacker's remaining swing and dispatching
 * {@code AttackTarget} for each swept target). This package only plans which
 * targets get swept -- applying the plan (running {@link AttackResolver}
 * against each planned target and consuming attacks) is the integrator's
 * job, matching this package's read-only, non-mutating contract.</p>
 *
 * <p>{@link #plan} is generic in the caller's target identity type (e.g. a
 * combatant id), so this utility class stays free of a dependency on any
 * specific combatant type.</p>
 */
public final class SweepAttackPlanner {

	private SweepAttackPlanner() {
	}

	/**
	 * One candidate from COAB {@code ovr025.BuildNearTargets(1, attacker)}.
	 *
	 * @param target the candidate's identity
	 * @param hitDice COAB {@code player.HitDice}; sweep only considers 0-hit-die targets
	 * @param hitBonus COAB {@code player.hitBonus}. Consumed verbatim by the final filter below --
	 *   ported faithfully even though gating a target's eligibility to BE swept on the
	 *   SWEEPER's to-hit bonus looks like a decompiler artifact (a mismatched field read) rather
	 *   than intentional game design.
	 */
	public record Candidate<T>(T target, int hitDice, int hitBonus) {
	}

	public record SweepPlan<T>(boolean triggered, List<T> sweepTargets) {
		static <T> SweepPlan<T> none() {
			return new SweepPlan<>(false, List.of());
		}
	}

	/**
	 * Ported from COAB {@code ovr014.TrySweepAttack} (sub_3EF3D).
	 *
	 * <p>Quirk preserved faithfully and covered by
	 * {@code SweepAttackPlannerTest}: the number of targets to sweep
	 * ({@code sweepableCount}) is counted from ALL candidates with
	 * {@code hitDice == 0}, but the actual sweep list is sliced from the
	 * candidates re-filtered down to {@code hitBonus == 0}. COAB takes this
	 * slice with C# {@code List<T>.GetRange(0, sweepableCount)}, which throws
	 * {@code ArgumentException} if the filtered list is shorter than
	 * {@code sweepableCount}. This method mirrors that failure with an
	 * {@link IndexOutOfBoundsException} rather than silently clamping, since
	 * clamping would diverge from the original's crash-on-this-input
	 * behavior.</p>
	 *
	 * @param primaryTarget COAB {@code target}, the target the caller was already resolving an
	 *   attack against; must be present in {@code nearbyCandidates} (COAB retrieves it from that
	 *   same list via {@code Find}; a real call site with {@code primaryTargetRangeIsOne == true}
	 *   is guaranteed this by construction since {@code BuildNearTargets(1, attacker)} includes
	 *   anyone within range 1)
	 * @param nearbyCandidates COAB {@code ovr025.BuildNearTargets(1, attacker)}
	 * @param attackerAttack1AttacksLeft COAB {@code attacker.attack1_AttacksLeft}
	 * @param attackerMaxSweepTargets COAB {@code attacker.actions.maxSweapTargets}
	 * @param primaryTargetHasZeroHitDice COAB {@code target.HitDice == 0}
	 * @param primaryTargetRangeIsOne COAB {@code ovr025.getTargetRange(target, attacker) == 1}
	 */
	public static <T> SweepPlan<T> plan(
		T primaryTarget,
		List<Candidate<T>> nearbyCandidates,
		int attackerAttack1AttacksLeft,
		int attackerMaxSweepTargets,
		boolean primaryTargetHasZeroHitDice,
		boolean primaryTargetRangeIsOne
	) {
		boolean eligible = attackerAttack1AttacksLeft < attackerMaxSweepTargets
			&& primaryTargetHasZeroHitDice
			&& primaryTargetRangeIsOne;
		if (!eligible) {
			return SweepPlan.none();
		}

		int primaryIndex = -1;
		for (int i = 0; i < nearbyCandidates.size(); i++) {
			if (nearbyCandidates.get(i).target().equals(primaryTarget)) {
				primaryIndex = i;
				break;
			}
		}
		if (primaryIndex < 0) {
			throw new IllegalArgumentException(
				"primaryTarget must be present in nearbyCandidates, as COAB sub_3EF3D expects "
					+ "BuildNearTargets(1, attacker) to already contain the range-1 target");
		}

		long sweepableCount = nearbyCandidates.stream().filter(c -> c.hitDice() == 0).count();
		if (sweepableCount <= attackerAttack1AttacksLeft) {
			return SweepPlan.none();
		}

		int sweepable = (int) sweepableCount;
		if (sweepable > attackerMaxSweepTargets) {
			sweepable = attackerMaxSweepTargets;
		}

		List<Candidate<T>> reordered = new ArrayList<>(nearbyCandidates);
		Candidate<T> primary = reordered.remove(primaryIndex);
		reordered.add(0, primary);

		List<Candidate<T>> zeroHitBonus = new ArrayList<>();
		for (Candidate<T> candidate : reordered) {
			if (candidate.hitBonus() == 0) {
				zeroHitBonus.add(candidate);
			}
		}

		if (zeroHitBonus.size() < sweepable) {
			throw new IndexOutOfBoundsException(
				"COAB sub_3EF3D quirk: sweepableCount (" + sweepable + ") exceeds the hitBonus==0 "
					+ "candidate count (" + zeroHitBonus.size() + ") after filtering, which is what "
					+ "COAB's List<T>.GetRange(0, sweepableCount) throws ArgumentException on");
		}

		List<T> sweepTargets = new ArrayList<>();
		for (int i = 0; i < sweepable; i++) {
			sweepTargets.add(zeroHitBonus.get(i).target());
		}

		return new SweepPlan<>(true, List.copyOf(sweepTargets));
	}
}
