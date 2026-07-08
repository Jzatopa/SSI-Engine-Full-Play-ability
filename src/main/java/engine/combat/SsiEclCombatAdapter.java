package engine.combat;

import java.util.ArrayList;
import java.util.List;

import character.AbilityScore;
import character.CharacterClass;
import character.Item;
import data.character.AbstractCharacter;
import data.character.BuckRogersEmbeddedItem;
import engine.character.CharacterSheetImpl;

/**
 * SSI Engine adapter that converts queued `LOAD_MON` character resources into
 * neutral {@link CombatEncounterFactory.MonsterSeed} records.
 */
public final class SsiEclCombatAdapter {
	private final EclCombatBridge bridge;
	private final OriginalItemCombatTable itemCombatTable;

	public SsiEclCombatAdapter() {
		this(new EclCombatBridge());
	}

	public SsiEclCombatAdapter(EclCombatBridge bridge) {
		this(bridge, null);
	}

	public SsiEclCombatAdapter(EclCombatBridge bridge, OriginalItemCombatTable itemCombatTable) {
		this.bridge = bridge;
		this.itemCombatTable = itemCombatTable;
	}

	public EclCombatBridge bridge() {
		return bridge;
	}

	public EclCombatBridge.EclCombatResult resolveQueued(List<AbstractCharacter> monsters) {
		return resolveQueued(monsters, List.of());
	}

	public EclCombatBridge.EclCombatResult resolveQueued(List<AbstractCharacter> monsters, List<CharacterSheetImpl> partyMembers) {
		List<CombatEncounterFactory.MonsterSeed> seeds = new ArrayList<>();
		int fallbackId = 1;
		for (AbstractCharacter monster : monsters) {
			seeds.add(toSeed(fallbackId++, monster));
		}
		List<CombatEncounterFactory.PartySeed> partySeeds = new ArrayList<>();
		int partyId = 1;
		for (CharacterSheetImpl member : partyMembers == null ? List.<CharacterSheetImpl>of() : partyMembers) {
			partySeeds.add(toPartySeed(partyId++, member));
		}
		return bridge.resolve(seeds, partySeeds);
	}

	public CombatEncounterFactory.MonsterSeed toSeed(int sourceId, AbstractCharacter monster) {
		if (monster == null) {
			return CombatEncounterFactory.MonsterSeed.ratwurst();
		}
		String name = monster.getName();
		if (name == null || name.trim().isEmpty()) {
			name = "MONSTER " + sourceId;
		}
		int hp = Math.max(1, monster.getNaturalHP());
		int dex = stat(monster, "DEX");
		int str = stat(monster, "STR");
		int level = Math.max(1, level(monster));
		int ac = Math.max(0, Math.min(20, 10 - ((dex - 10) / 2)));
		int thac0 = Math.max(5, 21 - level);
		int damageMin = Math.max(1, str / 6);
		int damageMax = Math.max(damageMin, damageMin + Math.max(1, str / 3));
		int movement = Math.max(4, Math.min(12, monster.getMovementRate()));
		return new CombatEncounterFactory.MonsterSeed(sourceId, name, hp, ac, thac0, damageMin, damageMax, movement,
			"Derived from queued SSI Engine AbstractCharacter/MONCHA resource. " + inventoryEvidence(monster)
				+ " Exact title-specific combat formulas remain pending.");
	}

	public CombatEncounterFactory.PartySeed toPartySeed(int sourceId, CharacterSheetImpl member) {
		if (member == null || member.getCharacter() == null) {
			return new CombatEncounterFactory.PartySeed(sourceId, "PARTY " + sourceId, 38, 4, 14, 6, 12, 6,
				"Fallback party seed; no decoded CharacterSheetImpl was available.");
		}
		AbstractCharacter character = member.getCharacter();
		String name = character.getName();
		if (name == null || name.trim().isEmpty()) {
			name = member.getName().toString();
		}
		int hp = Math.max(1, character.getCurrentHP() > 0 ? character.getCurrentHP() : character.getNaturalHP());
		int dex = stat(character, "DEX");
		int str = stat(character, "STR");
		int level = Math.max(1, level(character));
		int ac = Math.max(0, Math.min(20, 10 - ((dex - 10) / 2)));
		int thac0 = Math.max(5, 21 - level);
		int damageMin = Math.max(1, str / 6);
		int damageMax = Math.max(damageMin, damageMin + Math.max(1, str / 3));
		int movement = Math.max(4, Math.min(12, character.getMovementRate()));
		return new CombatEncounterFactory.PartySeed(sourceId, name, hp, ac, thac0, damageMin, damageMax, movement,
			"Derived from VM party CharacterSheetImpl/AbstractCharacter. Exact title-specific combat formulas remain pending.");
	}

	private int stat(AbstractCharacter character, String abbreviation) {
		try {
			for (AbilityScore stat : character.getAbilityScoreTypes()) {
				if (abbreviation.equalsIgnoreCase(stat.getName().toString())) {
					return Math.max(1, character.getCurrentStatValue(stat));
				}
			}
		} catch (RuntimeException ex) {
			// Preserve the neutral scaffold value until this title's record is decoded.
		}
		return 10;
	}

	private String inventoryEvidence(AbstractCharacter character) {
		List<String> recovered = new ArrayList<>();
		List<BuckRogersEmbeddedItem> embeddedItems = new ArrayList<>();
		for (Item item : character.getItems()) {
			if (item instanceof BuckRogersEmbeddedItem embedded) {
				embeddedItems.add(embedded);
				recovered.add("template " + embedded.templateIndex() + " itemptr " + embedded.itemPointer()
					+ " equipped " + embedded.isEquipped() + " quantity " + embedded.quantity());
			}
		}
		if (recovered.isEmpty()) {
			return character instanceof data.character.CharacterBuckRogers
				? "No stable-field ITEM0 match recovered from its MON0ITM records; this does not prove empty inventory."
				: "No title-specific inventory evidence is attached to this character.";
		}
		String optionEvidence = itemCombatTable == null ? ""
			: " " + new RecoveredItemOptionSelector(itemCombatTable).evidenceSummary(embeddedItems);
		return "Recovered MON0ITM/ITEM0 item(s): " + String.join(", ", recovered)
			+ "; equipped bit and quantity come from original GAME.OVR record accessors." + optionEvidence;
	}

	private int level(AbstractCharacter monster) {
		try {
			return monster.getClassSelection().map(monster::getLevel).max().getOrElse(1);
		} catch (RuntimeException ex) {
			return 1;
		}
	}
}
