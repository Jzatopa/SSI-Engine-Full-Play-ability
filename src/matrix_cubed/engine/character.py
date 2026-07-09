"""Character records, party roster, and stat helpers for Matrix Cubed.

Uses the decoded 259-byte character record format with ability scores,
skills, equipment candidates, and career/race helpers.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import IntEnum


@dataclass(frozen=True)
class CharacterRecord:
    """A decoded character record from WHO/SAV files (259 bytes)."""
    name: str
    strength: int
    dexterity: int
    constitution: int
    intelligence: int
    wisdom: int
    charisma: int
    tech: int
    cur_strength: int
    cur_dexterity: int
    cur_constitution: int
    cur_intelligence: int
    cur_wisdom: int
    cur_charisma: int
    cur_tech: int
    gender: int
    race: int
    career: int
    level: int
    credits: int
    experience: int
    age: int
    hp: int
    skills: list[int]
    weapon_index: int | None = None
    armor_index: int | None = None
    shield_index: int | None = None


class CharacterRoster:
    """Collection of all known character records."""

    def __init__(self) -> None:
        self._chars: list[CharacterRecord] = []

    def add(self, char: CharacterRecord) -> None:
        self._chars.append(char)

    def remove(self, name: str) -> bool:
        for i, c in enumerate(self._chars):
            if c.name == name:
                self._chars.pop(i)
                return True
        return False

    def get(self, name: str) -> CharacterRecord | None:
        for c in self._chars:
            if c.name == name:
                return c
        return None

    def replace(self, name: str, new_char: CharacterRecord) -> bool:
        """Replace the first matching record while preserving roster order."""
        for i, c in enumerate(self._chars):
            if c.name == name:
                self._chars[i] = new_char
                return True
        return False

    def list_all(self) -> list[CharacterRecord]:
        return list(self._chars)

    @property
    def count(self) -> int:
        return len(self._chars)


class Party:
    """Active adventuring party (1-10 characters)."""

    def __init__(self) -> None:
        self.members: list[CharacterRecord] = []
        self.member_hp: list[int] = []
        self.leader_index: int = 0

    def add(self, char: CharacterRecord) -> None:
        if len(self.members) < 10:
            self.members.append(char)
            self.member_hp.append(char.hp)

    def remove(self, name: str) -> bool:
        for i, m in enumerate(self.members):
            if m.name == name:
                self.members.pop(i)
                self.member_hp.pop(i)
                if self.leader_index >= len(self.members):
                    self.leader_index = max(0, len(self.members) - 1)
                return True
        return False

    def get(self, name: str) -> CharacterRecord | None:
        for m in self.members:
            if m.name == name:
                return m
        return None

    def swap(self, idx1: int, idx2: int) -> None:
        if 0 <= idx1 < len(self.members) and 0 <= idx2 < len(self.members):
            self.members[idx1], self.members[idx2] = self.members[idx2], self.members[idx1]
            self.member_hp[idx1], self.member_hp[idx2] = self.member_hp[idx2], self.member_hp[idx1]

    def set_leader(self, idx: int) -> None:
        if 0 <= idx < len(self.members):
            self.leader_index = idx

    def total_hp(self) -> int:
        return sum(self.member_hp)

    def total_credits(self) -> int:
        return self.members[0].credits if self.members else 0

    def is_alive(self, name: str) -> bool:
        for i, m in enumerate(self.members):
            if m.name == name:
                return self.member_hp[i] > 0
        return False

    def all_dead(self) -> bool:
        return all(hp <= 0 for hp in self.member_hp)


class Career(IntEnum):
    ROCKET_JOCK = 1
    MEDIC = 2

    @classmethod
    def display_name(cls, career_int: int) -> str:
        try:
            return cls(career_int).name.replace("_", " ").title()
        except ValueError:
            return f"Career {career_int}"

    @classmethod
    def skill_names(cls, career_int: int) -> list[str]:
        _skills = {
            1: ["Piloting", "Engineering", "Gunnery", "Navigation"],
            2: ["Medicine", "Surgery", "Pharmacology", "Diagnostics"],
        }
        return _skills.get(career_int, [])


class Race(IntEnum):
    TERRAN = 1
    MARTIAN = 2

    @classmethod
    def display_name(cls, race_int: int) -> str:
        try:
            return cls(race_int).name.replace("_", " ").title()
        except ValueError:
            return f"Race {race_int}"


# ── Stat helpers ────────────────────────────────────────────────────────────

def stat_modifier(stat: int) -> int:
    """Standard Gold Box ability modifier (clamped -3 to +3)."""
    return max(-3, min(3, (stat - 10) // 2))


def stat_string(stat: int) -> str:
    """Format a stat value with its modifier, e.g. '15 (+1)'."""
    mod = stat_modifier(stat)
    sign = "+" if mod >= 0 else ""
    return f"{stat} ({sign}{mod})"
