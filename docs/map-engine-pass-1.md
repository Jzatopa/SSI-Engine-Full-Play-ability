# Map Engine Pass 1 — Tile-Grid Movement and Event Triggers

**2026-06-21** — First pass of the runtime map engine.

## What Changed

New module: `src/matrix_cubed/engine/map_engine.py`

### Components
- **`Direction`** enum: NORTH, EAST, SOUTH, WEST
- **`MoveResult`** dataclass: tracks position, blocked status, tile type, event triggers, transitions
- **`MapContext`** dataclass: holds current map, player position/facing, visited tiles, event/door states
- **`MapEngine`** class:
  - `try_move(direction)` — core movement with collision, event trigger, door handling
  - `move_north/east/south/west()` — directional wrappers
  - `turn_left/right()` — facing changes
  - `get_cell(x, y)` — tile lookup via `GeoMap.cell_at()`
  - `get_overhead_view()` — full 16x16 tile grid for minimaps
  - `get_visible_cells(view_range)` — first-person view projection
  - `toggle_door(x, y)` — open/close doors
  - `load_map(map_id)` — load GEO map via repository

### Tile Classification
Tile types inferred from GeoCell wall/event/door fields:
- `TILE_WALL` — any cell with non-zero wall textures
- `TILE_FLOOR` — open walkable cell
- `TILE_DOOR` — cell with door index > 0
- `TILE_EVENT` — cell with event_id and event_flag set
- `TILE_EXIT` — cell with event_id but no event_flag (area transition)
- `TILE_VOID` — off-map coordinates

### Tests
New file: `tests/test_map_engine.py` — 23 tests covering:
- Movement in all 4 directions over open terrain
- Wall collision (border walls, interior walls)
- Facing (turn left/right wraparound)
- Event tile trigger detection
- Door open/closed state
- Visited tile tracking
- Overhead view grid dimensions
- Cell lookup (in bounds, out of bounds)
- View projection (4 directions, 3 distances, 3 offsets)

### Test Status
**38 passing, 0 failing** (was 15, now +23 map engine tests)

## Next Step
Connect the map engine to ECL event execution and game state, so walking onto an event tile actually fires the correct script. Then integrate with the runtime prototype for visual testing.
