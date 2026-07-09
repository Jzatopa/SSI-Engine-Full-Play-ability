#!/usr/bin/env python3
"""Scan GAME.OVR for raw GEO-shaped map blocks.

This is an evidence generator, not a semantic map importer. The current local
Matrix Cubed source folder has GEO1.DAX only, while GAME.OVR contains loader
strings for GEO*.DAX. This script records whether the overlay also contains
plain 1026-byte GEO map blocks matching the established GEO1 layout.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "src"
if str(SRC) not in sys.path:
    sys.path.insert(0, str(SRC))
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from matrix_cubed.formats.dax import DaxBlock, read_dax  # noqa: E402
from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()
GEO_BLOCK_SIZE = 1026


@dataclass(frozen=True)
class GeoScanMetrics:
    offset: int
    header_hex: str
    sha256: str
    north_south_match_ratio: float
    east_west_match_ratio: float
    known_door_ratio: float
    event_id_under_64_ratio: float
    event_high_bit_ratio: float
    nonzero_wall_nibbles: int
    unique_wall_nibbles: int
    nonzero_event_cells: int
    max_event_id: int
    nonzero_door_cells: int
    accepted: bool
    rejection_reasons: tuple[str, ...]

    def to_json(self) -> dict[str, Any]:
        row = self.__dict__.copy()
        row["rejection_reasons"] = list(self.rejection_reasons)
        return row


def scan_exact_blocks(overlay: bytes, known_blocks: list[DaxBlock]) -> list[dict[str, Any]]:
    rows = []
    for block in known_blocks:
        offset = overlay.find(block.data)
        rows.append(
            {
                "geo_id": block.block_id,
                "decoded_sha256": hashlib.sha256(block.data).hexdigest(),
                "found_in_game_ovr": offset >= 0,
                "offset": offset if offset >= 0 else None,
            }
        )
    return rows


def known_door_values(known_blocks: list[DaxBlock]) -> set[int]:
    values: set[int] = set()
    for block in known_blocks:
        if len(block.data) >= GEO_BLOCK_SIZE:
            values.update(block.data[770:1026])
    return values


def known_headers(known_blocks: list[DaxBlock]) -> set[bytes]:
    return {block.data[:2] for block in known_blocks if len(block.data) >= GEO_BLOCK_SIZE}


def score_geo_window(offset: int, data: bytes, door_values: set[int]) -> GeoScanMetrics:
    if len(data) != GEO_BLOCK_SIZE:
        raise ValueError(f"GEO window must be {GEO_BLOCK_SIZE} bytes, got {len(data)}")

    ne = data[2:258]
    sw = data[258:514]
    events = data[514:770]
    doors = data[770:1026]

    north_south_matches = 0
    east_west_matches = 0
    north_south_total = 0
    east_west_total = 0
    wall_nibbles: list[int] = []
    for index in range(256):
        row, col = divmod(index, 16)
        north = ne[index] >> 4
        east = ne[index] & 0x0F
        south = sw[index] >> 4
        west = sw[index] & 0x0F
        wall_nibbles.extend((north, east, south, west))
        if row > 0:
            north_south_total += 1
            previous_south = sw[index - 16] >> 4
            north_south_matches += int(north == previous_south)
        if col > 0:
            east_west_total += 1
            previous_east = ne[index - 1] & 0x0F
            east_west_matches += int(west == previous_east)

    event_ids = [byte & 0x7F for byte in events]
    reasons: list[str] = []
    north_south_ratio = north_south_matches / north_south_total
    east_west_ratio = east_west_matches / east_west_total
    known_door_ratio = sum(byte in door_values for byte in doors) / len(doors) if door_values else 0.0
    event_id_under_64_ratio = sum(event_id <= 64 for event_id in event_ids) / len(event_ids)
    event_high_bit_ratio = sum(byte >= 128 for byte in events) / len(events)
    nonzero_wall_nibbles = sum(value != 0 for value in wall_nibbles)
    unique_wall_nibbles = len(set(wall_nibbles))

    if known_door_ratio < 0.96:
        reasons.append("door bytes do not match the established GEO1 door-value set")
    if event_id_under_64_ratio < 0.98:
        reasons.append("too many event ids exceed the established GEO1 event range")
    if north_south_ratio < 0.58:
        reasons.append("north/south wall continuity is below the GEO1 minimum")
    if east_west_ratio < 0.58:
        reasons.append("east/west wall continuity is below the GEO1 minimum")
    if nonzero_wall_nibbles < 80 or nonzero_wall_nibbles > 760:
        reasons.append("wall-density is outside the GEO1 observed range")
    if unique_wall_nibbles < 3 or unique_wall_nibbles > 16:
        reasons.append("wall nibble variety is outside the GEO1 observed range")

    return GeoScanMetrics(
        offset=offset,
        header_hex=data[:2].hex(" "),
        sha256=hashlib.sha256(data).hexdigest(),
        north_south_match_ratio=round(north_south_ratio, 4),
        east_west_match_ratio=round(east_west_ratio, 4),
        known_door_ratio=round(known_door_ratio, 4),
        event_id_under_64_ratio=round(event_id_under_64_ratio, 4),
        event_high_bit_ratio=round(event_high_bit_ratio, 4),
        nonzero_wall_nibbles=nonzero_wall_nibbles,
        unique_wall_nibbles=unique_wall_nibbles,
        nonzero_event_cells=sum(event_id != 0 for event_id in event_ids),
        max_event_id=max(event_ids),
        nonzero_door_cells=sum(byte != 0 for byte in doors),
        accepted=not reasons,
        rejection_reasons=tuple(reasons),
    )


def scan_overlay_for_geo_windows(overlay: bytes, known_blocks: list[DaxBlock]) -> dict[str, Any]:
    headers = known_headers(known_blocks)
    door_values = known_door_values(known_blocks)
    header_hits: list[GeoScanMetrics] = []
    accepted: list[GeoScanMetrics] = []

    for offset in range(0, len(overlay) - GEO_BLOCK_SIZE + 1):
        window = overlay[offset : offset + GEO_BLOCK_SIZE]
        if window[:2] not in headers:
            continue
        metrics = score_geo_window(offset, window, door_values)
        header_hits.append(metrics)
        if metrics.accepted:
            accepted.append(metrics)

    header_hits_sorted = sorted(
        header_hits,
        key=lambda row: (
            row.accepted,
            row.known_door_ratio,
            row.event_id_under_64_ratio,
            row.north_south_match_ratio + row.east_west_match_ratio,
        ),
        reverse=True,
    )
    return {
        "known_headers": [value.hex(" ") for value in sorted(headers)],
        "known_door_values": sorted(door_values),
        "header_hit_count": len(header_hits),
        "accepted_candidate_count": len(accepted),
        "accepted_candidates": [row.to_json() for row in accepted],
        "top_header_hits": [row.to_json() for row in header_hits_sorted[:20]],
    }


def find_ascii_anchors(data: bytes, needles: tuple[bytes, ...] = (b"GEO", b".dax", b"Load3DMap", b"WALLDEF")) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for needle in needles:
        start = 0
        while True:
            offset = data.find(needle, start)
            if offset < 0:
                break
            before = max(0, offset - 48)
            after = min(len(data), offset + 96)
            raw = data[before:after]
            rows.append(
                {
                    "needle": needle.decode("ascii"),
                    "offset": offset,
                    "nearby_ascii": "".join(chr(byte) if 32 <= byte < 127 else "." for byte in raw),
                }
            )
            start = offset + 1
    return sorted(rows, key=lambda row: row["offset"])


def build_report(game_ovr: Path, geo1_dax: Path) -> dict[str, Any]:
    overlay = game_ovr.read_bytes()
    known_blocks = read_dax(geo1_dax)
    game_dir = game_ovr.parent
    return {
        "game_ovr": {
            "path": str(game_ovr),
            "bytes": len(overlay),
            "sha256": hashlib.sha256(overlay).hexdigest(),
        },
        "geo_ecl_dax_inventory": [
            {
                "name": path.name,
                "bytes": path.stat().st_size,
                "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
            }
            for path in sorted(game_dir.glob("[GE][EC][OL][0-9].DAX"))
        ],
        "known_geo_source": {
            "path": str(geo1_dax),
            "block_count": len(known_blocks),
            "block_size_counts": {
                str(size): sum(1 for block in known_blocks if len(block.data) == size)
                for size in sorted({len(block.data) for block in known_blocks})
            },
            "block_ids": [block.block_id for block in known_blocks],
        },
        "exact_known_geo_blocks": scan_exact_blocks(overlay, known_blocks),
        "raw_geo_window_scan": scan_overlay_for_geo_windows(overlay, known_blocks),
        "ascii_anchors": find_ascii_anchors(overlay),
    }


def write_markdown(path: Path, report: dict[str, Any]) -> None:
    exact_rows = report["exact_known_geo_blocks"]
    exact_found = [row for row in exact_rows if row["found_in_game_ovr"]]
    scan = report["raw_geo_window_scan"]
    anchors = report["ascii_anchors"]
    lines = [
        "# GAME.OVR Raw GEO Map Scan",
        "",
        "This is a conservative structural scan for plain, uncompressed GEO-shaped map blocks inside `GAME.OVR`.",
        "",
        "## Inputs",
        "",
        f"- GAME.OVR: `{report['game_ovr']['path']}`",
        f"- GAME.OVR bytes: `{report['game_ovr']['bytes']}`",
        f"- GAME.OVR SHA-256: `{report['game_ovr']['sha256']}`",
        f"- Known GEO source: `{report['known_geo_source']['path']}`",
        f"- Known GEO block count: `{report['known_geo_source']['block_count']}`",
        f"- Known GEO block sizes: `{report['known_geo_source']['block_size_counts']}`",
        "",
        "## Local GEO/ECL Inventory",
        "",
    ]
    for row in report["geo_ecl_dax_inventory"]:
        lines.append(f"- `{row['name']}`: `{row['bytes']}` bytes, SHA-256 `{row['sha256']}`")
    lines.extend(
        [
            "",
            "The current local source folder has no `GEO2.DAX`, `GEO3.DAX`, `GEO4.DAX`, `ECL2.DAX`, `ECL3.DAX`, or `ECL4.DAX` files.",
            "",
        ]
    )
    lines.extend(
        [
        "## Result",
        "",
        f"- Exact known GEO1 block copies found in GAME.OVR: `{len(exact_found)}` of `{len(exact_rows)}`",
        f"- Raw 1026-byte windows with a known GEO header: `{scan['header_hit_count']}`",
        f"- Accepted GEO-shaped raw-window candidates: `{scan['accepted_candidate_count']}`",
        "",
        ]
    )
    if scan["accepted_candidate_count"] == 0:
        lines.extend(
            [
                "No raw overlay window satisfied the established GEO1 structural filters. This is negative evidence only: it means this pass did not find plain GEO blocks embedded in `GAME.OVR`; it does not prove maps cannot be loaded indirectly, generated in memory, or stored in a compressed/segmented form.",
                "",
            ]
        )
    if scan["top_header_hits"]:
        lines.extend(["## Header Hits", ""])
        for row in scan["top_header_hits"]:
            reasons = "; ".join(row["rejection_reasons"]) or "accepted"
            lines.append(
                f"- `0x{row['offset']:05X}` header `{row['header_hex']}`: "
                f"door_ratio `{row['known_door_ratio']}`, event_ratio `{row['event_id_under_64_ratio']}`, "
                f"NS `{row['north_south_match_ratio']}`, EW `{row['east_west_match_ratio']}` — {reasons}"
            )
        lines.append("")
    if anchors:
        lines.extend(["## Loader/String Anchors", ""])
        for row in anchors:
            lines.append(f"- `0x{row['offset']:05X}` `{row['needle']}`: `{row['nearby_ascii']}`")
        lines.append("")
    lines.extend(
        [
            "## Next Validation",
            "",
            "- Trace the `Load3DMap`/GEO loader in `GAME.OVR` around the `GEO` and `.dax` anchors to identify how the DAX suffix/index is selected.",
            "- Obtain any missing original disk/install files if they exist; the current local source folder contains `GEO1.DAX` only.",
            "",
        ]
    )
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--game-ovr", type=Path)
    parser.add_argument("--geo1-dax", type=Path)
    parser.add_argument("--out-dir", type=Path, default=Path("generated") / "game_ovr")
    args = parser.parse_args()

    game_ovr = args.game_ovr or args.game_dir / "GAME.OVR"
    geo1_dax = args.geo1_dax or args.game_dir / "GEO1.DAX"
    report = build_report(game_ovr, geo1_dax)
    args.out_dir.mkdir(parents=True, exist_ok=True)
    json_path = args.out_dir / "map_scan.json"
    md_path = args.out_dir / "map_scan.md"
    json_path.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(md_path, report)
    accepted = report["raw_geo_window_scan"]["accepted_candidate_count"]
    print(f"wrote {json_path} and {md_path}; accepted raw GEO candidates: {accepted}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
