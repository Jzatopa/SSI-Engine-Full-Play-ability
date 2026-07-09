# ECL Text Context Pass 1

## Goal

Attach the Gold Box Explorer whole-block ECL strings that remain missing after
substring comparison to nearby decoded ECL rows. This is evidence for future
dialog/menu reconstruction, not a runtime text promotion pass.

## Changes

- Added `scripts/contextualize_goldbox_ecl_text.py`.
- Added `tests/test_goldbox_ecl_text_context.py`.
- Generated:
  - `generated/ecl_text_goldbox/goldbox_ecl_text_context.json`
  - `generated/ecl_text_goldbox/goldbox_ecl_text_context.tsv`
  - `generated/ecl_text_goldbox/goldbox_ecl_text_context.md`

## Evidence

The script reads `generated/ecl_text_goldbox/ecl_text_compare.json`, takes
`comparison.goldbox_substring_missing_hits`, maps each decoded ECL block offset
to VM-style address with:

```text
vm_address = 0x8000 + decoded ECL block offset
```

It then records the nearest decoded rows from `generated/ecl1_disasm/`.

Current generated summary:

- Context rows: 123 hit rows.
- ECL blocks represented: 27.
- Context kinds:
  - `short_choice_or_label`: 103
  - `label_fragment`: 13
  - `inline_text_fragment`: 7

The previous Gold Box comparison's 75 count was unique text count after
normalization. This pass records hit-level context, so duplicate strings at
different offsets are intentionally preserved.

## Interpretation

Most remaining Gold Box whole-block-only strings look like menu choices, labels,
or prompt fragments (`CONVINCE`, `DECLINE`, `WHO WILL TRY?`, `CURRENT FUEL:`,
`SEE FILES`, and similar). Several rows sit in broad gaps between decoded
instructions, which supports treating them as inline data or branch-local menu
resources until a control-flow/data-table pass proves exact ownership.

Do not wire these strings directly into runtime dialog yet. The useful next
step is to teach the ECL compiler about menu/prompt data regions around the
high-value blocks, especially ECL 95 ship service labels and the repeated
`WHO WILL TRY?`/choice prompts in ECL 80, 82, 84, 96, 97, 98, 112, and 113.

## Commands

```bash
source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_goldbox_ecl_text_context.py
source .venv/bin/activate && PYTHONPATH=src python3 scripts/contextualize_goldbox_ecl_text.py
```

