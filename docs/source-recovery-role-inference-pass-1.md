# Source Recovery Role Inference Pass 1

Date: 2026-06-29

## Scope

Used the recovered Ghidra pseudocode corpus to identify what original functions likely do.

This pass is intentionally conservative. It does not rename functions in runtime code, and it does not claim original source names. It emits role hypotheses for triage based on:

- existing GAME.OVR anchor proximity,
- original-file offset mapping,
- recovered pseudocode size,
- call count,
- direct-memory access count,
- visible string literals.

## Generated Artifacts

- `scripts/infer_source_recovery_roles.py`
- `generated/source_recovery/function_role_inference.json`
- `generated/source_recovery/function_role_inference.md`
- `tests/test_source_recovery_role_inference.py`

## Coverage

- Functions scanned: 981.
- Functions with inferred roles: 23.
- Functions left unknown: 958.

Confidence counts:

```text
high: 7
medium: 5
low: 11
unknown: 958
```

## Current Likely Roles

High-confidence candidates:

- `1000:8467 FUN_1000_8467`: character creation/setup candidate.
- `2000:1fd4 FUN_2000_1fd4`: character sheet/status candidate.
- `2000:b876 FUN_2000_b876`: ship status/travel-resource candidate.
- `2000:b749 FUN_2000_b749`: ship status/travel-resource candidate.
- `1000:fad0 FUN_1000_fad0`: save/load or save-character persistence candidate.
- `1000:eeec FUN_1000_eeec`: item catalog/detail/inventory data candidate.

Medium-confidence candidates:

- `2000:13fd FUN_2000_13fd`: save/load candidate near both load/save anchors.
- `1000:eb60 FUN_1000_eb60`: item loader candidate.
- `1000:f67d FUN_1000_f67d`: save-character persistence candidate.
- `0000:fb92 FUN_0000_fb92`: combat candidate with heavy direct-memory access.

Original low-confidence map/wall candidates:

- `3000:006f FUN_3000_006f`: call-heavy map/wall loader candidate, but far from the `Load3DMap` anchor.
- `3000:0c04 FUN_3000_0c04`: closer to the `Load3DMap` anchor, but decompiles as a tiny return/stub-like function.

## Interpretation

Superseded by `docs/load3dmap-cluster-resolution-pass-1.md`: raw disassembly shows the `Load3DMap` text anchor is embedded string/data, the loader-shaped code window is payload `0x30AD0-0x30C10`, `3000:0c04` is a misaligned epilogue entry, and `3000:006f` is not the `Load3DMap` loader.

## Validation

Commands:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/infer_source_recovery_roles.py
PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py
PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py
PYTHONPATH=src python3 -m pytest -q
```

Result:

```text
4 passed
163 passed
```

DeepSeek sidecar reviewed the supplied evidence and agreed with the conservative framing. It flagged the same main risks: missing overlay relocation context, possible role misassignment, `3000:0c04` as a possible stub/boundary artifact, and the need for behavioral validation before promoting any role hypothesis into runtime code.
