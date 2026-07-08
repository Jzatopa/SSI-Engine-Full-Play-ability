package engine.party;

import java.util.List;

/**
 * The live party membership list that {@link NpcPartyService} mutates.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * {@code gbl.TeamList} (the ordered party member list) and {@code gbl.SelectedPlayer}
 * (the currently loaded/active member). COAB also keeps a separate
 * {@code gbl.area2_ptr.party_size} counter that is supposed to track
 * {@code TeamList.Count} 1:1 (incremented in {@code ovr017.AssignPlayerIconId},
 * decremented in {@code ovr018.FreeCurrentPlayer} unless told to leave it alone);
 * this port drops the separate counter and always uses {@code members().size()},
 * which is the value it always agreed with in the source.</p>
 *
 * <p>An integrator implementation is expected to back this with the real
 * party-member storage (e.g. an {@code engine.VirtualMemory} party list) --
 * this package intentionally never touches {@code VirtualMemory} or
 * {@code PlayerDataFactory} directly so it stays reusable outside this
 * engine fork.</p>
 */
public interface PartyRoster {

	/** Current party members, in COAB {@code TeamList} order. */
	List<? extends NpcCharacter> members();

	/** Appends {@code member} to the end of the roster (COAB {@code TeamList.Add}). */
	void add(NpcCharacter member);

	/** Removes {@code member} from the roster (COAB {@code TeamList.RemoveAt}). */
	void remove(NpcCharacter member);

	/**
	 * The currently selected/active member (COAB {@code gbl.SelectedPlayer}),
	 * or {@code null} if the roster is empty or nothing is selected.
	 */
	NpcCharacter current();

	/** Sets the currently selected/active member; see {@link #current()}. */
	void setCurrent(NpcCharacter member);
}
