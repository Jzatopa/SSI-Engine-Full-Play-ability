#!/usr/bin/env python3
"""Label every previously unknown source-recovery function.

The labels produced here are intentionally conservative.  A confidence value is
the confidence that the static *shape label* is correct, not a claim that we know
the original function name or runtime behavior.  When the pseudocode does not
support a behavioral label, the script labels that fact explicitly.
"""

from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
SOURCE_RECOVERY = ROOT / "generated" / "source_recovery"
INFERENCE_JSON = SOURCE_RECOVERY / "function_role_inference.json"
BATCH_001_JSON = SOURCE_RECOVERY / "unknown_batch_001_resolution.json"
OUT_JSON = SOURCE_RECOVERY / "all_unknown_function_labels.json"
OUT_MD = SOURCE_RECOVERY / "all_unknown_function_labels.md"

CALL_RE = re.compile(r"\b(FUN_[0-9a-f]{4}_[0-9a-f]{4}|func_0x[0-9a-f]+)\s*\(", re.IGNORECASE)
MEMORY_REF_RE = re.compile(r"\*\((?:undefined|byte|char|ushort|uint|int|long|short)[^)]*\)\s*0x[0-9a-f]+", re.IGNORECASE)
STRING_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')


LABELS = {
    "bad_decode_or_mixed_code_data": {
        "status": "labeled_not_liftable_without_raw_review",
        "confidence_percent": 95,
        "summary": "Ghidra warning markers indicate overlapping instructions, bad instruction data, or abnormal stack setup.",
        "next_action": "Inspect raw bytes and xrefs before using this pseudocode.",
    },
    "return_only_stub_or_boundary": {
        "status": "labeled_boundary_or_stub",
        "confidence_percent": 92,
        "summary": "Tiny return-only pseudocode with no visible calls or direct-memory references.",
        "next_action": "Check xrefs before omitting; otherwise treat as boundary/padding/misidentified entry.",
    },
    "single_call_wrapper": {
        "status": "labeled_static_shape",
        "confidence_percent": 88,
        "summary": "Small wrapper whose visible behavior is dominated by one callee.",
        "next_action": "Resolve the wrapped callee and caller context before assigning subsystem behavior.",
    },
    "small_local_computation_or_data_move": {
        "status": "labeled_static_shape",
        "confidence_percent": 78,
        "summary": "Small no-call routine; visible pseudocode is local computation, comparison, or data movement.",
        "next_action": "Use only as a local helper after callers identify its domain.",
    },
    "direct_memory_state_helper": {
        "status": "labeled_static_shape",
        "confidence_percent": 72,
        "summary": "Routine has heavy direct-memory global access and likely manipulates engine state or packed records.",
        "next_action": "Map referenced globals and callers before promoting behavior.",
    },
    "call_heavy_coordinator": {
        "status": "labeled_static_shape",
        "confidence_percent": 70,
        "summary": "Routine calls many helpers and likely coordinates control flow, UI, file, event, or subsystem work.",
        "next_action": "Resolve callee cluster and caller context before naming a subsystem.",
    },
    "string_referencing_helper": {
        "status": "labeled_static_shape",
        "confidence_percent": 68,
        "summary": "Visible string references make this a candidate text/message/UI helper.",
        "next_action": "Cross-check string offsets with custom extractors and DOS captures.",
    },
    "multi_call_small_helper": {
        "status": "labeled_static_shape",
        "confidence_percent": 62,
        "summary": "Small helper with multiple visible calls but insufficient evidence for subsystem behavior.",
        "next_action": "Resolve the callees first.",
    },
    "large_no_call_data_transform": {
        "status": "labeled_static_shape",
        "confidence_percent": 58,
        "summary": "Larger no-call routine; likely local data transformation, table scan, or arithmetic helper.",
        "next_action": "Find callers and compare input/output effects before lifting.",
    },
    "insufficient_static_evidence": {
        "status": "labeled_for_followup",
        "confidence_percent": 99,
        "summary": "Static pseudocode does not support a more specific label without guessing.",
        "next_action": "Use xrefs, raw bytes, DOS captures, or adjacent named clusters before attempting a behavior label.",
    },
}


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


def classify(row: dict[str, Any], text: str) -> str:
    """Return the strongest conservative static label supported by pseudocode."""
    calls = call_names(text, row["name"])
    memory_ref_count = len(MEMORY_REF_RE.findall(source_body(text)))
    strings = string_literals(text)
    body_addresses = int(row["body_addresses"])

    # These first three labels are high-confidence shape facts and match the
    # previous 100-function batch policy.
    if has_bad_decode_warning(text):
        return "bad_decode_or_mixed_code_data"
    if body_addresses <= 5 and not calls and memory_ref_count == 0:
        return "return_only_stub_or_boundary"
    if len(calls) == 1 and body_addresses <= 40:
        return "single_call_wrapper"

    # The remaining labels keep functions searchable without assigning invented
    # game-specific semantics.
    if not calls and body_addresses <= 80:
        return "small_local_computation_or_data_move"
    if memory_ref_count >= 10:
        return "direct_memory_state_helper"
    if len(calls) >= 8:
        return "call_heavy_coordinator"
    if strings:
        return "string_referencing_helper"
    if 1 < len(calls) <= 7 and body_addresses <= 100:
        return "multi_call_small_helper"
    if not calls and body_addresses > 80:
        return "large_no_call_data_transform"
    return "insufficient_static_evidence"


def load_unknown_rows() -> list[dict[str, Any]]:
    report = json.loads(INFERENCE_JSON.read_text(encoding="utf-8"))
    rows = []
    for program in report["programs"]:
        for row in program["functions"]:
            if row["likely_roles"] == ["unknown"]:
                rows.append({**row, "program_key": program["key"], "program_title": program["title"]})
    return rows


def load_batch_001_entries() -> set[str]:
    if not BATCH_001_JSON.exists():
        return set()
    report = json.loads(BATCH_001_JSON.read_text(encoding="utf-8"))
    return {row["entry"] for row in report["resolutions"]}


def build_labels() -> dict[str, Any]:
    batch_001_entries = load_batch_001_entries()
    labels = []
    for row in load_unknown_rows():
        text = (ROOT / row["recovered_file"]).read_text(encoding="utf-8", errors="replace")
        label = classify(row, text)
        meta = LABELS[label]
        calls = call_names(text, row["name"])
        strings = string_literals(text)
        memory_ref_count = len(MEMORY_REF_RE.findall(source_body(text)))
        labels.append(
            {
                "program": row["program_key"],
                "entry": row["entry"],
                "name": row["name"],
                "original_file_offset": row["original_file_offset"],
                "body_addresses": row["body_addresses"],
                "outbound_call_count": len(calls),
                "memory_ref_count": memory_ref_count,
                "string_literals": strings,
                "called_functions_sample": calls[:12],
                "label": label,
                "status": meta["status"],
                "confidence_percent": meta["confidence_percent"],
                "confidence_scope": "Confidence applies to the static shape label, not original name or runtime behavior.",
                "summary": meta["summary"],
                "next_action": meta["next_action"],
                "already_in_unknown_batch_001": row["entry"] in batch_001_entries and row["program_key"] == "game_ovr_payload",
                "recovered_file": row["recovered_file"],
            }
        )

    labels.sort(key=lambda row: (row["program"], row["original_file_offset"] or row["entry"], row["entry"]))
    label_counts: dict[str, int] = {}
    status_counts: dict[str, int] = {}
    program_counts: dict[str, int] = {}
    for row in labels:
        label_counts[row["label"]] = label_counts.get(row["label"], 0) + 1
        status_counts[row["status"]] = status_counts.get(row["status"], 0) + 1
        program_counts[row["program"]] = program_counts.get(row["program"], 0) + 1

    report = {
        "description": "Confidence-backed labels for every function that remained unknown after role inference.",
        "confidence_policy": [
            "Confidence is about the static label being correct.",
            "Confidence is not about original function names.",
            "Confidence is not runtime validation.",
            "The insufficient_static_evidence label has high confidence because it means the script is deliberately refusing to guess.",
        ],
        "summary": {
            "total_unknown_labeled": len(labels),
            "already_in_unknown_batch_001": sum(1 for row in labels if row["already_in_unknown_batch_001"]),
            "newly_labeled_outside_batch_001": sum(1 for row in labels if not row["already_in_unknown_batch_001"]),
            "program_counts": dict(sorted(program_counts.items())),
            "status_counts": dict(sorted(status_counts.items())),
            "label_counts": dict(sorted(label_counts.items())),
        },
        "labels": labels,
    }
    OUT_JSON.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(report)
    return report


def write_markdown(report: dict[str, Any]) -> None:
    lines = [
        "# All Unknown Source-Recovery Function Labels",
        "",
        "Every function that remained unknown after role inference is labeled here.",
        "Confidence percentages describe the static label only; they do not claim original names or runtime behavior.",
        "",
        "## Summary",
        "",
        f"- Total unknown functions labeled: `{report['summary']['total_unknown_labeled']}`",
        f"- Already included in unknown batch 001: `{report['summary']['already_in_unknown_batch_001']}`",
        f"- Newly labeled outside batch 001: `{report['summary']['newly_labeled_outside_batch_001']}`",
        f"- Program counts: `{report['summary']['program_counts']}`",
        f"- Status counts: `{report['summary']['status_counts']}`",
        f"- Label counts: `{report['summary']['label_counts']}`",
        "",
        "## Confidence Policy",
        "",
    ]
    for item in report["confidence_policy"]:
        lines.append(f"- {item}")
    lines.extend(
        [
            "",
            "## Label Table",
            "",
            "| Program | Label | Confidence | Function | Offset | Signals | Summary | File |",
            "|---|---|---:|---|---:|---|---|---|",
        ]
    )
    for row in report["labels"]:
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
                    f"`{row['program']}`",
                    f"`{row['label']}`",
                    str(row["confidence_percent"]),
                    f"`{row['entry']} {row['name']}`",
                    str(row["original_file_offset"]),
                    ", ".join(signals).replace("|", "/"),
                    row["summary"].replace("|", "/"),
                    f"`{row['recovered_file']}`",
                ]
            )
            + " |"
        )
    lines.append("")
    OUT_MD.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    report = build_labels()
    print(f"Labeled {report['summary']['total_unknown_labeled']} previously unknown functions")
    print(f"Program counts: {report['summary']['program_counts']}")
    print(f"Label counts: {report['summary']['label_counts']}")
    print(f"Wrote {OUT_JSON}")
    print(f"Wrote {OUT_MD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
