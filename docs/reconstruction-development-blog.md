# Matrix Cubed Reconstruction Development Blog

This is the running build log for the private Buck Rogers: Matrix Cubed reconstruction. It is written as a small blog post series so the same workflow can accelerate future game-recovery projects: preserve evidence, decode formats into reusable data, build interactive viewers early, then promote verified behavior into source that can target desktop EXE and web builds.

## Why This Process Matters

The fastest path is not to hand-port screens one at a time. The useful pattern is:

1. Catalog the original files and extract stable data formats.
2. Generate human-readable artifacts that make errors obvious.
3. Build a browser/runtime viewer as a visual debugger.
4. Promote verified behavior into a runtime-neutral source package.
5. Keep pass notes and tests beside every promoted assumption.

That lets a future project reuse the same ladder: asset extraction, map/event atlas, input flow map, encounter cross-reference, runtime scaffold, then target-specific frontends.

## Steps Taken So Far

### 1. Source Inventory And Asset Extraction

The extracted DOS game lives at `<local Matrix Cubed source folder>`. The reverse-engineering workspace was created at `<project root>/` and mirrored to `<local durable mirror>/`.

Image export work produced `<local extracted image gallery>` with a browsable gallery and thousands of PNGs. This established that the original DAX image assets could be reused as evidence and frontend material.

### 2. DAX, ECL, And GEO Baseline

The early scripts decoded the main DAX block inventory, disassembled `ECL1.DAX`, and parsed `GEO1.DAX` maps. These generated:

- `generated/ecl1_disasm/`
- `generated/geo1/`
- `generated/event_atlas/`
- `generated/source_like_maps/`

This moved the work from opaque binaries into inspectable map and event artifacts.

### 3. ECL Cleanup And Semantic Naming

Several cleanup passes removed unknown opcode and suspect boundary markers, normalized prefixes and fallthroughs, and added conservative names for recurring memory fields. The main outcome was confidence that generated event pseudocode was no longer being polluted by obvious parser mistakes.

Useful pass notes include:

- `docs/complex-command-cleanup-pass-1.md`
- `docs/referenced-suspect-audit-pass-1.md`
- `docs/unknown-prefix-normalization-pass-1.md`
- `docs/semantic-memory-pass-1.md`

### 4. Visual Runtime Prototype

The runtime viewer started as a 16x16 map debugger and grew into a Gold Box-style first-person corridor prototype with wall textures from `WALLDEF1.DAX`, tactical map, event text, and event inspector.

Main artifact:

- `generated/viewer/matrix_cubed_runtime_prototype.html`

This viewer is valuable because every decoded format can be checked visually before being promoted into source.

### 5. Behavior Bridge

The browser runtime gained placeholder behavior for combat, rewards, damage, transitions, conditions, and event logging. This was a bridge from passive viewing toward a playable reconstruction.

Pass note:

- `docs/runtime-behavior-bridge-pass-1.md`

### 6. Startup And Opening Flow

The startup/opening sequence was reconstructed from `TITLE.DAX`, `BIGPIC1.DAX`, `START.EXE`, and `GAME.OVR` evidence. Later passes expanded the character-management branch and built the full startup input map through `Begin Adventuring / Game Starts`.

Main artifacts:

- `generated/opening/matrix_cubed_opening_sequence.html`
- `generated/startup_input_map/startup_input_map.html`
- `generated/startup_input_map/startup_input_map.json`

The important correction was that the real startup command menu includes Create/Purge/Modify/Train/View/Add/Remove Character, Load Saved Game, Save Current Game, Begin Adventuring, and Exit to DOS.

### 7. Data Model Catalog

The source-data pass decoded and cataloged:

- 182 model/data blocks
- 63 `MON0CHA.DAX` monster/character records
- 91 `ITEM0.DAX` item templates
- 118 `MON0SPC.DAX` effect records

Main artifact:

- `generated/data_model/data_model_catalog.md`

Important finding: `MON0CHA.DAX` is a 259-byte Matrix Cubed variant. Names and base stats decode cleanly, but old Gold Box offsets do not directly map to every Matrix Cubed stat, so uncertain fields remain candidate fields until call-site or live validation confirms them.

### 8. Encounter-To-Monster Cross-Reference

The encounter pass connected ECL `SETUP_MONSTER` references to `MON0CHA.DAX` names and stats.

Main artifacts:

- `generated/encounters/encounter_monster_xref.md`
- `generated/encounters/dynamic_encounter_analysis.md`

Results:

- 184 encounter-related ECL rows
- 142 direct constant rows linked to monsters
- 13 dynamic rows needing table/data-flow resolution
- 29 sentinel or picture-only rows

The runtime viewer now shows monster identities in event inspection, including Caloris event 7 resolving to `RAM WARRIOR`.

### 9. Source Runtime Scaffold

The project now has a Python package under `src/matrix_cubed/` with reusable DAX/GEO format helpers, generated-data loaders, map movement, wall blocking, event lookup, and a CLI probe.

Main files:

- `src/matrix_cubed/formats/`
- `src/matrix_cubed/data/repository.py`
- `src/matrix_cubed/engine/runtime.py`
- `src/matrix_cubed/tools/runtime_probe.py`
- `tests/test_runtime_probe.py`

This is the first runtime-neutral source layer. The goal is for desktop EXE packaging and web frontends to consume the same decoded data and behavior model instead of each becoming separate rewrites.

## Current Development Note

Qwen usage means `qwen3-coder:30b` only. It is available but slow and currently lower trust than deterministic local decoding, so it should stay out of the inner loop for binary/table work and only be used as a bounded sidecar for broad review checklists when it saves more time than it costs.

Local environment note: use `python3`, not `python`, in this shell.

## Update: Event Command IR

The newest source pass added a small runtime-neutral event command layer:

- `src/matrix_cubed/engine/events.py`
- `GameState.execute_current_event()`
- structured `last_execution` data in runtime snapshots

Instead of the runtime only saying "combat" or directly mutating placeholder state, decoded events now compile into commands such as `show_text`, `queue_combat`, `grant_credits`, `grant_item`, `damage_party`, `mark_transition`, and `mark_condition_checked`.

This matters for faster future development because it creates a reusable bridge between decoded evidence and playable source. A web frontend, a Python/Pygame frontend, and a packaged desktop EXE can all consume the same command stream while the decoder gradually promotes more exact ECL semantics.

Validated example: Caloris Space Port event 7 now emits `show_text` plus `queue_combat`, with the combat payload resolving `RAM WARRIOR` and its decoded stats from `MON0CHA.DAX`.

Pass note:

- `docs/source-runtime-event-ir-pass-1.md`

## Update: Queued Combat State And Dynamic Encounter Candidates

The next source pass promoted combat state from a plain string into a runtime-neutral `QueuedCombat` model:

- `src/matrix_cubed/engine/combat.py`
- `GameState.active_encounter`
- structured `active_combat` data in runtime snapshots

The loader now preserves dynamic encounter candidate evidence from the generated runtime seed. This is important for Matrix Cubed because some `SETUP_MONSTER` calls do not contain a constant monster id; they pull a value from an ECL table or state field. The source runtime now keeps those cases honest by separating:

- exact `monster_names`
- table-backed `candidate_monster_names`
- unresolved ECL operands in `unresolved_monster_refs`

Example: Caloris event 7 still resolves exactly to `RAM WARRIOR`. GEO 021 event 4 now queues candidate monsters from table evidence: `MER. WARRIOR`, `PIRATE LEADER`, `RAM WARRIOR`, and `SECURITY ROBOT`, while preserving the unresolved operand `area2.event_scratch7`.

This pattern matters for future game-recovery work because it avoids a common reverse-engineering trap: blocking playable development until every branch is perfect, or worse, pretending uncertain dynamic data is exact. The runtime can advance with an explicit confidence boundary, and later data-flow passes can narrow candidates without changing the frontend contract.

Pass note:

- `docs/source-runtime-combat-queue-pass-1.md`

## Update: Bounded Qwen Sidecar

The local Qwen route is now treated as a boxed advisory helper rather than a truth source. The wrapper at `../.agents/ralph/qwen-ollama-agent.sh` was tightened for deterministic coding assistance:

- `temperature: 0.1`
- `top_p: 0.8`
- `top_k: 20`
- `repeat_penalty: 1.05`
- default timeout: 360 seconds

The system prompt now explicitly forbids invented APIs, paths, filenames, commands, config keys, offsets, test results, and unsupported facts. It also requires a structured advisory shape: verified facts, files to inspect, hypotheses, implementation plan, validation plan, risks, and an unsupported-claims audit.

An additional rejection layer fails closed when Qwen emits illustrative or guessed names/paths. In testing, a prompt asking for exact save filenames without evidence was rejected as unusable, while a bounded liveplay advisory passed without fabricating filenames.

This matters for future reconstruction and similar projects because Qwen can still help with checklist-shaped review and repetitive coding advice, but Codex remains responsible for reading files, stepping the game, applying patches, running tests, and accepting only locally verified claims.

## Update: Liveplay Save Characters

The emulator path now produces real Matrix Cubed character save artifacts. Using DOSBox-X under Xvfb with slow `xdotool` input, the reliable character creation flow reaches:

- `REROLL STATS? YES NO`
- `CHARACTER NAME:`
- career skill allocation
- technical skill allocation
- icon confirmation
- `SAVE <name>? YES NO`

Two disposable characters were saved:

- `MATRIX/SAVE/TST1.WHO`
- `MATRIX/SAVE/TST1.STF`
- `MATRIX/SAVE/TST2.WHO`
- `MATRIX/SAVE/TST2.STF`

The `.WHO` files are 259 bytes, the same record size as the Matrix Cubed `MON0CHA.DAX` variant. Confirmed live offsets now include name, ability scores, race/gender/career id candidates, level, credits, experience, age, and an HP candidate field. The new source parser keeps only those evidence-backed fields named:

- `src/matrix_cubed/formats/save.py`
- `src/matrix_cubed/tools/save_probe.py`
- `tests/test_save_formats.py`
- `generated/liveplay/save_probe.json`

This is a faster reverse-engineering loop than static guessing: create a controlled live sample, diff the save directory, parse the changed bytes, then promote only screen-backed offsets into source. The next samples should vary one thing at a time: race, gender, career, skill allocation, icon choice, and then add-to-team/game-save behavior.

Pass note:

- `docs/liveplay-save-character-pass-1.md`

## Update: Controlled Save Samples And Slot A

The save-file loop now has controlled variants and the first active-party game save:

- `RAC1`: Martian, Male, Rocket Jock
- `GEN1`: Terran, Female, Rocket Jock
- `CAR1`: Terran, Male, Medic

Those samples corrected the first-pass enum assumption. Current evidence-backed candidates:

- `.WHO` / `CHRDATA*.SAV` offset `0x26`: gender id, with `0=male`, `1=female`
- offset `0x27`: race id, with `1=terran`, `2=martian`
- offset `0x28`: career id, with `1=rocket_jock`, `2=medic`

Adding `CAR1` to the team and saving slot A deleted `CAR1.WHO/.STF` from the loose roster and created:

- `CHRDATA1.SAV` at 259 bytes
- `CHRDATA1.STF` at 124 bytes
- `SAVGAMA.DAT` at 2901 bytes

The active-party `CHRDATA1.SAV` parses with the same 259-byte character parser. `SAVGAMA.DAT` begins with `01`, which is a party-count candidate after saving one active party member, but it needs a two-character party sample before promotion.

New generated summaries:

- `generated/liveplay/save_probe.json`
- `generated/liveplay/controlled_save_samples.md`
- `generated/liveplay/controlled_save_samples.json`

This also updates the practical liveplay route: use Add Character to Team, select Matrix, mark a character, select Exit, then Save Current Game slot A.

## Update: Compiler Runtime Identification

Qwen Coder was used as the only model-side analyst for a compiler/runtime identification pass. Codex gathered local evidence from `START.EXE` and `GAME.OVR`, then sent that evidence to `qwen3-coder:30b` through Ollama with token metadata capture.

Evidence included:

- `START.EXE` is an MS-DOS MZ executable.
- `GAME.OVR` starts with `FBOV`.
- `START.EXE` contains `Runtime error`, `Overlay error, program abort!`, `Please insert overlay disk.`, and `Portions Copyright (c) 1983,90 Borland`.
- Binary-mode i8086 disassembly shows normal stack-frame and far-call patterns.

Qwen Coder's bounded verdict: most likely Borland 16-bit DOS x86 toolchain/runtime with Borland overlay manager/runtime. Exact compiler/version is not proven, and current evidence does not cleanly distinguish Borland C/C++ from Turbo Pascal-era runtime components.

The recovery implication is practical: keep using Ghidra for 16-bit x86/overlay analysis and recover C-like pseudocode where stable, but do not try to rebuild the project with the original compiler as the main path.

Qwen Coder token metadata from Ollama:

- first prompt: 962 prompt + 341 output = 1303
- follow-up: 627 prompt + 322 output = 949
- total Qwen Coder tokens: 2252

Pass note:

- `docs/compiler-runtime-qwen-coder-pass-1.md`

## Milestone: Save Formats, Liveplay, and Runtime Foundation

Four new Python format parsers:

- `src/matrix_cubed/formats/game_state.py` — SAVGAMA.DAT (2901-byte game state)
- `src/matrix_cubed/formats/stf.py` — .STF skill/equipment records (124 bytes)
- `src/matrix_cubed/tools/game_state_probe.py` — before/after diff analyzer
- `src/matrix_cubed/formats/__init__.py` — consolidated format exports

Extensive liveplay automation: three scripts (bash + 2x Python) using DOSBox-X + Xvfb + xdotool. Character creation, team management, and Begin Adventuring are automated. The game world loads (Caloris Space Port map visible in EGA text-mode).

**Key obstacle**: In-game save key sequence could not be identified. Fifteen+ key combinations tested (S, F5-F10, Escape, 9, 1+0, Enter+S, Ctrl+O) across three MATRIX.CFG formats and three save directory paths. None wrote save files. GAME.OVR evidence confirms "Save Which Game: A B C D E F G H I J" and "Rest Save Change Exit" exist in the binary, but the trigger key remains unknown without screen-readable feedback.

**Project direction**: Build the runtime source with decoded data, hardcoding initial game state, and write the save format from the running runtime. Validate against the original game when a save can be produced.

**Test status**: 15 passing, 0 failing.

Milestone doc:

- `docs/reconstruction-milestone-2.md`

## Update: Pygame Desktop Runner

The first Pygame desktop frontend is live at `src/matrix_cubed/tools/pygame_runner.py`. It drives the existing GameState runtime — movement, event triggering, combat queuing — and renders a 16×16 overhead map, first-person direction indicator, event text overlay, and status panel. WASD/Q/E controls, SPACE to advance events, ESC to quit.

Key milestone: this is the first runtime that can be launched directly from the Python source without the web viewer dependency. The GameState runtime handles all the heavy lifting (movement, wall collision, event detection, combat queuing) — the Pygame frontend only renders and collects input.

Qwen Coder was used for the initial scaffold (layout, colours, rendering structure) via the hardened `--DIRECT` mode wrapper. Codex fixed API mismatches and wired to the actual runtime. Pattern: Qwen produces boilerplate (free), Codex validates and integrates (efficient).

Pass note:

- `docs/pygame-runner-pass-1.md`

**Test status**: 38 passing, 0 failing.

**Usage**: `cd matrix-cubed-re && PYTHONPATH=src python3 src/matrix_cubed/tools/pygame_runner.py`

## Update: Phase A Complete

Phase A (Source Runtime Core) is complete. The full pipeline works:
1. **Main menu** → New Game or Continue
2. **Character creation** → Name, race (Terran/Martian), career (Rocket Jock/Medic), stat point-buy
3. **Exploration** → WASD movement, Q/E turn, 16x16 overhead map, event text
4. **Combat** → Turn-based encounter resolution, player attacks first, victory/defeat
5. **Inventory/Character** → I/C overlay screens
6. **Save/Load** → Binary .WHO/.STF/.SAVGAMA.DAT persistence (96 tests)

External review caught encapsulation gaps (party state sync) and save-format risks. Both addressed.

**Test status**: 96 passing, 0 failing. 3,637 source+test lines.

Phase doc:
- `docs/phase-a-complete.md`
- `docs/phase-a-review-request.md`

Pass notes:
- `docs/pygame-runner-pass-1.md`
- `docs/character-creation-pass-1.md` (if written)

Usage: `cd matrix-cubed-re && source .venv/bin/activate && PYTHONPATH=src python3 src/matrix_cubed/tools/pygame_runner.py`
