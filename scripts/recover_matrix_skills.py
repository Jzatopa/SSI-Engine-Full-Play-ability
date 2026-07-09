#!/usr/bin/env python3
"""Recover Matrix Cubed skill ids, names, and save-record values.

Evidence boundary:
- START.EXE contains the visible skill-name Pascal strings.
- GAME.OVR decompiled functions read/write skill values at character offset
  0x4C + skill_id for skill ids 1..0x54.
- Local .WHO/.SAV samples validate non-zero values at those offsets.
"""

from __future__ import annotations

import csv
import json
from dataclasses import asdict, dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GAME_DIR = Path("/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX")
START_EXE = GAME_DIR / "START.EXE"
OUT_DIR = ROOT / "generated" / "skill_recovery" / "2026-07-08"
SKILL_HEADER_OFFSET = 0xF321
MAX_SKILL_ID = 0x54
WHO_SKILL_BASE = 0x4C


@dataclass(frozen=True)
class SkillName:
    skill_id: int
    who_offset: int | None
    start_exe_offset: int
    text: str


@dataclass(frozen=True)
class CharacterSkillValue:
    sample: str
    source_path: str
    name: str
    race_id: int
    gender_id: int
    career_id: int
    skill_id: int
    who_offset: int
    skill_name: str
    value: int


def pascal_strings(data: bytes, start: int, end: int) -> list[tuple[int, str]]:
    strings: list[tuple[int, str]] = []
    last_string_end = -1
    for offset in range(start, end):
        length = data[offset]
        if not (3 <= length <= 24):
            continue
        if offset <= last_string_end or offset + 1 + length > len(data):
            continue
        raw = data[offset + 1 : offset + 1 + length]
        if all(32 <= value < 127 for value in raw) and any(65 <= value <= 122 for value in raw):
            strings.append((offset, raw.decode("ascii")))
            last_string_end = offset + length
    return strings


def recover_skill_names() -> list[SkillName]:
    data = START_EXE.read_bytes()
    strings = pascal_strings(data, SKILL_HEADER_OFFSET, 0xFA80)
    if len(strings) < MAX_SKILL_ID + 1:
        raise RuntimeError(f"expected at least {MAX_SKILL_ID + 1} skill/header strings, got {len(strings)}")

    names: list[SkillName] = []
    for skill_id, (offset, text) in enumerate(strings[: MAX_SKILL_ID + 1]):
        names.append(
            SkillName(
                skill_id=skill_id,
                who_offset=None if skill_id == 0 else WHO_SKILL_BASE + skill_id,
                start_exe_offset=offset,
                text=text,
            )
        )
    return names


def sample_paths() -> list[Path]:
    paths: set[Path] = set()
    for directory in [
        ROOT / "generated/liveplay/first_map_capture/pre_saves",
        ROOT / "generated/liveplay/pre_combat",
        ROOT / "generated/liveplay/post_combat",
        GAME_DIR / "SAVE",
    ]:
        if not directory.exists():
            continue
        paths.update(directory.glob("*.WHO"))
        paths.update(directory.glob("*.SAV"))
    return sorted(paths)


def decode_name(data: bytes) -> str:
    name_len = data[0]
    if name_len > 15:
        return "<invalid-name>"
    return data[1 : 1 + name_len].decode("ascii", errors="replace").rstrip("\x00 ")


def recover_sample_values(skill_names: list[SkillName]) -> list[CharacterSkillValue]:
    values: list[CharacterSkillValue] = []
    for path in sample_paths():
        data = path.read_bytes()
        if len(data) != 259:
            continue
        for skill in skill_names:
            if skill.skill_id == 0 or skill.who_offset is None:
                continue
            value = data[skill.who_offset]
            if value == 0:
                continue
            values.append(
                CharacterSkillValue(
                    sample=path.stem,
                    source_path=str(path.relative_to(ROOT) if path.is_relative_to(ROOT) else path),
                    name=decode_name(data),
                    race_id=data[0x27],
                    gender_id=data[0x26],
                    career_id=data[0x28],
                    skill_id=skill.skill_id,
                    who_offset=skill.who_offset,
                    skill_name=skill.text,
                    value=value,
                )
            )
    return values


def write_tsv(path: Path, rows: list[dict[str, object]], fieldnames: list[str]) -> None:
    with path.open("w", newline="") as fh:
        writer = csv.DictWriter(fh, delimiter="\t", fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def write_markdown(skill_names: list[SkillName], values: list[CharacterSkillValue]) -> None:
    lines = [
        "# Matrix Cubed Skill Recovery - 2026-07-08",
        "",
        "Evidence boundary: skill names are extracted from START.EXE Pascal strings; "
        "skill value offsets are derived from GAME.OVR decompiled accessors that use "
        "`character + 0x4C + skill_id`; sample values come from local 259-byte `.WHO`/`.SAV` files.",
        "",
        "## Skill Ids",
        "",
        "| Skill ID | WHO Offset | START.EXE Offset | Name |",
        "|---:|---:|---:|---|",
    ]
    for skill in skill_names:
        if skill.skill_id == 0:
            continue
        lines.append(
            f"| {skill.skill_id} / 0x{skill.skill_id:02X} | "
            f"0x{skill.who_offset:02X} | 0x{skill.start_exe_offset:05X} | {skill.text} |"
        )

    lines.extend(["", "## Non-Zero Sample Values", "", "| Sample | Career ID | Skill | Value |", "|---|---:|---|---:|"])
    for value in values:
        lines.append(f"| {value.sample} ({value.name}) | {value.career_id} | {value.skill_name} | {value.value} |")

    (OUT_DIR / "README.md").write_text("\n".join(lines) + "\n")


def main() -> int:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    skill_names = recover_skill_names()
    sample_values = recover_sample_values(skill_names)

    (OUT_DIR / "skill_names.json").write_text(json.dumps([asdict(row) for row in skill_names], indent=2) + "\n")
    (OUT_DIR / "sample_skill_values.json").write_text(
        json.dumps([asdict(row) for row in sample_values], indent=2) + "\n"
    )
    write_tsv(
        OUT_DIR / "skill_names.tsv",
        [asdict(row) for row in skill_names],
        ["skill_id", "who_offset", "start_exe_offset", "text"],
    )
    write_tsv(
        OUT_DIR / "sample_skill_values.tsv",
        [asdict(row) for row in sample_values],
        ["sample", "source_path", "name", "race_id", "gender_id", "career_id", "skill_id", "who_offset", "skill_name", "value"],
    )
    write_markdown(skill_names, sample_values)
    print(f"wrote {len(skill_names) - 1} skills and {len(sample_values)} non-zero sample values to {OUT_DIR}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
