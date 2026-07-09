# Character Menu Reconstruction Pass 1

Date: 2026-06-20

## Goal

Step forward from the seeded opening menu into the `VIEW CHARACTERS` branch, then walk through each character-management option exposed by executable strings.

## What Changed

Updated:

- `scripts/build_opening_sequence.py`
- `generated/opening/opening_sequence.json`
- `generated/opening/matrix_cubed_opening_sequence.html`
- `generated/opening/assets/`

The opening reconstruction now has 24 steps. New character-flow steps begin after the initial game menu:

- Main menu: View Characters
- Character options
- Pick character
- View Character
- Option: Create New Character
- Option: Purge Character
- Option: Modify Character
- Option: Train Character
- Option: View Character
- Option: Add Character To Team
- Option: Remove Character From Team

## Source Evidence

Character menu labels are grounded in `START.EXE` strings:

- offset `59986`: `Create New Character`
- offset `60015`: `Purge Character`
- offset `60038`: `Modify Character`
- offset `60081`: `Train Character`
- offset `60104`: `View Character`
- offset `60126`: `Add Character to Team`
- offset `60156`: `Remove Character from Team`

Related `GAME.OVR` strings used for branch screens:

- `Pick Character`
- `Select Exit`
- `Character name:`
- `Reroll stats?`
- `Save`
- `Modify:`
- `Add Subtract Keep Exit`
- `Do you wish to train?`
- `Add a character:`
- `Lose character?`
- `CHARS`
- `Can't open CHARS.DAX!`

## Assets

The pass copies a small visible seed set from the extracted image corpus:

- `CHARS_000_000.png` through `CHARS_005_000.png`
- `CPIC1_001_000.png` through `CPIC1_005_000.png`

These are representative character sprites/portraits for the reconstruction UI. Exact party records, names, and stats still need CHARS.DAX decoding or live save inspection.

## Validation

Checks performed:

- Python compile for `scripts/build_opening_sequence.py`.
- Regenerated opening HTML and JSON.
- Confirmed the output has 24 timeline steps.
- Confirmed character-flow selected menu lines advance correctly through View Character and the option screens.
- Rendered the generated HTML with headless Chromium.

Screenshot:

- `<local viewer-check output>/matrix_opening_character_options.png`

## Next Step

Decode `CHARS.DAX` records enough to replace placeholder roster names and stat values with real character data, then wire these character-management screens into the runnable Python/web runtime state model.
