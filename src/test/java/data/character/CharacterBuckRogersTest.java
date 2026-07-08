package data.character;

import static character.buckrogers.AbilityScoreBuckRogers.CHARISMA;
import static character.buckrogers.AbilityScoreBuckRogers.CONSTITUTION;
import static character.buckrogers.AbilityScoreBuckRogers.DEXTERITY;
import static character.buckrogers.AbilityScoreBuckRogers.INTELLIGENCE;
import static character.buckrogers.AbilityScoreBuckRogers.STRENGTH;
import static character.buckrogers.AbilityScoreBuckRogers.TECH;
import static character.buckrogers.AbilityScoreBuckRogers.WISDOM;
import static character.buckrogers.CharacterClassBuckRogers.ROCKETJOCK;
import static character.CharacterGender.MALE;
import static character.buckrogers.CharacterRaceBuckRogers.TERRAN;
import static character.buckrogers.CharacterSkillBuckRogers.ASTROGATION;
import static character.buckrogers.CharacterSkillBuckRogers.BATTLE_TACTICS;
import static character.buckrogers.CharacterSkillBuckRogers.BEFRIEND_ANIMAL;
import static character.buckrogers.CharacterSkillBuckRogers.FAST_TALK_CONVINCE;
import static character.buckrogers.CharacterSkillBuckRogers.FIRST_AID;
import static character.buckrogers.CharacterSkillBuckRogers.MANEUVER_IN_ZERO_G;
import static character.buckrogers.CharacterSkillBuckRogers.NOTICE;
import static character.buckrogers.CharacterSkillBuckRogers.PILOT_ROCKET;
import static character.buckrogers.CharacterSkillBuckRogers.TREAT_CRITICAL_WOUNDS;
import static character.buckrogers.CharacterSkillBuckRogers.TREAT_LIGHT_WOUNDS;
import static character.buckrogers.CharacterSkillBuckRogers.TREAT_POISONING;
import static character.buckrogers.CharacterSkillBuckRogers.TREAT_SERIOUS_WOUNDS;
import static character.buckrogers.CharacterSkillBuckRogers.TREAT_STUN_PARALYSIS;
import static character.buckrogers.MoneyBuckRogers.CREDITS;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.file.Files;
import java.nio.file.Path;

import common.ByteBufferWrapper;
import data.ContentType;

import org.junit.Before;
import org.junit.Test;

public class CharacterBuckRogersTest {
	@Before
	public void setUp() {
		AbstractCharacter.configValues(CharacterValues.BUCK_ROGERS);
	}

	@Test
	public void readsPythonVerifiedWhoOffsetsFromSyntheticRecord() {
		byte[] data = new byte[259];
		writeName(data, "TST2");
		writeNaturalStats(data, 17, 14, 13, 14, 15, 13, 15);
		writeCurrentStats(data, 7, 8, 9, 10, 11, 12, 13);
		data[0x26] = (byte) MALE.getValue();
		data[0x27] = (byte) TERRAN.getValue();
		data[0x28] = (byte) ROCKETJOCK.ordinal();
		data[0x29] = 7;
		writeIntLE(data, 0x2B, 0x01020304);
		writeIntLE(data, 0x2F, 40000);
		data[0x38] = 24;
		data[0x39] = (byte) 0xFF;
		data[0x45] = 31;
		data[0x59] = 25;
		data[0x7F] = 85;
		data[0x98] = 12;
		data[0xE3] = 30;

		CharacterBuckRogers character = character(data);

		assertEquals("TST2", character.getName());
		assertEquals(TERRAN, character.getRace());
		assertTrue(character.getClassSelection().contains(ROCKETJOCK));
		assertEquals(7, character.getLevel(ROCKETJOCK));
		assertEquals(24, character.getAge());
		assertEquals(0x01020304, character.getMoneyValue(CREDITS));
		assertEquals(40000, character.getExperience());
		assertEquals(31, character.getNaturalHP());
		assertEquals(30, character.getCurrentHP());
		assertEquals(25, character.getSkillValue(FIRST_AID));
		assertEquals(85, character.getSkillValue(PILOT_ROCKET));
		assertEquals(12, character.getSkillValue(FAST_TALK_CONVINCE));
		assertEquals(0, character.getSkillValue(NOTICE));
		assertEquals(3, character.getSkills().size());
		assertTrue(character.getSkills().contains(FIRST_AID));
		assertTrue(character.getSkills().contains(PILOT_ROCKET));
		assertTrue(character.getSkills().contains(FAST_TALK_CONVINCE));

		assertEquals(17, character.getNaturalStatValue(STRENGTH));
		assertEquals(14, character.getNaturalStatValue(DEXTERITY));
		assertEquals(13, character.getNaturalStatValue(CONSTITUTION));
		assertEquals(14, character.getNaturalStatValue(INTELLIGENCE));
		assertEquals(15, character.getNaturalStatValue(WISDOM));
		assertEquals(13, character.getNaturalStatValue(CHARISMA));
		assertEquals(15, character.getNaturalStatValue(TECH));

		assertEquals(7, character.getCurrentStatValue(STRENGTH));
		assertEquals(8, character.getCurrentStatValue(DEXTERITY));
		assertEquals(9, character.getCurrentStatValue(CONSTITUTION));
		assertEquals(10, character.getCurrentStatValue(INTELLIGENCE));
		assertEquals(11, character.getCurrentStatValue(WISDOM));
		assertEquals(12, character.getCurrentStatValue(CHARISMA));
		assertEquals(13, character.getCurrentStatValue(TECH));

		assertEquals(0, character.getMovementRate());
		assertEquals(0, character.getTHACO());
	}

	@Test
	public void readsCapturedTst2WhoRecordConsistentlyWithPythonEvidence() {
		byte[] data = readProjectFile("generated/liveplay/first_map_capture/pre_saves/TST2.WHO");

		CharacterBuckRogers character = character(data);

		assertEquals("TST2", character.getName());
		assertEquals(TERRAN, character.getRace());
		assertTrue(character.getClassSelection().contains(ROCKETJOCK));
		assertEquals(7, character.getLevel(ROCKETJOCK));
		assertEquals(24, character.getAge());
		assertEquals(1000, character.getMoneyValue(CREDITS));
		assertEquals(40000, character.getExperience());
		assertEquals(31, character.getNaturalHP());
		assertEquals(31, character.getCurrentHP());
		assertEquals(25, character.getSkillValue(FIRST_AID));
		assertEquals(70, character.getSkillValue(ASTROGATION));
		assertEquals(85, character.getSkillValue(PILOT_ROCKET));
		assertEquals(85, character.getSkillValue(MANEUVER_IN_ZERO_G));
		assertEquals(40, character.getSkillValue(NOTICE));
		assertEquals(15, character.getSkills().size());
		assertEquals(17, character.getNaturalStatValue(STRENGTH));
		assertEquals(14, character.getNaturalStatValue(DEXTERITY));
		assertEquals(13, character.getNaturalStatValue(CONSTITUTION));
		assertEquals(14, character.getNaturalStatValue(INTELLIGENCE));
		assertEquals(15, character.getNaturalStatValue(WISDOM));
		assertEquals(13, character.getNaturalStatValue(CHARISMA));
		assertEquals(15, character.getNaturalStatValue(TECH));
		assertEquals(17, character.getCurrentStatValue(STRENGTH));
		assertEquals(14, character.getCurrentStatValue(DEXTERITY));
		assertEquals(13, character.getCurrentStatValue(CONSTITUTION));
		assertEquals(14, character.getCurrentStatValue(INTELLIGENCE));
		assertEquals(15, character.getCurrentStatValue(WISDOM));
		assertEquals(13, character.getCurrentStatValue(CHARISMA));
		assertEquals(15, character.getCurrentStatValue(TECH));
	}

	@Test
	public void readsCapturedMedicSkillSetFromCharacterRecord() {
		byte[] data = readProjectFile("generated/liveplay/first_map_capture/pre_saves/CHRDATA1.SAV");

		CharacterBuckRogers character = character(data);

		assertEquals("CAR1", character.getName());
		assertEquals(50, character.getSkillValue(TREAT_LIGHT_WOUNDS));
		assertEquals(40, character.getSkillValue(TREAT_SERIOUS_WOUNDS));
		assertEquals(75, character.getSkillValue(TREAT_CRITICAL_WOUNDS));
		assertEquals(40, character.getSkillValue(TREAT_POISONING));
		assertEquals(60, character.getSkillValue(TREAT_STUN_PARALYSIS));
		assertEquals(5, character.getSkillValue(BATTLE_TACTICS));
		assertEquals(80, character.getSkillValue(MANEUVER_IN_ZERO_G));
		assertEquals(55, character.getSkillValue(BEFRIEND_ANIMAL));
		assertEquals(9, character.getSkills().size());
		assertTrue(character.getSkills().contains(TREAT_LIGHT_WOUNDS));
		assertTrue(character.getSkills().contains(BEFRIEND_ANIMAL));
	}

	private CharacterBuckRogers character(byte[] data) {
		return new CharacterBuckRogers(new ByteBufferWrapper(ByteBuffer.wrap(data).order(ByteOrder.LITTLE_ENDIAN)), ContentType.MONCHA);
	}

	private byte[] readProjectFile(String projectRelativePath) {
		try {
			return Files.readAllBytes(Path.of("../..", projectRelativePath));
		} catch (java.io.IOException e) {
			throw new AssertionError("Unable to read project fixture " + projectRelativePath, e);
		}
	}

	private static void writeName(byte[] data, String name) {
		byte[] nameBytes = name.getBytes(java.nio.charset.StandardCharsets.US_ASCII);
		data[0] = (byte) nameBytes.length;
		System.arraycopy(nameBytes, 0, data, 1, nameBytes.length);
	}

	private static void writeNaturalStats(byte[] data, int str, int dex, int con, int intel, int wis, int cha, int tech) {
		writeStats(data, 0x10, str, dex, con, intel, wis, cha, tech);
	}

	private static void writeCurrentStats(byte[] data, int str, int dex, int con, int intel, int wis, int cha, int tech) {
		writeStats(data, 0x17, str, dex, con, intel, wis, cha, tech);
	}

	private static void writeStats(byte[] data, int offset, int str, int dex, int con, int intel, int wis, int cha, int tech) {
		data[offset] = (byte) str;
		data[offset + 1] = (byte) dex;
		data[offset + 2] = (byte) con;
		data[offset + 3] = (byte) intel;
		data[offset + 4] = (byte) wis;
		data[offset + 5] = (byte) cha;
		data[offset + 6] = (byte) tech;
	}

	private static void writeIntLE(byte[] data, int offset, int value) {
		data[offset] = (byte) value;
		data[offset + 1] = (byte) (value >>> 8);
		data[offset + 2] = (byte) (value >>> 16);
		data[offset + 3] = (byte) (value >>> 24);
	}
}
