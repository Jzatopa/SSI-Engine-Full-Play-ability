#!/usr/bin/env python3
"""Decode Matrix Cubed item name codes from local original files.

Evidence chain:

* ITEM0.DAX records are 16 bytes. The first four bytes match the Gold Box /
  FRUA item-instance shape: item pointer, name code 3, name code 2, name code 1.
* START.EXE contains the item name word literals from "Knife" through
  "BLANK ITEM". Assigning those literals sequential codes resolves the ITEM0
  name-code triples into human-readable names.
* The separate ITEMS side file remains 39 fixed 9-byte records. It is not the
  name table. GAME.OVR code indexes it as a 1-based detail table with
  `itemptr * 9`.
"""

from __future__ import annotations

import argparse
import csv
import json
import sys
from collections import Counter
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()
START_NAME_FIRST = "Knife"
START_NAME_LAST = "BLANK ITEM"


def printable(byte: int) -> bool:
    return byte == 9 or 32 <= byte < 127


def ascii_runs(data: bytes, min_len: int = 4) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    start: int | None = None
    for idx, byte in enumerate(data + b"\x00"):
        if printable(byte):
            if start is None:
                start = idx
            continue
        if start is not None and idx - start >= min_len:
            raw = data[start:idx]
            rows.append({"offset": start, "length": len(raw), "text": raw.decode("ascii", errors="replace")})
        start = None
    return rows


def pascal_strings(data: bytes, min_len: int = 4, max_len: int = 80) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for off, size in enumerate(data):
        if not (min_len <= size <= max_len):
            continue
        end = off + 1 + size
        if end > len(data):
            continue
        raw = data[off + 1 : end]
        if raw and all(printable(byte) for byte in raw):
            text = raw.decode("ascii", errors="replace")
            if sum(ch.isalpha() for ch in text) >= 3:
                rows.append({"offset": off, "length": size, "text": text})
    return rows


def load_item_templates(path: Path) -> list[dict[str, Any]]:
    return json.loads(path.read_text(encoding="utf-8"))


def decode_items_records(path: Path) -> list[dict[str, Any]]:
    data = path.read_bytes()
    if len(data) % 9 != 0:
        raise ValueError(f"ITEMS size must be a multiple of 9 bytes, got {len(data)}")

    rows: list[dict[str, Any]] = []
    for index, offset in enumerate(range(0, len(data), 9)):
        raw = data[offset : offset + 9]
        rows.append(
            {
                "index": index,
                "offset": offset,
                "raw_hex": raw.hex(" "),
                "bytes": list(raw),
                "u16_0": int.from_bytes(raw[0:2], "little"),
                "u16_1": int.from_bytes(raw[2:4], "little"),
                "u16_2": int.from_bytes(raw[4:6], "little"),
                "u16_3": int.from_bytes(raw[6:8], "little"),
                "byte_8": raw[8],
                "fields": decode_items_detail_fields(raw),
            }
        )
    return rows


def sbyte(value: int) -> int:
    return value - 256 if value > 127 else value


def decode_items_detail_fields(raw: bytes) -> dict[str, Any]:
    """Decode stable and candidate fields from one 9-byte ITEMS detail record.

    The table is proven to be indexed by ITEM0 itemptr. The exact semantics are
    still being reconstructed, so damage/range-like names stay marked as
    candidates. Byte group patterns match known weapon rows and the overlay
    reads bytes 0, 2, 3, 4, 5, and 6 by itemptr.
    """
    if len(raw) != 9:
        raise ValueError(f"ITEMS detail record must be 9 bytes, got {len(raw)}")
    return {
        "type_code": raw[0],
        "large_damage_candidate": {"dice": raw[0], "sides": raw[1], "bonus": sbyte(raw[2])},
        "medium_damage_candidate": {"dice": raw[4], "sides": raw[5], "bonus": sbyte(raw[3])},
        "effect_or_bonus_candidate": raw[6],
        "range_candidate": raw[7],
        "flags_candidate": raw[8],
        "raw_bytes": list(raw),
    }


def extract_start_item_name_parts(path: Path) -> list[dict[str, Any]]:
    data = path.read_bytes()
    first = data.index(bytes([len(START_NAME_FIRST)]) + START_NAME_FIRST.encode("ascii"))
    last = data.index(bytes([len(START_NAME_LAST)]) + START_NAME_LAST.encode("ascii"), first)

    rows: list[dict[str, Any]] = [{"code": 0, "offset": None, "length": 0, "text": ""}]
    for candidate in pascal_strings(data[first : last + 1 + len(START_NAME_LAST)], min_len=3, max_len=24):
        text = candidate["text"]
        # Exclude the directional literals immediately after the item table.
        if text in {"N", "NE", "E", "SE", "S", "SW", "W", "NW"}:
            continue
        rows.append(
            {
                "code": len(rows),
                "offset": first + candidate["offset"],
                "length": candidate["length"],
                "text": text,
            }
        )
    if rows[-1]["text"] != START_NAME_LAST:
        raise ValueError("START.EXE item-name extraction did not end at BLANK ITEM")
    return rows


def decode_item0_name_records(
    templates: list[dict[str, Any]],
    name_parts: list[dict[str, Any]],
    detail_records: list[dict[str, Any]] | None = None,
) -> list[dict[str, Any]]:
    names = {int(row["code"]): str(row["text"]) for row in name_parts}
    max_code = max(names)
    details = {int(row["index"]): row for row in detail_records or []}
    rows: list[dict[str, Any]] = []
    for template in templates:
        raw = bytes.fromhex(template["raw_hex"])
        if len(raw) != 16:
            raise ValueError(f"ITEM0 template {template['index']} raw_hex does not decode to 16 bytes")
        name_codes = [raw[3], raw[2], raw[1]]
        unknown_codes = [code for code in name_codes if code > max_code]
        parts = [names.get(code, f"<unknown:{code}>") for code in name_codes]
        name = " ".join(part for part in parts if part).strip()
        itemptr = raw[0]
        detail = details.get(itemptr)
        rows.append(
            {
                "index": template["index"],
                "itemptr": itemptr,
                "name_codes": name_codes,
                "name_parts": parts,
                "name": name if name else f"Item {template['index']}",
                "unmapped_name_codes": unknown_codes,
                "items_detail_record": detail,
                "raw_hex": template["raw_hex"],
                "name_evidence": "ITEM0 bytes [3,2,1] resolved through START.EXE item-name literal table",
                "detail_evidence": (
                    "ITEMS is indexed 1-based by ITEM0 itemptr in GAME.OVR. Runtime references include "
                    "0x5370+itemptr*9, 0x5372+itemptr*9, 0x5373+itemptr*9, 0x5374+itemptr*9, "
                    "0x5375+itemptr*9, and 0x5376+itemptr*9."
                    if detail is not None
                    else "No ITEMS detail record exists for this ITEM0 itemptr."
                ),
            }
        )
    return rows


def item_index_like_fields(records: list[dict[str, Any]], item_count: int) -> list[dict[str, Any]]:
    candidates: list[dict[str, Any]] = []
    for record in records:
        for field in ("u16_0", "u16_1", "u16_2", "u16_3", "byte_8"):
            value = int(record[field])
            if 0 <= value < item_count:
                candidates.append(
                    {
                        "record_index": record["index"],
                        "field": field,
                        "value": value,
                        "raw_hex": record["raw_hex"],
                    }
                )
    return candidates


def summarize_numeric_fields(records: list[dict[str, Any]]) -> dict[str, Any]:
    summary: dict[str, Any] = {}
    for field in ("u16_0", "u16_1", "u16_2", "u16_3", "byte_8"):
        values = [int(row[field]) for row in records]
        summary[field] = {
            "unique_count": len(set(values)),
            "min": min(values) if values else None,
            "max": max(values) if values else None,
            "zero_count": values.count(0),
            "top_values": [
                {"value": value, "count": count}
                for value, count in Counter(values).most_common(8)
            ],
        }
    return summary


def compare_record_counts(item_count: int, item_side_count: int) -> dict[str, Any]:
    return {
        "item0_template_count": item_count,
        "items_record_count": item_side_count,
        "one_record_per_item_possible": item_count == item_side_count,
        "verdict": (
            "ITEMS cannot be a direct one-record-per-ITEM0-name table in the current local files."
            if item_count != item_side_count
            else "ITEMS record count matches ITEM0 template count; further field validation required."
        ),
    }


def build_report(items_path: Path, item_templates_path: Path, start_exe_path: Path | None = None) -> dict[str, Any]:
    start_exe_path = start_exe_path or items_path.with_name("START.EXE")
    items_bytes = items_path.read_bytes()
    templates = load_item_templates(item_templates_path)
    records = decode_items_records(items_path)
    ascii_rows = ascii_runs(items_bytes)
    pascal_rows = pascal_strings(items_bytes)
    index_like = item_index_like_fields(records, len(templates))
    name_parts = extract_start_item_name_parts(start_exe_path)
    item_names = decode_item0_name_records(templates, name_parts, records)
    unmapped = [row for row in item_names if row["unmapped_name_codes"]]
    missing_details = [row for row in item_names if row["items_detail_record"] is None]

    return {
        "inputs": {
            "items_path": str(items_path),
            "items_bytes": len(items_bytes),
            "item_templates_path": str(item_templates_path),
            "item0_template_count": len(templates),
            "start_exe_path": str(start_exe_path),
        },
        "evidence_chain": [
            "Gold Box / FRUA item records store item pointer, name code 3, name code 2, name code 1 in the first four bytes.",
            "Local ITEM0.DAX records have the same 16-byte shape and use nonzero values in bytes 1..3 as name-code triples.",
            "Local START.EXE contains a contiguous Pascal-style item-name literal table from Knife through BLANK ITEM.",
            "GAME.OVR indexes the local ITEMS side file with itemptr * 9 and reads detail bytes from 0x5370, 0x5372, 0x5373, 0x5374, 0x5375, and 0x5376 plus that product.",
        ],
        "record_count_check": compare_record_counts(len(templates), len(records)),
        "items_text_check": {
            "ascii_string_count": len(ascii_rows),
            "pascal_candidate_count": len(pascal_rows),
            "ascii_strings": ascii_rows,
            "pascal_candidates": pascal_rows,
            "verdict": "ITEMS contains no printable strings long enough to be item names.",
        },
        "start_exe_item_name_parts": {
            "count_including_blank_code": len(name_parts),
            "max_code": max(int(row["code"]) for row in name_parts),
            "rows": name_parts,
        },
        "item0_name_records": item_names,
        "item0_name_summary": {
            "named_count": len(item_names) - sum(1 for row in item_names if row["name"].startswith("Item ")),
            "unmapped_code_record_count": len(unmapped),
            "missing_items_detail_record_count": len(missing_details),
            "unique_itemptr_count": len({row["itemptr"] for row in item_names}),
            "max_itemptr": max(row["itemptr"] for row in item_names) if item_names else None,
        },
        "items_detail_layout": {
            "record_size": 9,
            "alignment": "1-based by ITEM0 itemptr; file record N is used by ITEM0 itemptr N",
            "field_status": "partly semantic, partly candidate",
            "proven_overlay_uses": [
                {"table_offset": "0x5370 + itemptr*9", "record_byte": 0, "use": "type/category checks against values including 1, 7, 8, and 9"},
                {"table_offset": "0x5372 + itemptr*9", "record_byte": 2, "use": "copied to runtime character/item field 0xdd and shown in item debug view"},
                {"table_offset": "0x5373 + itemptr*9", "record_byte": 3, "use": "copied to runtime character/item field 0xdf and shown in item debug view"},
                {"table_offset": "0x5374 + itemptr*9", "record_byte": 4, "use": "copied to runtime character/item field 0xe1 and shown in item debug view"},
                {"table_offset": "0x5375 + itemptr*9", "record_byte": 5, "use": "used by item/combat checks; zero and 0xff are normalized to 1 in one routine"},
                {"table_offset": "0x5376 + itemptr*9", "record_byte": 6, "use": "tested before dispatching a runtime item effect routine"},
            ],
            "candidate_fields": {
                "type_code": "record byte 0",
                "large_damage_candidate": "record bytes 0,1,2 as dice/sides/bonus candidate; byte 0 also has non-damage type-code uses",
                "medium_damage_candidate": "record bytes 4,5,3 as dice/sides/bonus candidate; matches weapon rows such as Knife 1d3 and Laser Pistol 1d8",
                "effect_or_bonus_candidate": "record byte 6",
                "range_candidate": "record byte 7",
                "flags_candidate": "record byte 8",
            },
        },
        "numeric_field_profile": summarize_numeric_fields(records),
        "item_index_like_fields": {
            "count": len(index_like),
            "rows": index_like,
            "verdict": (
                "Some fields are in the ITEM0 index range, but this is weak evidence because zeros and small numeric fields are common in 9-byte binary records."
                if index_like
                else "No field values fall in the ITEM0 index range."
            ),
        },
        "items_records": records,
        "overall_verdict": (
            "Item names are decoded, and the ITEMS side-file blocker is narrowed: the table is now aligned as a 1-based itemptr detail table. "
            "Some detail semantics remain candidates, but non-name item fields no longer need to be treated as unaligned or untraceable."
        ),
    }


def write_tsv(path: Path, rows: list[dict[str, Any]], fields: list[str]) -> None:
    with path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fields, delimiter="\t", extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def flatten_items_detail_rows(rows: list[dict[str, Any]]) -> list[dict[str, Any]]:
    flat: list[dict[str, Any]] = []
    for row in rows:
        fields = row["fields"]
        large = fields["large_damage_candidate"]
        medium = fields["medium_damage_candidate"]
        flat.append(
            {
                "index": row["index"],
                "offset": row["offset"],
                "raw_hex": row["raw_hex"],
                "type_code": fields["type_code"],
                "large_dice_candidate": large["dice"],
                "large_sides_candidate": large["sides"],
                "large_bonus_candidate": large["bonus"],
                "medium_dice_candidate": medium["dice"],
                "medium_sides_candidate": medium["sides"],
                "medium_bonus_candidate": medium["bonus"],
                "effect_or_bonus_candidate": fields["effect_or_bonus_candidate"],
                "range_candidate": fields["range_candidate"],
                "flags_candidate": fields["flags_candidate"],
            }
        )
    return flat


def write_markdown(path: Path, report: dict[str, Any]) -> None:
    count = report["record_count_check"]
    text_check = report["items_text_check"]
    name_summary = report["item0_name_summary"]
    profile = report["numeric_field_profile"]
    lines = [
        "# ITEM Name Mapping Evidence",
        "",
        "This report records the local evidence used to resolve ITEM0 name-code triples into item names.",
        "",
        "## Inputs",
        "",
        f"- ITEMS: `{report['inputs']['items_path']}`",
        f"- ITEMS bytes: `{report['inputs']['items_bytes']}`",
        f"- ITEM0 templates: `{report['inputs']['item_templates_path']}`",
        f"- ITEM0 template count: `{count['item0_template_count']}`",
        f"- START.EXE: `{report['inputs']['start_exe_path']}`",
        "",
        "## Result",
        "",
        f"- START.EXE item-name codes including blank code 0: `{report['start_exe_item_name_parts']['count_including_blank_code']}`",
        f"- ITEM0 records with decoded names: `{name_summary['named_count']}`",
        f"- ITEM0 records with unmapped name codes: `{name_summary['unmapped_code_record_count']}`",
        f"- ITEM0 records missing ITEMS detail rows: `{name_summary['missing_items_detail_record_count']}`",
        f"- Unique ITEM0 item pointers: `{name_summary['unique_itemptr_count']}`",
        "",
        report["overall_verdict"],
        "",
        "## Evidence Chain",
        "",
    ]
    lines.extend(f"- {line}" for line in report["evidence_chain"])
    lines.extend(
        [
            "",
            "## First Decoded ITEM0 Names",
            "",
            "| index | itemptr | name codes | decoded name | raw bytes |",
            "|---:|---:|---|---|---|",
        ]
    )
    for row in report["item0_name_records"][:40]:
        lines.append(
            f"| {row['index']} | {row['itemptr']} | `{row['name_codes']}` | {row['name']} | `{row['raw_hex']}` |"
        )
    lines.extend(
        [
            "",
            "## ITEMS Side File Check",
            "",
            f"- One ITEMS record per ITEM0 template possible: `{count['one_record_per_item_possible']}`",
            f"- ITEMS ASCII strings: `{text_check['ascii_string_count']}`",
            f"- ITEMS Pascal-style string candidates: `{text_check['pascal_candidate_count']}`",
            "",
            "ITEMS is still not a direct text/name table.",
            "",
            "## ITEMS Detail Layout",
            "",
            f"- Record size: `{report['items_detail_layout']['record_size']}` bytes",
            f"- Alignment: {report['items_detail_layout']['alignment']}",
            f"- Field status: {report['items_detail_layout']['field_status']}",
            "",
            "### Proven Overlay Uses",
            "",
        ]
    )
    for row in report["items_detail_layout"]["proven_overlay_uses"]:
        lines.append(f"- `{row['table_offset']}` / byte `{row['record_byte']}`: {row['use']}")
    lines.extend(
        [
            "",
            "### Candidate Field Names",
            "",
        ]
    )
    for field, note in report["items_detail_layout"]["candidate_fields"].items():
        lines.append(f"- `{field}`: {note}")
    lines.extend(
        [
            "",
            "## ITEMS Numeric Field Profile",
            "",
        ]
    )
    for field, row in profile.items():
        top = ", ".join(f"{value['value']} ({value['count']})" for value in row["top_values"])
        lines.append(
            f"- `{field}`: unique `{row['unique_count']}`, range `{row['min']}`-`{row['max']}`, zeros `{row['zero_count']}`, top `{top}`"
        )
    lines.extend(
        [
            "",
            "## Remaining Caveat",
            "",
            "The table alignment and several byte uses are now traced. Damage/range-like names remain candidate labels until a combat validation capture verifies original displayed damage/range values.",
            "",
        ]
    )
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--item-templates", type=Path, default=Path("generated") / "data_model" / "item0_templates.json")
    parser.add_argument("--out-dir", type=Path, default=Path("generated") / "game_ovr")
    args = parser.parse_args()

    report = build_report(args.game_dir / "ITEMS", args.item_templates, args.game_dir / "START.EXE")
    args.out_dir.mkdir(parents=True, exist_ok=True)
    json_path = args.out_dir / "item_name_mapping.json"
    md_path = args.out_dir / "item_name_mapping.md"
    tsv_path = args.out_dir / "item_name_mapping_records.tsv"
    names_tsv_path = args.out_dir / "item0_names.tsv"
    details_tsv_path = args.out_dir / "items_detail_records.tsv"
    json_path.write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(md_path, report)
    write_tsv(
        tsv_path,
        report["items_records"],
        ["index", "offset", "raw_hex", "u16_0", "u16_1", "u16_2", "u16_3", "byte_8"],
    )
    write_tsv(
        names_tsv_path,
        report["item0_name_records"],
        ["index", "itemptr", "name_codes", "name", "name_parts", "unmapped_name_codes", "raw_hex", "name_evidence"],
    )
    write_tsv(
        details_tsv_path,
        flatten_items_detail_rows(report["items_records"]),
        [
            "index",
            "offset",
            "raw_hex",
            "type_code",
            "large_dice_candidate",
            "large_sides_candidate",
            "large_bonus_candidate",
            "medium_dice_candidate",
            "medium_sides_candidate",
            "medium_bonus_candidate",
            "effect_or_bonus_candidate",
            "range_candidate",
            "flags_candidate",
        ],
    )
    print(f"wrote {json_path}, {md_path}, {tsv_path}, {names_tsv_path}, and {details_tsv_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
