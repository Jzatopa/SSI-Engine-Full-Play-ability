# Referenced Suspect Audit Pass 1

Date: 2026-06-19

## Goal

Audit the remaining suspect ECL boundaries that are referenced by `GOTO`, `GOSUB`, or `ON GOTO` after text-fallthrough handling removed the bulk of false command decoding.

## Result

After the text-boundary, text-padding-range, operand `0x05`, and one-byte prefix-target patches:

- Total suspect boundaries fell from 498 to 46.
- Referenced suspect targets fell from 11 to 0.
- The 440 simple `PRINT`/`PRINTCLEAR` fallthrough cases are no longer decoded as fake commands.
- Three interior text-padding branch targets were removed by the range pass.
- Four remaining referenced suspects were resolved by operand `0x05` decoding and one-byte prefix-target normalization.

## Remaining Referenced Targets

None after `docs/operand-05-and-prefix-target-pass-1.md`.

## Previously Remaining Targets

| ECL block | Address | Reference source | Initial read |
| --- | ---: | --- | --- |
| 18 | `0x94A6` | `ON GOTO` at `0x9494` | First menu case for Salvation's port lounge. Starts immediately after the branch table and decodes as `MULTIPLY` with an invalid third operand. Needs ON-table/case alignment review. |
| 35 | `0x9BDC` | Multiple `GOTO`s from launch bay text paths | Common join target after printing launch bay status. Likely points into a text/table continuation region rather than a true `ENCOUNTER MENU`. |
| 95 | `0x8D0D` | Many exhibit carousel `GOTO`s | Common join after museum exhibit text entries. Prior decoded context includes an unknown byte sequence before the target, so this may be a carousel table/end marker. |
| 114 | `0xA2CF` | `GOSUB` at `0x979E` | Nikita/tour subroutine target. Unlike most others, this is a subroutine reference after normal code, so it may indicate a real Matrix Cubed command variant or a prior length/target issue. |

## Resolved By Text-Padding Range Pass

- ECL1 block 84 `0x99E0`: inside `0x9898..0xA1D0`
- ECL1 block 112 `0x85F8`: inside `0x85F6..0x8620`
- ECL1 block 113 `0x8DAD`: inside `0x8D6E..0x8DCF`

## Interpretation

All branch-referenced suspect targets are currently resolved. Remaining suspect rows are fallthrough-only and should be grouped by preceding command before adding more traversal rules.

## Next Step

Group the remaining 46 fallthrough-only suspects by preceding command and look for another small operand or command-length rule.
