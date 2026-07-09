#!/usr/bin/env python3
"""First-pass Gold Box ECL disassembler for Matrix Cubed.

Ported/adapted from Simeon Pilgrim's ECLDump concepts:
https://github.com/simeonpilgrim/coab/tree/ECLDump
"""

from __future__ import annotations

import argparse
import sys
from collections import deque
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "tools"))
from extract_goldbox_dax_images import read_dax  # noqa: E402


BASE = 0x8000


COMMANDS = {
    0x00: ("EXIT", 0),
    0x01: ("GOTO", 1),
    0x02: ("GOSUB", 1),
    0x03: ("COMPARE", 2),
    0x04: ("ADD", 3),
    0x05: ("SUBTRACT", 3),
    0x06: ("DIVIDE", 3),
    0x07: ("MULTIPLY", 3),
    0x08: ("RANDOM", 2),
    0x09: ("SAVE", 2),
    0x0A: ("LOAD CHARACTER", 1),
    0x0B: ("LOAD MONSTER", 3),
    0x0C: ("SETUP MONSTER", 3),
    0x0D: ("APPROACH", 0),
    0x0E: ("PICTURE", 1),
    0x0F: ("INPUT NUMBER", 2),
    0x10: ("INPUT STRING", 2),
    0x11: ("PRINT", 1),
    0x12: ("PRINTCLEAR", 1),
    0x13: ("RETURN", 0),
    0x14: ("COMPARE AND", 4),
    0x15: ("VERTICAL MENU", 0),
    0x16: ("IF =", 0),
    0x17: ("IF <>", 0),
    0x18: ("IF <", 0),
    0x19: ("IF >", 0),
    0x1A: ("IF <=", 0),
    0x1B: ("IF >=", 0),
    0x1C: ("CLEARMONSTERS", 0),
    0x1D: ("PARTYSTRENGTH", 1),
    0x1E: ("CHECKPARTY", 6),
    0x1F: ("UNKNOWN_1F", 2),
    0x20: ("NEWECL", 1),
    0x21: ("LOAD FILES", 3),
    0x22: ("PARTY SURPRISE", 2),
    0x23: ("SURPRISE", 4),
    0x24: ("COMBAT", 0),
    0x25: ("ON GOTO", 0),
    0x26: ("ON GOSUB", 0),
    0x27: ("TREASURE", 8),
    0x28: ("ROB", 3),
    0x29: ("ENCOUNTER MENU", 14),
    0x2A: ("GETTABLE", 3),
    0x2B: ("HORIZONTAL MENU", 0),
    0x2C: ("PARLAY", 6),
    0x2D: ("CALL", 1),
    0x2E: ("DAMAGE", 5),
    0x2F: ("AND", 3),
    0x30: ("OR", 3),
    0x31: ("SPRITE OFF", 0),
    0x32: ("FIND ITEM", 1),
    0x33: ("PRINT RETURN", 0),
    0x34: ("ECL CLOCK", 2),
    0x35: ("SAVE TABLE", 3),
    0x36: ("ADD NPC", 2),
    0x37: ("LOAD PIECES", 3),
    0x38: ("PROGRAM", 1),
    0x39: ("WHO", 1),
    0x3A: ("DELAY", 0),
    0x3B: ("SPELL", 3),
    0x3C: ("PROTECTION", 1),
    0x3D: ("CLEAR BOX", 0),
    0x3E: ("DUMP", 0),
    0x3F: ("FIND SPECIAL", 1),
    0x40: ("DESTROY ITEMS", 1),
}


AREA1_NAMES = {
    0x18E: "area1.time_minutes_ones",
    0x190: "area1.time_minutes_tens",
    0x192: "area1.time_hour",
    0x194: "area1.time_day",
    0x196: "area1.time_year",
    0x1CC: "area1.inDungeon",
    0x1E0: "area1.lastXPos",
    0x1E2: "area1.lastYPos",
    0x1E4: "area1.LastEclBlockId",
    0x1F6: "area1.block_area_view",
    0x1F8: "area1.game_speed",
    0x1FA: "area1.outdoor_sky_colour",
    0x1FC: "area1.indoor_sky_colour",
    0x200: "area1.event_word_200",
    0x202: "area1.event_word_202",
    0x204: "area1.event_word_204",
    0x206: "area1.event_word_206",
    0x208: "area1.event_word_208",
    0x20A: "area1.event_word_20A",
    0x20C: "area1.event_word_20C",
    0x20E: "area1.event_word_20E",
    0x210: "area1.event_word_210",
    0x212: "area1.event_word_212",
    0x214: "area1.event_word_214",
    0x216: "area1.event_word_216",
    0x218: "area1.event_word_218",
    0x21A: "area1.event_word_21A",
    0x21C: "area1.event_word_21C",
    0x21E: "area1.event_word_21E",
    0x220: "area1.event_word_220",
    0x222: "area1.event_word_222",
    0x224: "area1.event_word_224",
    0x226: "area1.event_word_226",
    0x228: "area1.event_word_228",
    0x22A: "area1.event_word_22A",
    0x22C: "area1.event_word_22C",
    0x22E: "area1.event_word_22E",
    0x342: "area1.current_city",
    0x3FE: "area1.picture_fade",
}

AREA2_NAMES = {
    0x000: "area2.selected_player_name",
    0x200: "area2.selected_player_in_combat",
    0x218: "area2.selected_player_combat_team",
    0x550: "area2.training_class_mask",
    0x580: "area2.max_encounter_distance",
    0x582: "area2.encounter_distance",
    0x594: "area2.search_flags",
    0x596: "area2.surprise_result",
    0x5A4: "area2.rest_encounter_period",
    0x5A6: "area2.rest_encounter_percentage",
    0x5AA: "area2.tried_to_exit_map",
    0x5C2: "area2.HeadBlockId",
    0x5C4: "area2.EnterTemple",
    0x5CC: "area2.isDuel",
    0x624: "area2.game_area",
    0x67C: "area2.party_size",
    0x67E: "area2.division_remainder",
    0x6D8: "area2.EnterShop",
    0x6F2: "area2.event_scratch0",
    0x6F4: "area2.event_scratch1",
    0x6F6: "area2.event_scratch2",
    0x6F8: "area2.event_scratch3",
    0x6FA: "area2.event_scratch4",
    0x6FC: "area2.event_scratch5",
    0x6FE: "area2.event_scratch6",
    0x700: "area2.event_scratch7",
    0x702: "area2.event_scratch8",
    0x704: "area2.event_scratch9",
}


class Ecl:
    def __init__(self, block: bytes):
        self.data = block[2:] if len(block) >= 2 else b""
        self.off = BASE
        self.strings = [""] * 40
        self.skip_next = False
        self.stop = False
        self.todo: deque[tuple[int, str]] = deque()
        self.done: dict[int, str] = {}
        self.byte_map: dict[int, int] = {}
        self.unknowns: list[tuple[int, int]] = []
        self.suspect_targets: list[tuple[int, int, str]] = []
        self.text_fallthrough_boundaries: list[tuple[int, int, str]] = []
        self.text_fallthrough_addrs: set[int] = set()
        self.text_padding_targets: list[tuple[int, int, int]] = []
        self.normalized_targets: list[tuple[int, int, str]] = []
        self.normalized_fallthroughs: list[tuple[int, int]] = []
        self.normalized_unknown_targets: list[tuple[int, int, str]] = []
        self.normalized_unknown_fallthroughs: list[tuple[int, int]] = []

    def byte(self, addr: int) -> int:
        loc = addr & 0xFFFF
        if 0 <= loc < len(self.data):
            return self.data[loc]
        return 0xFF

    def valid(self, addr: int) -> bool:
        return 0 <= (addr & 0xFFFF) < len(self.data)

    def add_addr(self, addr: int, reason: str) -> None:
        if not self.valid(addr + BASE):
            return
        if addr in self.text_fallthrough_addrs:
            return
        normalized = self.normalized_branch_target(addr)
        if normalized is not None:
            self.normalized_targets.append((addr, normalized, reason))
            addr = normalized
        normalized = self.normalized_unknown_target(addr)
        if normalized is not None:
            self.normalized_unknown_targets.append((addr, normalized, reason))
            addr = normalized
        opcode = self.byte(BASE + addr)
        if opcode not in COMMANDS:
            self.suspect_targets.append((addr, opcode, reason))
            return
        if addr not in self.done and all(a != addr for a, _ in self.todo):
            self.todo.append((addr, reason))

    def add_line(self, addr: int, text: str, length: int) -> None:
        if addr in self.done:
            return
        self.done[addr] = text
        for i in range(max(length, 1)):
            self.byte_map.setdefault(addr + i, addr)

    def read_header_entries(self) -> list[int]:
        self.off = BASE
        entries = []
        for _ in range(5):
            ops = self.load_ops(1)
            entries.append(ops[0].word)
        return entries

    def load_ops(self, count: int) -> list["Operand"]:
        str_idx = 0
        ops = []
        for _ in range(count):
            code = self.byte(BASE + self.off + 1)
            low = self.byte(BASE + self.off + 2)
            op = Operand(code, low)
            self.off += 2
            if code in (1, 2, 3, 5):
                self.off += 1
                op.set_high(self.byte(BASE + self.off))
            elif code == 0x80:
                str_idx += 1
                if low > 0:
                    raw = bytes(self.byte(BASE + self.off + 1 + i) for i in range(low))
                    self.off += low
                    self.strings[str_idx] = decompress_ecl_string(raw)
                else:
                    self.strings[str_idx] = ""
            elif code == 0x81:
                str_idx += 1
                self.off += 1
                op.set_high(self.byte(BASE + self.off))
                self.strings[str_idx] = f"<string at {mem_name(op.word)}>"
            ops.append(op)
        self.off += 1
        return ops

    def decode(self) -> str:
        entries = self.read_header_entries()
        labels = ["vm_run_1", "SearchLocation", "PreCampCheck", "CampInterrupted", "ecl_initial_entry"]
        lines = [f"{label:<18} 0x{entry:04X}" for label, entry in zip(labels, entries)]
        lines.append("")
        for entry, label in zip(entries, labels):
            self.add_addr(entry, label)

        while self.todo:
            addr, reason = self.todo.popleft()
            if addr in self.done:
                continue
            if addr in self.text_fallthrough_addrs:
                continue
            self.decode_addr(addr, reason)

        self.prune_text_padding_suspects()

        last = None
        for addr in sorted(self.done):
            if last is not None and addr != last:
                lines.append("")
            lines.append(self.done[addr])
            last = addr + max(1, instruction_length_from_text(self.done[addr]))
        if self.unknowns:
            lines.append("")
            lines.append("Unknown opcodes:")
            for addr, op in self.unknowns:
                lines.append(f"- 0x{addr:04X}: 0x{op:02X}")
        if self.suspect_targets:
            lines.append("")
            lines.append("Suspect branch/data targets not decoded as code:")
            seen = set()
            for addr, op, reason in self.suspect_targets:
                key = (addr, op, reason)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{addr:04X}: 0x{op:02X} from {reason}")
        if self.text_fallthrough_boundaries:
            lines.append("")
            lines.append("Text fallthrough boundaries skipped:")
            seen = set()
            for addr, op, reason in self.text_fallthrough_boundaries:
                key = (addr, op, reason)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{addr:04X}: 0x{op:02X} after {reason}")
        if self.text_padding_targets:
            lines.append("")
            lines.append("Text padding branch targets skipped:")
            seen = set()
            for addr, start, end in self.text_padding_targets:
                key = (addr, start, end)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{addr:04X}: inside 0x{start:04X}..0x{end:04X}")
        if self.normalized_targets:
            lines.append("")
            lines.append("Prefixed branch targets normalized:")
            seen = set()
            for src, dest, reason in self.normalized_targets:
                key = (src, dest, reason)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{src:04X} -> 0x{dest:04X} from {reason}")
        if self.normalized_fallthroughs:
            lines.append("")
            lines.append("Prefixed fallthroughs normalized:")
            seen = set()
            for src, dest in self.normalized_fallthroughs:
                key = (src, dest)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{src:04X} -> 0x{dest:04X}")
        if self.normalized_unknown_targets:
            lines.append("")
            lines.append("Unknown-prefixed branch targets normalized:")
            seen = set()
            for src, dest, reason in self.normalized_unknown_targets:
                key = (src, dest, reason)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{src:04X} -> 0x{dest:04X} from {reason}")
        if self.normalized_unknown_fallthroughs:
            lines.append("")
            lines.append("Unknown-prefixed fallthroughs normalized:")
            seen = set()
            for src, dest in self.normalized_unknown_fallthroughs:
                key = (src, dest)
                if key in seen:
                    continue
                seen.add(key)
                lines.append(f"- 0x{src:04X} -> 0x{dest:04X}")
        return "\n".join(lines) + "\n"

    def decode_addr(self, entry: int, reason: str) -> None:
        self.off = entry
        self.stop = False
        self.skip_next = False
        guard = 0
        while not self.stop and guard < 2000:
            guard += 1
            addr = self.off
            normalized = self.normalized_branch_target(addr)
            if normalized is not None:
                self.normalized_fallthroughs.append((addr, normalized))
                self.off = normalized
                continue
            normalized = self.normalized_unknown_target(addr)
            if normalized is not None:
                self.normalized_unknown_fallthroughs.append((addr, normalized))
                self.off = normalized
                continue
            opcode = self.byte(BASE + self.off)
            name, fixed_count = COMMANDS.get(opcode, (f"UNKNOWN_0x{opcode:02X}", 0))
            was_skip_next = self.skip_next
            detail = self.dispatch(opcode, name, fixed_count)
            if was_skip_next:
                self.skip_next = False
            length = (self.off - addr) & 0xFFFF
            self.add_line(addr, f"0x{addr:04X} 0x{opcode:02X} {name} {detail}".rstrip(), length)
            if opcode not in COMMANDS:
                self.unknowns.append((addr, opcode))
                break

    def dispatch(self, opcode: int, name: str, fixed_count: int) -> str:
        if opcode in (0x00, 0x13):
            self.off += 1
            if not self.skip_next:
                self.stop = True
            return ""
        if opcode in (0x0D, 0x1C, 0x24, 0x31, 0x33, 0x3A, 0x3D, 0x3E):
            self.off += 1
            return self.special_no_arg(opcode)
        if opcode in (0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B):
            self.off += 1
            self.skip_next = True
            return "<if compare flag is false, skip next op>"

        if opcode == 0x01:
            op = self.load_ops(1)[0]
            if not self.skip_next:
                self.stop = True
            self.add_addr(op.word, "GOTO")
            return f"0x{op.word:04X}"
        if opcode == 0x02:
            op = self.load_ops(1)[0]
            self.add_addr(op.word, "GOSUB")
            return f"0x{op.word:04X}"
        if opcode in (0x11, 0x12):
            op = self.load_ops(1)[0]
            self.stop_at_text_padding(opcode)
            if op.code >= 0x80:
                return repr(self.strings[1])
            return op.value(self)
        if opcode in (0x15, 0x2B):
            return self.menu(horizontal=opcode == 0x2B)
        if opcode in (0x25, 0x26):
            return self.on_goto(opcode)
        if opcode == 0x23:
            return self.surprise()

        ops = self.load_ops(fixed_count)
        invalid_codes = [op.code for op in ops if not op.valid()]
        if invalid_codes:
            self.stop = True
            codes = ", ".join(f"0x{code:02X}" for code in invalid_codes[:6])
            if len(invalid_codes) > 6:
                codes += ", ..."
            return f"<suspect data/code boundary: invalid operand code(s) {codes}; stopped linear decode>"
        vals = [op.value(self) for op in ops]
        return self.format_fixed(opcode, vals, ops)

    def stop_at_text_padding(self, opcode: int) -> None:
        next_addr = self.off
        invalid_codes = self.peek_invalid_operand_codes(next_addr)
        if not invalid_codes:
            return
        next_opcode = self.byte(BASE + next_addr)
        name = COMMANDS.get(opcode, (f"0x{opcode:02X}", 0))[0]
        self.text_fallthrough_boundaries.append((next_addr, next_opcode, name))
        self.text_fallthrough_addrs.add(next_addr)
        self.stop = True

    def prune_text_padding_suspects(self) -> None:
        if not self.text_fallthrough_addrs:
            return
        max_padding = 0x1000
        addrs = sorted(self.done)
        to_remove: set[int] = set()
        for start in sorted(self.text_fallthrough_addrs):
            end = None
            for addr in addrs:
                if addr <= start:
                    continue
                if addr - start > max_padding:
                    break
                line = self.done[addr]
                if "<suspect data/code boundary:" not in line:
                    end = addr
                    break
            if end is None:
                continue
            for addr in addrs:
                if start < addr < end and "<suspect data/code boundary:" in self.done[addr]:
                    to_remove.add(addr)
                    self.text_padding_targets.append((addr, start, end))
        for addr in to_remove:
            self.done.pop(addr, None)

    def peek_invalid_operand_codes(self, addr: int) -> list[int]:
        opcode = self.byte(BASE + addr)
        if opcode not in COMMANDS:
            return []
        _name, fixed_count = COMMANDS[opcode]
        if fixed_count <= 0:
            return []
        off = addr
        invalid_codes: list[int] = []
        for _ in range(fixed_count):
            code = self.byte(BASE + off + 1)
            low = self.byte(BASE + off + 2)
            if code not in (0x00, 0x01, 0x02, 0x03, 0x05, 0x80, 0x81):
                invalid_codes.append(code)
            off += 2
            if code in (0x01, 0x02, 0x03, 0x05):
                off += 1
            elif code == 0x80:
                off += low
            elif code == 0x81:
                off += 1
        return invalid_codes

    def normalized_branch_target(self, addr: int) -> int | None:
        if not self.peek_invalid_operand_codes(addr):
            return None
        for delta in range(1, 5):
            next_addr = (addr + delta) & 0xFFFF
            if self.clean_instruction_start(next_addr):
                return next_addr
        return None

    def normalized_unknown_target(self, addr: int) -> int | None:
        opcode = self.byte(BASE + addr)
        if opcode in COMMANDS:
            return None
        for delta in range(1, 9):
            next_addr = (addr + delta) & 0xFFFF
            if self.clean_instruction_start(next_addr):
                return next_addr
        return None

    def clean_instruction_start(self, addr: int) -> bool:
        opcode = self.byte(BASE + addr)
        if opcode not in COMMANDS:
            return False
        name, fixed_count = COMMANDS[opcode]
        if name in ("VERTICAL MENU", "HORIZONTAL MENU", "ON GOTO", "ON GOSUB"):
            return False
        return not self.peek_invalid_operand_codes(addr)

    def special_no_arg(self, opcode: int) -> str:
        if opcode == 0x24:
            return "<start/resolve combat or post-combat rewards>"
        if opcode == 0x3E:
            return "<drop current selected player>"
        return ""

    def menu(self, horizontal: bool) -> str:
        ops = self.load_ops(2 if horizontal else 3)
        loc = ops[0].word
        count = ops[1].word if horizontal else ops[2].word
        if count < 0 or count > 32:
            return f"{set_mem(loc, '<selected index from menu>')} MENU: <invalid item count {count}>"
        self.off -= 1
        self.load_ops(count)
        items = ", ".join(repr(self.strings[i + 1] if i + 1 < len(self.strings) else "") for i in range(count))
        return f"{set_mem(loc, '<selected index from menu>')} MENU: {items}"

    def on_goto(self, opcode: int) -> str:
        ops = self.load_ops(2)
        selector = ops[0].value(self)
        count = ops[1].word
        self.off -= 1
        targets = self.load_ops(count)
        words = []
        for op in targets:
            words.append(f"0x{op.word:04X}")
            self.add_addr(op.word, "ON GOTO" if opcode == 0x25 else "ON GOSUB")
        return f"{selector} of [{', '.join(words)}]"

    def surprise(self) -> str:
        start = self.off
        ops = self.load_ops(4)
        if any(not op.valid() for op in ops):
            self.off = start
            ops = self.load_ops(3)
        vals = [op.value(self) for op in ops]
        return "raw=(" + ", ".join(vals) + ")"

    def format_fixed(self, opcode: int, vals: list[str], ops: list["Operand"]) -> str:
        if opcode == 0x03:
            return f"Values: {vals[1]} == {vals[0]}"
        if opcode == 0x04:
            return set_mem(ops[2].word, f"{vals[0]} + {vals[1]}")
        if opcode == 0x05:
            return set_mem(ops[2].word, f"{vals[1]} - {vals[0]}")
        if opcode == 0x06:
            return f"{set_mem(ops[2].word, f'{vals[0]} / {vals[1]}')}; area2.division_remainder = {vals[0]} % {vals[1]}"
        if opcode == 0x07:
            return set_mem(ops[2].word, f"{vals[0]} * {vals[1]}")
        if opcode == 0x08:
            return set_mem(ops[1].word, f"random 1..{vals[0]}")
        if opcode == 0x09:
            return set_mem(ops[1].word, vals[0])
        if opcode == 0x0A:
            return f"index: {vals[0]}"
        if opcode == 0x0B:
            return f"monster_id: {vals[0]} copies: {vals[1]} cpic_id: {vals[2]}"
        if opcode == 0x0C:
            return f"sprite_id: {vals[0]} max_distance: {vals[1]} pic_id: {vals[2]}"
        if opcode == 0x0E:
            return f"block_id: {vals[0]}"
        if opcode == 0x0F:
            return set_mem(ops[1].word, "<user input number>")
        if opcode == 0x10:
            return f"{mem_name(ops[1].word)} = <user input string>"
        if opcode == 0x14:
            return f"Values: {vals[0]} == {vals[1]} && {vals[2]} == {vals[3]}"
        if opcode == 0x1D:
            return set_mem(ops[0].word, "<party strength>")
        if opcode == 0x1E:
            return f"check_party(raw=({', '.join(vals)}))"
        if opcode == 0x20:
            if not self.skip_next:
                self.stop = True
            return f"<load ECL {vals[0]} and exit>"
        if opcode == 0x21:
            return f"Load GEO {vals[0]} raw=({', '.join(vals)})"
        if opcode == 0x22:
            return f"zone: {vals[0]}, result: {vals[1]}"
        if opcode == 0x27:
            return "Treasure Cp:{0} Sl:{1} El:{2} Gl:{3} Pl:{4} Gems:{5} Jewel:{6} item:{7}".format(*vals)
        if opcode == 0x28:
            return f"rob(all_party: {vals[0]}, coin_percent: {vals[1]}, item: {vals[2]})"
        if opcode == 0x29:
            reactions = "[{0}]".format(", ".join(vals[4:9]))
            prompts = ", ".join(repr(self.strings[i]) for i in range(1, 4))
            return (
                f"sprite_id: {vals[0]} max_distance: {vals[1]} pic_id: {vals[2]} "
                f"{set_mem(ops[3].word, reactions)} prompts=({prompts}) "
                f"aux=({', '.join(vals[9:12])}) result=({vals[12]}, {vals[13]})"
            )
        if opcode == 0x2A:
            return set_mem(ops[2].word, f"{mem_name(ops[0].word)}[{vals[1]}]")
        if opcode == 0x2C:
            return f"<set {mem_name(ops[5].word)} from [{', '.join(vals[:5])}] mapped by parlay style>"
        if opcode == 0x2D:
            return engine_call_name(ops[0].word)
        if opcode == 0x2E:
            return damage_text(vals, ops)
        if opcode == 0x2F:
            return set_mem(ops[2].word, f"{vals[0]} & {vals[1]}")
        if opcode == 0x30:
            return set_mem(ops[2].word, f"{vals[0]} | {vals[1]}")
        if opcode == 0x32:
            return f"<find item type {vals[0]} in party>"
        if opcode == 0x34:
            return f"clock(slot: {vals[1]}, step: {vals[0]})"
        if opcode == 0x35:
            return f"{mem_name(ops[1].word)}[{vals[2]}] = {vals[0]}"
        if opcode == 0x36:
            return f"add_npc(npc_id: {vals[0]}, morale: {vals[1]})"
        if opcode == 0x37:
            return f"Load WALLDEF {vals[2]} {vals[1]} {vals[0]}"
        if opcode == 0x38:
            return program_name(ops[0].word)
        if opcode == 0x39:
            return f"<select player> {self.strings[1]!r}"
        if opcode == 0x3B:
            return f"<find party member with spell_id {vals[0]}> -> {mem_name(ops[1].word)}, {mem_name(ops[2].word)}"
        return "raw=(" + ", ".join(vals) + ")"


class Operand:
    def __init__(self, code: int, low: int):
        self.code = code
        self.low = low
        self.high: int | None = None
        self.word = low

    def set_high(self, high: int) -> None:
        self.high = high
        self.word = (high << 8) | self.low

    def valid(self) -> bool:
        return self.code in (0x00, 0x01, 0x02, 0x03, 0x05, 0x80, 0x81)

    def value(self, ecl: Ecl) -> str:
        if self.code == 0x00:
            return str(self.low)
        if self.code in (0x01, 0x03, 0x05, 0x80):
            return mem_name(self.word)
        if self.code in (0x02, 0x81):
            return str(self.word)
        return f"<invalid operand code 0x{self.code:02X}>"


def mem_name(loc: int) -> str:
    if 0x4B00 <= loc <= 0x4EFF:
        addr = (0x6A00 + loc * 2) & 0xFFFF
        if addr in AREA1_NAMES:
            return AREA1_NAMES[addr]
        if 0x200 <= addr <= 0x3FC and addr % 2 == 0:
            return f"area1.event_word_{addr:03X}"
        return AREA1_NAMES.get(addr, f"area1.word_{addr:03X}")
    if 0x7C00 <= loc <= 0x7FFF:
        addr = (0x800 + loc * 2) & 0xFFFF
        return AREA2_NAMES.get(addr, f"area2.word_{addr:03X}")
    if 0x7A00 <= loc <= 0x7BFF:
        return f"scratch.word_{((loc * 2) + 0x0C00) & 0xFFFF:04X}"
    if 0x8000 <= loc <= 0x9DFF:
        return f"ecl.byte_{(loc + BASE) & 0xFFFF:04X}"
    if loc < 0xBF68:
        return {
            0x00B1: "word_1D918",
            0x00FB: "word_1D914",
            0x00FC: "word_1D916",
            0x033D: "mapDirection",
            0x035F: "0",
            0x03DE: "word_1EE76",
            0x00B8: "word_1EE78",
            0x00B9: "word_1EE7A",
        }.get(loc, f"abs_{loc:04X}")
    rel = loc - 0xBF68
    return {
        0xE3: "mapPosX",
        0xE4: "mapPosY",
        0xE5: "mapDirection",
        0xF1: "byte_1EE91",
        0xF7: "byte_1EE91",
    }.get(rel, f"abs_{loc:04X}")


def set_mem(loc: int, value: str) -> str:
    return f"{mem_name(loc)} = {value}"


def engine_call_name(value: int) -> str:
    call_id = (value - 0x7FFF) & 0xFFFF
    names = {
        1: "setup_duel_vs_rolf_self",
        2: "setup_duel",
        0x4019: "reload_map_wall_type",
        0x401F: "walk_party_forward",
    }
    return names.get(call_id, f"raw: 0x{value:04X}, id: 0x{call_id:04X}")


def damage_text(vals: list[str], ops: list[Operand]) -> str:
    damage = f"{vals[1]}D{vals[2]}+{vals[3]}"
    if ops[0].code != 0 or ops[4].code != 0:
        return f"damage(raw=({', '.join(vals)}), dice: {damage})"

    mode = ops[0].word
    save_mode = ops[4].word
    if (mode & 0x80) == 0:
        return f"<do {mode} attacks of {damage} on random party member>"

    bonus_type = save_mode & 7
    if mode & 0x40:
        if (mode & 0x20) or (mode & 0x10):
            return f"<all party damaged for {damage}>"
        return f"<all party damaged for {damage} if individual save failed>"

    if save_mode & 0x80:
        if bonus_type == 0 or (mode & 0x10):
            return f"<selected player damaged for {damage}>"
        return f"<selected player damaged for {damage} if save failed>"

    if mode & 0x10:
        return f"<random party member damaged for {damage}>"
    return f"<random party member damaged for {damage} if save failed>"


def program_name(value: int) -> str:
    return {0: "StartGameMenu", 3: "PartyKilled", 8: "GameWon", 9: "TryEncamp"}.get(value, str(value))


def decompress_ecl_string(data: bytes) -> str:
    out = []
    state = 1
    last = 0
    for b in data:
        if state == 1:
            curr = (b >> 2) & 0x3F
            if curr:
                out.append(inflate_char(curr))
            state = 2
        elif state == 2:
            curr = ((last << 4) | (b >> 4)) & 0x3F
            if curr:
                out.append(inflate_char(curr))
            state = 3
        else:
            curr = ((last << 2) | (b >> 6)) & 0x3F
            if curr:
                out.append(inflate_char(curr))
            curr = b & 0x3F
            if curr:
                out.append(inflate_char(curr))
            state = 1
        last = b
    return "".join(out)


def inflate_char(value: int) -> str:
    if value <= 0x1F:
        value += 0x40
    return chr(value)


def instruction_length_from_text(_line: str) -> int:
    return 1


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("ecl_dax", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)
    summaries = []
    for block_id, block in read_dax(args.ecl_dax):
        ecl = Ecl(block)
        text = ecl.decode()
        out = args.out_dir / f"{args.ecl_dax.stem.lower()}_{block_id:03d}.ecl.txt"
        out.write_text(text, encoding="utf-8")
        summaries.append((block_id, len(block), len(ecl.done), len(ecl.unknowns), out.name))
    with (args.out_dir / "summary.tsv").open("w", encoding="utf-8") as f:
        f.write("block_id\tbytes\tdecoded_ops\tunknown_ops\tlisting\n")
        for row in summaries:
            f.write("\t".join(map(str, row)) + "\n")
    print(f"wrote {len(summaries)} ECL listings to {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
