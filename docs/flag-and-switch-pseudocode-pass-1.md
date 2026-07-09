# Flag And Switch Pseudocode Pass 1

Date: 2026-06-19

## What Changed

Updated `scripts/emit_structured_pseudocode.py`.

The structured pseudocode pass now handles:

- `AND` / `OR` as flag-producing expressions followed by `IF`.
- `ON GOTO` / `ON GOSUB` branch tables as `switch` blocks.

Regenerate with:

```bash
python3 scripts/emit_structured_pseudocode.py \
  generated/event_atlas/event_atlas.json \
  generated/ecl1_disasm \
  generated/event_structured
```

## Output

Updated files in:

- `generated/event_structured/`

## Example: Flag Modeling

Before:

```text
and(area2.word_6F2 = 4 & area1.word_25E);
if_<>(...);
goto 0x88B8;
```

After:

```text
area2.word_6F2 = 4 & area1.word_25E;
if (area2.word_6F2 != 0) {
  goto 0x88B8;
}
```

## Example: ON GOTO Switch

Before:

```text
on_goto(area1.word_20E of [0x860E, 0x88B3, 0x898C]);
```

After:

```text
switch (area1.word_20E) {
  case 0: goto 0x860E;
  case 1: goto 0x88B3;
  case 2: goto 0x898C;
}
```

The emitter also includes limited case-body expansion.

## Current Limitations

- Some complex commands, especially `ENCOUNTER MENU`, still contain invalid operand-code artifacts.
- Switch cases are numbered from zero for now. The exact selector indexing should be validated against engine behavior.
- Deep shared handlers can duplicate output or hit the recursion guard.

## Next Target

Improve operand decoding for complex command records:

- `ENCOUNTER MENU`
- `PARLAY`
- `DAMAGE`
- mixed inline strings / dynamic string references
