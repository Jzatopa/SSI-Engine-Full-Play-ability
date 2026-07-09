"""Tests for SAVGAMA.DAT game state parser."""

import pytest
from pathlib import Path
from matrix_cubed.formats.game_state import (
    parse_game_state,
    diff_game_state,
    SAVGAMA_SIZE,
)


def test_parse_game_state_from_liveplay():
    """Parse a real SAVGAMA.DAT from the pre-combat live save."""
    pre_dir = Path("generated/liveplay/pre_combat")
    pre_dat = pre_dir / "SAVGAMA.DAT"
    if not pre_dat.exists():
        pytest.skip("pre-combat SAVGAMA.DAT not available")
    state = parse_game_state(pre_dat)
    assert state.position.area_id >= 0
    assert state.team_size >= 0
    assert state.credits >= 0


def test_parse_game_state_wrong_size():
    from pathlib import Path
    import tempfile
    with tempfile.NamedTemporaryFile(suffix=".tmp") as f:
        f.write(b"\x00" * 100)
        f.flush()
        with pytest.raises(ValueError, match="expected.*2901"):
            parse_game_state(Path(f.name))


def test_diff_no_changes():
    data = b"\x00" * SAVGAMA_SIZE
    diff = diff_game_state(data, data)
    assert diff["total_changed_bytes"] == 0
    assert diff["changes"] == []


def test_diff_one_byte():
    data = b"\x00" * SAVGAMA_SIZE
    changed = bytearray(data)
    changed[0x2C] = 0x42
    diff = diff_game_state(data, bytes(changed))
    assert diff["total_changed_bytes"] == 1
    assert diff["changes"][0]["offset"] == 0x2C
    assert diff["changes"][0]["before"] == 0
    assert diff["changes"][0]["after"] == 0x42
