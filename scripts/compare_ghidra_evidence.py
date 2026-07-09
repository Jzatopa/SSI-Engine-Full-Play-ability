#!/usr/bin/env python3
"""Compare Ghidra exports with existing Matrix Cubed evidence artifacts."""

from __future__ import annotations

import csv
import json
from bisect import bisect_right
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "generated" / "ghidra" / "comparison"


MANUAL_GAME_ANCHORS = [
    {
        "name": "wall_loader_wall_def_1",
        "offset": 198845,
        "source": "generated/game_ovr/map_scan.json ascii_anchors",
        "note": "WALLDEF near first wall loader string",
    },
    {
        "name": "wall_loader_wall_def_2",
        "offset": 198880,
        "source": "generated/game_ovr/map_scan.json ascii_anchors",
        "note": "WALLDEF near second wall loader string",
    },
    {
        "name": "load3dmap_geo",
        "offset": 199334,
        "source": "generated/game_ovr/map_scan.json ascii_anchors",
        "note": "GEO string before Load3DMap error",
    },
    {
        "name": "load3dmap_error",
        "offset": 199365,
        "source": "generated/game_ovr/map_scan.json ascii_anchors",
        "note": "Load3DMap string",
    },
]


def read_tsv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def read_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def segmented_to_linear(address: str) -> int | None:
    if "::" in address:
        return None
    if ":" not in address:
        return int(address, 16)
    segment, offset = address.split(":", 1)
    return int(segment, 16) * 16 + int(offset, 16)


def linear_to_segmented(linear: int) -> str:
    segment = linear // 16
    offset = linear % 16
    return f"{segment:04x}:{offset:04x}"


def load_functions(path: Path) -> list[dict[str, Any]]:
    rows = []
    for row in read_tsv(path):
        linear = segmented_to_linear(row["entry"])
        if linear is None:
            continue
        item = dict(row)
        item["linear"] = linear
        item["linear_hex"] = f"0x{linear:05X}"
        rows.append(item)
    return sorted(rows, key=lambda row: row["linear"])


def nearest_functions(functions: list[dict[str, Any]], linear: int) -> dict[str, Any]:
    entries = [int(row["linear"]) for row in functions]
    index = bisect_right(entries, linear)
    previous_row = functions[index - 1] if index > 0 else None
    next_row = functions[index] if index < len(functions) else None

    def simplify(row: dict[str, Any] | None) -> dict[str, Any] | None:
        if row is None:
            return None
        return {
            "entry": row["entry"],
            "name": row["name"],
            "linear": row["linear"],
            "linear_hex": row["linear_hex"],
            "distance": abs(int(row["linear"]) - linear),
            "body_addresses": int(row["body_addresses"]),
            "calling_convention": row["calling_convention"],
            "is_thunk": row["is_thunk"] == "true",
        }

    return {"previous": simplify(previous_row), "next": simplify(next_row)}


def decompiled_file_for(entry: str, name: str, decompiled_dir: Path) -> str | None:
    safe = f"{entry}_{name}.c"
    safe = "".join(ch if ch.isalnum() or ch in "._-" else "_" for ch in safe)
    path = decompiled_dir / safe
    return str(path.relative_to(ROOT)) if path.exists() else None


def game_anchor_rows(functions: list[dict[str, Any]]) -> list[dict[str, Any]]:
    anchors = []
    for row in read_json(ROOT / "generated" / "game_ovr" / "anchors.json"):
        anchors.append(
            {
                "name": row["name"],
                "offset": int(row["offset"]),
                "source": "generated/game_ovr/anchors.json",
                "note": row.get("note", ""),
            }
        )
    anchors.extend(MANUAL_GAME_ANCHORS)
    out = []
    decompiled_dir = ROOT / "generated" / "ghidra" / "deep_game_ovr_payload" / "decompiled"
    for anchor in sorted(anchors, key=lambda row: row["offset"]):
        payload_linear = int(anchor["offset"]) - 8
        nearest = nearest_functions(functions, payload_linear) if payload_linear >= 0 else {"previous": None, "next": None}
        for key in ("previous", "next"):
            row = nearest[key]
            if row:
                row["decompiled_file"] = decompiled_file_for(row["entry"], row["name"], decompiled_dir)
        out.append(
            {
                **anchor,
                "payload_linear": payload_linear,
                "payload_linear_hex": f"0x{payload_linear:05X}" if payload_linear >= 0 else None,
                "ghidra_address": linear_to_segmented(payload_linear) if payload_linear >= 0 else None,
                "nearest_functions": nearest,
            }
        )
    return out


def ghidra_string_matches() -> dict[str, Any]:
    game_ascii = read_json(ROOT / "generated" / "game_ovr" / "ascii_strings.json")
    by_offset = {int(row["offset"]): row for row in game_ascii}
    game_matches = []
    for row in read_tsv(ROOT / "generated" / "ghidra" / "deep_game_ovr_payload" / "strings.tsv"):
        linear = segmented_to_linear(row["address"])
        if linear is None:
            continue
        file_offset = linear + 8
        existing = by_offset.get(file_offset)
        game_matches.append(
            {
                "ghidra_address": row["address"],
                "payload_linear": linear,
                "file_offset": file_offset,
                "text": row["text"],
                "exact_offset_match_in_ascii_artifact": existing is not None,
                "ascii_artifact_text": existing["text"] if existing else None,
            }
        )

    start_original_strings = {row["text"] for row in read_json(ROOT / "generated" / "start_exe_strings.json")}
    start_ghidra_rows = read_tsv(ROOT / "generated" / "ghidra" / "deep_start_unpacked" / "strings.tsv")
    start_overlap = [row for row in start_ghidra_rows if row["text"] in start_original_strings]
    return {
        "game_ovr_ghidra_defined_string_count": len(game_matches),
        "game_ovr_ghidra_strings": game_matches,
        "start_unpacked_ghidra_defined_string_count": len(start_ghidra_rows),
        "start_original_string_count": len(start_original_strings),
        "start_exact_text_overlap_count": len(start_overlap),
        "start_exact_text_overlap_sample": start_overlap[:40],
        "interpretation": (
            "Ghidra-defined strings are a subset of the project string extractors. "
            "For GAME.OVR, convert Ghidra payload linear offsets back to original file offsets by adding 8 bytes."
        ),
    }


def count_decompile(path: Path) -> dict[str, int]:
    rows = read_tsv(path)
    return {
        "attempted": len(rows),
        "completed": sum(1 for row in rows if row["completed"] == "true"),
        "timed_out": sum(1 for row in rows if row["timed_out"] == "true"),
        "errors": sum(1 for row in rows if row["error"]),
    }


def write_markdown(path: Path, report: dict[str, Any]) -> None:
    lines = [
        "# Ghidra Evidence Comparison",
        "",
        "This report maps Ghidra's segmented real-mode addresses back to existing Matrix Cubed evidence.",
        "",
        "## Summary",
        "",
        f"- START functions: `{report['start']['function_count']}`",
        f"- START decompiled completed: `{report['start']['decompile']['completed']}/{report['start']['decompile']['attempted']}`",
        f"- GAME.OVR candidate functions: `{report['game_ovr']['function_count']}`",
        f"- GAME.OVR decompiled completed: `{report['game_ovr']['decompile']['completed']}/{report['game_ovr']['decompile']['attempted']}`",
        f"- GAME.OVR Ghidra-defined strings: `{report['strings']['game_ovr_ghidra_defined_string_count']}`",
        f"- START exact text overlap with original START string artifact: `{report['strings']['start_exact_text_overlap_count']}`",
        "",
        "## Address Mapping",
        "",
        "- For raw `GAME.OVR.payload_after_fbov_header.bin`, Ghidra linear address = original `GAME.OVR` file offset minus 8.",
        "- Example: original file offset `199365` (`Load3DMap`) maps to payload linear `199357` / Ghidra address `3000:0ABD`.",
        "",
        "## GAME.OVR Anchor Map",
        "",
        "| Anchor | File offset | Ghidra address | Previous function | Distance | Next function | Distance |",
        "|---|---:|---|---|---:|---|---:|",
    ]
    for row in report["game_ovr"]["anchors"]:
        prev = row["nearest_functions"]["previous"] or {}
        nxt = row["nearest_functions"]["next"] or {}
        lines.append(
            "| "
            + " | ".join(
                [
                    f"`{row['name']}`",
                    str(row["offset"]),
                    f"`{row['ghidra_address']}`",
                    f"`{prev.get('entry', '')} {prev.get('name', '')}`",
                    str(prev.get("distance", "")),
                    f"`{nxt.get('entry', '')} {nxt.get('name', '')}`",
                    str(nxt.get("distance", "")),
                ]
            )
            + " |"
        )
    lines.extend(
        [
            "",
            "## Integration Notes",
            "",
            "- The comparison does not promote Ghidra anonymous function names into runtime code.",
            "- The nearest-function rows are triage targets for manual naming in Ghidra.",
            "- Existing custom string extractors remain authoritative for text coverage; Ghidra's string table is narrower.",
            "",
        ]
    )
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    game_functions = load_functions(ROOT / "generated" / "ghidra" / "deep_game_ovr_payload" / "functions.tsv")
    start_functions = load_functions(ROOT / "generated" / "ghidra" / "deep_start_unpacked" / "functions.tsv")
    report = {
        "address_rules": {
            "game_ovr_payload_to_original_file_offset": "original_file_offset = ghidra_linear + 8",
            "segmented_to_linear": "linear = segment * 16 + offset",
        },
        "start": {
            "function_count": len(start_functions),
            "decompile": count_decompile(ROOT / "generated" / "ghidra" / "deep_start_unpacked" / "decompile_summary.tsv"),
        },
        "game_ovr": {
            "function_count": len(game_functions),
            "decompile": count_decompile(ROOT / "generated" / "ghidra" / "deep_game_ovr_payload" / "decompile_summary.tsv"),
            "anchors": game_anchor_rows(game_functions),
        },
        "strings": ghidra_string_matches(),
    }
    (OUT_DIR / "ghidra_evidence_comparison.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(OUT_DIR / "ghidra_evidence_comparison.md", report)
    print(f"Wrote {OUT_DIR / 'ghidra_evidence_comparison.md'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
