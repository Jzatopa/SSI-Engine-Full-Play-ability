package engine.rulesystem;

import static character.buckrogers.CharacterSkillBuckRogers.FAST_TALK_CONVINCE;
import static character.buckrogers.CharacterSkillBuckRogers.FIRST_AID;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.List;
import java.util.OptionalInt;

import org.junit.Before;
import org.junit.Test;

import character.buckrogers.CharacterStatusBuckRogers;
import common.ByteBufferWrapper;
import data.ContentType;
import data.character.AbstractCharacter;
import data.character.CharacterBuckRogers;
import data.character.CharacterValues;

/**
 * Conformance tests for the Lane 1 Matrix mechanics (GIVE_EXP, SKILL_CHECK,
 * PARTY_SKILL_CHECK3) against the evidence trail documented in
 * {@link MatrixGameMechanics}'s class javadoc. These pin the CANDIDATE
 * behaviors chosen there (result encoding, eligibility filter, best-member
 * selection) so a future change to those choices is a deliberate,
 * test-visible decision rather than a silent regression.
 */
public class MatrixGameMechanicsTest {
	private static final int WHO_SKILL_BASE = 0x4C;
	private static final int STATUS_OFFSET = 0xD4;
	private static final int RECORD_SIZE = 259;

	@Before
	public void setUp() {
		AbstractCharacter.configValues(CharacterValues.BUCK_ROGERS);
	}

	@Test
	public void giveExperienceAppliesAmountToEveryEligibleMember() {
		CharacterBuckRogers alive = character(builder().build());
		CharacterBuckRogers dead = character(builder().status(CharacterStatusBuckRogers.DEAD).build());
		MatrixGameMechanics mechanics = new MatrixGameMechanics();

		OptionalInt result = mechanics.giveExperience(List.of(alive, dead), 5000, 0);

		assertEquals(OptionalInt.of(5000), result);
		assertEquals(5000, alive.getExperience());
		assertEquals(0, dead.getExperience());
	}

	@Test
	public void giveExperienceIsNoOpOnEmptyPartyOrZeroAmount() {
		MatrixGameMechanics mechanics = new MatrixGameMechanics();
		CharacterBuckRogers alive = character(builder().build());

		assertEquals(OptionalInt.empty(), mechanics.giveExperience(List.of(), 1000, 0));
		assertEquals(OptionalInt.empty(), mechanics.giveExperience(List.of(alive), 0, 0));
		assertEquals(0, alive.getExperience());
	}

	@Test
	public void giveExperienceIsNoOpWhenEveryMemberIsIneligible() {
		CharacterBuckRogers dead = character(builder().status(CharacterStatusBuckRogers.DEAD).build());
		MatrixGameMechanics mechanics = new MatrixGameMechanics();

		assertEquals(OptionalInt.empty(), mechanics.giveExperience(List.of(dead), 1000, 0));
	}

	@Test
	public void characterSkillCheckSucceedsWhenRollIsAtOrUnderSkillValue() {
		CharacterBuckRogers character = character(builder().skill(FIRST_AID, 50).build());
		// d100 supplier returns roll-1 (rollSkillCheck adds 1), so this yields roll=50.
		MatrixGameMechanics mechanics = new MatrixGameMechanics(() -> 49);

		OptionalInt result = mechanics.characterSkillCheck(character, List.of(FIRST_AID.getSkillId(), 1));

		assertEquals(OptionalInt.of(2), result);
	}

	@Test
	public void characterSkillCheckFailsWhenRollExceedsSkillValue() {
		CharacterBuckRogers character = character(builder().skill(FIRST_AID, 50).build());
		// roll=51 > skill=50.
		MatrixGameMechanics mechanics = new MatrixGameMechanics(() -> 50);

		OptionalInt result = mechanics.characterSkillCheck(character, List.of(FIRST_AID.getSkillId(), 1));

		assertEquals(OptionalInt.of(0), result);
	}

	@Test
	public void characterSkillCheckIsEmptyForUnknownSkillId() {
		CharacterBuckRogers character = character(builder().skill(FIRST_AID, 50).build());
		MatrixGameMechanics mechanics = new MatrixGameMechanics(() -> 0);

		assertEquals(OptionalInt.empty(), mechanics.characterSkillCheck(character, List.of(0xFF, 1)));
	}

	@Test
	public void partySkillCheckRollsAgainstTheHighestEligibleSkillValue() {
		CharacterBuckRogers weak = character(builder().skill(FAST_TALK_CONVINCE, 10).build());
		CharacterBuckRogers strong = character(builder().skill(FAST_TALK_CONVINCE, 90).build());
		CharacterBuckRogers deadButStronger = character(
			builder().skill(FAST_TALK_CONVINCE, 99).status(CharacterStatusBuckRogers.DEAD).build());
		// roll=50: fails against weak(10) and would fail if selection ignored eligibility
		// and picked the dead member's 99, but succeeds against strong(90).
		MatrixGameMechanics mechanics = new MatrixGameMechanics(() -> 49);

		OptionalInt result = mechanics.partySkillCheck(List.of(weak, strong, deadButStronger),
			List.of(FAST_TALK_CONVINCE.getSkillId(), 1));

		assertEquals(OptionalInt.of(2), result);
	}

	@Test
	public void partySkillCheckIsEmptyWhenNoMemberIsEligible() {
		CharacterBuckRogers dead = character(builder().skill(FAST_TALK_CONVINCE, 90).status(CharacterStatusBuckRogers.DEAD).build());
		MatrixGameMechanics mechanics = new MatrixGameMechanics(() -> 0);

		assertEquals(OptionalInt.empty(), mechanics.partySkillCheck(List.of(dead), List.of(FAST_TALK_CONVINCE.getSkillId(), 1)));
	}

	@Test
	public void unmappedOpcodesDelegateToUnresolvedGameMechanics() {
		MatrixGameMechanics mechanics = new MatrixGameMechanics();

		assertFalse(mechanics.treasure(List.of(), List.of()).isPresent());
		assertFalse(mechanics.damage(List.of(), List.of()).isPresent());
		assertFalse(mechanics.rob(List.of(), List.of()).isPresent());
	}

	private static Builder builder() {
		return new Builder();
	}

	private static CharacterBuckRogers character(byte[] data) {
		return new CharacterBuckRogers(new ByteBufferWrapper(ByteBuffer.wrap(data).order(ByteOrder.LITTLE_ENDIAN)), ContentType.MONCHA);
	}

	/** Builds a minimal synthetic .WHO-shaped record for these tests only. */
	private static final class Builder {
		private final byte[] data = new byte[RECORD_SIZE];

		Builder status(CharacterStatusBuckRogers status) {
			data[STATUS_OFFSET] = (byte) status.ordinal();
			return this;
		}

		Builder skill(character.buckrogers.CharacterSkillBuckRogers skill, int value) {
			data[WHO_SKILL_BASE + skill.getSkillId()] = (byte) value;
			return this;
		}

		byte[] build() {
			return data;
		}
	}
}
