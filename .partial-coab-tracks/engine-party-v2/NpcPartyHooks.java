package engine.party;

import java.util.List;

/**
 * Integrator/ruleset callbacks invoked by {@link NpcPartyService} at the
 * points where COAB calls out of the party-lifecycle code into rendering,
 * derived-stat recalculation, or AD&amp;D-specific rules. All defaults are
 * no-ops / permissive, so the service is fully usable for pure party
 * bookkeeping without wiring anything.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1);
 * each method cites the COAB call it stands in for.</p>
 */
public interface NpcPartyHooks {

	/**
	 * COAB {@code ovr026.ReclacClassBonuses(player)}, called by
	 * {@code ovr017.AssignPlayerIconId} only when the newly added member is
	 * NPC-controlled ({@code control_morale >= Control.NPC_Base}). AD&amp;D
	 * class/level bonus recomputation -- ruleset flavor, deliberately not
	 * ported into the universal engine.
	 */
	default void recalcClassBonuses(NpcCharacter npc) {
	}

	/**
	 * COAB {@code ovr025.reclac_player_values(player)}, called by
	 * {@code ovr003.CMD_AddNPC} on the selected member after assigning
	 * control/morale. Recomputes derived stats (AC, hit bonus, ...) --
	 * ruleset flavor.
	 */
	default void recalcDerivedValues(NpcCharacter member) {
	}

	/**
	 * COAB {@code ovr034.ReleaseCombatIcon(player.icon_id)}, called by
	 * {@code ovr018.FreeCurrentPlayer} when its {@code free_icon} argument is
	 * true. Icon-asset bookkeeping is integrator territory; the slot number
	 * itself is managed by {@link NpcPartyService}.
	 */
	default void releaseIcon(int iconId) {
	}

	/**
	 * The AD&amp;D-flavored portion of COAB {@code ovr018}'s add-character
	 * gate: a paladin will not join a party containing an evil member, an
	 * evil candidate is refused when a paladin is present, and at most 3
	 * rangers are allowed. Those checks read class levels and alignment,
	 * which are ruleset flavor -- a flavor module implements them here.
	 * The universal checks (duplicate identity, party-size limits) are in
	 * {@link NpcPartyService#checkJoin(NpcCharacter)} itself.
	 *
	 * @return true (default) to permit the join, false to refuse it
	 */
	default boolean flavorPermitsJoin(NpcCharacter candidate, List<? extends NpcCharacter> members) {
		return true;
	}
}
