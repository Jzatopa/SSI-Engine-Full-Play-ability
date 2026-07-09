# Source Runtime Scaffold Pass 1

Date: 2026-06-20

## Goal

Move the reconstruction from one-off analysis scripts toward a reusable source base that can support both a desktop executable and a web runtime.

## What Changed

Added a pure-Python package under `src/matrix_cubed/`:

- `formats/dax.py`: reusable DAX block reader and decompressor.
- `formats/geo.py`: GEO map/cell dataclasses and raw block parser.
- `data/repository.py`: loader for decoded generated artifacts, including maps, events, monsters, and encounter refs.
- `engine/runtime.py`: runtime-neutral game state with facing, movement, wall blocking, current event lookup, and placeholder event execution.
- `tools/runtime_probe.py`: CLI probe for loading reconstructed data and emitting a JSON snapshot.

Added project/test scaffolding:

- `pyproject.toml`
- `tests/test_runtime_probe.py`
- `generated/source_runtime/caloris_event_7_probe.json`

## Why This Matters

The previous runtime prototype was embedded in a generated HTML file. This pass creates a source-owned domain layer that can be reused by:

- a future Python/Pygame or PyInstaller desktop executable,
- a web renderer that consumes the same JSON/domain model,
- future event-interpreter and combat modules.

The package still consumes decoded local artifacts and does not embed copyrighted assets.

## Current Capability

The new runtime can:

- load reconstructed maps/events/monsters from `generated/`,
- start on a GEO map,
- track row/column/facing,
- block movement at map edges and walls,
- expose the current event,
- attach decoded encounter candidates to events,
- execute placeholder event behavior for combat/reward/damage/transition/condition/text categories.

Validation probe:

```bash
PYTHONPATH=src python3 -m matrix_cubed.tools.runtime_probe --generated-dir generated --map-id 17 --event-id 7 --execute --out generated/source_runtime/caloris_event_7_probe.json
```

Result: GEO 017 event 7 resolves to combat and queues `RAM WARRIOR`.

## Validation

Checks performed:

- Python compile for all `src/` and `tests/` files.
- Runtime probe generated `generated/source_runtime/caloris_event_7_probe.json`.
- No-dependency assertion test passed with `PYTHONPATH=src python3 tests/test_runtime_probe.py`.

`pytest` is not installed in this environment, so validation uses direct Python assertions for now.

## Next Step

Add a minimal event interpreter layer over the structured ECL operations. The first target should be deterministic event actions already modeled in pseudocode:

- `setup_monster`,
- `load_monster`,
- `clearmonsters`,
- simple `SAVE`/assignment,
- `ADD`/`SUBTRACT`/`AND`/`OR`,
- basic `GETTABLE`.

That will replace placeholder combat/reward/damage handling with executable reconstructed behavior.
