#!/usr/bin/env python3
"""Recover Matrix Cubed ECL skill-check opcode callsite evidence.

Evidence boundary:
- Current ECL listings decode opcode 0x23 with the generic `SURPRISE` label.
- The COAB Java stub audit records that Matrix maps opcode 0x23 to
  `SKILL_CHECK`, but the success rule and VM integration are still unresolved.
- This script records callsites, operands, and nearby context only; it does
  not implement the opcode or rename the disassembler globally.
"""

from __future__ import annotations

import csv
import json
import re
import sys
from dataclasses import asdict, dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from scripts.build_ecl_dialog_reference import build_regions, load_listings


ROOT = Path(__file__).resolve().parents[1]
LISTING_DIR = ROOT / "generated" / "ecl1_disasm"
SKILL_TABLE = ROOT / "generated" / "skill_recovery" / "2026-07-08" / "skill_names.tsv"
OUT_DIR = ROOT / "generated" / "skill_check_recovery" / "2026-07-08"

RAW_RE = re.compile(r"raw=\((?P<operands>.*)\)")
STRING_RE = re.compile(r"'([^']+)'|\"([^\"]+)\"")


@dataclass(frozen=True)
class SkillCheckCallsite:
    block_id: int
    address: int
    address_hex: str
    opcode: str
    current_listing_label: str
    matrix_candidate_label: str
    operand_count: int
    operands: tuple[str, ...]
    first_operand_kind: str
    candidate_skill_id: int | None
    candidate_skill_name: str | None
    candidate_who_offset: int | None
    result_operand: str | None
    branch_region_target: str | None
    branch_region_incoming: tuple[str, ...]
    nearest_previous_who: str | None
    previous_rows: tuple[str, ...]
    following_rows: tuple[str, ...]
    evidence_limit: str


@dataclass(frozen=True)
class WhoContext:
    block_id: int
    address: int
    address_hex: str
    prompt: str
    row: str
    branch_region_target: str | None
    branch_region_incoming: tuple[str, ...]
    previous_rows: tuple[str, ...]
    following_rows: tuple[str, ...]


def load_skill_names() -> dict[int, dict[str, object]]:
    with SKILL_TABLE.open(newline="", encoding="utf-8") as fh:
        rows = csv.DictReader(fh, delimiter="\t")
        result: dict[int, dict[str, object]] = {}
        for row in rows:
            skill_id = int(row["skill_id"])
            who_offset = row["who_offset"]
            result[skill_id] = {
                "skill_id": skill_id,
                "who_offset": int(who_offset) if who_offset else None,
                "text": row["text"],
            }
        return result


def parse_raw_operands(body: str) -> tuple[str, ...]:
    match = RAW_RE.search(body)
    if not match:
        return ()
    return tuple(part.strip() for part in match.group("operands").split(",") if part.strip())


def first_operand_kind(operands: tuple[str, ...]) -> str:
    if not operands:
        return "missing"
    try:
        int(operands[0], 0)
    except ValueError:
        return "variable"
    return "constant"


def window(rows: list[object], index: int, radius: int, before: bool) -> tuple[str, ...]:
    if before:
        selected = rows[max(0, index - radius) : index]
    else:
        selected = rows[index + 1 : index + 1 + radius]
    return tuple(getattr(row, "row") for row in selected)


def region_context(regions_by_block: dict[int, list[object]], block_id: int, address: int) -> tuple[str | None, tuple[str, ...]]:
    for region in regions_by_block.get(block_id, []):
        target = getattr(region, "target")
        end = getattr(region, "end")
        if address >= target and (end is None or address < end):
            return f"0x{target:04X}", tuple(getattr(region, "incoming"))
    return None, ()


def nearest_previous_who(instructions: list[object], index: int) -> str | None:
    for instr in reversed(instructions[:index]):
        if getattr(instr, "opcode") == 0x39:
            return getattr(instr, "row")
    return None


def prompt_from_who_body(body: str) -> str:
    matches = STRING_RE.findall(body)
    texts = [(single or double).strip() for single, double in matches if (single or double).strip()]
    return " | ".join(texts)


def recover_callsites() -> tuple[list[SkillCheckCallsite], list[WhoContext]]:
    skill_names = load_skill_names()
    entries_by_block, instructions_by_block = load_listings(LISTING_DIR)
    regions_by_block = build_regions(entries_by_block, instructions_by_block)

    callsites: list[SkillCheckCallsite] = []
    who_contexts: list[WhoContext] = []

    for block_id, instructions in sorted(instructions_by_block.items()):
        for index, instr in enumerate(instructions):
            region_target, incoming = region_context(regions_by_block, block_id, instr.address)
            if instr.opcode == 0x39:
                who_contexts.append(
                    WhoContext(
                        block_id=block_id,
                        address=instr.address,
                        address_hex=f"0x{instr.address:04X}",
                        prompt=prompt_from_who_body(instr.body),
                        row=instr.row,
                        branch_region_target=region_target,
                        branch_region_incoming=incoming,
                        previous_rows=window(instructions, index, 5, before=True),
                        following_rows=window(instructions, index, 5, before=False),
                    )
                )
            if instr.opcode != 0x23:
                continue

            operands = parse_raw_operands(instr.body)
            candidate_skill_id: int | None = None
            candidate_skill_name: str | None = None
            candidate_who_offset: int | None = None
            if operands and first_operand_kind(operands) == "constant":
                value = int(operands[0], 0)
                skill = skill_names.get(value)
                if skill and value != 0:
                    candidate_skill_id = value
                    candidate_skill_name = str(skill["text"])
                    candidate_who_offset = int(skill["who_offset"])

            callsites.append(
                SkillCheckCallsite(
                    block_id=block_id,
                    address=instr.address,
                    address_hex=f"0x{instr.address:04X}",
                    opcode="0x23",
                    current_listing_label=instr.body.split(" ", 1)[0],
                    matrix_candidate_label="SKILL_CHECK",
                    operand_count=len(operands),
                    operands=operands,
                    first_operand_kind=first_operand_kind(operands),
                    candidate_skill_id=candidate_skill_id,
                    candidate_skill_name=candidate_skill_name,
                    candidate_who_offset=candidate_who_offset,
                    result_operand=operands[-1] if operands else None,
                    branch_region_target=region_target,
                    branch_region_incoming=incoming,
                    nearest_previous_who=nearest_previous_who(instructions, index),
                    previous_rows=window(instructions, index, 8, before=True),
                    following_rows=window(instructions, index, 8, before=False),
                    evidence_limit=(
                        "Opcode 0x23 is treated as a Matrix SKILL_CHECK candidate from the "
                        "stub audit, but operand roles and success rules require local VM/DOS validation."
                    ),
                )
            )

    return callsites, who_contexts


def write_tsv(path: Path, rows: list[dict[str, object]], fieldnames: list[str]) -> None:
    with path.open("w", newline="", encoding="utf-8") as fh:
        writer = csv.DictWriter(fh, delimiter="\t", fieldnames=fieldnames)
        writer.writeheader()
        for row in rows:
            flattened = {
                key: " | ".join(value) if isinstance(value, (tuple, list)) else value
                for key, value in row.items()
            }
            writer.writerow(flattened)


def write_readme(callsites: list[SkillCheckCallsite], who_contexts: list[WhoContext]) -> None:
    constant = [row for row in callsites if row.candidate_skill_id is not None]
    variable = [row for row in callsites if row.candidate_skill_id is None]
    lines = [
        "# Matrix Cubed Skill-Check Opcode Recovery - 2026-07-08",
        "",
        "This artifact records ECL opcode `0x23` callsites as Matrix `SKILL_CHECK` candidates.",
        "The current generic listing still labels them as `SURPRISE`; operand semantics are not implemented here.",
        "",
        "## Summary",
        "",
        f"- opcode `0x23` callsites: {len(callsites)}",
        f"- callsites with constant first operand that maps to the recovered skill table: {len(constant)}",
        f"- callsites with variable first operand: {len(variable)}",
        f"- WHO prompt contexts recorded for correlation: {len(who_contexts)}",
        "",
        "## 0x23 Callsites",
        "",
        "| ECL block | Address | Operands | Candidate skill | Context |",
        "|---:|---:|---|---|---|",
    ]
    for row in callsites:
        skill = "variable/unknown"
        if row.candidate_skill_id is not None:
            skill = f"{row.candidate_skill_id} / {row.candidate_skill_name} (.WHO 0x{row.candidate_who_offset:02X})"
        lines.append(
            f"| {row.block_id} | {row.address_hex} | `{', '.join(row.operands)}` | {skill} | "
            f"region {row.branch_region_target or 'unknown'} |"
        )

    lines.extend(
        [
            "",
            "## Boundary",
            "",
            "- `candidate_skill_id` is only filled when operand 0 is a numeric id present in the recovered skill table.",
            "- Variable operands need backward dataflow through nearby `SAVE`, `RANDOM`, and branch rows before they can be named.",
            "- No runtime opcode behavior, roll threshold, selected-character rule, advancement rule, or VM writeback rule is promoted by this artifact.",
        ]
    )
    (OUT_DIR / "README.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    callsites, who_contexts = recover_callsites()
    callsite_rows = [asdict(row) for row in callsites]
    who_rows = [asdict(row) for row in who_contexts]

    (OUT_DIR / "skill_check_opcodes.json").write_text(json.dumps(callsite_rows, indent=2) + "\n", encoding="utf-8")
    (OUT_DIR / "who_contexts.json").write_text(json.dumps(who_rows, indent=2) + "\n", encoding="utf-8")
    write_tsv(
        OUT_DIR / "skill_check_opcodes.tsv",
        callsite_rows,
        [
            "block_id",
            "address",
            "address_hex",
            "opcode",
            "current_listing_label",
            "matrix_candidate_label",
            "operand_count",
            "operands",
            "first_operand_kind",
            "candidate_skill_id",
            "candidate_skill_name",
            "candidate_who_offset",
            "result_operand",
            "branch_region_target",
            "branch_region_incoming",
            "nearest_previous_who",
            "previous_rows",
            "following_rows",
            "evidence_limit",
        ],
    )
    write_tsv(
        OUT_DIR / "who_contexts.tsv",
        who_rows,
        [
            "block_id",
            "address",
            "address_hex",
            "prompt",
            "row",
            "branch_region_target",
            "branch_region_incoming",
            "previous_rows",
            "following_rows",
        ],
    )
    write_readme(callsites, who_contexts)
    print(f"wrote {len(callsites)} opcode 0x23 callsites and {len(who_contexts)} WHO contexts to {OUT_DIR}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
