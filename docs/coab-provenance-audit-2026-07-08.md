# COAB Provenance Audit — Tracks A/B/E (2026-07-08)

Read-only audit of the three mega-pass packages whose porting agents were
terminated before delivering final reports. Performed by a Haiku-tier
subagent; every specific `file.function` citation was mechanically verified
by grep against the COAB checkout (`~/.local/opt/coab`, commit `9dc46f1`).

## Results

| Classification | attack | map | loot | TOTAL |
|---|---|---|---|---|
| CITED-VERIFIED (citation names file.function; grep confirmed) | 18 | 10 | 20 | **48** |
| CITED-UNVERIFIED (citation didn't check out) | 0 | 0 | 0 | **0** |
| CITED-VAGUE (COAB referenced, no exact file.function) | 7 | 8 | 10 | **25** |
| UNCITED-PORTED (ported logic with no citation) | 0 | 0 | 0 | **0** |
| SELF-DEFINED (integrator interfaces/test scaffolding, labeled) | 10 | 2 | 5 | **17** |

**Key outcomes:**
- Zero invented citations: every exact citation resolves to a real function
  in the named COAB file.
- Zero orphan logic: no ported game logic lacks a COAB reference entirely.
- AD&D numeric tables in `AdndAttackRuleset` and `AdndCoinage` are labeled
  "flavor, not Matrix Cubed evidence" as required; `NeutralAttackRuleset`,
  `SingleCurrencyFlavor`, `SimpleMoneyAccount` correctly state they are not
  ports.

## Disposition of the 25 CITED-VAGUE items

They are predominantly data records and hook interfaces (e.g.
`AttackOutcome`, `ReachResult`, `TileTraits`, `MoneyAccount`) whose
semantics derive from an adjacent class that carries a verified citation;
a few are methods citing sub_ addresses without the file.function format
(`AttackResolver.largeWeaponDiceApply`, `CombatMapService.buildMapCache`,
`TreasurePool.discardRemainder`). No evidence risk — the porting trail is
recoverable in every case. Format tightening is DEFERRED to the dedicated
licensing/attribution pass (already planned before any public release),
where citation formatting will be normalized wholesale. The full per-file
list lives in the audit agent's report (session 2026-07-08); the priority
items are the ones named above.
