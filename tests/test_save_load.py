"""Tests for save/load roundtrip with game state."""

from __future__ import annotations

from pathlib import Path

from matrix_cubed.engine.save_load import load_game_state, save_game
from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.runtime import GameState
from matrix_cubed.engine.character import CharacterRecord


def _char() -> CharacterRecord:
    return CharacterRecord(
        name="HERO", strength=10, dexterity=10, constitution=10,
        intelligence=10, wisdom=10, charisma=10, tech=10,
        cur_strength=10, cur_dexterity=10, cur_constitution=10,
        cur_intelligence=10, cur_wisdom=10, cur_charisma=10, cur_tech=10,
        gender=0, race=1, career=1, level=1, credits=100,
        experience=0, age=25, hp=30, skills=[0]*16,
    )


def test_save_and_load_game_state(tmp_path: Path):
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_char())
    gs.party.credits = 500

    save_game(tmp_path, gs)
    loaded = load_game_state(tmp_path)
    assert loaded["map_id"] == 17
    assert loaded["credits"] == 500  # char's credits initially set
    assert loaded["roster"].count >= 1


def test_save_and_load_character_stats(tmp_path: Path):
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, 17)
    gs.add_character(_char())
    save_game(tmp_path, gs)
    loaded = load_game_state(tmp_path)
    char = loaded["roster"].get("HERO")
    assert char is not None
    assert char.credits == 100
    assert char.hp == 30


def test_load_nonexistent_raises():
    from pathlib import Path
    try:
        load_game_state(Path("/nonexistent/path"))
        assert False, "Should have raised"
    except FileNotFoundError:
        pass
