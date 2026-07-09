# Source Recovery Function Role Resolution

This resolves the 23 GAME.OVR role hypotheses into static triage decisions.
Resolved here means no longer unknown; it does not mean runtime-validated.

## Summary

- Candidates: `23`
- Resolved static decisions: `23`
- Status counts: `{'resolved_bad_decode': 2, 'resolved_static': 18, 'resolved_stub_or_boundary': 3}`

## Resolutions

| Status | Resolved role | Function | Offset | Summary | Use | File |
|---|---|---|---:|---|---|---|
| `resolved_static` | `overlay_startup_state_init` | `0000:016c FUN_0000_016c` | 372 | Calls a shared initializer, sets global flag 0x4417, and copies global mode/state byte 0x3ddb into 0x50d2. | Use as evidence for overlay/global state initialization, not as a credits routine. | `generated/source_recovery/game_ovr_payload/0000_016c_FUN_0000_016c.c` |
| `resolved_bad_decode` | `bad_decode_or_mixed_code_data_near_credits_anchor` | `0000:0385 FUN_0000_0385` | 909 | Ghidra reports overlapping instructions, bad instruction data, abnormal stack setup, and removed blocks. | Do not lift this pseudocode; treat the address as a bad entry or mixed code/data island. | `generated/source_recovery/game_ovr_payload/0000_0385_FUN_0000_0385.c` |
| `resolved_static` | `combat_roster_and_battlefield_setup` | `0000:fb92 FUN_0000_fb92` | 64410 | Initializes combat tables, walks the party linked list, records combatant pointers, status/facing, visibility, and battlefield placement entries. | Use to validate combat start roster construction and initial placement logic. | `generated/source_recovery/game_ovr_payload/0000_fb92_FUN_0000_fb92.c` |
| `resolved_stub_or_boundary` | `empty_combat_boundary_candidate` | `1000:0131 FUN_1000_0131` | 65849 | Decompiles to a tiny return-only function near the combat_start anchor. | Do not lift as combat logic; keep as possible boundary, padding, or misidentified function start. | `generated/source_recovery/game_ovr_payload/1000_0131_FUN_1000_0131.c` |
| `resolved_static` | `character_record_initial_field_fill` | `1000:8467 FUN_1000_8467` | 99439 | Loops 0x55 bytes, calls a byte-producing helper, and writes into the active character record at offset +0x4d onward. | Use to validate character-creation default/stat/equipment field initialization. | `generated/source_recovery/game_ovr_payload/1000_8467_FUN_1000_8467.c` |
| `resolved_static` | `character_roster_remove_and_compact` | `1000:8e7d FUN_1000_8e7d` | 102021 | If a roster/entry marker equals 7, removes an entry and compacts subsequent character indices while decrementing the active count. | Use to validate character removal or rejected-created-character roster compaction. | `generated/source_recovery/game_ovr_payload/1000_8e7d_FUN_1000_8e7d.c` |
| `resolved_static` | `shop_item_grant_or_inventory_insert` | `1000:c010 FUN_1000_c010` | 114712 | Builds item records from table bytes, links them into the active character inventory list, and marks an item flag bit. | Use to validate shop purchase/reward item insertion. | `generated/source_recovery/game_ovr_payload/1000_c010_FUN_1000_c010.c` |
| `resolved_stub_or_boundary` | `empty_shop_boundary_candidate` | `1000:ce56 FUN_1000_ce56` | 118366 | Decompiles to a tiny return-only function near the shop_menu anchor. | Do not lift as shop logic; likely boundary/padding or bad function start. | `generated/source_recovery/game_ovr_payload/1000_ce56_FUN_1000_ce56.c` |
| `resolved_static` | `item_type_classification_dispatch` | `1000:eb60 FUN_1000_eb60` | 125800 | Reads an item type byte from the loaded item table and dispatches item classes 1..6 through FUN_1000_cf61; otherwise advances the item pointer. | Use to validate ITEM0 category mapping and item-detail decode. | `generated/source_recovery/game_ovr_payload/1000_eb60_FUN_1000_eb60.c` |
| `resolved_static` | `equipment_flag_postprocess_or_active_item_refresh` | `1000:eeec FUN_1000_eeec` | 126708 | Checks equipment/status flags at 0x8c33..0x8c3a, clears them, updates globals, and calls display/result helpers. | Use as evidence for post-item/equipment state refresh, not base item loading. | `generated/source_recovery/game_ovr_payload/1000_eeec_FUN_1000_eeec.c` |
| `resolved_static` | `save_slot_or_filename_selection_validation` | `1000:f67d FUN_1000_f67d` | 128645 | Uses large stack buffers, menu/input/file helper calls, and returns a success flag after validating selected save/character output. | Use to validate save-character/save-slot prompting and file validation. | `generated/source_recovery/game_ovr_payload/1000_f67d_FUN_1000_f67d.c` |
| `resolved_static` | `save_character_or_save_game_writer_preflight` | `1000:fad0 FUN_1000_fad0` | 129752 | Calls the save selection helper, computes serialized linked-list sizes, copies party/character state, checks output size, and branches into write/error routines. | Use to validate save serialization sizing and character-state fields. | `generated/source_recovery/game_ovr_payload/1000_fad0_FUN_1000_fad0.c` |
| `resolved_static` | `save_linked_item_chain_writer_continuation` | `1000:fb92 FUN_1000_fb92` | 129946 | Walks a linked chain at character offsets 0xfb/0xfd in 9-byte increments and calls save/write helpers, including the save writer. | Use to validate serialized item-chain layout. | `generated/source_recovery/game_ovr_payload/1000_fb92_FUN_1000_fb92.c` |
| `resolved_static` | `save_serialized_party_size_calculator` | `2000:13fd FUN_2000_13fd` | 136197 | Walks party members and nested linked item/equipment chains to compute serialized save size using 0x103, 0x3e, and 9-byte record increments. | Use to validate save sizing before save/load byte-format work. | `generated/source_recovery/game_ovr_payload/2000_13fd_FUN_2000_13fd.c` |
| `resolved_stub_or_boundary` | `empty_save_boundary_candidate` | `2000:1c53 FUN_2000_1c53` | 138331 | Decompiles to a tiny return-only function near the save_game anchor. | Do not lift as save logic; keep as boundary/padding candidate. | `generated/source_recovery/game_ovr_payload/2000_1c53_FUN_2000_1c53.c` |
| `resolved_static` | `character_inventory_chain_count` | `2000:1fd4 FUN_2000_1fd4` | 139228 | Counts linked records from a character pointer at offsets 0xf7/0xf9 by following +0x2a/+0x2c next pointers. | Use to validate character sheet inventory counts. | `generated/source_recovery/game_ovr_payload/2000_1fd4_FUN_2000_1fd4.c` |
| `resolved_static` | `character_sheet_text_or_buffer_emit_helper` | `2000:25a1 FUN_2000_25a1` | 140713 | Calls a display/setup helper and copies up to 0xff bytes into a local text/display buffer. | Use as character-sheet display helper evidence only. | `generated/source_recovery/game_ovr_payload/2000_25a1_FUN_2000_25a1.c` |
| `resolved_static` | `inventory_item_line_formatter` | `2000:2986 FUN_2000_2986` | 141710 | Chooses display attribute 0x0d/0x0f, fetches item-related text/data through FUN_0000_733e, and writes a short display buffer. | Use to validate inventory/gear list line rendering. | `generated/source_recovery/game_ovr_payload/2000_2986_FUN_2000_2986.c` |
| `resolved_static` | `equipped_item_category_search` | `2000:3ea6 FUN_2000_3ea6` | 147118 | Walks a character item chain, filters equipped/flagged records, and returns the first item whose category table entry matches the requested category. | Use to validate equipped item lookup by item category. | `generated/source_recovery/game_ovr_payload/2000_3ea6_FUN_2000_3ea6.c` |
| `resolved_static` | `ship_effective_rating_with_damage_penalties` | `2000:b749 FUN_2000_b749` | 178001 | Checks whether a ship/vehicle record is valid, adds active/alternate modifiers, applies damage penalties, and clamps the result to at least 1. | Use to validate ship movement/maneuver/status derived values. | `generated/source_recovery/game_ovr_payload/2000_b749_FUN_2000_b749.c` |
| `resolved_static` | `ship_status_flag_and_message_emit` | `2000:b876 FUN_2000_b876` | 178302 | Sets global ship status flag 0x535b based on mode and ship record state, calls a UI helper, then emits a message/display block. | Use to validate ship status UI and travel gating. | `generated/source_recovery/game_ovr_payload/2000_b876_FUN_2000_b876.c` |
| `resolved_static` | `wall_segment_decode_or_emit_routine` | `3000:006f FUN_3000_006f` | 196727 | Runs repeated 4/3/2-count loops over byte-producing helpers and emit helpers, matching a span/segment decode pattern before the WALLDEF/Load3DMap string/data region. | Use as candidate wall segment decoder/emitter. Raw disassembly resolves it as not the Load3DMap file-load/copy routine. | `generated/source_recovery/game_ovr_payload/3000_006f_FUN_3000_006f.c` |
| `resolved_bad_decode` | `misaligned_load3dmap_epilogue_entry` | `3000:0c04 FUN_3000_0c04` | 199692 | Ghidra entry 3000:0c04 lands inside the instruction at payload 0x30C01 in the Load3DMap-shaped routine epilogue, so the tiny return decompile is a misaligned-entry artifact. | Do not lift as a function. The resolved Load3DMap-shaped code window is payload 0x30AD0-0x30C10. | `generated/source_recovery/game_ovr_payload/3000_0c04_FUN_3000_0c04.c` |

## Validation Next Steps

- `0000:016c overlay_startup_state_init`: Find callers around overlay entry and compare 0x4417/0x50d2 meanings against runtime state transitions.
- `0000:0385 bad_decode_or_mixed_code_data_near_credits_anchor`: Inspect raw bytes and Ghidra disassembly manually before assigning any behavior.
- `0000:fb92 combat_roster_and_battlefield_setup`: Compare combatant table counts and positions against a DOS combat capture.
- `1000:0131 empty_combat_boundary_candidate`: Check neighboring raw bytes and cross-references before deleting from the combat cluster.
- `1000:8467 character_record_initial_field_fill`: Compare generated character records after DOS character creation with reconstructed defaults.
- `1000:8e7d character_roster_remove_and_compact`: Capture DOS behavior for deleting/dropping a created character and compare roster order.
- `1000:c010 shop_item_grant_or_inventory_insert`: Compare inventory linked-list changes after buying known shop items.
- `1000:ce56 empty_shop_boundary_candidate`: Inspect neighboring shop-menu code and xrefs.
- `1000:eb60 item_type_classification_dispatch`: Compare dispatch buckets against decoded ITEM0 names and item detail records.
- `1000:eeec equipment_flag_postprocess_or_active_item_refresh`: Trigger equip/unequip/use flows in DOS and compare flags/UI side effects.
- `1000:f67d save_slot_or_filename_selection_validation`: Compare DOS save prompts and invalid-slot behavior.
- `1000:fad0 save_character_or_save_game_writer_preflight`: Compare produced SAVGAMA/character-save byte lengths and selected offsets.
- `1000:fb92 save_linked_item_chain_writer_continuation`: Compare saved inventory/equipment item-chain bytes against DOS saves.
- `2000:13fd save_serialized_party_size_calculator`: Assert computed size against known DOS save samples.
- `2000:1c53 empty_save_boundary_candidate`: Inspect adjacent save-game bytes and xrefs.
- `2000:1fd4 character_inventory_chain_count`: Compare count with visible character sheet inventory slots.
- `2000:25a1 character_sheet_text_or_buffer_emit_helper`: Trace caller context and compare emitted text in DOS character sheet.
- `2000:2986 inventory_item_line_formatter`: Compare inventory line highlighting/equipped markers in DOS.
- `2000:3ea6 equipped_item_category_search`: Compare weapon/armor selection effects against item category table.
- `2000:b749 ship_effective_rating_with_damage_penalties`: Compare ship stats before and after hull/system damage in DOS.
- `2000:b876 ship_status_flag_and_message_emit`: Compare status/message display for active ship versus alternate target.
- `3000:006f wall_segment_decode_or_emit_routine`: Trace helper xrefs and compare emitted sequence against WALLDEF rendering artifacts.
- `3000:0c04 misaligned_load3dmap_epilogue_entry`: Use generated/source_recovery/load3dmap_cluster_resolution.md before making map-loader runtime changes.
