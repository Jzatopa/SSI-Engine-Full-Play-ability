package engine.party;

import java.util.Optional;

/**
 * Loads the character record for a story NPC by id, so {@link NpcPartyService}
 * can add it to the party.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * {@code engine/ovr017.cs}: {@code load_mob(monster_id, exit)} (sub_4A54D-area)
 * reads {@code MON<area>CHA.dax} for the base character record, then appends
 * {@code MON<area>SPC.dax} (status affects) and {@code MON<area>ITM.dax}
 * (starting items) data onto it. That file/asset plumbing is integrator I/O,
 * not engine logic, so it is deliberately not ported here -- implementations
 * of this interface are expected to wire it to whatever the integrator's
 * equivalent of {@code PlayerDataFactory} is.</p>
 *
 * <p>COAB's {@code load_mob} returns {@code null} (or exits the process, if
 * {@code exit} is true) when the monster/character data set is missing. This
 * interface always uses the non-exiting behavior: a missing/unloadable record
 * is {@link Optional#empty()}, and it is the integrator's decision what to do
 * about a missing data file (COAB's own {@code exit=true} callers just crash
 * to DOS, which is not a behavior worth reproducing).</p>
 */
public interface NpcCharacterSource {

	/**
	 * Loads the NPC character record for {@code npcId} (COAB {@code monster_id}).
	 * Returns {@link Optional#empty()} if no such record exists, mirroring
	 * COAB's {@code load_mob(monster_id, false)} returning {@code null}.
	 */
	Optional<? extends NpcCharacter> load(int npcId);
}
