# GAME.OVR Raw GEO Map Scan

This is a conservative structural scan for plain, uncompressed GEO-shaped map blocks inside `GAME.OVR`.

## Inputs

- GAME.OVR: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/GAME.OVR`
- GAME.OVR bytes: `212529`
- GAME.OVR SHA-256: `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`
- Known GEO source: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/GEO1.DAX`
- Known GEO block count: `25`
- Known GEO block sizes: `{'1026': 25}`

## Local GEO/ECL Inventory

- `ECL1.DAX`: `254032` bytes, SHA-256 `5330bb436b3cac474506265db90cb3e0a888d7a9e5b0b65051d302035b60d854`
- `GEO1.DAX`: `21280` bytes, SHA-256 `398bab0120f5d16102aa121178d8f10d932a8db2bc23d96cb615dc6bb1171598`

The current local source folder has no `GEO2.DAX`, `GEO3.DAX`, `GEO4.DAX`, `ECL2.DAX`, `ECL3.DAX`, or `ECL4.DAX` files.

## Result

- Exact known GEO1 block copies found in GAME.OVR: `0` of `25`
- Raw 1026-byte windows with a known GEO header: `2`
- Accepted GEO-shaped raw-window candidates: `0`

No raw overlay window satisfied the established GEO1 structural filters. This is negative evidence only: it means this pass did not find plain GEO blocks embedded in `GAME.OVR`; it does not prove maps cannot be loaded indirectly, generated in memory, or stored in a compressed/segmented form.

## Header Hits

- `0x0DA9A` header `01 11`: door_ratio `0.3359`, event_ratio `0.6094`, NS `0.0375`, EW `0.05` — door bytes do not match the established GEO1 door-value set; too many event ids exceed the established GEO1 event range; north/south wall continuity is below the GEO1 minimum; east/west wall continuity is below the GEO1 minimum; wall-density is outside the GEO1 observed range
- `0x2C3B7` header `01 11`: door_ratio `0.1484`, event_ratio `0.5508`, NS `0.0958`, EW `0.1` — door bytes do not match the established GEO1 door-value set; too many event ids exceed the established GEO1 event range; north/south wall continuity is below the GEO1 minimum; east/west wall continuity is below the GEO1 minimum; wall-density is outside the GEO1 observed range

## Loader/String Anchors

- `0x1D389` `.dax`: `~. u.1..F....F..F..y..>.D..&......~..u...]..ECL..daxU.......F.........P0.1.RP1.P.~..W...P..........W....W......~..W.O........W....W......F.P.~..`
- `0x1EE04` `.dax`: `8D.t...P..P.&P..P......6.W.6.W.*.....]....ITEM0..dax.Unable to find item fileU....2..X.W...P..P......~..W....W......~..W....W.......P.~..W.~..W.`
- `0x208BD` `.dax`: `...~..W....W......F.P.~.&....P./.....]....0.CHA..dax.Unable to load Monster.SPC.ITMU.......~..W.....W...P.........W.....W...P..........W.....W..`
- `0x21ACB` `.dax`: `....3.&....&......3...5..n....R........]..ships..dax.Maelstrom Rider. U............~..W..).W......~..W..).W......F...(.P.~..W.~..W......~..W.~..`
- `0x2EE51` `.dax`: `v..F.0..........s...s......0.X...]....PIC.7.8.9..dax.PIC not foundU....8..~..W.~..W...P......~..u..:..~..W.6t.W.....u@.F.:.Htu7.>~s.t....P.P.P..`
- `0x308BD` `WALLDEF`: `P.dsP....W......~..W.F.P..P.dsP....W.......]....WALLDEF..dax.Unable to load . from WALLDEF..U.......~..v......P0.1.RP1.P.~..W...P..........W....`
- `0x308C5` `.dax`: `.W......~..W.F.P..P.dsP....W.......]....WALLDEF..dax.Unable to load . from WALLDEF..U.......~..v......P0.1.RP1.P.~..W...P..........W....W......~`
- `0x308E0` `WALLDEF`: `W.......]....WALLDEF..dax.Unable to load . from WALLDEF..U.......~..v......P0.1.RP1.P.~..W...P..........W....W......~..W.O........W....W......F.`
- `0x30AA6` `GEO`: `0....F.0.........ns.F.0....F.0.........ps..]....GEO..dax Unable to load geo in Load3DMap.U........P0.1.RP1.P.~..W...P..........W....W......~..W.`
- `0x30AAA` `.dax`: `.F.0.........ns.F.0....F.0.........ps..]....GEO..dax Unable to load geo in Load3DMap.U........P0.1.RP1.P.~..W...P..........W....W......~..W.O...`
- `0x30AC5` `Load3DMap`: `........ps..]....GEO..dax Unable to load geo in Load3DMap.U........P0.1.RP1.P.~..W...P..........W....W......~..W.O........W....W......F.P.~..W.~`

## Next Validation

- Trace the `Load3DMap`/GEO loader in `GAME.OVR` around the `GEO` and `.dax` anchors to identify how the DAX suffix/index is selected.
- Obtain any missing original disk/install files if they exist; the current local source folder contains `GEO1.DAX` only.
