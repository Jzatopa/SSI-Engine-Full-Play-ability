# Structured Pseudocode Pass 1

Date: 2026-06-19

## What Changed

Added `scripts/emit_structured_pseudocode.py`, which converts common ECL instruction patterns into more readable control flow.

Run:

```bash
python3 scripts/emit_structured_pseudocode.py \
  generated/event_atlas/event_atlas.json \
  generated/ecl1_disasm \
  generated/event_structured
```

## Output

- `generated/event_structured/index.md`
- 25 structured per-map files, for example:
  - `geo_017_caloris-space-port.structured.md`
  - `geo_034_historical-museum-levels-2-1.structured.md`
  - `geo_035_asteroid-base.structured.md`

## Improvements

The structurer recognizes this common ECL pattern:

```text
COMPARE
IF <operator>
next instruction
```

and emits:

```text
if (left <operator> right) {
  next_instruction();
}
```

It also follows `GOTO` bodies to a limited depth and keeps raw ECL addresses as comments.

## Example

```text
// 0x8D1B-0x8D21
if (1 == area1.word_208) {
  exit_event();  // 0x8D22
}
printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
```

## Current Limitations

- Flag-setting commands like `AND`, `OR`, `RANDOM`, and some menu/encounter commands are not yet modeled as condition sources, so they still appear as raw function calls followed by `if_<>` lines.
- `ON GOTO` branch tables are not fully structured into switch/case blocks yet.
- Some invalid operand-code artifacts remain and likely need Matrix Cubed-specific operand handling or better branch/table classification.

## Next Target

Add ECL flag-source modeling:

- `COMPARE` already maps cleanly.
- Next, model `AND`/`OR` result flags.
- Then convert `ON GOTO` into `switch`/`case`.
