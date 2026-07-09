# Matrix Cubed Reconstruction: Complete Roadmap

**Current state**: Formats decoded, data cataloged, runtime foundation exists.
**Target**: Playable source that builds to EXE + web.

---

## Phase A: Source Runtime Core (~15-20 passes)

The runtime must replicate the game's core loop: move on map → trigger events → resolve combat → update state → repeat.

| Step | Component | Description | Prerequisites |
|------|-----------|-------------|---------------|
| **A1** | Map engine | Tile grid movement, collision, facing direction, door/transition tiles | GEO map parser (done) |
| **A2** | Event trigger engine | Walk-on-tile → fire ECL event; conditional branching, flags, counters | ECL disassembly (done) |
| **A3** | Combat core | Initiative, turn order, attack rolls, damage, death, victory, flee | Monster stats (done), items (done) |
| **A4** | Party state | HP tracking, status effects, experience, level-up | Character format (done) |
| **A5** | Inventory | Carry items, equip weapons/armor/shields, use items | Item catalog (done) |
| **A6** | Full game state | Complete SAVGAMA.DAT read/write for all 2901 bytes | Partial decode (done) |
| **A7** | Save/load files | Read/write .WHO/.STF/.SAV/.DAT files | Formats done, trigger unknown |
| **A8** | Shop/vendor UI | Buy, sell, trade interface | Items (done) |
| **A9** | Dialog system | NPC conversation trees, quest text | ECL strings (done) |
| **A10** | Player character creation | Full creation flow: race, gender, career, stats, skills, name | Keybindings known |
| **A11** | Train/level-up | Spend skill points, stat increases on level-up | Character format (done) |
| **A12** | Ship/vehicle mode | Ram, Board, Command, Sensors, Boost engines — ship combat | Strings found in GAME.OVR |
| **A13** | Minimap/automap | Overhead view of explored areas | GEO map data (done) |

## Phase B: Content Integration (~10-15 passes)

| Step | Component | Description | Prerequisites |
|------|-----------|-------------|---------------|
| **B1** | All 122 GEO maps imported | Grid cells, wall types, elevation, event tile refs | GeoMap parser (done) |
| **B2** | All ECL scripts compiled | 100+ event scripts → executable command chains | ECL disassembly (done) |
| **B3** | Monster placement | Encounter definitions → which monsters appear where | Encounter xref (done) |
| **B4** | Monster behavior AI | Patrol, aggro, attack patterns, special abilities | Monster stats (done) |
| **B5** | All items functional | Weapons, armor, consumables, keys, quest items | Item catalog (done) |
| **B6** | All effects | Spell effects, status conditions, special abilities | Effects catalog (done) |
| **B7** | Dialog integration | All NPC text, mission briefings, terminal text | Strings in GAME.OVR |
| **B8** | Story progression | Plot flags, triggers, win state, final boss | ECL + strings |
| **B9** | All maps textured | Wall textures, floor textures, object sprites | DAX image (done) |
| **B10** | Sound & music | AdLib/SoundBlaster music, sound effects | XMI files (done) |

## Phase C: Frontend Targets (~5-8 passes)

| Step | Component | Description | Prerequisites |
|------|-----------|-------------|---------------|
| **C1** | Python desktop | Pygame-based windowed desktop app | Phase A complete |
| **C2** | Web runtime | JavaScript/WebGPU or Pyodide build | Phase A complete |
| **C3** | EXE packaging | PyInstaller / Nuitka → standalone Windows executable | C1 complete |
| **C4** | Static web host | Self-contained HTML/JS/CSS deployable to any host | C2 complete |
| **C5** | Installer | NSIS/InnoSetup for EXE distribution | C3 complete |

## Phase D: Validation (~5-10 passes)

| Step | Component | Description | Prerequisites |
|------|-----------|-------------|---------------|
| **D1** | Live behavior compare | Side-by-side: original DOSBox vs reconstructed runtime | Phase A complete |
| **D2** | Save roundtrip | Original game saves → reconstructed loads (and vice versa) | A6, A7 complete |
| **D3** | Combat accuracy | Verify AC, THAC0, damage, XP match original | A3 complete |
| **D4** | All encounters playable | Play through all 25 mapped GEO areas | B1-B4 complete |
| **D5** | Speedrun validation | Complete game start-to-finish matches original behavior | Phase B complete |
| **D6** | Bug fix pass | Fix discrepancies found in D1-D5 | D1-D5 complete |

## Current vs. Target

```
✅ Decoded:      Character records, skill records, game state (partial), 
                 monsters, items, effects, encounters, 25 GEO maps, 
                 ECL events, image assets, startup flow
✅ Built:        Format parsers, runtime prototype, event IR, combat model,
                 15 passing tests, Qwen sidecar
⬜ TODO:         Map engine, event executor, combat system, full state mgmt,
                 party/inventory, frontends, validation
```

## Effort Scale

| Phase | Passes | Realistic Timeline |
|-------|--------|--------------------|
| A. Source Runtime Core | 15-20 | Primary focused work |
| B. Content Integration | 10-15 | Parallel to A |
| C. Frontend Targets | 5-8 | After A stable |
| D. Validation | 5-10 | Parallel to B/C |

**Total estimated passes to playable EXE + web: 35-55**

## Methodology

Keep the existing pattern that works:
1. **One component per pass** — focused, testable, with pass note
2. **Browser viewer first** — visible results before promoting to source
3. **Tests alongside every component** — 15 passing now, target 100+
4. **Mirror everything to Documents** — redundancy
5. **Qwen only for bounded advisory** — not for deterministic decoding
6. **Keep the blog updated** — reusable for future game projects

## Next Step (A1): Map Engine

Build the tile-grid movement system: player position, facing, movement inputs, collision detection with wall tiles, door tiles, transition tiles, and event-tile triggers. Hook into the existing GeoMap parser and ECL event system so walking onto an event tile fires the correct script.
