"""Map engine: tile grid movement, collision, event triggers for Matrix Cubed."""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import IntEnum
from pathlib import Path
from typing import Callable

from matrix_cubed.formats.geo import GeoCell, GeoMap
from matrix_cubed.data.repository import ReconstructedData


class Direction(IntEnum):
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3


# Gold Box tile types inferred from wallset/geo data
TILE_WALL = 0x00       # Impassable wall
TILE_FLOOR = 0x01      # Walkable floor
TILE_DOOR = 0x02       # Door (may be openable)
TILE_EXIT = 0x03       # Area transition
TILE_EVENT = 0x04      # Event-triggering tile
TILE_OBJECT = 0x05     # Object/interactive tile
TILE_STAIR_UP = 0x06   # Stairs up
TILE_STAIR_DOWN = 0x07 # Stairs down
TILE_WATER = 0x08      # Water/hazard
TILE_WALL_N = 0x09     # North-facing wall texture
TILE_WALL_E = 0x0A     # East-facing wall texture
TILE_WALL_S = 0x0B     # South-facing wall texture
TILE_WALL_W = 0x0C     # West-facing wall texture
TILE_VOID = 0xFF       # Off-map boundary


@dataclass
class MoveResult:
    """Result of a movement attempt."""
    x: int
    y: int
    direction: Direction
    blocked: bool
    tile_type: int
    tile_value: int
    event_triggered: bool
    event_id: int | None = None
    transition: tuple[int, int, int] | None = None  # (area_id, x, y)


@dataclass
class MapContext:
    """Holds the current map and camera state."""
    geo_map: GeoMap
    map_id: int
    player_x: int
    player_y: int
    facing: Direction
    visited_tiles: set[tuple[int, int]] = field(default_factory=set)
    event_states: dict[int, bool] = field(default_factory=dict)  # event_id -> fired
    door_states: dict[tuple[int, int], bool] = field(default_factory=dict)  # tile -> open


class MapEngine:
    """Tile-grid map engine with collision, events, and transitions."""
    MAP_WIDTH = 16
    MAP_HEIGHT = 16

    def __init__(self, repo: ReconstructedData | None = None):
        self._maps: dict[int, GeoMap] = {}
        self._ecl_data: dict[int, dict] = {}
        self.repo = repo
        self.on_event_trigger: Callable[[int, int], None] | None = None
        self._context: MapContext | None = None

    @property
    def context(self) -> MapContext | None:
        return self._context

    def load_map(self, map_id: int) -> GeoMap | None:
        """Load a GEO map into the engine."""
        if map_id in self._maps:
            return self._maps[map_id]
        if not self.repo:
            return None

        ecl = self.repo.find_ecl(map_id)
        if not ecl:
            return None

        geo = ecl.get("geo")
        if not geo:
            return None

        self._maps[map_id] = geo
        self._ecl_data[map_id] = ecl
        return geo

    def set_context(self, ctx: MapContext) -> None:
        self._context = ctx

    def start_map(self, map_id: int, x: int, y: int, facing: Direction) -> MapContext | None:
        """Initialize a new map context at the given position."""
        geo = self.load_map(map_id)
        if not geo:
            return None

        ctx = MapContext(
            geo_map=geo,
            map_id=map_id,
            player_x=x,
            player_y=y,
            facing=facing,
            visited_tiles={(x, y)},
        )
        self._context = ctx
        return ctx

    def _get_tile_type(self, x: int, y: int, cell: GeoCell | None) -> int:
        """Classify a tile based on cell properties."""
        if cell is None:
            return TILE_VOID
        if cell.walls != (0, 0, 0, 0):
            return TILE_WALL
        if cell.door:
            return TILE_DOOR
        if cell.event_id and cell.event_flag:
            return TILE_EVENT
        if cell.event_id and not cell.event_flag:
            return TILE_EXIT
        return TILE_FLOOR

    def get_cell(self, x: int, y: int) -> GeoCell | None:
        """Get the cell at map coordinates, or None if out of bounds."""
        if not self._context:
            return None
        geo = self._context.geo_map
        try:
            return geo.cell_at(y, x)
        except (IndexError, ValueError):
            return None

    def try_move(self, direction: Direction) -> MoveResult:
        """Attempt to move the player in the given direction."""
        if not self._context:
            raise RuntimeError("No map context set")

        dx, dy = _dir_offset(direction)
        nx = self._context.player_x + dx
        ny = self._context.player_y + dy

        cell = self.get_cell(nx, ny)
        tile_type = self._get_tile_type(nx, ny, cell)
        tile_value = cell.event_id if cell else 0
        blocked = False
        event_triggered = False
        event_id = None
        transition = None

        if tile_type == TILE_WALL or tile_type == TILE_VOID:
            blocked = True
        elif tile_type == TILE_DOOR:
            door_open = self._context.door_states.get((nx, ny), False)
            if not door_open:
                blocked = True
            else:
                self._context.player_x = nx
                self._context.player_y = ny
        elif tile_type == TILE_EXIT:
            transition = (tile_value, nx, ny) if tile_value else None
            self._context.player_x = nx
            self._context.player_y = ny
        elif tile_type == TILE_EVENT:
            self._context.player_x = nx
            self._context.player_y = ny
            event_triggered = True
            event_id = tile_value if tile_value else None
        else:
            self._context.player_x = nx
            self._context.player_y = ny

        self._context.facing = direction
        self._context.visited_tiles.add((self._context.player_x, self._context.player_y))

        return MoveResult(
            x=self._context.player_x,
            y=self._context.player_y,
            direction=direction,
            blocked=blocked,
            tile_type=tile_type,
            tile_value=tile_value,
            event_triggered=event_triggered,
            event_id=event_id,
            transition=transition,
        )

    def move_north(self) -> MoveResult:
        return self.try_move(Direction.NORTH)

    def move_east(self) -> MoveResult:
        return self.try_move(Direction.EAST)

    def move_south(self) -> MoveResult:
        return self.try_move(Direction.SOUTH)

    def move_west(self) -> MoveResult:
        return self.try_move(Direction.WEST)

    def turn_left(self) -> None:
        if self._context:
            self._context.facing = Direction((self._context.facing - 1) % 4)

    def turn_right(self) -> None:
        if self._context:
            self._context.facing = Direction((self._context.facing + 1) % 4)

    def get_visible_cells(self, view_range: int = 10) -> list[list[GeoCell | None]]:
        """Get the visible map cells for first-person rendering."""
        if not self._context:
            return []

        cells: list[list[GeoCell | None]] = []
        for row in range(view_range):
            cells.append([])
            for col in range(-view_range // 2, view_range // 2 + 1):
                world_x, world_y = _project_view(
                    self._context.player_x,
                    self._context.player_y,
                    self._context.facing,
                    row + 1,
                    col,
                )
                cells[-1].append(self.get_cell(world_x, world_y))
        return cells

    def get_overhead_view(self) -> list[list[int]]:
        """Get the full overhead tile grid for minimap/overhead rendering."""
        if not self._context:
            return []
        geo = self._context.geo_map
        grid: list[list[int]] = []
        for row in range(16):
            grid_row: list[int] = []
            for col in range(16):
                cell = geo.cell_at(row, col)
                if cell is None:
                    grid_row.append(0xFF)
                elif cell.walls != (0, 0, 0, 0):
                    grid_row.append(0)  # wall
                elif cell.door:
                    grid_row.append(2)  # door
                elif cell.event_id:
                    grid_row.append(4)  # event
                else:
                    grid_row.append(1)  # floor
            grid.append(grid_row)
        return grid

    def toggle_door(self, x: int, y: int) -> bool | None:
        """Toggle a door at (x, y). Returns new state or None if not a door."""
        if not self._context:
            return None
        cell = self.get_cell(x, y)
        tile_type = self._get_tile_type(x, y, cell)
        if tile_type != TILE_DOOR:
            return None
        new_state = not self._context.door_states.get((x, y), False)
        self._context.door_states[(x, y)] = new_state
        return new_state


def _dir_offset(d: Direction) -> tuple[int, int]:
    return {
        Direction.NORTH: (0, -1),
        Direction.EAST: (1, 0),
        Direction.SOUTH: (0, 1),
        Direction.WEST: (-1, 0),
    }[d]


def _project_view(px: int, py: int, facing: Direction, dist: int, offset: int) -> tuple[int, int]:
    """Project a view-cell into world coordinates.

    For a first-person view from (px, py) facing 'facing':
    - dist = how far forward (1 = adjacent tile)
    - offset = horizontal offset (-2, -1, 0, 1, 2 for FOV)
    """
    if facing == Direction.NORTH:
        return px + offset, py - dist
    elif facing == Direction.EAST:
        return px + dist, py + offset
    elif facing == Direction.SOUTH:
        return px - offset, py + dist
    else:  # WEST
        return px - dist, py - offset
