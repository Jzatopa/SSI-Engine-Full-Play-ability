# Source-Like Map Pass 1

Date: 2026-06-19

## What Changed

Added `scripts/emit_source_like_maps.py`, which emits one first-pass source-like Markdown file per GEO map from the event atlas.

Run:

```bash
python3 scripts/emit_source_like_maps.py \
  generated/event_atlas/event_atlas.json \
  generated/source_like_maps
```

## Output

- `generated/source_like_maps/index.md`
- 25 per-map files, for example:
  - `geo_017_caloris-space-port.md`
  - `geo_034_historical-museum-levels-2-1.md`
  - `geo_035_asteroid-base.md`

## Result

Each file now has a source-like module shell:

```text
module geo_017_caloris_space_port {
  name = 'Caloris Space Port'
  ecl_block = 17

  event 01 at 0x880A:
    text_hint = ...
}
```

This is not original source, but it gives us a structured place to refine each event into real pseudocode as the ECL decoder improves.

## Current Limitation

The `text_hint` field is inferred from nearby decoded print statements. It is useful for navigation, but not yet a full event body.

## Next Target

Generate fuller per-event pseudocode bodies from ECL instruction ranges instead of only nearby text hints.
