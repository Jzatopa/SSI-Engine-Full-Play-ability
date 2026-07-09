from __future__ import annotations

import json
from pathlib import Path

from scripts.build_ecl_dialog_reference import (
    AttachedMissingText,
    Instruction,
    attach_contexts,
    build_dialog_conversations,
    build_regions,
    parse_listing,
)
from scripts.contextualize_goldbox_ecl_text import TextContext


ROOT = Path(__file__).resolve().parents[1]


def test_parse_listing_reads_entries_instructions_and_on_goto_targets(tmp_path) -> None:
    listing = tmp_path / "ecl1_095.ecl.txt"
    listing.write_text(
        "\n".join(
            [
                "vm_run_1           0x96F5",
                "SearchLocation     0x96F5",
                "",
                "0x8053 0x25 ON GOTO area1.event_word_250 of [0x8303, 0x8791, 0x8063]",
                "0x8063 0x12 PRINTCLEAR 'HELLO'",
            ]
        ),
        encoding="utf-8",
    )

    block_id, entries, instructions = parse_listing(listing)

    assert block_id == 95
    assert entries == [("vm_run_1", 0x96F5), ("SearchLocation", 0x96F5)]
    assert [instruction.address for instruction in instructions] == [0x8053, 0x8063]


def test_build_regions_labels_on_goto_choice_incoming() -> None:
    instructions = [
        Instruction(95, 0x8053, 0x25, "ON GOTO area1.event_word_250 of [0x8303, 0x8791, 0x8063]", "row on goto"),
        Instruction(95, 0x8063, 0x12, "PRINTCLEAR 'THIRD'", "row print"),
        Instruction(95, 0x8303, 0x12, "PRINTCLEAR 'FIRST'", "row print first"),
    ]

    regions = build_regions({95: [("vm_run_1", 0x8053)]}, {95: instructions})[95]

    region_8063 = next(region for region in regions if region.target == 0x8063)
    assert "0x8053 ON GOTO area1.event_word_250 choice 2" in region_8063.incoming


def test_attach_contexts_uses_branch_region_and_unique_normalized_index() -> None:
    contexts = [
        TextContext(
            block_id=95,
            offset=0x0650,
            vm_address=0x8650,
            encoded_length=6,
            text="REFUEL",
            previous_address=0x8600,
            previous_distance=0x50,
            previous_row="0x8600 0x12 PRINTCLEAR 'FUEL DEPOT'",
            next_address=0x8700,
            next_distance=0xB0,
            next_row="0x8700 0x01 GOTO 0x9000",
            context_kind="short_choice_or_label",
        ),
        TextContext(
            block_id=95,
            offset=0x0660,
            vm_address=0x8660,
            encoded_length=6,
            text="REFUEL",
            previous_address=0x8600,
            previous_distance=0x60,
            previous_row="0x8600 0x12 PRINTCLEAR 'FUEL DEPOT'",
            next_address=0x8700,
            next_distance=0xA0,
            next_row="0x8700 0x01 GOTO 0x9000",
            context_kind="short_choice_or_label",
        ),
    ]
    instructions = [
        Instruction(95, 0x8500, 0x12, "PRINTCLEAR 'FUEL DEPOT'", "0x8500 0x12 PRINTCLEAR 'FUEL DEPOT'"),
        Instruction(95, 0x8700, 0x01, "GOTO 0x9000", "0x8700 0x01 GOTO 0x9000"),
    ]
    regions = build_regions({95: [("vm_run_1", 0x8500)]}, {95: instructions})

    attached = attach_contexts(contexts, regions)

    assert {item.unique_index for item in attached} == {1}
    assert all(item.owner_target == 0x8500 for item in attached)
    assert all(item.attachment_kind == "branch_target_region" for item in attached)


def test_build_dialog_conversations_compiles_menu_labels_and_branch_targets() -> None:
    instructions = [
        Instruction(17, 0x9000, 0x12, "PRINTCLEAR 'DO YOU HELP?'", "0x9000 0x12 PRINTCLEAR 'DO YOU HELP?'"),
        Instruction(17, 0x9010, 0x12, "MENU: 'YES', 'NO'", "0x9010 0x12 MENU: 'YES', 'NO'"),
        Instruction(17, 0x9020, 0x12, "ON GOTO area2.event_scratch1 of [0x9100, 0x9200]", "0x9020 0x12 ON GOTO area2.event_scratch1 of [0x9100, 0x9200]"),
    ]
    regions = build_regions({17: [("vm_run_1", 0x9000)]}, {17: instructions})
    atlas = {
        17: {
            "geo_id": 17,
            "name": "Caloris Space Port",
            "events": {"20": {"target": 0x9000, "text": "'DO YOU HELP?'"}},
        }
    }

    conversations = build_dialog_conversations([], regions, atlas)

    assert len(conversations) == 1
    assert conversations[0]["geo_id"] == 17
    assert conversations[0]["event_id"] == 20
    assert conversations[0]["confidence"] == "menu_instruction"
    assert [choice["label"] for choice in conversations[0]["choices"]] == ["YES", "NO"]
    assert [choice["branch_target_hex"] for choice in conversations[0]["choices"]] == ["0x9100", "0x9200"]


def test_build_dialog_conversations_uses_attached_choice_labels_with_boundary() -> None:
    instructions = [
        Instruction(17, 0x96CF, 0x12, "PRINTCLEAR 'PLEASE HELP ME.'", "0x96CF 0x12 PRINTCLEAR 'PLEASE HELP ME.'"),
    ]
    regions = build_regions({17: [("vm_run_1", 0x96CF)]}, {17: instructions})
    attached = [
        AttachedMissingText(
            block_id=17,
            offset=0x08E0,
            vm_address=0x98E0,
            encoded_length=9,
            text="HELP ROMNEY",
            normalized_text="HELP ROMNEY",
            unique_index=1,
            attachment_kind="branch_target_region",
            owner_target=0x96CF,
            owner_incoming=("0x8510 ON GOTO area2.event_scratch1 choice 20",),
            owner_summary="0x96CF 0x12 PRINTCLEAR 'PLEASE HELP ME.'",
            previous_row="0x96CF 0x12 PRINTCLEAR 'PLEASE HELP ME.'",
            previous_distance=0x211,
            next_row=None,
            next_distance=None,
            context_kind="short_choice_or_label",
        )
    ]
    atlas = {
        17: {
            "geo_id": 17,
            "name": "Caloris Space Port",
            "events": {"20": {"target": 0x96CF, "text": "'PLEASE HELP ME.'"}},
        }
    }

    conversations = build_dialog_conversations(attached, regions, atlas)

    assert len(conversations) == 1
    assert conversations[0]["confidence"] == "attached_missing_text_near_branch"
    assert conversations[0]["choices"][0]["label"] == "HELP ROMNEY"
    assert conversations[0]["choices"][0]["branch_target"] is None
    assert "not ownership proof" in conversations[0]["evidence_limit"]


def test_generated_dialog_conversations_match_reference_summary() -> None:
    reference = json.loads((ROOT / "generated" / "ecl_text_goldbox" / "ecl_dialog_reference.json").read_text(encoding="utf-8"))
    conversations = json.loads((ROOT / "generated" / "ecl_text_goldbox" / "ecl_dialog_conversations.json").read_text(encoding="utf-8"))

    assert reference["summary"]["dialog_conversation_count"] == len(conversations) == 14

    by_event = {(row["geo_id"], row["event_id"]): row for row in conversations}
    romney = by_event[(17, 20)]
    autodoc = by_event[(17, 28)]

    assert romney["event_target_hex"] == "0x96CF"
    assert [choice["label"] for choice in romney["choices"]] == ["HELP ROMNEY"]
    assert romney["confidence"] == "attached_missing_text_near_branch"
    assert "not ownership proof" in romney["evidence_limit"]

    assert autodoc["event_target_hex"] == "0xA0AA"
    assert [choice["label"] for choice in autodoc["choices"]] == ["SOMEONE ELSE?"]
    assert autodoc["confidence"] == "attached_missing_text_near_branch"
