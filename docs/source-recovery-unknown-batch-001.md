# Source Recovery Unknown Batch 001

Date: 2026-06-29

## Scope

Resolved 100 previously unknown `GAME.OVR` source-recovery functions using conservative static evidence.

This batch avoids subsystem guesses. It assigns only mechanically supported categories:

- bad decode or mixed code/data,
- return-only stub or boundary,
- single-call wrapper.

## Generated Artifacts

- `scripts/triage_unknown_source_recovery_batch.py`
- `generated/source_recovery/unknown_batch_001_resolution.json`
- `generated/source_recovery/unknown_batch_001_resolution.md`
- `tests/test_unknown_source_recovery_batch.py`

## Selection Policy

- Only `GAME.OVR` functions from the prior unknown queue were eligible.
- The batch stopped at 100 selected functions.
- Functions were selected only if static pseudocode shape was strong enough to avoid semantic guessing.
- The batch does not assign original function names.

## Results

- Eligible `GAME.OVR` unknowns before this batch: 600.
- Selected/resolved in this batch: 100.
- Remaining unbatched `GAME.OVR` unknowns after this batch: 500.
- Remaining unbatched unknowns across START plus GAME.OVR after this batch: 858.

Status counts:

```text
resolved_bad_decode: 24
resolved_stub_or_boundary: 37
resolved_static_shape: 39
```

Category counts:

```text
bad_decode_or_mixed_code_data: 24
return_only_stub_or_boundary: 37
single_call_wrapper: 39
```

## Interpretation

This batch is useful because it removes low-semantic-value functions from the unknown queue without inventing behavior:

- `bad_decode_or_mixed_code_data` entries should not be lifted until raw bytes and Ghidra xrefs are inspected.
- `return_only_stub_or_boundary` entries should be treated as padding, boundary, or possible misidentified function starts until xrefs prove otherwise.
- `single_call_wrapper` entries should be resolved by following their wrapped callees before assigning subsystem behavior.

## Validation

Commands:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/triage_unknown_source_recovery_batch.py
PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_source_recovery_roles.py scripts/triage_unknown_source_recovery_batch.py
PYTHONPATH=src python3 -m pytest -q tests/test_unknown_source_recovery_batch.py
PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py tests/test_unknown_source_recovery_batch.py
PYTHONPATH=src python3 -m pytest -q
```

Result:

```text
2 passed
8 passed
167 passed
```

DeepSeek sidecar reviewed the supplied evidence and agreed with the core boundary: this batch resolves static shape only, not runtime behavior or original names. It flagged the same risks around single-call wrappers needing caller/callee context and stub/boundary entries needing raw xref checks before omission.
