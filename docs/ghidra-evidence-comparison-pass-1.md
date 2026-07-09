# Ghidra Evidence Comparison Pass 1

Date: 2026-06-26

## Scope

Compared Ghidra deep exports against existing START.EXE and GAME.OVR evidence artifacts.

The comparison script is:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/compare_ghidra_evidence.py
```

## Generated Artifacts

- `scripts/compare_ghidra_evidence.py`
- `generated/ghidra/comparison/ghidra_evidence_comparison.json`
- `generated/ghidra/comparison/ghidra_evidence_comparison.md`

## Address Mapping

For raw `GAME.OVR.payload_after_fbov_header.bin` imported into Ghidra:

```text
linear = segment * 16 + offset
original GAME.OVR file offset = linear + 8
```

Example:

```text
Load3DMap original file offset 199365
payload linear offset 199357
Ghidra address 3000:0ABD
```

## Results

- START functions compared: 358
- START decompile completion: 358/358
- GAME.OVR candidate functions compared: 623
- GAME.OVR decompile completion: 623/623
- GAME.OVR Ghidra-defined strings: 13
- START exact text overlaps with the original START string artifact: 166

The GAME.OVR Ghidra-defined string count is low because the raw overlay import lacks overlay loader context. Existing custom extractors remain authoritative for string coverage.

## High-Value GAME.OVR Anchor Mapping

Known file/string anchors now have nearby Ghidra function candidates:

| Anchor | File offset | Ghidra address | Nearby candidates |
|---|---:|---|---|
| `combat_start` | 65336 | `0ff3:0000` | previous `0000:fb92`, next `1000:0131` |
| `shop_menu` | 117370 | `1ca7:0002` | previous `1000:c010`, next `1000:ce56` |
| `item0_loader` | 126462 | `1edf:0006` | previous `1000:eb60`, next `1000:eeec` |
| `load_game` | 134527 | `20d7:0007` | previous `1000:fb92`, next `2000:13fd` |
| `save_game` | 136472 | `2151:0000` | previous `2000:13fd`, next `2000:1c53` |
| `item_debug_fields` | 143848 | `231e:0000` | previous `2000:2986`, next `2000:3ea6` |
| `wall_loader_wall_def_1` | 198845 | `308b:0005` | previous `3000:006f`, next `3000:0c04` |
| `wall_loader_wall_def_2` | 198880 | `308d:0008` | previous `3000:006f`, next `3000:0c04` |
| `load3dmap_geo` | 199334 | `30a9:000e` | previous `3000:006f`, next `3000:0c04` |
| `load3dmap_error` | 199365 | `30ab:000d` | previous `3000:006f`, next `3000:0c04` |

The `Load3DMap`/`WALLDEF` cluster is now a concrete Ghidra triage area:

- `generated/ghidra/deep_game_ovr_payload/decompiled/3000_006f_FUN_3000_006f.c`
- `generated/ghidra/deep_game_ovr_payload/decompiled/3000_0c04_FUN_3000_0c04.c`

## Integration Notes

- Do not promote anonymous Ghidra function names into runtime code.
- Use the comparison report as a triage map for manual function naming.
- The next useful pass is to inspect `3000:006f` and surrounding functions in Ghidra alongside the raw bytes and `generated/game_ovr/map_scan.md` before making map-loader claims.
