#!/usr/bin/env python3
from __future__ import annotations

import json
import re
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ECL_DIR = ROOT / "generated" / "ecl1_disasm"
DATA_DIR = ROOT / "generated" / "data_model"
OUT = ROOT / "generated" / "encounters"


SETUP_RE = re.compile(
    r"^0x(?P<addr>[0-9A-F]{4})\s+0x0C\s+SETUP MONSTER\s+sprite_id:\s+(?P<sprite>\S+)\s+max_distance:\s+(?P<dist>\S+)\s+pic_id:\s+(?P<pic>\S+)"
)
LOAD_RE = re.compile(
    r"^0x(?P<addr>[0-9A-F]{4})\s+0x0B\s+LOAD MONSTER\s+monster_id:\s+(?P<monster>\S+)\s+copies:\s+(?P<copies>\S+)\s+cpic_id:\s+(?P<cpic>\S+)"
)
ENCOUNTER_RE = re.compile(
    r"^0x(?P<addr>[0-9A-F]{4})\s+0x29\s+ENCOUNTER MENU\s+sprite_id:\s+(?P<sprite>\S+)\s+max_distance:\s+(?P<dist>\S+)\s+pic_id:\s+(?P<pic>\S+)"
)


DYNAMIC_TABLE_RULES = {
    (21, "0x83DE"): {"monster_table": 0x8FCD, "index_note": "4 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (21, "0x863A"): {"monster_table": 0x8FCD, "index_note": "3 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (21, "0x86EC"): {"monster_table": 0x8FCD, "index_note": "4 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (21, "0x8785"): {"monster_table": 0x8FCD, "index_note": "1 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (21, "0x881D"): {"monster_table": 0x8FCD, "index_note": "random 2..4 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (21, "0x88E4"): {"monster_table": 0x8FCD, "index_note": "1 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (21, "0x8A09"): {"monster_table": 0x8FCD, "index_note": "random 2..5 + area2.event_scratch8; event_scratch8 source unresolved", "scan": 28},
    (33, "0x8392"): {"monster_table": 0xA2EB, "pic_table": 0xA2E7, "indices": [1, 2, 3], "index_note": "area2.event_scratch0 = random 1..3, or 1..2 when abs_C04E path runs"},
    (34, "0x853F"): {"monster_table": 0xA2F0, "pic_table": 0xA2EC, "indices": [1, 2, 3], "index_note": "area1.event_word_21C = random 1..3"},
    (36, "0x884D"): {"monster_table": 0x9E4A, "pic_table": 0x9E46, "indices": [1, 2, 3], "index_note": "area1.event_word_21E = random 1..3"},
    (37, "0x82E6"): {"monster_table": 0xA3E6, "pic_table": 0xA3E2, "indices": [1, 2, 3], "index_note": "area2.event_scratch0 = random 1..3, or 1..2 when abs_C04E path runs"},
}


def parse_int(value: str) -> int | None:
    value = value.rstrip(",;)")
    if value.isdigit():
        return int(value)
    return None


def geo_names() -> dict[int, str]:
    path = ROOT / "generated" / "geo1" / "geo1_maps.tsv"
    rows: dict[int, str] = {}
    if not path.exists():
        return rows
    lines = path.read_text(encoding="utf-8").splitlines()
    header = lines[0].split("\t")
    for line in lines[1:]:
        vals = dict(zip(header, line.split("\t")))
        if vals.get("geo_id"):
            rows[int(vals["geo_id"])] = vals.get("name", "")
    return rows


def load_monsters() -> dict[int, dict]:
    path = DATA_DIR / "mon0cha_monsters.json"
    monsters = json.loads(path.read_text(encoding="utf-8"))
    return {row["id"]: row for row in monsters}


def monster_summary(monster: dict | None) -> dict | None:
    if monster is None:
        return None
    return {
        "id": monster["id"],
        "name": monster["name"],
        "stats": monster["stats"],
        "matrix_variant_candidates": monster["matrix_variant_candidates"],
        "visuals": monster["visuals"],
    }


def ecl_byte(block_id: int, address: int) -> int | None:
    path = ROOT / "generated" / "ecl1_blocks" / f"ecl1_{block_id:03d}.bin"
    if not path.exists():
        return None
    data = path.read_bytes()
    offset = address - 0x8000
    if offset < 0 or offset >= len(data):
        return None
    return data[offset]


def unique_monster_candidates(monster_ids: list[int], monsters: dict[int, dict]) -> list[dict]:
    rows = []
    seen = set()
    for monster_id in monster_ids:
        if monster_id in seen or monster_id in (0, 255):
            continue
        seen.add(monster_id)
        rows.append(monster_summary(monsters.get(monster_id)) or {"id": monster_id, "name": None})
    return rows


def resolve_dynamic_candidates(block_id: int, address: str, monsters: dict[int, dict]) -> dict | None:
    rule = DYNAMIC_TABLE_RULES.get((block_id, address))
    if rule is None:
        return None

    if "indices" in rule:
        indices = rule["indices"]
        monster_values = [ecl_byte(block_id, rule["monster_table"] + index) for index in indices]
        pic_values = [ecl_byte(block_id, rule["pic_table"] + index) for index in indices if "pic_table" in rule]
    else:
        scan = rule.get("scan", 0)
        indices = list(range(1, scan))
        monster_values = [ecl_byte(block_id, rule["monster_table"] + index) for index in indices]
        pic_values = []

    monster_ids = [value for value in monster_values if value is not None]
    pic_ids = [value for value in pic_values if value is not None]
    return {
        "source": "ecl_local_table",
        "monster_table": f"0x{rule['monster_table']:04X}",
        "pic_table": f"0x{rule['pic_table']:04X}" if "pic_table" in rule else None,
        "indices": indices,
        "index_note": rule["index_note"],
        "raw_monster_values": monster_ids,
        "raw_pic_values": pic_ids,
        "candidate_monsters": unique_monster_candidates(monster_ids, monsters),
        "sentinel_values": sorted({value for value in monster_ids if value in (0, 255)}),
    }


def parse_ecl_listing(path: Path, monsters: dict[int, dict], names: dict[int, str]) -> list[dict]:
    m_block = re.match(r"ecl1_(\d+)", path.name)
    if not m_block:
        return []
    block_id = int(m_block.group(1))
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        for kind, regex, id_key in (
            ("setup_monster", SETUP_RE, "sprite"),
            ("load_monster", LOAD_RE, "monster"),
            ("encounter_menu", ENCOUNTER_RE, "sprite"),
        ):
            m = regex.match(line)
            if not m:
                continue
            values = m.groupdict()
            monster_id = parse_int(values[id_key])
            pic_id = parse_int(values.get("pic", "") or values.get("cpic", ""))
            row = {
                "ecl_block": block_id,
                "map_name": names.get(block_id, ""),
                "address": f"0x{values['addr']}",
                "kind": kind,
                "raw": line,
                "monster_id": monster_id,
                "monster_ref": values[id_key],
                "pic_id": pic_id,
                "pic_ref": values.get("pic") or values.get("cpic"),
                "max_distance": values.get("dist"),
                "copies": values.get("copies"),
                "monster": monster_summary(monsters.get(monster_id)) if monster_id is not None else None,
                "resolution": "constant" if monster_id is not None else "dynamic",
            }
            if monster_id is not None and monster_id not in monsters and monster_id != 255:
                row["resolution"] = "missing_mon0cha_record"
            if monster_id == 255:
                row["resolution"] = "sentinel_or_pic_only"
            if monster_id is None:
                candidates = resolve_dynamic_candidates(block_id, row["address"], monsters)
                if candidates:
                    row["candidate_resolution"] = candidates
                    if candidates["candidate_monsters"]:
                        row["resolution"] = "candidate_table"
            rows.append(row)
    return rows


def render_markdown(rows: list[dict]) -> str:
    by_kind = Counter(row["kind"] for row in rows)
    by_resolution = Counter(row["resolution"] for row in rows)
    direct = [row for row in rows if row["monster"]]
    candidate_rows = [row for row in rows if row["resolution"] == "candidate_table"]
    monster_counts = Counter(row["monster"]["name"] for row in direct)
    lines = [
        "# Matrix Cubed Encounter Monster Cross-Reference",
        "",
        "This pass joins ECL monster setup/load commands to decoded `MON0CHA.DAX` records when the operand is a direct constant.",
        "",
        "## Summary",
        "",
        f"- total encounter-related command rows: {len(rows)}",
        f"- setup_monster rows: {by_kind.get('setup_monster', 0)}",
        f"- load_monster rows: {by_kind.get('load_monster', 0)}",
        f"- encounter_menu rows: {by_kind.get('encounter_menu', 0)}",
        f"- direct constant rows linked to `MON0CHA`: {len(direct)}",
        f"- dynamic rows narrowed to finite table candidates: {len(candidate_rows)}",
        f"- dynamic rows needing runtime expression resolution: {by_resolution.get('dynamic', 0)}",
        f"- sentinel/pic-only rows: {by_resolution.get('sentinel_or_pic_only', 0)}",
        "",
        "## Most Referenced Direct Monsters",
        "",
        "| Count | Monster |",
        "| ---: | --- |",
    ]
    for name, count in monster_counts.most_common(20):
        lines.append(f"| {count} | {name} |")

    lines.extend(
        [
            "",
            "## Direct Constant References",
            "",
            "| ECL | Map | Address | Kind | ID | Monster | Distance | Pic/CPIC |",
            "| ---: | --- | --- | --- | ---: | --- | --- | --- |",
        ]
    )
    for row in direct:
        lines.append(
            f"| {row['ecl_block']} | {row['map_name']} | `{row['address']}` | `{row['kind']}` | {row['monster_id']} | {row['monster']['name']} | {row.get('max_distance') or ''} | {row.get('pic_ref') or ''} |"
        )

    lines.extend(
        [
            "",
            "## Finite Table Candidates",
            "",
            "These rows still use variable operands at runtime, but the local ECL table bytes now constrain the possible monster records.",
            "",
            "| ECL | Map | Address | Ref | Candidates | Table Evidence |",
            "| ---: | --- | --- | --- | --- | --- |",
        ]
    )
    for row in candidate_rows:
        candidate = row["candidate_resolution"]
        names = ", ".join(monster["name"] or f"id {monster['id']}" for monster in candidate["candidate_monsters"]) or "(sentinel/pic-only)"
        evidence = f"{candidate['monster_table']} values {candidate['raw_monster_values']} ({candidate['index_note']})"
        lines.append(
            f"| {row['ecl_block']} | {row['map_name']} | `{row['address']}` | `{row['monster_ref']}` | {names} | {evidence} |"
        )

    dynamic = [row for row in rows if row["resolution"] == "dynamic"]
    lines.extend(
        [
            "",
            "## Dynamic References",
            "",
            "These operands are expressions or memory values. They need ECL data-flow resolution before they can be bound to `MON0CHA` records.",
            "",
            "| ECL | Map | Address | Kind | Monster Ref | Pic Ref | Raw |",
            "| ---: | --- | --- | --- | --- | --- | --- |",
        ]
    )
    for row in dynamic:
        lines.append(
            f"| {row['ecl_block']} | {row['map_name']} | `{row['address']}` | `{row['kind']}` | `{row['monster_ref']}` | `{row.get('pic_ref') or ''}` | `{row['raw']}` |"
        )
    return "\n".join(lines) + "\n"


def write_tsv(path: Path, rows: list[dict]) -> None:
    cols = ["ecl_block", "map_name", "address", "kind", "resolution", "monster_ref", "monster_id", "monster_name", "candidate_monsters", "max_distance", "pic_ref", "copies", "raw"]
    with path.open("w", encoding="utf-8") as f:
        f.write("\t".join(cols) + "\n")
        for row in rows:
            values = {
                **row,
                "monster_name": row["monster"]["name"] if row.get("monster") else "",
                "candidate_monsters": ", ".join(
                    monster.get("name") or f"id {monster['id']}"
                    for monster in row.get("candidate_resolution", {}).get("candidate_monsters", [])
                ),
            }
            f.write("\t".join(str(values.get(col, "")).replace("\t", " ").replace("\n", " ") for col in cols) + "\n")


def main() -> None:
    OUT.mkdir(parents=True, exist_ok=True)
    monsters = load_monsters()
    names = geo_names()
    rows = []
    for path in sorted(ECL_DIR.glob("ecl1_*.ecl.txt")):
        rows.extend(parse_ecl_listing(path, monsters, names))
    rows.sort(key=lambda row: (row["ecl_block"], row["address"], row["kind"]))

    by_monster: dict[str, list[dict]] = defaultdict(list)
    for row in rows:
        if row.get("monster"):
            by_monster[str(row["monster_id"])].append(
                {
                    "ecl_block": row["ecl_block"],
                    "map_name": row["map_name"],
                    "address": row["address"],
                    "kind": row["kind"],
                    "max_distance": row.get("max_distance"),
                    "pic_ref": row.get("pic_ref"),
                    "copies": row.get("copies"),
                }
            )

    (OUT / "encounter_monster_xref.json").write_text(json.dumps(rows, indent=2) + "\n", encoding="utf-8")
    (OUT / "monster_usage_by_id.json").write_text(json.dumps(by_monster, indent=2) + "\n", encoding="utf-8")
    (OUT / "encounter_monster_xref.md").write_text(render_markdown(rows), encoding="utf-8")
    write_tsv(OUT / "encounter_monster_xref.tsv", rows)


if __name__ == "__main__":
    main()
