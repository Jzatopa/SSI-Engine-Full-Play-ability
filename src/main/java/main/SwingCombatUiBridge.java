package main;

import java.awt.BorderLayout;
import java.awt.GraphicsEnvironment;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.nio.file.Path;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicReference;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

import engine.combat.CombatAssetLoader;
import engine.combat.CombatController;
import engine.combat.CombatSession;
import engine.combat.CombatSessionResult;
import engine.combat.CombatState;
import engine.combat.CombatUiBridge;
import engine.combat.HeadlessCombatUiBridge;

/**
 * Swing implementation scaffold for VM interactive combat handoff.
 *
 * <p>This is intentionally synchronous from the VM bridge point of view:
 * resolve(session) opens the asset-backed combat screen, waits until the
 * CombatState reaches VICTORY/DEFEAT, then returns COMBAT_RESULT semantics.
 * If the environment is headless, it falls back to HeadlessCombatUiBridge.</p>
 *
 * <p>OpenClaw should validate this with the full Maven/Swing runtime and then
 * decide whether VM execution should block on this method or use a future
 * asynchronous continuation.</p>
 */
public final class SwingCombatUiBridge implements CombatUiBridge {
	private final Path gameDir;
	private final boolean venus;
	private final HeadlessCombatUiBridge headlessFallback;

	public SwingCombatUiBridge(Path gameDir) {
		this(gameDir, false);
	}

	public SwingCombatUiBridge(Path gameDir, boolean venus) {
		this.gameDir = gameDir;
		this.venus = venus;
		this.headlessFallback = new HeadlessCombatUiBridge();
	}

	@Override
	public CombatSessionResult resolve(CombatSession session) {
		if (GraphicsEnvironment.isHeadless()) {
			CombatSessionResult fallback = headlessFallback.resolve(session);
			session.state().addEvidence("SwingCombatUiBridge: headless environment detected; used HeadlessCombatUiBridge fallback.");
			return CombatSessionResult.of(
				fallback.combatResult(),
				fallback.state(),
				fallback.transcript(),
				fallback.actions(),
				false,
				"SwingCombatUiBridge(headless fallback)"
			);
		}

		CountDownLatch finished = new CountDownLatch(1);
		AtomicReference<CombatSessionResult> result = new AtomicReference<>();
		AtomicBoolean completed = new AtomicBoolean();

		SwingUtilities.invokeLater(() -> {
			try {
				CombatAssetLoader.Assets assets = CombatAssetLoader.load(gameDir);
				CombatController controller = new CombatController(session.state());
				JFrame frame = new JFrame("Matrix Cubed - VM Combat Handoff");
				MatrixCubedPlayableCombatAssets.AssetCombatPanel panel =
					new MatrixCubedPlayableCombatAssets.AssetCombatPanel(controller, assets, venus);
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				frame.add(panel, BorderLayout.CENTER);
				frame.pack();
				frame.setLocationByPlatform(true);
				frame.setVisible(true);
				frame.toFront();
				panel.requestFocusInWindow();
				if (Boolean.getBoolean("matrix.combat.debugAutoVictory")) {
					SwingUtilities.invokeLater(controller::forceVictoryForDebug);
				}

				Timer timer = new Timer(100, e -> {
					if (controller.isCombatOver()) {
						((Timer) e.getSource()).stop();
						int combatResult = session.state().combatResult();
						if (combatResult < 0) {
							combatResult = 1;
						}
						frame.dispose();
						completeOnce(completed, result, finished, CombatSessionResult.of(
							combatResult,
							session.state(),
							renderInteractiveTranscript(session, combatResult),
							session.state().log().size(),
							true,
							"SwingCombatUiBridge"
						));
					}
				});
				frame.addWindowListener(new WindowAdapter() {
					private void resolveClosedWindow() {
						if (completed.get()) return;
						timer.stop();
						session.state().addEvidence("SwingCombatUiBridge: user closed combat before resolution; returned unresolved/defeat result instead of blocking the VM.");
						completeOnce(completed, result, finished, CombatSessionResult.of(
							1,
							session.state(),
							"Swing combat closed before resolution.",
							session.state().log().size(),
							true,
							"SwingCombatUiBridge(user closed)"
						));
					}

					@Override
					public void windowClosing(WindowEvent event) { resolveClosedWindow(); }

					@Override
					public void windowClosed(WindowEvent event) { resolveClosedWindow(); }
				});
				timer.start();
				if (Boolean.getBoolean("matrix.combat.debugAutoClose")) {
					Timer closeTimer = new Timer(500, e -> {
						((Timer) e.getSource()).stop();
						frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
					});
					closeTimer.setRepeats(false);
					closeTimer.start();
				}
			} catch (Exception ex) {
				session.state().addEvidence("SwingCombatUiBridge failed to launch: " + ex.getMessage());
				completeOnce(completed, result, finished, headlessFallback.resolve(session));
			}
		});

		try {
			finished.await();
		} catch (InterruptedException ex) {
			Thread.currentThread().interrupt();
			session.state().addEvidence("SwingCombatUiBridge interrupted; using unresolved/defeat result.");
			return CombatSessionResult.of(1, session.state(), "Swing combat interrupted.", session.state().log().size(), true,
				"SwingCombatUiBridge(interrupted)");
		}
		return result.get();
	}

	private static void completeOnce(AtomicBoolean completed, AtomicReference<CombatSessionResult> result,
		CountDownLatch finished, CombatSessionResult value) {
		if (completed.compareAndSet(false, true)) {
			result.set(value);
			finished.countDown();
		}
	}

	private String renderInteractiveTranscript(CombatSession session, int combatResult) {
		CombatState state = session.state();
		StringBuilder out = new StringBuilder();
		out.append("MATRIX CUBED INTERACTIVE COMBAT HANDOFF\n");
		out.append("Resolver: SwingCombatUiBridge\n");
		out.append("Source: ").append(session.source()).append('\n');
		out.append("Phase: ").append(state.phase()).append("  COMBAT_RESULT=").append(combatResult).append('\n');
		out.append("Log:\n");
		for (String line : state.log()) {
			out.append("  ").append(line).append('\n');
		}
		out.append("Evidence:\n");
		for (String line : state.evidence()) {
			out.append("  - ").append(line).append('\n');
		}
		out.append("Boundary: Swing bridge is a handoff scaffold; OpenClaw must validate VM pause/resume and user-input flow in the full runtime.\n");
		return out.toString();
	}
}
