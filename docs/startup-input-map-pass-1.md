# Startup Input Map Pass 1

Date: 2026-06-20

## Goal

Map the game's startup inputs from launch/setup through the point where the game starts.

The stopping boundary for this pass is `Begin Adventuring / Game Starts`.

## What Changed

Added:

- `scripts/build_startup_input_map.py`
- `generated/startup_input_map/startup_input_map.json`
- `generated/startup_input_map/startup_input_map.md`
- `generated/startup_input_map/startup_input_map.html`

The generated graph contains 32 nodes and has no unresolved transition targets.

## Coverage

The map covers:

- graphics adapter selection,
- sound selection,
- alternate input selection,
- joystick calibration,
- save-path entry,
- loading/title/story advancement,
- startup command menu,
- create character,
- purge character,
- modify character,
- train character,
- view character,
- add character to team,
- remove character from team,
- load saved game,
- save current game,
- exit to DOS,
- begin adventuring / game start.

## Key Correction

This pass found stronger executable-string evidence for the startup command menu than the earlier compact seed menu.

`START.EXE` offsets `59986-60298` expose these command labels:

- `Create New Character`
- `Purge Character`
- `Modify Character`
- `Train Character`
- `View Character`
- `Add Character to Team`
- `Remove Character from Team`
- `Load Saved Game`
- `Save Current Game`
- `Begin Adventuring`
- `Exit to DOS`

The earlier opening reconstruction remains a visual stepping artifact, but this input map should now be treated as the stronger menu topology seed.

## Source Evidence

Primary evidence comes from `START.EXE` and `GAME.OVR` strings, including:

- setup prompts at `START.EXE` offsets `5287`, `5444-5566`, `5639-5734`,
- joystick calibration prompt at `START.EXE` offset `45461`,
- loading/saving prompts at `START.EXE` offsets `29259` and `29338`,
- title/story advance prompt at `START.EXE` offset `60968`,
- character menu labels at `START.EXE` offsets `59986-60156`,
- main load/save/begin/exit labels at `START.EXE` offsets `60190-60298`,
- character creation prompts at `GAME.OVR` offsets `99509-99586`,
- character skill prompts at `GAME.OVR` offsets `154711-156292`,
- load/save prompts at `GAME.OVR` offsets `134527`, `136472`, and `129678`,
- quit confirmation at `GAME.OVR` offset `98188`.

## Qwen Attempt

Historical note: an early Qwen 3.6 attempt was made before the project standard was tightened to Qwen Coder only.

I attempted the existing local/network Qwen advisory wrapper with `RALPH_OLLAMA_MODEL=qwen3.6:latest`, but it timed out after 20 seconds:

- `QWEN_ADVISORY_UNAVAILABLE`

No Qwen output was used for this pass.

Current policy: future "Qwen" usage means `qwen3-coder:30b`, not Qwen 3.6.

## Validation

Checks performed:

- Python compile for `scripts/build_startup_input_map.py`.
- Generated JSON, Markdown, and HTML.
- Graph validation: 32 nodes, zero missing transition targets.
- Headless Chromium render check: 32 cards and 32 nav links.

Screenshot:

- `/home/jzatopa/Downloads/matrix-cubed-assets/viewer-check/matrix_startup_input_map.png`

## Next Step

The next useful phase is to resolve the remaining inferred edges with either DOSBox capture or deeper Ghidra control-flow review, especially:

- exact title/story skip behavior,
- whether loaded saves return to the menu or directly into map runtime,
- exact remove-character confirmation behavior,
- exact view-character sub-tabs,
- exact create-character race/gender/class option lists and ordering.
