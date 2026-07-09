package main;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;

import javax.swing.JFrame;
import javax.swing.JPanel;

import data.ContentFile;
import data.ContentType;
import data.image.VGAImage;
import io.vavr.collection.Seq;

public class MatrixCubedCombatStaticScreen {
	private static final String DEFAULT_GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";

	public static void main(String[] args) throws Exception {
		String gameDir = args.length > 0 ? args[0] : DEFAULT_GAME_DIR;
		CombatAssets assets = CombatAssets.load(gameDir);

		EventQueue.invokeLater(() -> {
			JFrame frame = new JFrame("Matrix Cubed - Static Combat Screen");
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.add(new CombatPanel(gameDir, assets));
			frame.pack();
			frame.setLocationByPlatform(true);
			frame.setVisible(true);
		});
	}

	private static final class CombatAssets {
		final Seq<BufferedImage> marsTiles;
		final Seq<BufferedImage> sprites;

		CombatAssets(Seq<BufferedImage> marsTiles, Seq<BufferedImage> sprites) {
			this.marsTiles = marsTiles;
			this.sprites = sprites;
		}

		static CombatAssets load(String gameDir) throws Exception {
			File root = new File(gameDir);
			VGAImage mars = ContentFile.create(new File(root, "MARSCOM.DAX")).get()
				.getById(1, VGAImage.class, ContentType.SPRIT)
				.get();
			VGAImage sprites = ContentFile.create(new File(root, "COMSPR.DAX")).get()
				.getById(1, VGAImage.class, ContentType.SPRIT)
				.get();
			return new CombatAssets(mars.toSeq(), sprites.toSeq());
		}
	}

	private static final class CombatPanel extends JPanel {
		private static final int SCALE = 2;
		private final String gameDir;
		private final CombatAssets assets;

		CombatPanel(String gameDir, CombatAssets assets) {
			this.gameDir = gameDir;
			this.assets = assets;
			setPreferredSize(new Dimension(640, 400));
			setBackground(Color.BLACK);
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			Graphics2D g2 = (Graphics2D) g;
			g2.setColor(Color.BLACK);
			g2.fillRect(0, 0, getWidth(), getHeight());

			g2.setColor(new Color(40, 200, 80));
			g2.drawString("Matrix Cubed static combat screen - original MARSCOM.DAX + COMSPR.DAX", 16, 20);
			g2.setColor(new Color(180, 180, 180));
			g2.drawString(gameDir, 16, 38);

			drawBoard(g2, 40, 60);
			drawSprites(g2, 80, 100);

			g2.setColor(new Color(40, 200, 80));
			g2.drawRect(40, 308, 560, 56);
			g2.drawString("COMBAT", 56, 330);
			g2.drawString("Static asset proof only: no tactical placement/formulas yet.", 56, 350);
		}

		private void drawBoard(Graphics2D g2, int startX, int startY) {
			int index = 0;
			for (int y = 0; y < 8; y++) {
				for (int x = 0; x < 10; x++) {
					BufferedImage img = assets.marsTiles.get(index % assets.marsTiles.size());
					g2.drawImage(img, startX + x * img.getWidth() * SCALE, startY + y * img.getHeight() * SCALE,
						img.getWidth() * SCALE, img.getHeight() * SCALE, null);
					index++;
				}
			}
		}

		private void drawSprites(Graphics2D g2, int startX, int startY) {
			if (assets.sprites.isEmpty()) {
				return;
			}
			BufferedImage sprite = assets.sprites.get(0);
			g2.drawImage(sprite, startX + 6 * sprite.getWidth(), startY + 2 * sprite.getHeight(),
				sprite.getWidth() * SCALE, sprite.getHeight() * SCALE, null);
			g2.drawImage(sprite, startX + 10 * sprite.getWidth(), startY + 4 * sprite.getHeight(),
				sprite.getWidth() * SCALE, sprite.getHeight() * SCALE, null);
		}
	}
}
