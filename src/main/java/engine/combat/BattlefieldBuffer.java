package engine.combat;

import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

public final class BattlefieldBuffer {
	public static final int HEADER_SIZE = 7;
	public static final int WIDTH = 50;
	public static final int HEIGHT = 25;

	private final byte[] bytes = new byte[HEADER_SIZE + WIDTH * HEIGHT];

	public BattlefieldBuffer() {
		bytes[0] = (byte) WIDTH;
		bytes[1] = (byte) HEIGHT;
	}

	public void setOriginalRawTile(int x, int y, int rawTile) {
		if (!isInside(x, y)) {
			return;
		}
		bytes[HEADER_SIZE + y * WIDTH + x] = (byte) ((rawTile + 1) & 0xFF);
	}

	public void setTileCode(int x, int y, int tileCode) {
		if (!isInside(x, y)) {
			return;
		}
		bytes[HEADER_SIZE + y * WIDTH + x] = (byte) (tileCode & 0xFF);
	}

	public int getTileCode(int x, int y) {
		if (!isInside(x, y)) {
			return 0;
		}
		return bytes[HEADER_SIZE + y * WIDTH + x] & 0xFF;
	}

	public byte[] toByteArray() {
		return Arrays.copyOf(bytes, bytes.length);
	}

	public Map<Integer, Integer> histogram() {
		Map<Integer, Integer> result = new TreeMap<>();
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				int code = getTileCode(x, y);
				if (code != 0) {
					result.merge(code, 1, Integer::sum);
				}
			}
		}
		return result;
	}

	private boolean isInside(int x, int y) {
		return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
	}
}
