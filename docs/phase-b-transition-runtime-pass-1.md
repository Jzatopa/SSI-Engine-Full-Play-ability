# Phase B Transition Runtime Pass 1

Date: 2026-06-29

## Goal

Promote evidence-backed map transitions from the traversal analysis into the live runtime. Earlier runtime behavior treated any unflagged cell `event_id` as a map transition when the target GEO was loaded. That was too broad: traversal analysis shows many such cells are local events or unresolved exits rather than map changes.

## Implementation

- Added `CellTransitionRef` and `EclLoadRef` in `matrix_cubed.data.repository`.
- `ReconstructedData.from_generated()` now reads `generated/traversal/map_traversal_reference.json`.
- Only `cell_edges` rows with `interpretation == "promoted_transition"` and `target_loaded == true` are promoted into runtime transition refs.
- ECL `LOAD FILES` GEO references are loaded into `ecl_loads_by_block` for later event-transition work, but are not executed by this pass.
- `GameState.move()` now checks promoted traversal evidence before falling back to legacy event-id transition behavior.

## Validation Boundary

This pass does not infer new map transitions. It only consumes the existing generated traversal reference, which is itself derived from local decoded artifacts and prior validation work. Any unpromoted event cell remains local or unresolved unless a later pass promotes it with evidence.

## Files

- `src/matrix_cubed/data/repository.py`
- `src/matrix_cubed/engine/runtime.py`
- `tests/test_phase_b_transitions.py`

## Follow-Up

- Use `EclLoadRef` to wire ECL load-driven transitions into event execution.
- Preserve target entry coordinates when the traversal evidence includes validated `map_pos_x` and `map_pos_y`.
- Expand validation against DOS captures for high-value story transitions.
