# Ghidra Evidence Comparison

This report maps Ghidra's segmented real-mode addresses back to existing Matrix Cubed evidence.

## Summary

- START functions: `358`
- START decompiled completed: `358/358`
- GAME.OVR candidate functions: `623`
- GAME.OVR decompiled completed: `623/623`
- GAME.OVR Ghidra-defined strings: `13`
- START exact text overlap with original START string artifact: `166`

## Address Mapping

- For raw `GAME.OVR.payload_after_fbov_header.bin`, Ghidra linear address = original `GAME.OVR` file offset minus 8.
- Example: original file offset `199365` (`Load3DMap`) maps to payload linear `199357` / Ghidra address `3000:0ABD`.

## GAME.OVR Anchor Map

| Anchor | File offset | Ghidra address | Previous function | Distance | Next function | Distance |
|---|---:|---|---|---:|---|---:|
| `overlay_magic` | 0 | `None` | ` ` |  | ` ` |  |
| `credits` | 393 | `0018:0001` | `0000:016c FUN_0000_016c` | 21 | `0000:0385 FUN_0000_0385` | 516 |
| `combat_start` | 65336 | `0ff3:0000` | `0000:fb92 FUN_0000_fb92` | 926 | `1000:0131 FUN_1000_0131` | 513 |
| `character_creation` | 99509 | `184a:000d` | `1000:8467 FUN_1000_8467` | 70 | `1000:8e7d FUN_1000_8e7d` | 2512 |
| `shop_menu` | 117370 | `1ca7:0002` | `1000:c010 FUN_1000_c010` | 2658 | `1000:ce56 FUN_1000_ce56` | 996 |
| `item0_loader` | 126462 | `1edf:0006` | `1000:eb60 FUN_1000_eb60` | 662 | `1000:eeec FUN_1000_eeec` | 246 |
| `save_character` | 129547 | `1fa0:0003` | `1000:f67d FUN_1000_f67d` | 902 | `1000:fad0 FUN_1000_fad0` | 205 |
| `load_game` | 134527 | `20d7:0007` | `1000:fb92 FUN_1000_fb92` | 4581 | `2000:13fd FUN_2000_13fd` | 1670 |
| `save_game` | 136472 | `2151:0000` | `2000:13fd FUN_2000_13fd` | 275 | `2000:1c53 FUN_2000_1c53` | 1859 |
| `character_sheet_labels` | 139303 | `2201:000f` | `2000:1fd4 FUN_2000_1fd4` | 75 | `2000:25a1 FUN_2000_25a1` | 1410 |
| `item_debug_fields` | 143848 | `231e:0000` | `2000:2986 FUN_2000_2986` | 2138 | `2000:3ea6 FUN_2000_3ea6` | 3270 |
| `gear_menu` | 145587 | `238a:000b` | `2000:2986 FUN_2000_2986` | 3877 | `2000:3ea6 FUN_2000_3ea6` | 1531 |
| `ship_stats` | 178171 | `2b7f:0003` | `2000:b749 FUN_2000_b749` | 170 | `2000:b876 FUN_2000_b876` | 131 |
| `wall_loader_wall_def_1` | 198845 | `308b:0005` | `3000:006f FUN_3000_006f` | 2118 | `3000:0c04 FUN_3000_0c04` | 847 |
| `wall_loader_wall_def_2` | 198880 | `308d:0008` | `3000:006f FUN_3000_006f` | 2153 | `3000:0c04 FUN_3000_0c04` | 812 |
| `load3dmap_geo` | 199334 | `30a9:000e` | `3000:006f FUN_3000_006f` | 2607 | `3000:0c04 FUN_3000_0c04` | 358 |
| `load3dmap_error` | 199365 | `30ab:000d` | `3000:006f FUN_3000_006f` | 2638 | `3000:0c04 FUN_3000_0c04` | 327 |

## Integration Notes

- The comparison does not promote Ghidra anonymous function names into runtime code.
- The nearest-function rows are triage targets for manual naming in Ghidra.
- Existing custom string extractors remain authoritative for text coverage; Ghidra's string table is narrower.
