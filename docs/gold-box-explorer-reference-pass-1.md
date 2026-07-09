# Gold Box Explorer Reference Pass 1

Date: 2026-06-19

## Goal

Use Bil Simser's Gold Box Explorer as a reference implementation for SSI Gold Box file formats, especially Matrix Cubed ECL/GEO/DAX behavior.

## Reference Source

Cloned a shallow reference copy:

- `references/gold-box-explorer`
- upstream: `https://github.com/bsimser/Gold-Box-Explorer`
- commit: `eac30abaa6ee66aea6f5d65ebe6d676b10015a8f`
- license: MIT

Most relevant files:

- `src/Common/Plugins/DaxEcl/Program.cs`
- `src/Common/Plugins/DaxEcl/Commands.cs`
- `src/Common/Plugins/DaxEcl/Memory.cs`
- `src/Common/Plugins/GeoDax/GeoDaxFile.cs`
- `src/Common/Plugins/FileHelper.cs`

## Findings

Gold Box Explorer confirmed the core ECL command table and the Matrix Cubed-compatible memory ranges used by the local decoder.

The useful table differences were:

- `ECL CLOCK` (`0x34`) should use two operands.
- `ADD NPC` (`0x36`) should use two operands.

It also confirmed/refined command semantics for:

- `DIVIDE`: quotient is stored at the requested destination and the remainder is stored in `area2.division_remainder`.
- `LOAD CHARACTER`: selects a player by index.
- `PARTY SURPRISE`: takes a zone/encounter value and result slot.
- `ROB`, `FIND ITEM`, `DAMAGE`, `CALL`, and `ADD NPC` can render more clearly than raw operands.

## What Changed

Updated `scripts/ecl_disassemble.py`:

- Changed opcode `0x34` arity to 2.
- Changed opcode `0x36` arity to 2.
- Fixed the lookahead validator so operand code `0x05` consumes its high byte just like the main operand loader.
- Improved renderers for:
  - `DIVIDE`
  - `LOAD CHARACTER`
  - `PARTY SURPRISE`
  - `ROB`
  - `CALL`
  - `DAMAGE`
  - `FIND ITEM`
  - `ECL CLOCK`
  - `ADD NPC`
  - `PARTYSTRENGTH`
  - `CHECKPARTY`

## Result

After regeneration:

- ECL listings: 33
- Event pseudocode files: 25
- Structured event pseudocode files: 25
- Suspect boundaries: 0
- Unknown opcode markers in generated outputs: 0
- Invalid operand markers in generated outputs: 0

The Gold Box Explorer reference is useful and should remain in the workspace as a cross-check for future command and memory naming passes.

## Next Step

Use `GeoDaxFile.cs` and `Memory.cs` next to cross-check:

- Matrix Cubed map names and GEO event linking.
- unresolved `AREA2` fields around combat/encounter setup.
- wallset and `WALLDEF` loading behavior.
