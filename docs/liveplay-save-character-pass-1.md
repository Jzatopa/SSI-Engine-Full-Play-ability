# Liveplay Save Character Pass 1

## Goal

Use DOSBox-X liveplay to create real Matrix Cubed character saves, then compare the save directory before and after saving so character file names and record offsets come from observed behavior.

## Liveplay Findings

The configured EGA/silent-input path can create a disposable character with this high-level flow:

1. Advance title/startup screens to the character menu.
2. Select `CREATE NEW CHARACTER`.
3. Accept default Terran, Male, Rocket Jock selections.
4. Answer `n` to `REROLL STATS? YES NO`.
5. Enter a character name.
6. Use `D` twice to pass career and technical skill screens when no points remain.
7. Accept the icon.
8. Confirm `SAVE <name>? YES NO`.

The first confirmed save writes were:

- `MATRIX/SAVE/TST1.WHO`
- `MATRIX/SAVE/TST1.STF`
- `MATRIX/SAVE/TST2.WHO`
- `MATRIX/SAVE/TST2.STF`

No other files changed during those character-save confirmations.

## Record Shape

Observed file sizes:

- `.WHO`: 259 bytes
- `.STF`: 124 bytes

The `.WHO` length matches the 259-byte Matrix Cubed `MON0CHA.DAX` record variant already seen in the data model pass. This gives us a strong bridge between generated characters, player characters, and monster/character templates.

Confirmed `.WHO` offsets from the `TST2` live sample:

- `0x00`: character name length
- `0x01-0x0f`: ASCII character name
- `0x10-0x16`: STR, DEX, CON, INT, WIS, CHA, TECH
- `0x17-0x1d`: current STR, DEX, CON, INT, WIS, CHA, TECH
- `0x26`: gender id candidate; Male saved as `0`, Female saved as `1`
- `0x27`: race id candidate; Terran saved as `1`, Martian saved as `2`
- `0x28`: career id candidate; Rocket Jock saved as `1`, Medic saved as `2`
- `0x29`: level
- `0x2b-0x2e`: credits, little-endian u32
- `0x2f-0x32`: experience, little-endian u32
- `0x38`: age
- `0xe3`: hit points candidate; matched the visible HP value in the `TST2` sample

## Source Added

- `src/matrix_cubed/formats/save.py`
- `src/matrix_cubed/tools/save_probe.py`
- `scripts/analyze_save_samples.py`
- `tests/test_save_formats.py`
- `generated/liveplay/save_probe.json`
- `generated/liveplay/controlled_save_samples.json`
- `generated/liveplay/controlled_save_samples.md`

The save probe currently decodes confirmed `.WHO` fields and reports `.STF` size. It deliberately leaves unknown `.STF` and uncertain `.WHO` fields unnamed until additional live samples or code call-sites confirm them.

## Controlled Samples

Three additional live-created characters varied one setup choice at a time:

- `RAC1`: Martian, Male, Rocket Jock
- `GEN1`: Terran, Female, Rocket Jock
- `CAR1`: Terran, Male, Medic

These samples corrected the first-pass enum assumption. The observed candidate bytes are:

- `0x26`: gender id
- `0x27`: race id
- `0x28`: career id

The summary artifact is:

- `generated/liveplay/controlled_save_samples.md`

## Active Party Save

Adding `CAR1` to the active team and saving game slot A produced the first party/game-save files:

- deleted loose roster files: `CAR1.WHO`, `CAR1.STF`
- added active character files: `CHRDATA1.SAV`, `CHRDATA1.STF`
- added game state file: `SAVGAMA.DAT`

Observed sizes:

- `CHRDATA1.SAV`: 259 bytes
- `CHRDATA1.STF`: 124 bytes
- `SAVGAMA.DAT`: 2901 bytes

`CHRDATA1.SAV` parses with the same 259-byte character-record parser and contains the saved `CAR1` Medic record. `SAVGAMA.DAT` starts with `01`, which is a party-count candidate after saving one active character, but that field still needs a second party-size sample before it should be promoted.

## Validation

- `PYTHONPATH=src python3 -m pytest -q`: 7 passed
- `python3 -m compileall -q src tests`: passed
- `PYTHONPATH=src python3 -m matrix_cubed.tools.save_probe /home/jzatopa/Downloads/matrix-cubed-liveplay/MATRIX/SAVE`: decoded `TST1` and `TST2`
- `python3 scripts/analyze_save_samples.py /home/jzatopa/Downloads/matrix-cubed-liveplay/MATRIX/SAVE generated/liveplay`: generated controlled-sample summary

## Next

Create a second active-party save with two characters so `SAVGAMA.DAT` party-count and party-slot structures can be confirmed. Then begin adventuring from the saved party and capture the first runtime/map save changes before pushing to the first fight.
