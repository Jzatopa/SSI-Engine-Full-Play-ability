# Source Runtime Combat Queue Pass 1

Date: 2026-06-20 18:54 CDT

## Goal

Promote encounter runtime state beyond a string placeholder so playable frontends can consume a stable combat queue object.

## Changes

- Preserved `candidateResolution` from `generated/viewer/matrix_cubed_runtime_seed.json` in `EncounterRef`.
- Added `src/matrix_cubed/engine/combat.py` with `QueuedCombat`.
- Updated `GameState.execute_current_event()` so `queue_combat` commands create `QueuedCombat` state.
- Updated runtime snapshots with:
  - `active_encounter`: human-readable summary
  - `active_combat`: structured queued-combat payload
- Split combat command payload names into:
  - `monster_names` for exact decoded monsters
  - `candidate_monster_names` for table-backed variable encounters
  - `unresolved_monster_refs` for unresolved ECL operands

## Validation Examples

`GEO 017` event 7 remains an exact encounter:

- `RAM WARRIOR`
- constant `SETUP_MONSTER` operand `52`
- regenerated probe: `generated/source_runtime/caloris_event_7_probe.json`

`GEO 021` event 4 now carries candidate encounter evidence:

- unresolved operand: `area2.event_scratch7`
- candidate monsters: `MER. WARRIOR`, `PIRATE LEADER`, `RAM WARRIOR`, `SECURITY ROBOT`
- table evidence: `0x8FCD`, indexed by a still-unresolved `area2.event_scratch8` expression
- regenerated probe: `generated/source_runtime/geo021_event_4_dynamic_probe.json`

## Why This Matters

This keeps uncertain dynamic encounters usable without overclaiming exact behavior. A future web, Python/Pygame, or packaged EXE frontend can show or simulate a queued combat state immediately, while later ECL data-flow passes narrow candidate tables into exact branch/runtime outcomes.

## Verification

- `PYTHONPATH=src python3 -m pytest -q`
- `python3 -m compileall -q src tests`
- `PYTHONPATH=src python3 -m matrix_cubed.tools.runtime_probe --map-id 17 --event-id 7 --execute --out generated/source_runtime/caloris_event_7_probe.json`
- `PYTHONPATH=src python3 -m matrix_cubed.tools.runtime_probe --map-id 21 --event-id 4 --execute --out generated/source_runtime/geo021_event_4_dynamic_probe.json`
