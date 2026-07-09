# Source Recovery Corpus Pass 1

Date: 2026-06-29

## Scope

Built a clean, reproducible source-recovery corpus from the existing full Ghidra decompile exports.

This pass does not recover original SSI source text. It organizes all available Ghidra pseudocode into a stable corpus with provenance headers, address mapping, and anchor roles so manual reconstruction can proceed from evidence instead of anonymous decompile files.

## Generated Artifacts

- `scripts/build_source_recovery_corpus.py`
- `generated/source_recovery/manifest.json`
- `generated/source_recovery/README.md`
- `generated/source_recovery/start_unpacked/*.c`
- `generated/source_recovery/game_ovr_payload/*.c`
- `tests/test_source_recovery_corpus.py`

## Coverage

- `START.unpacked.exe`: 358/358 recovered pseudocode files.
- `GAME.OVR` raw payload: 623/623 recovered pseudocode files.
- Combined recovered functions: 981/981.
- Ghidra decompile timeouts: 0.
- Missing decompile output files: 0.
- GAME.OVR recovered files with nearby project anchors: 23.

## Evidence Model

Each recovered pseudocode file starts with a header recording:

- imported program,
- Ghidra entry address,
- Ghidra function name,
- linear address,
- original `GAME.OVR` file offset when applicable,
- body address count,
- calling convention,
- evidence limits,
- nearby project anchors when known.

For `GAME.OVR`, the mapping remains:

```text
linear = segment * 16 + offset
original GAME.OVR file offset = linear + 8
```

## High-Value GAME.OVR Anchor Roles

The corpus marks nearby candidate functions for:

- combat,
- character creation,
- shop menu,
- item loading and item debug fields,
- save/load,
- inventory/gear menu,
- ship stats,
- wall/map loader and `Load3DMap`.

The current `Load3DMap` triage candidates remain:

- `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c`
- `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c`

## Limits

- The recovered corpus is Ghidra pseudocode, not source-equivalent code.
- Original variable names, source layout, compiler intent, and overlay relocation context are not recovered.
- `GAME.OVR` was imported as a raw overlay payload; the overlay manager context still needs a later overlay-aware analysis pass.
- Runtime changes should only be made after cross-checking these candidates against local bytes, generated data artifacts, and DOS captures.

## Validation

Commands:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/build_source_recovery_corpus.py
PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py
PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py
PYTHONPATH=src python3 -m pytest -q
```

Result:

```text
2 passed
161 passed
```

DeepSeek sidecar reviewed the supplied evidence and agreed with the main boundary: this is a complete corpus for the exported pseudocode files, but it is not source-equivalent original SSI code and still lacks overlay relocation/manager context for `GAME.OVR`.
