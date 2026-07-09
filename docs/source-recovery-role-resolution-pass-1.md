# Source Recovery Role Resolution Pass 1

Date: 2026-06-29

## Scope

Resolved the 23 high-value `GAME.OVR` source-recovery role hypotheses into static triage decisions.

In this pass, "resolved" means the function is no longer in the unknown/likely-only queue. It does not mean the behavior is runtime-validated, and it does not recover original function names.

## Generated Artifacts

- `scripts/resolve_source_recovery_roles.py`
- `generated/source_recovery/function_role_resolution.json`
- `generated/source_recovery/function_role_resolution.md`
- `tests/test_source_recovery_role_resolution.py`

## Resolution Counts

- Candidates: 23.
- Resolved static decisions: 23.
- Statically liftable behavior candidates: 18.
- Stub/boundary candidates: 3.
- Bad-decode/not-liftable candidates: 2.

Status counts:

```text
resolved_static: 18
resolved_stub_or_boundary: 3
resolved_bad_decode: 2
```

## Key Resolutions

- `0000:fb92 FUN_0000_fb92`: combat roster and battlefield setup. It initializes combat tables, walks the party list, records combatant pointers/status/facing, and queues battlefield placement entries.
- `1000:8467 FUN_1000_8467`: character record initial field fill. It fills 0x55 bytes into the active character record.
- `1000:8e7d FUN_1000_8e7d`: character roster removal/compaction.
- `1000:c010 FUN_1000_c010`: shop item grant or inventory insertion.
- `1000:eb60 FUN_1000_eb60`: item type classification dispatch.
- `1000:eeec FUN_1000_eeec`: equipment flag postprocess or active item refresh.
- `1000:f67d FUN_1000_f67d`: save slot or filename selection/validation.
- `1000:fad0 FUN_1000_fad0`: save-character/save-game writer preflight.
- `1000:fb92 FUN_1000_fb92`: save linked item-chain writer continuation.
- `2000:13fd FUN_2000_13fd`: serialized party save-size calculator.
- `2000:1fd4 FUN_2000_1fd4`: character inventory-chain count.
- `2000:25a1 FUN_2000_25a1`: character-sheet text/buffer emit helper.
- `2000:2986 FUN_2000_2986`: inventory item-line formatter.
- `2000:3ea6 FUN_2000_3ea6`: equipped item category search.
- `2000:b749 FUN_2000_b749`: ship effective rating with damage penalties.
- `2000:b876 FUN_2000_b876`: ship status flag and message emit.
- `3000:006f FUN_3000_006f`: wall segment decode or emit routine, not the `Load3DMap` loader.
- payload `0x30AD0-0x30C10`: `Load3DMap` file-load/copy routine candidate from raw disassembly.

## Resolved As Not Liftable

- `0000:0385 FUN_0000_0385`: bad decode or mixed code/data near the credits anchor. Ghidra reports overlapping instructions, bad instruction data, abnormal stack setup, and removed blocks.
- `1000:0131 FUN_1000_0131`: empty combat boundary candidate.
- `1000:ce56 FUN_1000_ce56`: empty shop boundary candidate.
- `2000:1c53 FUN_2000_1c53`: empty save boundary candidate.
- `3000:0c04 FUN_3000_0c04`: misaligned Ghidra entry inside the `Load3DMap` epilogue instruction. It should not be lifted as a function.

## Interpretation

The 23 candidates are resolved enough to guide implementation work:

- Save/load work should start with `2000:13fd`, `1000:f67d`, `1000:fad0`, and `1000:fb92`.
- Item/inventory work should start with `1000:eb60`, `1000:eeec`, `2000:2986`, and `2000:3ea6`.
- Combat validation should start with `0000:fb92`.
- Ship mode should start with `2000:b749` and `2000:b876`.
- Map/wall work should treat `3000:006f` as a wall segment decoder/emitter candidate.
- `Load3DMap` work should start from payload `0x30AD0-0x30C10`, not from Ghidra function `3000:0c04`.

## Validation

Commands:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/resolve_source_recovery_roles.py
PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_source_recovery_roles.py
PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_role_resolution.py
PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py
PYTHONPATH=src python3 -m pytest -q
```

Result:

```text
2 passed
6 passed
165 passed
```

DeepSeek sidecar reviewed the supplied evidence and agreed with the central caveat: the 23 candidates are resolved for static triage, not original function names or runtime-validated behavior. It also flagged the boundary/stub classifications and bad-decode region as places that still need raw-byte/Ghidra xref inspection before any behavior is promoted.
