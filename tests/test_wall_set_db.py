"""Tests for wall set lookups per map."""

from __future__ import annotations

from matrix_cubed.engine.wall_set_db import WallSetDB


def test_loads_wallsets():
    db = WallSetDB()
    assert db.count > 0


def test_caloris_has_set_5():
    db = WallSetDB()
    ws = db.get(17)
    assert ws == 5, f"Expected wall_set 5 for Caloris Space Port, got {ws}"


def test_luna_base_has_set_7():
    db = WallSetDB()
    ws = db.get(1)
    assert ws == 7, f"Expected wall_set 7 for Luna Base, got {ws}"


def test_asteroid_has_set_5():
    db = WallSetDB()
    ws = db.get(18)
    assert ws == 5


def test_unknown_map_returns_default():
    db = WallSetDB()
    ws = db.get(999)
    assert ws == 1  # Default


def test_list_maps():
    db = WallSetDB()
    maps = db.list_maps()
    assert len(maps) > 10
    assert all(isinstance(m[0], int) and isinstance(m[1], int) for m in maps)
