# Liveplay First Combat Pass 1

## Goal

Boot Matrix Cubed from an existing SLOT A saved game (CAR1 Terran Male Medic, level 7),
navigate the starting area to trigger the first combat encounter, save post-combat,
and capture all save-file diffs.

## Status: Save Load Succeeded; Combat and Save Steps Could Not Be Completed

The game loads and enters the game world. Save files persist correctly across runs.
However, the in-game save key sequence (Escape → 8 → A → Enter) does not trigger
a save, and combat could not be triggered through automated movement.

## Key Findings

### MATRIX.CFG Format

The game accepts two config formats:

1. **Comma-separated (game-generated):** `1,0,0,0,0,40,1,4,1,0`
   - The game writes this format after its own first-time setup.
   - These values are at: `LIVEPLAY/MATRIX/MATRIX.CFG`

2. **Line-based (original user format):** Lines with letters `E Q N ...`
   - The original liveplay used letter codes (E=EGA, Q=Silent, N=Neither)
   - The correct numeric values are `1` (EGA), `6` (Silent), `3` (Neither)

The comma-separated format boots the game directly to the game world
(when a saved game exists on SLOT A). The game loads the saved party
and enters play immediately at the starting location.

### Game World Rendering

The game renders the starting Caloris Space Port area as an EGA text-mode
tile map view. This is not the typical Gold Box first-person view; it
appears to be a top-down or debug-style tile rendering with:

- Magenta horizontal bars (walls/platforms)
- Red `R` letter columns (wall borders)
- Orange/yellow `K` letter columns (additional walls)
- Red arrow/triangle symbols (player/monster positions)
- `0` digit clusters (terrain/door markers)

The consistent screenshot size of 8586-8929 bytes for this view
indicates stable game rendering across runs.

### In-Game Key Behavior

| Key | Observed Result |
| --- | --- |
| Up/Down/Left/Right | Moves within tile map; no visible view change |
| Space | Appears to interact; no visible change |
| F (fire) | Appears to attempt action; no combat trigger |
| S (search) | No visible result |
| Escape (1x) | Stays in game world |
| Escape (3x) | Screen size changes (8929B vs 8586B) - subtle state change |
| F10 → s → A | Exits game to `C:\MATRIX>` DOS prompt |
| F10 → q → Enter | Quits DOSBox-X |

The F10 key appears to open the game's internal menu, where `s` then `A`
is being interpreted as a Quit command (rather than Save + Slot A).

### Save File Persistence

All 11 save files in `MATRIX/SAVE/` are identical before and after all runs.
The game correctly reads and preserves the save files. Key files:

| File | Size | SHA256 (first 16) | Purpose |
| --- | ---: | --- | --- |
| CHRDATA1.SAV | 259 | `bb1aeb4d213b831d` | Active character 1 (CAR1 Medic) |
| CHRDATA1.STF | 124 | `4c3f1fed62da30f2` | Active character 1 skill data |
| SAVGAMA.DAT | 2901 | `ae0f4283336d8093` | Game state / party record |
| GEN1.WHO | 259 | `5d3830697b12a7e9` | Roster character (Terran Female RJ) |
| RAC1.WHO | 259 | `82ae564eeccccbff` | Roster character (Martian Male RJ) |
| TST1.WHO | 259 | `388c3f43994f7462` | Roster character (Terran Male RJ) |
| TST2.WHO | 259 | `f3162d85a414655a` | Roster character (Terran Male RJ) |

`.STF` files are 124 bytes each. All `.STF` files except CHRDATA1.STF
and GEN1.STF share hash `eb16c4b6c1276da5`.

### SAVGAMA.DAT Structure (2901 bytes)

- Byte 0: `0x01` - party count candidate (1 active character)
- Bytes 0-4: little-endian: `01 00 00 00` (32-bit party count?)
- Large zero region from offset 0x04 to ~0x0b0
- At 0x0b0: non-zero data begins (`02 00 00 00 00 00 57 09 08 00 ...`)
- At 0x0a0c: ASCII string `CHRDATA1` embedded in the data
- File is mostly sparse with clustered data regions

### Save Probe Output (CHRDATA1.SAV)

Parsed with the existing 259-byte `.WHO` record parser:

```json
{
  "name": "CAR1",
  "ability_scores": {"str":10, "dex":16, "con":15, "int":12, "wis":13, "cha":15, "tech":15},
  "race_id": 1, "race": "terran",
  "gender_id": 0, "gender": "male",
  "career_id": 2, "career": "medic",
  "level": 7,
  "credits": 1000,
  "experience": 48000,
  "age": 22,
  "hit_points_candidate": 38
}
```

### Test Results

13 tests pass, 2 pre-existing failures (unrelated to save format):
- `tests/test_game_state.py::test_parse_game_state_wrong_size` - `__wrapped__` attribute issue
- `tests/test_stf.py::test_parse_stf_skill_values` - skill offset mismatch

## Observed Limitations

1. **Automated Save:** The Escape → 8 → A → Enter sequence at the command
   menu does not result in written save files. The game may require specific
   menu navigation that autokey sequences cannot reproduce without visual
   feedback.

2. **Combat Trigger:** Extensive automated exploration (arrow keys in all
   directions, Space/F/S key presses) did not trigger a random encounter or
   placed encounter in the Caloris Space Port starting area. Combat may
   require reaching specific map triggers not achievable through linear
   movement.

3. **MATRIX.CFG uncertainty:** Two different config formats were observed;
   the exact field mapping in the comma-separated format is not decoded.
   The numeric line-based format may need additional fields beyond the
   first 5 lines.

## Next Steps

1. **Live-play with human supervision** to navigate the game world
   interactively and trigger the first combat encounter
2. **Identify the correct in-game save key sequence** through the game's
   F10 menu (screenshot analysis or ECL reference)
3. **Decode SAVGAMA.DAT** fields by creating a second-party save sample
   (add TST2 character to party, save, diff)
4. **Add a second character** to the active party to confirm party-count
   and party-slot structures in SAVGAMA.DAT
