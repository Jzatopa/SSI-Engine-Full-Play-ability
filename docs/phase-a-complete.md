# Matrix Cubed Reconstruction — Phase A Complete

## Summary (June 21, 2026)

**96 passing tests. 3,637 lines. 25 decoded maps. 63 monsters. 91 items.**

## What Phase A Delivered

| Component | Status | Lines |
|-----------|--------|-------|
| **Map Engine** — Tile maps, wall collision, doors, overhead view, visible cells | ✅ | 135 |
| **Game Runtime** — Movement, event triggering, ECL execution, combat queuing | ✅ | 226 |
| **Event System** — ECL command compilation (show_text, queue_combat, grant_credits, etc.) | ✅ | 163 |
| **Combat** — QueuedCombat model + CombatLoop turn resolution (victory/defeat) | ✅ | 173 |
| **Character System** — Records, roster, party, stat modifiers, career/race enums | ✅ | 172 |
| **Inventory** — ItemCatalog (91 items), Equipment slots, Inventory container | ✅ | 135 |
| **Save/Load** — Binary .WHO/.STF/.DAT write + parse roundtrip, full persistence | ✅ | 189 |
| **Pygame Runner** — Main menu, character creation, exploration, combat UI, overlays | ✅ | 281 |
| **Character Creation** — Name entry, race/career selection, stat assignment | ✅ | 189 |
| **Dialog/Overlays** — Inventory view, character sheet, event text display | ✅ | 80 |

## Key Decisions Made

- **Party state**: Dual-store approach with `apply_damage()`/`add_credits()` methods keeping both in sync
- **Combat**: Simple always-hit with averaged dice; ready for THAC0 when validated
- **Save format**: Template-based preserving unknown bytes; roster slots still need population
- **Character creation**: Stat point-buy (14 points, 3-18 range, standard Gold Box array)

## External Review Findings

A separate deepseek sub-agent reviewed the entire codebase and found:
1. GameState is a god object (4 subsystems) — recommended extraction for Phase B
2. PartyState dual-write could diverge — mitigated with encapsulated methods
3. CombatLoop should call GameState methods rather than direct mutation — done
4. Save template approach can silently corrupt — flagged for Phase B hardening

## Remaining (Phase B/C)

- Character stats used in combat (THAC0/AC)
- Multi-step event state machine
- Shop/vendor UI
- Train/level-up
- Ship/vehicle mode
- GEO2-4 map extraction
- Item name resolution from GAME.OVR strings
- EXE packaging
- Web runtime polish

## File Map

```
src/matrix_cubed/
├── engine/       # Core gameplay (9 files, 1,383 lines)
├── tools/        # Frontends + utilities (5 files, 624 lines)
├── formats/      # Binary format parsers (6 files, 375 lines)
└── data/         # Asset repository (1 file)

tests/            # 10 test files, 96 tests
generated/        # Decoded game assets (maps, items, monsters, events, textures)
docs/             # Pass documentation + phase-a-review-request.md
```
