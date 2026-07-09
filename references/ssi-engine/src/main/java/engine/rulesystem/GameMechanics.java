package engine.rulesystem;

import java.util.List;
import java.util.OptionalInt;

import data.character.AbstractCharacter;

/**
 * Universal boundary for Gold Box mechanics whose data layout and rules vary
 * by title. Empty results are intentional evidence boundaries, not successful
 * zero-valued checks.
 */
public interface GameMechanics {
	OptionalInt partyStrength(List<? extends AbstractCharacter> party, int mode);
	OptionalInt partyCheck(List<? extends AbstractCharacter> party, List<Integer> arguments);
	OptionalInt partySkillCheck(List<? extends AbstractCharacter> party, List<Integer> arguments);
	OptionalInt characterSkillCheck(AbstractCharacter character, List<Integer> arguments);
	OptionalInt encounterMovement(List<? extends AbstractCharacter> party, boolean maximum);
	OptionalInt findItem(List<? extends AbstractCharacter> party, int itemId);
	OptionalInt destroyItem(List<? extends AbstractCharacter> party, int itemId);
	OptionalInt hasEffect(AbstractCharacter character, int effectId);
	OptionalInt castSpell(AbstractCharacter character, List<Integer> arguments);
	OptionalInt giveExperience(List<? extends AbstractCharacter> party, int amount, int mode);
	OptionalInt executeGameOpcode(int opcode, List<Integer> arguments);
}
