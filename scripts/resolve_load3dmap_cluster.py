#!/usr/bin/env python3
"""Resolve the GAME.OVR Load3DMap/WALLDEF Ghidra cluster using raw disassembly.

This script exists because nearest-Ghidra-function proximity was misleading for
the `Load3DMap` text anchor.  The anchor is inside embedded string/data bytes,
and the closest Ghidra function entry (`3000:0c04`) lands in the middle of the
real routine's epilogue.  The report records those byte-level facts so future
work does not keep treating the cluster as unresolved.
"""

from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
DISASM = (
    ROOT
    / "generated"
    / "reverse_engineering"
    / "imported"
    / "game_ovr"
    / "game_ovr_reverse_engineering"
    / "GAME.OVR.payload_8086_disassembly.asm"
)
OUT_DIR = ROOT / "generated" / "source_recovery"
OUT_JSON = OUT_DIR / "load3dmap_cluster_resolution.json"
OUT_MD = OUT_DIR / "load3dmap_cluster_resolution.md"

LINE_RE = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+?)\s{2,}(.+)$", re.IGNORECASE)


def parse_disassembly() -> list[dict[str, Any]]:
    rows = []
    for line in DISASM.read_text(encoding="utf-8", errors="replace").splitlines():
        match = LINE_RE.match(line)
        if not match:
            continue
        address = int(match.group(1), 16)
        rows.append(
            {
                "address": address,
                "address_hex": f"0x{address:05X}",
                "bytes": " ".join(match.group(2).split()),
                "instruction": match.group(3).strip(),
                "line": line.rstrip(),
            }
        )
    return rows


def window(rows: list[dict[str, Any]], start: int, end: int) -> list[dict[str, Any]]:
    return [row for row in rows if start <= row["address"] <= end]


def build_resolution() -> dict[str, Any]:
    rows = parse_disassembly()
    windows = {
        "pre_string_loader_code": window(rows, 0x3091C, 0x30AA2),
        "embedded_load3dmap_strings": window(rows, 0x30AA5, 0x30ACF),
        "post_string_loader_code": window(rows, 0x30AD0, 0x30C10),
        "epilogue_and_following_table": window(rows, 0x30BFA, 0x30C21),
    }
    report = {
        "description": "Byte-level resolution of the Load3DMap/WALLDEF cluster.",
        "address_rules": {
            "payload_linear_to_original_game_ovr_offset": "original_offset = payload_linear + 8",
            "ghidra_segmented_to_payload_linear": "linear = segment * 16 + offset",
        },
        "facts": [
            {
                "id": "load3dmap_anchor_is_string_data",
                "confidence_percent": 99,
                "evidence": (
                    "Raw disassembly at 0x30AAF-0x30ACF decodes ASCII bytes for "
                    "'Unable to load geo in Load3DMap.'; instruction mnemonics there are ASCII-as-code artifacts."
                ),
            },
            {
                "id": "post_string_code_is_loader_shaped",
                "confidence_percent": 90,
                "evidence": (
                    "Code resumes at 0x30AD0 with a stack frame, builds GEO filename text, checks loaded size 0x402, "
                    "copies four 0x100-byte chunks from global buffer 0x7360, closes/releases the loaded buffer, "
                    "and writes the selected map byte to active state at *(0x4418)+0xC5."
                ),
            },
            {
                "id": "ghidra_3000_0c04_is_misaligned_epilogue",
                "confidence_percent": 99,
                "evidence": (
                    "Ghidra entry 3000:0c04 maps to payload 0x30C04, which is inside instruction "
                    "'26 88 85 c5 00' beginning at 0x30C01; the actual epilogue is 0x30C06-0x30C10."
                ),
            },
            {
                "id": "ghidra_3000_006f_not_load3dmap",
                "confidence_percent": 85,
                "evidence": (
                    "3000:006f remains a behavior-rich wall/span emit candidate, but the raw Load3DMap-shaped "
                    "loader code is at 0x30AD0-0x30C10, after the embedded error string."
                ),
            },
        ],
        "resolved_roles": {
            "load3dmap_loader_code_window": {
                "payload_start": "0x30AD0",
                "payload_end": "0x30C10",
                "original_file_start": 0x30AD0 + 8,
                "original_file_end": 0x30C10 + 8,
                "confidence_percent": 90,
                "role": "GEO Load3DMap file-load/copy routine candidate",
            },
            "3000:0c04": {
                "payload_linear": "0x30C04",
                "original_file_offset": 0x30C04 + 8,
                "confidence_percent": 99,
                "role": "misaligned Ghidra function entry inside Load3DMap epilogue instruction",
            },
            "3000:006f": {
                "payload_linear": "0x3006F",
                "original_file_offset": 0x3006F + 8,
                "confidence_percent": 85,
                "role": "wall/span emit routine candidate, not the Load3DMap loader",
            },
        },
        "windows": windows,
    }
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    OUT_JSON.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(report)
    return report


def write_markdown(report: dict[str, Any]) -> None:
    lines = [
        "# Load3DMap Cluster Resolution",
        "",
        "This resolves the previously ambiguous Ghidra nearest-function cluster around the `Load3DMap` string.",
        "",
        "## Resolution",
        "",
        "- The `Load3DMap` text anchor is embedded string/data, not a function entry.",
        "- The loader-shaped code window is payload `0x30AD0-0x30C10`.",
        "- `3000:0c04` is a misaligned Ghidra entry inside the epilogue instruction, not an empty loader function.",
        "- `3000:006f` remains a wall/span emit candidate, not the `Load3DMap` loader.",
        "",
        "## Facts",
        "",
    ]
    for fact in report["facts"]:
        lines.append(f"- `{fact['id']}` ({fact['confidence_percent']}%): {fact['evidence']}")
    lines.extend(["", "## Key Disassembly Windows", ""])
    for name, rows in report["windows"].items():
        lines.append(f"### {name}")
        lines.append("")
        lines.append("```asm")
        for row in rows:
            lines.append(row["line"])
        lines.append("```")
        lines.append("")
    OUT_MD.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    report = build_resolution()
    role = report["resolved_roles"]["load3dmap_loader_code_window"]
    print(
        "Resolved Load3DMap loader-shaped code window "
        f"{role['payload_start']}-{role['payload_end']} "
        f"({role['confidence_percent']}% static confidence)"
    )
    print(f"Wrote {OUT_JSON}")
    print(f"Wrote {OUT_MD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
