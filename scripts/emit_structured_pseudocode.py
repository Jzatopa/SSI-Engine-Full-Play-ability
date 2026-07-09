#!/usr/bin/env python3
"""Emit structured first-pass pseudocode from decoded ECL listings."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


IF_OPS = {
    "IF =": "==",
    "IF <>": "!=",
    "IF <": "<",
    "IF >": ">",
    "IF <=": "<=",
    "IF >=": ">=",
}


def slug(text: str) -> str:
    return re.sub(r"[^a-zA-Z0-9]+", "-", text.lower()).strip("-") or "map"


def parse_listing(path: Path) -> list[dict]:
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.startswith("0x"):
            continue
        m = re.match(r"0x([0-9A-F]{4})\s+0x([0-9A-F]{2})\s+(.+)", line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        opcode = int(m.group(2), 16)
        rest = m.group(3)
        rows.append({"addr": addr, "opcode": opcode, "rest": rest, "line": line})
    rows.sort(key=lambda r: r["addr"])
    return rows


def cmd_name(rest: str) -> str:
    for name in sorted(
        [
            "COMPARE AND",
            "LOAD CHARACTER",
            "LOAD MONSTER",
            "SETUP MONSTER",
            "INPUT NUMBER",
            "INPUT STRING",
            "VERTICAL MENU",
            "HORIZONTAL MENU",
            "LOAD FILES",
            "PARTY SURPRISE",
            "ON GOSUB",
            "ON GOTO",
            "ENCOUNTER MENU",
            "PRINT RETURN",
            "ECL CLOCK",
            "SAVE TABLE",
            "ADD NPC",
            "LOAD PIECES",
            "FIND SPECIAL",
            "DESTROY ITEMS",
            "IF <>",
            "IF <=",
            "IF >=",
            "IF =",
            "IF <",
            "IF >",
            "PRINTCLEAR",
            "CLEARMONSTERS",
            "PARTYSTRENGTH",
            "NEWECL",
            "COMBAT",
            "TREASURE",
            "PARLAY",
            "DAMAGE",
            "RETURN",
            "GOSUB",
            "GOTO",
            "SAVE",
            "PRINT",
            "ADD",
            "SUBTRACT",
            "DIVIDE",
            "MULTIPLY",
            "RANDOM",
            "PICTURE",
            "APPROACH",
            "SURPRISE",
            "GETTABLE",
            "CALL",
            "AND",
            "OR",
            "PROGRAM",
            "WHO",
            "DELAY",
            "SPELL",
            "PROTECTION",
            "CLEAR BOX",
            "DUMP",
            "EXIT",
        ],
        key=len,
        reverse=True,
    ):
        if rest.startswith(name):
            return name
    return rest.split()[0] if rest.split() else ""


def detail(rest: str) -> str:
    name = cmd_name(rest)
    return rest[len(name) :].strip()


def compare_condition(compare_rest: str, if_name: str) -> str:
    d = detail(compare_rest)
    m = re.search(r"Values:\s*(.*?)\s*==\s*(.*)", d)
    if m:
        left, right = m.group(1).strip(), m.group(2).strip()
        op = IF_OPS.get(if_name, "?")
        return f"{left} {op} {right}"
    return f"compare_result {IF_OPS.get(if_name, '?')} true"


def flag_condition(flag_rest: str, if_name: str) -> tuple[str, str]:
    d = detail(flag_rest)
    op = IF_OPS.get(if_name, "?")
    m = re.match(r"(.+?)\s*=\s*(.+)", d)
    if not m:
        return "", f"last_result {op} 0"
    dest, expr = m.group(1).strip(), m.group(2).strip()
    return f"{dest} = {expr};", f"{dest} {op} 0"


def rewrite_statement(row: dict) -> str:
    name = cmd_name(row["rest"])
    d = detail(row["rest"])
    addr = row["addr"]
    if "<suspect data/code boundary:" in row["rest"]:
        return f"// suspect data/code boundary at 0x{addr:04X}; stopped linear decode"
    if name == "SAVE":
        return f"{d};  // 0x{addr:04X}"
    if name in ("PRINT", "PRINTCLEAR"):
        return f"{name.lower()}({d});  // 0x{addr:04X}"
    if name == "GOTO":
        return f"goto {d};  // 0x{addr:04X}"
    if name == "GOSUB":
        return f"gosub {d};  // 0x{addr:04X}"
    if name == "NEWECL":
        return f"load_ecl_and_exit({d});  // 0x{addr:04X}"
    if name == "EXIT":
        return f"exit_event();  // 0x{addr:04X}"
    if name == "RETURN":
        return f"return;  // 0x{addr:04X}"
    if name == "COMBAT":
        return f"combat();  // 0x{addr:04X}"
    if name == "CALL":
        return f"engine_call({d});  // 0x{addr:04X}"
    if name:
        return f"{name.lower().replace(' ', '_')}({d});  // 0x{addr:04X}"
    return f"raw({row['rest']});  // 0x{addr:04X}"


def target_from_goto(row: dict) -> int | None:
    if cmd_name(row["rest"]) != "GOTO":
        return None
    m = re.search(r"0x([0-9A-F]{4})", row["rest"])
    return int(m.group(1), 16) if m else None


class Structurer:
    def __init__(self, rows: list[dict]):
        self.rows = rows
        self.index = {r["addr"]: i for i, r in enumerate(rows)}

    def nearest_index(self, target: int) -> int | None:
        if target in self.index:
            return self.index[target]
        for i, row in enumerate(self.rows):
            if row["addr"] >= target:
                return i
        return None

    def block(self, target: int, depth: int = 0, max_lines: int = 100, visited: set[int] | None = None) -> list[str]:
        if visited is None:
            visited = set()
        if target in visited:
            return [f"// target 0x{target:04X} already emitted"]
        visited.add(target)
        idx = self.nearest_index(target)
        if idx is None:
            return [f"// no decoded instructions at 0x{target:04X}"]
        out = []
        i = idx
        while i < len(self.rows) and len(out) < max_lines:
            row = self.rows[i]
            if out and row["addr"] >= target + 0x280:
                out.append(f"// truncated at 0x{row['addr']:04X}")
                break
            name = cmd_name(row["rest"])
            if name in ("COMPARE", "AND", "OR") and i + 1 < len(self.rows):
                next_row = self.rows[i + 1]
                if_name = cmd_name(next_row["rest"])
                if if_name in IF_OPS and i + 2 < len(self.rows):
                    setup = ""
                    if name == "COMPARE":
                        condition = compare_condition(row["rest"], if_name)
                    else:
                        setup, condition = flag_condition(row["rest"], if_name)
                    action = self.rows[i + 2]
                    out.append(f"// 0x{row['addr']:04X}-0x{next_row['addr']:04X}")
                    if setup:
                        out.append(setup + f"  // 0x{row['addr']:04X}")
                    out.append(f"if ({condition}) {{")
                    if cmd_name(action["rest"]) == "GOTO":
                        branch = target_from_goto(action)
                        out.append(f"  {rewrite_statement(action)}")
                        if branch is not None and depth < 3:
                            out.append(f"  // branch body 0x{branch:04X}")
                            for line in self.block(branch, depth + 1, max_lines=max_lines - len(out), visited=visited):
                                out.append("  " + line)
                    else:
                        out.append("  " + rewrite_statement(action))
                    out.append("}")
                    i += 3
                    continue
            if name in ("ON GOTO", "ON GOSUB"):
                out.extend(self.switch_from_on_goto(row, depth, max_lines - len(out), visited))
                break
            out.append(rewrite_statement(row))
            if "<suspect data/code boundary:" in row["rest"]:
                break
            if name == "GOTO":
                branch = target_from_goto(row)
                if branch is not None and depth < 3:
                    out.append(f"// branch body 0x{branch:04X}")
                    for line in self.block(branch, depth + 1, max_lines=max_lines - len(out), visited=visited):
                        out.append("  " + line)
                break
            if name in ("EXIT", "RETURN", "NEWECL"):
                break
            i += 1
        return out

    def switch_from_on_goto(self, row: dict, depth: int, max_lines: int, visited: set[int]) -> list[str]:
        d = detail(row["rest"])
        m = re.match(r"(.+?)\s+of\s+\[(.*)\]", d)
        if not m:
            return [rewrite_statement(row)]
        selector = m.group(1).strip()
        targets = [int(x, 16) for x in re.findall(r"0x([0-9A-F]{4})", m.group(2))]
        out = [f"// 0x{row['addr']:04X}", f"switch ({selector}) {{"]
        for idx, branch in enumerate(targets):
            out.append(f"  case {idx}: goto 0x{branch:04X};")
            if depth < 2 and idx < 12 and len(out) < max_lines:
                out.append(f"    // case {idx} body")
                for line in self.block(branch, depth + 1, max_lines=max_lines - len(out), visited=visited):
                    out.append("    " + line)
        if len(targets) > 12:
            out.append(f"  // {len(targets) - 12} additional cases omitted in this pass")
        out.append("}")
        return out


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("atlas_json", type=Path)
    parser.add_argument("listings_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)
    atlas = json.loads(args.atlas_json.read_text(encoding="utf-8"))
    structurers = {}
    index = ["# Structured Event Pseudocode Index", ""]

    for item in atlas:
        geo_id = item["geo_id"]
        name = item["name"]
        ecl_block = item.get("ecl_block")
        out = args.out_dir / f"geo_{geo_id:03d}_{slug(name)}.structured.md"
        index.append(f"- [GEO {geo_id}: {name}]({out.name})")
        lines = [
            f"# GEO {geo_id}: {name}",
            "",
            f"ECL block: `{ecl_block or '-'}`",
            "",
            "Structured first-pass pseudocode. This is reconstructed analysis, not original source.",
            "",
        ]
        structurer = None
        if ecl_block:
            ecl_block = int(ecl_block)
            if ecl_block not in structurers:
                listing_path = args.listings_dir / f"ecl1_{ecl_block:03d}.ecl.txt"
                structurers[ecl_block] = Structurer(parse_listing(listing_path)) if listing_path.exists() else None
            structurer = structurers[ecl_block]
        events = item.get("events") or {}
        if not events:
            lines.append("_No mapped events for this pass._")
        for ev, info in sorted(events.items(), key=lambda kv: int(kv[0])):
            target = int(info.get("target", 0))
            lines.extend(
                [
                    f"## Event {int(ev):02d}",
                    "",
                    f"- Target: `0x{target:04X}`",
                    f"- Text hint: {info.get('text', '')}",
                    "",
                    "```text",
                    f"event {int(ev):02d} {{",
                ]
            )
            body = structurer.block(target) if structurer else [f"// no listing for ECL block {ecl_block}"]
            lines.extend("  " + line for line in body)
            lines.extend(["}", "```", ""])
        out.write_text("\n".join(lines), encoding="utf-8")
    (args.out_dir / "index.md").write_text("\n".join(index) + "\n", encoding="utf-8")
    print(f"wrote {len(atlas)} structured pseudocode files to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
