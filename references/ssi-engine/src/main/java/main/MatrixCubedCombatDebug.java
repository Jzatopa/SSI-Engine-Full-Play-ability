package main;

import java.awt.EventQueue;

import ui.DesktopFrame;

public class MatrixCubedCombatDebug {
	private static final String DEFAULT_GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";
	private static final int CALORIS_ECL_ID = 17;
	private static final int CALORIS_COMBAT_BRANCH = 0x8CDB;

	public static void main(String[] args) {
		String gameDir = args.length > 0 ? args[0] : DEFAULT_GAME_DIR;
		EventQueue.invokeLater(() -> {
			DesktopFrame ui = new DesktopFrame();
			ui.show();
			ui.startCombatDebug(gameDir, CALORIS_ECL_ID, CALORIS_COMBAT_BRANCH);
		});
	}
}
