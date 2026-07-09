# Source Recovery Function Role Inference

This report uses the recovered pseudocode corpus to identify what original functions likely do.
The labels are hypotheses for triage, not original function names.

## Summary

- Functions scanned: `981`
- Functions with inferred roles: `23`
- Confidence counts: `{'high': 7, 'low': 11, 'medium': 5, 'unknown': 958}`

## High-Value GAME.OVR Candidates

| Likely role | Confidence | Function | Offset | Evidence | Signals | File |
|---|---|---|---:|---|---|---|
| `anchor` | `high` | `0000:016c FUN_0000_016c` | 372 | credits@393 d=21 | calls=1, memrefs=3 | `generated/source_recovery/game_ovr_payload/0000_016c_FUN_0000_016c.c` |
| `character_creation` | `high` | `1000:8467 FUN_1000_8467` | 99439 | character_creation@99509 d=70 | calls=1, memrefs=3 | `generated/source_recovery/game_ovr_payload/1000_8467_FUN_1000_8467.c` |
| `character_sheet` | `high` | `2000:1fd4 FUN_2000_1fd4` | 139228 | character_sheet_labels@139303 d=75 |  | `generated/source_recovery/game_ovr_payload/2000_1fd4_FUN_2000_1fd4.c` |
| `ship` | `high` | `2000:b876 FUN_2000_b876` | 178302 | ship_stats@178171 d=131 | calls=2, memrefs=4 | `generated/source_recovery/game_ovr_payload/2000_b876_FUN_2000_b876.c` |
| `ship` | `high` | `2000:b749 FUN_2000_b749` | 178001 | ship_stats@178171 d=170 | calls=1, memrefs=4 | `generated/source_recovery/game_ovr_payload/2000_b749_FUN_2000_b749.c` |
| `save_load` | `high` | `1000:fad0 FUN_1000_fad0` | 129752 | save_character@129547 d=205 | calls=10, memrefs=19 | `generated/source_recovery/game_ovr_payload/1000_fad0_FUN_1000_fad0.c` |
| `items` | `high` | `1000:eeec FUN_1000_eeec` | 126708 | item0_loader@126462 d=246 | calls=5, memrefs=16 | `generated/source_recovery/game_ovr_payload/1000_eeec_FUN_1000_eeec.c` |
| `save_load` | `medium` | `2000:13fd FUN_2000_13fd` | 136197 | load_game@134527 d=1670, save_game@136472 d=275 | memrefs=2 | `generated/source_recovery/game_ovr_payload/2000_13fd_FUN_2000_13fd.c` |
| `map_loader`, `wall_loader` | `low` | `3000:0c04 FUN_3000_0c04` | 199692 | wall_loader_wall_def_1@198845 d=847, wall_loader_wall_def_2@198880 d=812, load3dmap_geo@199334 d=358, load3dmap_error@199365 d=327 |  | `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c` |
| `combat` | `low` | `1000:0131 FUN_1000_0131` | 65849 | combat_start@65336 d=513 |  | `generated/source_recovery/game_ovr_payload/1000_0131_FUN_1000_0131.c` |
| `anchor` | `medium` | `0000:0385 FUN_0000_0385` | 909 | credits@393 d=516 | calls=5 | `generated/source_recovery/game_ovr_payload/0000_0385_FUN_0000_0385.c` |
| `items` | `medium` | `1000:eb60 FUN_1000_eb60` | 125800 | item0_loader@126462 d=662 | calls=6, memrefs=7 | `generated/source_recovery/game_ovr_payload/1000_eb60_FUN_1000_eb60.c` |
| `save_load` | `medium` | `1000:f67d FUN_1000_f67d` | 128645 | save_character@129547 d=902 | calls=17, memrefs=3 | `generated/source_recovery/game_ovr_payload/1000_f67d_FUN_1000_f67d.c` |
| `combat` | `medium` | `0000:fb92 FUN_0000_fb92` | 64410 | combat_start@65336 d=926 | calls=9, memrefs=31, strings= at sensor operation!Ship Character | `generated/source_recovery/game_ovr_payload/0000_fb92_FUN_0000_fb92.c` |
| `shop` | `low` | `1000:ce56 FUN_1000_ce56` | 118366 | shop_menu@117370 d=996 |  | `generated/source_recovery/game_ovr_payload/1000_ce56_FUN_1000_ce56.c` |
| `character_sheet` | `low` | `2000:25a1 FUN_2000_25a1` | 140713 | character_sheet_labels@139303 d=1410 | calls=2 | `generated/source_recovery/game_ovr_payload/2000_25a1_FUN_2000_25a1.c` |
| `inventory`, `items` | `low` | `2000:3ea6 FUN_2000_3ea6` | 147118 | item_debug_fields@143848 d=3270, gear_menu@145587 d=1531 |  | `generated/source_recovery/game_ovr_payload/2000_3ea6_FUN_2000_3ea6.c` |
| `save_load` | `low` | `2000:1c53 FUN_2000_1c53` | 138331 | save_game@136472 d=1859 |  | `generated/source_recovery/game_ovr_payload/2000_1c53_FUN_2000_1c53.c` |
| `map_loader`, `wall_loader` | `low` | `3000:006f FUN_3000_006f` | 196727 | wall_loader_wall_def_1@198845 d=2118, wall_loader_wall_def_2@198880 d=2153, load3dmap_geo@199334 d=2607, load3dmap_error@199365 d=2638 | calls=39, strings=ls at sensor operation!Ship Character | `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c` |
| `inventory`, `items` | `low` | `2000:2986 FUN_2000_2986` | 141710 | item_debug_fields@143848 d=2138, gear_menu@145587 d=3877 | calls=3, memrefs=1 | `generated/source_recovery/game_ovr_payload/2000_2986_FUN_2000_2986.c` |
| `character_creation` | `low` | `1000:8e7d FUN_1000_8e7d` | 102021 | character_creation@99509 d=2512 | memrefs=10 | `generated/source_recovery/game_ovr_payload/1000_8e7d_FUN_1000_8e7d.c` |
| `shop` | `low` | `1000:c010 FUN_1000_c010` | 114712 | shop_menu@117370 d=2658 | calls=2, memrefs=6 | `generated/source_recovery/game_ovr_payload/1000_c010_FUN_1000_c010.c` |
| `save_load` | `low` | `1000:fb92 FUN_1000_fb92` | 129946 | load_game@134527 d=4581 | calls=9, memrefs=1 | `generated/source_recovery/game_ovr_payload/1000_fb92_FUN_1000_fb92.c` |

## Role Meanings

- `anchor`: near a known project text/data anchor; role remains unspecified.
- `character_creation`: candidate character creation or character setup function.
- `character_sheet`: candidate character-sheet display/status function.
- `combat`: candidate combat subsystem entry/support function.
- `inventory`: candidate inventory or gear menu function.
- `items`: candidate item catalog, item detail, or inventory data function.
- `map_loader`: candidate GEO/Load3DMap loader or nearby loader-boundary function.
- `save_load`: candidate save/load persistence function.
- `ship`: candidate ship status/travel-resource function.
- `shop`: candidate shop/menu transaction function.
- `wall_loader`: candidate first-person wall or WALLDEF loader function.

## Limits

- Roles are hypotheses for triage, not recovered original function names.
- Anchor proximity does not prove ownership.
- Raw GAME.OVR pseudocode still lacks overlay relocation/manager context.
- Runtime behavior must be validated before implementation changes.
