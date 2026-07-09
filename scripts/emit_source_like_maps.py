#!/usr/bin/env python3
"""Emit source-like map/event notes from the generated event atlas."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


def slug(text: str) -> str:
    s = re.sub(r"[^a-zA-Z0-9]+", "-", text.lower()).strip("-")
    return s or "map"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("atlas_json", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)
    atlas = json.loads(args.atlas_json.read_text(encoding="utf-8"))
    index = ["# Source-Like Map Event Index", ""]
    for item in atlas:
        geo_id = item["geo_id"]
        name = item["name"]
        out = args.out_dir / f"geo_{geo_id:03d}_{slug(name)}.md"
        index.append(f"- [GEO {geo_id}: {name}]({out.name})")
        lines = [
            f"# GEO {geo_id}: {name}",
            "",
            f"ECL block: `{item.get('ecl_block') or '-'}`",
            "",
            "This is a first-pass source-like reconstruction from GEO event ids and nearby ECL text. It is not original source.",
            "",
            "```text",
            f"module geo_{geo_id:03d}_{slug(name).replace('-', '_')} {{",
            f"  name = {name!r}",
            f"  ecl_block = {item.get('ecl_block')!r}",
            "",
        ]
        events = item.get("events") or {}
        if events:
            for ev, info in sorted(events.items(), key=lambda kv: int(kv[0])):
                text = (info.get("text") or "").replace("\n", " ")
                target = info.get("target", 0)
                lines.extend(
                    [
                        f"  event {int(ev):02d} at 0x{target:04X}:",
                        f"    text_hint = {text!r}",
                        "",
                    ]
                )
        else:
            lines.append("  // No event dispatch mapping found in pass 1.")
            lines.append("")
        lines.extend(["}", "```", ""])
        out.write_text("\n".join(lines), encoding="utf-8")
    (args.out_dir / "index.md").write_text("\n".join(index) + "\n", encoding="utf-8")
    print(f"wrote {len(atlas)} source-like map files to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
