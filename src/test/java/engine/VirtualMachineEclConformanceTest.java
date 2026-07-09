package engine;

import static character.CharacterGender.MALE;
import static character.buckrogers.CharacterClassBuckRogers.WARRIOR;
import static character.buckrogers.CharacterRaceBuckRogers.TERRAN;
import static data.character.CharacterValues.BUCK_ROGERS;
import static org.junit.Assert.assertEquals;

import java.io.File;

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

	private VirtualMachine vm() {
		return new VirtualMachine(null, null, 0, id -> Resource.of(monster));
	}

	private static EngineConfiguration localMatrixConfig() throws Exception {
		String gameDir = System.getenv("MATRIX_CUBED_GAME_DIR");
		Assume.assumeTrue("MATRIX_CUBED_GAME_DIR must point at a local Matrix Cubed install",
			gameDir != null && new File(gameDir, "TITLE.DAX").isFile());
		return new EngineConfiguration(new FileMap(gameDir));
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
