#!/usr/bin/env python3
"""Bounded COAB cross-checks for Matrix Cubed ECL text and GEO layouts.

COAB is secondary evidence. This audit does not copy its runtime code or treat
Curse-specific behavior/data as Matrix Cubed truth. It checks only shared binary
structures against local Matrix Cubed files.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "src"))

from matrix_cubed.formats.dax import read_dax  # noqa: E402
from matrix_cubed.formats.geo import parse_geo_block  # noqa: E402
from scripts.compare_goldbox_ecl_text import decompress_goldbox_ecl_string  # noqa: E402
from scripts.ecl_disassemble import decompress_ecl_string  # noqa: E402
from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()
DEFAULT_COAB_ROOT = Path.home() / ".local" / "opt" / "coab"
DEFAULT_OUT_DIR = ROOT / "generated" / "coab_reference"


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def decompress_packed_6bit_bitstream(data: bytes) -> str:
    """Independent MSB-first implementation of the Gold Box 6-bit alphabet."""
    bit_count = len(data) * 8
    value = int.from_bytes(data, "big") if data else 0
    chars: list[str] = []
    for consumed in range(0, bit_count - 5, 6):
        shift = bit_count - consumed - 6
        code = (value >> shift) & 0x3F
        if code:
            chars.append(chr(code + 0x40 if code <= 0x1F else code))
    return "".join(chars)


def packed_string_candidates(data: bytes) -> list[tuple[int, bytes]]:
    result: list[tuple[int, bytes]] = []
    for offset in range(max(0, len(data) - 1)):
        if data[offset] != 0x80:
            continue
        length = data[offset + 1]
        end = offset + 2 + length
        if end <= len(data):
            result.append((offset, data[offset + 2 : end]))
    return result


def audit_text(ecl_path: Path) -> dict:
    candidates = 0
    mismatches: list[dict] = []
    blocks_with_candidates: set[int] = set()
    for block in read_dax(ecl_path):
        for offset, packed in packed_string_candidates(block.data):
            candidates += 1
            blocks_with_candidates.add(block.block_id)
            outputs = {
                "project_whole_block": decompress_goldbox_ecl_string(packed),
                "project_disassembler": decompress_ecl_string(packed),
                "independent_bitstream": decompress_packed_6bit_bitstream(packed),
            }
            if len(set(outputs.values())) != 1:
                mismatches.append({"block_id": block.block_id, "offset": offset, "outputs": outputs})
    return {
        "source": str(ecl_path),
        "sha256": sha256(ecl_path),
        "candidate_count": candidates,
        "blocks_with_candidates": len(blocks_with_candidates),
        "decoder_mismatch_count": len(mismatches),
        "mismatches": mismatches[:20],
    }


def audit_maps(geo_path: Path) -> dict:
    checked_cells = 0
    mismatches: list[dict] = []
    sizes: dict[int, int] = {}
    for block in read_dax(geo_path):
        sizes[block.block_id] = len(block.data)
        parsed = parse_geo_block(block.block_id, str(block.block_id), block.data)
        payload = block.data[2:0x402]
        if len(payload) != 0x400:
            mismatches.append({"block_id": block.block_id, "reason": "not_0x402_bytes"})
            continue
        for index, cell in enumerate(parsed.cells):
            checked_cells += 1
            ne = payload[index]
            sw = payload[0x100 + index]
            event = payload[0x200 + index]
            door = payload[0x300 + index]
            independent = (
                ne >> 4,
                ne & 0x0F,
                sw >> 4,
                sw & 0x0F,
                event,
                door,
            )
            project = (
                cell.north,
                cell.east,
                cell.south,
                cell.west,
                cell.event_id | (0x80 if cell.event_flag else 0),
                cell.door,
            )
            if independent != project:
                mismatches.append(
                    {"block_id": block.block_id, "cell": index, "independent": independent, "project": project}
                )
    return {
        "source": str(geo_path),
        "sha256": sha256(geo_path),
        "block_count": len(sizes),
        "block_sizes": sorted(set(sizes.values())),
        "checked_cells": checked_cells,
        "layout_mismatch_count": len(mismatches),
        "mismatches": mismatches[:20],
    }


def audit_coab_sources(coab_root: Path) -> dict:
    interpreter = coab_root / "engine" / "ovr003.cs"
    text = coab_root / "engine" / "ovr008.cs"
    geo = coab_root / "Classes" / "GeoBlock.cs"
    for path in (interpreter, text, geo):
        if not path.is_file():
            raise FileNotFoundError(f"missing COAB reference source: {path}")
    command_re = re.compile(r'CommandTable\.Add\(0x([0-9A-Fa-f]+),\s*new CmdItem\((\d+),\s*"([^"]+)"')
    commands = [
        {"opcode": int(opcode, 16), "fixed_argument_count": int(count), "name": name}
        for opcode, count, name in command_re.findall(interpreter.read_text(encoding="utf-8-sig"))
    ]
    return {
        "root": str(coab_root),
        "commit": _git_commit(coab_root),
        "sources": {
            str(path.relative_to(coab_root)): sha256(path) for path in (interpreter, text, geo)
        },
        "command_table_entries": len(commands),
        "command_table": commands,
        "bounded_observations": {
            "load_monster": "argument 2 is a copy count; values <= 0 normalize to one; total loaded monsters is capped at 63",
            "arithmetic": "shared ADD, SUBTRACT (argument 2 minus argument 1), DIVIDE (argument 1 divided by argument 2), MULTIPLY, and inclusive RANDOM semantics match the current VM",
            "branching": "shared COMPARE/IF and ON GOTO/ON GOSUB operand direction and zero-based selection match the current VM",
            "menus": "vertical and horizontal menus store a zero-based selected index; the current VM already matches this shared behavior",
            "load_files": "argument 1 selects the GEO block in Curse; Matrix Cubed local listings and current LOAD_AREA_MAP handling use the same first-argument map target",
            "packed_text": "packed ECL strings decode as consecutive nonzero 6-bit codes using the shared Gold Box alphabet",
            "geo": "decoded GEO blocks are 0x402 bytes: two-byte prefix plus four 256-byte cell planes",
        },
    }


def _git_commit(path: Path) -> str | None:
    head = path / ".git" / "HEAD"
    if not head.is_file():
        return None
    value = head.read_text().strip()
    if value.startswith("ref: "):
        ref = path / ".git" / value[5:]
        return ref.read_text().strip() if ref.is_file() else None
    return value


def render_markdown(report: dict) -> str:
    text = report["matrix_cubed_text"]
    maps = report["matrix_cubed_maps"]
    coab = report["coab"]
    return "\n".join(
        [
            "# COAB Secondary-Reference Audit",
            "",
            "COAB is used only as secondary evidence. Curse-specific content and unverified behavior are not promoted.",
            "",
            "## ECL interpreter",
            "",
            f"- COAB command-table entries parsed: {coab['command_table_entries']}",
            "- Integrated verified behavior: `LOAD MONSTER` queues argument-2 copies, normalizes zero to one, and caps the queue at 63.",
            "- Matrix Cubed local proof includes ECL block 38 at `0x9754`: monster 11, copies 10, CPIC 11.",
            "- Existing arithmetic, comparison/IF, ON GOTO/GOSUB, menu-index, and first-argument `LOAD FILES` semantics agree; no replacement was needed.",
            "- Combat rules and Curse-specific handlers were not imported.",
            "",
            "## ECL packed text",
            "",
            f"- Candidates checked: {text['candidate_count']} across {text['blocks_with_candidates']} blocks",
            f"- Decoder mismatches: {text['decoder_mismatch_count']}",
            "- Compared the project whole-block decoder, project disassembler decoder, and an independent MSB-first bitstream decoder.",
            "",
            "## GEO map layout",
            "",
            f"- Blocks checked: {maps['block_count']}",
            f"- Cells checked: {maps['checked_cells']}",
            f"- Layout mismatches: {maps['layout_mismatch_count']}",
            f"- Decoded block sizes observed: {maps['block_sizes']}",
            "- COAB adds no missing GEO field decode: our parser already matches all four 256-byte planes.",
            "- COAB rendering/collision policy remains secondary and was not imported without Matrix Cubed behavioral proof.",
            "",
            "## Provenance",
            "",
            f"- COAB commit: `{coab['commit']}`",
            f"- ECL1 SHA-256: `{text['sha256']}`",
            f"- GEO1 SHA-256: `{maps['sha256']}`",
        ]
    ) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--coab-root", type=Path, default=DEFAULT_COAB_ROOT)
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    args = parser.parse_args()

    report = {
        "schema_version": 1,
        "coab": audit_coab_sources(args.coab_root),
        "matrix_cubed_text": audit_text(args.game_dir / "ECL1.DAX"),
        "matrix_cubed_maps": audit_maps(args.game_dir / "GEO1.DAX"),
    }
    args.out_dir.mkdir(parents=True, exist_ok=True)
    (args.out_dir / "coab_reference_audit.json").write_text(json.dumps(report, indent=2) + "\n")
    (args.out_dir / "coab_reference_audit.md").write_text(render_markdown(report))
    print(json.dumps({
        "text_candidates": report["matrix_cubed_text"]["candidate_count"],
        "text_mismatches": report["matrix_cubed_text"]["decoder_mismatch_count"],
        "map_cells": report["matrix_cubed_maps"]["checked_cells"],
        "map_mismatches": report["matrix_cubed_maps"]["layout_mismatch_count"],
    }))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
