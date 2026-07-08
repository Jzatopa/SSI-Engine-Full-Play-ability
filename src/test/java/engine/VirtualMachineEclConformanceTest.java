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
import common.ByteBufferWrapper;
import data.ContentFile;
import data.ContentType;
import data.Resource;
import data.character.AbstractCharacter;
import data.character.CharacterBuckRogers;
import data.script.EclProgram;
import engine.script.EclInstruction;
import engine.script.EclOpCode;
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

	private VirtualMachine vm() {
		return new VirtualMachine(null, null, 0, id -> Resource.of(monster));
	}
}
