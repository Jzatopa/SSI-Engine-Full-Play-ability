# Dynamic Encounter Table Pass 1

Date: 2026-06-20

## Goal

Start resolving encounter rows whose monster operands are variables rather than direct constants.

## What Changed

Added:

- `scripts/analyze_dynamic_encounters.py`
- `generated/encounters/dynamic_encounter_analysis.json`
- `generated/encounters/dynamic_encounter_analysis.md`

## Results

The previous encounter xref identified 13 dynamic rows. This pass found nearby table sources for 6 of them.

Confirmed table-backed candidates:

- GEO/ECL 021 uses `ecl.byte_0FCD[area2.event_scratch2]` for `area2.event_scratch7`.
- Candidate values in that table include `COYODORG`, `RAM WARRIOR`, and `SECURITY ROBOT`, with zero bytes and repeated entries.
- GEO/ECL 034 uses `abs_A2F0[area1.event_word_21C]` for monster ID and `abs_A2EC[area1.event_word_21C]` for picture ID.
- Candidate values in the ECL 034 monster table include sentinel `255`, `LG. E.C. GENNIE`, `RAM WARRIOR`, `RATWURST`, `WARRIOR`, and `SID REFUGE`.

Remaining dynamic rows are likely state-carried rather than immediate local-table cases:

- ECL 021 addresses `0x83DE` and `0x8A09`.
- ECL 033 address `0x8392`.
- ECL 036 address `0x884D`.
- ECL 037 address `0x82E6`.
- ECL 080 addresses `0x863E` and `0xA367`.

## Caution

The table bytes are decoded correctly as byte values, but final row selection still depends on runtime index expressions such as `area2.event_scratch8`, `area1.event_word_21C`, `area1.event_word_21A`, and map direction. Treat this as candidate analysis, not final combat source truth.

## Validation

Checks performed:

- Python compile for `scripts/analyze_dynamic_encounters.py`.
- Generated JSON and Markdown analysis.
- Confirmed 13 dynamic rows analyzed and 6 rows with table candidates.

## Next Step

Build a minimal ECL data-flow pass that can carry simple assignments, random ranges, `ADD`, and `GETTABLE` results across branch bodies. That should resolve the remaining dynamic rows into either bounded monster candidate sets or explicit state dependencies.
