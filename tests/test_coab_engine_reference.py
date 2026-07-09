from __future__ import annotations

from scripts.audit_coab_engine_reference import (
    audit_maps,
    decompress_packed_6bit_bitstream,
    packed_string_candidates,
)
from scripts.game_paths import default_game_dir
from tests.test_goldbox_ecl_text import pack_ecl_text


def test_independent_bitstream_decoder_matches_reference_text() -> None:
    assert decompress_packed_6bit_bitstream(pack_ecl_text("HELLO WORLD")).strip() == "HELLO WORLD"


def test_packed_string_candidates_reject_truncated_payloads() -> None:
    packed = pack_ecl_text("VALID TEXT")
    data = bytes([0x80, len(packed)]) + packed + b"\x80\xff"

    assert packed_string_candidates(data) == [(0, packed)]


def test_coab_geo_layout_cross_check_matches_local_matrix_data() -> None:
    report = audit_maps(default_game_dir() / "GEO1.DAX")

    assert report["block_count"] == 25
    assert report["checked_cells"] == 25 * 256
    assert report["layout_mismatch_count"] == 0
