#!/usr/bin/env python3
"""Shared resolution for the local original Matrix Cubed game directory.

The original game files are intentionally never committed to this
repository (see CLAUDE.md: "Original game files stay outside the project
and must not be committed or bundled"). Every script/test that reads them
previously hardcoded the same fixed absolute path in a dozen-plus places,
which made the whole evidence pipeline non-portable across machines and
sandboxes.

This module keeps that exact historical default (so behavior on the
primary machine is unchanged) while letting it be overridden with the
``MATRIX_CUBED_GAME_DIR`` environment variable. Scripts/tests should import
``default_game_dir()`` instead of hardcoding the literal path.
"""

from __future__ import annotations

import os
from pathlib import Path

ENV_VAR = "MATRIX_CUBED_GAME_DIR"

HISTORICAL_DEFAULT_GAME_DIR = Path(
    "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX"
)


def default_game_dir() -> Path:
    """Return the local original Matrix Cubed game directory.

    Honors ``MATRIX_CUBED_GAME_DIR`` when set; otherwise falls back to the
    historical fixed path used throughout this project's scripts and tests.
    Neither branch invents or guesses a new location -- the override must be
    supplied explicitly by the caller's environment.
    """
    override = os.environ.get(ENV_VAR)
    return Path(override) if override else HISTORICAL_DEFAULT_GAME_DIR
