#!/usr/bin/env python3
"""Infer likely function roles from the source-recovery pseudocode corpus."""

from __future__ import annotations

import json
import re
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
SOURCE_RECOVERY = ROOT / "generated" / "source_recovery"
OUT_JSON = SOURCE_RECOVERY / "function_role_inference.json"
OUT_MD = SOURCE_RECOVERY / "function_role_inference.md"

CALL_RE = re.compile(r"\b(FUN_[0-9a-f]{4}_[0-9a-f]{4}|func_0x[0-9a-f]+)\s*\(", re.IGNORECASE)
STRING_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')
MEMORY_REF_RE = re.compile(r"\*\((?:undefined|byte|char|ushort|uint|int|long|short)[^)]*\)\s*0x[0-9a-f]+", re.IGNORECASE)


ROLE_SUMMARIES = {
    "anchor": "near a known project text/data anchor; role remains unspecified",
    "combat": "candidate combat subsystem entry/support function",
    "character_creation": "candidate character creation or character setup function",
    "shop": "candidate shop/menu transaction function",
    "items": "candidate item catalog, item detail, or inventory data function",
    "save_load": "candidate save/load persistence function",
    "character_sheet": "candidate character-sheet display/status function",
    "inventory": "candidate inventory or gear menu function",
    "ship": "candidate ship status/travel-resource function",
    "wall_loader": "candidate first-person wall or WALLDEF loader function",
    "map_loader": "candidate GEO/Load3DMap loader or nearby loader-boundary function",
}


def confidence_from_roles(roles: list[dict[str, Any]], body_addresses: int) -> str:
    if not roles:
        return "low"
    best_distance = min(int(role["distance"]) for role in roles)
    if body_addresses <= 5:
        return "low"
    if best_distance <= 256:
        return "high"
    if best_distance <= 1024:
        return "medium"
    return "low"


def clean_strings(text: str) -> list[str]:
    values = []
    for match in STRING_RE.finditer(text):
        raw = match.group(1)
        if "Matrix Cubed source recovery corpus" in raw:
            continue
        printable = raw.encode("utf-8").decode("unicode_escape", errors="ignore")
        alnum = sum(ch.isalnum() for ch in printable)
        if alnum >= 4:
            values.append(printable[:120])
    return values[:12]


def summarize_actions(text: str, roles: list[dict[str, Any]], body_addresses: int, self_name: str) -> list[str]:
    actions = []
    role_names = {role["role"] for role in roles}
    for role_name in sorted(role_names):
        summary = ROLE_SUMMARIES.get(role_name)
        if summary:
            actions.append(summary)
    if "return;" in text and body_addresses <= 5:
        actions.append("tiny return/stub-like function; may be a boundary artifact or intentionally empty routine")
    memory_refs = len(MEMORY_REF_RE.findall(text))
    if memory_refs >= 10:
        actions.append("heavy direct-memory access; likely manipulates global engine state")
    elif memory_refs:
        actions.append("uses direct-memory globals; type/structure recovery still needed")
    call_count = len(call_names(text, self_name))
    if call_count >= 8:
        actions.append("call-heavy coordinator or menu/control routine")
    elif call_count == 0 and body_addresses > 20:
        actions.append("local computation/data movement candidate")
    return actions


def build_call_index(functions: list[dict[str, Any]]) -> dict[str, int]:
    inbound: Counter[str] = Counter()
    for function in functions:
        text = (ROOT / function["recovered_file"]).read_text(encoding="utf-8", errors="replace")
        for call in call_names(text, function["name"]):
            inbound[call] += 1
    return dict(inbound)


def call_names(text: str, self_name: str) -> list[str]:
    return [call for call in CALL_RE.findall(text) if call != self_name]


def infer_roles() -> dict[str, Any]:
    manifest = json.loads((SOURCE_RECOVERY / "manifest.json").read_text(encoding="utf-8"))
    all_functions = [function for program in manifest["programs"] for function in program["functions"]]
    inbound = build_call_index(all_functions)

    programs = []
    role_counts: Counter[str] = Counter()
    confidence_counts: Counter[str] = Counter()
    for program in manifest["programs"]:
        inferred = []
        for function in program["functions"]:
            path = ROOT / function["recovered_file"]
            text = path.read_text(encoding="utf-8", errors="replace")
            roles = function["roles"]
            body_addresses = int(function["body_addresses"])
            role_names = sorted({role["role"] for role in roles})
            for role_name in role_names:
                role_counts[role_name] += 1
            confidence = confidence_from_roles(roles, body_addresses) if roles else "unknown"
            confidence_counts[confidence] += 1
            call_count = len(call_names(text, function["name"]))
            memory_ref_count = len(MEMORY_REF_RE.findall(text))
            string_literals = clean_strings(text)
            inferred.append(
                {
                    "entry": function["entry"],
                    "name": function["name"],
                    "program": program["key"],
                    "recovered_file": function["recovered_file"],
                    "linear": function["linear"],
                    "original_file_offset": function["original_file_offset"],
                    "body_addresses": body_addresses,
                    "calling_convention": function["calling_convention"],
                    "likely_roles": role_names or ["unknown"],
                    "confidence": confidence,
                    "anchor_evidence": roles,
                    "inbound_call_count": inbound.get(function["name"], 0),
                    "outbound_call_count": call_count,
                    "memory_ref_count": memory_ref_count,
                    "string_literals": string_literals,
                    "action_summary": summarize_actions(text, roles, body_addresses, function["name"]),
                }
            )
        programs.append(
            {
                "key": program["key"],
                "title": program["title"],
                "function_count": len(inferred),
                "role_inferred_count": sum(1 for row in inferred if row["likely_roles"] != ["unknown"]),
                "functions": inferred,
            }
        )

    report = {
        "description": "Likely function-role inference from source-recovery pseudocode, anchors, and local text features.",
        "limits": [
            "Roles are hypotheses for triage, not recovered original function names.",
            "Anchor proximity does not prove ownership.",
            "Raw GAME.OVR pseudocode still lacks overlay relocation/manager context.",
            "Runtime behavior must be validated before implementation changes.",
        ],
        "role_summaries": ROLE_SUMMARIES,
        "summary": {
            "program_count": len(programs),
            "function_count": sum(program["function_count"] for program in programs),
            "role_inferred_count": sum(program["role_inferred_count"] for program in programs),
            "role_counts": dict(sorted(role_counts.items())),
            "confidence_counts": dict(sorted(confidence_counts.items())),
        },
        "programs": programs,
    }
    OUT_JSON.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(report)
    return report


def write_markdown(report: dict[str, Any]) -> None:
    game = next(program for program in report["programs"] if program["key"] == "game_ovr_payload")
    role_rows = [
        row
        for row in game["functions"]
        if row["likely_roles"] != ["unknown"]
    ]
    role_rows.sort(
        key=lambda row: (
            min((int(anchor["distance"]) for anchor in row["anchor_evidence"]), default=999999),
            row["linear"],
        )
    )

    lines = [
        "# Source Recovery Function Role Inference",
        "",
        "This report uses the recovered pseudocode corpus to identify what original functions likely do.",
        "The labels are hypotheses for triage, not original function names.",
        "",
        "## Summary",
        "",
        f"- Functions scanned: `{report['summary']['function_count']}`",
        f"- Functions with inferred roles: `{report['summary']['role_inferred_count']}`",
        f"- Confidence counts: `{report['summary']['confidence_counts']}`",
        "",
        "## High-Value GAME.OVR Candidates",
        "",
        "| Likely role | Confidence | Function | Offset | Evidence | Signals | File |",
        "|---|---|---|---:|---|---|---|",
    ]
    for row in role_rows:
        anchors = ", ".join(
            f"{anchor['anchor']}@{anchor['file_offset']} d={anchor['distance']}"
            for anchor in row["anchor_evidence"]
        )
        signals = []
        if row["outbound_call_count"]:
            signals.append(f"calls={row['outbound_call_count']}")
        if row["memory_ref_count"]:
            signals.append(f"memrefs={row['memory_ref_count']}")
        if row["string_literals"]:
            signals.append("strings=" + "; ".join(row["string_literals"][:2]).replace("|", "/"))
        lines.append(
            "| "
            + " | ".join(
                [
                    ", ".join(f"`{role}`" for role in row["likely_roles"]),
                    f"`{row['confidence']}`",
                    f"`{row['entry']} {row['name']}`",
                    str(row["original_file_offset"]),
                    anchors.replace("|", "/"),
                    ", ".join(signals).replace("|", "/"),
                    f"`{row['recovered_file']}`",
                ]
            )
            + " |"
        )

    lines.extend(
        [
            "",
            "## Role Meanings",
            "",
        ]
    )
    for role, summary in sorted(report["role_summaries"].items()):
        lines.append(f"- `{role}`: {summary}.")
    lines.extend(
        [
            "",
            "## Limits",
            "",
        ]
    )
    for limit in report["limits"]:
        lines.append(f"- {limit}")
    lines.append("")
    OUT_MD.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    report = infer_roles()
    print(f"Scanned {report['summary']['function_count']} functions")
    print(f"Inferred roles for {report['summary']['role_inferred_count']} functions")
    print(f"Wrote {OUT_JSON}")
    print(f"Wrote {OUT_MD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
