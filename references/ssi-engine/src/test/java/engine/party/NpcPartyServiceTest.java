package engine.party;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import org.junit.Test;

import engine.party.NpcPartyService.AddNpcResult;
import engine.party.NpcPartyService.JoinCheck;

/**
 * Conformance tests for the COAB-ported NPC party lifecycle
 * (ovr003.CMD_AddNPC/CMD_Dump, ovr017.load_npc/AssignPlayerIconId,
 * ovr018.FreeCurrentPlayer and add-character gate, coab commit 9dc46f1).
 */
public class NpcPartyServiceTest {

	private static final class FakeCharacter implements NpcCharacter {
		private int npcId;
		private final String name;
		private int controlMorale;
		private int iconId = NpcPartyService.UNASSIGNED_ICON_ID;
		private int shareCount;
		private boolean healthy = true;

		private FakeCharacter(int npcId, String name, int controlMorale) {
			this.npcId = npcId;
			this.name = name;
			this.controlMorale = controlMorale;
		}

		@Override
		public int npcId() {
			return npcId;
		}

		@Override
		public void setNpcId(int npcId) {
			this.npcId = npcId;
		}

		@Override
		public String name() {
			return name;
		}

		@Override
		public int controlMorale() {
			return controlMorale;
		}

		@Override
		public void setControlMorale(int controlMorale) {
			this.controlMorale = controlMorale;
		}

		@Override
		public int iconId() {
			return iconId;
		}

		@Override
		public void setIconId(int iconId) {
			this.iconId = iconId;
		}

		@Override
		public int npcTreasureShareCount() {
			return shareCount;
		}

		@Override
		public boolean isHealthy() {
			return healthy;
		}
	}

	private static final class FakeRoster implements PartyRoster {
		private final List<NpcCharacter> members = new ArrayList<>();
		private NpcCharacter current;

		@Override
		public List<NpcCharacter> members() {
			return members;
		}

		@Override
		public void add(NpcCharacter member) {
			members.add(member);
		}

		@Override
		public void remove(NpcCharacter member) {
			members.remove(member);
		}

		@Override
		public NpcCharacter current() {
			return current;
		}

		@Override
		public void setCurrent(NpcCharacter member) {
			current = member;
		}
	}

	private static final class FakeSource implements NpcCharacterSource {
		private final Map<Integer, String> records = new HashMap<>();

		private FakeSource with(int id, String name) {
			records.put(id, name);
			return this;
		}

		@Override
		public Optional<FakeCharacter> load(int npcId) {
			String name = records.get(npcId);
			if (name == null) {
				return Optional.empty();
			}
			// A fresh record per load, like COAB's load_mob decoding a new Player.
			return Optional.of(new FakeCharacter(0, name, 0));
		}
	}

	private static FakeCharacter pc(String name) {
		return new FakeCharacter(0, name, 0x30);
	}

	private static FakeCharacter npc(int id, String name) {
		return new FakeCharacter(id, name, NpcPartyService.NPC_CONTROL_BASE + 3);
	}

	@Test
	public void addNpcLoadsStampsIdAssignsIconMoraleAndSelection() {
		FakeRoster roster = new FakeRoster();
		FakeSource source = new FakeSource().with(5, "TALON");
		NpcPartyService service = new NpcPartyService(roster, source);

		assertEquals(AddNpcResult.ADDED, service.addNpc(5, 6));

		assertEquals(1, roster.members().size());
		NpcCharacter added = roster.members().get(0);
		assertSame(added, roster.current());
		assertEquals(5, added.npcId());
		assertEquals(0, added.iconId());
		// CMD_AddNPC: control_morale = (morale >> 1) + Control.NPC_Base = 3 + 0x80.
		assertEquals(0x83, added.controlMorale());
		assertTrue(added.isNpc());
	}

	@Test
	public void moraleArgumentUsesByteArithmetic() {
		FakeRoster roster = new FakeRoster();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource().with(1, "X"));

		service.addNpc(1, 0xFF);

		// (0xFF >> 1) + 0x80 = 0x7F + 0x80 = 0xFF, still one byte.
		assertEquals(0xFF, roster.current().controlMorale());
	}

	@Test
	public void iconAssignmentTakesLowestFreeSlot() {
		FakeRoster roster = new FakeRoster();
		FakeCharacter a = pc("A");
		a.setIconId(0);
		FakeCharacter b = pc("B");
		b.setIconId(1);
		FakeCharacter c = pc("C");
		c.setIconId(3);
		roster.add(a);
		roster.add(b);
		roster.add(c);
		NpcPartyService service = new NpcPartyService(roster, new FakeSource().with(9, "GAP"));

		service.addNpc(9, 0);

		assertEquals(2, roster.current().iconId());
	}

	@Test
	public void partyFullRefusesLoadButStillClobbersSelectedMorale() {
		// Faithful COAB quirk: load_npc's size gate fails silently, and
		// CMD_AddNPC's morale assignment lands on the already-selected member.
		FakeRoster roster = new FakeRoster();
		for (int i = 0; i < NpcPartyService.MAX_PARTY_SIZE; i++) {
			roster.add(pc("PC" + i));
		}
		FakeCharacter selected = (FakeCharacter) roster.members().get(2);
		roster.setCurrent(selected);
		NpcPartyService service = new NpcPartyService(roster, new FakeSource().with(5, "TALON"));

		assertEquals(AddNpcResult.PARTY_FULL, service.addNpc(5, 6));

		assertEquals(NpcPartyService.MAX_PARTY_SIZE, roster.members().size());
		assertEquals(0x83, selected.controlMorale());
	}

	@Test
	public void seventhAndEighthMemberStillAdmittedNinthRefused() {
		// load_npc admits while party_size <= 7, so the roster tops out at 8.
		FakeRoster roster = new FakeRoster();
		for (int i = 0; i < 6; i++) {
			roster.add(pc("PC" + i));
		}
		FakeSource source = new FakeSource().with(1, "A").with(2, "B").with(3, "C");
		NpcPartyService service = new NpcPartyService(roster, source);

		assertEquals(AddNpcResult.ADDED, service.addNpc(1, 0));
		assertEquals(AddNpcResult.ADDED, service.addNpc(2, 0));
		assertEquals(AddNpcResult.PARTY_FULL, service.addNpc(3, 0));
		assertEquals(8, roster.members().size());
	}

	@Test
	public void missingRecordDoesNothing() {
		FakeRoster roster = new FakeRoster();
		FakeCharacter selected = pc("HERO");
		roster.add(selected);
		roster.setCurrent(selected);
		int moraleBefore = selected.controlMorale();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertEquals(AddNpcResult.RECORD_MISSING, service.addNpc(42, 6));

		assertEquals(1, roster.members().size());
		assertEquals(moraleBefore, selected.controlMorale());
	}

	@Test
	public void duplicateAddsArePermittedByLoadNpc() {
		// ovr017.load_npc has no duplicate check: the same id can join twice.
		FakeRoster roster = new FakeRoster();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource().with(5, "TALON"));

		assertEquals(AddNpcResult.ADDED, service.addNpc(5, 6));
		assertEquals(AddNpcResult.ADDED, service.addNpc(5, 6));

		assertEquals(2, roster.members().size());
		assertEquals(5, roster.members().get(0).npcId());
		assertEquals(5, roster.members().get(1).npcId());
		assertEquals(0, roster.members().get(0).iconId());
		assertEquals(1, roster.members().get(1).iconId());
	}

	@Test
	public void npcJoinTriggersClassBonusRecalcHook() {
		List<NpcCharacter> recalced = new ArrayList<>();
		NpcPartyHooks hooks = new NpcPartyHooks() {
			@Override
			public void recalcClassBonuses(NpcCharacter npc) {
				recalced.add(npc);
			}
		};
		FakeRoster roster = new FakeRoster();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource(), hooks);

		// AssignPlayerIconId only recalcs class bonuses for NPC-controlled members.
		FakeCharacter playerControlled = pc("HERO");
		service.assignIconIdAndJoin(playerControlled);
		assertTrue(recalced.isEmpty());

		FakeCharacter npcControlled = npc(5, "TALON");
		service.assignIconIdAndJoin(npcControlled);
		assertEquals(1, recalced.size());
		assertSame(npcControlled, recalced.get(0));
	}

	@Test
	public void findNpcMatchesTheModIdStamp() {
		FakeRoster roster = new FakeRoster();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource().with(5, "TALON"));
		service.addNpc(5, 6);
		roster.add(pc("HERO"));

		assertSame(roster.members().get(0), service.findNpc(5).orElseThrow());
		assertFalse(service.findNpc(6).isPresent());
	}

	@Test
	public void removeMiddleMemberReturnsPreviousNeighbor() {
		FakeRoster roster = new FakeRoster();
		FakeCharacter a = pc("A");
		FakeCharacter b = pc("B");
		FakeCharacter c = pc("C");
		roster.add(a);
		roster.add(b);
		roster.add(c);
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertSame(a, service.remove(b, false));
		assertEquals(List.of(a, c), roster.members());
	}

	@Test
	public void removeFirstMemberReturnsNewFirst() {
		FakeRoster roster = new FakeRoster();
		FakeCharacter a = pc("A");
		FakeCharacter b = pc("B");
		roster.add(a);
		roster.add(b);
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertSame(b, service.remove(a, false));
	}

	@Test
	public void removeLastRemainingMemberReturnsNull() {
		FakeRoster roster = new FakeRoster();
		FakeCharacter a = pc("A");
		roster.add(a);
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertNull(service.remove(a, false));
		assertTrue(roster.members().isEmpty());
	}

	@Test
	public void removeNonMemberDoesNothing() {
		FakeRoster roster = new FakeRoster();
		roster.add(pc("A"));
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertNull(service.remove(pc("STRANGER"), true));
		assertEquals(1, roster.members().size());
	}

	@Test
	public void removeCurrentSelectsNeighborAndReleasesIcon() {
		List<Integer> releasedIcons = new ArrayList<>();
		NpcPartyHooks hooks = new NpcPartyHooks() {
			@Override
			public void releaseIcon(int iconId) {
				releasedIcons.add(iconId);
			}
		};
		FakeRoster roster = new FakeRoster();
		FakeCharacter a = pc("A");
		a.setIconId(0);
		FakeCharacter b = npc(5, "TALON");
		b.setIconId(1);
		roster.add(a);
		roster.add(b);
		roster.setCurrent(b);
		NpcPartyService service = new NpcPartyService(roster, new FakeSource(), hooks);

		assertSame(a, service.removeCurrent());

		assertSame(a, roster.current());
		assertEquals(List.of(a), roster.members());
		assertEquals(List.of(1), releasedIcons);
	}

	@Test
	public void removeCurrentOnEmptyRosterYieldsNullCurrent() {
		FakeRoster roster = new FakeRoster();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertNull(service.removeCurrent());
		assertNull(roster.current());
	}

	@Test
	public void checkJoinRejectsNameAndIdDuplicates() {
		FakeRoster roster = new FakeRoster();
		roster.add(npc(5, "TALON"));
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertEquals(JoinCheck.DUPLICATE, service.checkJoin(npc(5, "TALON")));
		// Same name, different id -- not a duplicate; same id, different name -- not a duplicate.
		assertEquals(JoinCheck.OK, service.checkJoin(npc(6, "TALON")));
		assertEquals(JoinCheck.OK, service.checkJoin(npc(5, "IMPOSTOR")));
	}

	@Test
	public void checkJoinLimitsPlayerCharactersToSix() {
		FakeRoster roster = new FakeRoster();
		for (int i = 0; i < NpcPartyService.MAX_PLAYER_CHARACTERS; i++) {
			roster.add(pc("PC" + i));
		}
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertEquals(JoinCheck.PARTY_FULL, service.checkJoin(pc("SEVENTH")));
		// An NPC candidate is gated by total party size (8), not the PC limit.
		assertEquals(JoinCheck.OK, service.checkJoin(npc(5, "TALON")));
	}

	@Test
	public void checkJoinLimitsNpcCandidatesToTotalPartySize() {
		FakeRoster roster = new FakeRoster();
		for (int i = 0; i < NpcPartyService.MAX_PARTY_SIZE; i++) {
			roster.add(i < 6 ? pc("PC" + i) : npc(i, "NPC" + i));
		}
		NpcPartyService service = new NpcPartyService(roster, new FakeSource());

		assertEquals(JoinCheck.PARTY_FULL, service.checkJoin(npc(9, "NINTH")));
	}

	@Test
	public void checkJoinDefersToFlavorHook() {
		NpcPartyHooks refuseAll = new NpcPartyHooks() {
			@Override
			public boolean flavorPermitsJoin(NpcCharacter candidate, List<? extends NpcCharacter> members) {
				return false;
			}
		};
		FakeRoster roster = new FakeRoster();
		NpcPartyService service = new NpcPartyService(roster, new FakeSource(), refuseAll);

		assertEquals(JoinCheck.REFUSED_BY_RULESET, service.checkJoin(pc("HERO")));
	}
}
