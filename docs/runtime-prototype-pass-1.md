# Runtime Prototype Pass 1

Date: 2026-06-19

## Goal

Create the first tiny playable web runtime from the extracted Matrix Cubed map/event data.

## What Changed

Updated `scripts/build_map_viewer.py` so the same generation pass can now emit:

- `generated/viewer/matrix_cubed_map_viewer.html`
- `generated/viewer/matrix_cubed_runtime_seed.json`
- `generated/viewer/matrix_cubed_runtime_prototype.html`

The runtime prototype is self-contained and embeds the compact runtime seed.

## Prototype Features

- Defaults to the first event-rich map: `GEO 017 Caloris Space Port`.
- Draws the 16x16 GEO map grid with inferred walls, doors, event cells, and event IDs.
- Places a player marker on the map.
- Supports keyboard movement with arrow keys or WASD.
- Supports on-screen movement buttons.
- Supports map switching with a select control.
- Shows current map state: GEO, position, facing, steps, ECL block, wallsets, cell walls, and door value.
- Triggers and displays event text when the player enters an event cell.
- Keeps a small event log of recent triggered cells.
- Includes a wall-blocking toggle so inferred collision can be tested without blocking exploration.

## Validation

Validated from the Documents mirror path because Chromium blocks direct access to hidden `.openclaw` paths:

- `/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-re/generated/viewer/matrix_cubed_runtime_prototype.html`

Checks performed:

- `python3 -m py_compile scripts/build_map_viewer.py`
- Regenerated viewer, runtime seed, and runtime prototype.
- Headless Chromium screenshot rendered successfully.
- DOM check found the prototype title, `Caloris Space Port`, current event panel, and event log.
- Screenshot pixel check found 474 sampled unique colors and 110,698 non-dark pixels in the map region, confirming a nonblank render.

Screenshot:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_runtime_prototype_documents.png`

## Next Step

The next useful layer is a real event inspector/runtime bridge:

- make event log entries expandable,
- show the structured pseudocode for the current event,
- classify events by behavior such as text, transition, combat, reward, damage, or condition,
- add map-to-map transitions once those command targets are confirmed.

## First-Person View Addendum

Added after the initial runtime pass:

- a first-person, Gold Box-style corridor viewport driven by the player's current GEO cell and facing direction,
- a smaller tactical map underneath the viewport for debugging,
- turn-based movement controls where left/right turn by default,
- a `strafe` mode for lateral debug movement,
- visible near/far side walls, front walls, doors, event markers, current event text, and facing/status overlay.

This pass uses canvas-drawn wall geometry from GEO wall data. The extracted PNG set does not currently include standalone `WALLDEF*.png` files, so textured wall rendering remains a later phase.

Validation screenshot:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_runtime_first_person_final2.png`
