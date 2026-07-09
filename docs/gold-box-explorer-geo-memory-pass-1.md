# Gold Box Explorer GEO/Memory Pass 1

Date: 2026-06-19

## Goal

Continue using Gold Box Explorer as a reference by cross-checking Matrix Cubed GEO map names, wallset loading, and memory labels.

## Findings

Gold Box Explorer's Matrix Cubed map-name list matches the local atlas names:

- The known named maps align with `generated/geo1/geo1_maps.tsv`.
- GEO `021` is also unnamed in Gold Box Explorer, so the local placeholder name `21` remains unchanged.

Gold Box Explorer's GEO scanner looks for `LOAD PIECES` / `Load WALLDEF` patterns to infer wallset choices. The local decoder can now produce the same kind of report from decoded ECL listings instead of raw byte scanning.

Gold Box Explorer's player-offset comments provide high-confidence names for two local `AREA2` fields:

- `area2.word_200` -> `area2.selected_player_in_combat`
- `area2.word_596` -> `area2.surprise_result`

`area2.word_58E` remains unresolved and should stay raw until it is confirmed against executable behavior or more context.

## What Changed

Added:

- `scripts/summarize_wallsets.py`
- `generated/geo1/wallsets.tsv`
- `generated/geo1/wallsets.md`

Updated:

- `scripts/ecl_disassemble.py`
  - added `area2.selected_player_in_combat`
  - added `area2.selected_player_combat_team`
  - added `area2.surprise_result`

## Result

After regeneration:

- ECL listings: 33
- Event pseudocode files: 25
- Structured event pseudocode files: 25
- Suspect boundaries: 0
- Unknown opcode markers in generated outputs: 0
- Invalid operand markers in generated outputs: 0

The wallset report now gives an early visual/map setup hook for the future web/Python remake.

## Next Step

Use the wallset summary and extracted assets to build a map/asset viewer that can show each GEO map with its inferred wallset choices. This will be a better bridge toward a web version than continuing to name isolated variables indefinitely.
