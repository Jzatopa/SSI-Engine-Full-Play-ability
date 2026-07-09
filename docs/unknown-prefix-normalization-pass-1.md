# Unknown Prefix Normalization Pass 1

Date: 2026-06-19

## Goal

Resolve the remaining `UNKNOWN_0x..` opcode rows in raw ECL listings after suspect-boundary cleanup reached zero.

## Finding

The unknown rows clustered around byte values:

- `0x43`
- `0x4C`
- `0x42`
- `0x4B`
- smaller counts of `0x46`, `0x48`, `0x7F`, `0x45`, `0x44`, `0x41`

Every unknown row had a clean instruction start within the next 8 bytes, and nearly all had one within the next 4 bytes. This matched the earlier prefixed-command pattern rather than a true missing-opcode pattern.

## What Changed

`scripts/ecl_disassemble.py` now normalizes unknown-prefixed fallthroughs and branch targets:

1. If the current byte is not a known command opcode,
2. and a clean instruction start is found within 1-8 bytes,
3. the decoder continues at the clean instruction start,
4. and records the skipped address in the raw listing.

The normalized rows are preserved under:

- `Unknown-prefixed branch targets normalized`
- `Unknown-prefixed fallthroughs normalized`

## Result

- Unknown opcode references: 169 -> 0
- Suspect boundaries: 0
- Event pseudocode inline invalid operand details: 0
- Structured pseudocode inline invalid operand details: 0

## Remaining Work

The first-pass ECL decoder now has no raw `UNKNOWN_0x..`, `invalid operand code`, or suspect-boundary rows. Remaining reverse-engineering work should move from decoder hygiene to semantic naming:

- name repeated memory locations,
- improve command-specific renderers,
- validate branch/case semantics against map events,
- begin translating stable event blocks into source-like modules.
