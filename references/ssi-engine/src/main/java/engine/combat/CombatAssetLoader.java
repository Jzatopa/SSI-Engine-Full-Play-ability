package engine.combat;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * Minimal Matrix Cubed DAX/VGA asset loader for playable combat rendering.
 *
 * <p>This uses only JDK classes and mirrors the DAX uncompress/VGA image path
 * already present in SSI Engine.  It allows the playable combat vertical slice
 * to render with original local Matrix Cubed assets without generated art.</p>
 */
public final class CombatAssetLoader {
	public enum ImageKind { SPRIT, PIC }

	public static final class Assets {
		private final Path gameDir;
		private final List<BufferedImage> marsTiles;
		private final List<BufferedImage> venusTiles;
		private final Map<Integer, BufferedImage> cpicSprites;
		private final List<BufferedImage> borders;

		private Assets(Path gameDir, List<BufferedImage> marsTiles, List<BufferedImage> venusTiles,
			Map<Integer, BufferedImage> cpicSprites, List<BufferedImage> borders) {
			this.gameDir = gameDir;
			this.marsTiles = List.copyOf(marsTiles);
			this.venusTiles = List.copyOf(venusTiles);
			this.cpicSprites = Map.copyOf(cpicSprites);
			this.borders = List.copyOf(borders);
		}

		public Path gameDir() { return gameDir; }
		public List<BufferedImage> marsTiles() { return marsTiles; }
		public List<BufferedImage> venusTiles() { return venusTiles; }
		public List<BufferedImage> terrainTiles(boolean venus) { return venus ? venusTiles : marsTiles; }
		public Map<Integer, BufferedImage> cpicSprites() { return cpicSprites; }
		public List<BufferedImage> borders() { return borders; }

		public BufferedImage terrainTile(boolean venus, int tileCode) {
			List<BufferedImage> tiles = terrainTiles(venus);
			if (tiles.isEmpty()) return null;
			int index = Math.max(0, tileCode - 1);
			if (index >= tiles.size()) index = Math.floorMod(index, tiles.size());
			return tiles.get(index);
		}

		public BufferedImage cpic(int id) { return cpicSprites.get(id); }
	}

	private static final int[][] GAME_STATIC = {
		{0,0,0,255},{0,0,170,255},{0,170,0,255},{0,170,170,255},
		{170,0,0,255},{170,0,170,255},{170,85,0,255},{170,170,170,255},
		{85,85,85,255},{85,85,255,255},{85,255,85,255},{85,255,255,255},
		{255,85,85,255},{255,85,255,255},{255,255,85,255},{255,255,255,255}
	};
	private static final int[][] SPRIT_STATIC = {
		{0,0,0,0},{0,0,170,255},{0,170,0,255},{0,170,170,255},
		{170,0,0,255},{170,0,170,255},{170,85,0,255},{170,170,170,255},
		{85,85,85,255},{85,85,255,255},{85,255,85,255},{85,255,255,255},
		{255,85,85,255},{0,0,0,255},{255,255,85,255},{255,255,255,255}
	};

	private CombatAssetLoader() {}

	public static Assets load(Path gameDir) throws IOException {
		if (!Files.isDirectory(gameDir)) throw new IOException("Game directory not found: " + gameDir);
		List<BufferedImage> mars = decodeBlockImages(gameDir.resolve("MARSCOM.DAX"), 1, ImageKind.SPRIT);
		List<BufferedImage> venus = decodeBlockImages(gameDir.resolve("VENUSCOM.DAX"), 1, ImageKind.SPRIT);
		Map<Integer, BufferedImage> cpic = transparentGreyBackdrop(decodeFirstImageByBlock(gameDir.resolve("CPIC1.DAX"), ImageKind.SPRIT));
		List<BufferedImage> borders = decodeBlockImages(gameDir.resolve("BORDERS.DAX"), 0, ImageKind.SPRIT);
		return new Assets(gameDir, mars, venus, cpic, borders);
	}

	public static List<BufferedImage> decodeBlockImages(Path daxPath, int blockId, ImageKind kind) throws IOException {
		byte[] block = readDaxBlocks(daxPath).get(blockId);
		if (block == null) return Collections.emptyList();
		return decodeVgaImages(block, kind);
	}

	public static Map<Integer, BufferedImage> decodeFirstImageByBlock(Path daxPath, ImageKind kind) throws IOException {
		Map<Integer, byte[]> blocks = readDaxBlocks(daxPath);
		Map<Integer, BufferedImage> result = new TreeMap<>();
		for (Map.Entry<Integer, byte[]> entry : blocks.entrySet()) {
			List<BufferedImage> images = decodeVgaImages(entry.getValue(), kind);
			if (!images.isEmpty()) result.put(entry.getKey(), images.get(0));
		}
		return result;
	}


	private static Map<Integer, BufferedImage> transparentGreyBackdrop(Map<Integer, BufferedImage> input) {
		Map<Integer, BufferedImage> result = new TreeMap<>();
		for (Map.Entry<Integer, BufferedImage> entry : input.entrySet()) {
			BufferedImage src = entry.getValue();
			BufferedImage dst = new BufferedImage(src.getWidth(), src.getHeight(), BufferedImage.TYPE_INT_ARGB);
			for (int y = 0; y < src.getHeight(); y++) {
				for (int x = 0; x < src.getWidth(); x++) {
					int argb = src.getRGB(x, y);
					int rgb = argb & 0x00FFFFFF;
					// CPIC sprites in this local Matrix Cubed set carry a flat
					// 0xAAAAAA/0x555555 backing field.  Treat only that exact game palette
					// color as transparent so combatants composite over terrain like
					// the original combat screenshots instead of appearing in boxes.
					if (rgb == 0xAAAAAA || rgb == 0x555555) {
						dst.setRGB(x, y, 0x00000000);
					} else {
						dst.setRGB(x, y, argb);
					}
				}
			}
			result.put(entry.getKey(), dst);
		}
		return result;
	}

	private static Map<Integer, byte[]> readDaxBlocks(Path path) throws IOException {
		byte[] file = Files.readAllBytes(path);
		ByteBuffer data = ByteBuffer.wrap(file).order(ByteOrder.LITTLE_ENDIAN);
		int byteCount = Short.toUnsignedInt(data.getShort(0));
		int headerCount = byteCount / 9;
		Map<Integer, byte[]> blocks = new TreeMap<>();
		for (int i = 0; i < headerCount; i++) {
			int headerStart = 2 + i * 9;
			int id = Byte.toUnsignedInt(file[headerStart]);
			int offset = data.getInt(headerStart + 1);
			int sizeRaw = Short.toUnsignedInt(data.getShort(headerStart + 5));
			int sizeCmp = Short.toUnsignedInt(data.getShort(headerStart + 7));
			int dataStart = 2 + byteCount + offset;
			byte[] compressed = new byte[sizeCmp];
			System.arraycopy(file, dataStart, compressed, 0, sizeCmp);
			blocks.put(id, uncompress(compressed, sizeRaw));
		}
		return blocks;
	}

	private static byte[] uncompress(byte[] compressed, int sizeRaw) throws IOException {
		byte[] result = new byte[sizeRaw];
		int in = 0, out = 0;
		while (in < compressed.length && out < result.length) {
			int next = compressed[in++];
			int count = Math.abs(next);
			if (next >= 0) {
				for (int i = 0; i < 1 + count && out < result.length && in < compressed.length; i++)
					result[out++] = compressed[in++];
			} else {
				if (in >= compressed.length) throw new IOException("Malformed DAX run.");
				byte repeat = compressed[in++];
				for (int i = 0; i < count && out < result.length; i++) result[out++] = repeat;
			}
		}
		return result;
	}

	private static List<BufferedImage> decodeVgaImages(byte[] block, ImageKind kind) {
		if (block.length < 10) return Collections.emptyList();
		int height = Byte.toUnsignedInt(block[0]);
		int width = 8 * Byte.toUnsignedInt(block[1]);
		int imageCount = u16(block, 6);
		int colorBase = Byte.toUnsignedInt(block[8]);
		int colorCount = 1 + Byte.toUnsignedInt(block[9]);
		if (height <= 0 || width <= 0 || imageCount <= 0) return Collections.emptyList();

		int[] palette = palette(kind);
		for (int i = 0; i < colorCount; i++) {
			int p = 10 + 3 * i;
			if (p + 2 >= block.length) break;
			int idx = colorBase + i;
			if (idx >= 0 && idx < palette.length) {
				int r = Math.min(255, Byte.toUnsignedInt(block[p]) << 2);
				int g = Math.min(255, Byte.toUnsignedInt(block[p + 1]) << 2);
				int b = Math.min(255, Byte.toUnsignedInt(block[p + 2]) << 2);
				palette[idx] = argb(0xFF, r, g, b);
			}
		}

		int imageSize = width * height;
		int imageOffset = block.length - imageCount * imageSize;
		if (imageOffset < 0) return Collections.emptyList();

		List<BufferedImage> result = new ArrayList<>();
		for (int img = 0; img < imageCount; img++) {
			BufferedImage bi = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
			int start = imageOffset + img * imageSize;
			for (int y = 0; y < height; y++)
				for (int x = 0; x < width; x++)
					bi.setRGB(x, y, palette[Byte.toUnsignedInt(block[start + y * width + x])]);
			result.add(bi);
		}
		return result;
	}

	private static int[] palette(ImageKind kind) {
		int[] result = new int[256];
		int[][] base = kind == ImageKind.SPRIT ? SPRIT_STATIC : GAME_STATIC;
		for (int h = 0; h < 0x100; h += 0x10)
			for (int i = 0; i < base.length; i++)
				result[h + i] = argb(base[i][3], base[i][0], base[i][1], base[i][2]);
		return result;
	}

	private static int u16(byte[] data, int index) {
		return Byte.toUnsignedInt(data[index]) | (Byte.toUnsignedInt(data[index + 1]) << 8);
	}
	private static int argb(int a, int r, int g, int b) {
		return ((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
	}

	public static Color goldBoxGreen() { return new Color(0x55FF55); }
}
