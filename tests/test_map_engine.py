"""Tests for the MapEngine tile-grid movement system."""

import pytest
from pathlib import Path
from matrix_cubed.engine.map_engine import (
    MapEngine,
    MapContext,
    Direction,
    MoveResult,
    _dir_offset,
    _project_view,
)
from matrix_cubed.formats.geo import GeoCell, GeoMap


def _make_floor(row: int, col: int) -> GeoCell:
    return GeoCell(row=row, col=col, north=0, east=0, south=0, west=0,
                   event_id=0, event_flag=False, door=0)


def _make_wall(row: int, col: int) -> GeoCell:
    return GeoCell(row=row, col=col, north=1, east=1, south=1, west=1,
                   event_id=0, event_flag=False, door=0)


def _make_event(row: int, col: int, event_id: int = 7) -> GeoCell:
    return GeoCell(row=row, col=col, north=0, east=0, south=0, west=0,
                   event_id=event_id, event_flag=True, door=0)


def _make_door(row: int, col: int) -> GeoCell:
    return GeoCell(row=row, col=col, north=0, east=0, south=0, west=0,
                   event_id=0, event_flag=False, door=1)


def _make_empty_map() -> GeoMap:
    cells = tuple(_make_floor(r, c) for r in range(16) for c in range(16))
    return GeoMap(map_id=1, name="test", cells=cells)


def _make_wall_map() -> GeoMap:
    """Map with walls around edges and a wall in the center."""
    cells_list = []
    for r in range(16):
        for c in range(16):
            if r == 0 or c == 0 or r == 15 or c == 15:
                cells_list.append(_make_wall(r, c))
            elif r == 4 and c == 4:
                cells_list.append(_make_wall(r, c))
            else:
                cells_list.append(_make_floor(r, c))
    return GeoMap(map_id=1, name="test_walls", cells=tuple(cells_list))


def _make_event_map() -> GeoMap:
    cells = tuple(
        _make_event(r, c, 7) if (r == 3 and c == 5) else _make_floor(r, c)
        for r in range(16) for c in range(16)
    )
    return GeoMap(map_id=1, name="test_events", cells=cells)


class TestDirectionOffset:
    def test_north(self):
        assert _dir_offset(Direction.NORTH) == (0, -1)

    def test_east(self):
        assert _dir_offset(Direction.EAST) == (1, 0)

    def test_south(self):
        assert _dir_offset(Direction.SOUTH) == (0, 1)

    def test_west(self):
        assert _dir_offset(Direction.WEST) == (-1, 0)


class TestProjectView:
    def test_north_facing(self):
        result = _project_view(5, 5, Direction.NORTH, 1, 0)
        assert result == (5, 4)

    def test_east_facing_offset(self):
        result = _project_view(5, 5, Direction.EAST, 2, -1)
        assert result == (7, 4)

    def test_south_facing(self):
        result = _project_view(5, 5, Direction.SOUTH, 1, 0)
        assert result == (5, 6)

    def test_west_facing(self):
        result = _project_view(5, 5, Direction.WEST, 1, 0)
        assert result == (4, 5)


class TestMapEngine:
    def test_move_north_free(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.NORTH)
        eng.set_context(ctx)
        result = eng.move_north()
        assert result.blocked is False
        assert result.x == 3 and result.y == 2

    def test_move_east_free(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.EAST)
        eng.set_context(ctx)
        result = eng.move_east()
        assert result.blocked is False
        assert result.x == 4 and result.y == 3

    def test_blocked_by_wall(self):
        eng = MapEngine()
        geo = _make_wall_map()
        # (r=4, c=4) = wall. Stand at (3, 4) facing east.
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=4, facing=Direction.EAST)
        eng.set_context(ctx)
        result = eng.move_east()  # (4, 4) = row 4 col 4 = wall
        assert result.blocked is True

    def test_blocked_by_border_wall(self):
        eng = MapEngine()
        geo = _make_wall_map()
        # Stand next to a border wall
        ctx = MapContext(geo_map=geo, map_id=1, player_x=5, player_y=1, facing=Direction.NORTH)
        eng.set_context(ctx)
        result = eng.move_north()  # going to row 0 = wall
        assert result.blocked is True

    def test_move_south(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.SOUTH)
        eng.set_context(ctx)
        result = eng.move_south()
        assert result.blocked is False
        assert result.x == 3 and result.y == 4

    def test_move_west(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.WEST)
        eng.set_context(ctx)
        result = eng.move_west()
        assert result.blocked is False
        assert result.x == 2 and result.y == 3

    def test_turn_left(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.NORTH)
        eng.set_context(ctx)
        eng.turn_left()
        assert ctx.facing == Direction.WEST
        eng.turn_left()
        assert ctx.facing == Direction.SOUTH
        eng.turn_left()
        assert ctx.facing == Direction.EAST
        eng.turn_left()
        assert ctx.facing == Direction.NORTH

    def test_turn_right(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.NORTH)
        eng.set_context(ctx)
        eng.turn_right()
        assert ctx.facing == Direction.EAST
        eng.turn_right()
        assert ctx.facing == Direction.SOUTH
        eng.turn_right()
        assert ctx.facing == Direction.WEST
        eng.turn_right()
        assert ctx.facing == Direction.NORTH

    def test_visited_tiles(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.NORTH)
        ctx.visited_tiles.add((3, 3))
        eng.set_context(ctx)
        assert (3, 3) in ctx.visited_tiles
        eng.move_north()
        assert (3, 2) in ctx.visited_tiles
        assert len(ctx.visited_tiles) == 2

    def test_overhead_view_dimensions(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=0, player_y=0, facing=Direction.NORTH)
        eng.set_context(ctx)
        view = eng.get_overhead_view()
        assert len(view) == 16
        assert len(view[0]) == 16

    def test_get_cell_in_bounds(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.NORTH)
        eng.set_context(ctx)
        cell = eng.get_cell(1, 1)
        assert cell is not None

    def test_get_cell_out_of_bounds(self):
        eng = MapEngine()
        geo = _make_empty_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=3, facing=Direction.NORTH)
        eng.set_context(ctx)
        cell = eng.get_cell(99, 99)
        assert cell is None

    def test_event_tile_triggers_event(self):
        eng = MapEngine()
        geo = _make_event_map()
        ctx = MapContext(geo_map=geo, map_id=1, player_x=5, player_y=3, facing=Direction.NORTH)
        eng.set_context(ctx)
        # Move south to (5, 4) which is a floor tile
        ctx.facing = Direction.SOUTH
        result = eng.move_south()
        assert result.blocked is False
        # Move west to (4, 4) which is floor
        ctx.facing = Direction.WEST
        result = eng.move_west()
        assert result.blocked is False
        # Move north to (4, 3) which is event tile at row=3, col=5... 
        # Actually the event is at (r=3, c=5). Let me start at a better position.
        ctx2 = MapContext(geo_map=geo, map_id=1, player_x=5, player_y=4, facing=Direction.NORTH)
        eng.set_context(ctx2)
        # Moving north from (5, 4) -> (5, 3) which is row 3, col 5 = event
        result = eng.move_north()
        assert result.blocked is False
        assert result.event_triggered is True
        assert result.event_id == 7

    def test_door_blocked_when_closed(self):
        eng = MapEngine()
        cells = tuple(
            _make_door(r, c) if (r == 2 and c == 3) else _make_floor(r, c)
            for r in range(16) for c in range(16)
        )
        geo = GeoMap(map_id=1, name="test_door", cells=cells)
        ctx = MapContext(geo_map=geo, map_id=1, player_x=3, player_y=2, facing=Direction.WEST)
        eng.set_context(ctx)
        # Door at (r=2, c=3) = x=3, y=2. Player at x=3, y=2 is ON the door
        # Actually let me start adjacent: player at (2, 2), door at (3, 2)  
        ctx2 = MapContext(geo_map=geo, map_id=1, player_x=2, player_y=2, facing=Direction.EAST)
        eng.set_context(ctx2)
        result = eng.move_east()
        assert result.blocked is True  # door closed

    def test_door_unblocked_when_open(self):
        eng = MapEngine()
        cells = tuple(
            _make_door(r, c) if (r == 2 and c == 3) else _make_floor(r, c)
            for r in range(16) for c in range(16)
        )
        geo = GeoMap(map_id=1, name="test_door", cells=cells)
        ctx = MapContext(geo_map=geo, map_id=1, player_x=2, player_y=2, facing=Direction.EAST,
                         door_states={(3, 2): True})
        eng.set_context(ctx)
        result = eng.move_east()
        assert result.blocked is False  # door open
