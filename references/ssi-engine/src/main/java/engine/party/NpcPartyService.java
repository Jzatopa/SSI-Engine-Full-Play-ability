package engine.party;

import java.util.List;
import java.util.Optional;

/**
 * Story-NPC party lifecycle: the ECL ADD NPC / DUMP command semantics plus
 * the join-gate rules, operating on a {@link PartyRoster} and loading records
 * through an {@link NpcCharacterSource}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1),
 * which translates the original Gold Box engine per overlay:</p>
 * <ul>
 * <li>{@code ovr003.CMD_AddNPC} (sub_28DCA), ECL opcode 0x36: loads the NPC via
 * {@code ovr017.load_npc}, then sets the selected member's control/morale to
 * {@code (morale >> 1) + Control.NPC_Base} and recalculates derived values --
 * see {@link #addNpc(int, int)}.</li>
 * <li>{@code ovr017.load_npc} (sub_4A57D): only acts while
 * {@code party_size <= 7}; loads the record, stamps {@code mod_id} with the
 * requested id, and joins it via {@code AssignPlayerIconId}. It performs
 * <em>no</em> duplicate check -- the same NPC id can be added twice.</li>
 * <li>{@code ovr017.AssignPlayerIconId} (sub_4A60A): appends the member, makes
 * it the selected member, assigns the lowest free combat-icon slot 0..7, and
 * (for NPC-controlled members) triggers the ruleset's class-bonus
 * recalculation -- see {@link #assignIconIdAndJoin(NpcCharacter)}.</li>
 * <li>{@code ovr003.CMD_Dump} (sub_29271), ECL opcode 0x3E (this engine fork's
 * {@code EclOpCode.NPC_REMOVE}): frees the selected member via
 * {@code ovr018.FreeCurrentPlayer} and selects the returned neighbor -- see
 * {@link #removeCurrent()}.</li>
 * <li>{@code ovr018.FreeCurrentPlayer} (free_players): removes the member,
 * optionally releases its combat icon, and returns the member at the removed
 * index minus one (or index 0), or null when the roster empties -- see
 * {@link #remove(NpcCharacter, boolean)}.</li>
 * <li>{@code ovr018}'s add-character gate (inside the Add menu loop): rejects
 * a candidate matching an existing member on name + {@code mod_id}, enforces
 * at most 6 player-controlled characters and at most 8 total members, and
 * applies the AD&amp;D paladin/ranger/alignment refusals (flavor, behind
 * {@link NpcPartyHooks#flavorPermitsJoin}) -- see
 * {@link #checkJoin(NpcCharacter)}.</li>
 * </ul>
 *
 * <p>Note on "find": this fork's {@code EclOpCode.NPC_FIND} is opcode 0x37,
 * but COAB registers 0x37 as "LOAD PIECES" ({@code CMD_LoadFiles}) -- there is
 * no NPC-find command in the COAB command table. {@link #findNpc(int)} is
 * therefore an adaptation: a roster lookup keyed on the {@code mod_id} stamp
 * that {@code load_npc} applies, the same key COAB's duplicate check uses.</p>
 *
 * <p>Adaptations, labeled per the reuse policy: where COAB's {@code load_mob}
 * exits to DOS on a missing MON record, {@link #addNpc} returns
 * {@link AddNpcResult#RECORD_MISSING} and does nothing else. COAB's separate
 * {@code area2_ptr.party_size} counter is dropped in favor of
 * {@code roster.members().size()} (see {@link PartyRoster}). UI calls
 * (PartySummary, icon pixel loading, farewell strings) are not ported.
 * The party-full quirk of {@code CMD_AddNPC} <em>is</em> ported: when the
 * party is full, {@code load_npc} silently does nothing but the morale
 * assignment still lands on whoever is currently selected.</p>
 *
 * <p>Integrator wiring: back {@link PartyRoster} with the engine's party
 * storage (e.g. {@code engine.VirtualMemory}'s party member list and
 * loaded-character selection), and {@link NpcCharacterSource} with the
 * engine's character loader (e.g. {@code PlayerDataFactory}); route the VM's
 * {@code NPC_ADD}/{@code NPC_REMOVE} opcode handlers to
 * {@link #addNpc(int, int)} and {@link #removeCurrent()}.</p>
 */
public final class NpcPartyService {

	/** COAB {@code Control.NPC_Base} (0x80): control/morale values at or above this mark NPC-controlled members. */
	public static final int NPC_CONTROL_BASE = 0x80;

	/** Total member limit: {@code load_npc} admits while {@code party_size <= 7}, so the roster tops out at 8. */
	public static final int MAX_PARTY_SIZE = 8;

	/** Player-character limit in the ovr018 join gate: {@code pc_count < 6}. */
	public static final int MAX_PLAYER_CHARACTERS = 6;

	/** Combat icon slots 0..7 scanned by {@code AssignPlayerIconId}. */
	public static final int ICON_SLOT_COUNT = 8;

	/** The 0xFF placeholder {@code AssignPlayerIconId} stores before scanning for a free slot. */
	public static final int UNASSIGNED_ICON_ID = 0xFF;

	/** Outcome of {@link #addNpc(int, int)} / {@link #loadNpc(int)}. */
	public enum AddNpcResult {
		/** The NPC was loaded and joined the party. */
		ADDED,
		/** {@code load_npc}'s {@code party_size <= 7} gate failed; nothing was loaded. */
		PARTY_FULL,
		/** The character source has no record for the id (COAB would exit to DOS here; labeled deviation). */
		RECORD_MISSING
	}

	/** Outcome of {@link #checkJoin(NpcCharacter)}, the ovr018 add-character gate. */
	public enum JoinCheck {
		OK,
		/** An existing member matches the candidate on both name and NPC id ({@code mod_id}). */
		DUPLICATE,
		/** A player character beyond the 6-PC limit, or any member beyond the 8-total limit. */
		PARTY_FULL,
		/** {@link NpcPartyHooks#flavorPermitsJoin} refused (AD&amp;D paladin/ranger/alignment rules). */
		REFUSED_BY_RULESET
	}

	private final PartyRoster roster;
	private final NpcCharacterSource characterSource;
	private final NpcPartyHooks hooks;

	public NpcPartyService(PartyRoster roster, NpcCharacterSource characterSource) {
		this(roster, characterSource, new NpcPartyHooks() {
		});
	}

	public NpcPartyService(PartyRoster roster, NpcCharacterSource characterSource, NpcPartyHooks hooks) {
		this.roster = roster;
		this.characterSource = characterSource;
		this.hooks = hooks;
	}

	/**
	 * {@code ovr003.CMD_AddNPC} (ECL ADD NPC, opcode 0x36): {@code loadNpc},
	 * then assign control/morale to the selected member as
	 * {@code (moraleArgument >> 1) + NPC_CONTROL_BASE} (byte arithmetic) and
	 * recalculate its derived values.
	 *
	 * <p>Faithful quirk: COAB applies the morale assignment to
	 * {@code gbl.SelectedPlayer} unconditionally. On {@link AddNpcResult#ADDED}
	 * that is the new NPC; on {@link AddNpcResult#PARTY_FULL} it clobbers the
	 * control/morale of whichever member was already selected. Only the
	 * {@link AddNpcResult#RECORD_MISSING} path skips it, because COAB never
	 * reaches the assignment there (it exits the process inside
	 * {@code load_mob}; this port returns instead -- labeled deviation).</p>
	 *
	 * @param npcId the MON record id (ECL argument 1)
	 * @param moraleArgument the raw morale byte (ECL argument 2); AD&amp;D
	 *   morale semantics of the low bits are ruleset flavor, but the
	 *   shift-and-base encoding is universal engine behavior and ported as-is
	 */
	public AddNpcResult addNpc(int npcId, int moraleArgument) {
		AddNpcResult result = loadNpc(npcId);

		if (result == AddNpcResult.RECORD_MISSING) {
			return result;
		}

		NpcCharacter selected = roster.current();
		if (selected != null) {
			int morale = moraleArgument & 0xFF;
			selected.setControlMorale(((morale >> 1) + NPC_CONTROL_BASE) & 0xFF);
			hooks.recalcDerivedValues(selected);
		}
		return result;
	}

	/**
	 * {@code ovr017.load_npc} (sub_4A57D): while the roster holds at most 7
	 * members, loads the record for {@code npcId}, stamps its NPC id
	 * ({@code player.mod_id = (byte)monster_id}), and joins it via
	 * {@link #assignIconIdAndJoin(NpcCharacter)}. No duplicate check: adding
	 * the same id twice yields two members, exactly as the C# does.
	 */
	public AddNpcResult loadNpc(int npcId) {
		if (roster.members().size() > MAX_PARTY_SIZE - 1) {
			return AddNpcResult.PARTY_FULL;
		}

		Optional<? extends NpcCharacter> loaded = characterSource.load(npcId);
		if (loaded.isEmpty()) {
			return AddNpcResult.RECORD_MISSING;
		}

		NpcCharacter npc = loaded.get();
		npc.setNpcId(npcId & 0xFF);
		assignIconIdAndJoin(npc);
		return AddNpcResult.ADDED;
	}

	/**
	 * {@code ovr017.AssignPlayerIconId} (sub_4A60A): appends {@code member} to
	 * the roster, makes it the selected member, and assigns the lowest combat
	 * icon slot (0..7) not held by any member. If all eight slots are taken
	 * the member ends up with icon id 8, exactly as the C# scan leaves it.
	 * NPC-controlled members get a ruleset class-bonus recalculation
	 * ({@link NpcPartyHooks#recalcClassBonuses}).
	 */
	public void assignIconIdAndJoin(NpcCharacter member) {
		member.setIconId(UNASSIGNED_ICON_ID);

		roster.add(member);
		roster.setCurrent(member);

		boolean[] iconSlotUsed = new boolean[ICON_SLOT_COUNT];
		for (NpcCharacter existing : roster.members()) {
			int icon = existing.iconId();
			if (icon >= 0 && icon < ICON_SLOT_COUNT) {
				iconSlotUsed[icon] = true;
			}
		}

		int slot = 0;
		while (slot < ICON_SLOT_COUNT && iconSlotUsed[slot]) {
			slot += 1;
		}
		member.setIconId(slot);

		if (member.controlMorale() >= NPC_CONTROL_BASE) {
			hooks.recalcClassBonuses(member);
		}
	}

	/**
	 * Finds the first roster member whose NPC id ({@code mod_id} stamp)
	 * matches. Adaptation, not a COAB command port: COAB has no FIND NPC
	 * opcode (0x37 is LOAD PIECES there); this is the lookup an integrator
	 * needs to target a specific story NPC, keyed the same way COAB's
	 * name+mod_id duplicate check identifies one.
	 */
	public Optional<NpcCharacter> findNpc(int npcId) {
		for (NpcCharacter member : roster.members()) {
			if (member.npcId() == (npcId & 0xFF)) {
				return Optional.of(member);
			}
		}
		return Optional.empty();
	}

	/**
	 * {@code ovr003.CMD_Dump} (ECL opcode 0x3E, this fork's NPC_REMOVE):
	 * removes the selected member (releasing its icon slot) and selects the
	 * neighbor {@code FreeCurrentPlayer} returns.
	 *
	 * @return the newly selected member, or null if the roster is now empty
	 */
	public NpcCharacter removeCurrent() {
		NpcCharacter next = remove(roster.current(), true);
		roster.setCurrent(next);
		return next;
	}

	/**
	 * {@code ovr018.FreeCurrentPlayer} (free_players): removes {@code member}
	 * from the roster; when {@code releaseIcon} is set, hands its icon slot to
	 * {@link NpcPartyHooks#releaseIcon}. Returns the member now at the removed
	 * index minus one (index 0 if the first member was removed), or null when
	 * the roster is empty afterwards or {@code member} was not in the roster.
	 *
	 * <p>COAB's third parameter {@code leave_party_size} only maintained the
	 * redundant {@code party_size} counter this port derives from the roster,
	 * so it has no equivalent here (labeled deviation; see
	 * {@link PartyRoster}).</p>
	 */
	public NpcCharacter remove(NpcCharacter member, boolean releaseIcon) {
		List<? extends NpcCharacter> members = roster.members();
		int index = -1;
		for (int i = 0; i < members.size(); i++) {
			if (members.get(i) == member) {
				index = i;
				break;
			}
		}
		if (index < 0) {
			return null;
		}

		roster.remove(member);

		if (releaseIcon) {
			hooks.releaseIcon(member.iconId());
		}

		int next = index > 0 ? index - 1 : 0;
		List<? extends NpcCharacter> remaining = roster.members();
		return remaining.isEmpty() ? null : remaining.get(next);
	}

	/**
	 * The ovr018 add-character gate (the checks around
	 * {@code "paladins do not join with evil scum"}), split into its universal
	 * and flavor parts: a candidate is refused when an existing member matches
	 * on name + NPC id ({@link JoinCheck#DUPLICATE}); a player-controlled
	 * candidate needs fewer than 6 player characters and an NPC-controlled
	 * candidate fewer than 8 total members ({@link JoinCheck#PARTY_FULL});
	 * finally {@link NpcPartyHooks#flavorPermitsJoin} may veto
	 * ({@link JoinCheck#REFUSED_BY_RULESET}). Note this gate belongs to the
	 * interactive Add menu -- the ECL {@link #addNpc(int, int)} path bypasses
	 * it entirely, as in COAB.
	 */
	public JoinCheck checkJoin(NpcCharacter candidate) {
		int pcCount = 0;
		List<? extends NpcCharacter> members = roster.members();

		for (NpcCharacter member : members) {
			if (member.name().equals(candidate.name()) && member.npcId() == candidate.npcId()) {
				return JoinCheck.DUPLICATE;
			}
			if (member.controlMorale() < NPC_CONTROL_BASE) {
				pcCount += 1;
			}
		}

		boolean fits = candidate.controlMorale() < NPC_CONTROL_BASE //
			? pcCount < MAX_PLAYER_CHARACTERS
			: members.size() < MAX_PARTY_SIZE;
		if (!fits) {
			return JoinCheck.PARTY_FULL;
		}

		if (!hooks.flavorPermitsJoin(candidate, members)) {
			return JoinCheck.REFUSED_BY_RULESET;
		}
		return JoinCheck.OK;
	}
}
