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

	/**
	 * SURPRISE (ECL opcode 0x23, 4-argument form). COAB evidence:
	 * {@code ovr003.CMD_PartySurprise} / {@code CMD_Surprise} — encounter initiative
	 * state, not a UI-only flag (docs/coab-java-stub-audit.md). Matrix's opcode-0x23
	 * profile selects {@link #characterSkillCheck} (SKILL_CHECK) instead, so this
	 * method is universal plumbing for other titles, not yet exercised by Matrix.
	 */
	OptionalInt surprise(List<? extends AbstractCharacter> party, List<Integer> arguments);

	/**
	 * TREASURE / TREASURE_MULTICOIN / TREASURE_MULTICOIN4 (ECL opcode 0x27). COAB
	 * evidence: {@code ovr003.CMD_Treasure}, {@code ovr006} distribution,
	 * {@code MoneySet} — build a temporary treasure pool, then explicitly
	 * take/share/discard it (docs/coab-java-stub-audit.md). Universal stub; Matrix
	 * ITEM0/MON0ITM layout differs and is not yet decoded.
	 */
	OptionalInt treasure(List<? extends AbstractCharacter> party, List<Integer> arguments);

	/**
	 * ROB (ECL opcode 0x28). COAB evidence: {@code ovr008.RobMoney} /
	 * {@code RobItems} — money scaling and probabilistic item loss are separate
	 * operations (docs/coab-java-stub-audit.md). Universal stub; Matrix credit and
	 * item weight semantics need recovery.
	 */
	OptionalInt rob(List<? extends AbstractCharacter> party, List<Integer> arguments);

	/**
	 * DAMAGE (ECL opcode 0x2E). No dedicated COAB audit row exists yet; see
	 * docs/coab-java-stub-audit.md "Combat stubs" section, which notes attack/save/
	 * damage formulas remain explicitly unresolved pending DOS or GAME.OVR
	 * validation. Universal stub.
	 */
	OptionalInt damage(List<? extends AbstractCharacter> party, List<Integer> arguments);
}
