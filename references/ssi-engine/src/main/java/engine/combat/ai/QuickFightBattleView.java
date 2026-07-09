package engine.combat.ai;

import java.util.List;
import java.util.OptionalInt;

/**
 * Read-only battlefield facts and geometry callbacks for {@link QuickFightPlanner}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * — as an interface, not a port: the geometry methods stand in for COAB's
 * pathing/LOS routines, which are map math owned by the map/LOS track. This
 * package defines its own minimal boundary instead of depending on the
 * sibling {@code engine.combat.map} package so the tracks can land
 * independently; the integrator's adapter is expected to delegate to that
 * package (or the frozen combat scaffold) later.</p>
 */
public interface QuickFightBattleView {
	/** All combatants in the battle, alive or not; the planner filters by {@code inCombat()}. */
	List<QuickFightCombatantView> combatants();

	/**
	 * COAB {@code ovr014.CanSeeTargetA} (sub_3F143): target is non-null,
	 * visible (not invisible/blinded away) from the attacker. Self is always
	 * visible in COAB; adapters should preserve that.
	 */
	boolean canSee(QuickFightCombatantView self, QuickFightCombatantView target);

	/**
	 * COAB {@code ovr025.BuildNearTargets} (near_enermy): opposing-team
	 * combatants still in combat whose walk distance from {@code self} is at
	 * most {@code maxRange} squares, sorted nearest first. When
	 * {@code ignoreWalls} is set the path may cross walls, mirroring
	 * {@code gbl.mapToBackGroundTile.ignoreWalls} in {@code find_target}'s
	 * second pass.
	 */
	List<QuickFightCombatantView> enemiesWithin(QuickFightCombatantView self, int maxRange, boolean ignoreWalls);

	/**
	 * COAB {@code ovr032.canReachTarget} (sub_733F1 wrapper), walls
	 * respected: half-step path length to the target, or empty when no path
	 * exists. {@code sub_35DB1} attacks the remembered target when
	 * {@code steps / 2 <= weaponRange}. Deviation, labeled: COAB's
	 * {@code range*2+1} early-out is an optimization inside the path routine
	 * and is left to the adapter.
	 */
	OptionalInt pathStepsTo(QuickFightCombatantView self, QuickFightCombatantView target);

	/**
	 * COAB {@code ovr025.getTargetRange} (sub_68708): walk distance in
	 * squares with walls ignored, or {@link QuickFightCombatantView#UNREACHABLE}
	 * when no path exists at all.
	 */
	int distanceTo(QuickFightCombatantView self, QuickFightCombatantView target);

	/**
	 * COAB {@code gbl.area2_ptr.field_58C}: the encounter's base morale value
	 * consumed by {@code FleeCheck_001}'s {@code 100 - field_58C} threshold.
	 */
	int battleBaseMorale();

	/**
	 * COAB {@code gbl.area_ptr.can_cast_spells == false}. Quirk preserved
	 * from {@code sub_354AA}: the AI reaches for charged items only in areas
	 * where spellcasting is forbidden.
	 */
	boolean areaForbidsSpells();

	/** COAB {@code gbl.AutoPCsCastMagic}: the player toggle letting quick-fought PCs cast. */
	boolean autoPartyCastsMagic();

	/**
	 * COAB {@code ovr025.bandage(...)} scan condition: some party-side
	 * teammate (not an outsider) has {@code health_status == dying}.
	 * {@code sub_35DB1} bandages before anything else on the party's side.
	 */
	boolean anyPartyTeammateDying();
}
