# COAB → Java Combat Port Map

Date: 2026-07-07
Author: Claude Code (survey pass; docs only, no source changes)

## Purpose

Combat is the main missing subsystem between the current ssi-engine fork and a
fully playable game. Per James's 2026-07-07 reuse policy, COAB may be ported
directly into the universal engine layer (record provenance, defer licensing).
This document maps COAB's combat subsystem — a complete, working, per-overlay
C# translation of the original Gold Box engine — onto the existing Java combat
scaffold, and defines the port order.

## Sources

| Source | Location | Version | Role |
|---|---|---|---|
| COAB (Simeon Pilgrim et al.) | `/home/jzatopa/.local/opt/coab` | commit `9dc46f1` | Combat flow blueprint + AD&D reference flavor. No root license file; provenance must be recorded per ported unit; compliance pass deferred. |
| Matrix Cubed Ghidra deep export | `generated/ghidra/deep_game_ovr_payload/` (624 functions, decompiled) | see `docs/ghidra-deep-pass-1.md` | Buck Rogers-specific rules/values; validation oracle for what carries over. |
| Existing Java scaffold | `references/ssi-engine/src/main/java/engine/combat/` | uncommitted on `matrix-cubed-fork` | Target; parts survive, parts are replaced (see below). |

Evidence rule: everything ported from COAB is labeled **ported (AD&D/COAB)**
until independently confirmed against Matrix Cubed files or the GAME.OVR
decompile. COAB values must not be promoted as Matrix evidence.

## COAB combat call graph (verified by reading the C#)

Confidence: read directly from `ovr009.cs`, `ovr014.cs` this pass; other
overlays surveyed by function inventory only (marked *inventory*).

- **`ovr009.MainCombatLoop`** (`sub_33100`): `ovr011.BattleSetup()` → loop
  until one side is empty:
  `ovr025.CountCombatTeamMembers()` → per-combatant
  `ovr014.CalculateInitiative()` → `FindNextCombatant()` yields turn order →
  `DoPlayerCombatTurn()` per combatant → `BattleRoundChecks()` → repeat.
  Ends with `free_combat_stuff()`.
- **Initiative** (`ovr014.CalculateInitiative`, `sub_3E000`):
  `delay = 1d6 + DexReactionAdj(player)`, min 1; a surprise flag
  (`area2_ptr.field_596` vs combat team) subtracts 6; result clamped to
  0..20; `delay == 0` means no turn this round. Also resets per-round action
  state and recalculates attacks (`reclac_attacks`) and half-moves.
- **Turn order** (`ovr009.FindNextCombatant`, `sub_331BC`): repeatedly scans
  all combatants, picks highest remaining `delay`, ties broken by a fresh
  1d100 per scan; yields combatants until all delays are consumed. Note:
  order is dynamic within the round, not a pre-sorted list.
- **Per-turn** (`ovr009.DoPlayerCombatTurn`, `sub_33281`): resets
  AttacksReceived / directionChanges / guarding, checks restrained affect,
  `ovr025.reclac_player_values` (effective values recomputed every turn),
  then either `ovr010.PlayerQuickFight` (AI) or `combat_menu` (interactive).
- **Round end** (`ovr009.BattleRoundChecks`, `battle01`): steps game time,
  increments `combat_round`, per-combatant affect ticks + poison cloud,
  dying combatants accumulate `bleeding` (dead when > 9), bandage prompt,
  recount teams; battle over when either side is empty or
  `combat_round >= combat_round_no_action_limit`.
- **Attack resolution** (*inventory*): `ovr014.AttackTarget` /
  `can_attack_target` / `TrySweepAttack` / `RangedDefenseBonus`;
  `ovr024.CanHitTarget`, `RollSavingThrow`, `roll_dice`;
  `ovr025.CalculateAttackValues`, `strengthHitBonus`, `strengthDamBonus`,
  `DexAcBonus`, `CalcArmorWeightEffect` (encumbrance).
- **Battlefield setup** (*inventory*): `ovr011.BattleSetup`,
  `place_combatant`, `SetupDungeonFloor` / `SetupWildernessFloor01`,
  background-tile builders.
- **LOS / pathing** (*inventory*): `ovr032.buildMapCache`,
  `canReachTarget`, `CanSeeCombatant`, `FindCombatantDirection`.
- **Effects/affects** (*inventory*): `ovr024.add_affect` / `remove_affect` /
  `CheckAffectsEffect` (structure is universal); `ovr013` holds the
  AD&D-specific affect implementations (Bless, Curse, etc. — flavor-only).
- **Movement** (*inventory*): `ovr014.CalcMoves`, `ovr025.calc_movement`.

## Mapping onto the existing Java scaffold

### Survives as-is (asset/UI/bridge layer — orthogonal to combat rules)

- `CombatAssetLoader`, `BattlefieldBuffer`, `RecoveredBattlefieldGenerator`
- `SwingCombatUiBridge` / `HeadlessCombatUiBridge` /
  `LegacyGoldBoxCombatUiBridge` and `CombatUiBridgeSelector` profile routing
- `EclCombatBridge` VM entry (`LOAD_MON` → `COMBAT` → `COMBAT_RESULT`),
  `CombatSession` / `CombatSessionResult`, `CombatPosition`

### Replaced or restructured by the port

| Java today | COAB counterpart | Change |
|---|---|---|
| `CombatTurnQueue` (fixed order, simple round counter) | `CalculateInitiative` + `FindNextCombatant` | Replace with delay-based initiative and dynamic max-delay selection with d100 tiebreak. |
| `CombatController` scaffold turn/attack logic | `MainCombatLoop` / `DoPlayerCombatTurn` / `combat_menu` / `PlayerQuickFight` | Restructure around COAB's loop; keep cursor/menu UI concepts, replace resolution internals. |
| `Combatant` static `thac0`/`damageMin`/`damageMax`/`movement` fields | `reclac_player_values` (per-turn effective values) | Effective values become computed per turn through a ruleset hook, not constructor constants. |
| (missing) round-end handling | `BattleRoundChecks` | New: dying/bleeding progression, affect ticks, round no-action limit. |
| (missing) LOS/pathing | `ovr032` | New universal service. |
| (missing) affect/effect service | `ovr024` structure (not `ovr013` contents) | New universal service; AD&D affects stay in a flavor. |

### Ruleset boundary (universal vs flavor)

Universal (port from COAB structure): combat loop, initiative mechanics,
turn selection, round checks, attack/target flow, LOS/path, affect
plumbing, movement flow. AD&D flavor (COAB values, port but gate): dex
reaction/AC tables, strength hit/damage bonuses, saving-throw tables,
`ovr013` affects. Buck Rogers flavor: fill from Ghidra GAME.OVR evidence —
expect skills instead of spells, credits, burst/autofire weapon behavior,
and a THAC0-analog whose table must come from Matrix evidence. The existing
`GameMechanics` / rulesystem-flavor boundary is the attachment point.

## Ghidra cross-check (the Buck delta finder)

Because Matrix Cubed shares the engine lineage, GAME.OVR functions should
match COAB functions by shape (call structure, loop form, table access).
Plan: walk `generated/ghidra/deep_game_ovr_payload/functions.tsv` +
`decompiled/` against COAB's named functions; produce a coverage table
(matched → name adopted as candidate; unmatched → Matrix-specific, needs
its own analysis). This replaces DOS-capture-first reconstruction as the
primary combat-evidence method; captures remain the final validation.

## Port order (one pass each, tests first)

1. **Initiative + turn order**: port `CalculateInitiative` +
   `FindNextCombatant` semantics into a `CombatTurnQueue` replacement with
   seeded-RNG tests mirroring COAB behavior (incl. tiebreak and surprise).
   ✅ Done 2026-07-08 — see `CombatTurnQueue.java` (provenance header) and
   `CombatTurnQueueTest.java` (10 conformance tests). Deferred within pass 1:
   casting delays (`delay = 20` paths), surprise wiring from encounter
   context, Buck reaction-adjustment table (hook defaults to 0).
2. **Round structure**: `BattleRoundChecks` — dying/bleeding, affect tick
   hooks, no-action round limit.
   ✅ Done 2026-07-08 — `Combatant` carries `HealthStatus`/`bleeding` with
   `ovr025.damage_player` semantics (overkill >9 dead, 1..9 dying with
   bleeding = overkill, exact 0 unconscious); `CombatState` runs end-of-round
   checks (bleed ticks, teammate-dying warning, `Phase.EXPIRED` after 15
   attack-free rounds, re-armed by every attack) with a `RoundEndHook`
   extension point for the effect pass. Deferred within pass 2: game-time
   stepping, poison clouds, the bandage action, animated-status branch,
   enemy-health morale recalculation.
3. **Attack flow**: `CanHitTarget`/`AttackTarget` skeleton with
   ruleset-provided numbers; current THAC0 scaffold values become the Buck
   *candidate* flavor.
4. **Movement + LOS/pathing**: `ovr032` + `calc_movement`/`CalcMoves`.
5. **Effects service**: `ovr024` plumbing only.
6. **Ghidra cross-check pass**: coverage table COAB ↔ GAME.OVR; promote or
   replace candidates.
7. **Interactive wiring + smoke**: quick-fight AI (`ovr010.PlayerQuickFight`)
   and `combat_menu` parity in `SwingCombatUiBridge`; headless end-to-end
   smoke (new game → dungeon → ECL combat → save → load).

Prerequisite feeding 3/4: decode `CharacterBuckRogers` movement/THAC0-analog/
skills (currently hardcoded 0) — `reclac_player_values` tells us exactly
which character fields combat consumes; reuse the Python `.WHO` decode
evidence rather than re-deriving.
