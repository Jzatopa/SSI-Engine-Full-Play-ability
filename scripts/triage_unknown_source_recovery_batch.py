#!/usr/bin/env python3
"""Resolve a conservative batch of previously unknown source-recovery functions."""

from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
SOURCE_RECOVERY = ROOT / "generated" / "source_recovery"
INFERENCE_JSON = SOURCE_RECOVERY / "function_role_inference.json"
OUT_JSON = SOURCE_RECOVERY / "unknown_batch_001_resolution.json"
OUT_MD = SOURCE_RECOVERY / "unknown_batch_001_resolution.md"

CALL_RE = re.compile(r"\b(FUN_[0-9a-f]{4}_[0-9a-f]{4}|func_0x[0-9a-f]+)\s*\(", re.IGNORECASE)
MEMORY_REF_RE = re.compile(r"\*\((?:undefined|byte|char|ushort|uint|int|long|short)[^)]*\)\s*0x[0-9a-f]+", re.IGNORECASE)
STRING_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')

BATCH_SIZE = 100


def source_body(text: str) -> str:
    return text.split("*/", 1)[-1]


def call_names(text: str, self_name: str) -> list[str]:
    return [call for call in CALL_RE.findall(source_body(text)) if call != self_name]


def string_literals(text: str) -> list[str]:
    values = []
    for match in STRING_RE.finditer(source_body(text)):
        raw = match.group(1)
        printable = raw.encode("utf-8").decode("unicode_escape", errors="ignore")
        if sum(ch.isalnum() for ch in printable) >= 4:
            values.append(printable[:100])
    return values[:8]


def body_line_count(text: str) -> int:
    return len([line for line in source_body(text).splitlines() if line.strip()])


def has_bad_decode_warning(text: str) -> bool:
    return any(
        marker in text
        for marker in (
            "Control flow encountered bad instruction data",
            "Bad instruction",
            "overlaps instruction",
            "Stack frame is not setup normally",
        )
    )


def classify(row: dict[str, Any], text: str) -> dict[str, Any]:
    calls = call_names(text, row["name"])
    memory_refs = MEMORY_REF_RE.findall(source_body(text))
    strings = string_literals(text)
    line_count = body_line_count(text)
    body_addresses = int(row["body_addresses"])

    if has_bad_decode_warning(text):
        return {
            "status": "resolved_bad_decode",
            "static_category": "bad_decode_or_mixed_code_data",
            "summary": "Ghidra warning markers show bad instruction data, overlapping instructions, or abnormal stack setup.",
            "implementation_use": "Do not lift this pseudocode until raw bytes and xrefs are inspected.",
            "priority": 0,
        }
    if body_addresses <= 5 and not calls and not memory_refs:
        return {
            "status": "resolved_stub_or_boundary",
            "static_category": "return_only_stub_or_boundary",
            "summary": "Tiny function body with no calls or direct-memory references; decompiles as an empty return-like boundary.",
            "implementation_use": "Treat as padding, boundary, or possible misidentified entry until xrefs prove otherwise.",
            "priority": 1,
        }
    if len(calls) == 1 and body_addresses <= 40:
        return {
            "status": "resolved_static_shape",
            "static_category": "single_call_wrapper",
            "summary": f"Small wrapper around `{calls[0]}` with little local behavior visible in pseudocode.",
            "implementation_use": "Resolve by following the wrapped callee before assigning subsystem behavior.",
            "priority": 2,
        }
    if not calls and body_addresses <= 80:
        return {
            "status": "resolved_static_shape",
            "static_category": "small_local_computation_or_data_move",
            "summary": "Small no-call routine; behavior appears limited to local computation, comparisons, or data movement.",
            "implementation_use": "Use as a local helper only after caller context is known.",
            "priority": 3,
        }
    if len(memory_refs) >= 10:
        return {
            "status": "resolved_static_shape",
            "static_category": "direct_memory_state_helper",
            "summary": "Heavy direct-memory global access; likely manipulates engine state, tables, or packed records.",
            "implementation_use": "Map referenced globals before lifting behavior.",
            "priority": 4,
        }
    if len(calls) >= 8:
        return {
            "status": "resolved_static_shape",
            "static_category": "call_heavy_coordinator",
            "summary": "Calls many helpers; likely coordinates UI, file, event, or subsystem flow.",
            "implementation_use": "Resolve callees and caller context before assigning a specific game subsystem.",
            "priority": 5,
        }
    if strings:
        return {
            "status": "resolved_static_shape",
            "static_category": "string_referencing_helper",
            "summary": "Contains visible text/string references in pseudocode, making it a candidate UI/message helper.",
            "implementation_use": "Cross-check string offsets against custom extractors before lifting.",
            "priority": 6,
        }
    return {
        "status": "deferred_insufficient_static_evidence",
        "static_category": "still_unknown_after_batch_rules",
        "summary": "No conservative static rule was strong enough for this batch.",
        "implementation_use": "Leave in the unknown queue.",
        "priority": 99,
    }


def load_game_unknowns() -> list[dict[str, Any]]:
    report = json.loads(INFERENCE_JSON.read_text(encoding="utf-8"))
    game = next(program for program in report["programs"] if program["key"] == "game_ovr_payload")
    return [row for row in game["functions"] if row["likely_roles"] == ["unknown"]]


def build_batch() -> dict[str, Any]:
    rows = []
    for row in load_game_unknowns():
        path = ROOT / row["recovered_file"]
        text = path.read_text(encoding="utf-8", errors="replace")
        classification = classify(row, text)
        if classification["status"] == "deferred_insufficient_static_evidence":
            continue
        calls = call_names(text, row["name"])
        memory_count = len(MEMORY_REF_RE.findall(source_body(text)))
        strings = string_literals(text)
        rows.append(
            {
                "entry": row["entry"],
                "name": row["name"],
                "original_file_offset": row["original_file_offset"],
                "body_addresses": row["body_addresses"],
                "outbound_call_count": len(calls),
                "memory_ref_count": memory_count,
                "string_literals": strings,
                "called_functions_sample": calls[:12],
                "recovered_file": row["recovered_file"],
                **classification,
            }
        )

    rows.sort(key=lambda row: (row["priority"], row["original_file_offset"], row["entry"]))
    selected = rows[:BATCH_SIZE]
    status_counts: dict[str, int] = {}
    category_counts: dict[str, int] = {}
    for row in selected:
        status_counts[row["status"]] = status_counts.get(row["status"], 0) + 1
        category_counts[row["static_category"]] = category_counts.get(row["static_category"], 0) + 1
        row.pop("priority", None)
    report = {
        "description": "Conservative static triage resolution for 100 previously unknown GAME.OVR functions.",
        "selection_policy": [
            "Only GAME.OVR functions from the prior unknown queue are eligible.",
            "Prefer mechanically provable categories over subsystem guesses.",
            "Do not assign original function names.",
            "Stop at 100 selected functions for this batch.",
        ],
        "limits": [
            "These are static shape/triage classifications, not runtime-validated behavior.",
            "Single-call wrappers and coordinators require caller/callee context before subsystem promotion.",
            "Stub/boundary decisions should be cross-checked with raw xrefs before deletion or omission.",
        ],
        "summary": {
            "batch_id": "unknown_batch_001",
            "eligible_game_unknown_count": len(load_game_unknowns()),
            "selected_count": len(selected),
            "status_counts": dict(sorted(status_counts.items())),
            "category_counts": dict(sorted(category_counts.items())),
        },
        "resolutions": selected,
    }
    OUT_JSON.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(report)
    return report


def write_markdown(report: dict[str, Any]) -> None:
    lines = [
        "# Unknown Function Batch 001 Resolution",
        "",
        "This batch resolves 100 previously unknown `GAME.OVR` functions using conservative static evidence.",
        "The classifications describe proven pseudocode shape, not original function names.",
        "",
        "## Summary",
        "",
        f"- Eligible GAME.OVR unknowns: `{report['summary']['eligible_game_unknown_count']}`",
        f"- Selected/resolved in this batch: `{report['summary']['selected_count']}`",
        f"- Status counts: `{report['summary']['status_counts']}`",
        f"- Category counts: `{report['summary']['category_counts']}`",
        "",
        "## Resolutions",
        "",
        "| Category | Status | Function | Offset | Signals | Summary | File |",
        "|---|---|---|---:|---|---|---|",
    ]
    for row in report["resolutions"]:
        signals = [
            f"body={row['body_addresses']}",
            f"calls={row['outbound_call_count']}",
            f"memrefs={row['memory_ref_count']}",
        ]
        if row["called_functions_sample"]:
            signals.append("callee=" + row["called_functions_sample"][0])
        if row["string_literals"]:
            signals.append("string=" + row["string_literals"][0].replace("|", "/"))
        lines.append(
            "| "
            + " | ".join(
                [
                    f"`{row['static_category']}`",
                    f"`{row['status']}`",
                    f"`{row['entry']} {row['name']}`",
                    str(row["original_file_offset"]),
                    ", ".join(signals).replace("|", "/"),
                    row["summary"].replace("|", "/"),
                    f"`{row['recovered_file']}`",
                ]
            )
            + " |"
        )
    lines.extend(["", "## Limits", ""])
    for limit in report["limits"]:
        lines.append(f"- {limit}")
    lines.append("")
    OUT_MD.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    report = build_batch()
    print(
        f"Resolved {report['summary']['selected_count']} of "
        f"{report['summary']['eligible_game_unknown_count']} eligible GAME.OVR unknowns"
    )
    print(f"Status counts: {report['summary']['status_counts']}")
    print(f"Category counts: {report['summary']['category_counts']}")
    print(f"Wrote {OUT_JSON}")
    print(f"Wrote {OUT_MD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
