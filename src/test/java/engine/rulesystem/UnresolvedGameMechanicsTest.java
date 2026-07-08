package engine.rulesystem;

import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Test;

public class UnresolvedGameMechanicsTest {
	private final GameMechanics mechanics = new UnresolvedGameMechanics();

	@Test
	public void unresolvedOperationsAreNotReportedAsSuccessfulZeroes() {
		assertTrue(mechanics.partyStrength(List.of(), 0).isEmpty());
		assertTrue(mechanics.partyCheck(List.of(), List.of()).isEmpty());
		assertTrue(mechanics.partySkillCheck(List.of(), List.of()).isEmpty());
		assertTrue(mechanics.encounterMovement(List.of(), false).isEmpty());
		assertTrue(mechanics.findItem(List.of(), 1).isEmpty());
		assertTrue(mechanics.destroyItem(List.of(), 1).isEmpty());
		assertTrue(mechanics.giveExperience(List.of(), 100, 0).isEmpty());
		assertTrue(mechanics.executeGameOpcode(0x48, List.of()).isEmpty());
	}
}
