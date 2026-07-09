# Map Viewer Pass 1

Date: 2026-06-19

## Goal

Create the first concrete web-viewable artifact from the Matrix Cubed reverse-engineering outputs.

## What Changed

Added:

- `scripts/build_map_viewer.py`
- `generated/viewer/matrix_cubed_map_viewer.html`
- `generated/viewer/matrix_cubed_runtime_seed.json`

The generated HTML is self-contained and embeds:

- GEO map cells from `generated/geo1/geo1_maps.json`
- decoded event hints from `generated/event_atlas/event_atlas.json`
- inferred wallsets from `generated/geo1/wallsets.tsv`
- a local asset thumbnail strip from `/home/jzatopa/Downloads/matrix-cubed-assets/images`
- links to structured and pseudocode event files

The viewer now supports:

- clicking event cells to select/highlight the matching event,
- clicking event rows to highlight the matching map cell,
- opening the structured/pseudocode source files for each map,
- a compact runtime seed JSON for future Python/web runtime work.

## Validation

Validated with headless Chromium from the Documents mirror path:

- `/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-re/generated/viewer/matrix_cubed_map_viewer.html`

The `.openclaw` workspace path is not suitable for Chromium snap validation because the browser denies direct file access to hidden path elements.

Screenshot captured at:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_viewer_docs_final.png`

## Result

The viewer renders:

- map list,
- 16x16 wall/event/door canvas,
- GEO/ECL/wallset metadata,
- decoded event text where available,
- extracted asset thumbnails.
- structured/pseudocode source links.

## Next Step

Start a small runtime prototype:

- load `matrix_cubed_runtime_seed.json`,
- move a player marker on a selected map,
- trigger event text when stepping onto event cells,
- keep rendering assets from the extracted PNG folder.
