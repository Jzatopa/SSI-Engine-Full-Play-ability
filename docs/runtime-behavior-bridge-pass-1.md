# Runtime Behavior Bridge Pass 1

Date: 2026-06-19

## Goal

Start turning decoded event inspection into executable prototype behavior.

This is not the final game logic yet. It is a runtime bridge that proves each classified event can affect prototype state in a visible, testable way while the exact ECL semantics continue to be reconstructed.

## What Changed

Updated:

- `scripts/build_map_viewer.py`
- `generated/viewer/matrix_cubed_runtime_seed.json`
- `generated/viewer/matrix_cubed_runtime_prototype.html`

The playable runtime now tracks:

- party HP
- credits
- inventory
- flags
- active encounter placeholder

The current-event panel now includes a `Run placeholder behavior` button.

## Placeholder Behavior

Event classifications now map to temporary runtime effects:

- `combat`: sets the active encounter marker.
- `reward`: adds 100 credits and a placeholder inventory item.
- `damage`: subtracts 10 party HP.
- `transition`: records a transition flag.
- `condition`: records a checked-condition flag.
- `text`: logs that dialogue was displayed.
- `unknown`: logs that the event still needs inspection.

These effects are intentionally simple. Their purpose is to create stable hooks for the next pass, where real decoded ECL instructions can replace placeholders one class at a time.

## Validation

Validated from the Documents mirror path:

- `/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-re/generated/viewer/matrix_cubed_runtime_prototype.html`

Checks performed:

- Python compile for `scripts/build_map_viewer.py`.
- Regenerated runtime seed, map viewer, and runtime prototype.
- Mirrored workspace to Documents.
- Headless Chromium screenshot rendered successfully.
- DOM check confirmed runtime state fields and the placeholder behavior button.

Screenshot:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_runtime_behavior_bridge.png`

## Next Step

Replace placeholder behavior with real behavior for one event class at a time, starting with transitions because they are easiest to validate visually:

- identify map/event transition targets,
- wire map switching to decoded transition instructions,
- keep flags/inventory/HP as persistent runtime state,
- then move to rewards, damage, conditions, and combat setup.
