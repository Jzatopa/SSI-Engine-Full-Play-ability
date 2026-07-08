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
import java.awt.image.BufferedImage;
import java.io.File;
import java.nio.file.Path;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

import engine.combat.BattlefieldBuffer;
import engine.combat.CombatAssetLoader;
import engine.combat.CombatAssetLoader.Assets;
import engine.combat.CombatController;
import engine.combat.CombatPosition;
import engine.combat.CombatState;
import engine.combat.Combatant;
import engine.combat.Combatant.Side;
import engine.combat.RecoveredBattlefieldGenerator;

/**
 * Playable combat screen using original Matrix Cubed DAX assets only.
 *
 * <p>Uses MARSCOM/VENUSCOM terrain, CPIC1 combat sprites, and BORDERS panel
 * pieces.  No generated replacement art is used.  The state/controls remain
 * backed by CombatState + CombatController.</p>
 */
public final class MatrixCubedPlayableCombatAssets {
	private static final Path DEFAULT_GAME_DIR = Path.of("../../generated/liveplay/first_map_capture/game");

	private MatrixCubedPlayableCombatAssets() {}

	public static void main(String[] args) throws Exception {
		Path gameDir = DEFAULT_GAME_DIR;
		File screenshot = null;
		boolean venus = false;

		for (String arg : args) {
			if (arg.startsWith("--screenshot=")) screenshot = new File(arg.substring("--screenshot=".length()));
			else if ("--venus".equals(arg)) venus = true;
			else if (!arg.startsWith("--")) gameDir = Path.of(arg);
		}

		Assets assets = CombatAssetLoader.load(gameDir);
		RecoveredBattlefieldGenerator.Options options = new RecoveredBattlefieldGenerator.Options();
		if (venus) options.terrain = RecoveredBattlefieldGenerator.Terrain.VENUS;
		CombatState state = CombatState.ratwurstVerticalSlice(options);
		if (venus) {
			state.addEvidence("Playable combat asset demo requested VENUS terrain via CLI.");
		}
		CombatController controller = new CombatController(state);

		if (screenshot != null) {
			BufferedImage image = renderSnapshot(controller, assets);
			File parent = screenshot.getParentFile();
			if (parent != null) parent.mkdirs();
			ImageIO.write(image, "png", screenshot);
			System.out.println("Wrote " + screenshot.getAbsolutePath());
			System.out.println("Assets: " + gameDir);
			System.out.println("Terrain tiles: " + assets.terrainTiles(venus).size() + "  CPIC sprites: " + assets.cpicSprites().size());
			return;
		}

		final boolean useVenus = venus;
		SwingUtilities.invokeLater(() -> {
			JFrame frame = new JFrame("Matrix Cubed - Playable Combat with Original Assets");
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.add(new AssetCombatPanel(controller, assets, useVenus), BorderLayout.CENTER);
			frame.pack();
			frame.setLocationByPlatform(true);
			frame.setVisible(true);
		});
	}

	public static BufferedImage renderSnapshot(CombatController controller, Assets assets, boolean venus) {
		BufferedImage image = new BufferedImage(AssetCombatPanel.W, AssetCombatPanel.H, BufferedImage.TYPE_INT_ARGB);
		Graphics2D g2 = image.createGraphics();
		new AssetCombatPanel(controller, assets, venus).paintForImage(g2);
		g2.dispose();
		return image;
	}

	public static BufferedImage renderSnapshot(CombatController controller, Assets assets) {
		BufferedImage image = new BufferedImage(AssetCombatPanel.W, AssetCombatPanel.H, BufferedImage.TYPE_INT_ARGB);
		Graphics2D g2 = image.createGraphics();
		new AssetCombatPanel(controller, assets).paintForImage(g2);
		g2.dispose();
		return image;
	}

	static final class AssetCombatPanel extends JPanel {
		static final int SCALE = 2;
		static final int TILE = 24 * SCALE;
		static final int VIEW_COLS = 10;
		static final int VIEW_ROWS = 7;
		static final int BOARD_X = 18;
		static final int BOARD_Y = 30;
		static final int SIDE_X = BOARD_X + VIEW_COLS * TILE + 16;
		static final int W = 640;
		static final int H = 400;

		private final CombatController controller;
		private final Assets assets;
		private final boolean venus;
		private final Font small = new Font(Font.MONOSPACED, Font.BOLD, 12);
		private final Font tiny = new Font(Font.MONOSPACED, Font.PLAIN, 11);
		private String actionStatus = "SELECT AN ENEMY WITH TAB/T, THEN PRESS A";
		private Timer monsterTurnTimer;

		AssetCombatPanel(CombatController controller, Assets assets, boolean venus) {
			this.controller = controller;
			this.assets = assets;
			this.venus = controller.state().battlefieldOptions().terrain == RecoveredBattlefieldGenerator.Terrain.VENUS || venus;
			setPreferredSize(new Dimension(W, H));
			setFocusable(true);
			setFocusTraversalKeysEnabled(false);
			setBackground(Color.BLACK);
			bindKeys();
		}

		AssetCombatPanel(CombatController controller, Assets assets) {
			this(controller, assets, false);
		}

		void paintForImage(Graphics2D g2) {
			setSize(W, H);
			paintComponent(g2);
		}

		private void bindKeys() {
			bind("LEFT", "cursor-left", () -> { controller.moveCursor(-1, 0); return null; });
			bind("RIGHT", "cursor-right", () -> { controller.moveCursor(1, 0); return null; });
			bind("UP", "cursor-up", () -> { controller.moveCursor(0, -1); return null; });
			bind("DOWN", "cursor-down", () -> { controller.moveCursor(0, 1); return null; });
			bind("TAB", "next-enemy", controller::selectNextEnemy);
			bind("T", "next-enemy-t", controller::selectNextEnemy);
			bind("M", "move", controller::moveCurrentToCursor);
			bind("A", "attack", controller::attackCursor);
			bind("ENTER", "context", controller::contextualAction);
			bind("SPACE", "end-turn", controller::endTurn);
			bind("E", "end-turn-e", controller::endTurn);
			bind("H", "home-current", () -> controller.syncCursorToCurrent());
			bind("V", "debug-victory", controller::forceVictoryForDebug);
		}

		private void bind(String key, String name, java.util.function.Supplier<CombatController.Action> action) {
			getInputMap(WHEN_IN_FOCUSED_WINDOW).put(KeyStroke.getKeyStroke(key), name);
			getActionMap().put(name, new AbstractAction() {
				@Override
				public void actionPerformed(ActionEvent e) {
					if (controller.state().phase() == CombatState.Phase.MONSTER_TURN) {
						actionStatus = "ENEMY TURN - PLEASE WAIT";
						repaint();
						return;
					}
					CombatController.Action result = action.get();
					if (result != null) actionStatus = statusFor(result);
					repaint();
					startAutomaticMonsterTurnsIfNeeded();
				}
			});
		}

		private void startAutomaticMonsterTurnsIfNeeded() {
			if (controller.state().phase() != CombatState.Phase.MONSTER_TURN
				|| (monsterTurnTimer != null && monsterTurnTimer.isRunning())) {
				return;
			}
			actionStatus = "ENEMY TURN - AUTOMATIC";
			monsterTurnTimer = new Timer(500, e -> {
				if (controller.state().phase() != CombatState.Phase.MONSTER_TURN || controller.isCombatOver()) {
					((Timer) e.getSource()).stop();
					controller.syncCursorToCurrent();
					actionStatus = controller.isCombatOver() ? "COMBAT COMPLETE" : "YOUR TURN";
					repaint();
					return;
				}
				controller.resolveMonsterTurn();
				actionStatus = latestCombatLog("ENEMY ACTION RESOLVED");
				repaint();
			});
			monsterTurnTimer.setInitialDelay(600);
			monsterTurnTimer.start();
		}

		private String latestCombatLog(String fallback) {
			List<String> log = controller.state().log();
			if (log.size() < 2) return fallback;
			return log.get(log.size() - 2);
		}

		private void bind(String key, String name, Runnable action) {
			bind(key, name, () -> { action.run(); return null; });
		}

		private String statusFor(CombatController.Action action) {
			return switch (action) {
				case ATTACKED -> controller.state().log().isEmpty()
					? "ATTACK RESOLVED - TURN ADVANCED"
					: controller.state().log().get(controller.state().log().size() - 2).replace("ATTACK: ", "");
				case NO_TARGET -> controller.state().occupantAt(controller.cursor())
					.map(c -> "TARGET: " + c.name() + " HP " + c.hitPoints() + "/" + c.maxHitPoints())
					.orElse("NO ENEMY ON CURSOR - TAB/T SELECTS ONE");
				case MOVED -> "MOVE ACCEPTED";
				case BLOCKED -> "ACTION BLOCKED";
				case ENDED_TURN -> "TURN ENDED";
				case MONSTER_ACTED -> "MONSTER ACTION RESOLVED";
				case COMBAT_OVER -> "COMBAT COMPLETE";
			};
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			Graphics2D g2 = (Graphics2D) g;
			g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
			g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_OFF);

			g2.setColor(Color.BLACK);
			g2.fillRect(0, 0, W, H);
			drawFrame(g2, BOARD_X - 10, BOARD_Y - 10, VIEW_COLS * TILE + 20, VIEW_ROWS * TILE + 20);
			drawFrame(g2, SIDE_X - 8, BOARD_Y - 10, W - SIDE_X - 10, 238);
			drawFrame(g2, 18, 318, 604, 64);

			drawBoard(g2);
			drawCombatants(g2);
			drawCursor(g2);
			drawSidePanel(g2);
			drawBottomMenu(g2);
		}

		private int viewX() {
			Combatant current = controller.state().current();
			int center = current == null ? 0 : current.position().x();
			return clamp(center - VIEW_COLS / 2, 0, BattlefieldBuffer.WIDTH - VIEW_COLS);
		}

		private int viewY() {
			Combatant current = controller.state().current();
			int center = current == null ? 0 : current.position().y();
			return clamp(center - VIEW_ROWS / 2, 0, BattlefieldBuffer.HEIGHT - VIEW_ROWS);
		}

		private void drawBoard(Graphics2D g2) {
			int vx = viewX();
			int vy = viewY();
			for (int row = 0; row < VIEW_ROWS; row++) {
				for (int col = 0; col < VIEW_COLS; col++) {
					int bx = vx + col;
					int by = vy + row;
					int code = controller.state().battlefield().getTileCode(bx, by);
					int tileCode = code == 0 ? baseTileCode(bx, by) : code;
					BufferedImage tile = assets.terrainTile(venus, tileCode);
					if (tile != null) g2.drawImage(tile, BOARD_X + col * TILE, BOARD_Y + row * TILE, TILE, TILE, null);
				}
			}
		}

		private int baseTileCode(int x, int y) {
			int[] mars = { 11, 12, 13, 15, 16, 17, 18, 19 };
			int[] ven = { 8, 9, 10, 11, 12, 13, 14, 15 };
			int[] set = venus ? ven : mars;
			return set[Math.floorMod(x * 3 + y * 5, set.length)];
		}

		private void drawCombatants(Graphics2D g2) {
			int vx = viewX();
			int vy = viewY();
			for (Combatant combatant : controller.state().combatants()) {
				if (!combatant.isAlive()) continue;
				int col = combatant.position().x() - vx;
				int row = combatant.position().y() - vy;
				if (col < 0 || col >= VIEW_COLS || row < 0 || row >= VIEW_ROWS) continue;

				BufferedImage sprite = spriteFor(combatant);
				int x = BOARD_X + col * TILE;
				int y = BOARD_Y + row * TILE;
				if (sprite != null) g2.drawImage(sprite, x, y, TILE, TILE, null);
				if (combatant == controller.state().current()) {
					g2.setColor(Color.WHITE);
					g2.setStroke(new BasicStroke(3f));
					g2.drawRect(x + 2, y + 2, TILE - 4, TILE - 4);
					g2.setStroke(new BasicStroke(1f));
				}
			}
		}

		private BufferedImage spriteFor(Combatant combatant) {
			if (combatant.side() == Side.MONSTER) {
				BufferedImage rat = assets.cpic(139);
				if (rat != null) return rat;
				return assets.cpic(138);
			}
			int[] partyIds = { 1, 2, 3, 4, 129, 130, 131, 132 };
			return assets.cpic(partyIds[Math.floorMod(combatant.id() - 1, partyIds.length)]);
		}

		private void drawCursor(Graphics2D g2) {
			int vx = viewX();
			int vy = viewY();
			CombatPosition c = controller.cursor();
			int col = c.x() - vx;
			int row = c.y() - vy;
			if (col < 0 || col >= VIEW_COLS || row < 0 || row >= VIEW_ROWS) return;
			int x = BOARD_X + col * TILE;
			int y = BOARD_Y + row * TILE;
			g2.setColor(CombatAssetLoader.goldBoxGreen());
			g2.setStroke(new BasicStroke(3f));
			g2.drawRect(x + 5, y + 5, TILE - 10, TILE - 10);
			g2.setStroke(new BasicStroke(1f));
		}

		private void drawSidePanel(Graphics2D g2) {
			CombatState state = controller.state();
			g2.setFont(small);
			g2.setColor(CombatAssetLoader.goldBoxGreen());
			int x = SIDE_X + 8;
			int y = BOARD_Y + 6;
			drawText(g2, "RATWURST", x, y); y += 22;
			drawText(g2, "HITPOINTS 52", x, y); y += 18;
			drawText(g2, "AC 4", x, y); y += 28;
			drawText(g2, "PHASE " + state.phase(), x, y); y += 16;
			drawText(g2, "ROUND " + state.round(), x, y); y += 16;
			drawText(g2, "RESULT " + state.combatResult(), x, y); y += 24;
			Combatant cur = state.current();
			drawText(g2, "CURRENT", x, y); y += 16;
			if (cur != null) {
				drawText(g2, trim(cur.name() + " HP " + cur.hitPoints() + "/" + cur.maxHitPoints(), 24), x, y); y += 16;
				drawText(g2, "AC " + cur.armorClass() + " POS " + cur.position(), x, y);
			}
		}

		private void drawBottomMenu(Graphics2D g2) {
			g2.setFont(small);
			g2.setColor(CombatAssetLoader.goldBoxGreen());
			drawText(g2, "RANGE     3    (SHORT)", 28, 338);
			drawText(g2, trim(actionStatus, 72), 28, 358);
			g2.setFont(tiny);
			g2.setColor(new Color(190, 190, 190));
			drawText(g2, "ARROWS CURSOR  TAB/T TARGET  A ATTACK  M MOVE  SPACE END", 28, 378);
		}

		private void drawFrame(Graphics2D g2, int x, int y, int w, int h) {
			List<BufferedImage> b = assets.borders();
			if (b.size() >= 12) {
				BufferedImage tl = b.get(0), tr = b.get(1), br = b.get(2), bl = b.get(3), horiz = b.get(4), vert = b.get(5);
				for (int xx = x + 16; xx < x + w - 16; xx += 16) {
					g2.drawImage(horiz, xx, y, 16, 16, null);
					g2.drawImage(horiz, xx, y + h - 16, 16, 16, null);
				}
				for (int yy = y + 16; yy < y + h - 16; yy += 16) {
					g2.drawImage(vert, x, yy, 16, 16, null);
					g2.drawImage(vert, x + w - 16, yy, 16, 16, null);
				}
				g2.drawImage(tl, x, y, 16, 16, null);
				g2.drawImage(tr, x + w - 16, y, 16, 16, null);
				g2.drawImage(bl, x, y + h - 16, 16, 16, null);
				g2.drawImage(br, x + w - 16, y + h - 16, 16, 16, null);
			}
		}

		private void drawText(Graphics2D g2, String text, int x, int y) { g2.drawString(text, x, y); }
		private int clamp(int value, int min, int max) { return Math.max(min, Math.min(max, value)); }
		private String trim(String text, int len) { return text.length() <= len ? text : text.substring(0, Math.max(0, len - 3)) + "..."; }
	}
}
