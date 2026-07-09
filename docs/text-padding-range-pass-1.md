# Text Padding Range Pass 1

Date: 2026-06-19

## Goal

Handle branch targets that land inside a text/data padding region, not only at the first byte after a `PRINT` or `PRINTCLEAR`.

## What Changed

`scripts/ecl_disassemble.py` now performs a cautious postprocess:

1. Record exact text fallthrough boundaries after string-bearing print commands.
2. Find the next high-confidence decoded instruction after each boundary.
3. Remove only suspect boundary rows that fall between the text boundary and that next high-confidence instruction.
4. Preserve a raw listing note under `Text padding branch targets skipped`.

This avoids a broad traversal rule while still removing branch targets proven to sit inside a known text padding range.

## Confirmed Skips

- ECL1 block 84: `0x99E0` inside `0x9898..0xA1D0`
- ECL1 block 112: `0x85F8` inside `0x85F6..0x8620`
- ECL1 block 113: `0x8DAD` inside `0x8D6E..0x8DCF`

## Counts After This Pass

- Total suspect boundaries after the later operand/prefix pass: 46
- Branch/table referenced suspects after the later operand/prefix pass: 0
- Event pseudocode inline invalid operand details: 0
- Structured pseudocode inline invalid operand details: 0

## Remaining Hard Referenced Targets

Resolved in `docs/operand-05-and-prefix-target-pass-1.md`.

## Next Step

Inspect the remaining four hard referenced targets one by one. The likely order is:

1. ECL1 block 18 `ON GOTO` table alignment.
2. ECL1 block 95 museum exhibit carousel, because many branches converge there.
3. ECL1 block 35 launch bay join target.
4. ECL1 block 114 Nikita `GOSUB`, which may reveal a real command variant or prior target issue.
