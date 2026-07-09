package engine.combat.attack;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

import engine.combat.attack.SweepAttackPlanner.Candidate;
import engine.combat.attack.SweepAttackPlanner.SweepPlan;

/**
 * Conformance tests for the COAB-ported sweep-attack target selection
 * (ovr014.TrySweepAttack sub_3EF3D; coab commit 9dc46f1).
 */
public class SweepAttackPlannerTest {

	private static Candidate<String> mook(String name) {
		return new Candidate<>(name, 0, 0);
	}

	@Test
	public void notTriggeredWhenAttacksLeftMeetsMaxSweepTargets() {
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), mook("b")), 2, 2, true, true);
		assertFalse(plan.triggered());
		assertTrue(plan.sweepTargets().isEmpty());
	}

	@Test
	public void notTriggeredAgainstTargetWithHitDice() {
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), mook("b")), 1, 4, false, true);
		assertFalse(plan.triggered());
	}

	@Test
	public void notTriggeredBeyondRangeOne() {
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), mook("b")), 1, 4, true, false);
		assertFalse(plan.triggered());
	}

	@Test
	public void notTriggeredWhenSweepableCountDoesNotExceedAttacksLeft() {
		// sub_3EF3D requires sweepableCount > attack1_AttacksLeft, strictly.
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), mook("b")), 2, 4, true, true);
		assertFalse(plan.triggered());
	}

	@Test
	public void sweepsAllZeroHitDiceNeighborsWithPrimaryTargetFirst() {
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"c", List.of(mook("a"), mook("b"), mook("c")), 1, 4, true, true);
		assertTrue(plan.triggered());
		// COAB moves the aimed-at target to the front of the near-target list.
		assertEquals(List.of("c", "a", "b"), plan.sweepTargets());
	}

	@Test
	public void sweepListClampsToMaxSweepTargets() {
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), mook("b"), mook("c"), mook("d")), 1, 2, true, true);
		assertTrue(plan.triggered());
		assertEquals(List.of("a", "b"), plan.sweepTargets());
	}

	@Test
	public void hitDiceCountsEligibilityButHitBonusFiltersTheActualSlice() {
		// Quirk pinned from sub_3EF3D: sweepableCount counts HitDice == 0
		// candidates, but the swept slice is taken from the candidates
		// re-filtered to hitBonus == 0 -- a nonzero-hitBonus mook still
		// inflates the count while being skipped in the sweep itself.
		Candidate<String> bonusMook = new Candidate<>("b", 0, 2);
		Candidate<String> hitDiceMook = new Candidate<>("d", 3, 0);
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), bonusMook, mook("c"), hitDiceMook, mook("e")), 1, 3, true, true);
		assertTrue(plan.triggered());
		// sweepableCount = 4 (a, b, c, e), clamped to 3; slice from
		// hitBonus == 0 candidates in primary-first order: a, c, d, e -> first 3.
		assertEquals(List.of("a", "c", "d"), plan.sweepTargets());
	}

	@Test
	public void hitDiceCarryingZeroBonusCandidateCanBeSweptDespiteNotCounting() {
		// Second face of the same quirk: candidate "d" above has HitDice 3 (it
		// never counted toward sweepableCount) yet lands in the swept slice
		// because its hitBonus is 0 and it sits early in the list.
		Candidate<String> hitDiceMook = new Candidate<>("d", 3, 0);
		SweepPlan<String> plan = SweepAttackPlanner.plan(
			"a", List.of(mook("a"), hitDiceMook, mook("c"), mook("e")), 1, 2, true, true);
		assertTrue(plan.triggered());
		assertEquals(List.of("a", "d"), plan.sweepTargets());
	}

	@Test(expected = IndexOutOfBoundsException.class)
	public void tooFewZeroHitBonusCandidatesThrowsLikeCoabGetRange() {
		// Quirk pinned: COAB slices with List<T>.GetRange(0, sweepableCount),
		// which throws when the hitBonus == 0 filter leaves fewer candidates
		// than sweepableCount. Mirrored, not clamped.
		Candidate<String> bonusMookB = new Candidate<>("b", 0, 1);
		Candidate<String> bonusMookC = new Candidate<>("c", 0, 1);
		SweepAttackPlanner.plan(
			"a", List.of(mook("a"), bonusMookB, bonusMookC), 1, 4, true, true);
	}

	@Test(expected = IllegalArgumentException.class)
	public void primaryTargetMissingFromCandidatesIsRejected() {
		SweepAttackPlanner.plan(
			"zz", List.of(mook("a"), mook("b")), 1, 4, true, true);
	}
}
