# Textured Runtime And Event Inspector Pass 1

Date: 2026-06-19

## Goal

Overlay game-derived wall textures onto the first-person runtime prototype, then continue into the next runtime task: current-event inspection.

## What Changed

Added:

- `scripts/export_wall_textures.py`
- `generated/wall_textures/`

Updated:

- `scripts/build_map_viewer.py`
- `generated/viewer/matrix_cubed_runtime_seed.json`
- `generated/viewer/matrix_cubed_runtime_prototype.html`

## Wall Textures

The exporter assembles `WALLDEF1.DAX` wall views using the extracted `8X8D1` 8x8 tile PNGs.

Output:

- 1,650 wall-view PNGs
- 11 wallsets
- 15 wall IDs per wallset
- 10 perspective views per wall

The runtime seed now chooses the first available real wall texture set for each map. For `GEO 017 Caloris Space Port`, the texture set is `005`.

The prototype uses relative texture paths:

- `../wall_textures`

This keeps the generated HTML usable from the Documents mirror path.

## Event Inspector

The runtime seed now embeds compact per-event context from:

- `generated/event_structured/`
- `generated/event_pseudocode/`

The current event panel now shows:

- event type classification,
- decoded event text,
- expandable structured logic,
- expandable pseudocode.

## Validation

Validated from the Documents mirror path:

- `/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-re/generated/viewer/matrix_cubed_runtime_prototype.html`

Checks performed:

- Python compile for both generator scripts.
- Regenerated wall textures, runtime seed, map viewer, and runtime prototype.
- Mirrored workspace to Documents.
- Headless Chromium screenshot rendered successfully.
- DOM check confirmed texture set `005`, structured logic, pseudocode, and relative wall texture base.

Screenshot:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_runtime_textured_event_inspector.png`

## Next Step

Start connecting classified event behavior to runtime actions:

- transitions between maps,
- dialogue prompts/choices,
- combat placeholders,
- reward/item changes,
- damage/status effects.
