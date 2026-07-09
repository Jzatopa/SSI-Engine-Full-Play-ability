from __future__ import annotations

import json
from pathlib import Path

from scripts.recover_skill_check_opcodes import recover_callsites


ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "generated" / "skill_check_recovery" / "2026-07-08"


def test_recover_skill_check_opcodes_finds_all_current_0x23_callsites() -> None:
    callsites, who_contexts = recover_callsites()

    assert [(row.block_id, row.address_hex) for row in callsites] == [
        (34, "0xA13D"),
        (95, "0x9705"),
        (98, "0xA21C"),
    ]
    assert {row.prompt for row in who_contexts} == {
        "WHO WILL REPROGRAM?",
        "WHO WILL FAST TALK?",
        "WHO MAKES THE ATTEMPT?",
    }


def test_constant_skill_check_operand_maps_to_recovered_skill_table() -> None:
    callsites, _ = recover_callsites()
    etiquette = next(row for row in callsites if row.block_id == 95 and row.address_hex == "0x9705")

    assert etiquette.current_listing_label == "SURPRISE"
    assert etiquette.matrix_candidate_label == "SKILL_CHECK"
    assert etiquette.first_operand_kind == "constant"
    assert etiquette.candidate_skill_id == 79
    assert etiquette.candidate_skill_name == "Etiquette"
    assert etiquette.candidate_who_offset == 0x9B
    assert etiquette.operands == ("79", "area2.event_scratch0", "area2.event_scratch1", "scratch.word_0002")


def test_variable_skill_check_operands_remain_unpromoted() -> None:
    callsites, _ = recover_callsites()
    variable_rows = [row for row in callsites if row.first_operand_kind == "variable"]

    assert [(row.block_id, row.address_hex, row.candidate_skill_name) for row in variable_rows] == [
        (34, "0xA13D", None),
        (98, "0xA21C", None),
    ]
    assert all("require local VM/DOS validation" in row.evidence_limit for row in variable_rows)


def test_generated_skill_check_artifacts_match_recovery() -> None:
    callsites, who_contexts = recover_callsites()
    generated_callsites = json.loads((OUT_DIR / "skill_check_opcodes.json").read_text(encoding="utf-8"))
    generated_who = json.loads((OUT_DIR / "who_contexts.json").read_text(encoding="utf-8"))

    assert len(generated_callsites) == len(callsites) == 3
    assert len(generated_who) == len(who_contexts) == 3
    assert generated_callsites[1]["candidate_skill_name"] == "Etiquette"
    assert generated_callsites[1]["candidate_who_offset"] == 0x9B
