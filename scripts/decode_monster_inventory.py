#!/usr/bin/env python3
"""Extract structurally aligned ITEM0 payloads from MON0ITM records."""

from __future__ import annotations

import hashlib
import json
from pathlib import Path

try:
    from scripts.build_data_model_catalog import read_dax
except ModuleNotFoundError:
    from build_data_model_catalog import read_dax

try:
    from scripts.game_paths import default_game_dir
except ModuleNotFoundError:
    from game_paths import default_game_dir


ROOT = Path(__file__).resolve().parents[1]
GAME_DIR = default_game_dir()
OUT_DIR = ROOT / "generated" / "monster_inventory"
MONSTER_ITEM_RECORD_SIZE = 62
ITEM_PAYLOAD_OFFSET = 46
ITEM_TEMPLATE_SIZE = 16
EQUIPPED_FLAG_OFFSET = 6
QUANTITY_OFFSET = 10
MUTABLE_PAYLOAD_OFFSETS = {EQUIPPED_FLAG_OFFSET, QUANTITY_OFFSET}


def compare_payload(raw: bytes, templates: list[bytes]) -> dict[str, object]:
    distances = [sum(a != b for a, b in zip(raw, template)) for template in templates]
    minimum = min(distances)
    nearest = [index for index, distance in enumerate(distances) if distance == minimum]
    differences = []
    if len(nearest) == 1:
        template = templates[nearest[0]]
        differences = [
            {"payload_offset": offset, "template_value": template[offset], "saved_value": raw[offset]}
            for offset in range(ITEM_TEMPLATE_SIZE) if raw[offset] != template[offset]
        ]
    stable_matches = [
        index for index, template in enumerate(templates)
        if all(raw[offset] == template[offset] for offset in range(ITEM_TEMPLATE_SIZE)
               if offset not in MUTABLE_PAYLOAD_OFFSETS)
    ]
    return {
        "exact_template_index": nearest[0] if minimum == 0 and len(nearest) == 1 else None,
        "nearest_template_indices": nearest,
        "nearest_byte_difference_count": minimum,
        "unique_nearest_differences": differences,
        "stable_field_template_index": stable_matches[0] if len(stable_matches) == 1 else None,
        "stable_field_match_count": len(stable_matches),
        "equipped": bool(raw[EQUIPPED_FLAG_OFFSET] & 0x80),
        "quantity": raw[QUANTITY_OFFSET],
    }


def decode(game_dir: Path = GAME_DIR) -> dict[str, object]:
    item0_path = game_dir / "ITEM0.DAX"
    monitm_path = game_dir / "MON0ITM.DAX"
    item0_blocks = read_dax(item0_path)
    if len(item0_blocks) != 1 or len(item0_blocks[0]["data"]) % ITEM_TEMPLATE_SIZE:
        raise ValueError("ITEM0.DAX block layout is not the expected 16-byte template table")
    templates = [
        item0_blocks[0]["data"][offset : offset + ITEM_TEMPLATE_SIZE]
        for offset in range(0, len(item0_blocks[0]["data"]), ITEM_TEMPLATE_SIZE)
    ]
    template_lookup = {raw: index for index, raw in enumerate(templates)}
    blocks = []
    total_records = 0
    total_exact_matches = 0
    total_stable_matches = 0
    for block in read_dax(monitm_path):
        data = block["data"]
        if len(data) % MONSTER_ITEM_RECORD_SIZE:
            raise ValueError(
                f"MON0ITM block {block['id']} size {len(data)} is not divisible by "
                f"{MONSTER_ITEM_RECORD_SIZE}"
            )
        matches = []
        records = []
        for record_index, record_offset in enumerate(range(0, len(data), MONSTER_ITEM_RECORD_SIZE)):
            item_offset = record_offset + ITEM_PAYLOAD_OFFSET
            raw = data[item_offset : item_offset + ITEM_TEMPLATE_SIZE]
            template_index = template_lookup.get(raw)
            comparison = compare_payload(raw, templates)
            record = {
                "record_index": record_index,
                "record_offset": record_offset,
                "item_payload_offset": item_offset,
                "prefix_sha256": hashlib.sha256(data[record_offset:item_offset]).hexdigest(),
                "item_payload_hex": raw.hex(" "),
                "exact_template_index": template_index,
                "template_comparison": comparison,
            }
            records.append(record)
            if template_index is not None:
                matches.append(
                    {
                        "offset": item_offset,
                        "record_index": record_index,
                        "template_index": template_index,
                        "itemptr": raw[0],
                        "raw_hex": raw.hex(" "),
                    }
                )
        total_records += len(records)
        total_exact_matches += len(matches)
        total_stable_matches += sum(
            record["template_comparison"]["stable_field_template_index"] is not None
            for record in records
        )
        blocks.append(
            {
                "monster_id": block["id"],
                "decoded_size": len(data),
                "decoded_sha256": hashlib.sha256(data).hexdigest(),
                "record_count": len(records),
                "records": records,
                "exact_item0_matches": matches,
                "unresolved_record_count": len(records) - len(matches),
            }
        )
    saved_files = []
    for path in sorted((game_dir / "SAVE").glob("*.STF")):
        data = path.read_bytes()
        if len(data) % MONSTER_ITEM_RECORD_SIZE:
            raise ValueError(f"{path.name} size {len(data)} is not divisible by 62")
        records = []
        for index, offset in enumerate(range(0, len(data), MONSTER_ITEM_RECORD_SIZE)):
            payload = data[offset + ITEM_PAYLOAD_OFFSET : offset + MONSTER_ITEM_RECORD_SIZE]
            records.append({
                "record_index": index,
                "record_offset": offset,
                "prefix_hex": data[offset : offset + ITEM_PAYLOAD_OFFSET].hex(" "),
                "item_payload_hex": payload.hex(" "),
                "itemptr": payload[0],
                "template_comparison": compare_payload(payload, templates),
            })
        saved_files.append({
            "name": path.name,
            "size": len(data),
            "sha256": hashlib.sha256(data).hexdigest(),
            "record_count": len(records),
            "records": records,
        })
    saved_records = [record for saved in saved_files for record in saved["records"]]
    return {
        "schema": "matrix-cubed-monster-inventory-evidence-v4",
        "recovered_game_ovr_accessors": {
            "equipped_item_category_search": {
                "entry": "2000:3ea6", "file_offset": 147118,
                "observation": "requires record offset 0x34 bit 0x80 before accepting an item",
            },
            "stack_merge": {
                "entry": "2000:42f6", "file_offset": 148222,
                "observation": "merges matching record offset 0x38 values with a 100-unit cap",
            },
            "stack_consume": {
                "entry": "0000:309f", "file_offset": 12455,
                "observation": "decrements record offset 0x38 or removes the item record",
            },
        },
        "source_files": {
            "ITEM0.DAX": {
                "size": item0_path.stat().st_size,
                "sha256": hashlib.sha256(item0_path.read_bytes()).hexdigest(),
            },
            "MON0ITM.DAX": {
                "size": monitm_path.stat().st_size,
                "sha256": hashlib.sha256(monitm_path.read_bytes()).hexdigest(),
            },
        },
        "item0_template_count": len(templates),
        "mon0itm_block_count": len(blocks),
        "record_layout": {
            "record_size": MONSTER_ITEM_RECORD_SIZE,
            "unresolved_prefix_size": ITEM_PAYLOAD_OFFSET,
            "item_payload_offset": ITEM_PAYLOAD_OFFSET,
            "item_payload_size": ITEM_TEMPLATE_SIZE,
            "all_blocks_divisible": True,
        },
        "summary": {
            "record_count": total_records,
            "exact_item0_match_count": total_exact_matches,
            "blocks_with_exact_matches": sum(bool(block["exact_item0_matches"]) for block in blocks),
            "stable_field_item0_match_count": total_stable_matches,
            "newly_recovered_mutable_match_count": total_stable_matches - total_exact_matches,
            "saved_stf_file_count": len(saved_files),
            "saved_stf_record_count": len(saved_records),
            "saved_exact_item0_match_count": sum(
                record["template_comparison"]["exact_template_index"] is not None
                for record in saved_records
            ),
        },
        "blocks": blocks,
        "saved_stf_files": saved_files,
        "boundary": (
            "Every decoded MON0ITM block is divisible into 62-byte records. The trailing 16 bytes at record "
            "offset 46 have ITEM0-shaped values, and only byte-for-byte ITEM0 matches at that structural offset "
            "are promoted. The first 46 bytes and non-exact trailing payloads remain unresolved; absence of an "
            "exact match does not mean a monster has no inventory. Supplied STF saves use the same 62-byte "
            "record boundary and trailing payload position. Original GAME.OVR proves record offset 0x34 bit 0x80 "
            "as the equipped flag and record offset 0x38 as a stack quantity; these are payload offsets 6 and 10. "
            "A unique ITEM0 match across every other payload byte is therefore promoted, while records differing "
            "in any other byte remain unresolved."
        ),
    }


def main() -> None:
    report = decode()
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    (OUT_DIR / "monster_inventory_evidence.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    summary = report["summary"]
    layout = report["record_layout"]
    lines = [
        "# Monster Inventory Evidence",
        "",
        report["boundary"],
        "",
        f"- records: {summary['record_count']}",
        f"- exact aligned ITEM0 matches: {summary['exact_item0_match_count']}",
        f"- stable-field ITEM0 matches: {summary['stable_field_item0_match_count']} ({summary['newly_recovered_mutable_match_count']} newly recovered)",
        f"- saved STF records: {summary['saved_stf_record_count']} across {summary['saved_stf_file_count']} files",
        f"- saved STF exact ITEM0 matches: {summary['saved_exact_item0_match_count']}",
        f"- layout: {layout['record_size']} bytes = {layout['unresolved_prefix_size']}-byte unresolved prefix + {layout['item_payload_size']}-byte item payload",
        "",
        "| Monster | Size | Records | Stable-field ITEM0 matches |",
        "|---:|---:|---:|---|",
    ]
    for block in report["blocks"]:
        matches = ", ".join(
            f"record {record['record_index']}: template {record['template_comparison']['stable_field_template_index']}"
            f" / equipped {str(record['template_comparison']['equipped']).lower()}"
            f" / quantity {record['template_comparison']['quantity']}"
            for record in block["records"]
            if record["template_comparison"]["stable_field_template_index"] is not None
        ) or "none"
        lines.append(f"| {block['monster_id']} | {block['decoded_size']} | {block['record_count']} | {matches} |")
    (OUT_DIR / "monster_inventory_evidence.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {OUT_DIR / 'monster_inventory_evidence.json'}")


if __name__ == "__main__":
    main()
