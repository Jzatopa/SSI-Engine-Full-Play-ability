"""Tests for GameState multi-character party integration."""

from __future__ import annotations

from pathlib import Path

from matrix_cubed.engine.runtime import GameState
from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.character import CharacterRecord


def _make_char(name: str, hp: int = 30, career: int = 1) -> CharacterRecord:
    return CharacterRecord(
        name=name, strength=10, dexterity=10, constitution=10,
        intelligence=10, wisdom=10, charisma=10, tech=10,
        cur_strength=10, cur_dexterity=10, cur_constitution=10,
        cur_intelligence=10, cur_wisdom=10, cur_charisma=10, cur_tech=10,
        gender=0, race=1, career=career, level=1, credits=0,
        experience=0, age=25, hp=hp, skills=[0]*16,
    )


def test_game_state_accepts_characters():
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_make_char("TST1"))
    gs.add_character(_make_char("TST2"))
    assert gs.roster.count == 2
    assert len(gs.active_party.members) == 2


def test_first_character_hp_matches_current_hp():
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_make_char("TST1", hp=42))
    assert gs.current_hp() == 42
    assert gs.active_party.member_hp[0] == 42


def test_current_hp_falls_back_to_shared():
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.party.hp = 100
    assert gs.current_hp() == 100  # no active party members


def test_snapshot_contains_active_party():
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_make_char("LEADER"))
    snap = gs.snapshot()
    assert "active_party" in snap
    assert snap["active_party"]["count"] == 1
    assert snap["active_party"]["members"] == ["LEADER"]


def test_add_credits_updates_frozen_character_record():
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_make_char("LEADER"))

    gs.add_credits(25)

    assert gs.party.credits == 25
    assert gs.current_credits() == 25
    assert gs.active_party.members[0].credits == 25
    assert gs.roster.get("LEADER").credits == 25


def test_set_credits_syncs_loaded_savgama_credits_to_active_character():
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_make_char("LEADER"))

    gs.set_credits(500)

    assert gs.party.credits == 500
    assert gs.current_credits() == 500
    assert gs.active_party.members[0].credits == 500
    assert gs.roster.get("LEADER").credits == 500
