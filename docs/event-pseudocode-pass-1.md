# Event Pseudocode Pass 1

Date: 2026-06-19

## What Changed

Added `scripts/emit_event_pseudocode.py`, which expands each event atlas entry into a fuller pseudocode body using decoded ECL instruction ranges.

Run:

```bash
python3 scripts/emit_event_pseudocode.py \
  generated/event_atlas/event_atlas.json \
  generated/ecl1_disasm \
  generated/event_pseudocode
```

## Output

- `generated/event_pseudocode/index.md`
- 25 per-map pseudocode files, for example:
  - `geo_017_caloris-space-port.pseudo.md`
  - `geo_034_historical-museum-levels-2-1.pseudo.md`
  - `geo_035_asteroid-base.pseudo.md`

## Improvement Over Source-Like Map Pass 1

The earlier `source_like_maps` files had one-line `text_hint` entries. This pass emits decoded instruction bodies:

```text
event 01 {
  @0x880A: AND area2.word_6F2 = 4 & area1.word_25E
  @0x8813: IF <> <if compare flag is false, skip next op>
  @0x8814: GOTO 0x88B8
  // follows GOTO 0x88B8
    @0x88B8: SAVE area1.word_22A = abs_0001
    ...
}
```

The emitter follows `GOTO` chains up to a limited depth so common setup/shared handlers become visible.

## Current Limitations

- Conditional branches are still represented linearly. A later pass should emit explicit `if/else` blocks.
- Some indirect engine addresses such as `0xC04C` are outside decoded ECL listings and need binary/engine mapping.
- Operand decoding still has a few invalid operand-code artifacts, usually where an instruction boundary is imperfect or a Matrix Cubed variant differs from ECLDump.

## Next Target

Add structured control-flow reconstruction:

- convert `COMPARE` + `IF` + next-op patterns into `if` statements,
- model fallthrough and branch bodies,
- mark shared subroutines/handlers,
- improve `CALL` target names from `GAME.OVR` reverse engineering.
