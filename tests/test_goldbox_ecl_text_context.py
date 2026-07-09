from __future__ import annotations

import json

from scripts.contextualize_goldbox_ecl_text import (
    ListingRow,
    context_for_hit,
    load_substring_missing_hits,
    parse_listing_rows,
)


def test_parse_listing_rows_reads_decoded_instruction_lines(tmp_path) -> None:
    listing = tmp_path / "ecl1_095.ecl.txt"
    listing.write_text(
        "\n".join(
            [
                "vm_run_1           0x96F5",
                "",
                "0x8053 0x25 ON GOTO area1.event_word_250 of [0x8303, 0x8791, 0x8063]",
                "0x8062 0x00 EXIT",
            ]
        ),
        encoding="utf-8",
    )

    rows = parse_listing_rows(listing)

    assert [row.address for row in rows] == [0x8053, 0x8062]
    assert rows[0].block_id == 95
    assert "ON GOTO" in rows[0].text


def test_context_for_hit_maps_offsets_to_vm_addresses_and_neighbors() -> None:
    hit = {"block_id": 95, "offset": 0x1091, "encoded_length": 6, "text": "CHOOSE:"}
    rows_by_block = {
        95: [
            ListingRow(95, 0x9080, "0x9080 0x11 PRINT 'CURRENT FUEL:'"),
            ListingRow(95, 0x90A0, "0x90A0 0x2B HORIZONTAL MENU area2.event_scratch0 MENU: 'A', 'B'"),
        ]
    }

    context = context_for_hit(hit, rows_by_block)

    assert context.vm_address == 0x9091
    assert context.previous_address == 0x9080
    assert context.next_address == 0x90A0
    assert context.context_kind == "near_menu_instruction"


def test_load_substring_missing_hits_reads_compare_json(tmp_path) -> None:
    compare = tmp_path / "ecl_text_compare.json"
    compare.write_text(
        json.dumps(
            {
                "comparison": {
                    "goldbox_substring_missing_hits": [
                        {"block_id": 1, "offset": 267, "encoded_length": 3, "text": "PREV"}
                    ]
                }
            }
        ),
        encoding="utf-8",
    )

    hits = load_substring_missing_hits(compare)

    assert hits == [{"block_id": 1, "offset": 267, "encoded_length": 3, "text": "PREV"}]
