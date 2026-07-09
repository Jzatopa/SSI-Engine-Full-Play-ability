# Map Traversal Reference

This report records decoded traversal evidence from GEO cells and ECL `LOAD FILES Load GEO` instructions.

## Summary

- Loaded maps: 25
- ECL load rows: 26
- Loaded ECL targets: 19
- Cell edge rows: 194
- Loaded cell targets: 5
- Covered loaded maps: 20
- Uncovered loaded maps: 51, 80, 82, 113, 115
- Evidence limit: ECL LOAD FILES rows prove map load targets, not complete player route conditions. Cell edges are only promoted when the target is an already decoded GEO map.

## ECL Loads

| ECL | Address | Target | Loaded | X | Y |
|---:|---|---:|---|---:|---:|
| 1 | `0x808E` | `1` | `True` | 9 | 4 |
| 17 | `0x805E` | `17` | `True` |  |  |
| 18 | `0x8032` | `18` | `True` |  |  |
| 19 | `0x8051` | `17` | `True` |  |  |
| 21 | `0x8058` | `21` | `True` |  |  |
| 24 | `0x803E` | `64` | `True` | 13 | 8 |
| 32 | `0x804B` | `127` | `False` |  |  |
| 34 | `0x8063` | `34` | `True` | 7 | 15 |
| 35 | `0x802E` | `35` | `True` | 4 | 15 |
| 38 | `0x8052` | `38` | `True` |  |  |
| 48 | `0x8031` | `127` | `False` |  |  |
| 49 | `0x8051` | `49` | `True` |  |  |
| 49 | `0x80FE` | `52` | `True` | 15 | 3 |
| 49 | `0x834D` | `49` | `True` |  |  |
| 50 | `0x8047` | `50` | `True` |  |  |
| 64 | `0x803A` | `64` | `True` | 11 | 15 |
| 65 | `0x8040` | `65` | `True` | 5 | 15 |
| 66 | `0x8034` | `66` | `True` | 15 | 13 |
| 80 | `0x8052` | `84` | `True` |  |  |
| 81 | `0x8057` | `81` | `True` |  |  |
| 96 | `0x808F` | `96` | `True` |  | 0 |
| 97 | `0x80A5` | `97` | `True` |  | 15 |
| 97 | `0x80E9` | `96` | `True` | 1 | 11 |
| 112 | `0x8058` | `112` | `True` |  |  |
| 114 | `0x8034` | `114` | `True` | 7 | 4 |
| 114 | `0x81B9` | `area2.event_scratch0` | `False` |  |  |

## Promoted Cell Edges

| Source | Cell | Target | Interpretation |
|---|---|---:|---|
| GEO 001 Luna Base | 2,4 | 33 | promoted_transition |
| GEO 001 Luna Base | 11,3 | 21 | promoted_transition |
| GEO 033 Losangelorg Sprawls | 1,12 | 1 | promoted_transition |
| GEO 033 Losangelorg Sprawls | 4,11 | 1 | promoted_transition |
| GEO 033 Losangelorg Sprawls | 6,9 | 18 | promoted_transition |
| GEO 033 Losangelorg Sprawls | 6,14 | 18 | promoted_transition |
| GEO 033 Losangelorg Sprawls | 7,13 | 21 | promoted_transition |
| GEO 064 Luna Base | 2,4 | 33 | promoted_transition |
| GEO 064 Luna Base | 11,3 | 21 | promoted_transition |
| GEO 084 Mars Prison, Level 2 | 7,8 | 1 | promoted_transition |
| GEO 084 Mars Prison, Level 2 | 10,9 | 21 | promoted_transition |
| GEO 112 Stormrider University | 0,5 | 34 | promoted_transition |
| GEO 112 Stormrider University | 1,5 | 34 | promoted_transition |
| GEO 112 Stormrider University | 1,6 | 34 | promoted_transition |
| GEO 112 Stormrider University | 4,3 | 34 | promoted_transition |
| GEO 112 Stormrider University | 4,4 | 34 | promoted_transition |
| GEO 112 Stormrider University | 5,3 | 34 | promoted_transition |
| GEO 112 Stormrider University | 5,4 | 1 | promoted_transition |
| GEO 112 Stormrider University | 6,15 | 33 | promoted_transition |
