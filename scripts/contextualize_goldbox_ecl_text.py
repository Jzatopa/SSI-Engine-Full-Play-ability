#!/usr/bin/env python3
"""Attach Gold Box whole-block ECL text hits to nearby decoded ECL rows.

The Gold Box Explorer text scan can find readable 0x80-packed strings that the
current path-following disassembler does not emit as operands. This script keeps
those hits as evidence only and records nearby decoded rows so future dialog and
menu work can decide whether a hit is inline text, menu data, table data, or a
false positive.
"""

from __future__ import annotations

import argparse
import csv
import json
import re
from bisect import bisect_right
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Iterable


DEFAULT_COMPARE_JSON = Path("generated") / "ecl_text_goldbox" / "ecl_text_compare.json"
DEFAULT_LISTING_DIR = Path("generated") / "ecl1_disasm"
DEFAULT_OUT_DIR = Path("generated") / "ecl_text_goldbox"

LISTING_ROW_RE = re.compile(r"^(?P<address>0x[0-9A-Fa-f]{4})\s+0x[0-9A-Fa-f]{2}\s+(?P<body>.+)$")


@dataclass(frozen=True)
class ListingRow:
    block_id: int
    address: int
    text: str


@dataclass(frozen=True)
class TextContext:
    block_id: int
    offset: int
    vm_address: int
    encoded_length: int
    text: str
    previous_address: int | None
    previous_distance: int | None
    previous_row: str | None
    next_address: int | None
    next_distance: int | None
    next_row: str | None
    context_kind: str


def block_id_from_listing_path(path: Path) -> int | None:
    match = re.search(r"ecl1_(\d+)\.ecl\.txt$", path.name)
    if not match:
        return None
    return int(match.group(1))


def parse_listing_rows(path: Path) -> list[ListingRow]:
    block_id = block_id_from_listing_path(path)
    if block_id is None:
        return []
    rows: list[ListingRow] = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = LISTING_ROW_RE.match(line)
        if not match:
            continue
        rows.append(
            ListingRow(
                block_id=block_id,
                address=int(match.group("address"), 16),
                text=line,
            )
        )
    return rows


def load_listing_rows(listing_dir: Path) -> dict[int, list[ListingRow]]:
    by_block: dict[int, list[ListingRow]] = {}
    if not listing_dir.exists():
        return by_block
    for path in sorted(listing_dir.glob("ecl1_*.ecl.txt")):
        for row in parse_listing_rows(path):
            by_block.setdefault(row.block_id, []).append(row)
    for rows in by_block.values():
        rows.sort(key=lambda row: row.address)
    return by_block


def load_substring_missing_hits(compare_json: Path) -> list[dict[str, object]]:
    data = json.loads(compare_json.read_text(encoding="utf-8"))
    comparison = data.get("comparison", {})
    hits = comparison.get("goldbox_substring_missing_hits", [])
    if not isinstance(hits, list):
        raise ValueError("comparison.goldbox_substring_missing_hits must be a list")
    return [hit for hit in hits if isinstance(hit, dict)]


def classify_context(text: str, previous_row: ListingRow | None, next_row: ListingRow | None) -> str:
    upper_text = text.strip().upper()
    neighbors = " ".join(row.text.upper() for row in (previous_row, next_row) if row is not None)
    if "MENU" in neighbors:
        return "near_menu_instruction"
    if upper_text.endswith(":"):
        return "label_fragment"
    if len(upper_text.split()) <= 3 and len(upper_text) <= 18:
        return "short_choice_or_label"
    if previous_row is None and next_row is None:
        return "no_decoded_listing_context"
    return "inline_text_fragment"


def context_for_hit(hit: dict[str, object], rows_by_block: dict[int, list[ListingRow]]) -> TextContext:
    block_id = int(hit["block_id"])
    offset = int(hit["offset"])
    vm_address = 0x8000 + offset
    rows = rows_by_block.get(block_id, [])
    addresses = [row.address for row in rows]
    index = bisect_right(addresses, vm_address)
    previous_row = rows[index - 1] if index > 0 else None
    next_row = rows[index] if index < len(rows) else None
    text = str(hit["text"])
    return TextContext(
        block_id=block_id,
        offset=offset,
        vm_address=vm_address,
        encoded_length=int(hit["encoded_length"]),
        text=text,
        previous_address=previous_row.address if previous_row else None,
        previous_distance=vm_address - previous_row.address if previous_row else None,
        previous_row=previous_row.text if previous_row else None,
        next_address=next_row.address if next_row else None,
        next_distance=next_row.address - vm_address if next_row else None,
        next_row=next_row.text if next_row else None,
        context_kind=classify_context(text, previous_row, next_row),
    )


def contextualize_hits(
    hits: Iterable[dict[str, object]],
    rows_by_block: dict[int, list[ListingRow]],
) -> list[TextContext]:
    contexts = [context_for_hit(hit, rows_by_block) for hit in hits]
    return sorted(contexts, key=lambda item: (item.block_id, item.offset, item.text))


def hex_or_blank(value: int | None) -> str:
    return "" if value is None else f"0x{value:04X}"


def write_outputs(contexts: list[TextContext], out_dir: Path) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    summary: dict[str, int] = {}
    for context in contexts:
        summary[context.context_kind] = summary.get(context.context_kind, 0) + 1

    json_payload = {
        "source": "Gold Box whole-block ECL texts still missing after substring comparison",
        "address_mapping": "vm_address = 0x8000 + decoded ECL block offset",
        "summary": {
            "context_count": len(contexts),
            "by_context_kind": dict(sorted(summary.items())),
        },
        "contexts": [asdict(context) for context in contexts],
    }
    (out_dir / "goldbox_ecl_text_context.json").write_text(json.dumps(json_payload, indent=2), encoding="utf-8")

    fieldnames = [
        "block_id",
        "offset",
        "vm_address",
        "encoded_length",
        "text",
        "context_kind",
        "previous_address",
        "previous_distance",
        "previous_row",
        "next_address",
        "next_distance",
        "next_row",
    ]
    with (out_dir / "goldbox_ecl_text_context.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames, delimiter="\t")
        writer.writeheader()
        for context in contexts:
            row = asdict(context)
            row["offset"] = hex_or_blank(context.offset)
            row["vm_address"] = hex_or_blank(context.vm_address)
            row["previous_address"] = hex_or_blank(context.previous_address)
            row["next_address"] = hex_or_blank(context.next_address)
            writer.writerow(row)

    lines = [
        "# Gold Box ECL Text Context",
        "",
        "This report attaches the Gold Box whole-block strings that are still missing",
        "after substring comparison to nearby decoded ECL rows. It is evidence for",
        "future dialog/menu reconstruction, not runtime text promotion.",
        "",
        "## Summary",
        "",
        f"- Context rows: {len(contexts)}",
        "- Address mapping: `vm_address = 0x8000 + decoded ECL block offset`",
    ]
    for kind, count in sorted(summary.items()):
        lines.append(f"- `{kind}`: {count}")
    lines.extend(
        [
            "",
            "## Context Rows",
            "",
            "| ECL | Offset | VM address | Kind | Text | Previous decoded row | Next decoded row |",
            "|---:|---:|---:|---|---|---|---|",
        ]
    )
    for context in contexts:
        text = context.text.replace("|", "\\|")
        previous = (context.previous_row or "").replace("|", "\\|")
        next_row = (context.next_row or "").replace("|", "\\|")
        lines.append(
            f"| {context.block_id} | {hex_or_blank(context.offset)} | {hex_or_blank(context.vm_address)} "
            f"| {context.context_kind} | {text} | {previous} | {next_row} |"
        )
    lines.append("")
    (out_dir / "goldbox_ecl_text_context.md").write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--compare-json", type=Path, default=DEFAULT_COMPARE_JSON)
    parser.add_argument("--listing-dir", type=Path, default=DEFAULT_LISTING_DIR)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    args = parser.parse_args()

    hits = load_substring_missing_hits(args.compare_json)
    rows_by_block = load_listing_rows(args.listing_dir)
    contexts = contextualize_hits(hits, rows_by_block)
    write_outputs(contexts, args.out_dir)
    print(
        "Gold Box ECL text context: "
        f"{len(contexts)} still-missing hits, "
        f"{len({context.block_id for context in contexts})} ECL blocks"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
