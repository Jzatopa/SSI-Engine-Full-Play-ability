package engine.rulesystem;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class GameMechanicsSelectorTest {
	@Test
	public void selectsMatrixMechanicsOnlyForMatrixCubed() {
		assertTrue(GameMechanicsSelector.select("Buck Rogers - Matrix Cubed") instanceof MatrixGameMechanics);
	}

	@Test
	public void fallsBackToUnresolvedForOtherTitles() {
		assertEquals(UnresolvedGameMechanics.class, GameMechanicsSelector.select("Curse of the Azure Bonds").getClass());
		assertEquals(UnresolvedGameMechanics.class,
			GameMechanicsSelector.select("Buck Rogers - Countdown to Doomsday").getClass());
	}
}
