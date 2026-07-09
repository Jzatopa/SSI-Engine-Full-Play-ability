package engine.script;

import static org.junit.Assert.assertEquals;

import java.io.ByteArrayOutputStream;

import org.junit.Test;

public class EclArgumentTextDecoderTest {
	@Test
	public void decodesTheSharedGoldBoxPackedAlphabet() {
		assertEquals("HELLO WORLD", EclArgument.decompressString(pack("HELLO WORLD")).toString().trim());
	}

	@Test
	public void suppressesZeroPaddingCodes() {
		assertEquals("A", EclArgument.decompressString(pack("A")).toString());
	}

	private byte[] pack(String text) {
		int[] codes = new int[text.length()];
		for (int i = 0; i < text.length(); i++) {
			int value = text.charAt(i);
			if (value > 0x40 && value <= 0x5F) value -= 0x40;
			codes[i] = value & 0x3F;
		}
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		for (int i = 0; i < codes.length; i += 4) {
			int a = codes[i];
			int b = i + 1 < codes.length ? codes[i + 1] : 0;
			int c = i + 2 < codes.length ? codes[i + 2] : 0;
			int d = i + 3 < codes.length ? codes[i + 3] : 0;
			out.write((a << 2) | (b >> 4));
			out.write(((b & 0x0F) << 4) | (c >> 2));
			out.write(((c & 0x03) << 6) | d);
		}
		return out.toByteArray();
	}
}
