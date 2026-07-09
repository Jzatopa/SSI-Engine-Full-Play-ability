# OpenClaw Pygame Runtime Validation Pass 1

Date: 2026-06-29

## Goal

Validate the desktop Pygame runtime in the OpenClaw workspace with Pygame installed, then leave a reproducible handoff for the next ChatGPT agent.

## Environment

- Workspace: `/home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re`
- Python: project `.venv`
- Pygame: 2.6.1, SDL 2.28.4
- Xvfb: `/usr/bin/xvfb-run`
- OpenClaw gateway environment present on this host.

## Runtime Fix

The real Pygame runner initially failed after menu entry because `MapEngine.load_map()` expected a `find_ecl()` repository method. `ReconstructedData` now exposes a compatibility adapter returning the runtime GEO, ECL block, events, and wallset metadata for a loaded map.

## Reproducible Smoke

Added `scripts/validate_pygame_runtime.py`.

Run:

```bash
source .venv/bin/activate
xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/validate_pygame_runtime.py
```

The script runs the real `Runner().run()` loop, posts keys to select Continue, toggles inventory, sends one movement key, captures the display, and exits with ESC.

Generated:

- `generated/runtime_validation/pygame_runner_xvfb_smoke.json`
- `generated/runtime_validation/pygame_runner_xvfb_smoke.png`

Latest result:

- status: `exited`
- display size: `1024x768`
- screenshot bytes: `9876`
- unique colors: `208`
- nonblack pixels: `662272`

## Validation

- `PYTHONPATH=src python3 -m py_compile scripts/validate_pygame_runtime.py src/matrix_cubed/data/repository.py src/matrix_cubed/tools/pygame_runner.py`
- `PYTHONPATH=src python3 -m pytest -q` -> 180 passed

## Boundary

This pass validates boot/menu/world-render/event-loop viability under Xvfb. It does not validate real-time manual play, audio, native window-manager behavior, or complete story-route correctness.
