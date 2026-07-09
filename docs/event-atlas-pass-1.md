# Event Atlas Pass 1

Date: 2026-06-19

## What Changed

Added `scripts/build_event_atlas.py`, which ties together:

- GEO map event grids,
- ECL block references,
- first `ON GOTO` target arrays,
- nearby decoded `PRINT` / `PRINTCLEAR` text.

Run:

```bash
python3 scripts/build_event_atlas.py \
  generated/geo1/geo1_maps.json \
  generated/geo1/geo1_maps.tsv \
  generated/ecl1_disasm \
  generated/event_atlas
```

## Output

- `generated/event_atlas/event_atlas.md`
- `generated/event_atlas/event_atlas.html`
- `generated/event_atlas/event_atlas.json`

## Why This Matters

This is the first pass where the reverse engineering becomes navigable:

`GEO map cell` -> `event id` -> `ECL branch target` -> `nearby event text`

That is the backbone for reconstructing area scripts and eventually producing readable source-like event files.

## Good Examples

### GEO 17: Caloris Space Port

Resolved event text includes:

- De Sade greeting the party before the coronation.
- Linarian guards and questioning.
- security bots blocking the Warrens airlock.
- the `Rising Sun` service droid/inn event.
- dockside bar.
- portmaster / honor guard scenes.
- Dr. Romney asking for help.
- autodoc healing prompt.

### GEO 34: Historical Museum

Resolved event text includes:

- Chade / Stefi story events.
- RAM forces in the lobby.
- historical exhibits like California Condor, Black Rhino, Hubble telescope, ENIAC, Masterlink, and Fat Boy.
- gift shop and security bot events.

### GEO 35: Asteroid Base

Resolved event text includes:

- airlock between launch bays.
- security station.
- command center.
- laser control.
- General Mavroudis' office.
- doomsday laser platform.
- access-code clue in the bathroom.

## Current Limitations

- The atlas currently chooses the first `ON GOTO` with enough targets in the selected ECL block. That works for many normal map-event dispatchers, but some areas have multiple dispatch tables or indirect event handling.
- Some maps with references do not yet resolve to event text because the relevant dispatch table is not the first/obvious one.
- Event text snippets are nearby-text heuristics, not full control-flow summaries yet.

## Next Target

Improve ECL control-flow analysis:

1. identify map-event dispatcher tables more reliably,
2. mark branch tables as code or data,
3. reduce false `UNKNOWN_0xNN` lines,
4. emit one readable source-like file per map/event.
