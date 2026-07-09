# Fallthrough Prefix And Surprise Pass 1

Date: 2026-06-19

## Goal

Clear the remaining fallthrough-only suspect boundaries after branch-referenced targets had already been resolved.

## What Changed

### Prefixed Fallthrough Normalization

The decoder now normalizes short prefixed fallthroughs, not just prefixed branch targets.

Rule:

1. current address decodes as a suspect boundary,
2. a clean instruction start exists within the next 1-4 bytes,
3. continue decoding at that clean instruction start,
4. record the normalization in the raw listing.

This resolved the repeated `0x29` / `0x29 0x42` prefix pattern that appeared before valid `COMPARE`, `SAVE`, `PRINTCLEAR`, `AND`, `OR`, and related commands.

### `SURPRISE` 3-Operand Variant

One remaining case in ECL1 block 98 at `0xA21C` showed `SURPRISE` with three valid operands followed by a prefixed clean instruction:

```text
0xA21C SURPRISE raw=(area2.word_6F4, area2.word_6F6, area2.word_6F8)
0xA227 COMPARE Values: 2 == area2.word_6F8
```

The decoder now tries the normal 4-operand `SURPRISE` form first, and falls back to a 3-operand form if the fourth operand is invalid.

## Result

- Suspect boundaries: 46 -> 0
- Branch/table referenced suspect targets: 0
- Event pseudocode inline invalid operand details: 0
- Structured pseudocode inline invalid operand details: 0

## Remaining Separate Work

The suspect-boundary cleanup is complete. Raw ECL listings still contain separate `UNKNOWN_0x..` opcode references. Those are not invalid operand boundaries; they should be handled in the next phase by grouping unknown opcodes and checking whether they are true opcodes, data/table bytes, or more command-length variants.
