package engine.rulesystem;

/**
 * Profile-gates the {@link GameMechanics} boundary the same way
 * {@code main.CombatUiBridgeSelector} gates the combat UI renderer: a
 * title-specific mechanics provider is only handed to titles it was built
 * and evidenced for. Every other configured Gold Box game keeps getting
 * {@link UnresolvedGameMechanics} (a true no-op boundary) until it gets its
 * own provider.
 */
public final class GameMechanicsSelector {
	public static final String MATRIX_CUBED = "Buck Rogers - Matrix Cubed";

	private GameMechanicsSelector() {
	}

	public static GameMechanics select(String gameName) {
		if (MATRIX_CUBED.equals(gameName)) {
			return new MatrixGameMechanics();
		}
		return new UnresolvedGameMechanics();
	}
}
