package engine.combat;

import java.util.ArrayList;
import java.util.List;

import engine.combat.Combatant.Side;
import engine.combat.RecoveredBattlefieldGenerator.GeneratedBattlefield;
import engine.combat.RecoveredBattlefieldGenerator.Options;

/**
 * Converts ECL/VM combat encounter evidence into a stateful {@link CombatState}.
 *
 * <p>This is the neutral bridge layer between the script VM and the playable
 * combat renderer.  It does not depend on SSI Engine resource classes; callers
 * can provide small {@link MonsterSeed} records derived from ECL `LOAD_MON`
 * opcodes, MON0CHA resources, screenshots, or tests.</p>
 */
public final class CombatEncounterFactory {
	public static final class MonsterSeed {
		private final int sourceId;
		private final String name;
		private final int hitPoints;
		private final int armorClass;
		private final int thac0;
		private final int damageMin;
		private final int damageMax;
		private final int movement;
		private final String evidence;

		public MonsterSeed(int sourceId, String name, int hitPoints, int armorClass, int thac0, int damageMin, int damageMax,
			int movement, String evidence) {
			this.sourceId = sourceId;
			this.name = name == null || name.trim().isEmpty() ? "MONSTER " + sourceId : name.trim();
			this.hitPoints = Math.max(1, hitPoints);
			this.armorClass = Math.max(0, armorClass);
			this.thac0 = Math.max(1, thac0);
			this.damageMin = Math.max(1, damageMin);
			this.damageMax = Math.max(this.damageMin, damageMax);
			this.movement = Math.max(0, movement);
			this.evidence = evidence == null ? "" : evidence;
		}

		public static MonsterSeed ratwurst() {
			return new MonsterSeed(139, "RATWURST", 52, 4, 13, 4, 10, 5,
				"RATWURST HP/AC from supplied Matrix Cubed combat screenshot; combat formulas still unproven.");
		}

		public int sourceId() { return sourceId; }
		public String name() { return name; }
		public int hitPoints() { return hitPoints; }
		public int armorClass() { return armorClass; }
		public int thac0() { return thac0; }
		public int damageMin() { return damageMin; }
		public int damageMax() { return damageMax; }
		public int movement() { return movement; }
		public String evidence() { return evidence; }
	}

	public static final class PartySeed {
		private final int sourceId;
		private final String name;
		private final int hitPoints;
		private final int armorClass;
		private final int thac0;
		private final int damageMin;
		private final int damageMax;
		private final int movement;
		private final String evidence;

		public PartySeed(int sourceId, String name, int hitPoints, int armorClass, int thac0, int damageMin, int damageMax,
			int movement, String evidence) {
			this.sourceId = sourceId;
			this.name = name == null || name.trim().isEmpty() ? "PARTY " + sourceId : name.trim();
			this.hitPoints = Math.max(1, hitPoints);
			this.armorClass = Math.max(0, armorClass);
			this.thac0 = Math.max(1, thac0);
			this.damageMin = Math.max(1, damageMin);
			this.damageMax = Math.max(this.damageMin, damageMax);
			this.movement = Math.max(0, movement);
			this.evidence = evidence == null ? "" : evidence;
		}

		public int sourceId() { return sourceId; }
		public String name() { return name; }
		public int hitPoints() { return hitPoints; }
		public int armorClass() { return armorClass; }
		public int thac0() { return thac0; }
		public int damageMin() { return damageMin; }
		public int damageMax() { return damageMax; }
		public int movement() { return movement; }
		public String evidence() { return evidence; }
	}

	private static final CombatPosition[] PARTY_POSITIONS = {
		CombatPosition.of(16, 11),
		CombatPosition.of(14, 9),
		CombatPosition.of(16, 13),
		CombatPosition.of(18, 11),
		CombatPosition.of(15, 15),
		CombatPosition.of(18, 15)
	};

	private static final CombatPosition[] MONSTER_POSITIONS = {
		CombatPosition.of(11, 8),
		CombatPosition.of(11, 14),
		CombatPosition.of(20, 8),
		CombatPosition.of(20, 14),
		CombatPosition.of(10, 11),
		CombatPosition.of(21, 11),
		CombatPosition.of(8, 8),
		CombatPosition.of(23, 14)
	};

	public CombatState create(List<MonsterSeed> monsters) {
		return create(monsters, List.of());
	}

	public CombatState create(List<MonsterSeed> monsters, List<PartySeed> partySeeds) {
		return create(monsters, partySeeds, new Options());
	}

	public CombatState create(List<MonsterSeed> monsters, List<PartySeed> partySeeds, Options battlefieldOptions) {
		List<MonsterSeed> seeds = monsters == null || monsters.isEmpty() ? List.of(MonsterSeed.ratwurst()) : monsters;
		Options options = battlefieldOptions == null ? new Options() : battlefieldOptions;
		GeneratedBattlefield generated = new RecoveredBattlefieldGenerator().generate(options);
		List<Combatant> party = partyFromSeeds(partySeeds);
		if (party.isEmpty()) {
			party = defaultParty();
		}
		List<Combatant> enemy = new ArrayList<>();

		for (int i = 0; i < seeds.size(); i++) {
			MonsterSeed seed = seeds.get(i);
			CombatPosition position = MONSTER_POSITIONS[Math.floorMod(i, MONSTER_POSITIONS.length)];
			enemy.add(new Combatant(100 + i, seed.name(), Side.MONSTER, seed.hitPoints(), seed.armorClass(), seed.thac0(),
				seed.damageMin(), seed.damageMax(), seed.movement(), position,
				"ECL combat seed source=" + seed.sourceId() + ". " + seed.evidence()));
		}

		CombatState state = CombatState.fromRecoveredBattlefield(generated, party, enemy);
		state.addEvidence("CombatEncounterFactory: built CombatState from " + seeds.size() + " ECL/VM monster seed(s).");
		state.addEvidence("CombatEncounterFactory: battlefield terrain source " + generated.options().terrain.tileFile()
			+ " block " + generated.options().terrain.blockId() + ".");
		if (partySeeds != null && !partySeeds.isEmpty()) {
			state.addEvidence("CombatEncounterFactory: used " + party.size() + " VM party member seed(s); combat-only formulas remain scaffold values where the Java character decoder lacks exact fields.");
		}
		return state;
	}

	public List<Combatant> defaultParty() {
		List<Combatant> party = new ArrayList<>();
		for (int i = 0; i < PARTY_POSITIONS.length; i++) {
			party.add(Combatant.partyMember(i + 1, "CAR" + (i + 1), PARTY_POSITIONS[i]));
		}
		return party;
	}

	private List<Combatant> partyFromSeeds(List<PartySeed> partySeeds) {
		List<Combatant> party = new ArrayList<>();
		if (partySeeds == null) {
			return party;
		}
		for (int i = 0; i < partySeeds.size() && i < PARTY_POSITIONS.length; i++) {
			PartySeed seed = partySeeds.get(i);
			party.add(new Combatant(seed.sourceId(), seed.name(), Side.PARTY, seed.hitPoints(), seed.armorClass(),
				seed.thac0(), seed.damageMin(), seed.damageMax(), seed.movement(), PARTY_POSITIONS[i],
				"VM party seed source=" + seed.sourceId() + ". " + seed.evidence()));
		}
		return party;
	}
}
