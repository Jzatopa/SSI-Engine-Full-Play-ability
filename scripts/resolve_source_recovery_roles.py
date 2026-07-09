#!/usr/bin/env python3
"""Resolve the 23 source-recovery role hypotheses into static triage decisions."""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
SOURCE_RECOVERY = ROOT / "generated" / "source_recovery"
INFERENCE_JSON = SOURCE_RECOVERY / "function_role_inference.json"
OUT_JSON = SOURCE_RECOVERY / "function_role_resolution.json"
OUT_MD = SOURCE_RECOVERY / "function_role_resolution.md"


RESOLUTIONS: dict[str, dict[str, str]] = {
    "0000:016c": {
        "status": "resolved_static",
        "resolved_role": "overlay_startup_state_init",
        "summary": "Calls a shared initializer, sets global flag 0x4417, and copies global mode/state byte 0x3ddb into 0x50d2.",
        "implementation_use": "Use as evidence for overlay/global state initialization, not as a credits routine.",
        "next_validation": "Find callers around overlay entry and compare 0x4417/0x50d2 meanings against runtime state transitions.",
    },
    "0000:0385": {
        "status": "resolved_bad_decode",
        "resolved_role": "bad_decode_or_mixed_code_data_near_credits_anchor",
        "summary": "Ghidra reports overlapping instructions, bad instruction data, abnormal stack setup, and removed blocks.",
        "implementation_use": "Do not lift this pseudocode; treat the address as a bad entry or mixed code/data island.",
        "next_validation": "Inspect raw bytes and Ghidra disassembly manually before assigning any behavior.",
    },
    "0000:fb92": {
        "status": "resolved_static",
        "resolved_role": "combat_roster_and_battlefield_setup",
        "summary": "Initializes combat tables, walks the party linked list, records combatant pointers, status/facing, visibility, and battlefield placement entries.",
        "implementation_use": "Use to validate combat start roster construction and initial placement logic.",
        "next_validation": "Compare combatant table counts and positions against a DOS combat capture.",
    },
    "1000:0131": {
        "status": "resolved_stub_or_boundary",
        "resolved_role": "empty_combat_boundary_candidate",
        "summary": "Decompiles to a tiny return-only function near the combat_start anchor.",
        "implementation_use": "Do not lift as combat logic; keep as possible boundary, padding, or misidentified function start.",
        "next_validation": "Check neighboring raw bytes and cross-references before deleting from the combat cluster.",
    },
    "1000:8467": {
        "status": "resolved_static",
        "resolved_role": "character_record_initial_field_fill",
        "summary": "Loops 0x55 bytes, calls a byte-producing helper, and writes into the active character record at offset +0x4d onward.",
        "implementation_use": "Use to validate character-creation default/stat/equipment field initialization.",
        "next_validation": "Compare generated character records after DOS character creation with reconstructed defaults.",
    },
    "1000:8e7d": {
        "status": "resolved_static",
        "resolved_role": "character_roster_remove_and_compact",
        "summary": "If a roster/entry marker equals 7, removes an entry and compacts subsequent character indices while decrementing the active count.",
        "implementation_use": "Use to validate character removal or rejected-created-character roster compaction.",
        "next_validation": "Capture DOS behavior for deleting/dropping a created character and compare roster order.",
    },
    "1000:c010": {
        "status": "resolved_static",
        "resolved_role": "shop_item_grant_or_inventory_insert",
        "summary": "Builds item records from table bytes, links them into the active character inventory list, and marks an item flag bit.",
        "implementation_use": "Use to validate shop purchase/reward item insertion.",
        "next_validation": "Compare inventory linked-list changes after buying known shop items.",
    },
    "1000:ce56": {
        "status": "resolved_stub_or_boundary",
        "resolved_role": "empty_shop_boundary_candidate",
        "summary": "Decompiles to a tiny return-only function near the shop_menu anchor.",
        "implementation_use": "Do not lift as shop logic; likely boundary/padding or bad function start.",
        "next_validation": "Inspect neighboring shop-menu code and xrefs.",
    },
    "1000:eb60": {
        "status": "resolved_static",
        "resolved_role": "item_type_classification_dispatch",
        "summary": "Reads an item type byte from the loaded item table and dispatches item classes 1..6 through FUN_1000_cf61; otherwise advances the item pointer.",
        "implementation_use": "Use to validate ITEM0 category mapping and item-detail decode.",
        "next_validation": "Compare dispatch buckets against decoded ITEM0 names and item detail records.",
    },
    "1000:eeec": {
        "status": "resolved_static",
        "resolved_role": "equipment_flag_postprocess_or_active_item_refresh",
        "summary": "Checks equipment/status flags at 0x8c33..0x8c3a, clears them, updates globals, and calls display/result helpers.",
        "implementation_use": "Use as evidence for post-item/equipment state refresh, not base item loading.",
        "next_validation": "Trigger equip/unequip/use flows in DOS and compare flags/UI side effects.",
    },
    "1000:f67d": {
        "status": "resolved_static",
        "resolved_role": "save_slot_or_filename_selection_validation",
        "summary": "Uses large stack buffers, menu/input/file helper calls, and returns a success flag after validating selected save/character output.",
        "implementation_use": "Use to validate save-character/save-slot prompting and file validation.",
        "next_validation": "Compare DOS save prompts and invalid-slot behavior.",
    },
    "1000:fad0": {
        "status": "resolved_static",
        "resolved_role": "save_character_or_save_game_writer_preflight",
        "summary": "Calls the save selection helper, computes serialized linked-list sizes, copies party/character state, checks output size, and branches into write/error routines.",
        "implementation_use": "Use to validate save serialization sizing and character-state fields.",
        "next_validation": "Compare produced SAVGAMA/character-save byte lengths and selected offsets.",
    },
    "1000:fb92": {
        "status": "resolved_static",
        "resolved_role": "save_linked_item_chain_writer_continuation",
        "summary": "Walks a linked chain at character offsets 0xfb/0xfd in 9-byte increments and calls save/write helpers, including the save writer.",
        "implementation_use": "Use to validate serialized item-chain layout.",
        "next_validation": "Compare saved inventory/equipment item-chain bytes against DOS saves.",
    },
    "2000:13fd": {
        "status": "resolved_static",
        "resolved_role": "save_serialized_party_size_calculator",
        "summary": "Walks party members and nested linked item/equipment chains to compute serialized save size using 0x103, 0x3e, and 9-byte record increments.",
        "implementation_use": "Use to validate save sizing before save/load byte-format work.",
        "next_validation": "Assert computed size against known DOS save samples.",
    },
    "2000:1c53": {
        "status": "resolved_stub_or_boundary",
        "resolved_role": "empty_save_boundary_candidate",
        "summary": "Decompiles to a tiny return-only function near the save_game anchor.",
        "implementation_use": "Do not lift as save logic; keep as boundary/padding candidate.",
        "next_validation": "Inspect adjacent save-game bytes and xrefs.",
    },
    "2000:1fd4": {
        "status": "resolved_static",
        "resolved_role": "character_inventory_chain_count",
        "summary": "Counts linked records from a character pointer at offsets 0xf7/0xf9 by following +0x2a/+0x2c next pointers.",
        "implementation_use": "Use to validate character sheet inventory counts.",
        "next_validation": "Compare count with visible character sheet inventory slots.",
    },
    "2000:25a1": {
        "status": "resolved_static",
        "resolved_role": "character_sheet_text_or_buffer_emit_helper",
        "summary": "Calls a display/setup helper and copies up to 0xff bytes into a local text/display buffer.",
        "implementation_use": "Use as character-sheet display helper evidence only.",
        "next_validation": "Trace caller context and compare emitted text in DOS character sheet.",
    },
    "2000:2986": {
        "status": "resolved_static",
        "resolved_role": "inventory_item_line_formatter",
        "summary": "Chooses display attribute 0x0d/0x0f, fetches item-related text/data through FUN_0000_733e, and writes a short display buffer.",
        "implementation_use": "Use to validate inventory/gear list line rendering.",
        "next_validation": "Compare inventory line highlighting/equipped markers in DOS.",
    },
    "2000:3ea6": {
        "status": "resolved_static",
        "resolved_role": "equipped_item_category_search",
        "summary": "Walks a character item chain, filters equipped/flagged records, and returns the first item whose category table entry matches the requested category.",
        "implementation_use": "Use to validate equipped item lookup by item category.",
        "next_validation": "Compare weapon/armor selection effects against item category table.",
    },
    "2000:b749": {
        "status": "resolved_static",
        "resolved_role": "ship_effective_rating_with_damage_penalties",
        "summary": "Checks whether a ship/vehicle record is valid, adds active/alternate modifiers, applies damage penalties, and clamps the result to at least 1.",
        "implementation_use": "Use to validate ship movement/maneuver/status derived values.",
        "next_validation": "Compare ship stats before and after hull/system damage in DOS.",
    },
    "2000:b876": {
        "status": "resolved_static",
        "resolved_role": "ship_status_flag_and_message_emit",
        "summary": "Sets global ship status flag 0x535b based on mode and ship record state, calls a UI helper, then emits a message/display block.",
        "implementation_use": "Use to validate ship status UI and travel gating.",
        "next_validation": "Compare status/message display for active ship versus alternate target.",
    },
    "3000:006f": {
        "status": "resolved_static",
        "resolved_role": "wall_segment_decode_or_emit_routine",
        "summary": "Runs repeated 4/3/2-count loops over byte-producing helpers and emit helpers, matching a span/segment decode pattern before the WALLDEF/Load3DMap string/data region.",
        "implementation_use": "Use as candidate wall segment decoder/emitter. Raw disassembly resolves it as not the Load3DMap file-load/copy routine.",
        "next_validation": "Trace helper xrefs and compare emitted sequence against WALLDEF rendering artifacts.",
    },
    "3000:0c04": {
        "status": "resolved_bad_decode",
        "resolved_role": "misaligned_load3dmap_epilogue_entry",
        "summary": "Ghidra entry 3000:0c04 lands inside the instruction at payload 0x30C01 in the Load3DMap-shaped routine epilogue, so the tiny return decompile is a misaligned-entry artifact.",
        "implementation_use": "Do not lift as a function. The resolved Load3DMap-shaped code window is payload 0x30AD0-0x30C10.",
        "next_validation": "Use generated/source_recovery/load3dmap_cluster_resolution.md before making map-loader runtime changes.",
    },
}


def load_inference_rows() -> dict[str, dict[str, Any]]:
    report = json.loads(INFERENCE_JSON.read_text(encoding="utf-8"))
    game = next(program for program in report["programs"] if program["key"] == "game_ovr_payload")
    return {row["entry"]: row for row in game["functions"] if row["likely_roles"] != ["unknown"]}


def build_resolution() -> dict[str, Any]:
    rows = load_inference_rows()
    missing = sorted(set(rows) - set(RESOLUTIONS))
    extra = sorted(set(RESOLUTIONS) - set(rows))
    if missing or extra:
        raise ValueError(f"resolution mismatch missing={missing} extra={extra}")

    resolved = []
    for entry, row in sorted(rows.items(), key=lambda item: item[1]["linear"]):
        resolution = RESOLUTIONS[entry]
        resolved.append(
            {
                **resolution,
                "entry": entry,
                "name": row["name"],
                "previous_likely_roles": row["likely_roles"],
                "previous_confidence": row["confidence"],
                "original_file_offset": row["original_file_offset"],
                "body_addresses": row["body_addresses"],
                "outbound_call_count": row["outbound_call_count"],
                "memory_ref_count": row["memory_ref_count"],
                "anchor_evidence": row["anchor_evidence"],
                "recovered_file": row["recovered_file"],
            }
        )

    status_counts: dict[str, int] = {}
    for row in resolved:
        status_counts[row["status"]] = status_counts.get(row["status"], 0) + 1
    report = {
        "description": "Static resolution pass for the 23 GAME.OVR source-recovery role hypotheses.",
        "limits": [
            "Resolved means removed from the unknown queue by static evidence.",
            "Resolved does not mean runtime-validated or original-name recovery.",
            "Stub/boundary and bad-decode resolutions are intentionally not liftable into runtime behavior.",
        ],
        "summary": {
            "candidate_count": len(resolved),
            "resolved_count": len(resolved),
            "status_counts": dict(sorted(status_counts.items())),
        },
        "resolutions": resolved,
    }
    OUT_JSON.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(report)
    return report


def write_markdown(report: dict[str, Any]) -> None:
    lines = [
        "# Source Recovery Function Role Resolution",
        "",
        "This resolves the 23 GAME.OVR role hypotheses into static triage decisions.",
        "Resolved here means no longer unknown; it does not mean runtime-validated.",
        "",
        "## Summary",
        "",
        f"- Candidates: `{report['summary']['candidate_count']}`",
        f"- Resolved static decisions: `{report['summary']['resolved_count']}`",
        f"- Status counts: `{report['summary']['status_counts']}`",
        "",
        "## Resolutions",
        "",
        "| Status | Resolved role | Function | Offset | Summary | Use | File |",
        "|---|---|---|---:|---|---|---|",
    ]
    for row in report["resolutions"]:
        lines.append(
            "| "
            + " | ".join(
                [
                    f"`{row['status']}`",
                    f"`{row['resolved_role']}`",
                    f"`{row['entry']} {row['name']}`",
                    str(row["original_file_offset"]),
                    row["summary"].replace("|", "/"),
                    row["implementation_use"].replace("|", "/"),
                    f"`{row['recovered_file']}`",
                ]
            )
            + " |"
        )
    lines.extend(["", "## Validation Next Steps", ""])
    for row in report["resolutions"]:
        lines.append(f"- `{row['entry']} {row['resolved_role']}`: {row['next_validation']}")
    lines.append("")
    OUT_MD.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    report = build_resolution()
    print(f"Resolved {report['summary']['resolved_count']}/{report['summary']['candidate_count']} candidates")
    print(f"Status counts: {report['summary']['status_counts']}")
    print(f"Wrote {OUT_JSON}")
    print(f"Wrote {OUT_MD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
