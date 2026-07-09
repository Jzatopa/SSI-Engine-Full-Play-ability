# Matrix Cubed Reconstruction — Handoff Record

> Created: 2026-06-21 21:13 CDT
> Updated: 2026-07-09 CDT
> Purpose: Full context for any agent continuing this work

## Project North Star Update (2026-07-09, James's direction)

The project goal is now framed as a near-preservation-level universal Java SSI
Gold Box engine. Buck Rogers: Matrix Cubed remains the first proof target
because local original files, generated artifacts, and smoke tests already
exist, but the architecture should support the wider SSI Gold Box catalog.
Curse of the Azure Bonds is also available on this computer and should become
an early secondary validation target after the Buck Rogers path is stable.

Architecture target:

- UI-neutral Java engine core for rules, VM/ECL execution, file formats,
  save/load, combat, menu state, and game services;
- Swing/AWT as the first production desktop frontend adapter;
- title-specific data, quirks, and rules behind game/rules/data profiles rather
  than hardcoded into the universal core.

COAB should be treated as a direct porting/reference source for universal Gold
Box engine behavior: port the relevant logic into Java, cite the COAB
repo/commit/file, add focused Java tests, and then validate against Matrix
Cubed or another local original game where feasible. COAB-derived values remain
ported/candidate for a specific title until independently checked against that
title's local files or runtime behavior.

Preservation standard:

- preserve original behavior and gameplay-affecting quirks when known;
- document preserved bugs/quirks so later optional fixes can be intentional;
- keep original game files external and load user-provided installs;
- do not bundle original data into the repo;
- a subsystem is not complete until source/evidence are recorded, focused tests
  cover the behavior, the Matrix Cubed smoke path remains green, and
  original-game/DOS validation is added where feasible.

## Policy Update: External Gold Box Code Reuse (2026-07-07, James's direction)

James confirmed the end goal: the Java `ssi-engine` fork should become a
universal engine that can play any Gold Box game, Buck Rogers: Matrix Cubed
is the first game to bring to full playability, and agents should reuse
already-built code from COAB / Gold Box Explorer / similar community
reconstructions where it saves time rather than re-deriving everything from
scratch. This updates the prior `CLAUDE.md` stance (which restricted COAB to
secondary evidence only, citing its unclear local license). His explicit
choice was "reuse now, sort licensing later" — see the updated `CLAUDE.md`
working rules for the guardrails that still apply (record source/commit,
keep reused logic behind the universal engine boundary, don't promote a
reused project's game-specific values as confirmed Matrix Cubed evidence
without independent validation). Licensing/attribution compliance is
explicitly deferred and will need a dedicated pass before any public
release.

## Shared OpenAI / Claude Code Workspace (2026-07-07)

- Both agents now work from the same canonical directory:
  `<project root>`.
- `CLAUDE.md` contains Claude Code startup, evidence, safety, validation, and
  completion instructions.
- `COLLABORATION.md` is the live file-claim ledger. Each agent must claim narrow
  paths before editing, avoid concurrently claimed files, and move completed
  work into its completion table.
- The project remains embedded in the larger `<OpenClaw workspace>`
  Git repository and contains nested reference repositories. No new Git repo or
  worktree was created; agents must scope Git inspection/checks to
  `matrix-cubed-re` and preserve unrelated parent-workspace changes.

---

## 1. Project Overview

### Latest Pass: Combat Slice 2 QuickFightPlanner Live AI Wire (2026-07-09, GoldenBox + Qwen3-Coder sidecar)

- Replaced the live monster-turn `RecoveredEnemyTactics` scaffold in
  `CombatController.resolveMonsterTurn()` with one persistent COAB
  `QuickFightPlanner` per combat controller, preserving the planner's
  remembered-target state across turns.
- Added `engine.combat.ai.CombatStateQuickFightView`, a UI-neutral adapter from
  `CombatState`/`Combatant` into `QuickFightBattleView` and
  `QuickFightCombatantView`. Geometry delegates to the already-ported
  `CombatMapService` with open-field neutral `TileTraits` until Matrix Cubed
  tile height/wall traits are decoded.
- Implemented live intent execution for `ATTACK`, `MOVE_TOWARD`, `GUARD`, and
  `END_TURN`. Unsupported COAB intents (`FLEE`, `SURRENDER`, `BANDAGE`,
  `TURN_UNDEAD`, spell/item use, weapon switching) intentionally end the turn
  for now and are documented as deferred rather than faked.
- Kept missing `Combatant` facts neutral in the adapter: no spells, items,
  morale/NPC control, ranged weapon, undead/turning, held, forced-fleeing, or
  Buck-specific stat values are invented.
- Added focused tests:
  `CombatStateQuickFightViewTest` covers team mapping, map-service geometry,
  enemy filtering, and neutral unsupported capability hooks;
  `CombatControllerTest` now proves an adjacent monster uses the planner path
  to execute a real attack intent.
- Qwen3-Coder sidecar ran via `ollama/qwen3-coder:30b` with a 300s timeout for
  adapter/test design. Useful high-level advice accepted: keep a persistent
  adapter/planner, map attack/move/end-turn directly, and test unsupported
  intent degradation. Invented method/API names from the advisory were ignored.
- Boundary: live monster AI now uses the ported COAB decision planner, but
  Matrix-specific movement costs, wall traits, morale/flee/surrender,
  spells/items/skills, ranged weapons, guarding effects, and DOS/original-game
  AI parity validation remain future work.
- Validation:
  - focused Java
    `<project root>/.tools/apache-maven-3.9.9/bin/mvn -q -Dtest=CombatControllerTest,CombatStateQuickFightViewTest,QuickFightPlannerTest test`
    -> pass;
  - full Java
    `<project root>/.tools/apache-maven-3.9.9/bin/mvn -q test`
    -> 288 tests / 0 failures / 0 errors / 7 pre-existing skips;
  - `references/ssi-engine/scripts/run-combat-scene.sh` ->
    `Final COMBAT_RESULT=0`, with monster moves/attacks and the
    `QuickFightPlanner live AI wire` evidence line in the transcript.

### Latest Pass: Matrix Skill-Check Opcode Evidence (2026-07-08, GoldenBox + Qwen-Coder sidecar)

- Added repeatable Matrix skill-check opcode evidence generation in
  `scripts/recover_skill_check_opcodes.py`, writing
  `generated/skill_check_recovery/2026-07-08/`.
- Current ECL listings contain three opcode `0x23` callsites. The generic
  disassembler still labels them as `SURPRISE`, while the Java stub audit
  records Matrix opcode `0x23` as a `SKILL_CHECK` candidate:
  - ECL34 `0xA13D` uses variable operands
    `area2.event_scratch1, area2.event_scratch2, area2.event_scratch3,
    area2.word_002`;
  - ECL95 `0x9705` uses constant first operand `79`, which maps through the
    recovered skill table to `Etiquette` at `.WHO` offset `0x9B`;
  - ECL98 `0xA21C` uses variable operands
    `area2.event_scratch1, area2.event_scratch2, area2.event_scratch3`.
- Recorded direct WHO prompt contexts for later correlation:
  ECL35 `0x8EB5` (`WHO WILL REPROGRAM?`), ECL35 `0xA168`
  (`WHO WILL FAST TALK?`), and ECL82 `0x8CB5`
  (`WHO MAKES THE ATTEMPT?`).
- Qwen-Coder sidecar ran via `ollama/qwen3-coder:30b` for three bounded jobs:
  opcode 0x23 callsite review, WHO/skill prompt correlation, and disassembler
  label boundary. All returned 0. Useful advice accepted: do not globally
  rename opcode `0x23` yet, require Matrix-aware/profile-gated naming for any
  future disassembler change, and trace variable operands locally before
  assigning skill/result roles. Unsupported prompt-to-skill guesses were not
  accepted.
- Wrote `docs/matrix-skill-check-recovery-2026-07-08.md` and focused tests in
  `tests/test_skill_check_recovery.py`.
- Boundary: this pass does not implement VM behavior, opcode success rules,
  thresholds, selected-character/party-skill rules, advancement/training, or
  combat integration. It intentionally avoids the active Claude combat/VM
  claim.
- Validation:
  - `python3 scripts/recover_skill_check_opcodes.py` -> 3 opcode `0x23`
    callsites and 3 WHO contexts;
  - `python3 scripts/qwen_skill_check_advisory.py --timeout 300` -> 3 Qwen
    jobs, all return code 0;
  - `python3 -m py_compile scripts/recover_skill_check_opcodes.py
    scripts/qwen_skill_check_advisory.py` -> pass;
  - `PYTHONPATH=src python3 -m pytest -q tests/test_skill_check_recovery.py`
    -> 4 passed;
  - full Python suite fallback `PYTHONPATH=src python3 -m pytest -q` ->
    197 passed.

### Latest Pass: Matrix Skill Table Recovery (2026-07-08, GoldenBox + Qwen-Coder sidecar)

- Recovered the Buck Rogers skill id/name table from local `START.EXE`
  Pascal strings and documented the evidence in
  `docs/matrix-skill-recovery-2026-07-08.md`.
- Verified the storage rule from `GAME.OVR` decompiled accessors:
  skill values are read/written at character record offset
  `0x4C + skill_id` for real skill ids `1..0x54`. Skill id 0 is the
  `technical Skills` header/category string and is not treated as a real
  skill.
- Generated repeatable artifacts under
  `generated/skill_recovery/2026-07-08/`:
  `skill_names.{tsv,json}`, `sample_skill_values.{tsv,json}`, README, and
  Qwen-Coder prompts/raw outputs/JSON metadata under `qwen/`.
- Qwen-Coder sidecar was used via `ollama/qwen3-coder:30b` for three bounded
  advisory jobs: skill table mapping review, sample value clustering, and Java
  implementation boundary review. All returned 0. Useful advice accepted:
  keep id 0 as a header/non-skill, expose non-zero skills in `getSkills()`,
  and test exact byte-backed values. Unsupported Qwen claims about id/name
  certainty were not accepted without local START.EXE/GAME.OVR validation.
- Java nested repo commit:
  `fdddd9f Decode Buck Rogers skill table`.
  Changes:
  - `CharacterSkillBuckRogers` now enumerates all 84 recovered skills and
    carries each skill id / `.WHO` offset.
  - `AbstractCharacter` exposes a protected unsigned file-byte reader for
    game-specific byte tables without expanding the universal
    `CharacterValueType` table.
  - `CharacterBuckRogers.getSkillValue()` can read any recovered Buck skill;
    `getSkills()` returns only non-zero skills.
  - `CharacterBuckRogersTest` now covers synthetic multi-skill reads, TST2
    rocket-jock fixture values, and CHRDATA1/CAR1 medic fixture values.
- Boundary: skill names and byte offsets are recovered; `SKILL_CHECK` /
  `PARTY_SKILL_CHECK2/3` opcode success rules, advancement/training rules,
  skill thresholds, and VM/combat integration remain future work. `.STF` files
  remain inventory/item records in current evidence, not the skill table.
- Validation:
  - `python3 scripts/recover_matrix_skills.py` -> 84 skills and 265 non-zero
    sample values;
  - `python3 scripts/qwen_skill_recovery_advisory.py --timeout 300` -> 3 Qwen
    jobs, all return code 0;
  - focused Java
    `../../.tools/apache-maven-3.9.9/bin/mvn -q -Dtest=data.character.CharacterBuckRogersTest test`
    -> pass;
  - full Java `../../.tools/apache-maven-3.9.9/bin/mvn -q test` -> pass;
  - `references/ssi-engine/scripts/run-combat-scene.sh` ->
    `Final COMBAT_RESULT=0`.

### Latest Pass: Qwen-Coder Advisory Orchestration (2026-07-08, GoldenBox)

- Added repeatable Qwen-Coder sidecar orchestration in
  `scripts/qwen_coder_advisory.py`, using the working model route
  `ollama/qwen3-coder:30b` with extended per-job timeouts for the slower
  local/network model path.
- Completed all six requested advisory workstreams with return code 0:
  Ghidra function triage rule review, Ghidra-to-COAB candidate matching,
  unknown offset clustering, test matrix generation, COAB port-map comparison,
  and OCR/text sanity boundary review.
- Generated durable artifacts under
  `generated/qwen_advisory/2026-07-08/`, including exact prompts, raw model
  outputs, JSON run metadata, and
  `ghidra_function_triage_candidates.tsv`, a deterministic metadata-only queue
  covering all 623 Ghidra `GAME.OVR` candidate functions plus a header row.
- Wrote the local assessment in
  `docs/qwen-coder-advisory-2026-07-08.md`. The useful outputs are offset/test
  planning and OCR boundary review; the Ghidra-to-COAB matching output is
  explicitly low-confidence and must not be treated as verified function
  identity.
- Boundary: all Qwen-Coder results remain advisory. No offset, function name,
  opcode behavior, combat formula, map-state claim, or COAB port status is
  promoted without local byte/source/test validation.
- Validation:
  - `python3 -m py_compile scripts/qwen_coder_advisory.py` -> pass;
  - generated metadata check confirms all six JSON records have return code 0;
  - `ghidra_function_triage_candidates.tsv` contains 624 lines
    (623 functions plus header).

### Latest Pass: Java CharacterBuckRogers WHO Decode Alignment (2026-07-08, GoldenBox + Qwen-Coder sidecar)

- Ported verified Python `.WHO`/CHRDATA offset evidence into the Java
  Buck Rogers character mapping:
  - natural/base abilities are `0x10..0x16` in order
    `str,dex,con,int,wis,cha,tech`;
  - current abilities are `0x17..0x1D` in the same order;
  - age is a single byte at `0x38`;
  - credits are 32-bit little-endian at `0x2B`;
  - natural/current HP remain `0x45` / `0xE3` as supported by live save
    captures.
- Fixed the prior Java mapping bugs in `CharacterValues.BUCK_ROGERS`:
  current/natural abilities had been swapped, `WIS_NATURAL` was aliased to
  `0x19`, Buck age used the shared short mapping, and credits used the shared
  short money mapping.
- Added `character.buckrogers.CharacterSkillBuckRogers` with only the
  currently mapped/proven skill surface, `PILOT_ROCKET`, and made
  `CharacterBuckRogers.getSkillValue(PILOT_ROCKET)` read `0x7F`. Complete
  skill naming/order remains unresolved because `.STF` skill bytes and the
  in-record `0x7F..` cluster still need a dedicated recovery pass.
- Left `getMovementRate()` and `getTHACO()` returning `0` intentionally. The
  handoff and validation artifacts still label movement/THAC0/AC/player
  combat formulas as unresolved scaffolding, so this pass does not invent
  combat formulas or field names.
- Added `CharacterBuckRogersTest` with a synthetic 259-byte record that catches
  natural/current swaps, the `WIS_NATURAL` alias, byte-sized age, 32-bit
  credits, HP, and pilot-rocket skill decoding, plus a regression against
  `generated/liveplay/first_map_capture/pre_saves/TST2.WHO`.
- Qwen-Coder sidecar used via
  `openclaw infer model run --model ollama/qwen3-coder:30b` with a bounded
  evidence prompt. Its advisory recommendation matched the implemented
  boundary: fix proven mappings, expose only the known pilot-rocket byte, and
  leave movement/THAC0 unresolved.
- Validation:
  - focused Java:
    `.tools/apache-maven-3.9.9/bin/mvn -q -Dtest=data.character.CharacterBuckRogersTest test`
    -> pass;
  - full Java:
    `.tools/apache-maven-3.9.9/bin/mvn -q test` in `references/ssi-engine`
    -> **277 tests, 0 failures, 0 errors, 7 pre-existing skips**;
  - `references/ssi-engine/scripts/run-combat-scene.sh` ->
    `Final COMBAT_RESULT=0`.

### Latest Pass: COAB Mega-Pass — COMPLETE (2026-07-08, Claude Code + Sonnet subagents)

**All five tracks landed** as self-contained, tested, unwired packages.
Nested-repo commits: `0a1e8ae`, `7db8de4`, `1cc2f44` (track D: NPC party
lifecycle `engine/party/` + game clock `engine/time/`, 37 tests; faithful
quirks documented — party-full morale clobber, no duplicate check in
load_npc, integer-division treasure wipe; evidence note: this fork's
`NPC_FIND` 0x37 is LOAD PIECES in COAB, so findNpc is a labeled adaptation),
`e130f62` (track C: quick-fight AI `engine/combat/ai/`, intent-producing
planner porting ovr010.PlayerQuickFight's full decision order + ovr014
targeting helpers, 25 branch-pinned tests). Final suite: **275 tests,
0 failures, 7 pre-existing skips**; `run-combat-scene.sh` re-verified
(`COMBAT_RESULT=0`).

**Remaining from this pass:** (a) ✅ provenance audit done 2026-07-08 —
zero unverified citations, zero uncited ported logic; 25 vague-format
citations deferred to the licensing pass (see
`references/ssi-engine/docs/coab-provenance-audit-2026-07-08.md`);
(b) the coordinator integration pass wiring the five packages into
`CombatState`/`CombatController`/VM opcode stubs (see agent reports'
"integrator wiring" notes preserved below and in
`docs/coab-combat-port-map.md`). Track C/D integrator notes: adapter mapping
`Combatant`/`CombatState` onto `QuickFightCombatantView`/`QuickFightBattleView`
(geometry can delegate to `engine/combat/map`), an intent executor that
re-plans while delay/moves remain and retires `RecoveredEnemyTactics`, one
planner instance per combat (holds target memory); `PartyRoster` →
`VirtualMemory` party list, `NpcCharacterSource` → `PlayerDataFactory
.loadCharacter`, `NPC_ADD`/`NPC_REMOVE` VM handlers → `addNpc(id,morale)` /
`removeCurrent()`, GameClock ↔ area clock words (0x18C–0x198).

*(Section below written while the pass was in flight; kept for history.)*

### Prior status snapshot: COAB Mega-Pass in flight (2026-07-08, Claude Code + Sonnet subagents)

**Strategy (James-approved):** port everything plug-in-able from COAB
(`~/.local/opt/coab`, github.com/simeonpilgrim/coab commit `9dc46f1`) into new
self-contained packages in the Java fork, tests included, no shared-file
edits; the coordinator wires them into `CombatState`/`CombatController`/VM
afterwards. Five Sonnet subagent tracks were run in parallel; two session-limit
interruptions occurred (agents killed mid-write both times). All completed
work is committed and the build is green.

**Git state (nested repo `references/ssi-engine`, branch `matrix-cubed-fork`):**
- `0a1e8ae` — checkpoint: everything through COAB combat passes 1–2 + smoke harness + partial round-1 tracks.
- `7db8de4` — checkpoint: round-2 landings (attack/map/loot tests), party re-quarantined.
- Repo-local git identity set to James <jzatopa@gmail.com> (nested repo had none).
- Suite at `7db8de4`: `mvn test` → **213 tests, 0 failures, 7 pre-existing fixture skips**.

**Track status:**
| Track | Package | State |
|---|---|---|
| A attack flow | `engine/combat/attack/` + tests | ✅ landed: 10 classes + 5 test classes, passing. Final agent report not delivered (killed) — audit provenance javadoc before trusting details. |
| B map/LOS/movement | `engine/combat/map/` + tests | ✅ landed: 8 classes + 2 test classes, passing. Same caveat: no final report. |
| E treasure/money | `engine/loot/` + tests | ✅ landed: 11 classes + 3 test classes (TreasurePool/RobOperations/AdndCoinage), passing. No final report. |
| D NPC lifecycle + clock | `engine/party/`, `engine/time/` | 🔶 incomplete: 4 interface files quarantined at `references/ssi-engine/.partial-coab-tracks/engine-party-v2/` (they reference the unwritten `NpcPartyService`); `engine/time/` (GameClock from ovr021) not started. |
| C quick-fight AI | `engine/combat/ai/` | ❌ not started (agent died twice during COAB reading). |

**Remaining work items for this pass (in order):**
1. Finish track D: restore `engine-party-v2` files into `src/main/java/engine/party/`, write `NpcPartyService` (COAB `ovr003.CMD_AddNPC`/`CMD_RemoveNPC`, `ovr017.load_npc`: party limits, control/morale, treasure share, duplicates) + `engine/time/GameClock` (`ovr021.NormalizeClock`, `step_game_time`) + JUnit 4 tests.
2. Do track C: port `ovr010.PlayerQuickFight` as an intent-producing `QuickFightPlanner` in `engine/combat/ai/` + tests (own interfaces; no dependence on sibling packages).
3. Audit tracks A/B/E for provenance javadoc completeness (agents died before final reports).
4. Coordinator integration pass (judgment tier, NOT a subagent): wire attack resolver + map service + AI planner into `CombatState`/`CombatController` (replacing scaffold THAC0 math and `RecoveredEnemyTactics` fallback), and party/clock/loot services toward the VM opcode stubs (`NPC_ADD`, `TREASURE`, `CLOCK1/2`) per `docs/coab-java-stub-audit.md`.
5. Re-validate: full `mvn test` + `scripts/run-combat-scene.sh` (must still reach `COMBAT_RESULT=0`) + `MatrixCubedSmokeTest`. Commit per pass.

**Agent policy (James, 2026-07-08):** maximum TWO subagents at a time from now
on, unless a requirement genuinely demands more; use the cheapest adequate
model (Haiku for mechanical work, Sonnet for code-judgment work like COAB
porting); Fable-tier stays coordinator-only. Commit checkpoints before/after
agent rounds — session limits killed agents mid-write twice today; quarantine
(move, never delete) any partial files that break the build, in
`references/ssi-engine/.partial-coab-tracks/`.

**Roadmap context:** see the compressed plan in this file's earlier passes and
`references/ssi-engine/docs/coab-combat-port-map.md` (port order items 1–2
done, 3–5 landed as unwired packages by this mega-pass). After integration:
character decode (`CharacterBuckRogers` zeros), VM `GameMechanics` wiring,
space/effects stubs, then the authenticity track (Ghidra↔COAB function
matching — good future job for James's local 3090 + qwen-coder as a
candidate-generator with agent verification).

### Latest Pass: Headless End-to-End Smoke Harness (2026-07-08, Claude Code + Sonnet subagent)
- Added `references/ssi-engine/src/test/java/integration/MatrixCubedSmokeTest.java`
  (4 tests, JUnit 4, skips via Assume when the MATRIX game dir is absent):
  1. game detection off original data (name + `PlayerDataType.BUCK_ROGERS`);
  2. character creation → party of two via real `PlayerDataFactory` /
     `CharacterSheetImpl` / `VirtualMemory.addPartyMember`;
  3. real `VirtualMachine` executing original ECL 17 from `0x8C54` through
     `LOAD_MON` into the production combat wiring
     (`SsiEclCombatAdapter → EclCombatBridge → CombatController →
     HeadlessCombatUiBridge`), asserting combat resolves structurally;
  4. save/load round trip via `VirtualMemory.saveTo`/`writePartyMember` →
     `loadFrom`/`PlayerDataFactory.loadCharacter` (the same primitives
     `SaveHandler`/`LoadHandler` call), asserting party count/names/ECL/area/
     combat-result survive.
- `main/MatrixCubedCombatScene.java` refactored minimally so the harness can
  call it: `main()` body extracted to `runToCombat(...)` (+ overload with a
  `PartyBuilder` callback); printed output verified unchanged.
- Honest shortcuts (recorded for the next pass): save/load drives
  `VirtualMemory` directly (no full `Engine`+UI boot); character creation
  bypasses the menu-driven `CREATE_CHAR` flow; the ECL test party is a
  bare 1-HP character so combat reliably resolves as a loss (structural
  assertion only — a victory-path variant needs meaningful stats).
- Validation: full Java `mvn test` → 82 tests, 0 failures, 7 pre-existing
  fixture skips (verified independently by the coordinator after the
  subagent's run). This suite is now the regression net for the combat
  porting work.

### Latest Pass: Combat Port Pass 2 — COAB Round Checks / Dying / Expiry (2026-07-08, Claude Code)
- Ported COAB's damage/dying/round-end semantics into the Java fork
  (source: `https://github.com/simeonpilgrim/coab` commit `9dc46f1`, files
  `engine/ovr025.cs` `damage_player`, `engine/ovr009.cs` `BattleRoundChecks`,
  `engine/ovr011.cs`/`ovr014.cs` no-action limit, `Classes/Enums.cs` Status;
  provenance recorded in javadoc at each ported member):
  - `Combatant` now carries `HealthStatus {OKAY, UNCONSCIOUS, DYING, DEAD}`
    (subset of COAB's Status) plus a bleeding counter. `applyDamage` follows
    `damage_player`: overkill past 0 HP by >9 kills outright; overkill 1..9
    leaves the combatant DYING with bleeding starting at the overkill amount;
    landing exactly on 0 is UNCONSCIOUS; any non-okay status pins HP to 0
    (so existing `isAlive()` semantics were preserved unchanged).
  - `CombatState` runs end-of-round checks when the initiative queue crosses
    a round boundary: dying combatants bleed +1 (dead past 9, matching
    `BattleRoundChecks`), a "Your Teammate is Dying" log warning mirrors
    COAB's bandage check message, and combat expires to a new
    `Phase.EXPIRED` (combatResult 1, per the existing 0=victory /
    1=defeat-or-unresolved convention) when 15 rounds pass without an attack
    (`Gbl.combat_round_no_action_value`); every attack re-arms the limit
    (`ovr014.AttackTarget`). A `RoundEndHook` extension point reserves the
    per-round `CheckAffectsEffect` slot for the coming effects pass.
  - `CombatController.isCombatOver()` includes EXPIRED; debug forceVictory
    now overkills past the dying window so debug kills read DEAD.
- Labeled deferrals: game-time stepping, poison clouds, the bandage action
  itself, animated-status death branch, and enemy-health morale
  recalculation belong to later effect/AI passes. `Combatant.heal()` is an
  explicitly labeled candidate scaffold until COAB cure/bandage is ported.
- Tests: new `CombatantTest` (8 conformance tests for the damage_player
  rules, bleeding progression, heal boundaries, copy fidelity) and 4 new
  `CombatStateTest` cases (bleed-out across rounds with log warning, expiry
  after 15 attack-free rounds, attack re-arming the limit, round-end hook
  firing once per completed round).
- Validation: full Java `mvn test` → 78 tests, 0 failures, 7 pre-existing
  fixture skips; headless original-ECL harness `run-combat-scene.sh` reaches
  `COMBAT_RESULT=0` and its transcript shows the new mechanics live
  (`BLEED OUT: RAM G.D. GENNIE has died (round 11)` — a monster in the 1..9
  overkill window bleeding out).
- Next: pass 3 (attack flow — `CanHitTarget`/`AttackTarget` skeleton with
  ruleset-provided values) per the port map.

### Latest Pass: Combat Port Pass 1 — COAB Initiative/Turn Order (2026-07-08, Claude Code)
- Replaced the placeholder insertion-order `CombatTurnQueue` in the Java fork
  with COAB's delay-based initiative and turn selection
  (`references/ssi-engine/src/main/java/engine/combat/CombatTurnQueue.java`).
- Ported semantics (source: `https://github.com/simeonpilgrim/coab` commit
  `9dc46f1`, files `engine/ovr009.cs`, `engine/ovr014.cs`,
  `Classes/Action.cs`; provenance recorded in the class javadoc):
  - per-round initiative `delay = 1d6 + reaction adjustment`, min 1;
    surprised side −6; below 0 or above 20 → 0 (no turn this round)
    (`ovr014.CalculateInitiative`/sub_3E000);
  - next combatant = highest remaining delay, equal delays contested by a
    fresh 1d100 per scan with later roll-ties winning; the exact COAB scan
    quirk (strictly higher delay always wins because the roll threshold is
    reset first) is preserved (`ovr009.FindNextCombatant`/sub_331BC);
  - acting clears delay to 0 (`Action.Clear`); the Delay action keeps
    delay 1 so the combatant re-enters at lowest priority
    (`ovr009.delay_menu` case 'D'); round advances with fresh initiative
    when all delays are spent; surprise applies to the first round only
    (mirrors `MainCombatLoop` zeroing `area2_ptr.field_596`).
- Labeled adaptations (not COAB-verbatim): dead combatants skipped in the
  scan (COAB removes them from its list); reaction adjustment is a universal
  `ToIntFunction<Combatant>` hook defaulting to 0 — COAB's AD&D
  `DexReactionAdj` table is flavor-only and the Buck Rogers table is not yet
  recovered; seeded `java.util.Random` (deterministic per seed, not the
  original RNG stream); casting-delay (`delay = 20`) paths deferred to the
  spell/skill pass.
- Public queue API kept (`order/round/current/advance/hasLivingCombatant`),
  added `delay(Combatant)` and `delayCurrent()`; `CombatState` and
  `CombatController` needed no source changes.
- Tests: rewrote `CombatTurnQueueTest` as 10 COAB-conformance tests (bounds,
  strict-delay win, d100 tiebreak incl. tie-goes-later, all-spent → null,
  dead-skip, round advance, delay-action, first-round-only surprise, single
  survivor, all-dead). Updated `CombatStateTest`/`CombatControllerTest`
  assertions that assumed insertion order (CAR1-first) to initiative-aware
  dynamic assertions.
- Validation: focused `CombatTurnQueueTest` green; full Java suite
  `mvn test` → 66 tests, 0 failures, 7 skipped (pre-existing fixture skips);
  headless original-ECL harness `scripts/run-combat-scene.sh` still reaches
  `COMBAT_RESULT=0` and its transcript now shows initiative-varying turn
  order with the monster interleaving mid-round (Gold Box behavior) instead
  of fixed roster order.
- Known limitations: `CombatState` constructs the queue with a fixed default
  seed (0) — deterministic but identical initiative pattern per encounter
  until seeds are threaded through; surprise/reaction hooks exist but nothing
  passes them yet. Next: pass 2 (`BattleRoundChecks` — dying/bleeding, affect
  tick hooks, round no-action limit) per
  `references/ssi-engine/docs/coab-combat-port-map.md`.

### Latest Pass: COAB→Java Combat Port Map (2026-07-07, Claude Code)
- Docs-only survey pass; no source changes. Added
  `references/ssi-engine/docs/coab-combat-port-map.md`.
- Strategy shift (per James's reuse-now policy): combat completion in the Java
  fork should be ported from COAB's working combat subsystem rather than
  reconstructed evidence-first from DOS captures; the Matrix Cubed Ghidra
  GAME.OVR deep export (`generated/ghidra/deep_game_ovr_payload/`, 624
  functions) becomes the Buck-delta finder and validation oracle, with DOS
  captures as final validation only.
- Verified by reading COAB C# (`~/.local/opt/coab`, commit `9dc46f1`):
  `ovr009.MainCombatLoop`/`FindNextCombatant`/`BattleRoundChecks` and
  `ovr014.CalculateInitiative` — initiative is `1d6 + DexReactionAdj`
  (surprise −6, clamp 0..20), turn order is dynamic max-delay selection with
  d100 tiebreak per scan, dying combatants bleed out after 9 rounds, battle
  ends on empty side or round no-action limit. Other combat overlays
  (ovr010/011/013/024/025/032) surveyed at function-inventory level only.
- Port map defines: what survives in the existing Java scaffold (asset/UI/
  bridge layer), what gets replaced (`CombatTurnQueue`, `CombatController`
  internals, static `Combatant` stat fields → per-turn effective values),
  the universal-vs-flavor boundary, and a 7-pass port order starting with
  initiative/turn-order (tests first, seeded RNG).
- Known blocker feeding the attack/movement passes: `CharacterBuckRogers`
  hardcodes 0 for movement/THAC0/skills; decode should reuse the Python
  `.WHO` evidence rather than re-deriving.
- Validation: none required (no code changed); Java `mvn test` confirmed
  green at start of pass (0 failures).

### Latest Pass: Python Original-Game-Directory Portability (2026-07-07, Claude/Cowork)
- Scope: infrastructure/portability only. No evidence, offsets, formulas, or generated data were changed.
- Problem: ~13 scripts and 2 tests hardcoded the same literal absolute path
  (`$MATRIX_CUBED_GAME_DIR`) to locate
  the original (uncommitted) game files. This made the Python evidence
  pipeline unrunnable in any environment where that exact path doesn't exist
  (for example, this pass was done from a sandboxed session where the folder
  is mounted at a different path).
- Fix: added `scripts/game_paths.py` with `default_game_dir()`, which returns
  the identical historical literal path unless the `MATRIX_CUBED_GAME_DIR`
  environment variable is set, in which case it returns that override. Every
  script/test that previously hardcoded the literal now calls this function
  instead; behavior is byte-for-byte identical when the env var is unset.
- Updated: `scripts/analyze_game_ovr.py`, `scripts/audit_coab_engine_reference.py`,
  `scripts/decode_monster_inventory.py`, `scripts/review_reverse_engineering_packages.py`,
  `scripts/build_data_model_catalog.py`, `scripts/compare_goldbox_ecl_text.py`,
  `scripts/audit_original_capture_targets.py` (only the MATRIX game dir entry;
  the separate liveplay-capture directory constant was left untouched),
  `scripts/analyze_local_files.py`, `scripts/decode_original_files.py`,
  `scripts/analyze_item_name_mapping.py`, `scripts/audit_goldbox_explorer_maps.py`
  (only the game dir; the unrelated Gold Box Explorer C# source path was left
  untouched), `scripts/analyze_combat_ai.py` (derives `DEFAULT_GAME_OVR` from
  the same helper), `scripts/scan_game_ovr_maps.py`,
  `tests/test_item_name_mapping.py`, `tests/test_coab_engine_reference.py`.
- Added `tests/test_game_paths.py` (3 tests: default fallback, env override,
  blank-override-treated-as-unset).
- Explicitly out of scope / left alone: Java sources under `references/ssi-engine`
  (this sandbox only has OpenJDK 11; the fork requires 17, so Java changes could
  not be validated here), shell launcher scripts under `references/ssi-engine/scripts`
  (already support override via `${MATRIX_DIR:-...}`), `scripts/build_source_recovery_corpus.py`
  and its two failing tests (`tests/test_source_recovery_corpus.py`), which
  depend on a separate external Ghidra-decompiled corpus directory and hit an
  unrelated `PermissionError` during `shutil.rmtree` cleanup in this specific
  sandbox — not caused by, or fixed by, this pass.
- Validation:
  - `PYTHONPATH=src:scripts:. python3 -m pytest -q` (var unset): 186 passed,
    7 failed — the same 7 tests that failed before this pass (all due to the
    original game files not existing at the literal default path in this
    sandbox), plus the 3 new `test_game_paths.py` tests now passing.
  - `MATRIX_CUBED_GAME_DIR="<mounted MATRIX folder>" PYTHONPATH=src:scripts:. python3 -m pytest -q`:
    191 passed, 2 failed. The 2 remaining failures are both in
    `tests/test_source_recovery_corpus.py` (unrelated external Ghidra corpus,
    see above); every game-file-dependent test now passes with the override set.
  - Confirmed no other generated artifact drifted: `git status` showed no
    unexpected changes outside the claimed files after this pass.
- Note for the next agent: this sandboxed Cowork session could not run the
  Java suite (`OpenJDK 11` present, project requires `17`) or reach the
  external Ghidra source-recovery corpus, so those areas are unverified by
  this pass and should be re-checked by an agent with a matching environment.

### Latest Pass: Universal Gold Box Java Hardening (2026-07-07)
- Revalidated the fork as a multi-game engine before continuing Matrix-specific work.
- Local original fixtures verified:
  - Curse of the Azure Bonds (`TITLE.DAX` MD5 matches its shipped profile),
  - Pool of Radiance,
  - Pools of Darkness,
  - Secret of the Silver Blades.
- Fixed packaged/test profile discovery:
  - `GameResourceConfiguration` no longer lists a filesystem classpath directory,
  - it uses an explicit registry of all 13 shipped game property resources,
  - this fixed Curse detection under the Maven test classpath and remains valid inside the packaged JAR.
- Removed Buck type assumptions from shared combat conversion:
  - `SsiEclCombatAdapter` resolves STR/DEX through each `AbstractCharacter` ability list,
  - resolves level through that character's own class selection,
  - keeps Buck inventory evidence explicitly type-gated,
  - generic evidence now says `MONCHA` and title-specific formulas.
- Added profile-safe UI routing:
  - only exact detected game `Buck Rogers - Matrix Cubed` receives `SwingCombatUiBridge`,
  - every other profile receives `LegacyGoldBoxCombatUiBridge`, preserving upstream `COMBAT_RESULT=0` without applying Matrix tactical rules or assets,
  - the legacy result is explicitly labeled as unimplemented compatibility behavior.
- Added local integration coverage:
  - detects and decodes every recognized content file in the four available AD&D game directories,
  - loads every discovered Curse monster record,
  - maps Curse monsters without Buck enums,
  - runs a real Curse monster through the legacy combat handoff.
- Packaged-classpath smoke:
  - Curse and Matrix both detect correctly and reach normal mode startup,
  - the desktop remained internally responsive,
  - captures were black for both games in the current Wayland/X11 session, so this is not treated as a Curse-only rendering failure.
- COAB boundary: used only to confirm subsystem separation (effective stats, classes, inventory/effects/movement/combat state). No COAB source, AD&D formulas, offsets, tables, or content were copied.
- Validation:
  - focused universal/Curse tests: success,
  - full Java Maven suite and package: success,
  - full Python suite with dummy SDL: 190 passed,
  - `git diff --check`: success,
  - DeepSeek review agreed with profile routing and character-type decoupling; its level-cap warning does not apply because the adapter reads existing levels and does not perform leveling.
- Detailed report: `references/ssi-engine/docs/universal-goldbox-hardening-pass-1.md`.
- Remaining universal boundary: ECL opcode and character-value configuration are static, so simultaneous different-game instances are unsafe; non-Matrix combat intentionally remains legacy pass-through; `CombatEncounterFactory` should eventually become profile-selected.
- Additional fixtures useful later: Countdown to Doomsday, the Krynn trilogy, Gateway/Treasures of the Savage Frontier, and FRUA. They were not needed to complete this pass.

### Latest Pass: Complete COAB-to-Java Stub Classification (2026-07-07)
- Audited every explicit Java TODO/stub/scaffold and separated actionable mechanics gaps from valid sentinel returns, UI-only TODOs, and debug/decompiler gaps.
- Added `references/ssi-engine/docs/coab-java-stub-audit.md`, mapping every COAB-relevant Java mechanics gap to concrete COAB evidence and a Matrix/universal disposition:
  - party strength/checks, skill checks, surprise,
  - treasure/robbery and encounter movement,
  - item find/destroy,
  - clock/time, NPC lifecycle, spells/effects, experience,
  - late unknown opcodes and non-VM character-sheet/combat placeholders.
- Added universal `GameMechanics` and conservative `UnresolvedGameMechanics` boundaries. Unresolved operations return `OptionalInt.empty()` so unknown mechanics cannot silently masquerade as a successful zero. These are typed extension stubs; they are not yet wired into the VM.
- Corrected `CharacterSheetImpl` to stop displaying fabricated `10` values:
  - movement and THAC0 display a positive decoded value when the character implementation provides one,
  - encumbrance, equipped weapon/armor, damage, and armor class display `UNRESOLVED` until backed by decoded fields/rules.
- Added `UnresolvedGameMechanicsTest` covering the unknown-not-zero contract.
- COAB boundary:
  - reusable subsystem shape includes effective party stats, skills, inventory/treasure, clocks/effects, NPC lifecycle, spells, combat state, and pathfinding,
  - COAB AD&D offsets, tables, formulas, and overlay behavior are not Matrix evidence and were not copied,
  - the inspected COAB checkout has no root license file, so it remains secondary behavioral evidence only.
- Validation:
  - focused Java mechanics/factory tests: success (factory fixture remains skipped when its author-private path is unavailable),
  - full Java Maven suite: success,
  - full Python suite with dummy SDL drivers: 190 passed,
  - active-desktop Python run reached 179/190 before hanging in the final UI/capture test and was terminated; this is an environment hang, not reported as a pass,
  - DeepSeek review agreed with preserving unknown-vs-zero and recommended keeping the new interface methods semantically separate.
- Important status: this pass clarifies all COAB-addressable stubs but does **not** make Matrix Cubed 100% complete. Remaining Matrix-specific recovery includes complete skills, inventory-chain mutation, movement/THAC0/AC fields, clocks/effects, NPC lifecycle, space combat, and exact tactical terrain/pathing/initiative/range/damage/morale/outcome persistence.
- Next implementation order: decode Matrix skills and inventory mutation first; wire a Matrix `GameMechanics` provider into the VM; then replace each empty handler one at a time with original ECL/GAME.OVR/DOS-capture conformance tests.

### Latest Pass: COAB ECL/Text/GEO Secondary-Reference Audit (2026-07-06)
- Audited Simeon Pilgrim's COAB Curse of the Azure Bonds reconstruction at commit `9dc46f1d5911710fb2fcb7a9c0ec0ef74264d17c` strictly as secondary engine evidence; no Curse content, combat flow, rendering policy, or unverified code was imported.
- ECL interpreter result:
  - COAB's recovered `LOAD MONSTER` handler proves operand 2 is the copy count, normalizes zero to one, and caps total loaded monsters at 63.
  - Local Matrix Cubed `ECL1.DAX` block 38 independently requests monster 11 with 10 copies at `0x9754`.
  - Updated the Java `VirtualMachine` to queue the requested copies with the same normalization and bound.
  - Added focused tests for 10 copies, zero-to-one normalization, the 63-monster bound, and direct parsing of the original block-38 instruction.
  - Existing arithmetic operand order, comparison/IF direction, ON GOTO/GOSUB indexing, menu result indexing, and first-argument `LOAD FILES` map selection already agree with COAB's shared behavior, so they were left unchanged.
- ECL text result:
  - Added a reproducible three-way audit of the existing whole-block decoder, existing disassembler decoder, and an independent MSB-first 6-bit decoder.
  - Checked 10,314 bounded `0x80,length,payload` candidates across 33 Matrix Cubed ECL blocks with zero decoder mismatches.
  - Added Java known-alphabet and zero-padding tests for the runtime `EclArgument` decoder.
- GEO/map result:
  - Compared the project GEO parser against COAB's independent four-plane layout across all 25 local maps / 6,400 cells.
  - Every block is 1,026 bytes and all wall, event, and door-plane values match; zero mismatches.
  - COAB exposed no missing GEO field decode. Its rendering/collision behavior remains unverified for Matrix Cubed and was intentionally not integrated.
- Reproducible outputs:
  - `scripts/audit_coab_engine_reference.py`
  - `generated/coab_reference/coab_reference_audit.{json,md}`
  - source hashes and the COAB commit are recorded in the report.
- Validation:
  - focused Python COAB/text tests: 6 passed,
  - focused Java ECL/text tests: success,
  - full Python suite: 190 passed with `SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy` (the active desktop driver hangs in Pygame setup; no test failure),
  - full Java Maven suite: success,
  - DeepSeek advisory review accepted the bounded facts and warned against generalizing from COAB to untested opcodes/rendering behavior.
- Best next ECL work: use original Matrix Cubed instruction bytes and live scene traces to implement currently empty VM handlers one at a time. COAB may suggest test cases, but it must remain secondary evidence.

### Latest Pass: Equipped Item Combat-Option Bridge (2026-07-04)
- Connected recovered equipped `BuckRogersEmbeddedItem` records to the exact 39×9-byte original `ITEMS` table through their proven `itemptr` alignment.
- Added `RecoveredItemOptionSelector`, implementing only the statically proven subset of `GAME.OVR` `0000:d3bf`:
  - walk equipped recovered item options,
  - for `ITEMS` family/category byte 0 equal to 1, compare unsigned `ITEMS` byte 2 plus signed runtime item byte `+0x32`,
  - because the ITEM0-shaped payload begins at runtime offset `0x2e`, the latter is payload byte 4,
  - retain the first candidate on ties by replacing only on strict greater-than.
- Added a bounded signed-payload accessor to `BuckRogersEmbeddedItem`; no semantic field name was assigned to payload byte 4.
- `SsiEclCombatAdapter` can now accept an `OriginalItemCombatTable` and append the recovered equipped-option mapping to encounter evidence. Damage, range, attack dispatch, and category-0 target-dependent scoring remain unchanged and explicitly unresolved.
- Monster 52 provides the concrete integration fixture: four stable-field items are recovered, two have the proven equipped bit, and both map through original `ITEMS` records.
- Validation:
  - focused Java selector/table tests: success,
  - full Python suite: 187 passed,
  - full Java Maven suite: success,
  - DeepSeek advisory review agreed the supplied category-1 comparison and offset mapping are supported; it warned that category-0 scoring and other branches remain incomplete.
- Best next combat pass: trace the category-0 score inputs in `0000:d18e` and their callers far enough to assign only proven coordinate/target fields, or capture original option choices for controlled equipped loadouts. Do not use the current selector to alter damage or attack range yet.

### Latest Pass: Original Equipped Flag + Quantity Recovery (2026-07-04)
- Proved both mutable ITEM0 payload fields from recovered original `GAME.OVR` code:
  - `2000:3ea6` / file offset 147118 walks the item chain, reads `itemptr` at record offset `0x2E`, and requires record offset `0x34` bit `0x80`; because the ITEM0-shaped payload begins at `0x2E`, this proves payload byte 6 bit `0x80` is the equipped flag,
  - `2000:42f6` / file offset 148222 merges otherwise identical item records through record offset `0x38`, normalizes zero to one, and caps stacks at 100,
  - `0000:309f` / file offset 12455 decrements record offset `0x38` when greater than one or removes the item record; this proves payload byte 10 is quantity.
- Upgraded the evidence generator to schema v4. Matching all stable payload bytes while ignoring only equipped byte 6 and quantity byte 10 yields:
  - 64 unique ITEM0 matches,
  - zero ambiguous matches,
  - 18 prior byte-exact matches plus 46 newly recovered mutable records,
  - 24 MON0ITM blocks with at least one recovered item.
- Updated Python `SavedItemRecord` with evidence-backed `is_equipped` and `quantity` accessors.
- Updated the Java bridge:
  - `BuckRogersItemCatalogBlock.stableFieldIndex()` requires a unique match across every non-mutable byte,
  - `BuckRogersMonsterInventoryBlock.recoveredItems()` attaches stable-field matches,
  - `BuckRogersEmbeddedItem` exposes original-backed equipped state and quantity,
  - `CharacterBuckRogers.isEquipped()` now consumes the proven bit,
  - combat seed evidence reports template, `itemptr`, equipped state, and quantity.
- Monster 52 now recovers four items instead of the one exact match; two carry the proven equipped bit. Damage and weapon selection remain unchanged pending exact combat-option selection recovery.
- Visible DOSBox validation was attempted on desktop `:0`, but the GNOME session was locked and only the compositor guard window was mapped. No headless substitute was used. The disposable liveplay save was seeded after preserving its prior empty state under `generated/liveplay/20260704-inventory-control/`.
- Validation:
  - focused STF/inventory tests: 5 passed,
  - full Python suite: 187 passed,
  - full Java Maven suite: success,
  - DeepSeek advisory review agreed the equipped and quantity semantics are supported by the supplied call-site evidence; it retained visible DOS behavior as an outstanding validation.
- Best next combat pass: connect equipped recovered items through `itemptr` to `OriginalItemCombatTable`, then port only the statically proven weapon-option selection invariants. Keep damage/range field meanings unresolved until their original accessors are traced.

### Latest Pass: Saved STF Inventory Record Decoder (2026-07-04)
- Corrected the prior unsupported `.STF` interpretation: the supplied files are not 124-byte skill records. They are variable-length arrays of the same 62-byte item-record shape seen in MON0ITM.
- Evidence from the five supplied saves:
  - sizes are 992, 310, 124, 124, and 124 bytes,
  - record counts are 16, 5, 2, 2, and 2 (27 total),
  - every record splits into a 46-byte runtime/display prefix and a 16-byte ITEM0-shaped payload at offset 46,
  - 15 payloads exactly match one of the 91 ITEM0 templates.
- The 12 non-exact saved payloads have unique nearest templates and only four observed delta patterns:
  - five change payload byte 6 from `0x20` to `0xA0`,
  - five make that byte-6 change and change byte 10 from 10 to 100,
  - one changes byte 10 from 1 to 2,
  - one changes byte 10 from 1 to 3.
- Replaced `matrix_cubed.formats.stf` with a conservative `SavedInventory` / `SavedItemRecord` decoder that exposes the 46-byte prefix, 16-byte payload, and proven `itemptr` byte without assigning field semantics. Updated `game_state_probe` to report inventory record counts.
- Extended `scripts/decode_monster_inventory.py` and regenerated schema-v3 evidence with STF hashes, raw prefixes/payloads, exact matches, unique nearest templates, and byte-level differences.
- Evidence boundary: `0x20 -> 0xA0` at payload byte 6 correlates with the first two records in every supplied save, while byte 10 varies like a mutable count. Neither is promoted as equipped/quantity semantics without a controlled DOS capture.
- Validation:
  - focused STF/inventory tests: 4 passed,
  - full Python suite: 186 passed,
  - full Java Maven suite: success,
  - DeepSeek advisory review agreed with the raw 62-byte decoder and warned against assigning byte 6 or byte 10 semantics from this five-save corpus.
- Best next validation: perform a controlled DOS save before/after equipping one known item and before/after consuming one known stack, then diff the corresponding 62-byte STF record. Only after that should Java `isEquipped()` or mutable quantities consume these bytes.

### Latest Pass: Aligned 62-Byte MON0ITM Record Decoder (2026-07-03)
- Replaced the prior arbitrary-offset/executable-fragment interpretation with a stronger local structural result:
  - all 42 decoded `MON0ITM.DAX` blocks are divisible by 62,
  - they contain 143 total 62-byte records,
  - each record has a 16-byte ITEM0-shaped payload at record offset 46,
  - all 18 existing exact ITEM0 matches occur at `record_index * 62 + 46`, across 13 monster blocks.
- Updated `scripts/decode_monster_inventory.py` and regenerated `generated/monster_inventory/monster_inventory_evidence.{json,md}` as schema v2 with source hashes, per-record offsets/hashes/raw payloads, and summary counts.
- Tightened the Java bridge so only exact ITEM0 templates at the aligned payload offset can become `BuckRogersEmbeddedItem` instances. An exact template byte sequence elsewhere in a record is now ignored.
- Preserved the evidence boundary: the first 46 bytes, all non-exact 16-byte payloads, empty-slot semantics, and equipped state remain unresolved; no near match is promoted into runtime inventory.
- Source evidence:
  - `ITEM0.DAX`: 1,534 bytes, SHA-256 `030793591f1b48ea23d5f866b8d14964a39caed68d333e1e4edf3698385b77dc`, 91 decoded templates,
  - `MON0ITM.DAX`: 8,636 bytes, SHA-256 `ffa78372cf0a838aaeb3bc0a6b57263c0063931697fb0bba34be7f24976597a2`, 42 decoded blocks,
  - monster 52 remains the concrete runtime proof: record 3 payload at block offset 232 exactly equals ITEM0 template 39 and carries proven `itemptr` 3.
- Validation:
  - focused Python decoder regression: 1 passed,
  - focused Java `BuckRogersMonsterInventoryBlockTest`: success, including the new unaligned-match rejection case,
  - full Python suite: 187 passed,
  - full Java Maven suite: success,
  - DeepSeek advisory review agreed that the aligned scan and unresolved boundary are conservative; it highlighted the 125 non-exact records and unresolved 46-byte prefixes as the main remaining risks.
- Best next inventory work: compare the 143 aligned payloads field-by-field with ITEM0 templates and saved 62-byte `.STF` records to identify mutable fields without guessing; DOS memory/save captures showing monster inventory/equipped state would provide the strongest validation.

### Latest Pass: Combat Audit + Conservative MON0ITM Inventory Decoder (2026-07-03)
- Audited the complete Java combat path: ECL `LOAD_MON` queue, party/monster seeds, encounter construction, turn queue, automatic enemy actions, recovered target memory, attack/result flow, Swing bridge lifecycle, original-asset renderer, and all direct-compile scripts.
- Fixed concrete combat defects:
  - Swing combat now resolves user cancellation instead of blocking the VM forever; both `windowClosing` and `windowClosed` are guarded through a single atomic completion path,
  - added debug-only `matrix.combat.debugAutoClose` to exercise the real Swing `WINDOW_CLOSING` event,
  - removed manual `N` enemy control from the legacy non-asset panel and added automatic timed monster turns,
  - fixed missing `CombatEncounterFactory.java` entries in `run-playable-combat.sh` and `run-combat-state-demo.sh` direct compile lists.
- Visible lifecycle proof with original ECL 17:
  - opened real Swing combat at `0x8CEA COMBAT()`,
  - dispatched Swing window close,
  - returned `COMBAT_RESULT=1 resolver=SwingCombatUiBridge(user closed)`,
  - resumed at `0x8CEB OR`, reached `0x8CF4 EXIT`, and exited 0.
- Added `scripts/decode_monster_inventory.py` and `generated/monster_inventory/monster_inventory_evidence.{json,md}`.
- Corrected the inventory model:
  - 259-byte MONCHA/WHO records do not directly contain the decoded item list,
  - MON0ITM blocks are executable initializer fragments, not flat 62-byte runtime item structs,
  - exact 16-byte ITEM0 templates can nevertheless be recovered conservatively by byte-for-byte matching.
- Current exact evidence:
  - 42 MON0ITM blocks scanned against all 91 ITEM0 templates,
  - exact embeddings found in 13 monster blocks,
  - monster 52 contains exactly ITEM0 template 39 at decoded block offset 232; that template's proven ITEM0 `itemptr` is 3.
- Java inventory bridge:
  - added `ContentType.ITEM` and `ContentType.MONITM`,
  - added `BuckRogersItemCatalogBlock`, `BuckRogersMonsterInventoryBlock`, and `BuckRogersEmbeddedItem`,
  - `PlayerDataFactory` attaches exact embedded templates to `CharacterBuckRogers.getItems()`,
  - combat seed evidence carries exact template/itemptr provenance,
  - `isEquipped()` remains false because MON0ITM initializer equip actions are not decoded,
  - attached inventory does not alter damage or weapon choice.
- Validation:
  - focused combat/inventory tests pass,
  - exact-match decoder regression test passes,
  - all direct combat launchers compile/start,
  - original-asset capture writes a valid 640x400 PNG,
  - full Python suite: 187 passed,
  - full Java Maven suite succeeds,
  - DeepSeek independent review agreed the boundary is evidence-safe and highlighted exact-match false negatives/equip-state recovery as the remaining risks.
- Remaining combat boundaries: unlimited scaffold attack range, terrain-free movement, insertion-order initiative, approximate stats/damage, unresolved ITEM detail semantics, dynamic MON0ITM initializer behavior, equipped state, weapon choice, morale, and original pathfinding.
- Best next inventory pass: disassemble/emulate the MON0ITM initializer contract and validate resulting runtime item chains against DOS memory/save captures; do not infer absence of inventory from zero exact template matches.

### Latest Pass: Original ITEMS Combat Table Bridge (2026-07-03)
- Traced the recovered combat option table `DAT_0000_536e` through all available pseudocode accessors.
- Rejected the false raw-offset interpretation: runtime DS address `0x536e` is not `GAME.OVR` file offset `0x5376`.
- Confirmed the existing evidence chain that `DAT_0000_536e` is populated from the separate original `ITEMS` file:
  - 351 bytes,
  - 39 records × 9 bytes,
  - SHA-256 `9175c15b2390e12f007eed627fa5568a64bc761b81df0d5f43102f1669ca3a5c`,
  - record index aligns directly with ITEM0 `itemptr`, with record 0 as the all-zero sentinel.
- Extended `scripts/analyze_combat_ai.py` and `generated/combat_ai/combat_ai_evidence.{json,md}` with the original ITEMS hash, all raw records, runtime accessor mapping, and unresolved semantic boundary.
- Added Java `OriginalItemCombatTable`:
  - validates the exact 39×9 size,
  - performs proven `itemptr` lookup,
  - exposes raw unsigned fields without assigning guessed names,
  - rejects out-of-range pointers.
- Added focused Python and Java tests; full Python suite is 186 passed and the full Java Maven suite succeeds.
- Runtime boundary: `CharacterBuckRogers.getItems()` currently returns an empty list and `isEquipped()` always returns false, so exact original weapon-option scoring cannot yet be connected to combatants. No arbitrary ITEMS record was promoted into AI behavior.
- Next pass: decode the Buck Rogers 259-byte character inventory/equipped-item records, expose their `itemptr` values in Java, then connect equipped weapon options to `OriginalItemCombatTable` and the recovered selector structure.

### Latest Pass: Recovered Enemy Targeting Invariants (2026-07-03)
- Added `scripts/analyze_combat_ai.py`, which verifies the local `GAME.OVR` SHA-256 and emits `generated/combat_ai/combat_ai_evidence.{json,md}` with function offsets, raw evidence-slice hashes, conservative roles, verified observations, and unresolved boundaries.
- Recovered static tactical-AI evidence:
  - `0000:cb18` / file offset `52000`: automated actor action-loop candidate with remembered target and candidate/action dispatch,
  - `0000:d18e` / file offset `53654`: byte-sized attack-option score candidate,
  - `0000:d3bf` / file offset `54215`: linked attack-option selector using a 9-byte table,
  - `0000:d805` / file offset `55309`: target validation/search with an explicit `0x14` (20) attempt bound.
- Added Java `RecoveredEnemyTactics` and wired it into `CombatController.resolveMonsterTurn()`:
  - retains a valid target between turns,
  - invalidates a dead/missing target,
  - limits fresh candidate enumeration to 20,
  - isolates distance/HP/id ordering as an explicit fallback until the original score/table semantics are decoded.
- Updated direct-compile combat launch/capture scripts to include `RecoveredEnemyTactics.java`.
- Validation:
  - focused Python evidence test passes,
  - focused Java tactics/controller tests pass,
  - full Python suite: 186 passed,
  - full Java Maven suite succeeds,
  - standalone original-asset renderer compiles and writes a 640x400 image,
  - visible desktop ECL/Swing combat advances through automatic enemy actions and returns to party control in round 2.
- Boundary: this does not claim exact original target ranking, weapon choice, pathfinding, morale, or attack formulas; those remain unresolved in the recovered 9-byte table and helper calls.

### Latest Pass: Visible Swing Combat Targeting Fix (2026-07-03)
- Reproduced combat through the visible desktop Swing path at ECL 17 `0x8CDB`; no Xvfb, headless resolver, or auto-victory flag was used.
- Confirmed the apparent attack failure was a UI targeting problem: `A` only attacked when the cursor exactly occupied an enemy, while the screen provided no target/action feedback.
- Added `CombatController.selectNextEnemy()` plus `Tab`/`T` enemy targeting.
- Disabled Swing focus traversal on the combat panel so `Tab` reaches the combat binding.
- Added an on-screen action status line for selected targets, blocked/no-target actions, and actual attack roll results.
- Visible validation: `T` selected an enemy and `A` resolved the attack, advancing `CAR1` to `CAR2`.
- Validation: full Java `mvn -q test` succeeds with a focused controller regression test for enemy selection.
- Boundary: attack range and weapon-specific targeting remain scaffold behavior pending original DOS/GAME.OVR validation.

### Latest Pass: Automatic Swing Enemy Turns (2026-07-03)
- Removed the player-facing `N` monster-turn control; it was retained debug scaffolding and incorrectly allowed manual enemy control.
- `AssetCombatPanel` now advances consecutive monster turns automatically on a 500 ms Swing timer after the party turn ends.
- Player combat input is ignored during the automatic enemy phase, with an `ENEMY TURN - PLEASE WAIT` status.
- Visible desktop validation ended the party turns, observed both enemies act without input, recorded an enemy attack against `CAR1`, and returned control in round 2 with `PHASE PARTY_TURN`.
- Full Java `mvn -q test` succeeds.
- Boundary: monster AI/pathfinding and timing remain explicit scaffolding pending original combat validation.

**What:** Source-code reconstruction of Buck Rogers: Matrix Cubed (SSI, 1992), a Gold Box engine RPG. The goal is a functionally equivalent, playable, portable reconstruction built from decoded game data — not copied binary code.

**Why:** Decoding a 34-year-old DOS game into clean, modern source produces a playable cross-platform version that can be studied, modded, and preserved.

**Status:** Python/Pygame Phase A remains preserved as completed reconstruction evidence. New primary runtime direction is Java-first, using a local fork of `ssi-engine` plus the original Matrix Cubed game files.

**State:** Python package remains at 185 passing tests in the project venv. Java fork branch `matrix-cubed-fork` exists under `references/ssi-engine`, builds with project-local Maven 3.9.9, launches far enough under Xvfb to detect `Buck Rogers - Matrix Cubed`, includes a console combat slice that loads `RAM WARRIOR` from original `MON0CHA.DAX`, wires ECL `LOAD_MON`/`COMBAT` into a stateful combat bridge, has a headless ECL combat scene harness that reaches combat through original ECL 17 at `0x8C54`, has Swing/debug combat launchers, static original combat-asset proofs, a recovered GAME.OVR battlefield-buffer generator rendered with original `MARSCOM.DAX`/`VENUSCOM.DAX` tile art, carries recovered battlefield terrain options through `CombatState` into the original-asset Swing renderer, injects `SwingCombatUiBridge` into the production Swing VM path, has a debug autowin proof that returns `COMBAT_RESULT=0` through actual Swing combat, and can seed combat from current VM party members when loaded.

### Bugs Fixed Since Handoff
- ✅ Initial credits/HP now sync from character record to PartyState on add_character()
- ✅ HP display in runner uses `current_hp()` (active party member's HP, not legacy default)
- ✅ Wall sets per map: WallSetDB maps GEO ID → correct wall texture set (19 of 25 maps resolved)
- ✅ Combat validation tool written: `tools/validate_combat.py`
- ✅ Combat runtime evidence report added: `scripts/validate_combat_runtime.py` now writes `generated/validation/combat_runtime_validation.json` and `.md` with explicit confidence boundaries
- ✅ Credits display in runner uses `current_credits()` from active party member
- ✅ Continue restores SAVGAMA.DAT map/position/facing/credits plus saved roster
- ✅ F5/Ctrl+S writes timestamped save and `saves/autosave/`
- ✅ Shop sell mode wired with TAB/ENTER and inventory credit updates
- ✅ GAME.OVR analysis artifacts generated from the real local overlay binary
- ✅ Original-file structural decode pass added: `scripts/decode_original_files.py` now emits JSON evidence for all original files and all 611 DAX blocks under `generated/original_files/`
- ✅ GAME.OVR raw GEO scan added: `scripts/scan_game_ovr_maps.py` emits `generated/game_ovr/map_scan.json` and `.md`, proving no plain 1026-byte GEO1-style map blocks are embedded contiguously in the local `GAME.OVR`
- ✅ Gold Box Explorer map audit added: the editor/reference map table has 24 named Matrix Cubed maps and all are present in local `GEO1.DAX`; local GEO 21 remains unnamed by both the project and Gold Box Explorer
- ✅ Walkthrough development reference added from GameFAQs/kibbitz guide as secondary route-validation evidence; do not copy FAQ prose into runtime data
- ✅ HTML runtime now loads generated floor/ceiling surface texture sprites, renders ECL dialog-reference choices as executable branch/menu buttons, and validates five high-value story progression scenes against local DOS capture evidence/probes
- ✅ Shared runtime now preserves ECL dialog choices, emits `offer_dialog_choices`, executes selected choices through `GameState.execute_dialog_choice()`, and exposes choices in the Pygame runner with number keys
- ✅ Map traversal assumptions tightened: unflagged cell event IDs only transition when the target is a loaded GEO map; traversal evidence report now covers 20/25 loaded maps and names the remaining unresolved maps
- ✅ ITEM0 item names decoded from START.EXE name-code literals and wired into the item catalog/shop UI
- ✅ `ITEMS` 9-byte side-file alignment traced as a 1-based `itemptr` detail table; exact damage/range semantics remain candidate labels pending combat validation
- ✅ Clean source-recovery corpus generated from all available Ghidra decompile exports: 981/981 recovered pseudocode files with provenance headers and GAME.OVR anchor roles
- ✅ Source-recovery role inference added: 23 high-value GAME.OVR functions now have conservative likely-role hypotheses, 958 remain unknown
- ✅ Source-recovery role resolution added: all 23 high-value GAME.OVR candidates now have static triage decisions
- ✅ Unknown source-recovery batch 001 resolved 100 additional `GAME.OVR` unknown functions by conservative static shape, without assigning guessed subsystem names
- ✅ All remaining source-recovery unknowns labeled: 958/958 prior unknown functions now have confidence-backed static labels
- ✅ `Load3DMap` cluster ambiguity resolved by raw disassembly: loader-shaped code is payload `0x30AD0-0x30C10`; `3000:0c04` is a misaligned epilogue entry
- ✅ Phase B transition runtime pass integrated from external agent-mode drop: movement now checks traversal-promoted cell transitions before legacy event-id fallback
- ✅ ECL `LOAD FILES` transition pass integrated: validated map entry coordinates now replace `(1,1)` for promoted transitions when ECL `mapPosX/mapPosY` evidence exists, and exact `LOAD FILES` event targets compile into executable `load_geo` commands
- ✅ OpenClaw/Pygame runtime smoke validated under Xvfb: real `Runner().run()` boots through menu into world render, captures a nonblank 1024x768 screenshot, and exits cleanly
- ✅ Original archive/capture-target audit added: local supplied game directories contain `GEO1.DAX`/`ECL1.DAX` only, no `GEO2-4.DAX`/`ECL2-4.DAX`; existing liveplay evidence still lacks ship-service and exact Caloris/Luna transition captures, and the current combat save pair is byte-identical
- ✅ First-map capture attempt added with Qwen OCR sidecar: menu/title OCR is usable, but current DOSBox-X/Xvfb first-map viewport captures are corrupted and must not be treated as original map text evidence
- ✅ Non-Pygame handoff evidence bundle added: six static Pygame screenshots, JSON runtime states, Qwen OCR for dialog/combat frames, and a zip package for review on systems that cannot run Pygame
- ✅ ECL dialog conversation compiler added: generated 14 compact conversation rows from decoded ECL branch regions, missing packed-text attachments, and event-atlas map/event targets, with confidence boundaries preserved
- ✅ Java runtime fork started from `ssi-engine`: local branch `matrix-cubed-fork`, fork plan, Matrix Cubed launcher script, and build-output ignore added
- ✅ Java combat vertical slice added: `main.MatrixCubedCombatSlice` and `scripts/run-combat-slice.sh` load `MON0CHA.DAX` block 52 and print a deterministic RAM WARRIOR combat transcript
- ✅ Java VM combat wiring started: `LOAD_MON` now queues decoded monsters through the engine character loader, and `COMBAT` runs `engine.combat.SimpleCombat` instead of forcing success
- ✅ Java headless ECL combat scene harness added: `scripts/run-combat-scene.sh` loads ECL 17, jumps to `0x8C54`, chooses `RETURN THE INSULT`, executes `LOAD_MON` and `COMBAT`, and resolves with `COMBAT_RESULT=0`
- ✅ Swing combat debug launcher added: `scripts/run-matrix-cubed-combat-debug.sh` opens the Java UI at ECL 17 address `0x8CBD` so combat can be visually advanced through continue prompts
- ✅ Static combat asset screen proof added: `scripts/run-combat-static-screen.sh` loads original `MARSCOM.DAX` and `COMSPR.DAX` through Java DAX/VGA decoders and displays a fixed Swing proof screen
- ✅ Recovered combat battlefield buffer pass added: `scripts/run-combat-battlefield.sh` ports the recovered `GAME.OVR` `0000:db35` 50x25 buffer write transform plus first concrete caller branches and renders the generated buffer with original `MARSCOM.DAX` or `VENUSCOM.DAX` tile art
- ✅ Interactive VM combat handoff scaffold imported: `CombatSession`/`CombatUiBridge`/`HeadlessCombatUiBridge`/`SwingCombatUiBridge` let VM-created `CombatState` resolve through headless fallback now and a Swing bridge next; ECL 17 combat now drains both queued monsters and returns `COMBAT_RESULT=0`
- ✅ Production Swing VM combat bridge wired: `DesktopFrame.startGame()` injects `SwingCombatUiBridge`, combat panel requests focus, `run-playable-combat-assets.sh` direct compile list includes `CombatEncounterFactory`, and the combat debug launcher now jumps to ECL 17 `0x8CDB` to open the actual `COMBAT()` window directly
- ✅ Production Swing autowin proof added: debug `V`/auto-victory path resolves graphical combat, logs `COMBAT_RESULT=0 resolver=SwingCombatUiBridge`, executes post-combat ECL `OR`, and exits cleanly under Xvfb
- ✅ VM party seed bridge started: current `VirtualMemory` party members are converted to `PartySeed` records for combat state creation when present; defaults remain only as a no-party fallback

### Latest Pass: Swing Autowin + VM Party Seeds (2026-07-01)
- Added debug autowin support:
  - `CombatState.forceVictory(...)`,
  - `CombatController.forceVictoryForDebug()`,
  - `MatrixCubedPlayableCombatAssets` binds `V` to the dev victory action,
  - `SwingCombatUiBridge` honors `-Dmatrix.combat.debugAutoVictory=true` by triggering the same controller action after the Swing combat frame opens,
  - `VirtualMachine` writes/logs `COMBAT_RESULT` immediately after the combat bridge returns,
  - `VirtualMachine` honors `-Dmatrix.combat.debugAutoContinue=true` to skip the post-combat transcript/continue prompt for automated branch validation,
  - `Engine.debugStartEclAtAddress(...)` honors `-Dmatrix.combat.debugExitAfterEcl=true` so debug validation can exit cleanly.
- Added CLI:
  - `references/ssi-engine/scripts/run-matrix-cubed-combat-debug-autowin.sh`
  - Runs production Swing debug combat with the autowin/autocontinue/exit debug flags.
- Started actual-party bridge:
  - `CombatEncounterFactory.PartySeed`,
  - `CombatEncounterFactory.create(monsters, partySeeds)`,
  - `EclCombatBridge.resolve(monsters, partySeeds)`,
  - `SsiEclCombatAdapter.toPartySeed(...)`,
  - VM `COMBAT()` now passes current `VirtualMemory` party members into the adapter.
- Evidence/boundary:
  - party member names/current HP come from decoded `CharacterSheetImpl`/`AbstractCharacter` when loaded,
  - AC/THAC0/damage/movement are still conservative scaffold derivations because exact Matrix Cubed player combat formulas and item/equipment effects remain unverified,
  - if no VM party is loaded, combat still falls back to the six-member `CAR1..CAR6` scaffold party.
- Validation:
  - Focused combat tests -> `BUILD SUCCESS`, 17 tests, 0 failures, 1 skipped.
  - `xvfb-run -a ./scripts/run-matrix-cubed-combat-debug-autowin.sh "$MATRIX_CUBED_GAME_DIR"` -> exits 0 after actual ECL `COMBAT()`, prints `COMBAT_RESULT=0 resolver=SwingCombatUiBridge`, executes `0x8CEB OR`, and reaches `0x8CF4 EXIT`.
  - Full Java `mvn test -q` in `references/ssi-engine` -> success.
  - `java -cp "target/classes:target/*" main.MatrixCubedCombatScene` -> still reaches `Final COMBAT_RESULT=0`.

### Latest Pass: Combat Terrain Option Bridge (2026-07-02)
- Added recovered battlefield terrain plumbing:
  - `CombatState.ratwurstVerticalSlice(Options)` now preserves caller-supplied `RecoveredBattlefieldGenerator.Options`,
  - `CombatEncounterFactory.create(monsters, partySeeds, Options)` builds VM/ECL combat states from the requested recovered battlefield options,
  - factory evidence now records the concrete combat tile source, for example `MARSCOM.DAX block 1` or `VENUSCOM.DAX block 1`,
  - `MatrixCubedPlayableCombatAssets.AssetCombatPanel` now derives Mars/Venus tile selection from `CombatState.battlefieldOptions().terrain`,
  - `scripts/capture-playable-combat-assets.sh` direct-compile list now includes `CombatEncounterFactory`.
- Evidence/boundary:
  - this pass only carries the recovered terrain option through existing Java combat state and renderer paths,
  - it does not decode a new original combat terrain selector from ECL/VM globals,
  - visual validation is a nonblank/manual screenshot check, not a pixel-level original-DOS equivalence proof.
- Validation:
  - Focused Java tests: `CombatEncounterFactoryTest,CombatStateTest,RecoveredBattlefieldGeneratorTest` -> success.
  - Full Java `mvn test -q` in `references/ssi-engine` with project-local Maven 3.9.9 -> success.
  - Full Python `PYTHONPATH=src python3 -m pytest -q` in the project venv -> 185 passed.
  - `xvfb-run -a ./scripts/run-matrix-cubed-combat-debug-autowin.sh "$MATRIX_CUBED_GAME_DIR"` -> exits 0, reaches original ECL `COMBAT()`, prints `COMBAT_RESULT=0 resolver=SwingCombatUiBridge`, executes `0x8CEB OR`, and reaches `0x8CF4 EXIT`.
  - `./scripts/run-playable-combat-assets.sh "$MATRIX_CUBED_GAME_DIR" --venus --screenshot=../../generated/validation/java_combat_venus_terrain_snapshot.png` -> writes a nonblank Venus terrain screenshot, decodes 44 Venus terrain tiles and 108 CPIC sprites.

### Latest Pass: Production Swing VM Combat Bridge (2026-07-01)
- Added production bridge injection:
  - `Engine.setCombatUiBridge(CombatUiBridge)`,
  - `DesktopFrame.startGame(...)` installs `new SwingCombatUiBridge(Path.of(gameDir))` on the VM after game initialization,
  - `SwingCombatUiBridge` now keeps a panel reference, shows the combat frame, brings it forward, and requests focus so existing `WHEN_IN_FOCUSED_WINDOW` combat key bindings are active.
- Updated debug/runtime scripts:
  - `scripts/run-playable-combat-assets.sh` now compiles `CombatEncounterFactory.java` in its direct `javac` source list,
  - `main.MatrixCubedCombatDebug` now jumps to ECL 17 address `0x8CDB` (`CLEAR_MON`/`LOAD_MON`/`COMBAT`) so the debug launcher opens the production combat window without blocking on the prior text continue prompt.
- Validation:
  - Plain `mvn` is still not on this shell's `PATH`; used project-local `.tools/apache-maven-3.9.9/bin/mvn`.
  - Focused handoff tests in `references/ssi-engine`: `RecoveredBattlefieldGeneratorTest,CombatStateTest,CombatTurnQueueTest,CombatControllerTest,CombatAssetLoaderTest,CombatEncounterFactoryTest,EclCombatBridgeTest,CombatUiBridgeTest` -> `BUILD SUCCESS`, 15 tests, 0 failures, 1 skipped.
  - `scripts/run-interactive-combat-handoff-demo.sh ../../generated/liveplay/first_map_capture/game` -> launched Swing handoff process and held until manually stopped for validation hygiene.
  - `scripts/run-playable-combat-assets.sh ../../generated/liveplay/first_map_capture/game` -> compiles after script fix, launches Swing combat asset screen, and holds until manually stopped.
  - `mvn -q -DskipTests package` with local Maven -> success.
  - `java -cp "target/classes:target/*" main.MatrixCubedCombatScene` -> original ECL 17 reaches `LOAD_MON(47,4,47)`, `LOAD_MON(52,3,52)`, `COMBAT()`, resolves via headless bridge, executes post-combat `OR`, exits, and prints `Final COMBAT_RESULT=0`.
  - Xvfb production smoke with `main.MatrixCubedCombatDebug` -> actual ECL `COMBAT()` opened `Matrix Cubed - VM Combat Handoff` at 640x400; direct X key events were accepted for the combat window.
- Boundary:
  - graphical combat still requires manual play to resolve victory/defeat through the Swing bridge,
  - automated `COMBAT_RESULT` branch confirmation is currently through the deterministic headless bridge, not a fully played Swing combat,
  - exact original combat formulas, initiative, placement, and combat-screen flow remain pending.

### Latest Pass: Interactive VM Combat Handoff Scaffold Import (2026-07-01)
- Imported from the local handoff package at:
  - `<local durable mirror>-java-combat-interactive-vm-handoff-scaffold-pass-1-20260701`
- Added/updated Java combat bridge files under `references/ssi-engine`:
  - `engine/combat/CombatSession.java`,
  - `engine/combat/CombatSessionResult.java`,
  - `engine/combat/CombatUiBridge.java`,
  - `engine/combat/HeadlessCombatUiBridge.java`,
  - `engine/combat/CombatState.java`,
  - `engine/combat/CombatController.java`,
  - `engine/combat/CombatEncounterFactory.java`,
  - `engine/combat/CombatAssetLoader.java`,
  - `engine/combat/EclCombatBridge.java`,
  - `engine/combat/SsiEclCombatAdapter.java`,
  - `main/SwingCombatUiBridge.java`,
  - `main/MatrixCubedInteractiveHandoffDemo.java`,
  - plus related tests and scripts.
- VM integration:
  - `VirtualMachine` now owns a `SsiEclCombatAdapter`,
  - `setCombatUiBridge(CombatUiBridge)` can inject an interactive resolver,
  - ECL `COMBAT()` drains all queued monsters instead of only the first one,
  - queued SSI Engine monster resources are converted to `MonsterSeed` records,
  - the default resolver remains deterministic/headless for tests and CLI validation.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test -q` in `references/ssi-engine` → success, 30 tests, 0 failures, 7 skipped.
  - `JAVA_TOOL_OPTIONS=-Djava.awt.headless=true ./scripts/run-interactive-combat-handoff-demo.sh "$MATRIX_CUBED_GAME_DIR"` → resolved the four-Ratwurst bridge demo through `HeadlessCombatUiBridge`, with `COMBAT_RESULT=0`.
  - `timeout 30s ./scripts/run-combat-scene.sh` → original ECL 17 scene reaches `LOAD_MON(47,4,47)`, `LOAD_MON(52,3,52)`, and `COMBAT()`; bridge resolves both `RAM G.D. GENNIE` and `RAM WARRIOR`; final `COMBAT_RESULT=0`.
  - `timeout 12s xvfb-run -a ./scripts/run-combat-battlefield.sh` → recovered battlefield renderer still loads original `MARSCOM.DAX` block `1` and starts cleanly.
- Notes:
  - The first graphical `run-interactive-combat-handoff-demo.sh` attempt opened a Swing window and blocked as expected in this graphical shell; use `JAVA_TOOL_OPTIONS=-Djava.awt.headless=true` for non-interactive validation.
  - Imported `CombatState.ratwurstVerticalSlice()` was aligned with the six-member `CombatEncounterFactory.defaultParty()` fixture; the occupied-cell unit test was corrected to use CAR2's actual `(14,9)` position.
- Boundary:
  - this is a VM/UI handoff scaffold, not final original combat equivalence,
  - Swing bridge injection into the production runtime still needs live UI validation,
  - exact original combat formulas, initiative, placement, and combat screen flow remain pending.

### Latest Pass: Recovered Combat Battlefield Buffer (2026-07-01)
- Added:
  - `references/ssi-engine/src/main/java/engine/combat/BattlefieldBuffer.java`,
  - `references/ssi-engine/src/main/java/engine/combat/RecoveredBattlefieldGenerator.java`,
  - `references/ssi-engine/src/main/java/main/MatrixCubedCombatBattlefield.java`,
  - `references/ssi-engine/src/test/java/engine/combat/RecoveredBattlefieldGeneratorTest.java`,
  - `references/ssi-engine/scripts/run-combat-battlefield.sh`.
- The generator:
  - models the recovered original battlefield buffer shape as `7-byte header + 50 columns x 25 rows`,
  - ports the recovered `GAME.OVR` `0000:db35` write transform: local combat coords are shifted by globals equivalent to `0x4004/0x4005`, then written at `base + 7 + y*50 + x`,
  - applies the first concrete recovered caller branches:
    - `0000:e3ab` when `0x4006 == 1`, writing the `0x18/0x19` local cluster,
    - `0000:e2f5` when `0x4007 == 1` or `3`, writing the recovered `0x1a..0x26` local terrain clusters,
  - renders the resulting tile-code buffer through original `MARSCOM.DAX` or `VENUSCOM.DAX` block `1` decoded by the Java DAX/VGA path,
  - prints a tile histogram and evidence/boundary notes before opening Swing.
- CLI:
  - `cd <project root>/references/ssi-engine`
  - `./scripts/run-combat-battlefield.sh`
  - optional examples:
    - `./scripts/run-combat-battlefield.sh "$MATRIX_CUBED_GAME_DIR" --terrain=venus --global-4007=1`
    - `./scripts/run-combat-battlefield.sh "$MATRIX_CUBED_GAME_DIR" --sector-x=1 --sector-y=1`
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test -q` in `references/ssi-engine` → success, 17 tests, 0 failures, 6 skipped.
  - `timeout 12s xvfb-run -a ./scripts/run-combat-battlefield.sh` → printed recovered-buffer report, loaded `MARSCOM.DAX` block `1` with 42 decoded tile images, and stayed open until timeout with no startup/decode crash.
  - Venus smoke: `./scripts/run-combat-battlefield.sh ... --terrain=venus --global-4007=1` → loaded `VENUSCOM.DAX` block `1` with 44 decoded tile images and printed the recovered tile histogram.
- Boundary:
  - this is a recovered-code buffer generator, not a fully proven exact DOS combat screen yet,
  - unresolved original random/fill routines such as the `FUN_0000_e1ea`/`dbe2`/`dded` cluster are intentionally not guessed,
  - combatant placement/menu/frame rendering is still separate from the generated terrain buffer,
  - next pass should port or instrument the remaining original fill/random routines and connect this buffer to a first-class Java `COMBAT` UI state.

### Latest Pass: Static Combat Asset Screen Proof (2026-07-01)
- Added:
  - `src/main/java/main/MatrixCubedCombatStaticScreen.java`,
  - `scripts/run-combat-static-screen.sh`.
- The static screen proof:
  - loads `MARSCOM.DAX` block `1` from the original game directory,
  - loads `COMSPR.DAX` block `1` from the original game directory,
  - decodes both through existing Java `ContentFile`/`VGAImage` paths,
  - draws a fixed Swing combat-board proof using original asset images.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test` → `BUILD SUCCESS`, 15 tests, 0 failures, 6 skipped.
  - `timeout 12s xvfb-run -a ./scripts/run-combat-static-screen.sh` → stayed open until timeout with no startup/decode crash.
- CLI:
  - `cd <project root>/references/ssi-engine`
  - `./scripts/run-combat-static-screen.sh`
- Boundary:
  - this is not the original tactical layout,
  - it proves static original combat assets can be decoded and displayed by the Java fork,
  - exact battlefield layout, combat menu frame, palette choices, and sprite placement still need reconstruction.
- Next Java combat-screen work:
  - determine exact original combat screen layout from DOS capture or code,
  - add first-class `COMBAT` UI state/renderer,
  - route VM `COMBAT` to that renderer instead of story text.

### Latest Pass: Swing Combat Debug Launcher (2026-07-01)
- Added:
  - `src/main/java/main/MatrixCubedCombatDebug.java`,
  - `scripts/run-matrix-cubed-combat-debug.sh`.
- Added debug support:
  - `Engine.debugStartEclAtAddress(int eclId, int address)`,
  - `DesktopFrame.startCombatDebug(String gameDir, int eclId, int address)`.
- The Swing launcher:
  - opens the normal Java UI,
  - loads Matrix Cubed from the original game directory,
  - skips title screens,
  - jumps to ECL `17` address `0x8CBD` (post-choice combat branch),
  - lets the user press Enter/Space through continue prompts to reach the scaffold combat transcript.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test` → `BUILD SUCCESS`, 15 tests, 0 failures, 6 skipped.
  - `timeout 12s xvfb-run -a ./scripts/run-matrix-cubed-combat-debug.sh` → reached Matrix Cubed property detection and stayed open until timeout, with no startup crash.
- CLI:
  - `cd <project root>/references/ssi-engine`
  - `./scripts/run-matrix-cubed-combat-debug.sh`
- Boundary:
  - this validates startup, not the visual combat text yet,
  - player/user must advance continue prompts,
  - branch starts at `0x8CBD` to avoid needing automated menu choice selection in Swing,
  - combat rules and fixed hero remain scaffold behavior.
- Next Java combat work:
  - capture a screenshot/video of the Swing combat debug scene after advancing prompts,
  - consume both queued monsters,
  - replace fixed hero with active party members.

### Latest Pass: Headless ECL Combat Scene Harness (2026-07-01)
- Added:
  - `src/main/java/main/MatrixCubedCombatScene.java`,
  - `scripts/run-combat-scene.sh`,
  - `VirtualMachine.startAtAddress(int address)` debug entry point.
- The harness:
  - loads original Matrix Cubed config from `TITLE.DAX` detection,
  - configures Matrix Cubed ECL opcode variants,
  - loads ECL `17`,
  - jumps to address `0x8C54`,
  - prints the original scene text `RAM WARRIORS STAND BY THE AIRLOCK...`,
  - chooses `RETURN THE INSULT`,
  - reaches `LOAD_MON(47,4,47)` and `LOAD_MON(52,3,52)`,
  - reaches `COMBAT()`,
  - runs scaffold combat against the first queued monster, `RAM G.D. GENNIE`,
  - exits with `Final COMBAT_RESULT=0`.
- Also hardened `SimpleCombat` level derivation to use each monster's decoded class selection instead of assuming WARRIOR.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test` → `BUILD SUCCESS`, 15 tests, 0 failures, 6 skipped.
  - `timeout 20s ./scripts/run-combat-scene.sh` → completed successfully and reached `COMBAT_RESULT=0`.
- CLI:
  - `cd <project root>/references/ssi-engine`
  - `./scripts/run-combat-scene.sh`
- Boundary:
  - this proves original ECL can drive the Java VM into the new combat scaffold,
  - it is still headless and not a Swing UI capture,
  - combat formulas and fixed hero remain scaffold behavior,
  - multi-monster queue behavior currently consumes only the first queued monster.
- Next Java combat work:
  - display/drive the same branch in the Swing runtime,
  - consume all queued monsters rather than only the first,
  - replace fixed hero with active party records,
  - add a direct regression test for the ECL 17/`0x8C54` harness.

### Latest Pass: Java VM Combat Wiring (2026-07-01)
- Added shared scaffold combat resolver:
  - `src/main/java/engine/combat/SimpleCombat.java`.
- Updated engine/VM integration:
  - `Engine` now constructs `VirtualMachine` with `PlayerDataFactory::loadCharacter`,
  - `VirtualMachine` now accepts a monster/character loader callback,
  - ECL `LOAD_MON` queues decoded original-file monster records,
  - ECL `COMBAT` consumes the queued monster, prints a deterministic scaffold transcript via story text, waits for continue, and writes `COMBAT_RESULT`.
- Kept `main.MatrixCubedCombatSlice` as the console regression harness.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test` → `BUILD SUCCESS`, 15 tests, 0 failures, 6 skipped.
  - `./scripts/run-combat-slice.sh` → still loads `RAM WARRIOR` from `MON0CHA.DAX` block `52`, resolves victory in 7 rounds with seed `52017`.
- Boundary:
  - combat is still a scaffold, not original-validated tactical combat,
  - fixed test-hero stats are still used,
  - formulas are visible/deterministic and intentionally conservative,
  - the next runtime validation should trigger an actual in-game ECL encounter and confirm the VM text path displays correctly.
- Next Java combat work:
  - replace fixed hero with active party records,
  - preserve queued monster ids/counts and sprite/context from `LOAD_MON` arguments,
  - capture an in-game encounter to confirm `COMBAT` is reached from Matrix Cubed ECL,
  - add a direct VM regression test for `LOAD_MON` followed by `COMBAT`.

### Latest Pass: Java Combat Vertical Slice (2026-07-01)
- Added a first Java combat slice inside the `ssi-engine` fork:
  - `src/main/java/main/MatrixCubedCombatSlice.java`,
  - `src/test/java/main/MatrixCubedCombatSliceTest.java`,
  - `scripts/run-combat-slice.sh`.
- The slice:
  - reads original game files from `$MATRIX_CUBED_GAME_DIR` by default,
  - loads `MON0CHA.DAX` block `52`,
  - decodes enemy name `RAM WARRIOR`,
  - prints HP/AC/THAC0/damage scaffold fields,
  - runs a deterministic console combat transcript against a fixed test hero,
  - reports `COMBAT_RESULT would be 0` on victory.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test` → `BUILD SUCCESS`, 15 tests, 0 failures, 6 skipped.
  - `./scripts/run-combat-slice.sh` → loaded `RAM WARRIOR` from `MON0CHA.DAX` block `52`, resolved victory in 7 rounds with seed `52017`.
- Boundary:
  - monster identity and basic fields are read from original files,
  - attack formula and fixed hero are deterministic scaffold behavior,
  - this is not yet wired into the Swing engine/ECL `COMBAT` opcode,
  - original combat formulas remain unproven.
- CLI:
  - `cd <project root>/references/ssi-engine`
  - `./scripts/run-combat-slice.sh`
- Next Java combat work:
  - make `LOAD_MON` queue decoded monsters inside the engine,
  - wire `COMBAT` to call a combat controller instead of forcing success,
  - replace fixed hero with current party records,
  - keep the console slice as a fast regression harness.

### Latest Pass: Java Runtime Fork Start (2026-07-01)
- James redirected the primary runtime strategy: start over with Java and the original game software as the active base; preserve all Python/Pygame reconstruction work as later-use evidence/reference.
- Local fork point:
  - path: `references/ssi-engine`,
  - upstream: `https://gitlab.com/farmboy0/ssi-engine.git`,
  - base commit: `f10f96f`,
  - branch: `matrix-cubed-fork`.
- Added fork scaffolding:
  - `references/ssi-engine/.gitignore`,
  - `references/ssi-engine/scripts/run-matrix-cubed.sh`,
  - `references/ssi-engine/docs/matrix-cubed-fork-plan.md`,
  - README note documenting the Matrix Cubed fork direction.
- Launcher behavior:
  - default game dir: `$MATRIX_CUBED_GAME_DIR`,
  - accepts an explicit path argument or `MATRIX_CUBED_GAME_DIR`,
  - uses `mvn` from `PATH` or the project-local Maven at `.tools/apache-maven-3.9.9/bin/mvn`,
  - launches with `java -cp "target/classes:target/*" main.Goldbox "$GAME_DIR" --no-title` to avoid the current jar classpath issue.
- Validation:
  - `<project root>/.tools/apache-maven-3.9.9/bin/mvn test` → `BUILD SUCCESS`, 14 tests, 0 failures, 6 skipped.
  - `timeout 12s xvfb-run -a ./scripts/run-matrix-cubed.sh` → timed out as expected with the UI still running after printing `Reading game properties: Buck Rogers - Matrix Cubed`.
- Boundaries:
  - `ssi-engine` is GPLv3; distributing modified fork builds must respect GPLv3.
  - Original and AI-derived game assets should not be committed or bundled without rights clearance.
  - Upstream README says party handling and combat mechanics remain major missing features; verify before adding HD/AI improvements.
- Next Java-specific work:
  - add an automated launch/screenshot smoke harness,
  - verify first map rendering, movement, search, save/load, dialogs, ECL transitions, and combat gaps,
  - then add an optional HD asset override layer keyed by original asset id and provenance manifest.

### Latest Pass: ECL Dialog Conversation Compiler (2026-06-30)
- Extended `scripts/build_ecl_dialog_reference.py` to compile compact dialog conversation rows from:
  - decoded ECL branch regions,
  - nearby missing packed-text attachments,
  - `generated/event_atlas/event_atlas.json` GEO/event targets.
- Generated/updated:
  - `generated/ecl_text_goldbox/ecl_dialog_reference.json`
  - `generated/ecl_text_goldbox/ecl_dialog_conversations.json`
  - `generated/ecl_text_goldbox/ecl_dialog_conversations.tsv`
  - `docs/ecl-dialog-trees-reference.md`
- Evidence summary:
  - missing text attachments remain `123`,
  - unique normalized still-missing strings remain `75`,
  - compiled dialog conversation rows: `14`.
- High-value compiled rows:
  - Caloris GEO 17 event 20 target `0x96CF`: choice `HELP ROMNEY`,
  - Caloris GEO 17 event 28 target `0xA0AA`: choice `SOMEONE ELSE?`.
- Boundary:
  - all 14 current conversation rows have confidence `attached_missing_text_near_branch`,
  - these labels are useful runtime/capture validation targets but are not final ownership proof by themselves,
  - no new original DOS capture was produced in this pass.
- Tests added/updated:
  - `tests/test_ecl_dialog_reference.py` now covers MENU-row compilation, attachment-fallback compilation, and generated conversation artifact consistency.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_ecl_dialog_reference.py` → 5 passed before artifact-regression addition.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/build_ecl_dialog_reference.py` → 123 missing text hit attachments, 75 unique strings, 33 ECL listing blocks.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_ecl_dialog_reference.py tests/test_html_runtime_dialog.py tests/test_runtime_probe.py tests/test_story_progression_scene_validation.py` → 16 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 185 passed.
- DeepSeek sidecar status:
  - verified the supplied artifact/test facts,
  - correctly flagged the risk that attached missing text is not ownership proof,
  - suggested local validation by checking Caloris rows, conversation counts, and stricter assertions; local jq checks and the generated-artifact regression test now pin those facts.
- Next dialog-specific work:
  - add a validator that separates `menu_instruction` rows from `attached_missing_text_near_branch` rows and prevents attachment-only rows from being treated as fully proven,
  - use OCR-readable DOS captures to confirm high-value attachment-only choices,
  - compile executable multi-step branch effects only when target/control-flow semantics are locally validated.

### Previous Pass: OpenClaw-Only Runtime Evidence Handoff Bundle (2026-06-30)
- Added `scripts/capture_pygame_reference_bundle.py`.
- Generated:
  - `generated/runtime_validation/pygame_reference_bundle/pygame_reference_bundle.json`
  - `generated/runtime_validation/pygame_reference_bundle/pygame_reference_bundle.md`
  - `generated/runtime_validation/pygame_reference_bundle/qwen_ocr.md`
  - screenshots under `generated/runtime_validation/pygame_reference_bundle/screens/`
- Pygame/Xvfb reference screenshots generated:
  - `caloris_world.png`
  - `inventory_overlay.png`
  - `character_overlay.png`
  - `caloris_romney_dialog.png`
  - `caloris_autodoc_dialog.png`
  - `caloris_combat.png`
- Bundle validation:
  - 6 screenshots,
  - all nonblank,
  - image hashes and nonblack-pixel counts recorded in the JSON/Markdown manifest.
- Runtime state JSON included for:
  - Caloris base world,
  - Dr. Romney dialog event/choice,
  - autodoc dialog event/choice,
  - Caloris RAM WARRIOR combat queue/status.
- Qwen OCR sidecar for Pygame screenshots:
  - Romney dialog: position `(4,0)`, choice `HELP ROMNEY`; Qwen noted runtime text is sharp but the overlay truncates the long line,
  - autodoc dialog: position `(4,5)`, text `THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'`, choice `SOMEONE ELSE?`,
  - combat: `COMBAT`, `Turn 1 | HP: 100 | RAM WARRIOR(35)`, `Combat! RAM WARRIOR`, `RAM WARRIOR: d20 3+2 vs AC 10 = miss`.
- Created non-Pygame review package:
  - `<local durable mirror>-openclaw-runtime-evidence-2026-06-30.zip`
  - size: 193K,
  - `zip -T` passed.
- Package contents include:
  - handoff,
  - Pygame reference screenshots/state/OCR,
  - Pygame smoke validation output,
  - DOS/Qwen first-map capture attempt manifests and OCR boundary,
  - original archive/capture-target audit,
  - combat runtime validation report.
- Commands run:
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/capture_pygame_reference_bundle.py` → 6 screenshots, all nonblank.
  - `openclaw infer model run --model ollama/qwen3.6:latest --file generated/runtime_validation/pygame_reference_bundle/screens/caloris_romney_dialog.png ...` → OCR succeeded.
  - `openclaw infer model run --model ollama/qwen3.6:latest --file generated/runtime_validation/pygame_reference_bundle/screens/caloris_autodoc_dialog.png ...` → OCR succeeded.
  - `openclaw infer model run --model ollama/qwen3.6:latest --file generated/runtime_validation/pygame_reference_bundle/screens/caloris_combat.png ...` → OCR succeeded.
  - `zip -T <local durable mirror>-openclaw-runtime-evidence-2026-06-30.zip` → OK.
- Boundary:
  - this package is for review on systems that cannot run Pygame,
  - it does not replace runtime validation,
  - DOSBox first-map viewport capture remains corrupted in current Xvfb setup and is included only as failure evidence.

### Latest Pass: First Map Liveplay Capture and Qwen OCR Attempt (2026-06-30)
- Added reusable capture runner:
  - `scripts/capture_first_map_liveplay.py`
- Generated first-map capture attempts:
  - `generated/liveplay/first_map_capture/` → seeded-save route, 20 nonblank screenshots, corrupted viewport,
  - `generated/liveplay/first_map_fresh_capture/` → fresh-character route, 26 nonblank screenshots, corrupted viewport,
  - `generated/liveplay/first_map_fresh_capture_noescape/` → fresh route without boot `Escape`, 25 nonblank screenshots, corrupted viewport,
  - `generated/liveplay/first_map_direct_probe/` → direct live install boot probe, 1 nonblank screenshot, corrupted boot viewport.
- Important capture boundary:
  - the current DOSBox-X/Xvfb recording path is not producing readable first-map viewport screenshots,
  - Qwen classified the first-map viewport frame as corrupted and unusable for game-state text,
  - do not promote these new first-map viewport frames as original map text evidence.
- Qwen OCR sidecar:
  - used `openclaw infer model run --model ollama/qwen3.6:latest --file ...`,
  - `openclaw.image` Qwen batch attempts timed out, but the infer CLI with one image at a time succeeded.
- Generated OCR artifacts:
  - `generated/liveplay/first_map_qwen_ocr.md`
  - `generated/liveplay/first_map_qwen_ocr.json`
- Usable Qwen OCR reference captured from already-readable menu/title frames:
  - `generated/liveplay/screens/team_00_menu.png`: `CREATE NEW CHARACTER`, `ADD CHARACTER TO TEAM`, `LOAD SAVED GAME`, `JOYSTICK/MOUSE INITIALIZE`, `EXIT TO DOS`, `CHOOSE A FUNCTION SELECT`,
  - `generated/liveplay/screens/team3_00_load_from.png`: `LOAD FROM: MATRIX COUNTDOWN`,
  - `generated/liveplay/screens/gamesave_00_full_menu.png`: `NAME AC HP`, `CAR1 4 38`, `CREATE NEW CHARACTER`, `PURGE CHARACTER`, `MODIFY CHARACTER`, `ICON SELECT`, `VIEW CHARACTER`, `ADD CHARACTER TO TEAM`, `REMOVE CHARACTER FROM TEAM`, `SAVE CURRENT GAME`, `BEGIN ADVENTURING`, `EXIT TO DOS`, `CHOOSE A FUNCTION SELECT`,
  - `generated/liveplay/screens/s00_boot.png`: title/copyright text plus a DOSBox-X quit warning overlay.
- Memory/save evidence:
  - the fresh/copy capture route did not successfully write useful post-run save files,
  - no new map-state mutation was proven in this pass.
- Commands run:
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/capture_first_map_liveplay.py --boot-wait 12` → 20 nonblank screenshots, corrupted viewport.
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/capture_first_map_liveplay.py --fresh --out-dir generated/liveplay/first_map_fresh_capture --boot-wait 12` → 26 nonblank screenshots, corrupted viewport.
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/capture_first_map_liveplay.py --fresh --out-dir generated/liveplay/first_map_fresh_capture_noescape --boot-wait 12 --no-boot-escape --title-returns 8` → 25 nonblank screenshots, corrupted viewport.
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/capture_first_map_liveplay.py --direct-use-source --probe-only --out-dir generated/liveplay/first_map_direct_probe --boot-wait 12` → 1 nonblank screenshot, corrupted boot viewport.
  - `openclaw infer model run --model ollama/qwen3.6:latest --file ...` → Qwen OCR succeeded for individual readable/corrupted frames.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/capture_first_map_liveplay.py` → passed.
- Next capture-specific work:
  - fix the DOSBox-X/Xvfb capture/rendering path before relying on first-map viewport OCR,
  - compare current corrupt screenshots against the known-readable `team_00_menu.png` run conditions,
  - once viewport capture is readable, rerun first-map route and Qwen OCR on actual world/event frames.

### Latest Pass: Original Archive and DOS Capture Target Audit (2026-06-30)
- Added `scripts/audit_original_capture_targets.py`.
- Added `tests/test_original_capture_target_audit.py`.
- Generated:
  - `generated/validation/original_capture_target_audit.json`
  - `generated/validation/original_capture_target_audit.md`
- Audited local game directories:
  - `$MATRIX_CUBED_GAME_DIR`
  - `<local Matrix Cubed liveplay capture folder>`
- Verified present archive names in both audited directories:
  - `GEO1.DAX`
  - `ECL1.DAX`
- Verified missing archive names in the audited local directories:
  - `GEO2.DAX`
  - `GEO3.DAX`
  - `GEO4.DAX`
  - `ECL2.DAX`
  - `ECL3.DAX`
  - `ECL4.DAX`
- Boundary:
  - this proves absence only from the audited local directories,
  - it does not prove those names never existed in another release/install source.
- Existing capture coverage:
  - ship-service menus: missing, 0 confidently matched captures,
  - choice dialogs: 2 existing interaction/search-family captures, not OCR-confirmed,
  - Caloris/Luna transitions: missing, 0 exact transition captures,
  - combat state changes: 1 combat UI capture exists, but state mutation remains unproven.
- Combat save-state evidence:
  - pre `SAVGAMA.DAT` SHA-256: `ae0f4283336d809349e0dd08d997fd63920ae8be0e97d125eeb1da41b975f581`,
  - post `SAVGAMA.DAT` SHA-256: `ae0f4283336d809349e0dd08d997fd63920ae8be0e97d125eeb1da41b975f581`,
  - byte diff: 0 changed bytes,
  - interpretation: current capture does not prove original combat/session state mutation.
- Decoded transition anchors now surfaced for the next capture pass:
  - ECL `LOAD FILES` GEO 1 at `0x808E`, entry `(9,4)`,
  - ECL `LOAD FILES` GEO 17 at `0x805E`,
  - ECL 19 `LOAD FILES` GEO 17 at `0x8051`,
  - ECL 24 `LOAD FILES` GEO 64 at `0x803E`, entry `(13,8)`,
  - ECL `LOAD FILES` GEO 64 at `0x803A`, entry `(11,15)`,
  - Luna GEO 1/GEO 64 cell-edge candidates are listed in the generated audit.
- Recommended next DOS recordings:
  - ship-service menu route with screenshots before selection, each menu page, and save/memory snapshot after service actions,
  - OCR-readable Caloris Dr. Romney/autodoc dialog and at least one selected branch,
  - Caloris/Luna transition capture with pre/post `SAVGAMA.DAT`,
  - combat capture that actually changes `SAVGAMA.DAT` or character files.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/audit_original_capture_targets.py` → audit complete, 6 missing archive names, 2 missing capture targets.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_original_capture_target_audit.py` → 1 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_original_capture_target_audit.py tests/test_combat_runtime_validation.py tests/test_story_progression_scene_validation.py tests/test_phase_b_transitions.py` → 12 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 182 passed.
- DeepSeek sidecar status:
  - verified the supplied audit facts, missing archive list, byte-identical save pair, transition anchors, and test results,
  - correctly flagged risks around missing targeted captures, no OCR-confirmed dialog text, and no proven combat state mutation,
  - made unsupported hypotheses about missing archives being required and anchor mismatch; those were not accepted into project facts.

### Latest Pass: Combat Runtime Validation Evidence (2026-06-30)
- Incoming pass at `<local durable mirror>-openclaw-pygame-validated-2026-06-29 (2)/matrix-cubed-re` matched the active project tree after excluding `.git`, `.venv`, caches, and bytecode; no separate patch set was present to merge.
- Followed the documented next priority for combat validation.
- Added `scripts/validate_combat_runtime.py`.
- Added `tests/test_combat_runtime_validation.py`.
- Generated:
  - `generated/validation/combat_runtime_validation.json`
  - `generated/validation/combat_runtime_validation.md`
- Confirmed exact decoded queue evidence:
  - Caloris GEO 017 event 7,
  - combat type,
  - constant `SETUP_MONSTER` operand resolving to MON0CHA monster id `52`,
  - monster name `RAM WARRIOR`,
  - ECL address `0x8C54`,
  - exact queue confidence recorded as 98%.
- Tied the queue to local DOS evidence:
  - `generated/liveplay/screens/14_after_combat_inputs.png`,
  - SHA-256 `ce05dfe1e7b292bb09f6121ecb712a08605424597cd21726f5e4dafe58cd43d4`,
  - pre/post `SAVGAMA.DAT` hashes are identical: `ae0f4283336d809349e0dd08d997fd63920ae8be0e97d125eeb1da41b975f581`.
- Important boundary:
  - the identical pre/post `SAVGAMA.DAT` hash and unchanged decoded party fields mean this capture set does not prove original combat state mutation,
  - the current Python combat loop remains a deterministic scaffold using derived THAC0/damage stats, not a proven original turn-by-turn combat model,
  - runtime combat simulation confidence is therefore recorded as 45%.
- Deterministic runtime scaffold check:
  - seed `52017`,
  - queued RAM WARRIOR encounter resolves in 12 rounds,
  - victory true, defeat false.
- DeepSeek sidecar status:
  - responded successfully,
  - verified the supplied facts from the evidence,
  - flagged the same risks: identical save hashes, low-confidence derived combat formulas, and one-seed runtime coverage.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/validate_combat_runtime.py` → 5/5 checks.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_combat_runtime_validation.py tests/test_story_progression_scene_validation.py tests/test_runtime_probe.py` → 8 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/validate_combat_runtime.py && PYTHONPATH=src python3 -m pytest -q` → 181 passed.
- Next combat-specific work:
  - decode `SAVGAMA.DAT` combat/session bytes around pre/post capture sets,
  - capture an OCR-readable DOS combat transcript for Caloris event 7,
  - replace derived combat formulas only when original combat fields or DOS turn logs validate them.

### Previous Pass: OpenClaw Pygame Runtime Validation (2026-06-29)
- Verified project venv has:
  - Python 3.12.3,
  - Pygame 2.6.1 / SDL 2.28.4,
  - Pillow,
  - pytest.
- Verified host tools:
  - `/usr/bin/xvfb-run`,
  - `/usr/bin/xdotool`,
  - OpenClaw gateway environment present.
- Fixed Pygame runtime boot failure:
  - `MapEngine.load_map()` expected `repo.find_ecl(map_id)`,
  - `ReconstructedData` now exposes `find_ecl()` as a compatibility adapter for map engine use.
- Added `scripts/validate_pygame_runtime.py`.
- Added `docs/openclaw-pygame-runtime-validation-pass-1.md`.
- Generated:
  - `generated/runtime_validation/pygame_runner_xvfb_smoke.json`
  - `generated/runtime_validation/pygame_runner_xvfb_smoke.png`
- Runtime smoke command:
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/validate_pygame_runtime.py`
- Runtime smoke result:
  - selected Continue from the real Pygame menu,
  - entered the world render,
  - toggled inventory,
  - posted one movement key,
  - captured a screenshot,
  - exited cleanly via ESC.
- Screenshot validation:
  - display size: 1024x768,
  - PNG size: 9876 bytes,
  - unique colors: 208,
  - nonblack pixels: 662272.
- Commands run:
  - `source .venv/bin/activate && xvfb-run -a env SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 scripts/validate_pygame_runtime.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/validate_pygame_runtime.py src/matrix_cubed/data/repository.py src/matrix_cubed/tools/pygame_runner.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_phase_b_transitions.py tests/test_map_traversal_reference.py tests/test_map_engine.py` → 35 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 180 passed.
- DeepSeek sidecar status:
  - responded successfully,
  - verified the environment, smoke output, `find_ecl()` fix, and validation results from the supplied evidence,
  - flagged the expected residual limits: audio disabled, native window-manager/manual-play behavior untested, shallow route coverage, and no rendering-accuracy comparison yet.
- Boundary:
  - This validates OpenClaw/Xvfb Pygame boot/menu/world-render/event-loop viability.
  - It does not validate native desktop window-manager behavior, audio, manual play feel, or full story-route correctness.

### Latest Pass: ECL LOAD FILES Transition Runtime Integration (2026-06-29)
- Updated `scripts/build_map_traversal_reference.py`:
  - widened nearby `SAVE mapPosX/mapPosY` scanning for `LOAD FILES Load GEO` rows,
  - stops coordinate collection at ECL control-flow terminators so coordinates do not leak from the next branch.
- Regenerated:
  - `generated/traversal/map_traversal_reference.json`
  - `generated/traversal/map_traversal_reference.md`
- Updated `src/matrix_cubed/data/repository.py`:
  - `EclLoadRef` now preserves `address`, `raw_operands`, `map_pos_x`, and `map_pos_y`,
  - `CellTransitionRef` now carries optional `target_col`/`target_row`,
  - `ReconstructedData.entry_position_for_map()` exposes complete, conservative target entry coordinates.
- Updated `src/matrix_cubed/engine/events.py`:
  - `compile_event_commands()` accepts exact ECL load refs and emits `load_geo` commands.
- Updated `src/matrix_cubed/engine/runtime.py`:
  - promoted cell transitions now use validated target entry coordinates when available,
  - exact event-target-to-`LOAD FILES` address matches execute `load_geo` only when coordinates are available,
  - source map/event flags remain tied to the source event even after a transition changes maps.
- Added `docs/ecl-load-files-transition-runtime-pass-1.md`.
- Expanded `tests/test_phase_b_transitions.py`.
- Verified coordinate examples:
  - GEO 001 entry `(9,4)`,
  - GEO 034 entry `(7,15)`,
  - GEO 064 entry `(11,15)`,
  - GEO 112 promoted cell transition to GEO 034 now enters at `(7,15)`.
- Validation boundary:
  - This pass uses ECL disassembly `LOAD FILES` plus same-branch `SAVE mapPosX/mapPosY` evidence for coordinates.
  - Existing DOS capture validation anchors scene families/UI availability, not exact coordinate OCR.
  - Existing runtime events do not yet carry complete instruction ranges, so ECL load execution is exact-address only.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/build_map_traversal_reference.py` → 20/25 loaded maps covered by current evidence.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_phase_b_transitions.py tests/test_map_traversal_reference.py` → 11 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 179 passed.
- DeepSeek sidecar status:
  - responded successfully,
  - verified the supplied implementation facts and validation results,
  - agreed with the main risks: 20/25 loaded maps covered, no DOS coordinate OCR, and no full ECL instruction-range execution yet.

### Latest Pass: Phase B Transition Runtime Integration (2026-06-29)
- Reviewed external agent-mode drop at `<local external phase-B handoff folder>`.
- Integrated the useful runtime changes without overwriting newer source-recovery work.
- Added transition evidence models in `src/matrix_cubed/data/repository.py`:
  - `CellTransitionRef` for promoted cell-edge transitions from `generated/traversal/map_traversal_reference.json`.
  - `EclLoadRef` for loaded ECL `LOAD FILES` GEO references, stored for later event-transition work.
- `ReconstructedData.from_generated()` now loads traversal references:
  - promotes only `cell_edges` rows where `interpretation == "promoted_transition"` and `target_loaded` is true,
  - stores loaded `ecl_loads` rows by ECL block.
- `GameState.move()` now checks `data.cell_transition(map_id, row, col)` before the legacy event-id fallback.
- Added `tests/test_phase_b_transitions.py`.
- Added `docs/phase-b-transition-runtime-pass-1.md`.
- Validation boundary:
  - This pass does not infer new transitions.
  - Transition destinations still enter at `(1,1)` until target coordinates are validated.
  - `EclLoadRef` entries are loaded but not executed yet.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_phase_b_transitions.py tests/test_map_traversal_reference.py` → 8 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 176 passed.
- DeepSeek sidecar status:
  - responded successfully,
  - verified the supplied integration facts and test results,
  - flagged the same risks: default target coordinates and non-executed ECL load refs remain future work.

### Latest Pass: Load3DMap Cluster Resolution (2026-06-29)
- Added `scripts/resolve_load3dmap_cluster.py`.
- Added `tests/test_load3dmap_cluster_resolution.py`.
- Added `docs/load3dmap-cluster-resolution-pass-1.md`.
- Generated:
  - `generated/source_recovery/load3dmap_cluster_resolution.json`
  - `generated/source_recovery/load3dmap_cluster_resolution.md`
- Raw-disassembly resolution:
  - The `Load3DMap` text anchor is embedded string/data, not a function entry.
  - Payload `0x30AAF-0x30ACF` decodes to ASCII bytes for `Unable to load geo in Load3DMap.`.
  - Loader-shaped code window is payload `0x30AD0-0x30C10`.
  - `3000:0c04` maps to payload `0x30C04`, inside the instruction beginning at payload `0x30C01`; the tiny return decompile is a misaligned-entry artifact.
  - `3000:006f` remains a wall/span emit candidate and is not the `Load3DMap` file-load/copy routine.
- Confidence:
  - `Load3DMap` text anchor is string/data: 99%.
  - `0x30AD0-0x30C10` is loader-shaped routine: 90%.
  - `3000:0c04` is misaligned epilogue entry: 99%.
  - `3000:006f` is not the loader: 85%.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/resolve_load3dmap_cluster.py` → resolved loader-shaped window `0x30AD0-0x30C10`.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_load3dmap_cluster.py scripts/resolve_source_recovery_roles.py scripts/triage_unknown_source_recovery_batch.py scripts/label_all_unknown_source_recovery.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_load3dmap_cluster_resolution.py tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py tests/test_unknown_source_recovery_batch.py tests/test_all_unknown_source_recovery_labels.py` → 12 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 171 passed.
- DeepSeek sidecar status:
  - responded successfully,
  - verified the supplied facts that `0x30AAF-0x30ACF` is string/data, `0x30AD0-0x30C10` is loader-shaped code, and `3000:0c04` is a misaligned epilogue entry,
  - flagged the correct caveat that this is not yet a full runtime-validated `Load3DMap` reconstruction.

### Latest Pass: Source Recovery All Unknown Labels (2026-06-29)
- Added `scripts/label_all_unknown_source_recovery.py`.
- Added `tests/test_all_unknown_source_recovery_labels.py`.
- Added `docs/source-recovery-all-unknown-labels.md`.
- Generated:
  - `generated/source_recovery/all_unknown_function_labels.json`
  - `generated/source_recovery/all_unknown_function_labels.md`
- Coverage:
  - Total prior unknowns labeled: 958.
  - `GAME.OVR` labels: 600.
  - `START.unpacked.exe` labels: 358.
  - Already covered by unknown batch 001: 100.
  - Newly labeled outside batch 001: 858.
- Status counts:
  - `labeled_static_shape`: 648.
  - `labeled_for_followup`: 219.
  - `labeled_boundary_or_stub`: 49.
  - `labeled_not_liftable_without_raw_review`: 42.
- Label counts:
  - `single_call_wrapper`: 174.
  - `multi_call_small_helper`: 131.
  - `small_local_computation_or_data_move`: 128.
  - `direct_memory_state_helper`: 96.
  - `large_no_call_data_transform`: 62.
  - `call_heavy_coordinator`: 54.
  - `return_only_stub_or_boundary`: 49.
  - `bad_decode_or_mixed_code_data`: 42.
  - `string_referencing_helper`: 3.
  - `insufficient_static_evidence`: 219.
- Confidence policy:
  - Confidence is about the static label being correct.
  - Confidence is not about original function names.
  - Confidence is not runtime validation.
  - `insufficient_static_evidence` has high confidence because it means the script is deliberately refusing to guess.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/label_all_unknown_source_recovery.py` → 958 prior unknowns labeled.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_source_recovery_roles.py scripts/triage_unknown_source_recovery_batch.py scripts/label_all_unknown_source_recovery.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_all_unknown_source_recovery_labels.py` → 2 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py tests/test_unknown_source_recovery_batch.py tests/test_all_unknown_source_recovery_labels.py` → 10 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 169 passed.
- DeepSeek sidecar status:
  - responded successfully,
  - agreed with the main confidence boundary: static labels are not original names or runtime behavior,
  - highlighted follow-up work for `insufficient_static_evidence` and `bad_decode_or_mixed_code_data` buckets.

### Latest Pass: Source Recovery Unknown Batch 001 (2026-06-29)
- Added `scripts/triage_unknown_source_recovery_batch.py`.
- Added `tests/test_unknown_source_recovery_batch.py`.
- Added `docs/source-recovery-unknown-batch-001.md`.
- Generated:
  - `generated/source_recovery/unknown_batch_001_resolution.json`
  - `generated/source_recovery/unknown_batch_001_resolution.md`
- Scope:
  - Only `GAME.OVR` functions from the prior unknown queue were eligible.
  - The batch stopped at 100 selected functions.
  - The batch assigns only mechanically supported static-shape categories, not original names or subsystem guesses.
- Results:
  - Eligible `GAME.OVR` unknowns before this batch: 600.
  - Selected/resolved in this batch: 100.
  - Remaining unbatched `GAME.OVR` unknowns: 500.
  - Remaining unbatched unknowns across START plus GAME.OVR: 858.
  - Status counts: `resolved_bad_decode` 24, `resolved_stub_or_boundary` 37, `resolved_static_shape` 39.
  - Category counts: `bad_decode_or_mixed_code_data` 24, `return_only_stub_or_boundary` 37, `single_call_wrapper` 39.
- Interpretation:
  - `bad_decode_or_mixed_code_data` entries should not be lifted until raw bytes and Ghidra xrefs are inspected.
  - `return_only_stub_or_boundary` entries should be treated as padding, boundaries, or possible misidentified function starts until xrefs prove otherwise.
  - `single_call_wrapper` entries should be resolved by following their wrapped callees before assigning subsystem behavior.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/triage_unknown_source_recovery_batch.py` → 100/600 eligible GAME.OVR unknowns resolved.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_source_recovery_roles.py scripts/triage_unknown_source_recovery_batch.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_unknown_source_recovery_batch.py` → 2 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py tests/test_unknown_source_recovery_batch.py` → 8 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 167 passed.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the static-shape boundary:
  - this batch does not identify original names or runtime behavior,
  - single-call wrappers need caller/callee context before subsystem promotion,
  - stub/boundary entries need raw xref checks before omission.

### Latest Pass: Source Recovery Role Resolution (2026-06-29)
- Added `scripts/resolve_source_recovery_roles.py`.
- Added `tests/test_source_recovery_role_resolution.py`.
- Added `docs/source-recovery-role-resolution-pass-1.md`.
- Generated:
  - `generated/source_recovery/function_role_resolution.json`
  - `generated/source_recovery/function_role_resolution.md`
- Resolution result:
  - Candidates: 23.
  - Static triage decisions: 23/23.
  - `resolved_static`: 18.
  - `resolved_stub_or_boundary`: 3.
  - `resolved_bad_decode`: 2.
- Key resolved behavior candidates:
  - `0000:fb92 FUN_0000_fb92`: combat roster and battlefield setup.
  - `1000:8467 FUN_1000_8467`: character record initial field fill.
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
- Resolved as not liftable without deeper raw-byte/Ghidra work:
  - `0000:0385 FUN_0000_0385`: bad decode or mixed code/data near credits anchor.
  - `1000:0131 FUN_1000_0131`: empty combat boundary candidate.
  - `1000:ce56 FUN_1000_ce56`: empty shop boundary candidate.
  - `2000:1c53 FUN_2000_1c53`: empty save boundary candidate.
  - `3000:0c04 FUN_3000_0c04`: misaligned Ghidra entry inside the `Load3DMap` epilogue instruction.
- Interpretation:
  - "Resolved" here means removed from the unknown/likely-only queue by static evidence.
  - It does not mean runtime-validated or original function-name recovery.
  - Next implementation-quality pass should pick one subsystem and validate behavior against DOS captures/saves before promoting into runtime code.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/build_source_recovery_corpus.py` → START 358/358, GAME.OVR 623/623.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/infer_source_recovery_roles.py` → 981 scanned, 23 roles inferred.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/resolve_source_recovery_roles.py` → 23/23 resolved.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py scripts/resolve_source_recovery_roles.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_role_resolution.py` → 2 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py tests/test_source_recovery_role_resolution.py` → 6 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 165 passed.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the core caveat:
  - the 23 candidates are resolved for static triage only,
  - they are not original function names or runtime-validated behavior,
  - boundary/stub classifications and the bad-decode region still need raw-byte/Ghidra xref inspection before promotion.

### Latest Pass: Source Recovery Role Inference (2026-06-29)
- Added `scripts/infer_source_recovery_roles.py`.
- Added `tests/test_source_recovery_role_inference.py`.
- Added `docs/source-recovery-role-inference-pass-1.md`.
- Generated:
  - `generated/source_recovery/function_role_inference.json`
  - `generated/source_recovery/function_role_inference.md`
- Coverage:
  - Functions scanned: 981.
  - Functions with inferred roles: 23.
  - Functions left unknown: 958.
  - Confidence counts: high 7, medium 5, low 11, unknown 958.
- Current likely high/medium-value GAME.OVR roles:
  - `1000:8467 FUN_1000_8467`: character creation/setup candidate.
  - `2000:1fd4 FUN_2000_1fd4`: character sheet/status candidate.
  - `2000:b876 FUN_2000_b876` and `2000:b749 FUN_2000_b749`: ship status/travel-resource candidates.
  - `1000:fad0 FUN_1000_fad0`: save/load or save-character persistence candidate.
  - `1000:eeec FUN_1000_eeec` and `1000:eb60 FUN_1000_eb60`: item catalog/detail/inventory data candidates.
  - `2000:13fd FUN_2000_13fd`: save/load candidate near both load/save anchors.
  - `1000:f67d FUN_1000_f67d`: save-character persistence candidate.
  - `0000:fb92 FUN_0000_fb92`: combat candidate with heavy direct-memory access.
- `Load3DMap`/WALLDEF cluster is now resolved by raw disassembly:
  - `3000:006f FUN_3000_006f` is call-heavy and behavior-rich but belongs to the wall/span emit side, not the loader.
  - `3000:0c04 FUN_3000_0c04` is a misaligned Ghidra entry inside the loader epilogue instruction.
  - The loader-shaped code window is payload `0x30AD0-0x30C10`.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/infer_source_recovery_roles.py` → 981 scanned, 23 roles inferred.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py scripts/infer_source_recovery_roles.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py tests/test_source_recovery_role_inference.py` → 4 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 163 passed.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the conservative stance:
  - the 23 role labels are triage hypotheses, not recovered original names,
  - missing overlay relocation context remains a core risk,
  - `3000:0c04` is now resolved as a misaligned epilogue entry by local raw-disassembly evidence,
  - behavior validation is still required before runtime promotion.

### Latest Pass: Source Recovery Corpus (2026-06-29)
- Added `scripts/build_source_recovery_corpus.py`.
- Added `tests/test_source_recovery_corpus.py`.
- Added `docs/source-recovery-corpus-pass-1.md`.
- Generated:
  - `generated/source_recovery/manifest.json`
  - `generated/source_recovery/README.md`
  - `generated/source_recovery/start_unpacked/*.c`
  - `generated/source_recovery/game_ovr_payload/*.c`
- Coverage:
  - `START.unpacked.exe`: 358/358 recovered pseudocode files.
  - `GAME.OVR` raw payload: 623/623 recovered pseudocode files.
  - Combined: 981/981 recovered pseudocode files.
  - Missing decompile output files: 0.
  - GAME.OVR recovered files with nearby project anchors: 23.
- Interpretation:
  - This is the cleanest current "full source recovery" artifact, but it is not original/source-equivalent SSI code.
  - Every recovered file records Ghidra entry, linear address, `GAME.OVR` original file offset where applicable, calling convention, evidence limits, and nearby anchor roles.
  - `GAME.OVR` offset mapping remains `original GAME.OVR file offset = segment * 16 + offset + 8`.
  - Runtime changes still require local validation against bytes, generated DAX/ECL/GEO artifacts, and DOS captures before promotion.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/build_source_recovery_corpus.py` → START 358/358, GAME.OVR 623/623.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile scripts/build_source_recovery_corpus.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_source_recovery_corpus.py` → 2 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 161 passed.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the main limits:
  - the corpus is complete for exported pseudocode files,
  - pseudocode is not source-equivalent original SSI code,
  - raw `GAME.OVR` still lacks overlay relocation/manager context,
  - semantic correctness still needs behavior validation before runtime promotion.

### Latest Pass: Shared Dialog Runtime / Traversal Evidence (2026-06-29)
- Updated shared runtime/data model:
  - `src/matrix_cubed/data/repository.py`
  - `src/matrix_cubed/engine/events.py`
  - `src/matrix_cubed/engine/runtime.py`
  - `src/matrix_cubed/tools/pygame_runner.py`
- Added traversal evidence tooling:
  - `scripts/build_map_traversal_reference.py`
  - `tests/test_map_traversal_reference.py`
- Extended runtime tests:
  - `tests/test_runtime_probe.py`
- Generated:
  - `generated/traversal/map_traversal_reference.json`
  - `generated/traversal/map_traversal_reference.md`
- Runtime behavior promoted:
  - `Event` now preserves `DialogRef`/`DialogChoice` from `generated/viewer/matrix_cubed_runtime_seed.json`.
  - `compile_event_commands()` emits `offer_dialog_choices` for events with recovered ECL dialog labels.
  - `GameState.execute_dialog_choice()` records the selected label, branch target evidence, a `dialog:<geo>:<event>:<choice>` flag, and snapshot-visible `last_dialog_selection`.
  - Pygame displays numbered dialog choices in the viewport and accepts number keys `1`-`9` for selection.
  - Existing event overlay draw order was fixed so the viewport no longer overwrites event text.
- Traversal behavior promoted:
  - Movement no longer attempts to treat every unflagged cell event id as a map transition.
  - It now transitions only if the cell target is an already loaded decoded GEO map; otherwise it logs `unpromoted local event cell <id>`.
- Traversal reference evidence:
  - Loaded maps: 25.
  - Current ECL/cell evidence covers 20/25 loaded maps.
  - Still unresolved by the current traversal evidence report: GEO 51, 80, 82, 113, 115.
  - Evidence limit: ECL `LOAD FILES Load GEO` rows prove load targets, not complete player route conditions.
- Chrome validation:
  - Used James' requested Chrome path `/usr/bin/google-chrome`.
  - Local server + headless screenshot succeeded:
    - `/tmp/matrix_cubed_runtime_chrome_smoke.png`
    - 1280x900
    - 3,077 unique colors in sampled viewport area
    - 107,865 non-dark sampled pixels
- DeepSeek sidecar reviewed the supplied evidence and agreed with the main limits:
  - dialog selection is runtime state tracking, not a full ECL VM,
  - traversal coverage is currently 20/25 loaded maps,
  - unresolved traversal maps remain GEO 51, 80, 82, 113, and 115,
  - save/load persistence for dialog flags should be validated in a later pass.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/build_map_traversal_reference.py` → 20/25 loaded maps covered.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_runtime_probe.py tests/test_map_traversal_reference.py` → 9 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_runtime_probe.py tests/test_map_traversal_reference.py tests/test_story_progression_scene_validation.py` → 10 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m py_compile src/matrix_cubed/tools/pygame_runner.py scripts/build_map_traversal_reference.py` → passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 159 passed.

### Latest Pass: HTML Story Progression Runtime Bridge (2026-06-29)
- Updated `scripts/build_map_viewer.py`.
- Added `tests/test_html_runtime_dialog.py`.
- Added `scripts/validate_story_progression_scenes.py`.
- Added `tests/test_story_progression_scene_validation.py`.
- Regenerated:
  - `generated/viewer/matrix_cubed_runtime_seed.json`
  - `generated/viewer/matrix_cubed_runtime_prototype.html`
  - `generated/viewer/matrix_cubed_map_viewer.html`
  - `generated/validation/story_progression_scene_validation.json`
  - `generated/validation/story_progression_scene_validation.md`
- Runtime bridge changes:
  - Each runtime map now carries `surfaceTextures` when generated `walldef1_*` floor/ceiling sprite candidates exist.
  - The HTML first-person viewport now loads those surface texture PNGs asynchronously and tiles them for ceiling/floor, falling back to the prior gradients if unavailable.
  - `--dialog-reference-json` wires `generated/ecl_text_goldbox/ecl_dialog_reference.json` into runtime seed events.
  - Events with confirmed dialog-reference labels now render executable buttons. Clicking a button records a dialog flag/log row and shows the selected branch evidence in state.
  - Caloris examples now include event 20 `HELP ROMNEY` and event 28 `SOMEONE ELSE?` from the ECL dialog reference.
- Story progression validation:
  - Five scene-family checks pass:
    - Caloris floor/ceiling sprite availability,
    - Caloris Dr. Romney dialog choice,
    - Caloris autodoc branch choice,
    - Caloris RAM Warrior combat queue,
    - GEO 021 dynamic combat candidate table.
  - DOS capture hashes/dimensions are recorded for the relevant liveplay screenshots.
  - Evidence limit is explicit: current DOS screenshots anchor scene families/UI availability, but exact prompt OCR and pixel-equivalence remain targeted liveplay work.
- Browser smoke note:
  - A temporary local static server was started for headless Chromium validation, but the installed `/snap/bin/chromium` wrote the screenshot inside snap namespace isolation and the shell could not read it afterward. Use non-snap Chromium or Playwright for future browser screenshots.
  - James preference from 2026-06-29: use Chrome, not Chromium, for browser validation. Chrome is available locally at `/usr/bin/google-chrome`; prefer that path for future HTML screenshots/smoke tests.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the main limits:
  - dialog choice clicks record runtime state/logs but are not full ECL VM branch execution yet,
  - DOS screenshot hashes/dimensions are useful anchors but not prompt OCR or pixel-equivalence validation,
  - browser visual validation still needs a non-snap browser or Playwright.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_html_runtime_dialog.py` → 3 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/build_map_viewer.py ... --dialog-reference-json generated/ecl_text_goldbox/ecl_dialog_reference.json` → regenerated viewer/runtime artifacts.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/validate_story_progression_scenes.py` → validated 5/5 story progression scenes.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_html_runtime_dialog.py tests/test_story_progression_scene_validation.py` → 4 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 154 passed.

### Latest Pass: Walkthrough Development Reference (2026-06-29)
- Added `docs/walkthrough-development-reference.md`.
- Source: GameFAQs, "Buck Rogers: Matrix Cubed - Guide and Walkthrough" by kibbitz, updated 2023-08-30:
  - `https://gamefaqs.gamespot.com/pc/577927-buck-rogers-matrix-cubed/faqs/80490`
- Use policy:
  - Treat the walkthrough as secondary gameplay evidence for route validation, smoke tests, coordinate checks, and feature prioritization.
  - Do not copy walkthrough prose into runtime data, generated game text, or source-equivalent reconstruction artifacts.
  - Local binaries, decoded DAX/GEO/ECL artifacts, and DOS captures remain primary evidence.
- Development uses captured:
  - start-to-finish route order,
  - Caloris opening checkpoints,
  - ship fuel/travel systems,
  - Stormrider University and Jupiter finale checkpoints,
  - captured/no-equipment segment requirements,
  - route-runner/test backlog.
- Next useful pass:
  - Create a compact Caloris route-validation dataset that ties walkthrough coordinates to decoded GEO event cells and ECL branch targets, then verify with DOS captures.

### Latest Pass: Gold Box Explorer Map Audit (2026-06-29)
- Tried the local Gold Box Explorer source from `<local Gold Box Explorer checkout>`.
- `dotnet`, `msbuild`, `xbuild`, `mcs`, and `mono` were not available, so the Windows GUI/editor could not be run directly in this environment.
- Used Gold Box Explorer's source table instead:
  - `Common/Plugins/GeoDax/GeoDaxFile.cs`
  - `FileHelper.GameList.MatrixCubed`
- Added `scripts/audit_goldbox_explorer_maps.py`.
- Added `tests/test_goldbox_explorer_map_audit.py`.
- Generated:
  - `generated/goldbox_explorer_maps/goldbox_explorer_map_audit.json`
  - `generated/goldbox_explorer_maps/goldbox_explorer_map_audit.tsv`
  - `generated/goldbox_explorer_maps/goldbox_explorer_map_audit.md`
- Evidence recorded:
  - Local source directory contains `GEO1.DAX` and `ECL1.DAX` only; archive scans found no `GEO2.DAX`, `GEO3.DAX`, `GEO4.DAX`, `ECL2.DAX`, `ECL3.DAX`, or `ECL4.DAX` in available Matrix Cubed copies/zips.
  - Local `GEO1.DAX` decodes to 25 GEO blocks, all 1026 bytes.
  - Gold Box Explorer's Matrix Cubed table names 24 GEO IDs.
  - Gold Box Explorer named maps missing locally: 0.
  - Local GEO IDs missing Gold Box Explorer names: `[21]`.
- Interpretation:
  - This supports treating the current 25 decoded `GEO1.DAX` blocks as all map blocks available in the current local source set.
  - Gold Box Explorer does not provide evidence for missing Matrix Cubed `GEO2-4` archives or additional named maps.
  - Future "more maps" work should switch from assumed numbered-archive recovery to either finding a different original disk/install source or validating all 25 maps via event/ship/world traversal.
- Commands run:
  - `find <local user home> ... GEO/ECL/archive scan` → only `GEO1.DAX`/`ECL1.DAX` found in Matrix Cubed source/prototype copies; source zips list only those GEO/ECL archives.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_goldbox_explorer_map_audit.py tests/test_game_ovr_map_scan.py` → 4 passed.
  - `PYTHONPATH=src python3 scripts/audit_goldbox_explorer_maps.py` → 25 local GEO blocks, 24 GBE named maps, 0 GBE named maps missing locally.

### Latest Pass: ECL Dialog Tree Reference / Missing Text Attachment (2026-06-29)
- Added `scripts/build_ecl_dialog_reference.py`.
- Added `tests/test_ecl_dialog_reference.py`.
- Added durable markdown reference:
  - `docs/ecl-dialog-trees-reference.md`
- Generated:
  - `generated/ecl_text_goldbox/ecl_dialog_reference.json`
  - `generated/ecl_text_goldbox/ecl_missing_text_attachments.tsv`
- Evidence recorded:
  - Input missing-text evidence remains `generated/ecl_text_goldbox/ecl_text_compare.json` field `comparison.goldbox_substring_missing_hits`.
  - The pass attaches 123 hit-level still-missing Gold Box text rows to decoded ECL branch-target regions.
  - Those 123 hit rows cover the expected 75 unique normalized still-missing strings.
  - The output preserves the prior address mapping: `vm_address = 0x8000 + decoded ECL block offset`.
  - Every attachment records owner ECL block, raw offset, VM address, owner branch target, incoming branch/menu sources when known, and a nearest decoded owner-summary row.
  - The markdown reference then lays out all currently extracted dialog/menu text by ECL block, with GEO names from the event atlas where available.
- Interpretation:
  - This is stronger than the previous nearest-row context pass because it groups missing packed strings under concrete decoded branch-target regions and records incoming branch sources.
  - It is still evidence, not runtime ownership proof. Several remaining strings sit in packed data islands after exits/returns or near loader/menu data and need instruction-format validation before being compiled into runtime dialog.
  - High-value next work is to improve the ECL disassembler's menu/prompt operand recovery around ECL 95, 84, 64, 80, 96, 97, 98, 112, and 113, then promote confirmed dialog choices into the runtime conversation compiler.
- Commands run:
  - `PYTHONPATH=src python3 -m pytest -q tests/test_goldbox_ecl_text.py tests/test_goldbox_ecl_text_context.py tests/test_ecl_dialog_reference.py` → 9 passed.
  - `PYTHONPATH=src python3 scripts/build_ecl_dialog_reference.py` → 123 missing text hit attachments, 75 unique strings, 33 ECL listing blocks.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 149 passed.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the conservative stance. Its initial dependency concern was resolved by running the suite inside the project `.venv`; it repeated that attachments are not runtime ownership proof until ECL menu/prompt operand formats are validated locally.

### Latest Pass: Gold Box ECL Text Contextualization (2026-06-27)
- Added `scripts/contextualize_goldbox_ecl_text.py`.
- Added `tests/test_goldbox_ecl_text_context.py`.
- Added `docs/ecl-text-context-pass-1.md`.
- Generated:
  - `generated/ecl_text_goldbox/goldbox_ecl_text_context.json`
  - `generated/ecl_text_goldbox/goldbox_ecl_text_context.tsv`
  - `generated/ecl_text_goldbox/goldbox_ecl_text_context.md`
- Evidence recorded:
  - Input is `generated/ecl_text_goldbox/ecl_text_compare.json` field `comparison.goldbox_substring_missing_hits`.
  - Address mapping used for context only: `vm_address = 0x8000 + decoded ECL block offset`.
  - Output has 123 hit-level contexts across 27 ECL blocks.
  - Context kinds: `short_choice_or_label` 103, `label_fragment` 13, `inline_text_fragment` 7.
  - The earlier Gold Box comparison's 75 value is the unique normalized still-missing text count; this pass preserves duplicate hit offsets intentionally.
- Interpretation:
  - Most remaining whole-block-only strings look like menu choices, labels, prompt fragments, and short table resources (`CONVINCE`, `DECLINE`, `WHO WILL TRY?`, `CURRENT FUEL:`, `SEE FILES`, etc.).
  - Proximity to decoded rows is useful spatial evidence, not proof of exact control-flow ownership.
  - Do not wire these strings directly into runtime dialog yet; the next useful dialog pass is to model ECL menu/prompt data regions around high-value blocks such as ECL 95, 80, 82, 84, 96, 97, 98, 112, and 113.
- DeepSeek sidecar reviewed the supplied evidence and agreed with the conservative stance. It flagged the nearest-row linkage and `0x8000 + offset` base as assumptions to validate by sample/manual control-flow checks before runtime promotion.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_goldbox_ecl_text_context.py` → 3 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/contextualize_goldbox_ecl_text.py` → 123 still-missing hit contexts, 27 ECL blocks.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_goldbox_ecl_text.py tests/test_goldbox_ecl_text_context.py` → 6 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 146 passed.

### Latest Pass: Ghidra Evidence Comparison / Anchor Integration (2026-06-26)
- Expanded Ghidra decompile exports to all detected functions:
  - START: 358/358 decompiled, 0 timeouts.
  - GAME.OVR raw payload: 623/623 decompiled, 0 timeouts.
- Added `scripts/compare_ghidra_evidence.py`.
- Generated:
  - `generated/ghidra/comparison/ghidra_evidence_comparison.json`
  - `generated/ghidra/comparison/ghidra_evidence_comparison.md`
- Added `docs/ghidra-evidence-comparison-pass-1.md`.
- Moved durable Ghidra project outside the mirrored repo so `rsync --delete` will not remove it:
  - `<local Ghidra project>`
- Verified address mapping for the raw GAME.OVR import:
  - `linear = segment * 16 + offset`
  - `original GAME.OVR file offset = linear + 8`
  - Example: `Load3DMap` original offset `199365` maps to payload linear `199357` / Ghidra `3000:0ABD`.
- Integrated high-value anchor comparisons:
  - `combat_start` offset `65336` / Ghidra `0ff3:0000`: nearest functions `0000:fb92`, `1000:0131`.
  - `shop_menu` offset `117370` / Ghidra `1ca7:0002`: nearest functions `1000:c010`, `1000:ce56`.
  - `item0_loader` offset `126462` / Ghidra `1edf:0006`: nearest functions `1000:eb60`, `1000:eeec`.
  - `load_game` offset `134527` / Ghidra `20d7:0007`: nearest functions `1000:fb92`, `2000:13fd`.
  - `save_game` offset `136472` / Ghidra `2151:0000`: nearest functions `2000:13fd`, `2000:1c53`.
  - `Load3DMap` offset `199365` / Ghidra `3000:0ABD`: nearest functions `3000:006f`, `3000:0c04`.
- Interpretation:
  - Existing custom string extractors remain authoritative for text coverage; Ghidra defined only 13 GAME.OVR strings in raw overlay mode.
  - The comparison report is now the bridge from file offsets/string anchors to Ghidra decompiled candidate functions.
  - Do not promote anonymous Ghidra function names into runtime code; use them as triage targets for manual naming.

### Latest External Prototype Assessment (2026-06-27)
- Imported the separately supplied Matrix Cubed Pygame title/debug handoff as evidence:
  - `docs/external/matrix-cubed-pygame-title-handoff.md`
  - SHA-256: `c46fb644450942edcce79251ca1e4bca3bdef64dd815f945a1ae4be0d8ca349e`
- Imported the DOSBox title reference screenshot from that prototype:
  - `docs/reference_dosbox_title.png`
  - SHA-256: `fbe4b1df88aa7496257efd64b2c4b5e8393619bb3f9022386fae197ba680e651`
- Added `docs/external-pygame-title-prototype-assessment.md`.
- Verdict:
  - The external `matrix_py` package is not further along than this repo as a game reconstruction.
  - This repo remains authoritative because it already has runtime, combat, save/load, ECL/GEO artifacts, item names, wall rendering, Ghidra evidence, and 140 passing tests.
  - The external package is useful as a second track for title-screen and archive-specific image-decoder work.
- Data comparison:
  - Both folders have 27 `.DAX` archives.
  - The current original source folder has one extra config file, `MATRIX.CFG`.
  - No unique original data asset from the external package was found missing from the current source folder.
- Recommended next graphics pass:
  - Generate static `TITLE.DAX` candidate PNGs in this repo using the existing DAX parser.
  - Compare them against `docs/reference_dosbox_title.png`.
  - Use Gold Box Explorer C# image/palette code as a reference for archive-specific decoders.
  - Do not replace the current runtime with the older `matrix_py` shell.

### Latest Pass: Gold Box Explorer ECL Text Comparison (2026-06-27)
- Added `scripts/compare_goldbox_ecl_text.py`, a Python port of Gold Box Explorer's ECL whole-block text scan from `DaxEclFile.cs`.
- Added `tests/test_goldbox_ecl_text.py` for the 6-bit text decoder, `0x80 length` block scan, and readability filter.
- Generated:
  - `generated/ecl_text_goldbox/ecl_text_compare.json`
  - `generated/ecl_text_goldbox/ecl_text_compare.md`
  - `generated/ecl_text_goldbox/goldbox_ecl_texts.tsv`
  - `generated/ecl_text_goldbox/goldbox_ecl_texts_missing_from_current.tsv`
  - `generated/ecl_text_goldbox/goldbox_ecl_texts_still_missing_after_substring.tsv`
- Added `docs/ecl-text-goldbox-comparison-pass-1.md`.
- Results:
  - Gold Box whole-block text hits: 3662.
  - Gold Box unique texts: 3127.
  - Current ECL listing unique texts: 1244.
  - Current event-atlas unique texts: 696.
  - Exact overlap with current outputs: 1100.
  - Exact-missing unique texts: 2027.
  - Exact-or-substring overlap with current outputs: 3052.
  - Still missing after substring comparison: 75.
- Interpretation:
  - The existing operand string decoder is compatible with Gold Box Explorer's 6-bit text decoding.
  - Most exact-missing strings are represented as substrings of larger current event text.
  - The 75 still-missing strings are mostly menu labels, player choices, continuation fragments, resource labels, and a few likely false positives.
  - Do not promote whole-block hits directly into runtime dialog; attach them to decoded instructions/menus/branch targets first.

### Previous Pass: Ghidra Deep START/GAME.OVR Pass (2026-06-26)
- Added `scripts/ghidra/DumpDeepProgramSummary.java` to export Ghidra program summaries, function tables, defined strings, decompile summaries, and bounded decompiler output.
- Ran local Ghidra 12.1.2 headless with the installed 16-bit real-mode language id `x86:LE:16:Real Mode` and compiler spec `default`. Ghidra reports imports as `x86:LE:16:Real Mode:default`.
- Imported `generated/reverse_engineering/imported/start/START.unpacked.exe` with the `Old-style DOS Executable (MZ)` loader:
  - Ghidra MD5: `342095ccae84adc876f86dfce5e35ffe`
  - 52 executable `CODE_*` blocks plus `HEADER`
  - 358 functions
  - 243 defined strings
  - 358 decompiled functions exported, 0 timeouts
  - Output: `generated/ghidra/deep_start_unpacked/`
- Imported `generated/reverse_engineering/imported/game_ovr/game_ovr_reverse_engineering/GAME.OVR.payload_after_fbov_header.bin` with the raw `BinaryLoader`:
  - Ghidra MD5: `1a6f200edd4745797e47c98d53aa81de`
  - One initialized executable/writable `ram` block from `0000:0000` to `3000:3e28`
  - 623 candidate functions
  - 13 Ghidra-defined strings
  - 623 decompiled functions exported, 0 timeouts
  - Output: `generated/ghidra/deep_game_ovr_payload/`
- Added `docs/ghidra-deep-pass-1.md`.
- Ghidra project path: `<local Ghidra project>`.
- Interpretation:
  - The START unpacked pass gives a useful segmented function map and startup call chain.
  - The GAME.OVR raw pass is useful for rough function discovery but still lacks overlay manager segment/relocation context; do not treat anonymous C-like snippets as source-equivalent.
  - Next step is to name Ghidra functions around known anchors (`GAME.OVR`, `Load3DMap`, save/load, shop, combat, item tables) and cross-check against existing generated evidence before runtime changes.

### Previous Pass: START/GAME.OVR Reverse-Engineering Package Import (2026-06-26)
- Added `scripts/review_reverse_engineering_packages.py` to reproducibly import externally supplied START.EXE and GAME.OVR reverse-engineering ZIPs, hash them, safely extract them, compare them against local originals, and emit `generated/reverse_engineering/package_review.json` plus `.md`.
- Added `docs/reverse-engineering-package-import-pass-1.md`.
- Generated/staged package files under `generated/reverse_engineering/imported/`.
- Verified:
  - START package ZIP SHA-256: `6772a1989d76e8fa706cd997f3d4cc0c55e3a7c3180fea43b91b83708245b404`.
  - GAME.OVR package ZIP SHA-256: `c6cac25cf56e52892ce68dcb44361fbd4a853fab87fbf1c5b9eb017449b9d87d`.
  - Local `START.EXE` hash remains `20d039d341c9d0851fe935d4eeb4de07e255e71aeb555cdb779d2ecf7e680597`.
  - Supplied `START.unpacked.exe` is a valid MZ executable: SHA-256 `2694f750e7f5e43745ad8b8ca84aa6dd205e6a87d9be815082e77e4b86c44840`, entry `0000:002F`, stack `18A1:4000`, 708 relocations, 75344-byte load image.
  - Local `START.EXE` contains `Packed file is corrupt`; the supplied unpacked START artifact contains the Borland copyright string.
  - Local `GAME.OVR` hash remains `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`.
  - Local `GAME.OVR` starts with `FBOV`; dword at offset 4 declares a 212521-byte payload.
  - Supplied `GAME.OVR.payload_after_fbov_header.bin` exactly matches local `GAME.OVR[8:]`.
- Interpretation:
  - The GAME.OVR package is confirmed as a byte-identical derived view of the local overlay plus raw disassembly/search aids.
  - The START unpacked EXE is valuable external evidence but should not replace the local original until the unpacking method is reproduced locally.
  - Next decompiler work should combine `START.unpacked.exe` and `GAME.OVR` in an overlay-aware Ghidra/IDA/Reko-style pass before promoting pseudocode into runtime behavior.

### Previous Pass: ITEMS Side-File Detail Alignment (2026-06-25)
- Extended `scripts/analyze_item_name_mapping.py` to attach the local 351-byte `ITEMS` side file to decoded ITEM0 names as a 39-record, 9-byte detail table indexed by ITEM0 `itemptr`.
- Evidence recorded:
  - `ITEMS` is still not a text/name table: 0 ASCII strings and 0 Pascal-style name candidates.
  - All 91 ITEM0 records have a matching `ITEMS` detail row through their 1-based `itemptr`; missing detail rows: 0.
  - GAME.OVR runtime references use `itemptr * 9` against the 0x5370 table area and read bytes at 0x5370, 0x5372, 0x5373, 0x5374, 0x5375, and 0x5376 plus that product.
  - Candidate field labels are recorded only as candidates: `type_code`, large/medium damage-like triples, effect/bonus-like byte, range-like byte, and flags-like byte.
- Runtime change:
  - `ItemCatalog` now carries `items_detail_record` and `detail_evidence` on `ItemTemplate` for inspection.
  - Candidate `ITEMS` damage/range bytes are **not** promoted into gameplay stats yet; `damage_string()` still uses the existing generated item template fields until original combat/shop validation confirms the display behavior.
- Generated:
  - Updated `generated/game_ovr/item_name_mapping.json`
  - Updated `generated/game_ovr/item_name_mapping.md`
  - Updated `generated/game_ovr/item_name_mapping_records.tsv`
  - Updated `generated/game_ovr/item0_names.tsv`
  - Added `generated/game_ovr/items_detail_records.tsv`
- DeepSeek sidecar reviewed the supplied evidence and agreed with the conservative stance. It also flagged byte 7/8 and damage/range meanings as unsupported until validation; local artifacts keep those names as candidates only.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/analyze_item_name_mapping.py` → wrote item-name/detail mapping artifacts.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_item_name_mapping.py tests/test_inventory.py` → 23 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 140 passed.

### Previous Pass: ITEM0 / START.EXE Item Name Mapping (2026-06-25)
- Reworked `scripts/analyze_item_name_mapping.py` from a blocker report into a reproducible decoder. It now extracts the contiguous START.EXE Pascal-style item-name literal table from `Knife` through `BLANK ITEM`, assigns code 0 to blank, and decodes ITEM0 bytes `[3,2,1]` as the three name-code fields.
- Evidence recorded:
  - `START.EXE` item-name code table has 46 entries including blank code 0; max extracted code is 45.
  - `ITEM0.DAX` has 91 16-byte records. The first four bytes match the Gold Box / FRUA item-record pattern: item pointer, name code 3, name code 2, name code 1.
  - All 91 ITEM0 records now decode to names with 0 unmapped name codes.
  - Examples: item 0 `Knife`, item 1 `Mono Knife`, item 5 `Needle Gun`, item 21 `Heavy Body Armor`, item 31 `mini Explosive Grenade`.
  - `ITEMS` remains 351 bytes / 39 records of 9 bytes with no printable names; it is not the name table.
- Runtime change:
  - `ItemCatalog` loads `generated/game_ovr/item_name_mapping.json` when present and attaches `itemptr`, `name_codes`, `name`, and `name_evidence` to `ItemTemplate`.
  - `matrix_cubed.tools.shop.item_name()` now displays evidence-backed names and falls back to `Item N` if the generated mapping is absent.
  - Shop sell mode resolves both decoded labels and old `Item N` labels back to catalog indices for pricing.
- Generated:
  - `generated/game_ovr/item_name_mapping.json`
  - `generated/game_ovr/item_name_mapping.md`
  - `generated/game_ovr/item_name_mapping_records.tsv`
  - `generated/game_ovr/item0_names.tsv`
- DeepSeek sidecar reviewed the supplied evidence and agreed with the main START.EXE/ITEM0 mapping. It misread code 0 in one advisory risk note; local extractor/tests verify code 0 is blank and code 1 starts at `Knife`.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/analyze_item_name_mapping.py` → wrote item-name mapping artifacts.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_item_name_mapping.py tests/test_inventory.py` → 21 passed at the time of that pass.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 138 passed at the time of that pass.

### Previous Pass: GAME.OVR Raw GEO Map Scan (2026-06-24)
- Added `scripts/scan_game_ovr_maps.py`, a reproducible evidence script for map expansion. It compares `GAME.OVR` against known decoded `GEO1.DAX` blocks, scans raw 1026-byte windows using GEO1-derived header/door/event/wall-continuity filters, and records loader/string anchors.
- Added `tests/test_game_ovr_map_scan.py` for scanner scoring, false-positive rejection, and exact embedded-block detection.
- Generated `generated/game_ovr/map_scan.json` and `generated/game_ovr/map_scan.md`.
- Evidence recorded:
  - `GAME.OVR`: 212,529 bytes, SHA-256 `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`.
  - Local GEO/ECL DAX inventory now confirmed in the artifact: `GEO1.DAX` only for GEO and `ECL1.DAX` only for ECL. No `GEO2.DAX`, `GEO3.DAX`, `GEO4.DAX`, `ECL2.DAX`, `ECL3.DAX`, or `ECL4.DAX` are present in the current source folder.
  - Known `GEO1.DAX`: 25 decoded blocks, all 1026 bytes.
  - Exact decoded GEO1 blocks found inside `GAME.OVR`: 0/25.
  - Raw 1026-byte windows with known GEO1 header bytes inside `GAME.OVR`: 2, at `0x0DA9A` and `0x2C3B7`; both rejected by door/event/wall-continuity filters.
  - Accepted raw GEO candidates in `GAME.OVR`: 0.
  - Loader/string anchors remain useful: `WALLDEF` around `0x308BD`/`0x308E0`, `GEO` around `0x30AA6`, and `Load3DMap` around `0x30AC5`.
- Interpretation: this is negative evidence only. It does not prove the missing maps are impossible to recover; it shows they are not present as plain contiguous GEO1-layout blocks in this `GAME.OVR`. Next map work should trace the `Load3DMap` loader or obtain missing original numbered GEO/ECL files if they exist.
- DeepSeek sidecar reviewed the supplied evidence and agreed the supported next validations are source completeness, rechecking decoded GEO1 integrity, and tracing/inspecting the `Load3DMap` area. Treat that as advisory; the facts above are locally verified.
- Commands run:
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q tests/test_game_ovr_map_scan.py` → 3 passed.
  - `source .venv/bin/activate && PYTHONPATH=src python3 scripts/scan_game_ovr_maps.py` → wrote map scan artifacts; accepted raw GEO candidates: 0.
  - `source .venv/bin/activate && PYTHONPATH=src python3 -m pytest -q` → 131 passed.

### Review Notes From Last Pass
- ✅ Save/load direction is good: `load_game_state()` reads SAVGAMA.DAT and character files, and Continue now looks in autosave before timestamped saves.
- ✅ Shop sell is playable.
- ⚠️ Corrected: the shop had invented item names. It now displays names decoded from ITEM0 name-code triples and the START.EXE item-name literal table.
- ⚠️ Corrected: `GameState.add_credits()` mutated frozen `CharacterRecord` instances directly. Credits now update via `dataclasses.replace()` and keep roster/active party/legacy PartyState in sync.
- ⚠️ Corrected: Continue now applies loaded SAVGAMA credits through `set_credits()` after loading characters, so the UI does not fall back to stale per-character credits.
- ⚠️ Corrected: `GAME.OVR` is available locally at `$MATRIX_CUBED_GAME_DIR/GAME.OVR`; the earlier "no binary" note was stale.

---

## 2. Current Architecture

```
src/matrix_cubed/
├── engine/
│   ├── runtime.py          # GameState: movement, events, combat queuing, party, map transitions
│   ├── combat.py           # QueuedCombat: frozen dataclass from decoded ECL events
│   ├── combat_loop.py      # CombatLoop: THAC0-based turn resolution, MonsterDB integration
│   ├── events.py           # EventCommand/Execution: compiles decoded ECL → command list
│   ├── map_engine.py       # MapEngine: tile maps, wall collision, overhead view, visible cells
│   ├── character.py        # CharacterRecord (frozen), CharacterRoster, Party, Career/Race enums
│   ├── inventory.py        # ItemCatalog (91 named items), Equipment, Inventory container
│   ├── monster_db.py       # MonsterDB: loads 63 decoded monsters, derives combat stats
│   ├── level_up.py         # XP thresholds, level-up (HP gains, stat boosts), frozen-safe updates
│   ├── wall_set_db.py      # Per-map wall set lookup (19/25 resolved)
│   └── save_load.py        # Binary .WHO/.STF/SAVGAMA.DAT write+read roundtrip
│
├── tools/
│   ├── pygame_runner.py    # Desktop frontend: main menu → character creation → exploration → combat
│   ├── wall_renderer.py    # First-person raycasting: 1650 wall textures, depth projection, clipping
│   ├── shop.py             # Buy/sell UI: 91-item catalog, credits, decoded item labels
│   ├── overlays.py         # Inventory overlay (string/int list), character sheet overlay
│   └── character_creation.py # Name entry, race/career/stats point-buy (14 pts, 3-18 range)
│
tools/
└── validate_combat.py      # Combat validation against original DOS data
│
├── formats/
│   ├── save.py             # 259-byte .WHO parser, CharacterWhoRecord
│   ├── stf.py              # 124-byte .STF skill record parser
│   ├── game_state.py       # 2901-byte SAVGAMA.DAT parser
│   └── geo.py              # GeoCell, GeoMap dataclasses
│
└── data/
    └── repository.py       # ReconstructedData: loads decoded assets from generated/

tests/
├── test_map_engine.py      # 38 tests: tile movement, collision, overhead view
├── test_combat_loop.py     # 10 tests: combat lifecycle, THAC0
├── test_combat_deterministic.py  # 4 tests: termination, victory, defeat
├── test_character.py       # 16 tests: records, roster, party, stat helpers
├── test_inventory.py       # 15 tests: ItemCatalog, Equipment, Inventory, shop label/helper evidence
├── test_runtime_party.py   # 6 tests: multi-character GameState integration and credit sync
├── test_save_load.py       # 9 tests: binary roundtrip, file creation
├── test_save_formats.py    # Format parser tests
├── test_stf.py             # STF format tests
├── test_game_state.py      # SAVGAMA.DAT tests
├── test_item_name_mapping.py # 8 tests: ITEMS/ITEM0 name/detail mapping evidence
├── test_monster_db.py      # 9 tests: monster lookup, stat derivation
├── test_level_up.py        # 8 tests: XP thresholds, level-up, HP gains
├── test_wall_renderer.py   # 5 tests: texture loading, rendering
└── test_runtime_probe.py   # Runtime probe tests

generated/
├── dax_blocks.json         # 611 decoded DAX blocks across 26 files
├── original_files/          # Structural JSON for every original file; 27 DAX containers, 611 block hashes/string candidates/layout hints
├── data_model/              # Monsters (63), Items (91), Effects (118)
├── game_ovr/                # Full GAME.OVR string/header/ITEMS analysis, map scan, ITEM0 name artifacts
├── ecl1_blocks/             # 33 decoded ECL blocks
├── ecl1_disasm/             # 33 ECL disassemblies
├── encounters/              # 184 encounter→monster cross-references
├── event_atlas/             # All events cross-referenced
├── geo1/                    # 25 decoded GEO maps
├── viewer/                  # Web prototype (1.4 MB runtime HTML + 914 KB map viewer)
├── wall_textures/           # 1650 decoded wall texture PNGs (11 sets × 15 walls × 10 views)
└── liveplay/                # DOSBox-captured save files, screenshots
```

---

## 3. End Goal

A **playable, complete reconstruction** that can be:

1. **Run as a Python desktop app** (current — Pygame runner)
2. **Packaged as a standalone EXE** (via PyInstaller/Nuitka)
3. **Served as a web app** (HTML/JS — the 1.4 MB prototype exists)

The game should be playable from start to finish: character creation → exploration → combat → level-up → story progression through all 25+ maps.

---

## 4. Current State (What Works)

### Functional
- ✅ Main menu (New Game / Continue / Quit)
- ✅ Character creation (name, race, career, stat point-buy)
- ✅ WASD/Q/E exploration on 16×16 tile maps
- ✅ Overhead minimap with player/facing indicators
- ✅ Event trigger (walk on event tiles → decoded ECL text)
- ✅ THAC0 combat (d20 rolls, STR modifiers, MonsterDB stat lookup)
- ✅ Multi-monster combat (all alive monsters attack)
- ✅ Multi-party damage rotation (damage distributes across members)
- ✅ Post-combat rewards (XP, credits, auto-level-up)
- ✅ Map transitions (TILE_EXIT cells load new GEO via transition_to)
- ✅ First-person wall rendering (1650 textures, depth projection, clipping)
- ✅ Per-map wall set lookup/rendering for 19/25 GEO1 maps
- ✅ Save/Load to binary .WHO/.STF/SAVGAMA.DAT (F5 / Ctrl+S, autosave, Continue)
- ✅ Inventory (I), Character (C), Shop (O) overlays
- ✅ Shop buy/sell mode
- ✅ 91-item catalog with decoded START.EXE/ITEM0 labels and damage display
- ✅ GAME.OVR full string/header analysis (`generated/game_ovr/`)
- ✅ Original file structural decode (`generated/original_files/`): 43 original files inventoried, 27 DAX containers expanded, 611 DAX blocks validated against `generated/dax_blocks.json`, zero decompression warnings
- ✅ 63-monster database with stat derivation
- ✅ 259-byte .WHO roundtrip (write → read → verify)
- ✅ 124-byte .STF roundtrip
- ✅ XP/level-up with career-specific HP gains (Rocket Jock +8, Medic +6)

### Not Yet Working
- 🔶 25 maps loaded from `GEO1.DAX`; Gold Box Explorer's Matrix Cubed map table has no named maps missing locally, but GEO 21 remains unnamed and full world/ship traversal still needs validation
- ❌ GAME.OVR not fully decoded (997 strings; map lookup and several runtime tables still unresolved)
- ⚠️ Item names are decoded from ITEM0 + START.EXE, and `ITEMS` is aligned as a 1-based 9-byte `itemptr` detail table; exact damage/range/effect semantics remain candidate labels pending original combat validation
- 🔶 Dialog system (multi-step branching NPC conversations): 14 compact conversation rows are compiled for runtime/capture validation, but all current rows are attachment-near-branch confidence and still need DOS/OCR or decoded-menu proof before final story logic promotion
- ❌ Ship/vehicle mode (overworld travel between maps)
- ❌ Sound/music (XMI files exist, not decoded for Pygame)
- ❌ Many DAX/image/audio blocks have structural JSON only; semantic parsers still need per-format follow-up
- ❌ Web build unpolished (the 1.4 MB prototype works but isn't productionized)
- ❌ EXE packaging not done
- 🔶 Combat queue validation is tied to local DOS capture/save evidence for Caloris event 7; original turn-by-turn combat mechanics still need OCR/save-byte validation

---

## 5. Planned Steps (Priority Order)

| Priority | Step | Est. Passes | Description | Status |
|----------|------|-------------|-------------|--------|
| 1 | 🎨 Wall set per map | 1 | Wire wall_set_id from GEO data into WallRenderer | ✅ Done |
| 2 | 🐛 HP/credits sync | 1 | Fix initial credits/HP sync on add_character() | ✅ Done |
| 3 | 📛 Item names from START.EXE/ITEM0 | 2 | Match `namenum(1..3)` item fields to their source table | ✅ Done |
| 3b | 📦 ITEMS detail alignment | 1 | Trace 9-byte `ITEMS` side-file alignment by ITEM0 `itemptr` without promoting candidate stats | ✅ Done |
| 4 | 🗺️ Extract remaining maps | 5 | GEO2-4 decoding from missing source files or GAME.OVR loader trace | 🔶 Gold Box Explorer audit suggests no named Matrix Cubed maps missing from local GEO1; validate traversal next |
| 5 | 🎯 Combat validation | 3 | Play through events vs original game | 🔶 Caloris event-7 queue validated; original turn-by-turn mechanics still open |
| 6 | 🏪 Shop sell | 1 | Wire item drops + sell from combat rewards | ✅ Done |
| 7 | 📊 Load from SAVGAMA.DAT | 1 | Restore full state from .DAT on Continue | ✅ Done |
| 8 | 🎬 Dialog system | 3 | Branching NPC conversations with choices | 🔶 Conversation compiler built; branch ownership/effects still need validation |
| 9 | 🚀 EXE packaging | 2 | PyInstaller → standalone .exe | ❌ |
| 10 | 🌐 Web polish | 3 | Embed Pyodide or serve via static site | ❌ |

---

## 6. Key Design Decisions

### Why THAC0 instead of always-hit?
Phase A used always-hit for simplicity. Phase B upgraded to d20 THAC0 for authenticity. The Gold Box standard: `hit_needed = THAC0 - target_AC`, nat20 always hits, no nat1 auto-miss (yet).

### Why MonsterDB derives stats from ability scores instead of direct binary?
The MON0CHA.DAX 259-byte records match the .WHO format. HP/AC/damage offsets are labeled "candidates" — not confirmed. Deriving from ability scores is correct for demo/validation and can be replaced when the real offsets are confirmed.

### Why dual-store for party state (PartyState + active_party)?
Legacy `PartyState` (simple HP/credits/inventory/flags) existed first. `active_party` (CharacterRoster/Party) was added for multi-character support. Both are kept in sync via `apply_damage()`, `set_credits()`, `add_credits()`, and `current_hp()` methods. Because `CharacterRecord` is frozen, credit updates must replace the active character record and roster entry instead of mutating fields. Migration to active_party-only should happen when multi-character is fully working.

### Why template-based save format?
SAVGAMA.DAT has 2901 bytes with many unknown fields. Writing only the decoded fields (map_id, position, facing, credits) and preserving everything else from a template avoids corrupting unknown data. The downside: without a valid template, the save file is mostly zeros.

### Why frozen dataclasses for CharacterRecord/ItemTemplate?
Immutability prevents accidental mutation. Level-up creates new instances via `dataclasses.replace()` or manual dict construction.

---

## 7. Known Issues & Gotchas

0. **Cowork sandbox Java setup — SOLVED (2026-07-07)**: a Claude Cowork
   session only has OpenJDK 11 *JRE* preinstalled (no `javac`, project needs
   17+) and no root/sudo, so `apt-get install`/`apt-get update` both fail with
   permission errors, and `repo.maven.apache.org` is blocked by the sandbox's
   network allowlist. Full working recipe, no admin/network-policy change
   needed, just three folder shares from James (`request_cowork_directory`):
   1. Share `<local Maven cache>` — James's real machine already has a
      populated Maven local repo. Run Maven with
      `-Dmaven.repo.local=<mounted path>/repository -o` and all plugin/
      dependency resolution works fully offline.
   2. Share `/usr/lib/jvm` — James's host has a real `java-21-openjdk-amd64`
      (Ubuntu build, `javac` included) at
      `/usr/lib/jvm/java-21-openjdk-amd64`. **It cannot be executed directly**
      from the Cowork bash sandbox: `GLIBC_2.38' not found` (the sandbox's
      glibc is older than the host's). Two different sandboxes, same
      physical machine — file tools reach any shared host path, but the bash
      tool is a separate isolated environment with its own userland.
   3. Separately, `pip3 install --break-system-packages --user
      "jdk4py==21.0.8.2"` (PyPI is allowlisted) gives a `java` launcher that
      *does* run in the sandbox (built for an older/compatible glibc) — but
      it's a `jlink`-trimmed JRE with `jdk.compiler` deliberately excluded, so
      it has no `javac` of its own.
   - **The fix**: `jdk.compiler`/`jdk.internal.opt`/`java.compiler` are just
     bytecode (`.jmod` = 4-byte magic header + a zip archive of `classes/`) —
     they don't need the host's glibc, only a JVM to run in. Extract those
     three `.jmod` files from the mounted `/usr/lib/jvm/java-21-openjdk-amd64/jmods/`
     with Python's `zipfile` (skip the 4-byte header), then run
     `com.sun.tools.javac.Main` on that combined classpath using the
     glibc-compatible `jdk4py` `java`:
     ```
     JAVA4PY=<jdk4py java-runtime dir>
     CP=/tmp/jdk_compiler_extracted/classes:/tmp/jdk.internal.opt_extracted/classes:/tmp/java.compiler_extracted/classes
     $JAVA4PY/bin/java -cp "$CP" com.sun.tools.javac.Main Hello.java -d out   # works standalone
     ```
   - For Maven specifically, wrap that into a fake `javac` shell script
     (`exec "$JAVA4PY/bin/java" -cp "$CP" com.sun.tools.javac.Main "$@"`),
     symlink `java` next to it, put that dir first on `PATH` as `JAVA_HOME`,
     and force forked compilation so Maven shells out to the wrapper instead
     of using its own in-process compiler API:
     `mvn -Dmaven.repo.local=<m2>/repository -Dmaven.compiler.fork=true -Dmaven.compiler.executable=<wrapper>/bin/javac -o test`.
   - Verified end to end: this actually compiled the full `ssi-engine` module
     and ran the real JUnit suite via Maven/Surefire — `Tests run: 57,
     Failures: 0, Errors: 7, Skipped: 12`. Of the 7 errors, 2
     (`OriginalItemCombatTableTest`) are the exact same class of problem
     fixed for Python earlier today: a hardcoded
     `$MATRIX_CUBED_GAME_DIR/ITEMS`
     path that doesn't exist verbatim in the sandbox — Java scripts/tests
     never got the `MATRIX_CUBED_GAME_DIR`-style treatment `scripts/game_paths.py`
     gave the Python side; that's a reasonable follow-up task. The other 5
     (`NullPointerException` in `io.vavr.collection.Array.of`, in
     `BuckRogersMonsterInventoryBlockTest`/`RecoveredItemOptionSelectorTest`)
     are **not yet root-caused** — could be a real bug, or could be an
     artifact of this improvised classpath/dependency setup (e.g. a vavr
     version mismatch between what's cached in the mounted `.m2` vs what the
     `pom.xml` expects). Don't treat those 5 as confirmed bugs without
     re-running on a normal (non-workaround) JDK/Maven setup first.
   - This setup is entirely session-scoped (nothing here persists to a fresh
     Cowork sandbox) but takes under 5 minutes to redo from this recipe.
   - Separately, the Cowork bash sandbox can create/overwrite files in a
     mounted project folder but cannot delete pre-existing files from it
     (`os.remove`/`os.unlink` return `PermissionError: Operation not
     permitted`, confirmed both via Python and `rm`) — this is what actually
     caused the two `test_source_recovery_corpus.py` failures during the
     2026-07-07 portability pass, not a missing Ghidra corpus (the corpus is
     fully present in `generated/ghidra/`; the script just does
     `shutil.rmtree()` on an existing `generated/source_recovery/*` output dir
     before rewriting it, which this sandbox's mount refuses).
   - DOSBox/DOSBox-X ARE present on James's host (`/usr/bin/dosbox`,
     `/usr/bin/dosbox-x`) and were reachable once James shared `/usr/bin` and
     `/usr/lib/x86_64-linux-gnu`, but they cannot run in the Cowork sandbox,
     and — unlike the `javac` case above — there is no workaround. Diagnosis:
     `dosbox-x --version` first failed on missing shared libraries
     (`libSDL2_net`, `libSDL_sound`, `libfluidsynth`, `libslirp`,
     `libinstpatch`, `libpipewire`, etc. — 13 total, traced via `readelf -d`
     NEEDED entries, recursively, then sourced from the mounted host lib dir
     into an isolated `/tmp` directory added to `LD_LIBRARY_PATH`, carefully
     *not* including host copies of `libc.so.6`/`ld-linux` so the sandbox's
     own compatible loader stays in charge). Once those were supplied, the
     real blocker surfaced: `dosbox-x`, `libpipewire`, `libc.so.6`, and
     `libstdc++.so.6` all require `GLIBC_2.38`/`GLIBCXX_3.4.32`, but this
     sandbox only has glibc 2.35 (Ubuntu 22.04; the host is a newer build,
     matching the same newer-glibc pattern seen with the host JDK). This is
     fundamentally different from the `javac` fix: the JDK compiler is mostly
     portable bytecode that could be lifted out and run on a
     glibc-compatible JVM; DOSBox-X is native C/C++ calling glibc symbols
     directly, so there is no equivalent extraction trick, and overriding
     `LD_LIBRARY_PATH` with the host's full lib directory (to get a newer
     libc) breaks the sandbox's own basic tools (confirmed: `head` failed
     with a `GLIBC_PRIVATE` symbol error). **Conclusion: original-DOS-capture
     validation cannot run inside a Claude Cowork sandbox as currently
     provisioned, regardless of what folders are shared.** That work needs an
     agent with real host execution (see `TOOLS.md`: GoldenBox runs natively
     on James's machine via `openclaw`) or a statically-linked / matching-glibc
     DOSBox-X build. Headless Java/Swing/AWT capture via `Xvfb`/`xvfb-run`
     (both present in the sandbox) is unaffected by this and still works.
   - Found (not yet reviewed) a real license file for the local COAB checkout
     at `<local COAB checkout>/Installer/CotAB License.rtf` — prior
     passes stated COAB "has no root license file" and treated it as
     unlicensed; that claim should be revisited against this file before
     leaning further on James's 2026-07-07 "reuse now, resolve licensing
     later" direction.

1. **Pygame init**: Tests that use Pygame (wall_renderer, runner) must run via the venv (`source .venv/bin/activate`). System Python doesn't have Pygame. `pytest` is installed globally but `PYTHONPATH=src` must be set.

2. **WallRenderer startup**: The WallRenderer loads 1650 textures via PIL on init, which takes ~1.5 seconds. Consider lazy loading or caching.

3. **MonsterDB CWD**: MonsterDB reads from `generated/data_model/mon0cha_monsters.json` relative to CWD. Must be run from `matrix-cubed-re/`.

4. **Encounter data**: The ECL events produce QueuedCombat with `monster_names` but the full `encounters` field (with copies/stats) is available but not fully utilized. CombatLoop.enter() prefers encounters data when available.

5. **Qwen wrapper**: `qwen-ollama-agent.sh` has a `--DIRECT` mode for code generation but was removed from the workflow. The hardening changes (no fixed seed, 32K tokens, looser guard) are still in place if needed.

6. **GAME.OVR / item names**: The original game binary is available outside the repo at `$MATRIX_CUBED_GAME_DIR/GAME.OVR` (SHA-256 `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`). `scripts/analyze_game_ovr.py` writes `generated/game_ovr/` with 1007 ASCII strings, 724 Pascal-style candidates, key anchors, and the separate 351-byte `ITEMS` file decoded as 39 9-byte records. Real item names are now resolved by `scripts/analyze_item_name_mapping.py` using ITEM0 name-code bytes and the START.EXE literal table. `ITEMS` is now aligned as a 1-based `itemptr` detail table and attached to `ItemTemplate` as raw evidence; damage/range/effect byte semantics remain candidate-only until combat validation.

7. **Original file structural decode**: `scripts/decode_original_files.py` writes `generated/original_files/` with per-file JSON for all 43 original files in `$MATRIX_CUBED_GAME_DIR`. It expands all 611 DAX blocks and records block IDs, offsets, packed/raw sizes, decoded SHA-256 hashes, head/tail hex, ASCII/Pascal candidates, byte histograms, and record-size hints. This is structural evidence, not proof of semantic field names; use `generated/original_files/undecoded_files.json` to pick the next per-format parser target.

8. **Map expansion evidence**: `scripts/scan_game_ovr_maps.py` writes `generated/game_ovr/map_scan.json` and `.md`. Current result: no exact decoded GEO1 block copies in `GAME.OVR`, no accepted raw 1026-byte GEO-shaped overlay windows, and only two rejected header hits. Do not claim GEO2-4 are embedded plainly in `GAME.OVR`; trace `Load3DMap` near `0x30AC5` or obtain missing numbered GEO/ECL source files.

9. **ECL text context evidence**: `scripts/contextualize_goldbox_ecl_text.py` writes `generated/ecl_text_goldbox/goldbox_ecl_text_context.{json,tsv,md}`. It maps Gold Box whole-block text hits that are still absent after substring comparison to `0x8000 + offset` VM-style addresses and nearest decoded ECL rows. Current result: 123 hit-level contexts across 27 ECL blocks, mostly short choice/label fragments. Treat nearest-row linkage as heuristic until a data-flow/control-flow pass confirms ownership.

10. **ssi-engine external reference**: `references/ssi-engine/` is a local clone of `https://gitlab.com/farmboy0/ssi-engine` at commit `f10f96f277dbe27f75a39d87de8c4cc0f662155f`. Local Maven 3.9.9 is installed at `.tools/apache-maven-3.9.9/`; `mvn clean package` succeeds under Java 21. The upstream jar contains Matrix Cubed resources but its jar-mode config discovery assumes a directory classpath, so launch it from `target/classes` instead: `java -cp 'target/classes:target/*' main.Goldbox '$MATRIX_CUBED_GAME_DIR' --no-title`. Xvfb validation opened a `Buck Rogers - Matrix Cubed` Swing window and detected the original `TITLE.DAX` MD5 `f8881eac363f723ea44109bb6117fa26`.

11. **ssi-engine acceleration path**: `scripts/run_ssi_engine_reference.sh` is the repo-local launcher for the Java reference engine. `docs/ssi-engine-reference-acceleration-plan.md` records what can be used immediately: runtime comparison, DAX/GEO/WALLDEF/ECL reference behavior, Matrix Cubed address names, renderer parity, combat state checks, and space/ship recovery. Boundary: `ssi-engine` is GPL-3.0, so direct Python ports of substantial Java code need attribution/license handling; prefer evidence-driven reimplementation through tests unless the project intentionally adopts compatible terms.

---

## 8. How to Run

```bash
cd matrix-cubed-re
source .venv/bin/activate
PYTHONPATH=src python3 src/matrix_cubed/tools/pygame_runner.py
```

### Controls
- WASD: Move forward/back/strafe left/right
- Q/E: Turn left/right
- SPACE: Advance event text / combat turn
- I: Toggle inventory overlay
- C: Toggle character sheet overlay
- O: Open shop (buy/sell)
- F5 / Ctrl+S: Save game to `saves/save_YYYYMMDD_HHMMSS/` and `saves/autosave/`
- ESC: Quit

### Run tests
```bash
source .venv/bin/activate
PYTHONPATH=src python3 -m pytest -q
```

---

## 9. Web Version

A self-contained HTML runtime prototype exists at:
`generated/viewer/matrix_cubed_runtime_prototype.html` (1.4 MB)

Open directly in a browser via `file://` URL — no server needed.

Also available: `generated/viewer/matrix_cubed_map_viewer.html` (914 KB)

---

## 10. File Sizes & Stats

| Category | Files | Lines |
|----------|-------|-------|
| Engine source | 10 | 1,751 |
| Tools/frontend | 6 | 1,092 |
| Format parsers | 6 | 453 |
| Tests | 15 | 1,360 |
| Standalone tools | 1 | 110 |
| **Total** | **38** | **4,910** |
| Generated assets | 1,650+ | (PNGs, JSON) |

---

*End of handoff. Next agent should read this file first, then continue from the planned steps list (Section 5).*
