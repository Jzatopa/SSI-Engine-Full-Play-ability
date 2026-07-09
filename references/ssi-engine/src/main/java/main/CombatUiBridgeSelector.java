package main;

import java.nio.file.Path;
import java.util.Optional;

import engine.combat.CombatUiBridge;
import engine.combat.LegacyGoldBoxCombatUiBridge;

/** Keeps title-specific combat renderers out of other configured Gold Box games. */
public final class CombatUiBridgeSelector {
	public static final String MATRIX_CUBED = "Buck Rogers - Matrix Cubed";

	private CombatUiBridgeSelector() {
	}

	public static Optional<CombatUiBridge> select(String gameName, Path gameDir) {
		if (MATRIX_CUBED.equals(gameName)) {
			return Optional.of(new SwingCombatUiBridge(gameDir));
		}
		return Optional.of(new LegacyGoldBoxCombatUiBridge());
	}
}
