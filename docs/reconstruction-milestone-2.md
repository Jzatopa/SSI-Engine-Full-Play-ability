# Reconstruction Milestone 2: Save Formats, Liveplay, and Runtime Foundation

**2026-06-21** — Consolidated progress after extensive liveplay automation testing.

## What's Decoded

### Character Record Format (`.WHO` / `.SAV`)
- **259-byte** fixed-size record (Matrix Cubed variant of Gold Box record)
- Overlaid on original `MON0CHA.DAX` monster data structure
- **Decoded fields**: name, ability scores (str/dex/con/int/wis/cha/tech), current ability scores, gender (0=male, 1=female), race (1=terran, 2=martian), career (1=rocket_jock, 2=medic), level, credits (4 bytes LE), experience (4 bytes LE), age, HP candidate (offset 0xE3)
- **Two candidate fields** at offsets 0x45 and 0xE3 that vary identically; need live validation

### Skill Record Format (`.STF`)
- **124-byte** fixed-size record
- 16 skill bytes at offsets 0x0C-0x1B
- Armor/weapon/shield candidates at 0x05-0x07
- Remainder of file (0x1C-0x7B) stores icons/portraits or other data

### Game State Format (`SAVGAMA.DAT`)
- **2901-byte** binary snapshot
- Offset 0x00-0x01: area ID (LE u16)
- Offset 0x02-0x04: position x, y, facing
- Offset 0x05-0x28: team slot names (9 slots x 4 bytes)
- Offset 0x2C-0x2F: credits (LE u32)
- Higher offsets: event flags, map exit table, active encounter state, embedded character records

### Data Model
- 182 model blocks cataloged
- 63 monster records from `MON0CHA.DAX` (names, base stats, visuals)
- 91 item templates from `ITEM0.DAX`
- 118 effect records from `MON0SPC.DAX`
- 184 encounter rows mapped
- 142 direct ECL refs resolved to named monsters

## Liveplay Automation Results

### What Worked
- DOSBox-X + Xvfb + xdotool can launch and drive the game
- Character creation: race → gender → career → roll stats → allocate skills → name → complete
- Add to Team: works via option 6
- Command menu navigation: works via option keys
- "Begin Adventuring": key sequence `1` then `0` (option 10)
- Game world loads (Caloris Space Port, tile-map EGA text mode view)
- Mouse/keyboard events reach the game

### What Did Not Work
- **Save to disk**: None of 15+ different key sequences triggered a file write.
  - Save paths tested: `C:\SAVE\`, `C:\MATRIX\SAVE\`, `C:\BUCK\SAVE\`
  - MATRIX.CFG formats tested: comma-separated 10-field, line-separated 5-line, mixed
  - Keys tested: 9, S, F5, F6, F7, F8, F10, Escape, Ctrl+O, Enter+S, and combinations
  - No `.DAT`, `.SAV`, `.WHO`, or `.STF` files were created in any checked location
- **Combat trigger**: No encounters triggered despite extensive automated exploration
- **F10 in-game menu**: Intercepted by DOSBox-X emulator menu

### Root Cause Hypothesis
The game's save routine may:
1. Require a specific function key not yet identified
2. Store saves in a virtual DOS filesystem (not mapped to host)
3. Be disabled when running under certain configs
4. Check for conditions not met during automation

## Key Source/Reference Milestones

From `GAME.OVR`:
- `Rest Save Change Exit` menu at offset 0x17BCF
- `Save Which Game: A B C D E F G H I J` at offset 0x21518
- `Load Which Game: A B C D E F G H I J` at offset 0x20D7F
- "Choose a FUNCTION" prompt at 0x17F2D
- "Quit to DOS. Game NOT saved." at 0x17F7F

From `START.EXE`:
- In-game action menu: `Move Area View Look Change Save Order Purge`
- Command menu: `Create, Purge, Modify, Train, View, Add, Remove, Load, Save, Begin Adventuring, Exit`

## Project Status

### Decoded (source-runtime ready)
- Character records ✓
- Skill records ✓
- Game state layout (partial) ✓
- Encounter→monster xref ✓
- Item catalog ✓
- Monster stats ✓
- Event command IR ✓
- Startup input map ✓
- Opening sequence ✓

### Needs Deeper Work
- Full game state decode (all 2901 bytes)
- Tile→event mapping
- Movement/position updates
- Combat system (initiative, attacks, damage, death)
- SAVE/LOAD game mechanics
- Party roster management at runtime

### Next Best Step
Build the runtime source with the data we have decoded, hardcoding initial game state. Implement movement on the map grid, event triggers, and combat resolution. The save format can be written from the running runtime and only needs validation against the real game behavior, which we can capture later.
