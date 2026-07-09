# Semantic Memory Pass 1

Date: 2026-06-19

## Goal

Move from decoder cleanup into source-like semantics by naming high-volume memory references that have clear, repeated roles.

## What Changed

`scripts/ecl_disassemble.py` now names the most common shared event scratch area in `AREA2`:

- `area2.event_scratch0` through `area2.event_scratch9` for offsets `0x6F2` through `0x704`.
- `area2.selected_player_name` for offset `0x000`, used by string operands that print the currently selected party member's name.
- `area2.division_remainder` for offset `0x67E`, based on divide/remainder use.

It also adds conservative `area1.event_word_XXX` names for the broad `AREA1` event-state range from `0x200` through `0x3FC`. These are intentionally generic because their meanings vary by map and event block. Specific known names such as `area1.current_city` and `area1.picture_fade` still take priority over the generic rule.

## New Report

Added `scripts/summarize_memory_refs.py`, which scans structured event pseudocode and emits:

- `generated/semantic/memory_refs.tsv`
- `generated/semantic/memory_refs.md`

The report ranks memory references by frequency and includes a top file and example line for each reference.

## Result

After regeneration:

- Suspect boundaries: 0
- Unknown opcode references in generated outputs: 0
- Invalid operand details in generated outputs: 0
- Top shared scratch reference is now named: `area2.event_scratch0` with 1,699 structured references.
- High-volume `AREA1` map/event fields now render as `area1.event_word_XXX` instead of `area1.word_XXX`.

## Next Targets

The next semantic pass should focus on `AREA2` engine fields and then replace generic `area1.event_word_XXX` labels only where map context proves a stronger name:

- Combat/setup fields around `area2.word_58C`, `area2.word_592`, `area2.word_596`, and `area2.word_58E`, after cross-checking their engine use.
- The small `area2.word_200` cluster in NEO Installation, which may be a special engine state rather than event scratch.
- Map-specific event names for high-volume blocks, starting with `area1.event_word_2C0`/`2BE` in the historical museum, `area1.event_word_372`/`376` in Stormrider University, and `area1.event_word_34A`/`34E` in the NEO Installation.
