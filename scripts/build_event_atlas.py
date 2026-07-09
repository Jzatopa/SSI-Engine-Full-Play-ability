#!/usr/bin/env python3
"""Build a readable GEO event -> ECL text atlas."""

from __future__ import annotations

import argparse
import ast
import html
import json
import re
from pathlib import Path


def parse_listing(path: Path) -> dict:
    instructions = []
    on_gotos = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.startswith("0x"):
            continue
        m = re.match(r"0x([0-9A-F]{4})\s+0x([0-9A-F]{2})\s+(.+)", line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        body = m.group(3)
        instructions.append((addr, body, line))
        if "ON GOTO" in body and " of [" in body:
            targets = [int(x, 16) for x in re.findall(r"0x([0-9A-F]{4})", body.split(" of [", 1)[1])]
            on_gotos.append((addr, targets, line))
    instructions.sort()
    return {"instructions": instructions, "on_gotos": on_gotos}


def first_print_after(listing: dict, target: int) -> str:
    snippets = []
    for addr, body, line in listing["instructions"]:
        if addr < target:
            continue
        if snippets and (addr > target + 0x180):
            break
        if "PRINT" in body:
            text = line.split("PRINT", 1)[1].strip()
            # Remove opcode-specific prefix if present.
            text = re.sub(r"^(CLEAR|RETURN)\s+", "", text)
            if text:
                snippets.append(text)
        if snippets and any(term in body for term in ("COMBAT", "GOTO", "RETURN", "EXIT")):
            break
        if len(snippets) >= 3:
            break
    return " ".join(snippets) if snippets else ""


def choose_listing(geo_id: int, refs: list[int], listings_dir: Path):
    candidates = [geo_id] + refs
    for block_id in candidates:
        p = listings_dir / f"ecl1_{block_id:03d}.ecl.txt"
        if p.exists():
            return block_id, p
    return None, None


def event_grid_html(cells: list[dict], event_info: dict[int, dict]) -> str:
    tds = []
    for idx, cell in enumerate(cells):
        ev = cell["event_id"]
        title = ""
        if ev in event_info:
            title = event_info[ev].get("text", "")
        label = ".." if ev == 0 else f"{ev:02X}"
        cls = "empty" if ev == 0 else "event"
        if idx % 16 == 0:
            tds.append("<tr>")
        tds.append(f'<td class="{cls}" title="{html.escape(title)}">{label}</td>')
        if idx % 16 == 15:
            tds.append("</tr>")
    return "<table>" + "".join(tds) + "</table>"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("geo_json", type=Path)
    parser.add_argument("geo_tsv", type=Path)
    parser.add_argument("listings_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)

    maps = json.loads(args.geo_json.read_text(encoding="utf-8"))
    refs_by_geo = {}
    for line in args.geo_tsv.read_text(encoding="utf-8").splitlines()[1:]:
        parts = line.split("\t")
        if len(parts) >= 7:
            refs_by_geo[int(parts[0])] = [int(x) for x in parts[6].split(",") if x]

    listing_cache = {}
    atlas = []
    for m in maps:
        block_id, listing_path = choose_listing(m["id"], refs_by_geo.get(m["id"], []), args.listings_dir)
        event_info = {}
        if listing_path:
            listing = listing_cache.setdefault(listing_path, parse_listing(listing_path))
            # Use the first ON GOTO with enough entries for this map's highest event.
            chosen = None
            for _, targets, _ in listing["on_gotos"]:
                if len(targets) > m["highest_event"]:
                    chosen = targets
                    break
            if chosen:
                for ev in sorted(int(k) for k in m["event_counts"].keys()):
                    if ev < len(chosen):
                        target = chosen[ev]
                        event_info[ev] = {"target": target, "text": first_print_after(listing, target)}
        atlas.append({"geo_id": m["id"], "name": m["name"], "ecl_block": block_id, "events": event_info})

    (args.out_dir / "event_atlas.json").write_text(json.dumps(atlas, indent=2), encoding="utf-8")

    md = ["# Matrix Cubed Event Atlas", ""]
    html_parts = [
        "<!doctype html><meta charset='utf-8'><title>Matrix Cubed Event Atlas</title>",
        "<style>body{font:14px system-ui,sans-serif;background:#181818;color:#eee;margin:24px}table{border-collapse:collapse;margin:12px 0 28px}td{width:34px;height:28px;text-align:center;border:1px solid #444;font-family:ui-monospace,monospace}.empty{color:#555;background:#202020}.event{background:#29445f;color:#fff}h2{margin-top:32px}li{margin:4px 0}</style>",
        "<h1>Matrix Cubed Event Atlas</h1>",
    ]
    for m, item in zip(maps, atlas):
        md.extend([f"## GEO {m['id']}: {m['name']}", "", f"- ECL block used: {item['ecl_block'] or '-'}", ""])
        html_parts.append(f"<h2>GEO {m['id']}: {html.escape(m['name'])}</h2>")
        html_parts.append(f"<p>ECL block used: {item['ecl_block'] or '-'}</p>")
        html_parts.append(event_grid_html(m["cells"], item["events"]))
        if item["events"]:
            md.append("| Event | Target | First Nearby Text |")
            md.append("|---:|---:|---|")
            html_parts.append("<ul>")
            for ev, info in sorted(item["events"].items(), key=lambda kv: int(kv[0])):
                text = info.get("text", "")
                target = info.get("target", 0)
                md.append(f"| {int(ev)} | `0x{target:04X}` | {text} |")
                html_parts.append(f"<li><b>{int(ev):02X}</b> -> 0x{target:04X}: {html.escape(text)}</li>")
            html_parts.append("</ul>")
        else:
            md.append("_No event target mapping found in first pass._")
        md.append("")
    (args.out_dir / "event_atlas.md").write_text("\n".join(md), encoding="utf-8")
    (args.out_dir / "event_atlas.html").write_text("\n".join(html_parts), encoding="utf-8")
    print(f"wrote event atlas to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
