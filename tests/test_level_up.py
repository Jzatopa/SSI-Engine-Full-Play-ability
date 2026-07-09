"""Tests for experience and level-up system."""

from __future__ import annotations

from matrix_cubed.engine.character import CharacterRecord
from matrix_cubed.engine.level_up import (
    xp_for_next_level,
    can_level_up,
    apply_level_up,
    grant_xp,
)


def _hero(level: int = 1, xp: int = 0, hp: int = 30,
          career: int = 1, strength: int = 10, dexterity: int = 10,
          constitution: int = 10, intelligence: int = 10) -> CharacterRecord:
    return CharacterRecord(
        name="HERO", strength=strength, dexterity=dexterity,
        constitution=constitution, intelligence=intelligence,
        wisdom=10, charisma=10, tech=10,
        cur_strength=strength, cur_dexterity=dexterity,
        cur_constitution=constitution, cur_intelligence=intelligence,
        cur_wisdom=10, cur_charisma=10, cur_tech=10,
        gender=0, race=1, career=career, level=level, credits=0,
        experience=xp, age=25, hp=hp, skills=[0]*16,
    )


class TestXP:
    def test_level_1_needs_2000_xp(self):
        assert xp_for_next_level(1) == 2000

    def test_level_1_cannot_level_up_without_xp(self):
        char = _hero(level=1, xp=0)
        assert not can_level_up(char)

    def test_level_1_can_level_up_with_2000_xp(self):
        char = _hero(level=1, xp=2000)
        assert can_level_up(char)

    def test_grant_xp_adds_experience(self):
        char = _hero(level=1, xp=0)
        char, lines = grant_xp(char, 500)
        assert char.experience == 500
        assert "gains 500" in lines[0]

    def test_level_up_from_1_to_2(self):
        char = _hero(level=1, xp=2000)
        char, lines = grant_xp(char, 0)
        assert char.level == 2
        assert any("level 2" in l for l in lines)

    def test_level_up_gains_hp(self):
        char = _hero(level=1, xp=2000, hp=30)
        total = char.hp
        char, lines = grant_xp(char, 0)
        assert char.hp > total

    def test_double_level_up_if_enough_xp(self):
        char = _hero(level=1, xp=6000)
        char, lines = grant_xp(char, 0)
        assert char.level >= 2

    def test_medic_gains_less_hp(self):
        char_medic = _hero(level=1, xp=2000, hp=30, career=2)
        char_jock = _hero(level=1, xp=2000, hp=30, career=1)
        char_m, _ = grant_xp(char_medic, 0)
        char_j, _ = grant_xp(char_jock, 0)
        assert char_m.hp <= char_j.hp  # Medic: +6, Jock: +8
