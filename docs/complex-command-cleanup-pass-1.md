# Complex Command Cleanup Pass 1

Date: 2026-06-19

## Goal

Reduce false source-like output caused by the ECL walker decoding inline data as commands, especially noisy `ENCOUNTER MENU` rows with impossible operand codes.

## What Changed

- `scripts/ecl_disassemble.py` now treats operands outside the known ECL operand-code set (`0x00`, `0x01`, `0x02`, `0x03`, `0x80`, `0x81`) as a suspect data/code boundary.
- When a suspect boundary is hit, the raw ECL listing preserves the address and invalid codes, then stops linear decoding for that path.
- Cleanly decoded `ENCOUNTER MENU` commands now print source-like fields for sprite, max distance, picture, reaction mapping, prompt strings, auxiliary operands, and result operands.
- `scripts/emit_event_pseudocode.py` and `scripts/emit_structured_pseudocode.py` hide byte-level invalid operand details and emit a concise boundary comment.

## Example

Caloris Space Port event 01 previously emitted a fake `encounter_menu(...)` at `0x88B1`, followed by additional invented operations. Raw bytes and branch context show that the real target after the welcome text is `0x88B8`; the bytes at `0x88B1` are now marked as a suspect boundary instead of source-like logic.

The structured event now reads as:

```text
picture(block_id: 86);
or(area1.word_25E = 4 | area1.word_25E);
printclear("'WELCOME TO CALORIS...'");
// suspect data/code boundary at 0x88B1; stopped linear decode
```

## Regenerated Outputs

- `generated/ecl1_disasm/`
- `generated/event_atlas/`
- `generated/event_pseudocode/`
- `generated/event_structured/`
- `generated/suspect_boundaries/`

## Current Counts

- Raw ECL listings now retain 0 suspect invalid-operand markers.
- Event pseudocode has 0 inline invalid operand details.
- Structured pseudocode has 0 inline invalid operand details.
- Suspect boundary classifier found 0 total boundaries.
  - 440 former `PRINT`/`PRINTCLEAR` fallthrough cases are now skipped as text fallthrough boundaries

## Next Step

The suspect-boundary cleanup is complete. Next phase: group remaining `UNKNOWN_0x..` opcode references and determine which are true Matrix Cubed opcodes versus table/data bytes.
