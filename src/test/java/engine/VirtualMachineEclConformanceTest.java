package engine;

import static character.CharacterGender.MALE;
import static character.buckrogers.CharacterClassBuckRogers.WARRIOR;
import static character.buckrogers.CharacterRaceBuckRogers.TERRAN;
import static data.character.CharacterValues.BUCK_ROGERS;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;

import java.io.File;
import java.util.List;
import java.util.OptionalInt;

import org.junit.Assume;
import org.junit.Before;
import org.junit.Test;

import character.ClassSelection;
import common.FileMap;
import common.ByteBufferWrapper;
import data.ContentFile;
import data.ContentType;
import data.Resource;
import data.character.AbstractCharacter;
import data.character.CharacterBuckRogers;
import data.script.EclProgram;
import engine.character.CharacterSheetImpl;
import engine.rulesystem.GameMechanics;
import engine.rulesystem.UnresolvedGameMechanics;
import engine.script.EclInstruction;
import engine.script.EclOpCode;
import engine.time.GameClock;
import io.vavr.collection.HashMap;

public class VirtualMachineEclConformanceTest {
	private CharacterBuckRogers monster;

	@Before
	public void configureCharacterFormat() {
		AbstractCharacter.configValues(BUCK_ROGERS);
		monster = new CharacterBuckRogers(TERRAN, MALE, ClassSelection.of(WARRIOR));
	}

	@Test
	public void loadMonsterQueuesTheRequestedCopies() {
		VirtualMachine vm = vm();

		assertEquals(10, vm.queueMonsterCopies(11, 10));
		assertEquals(10, vm.queuedMonsterCount());
	}

	@Test
	public void loadMonsterNormalizesZeroCopiesToOne() {
		VirtualMachine vm = vm();

		assertEquals(1, vm.queueMonsterCopies(11, 0));
		assertEquals(1, vm.queuedMonsterCount());
	}

	@Test
	public void loadMonsterHonorsTheOriginalSixtyThreeMonsterBound() {
		VirtualMachine vm = vm();

		assertEquals(63, vm.queueMonsterCopies(11, 100));
		assertEquals(0, vm.queueMonsterCopies(11, 1));
		assertEquals(63, vm.queuedMonsterCount());
	}

	@Test
	public void localMatrixEclBlock38RequestsTenMonsterCopies() throws Exception {
		File eclFile = new File(
			"/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/ECL1.DAX");
		Assume.assumeTrue(eclFile.isFile());
		EclInstruction.configOpCodes(HashMap.of(0x0B, EclOpCode.LOAD_MON));
		EclProgram program = ContentFile.create(eclFile).get()
			.getById(38, EclProgram.class, ContentType.ECL).get();
		ByteBufferWrapper code = program.getCode().duplicate().position(0x9754 - 0x8000);

		EclInstruction instruction = EclInstruction.parseNext(code);

		assertEquals(EclOpCode.LOAD_MON, instruction.getOpCode());
		assertEquals(11, instruction.getArgument(0).valueAsInt());
		assertEquals(10, instruction.getArgument(1).valueAsInt());
		assertEquals(11, instruction.getArgument(2).valueAsInt());
	}

	@Test
	public void clock2OpcodeStepsCoabBackedClockWords() throws Exception {
		EngineConfiguration cfg = localMatrixConfig();
		VirtualMemory memory = new VirtualMemory(cfg);
		memory.setClockSlot(GameClock.SLOT_MINUTES_ONES, 8);
		memory.writeMemInt(VirtualMemory.MEMLOC_CLOCK_START + GameClock.SLOT_MINUTES_ONES, 9, false);
		assertEquals(9, memory.getClockSlot(GameClock.SLOT_MINUTES_ONES));
		assertEquals(9, memory.readMemInt(new engine.script.EclArgument(1, 3,
			VirtualMemory.MEMLOC_CLOCK_START + GameClock.SLOT_MINUTES_ONES)));
		memory.setClockSlot(GameClock.SLOT_MINUTES_ONES, 8);

		EclInstruction.configOpCodes(HashMap.of(0x00, EclOpCode.EXIT, 0x01, EclOpCode.GOTO,
			0x34, EclOpCode.CLOCK2));
		VirtualMachine vm = new VirtualMachine(null, memory, cfg.getCodeBase());
		vm.newEcl(clock2Program(cfg.getCodeBase(), 5, GameClock.SLOT_MINUTES_ONES));

		vm.startInit();

		assertEquals(3, memory.getClockSlot(GameClock.SLOT_MINUTES_ONES));
		assertEquals(1, memory.getClockSlot(GameClock.SLOT_MINUTES_TENS));
	}

	@Test
	public void unusedOpcodesDispatchAsSafeNoOpsInsteadOfThrowing() throws Exception {
		// UNUSED_1F/UNUSED_42 previously had no IMPL entry at all, so dispatch fell
		// through to IMPL.get(...).get() and threw NoSuchElementException (a live
		// crash risk for Curse/Krynn/Pool profiles that select this opcode form).
		EngineConfiguration cfg = localMatrixConfig();
		VirtualMemory memory = new VirtualMemory(cfg);
		EclInstruction.configOpCodes(HashMap.of( //
			0x00, EclOpCode.EXIT, //
			0x01, EclOpCode.GOTO, //
			0x1F, EclOpCode.UNUSED_1F, //
			0x42, EclOpCode.UNUSED_42));
		VirtualMachine vm = new VirtualMachine(null, memory, cfg.getCodeBase());

		vm.newEcl(unusedOpcodesProgram(cfg.getCodeBase()));

		vm.startInit(); // must not throw NoSuchElementException
	}

	@Test
	public void skillCheckRoutesThroughInjectedGameMechanicsAndWritesTheResult() throws Exception {
		EngineConfiguration cfg = localMatrixConfig();
		VirtualMemory memory = new VirtualMemory(cfg);
		memory.addPartyMember(new CharacterSheetImpl(cfg.getFlavor(), monster));
		memory.setSelectedPartyMember(0);

		EclInstruction.configOpCodes(HashMap.of( //
			0x00, EclOpCode.EXIT, //
			0x01, EclOpCode.GOTO, //
			0x23, EclOpCode.SKILL_CHECK));
		int destAddress = 0x0300;
		VirtualMachine vm = new VirtualMachine(null, memory, cfg.getCodeBase(), id -> Resource.of(monster),
			fakeMechanicsReturning(42));
		vm.newEcl(threeArgOpcodeProgram(cfg.getCodeBase(), 0x23, 1, 2, destAddress));

		vm.startInit();

		assertEquals(42, memory.readMemInt(new engine.script.EclArgument(1, 3, destAddress)));
	}

	@Test
	public void partySkillCheck3RoutesThroughInjectedGameMechanicsAndWritesTheResult() throws Exception {
		EngineConfiguration cfg = localMatrixConfig();
		VirtualMemory memory = new VirtualMemory(cfg);

		EclInstruction.configOpCodes(HashMap.of( //
			0x00, EclOpCode.EXIT, //
			0x01, EclOpCode.GOTO, //
			0x22, EclOpCode.PARTY_SKILL_CHECK3));
		int destAddress = 0x0300;
		VirtualMachine vm = new VirtualMachine(null, memory, cfg.getCodeBase(), id -> Resource.of(monster),
			fakeMechanicsReturning(77));
		vm.newEcl(threeArgOpcodeProgram(cfg.getCodeBase(), 0x22, 1, 2, destAddress));

		vm.startInit();

		assertEquals(77, memory.readMemInt(new engine.script.EclArgument(1, 3, destAddress)));
	}

	@Test
	public void partySkillCheck3NoLongerFabricatesTheLiteralHundredWhenUnresolved() throws Exception {
		// PARTY_SKILL_CHECK3 used to unconditionally write 100 regardless of any
		// mechanics evidence. With the default UnresolvedGameMechanics (empty
		// result) this must now be a true no-op: the destination stays whatever it
		// already was, not a fabricated pass value.
		EngineConfiguration cfg = localMatrixConfig();
		VirtualMemory memory = new VirtualMemory(cfg);

		EclInstruction.configOpCodes(HashMap.of( //
			0x00, EclOpCode.EXIT, //
			0x01, EclOpCode.GOTO, //
			0x22, EclOpCode.PARTY_SKILL_CHECK3));
		int destAddress = 0x0300;
		VirtualMachine vm = new VirtualMachine(null, memory, cfg.getCodeBase()); // default UnresolvedGameMechanics
		vm.newEcl(threeArgOpcodeProgram(cfg.getCodeBase(), 0x22, 1, 2, destAddress));

		vm.startInit();

		int value = memory.readMemInt(new engine.script.EclArgument(1, 3, destAddress));
		assertFalse("PARTY_SKILL_CHECK3 must not fabricate the old literal 100 when unresolved", value == 100);
		assertEquals(0, value);
	}

	/** Fake GameMechanics that answers every routed check with a fixed value, to prove routing/wiring. */
	private static GameMechanics fakeMechanicsReturning(int value) {
		UnresolvedGameMechanics unresolved = new UnresolvedGameMechanics();
		return new GameMechanics() {
			@Override
			public OptionalInt partyStrength(List<? extends AbstractCharacter> party, int mode) {
				return unresolved.partyStrength(party, mode);
			}

			@Override
			public OptionalInt partyCheck(List<? extends AbstractCharacter> party, List<Integer> arguments) {
				return unresolved.partyCheck(party, arguments);
			}

			@Override
			public OptionalInt partySkillCheck(List<? extends AbstractCharacter> party, List<Integer> arguments) {
				return OptionalInt.of(value);
			}

			@Override
			public OptionalInt characterSkillCheck(AbstractCharacter character, List<Integer> arguments) {
				return OptionalInt.of(value);
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
			public OptionalInt giveExperience(List<? extends AbstractCharacter> party, int amount, int mode) {
				return unresolved.giveExperience(party, amount, mode);
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
		};
	}

	private VirtualMachine vm() {
		return new VirtualMachine(null, null, 0, id -> Resource.of(monster));
	}

	private static EngineConfiguration localMatrixConfig() throws Exception {
		String gameDir = System.getenv("MATRIX_CUBED_GAME_DIR");
		if (gameDir == null) {
			gameDir = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";
		}
		Assume.assumeTrue("MATRIX_CUBED_GAME_DIR (or the default local install path) must point at a Matrix Cubed install",
			new File(gameDir, "TITLE.DAX").isFile());
		return new EngineConfiguration(new FileMap(gameDir));
	}

	/** Header + onMove/onSearchLocation/onRest/onRestInterruption(EXIT) + onInit(GOTO body) + body(opcode, arg0, arg1, dest) + EXIT. */
	private static EclProgram threeArgOpcodeProgram(int codeBase, int opcodeByte, int arg0, int arg1,
		int destAddress) {
		ByteBufferWrapper code = ByteBufferWrapper.allocateLE(20);
		int bodyAddress = codeBase + 8;
		code.put(new byte[] {
			(byte) 0x88, 0x13, // EclProgram header id 5000, stripped by constructor
			0x00, // onMove: EXIT
			0x00, // onSearchLocation: EXIT
			0x00, // onRest: EXIT
			0x00, // onRestInterruption: EXIT
			0x01, 0x01, (byte) (bodyAddress & 0xFF), (byte) ((bodyAddress >> 8) & 0xFF), // onInit: GOTO body
			(byte) opcodeByte, // body: SKILL_CHECK / PARTY_SKILL_CHECK3
			0x00, (byte) arg0,
			0x00, (byte) arg1,
			0x01, (byte) (destAddress & 0xFF), (byte) ((destAddress >> 8) & 0xFF),
			0x00, // next instruction: EXIT
			0x00 // padding guard
		});
		code.flip();
		return new EclProgram(code, ContentType.ECL);
	}

	private static EclProgram unusedOpcodesProgram(int codeBase) {
		ByteBufferWrapper code = ByteBufferWrapper.allocateLE(14);
		int bodyAddress = codeBase + 8;
		code.put(new byte[] {
			(byte) 0x88, 0x13, // EclProgram header id 5000, stripped by constructor
			0x00, // onMove: EXIT
			0x00, // onSearchLocation: EXIT
			0x00, // onRest: EXIT
			0x00, // onRestInterruption: EXIT
			0x01, 0x01, (byte) (bodyAddress & 0xFF), (byte) ((bodyAddress >> 8) & 0xFF), // onInit: GOTO body
			0x1F, // body: UNUSED_1F
			0x42, // UNUSED_42
			0x00, // EXIT
			0x00 // padding guard
		});
		code.flip();
		return new EclProgram(code, ContentType.ECL);
	}

	private static EclProgram clock2Program(int codeBase, int timeStep, int timeSlot) {
		ByteBufferWrapper code = ByteBufferWrapper.allocateLE(17);
		int bodyAddress = codeBase + 8;
		code.put(new byte[] {
			(byte) 0x88, 0x13, // EclProgram header id 5000, stripped by constructor
			0x00, // onMove: EXIT
			0x00, // onSearchLocation: EXIT
			0x00, // onRest: EXIT
			0x00, // onRestInterruption: EXIT
			0x01, 0x01, (byte) (bodyAddress & 0xFF), (byte) ((bodyAddress >> 8) & 0xFF), // onInit: GOTO body
			0x34, // body: CLOCK2
			0x00, (byte) timeStep,
			0x00, (byte) timeSlot,
			0x00, // next instruction: EXIT
			0x00 // padding guard
		});
		code.flip();
		return new EclProgram(code, ContentType.ECL);
	}
}
