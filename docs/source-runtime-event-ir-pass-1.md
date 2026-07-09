# Source Runtime Event IR Pass 1

Date: 2026-06-20

## Goal

Move event execution one step closer to reusable source by replacing one-off placeholder behavior with a small runtime-neutral event command layer.

## Added

- `src/matrix_cubed/engine/events.py`
  - `EventCommand`
  - `EventExecution`
  - `compile_event_commands()`
- `GameState.execute_current_event()`
- `GameState.last_execution`
- Structured `last_execution` output in runtime snapshots

## Command Types Promoted

- `show_text`
- `queue_combat`
- `grant_credits`
- `grant_item`
- `damage_party`
- `mark_transition`
- `mark_condition_checked`
- `inspect_only`

## Why It Matters

The runtime now exposes event behavior as data instead of only mutating state directly. That gives future desktop EXE and web builds a shared contract:

1. compile decoded event evidence into commands
2. execute commands against game state
3. render commands in whatever frontend is active

This also creates a safe landing zone for future ECL promotion. As individual opcodes and operands are confirmed, they can emit more specific commands without rewriting the frontend or the movement/runtime shell.

## Validation

Commands run:

```bash
PYTHONPATH=src python3 tests/test_runtime_probe.py
python3 -m compileall -q src tests
PYTHONPATH=src python3 -m matrix_cubed.tools.runtime_probe --generated-dir generated --map-id 17 --event-id 7 --execute --out generated/source_runtime/caloris_event_7_probe.json
```

Results:

- Caloris event 7 compiles to `show_text` and `queue_combat`.
- The combat payload resolves `RAM WARRIOR` from `MON0CHA.DAX`.
- Reward-classified events compile into `grant_credits` and `grant_item`.
- Source and tests compile under `python3`.

## Notes

The shell has `python3` but not `python`; repeatable commands should use `python3`.

Qwen Coder was not used for this pass. The work was deterministic source integration and tests, where local evidence was faster and safer.
