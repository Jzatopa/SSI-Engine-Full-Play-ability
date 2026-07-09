# Pygame Runner Pass 1

**2026-06-21** — First working Pygame desktop frontend for Matrix Cubed.

## What Was Built

`src/matrix_cubed/tools/pygame_runner.py` — a self-contained Pygame frontend that:

- Drives the existing `GameState` runtime (movement, events, combat queuing)
- Renders a 16×16 overhead tile map (left panel, 320×320) using `MapEngine.get_overhead_view()`
- Shows a first-person direction indicator (right panel)
- Displays event text overlay when walking onto event tiles
- Bottom panel shows position, HP, credits, steps, active event
- WASD for movement/strafe, Q/E for turn, SPACE advances events, ESC exits
- Player drawn as green circle with facing indicator dot

## How Qwen Was Used

Qwen Coder (`--DIRECT` mode) generated an initial Pygame scaffold with correct layout/colour constants. Codex then:

1. Fixed API mismatches (ReconstructedData constructor, Direction types, GameState row/col vs x/y)
2. Wired to the actual `GameState.perform()` runtime instead of raw MapEngine
3. Added `_sync_map_engine()` to keep the rendering engine in sync with game state
4. Added proper event detection + `execute_current_event()` wiring
5. Added facing indicator on both overhead map and viewport

**Efficiency**: Qwen → 100+ line scaffold (free). Codex → ~50 lines of corrections + validation. Net: ~1.5× faster than writing from scratch.

## Validation

```
Loaded 25 maps, 63 monsters
Start: map=Caloris Space Port, pos=(1, 0), facing=south
Event: "'THE TELLTALE ON THE DOOR READS,'"
After 2 steps: pos=(1, 2), event=None
After 2 steps: log shows event 4 triggered
Runner imports OK: matrix_cubed.tools.pygame_runner
pytest: 38 passed, 0 failed
```

## Requirements

- Python 3.11+
- Pygame 2.x (`pip install pygame`)

## Usage

```bash
cd matrix-cubed-re
PYTHONPATH=src python3 src/matrix_cubed/tools/pygame_runner.py
```
