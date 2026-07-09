# Load3DMap Cluster Resolution Pass 1

Date: 2026-06-29

## Scope

Resolved the stale ambiguity around the `Load3DMap`/WALLDEF Ghidra nearest-function cluster.

Previous state:

- `3000:006f` looked behavior-rich but was far from the `Load3DMap` text anchor.
- `3000:0c04` was closer to the anchor but decompiled as a tiny return/stub-like function.

New raw-disassembly evidence resolves that split.

## Generated Artifacts

- `scripts/resolve_load3dmap_cluster.py`
- `generated/source_recovery/load3dmap_cluster_resolution.json`
- `generated/source_recovery/load3dmap_cluster_resolution.md`
- `tests/test_load3dmap_cluster_resolution.py`

## Resolution

- The `Load3DMap` text anchor is embedded string/data, not a function entry.
- Payload `0x30AAF-0x30ACF` decodes to ASCII bytes for `Unable to load geo in Load3DMap.`.
- The loader-shaped code window is payload `0x30AD0-0x30C10`.
- `3000:0c04` maps to payload `0x30C04`, which is inside the instruction beginning at payload `0x30C01`; the tiny return decompile is a misaligned-entry artifact.
- `3000:006f` remains a wall/span emit candidate, not the `Load3DMap` file-load/copy routine.

## Load3DMap-Shaped Code Evidence

The code at payload `0x30AD0-0x30C10`:

- opens/loads a `GEO` resource using filename text built around the embedded strings,
- checks for loaded size `0x402`,
- copies four `0x100` byte chunks from global buffer `0x7360`,
- closes/releases the loaded block,
- writes the selected map byte to active state at `*(0x4418)+0xC5`,
- returns with `retf 0x2`.

Confidence:

- `Load3DMap` text anchor is string/data: 99%.
- `0x30AD0-0x30C10` is the loader-shaped routine: 90%.
- `3000:0c04` is a misaligned epilogue entry: 99%.
- `3000:006f` is not the loader: 85%.

## Validation

Commands:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/resolve_load3dmap_cluster.py
PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_load3dmap_cluster.py scripts/resolve_source_recovery_roles.py scripts/triage_unknown_source_recovery_batch.py scripts/label_all_unknown_source_recovery.py
PYTHONPATH=src python3 -m pytest -q tests/test_load3dmap_cluster_resolution.py
PYTHONPATH=src python3 -m pytest -q tests/test_load3dmap_cluster_resolution.py tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py tests/test_unknown_source_recovery_batch.py tests/test_all_unknown_source_recovery_labels.py
PYTHONPATH=src python3 -m pytest -q
```

Expected result:

```text
2 passed
12 passed
171 passed
```

DeepSeek sidecar responded successfully. It verified the supplied facts that `0x30AAF-0x30ACF` is string/data, `0x30AD0-0x30C10` is loader-shaped code, `3000:0c04` is a misaligned Ghidra entry inside the epilogue instruction, and `3000:006f` is not the `Load3DMap` loader. It also correctly flagged that this does not yet mean a full runtime-validated reconstruction of `Load3DMap`.
