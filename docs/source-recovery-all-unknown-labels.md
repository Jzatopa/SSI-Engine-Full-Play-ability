# Source Recovery All Unknown Labels

Date: 2026-06-29

## Scope

Labeled every function that remained unknown after source-recovery role inference.

This pass does not assign original function names and does not claim runtime behavior. It gives each formerly unknown function a conservative static-shape label and a confidence percentage for that label.

## Generated Artifacts

- `scripts/label_all_unknown_source_recovery.py`
- `generated/source_recovery/all_unknown_function_labels.json`
- `generated/source_recovery/all_unknown_function_labels.md`
- `tests/test_all_unknown_source_recovery_labels.py`

## Coverage

- Total prior unknowns labeled: 958.
- `GAME.OVR` labels: 600.
- `START.unpacked.exe` labels: 358.
- Already covered by unknown batch 001: 100.
- Newly labeled outside batch 001: 858.

Status counts:

```text
labeled_static_shape: 648
labeled_for_followup: 219
labeled_boundary_or_stub: 49
labeled_not_liftable_without_raw_review: 42
```

Label counts:

```text
single_call_wrapper: 174
multi_call_small_helper: 131
small_local_computation_or_data_move: 128
direct_memory_state_helper: 96
large_no_call_data_transform: 62
call_heavy_coordinator: 54
return_only_stub_or_boundary: 49
bad_decode_or_mixed_code_data: 42
string_referencing_helper: 3
insufficient_static_evidence: 219
```

## Confidence Policy

Confidence values are attached to every label.

Important interpretation:

- Confidence is about the static label being correct.
- Confidence is not about original function names.
- Confidence is not runtime validation.
- `insufficient_static_evidence` has high confidence because it means the script is deliberately refusing to guess.

Examples:

- `single_call_wrapper` at 88% means the function is very likely a small wrapper around one visible callee.
- `call_heavy_coordinator` at 70% means the function is likely a coordinator by shape, but not yet a named subsystem.
- `insufficient_static_evidence` at 99% means the safe label is "do not infer behavior from this pseudocode alone."

## Use Policy

- Use these labels to prioritize review and prevent repeated rediscovery.
- Do not promote `labeled_for_followup` entries into runtime behavior without xrefs, raw bytes, DOS captures, or caller/callee context.
- Do not omit `return_only_stub_or_boundary` entries until raw xrefs confirm they are not meaningful entry points.
- Treat `bad_decode_or_mixed_code_data` as not liftable until Ghidra/disassembly boundaries are corrected.

## Validation

Commands:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/label_all_unknown_source_recovery.py
PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_source_recovery_roles.py scripts/triage_unknown_source_recovery_batch.py scripts/label_all_unknown_source_recovery.py
PYTHONPATH=src python3 -m pytest -q tests/test_all_unknown_source_recovery_labels.py
PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py tests/test_unknown_source_recovery_batch.py tests/test_all_unknown_source_recovery_labels.py
PYTHONPATH=src python3 -m pytest -q
```

Result:

```text
2 passed
10 passed
169 passed
```

DeepSeek sidecar responded successfully. It agreed with the main boundary: these are static labels, not original names or runtime-validated behavior. It also highlighted the same follow-up buckets: `insufficient_static_evidence` entries need more evidence before behavior labels, and `bad_decode_or_mixed_code_data` entries need raw-byte/Ghidra boundary review.
