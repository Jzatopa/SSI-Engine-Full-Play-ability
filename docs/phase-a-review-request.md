# Matrix Cubed Reconstruction — Phase A Review

## Project State (June 21, 2026)

**Total tests:** 96 passing, 0 failing
**Runtime:** Python 3.12, Pygame 2.6.1, 25 decoded maps, 63 monsters, 91 items

## Architecture Overview

```
engine/
├── map_engine.py      # Tile maps, collision, overhead view, visible cells
├── runtime.py          # GameState: movement, events, combat queuing, party state
├── combat.py           # QueuedCombat model (frozen dataclass, from event decoding)
├── combat_loop.py      # Turn-based combat resolution (player + monster turns)
├── events.py           # EventCommand, EventExecution, compile_event_commands
├── inventory.py        # ItemCatalog, ItemTemplate, Equipment, Inventory
├── character.py        # CharacterRecord, CharacterRoster, Party, stat helpers
└── save_load.py        # Binary save/load to .WHO / .STF / SAVGAMA.DAT formats

tools/
├── pygame_runner.py    # Desktop frontend: exploration + combat + overlays
└── overlays.py         # Inventory overlay + character sheet overlay

formats/
├── save.py             # 259-byte .WHO character record parser
├── stf.py              # 124-byte .STF skill record parser
└── game_state.py       # 2901-byte SAVGAMA.DAT game state parser

data/
└── repository.py       # ReconstructedData: loads decoded assets from generated/
```

## What's Complete

| Module | Status | Tests |
|--------|--------|-------|
| Map Engine (GeoMap) | ✅ Tile movement, wall collision, doors, overhead view | 38 |
| Game Runtime (GameState) | ✅ Movement, event triggering, ECL execution, combat queuing | 10 |
| Combat | ✅ QueuedCombat model, turn resolution, victory/defeat | 10 |
| Character System | ✅ Records, roster, party, stat modifiers, career/race enums | 16 |
| Inventory | ✅ ItemCatalog (91 items), Equipment slots, Inventory container | 13 |
| Save/Load | ✅ Binary .WHO/.STF/.DAT write + parse roundtrip | 9 |
| Pygame Frontend | ✅ Exploration view, combat UI, inventory/character overlays | — |

## Event System Integration

The GameState.execute_current_event() method dispatches decoded ECL commands:
- **show_text** → displayed in viewport overlay
- **queue_combat** → sets active_encounter → CombatLoop
- **grant_credits** → updates party.credits (both legacy + active_party)
- **grant_item** → appends to party.inventory (string placeholder)
- **damage_party** → damages party HP (both legacy + active_party first member)
- **mark_transition** / **mark_condition_checked** → sets flags

## Combat Loop Design

```
player_turn()
  → always hits (d20 >= 12 auto, damage = 3 avg d6)
  → targets current monster_index
  → if monster HP <= 0: _advance() to next living monster
  → if all monsters dead: resolved = True, log "Victory!"

monster_turn()
  → always hits (d20 >= 14 auto, damage = 2 avg d4)
  → damages party.hp + active_party.member_hp[0]
  → if party HP <= 0: resolved = True, log "Defeated!"
```

Current simplification: always hits (no random). The hit/miss system is ready to add once we validate against the original game.

## What's Remaining for Phase A

1. **Character Creation UI** — Pygame screens for name/stats/race/career selection
2. **Dialog Enhancements** — Scrollable multi-line event text, typewriter effect
3. **Shop/Vendor** — Buy/sell items using credit system (item templates exist)
4. **Train/Level-Up** — Spend experience to raise stats, HP increase on level
5. **Ship/Vehicle Mode** — Overworld travel between maps (GEO transitions detected in ECL)
6. **GEO Map Expansion** — Only 25/122 maps loaded (all from GEO1.DAX); remaining maps in GAME.OVR need extraction

## Questions for Review

1. **Combat damage**: Always-hit is fine for now, but should we implement d20 THAC0-style from day one?
2. **Multi-monster targeting**: Currently targets monster_names[0] until dead. Should we allow player to select target?
3. **Party HP**: Single shared HP pool for now. Should each character have individual HP in combat?
4. **Save format**: SAVGAMA.DAT writer uses a template approach (preserves unknown fields). Is this robust enough for long-term saves?
5. **Shop prices**: The item catalog has no price field decoded. Should we derive prices from item index or add a lookup?
6. **Map expansion**: GEO2.DAX through GEO4.DAX have not been extracted. Is this a priority or can we prototype with geo 17 only?
