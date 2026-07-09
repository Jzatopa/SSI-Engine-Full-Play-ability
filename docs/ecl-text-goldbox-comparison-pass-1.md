# ECL Text Gold Box Explorer Comparison Pass 1

Date: 2026-06-27

## Goal

Port Gold Box Explorer's ECL text decompressor/whole-block scan and compare its extracted strings against the current generated ECL listings and event-atlas text.

## What Changed

Added:

- `scripts/compare_goldbox_ecl_text.py`
- `tests/test_goldbox_ecl_text.py`
- `generated/ecl_text_goldbox/ecl_text_compare.json`
- `generated/ecl_text_goldbox/ecl_text_compare.md`
- `generated/ecl_text_goldbox/goldbox_ecl_texts.tsv`
- `generated/ecl_text_goldbox/goldbox_ecl_texts_missing_from_current.tsv`
- `generated/ecl_text_goldbox/goldbox_ecl_texts_still_missing_after_substring.tsv`

The script ports the Gold Box Explorer logic from `DaxEclFile.cs`:

- scan decoded ECL blocks for `0x80, length, packed_text`,
- decode packed 6-bit text,
- apply the same readability filter,
- compare against quoted strings in `generated/ecl1_disasm/` and `generated/event_atlas/event_atlas.json`.

## Results

Command:

```bash
source .venv/bin/activate && PYTHONPATH=src:. python3 scripts/compare_goldbox_ecl_text.py
```

Output:

```text
Gold Box ECL text scan: 3662 hits, 3127 unique, 2027 unique missing from current outputs
```

Comparison report:

- Gold Box whole-block text hits: 3662
- Gold Box unique texts: 3127
- Current ECL listing unique texts: 1244
- Current event-atlas unique texts: 696
- Exact overlap with current outputs: 1100
- Exact-missing Gold Box unique texts: 2027
- Exact-or-substring overlap with current outputs: 3052
- Still missing after substring comparison: 75

## Interpretation

The exact-missing count is high because current outputs often combine several string operands into larger event text fields. After substring comparison, most Gold Box strings are already represented somewhere in the existing listings or event atlas.

The 75 still-missing unique strings are useful follow-up evidence. They are mostly:

- menu labels and ship/utility prompts (`CONTROLS:`, `ENGINES:`, `HULL:`, `FIGHT WHICH SHIP TYPE?`),
- player choices (`CONVINCE`, `DECLINE`, `KILL HIM`, `OPEN LOCK`),
- short continuation fragments (`HE CONTINUES`, `HIS SPEECH`),
- picture/program/resource labels (`BIGPIC`, `BOXPIC`, `PICTURE:`),
- a few likely false positives (`A 1JALLD88UJX0EL UNYH`, `PE:PE:BPDB`).

This confirms the current disassembler's operand text decoder is compatible with Gold Box Explorer, but the whole-block scan is valuable for dialog-system coverage because it finds strings that are not attached to current decoded instruction paths.

## Next Step

Use `goldbox_ecl_texts_still_missing_after_substring.tsv` to improve dialog/menu extraction. Do not blindly promote all whole-block hits into runtime conversations; first attach each string to a decoded instruction, branch target, menu command, or ECL block role.
