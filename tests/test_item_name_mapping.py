from __future__ import annotations

import json
from pathlib import Path

from scripts.analyze_item_name_mapping import (
    build_report,
    compare_record_counts,
    decode_items_detail_fields,
    decode_items_records,
    decode_item0_name_records,
    extract_start_item_name_parts,
    item_index_like_fields,
)
from scripts.game_paths import default_game_dir

GAME_DIR = default_game_dir()


def test_compare_record_counts_rejects_direct_name_table_mismatch() -> None:
    result = compare_record_counts(item_count=91, item_side_count=39)

    assert result["one_record_per_item_possible"] is False
    assert "cannot be a direct one-record-per-ITEM0-name table" in result["verdict"]


def test_decode_items_records_requires_nine_byte_records(tmp_path: Path) -> None:
    path = tmp_path / "ITEMS"
    path.write_bytes(b"\x00" * 18)

    rows = decode_items_records(path)

    assert len(rows) == 2
    assert rows[0]["offset"] == 0
    assert rows[1]["offset"] == 9
    assert rows[0]["fields"]["type_code"] == 0


def test_decode_items_detail_fields_keeps_semantics_candidate() -> None:
    fields = decode_items_detail_fields(bytes.fromhex("00 04 00 00 01 03 00 00 00"))

    assert fields["type_code"] == 0
    assert fields["large_damage_candidate"] == {"dice": 0, "sides": 4, "bonus": 0}
    assert fields["medium_damage_candidate"] == {"dice": 1, "sides": 3, "bonus": 0}
    assert fields["range_candidate"] == 0
    assert fields["flags_candidate"] == 0


def test_item_index_like_fields_are_reported_as_weak_candidates() -> None:
    records = [
        {"index": 0, "raw_hex": "00", "u16_0": 1024, "u16_1": 54, "u16_2": 0, "u16_3": 0, "byte_8": 0},
        {"index": 1, "raw_hex": "00", "u16_0": 512, "u16_1": 150, "u16_2": 200, "u16_3": 300, "byte_8": 255},
    ]

    rows = item_index_like_fields(records, item_count=91)

    assert {"record_index": 0, "field": "u16_1", "value": 54, "raw_hex": "00"} in rows
    assert any(row["field"] == "byte_8" and row["value"] == 0 for row in rows)


def test_extract_start_item_name_parts_assigns_matrix_codes() -> None:
    rows = extract_start_item_name_parts(GAME_DIR / "START.EXE")

    assert rows[0]["code"] == 0
    assert rows[0]["text"] == ""
    assert rows[1]["text"] == "Knife"
    assert rows[2]["text"] == "Mono"
    assert rows[44]["text"] == "mini"
    assert rows[45]["text"] == "BLANK ITEM"


def test_decode_item0_name_records_uses_bytes_3_2_1_as_name_codes() -> None:
    name_parts = [
        {"code": 0, "text": ""},
        {"code": 1, "text": "Knife"},
        {"code": 2, "text": "Mono"},
        {"code": 3, "text": "Cutlass"},
    ]
    templates = [
        {"index": 0, "raw_hex": "01 00 00 01 00 00 20 00 01 00 00 0a 00 00 00 00"},
        {"index": 1, "raw_hex": "02 00 01 02 00 00 20 00 01 00 00 c8 00 00 00 00"},
    ]

    detail_records = [
        {
            "index": 1,
            "offset": 9,
            "raw_hex": "00 04 00 00 01 03 00 00 00",
            "bytes": [0, 4, 0, 0, 1, 3, 0, 0, 0],
            "fields": decode_items_detail_fields(bytes.fromhex("00 04 00 00 01 03 00 00 00")),
        },
        {
            "index": 2,
            "offset": 18,
            "raw_hex": "00 04 00 00 01 06 00 00 00",
            "bytes": [0, 4, 0, 0, 1, 6, 0, 0, 0],
            "fields": decode_items_detail_fields(bytes.fromhex("00 04 00 00 01 06 00 00 00")),
        },
    ]

    rows = decode_item0_name_records(templates, name_parts, detail_records)

    assert rows[0]["itemptr"] == 1
    assert rows[0]["name_codes"] == [1, 0, 0]
    assert rows[0]["name"] == "Knife"
    assert rows[0]["items_detail_record"]["fields"]["medium_damage_candidate"] == {"dice": 1, "sides": 3, "bonus": 0}
    assert rows[1]["name_codes"] == [2, 1, 0]
    assert rows[1]["name"] == "Mono Knife"


def test_build_report_decodes_names_while_rejecting_items_as_text_table(tmp_path: Path) -> None:
    items_path = tmp_path / "ITEMS"
    items_path.write_bytes(
        b"".join(
            [
                bytes.fromhex("00 00 00 00 00 00 00 00 00"),
                bytes.fromhex("00 04 00 00 01 03 00 00 00"),
                bytes.fromhex("00 04 00 00 01 06 00 00 00"),
                bytes.fromhex("00 04 00 00 01 06 00 00 00"),
            ]
        )
    )
    templates_path = tmp_path / "item0_templates.json"
    templates_path.write_text(
        json.dumps(
            [
                {"index": 0, "raw_hex": "01 00 00 01 00 00 20 00 01 00 00 0a 00 00 00 00"},
                {"index": 1, "raw_hex": "02 00 01 02 00 00 20 00 01 00 00 c8 00 00 00 00"},
                {"index": 2, "raw_hex": "03 00 00 03 00 00 20 00 04 00 00 64 00 00 00 00"},
            ]
        ),
        encoding="utf-8",
    )

    report = build_report(
        items_path,
        templates_path,
        GAME_DIR / "START.EXE",
    )

    assert report["record_count_check"]["one_record_per_item_possible"] is False
    assert report["items_text_check"]["ascii_string_count"] == 0
    assert report["items_text_check"]["pascal_candidate_count"] == 0
    assert report["item0_name_records"][0]["name"] == "Knife"
    assert report["item0_name_summary"]["missing_items_detail_record_count"] == 0
    assert report["item0_name_records"][0]["items_detail_record"]["fields"]["medium_damage_candidate"] == {
        "dice": 1,
        "sides": 3,
        "bonus": 0,
    }
    assert report["items_detail_layout"]["alignment"].startswith("1-based by ITEM0 itemptr")
    assert "blocker is narrowed" in report["overall_verdict"]
