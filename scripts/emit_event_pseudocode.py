#!/usr/bin/env python3
"""Emit fuller per-event pseudocode from atlas targets and ECL listings."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


TERMINATORS = (" EXIT", " RETURN", " NEWECL", " PROGRAM PartyKilled", " PROGRAM GameWon", " PROGRAM TryEncamp")
BRANCH_TERMINATORS = (" GOTO ",)


def slug(text: str) -> str:
    return re.sub(r"[^a-zA-Z0-9]+", "-", text.lower()).strip("-") or "map"


def parse_listing(path: Path) -> list[tuple[int, str]]:
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.startswith("0x"):
            continue
        m = re.match(r"0x([0-9A-F]{4})\s+(.+)", line)
        if not m:
            continue
        rows.append((int(m.group(1), 16), line))
    rows.sort()
    return rows


def body_for_target(rows: list[tuple[int, str]], target: int, max_lines: int = 120) -> list[str]:
    index = {addr: i for i, (addr, _) in enumerate(rows)}
    visited: set[int] = set()
    return collect_body(rows, index, target, visited, max_lines=max_lines)


def collect_body(
    rows: list[tuple[int, str]],
    index: dict[int, int],
    target: int,
    visited: set[int],
    max_lines: int,
    depth: int = 0,
) -> list[str]:
    if target in visited:
        return [f"// branch target 0x{target:04X} already shown"]
    visited.add(target)
    body = []
    start_idx = index.get(target)
    if start_idx is None:
        # Fall back to the next decoded instruction at/after the target.
        start_idx = next((i for i, (addr, _) in enumerate(rows) if addr >= target), None)
    if start_idx is None:
        return [f"// no decoded instructions found at 0x{target:04X}"]

    for addr, line in rows[start_idx:]:
        if body and addr >= target + 0x280:
            body.append(f"// truncated: next decoded instruction is 0x{addr:04X}")
            break
        body.append(rewrite_line(line))
        if "<suspect data/code boundary:" in line:
            break
        if " GOTO " in line:
            m = re.search(r"GOTO 0x([0-9A-F]{4})", line)
            if m and depth < 3:
                branch = int(m.group(1), 16)
                body.append(f"// follows GOTO 0x{branch:04X}")
                body.extend("  " + x for x in collect_body(rows, index, branch, visited, max_lines=max_lines - len(body), depth=depth + 1))
            break
        if " ON GOTO " in line or " ON GOSUB " in line:
            targets = [int(x, 16) for x in re.findall(r"0x([0-9A-F]{4})", line)]
            for branch in targets[:8]:
                if depth < 2:
                    body.append(f"// possible branch 0x{branch:04X}")
                    body.extend("  " + x for x in collect_body(rows, index, branch, visited, max_lines=max_lines - len(body), depth=depth + 1))
            break
        if len(body) >= max_lines:
            body.append("// truncated: max event body lines reached")
            break
        if len(body) >= 1 and any(t in line for t in TERMINATORS):
            break
    return body or [f"// no decoded instructions found at 0x{target:04X}"]


def rewrite_line(line: str) -> str:
    m = re.match(r"0x([0-9A-F]{4})\s+0x([0-9A-F]{2})\s+(.+)", line)
    if not m:
        return "// " + line
    addr, opcode, rest = m.groups()
    rest = rest.strip()
    if "<suspect data/code boundary:" in rest:
        return f"@0x{addr}: suspect data/code boundary; stopped linear decode"
    return f"@0x{addr}: {rest}"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("atlas_json", type=Path)
    parser.add_argument("listings_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)

    atlas = json.loads(args.atlas_json.read_text(encoding="utf-8"))
    listing_cache: dict[int, list[tuple[int, str]]] = {}
    index = ["# Event Pseudocode Index", ""]

    for item in atlas:
        geo_id = item["geo_id"]
        name = item["name"]
        ecl_block = item.get("ecl_block")
        out = args.out_dir / f"geo_{geo_id:03d}_{slug(name)}.pseudo.md"
        index.append(f"- [GEO {geo_id}: {name}]({out.name})")
        lines = [
            f"# GEO {geo_id}: {name}",
            "",
            f"ECL block: `{ecl_block or '-'}`",
            "",
            "First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.",
            "",
        ]
        rows = []
        if ecl_block:
            listing_path = args.listings_dir / f"ecl1_{int(ecl_block):03d}.ecl.txt"
            if listing_path.exists():
                rows = listing_cache.setdefault(int(ecl_block), parse_listing(listing_path))

        events = item.get("events") or {}
        if not events:
            lines.append("_No mapped events for this pass._")
        for ev, info in sorted(events.items(), key=lambda kv: int(kv[0])):
            target = int(info.get("target", 0))
            text_hint = info.get("text", "")
            lines.extend(
                [
                    f"## Event {int(ev):02d}",
                    "",
                    f"- Target: `0x{target:04X}`",
                    f"- Text hint: {text_hint}",
                    "",
                    "```text",
                    f"event {int(ev):02d} {{",
                ]
            )
            for body_line in body_for_target(rows, target):
                lines.append("  " + body_line)
            lines.extend(["}", "```", ""])
        out.write_text("\n".join(lines), encoding="utf-8")

    (args.out_dir / "index.md").write_text("\n".join(index) + "\n", encoding="utf-8")
    print(f"wrote {len(atlas)} event pseudocode files to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
