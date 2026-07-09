# Opening Sequence Reconstruction Pass 1

Date: 2026-06-19

## Goal

Start reconstructing the game from launch instead of only from the in-map runtime prototype.

This pass creates a launch/opening sequence artifact and a structured window-set seed that can later be consumed by the Python/transcoded runtime.

## What Changed

Added:

- `scripts/build_opening_sequence.py`
- `generated/opening/matrix_cubed_opening_sequence.html`
- `generated/opening/opening_sequence.json`
- `generated/opening/assets/`

## Source Inputs

The opening reconstruction uses extracted assets from:

- `TITLE.DAX`
- `BIGPIC1.DAX`

It also uses launch/setup strings from:

- `START.EXE`
- `GAME.OVR`

The current pass includes visible startup/setup prompts found in `START.EXE`:

- graphics adapter selection,
- sound type selection,
- alternate input selection,
- save path prompt,
- loading message.

It also includes title/opening assets:

- SSI presents,
- Buck Rogers logo,
- copyright,
- Matrix Cubed title,
- two opening story panels.

## Window Set Seed

The generated JSON defines a 320x200 DOS coordinate space and five reusable windows:

- `full_screen_art`
- `setup_dialog`
- `message_dialog`
- `main_menu`
- `credits_text`

The sequence currently has 13 steps.

The initial game menu entries are a reconstruction seed, not yet confirmed from a live DOSBox capture:

- `LOAD SAVED GAME`
- `CREATE CHARACTERS`
- `VIEW CHARACTERS`
- `BEGIN GAME`
- `EXIT TO DOS`

## Validation

Validated from the Documents mirror path:

- `/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-re/generated/opening/matrix_cubed_opening_sequence.html`

Checks performed:

- Python compile for `scripts/build_opening_sequence.py`.
- Generated opening HTML, JSON, and copied opening assets.
- Mirrored workspace to Documents.
- Headless Chromium screenshot rendered successfully.
- DOM check confirmed opening title, first START.EXE setup prompt, window-set JSON, and full timeline.

Screenshot:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_opening_sequence.png`

## Next Step

Use this as the startup surface for the transcode direction:

- create a Python `opening.py` module from `opening_sequence.json`,
- wire the opening sequence into the playable runtime before map load,
- verify live startup/menu order with DOSBox-X or another DOS runner when available,
- replace inferred menu entries with confirmed executable/menu behavior.
