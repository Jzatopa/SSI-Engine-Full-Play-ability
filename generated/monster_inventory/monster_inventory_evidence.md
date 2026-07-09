# Monster Inventory Evidence

Every decoded MON0ITM block is divisible into 62-byte records. The trailing 16 bytes at record offset 46 have ITEM0-shaped values, and only byte-for-byte ITEM0 matches at that structural offset are promoted. The first 46 bytes and non-exact trailing payloads remain unresolved; absence of an exact match does not mean a monster has no inventory. Supplied STF saves use the same 62-byte record boundary and trailing payload position. Original GAME.OVR proves record offset 0x34 bit 0x80 as the equipped flag and record offset 0x38 as a stack quantity; these are payload offsets 6 and 10. A unique ITEM0 match across every other payload byte is therefore promoted, while records differing in any other byte remain unresolved.

- records: 143
- exact aligned ITEM0 matches: 18
- stable-field ITEM0 matches: 64 (46 newly recovered)
- saved STF records: 27 across 5 files
- saved STF exact ITEM0 matches: 15
- layout: 62 bytes = 46-byte unresolved prefix + 16-byte item payload

| Monster | Size | Records | Stable-field ITEM0 matches |
|---:|---:|---:|---|
| 1 | 372 | 6 | record 1: template 17 / equipped true / quantity 2, record 2: template 2 / equipped false / quantity 0, record 3: template 23 / equipped true / quantity 0, record 4: template 34 / equipped false / quantity 2, record 5: template 24 / equipped false / quantity 2 |
| 2 | 124 | 2 | record 0: template 16 / equipped true / quantity 10 |
| 3 | 124 | 2 | none |
| 4 | 62 | 1 | none |
| 5 | 434 | 7 | record 0: template 25 / equipped true / quantity 0, record 1: template 26 / equipped true / quantity 0, record 2: template 12 / equipped true / quantity 14, record 3: template 36 / equipped false / quantity 2, record 4: template 32 / equipped false / quantity 1, record 5: template 7 / equipped false / quantity 0, record 6: template 21 / equipped true / quantity 0 |
| 6 | 372 | 6 | record 0: template 42 / equipped true / quantity 20, record 1: template 32 / equipped false / quantity 1, record 3: template 36 / equipped false / quantity 2, record 4: template 7 / equipped false / quantity 0, record 5: template 20 / equipped true / quantity 0 |
| 7 | 186 | 3 | record 0: template 5 / equipped true / quantity 50, record 1: template 21 / equipped true / quantity 0, record 2: template 1 / equipped false / quantity 0 |
| 8 | 186 | 3 | none |
| 12 | 186 | 3 | record 1: template 32 / equipped false / quantity 2 |
| 13 | 248 | 4 | record 0: template 21 / equipped true / quantity 0, record 1: template 17 / equipped false / quantity 10, record 2: template 31 / equipped false / quantity 2 |
| 14 | 248 | 4 | record 1: template 32 / equipped false / quantity 2, record 2: template 7 / equipped false / quantity 0 |
| 15 | 248 | 4 | record 1: template 32 / equipped false / quantity 2 |
| 16 | 248 | 4 | record 2: template 34 / equipped false / quantity 2, record 3: template 31 / equipped false / quantity 1 |
| 17 | 124 | 2 | none |
| 19 | 248 | 4 | record 3: template 36 / equipped false / quantity 3 |
| 20 | 248 | 4 | record 3: template 32 / equipped false / quantity 3 |
| 21 | 124 | 2 | none |
| 23 | 186 | 3 | none |
| 29 | 186 | 3 | none |
| 30 | 62 | 1 | none |
| 31 | 186 | 3 | record 2: template 6 / equipped false / quantity 0 |
| 33 | 310 | 5 | record 1: template 20 / equipped true / quantity 0, record 2: template 35 / equipped false / quantity 1, record 3: template 2 / equipped false / quantity 0, record 4: template 25 / equipped true / quantity 0 |
| 35 | 248 | 4 | none |
| 38 | 124 | 2 | none |
| 43 | 248 | 4 | none |
| 44 | 310 | 5 | record 3: template 37 / equipped false / quantity 2 |
| 45 | 186 | 3 | none |
| 46 | 186 | 3 | record 0: template 38 / equipped true / quantity 0, record 1: template 21 / equipped true / quantity 0, record 2: template 32 / equipped false / quantity 1 |
| 48 | 124 | 2 | none |
| 49 | 248 | 4 | none |
| 50 | 186 | 3 | record 2: template 34 / equipped false / quantity 2 |
| 51 | 248 | 4 | record 1: template 15 / equipped true / quantity 0, record 2: template 35 / equipped true / quantity 2, record 3: template 32 / equipped false / quantity 1 |
| 52 | 310 | 5 | record 0: template 49 / equipped true / quantity 50, record 2: template 26 / equipped true / quantity 0, record 3: template 39 / equipped false / quantity 0, record 4: template 24 / equipped false / quantity 2 |
| 53 | 124 | 2 | none |
| 54 | 248 | 4 | record 0: template 41 / equipped true / quantity 0, record 2: template 42 / equipped true / quantity 150, record 3: template 32 / equipped false / quantity 2 |
| 55 | 186 | 3 | record 2: template 34 / equipped false / quantity 10 |
| 57 | 62 | 1 | none |
| 58 | 310 | 5 | record 0: template 21 / equipped true / quantity 0, record 1: template 47 / equipped true / quantity 100, record 3: template 32 / equipped false / quantity 1, record 4: template 7 / equipped false / quantity 0 |
| 59 | 248 | 4 | record 0: template 21 / equipped true / quantity 0, record 1: template 9 / equipped true / quantity 10, record 2: template 1 / equipped false / quantity 0, record 3: template 6 / equipped false / quantity 10 |
| 60 | 186 | 3 | record 0: template 4 / equipped true / quantity 250, record 1: template 21 / equipped true / quantity 0, record 2: template 7 / equipped false / quantity 0 |
| 61 | 186 | 3 | none |
| 62 | 186 | 3 | none |
