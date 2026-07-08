package engine.party;

/**
 * A single party member (player character or story NPC) as seen by
 * {@link NpcPartyService}.
 *
 * <p>Ported from COAB (https://github.com/simeonpilgrim/coab, commit 9dc46f1)
 * {@code Classes/Player.cs}: this interface exposes only the fields the NPC
 * lifecycle functions ({@code ovr003.CMD_AddNPC}, {@code ovr017.load_npc},
 * {@code ovr017.AssignPlayerIconId}, {@code ovr018.FreeCurrentPlayer},
 * {@code ovr006.distributeNpcTreasure}) actually read or write. Everything
 * else about a character (stats, inventory, spells...) belongs to whatever
 * character-sheet type the integrator already has; that type should simply
 * implement this interface, or a small adapter should wrap it.</p>
 */
public interface NpcCharacter {

	/**
	 * COAB {@code Player.mod_id}: the monster/character id this record was
	 * loaded from ({@code ovr017.load_npc} sets {@code player.mod_id = monster_id}
	 * immediately after {@code load_mob}). Used to identify/find a specific
	 * story NPC.
	 */
	int npcId();

	/**
	 * Sets {@code Player.mod_id}; {@code ovr017.load_npc} stamps the requested
	 * monster id onto the freshly loaded record ({@code player.mod_id =
	 * (byte)monster_id}) before adding it to the party.
	 */
	void setNpcId(int npcId);

	/**
	 * COAB {@code Player.name}. Together with {@link #npcId()} this is the
	 * duplicate-membership key: {@code ovr018}'s add-character gate rejects a
	 * candidate when an existing member matches on both {@code name} and
	 * {@code mod_id}.
	 */
	String name();

	/**
	 * COAB {@code Player.control_morale} (a byte, 0-255). Values
	 * {@code >= NpcPartyService.NPC_CONTROL_BASE} (COAB {@code Control.NPC_Base = 0x80})
	 * mark the member as NPC-controlled rather than player-controlled; the low
	 * bits below that threshold are the AD&D morale value used elsewhere by
	 * COAB's combat AI (flavor, not ported here).
	 */
	int controlMorale();

	/** Sets {@code Player.control_morale}; see {@link #controlMorale()}. */
	void setControlMorale(int controlMorale);

	/** {@code controlMorale() >= NpcPartyService.NPC_CONTROL_BASE}, i.e. COAB's {@code control_morale >= Control.NPC_Base} test. */
	default boolean isNpc() {
		return controlMorale() >= NpcPartyService.NPC_CONTROL_BASE;
	}

	/**
	 * COAB {@code Player.icon_id}: the combat-portrait/icon slot (0-7) this
	 * member occupies, assigned by {@code ovr017.AssignPlayerIconId}. Not
	 * icon-rendering itself (out of scope here) -- just the slot-number
	 * bookkeeping that decides which slot is "free" for the next add.
	 */
	int iconId();

	/** Sets {@code Player.icon_id}; see {@link #iconId()}. */
	void setIconId(int iconId);

	/**
	 * COAB {@code Player.npcTreasureShareCount} (a byte; only the low 3 bits
	 * are used, per {@code ovr006.distributeNpcTreasure}'s {@code & 7} mask).
	 * Only meaningful when {@link #isNpc()} is true; used by
	 * {@link NpcTreasureShare}.
	 */
	int npcTreasureShareCount();

	/**
	 * COAB {@code Player.health_status == Status.okey}, read by
	 * {@code ovr006.distributeNpcTreasure} to decide whether a downed/dead NPC
	 * still takes a treasure share. The full COAB health-status enum is
	 * ruleset-specific (flavor); this interface only needs the boolean
	 * "eligible to take a share" answer.
	 */
	boolean isHealthy();
}
