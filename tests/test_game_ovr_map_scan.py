from __future__ import annotations

from dataclasses import dataclass

from scripts.scan_game_ovr_maps import (
    GEO_BLOCK_SIZE,
    scan_exact_blocks,
    scan_overlay_for_geo_windows,
    score_geo_window,
)


@dataclass(frozen=True)
class KnownBlock:
    block_id: int
    data: bytes


def make_geo_like_block(header: bytes = b"\xcc\xdd", wall: int = 5) -> bytes:
    block = bytearray(GEO_BLOCK_SIZE)
    block[:2] = header
    for index in range(256):
        row, col = divmod(index, 16)
        north = wall if row == 0 else (6 if row % 4 == 0 else 0)
        south = wall if row == 15 else (6 if (row + 1) % 4 == 0 else 0)
        west = wall if col == 0 else (7 if col % 4 == 0 else 0)
        east = wall if col == 15 else (7 if (col + 1) % 4 == 0 else 0)
        block[2 + index] = (north << 4) | east
        block[258 + index] = (south << 4) | west
    block[514:770] = bytes([0x80]) * 256
    block[770:1026] = bytes([0]) * 256
    return bytes(block)


def test_score_geo_window_accepts_consistent_geo_shaped_data() -> None:
    block = make_geo_like_block()

    metrics = score_geo_window(32, block, {0, 1, 4, 16, 64})

    assert metrics.accepted
    assert metrics.offset == 32
    assert metrics.north_south_match_ratio == 1.0
    assert metrics.east_west_match_ratio == 1.0
    assert metrics.known_door_ratio == 1.0
    assert metrics.max_event_id == 0


def test_scan_overlay_rejects_header_match_with_non_geo_layout() -> None:
    known = [KnownBlock(1, make_geo_like_block())]  # type: ignore[list-item]
    bad = bytearray(GEO_BLOCK_SIZE)
    bad[:2] = b"\xcc\xdd"
    bad[2:] = bytes((index * 37) % 256 for index in range(GEO_BLOCK_SIZE - 2))

    report = scan_overlay_for_geo_windows(bytes(bad), known)  # type: ignore[arg-type]

    assert report["header_hit_count"] == 1
    assert report["accepted_candidate_count"] == 0
    assert report["top_header_hits"][0]["rejection_reasons"]


def test_scan_exact_blocks_reports_embedded_known_block_offset() -> None:
    block = make_geo_like_block()
    known = [KnownBlock(17, block)]  # type: ignore[list-item]
    overlay = b"prefix" + block + b"suffix"

    rows = scan_exact_blocks(overlay, known)  # type: ignore[arg-type]

    assert rows == [
        {
            "geo_id": 17,
            "decoded_sha256": rows[0]["decoded_sha256"],
            "found_in_game_ovr": True,
            "offset": len(b"prefix"),
        }
    ]
