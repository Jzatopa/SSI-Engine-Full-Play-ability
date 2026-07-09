# Operand 0x05 And Prefix Target Pass 1

Date: 2026-06-19

## Goal

Resolve the remaining branch/table referenced suspect ECL targets after text-padding cleanup.

## Discovery 1: Operand Code `0x05`

ECL1 block 18's Salvation port lounge menu exposed a Matrix Cubed operand variant not present in the first ECLDump-derived operand set.

The `BUY DRINKS` branch at `0x94A6` previously decoded as a suspect `MULTIPLY` because the third operand began with code `0x05`.

Treating `0x05` as a word-sized memory operand makes the sequence align cleanly:

```text
0x94A6 MULTIPLY area2.word_6F6 = area2.party_size * 4
0x94AF PRINTCLEAR 'A ROUND OF DRINKS WILL COST '
0x94C7 PRINT area2.word_6F6
0x94CB PRINT ' CREDITS.'
```

The Python decoder now:

- consumes a high byte for operand code `0x05`,
- treats it as a valid operand,
- renders its value through the memory-name mapper.

The print dispatcher also now renders non-string `PRINT` operands directly instead of reusing the last loaded string.

## Discovery 2: One-Byte Prefixed Branch Targets

The remaining referenced suspects all pointed to a suspect byte whose next byte was a clean instruction start. The decoder now normalizes those branch targets only when:

1. the original target has invalid operand codes, and
2. `target + 1` starts a clean, non-variable instruction.

Confirmed normalizations:

- ECL1 block 35: `0x9BDC -> 0x9BDD`, revealing `PRINTCLEAR 'DO YOU CONTINUE TO WATCH?'`
- ECL1 block 95: `0x8D0D -> 0x8D0E`, revealing `SAVE area2.game_area = 1` followed by `NEWECL 20`
- ECL1 block 114: `0xA2CF -> 0xA2D0`, revealing `OR area1.word_20C = 2 | area1.word_20C`

## Counts After This Pass

- Total suspect boundaries: 46
- Branch/table referenced suspect targets: 0
- Event pseudocode inline invalid operand details: 0
- Structured pseudocode inline invalid operand details: 0

## Remaining Work

All branch-referenced suspects are currently resolved. The remaining 46 suspects are fallthrough-only artifacts. The next most useful target is to group them by preceding command (`IF`, `GOSUB`, `SAVE`, `OR`, `GOTO`, `EXIT`, `ADD`) and look for another small operand or command-length rule.
