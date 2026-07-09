# Night Work Order — Combat Slice 2 (AI planner) + review/refactor

Prepared by Claude Code (Fable) 2026-07-08 for an unattended overnight run.
Self-contained: an agent starting cold should be able to execute from this file
plus HANDOFF.md. Recommended model for the whole run: **Opus** (one model, must
end in a green build). Work in the LOCAL fork; do not rely on any remote.

## Environment / preconditions
- Repo: `<project root>`, nested Java fork at
  `references/ssi-engine`, branch `matrix-cubed-fork` (local only — never push).
- Build/test: `cd references/ssi-engine && <project root>/.tools/apache-maven-3.9.9/bin/mvn test`
- Harness: `references/ssi-engine/scripts/run-combat-scene.sh` (needs local
  MATRIX game dir; must end `Final COMBAT_RESULT=0`).
- Baseline at start: **284 tests, 0 failures, 7 pre-existing skips**.
- Read first: `HANDOFF.md` (top section) and `docs/coab-combat-port-map.md`.
- Rules: `../../CLAUDE.md` + `../../COLLABORATION.md` (claim work; commit
  checkpoints before/after; never fabricate Matrix values — unknown → neutral/
  candidate, labeled; keep Matrix specifics behind the universal engine boundary).

## Phase 1 — Review & refactor (no behavior change)
Scope: the freshly-wired attack path and the COAB-ported combat packages.
- `engine/combat/CombatState.java` (attack() routing), `attack/CombatantAttackerView.java`,
  `attack/CombatantDefenderView.java`, and the `engine/combat/attack|map|ai|loot`,
  `engine/party`, `engine/time` packages.
Do:
- Tighten duplication, naming, and javadoc consistency; ensure every ported
  member still cites its COAB source (spec: `docs/coab-provenance-audit-2026-07-08.md`).
- Verify the neutral/candidate field mappings in the adapters are still honest
  (no silently-fabricated stats crept in) and the B=20 hit-scale bridge stays
  outcome-invariant.
- DO NOT change validated behavior. After refactor: full `mvn test` green and
  `run-combat-scene.sh` = COMBAT_RESULT=0. Commit as a "refactor:" checkpoint.
Constraint: if a "cleanup" would change any test's expected values, STOP and
leave it — that's behavior, not refactor.

## Phase 2 — Update handoff & steps-to-completion
- Update `HANDOFF.md` top section and `docs/coab-combat-port-map.md` port-order
  status (slice 1 attack = wired; mark slice 2 progress).
- Move COLLABORATION.md rows appropriately. Keep numbers accurate (re-run tests
  for the count).

## Phase 3 — Slice 2: wire QuickFightPlanner AI
Goal: monster/auto turns run the ported COAB AI instead of the `RecoveredEnemyTactics`
scaffold. Mirror slice 1's adapter+guardrail pattern.
- Read: `engine/combat/ai/QuickFightPlanner.java` (entry `plan(self)` → `QuickFightIntent`:
  ATTACK/MOVE_TOWARD/GUARD/FLEE/SURRENDER/BANDAGE/TURN_UNDEAD/castQueuedSpell/END_TURN),
  its view interfaces `QuickFightBattleView`/`QuickFightCombatantView`, `DiceRoller`,
  `SpellcastJudge`; and `engine/combat/CombatController.java` (`resolveMonsterTurn()`
  currently calls `RecoveredEnemyTactics.selectTarget`).
Build:
1. Adapter: `Combatant`/`CombatState` → `QuickFightBattleView`/`QuickFightCombatantView`.
   Geometry (LOS/reachability) may delegate to the already-ported `engine/combat/map`
   service. For any view field `Combatant` lacks real data for (spells, morale
   numbers, skills), return neutral/candidate values, documented — NO fabricated
   Matrix stats. Reuse the slice-1 neutral pattern.
2. Intent executor: translate a `QuickFightIntent` into `CombatController`/`CombatState`
   actions — ATTACK → the wired attack path (state.attack via cursor), MOVE_TOWARD →
   a move toward target, GUARD/END_TURN → end turn, FLEE/SURRENDER/BANDAGE/TURN_UNDEAD →
   best-effort mapping or a labeled TODO if no current mechanism (do not fake them).
3. Replace `resolveMonsterTurn()`'s `RecoveredEnemyTactics` call with: one
   `QuickFightPlanner` instance per combat (it holds remembered-target memory) →
   `plan(currentAsView)` → execute the intent. Retire/soft-deprecate
   `RecoveredEnemyTactics` (keep the class if other tests need it; stop using it in
   the live path).
Guardrails:
- One planner instance per `CombatController`/combat (target memory is stateful).
- Keep determinism: inject a seeded `DiceRoller`.
- Tests: add a controller-level test that a monster turn now produces a planner
  intent and executes it (e.g., adjacent enemy → ATTACK damages it; distant →
  MOVE_TOWARD reduces distance). Keep existing `CombatControllerTest` green.
- Full `mvn test` green + `run-combat-scene.sh` COMBAT_RESULT=0, transcript should
  show monsters acting via the planner. Commit as a "slice 2" checkpoint.
If a clean wire is impossible without fabricating data, STOP at a documented
partial (adapter + seam) rather than guess — same rule as slice 1.

## Finish
- `git diff --check` clean; update HANDOFF with what shipped, tests, limitations,
  and the next slice (movement/LOS, then VM opcodes). Leave COLLABORATION tidy.
