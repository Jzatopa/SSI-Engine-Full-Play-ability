from __future__ import annotations

from scripts.compare_goldbox_ecl_text import (
    decompress_goldbox_ecl_string,
    extract_goldbox_ecl_texts,
    is_goldbox_readable_text,
)


def pack_ecl_text(text: str) -> bytes:
    codes = []
    for ch in text:
        value = ord(ch)
        if 0x40 < value <= 0x5F:
            value -= 0x40
        codes.append(value & 0x3F)

    out = bytearray()
    for index in range(0, len(codes), 4):
        a, b, c, d = (codes[index : index + 4] + [0, 0, 0, 0])[:4]
        out.append((a << 2) | (b >> 4))
        out.append(((b & 0x0F) << 4) | (c >> 2))
        out.append(((c & 0x03) << 6) | d)
    return bytes(out)


def test_goldbox_ecl_6bit_string_decode_roundtrips_reference_alphabet() -> None:
    packed = pack_ecl_text("HELLO WORLD")

    assert decompress_goldbox_ecl_string(packed).strip() == "HELLO WORLD"


def test_goldbox_whole_block_scan_finds_readable_0x80_strings() -> None:
    packed = pack_ecl_text("WELCOME PILOT")
    block = b"\x01\x02\x99" + bytes([0x80, len(packed)]) + packed + b"\x00"

    hits = extract_goldbox_ecl_texts(17, block)

    assert len(hits) == 1
    assert hits[0].block_id == 17
    assert hits[0].offset == 3
    assert hits[0].text == "WELCOME PILOT"


def test_goldbox_readability_filter_matches_reference_rejections() -> None:
    assert is_goldbox_readable_text("WELCOME PILOT")
    assert not is_goldbox_readable_text("A_B")
    assert not is_goldbox_readable_text("1234")
    assert not is_goldbox_readable_text("ABCDEFGHIJKLMNOP")
