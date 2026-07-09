# ITEM Name Mapping Evidence

This report records the local evidence used to resolve ITEM0 name-code triples into item names.

## Inputs

- ITEMS: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/ITEMS`
- ITEMS bytes: `351`
- ITEM0 templates: `generated/data_model/item0_templates.json`
- ITEM0 template count: `91`
- START.EXE: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/START.EXE`

## Result

- START.EXE item-name codes including blank code 0: `46`
- ITEM0 records with decoded names: `91`
- ITEM0 records with unmapped name codes: `0`
- ITEM0 records missing ITEMS detail rows: `0`
- Unique ITEM0 item pointers: `38`

Item names are decoded, and the ITEMS side-file blocker is narrowed: the table is now aligned as a 1-based itemptr detail table. Some detail semantics remain candidates, but non-name item fields no longer need to be treated as unaligned or untraceable.

## Evidence Chain

- Gold Box / FRUA item records store item pointer, name code 3, name code 2, name code 1 in the first four bytes.
- Local ITEM0.DAX records have the same 16-byte shape and use nonzero values in bytes 1..3 as name-code triples.
- Local START.EXE contains a contiguous Pascal-style item-name literal table from Knife through BLANK ITEM.
- GAME.OVR indexes the local ITEMS side file with itemptr * 9 and reads detail bytes from 0x5370, 0x5372, 0x5373, 0x5374, 0x5375, and 0x5376 plus that product.

## First Decoded ITEM0 Names

| index | itemptr | name codes | decoded name | raw bytes |
|---:|---:|---|---|---|
| 0 | 1 | `[1, 0, 0]` | Knife | `01 00 00 01 00 00 20 00 01 00 00 0a 00 00 00 00` |
| 1 | 2 | `[2, 1, 0]` | Mono Knife | `02 00 01 02 00 00 20 00 01 00 00 c8 00 00 00 00` |
| 2 | 3 | `[3, 0, 0]` | Cutlass | `03 00 00 03 00 00 20 00 04 00 00 64 00 00 00 00` |
| 3 | 4 | `[4, 0, 0]` | Sword | `04 00 00 04 00 00 20 00 06 00 00 96 00 00 00 00` |
| 4 | 5 | `[5, 0, 0]` | D.R. X-bow | `05 00 00 05 00 00 20 00 04 00 0a 6e 00 00 00 00` |
| 5 | 6 | `[6, 7, 0]` | Needle Gun | `06 00 07 06 00 00 20 00 03 00 0a d2 00 00 00 00` |
| 6 | 7 | `[8, 7, 0]` | Bolt Gun | `07 00 07 08 00 00 20 00 02 00 0a d2 00 00 00 00` |
| 7 | 8 | `[2, 4, 0]` | Mono Sword | `08 00 04 02 00 00 20 00 01 00 00 e8 03 00 00 00` |
| 8 | 9 | `[9, 10, 0]` | Laser Pistol | `09 00 0a 09 00 00 20 00 01 00 0a 4f 01 00 00 00` |
| 9 | 10 | `[11, 10, 0]` | Rocket Pistol | `0a 00 0a 0b 00 00 20 00 03 00 0a 90 01 00 00 00` |
| 10 | 11 | `[11, 13, 0]` | Rocket Rifle | `0b 00 0d 0b 00 00 20 00 06 00 0a 58 02 00 00 00` |
| 11 | 12 | `[12, 7, 0]` | Microwave Gun | `0c 00 07 0c 00 00 20 00 02 00 0a 90 01 00 00 00` |
| 12 | 13 | `[9, 13, 0]` | Laser Rifle | `0d 00 0d 09 00 00 20 00 05 00 0a 7b 02 00 00 00` |
| 13 | 14 | `[14, 7, 0]` | Heat Gun | `0e 00 07 0e 00 00 20 00 02 00 0a f4 01 00 00 00` |
| 14 | 15 | `[15, 0, 0]` | Sonic Stunner | `0f 00 00 0f 00 00 20 00 02 00 0a 7c 01 00 11 80` |
| 15 | 16 | `[16, 17, 0]` | Grenade Lnchr. | `10 00 11 10 00 00 20 00 03 00 00 f4 01 00 00 00` |
| 16 | 17 | `[18, 0, 0]` | Plasma Thrwr | `11 00 00 12 00 00 20 00 4b 00 0a 40 06 00 0a 80` |
| 17 | 18 | `[11, 17, 0]` | Rocket Lnchr. | `12 00 11 0b 00 00 20 00 32 00 0a d0 07 00 0b 80` |
| 18 | 19 | `[43, 0, 0]` | Polearm | `13 00 00 2b 00 00 20 00 04 00 00 78 00 00 00 00` |
| 19 | 20 | `[23, 0, 0]` | Spacesuit | `14 00 00 17 00 00 20 00 19 00 00 f4 01 00 00 00` |
| 20 | 21 | `[24, 0, 0]` | Smartsuit | `15 00 00 18 00 00 20 00 1e 00 00 b0 04 00 00 00` |
| 21 | 22 | `[25, 26, 0]` | Heavy Body Armor | `16 00 1a 19 00 00 20 00 23 00 00 a4 06 00 00 00` |
| 22 | 23 | `[27, 0, 0]` | Battle armor | `17 00 00 1b 00 00 20 00 4b 00 00 c4 09 00 00 00` |
| 23 | 24 | `[27, 28, 0]` | Battle armor w/fields | `18 00 1c 1b 00 00 20 00 50 00 00 b8 0b 00 00 00` |
| 24 | 25 | `[35, 0, 0]` | Demo Charge | `19 00 00 23 00 00 00 00 01 00 01 64 00 00 00 00` |
| 25 | 26 | `[36, 0, 0]` | ECM package | `1a 00 00 24 00 00 20 00 01 00 00 32 00 00 00 00` |
| 26 | 27 | `[37, 38, 0]` | Protective Goggles | `1b 00 26 25 00 00 20 00 01 00 00 0a 00 00 00 00` |
| 27 | 28 | `[39, 0, 0]` | Breathing Mask | `1c 00 00 27 00 00 20 00 01 00 00 28 00 00 00 00` |
| 28 | 29 | `[40, 0, 0]` | Rope | `1d 00 00 28 00 00 00 00 01 00 01 19 00 00 00 00` |
| 29 | 30 | `[41, 0, 0]` | Jetpack | `1e 00 00 29 00 00 20 00 0a 00 00 e8 03 00 00 00` |
| 30 | 31 | `[42, 0, 0]` | Poison Antidote | `1f 00 00 2a 00 00 00 00 00 00 01 90 01 00 00 00` |
| 31 | 32 | `[44, 29, 16]` | mini Explosive Grenade | `20 10 1d 2c 00 00 00 00 01 00 01 32 00 00 06 80` |
| 32 | 33 | `[29, 16, 0]` | Explosive Grenade | `21 00 10 1d 00 00 00 00 01 00 01 32 00 00 06 80` |
| 33 | 34 | `[30, 16, 0]` | Gas Grenade | `22 00 10 1e 00 00 00 00 01 00 01 32 00 00 07 80` |
| 34 | 35 | `[31, 16, 0]` | Stun Grenade | `23 00 10 1f 00 00 00 00 01 00 01 32 00 00 0c 80` |
| 35 | 36 | `[32, 16, 0]` | Dazzle Grenade | `24 00 10 20 00 00 00 00 01 00 01 32 00 00 05 80` |
| 36 | 37 | `[33, 16, 0]` | Chaff Grenade | `25 00 10 21 00 00 00 00 01 00 01 32 00 00 08 80` |
| 37 | 38 | `[34, 16, 0]` | Aerosol Mist Grenade | `26 00 10 22 00 00 00 00 01 00 01 32 00 00 09 80` |
| 38 | 2 | `[19, 2, 1]` | Martian Mono Knife | `02 01 02 13 01 00 20 00 01 00 00 90 01 00 00 00` |
| 39 | 3 | `[19, 3, 0]` | Martian Cutlass | `03 00 03 13 01 00 20 00 04 00 00 c8 00 00 00 00` |

## ITEMS Side File Check

- One ITEMS record per ITEM0 template possible: `False`
- ITEMS ASCII strings: `0`
- ITEMS Pascal-style string candidates: `0`

ITEMS is still not a direct text/name table.

## ITEMS Detail Layout

- Record size: `9` bytes
- Alignment: 1-based by ITEM0 itemptr; file record N is used by ITEM0 itemptr N
- Field status: partly semantic, partly candidate

### Proven Overlay Uses

- `0x5370 + itemptr*9` / byte `0`: type/category checks against values including 1, 7, 8, and 9
- `0x5372 + itemptr*9` / byte `2`: copied to runtime character/item field 0xdd and shown in item debug view
- `0x5373 + itemptr*9` / byte `3`: copied to runtime character/item field 0xdf and shown in item debug view
- `0x5374 + itemptr*9` / byte `4`: copied to runtime character/item field 0xe1 and shown in item debug view
- `0x5375 + itemptr*9` / byte `5`: used by item/combat checks; zero and 0xff are normalized to 1 in one routine
- `0x5376 + itemptr*9` / byte `6`: tested before dispatching a runtime item effect routine

### Candidate Field Names

- `type_code`: record byte 0
- `large_damage_candidate`: record bytes 0,1,2 as dice/sides/bonus candidate; byte 0 also has non-damage type-code uses
- `medium_damage_candidate`: record bytes 4,5,3 as dice/sides/bonus candidate; matches weapon rows such as Knife 1d3 and Laser Pistol 1d8
- `effect_or_bonus_candidate`: record byte 6
- `range_candidate`: record byte 7
- `flags_candidate`: record byte 8

## ITEMS Numeric Field Profile

- `u16_0`: unique `13`, range `0`-`3072`, zeros `1`, top `1024 (11), 512 (9), 1 (5), 2048 (3), 8 (3), 0 (1), 3072 (1), 1536 (1)`
- `u16_1`: unique `16`, range `0`-`265`, zeros `14`, top `0 (14), 8 (7), 1 (3), 3 (2), 2 (2), 4 (1), 5 (1), 6 (1)`
- `u16_2`: unique `12`, range `0`-`3073`, zeros `18`, top `0 (18), 2561 (4), 769 (3), 2049 (3), 1537 (2), 1025 (2), 2564 (2), 2050 (1)`
- `u16_3`: unique `13`, range `0`-`30720`, zeros `20`, top `0 (20), 768 (6), 4096 (3), 2048 (1), 3072 (1), 8192 (1), 20480 (1), 30720 (1)`
- `byte_8`: unique `2`, range `0`-`1`, zeros `32`, top `0 (32), 1 (7)`

## Remaining Caveat

The table alignment and several byte uses are now traced. Damage/range-like names remain candidate labels until a combat validation capture verifies original displayed damage/range values.
