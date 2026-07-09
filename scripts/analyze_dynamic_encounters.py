#!/usr/bin/env python3
from __future__ import annotations

import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "generated" / "encounters"


GETTABLE_RE = re.compile(
    r"gettable\((?P<dest>[\w.]+)\s+=\s+(?P<table>(?:ecl\.byte_[0-9A-F]{4}|abs_[0-9A-F]{4}))\[(?P<index>[^\]]+)\]\);"
)
EVENT_RE = re.compile(r"^## Event\s+(?P<event>\d+)\s*$", re.MULTILINE)


def load_monsters() -> dict[int, dict]:
    rows = json.loads((ROOT / "generated" / "data_model" / "mon0cha_monsters.json").read_text(encoding="utf-8"))
    return {row["id"]: row for row in rows}


def ecl_block_bytes(block_id: int) -> bytes:
    return (ROOT / "generated" / "ecl1_blocks" / f"ecl1_{block_id:03d}.bin").read_bytes()


def table_offset(label: str) -> int | None:
    value = int(label.rsplit("_", 1)[1], 16)
    if label.startswith("ecl.byte_"):
        return value
    if label.startswith("abs_") and value >= 0x8000:
        return value - 0x8000
    return None


def table_candidates(block_id: int, label: str, monsters: dict[int, dict], count: int = 12) -> list[dict]:
    off = table_offset(label)
    data = ecl_block_bytes(block_id)
    if off is None or off >= len(data):
        return []
    rows = []
    for index, value in enumerate(data[off : off + count]):
        monster = monsters.get(value)
        rows.append(
            {
                "index": index,
                "value": value,
                "hex": f"0x{value:02X}",
                "monster": monster["name"] if monster else None,
                "sentinel": value == 255,
            }
        )
    return rows


def event_sections(block_id: int) -> dict[str, str]:
    matches = sorted((ROOT / "generated" / "event_structured").glob(f"geo_{block_id:03d}_*.structured.md"))
    if not matches:
        return {}
    text = matches[0].read_text(encoding="utf-8")
    found = list(EVENT_RE.finditer(text))
    sections: dict[str, str] = {}
    for i, match in enumerate(found):
        start = match.end()
        end = found[i + 1].start() if i + 1 < len(found) else len(text)
        sections[match.group("event")] = text[start:end]
    return sections


def find_event_for_address(block_id: int, address: str) -> tuple[str | None, str]:
    for event_id, body in event_sections(block_id).items():
        if address in body:
            return event_id, body
    return None, ""


def context_before(body: str, address: str, lines: int = 12) -> str:
    rows = body.splitlines()
    hit = 0
    for i, line in enumerate(rows):
        if address in line:
            hit = i
            break
    return "\n".join(rows[max(0, hit - lines) : hit + 1])


def analyze_row(row: dict, monsters: dict[int, dict]) -> dict:
    block_id = int(row["ecl_block"])
    event_id, body = find_event_for_address(block_id, row["address"])
    ctx = context_before(body, row["address"])
    refs = []
    for match in GETTABLE_RE.finditer(ctx):
        dest = match.group("dest")
        if dest not in (row.get("monster_ref"), row.get("pic_ref")):
            continue
        table = match.group("table")
        refs.append(
            {
                "dest": dest,
                "table": table,
                "index_expression": match.group("index"),
                "candidates": table_candidates(block_id, table, monsters),
            }
        )
    return {
        "ecl_block": block_id,
        "map_name": row.get("map_name", ""),
        "event_id": int(event_id) if event_id else None,
        "address": row["address"],
        "kind": row["kind"],
        "monster_ref": row.get("monster_ref"),
        "pic_ref": row.get("pic_ref"),
        "context": ctx,
        "table_refs": refs,
    }


def render_markdown(rows: list[dict]) -> str:
    lines = [
        "# Dynamic Encounter Table Analysis",
        "",
        "This pass inspects dynamic encounter operands and extracts nearby `GETTABLE` sources when possible.",
        "",
        f"- dynamic rows analyzed: {len(rows)}",
        f"- rows with table candidates: {sum(1 for row in rows if row['table_refs'])}",
        "",
    ]
    for row in rows:
        lines.extend(
            [
                f"## ECL {row['ecl_block']:03} Event {row['event_id'] or '?'} `{row['address']}`",
                "",
                f"- Map: {row['map_name'] or '-'}",
                f"- Kind: `{row['kind']}`",
                f"- Monster ref: `{row['monster_ref']}`",
                f"- Pic ref: `{row['pic_ref']}`",
                "",
            ]
        )
        if row["table_refs"]:
            for ref in row["table_refs"]:
                names = []
                for candidate in ref["candidates"]:
                    label = candidate["monster"] or ("sentinel" if candidate["sentinel"] else "")
                    names.append(f"{candidate['index']}:{candidate['value']}{' ' + label if label else ''}")
                lines.append(f"- `{ref['dest']}` from `{ref['table']}[{ref['index_expression']}]`: {', '.join(names)}")
            lines.append("")
        else:
            lines.append("- No nearby table source found; likely state carried from another event path.\n")
        lines.extend(["~~~text", row["context"], "~~~", ""])
    return "\n".join(lines)


def main() -> None:
    OUT.mkdir(parents=True, exist_ok=True)
    monsters = load_monsters()
    xref = json.loads((OUT / "encounter_monster_xref.json").read_text(encoding="utf-8"))
    rows = [analyze_row(row, monsters) for row in xref if row.get("resolution") == "dynamic"]
    (OUT / "dynamic_encounter_analysis.json").write_text(json.dumps(rows, indent=2) + "\n", encoding="utf-8")
    (OUT / "dynamic_encounter_analysis.md").write_text(render_markdown(rows), encoding="utf-8")


if __name__ == "__main__":
    main()
