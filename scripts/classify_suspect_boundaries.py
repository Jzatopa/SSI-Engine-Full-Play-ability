#!/usr/bin/env python3
"""Classify suspect ECL data/code boundaries by incoming reference type."""

from __future__ import annotations

import argparse
import re
from collections import Counter, defaultdict
from pathlib import Path


LINE_RE = re.compile(r"0x([0-9A-F]{4})\s+0x([0-9A-F]{2})\s+(.+)")
ENTRY_RE = re.compile(r"^([A-Za-z0-9_]+)\s+0x([0-9A-F]{4})$")
TARGET_RE = re.compile(r"0x([0-9A-F]{4})")


def command_name(rest: str) -> str:
    if "<suspect data/code boundary:" in rest:
        return rest.split("<", 1)[0].strip()
    return rest.split(" ", 1)[0]


def parse_listing(path: Path) -> tuple[list[tuple[str, int]], list[dict]]:
    entries = []
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        m_entry = ENTRY_RE.match(line)
        if m_entry:
            entries.append((m_entry.group(1), int(m_entry.group(2), 16)))
            continue
        m = LINE_RE.match(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        opcode = int(m.group(2), 16)
        rest = m.group(3)
        rows.append(
            {
                "addr": addr,
                "opcode": opcode,
                "rest": rest,
                "cmd": command_name(rest),
                "suspect": "<suspect data/code boundary:" in rest,
                "line": line,
            }
        )
    return entries, rows


def classify_block(path: Path) -> list[dict]:
    m_block = re.search(r"ecl1_(\d{3})\.ecl\.txt$", path.name)
    if not m_block:
        raise ValueError(f"unexpected listing filename: {path.name}")
    block_id = int(m_block.group(1))
    entries, rows = parse_listing(path)
    by_addr = {row["addr"]: row for row in rows}
    refs: dict[int, list[str]] = defaultdict(list)

    for label, target in entries:
        refs[target].append(f"entry:{label}")

    for row in rows:
        rest = row["rest"]
        if not any(tag in rest for tag in ("GOTO", "GOSUB")):
            continue
        for target_text in TARGET_RE.findall(rest):
            target = int(target_text, 16)
            refs[target].append(f"{row['cmd']}@0x{row['addr']:04X}")

    out = []
    for idx, row in enumerate(rows):
        if not row["suspect"]:
            continue
        prev = rows[idx - 1] if idx else None
        incoming = refs.get(row["addr"], [])
        if incoming:
            reach = "referenced"
        elif prev and prev["cmd"] in ("PRINT", "PRINTCLEAR"):
            reach = "fallthrough_after_print"
        elif prev:
            reach = f"fallthrough_after_{prev['cmd'].lower().replace(' ', '_')}"
        else:
            reach = "unknown"
        out.append(
            {
                "block_id": block_id,
                "addr": row["addr"],
                "opcode": row["opcode"],
                "cmd": row["cmd"],
                "reach": reach,
                "incoming": ", ".join(incoming),
                "previous": f"0x{prev['addr']:04X} {prev['cmd']}" if prev else "",
            }
        )
    return out


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("listings_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)

    rows = []
    for listing in sorted(args.listings_dir.glob("ecl1_*.ecl.txt")):
        rows.extend(classify_block(listing))

    tsv = args.out_dir / "suspect_boundaries.tsv"
    with tsv.open("w", encoding="utf-8") as f:
        f.write("block_id\taddr\topcode\tcmd\treach\tincoming\tprevious\n")
        for row in rows:
            f.write(
                "\t".join(
                    [
                        str(row["block_id"]),
                        f"0x{row['addr']:04X}",
                        f"0x{row['opcode']:02X}",
                        row["cmd"],
                        row["reach"],
                        row["incoming"],
                        row["previous"],
                    ]
                )
                + "\n"
            )

    by_reach = Counter(row["reach"] for row in rows)
    by_cmd = Counter(row["cmd"] for row in rows)
    by_block = Counter(row["block_id"] for row in rows)

    md = [
        "# Suspect ECL Boundary Classification",
        "",
        f"Total suspect boundaries: {len(rows)}",
        "",
        "## By Reach Type",
        "",
    ]
    md.extend(f"- {name}: {count}" for name, count in by_reach.most_common())
    md.extend(["", "## By Command Byte", ""])
    md.extend(f"- {name}: {count}" for name, count in by_cmd.most_common())
    md.extend(["", "## Busiest ECL Blocks", ""])
    md.extend(f"- ECL1 block {block_id}: {count}" for block_id, count in by_block.most_common(12))
    md.extend(["", f"Full table: `{tsv.name}`", ""])
    (args.out_dir / "summary.md").write_text("\n".join(md), encoding="utf-8")

    print(f"wrote {len(rows)} suspect boundary rows to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
