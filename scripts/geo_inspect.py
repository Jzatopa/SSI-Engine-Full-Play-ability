#!/usr/bin/env python3
"""Inspect Gold Box GEO*.DAX map blocks."""

from __future__ import annotations

import argparse
import csv
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "tools"))
from extract_goldbox_dax_images import read_dax  # noqa: E402


MATRIX_MAP_NAMES = {
    1: "Luna Base",
    17: "Caloris Space Port",
    18: "Asteroid",
    33: "Losangelorg Sprawls",
    34: "Historical Museum, Levels 2-1",
    35: "Asteroid Base",
    38: "Losangelorg Sprawls",
    49: "Lowlander Village",
    50: "Venus Laboratory, Level 1",
    51: "Venus Laboratory, Level 2",
    52: "Lowlander Mines",
    64: "Luna Base",
    65: "Tsai Weaponry Labs",
    66: "RAM Battler, Deimos Level 19-41",
    80: "Mars Prison, Level 1",
    81: "PURGE Headquarters, Floors Ground-Upper",
    82: "NEO Installation",
    84: "Mars Prison, Level 2",
    96: "Living Ship",
    97: "Living Ship",
    112: "Stormrider University",
    113: "Genetics Foundation Building, Levels 1-4",
    114: "Jupiter Finale",
    115: "Jupiter Aircar",
}


def parse_geo_block(block_id: int, data: bytes) -> dict:
    cells = []
    event_counts = Counter()
    door_counts = Counter()
    for i in range(256):
        row, col = i >> 4, i & 0x0F
        ne = data[i + 2] if i + 2 < len(data) else 0
        sw = data[i + 258] if i + 258 < len(data) else 0
        event = data[i + 514] if i + 514 < len(data) else 0
        door = data[i + 770] if i + 770 < len(data) else 0
        event_id = event & 0x7F
        event_counts[event_id] += 1
        door_counts[door] += 1
        cells.append(
            {
                "row": row,
                "col": col,
                "north": ne >> 4,
                "east": ne & 0x0F,
                "south": sw >> 4,
                "west": sw & 0x0F,
                "event": event,
                "event_id": event_id,
                "event_flag": bool(event & 0x80),
                "door": door,
            }
        )
    interesting_events = {k: v for k, v in sorted(event_counts.items()) if k != 0}
    interesting_doors = {k: v for k, v in sorted(door_counts.items()) if k != 0}
    return {
        "id": block_id,
        "name": MATRIX_MAP_NAMES.get(block_id, str(block_id)),
        "bytes": len(data),
        "highest_event": max(event_counts) if event_counts else 0,
        "event_counts": interesting_events,
        "door_counts": interesting_doors,
        "cells": cells,
    }


def scan_ecl_geo_refs(ecl_path: Path) -> tuple[dict[int, set[int]], dict[int, set[tuple[int, int, int]]]]:
    geo_refs: dict[int, set[int]] = defaultdict(set)
    wall_refs: dict[int, set[tuple[int, int, int]]] = defaultdict(set)
    for block_id, data in read_dax(ecl_path):
        for i in range(0, max(0, len(data) - 7)):
            # LOAD FILES: 0x21 a 0x00 b 0x00 c 0x00, first operand is GEO id in ECLDump.
            if data[i] == 0x21 and data[i + 1] == 0 and data[i + 3] == 0 and data[i + 5] == 0:
                geo_refs[data[i + 2]].add(block_id)
            # LOAD PIECES/WALLDEF: 0x37 a 0x00 b 0x00 c 0x00
            if data[i] == 0x37 and data[i + 1] == 0 and data[i + 3] == 0 and data[i + 5] == 0:
                wall_refs[block_id].add((data[i + 2], data[i + 4], data[i + 6]))
    return geo_refs, wall_refs


def ascii_event_map(cells: list[dict]) -> str:
    rows = []
    for r in range(16):
        vals = []
        for c in range(16):
            cell = cells[r * 16 + c]
            ev = cell["event_id"]
            vals.append(".." if ev == 0 else f"{ev:02X}")
        rows.append(" ".join(vals))
    return "\n".join(rows)


def write_outputs(maps: list[dict], geo_refs: dict[int, set[int]], wall_refs: dict[int, set[tuple[int, int, int]]], out: Path) -> None:
    out.mkdir(parents=True, exist_ok=True)
    (out / "geo1_maps.json").write_text(json.dumps(maps, indent=2), encoding="utf-8")
    with (out / "geo1_maps.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f, delimiter="\t")
        writer.writerow(["geo_id", "name", "bytes", "highest_event", "event_count", "door_count", "referenced_by_ecl", "wallsets_seen_in_ecl"])
        for m in maps:
            refs = ",".join(map(str, sorted(geo_refs.get(m["id"], set()))))
            walls = sorted(set().union(*(wall_refs.get(ref, set()) for ref in geo_refs.get(m["id"], set())))) if refs else []
            writer.writerow(
                [
                    m["id"],
                    m["name"],
                    m["bytes"],
                    m["highest_event"],
                    sum(m["event_counts"].values()),
                    sum(m["door_counts"].values()),
                    refs,
                    ";".join("/".join(map(str, w)) for w in walls),
                ]
            )
    lines = ["# GEO1.DAX Map Summary", ""]
    for m in maps:
        refs = ", ".join(map(str, sorted(geo_refs.get(m["id"], set())))) or "-"
        lines.extend(
            [
                f"## {m['id']}: {m['name']}",
                "",
                f"- Bytes: {m['bytes']}",
                f"- Highest event id: {m['highest_event']}",
                f"- Non-zero event cells: {sum(m['event_counts'].values())}",
                f"- Door cells: {sum(m['door_counts'].values())}",
                f"- Referenced by ECL blocks: {refs}",
                "",
                "Event grid (`..` means no event):",
                "",
                "```text",
                ascii_event_map(m["cells"]),
                "```",
                "",
            ]
        )
    (out / "geo1_summary.md").write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("geo_dax", type=Path)
    parser.add_argument("ecl_dax", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    maps = [parse_geo_block(block_id, data) for block_id, data in read_dax(args.geo_dax)]
    geo_refs, wall_refs = scan_ecl_geo_refs(args.ecl_dax)
    write_outputs(maps, geo_refs, wall_refs, args.out_dir)
    print(f"wrote {len(maps)} GEO maps to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
