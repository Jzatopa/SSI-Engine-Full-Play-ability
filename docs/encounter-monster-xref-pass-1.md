# Encounter Monster Cross-Reference Pass 1

Date: 2026-06-20

## Goal

Connect decoded `MON0CHA.DAX` monster records to ECL encounter commands so the reconstruction has concrete enemy identities instead of generic combat placeholders.

## What Changed

Added and fixed:

- `scripts/build_encounter_monster_xref.py`
- `generated/encounters/encounter_monster_xref.json`
- `generated/encounters/encounter_monster_xref.tsv`
- `generated/encounters/encounter_monster_xref.md`
- `generated/encounters/monster_usage_by_id.json`

Updated:

- `scripts/build_map_viewer.py`
- `generated/viewer/matrix_cubed_runtime_seed.json`
- `generated/viewer/matrix_cubed_runtime_prototype.html`
- `generated/viewer/matrix_cubed_map_viewer.html`

## Results

The encounter xref now finds:

- 184 encounter-related ECL rows.
- 180 `SETUP MONSTER` rows.
- 4 `LOAD MONSTER` rows.
- 142 direct constant rows linked to decoded `MON0CHA.DAX` records.
- 13 dynamic rows that require data-flow/table resolution.
- 29 sentinel or picture-only rows, mostly `255` monster operands.

Most frequently referenced direct monsters:

- `RAM WARRIOR`: 23 rows.
- `PURGE COMMANDO`: 18 rows.
- `GANG LEADER`: 18 rows.
- `PIRATE LEADER`: 13 rows.
- `AMALTHEAN WARR`: 13 rows.
- `SECURITY ROBOT`: 10 rows.

The playable runtime seed now attaches encounter rows to map events when the structured/pseudocode section references the same ECL address. This produced 113 events with encounter candidates.

## Runtime Bridge

The runtime event inspector now displays matched encounter rows with:

- monster name or dynamic operand reference,
- ECL command kind and address,
- max distance / copies when present,
- key decoded base stats when linked to `MON0CHA`.

Running placeholder combat behavior now carries the matched monster names into `state.activeEncounter`.

Example validation:

- GEO 017 `Caloris Space Port`, event 6, address `0x8C27`, resolves to `PURGE COMMANDO`.

## Dynamic Rows Still Open

Some events use table lookups or state words:

- GEO 021 uses `area2.event_scratch7` after `gettable(ecl.byte_0FCD[...])`.
- GEO 033/034/036/037 use `area2.event_scratch1` and `area2.event_scratch2` from local tables.
- GEO 080 uses `area1.event_word_23A` for both monster and portrait IDs.

These need a small ECL data-flow/table decoder pass before they can be safely resolved.

## Validation

Checks performed:

- Python compile for `scripts/build_map_viewer.py` and `scripts/build_encounter_monster_xref.py`.
- Regenerated encounter xref outputs.
- Regenerated runtime seed, prototype, and map viewer with `--encounter-xref-json`.
- Confirmed runtime seed has 25 maps and 113 events with attached encounter candidates.
- Chromium render check confirmed the local playable HTML loads with no console/page errors and both canvases present.
- Chromium event check confirmed Caloris event 6 displays `PURGE COMMANDO` in the encounter panel.

Screenshots:

- `<local viewer-check output>/matrix_runtime_monster_bridge.png`
- `<local viewer-check output>/matrix_runtime_monster_bridge_event.png`

## Next Step

Resolve the 13 dynamic encounter rows by decoding small ECL local tables and simple data flow into `event_scratch` / `area1.event_word_*` fields. After that, move into a reusable source scaffold: shared parsers, map runtime, event interpreter skeleton, and desktop/web frontends using the same decoded data.
