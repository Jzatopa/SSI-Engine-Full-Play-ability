"""Level-up and experience system for Matrix Cubed."""

from __future__ import annotations

import dataclasses

from matrix_cubed.engine.character import CharacterRecord


# Gold Box style XP thresholds
XP_PER_LEVEL: list[int] = [
    0,      # Level 1
    2000,   # Level 2
    4000,   # Level 3
    8000,   # Level 4
    16000,  # Level 5
    32000,  # Level 6
    64000,  # Level 7
    125000, # Level 8
    250000, # Level 9
    375000, # Level 10
]

HP_PER_LEVEL: dict[int, int] = {
    1: 8,   # Rocket Jock
    2: 6,   # Medic
}


def xp_for_next_level(current_level: int) -> int:
    """XP needed to reach the next level."""
    if current_level < 1:
        return 2000
    if current_level >= len(XP_PER_LEVEL) - 1:
        return 0
    return XP_PER_LEVEL[current_level]


def can_level_up(char: CharacterRecord) -> bool:
    """Check if a character has enough XP to level up."""
    needed = xp_for_next_level(char.level)
    return needed > 0 and char.experience >= needed


def apply_level_up(char: CharacterRecord) -> tuple[CharacterRecord, list[str]]:
    """Level up a character. Returns (updated_character, log_lines).

    CharacterRecord is frozen, so this creates a new instance.
    """
    lines: list[str] = []
    if not can_level_up(char):
        return char, lines

    d = {f.name: getattr(char, f.name) for f in dataclasses.fields(CharacterRecord)}
    d["level"] = char.level + 1
    hp_gain = HP_PER_LEVEL.get(char.career, 6)
    d["hp"] = char.hp + hp_gain
    lines.append(f"{char.name} reaches level {d['level']}!")
    lines.append(f"HP +{hp_gain} (now {d['hp']})")

    # Every 3 levels, boost a stat
    if d["level"] % 3 == 0:
        import random
        stats = ["strength", "dexterity", "constitution", "intelligence"]
        boost = random.choice(stats)
        current = d.get(boost, 10)
        if current < 18:
            d[boost] = current + 1
            d[f"cur_{boost}"] = current + 1
            lines.append(f"{boost.title()} +1 (now {current + 1})")

    return CharacterRecord(**d), lines


def grant_xp(char: CharacterRecord, amount: int) -> tuple[CharacterRecord, list[str]]:
    """Add XP and auto-level if thresholds reached. Returns (updated_char, log)."""
    lines: list[str] = []
    d = {f.name: getattr(char, f.name) for f in dataclasses.fields(CharacterRecord)}

    d["experience"] = char.experience + amount
    lines.append(f"{char.name} gains {amount} XP (total: {d['experience']})")

    char = CharacterRecord(**d)
    while can_level_up(char):
        char, level_lines = apply_level_up(char)
        lines.extend(level_lines)

    return char, lines
