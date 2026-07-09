# GEO Map Pass 1

Date: 2026-06-19

## What Changed

Added `scripts/geo_inspect.py`, a first-pass inspector for `GEO1.DAX`.

Run:

```bash
python3 scripts/geo_inspect.py \
  "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/GEO1.DAX" \
  "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/ECL1.DAX" \
  generated/geo1
```

## GEO Layout

Each GEO block is a 16x16 map. The decoded block size is 1026 bytes.

Per cell:

- bytes `2..257`: north/east wall nibbles
- bytes `258..513`: south/west wall nibbles
- bytes `514..769`: event byte
- bytes `770..1025`: door byte

The event byte's low 7 bits are the event id. The high bit appears to be a flag.

## Output

- `generated/geo1/geo1_maps.tsv`
- `generated/geo1/geo1_maps.json`
- `generated/geo1/geo1_summary.md`

## Map Records Found

25 GEO maps were decoded.

Selected map-to-ECL links:

- GEO 1, `Luna Base`, referenced by ECL blocks `1`, `50`.
- GEO 17, `Caloris Space Port`, referenced by ECL blocks `17`, `19`.
- GEO 34, `Historical Museum, Levels 2-1`, referenced by ECL block `34`.
- GEO 49, `Lowlander Village`, referenced by ECL block `49`.
- GEO 50, `Venus Laboratory, Level 1`, referenced by ECL block `50`.
- GEO 80, `Mars Prison, Level 1`, referenced by ECL block `80`.
- GEO 82, `NEO Installation`, referenced by ECL block `82`.
- GEO 112, `Stormrider University`, referenced by ECL block `112`.
- GEO 113, `Genetics Foundation Building, Levels 1-4`, referenced by ECL block `113`.
- GEO 114, `Jupiter Finale`, referenced by ECL block `114`.

## Notable Counts

- `Historical Museum` has 135 non-zero event cells.
- `Mars Prison, Level 1` has 157 non-zero event cells.
- `Jupiter Finale` has 139 non-zero event cells.
- `Asteroid` GEO 18 has no non-zero event cells, suggesting it may be a navigation/combat/transition map rather than a normal event map.
- GEO 115 `Jupiter Aircar` exists but was not found in simple `LOAD FILES` scans; it may be loaded indirectly or by code.

## Current Interpretation

We now have a basic chain:

`ECL LOAD FILES` -> GEO map id -> 16x16 event grid -> event number -> `ON GOTO` branches inside the corresponding ECL block.

This is the backbone needed to reconstruct area scripts and map triggers.

## Next Target

Create visual map exports from GEO event grids and begin tying event ids to first printable ECL text snippets for each map.
