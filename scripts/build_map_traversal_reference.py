#!/usr/bin/env python3
"""Build a map traversal evidence reference from decoded GEO cells and ECL loads."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


LOAD_GEO_RE = re.compile(r"^(0x[0-9A-Fa-f]+)\s+0x21 LOAD FILES Load GEO ([^ ]+) raw=\(([^)]*)\)")
SAVE_POS_RE = re.compile(r"^(0x[0-9A-Fa-f]+)\s+0x09 SAVE (mapPos[XY]) = (\d+)")
BLOCK_RE = re.compile(r"ecl1_(\d+)\.ecl\.txt$")


def build_reference(root: Path) -> dict:
    seed = json.loads((root / "generated" / "viewer" / "matrix_cubed_runtime_seed.json").read_text(encoding="utf-8"))
    maps = {int(row["id"]): row for row in seed["maps"]}
    loaded_ids = set(maps)
    cell_edges = build_cell_edges(maps, loaded_ids)
    ecl_loads = build_ecl_loads(root / "generated" / "ecl1_disasm", loaded_ids)
    ecl_targets = {row["target_geo"] for row in ecl_loads if row["target_loaded"]}
    cell_targets = {row["target_geo"] for row in cell_edges if row["target_loaded"]}
    covered = sorted(ecl_targets | cell_targets)
    return {
        "source": "scripts/build_map_traversal_reference.py",
        "summary": {
            "loaded_map_count": len(loaded_ids),
            "loaded_maps": sorted(loaded_ids),
            "ecl_load_count": len(ecl_loads),
            "loaded_ecl_target_count": len(ecl_targets),
            "cell_edge_count": len(cell_edges),
            "loaded_cell_target_count": len(cell_targets),
            "covered_loaded_map_count": len(set(covered)),
            "covered_loaded_maps": covered,
            "uncovered_loaded_maps": sorted(loaded_ids - set(covered)),
            "evidence_limit": "ECL LOAD FILES rows prove map load targets, not complete player route conditions. Cell edges are only promoted when the target is an already decoded GEO map.",
        },
        "ecl_loads": ecl_loads,
        "cell_edges": cell_edges,
    }


def build_cell_edges(maps: dict[int, dict], loaded_ids: set[int]) -> list[dict]:
    edges = []
    for source_id, row in sorted(maps.items()):
        for cell in row.get("cells", []):
            target = int(cell.get("eventId") or 0)
            if not target or cell.get("eventFlag"):
                continue
            edges.append(
                {
                    "source_geo": source_id,
                    "source_name": row["name"],
                    "row": int(cell["row"]),
                    "col": int(cell["col"]),
                    "target_geo": target,
                    "target_loaded": target in loaded_ids,
                    "interpretation": "promoted_transition" if target in loaded_ids else "local_event_or_unresolved_exit",
                }
            )
    return edges


def build_ecl_loads(disasm_dir: Path, loaded_ids: set[int]) -> list[dict]:
    rows = []
    for path in sorted(disasm_dir.glob("ecl1_*.ecl.txt")):
        match = BLOCK_RE.search(path.name)
        if not match:
            continue
        block_id = int(match.group(1))
        lines = path.read_text(encoding="utf-8").splitlines()
        for index, line in enumerate(lines):
            load_match = LOAD_GEO_RE.match(line)
            if not load_match:
                continue
            target_text = load_match.group(2)
            target_geo = int(target_text) if target_text.isdigit() else None
            pos = nearest_literal_position(lines, index)
            rows.append(
                {
                    "ecl_block": block_id,
                    "address": load_match.group(1),
                    "target": target_text,
                    "target_geo": target_geo,
                    "target_loaded": target_geo in loaded_ids if target_geo is not None else False,
                    "raw_operands": load_match.group(3),
                    "map_pos_x": pos.get("mapPosX"),
                    "map_pos_y": pos.get("mapPosY"),
                    "row": line,
                }
            )
    return rows


def nearest_literal_position(lines: list[str], start_index: int, window: int = 16) -> dict[str, int]:
    pos: dict[str, int] = {}
    for line in lines[start_index + 1 : start_index + 1 + window]:
        match = SAVE_POS_RE.match(line)
        if match:
            pos[match.group(2)] = int(match.group(3))
        if " EXIT" in line or " RETURN" in line or " GOTO " in line:
            break
    return pos


def write_markdown(report: dict, path: Path) -> None:
    summary = report["summary"]
    lines = [
        "# Map Traversal Reference",
        "",
        "This report records decoded traversal evidence from GEO cells and ECL `LOAD FILES Load GEO` instructions.",
        "",
        "## Summary",
        "",
        f"- Loaded maps: {summary['loaded_map_count']}",
        f"- ECL load rows: {summary['ecl_load_count']}",
        f"- Loaded ECL targets: {summary['loaded_ecl_target_count']}",
        f"- Cell edge rows: {summary['cell_edge_count']}",
        f"- Loaded cell targets: {summary['loaded_cell_target_count']}",
        f"- Covered loaded maps: {summary['covered_loaded_map_count']}",
        f"- Uncovered loaded maps: {', '.join(map(str, summary['uncovered_loaded_maps'])) or '-'}",
        f"- Evidence limit: {summary['evidence_limit']}",
        "",
        "## ECL Loads",
        "",
        "| ECL | Address | Target | Loaded | X | Y |",
        "|---:|---|---:|---|---:|---:|",
    ]
    for row in report["ecl_loads"]:
        lines.append(
            f"| {row['ecl_block']} | `{row['address']}` | `{row['target']}` | `{row['target_loaded']}` | "
            f"{row['map_pos_x'] if row['map_pos_x'] is not None else ''} | {row['map_pos_y'] if row['map_pos_y'] is not None else ''} |"
        )
    lines.extend(["", "## Promoted Cell Edges", "", "| Source | Cell | Target | Interpretation |", "|---|---|---:|---|"])
    for row in report["cell_edges"]:
        if not row["target_loaded"]:
            continue
        lines.append(
            f"| GEO {row['source_geo']:03} {row['source_name']} | {row['row']},{row['col']} | "
            f"{row['target_geo']} | {row['interpretation']} |"
        )
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--out-json", type=Path, default=Path("generated/traversal/map_traversal_reference.json"))
    parser.add_argument("--out-md", type=Path, default=Path("generated/traversal/map_traversal_reference.md"))
    args = parser.parse_args()

    report = build_reference(args.root.resolve())
    args.out_json.parent.mkdir(parents=True, exist_ok=True)
    args.out_json.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    write_markdown(report, args.out_md)
    print(
        f"map traversal reference: {report['summary']['covered_loaded_map_count']}/"
        f"{report['summary']['loaded_map_count']} loaded maps covered by current evidence"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
