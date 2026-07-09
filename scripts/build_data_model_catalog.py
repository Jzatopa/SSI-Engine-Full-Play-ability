#!/usr/bin/env python3
from __future__ import annotations

import json
from collections import Counter
from pathlib import Path

try:
    from scripts.game_paths import default_game_dir
except ModuleNotFoundError:
    from game_paths import default_game_dir


GAME_DIR = default_game_dir()
OUT = Path("generated/data_model")


def sbyte(value: int) -> int:
    return value - 256 if value >= 128 else value


def dax_decompress(raw_size: int, compressed: bytes) -> bytes:
    out = bytearray(raw_size)
    inp = 0
    outp = 0
    while inp < len(compressed) and outp < raw_size:
        run = sbyte(compressed[inp])
        if run >= 0:
            n = run + 1
            chunk = compressed[inp + 1 : inp + 1 + n]
            out[outp : outp + len(chunk)] = chunk
            inp += run + 2
            outp += len(chunk)
        else:
            n = -run
            if inp + 1 >= len(compressed):
                break
            end = min(outp + n, raw_size)
            out[outp:end] = bytes([compressed[inp + 1]]) * (end - outp)
            inp += 2
            outp = end
    return bytes(out)


def read_dax(path: Path) -> list[dict]:
    data = path.read_bytes()
    toc_len = int.from_bytes(data[:2], "little")
    data_offset = toc_len + 2
    rows = []
    for off in range(2, data_offset, 9):
        if off + 9 > len(data):
            break
        block_id = data[off]
        rel = int.from_bytes(data[off + 1 : off + 5], "little")
        raw_size = int.from_bytes(data[off + 5 : off + 7], "little")
        packed_size = int.from_bytes(data[off + 7 : off + 9], "little")
        packed = data[data_offset + rel : data_offset + rel + packed_size]
        block = packed if raw_size <= 0 else dax_decompress(raw_size, packed)
        rows.append(
            {
                "file": path.name,
                "id": block_id,
                "offset": rel,
                "raw_size": raw_size,
                "packed_size": packed_size,
                "data": block,
            }
        )
    return rows


def u16(data: bytes, off: int) -> int:
    if off + 2 > len(data):
        return 0
    return data[off] | (data[off + 1] << 8)


def u32(data: bytes, off: int) -> int:
    if off + 4 > len(data):
        return 0
    return data[off] | (data[off + 1] << 8) | (data[off + 2] << 16) | (data[off + 3] << 24)


def pascal_string(data: bytes, off: int, field_len: int) -> str:
    if off >= len(data):
        return ""
    declared = data[off - 1] if off > 0 else 0
    n = min(declared if declared else field_len, field_len, len(data) - off)
    raw = data[off : off + n].split(b"\x00", 1)[0]
    return raw.decode("ascii", errors="replace").strip()


def hex_head(data: bytes, n: int = 32) -> str:
    return data[:n].hex(" ")


def ascii_head(data: bytes, n: int = 64) -> str:
    return "".join(chr(b) if 32 <= b < 127 else "." for b in data[:n])


def decode_monster_record(block: dict) -> dict:
    data = block["data"]
    return {
        "id": block["id"],
        "name": pascal_string(data, 1, 15),
        "record_size": len(data),
        "stats": {
            "strength": data[0x10],
            "intelligence": data[0x11],
            "wisdom": data[0x12],
            "dexterity": data[0x13],
            "constitution": data[0x14],
            "charisma": data[0x15],
            "extraordinary_strength": data[0x16],
        },
        "goldbox_legacy_offsets": {
            "thac0_raw": data[0x2D],
            "max_hp": data[0x32],
            "movement": data[0x72] if len(data) > 0x72 else 0,
            "hit_dice": data[0x73] if len(data) > 0x73 else 0,
            "armor_class_raw": data[0xA9] if len(data) > 0xA9 else 0,
            "primary_attacks_x2": data[0xA1] if len(data) > 0xA1 else 0,
            "secondary_attacks_x2": data[0xA2] if len(data) > 0xA2 else 0,
            "primary_damage": {
                "dice": data[0xA3] if len(data) > 0xA3 else 0,
                "sides": data[0xA5] if len(data) > 0xA5 else 0,
                "bonus": sbyte(data[0xA7]) if len(data) > 0xA7 else 0,
            },
            "secondary_damage": {
                "dice": data[0xA4] if len(data) > 0xA4 else 0,
                "sides": data[0xA6] if len(data) > 0xA6 else 0,
                "bonus": sbyte(data[0xA8]) if len(data) > 0xA8 else 0,
            },
        },
        "matrix_variant_candidates": {
            "offset_0x29": data[0x29],
            "offset_0x33": data[0x33],
            "offset_0x36": data[0x36],
            "offset_0x37": data[0x37],
            "offset_0x45": data[0x45],
            "offset_0x6B": data[0x6B],
            "offset_0x8A": data[0x8A],
            "offset_0x8F": data[0x8F],
            "offset_0xB2": data[0xB2],
            "offset_0xE3": data[0xE3],
        },
        "identity": {
            "race": data[0x2E],
            "class": data[0x2F],
            "age": u16(data, 0x30),
            "gender": data[0x9E] if len(data) > 0x9E else 0,
            "monster_type": data[0x9F] if len(data) > 0x9F else 0,
            "alignment": data[0xA0] if len(data) > 0xA0 else 0,
            "size": data[0x6C] if len(data) > 0x6C else 0,
        },
        "rewards": {
            "goldbox_legacy_experience": u32(data, 0xAC) if len(data) > 0xAF else 0,
            "base_xp_for_defeating": u16(data, 0xB8) if len(data) > 0xB9 else 0,
            "bonus_xp_per_hp": data[0xBA] if len(data) > 0xBA else 0,
        },
        "visuals": {
            "head_portrait": data[0xBB] if len(data) > 0xBB else 0,
            "body_portrait": data[0xBC] if len(data) > 0xBC else 0,
            "head_icon": data[0xBD] if len(data) > 0xBD else 0,
            "weapon_icon": data[0xBE] if len(data) > 0xBE else 0,
            "icon_size": data[0xC0] if len(data) > 0xC0 else 0,
            "colors": {
                "body": data[0xC1] if len(data) > 0xC1 else 0,
                "arm": data[0xC2] if len(data) > 0xC2 else 0,
                "leg": data[0xC3] if len(data) > 0xC3 else 0,
                "head": data[0xC4] if len(data) > 0xC4 else 0,
                "shield": data[0xC5] if len(data) > 0xC5 else 0,
                "weapon": data[0xC6] if len(data) > 0xC6 else 0,
            },
        },
        "raw_head_hex": hex_head(data),
    }


def decode_effect_records(block: dict) -> list[dict]:
    data = block["data"]
    rows = []
    for i in range(0, len(data), 9):
        rec = data[i : i + 9]
        if len(rec) != 9:
            continue
        rows.append(
            {
                "block_id": block["id"],
                "record_index": i // 9,
                "effect_code": rec[0],
                "duration": u16(rec, 1),
                "effect_data": rec[3],
                "effect_table_flag": rec[4],
                "next_effect_ptr": rec[5] | (rec[6] << 8) | (rec[7] << 16) | (rec[8] << 24),
                "raw_hex": rec.hex(" "),
            }
        )
    return rows


def decode_item_templates(block: dict) -> list[dict]:
    data = block["data"]
    rows = []
    for i in range(0, len(data), 16):
        rec = data[i : i + 16]
        if len(rec) != 16:
            continue
        rows.append(
            {
                "index": i // 16,
                "location": rec[0],
                "hands": rec[1],
                "damage_large": {"dice": rec[2], "sides": rec[3], "bonus": sbyte(rec[4])},
                "rate": rec[5],
                "protection": rec[6],
                "damage_type": rec[7],
                "melee_flag": rec[8],
                "damage_medium": {"dice": rec[9], "sides": rec[10], "bonus": sbyte(rec[11])},
                "range": rec[12],
                "class_restrictions": rec[13],
                "ammo_type": rec[14],
                "unknown": rec[15],
                "raw_hex": rec.hex(" "),
            }
        )
    return rows


def block_catalog(files: list[str]) -> list[dict]:
    rows = []
    for fn in files:
        for block in read_dax(GAME_DIR / fn):
            data = block["data"]
            rows.append(
                {
                    "file": fn,
                    "id": block["id"],
                    "raw_size": block["raw_size"],
                    "packed_size": block["packed_size"],
                    "compression_ratio": round(block["packed_size"] / block["raw_size"], 4) if block["raw_size"] else 0,
                    "record_size_candidate": infer_record_size(fn, len(data)),
                    "ascii_head": ascii_head(data),
                    "hex_head": hex_head(data),
                }
            )
    return rows


def infer_record_size(filename: str, size: int) -> int | None:
    if filename == "MON0CHA.DAX" and size == 259:
        return 259
    if filename == "MON0SPC.DAX" and size % 9 == 0:
        return 9
    if filename == "ITEM0.DAX" and size % 16 == 0:
        return 16
    if filename == "MON0ITM.DAX" and size % 62 == 0:
        return 62
    return None


def write_tsv(path: Path, rows: list[dict], columns: list[str]) -> None:
    with path.open("w", encoding="utf-8") as f:
        f.write("\t".join(columns) + "\n")
        for row in rows:
            vals = []
            for col in columns:
                value = row
                for part in col.split("."):
                    value = value.get(part, "") if isinstance(value, dict) else ""
                vals.append(str(value).replace("\t", " ").replace("\n", " "))
            f.write("\t".join(vals) + "\n")


def render_markdown(catalog: list[dict], monsters: list[dict], item_templates: list[dict], effects: list[dict]) -> str:
    lines = [
        "# Matrix Cubed Data Model Catalog",
        "",
        "This is a source-data pass over non-map, non-image model files. It favors conservative structure over overconfident names.",
        "",
        "## File Summary",
        "",
        "| File | Blocks | Raw sizes | Record-size hints |",
        "| --- | ---: | --- | --- |",
    ]
    by_file: dict[str, list[dict]] = {}
    for row in catalog:
        by_file.setdefault(row["file"], []).append(row)
    for fn, rows in sorted(by_file.items()):
        raw_sizes = ", ".join(f"{size}x{count}" for size, count in sorted(Counter(r["raw_size"] for r in rows).items()))
        hints = ", ".join(str(v) for v in sorted({r["record_size_candidate"] for r in rows if r["record_size_candidate"]}))
        lines.append(f"| `{fn}` | {len(rows)} | {raw_sizes} | {hints or '-'} |")

    lines.extend(
        [
            "",
            "## Monster / Character Records",
            "",
            "`MON0CHA.DAX` decodes as 63 fixed 259-byte records. Names and base stats line up with the Gold Box character/monster record family, but later combat fields are a Matrix Cubed variant and are not yet fully named.",
            "",
            "| ID | Name | STR | INT | DEX | Candidate 0x45 | Candidate 0xE3 | Visuals |",
            "| ---: | --- | ---: | ---: | ---: | ---: | ---: | --- |",
        ]
    )
    for mon in monsters:
        visuals = f"H{mon['visuals']['head_portrait']} B{mon['visuals']['body_portrait']} I{mon['visuals']['head_icon']}"
        lines.append(
            f"| {mon['id']} | {mon['name']} | {mon['stats']['strength']} | {mon['stats']['intelligence']} | {mon['stats']['dexterity']} | {mon['matrix_variant_candidates']['offset_0x45']} | {mon['matrix_variant_candidates']['offset_0xE3']} | {visuals} |"
        )

    lines.extend(
        [
            "",
            "## Item Templates",
            "",
            "`ITEM0.DAX` block 1 is 1456 bytes, exactly 91 records of 16 bytes. The byte layout matches the Gold Box item-template shape closely enough to decode combat and equipment properties.",
            "",
            f"- decoded template records: {len(item_templates)}",
            "",
            "## Effects",
            "",
            "`MON0SPC.DAX` block sizes are multiples of 9 bytes and match the Gold Box effect-record shape.",
            "",
            f"- decoded effect records: {len(effects)}",
            "",
            "## Open Questions",
            "",
            "- Confirm Matrix Cubed's MON0CHA combat field layout. Old Gold Box offsets for HP/AC/XP do not directly line up; offsets `0x45` and `0xE3` vary identically and look like high-value encounter/combat fields.",
            "- `MON0ITM.DAX` has 62-byte structural records. A dedicated decoder proves that their trailing 16 bytes begin at record offset 46 and sometimes exactly match ITEM0 templates; the first 46 bytes, non-exact payloads, and equipped state remain unresolved.",
            "- `SHIPS.DAX` mixes large art-like blocks and smaller data/code-like blocks; it needs a dedicated ship-system pass.",
            "- Saved party records are not present in the extracted base directory; they will need live save files or installer/runtime-created save files.",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> None:
    OUT.mkdir(parents=True, exist_ok=True)
    files = ["ITEM0.DAX", "MON0CHA.DAX", "MON0ITM.DAX", "MON0SPC.DAX", "SHIPS.DAX"]
    catalog = block_catalog(files)
    monsters = [decode_monster_record(block) for block in read_dax(GAME_DIR / "MON0CHA.DAX")]
    item_templates = decode_item_templates(read_dax(GAME_DIR / "ITEM0.DAX")[0])
    effects = [row for block in read_dax(GAME_DIR / "MON0SPC.DAX") for row in decode_effect_records(block)]

    (OUT / "data_block_catalog.json").write_text(json.dumps(catalog, indent=2) + "\n", encoding="utf-8")
    (OUT / "mon0cha_monsters.json").write_text(json.dumps(monsters, indent=2) + "\n", encoding="utf-8")
    (OUT / "item0_templates.json").write_text(json.dumps(item_templates, indent=2) + "\n", encoding="utf-8")
    (OUT / "mon0spc_effects.json").write_text(json.dumps(effects, indent=2) + "\n", encoding="utf-8")
    (OUT / "data_model_catalog.md").write_text(render_markdown(catalog, monsters, item_templates, effects), encoding="utf-8")

    write_tsv(
        OUT / "mon0cha_monsters.tsv",
        monsters,
        [
            "id",
            "name",
            "stats.strength",
            "stats.intelligence",
            "stats.wisdom",
            "stats.dexterity",
            "stats.constitution",
            "stats.charisma",
            "matrix_variant_candidates.offset_0x29",
            "matrix_variant_candidates.offset_0x33",
            "matrix_variant_candidates.offset_0x36",
            "matrix_variant_candidates.offset_0x37",
            "matrix_variant_candidates.offset_0x45",
            "matrix_variant_candidates.offset_0xE3",
            "visuals.head_portrait",
            "visuals.body_portrait",
            "visuals.head_icon",
            "visuals.weapon_icon",
        ],
    )
    write_tsv(
        OUT / "item0_templates.tsv",
        item_templates,
        [
            "index",
            "location",
            "hands",
            "damage_large.dice",
            "damage_large.sides",
            "damage_large.bonus",
            "rate",
            "protection",
            "damage_type",
            "melee_flag",
            "damage_medium.dice",
            "damage_medium.sides",
            "damage_medium.bonus",
            "range",
            "class_restrictions",
            "ammo_type",
            "unknown",
        ],
    )
    write_tsv(
        OUT / "mon0spc_effects.tsv",
        effects,
        ["block_id", "record_index", "effect_code", "duration", "effect_data", "effect_table_flag", "next_effect_ptr", "raw_hex"],
    )


if __name__ == "__main__":
    main()
