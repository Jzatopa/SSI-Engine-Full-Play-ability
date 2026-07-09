# Matrix Cubed Source Recovery Corpus

This is a cleaned, navigable corpus of every available Ghidra decompile export.
It is not original SSI source. Treat it as evidence-backed pseudocode for manual reconstruction.

## Summary

### START.unpacked.exe

- Recovered files: `358/358`
- Completed decompiles: `358`
- Timeouts: `0`
- Errors: `0`
- Anchor candidate functions: `0`
- Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.

### GAME.OVR payload

- Recovered files: `623/623`
- Completed decompiles: `623`
- Timeouts: `0`
- Errors: `0`
- Anchor candidate functions: `23`
- Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.

## GAME.OVR Anchor Candidates

| Role | Anchor | Candidate | Source offset | Distance | Recovered file |
|---|---|---|---:|---:|---|
| `anchor` | `credits` | `0000:016c FUN_0000_016c` | 393 | 21 | `generated/source_recovery/game_ovr_payload/0000_016c_FUN_0000_016c.c` |
| `anchor` | `credits` | `0000:0385 FUN_0000_0385` | 393 | 516 | `generated/source_recovery/game_ovr_payload/0000_0385_FUN_0000_0385.c` |
| `combat` | `combat_start` | `0000:fb92 FUN_0000_fb92` | 65336 | 926 | `generated/source_recovery/game_ovr_payload/0000_fb92_FUN_0000_fb92.c` |
| `combat` | `combat_start` | `1000:0131 FUN_1000_0131` | 65336 | 513 | `generated/source_recovery/game_ovr_payload/1000_0131_FUN_1000_0131.c` |
| `character_creation` | `character_creation` | `1000:8467 FUN_1000_8467` | 99509 | 70 | `generated/source_recovery/game_ovr_payload/1000_8467_FUN_1000_8467.c` |
| `character_creation` | `character_creation` | `1000:8e7d FUN_1000_8e7d` | 99509 | 2512 | `generated/source_recovery/game_ovr_payload/1000_8e7d_FUN_1000_8e7d.c` |
| `shop` | `shop_menu` | `1000:c010 FUN_1000_c010` | 117370 | 2658 | `generated/source_recovery/game_ovr_payload/1000_c010_FUN_1000_c010.c` |
| `shop` | `shop_menu` | `1000:ce56 FUN_1000_ce56` | 117370 | 996 | `generated/source_recovery/game_ovr_payload/1000_ce56_FUN_1000_ce56.c` |
| `items` | `item0_loader` | `1000:eb60 FUN_1000_eb60` | 126462 | 662 | `generated/source_recovery/game_ovr_payload/1000_eb60_FUN_1000_eb60.c` |
| `items` | `item0_loader` | `1000:eeec FUN_1000_eeec` | 126462 | 246 | `generated/source_recovery/game_ovr_payload/1000_eeec_FUN_1000_eeec.c` |
| `save_load` | `save_character` | `1000:f67d FUN_1000_f67d` | 129547 | 902 | `generated/source_recovery/game_ovr_payload/1000_f67d_FUN_1000_f67d.c` |
| `save_load` | `save_character` | `1000:fad0 FUN_1000_fad0` | 129547 | 205 | `generated/source_recovery/game_ovr_payload/1000_fad0_FUN_1000_fad0.c` |
| `save_load` | `load_game` | `1000:fb92 FUN_1000_fb92` | 134527 | 4581 | `generated/source_recovery/game_ovr_payload/1000_fb92_FUN_1000_fb92.c` |
| `save_load` | `load_game` | `2000:13fd FUN_2000_13fd` | 134527 | 1670 | `generated/source_recovery/game_ovr_payload/2000_13fd_FUN_2000_13fd.c` |
| `save_load` | `save_game` | `2000:13fd FUN_2000_13fd` | 136472 | 275 | `generated/source_recovery/game_ovr_payload/2000_13fd_FUN_2000_13fd.c` |
| `save_load` | `save_game` | `2000:1c53 FUN_2000_1c53` | 136472 | 1859 | `generated/source_recovery/game_ovr_payload/2000_1c53_FUN_2000_1c53.c` |
| `character_sheet` | `character_sheet_labels` | `2000:1fd4 FUN_2000_1fd4` | 139303 | 75 | `generated/source_recovery/game_ovr_payload/2000_1fd4_FUN_2000_1fd4.c` |
| `character_sheet` | `character_sheet_labels` | `2000:25a1 FUN_2000_25a1` | 139303 | 1410 | `generated/source_recovery/game_ovr_payload/2000_25a1_FUN_2000_25a1.c` |
| `items` | `item_debug_fields` | `2000:2986 FUN_2000_2986` | 143848 | 2138 | `generated/source_recovery/game_ovr_payload/2000_2986_FUN_2000_2986.c` |
| `inventory` | `gear_menu` | `2000:2986 FUN_2000_2986` | 145587 | 3877 | `generated/source_recovery/game_ovr_payload/2000_2986_FUN_2000_2986.c` |
| `items` | `item_debug_fields` | `2000:3ea6 FUN_2000_3ea6` | 143848 | 3270 | `generated/source_recovery/game_ovr_payload/2000_3ea6_FUN_2000_3ea6.c` |
| `inventory` | `gear_menu` | `2000:3ea6 FUN_2000_3ea6` | 145587 | 1531 | `generated/source_recovery/game_ovr_payload/2000_3ea6_FUN_2000_3ea6.c` |
| `ship` | `ship_stats` | `2000:b749 FUN_2000_b749` | 178171 | 170 | `generated/source_recovery/game_ovr_payload/2000_b749_FUN_2000_b749.c` |
| `ship` | `ship_stats` | `2000:b876 FUN_2000_b876` | 178171 | 131 | `generated/source_recovery/game_ovr_payload/2000_b876_FUN_2000_b876.c` |
| `wall_loader` | `wall_loader_wall_def_1` | `3000:006f FUN_3000_006f` | 198845 | 2118 | `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c` |
| `wall_loader` | `wall_loader_wall_def_2` | `3000:006f FUN_3000_006f` | 198880 | 2153 | `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c` |
| `map_loader` | `load3dmap_geo` | `3000:006f FUN_3000_006f` | 199334 | 2607 | `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c` |
| `map_loader` | `load3dmap_error` | `3000:006f FUN_3000_006f` | 199365 | 2638 | `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c` |
| `wall_loader` | `wall_loader_wall_def_1` | `3000:0c04 FUN_3000_0c04` | 198845 | 847 | `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c` |
| `wall_loader` | `wall_loader_wall_def_2` | `3000:0c04 FUN_3000_0c04` | 198880 | 812 | `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c` |
| `map_loader` | `load3dmap_geo` | `3000:0c04 FUN_3000_0c04` | 199334 | 358 | `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c` |
| `map_loader` | `load3dmap_error` | `3000:0c04 FUN_3000_0c04` | 199365 | 327 | `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c` |

## Use Policy

- Use recovered files to name and inspect candidate functions.
- Validate behavior against local binaries, generated DAX/ECL/GEO artifacts, and DOS captures before runtime changes.
- Do not copy anonymous Ghidra names into runtime APIs as if they were original names.
- For GAME.OVR, original file offset equals `linear + 8` because the Ghidra import starts after the FBOV header.
