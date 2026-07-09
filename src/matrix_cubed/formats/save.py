from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


ABILITY_NAMES = ("str", "dex", "con", "int", "wis", "cha", "tech")
GENDER_LABELS = {0: "male", 1: "female"}
RACE_LABELS = {1: "terran", 2: "martian"}
CAREER_LABELS = {1: "rocket_jock", 2: "medic"}


@dataclass(frozen=True)
class CharacterWhoRecord:
    """Decoded fields from one 259-byte Matrix Cubed `.WHO` character record."""

    name: str
    ability_scores: dict[str, int]
    current_ability_scores: dict[str, int]
    race_id: int
    race: str | None
    gender_id: int
    gender: str | None
    career_id: int
    career: str | None
    level: int
    credits: int
    experience: int
    age: int
    hit_points_candidate: int


@dataclass(frozen=True)
class SavedCharacter:
    stem: str
    who_path: Path
    stf_path: Path | None
    who: CharacterWhoRecord
    stf_size: int | None


def parse_who_record(data: bytes) -> CharacterWhoRecord:
    if len(data) != 259:
        raise ValueError(f"expected 259-byte .WHO record, got {len(data)} bytes")

    name_len = data[0]
    if name_len > 15:
        raise ValueError(f"invalid .WHO name length {name_len}")
    name = data[1 : 1 + name_len].decode("ascii", errors="replace").rstrip("\x00 ")

    ability_scores = _ability_dict(data[0x10 : 0x10 + len(ABILITY_NAMES)])
    current_ability_scores = _ability_dict(data[0x17 : 0x17 + len(ABILITY_NAMES)])

    gender_id = data[0x26]
    race_id = data[0x27]
    career_id = data[0x28]

    return CharacterWhoRecord(
        name=name,
        ability_scores=ability_scores,
        current_ability_scores=current_ability_scores,
        race_id=race_id,
        race=RACE_LABELS.get(race_id),
        gender_id=gender_id,
        gender=GENDER_LABELS.get(gender_id),
        career_id=career_id,
        career=CAREER_LABELS.get(career_id),
        level=data[0x29],
        credits=_u32(data, 0x2B),
        experience=_u32(data, 0x2F),
        age=data[0x38],
        hit_points_candidate=data[0xE3],
    )


def read_saved_character(who_path: Path) -> SavedCharacter:
    who = parse_who_record(who_path.read_bytes())
    stf_path = who_path.with_suffix(".STF")
    stf_size = stf_path.stat().st_size if stf_path.exists() else None
    return SavedCharacter(
        stem=who_path.stem,
        who_path=who_path,
        stf_path=stf_path if stf_path.exists() else None,
        who=who,
        stf_size=stf_size,
    )


def _ability_dict(values: bytes) -> dict[str, int]:
    if len(values) != len(ABILITY_NAMES):
        raise ValueError(f"expected {len(ABILITY_NAMES)} ability bytes, got {len(values)}")
    return dict(zip(ABILITY_NAMES, values, strict=True))


def _u32(data: bytes, offset: int) -> int:
    return int.from_bytes(data[offset : offset + 4], "little")
