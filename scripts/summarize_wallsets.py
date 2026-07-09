#!/usr/bin/env python3
"""Summarize first WALLDEF/load-pieces choices for each GEO map."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


WALLDEF_RE = re.compile(r"0x([0-9A-F]{4})\s+0x37 LOAD PIECES Load WALLDEF (.+?) (.+?) (.+)$")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("event_atlas", type=Path)
    parser.add_argument("ecl_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()

    atlas = json.loads(args.event_atlas.read_text(encoding="utf-8"))
    rows = []
    for item in atlas:
        ecl_block = item["ecl_block"]
        wallsets = None
        source_addr = ""
        if ecl_block is None:
            ecl_path = None
        else:
            ecl_path = args.ecl_dir / f"ecl1_{ecl_block:03d}.ecl.txt"
        if ecl_path is not None and ecl_path.exists():
            for line in ecl_path.read_text(encoding="utf-8").splitlines():
                match = WALLDEF_RE.search(line)
                if match:
                    source_addr = "0x" + match.group(1)
                    wallsets = (match.group(2), match.group(3), match.group(4))
                    break
        rows.append(
            {
                "geo_id": item["geo_id"],
                "name": item["name"],
                "ecl_block": ecl_block,
                "source_addr": source_addr,
                "wallsets": wallsets,
            }
        )

    args.out_dir.mkdir(parents=True, exist_ok=True)

    tsv = ["geo_id\tname\tecl_block\tsource_addr\twalldef_1\twalldef_2\twalldef_3"]
    for row in rows:
        wallsets = row["wallsets"] or ("", "", "")
        ecl_block = "" if row["ecl_block"] is None else row["ecl_block"]
        tsv.append(
            f"{row['geo_id']}\t{row['name']}\t{ecl_block}\t{row['source_addr']}\t"
            f"{wallsets[0]}\t{wallsets[1]}\t{wallsets[2]}"
        )
    (args.out_dir / "wallsets.tsv").write_text("\n".join(tsv) + "\n", encoding="utf-8")

    md = [
        "# GEO Wallset Summary",
        "",
        "First `LOAD PIECES / Load WALLDEF` command seen in each map's ECL block.",
        "",
    ]
    for row in rows:
        wallsets = row["wallsets"]
        if wallsets is None:
            detail = "no WALLDEF load found"
        else:
            detail = f"`{wallsets[0]}`, `{wallsets[1]}`, `{wallsets[2]}` at `{row['source_addr']}`"
        ecl_block = "---" if row["ecl_block"] is None else f"{row['ecl_block']:03d}"
        md.append(f"- GEO `{row['geo_id']:03d}` `{row['name']}` ECL `{ecl_block}`: {detail}")
    (args.out_dir / "wallsets.md").write_text("\n".join(md) + "\n", encoding="utf-8")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
