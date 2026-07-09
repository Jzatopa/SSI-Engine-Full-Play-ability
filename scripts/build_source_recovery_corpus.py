#!/usr/bin/env python3
"""Build a navigable source-recovery corpus from Ghidra decompile exports."""

from __future__ import annotations

import csv
import json
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "generated" / "source_recovery"


@dataclass(frozen=True)
class ProgramSpec:
    key: str
    title: str
    ghidra_dir: Path
    out_subdir: str
    original_offset_delta: int | None
    evidence_limit: str


PROGRAMS = [
    ProgramSpec(
        key="start_unpacked",
        title="START.unpacked.exe",
        ghidra_dir=ROOT / "generated" / "ghidra" / "deep_start_unpacked",
        out_subdir="start_unpacked",
        original_offset_delta=None,
        evidence_limit=(
            "Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, "
            "not original source text."
        ),
    ),
    ProgramSpec(
        key="game_ovr_payload",
        title="GAME.OVR payload",
        ghidra_dir=ROOT / "generated" / "ghidra" / "deep_game_ovr_payload",
        out_subdir="game_ovr_payload",
        original_offset_delta=8,
        evidence_limit=(
            "Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; "
            "relocation and overlay-manager context are not recovered."
        ),
    ),
]


ANCHOR_LABELS = {
    "combat_start": "combat",
    "character_creation": "character_creation",
    "shop_menu": "shop",
    "item0_loader": "items",
    "save_character": "save_load",
    "load_game": "save_load",
    "save_game": "save_load",
    "character_sheet_labels": "character_sheet",
    "item_debug_fields": "items",
    "gear_menu": "inventory",
    "ship_stats": "ship",
    "wall_loader_wall_def_1": "wall_loader",
    "wall_loader_wall_def_2": "wall_loader",
    "load3dmap_geo": "map_loader",
    "load3dmap_error": "map_loader",
}


def read_tsv(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def read_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def segmented_to_linear(address: str) -> int:
    segment, offset = address.split(":", 1)
    return int(segment, 16) * 16 + int(offset, 16)


def safe_name(value: str) -> str:
    return "".join(ch if ch.isalnum() or ch in "._-" else "_" for ch in value)


def source_file_name(entry: str, name: str) -> str:
    return safe_name(f"{entry}_{name}.c")


def recovered_file_name(entry: str, name: str) -> str:
    return safe_name(f"{entry.replace(':', '_')}_{name}.c")


def load_anchor_roles() -> dict[tuple[str, str], list[dict[str, Any]]]:
    comparison = read_json(OUT_DIR.parent / "ghidra" / "comparison" / "ghidra_evidence_comparison.json")
    roles: dict[tuple[str, str], list[dict[str, Any]]] = {}
    for anchor in comparison["game_ovr"]["anchors"]:
        role = ANCHOR_LABELS.get(anchor["name"], "anchor")
        for side in ("previous", "next"):
            function = anchor["nearest_functions"].get(side)
            if not function:
                continue
            key = (function["entry"], function["name"])
            roles.setdefault(key, []).append(
                {
                    "anchor": anchor["name"],
                    "role": role,
                    "side": side,
                    "distance": function["distance"],
                    "file_offset": anchor["offset"],
                    "ghidra_address": anchor["ghidra_address"],
                }
            )
    return roles


def load_decompile_status(spec: ProgramSpec) -> dict[tuple[str, str], dict[str, str]]:
    status = {}
    for row in read_tsv(spec.ghidra_dir / "decompile_summary.tsv"):
        status[(row["entry"], row["name"])] = row
    return status


def file_header(spec: ProgramSpec, row: dict[str, str], roles: list[dict[str, Any]]) -> str:
    linear = segmented_to_linear(row["entry"])
    original_offset = None
    if spec.original_offset_delta is not None:
        original_offset = linear + spec.original_offset_delta
    lines = [
        "/*",
        " * Matrix Cubed source recovery corpus",
        f" * Program: {spec.title}",
        f" * Ghidra entry: {row['entry']}",
        f" * Ghidra name: {row['name']}",
        f" * Linear address: 0x{linear:05X}",
    ]
    if original_offset is not None:
        lines.append(f" * Original GAME.OVR file offset: {original_offset}")
    lines.extend(
        [
            f" * Body addresses: {row['body_addresses']}",
            f" * Calling convention: {row['calling_convention']}",
            f" * Evidence limit: {spec.evidence_limit}",
        ]
    )
    if roles:
        lines.append(" * Nearby project anchors:")
        for role in roles:
            lines.append(
                " *   - "
                f"{role['anchor']} ({role['role']}), {role['side']} candidate, "
                f"distance {role['distance']} byte(s), source offset {role['file_offset']}"
            )
    lines.extend([" */", ""])
    return "\n".join(lines)


def copy_program(spec: ProgramSpec, anchor_roles: dict[tuple[str, str], list[dict[str, Any]]]) -> dict[str, Any]:
    out_dir = OUT_DIR / spec.out_subdir
    if out_dir.exists():
        shutil.rmtree(out_dir)
    out_dir.mkdir(parents=True)

    functions = read_tsv(spec.ghidra_dir / "functions.tsv")
    statuses = load_decompile_status(spec)
    recovered_rows = []
    missing_outputs = []

    for row in functions:
        status = statuses.get((row["entry"], row["name"]))
        source = spec.ghidra_dir / "decompiled" / source_file_name(row["entry"], row["name"])
        target = out_dir / recovered_file_name(row["entry"], row["name"])
        roles = anchor_roles.get((row["entry"], row["name"]), []) if spec.key == "game_ovr_payload" else []
        linear = segmented_to_linear(row["entry"])
        original_offset = linear + spec.original_offset_delta if spec.original_offset_delta is not None else None

        if not source.exists():
            missing_outputs.append({"entry": row["entry"], "name": row["name"], "expected": str(source)})
            continue

        recovered_source = file_header(spec, row, roles) + source.read_text(encoding="utf-8")
        target.write_text(recovered_source, encoding="utf-8")
        recovered_rows.append(
            {
                "entry": row["entry"],
                "name": row["name"],
                "linear": linear,
                "linear_hex": f"0x{linear:05X}",
                "original_file_offset": original_offset,
                "body_addresses": int(row["body_addresses"]),
                "calling_convention": row["calling_convention"],
                "is_thunk": row["is_thunk"] == "true",
                "completed": status["completed"] == "true" if status else None,
                "timed_out": status["timed_out"] == "true" if status else None,
                "error": status["error"] if status else None,
                "roles": roles,
                "recovered_file": str(target.relative_to(ROOT)),
                "source_decompile_file": str(source.relative_to(ROOT)),
            }
        )

    recovered_rows.sort(key=lambda item: item["linear"])
    return {
        "key": spec.key,
        "title": spec.title,
        "function_count": len(functions),
        "recovered_file_count": len(recovered_rows),
        "missing_output_count": len(missing_outputs),
        "missing_outputs": missing_outputs,
        "completed_count": sum(1 for row in recovered_rows if row["completed"]),
        "timed_out_count": sum(1 for row in recovered_rows if row["timed_out"]),
        "error_count": sum(1 for row in recovered_rows if row["error"]),
        "anchor_candidate_count": sum(1 for row in recovered_rows if row["roles"]),
        "evidence_limit": spec.evidence_limit,
        "functions": recovered_rows,
    }


def write_markdown(manifest: dict[str, Any]) -> None:
    lines = [
        "# Matrix Cubed Source Recovery Corpus",
        "",
        "This is a cleaned, navigable corpus of every available Ghidra decompile export.",
        "It is not original SSI source. Treat it as evidence-backed pseudocode for manual reconstruction.",
        "",
        "## Summary",
        "",
    ]
    for program in manifest["programs"]:
        lines.extend(
            [
                f"### {program['title']}",
                "",
                f"- Recovered files: `{program['recovered_file_count']}/{program['function_count']}`",
                f"- Completed decompiles: `{program['completed_count']}`",
                f"- Timeouts: `{program['timed_out_count']}`",
                f"- Errors: `{program['error_count']}`",
                f"- Anchor candidate functions: `{program['anchor_candidate_count']}`",
                f"- Evidence limit: {program['evidence_limit']}",
                "",
            ]
        )

    game = next(program for program in manifest["programs"] if program["key"] == "game_ovr_payload")
    anchor_rows = [row for row in game["functions"] if row["roles"]]
    lines.extend(
        [
            "## GAME.OVR Anchor Candidates",
            "",
            "| Role | Anchor | Candidate | Source offset | Distance | Recovered file |",
            "|---|---|---|---:|---:|---|",
        ]
    )
    for row in anchor_rows:
        for role in row["roles"]:
            lines.append(
                "| "
                + " | ".join(
                    [
                        f"`{role['role']}`",
                        f"`{role['anchor']}`",
                        f"`{row['entry']} {row['name']}`",
                        str(role["file_offset"]),
                        str(role["distance"]),
                        f"`{row['recovered_file']}`",
                    ]
                )
                + " |"
            )

    lines.extend(
        [
            "",
            "## Use Policy",
            "",
            "- Use recovered files to name and inspect candidate functions.",
            "- Validate behavior against local binaries, generated DAX/ECL/GEO artifacts, and DOS captures before runtime changes.",
            "- Do not copy anonymous Ghidra names into runtime APIs as if they were original names.",
            "- For GAME.OVR, original file offset equals `linear + 8` because the Ghidra import starts after the FBOV header.",
            "",
        ]
    )
    (OUT_DIR / "README.md").write_text("\n".join(lines), encoding="utf-8")


def build_corpus() -> dict[str, Any]:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    anchor_roles = load_anchor_roles()
    programs = [copy_program(spec, anchor_roles) for spec in PROGRAMS]
    manifest = {
        "description": "Clean source-recovery corpus generated from Ghidra pseudocode exports.",
        "not_source_equivalent": True,
        "source_equivalence_limit": (
            "No original variable names, original source layout, overlay relocations, or compiler-intent proof "
            "are recovered by this pass."
        ),
        "programs": programs,
    }
    (OUT_DIR / "manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    write_markdown(manifest)
    return manifest


def main() -> int:
    manifest = build_corpus()
    for program in manifest["programs"]:
        print(
            f"{program['title']}: "
            f"{program['recovered_file_count']}/{program['function_count']} recovered, "
            f"{program['anchor_candidate_count']} anchor candidates"
        )
    print(f"Wrote {OUT_DIR / 'manifest.json'}")
    print(f"Wrote {OUT_DIR / 'README.md'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
