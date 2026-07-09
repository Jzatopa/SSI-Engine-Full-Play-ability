"""Save/load runtime state to Matrix Cubed binary formats.

Writes .WHO (character), .STF (skills), .SAV (active party),
and SAVGAMA.DAT (game state) files from the running GameState.
"""

from __future__ import annotations

from pathlib import Path
from typing import Any

from matrix_cubed.engine.character import CharacterRecord, CharacterRoster
from matrix_cubed.engine.runtime import GameState
from matrix_cubed.formats.save import (
    ABILITY_NAMES,
    RACE_LABELS,
    CAREER_LABELS,
    GENDER_LABELS,
    parse_who_record,
    read_saved_character,
)
from matrix_cubed.formats.game_state import SAVGAMA_SIZE

# ── Binary format writers ─────────────────────────────────────────────────

def _char_to_who_bytes(char: CharacterRecord) -> bytes:
    """Serialize a CharacterRecord into a 259-byte .WHO record."""
    buf = bytearray(259)

    # Name: length prefix + ASCII + null-padded to 15 chars
    name_bytes = char.name.encode("ascii", errors="replace")[:15]
    buf[0] = len(name_bytes)
    buf[1:1 + len(name_bytes)] = name_bytes

    # Ability scores at offset 0x10 (7 bytes: str,dex,con,int,wis,cha,tech)
    _write_abilities(buf, 0x10, char)
    # Current ability scores at offset 0x17
    _write_current(buf, 0x17, char)

    # Gender at 0x26
    buf[0x26] = char.gender
    # Race at 0x27
    buf[0x27] = char.race
    # Career at 0x28
    buf[0x28] = char.career
    # Level at 0x29
    buf[0x29] = char.level
    # Credits at 0x2B (4 bytes LE)
    buf[0x2B:0x2B+4] = char.credits.to_bytes(4, "little")
    # Experience at 0x2F (4 bytes LE)
    buf[0x2F:0x2F+4] = char.experience.to_bytes(4, "little")
    # Age at 0x38
    buf[0x38] = char.age
    # HP candidate at 0xE3
    buf[0xE3] = min(255, char.hp)

    return bytes(buf)


def _char_to_stf_bytes(char: CharacterRecord) -> bytes:
    """Serialize a CharacterRecord into a 124-byte .STF skill record."""
    buf = bytearray(124)

    # Skills at offset 0x0C-0x1B (16 bytes)
    for i, skill_val in enumerate(char.skills[:16]):
        buf[0x0C + i] = skill_val & 0xFF

    # Equipment candidates at 0x05-0x07
    if char.weapon_index is not None:
        buf[0x06] = char.weapon_index & 0xFF
    if char.armor_index is not None:
        buf[0x05] = char.armor_index & 0xFF
    if char.shield_index is not None:
        buf[0x07] = char.shield_index & 0xFF

    return bytes(buf)


def _write_abilities(buf: bytearray, offset: int, char: CharacterRecord) -> None:
    vals = (char.strength, char.dexterity, char.constitution,
            char.intelligence, char.wisdom, char.charisma, char.tech)
    for i, v in enumerate(vals):
        buf[offset + i] = v & 0xFF


def _write_current(buf: bytearray, offset: int, char: CharacterRecord) -> None:
    vals = (char.cur_strength, char.cur_dexterity, char.cur_constitution,
            char.cur_intelligence, char.cur_wisdom, char.cur_charisma, char.cur_tech)
    for i, v in enumerate(vals):
        buf[offset + i] = v & 0xFF


# ── SAVGAMA.DAT writer ────────────────────────────────────────────────────

def _game_state_to_dat_bytes(gs: GameState, template: bytes | None = None) -> bytes:
    """Build a 2901-byte SAVGAMA.DAT from the current GameState.

    A template (previous save) is used to preserve unknown fields.
    Without a template, we build from scratch with decoded fields.
    """
    if template is not None and len(template) == SAVGAMA_SIZE:
        buf = bytearray(template)
    else:
        buf = bytearray(SAVGAMA_SIZE)

    # Area ID at 0x00 (LE u16)
    buf[0x00:0x02] = gs.map_id.to_bytes(2, "little")
    # Position at 0x02-0x04
    _facing_map = {"north": 0, "east": 1, "south": 2, "west": 3}
    buf[0x02] = gs.col & 0xFF
    buf[0x03] = gs.row & 0xFF
    buf[0x04] = _facing_map.get(gs.facing, 0) & 0xFF
    # Credits at 0x2C
    buf[0x2C:0x30] = gs.party.credits.to_bytes(4, "little")

    return bytes(buf)


# ── High-level API ─────────────────────────────────────────────────────────

def save_game(output_dir: Path, gs: GameState) -> dict[str, Path]:
    """Write the full game state to save files in output_dir.

    Returns dict mapping logical name to file path.
    """
    output_dir.mkdir(parents=True, exist_ok=True)
    results: dict[str, Path] = {}

    # Write individual character files (.WHO + .STF)
    for char in gs.roster.list_all():
        stem = char.name[:8].upper() or "CHAR"
        who_path = output_dir / f"{stem}.WHO"
        who_path.write_bytes(_char_to_who_bytes(char))
        stf_path = output_dir / f"{stem}.STF"
        stf_path.write_bytes(_char_to_stf_bytes(char))
        results[f"who:{stem}"] = who_path
        results[f"stf:{stem}"] = stf_path

    # Write active party file (CHRDATA1.SAV + CHRDATA1.STF for first member)
    if gs.active_party.members:
        char = gs.active_party.members[0]
        sav_path = output_dir / "CHRDATA1.SAV"
        sav_path.write_bytes(_char_to_who_bytes(char))
        stf_path = output_dir / "CHRDATA1.STF"
        stf_path.write_bytes(_char_to_stf_bytes(char))
        results["chrp:SAV"] = sav_path
        results["chrp:STF"] = stf_path

    # Write game state file
    dat_path = output_dir / "SAVGAMA.DAT"
    dat_path.write_bytes(_game_state_to_dat_bytes(gs))
    results["savgama"] = dat_path

    return results


def load_characters(save_dir: Path) -> CharacterRoster:
    """Load .WHO files from a save directory into a CharacterRoster."""
    from matrix_cubed.engine.character import CharacterRecord

    roster = CharacterRoster()
    for who_path in sorted(save_dir.glob("*.WHO")):
        try:
            saved = read_saved_character(who_path)
            record = _who_to_character_record(saved)
            roster.add(record)
        except (ValueError, OSError, KeyError, IndexError) as exc:
            import sys
            print(f"load_characters: skipping {who_path.name}: {exc}", file=sys.stderr)
    return roster



def load_game_state(save_dir: Path) -> dict:
    """Load saved game state from a save directory.
    Returns dict with map_id, row, col, facing, credits, roster.
    """
    from matrix_cubed.formats.game_state import parse_game_state
    dat_path = save_dir / "SAVGAMA.DAT"
    if not dat_path.exists():
        raise FileNotFoundError(f"No SAVGAMA.DAT in {save_dir}")
    parsed = parse_game_state(dat_path)
    roster = load_characters(save_dir)
    _face_map = {0: "north", 1: "east", 2: "south", 3: "west"}
    return {
        "map_id": parsed.position.area_id,
        "row": parsed.position.y,
        "col": parsed.position.x,
        "facing": _face_map.get(parsed.position.facing, "south"),
        "credits": parsed.credits,
        "roster": roster,
    }

def _who_to_character_record(saved: Any) -> CharacterRecord:
    """Convert a parsed .WHO record (from formats.save) to our CharacterRecord."""
    who = saved.who
    ab = who.ability_scores
    cur = who.current_ability_scores
    return CharacterRecord(
        name=who.name,
        strength=ab.get("str", 10), dexterity=ab.get("dex", 10),
        constitution=ab.get("con", 10), intelligence=ab.get("int", 10),
        wisdom=ab.get("wis", 10), charisma=ab.get("cha", 10), tech=ab.get("tech", 10),
        cur_strength=cur.get("str", 10), cur_dexterity=cur.get("dex", 10),
        cur_constitution=cur.get("con", 10), cur_intelligence=cur.get("int", 10),
        cur_wisdom=cur.get("wis", 10), cur_charisma=cur.get("cha", 10),
        cur_tech=cur.get("tech", 10),
        gender=who.gender_id, race=who.race_id, career=who.career_id,
        level=who.level, credits=who.credits, experience=who.experience,
        age=who.age, hp=who.hit_points_candidate, skills=[0] * 16,
    )
