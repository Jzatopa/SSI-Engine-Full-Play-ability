# Gold Box Explorer Matrix Cubed Map Audit

This audit compares the local `GEO*.DAX` files against Gold Box Explorer's
`MatrixCubed` map-name table. It uses Gold Box Explorer as a reference,
but does not require running its Windows GUI.

## Summary

- Game directory: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX`
- Gold Box Explorer source: `/home/jzatopa/Downloads/goldboxexplorer/Common/Plugins/GeoDax/GeoDaxFile.cs`
- Local GEO archives present: GEO1.DAX
- Local ECL archives present: ECL1.DAX
- Local decoded GEO blocks: 25
- Gold Box Explorer named Matrix Cubed maps: 24
- Gold Box Explorer named map IDs missing locally: []
- Local GEO IDs missing Gold Box Explorer names: [21]

## Interpretation

- Gold Box Explorer's Matrix Cubed map table does not identify any named map absent from the local `GEO1.DAX`.
- The only local GEO block without a Gold Box Explorer name is GEO 21, matching prior local notes.
- The current local source set has no `GEO2.DAX`, `GEO3.DAX`, `GEO4.DAX`, `ECL2.DAX`, `ECL3.DAX`, or `ECL4.DAX`.
- This supports treating the 25 decoded `GEO1.DAX` blocks as all map blocks available in the current source set, while leaving room for future evidence from another disk image or installer.

## Gold Box Explorer Named Maps

| GEO | Name | Present locally |
|---:|---|---|
| 1 | Luna Base | True |
| 17 | Caloris Space Port | True |
| 18 | Asteroid | True |
| 33 | Losangelorg Sprawls | True |
| 34 | Historical Museum, Levels 2-1 | True |
| 35 | Asteroid Base | True |
| 38 | Losangelorg Sprawls | True |
| 49 | Lowlander Village | True |
| 50 | Venus Laboratory, Level 1 | True |
| 51 | Venus Laboratory, Level 2 | True |
| 52 | Lowlander Mines | True |
| 64 | Luna Base | True |
| 65 | Tsai Weaponry Labs | True |
| 66 | RAM Battler, Deimos Level 19-41 | True |
| 80 | Mars Prison, Level 1 | True |
| 81 | PURGE Headquarters, Floors Ground-Upper | True |
| 82 | NEO Installation | True |
| 84 | Mars Prison, Level 2 | True |
| 96 | Living Ship | True |
| 97 | Living Ship | True |
| 112 | Stormrider University | True |
| 113 | Genetics Foundation Building, Levels 1-4 | True |
| 114 | Jupiter Finale | True |
| 115 | Jupiter Aircar | True |

## Local GEO Blocks

| Archive | GEO | Decoded bytes | Gold Box Explorer name |
|---|---:|---:|---|
| GEO1.DAX | 1 | 1026 | Luna Base |
| GEO1.DAX | 17 | 1026 | Caloris Space Port |
| GEO1.DAX | 18 | 1026 | Asteroid |
| GEO1.DAX | 21 | 1026 |  |
| GEO1.DAX | 33 | 1026 | Losangelorg Sprawls |
| GEO1.DAX | 34 | 1026 | Historical Museum, Levels 2-1 |
| GEO1.DAX | 35 | 1026 | Asteroid Base |
| GEO1.DAX | 38 | 1026 | Losangelorg Sprawls |
| GEO1.DAX | 49 | 1026 | Lowlander Village |
| GEO1.DAX | 50 | 1026 | Venus Laboratory, Level 1 |
| GEO1.DAX | 51 | 1026 | Venus Laboratory, Level 2 |
| GEO1.DAX | 52 | 1026 | Lowlander Mines |
| GEO1.DAX | 64 | 1026 | Luna Base |
| GEO1.DAX | 65 | 1026 | Tsai Weaponry Labs |
| GEO1.DAX | 66 | 1026 | RAM Battler, Deimos Level 19-41 |
| GEO1.DAX | 80 | 1026 | Mars Prison, Level 1 |
| GEO1.DAX | 81 | 1026 | PURGE Headquarters, Floors Ground-Upper |
| GEO1.DAX | 82 | 1026 | NEO Installation |
| GEO1.DAX | 84 | 1026 | Mars Prison, Level 2 |
| GEO1.DAX | 96 | 1026 | Living Ship |
| GEO1.DAX | 97 | 1026 | Living Ship |
| GEO1.DAX | 112 | 1026 | Stormrider University |
| GEO1.DAX | 113 | 1026 | Genetics Foundation Building, Levels 1-4 |
| GEO1.DAX | 114 | 1026 | Jupiter Finale |
| GEO1.DAX | 115 | 1026 | Jupiter Aircar |
