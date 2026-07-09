package main;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

import javax.swing.JFrame;
import javax.swing.JPanel;

import data.ContentFile;
import data.ContentType;
import data.image.VGAImage;
import engine.combat.BattlefieldBuffer;
import engine.combat.RecoveredBattlefieldGenerator;
import engine.combat.RecoveredBattlefieldGenerator.GeneratedBattlefield;
import engine.combat.RecoveredBattlefieldGenerator.Options;
import engine.combat.RecoveredBattlefieldGenerator.Terrain;
import io.vavr.collection.Seq;

public class MatrixCubedCombatBattlefield {
	private static final String DEFAULT_GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";

	public static void main(String[] args) throws Exception {
		String gameDir = args.length > 0 ? args[0] : DEFAULT_GAME_DIR;
		Options options = parseOptions(args);
		GeneratedBattlefield battlefield = new RecoveredBattlefieldGenerator().generate(options);
		Seq<BufferedImage> tiles = loadTiles(gameDir, options.terrain);

		System.out.println(renderReport(gameDir, battlefield, tiles.size()));

		EventQueue.invokeLater(() -> {
			JFrame frame = new JFrame("Matrix Cubed - Recovered Combat Battlefield Buffer");
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.add(new BattlefieldPanel(gameDir, battlefield, tiles));
			frame.pack();
			frame.setLocationByPlatform(true);
			frame.setVisible(true);
		});
	}

	public static String renderReport(String gameDir, GeneratedBattlefield battlefield, int tileImageCount) {
		StringBuilder out = new StringBuilder();
		Options options = battlefield.options();
		out.append("Matrix Cubed recovered combat battlefield buffer\n");
		out.append("Game dir: ").append(gameDir).append('\n');
		out.append("Tile source: ").append(options.terrain.tileFile()).append(" block ").append(options.terrain.blockId()).append('\n');
		out.append("Decoded tile images: ").append(tileImageCount).append('\n');
		out.append("Buffer: 7-byte header + ").append(BattlefieldBuffer.WIDTH).append("x")
			.append(BattlefieldBuffer.HEIGHT).append(" tile codes\n");
		out.append("Globals: 0x4004=").append(options.sectorX).append(" 0x4005=").append(options.sectorY)
			.append(" 0x4006=").append(options.global4006).append(" 0x4007=").append(options.global4007)
			.append('\n');
		out.append("Tile histogram: ").append(formatHistogram(battlefield.tileHistogram())).append('\n');
		out.append("Evidence:\n");
		for (String line : battlefield.evidence()) {
			out.append("  - ").append(line).append('\n');
		}
		out.append("Boundary: generated from recovered GAME.OVR tile-buffer routines plus original combat tile DAX art; ")
			.append("unresolved GAME.OVR random/fill routines are not yet ported.\n");
		return out.toString();
	}

	private static Options parseOptions(String[] args) {
		Options options = new Options();
		for (int i = 1; i < args.length; i++) {
			String arg = args[i];
			if (arg.startsWith("--terrain=")) {
				options.terrain = Terrain.valueOf(arg.substring("--terrain=".length()).toUpperCase());
			} else if (arg.startsWith("--sector-x=")) {
				options.sectorX = Integer.parseInt(arg.substring("--sector-x=".length()));
			} else if (arg.startsWith("--sector-y=")) {
				options.sectorY = Integer.parseInt(arg.substring("--sector-y=".length()));
			} else if (arg.startsWith("--global-4006=")) {
				options.global4006 = Integer.parseInt(arg.substring("--global-4006=".length()));
			} else if (arg.startsWith("--global-4007=")) {
				options.global4007 = Integer.parseInt(arg.substring("--global-4007=".length()));
			}
		}
		return options;
	}

	private static Seq<BufferedImage> loadTiles(String gameDir, Terrain terrain) throws Exception {
		File root = new File(gameDir);
		VGAImage image = ContentFile.create(new File(root, terrain.tileFile())).get()
			.getById(terrain.blockId(), VGAImage.class, ContentType.SPRIT)
			.get();
		return image.toSeq();
	}

	private static String formatHistogram(Map<Integer, Integer> histogram) {
		if (histogram.isEmpty()) {
			return "(empty)";
		}
		return histogram.entrySet().stream()
			.map(e -> String.format("0x%02X=%d", e.getKey(), e.getValue()))
			.collect(Collectors.joining(", "));
	}

	private static final class BattlefieldPanel extends JPanel {
		private static final int CELL = 12;
		private final String gameDir;
		private final GeneratedBattlefield battlefield;
		private final Seq<BufferedImage> tiles;

		BattlefieldPanel(String gameDir, GeneratedBattlefield battlefield, Seq<BufferedImage> tiles) {
			this.gameDir = gameDir;
			this.battlefield = battlefield;
			this.tiles = tiles;
			setPreferredSize(new Dimension(760, 500));
			setBackground(Color.BLACK);
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			Graphics2D g2 = (Graphics2D) g;
			g2.setColor(Color.BLACK);
			g2.fillRect(0, 0, getWidth(), getHeight());
			g2.setColor(new Color(40, 200, 80));
			g2.drawString("Recovered GAME.OVR combat battlefield buffer", 16, 20);
			g2.setColor(new Color(180, 180, 180));
			g2.drawString(gameDir, 16, 38);

			drawGrid(g2, 24, 56);
			drawDiagnostics(g2, 24, 374);
		}

		private void drawGrid(Graphics2D g2, int startX, int startY) {
			BattlefieldBuffer buffer = battlefield.buffer();
			g2.setColor(new Color(32, 32, 32));
			for (int y = 0; y <= BattlefieldBuffer.HEIGHT; y++) {
				g2.drawLine(startX, startY + y * CELL, startX + BattlefieldBuffer.WIDTH * CELL, startY + y * CELL);
			}
			for (int x = 0; x <= BattlefieldBuffer.WIDTH; x++) {
				g2.drawLine(startX + x * CELL, startY, startX + x * CELL, startY + BattlefieldBuffer.HEIGHT * CELL);
			}

			for (int y = 0; y < BattlefieldBuffer.HEIGHT; y++) {
				for (int x = 0; x < BattlefieldBuffer.WIDTH; x++) {
					int code = buffer.getTileCode(x, y);
					if (code == 0) {
						continue;
					}
					BufferedImage tile = tileForCode(code);
					if (tile != null) {
						g2.drawImage(tile, startX + x * CELL, startY + y * CELL, CELL, CELL, null);
					} else {
						g2.setColor(new Color(110, 60, 180));
						g2.fillRect(startX + x * CELL + 1, startY + y * CELL + 1, CELL - 1, CELL - 1);
					}
					g2.setColor(Color.WHITE);
					g2.drawString(Integer.toHexString(code).toUpperCase(), startX + x * CELL + 1, startY + y * CELL + 10);
				}
			}
		}

		private BufferedImage tileForCode(int code) {
			int index = code - 1;
			if (index < 0 || index >= tiles.size()) {
				return null;
			}
			return tiles.get(index);
		}

		private void drawDiagnostics(Graphics2D g2, int x, int y) {
			Options options = battlefield.options();
			g2.setColor(new Color(40, 200, 80));
			g2.drawString("Tile source: " + options.terrain.tileFile() + " block " + options.terrain.blockId(), x, y);
			g2.setColor(new Color(180, 180, 180));
			g2.drawString("Globals 0x4004=" + options.sectorX + " 0x4005=" + options.sectorY + " 0x4006="
				+ options.global4006 + " 0x4007=" + options.global4007, x, y + 18);
			g2.drawString("Tile histogram: " + formatHistogram(new TreeMap<>(battlefield.tileHistogram())), x, y + 36);
			g2.drawString("Purple cells are recovered tile codes without a direct decoded-image mapping yet.", x, y + 54);
			g2.drawString("Boundary: unresolved random/fill routines are still pending.", x, y + 72);
		}
	}
}
