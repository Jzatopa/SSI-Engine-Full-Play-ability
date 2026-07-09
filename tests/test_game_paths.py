from __future__ import annotations

from pathlib import Path

import pytest

from scripts.game_paths import ENV_VAR, HISTORICAL_DEFAULT_GAME_DIR, default_game_dir


def test_default_game_dir_falls_back_to_historical_path_when_unset(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.delenv(ENV_VAR, raising=False)

    assert default_game_dir() == HISTORICAL_DEFAULT_GAME_DIR


def test_default_game_dir_honors_env_var_override(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setenv(ENV_VAR, "/tmp/some-other-matrix-game-dir")

    assert default_game_dir() == Path("/tmp/some-other-matrix-game-dir")


def test_default_game_dir_treats_blank_override_as_unset(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.setenv(ENV_VAR, "")

    assert default_game_dir() == HISTORICAL_DEFAULT_GAME_DIR
