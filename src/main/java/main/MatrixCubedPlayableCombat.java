package main;

import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

import engine.combat.BattlefieldBuffer;
import engine.combat.CombatController;
import engine.combat.CombatPosition;
import engine.combat.CombatState;
import engine.combat.Combatant;
import engine.combat.Combatant.Side;

/**
 * Playable Matrix Cubed combat-state screen.
 *
 * <p>This is the first Java pass where the reconstructed combat state is
 * accessible as an interactive screen.  It uses the recovered combat
 * battlefield buffer and the Ratwurst vertical slice.  It does not require
 * original SSI asset files; a later renderer should replace the placeholder
 * board colors with original MARSCOM/VENUSCOM/COMSPR images.</p>
 *
 * <p>Controls:</p>
 * <ul>
 *   <li>Arrow keys: move cursor</li>
 *   <li>M: move current party member to cursor</li>
 *   <li>A: attack hostile combatant under cursor</li>
 *   <li>Enter: contextual action (attack hostile, move otherwise)</li>
 *   <li>Space/E: end current turn</li>
 *   <li>Monster turns resolve automatically</li>
 *   <li>H: recenter cursor on current combatant</li>
 * </ul>
 */
public final class MatrixCubedPlayableCombat {
	private MatrixCubedPlayableCombat() {
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			CombatController controller = new CombatController(CombatState.ratwurstVerticalSlice());
			JFrame frame = new JFrame("Matrix Cubed - Playable Combat State Pass 1");
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.add(new CombatPanel(controller), BorderLayout.CENTER);
			frame.pack();
			frame.setLocationByPlatform(true);
			frame.setVisible(true);
		});
	}

	static final class CombatPanel extends JPanel {
		private static final int CELL = 18;
		private static final int BOARD_X = 18;
		private static final int BOARD_Y = 34;
		private static final int PANEL_X = BOARD_X + BattlefieldBuffer.WIDTH * CELL + 22;
		private static final int W = PANEL_X + 360;
		private static final int H = BOARD_Y + BattlefieldBuffer.HEIGHT * CELL + 34;

		private final CombatController controller;
		private final Font small = new Font(Font.MONOSPACED, Font.PLAIN, 12);
		private final Font bold = new Font(Font.MONOSPACED, Font.BOLD, 14);
		private Timer monsterTurnTimer;

		CombatPanel(CombatController controller) {
			this.controller = controller;
			setPreferredSize(new Dimension(W, H));
			setFocusable(true);
			setBackground(Color.BLACK);
			bindKeys();
		}

		private void bindKeys() {
			bind("LEFT", "cursor-left", () -> controller.moveCursor(-1, 0));
			bind("RIGHT", "cursor-right", () -> controller.moveCursor(1, 0));
			bind("UP", "cursor-up", () -> controller.moveCursor(0, -1));
			bind("DOWN", "cursor-down", () -> controller.moveCursor(0, 1));
			bind("M", "move", () -> controller.moveCurrentToCursor());
			bind("A", "attack", () -> controller.attackCursor());
			bind("ENTER", "context", () -> controller.contextualAction());
			bind("SPACE", "end-turn", () -> controller.endTurn());
			bind("E", "end-turn-e", () -> controller.endTurn());
			bind("H", "home-current", () -> controller.syncCursorToCurrent());
		}

		private void bind(String key, String name, Runnable action) {
			getInputMap(WHEN_IN_FOCUSED_WINDOW).put(KeyStroke.getKeyStroke(key), name);
			getActionMap().put(name, new AbstractAction() {
				@Override
				public void actionPerformed(ActionEvent e) {
					if (controller.state().phase() == CombatState.Phase.MONSTER_TURN) return;
					action.run();
					repaint();
					startAutomaticMonsterTurnsIfNeeded();
				}
			});
		}

		private void startAutomaticMonsterTurnsIfNeeded() {
			if (controller.state().phase() != CombatState.Phase.MONSTER_TURN
				|| (monsterTurnTimer != null && monsterTurnTimer.isRunning())) return;
			monsterTurnTimer = new Timer(500, e -> {
				if (controller.state().phase() != CombatState.Phase.MONSTER_TURN || controller.isCombatOver()) {
					((Timer) e.getSource()).stop();
					controller.syncCursorToCurrent();
					repaint();
					return;
				}
				controller.resolveMonsterTurn();
				repaint();
			});
			monsterTurnTimer.setInitialDelay(600);
			monsterTurnTimer.start();
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			Graphics2D g2 = (Graphics2D) g;
			g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

			drawTitle(g2);
			drawBoard(g2);
			drawCombatants(g2);
			drawCursor(g2);
			drawSidePanel(g2);
		}

		private void drawTitle(Graphics2D g2) {
			g2.setFont(bold);
			g2.setColor(new Color(80, 240, 120));
			g2.drawString("MATRIX CUBED - PLAYABLE COMBAT STATE PASS 1", BOARD_X, 20);
			g2.setFont(small);
			g2.setColor(new Color(190, 190, 190));
			g2.drawString("Recovered 50x25 battlefield buffer + stateful Ratwurst vertical slice. Formulas still marked as scaffold.", BOARD_X + 350, 20);
		}

		private void drawBoard(Graphics2D g2) {
			BattlefieldBuffer buffer = controller.state().battlefield();
			for (int y = 0; y < BattlefieldBuffer.HEIGHT; y++) {
				for (int x = 0; x < BattlefieldBuffer.WIDTH; x++) {
					int code = buffer.getTileCode(x, y);
					g2.setColor(tileColor(code, x, y));
					g2.fillRect(BOARD_X + x * CELL, BOARD_Y + y * CELL, CELL, CELL);
					g2.setColor(new Color(18, 24, 32));
					g2.drawRect(BOARD_X + x * CELL, BOARD_Y + y * CELL, CELL, CELL);
					if (code != 0) {
						g2.setFont(small);
						g2.setColor(new Color(230, 230, 230));
						g2.drawString(Integer.toHexString(code).toUpperCase(), BOARD_X + x * CELL + 3, BOARD_Y + y * CELL + 13);
					}
				}
			}
		}

		private Color tileColor(int code, int x, int y) {
			if (code == 0) {
				return ((x + y) % 2 == 0) ? new Color(34, 38, 45) : new Color(28, 32, 39);
			}
			int r = 55 + ((code * 37) % 110);
			int g = 60 + ((code * 19) % 120);
			int b = 75 + ((code * 53) % 120);
			return new Color(r, g, b);
		}

		private void drawCombatants(Graphics2D g2) {
			for (Combatant combatant : controller.state().combatants()) {
				if (!combatant.isAlive()) {
					continue;
				}
				int cx = BOARD_X + combatant.position().x() * CELL + CELL / 2;
				int cy = BOARD_Y + combatant.position().y() * CELL + CELL / 2;
				boolean active = combatant == controller.state().current();
				g2.setColor(combatant.side() == Side.PARTY ? new Color(55, 175, 255) : new Color(225, 80, 70));
				g2.fillOval(cx - 7, cy - 7, 14, 14);
				g2.setColor(active ? Color.WHITE : Color.BLACK);
				g2.setStroke(new BasicStroke(active ? 3f : 1f));
				g2.drawOval(cx - 8, cy - 8, 16, 16);
				g2.setStroke(new BasicStroke(1f));
				g2.setFont(small);
				g2.setColor(Color.WHITE);
				String label = combatant.side() == Side.PARTY ? combatant.name() : "R";
				g2.drawString(label, cx - 8, cy - 10);
			}
		}

		private void drawCursor(Graphics2D g2) {
			CombatPosition cursor = controller.cursor();
			int x = BOARD_X + cursor.x() * CELL;
			int y = BOARD_Y + cursor.y() * CELL;
			g2.setColor(new Color(255, 245, 90));
			g2.setStroke(new BasicStroke(3f));
			g2.drawRect(x + 1, y + 1, CELL - 2, CELL - 2);
			g2.setStroke(new BasicStroke(1f));
		}

		private void drawSidePanel(Graphics2D g2) {
			CombatState state = controller.state();
			int x = PANEL_X;
			int y = BOARD_Y;
			g2.setColor(new Color(12, 16, 22));
			g2.fillRect(x, y, 330, BattlefieldBuffer.HEIGHT * CELL);
			g2.setColor(new Color(80, 240, 120));
			g2.drawRect(x, y, 330, BattlefieldBuffer.HEIGHT * CELL);

			g2.setFont(bold);
			g2.drawString("COMBAT STATE", x + 12, y + 22);
			g2.setFont(small);
			g2.setColor(Color.WHITE);
			g2.drawString("Phase: " + state.phase(), x + 12, y + 45);
			g2.drawString("Result: " + state.combatResult() + "   Round: " + state.round(), x + 12, y + 63);
			g2.drawString("Cursor: " + controller.cursor(), x + 12, y + 81);

			Combatant current = state.current();
			g2.setColor(new Color(80, 240, 120));
			g2.drawString("CURRENT", x + 12, y + 110);
			g2.setColor(Color.WHITE);
			if (current != null) {
				drawCombatantLine(g2, current, x + 12, y + 130);
			}

			int yy = y + 162;
			g2.setColor(new Color(80, 240, 120));
			g2.drawString("PARTY", x + 12, yy);
			yy += 18;
			for (Combatant c : state.combatants()) {
				if (c.side() == Side.PARTY) {
					drawCombatantLine(g2, c, x + 12, yy);
					yy += 16;
				}
			}

			yy += 10;
			g2.setColor(new Color(80, 240, 120));
			g2.drawString("MONSTERS", x + 12, yy);
			yy += 18;
			for (Combatant c : state.combatants()) {
				if (c.side() == Side.MONSTER) {
					drawCombatantLine(g2, c, x + 12, yy);
					yy += 16;
				}
			}

			yy += 12;
			g2.setColor(new Color(80, 240, 120));
			g2.drawString("CONTROLS", x + 12, yy);
			g2.setColor(new Color(215, 215, 215));
			List<String> controls = List.of(
				"Arrows: cursor",
				"Enter: context",
				"M: move to cursor",
				"A: attack target",
				"Space/E: end turn",
				"Enemies act automatically",
				"H: cursor to current"
			);
			for (String line : controls) {
				yy += 16;
				g2.drawString(line, x + 12, yy);
			}

			yy += 20;
			g2.setColor(new Color(80, 240, 120));
			g2.drawString("LOG", x + 12, yy);
			g2.setColor(new Color(215, 215, 215));
			List<String> log = state.log();
			int start = Math.max(0, log.size() - 7);
			for (int i = start; i < log.size(); i++) {
				yy += 15;
				g2.drawString(trim(log.get(i), 42), x + 12, yy);
			}
		}

		private void drawCombatantLine(Graphics2D g2, Combatant c, int x, int y) {
			g2.setColor(c.isAlive() ? Color.WHITE : new Color(120, 120, 120));
			g2.drawString(c.name() + " HP " + c.hitPoints() + "/" + c.maxHitPoints() + " AC " + c.armorClass() + " " + c.position(), x, y);
		}

		private String trim(String text, int len) {
			if (text.length() <= len) {
				return text;
			}
			return text.substring(0, Math.max(0, len - 3)) + "...";
		}
	}
}
