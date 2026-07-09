#!/usr/bin/env python3
"""Compare local Matrix Cubed GEO maps against Gold Box Explorer's map table."""

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from dataclasses import asdict, dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "src"))
sys.path.insert(0, str(ROOT))

from matrix_cubed.formats.dax import read_dax  # noqa: E402
from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()
DEFAULT_GBE_GEO_DAX = Path("/home/jzatopa/Downloads/goldboxexplorer/Common/Plugins/GeoDax/GeoDaxFile.cs")
DEFAULT_OUT_DIR = Path("generated") / "goldbox_explorer_maps"


@dataclass(frozen=True)
class LocalGeoBlock:
    archive: str
    block_id: int
    decoded_size: int


def extract_matrix_map_names(gbe_geo_dax_file: Path) -> dict[int, str]:
    text = gbe_geo_dax_file.read_text(encoding="utf-8-sig")
    marker = "_mapNames.Add((int)FileHelper.GameList.MatrixCubed"
    marker_index = text.find(marker)
    if marker_index < 0:
        raise ValueError(f"MatrixCubed map table marker not found in {gbe_geo_dax_file}")
    table_start = text.rfind("maps = new Dictionary<int, string>", 0, marker_index)
    if table_start < 0:
        raise ValueError(f"MatrixCubed map table start not found in {gbe_geo_dax_file}")
    snippet = text[table_start:marker_index]
    return {
        int(match.group("id")): match.group("name")
        for match in re.finditer(r'\{(?P<id>\d+),\s+"(?P<name>[^"]+)"\}', snippet)
    }


def find_numbered_archives(game_dir: Path, prefix: str) -> list[str]:
    return sorted(path.name for path in game_dir.glob(f"{prefix}*.DAX"))


def load_local_geo_blocks(game_dir: Path) -> list[LocalGeoBlock]:
    blocks: list[LocalGeoBlock] = []
    for geo_path in sorted(game_dir.glob("GEO*.DAX")):
        for block in read_dax(geo_path):
            blocks.append(LocalGeoBlock(geo_path.name, block.block_id, len(block.data)))
    return sorted(blocks, key=lambda item: (item.archive, item.block_id))


def build_audit(game_dir: Path, gbe_geo_dax_file: Path) -> dict[str, object]:
    explorer_names = extract_matrix_map_names(gbe_geo_dax_file)
    local_blocks = load_local_geo_blocks(game_dir)
    local_ids = {block.block_id for block in local_blocks}
    explorer_ids = set(explorer_names)
    return {
        "source": "Gold Box Explorer Common/Plugins/GeoDax/GeoDaxFile.cs MatrixCubed map table",
        "gold_box_explorer_source": str(gbe_geo_dax_file),
        "game_dir": str(game_dir),
        "geo_archives_present": find_numbered_archives(game_dir, "GEO"),
        "ecl_archives_present": find_numbered_archives(game_dir, "ECL"),
        "summary": {
            "local_geo_archive_count": len(find_numbered_archives(game_dir, "GEO")),
            "local_ecl_archive_count": len(find_numbered_archives(game_dir, "ECL")),
            "local_geo_block_count": len(local_blocks),
            "local_geo_unique_id_count": len(local_ids),
            "gold_box_explorer_named_map_count": len(explorer_names),
            "local_ids_missing_from_gold_box_explorer_names": sorted(local_ids - explorer_ids),
            "gold_box_explorer_ids_missing_locally": sorted(explorer_ids - local_ids),
            "all_gold_box_explorer_named_maps_present": explorer_ids <= local_ids,
        },
        "local_geo_blocks": [asdict(block) for block in local_blocks],
        "gold_box_explorer_map_names": [
            {"geo_id": geo_id, "name": explorer_names[geo_id], "present_locally": geo_id in local_ids}
            for geo_id in sorted(explorer_names)
        ],
    }


def write_outputs(audit: dict[str, object], out_dir: Path) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "goldbox_explorer_map_audit.json").write_text(json.dumps(audit, indent=2), encoding="utf-8")

    with (out_dir / "goldbox_explorer_map_audit.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["geo_id", "name", "present_locally"], delimiter="\t")
        writer.writeheader()
        for row in audit["gold_box_explorer_map_names"]:  # type: ignore[index]
            writer.writerow(row)

    summary = audit["summary"]  # type: ignore[index]
    lines = [
        "# Gold Box Explorer Matrix Cubed Map Audit",
        "",
        "This audit compares the local `GEO*.DAX` files against Gold Box Explorer's",
        "`MatrixCubed` map-name table. It uses Gold Box Explorer as a reference,",
        "but does not require running its Windows GUI.",
        "",
        "## Summary",
        "",
        f"- Game directory: `{audit['game_dir']}`",
        f"- Gold Box Explorer source: `{audit['gold_box_explorer_source']}`",
        f"- Local GEO archives present: {', '.join(audit['geo_archives_present']) or '-'}",  # type: ignore[arg-type]
        f"- Local ECL archives present: {', '.join(audit['ecl_archives_present']) or '-'}",  # type: ignore[arg-type]
        f"- Local decoded GEO blocks: {summary['local_geo_block_count']}",
        f"- Gold Box Explorer named Matrix Cubed maps: {summary['gold_box_explorer_named_map_count']}",
        f"- Gold Box Explorer named map IDs missing locally: {summary['gold_box_explorer_ids_missing_locally']}",
        f"- Local GEO IDs missing Gold Box Explorer names: {summary['local_ids_missing_from_gold_box_explorer_names']}",
        "",
        "## Interpretation",
        "",
        "- Gold Box Explorer's Matrix Cubed map table does not identify any named map absent from the local `GEO1.DAX`.",
        "- The only local GEO block without a Gold Box Explorer name is GEO 21, matching prior local notes.",
        "- The current local source set has no `GEO2.DAX`, `GEO3.DAX`, `GEO4.DAX`, `ECL2.DAX`, `ECL3.DAX`, or `ECL4.DAX`.",
        "- This supports treating the 25 decoded `GEO1.DAX` blocks as all map blocks available in the current source set, while leaving room for future evidence from another disk image or installer.",
        "",
        "## Gold Box Explorer Named Maps",
        "",
        "| GEO | Name | Present locally |",
        "|---:|---|---|",
    ]
    for row in audit["gold_box_explorer_map_names"]:  # type: ignore[index]
        lines.append(f"| {row['geo_id']} | {row['name']} | {row['present_locally']} |")
    lines.extend(
        [
            "",
            "## Local GEO Blocks",
            "",
            "| Archive | GEO | Decoded bytes | Gold Box Explorer name |",
            "|---|---:|---:|---|",
        ]
    )
    names = {row["geo_id"]: row["name"] for row in audit["gold_box_explorer_map_names"]}  # type: ignore[index]
    for block in audit["local_geo_blocks"]:  # type: ignore[index]
        lines.append(
            f"| {block['archive']} | {block['block_id']} | {block['decoded_size']} | "
            f"{names.get(block['block_id'], '')} |"
        )
    lines.append("")
    (out_dir / "goldbox_explorer_map_audit.md").write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--goldbox-explorer-geo-dax", type=Path, default=DEFAULT_GBE_GEO_DAX)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    args = parser.parse_args()

    audit = build_audit(args.game_dir, args.goldbox_explorer_geo_dax)
    write_outputs(audit, args.out_dir)
    summary = audit["summary"]
    print(
        "Gold Box Explorer map audit: "
        f"{summary['local_geo_block_count']} local GEO blocks, "
        f"{summary['gold_box_explorer_named_map_count']} GBE named maps, "
        f"{len(summary['gold_box_explorer_ids_missing_locally'])} GBE named maps missing locally"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
