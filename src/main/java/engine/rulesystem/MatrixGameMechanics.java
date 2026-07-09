package engine.rulesystem;

import java.util.List;
import java.util.OptionalInt;
import java.util.Random;
import java.util.function.IntSupplier;

import character.CharacterStatus;
import character.buckrogers.CharacterSkillBuckRogers;
import character.buckrogers.CharacterStatusBuckRogers;
import data.character.AbstractCharacter;
import data.character.CharacterBuckRogers;

/**
 * Buck Rogers: Matrix Cubed mechanics provider. Implements the two Lane 1
 * playthrough blockers measured by {@code MatrixCubedPlaythroughProber}
 * (see docs/engine-completion-plan-2026-07-09.md section 4): GIVE_EXP
 * (opcode 0x41, 96 hits/26 blocks) and SKILL_CHECK/PARTY_SKILL_CHECK3
 * (opcode 0x23/0x22 dual-arity family, 70 hits/22 blocks + 46 hits/19
 * blocks).
 *
 * <h2>Why this is not a COAB port</h2>
 * COAB's own ECL command table ({@code ovr003.SetupCommandTable}, checked
 * at repo {@code ~/.local/opt/coab}, commit tree as of 2026-07-09) stops at
 * opcode {@code 0x40} ("DESTROY ITEMS") — Curse of the Azure Bonds has no
 * ECL-level GIVE_EXP or SKILL_CHECK command at all; AD&D XP is awarded by
 * the post-combat routine {@code ovr006.addExp(int)} outside the ECL
 * interpreter, and COAB has no percentage-based skill system. There is
 * therefore no COAB opcode handler to port for either mechanic; what COAB
 * *does* supply and what this class borrows:
 * <ul>
 * <li>{@code ovr006.addExp(int exp_to_add)} (ovr006.cs:141-142): loops the
 * party and does {@code player.exp += exp_to_add} — the same amount to
 * every eligible member, no further division (division into a per-member
 * share already happened earlier, in {@code calc_battle_exp}). Ported here
 * as "apply the ECL-supplied amount to every eligible party member",
 * documented as the closest COAB analog rather than an exact port.</li>
 * <li>{@code ovr008.RobItems} (ovr008.cs:1352-1365):
 * {@code ovr024.roll_dice(100, 1) <= chance} — the universal Gold Box
 * roll-under-percentage idiom used for any probabilistic check in this
 * codebase. Ported here as the SKILL_CHECK/PARTY_SKILL_CHECK3 roll flow
 * (d100 roll-under the character's skill percentage), since COAB has no
 * skill-check opcode of its own to borrow a formula from.</li>
 * </ul>
 *
 * <h2>Matrix ECL evidence</h2>
 * All argument-shape and dest-arg claims below were confirmed by
 * disassembling real Matrix Cubed ECL blocks with the profile-aware
 * {@code engine.debug.Disassembler} (Matrix's
 * {@code opcode.22=PARTY_SKILL_CHECK3} / {@code opcode.23=SKILL_CHECK}
 * mapping from {@code Buck Rogers - Matrix Cubed.properties}), not by
 * analogy alone:
 * <ul>
 * <li>ECL17 0x893D: {@code SKILL_CHECK(0:76, 1:0x7F79, 1:0x7F7A)} followed
 * immediately by {@code COMPARE(0x7F7A, 0:2); IF_LESS() -> fail-branch} —
 * confirms arg index 2 is the destination write slot and that the ECL
 * author's convention is "result &gt;= 2 succeeds". Skill id 76 (0x4C) is
 * {@link CharacterSkillBuckRogers#FAST_TALK_CONVINCE}; the surrounding text
 * ("QUESTION THEM?" / on success "THEY AGREE TO TALK.") is thematically
 * consistent.</li>
 * <li>ECL17 0xA19D: {@code PARTY_SKILL_CHECK3(0:83, 1:0x7F7B, 1:0x7F7C)}
 * followed by the identical {@code COMPARE(dest, 0:2); IF_LESS()} pattern —
 * same arg shape and dest convention as SKILL_CHECK.</li>
 * <li>ECL1 0x8743/0x8806 (an in-game QA test menu, "WHICH FUNCTION DO YOU
 * WISH TO TEST?" -&gt; "SKILL"): both opcodes called with
 * {@code (skillId, flag, dest)} where the flag slot is set from the answer
 * to "CHECK ONLY A SINGLE PERSON?" (1 = single, then a WHO prompt; 0 =
 * whole party, no WHO). This is the basis for treating arg index 1 as an
 * individual-vs-party scope flag, not a character index -- CANDIDATE, see
 * below.</li>
 * <li>ECL17 0x86B1/0x8951/0x990F/etc and ECL1 0x8578: GIVE_EXP's two
 * arguments are consistently (small literal 0/1, an amount -- either a
 * literal like 1000/5000/30000 or, in the ECL1 QA menu, a variable filled
 * by "HOW MANY EXPERIENCE POINTS FOR THE PARTY?"). This is arg index 0 =
 * mode flag, arg index 1 = amount -- the reverse of the order the
 * {@code GIVE_EXP} argument names in {@link GameMechanics#giveExperience}
 * suggested; {@code VirtualMachine}'s GIVE_EXP dispatch was corrected to
 * pass arguments in this evidenced order.</li>
 * </ul>
 *
 * <h2>Candidate / unresolved items (do not treat as confirmed)</h2>
 * <ul>
 * <li>The exact numeric encoding of the SKILL_CHECK/PARTY_SKILL_CHECK3
 * result is CANDIDATE beyond the evidenced "&gt;=2 means success" boundary:
 * this implementation writes {@code 2} on success and {@code 0} on
 * failure, the smallest values consistent with every observed compare.
 * Whether the real engine ever produces other values (e.g. a
 * margin-of-success scale) is unresolved.</li>
 * <li>The flag argument's effect on the roll is CANDIDATE. Every real
 * callsite examined sets it to a literal {@code 1}; this implementation
 * currently ignores its value (both opcodes always resolve a single
 * character's skill), which is consistent with all inspected evidence but
 * not proven for flag=0.</li>
 * <li>GIVE_EXP's mode argument (observed values: 0, 1 only) is UNRESOLVED:
 * no callsite branches on it and COAB has no analogous opcode to consult,
 * so both observed values currently behave identically (full amount to
 * every eligible party member). This is a deliberate no-op distinction,
 * not a fabricated formula.</li>
 * <li>Level-up processing (career/level tables) is explicitly out of scope
 * for this slice; {@link #giveExperience} only mutates the raw
 * {@code EXP} value via {@link AbstractCharacter#addExperience(int)}.</li>
 * </ul>
 */
public final class MatrixGameMechanics implements GameMechanics {
	/**
	 * Matrix ECL convention observed at every inspected SKILL_CHECK/
	 * PARTY_SKILL_CHECK3 callsite: dest >= 2 succeeds. Success is encoded as
	 * exactly this boundary value; see class javadoc "candidate" section.
	 */
	private static final int SUCCESS_RESULT = 2;
	private static final int FAILURE_RESULT = 0;

	private final UnresolvedGameMechanics unresolved = new UnresolvedGameMechanics();
	private final IntSupplier d100;

	public MatrixGameMechanics() {
		this(new Random()::nextInt);
	}

	/** @param d100 supplies a roll in [0,100); injected for deterministic tests. */
	public MatrixGameMechanics(IntSupplier d100) {
		this.d100 = d100;
	}

	@Override
	public OptionalInt giveExperience(List<? extends AbstractCharacter> party, int amount, int mode) {
		if (party.isEmpty() || amount == 0) {
			return OptionalInt.empty();
		}
		boolean appliedAny = false;
		for (AbstractCharacter character : party) {
			if (!isEligibleForExperience(character)) {
				continue;
			}
			character.addExperience(amount);
			appliedAny = true;
		}
		return appliedAny ? OptionalInt.of(amount) : OptionalInt.empty();
	}

	/**
	 * Candidate filter: mirrors COAB's {@code ovr006.addExp} eligibility test
	 * (in_combat &amp;&amp; health_status != animated) as closely as Matrix's
	 * different status enum allows. Matrix has no "animated" status; DEAD,
	 * GONE and NOT_HERE are excluded as the closest analog.
	 */
	private boolean isEligibleForExperience(AbstractCharacter character) {
		CharacterStatus status = character.getStatus();
		return status != CharacterStatusBuckRogers.DEAD //
			&& status != CharacterStatusBuckRogers.GONE //
			&& status != CharacterStatusBuckRogers.NOT_HERE;
	}

	@Override
	public OptionalInt characterSkillCheck(AbstractCharacter character, List<Integer> arguments) {
		if (!(character instanceof CharacterBuckRogers buckCharacter) || arguments.size() < 1) {
			return OptionalInt.empty();
		}
		int skillId = arguments.get(0);
		return resolveSkill(skillId).map(skill -> rollSkillCheck(buckCharacter.getSkillValue(skill)))
			.map(OptionalInt::of).orElse(OptionalInt.empty());
	}

	/**
	 * PARTY_SKILL_CHECK3: best-eligible-member selection (per plan section 4
	 * step 3 / task instructions) -- picks the party member with the highest
	 * raw skill value for the requested skill id, then applies the same
	 * roll-under-percentage flow used by {@link #characterSkillCheck}.
	 * CANDIDATE: "best eligible" is read as "highest skill byte", not
	 * "already-passing member" or "lowest-index member"; no COAB opcode or
	 * Matrix evidence proves the selection rule beyond the opcode's PARTY
	 * naming.
	 */
	@Override
	public OptionalInt partySkillCheck(List<? extends AbstractCharacter> party, List<Integer> arguments) {
		if (party.isEmpty() || arguments.isEmpty()) {
			return OptionalInt.empty();
		}
		int skillId = arguments.get(0);
		var skill = resolveSkill(skillId);
		if (skill.isEmpty()) {
			return OptionalInt.empty();
		}

		CharacterBuckRogers best = null;
		int bestValue = -1;
		for (AbstractCharacter character : party) {
			if (!(character instanceof CharacterBuckRogers buckCharacter) || !isEligibleForExperience(character)) {
				continue;
			}
			int value = buckCharacter.getSkillValue(skill.get());
			if (value > bestValue) {
				bestValue = value;
				best = buckCharacter;
			}
		}
		if (best == null) {
			return OptionalInt.empty();
		}
		return OptionalInt.of(rollSkillCheck(bestValue));
	}

	/**
	 * COAB flow analog: {@code ovr008.RobItems} (ovr008.cs:1362) resolves a
	 * probability with {@code ovr024.roll_dice(100, 1) <= chance}. Applied
	 * here with the character's raw .WHO skill byte (0-99-style percentage,
	 * see {@code data/character/CharacterBuckRogers#getSkillValue}) standing
	 * in for {@code chance}. Result encoding is CANDIDATE -- see class
	 * javadoc.
	 */
	private int rollSkillCheck(int skillValue) {
		int roll = 1 + Math.floorMod(d100.getAsInt(), 100); // 1..100, matching COAB's roll_dice(100, 1)
		boolean success = roll <= skillValue;
		return success ? SUCCESS_RESULT : FAILURE_RESULT;
	}

	private static java.util.Optional<CharacterSkillBuckRogers> resolveSkill(int skillId) {
		for (CharacterSkillBuckRogers skill : CharacterSkillBuckRogers.values()) {
			if (skill.getSkillId() == skillId) {
				return java.util.Optional.of(skill);
			}
		}
		return java.util.Optional.empty();
	}

	// Everything below this line is out of scope for this slice (Lane 1 GIVE_EXP /
	// SKILL_CHECK only); delegate to UnresolvedGameMechanics rather than fabricate.

	@Override
	public OptionalInt partyStrength(List<? extends AbstractCharacter> party, int mode) {
		return unresolved.partyStrength(party, mode);
	}

	@Override
	public OptionalInt partyCheck(List<? extends AbstractCharacter> party, List<Integer> arguments) {
		return unresolved.partyCheck(party, arguments);
	}

	@Override
	public OptionalInt encounterMovement(List<? extends AbstractCharacter> party, boolean maximum) {
		return unresolved.encounterMovement(party, maximum);
	}

	@Override
	public OptionalInt findItem(List<? extends AbstractCharacter> party, int itemId) {
		return unresolved.findItem(party, itemId);
	}

	@Override
	public OptionalInt destroyItem(List<? extends AbstractCharacter> party, int itemId) {
		return unresolved.destroyItem(party, itemId);
	}

	@Override
	public OptionalInt hasEffect(AbstractCharacter character, int effectId) {
		return unresolved.hasEffect(character, effectId);
	}

	@Override
	public OptionalInt castSpell(AbstractCharacter character, List<Integer> arguments) {
		return unresolved.castSpell(character, arguments);
	}

	@Override
	public OptionalInt executeGameOpcode(int opcode, List<Integer> arguments) {
		return unresolved.executeGameOpcode(opcode, arguments);
	}

	@Override
	public OptionalInt surprise(List<? extends AbstractCharacter> party, List<Integer> arguments) {
		return unresolved.surprise(party, arguments);
	}

	@Override
	public OptionalInt treasure(List<? extends AbstractCharacter> party, List<Integer> arguments) {
		return unresolved.treasure(party, arguments);
	}

	@Override
	public OptionalInt rob(List<? extends AbstractCharacter> party, List<Integer> arguments) {
		return unresolved.rob(party, arguments);
	}

	@Override
	public OptionalInt damage(List<? extends AbstractCharacter> party, List<Integer> arguments) {
		return unresolved.damage(party, arguments);
	}
}
