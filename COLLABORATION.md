# Shared Agent Coordination

This file coordinates GoldenBox/OpenAI and Claude Code in the same canonical
project tree:

`<project root>`

The convenient OpenClaw path
`<project root>` is a symlink to
that same directory. They are not separate copies.

## Protocol

Before editing, add one row under **Active work** with your agent name, task,
and the files/directories you intend to change. Claims should be narrow. If a
needed file is already claimed, stop and coordinate through James or choose
non-overlapping work.

After completing and validating a pass, move the row to **Completed work** and
include the date and test result. Update `HANDOFF.md` for durable technical
findings. Do not use this file as a substitute for the handoff.

Do not edit the same source file concurrently. Read-only inspection is always
allowed. Shared high-contention files such as `HANDOFF.md` should be updated
only at the end of a pass after re-reading their latest contents.

## Current project frame

James's 2026-07-09 direction: the goal is a near-preservation-level universal
Java SSI Gold Box engine. Buck Rogers: Matrix Cubed is the first full-game proof
target; Curse of the Azure Bonds is also available locally and should become an
early secondary validation target after the Buck Rogers path is stable.

Architecture target:

- UI-neutral Java engine core for rules, VM/ECL execution, file formats,
  save/load, combat, menus, and game services.
- Swing/AWT is the first production desktop frontend adapter, not the place
  where core gameplay logic should live.
- Title-specific data, rules, and quirks belong behind game/rules/data
  profiles.
- COAB is a direct porting/reference source for universal Gold Box engine
  behavior. Port code/logic into Java, cite source repo/commit/file, test it,
  and keep title-specific values candidate until validated against local
  original files/runtime behavior.
- Preserve original quirks and bugs when known; document them so later cleanup
  can be intentional.

## Active work

| Agent | Task | Claimed paths | Started |
|---|---|---|---|

**Mega-pass status (2026-07-08, after two session-limit interruptions; full
detail in `HANDOFF.md` top section):** tracks A (attack), B (map), E (loot)
are landed WITH passing tests; track D (party/clock) is quarantined at
`references/ssi-engine/.partial-coab-tracks/engine-party-v2/` pending
`NpcPartyService` + `engine/time/`; track C (quick-fight AI) not started.
Build green: 213 tests, 0 failures. Committed as `0a1e8ae` + `7db8de4` on
`matrix-cubed-fork`. Policy going forward (James): max TWO subagents at a
time, cheapest adequate model; commit before/after agent rounds; quarantine
(never delete) partial files that break the build.

## Completed work

| Agent | Task | Changed paths | Completed / validation |
|---|---|---|---|
| GoldenBox (+ Qwen3-Coder sidecar) | COAB/SSI low-hanging review + VM clock integration: wired already-ported `GameClock` into the VM `CLOCK2` opcode with COAB word-backed ECL clock slots, leaving `CLOCK1` and effect/party hooks unresolved | `references/ssi-engine/src/main/java/engine/VirtualMachine.java`, `references/ssi-engine/src/main/java/engine/VirtualMemory.java`, `references/ssi-engine/src/test/java/engine/VirtualMachineEclConformanceTest.java`, `references/ssi-engine/docs/coab-java-stub-audit.md`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-09; focused `VirtualMachineEclConformanceTest,GameClockTest` passed with local Matrix dir; full Java 289 tests / 0 failures / 0 errors / 7 pre-existing skips; `run-combat-scene.sh` reaches `Final COMBAT_RESULT=0`; Qwen3-Coder advisory accepted for mapping-test coverage only |
| GoldenBox (+ Qwen3-Coder sidecar) | Combat slice 2: wired live monster/auto turns to the ported COAB `QuickFightPlanner` through `CombatStateQuickFightView`, replacing `RecoveredEnemyTactics` in the runtime path while keeping unsupported spells/items/morale/flee/ranged hooks neutral/deferred | `references/ssi-engine/src/main/java/engine/combat/CombatController.java`, `references/ssi-engine/src/main/java/engine/combat/ai/CombatStateQuickFightView.java`, `references/ssi-engine/src/test/java/engine/combat/CombatControllerTest.java`, `references/ssi-engine/src/test/java/engine/combat/ai/CombatStateQuickFightViewTest.java`, `references/ssi-engine/docs/coab-combat-port-map.md`, `references/ssi-engine/docs/night-work-order-2026-07-09.md`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-09; focused Java `CombatControllerTest,CombatStateQuickFightViewTest,QuickFightPlannerTest` passed; full Java 288 tests / 0 failures / 0 errors / 7 pre-existing skips; `run-combat-scene.sh` reaches `Final COMBAT_RESULT=0`; Qwen3-Coder advisory accepted only for high-level adapter/test mapping |
| GoldenBox | Reframed project docs around universal near-preservation Java Gold Box engine, COAB-as-porting-source, Buck Rogers first validation, Curse of the Azure Bonds secondary validation target, UI-neutral core, and Swing/AWT frontend adapter | `CLAUDE.md`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-09; docs-only; `git diff --check` run on changed docs |
| GoldenBox (+ Qwen-Coder sidecar) | Matrix skill-check opcode recovery: generated repeatable opcode `0x23` callsite evidence, mapped the one constant first operand to recovered skill id 79 / `Etiquette` / `.WHO 0x9B`, captured WHO prompt contexts, and ran Qwen advisory without VM/combat integration edits | `scripts/recover_skill_check_opcodes.py`, `scripts/qwen_skill_check_advisory.py`, `generated/skill_check_recovery/2026-07-08/`, `docs/matrix-skill-check-recovery-2026-07-08.md`, `tests/test_skill_check_recovery.py`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-08; recovery script wrote 3 opcode `0x23` callsites and 3 WHO contexts; Qwen skill-check jobs 3/3 returncode 0; focused pytest 4 passed; full Python suite 197 passed |
| GoldenBox (+ Qwen-Coder sidecar) | Matrix skill-table recovery: recovered START.EXE skill id/name table, validated GAME.OVR `0x4C + skill_id` character-byte accessors, generated local/Qwen advisory artifacts, and wired all 84 recovered Buck skills into Java non-zero skill decoding | `scripts/recover_matrix_skills.py`, `scripts/qwen_skill_recovery_advisory.py`, `generated/skill_recovery/2026-07-08/`, `docs/matrix-skill-recovery-2026-07-08.md`, `references/ssi-engine/src/main/java/character/buckrogers/CharacterSkillBuckRogers.java`, `references/ssi-engine/src/main/java/data/character/AbstractCharacter.java`, `references/ssi-engine/src/main/java/data/character/CharacterBuckRogers.java`, `references/ssi-engine/src/test/java/data/character/CharacterBuckRogersTest.java`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-08; nested `ssi-engine` commit `fdddd9f`; Qwen skill jobs 3/3 returncode 0; focused `CharacterBuckRogersTest` passed; full Java `mvn test` passed; `run-combat-scene.sh` reaches `Final COMBAT_RESULT=0`; skill-check opcode semantics remain future work |
| GoldenBox (+ Qwen-Coder sidecar) | Qwen-Coder advisory orchestration across Ghidra triage, Ghidra-to-COAB matching, unknown offset clustering, test matrix generation, port-map comparison, and OCR sanity review | `scripts/qwen_coder_advisory.py`, `generated/qwen_advisory/2026-07-08/`, `docs/qwen-coder-advisory-2026-07-08.md`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-08; all six Qwen jobs returned 0 via `ollama/qwen3-coder:30b`; `python3 -m py_compile scripts/qwen_coder_advisory.py` passed; JSON metadata all returncode 0; Ghidra triage TSV has 624 lines (623 functions plus header). All outputs are advisory only |
| GoldenBox (+ Qwen-Coder sidecar) | CharacterBuckRogers WHO decode alignment: fixed Java Buck Rogers natural/current ability offsets, age byte, 32-bit credits, HP mapping regression coverage, and exposed only the verified `PILOT_ROCKET` skill byte while leaving movement/THAC0 unresolved | `references/ssi-engine/src/main/java/data/character/CharacterValues.java`, `CharacterBuckRogers.java`, `character/buckrogers/CharacterSkillBuckRogers.java`, `references/ssi-engine/src/test/java/data/character/CharacterBuckRogersTest.java`, `HANDOFF.md`, `COLLABORATION.md` | 2026-07-08; focused `CharacterBuckRogersTest` passed; full Java 277 tests / 0 failures / 0 errors / 7 pre-existing skips; `run-combat-scene.sh` reaches `Final COMBAT_RESULT=0` |
| Claude Code (coordination) + Sonnet | Integration slice 1: wired ported attack resolution into `CombatState.attack()` via `Combatant`→AttackerView/DefenderView adapters (neutral/candidate for the 26-field gap; no fabricated Buck stats). Review caught + fixed a descending/ascending hit-scale bug (attacker skill was cancelling out); added skill-drives-hit-chance behavioral tests | `references/ssi-engine/src/main/java/engine/combat/CombatState.java` + new `attack/CombatantAttackerView.java`, `CombatantDefenderView.java`; `src/test/java/engine/combat/CombatStateTest.java` + `attack/CombatantAttackViewsTest.java` | 2026-07-08; nested-repo commit `1640949`; mvn test 284/0/7; `run-combat-scene.sh` COMBAT_RESULT=0 with skill-varying hit/miss |
| Claude Code (+ Haiku) | Qwen skeptic pass: re-verified the 97 first-run candidates against actual COAB source — 0 yes / 87 no / 10 unresolvable; killed all 79 CMD_Compare/RunEclVm bucket anchors. Meta-finding: naive whole-catalog matching hit its ceiling; avenue parked | `scripts/qwen_skeptic_pass.py`, `generated/qwen_advisory/ghidra_coab_skeptic/`, `references/ssi-engine/docs/qwen-ghidra-skeptic-results-2026-07-08.md` | 2026-07-08; candidate/advisory only; committed (outer + nested repos) |
| GoldenBox | Establish shared Claude/OpenAI workspace protocol | `CLAUDE.md`, `COLLABORATION.md`, `HANDOFF.md` | 2026-07-07; documentation-only setup |
| Claude Code (+ Sonnet subagents) | COAB mega pass tracks C (quick-fight AI: intent-producing planner, 25 branch-pinned tests) and D (NPC party lifecycle + game clock, 37 tests; faithful quirks documented; NPC_FIND-opcode evidence note) | `references/ssi-engine/src/{main,test}/java/engine/combat/ai/` (7+1 classes), `engine/party/` (6+2), `engine/time/` (1+1) | 2026-07-08; full suite 275 passed / 0 failed / 7 pre-existing skips at nested-repo commit `e130f62`; `run-combat-scene.sh` reaches `COMBAT_RESULT=0` |
| Claude Code (+ Sonnet subagents) | COAB mega pass tracks A (attack flow), B (map/LOS/movement), E (treasure/money): ported as self-contained packages with passing tests. Caveat: agents were killed by session limits before delivering final reports — provenance-javadoc audit still owed (HANDOFF remaining-work item 3) | `references/ssi-engine/src/{main,test}/java/engine/combat/attack/` (10+5 classes), `engine/combat/map/` (8+2), `engine/loot/` (11+3) | 2026-07-08; suite 213 passed / 0 failed / 7 pre-existing skips at nested-repo commit `7db8de4` |
| Claude Code (+ Sonnet subagent) | Headless end-to-end smoke harness: game detection, party creation, original ECL 17 → real VM combat, save/load round trip; `MatrixCubedCombatScene.main()` extracted into callable `runToCombat(...)` (output unchanged) | `references/ssi-engine/src/test/java/integration/MatrixCubedSmokeTest.java` (new), `references/ssi-engine/src/main/java/main/MatrixCubedCombatScene.java`, `HANDOFF.md` | 2026-07-08; full Java `mvn test` 82 passed / 0 failed / 7 pre-existing skips (all 4 smoke tests ran against local MATRIX dir; they Assume-skip elsewhere) |
| Claude Code | Combat port pass 2: COAB `damage_player` dying/unconscious/dead semantics + `BattleRoundChecks` (bleeding ticks, teammate-dying warning, 15-round no-action expiry re-armed by attacks, `RoundEndHook` effect slot) | `references/ssi-engine/src/main/java/engine/combat/Combatant.java`, `CombatState.java`, `CombatController.java`, new `src/test/java/engine/combat/CombatantTest.java`, `CombatStateTest.java`, `docs/coab-combat-port-map.md`, `HANDOFF.md` | 2026-07-08; full Java `mvn test` 78 passed / 0 failed / 7 pre-existing skips; headless `run-combat-scene.sh` reaches `COMBAT_RESULT=0` with live bleed-out in transcript |
| Claude Code | Combat port pass 1: replaced placeholder `CombatTurnQueue` with COAB delay-based initiative/turn selection (`ovr014.CalculateInitiative` + `ovr009.FindNextCombatant`, coab `9dc46f1`; adaptations labeled in class javadoc) | `references/ssi-engine/src/main/java/engine/combat/CombatTurnQueue.java`, `references/ssi-engine/src/test/java/engine/combat/CombatTurnQueueTest.java` (10 conformance tests), `CombatStateTest.java`/`CombatControllerTest.java` (order-agnostic rewrites), `references/ssi-engine/docs/coab-combat-port-map.md`, `HANDOFF.md` | 2026-07-08; full Java `mvn test` 66 passed / 0 failed / 7 pre-existing skips; headless `run-combat-scene.sh` reaches `COMBAT_RESULT=0` with initiative-varying turn order |
| Claude Code | COAB→Java combat port map: surveyed COAB combat overlays (`~/.local/opt/coab`, `9dc46f1`), mapped combat loop/initiative/round semantics onto the Java scaffold, defined universal-vs-flavor boundary and 7-pass port order with Ghidra GAME.OVR as Buck-delta finder | `references/ssi-engine/docs/coab-combat-port-map.md` (new), `HANDOFF.md` | 2026-07-07; docs-only, no source changes; Java `mvn test` green at pass start |
| Claude (Cowork) | Made the hardcoded original-game-directory path overridable via `MATRIX_CUBED_GAME_DIR` env var across Python scripts/tests (portability hardening; no formula/evidence changes) | `scripts/game_paths.py` (new), `scripts/analyze_game_ovr.py`, `scripts/audit_coab_engine_reference.py`, `scripts/decode_monster_inventory.py`, `scripts/review_reverse_engineering_packages.py`, `scripts/build_data_model_catalog.py`, `scripts/compare_goldbox_ecl_text.py`, `scripts/audit_original_capture_targets.py`, `scripts/analyze_local_files.py`, `scripts/decode_original_files.py`, `scripts/analyze_item_name_mapping.py`, `scripts/audit_goldbox_explorer_maps.py`, `scripts/analyze_combat_ai.py`, `scripts/scan_game_ovr_maps.py`, `tests/test_item_name_mapping.py`, `tests/test_coab_engine_reference.py`, `tests/test_game_paths.py` (new) | 2026-07-07; full Python suite 191/193 passed with `MATRIX_CUBED_GAME_DIR` set (2 pre-existing failures in `test_source_recovery_corpus.py` are unrelated: external Ghidra corpus + sandbox permission limit), 186/193 passed with the var unset (same 7 pre-existing failures as before this pass, unchanged) |

## Suggested next work

High-value work, in priority order:

1. **Combat movement/LOS validation slice**: replace the QuickFight adapter's
   open-field neutral `TileTraits` with Matrix Cubed wall/height traits once
   decoded, then compare pathing/visibility against local original-game/DOS
   captures.
2. **Clock/effect integration follow-up**: resolve `CLOCK1` per-title
   semantics, then connect `GameClock` party-aging and effect-timeout hooks to
   real party/effect state instead of leaving them as standalone services.
3. **Character and combat-stat validation**: continue Buck Rogers character
   field/stat recovery only from local evidence. Keep unknown combat stats
   neutral/candidate until verified.
4. **DOS/original-game validation targets**: capture Matrix Cubed combat
   behavior for initiative, attacks, damage ranges, NPC join flow, and AI
   decisions. Add Curse of the Azure Bonds as a secondary local validation
   target after the Matrix path is stable.
5. **Skill-check opcode dataflow**: use
   `generated/skill_check_recovery/2026-07-08/skill_check_opcodes.tsv` as the
   queue. ECL95 has constant skill id 79 / `Etiquette` / `.WHO 0x9B`; ECL34 and
   ECL98 variable operands still need local dataflow and runtime validation.
6. **Licensing/attribution cleanup before public release**: COAB and other
   reconstruction sources may be ported now, but attribution and license
   compatibility need a dedicated pass before any public distribution.

Protocol reminders: claim narrow paths here before editing; commit nested-repo
checkpoints (`references/ssi-engine` is its own git repo, branch
`matrix-cubed-fork`) before/after each work round; keep the suite green and
label all new values candidate until validated.

## Shared environment

- Canonical project: `<project root>`
- OpenClaw symlink: `<project root>`
- Durable mirror: `<local durable mirror>`
- Matrix original files: `$MATRIX_CUBED_GAME_DIR`
- Python tests: activate `.venv`, set `PYTHONPATH=src`, and use dummy SDL drivers
- Java project: `references/ssi-engine`, forked from upstream
  `https://gitlab.com/farmboy0/ssi-engine` at base commit `f10f96f` (GPL-3.0;
  see `HANDOFF.md` "Known Issues & Gotchas" #11 and
  `references/ssi-engine/docs/matrix-cubed-fork-plan.md` for the fork plan
  and licensing note). Goal (James, 2026-07-07): this engine should
  eventually play any Gold Box game, Buck Rogers: Matrix Cubed first.
- James's local OpenClaw setup runs on this same physical machine and has a
  working Maven/JDK toolchain and DOSBox already installed. Claude (Cowork)
  sessions run in a separate sandboxed shell on this machine — file tools
  (Read/Write/Edit/Grep/Glob) can reach any host path once James shares it,
  but the sandboxed shell (bash) is a different execution environment, so
  host-native binaries found this way are not guaranteed to run there without
  testing. See `HANDOFF.md` Known Issues #0 for what's been verified so far.
