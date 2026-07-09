package engine.rulesystem;

import java.util.List;
import java.util.OptionalInt;

import data.character.AbstractCharacter;

/** Default mechanics provider used until a title/ruleset supplies verified behavior. */
public final class UnresolvedGameMechanics implements GameMechanics {
	private static final OptionalInt UNRESOLVED = OptionalInt.empty();

	@Override public OptionalInt partyStrength(List<? extends AbstractCharacter> party, int mode) { return UNRESOLVED; }
	@Override public OptionalInt partyCheck(List<? extends AbstractCharacter> party, List<Integer> arguments) { return UNRESOLVED; }
	@Override public OptionalInt partySkillCheck(List<? extends AbstractCharacter> party, List<Integer> arguments) { return UNRESOLVED; }
	@Override public OptionalInt characterSkillCheck(AbstractCharacter character, List<Integer> arguments) { return UNRESOLVED; }
	@Override public OptionalInt encounterMovement(List<? extends AbstractCharacter> party, boolean maximum) { return UNRESOLVED; }
	@Override public OptionalInt findItem(List<? extends AbstractCharacter> party, int itemId) { return UNRESOLVED; }
	@Override public OptionalInt destroyItem(List<? extends AbstractCharacter> party, int itemId) { return UNRESOLVED; }
	@Override public OptionalInt hasEffect(AbstractCharacter character, int effectId) { return UNRESOLVED; }
	@Override public OptionalInt castSpell(AbstractCharacter character, List<Integer> arguments) { return UNRESOLVED; }
	@Override public OptionalInt giveExperience(List<? extends AbstractCharacter> party, int amount, int mode) { return UNRESOLVED; }
	@Override public OptionalInt executeGameOpcode(int opcode, List<Integer> arguments) { return UNRESOLVED; }
}
