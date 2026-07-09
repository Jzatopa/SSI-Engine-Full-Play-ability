**Matrix Cubed Reconstruction — Phase A Complete + Fix Pass**

**97 tests passing. 3.6K lines.** Game runs from main menu → character creation → exploration → combat → save/load.

**Fixes from audit:**
- 🚫 Inventory crash: overlay now accepts both old (string list) and new (int list) formats
- 🗺️ Map transitions: MapEngine syncs when player walks off-map (TILE_EXIT cells now work)
- 🚫 Event leak: walking off event tiles now clears the active event state
- 📂 Continue option now actually loads saved characters from disk
- 👤 Character overlay shows the real player character, not a placeholder
- 🐛 load_characters() now logs errors instead of swallowing them silently
- 🧹 pycache cleaned

**Current capabilities:**
- Main menu (New Game / Continue / Quit)
- Character creation — name, race (Terran/Martian), career (Rocket Jock/Medic), stat point-buy (14 pts)
- First-person corridor exploration with WASD/Q/E, 16×16 overhead minimap
- Event triggers — walk on special tiles, read decoded ECL text
- THAC0 combat — d20 attack rolls vs monster AC, STR modifier, multi-monster waves
- Map transitions — walking off the edge loads the next GEO map
- Save/Load — binary .WHO / .STF / SAVGAMA.DAT persistence

**Next steps to end-game (finish Phase B + C):**

| Priority | Item | ETA |
|----------|------|-----|
| 1 | Extract remaining 97 maps from GAME.OVR (GEO2-4) | ~5 passes |
| 2 | Real combat validation — play through Caloris Space Port vs original DOS | ~3 passes |
| 3 | Item names from GAME.OVR strings (so inventory shows readable names like "Laser Pistol") | ~2 passes |
| 4 | Shop/vendor screen (buy/sell from 91-item catalog) | ~2 passes |
| 5 | Multi-party combat — distribute damage across all characters | ~2 passes |
| 6 | Level-up / train system (XP → level → HP/THAC0 improvements) | ~2 passes |
| 7 | EXE packaging (PyInstaller → portable .exe) | ~2 passes |
| 8 | Web build polish (HTML prototype → full web frontend) | ~3 passes |
| Total remaining | | **~21 passes / 2-3 weeks sustained** |

First playable full run: after items #1-3 the game has maps, readable items, and validated combat — the core "walk around, fight, loot" loop works end-to-end.

[Source: matrix-cubed-re/ | 97 tests | pygame runner]
