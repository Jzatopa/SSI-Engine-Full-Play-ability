# ECL LOAD FILES Transition Runtime Pass 1

Date: 2026-06-29

## Goal

Use decoded ECL `LOAD FILES Load GEO` rows to improve transition execution without guessing route semantics. This pass replaces `(1,1)` destination coordinates where a validated ECL load row provides nearby literal `SAVE mapPosX` and `SAVE mapPosY` values.

## Evidence Used

- `generated/traversal/map_traversal_reference.json`
- ECL disassembly rows under `generated/ecl1_disasm/`
- Existing DOS capture validation artifacts under `generated/validation/`

The DOS capture artifacts currently anchor scene families and UI availability. They do not yet OCR-confirm exact transition prompts or exact map coordinates, so this pass treats coordinate evidence as ECL-disassembly-backed rather than DOS-coordinate-confirmed.

## Implementation

- `scripts/build_map_traversal_reference.py`
  - widens the nearby coordinate scan for `LOAD FILES` rows,
  - stops at control-flow terminators so coordinates do not leak from the next ECL branch.
- `EclLoadRef`
  - now preserves address, raw operands, and optional `map_pos_x` / `map_pos_y`.
- `CellTransitionRef`
  - now carries optional target entry coordinates.
- `ReconstructedData`
  - builds a conservative `entry_positions_by_map` table from complete `(mapPosX,mapPosY)` ECL load evidence.
- `GameState.move()`
  - uses target entry coordinates for promoted cell transitions when available.
- `compile_event_commands()`
  - can emit `load_geo` commands for exact event-target-to-`LOAD FILES` address matches.
- `GameState.execute_current_event()`
  - executes `load_geo` commands only when a validated entry position is available.

## Validation Boundary

- This pass does not infer which in-game prompt should trigger every ECL load.
- Existing runtime events do not yet carry complete instruction ranges, so ECL load execution is exact-address only.
- Coordinate-incomplete rows remain available in the data model but do not force an ECL transition.
- Promoted cell transitions still fall back to `(1,1)` only when no validated target entry position exists.

## Verified Examples

- GEO 001 entry position: `(9,4)`
- GEO 034 entry position: `(7,15)`
- GEO 064 entry position: `(11,15)`
- GEO 112 promoted cell transition to GEO 034 now enters at `(7,15)`.

## Tests

- `tests/test_phase_b_transitions.py`
- `tests/test_map_traversal_reference.py`
