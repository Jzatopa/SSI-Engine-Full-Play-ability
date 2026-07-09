# Reverse-Engineering Package Import Pass 1

Date: 2026-06-26

## Scope

Imported and reviewed two externally supplied reverse-engineering packages:

- `START_reverse_engineering_package---35e28ac5-a822-4a78-bfe6-e973e63fd973.zip`
- `GAME_OVR_reverse_engineering_package---5461e321-756c-48f6-a105-e13acb723264.zip`

The importer is reproducible:

```bash
source .venv/bin/activate
PYTHONPATH=src python3 scripts/review_reverse_engineering_packages.py \
  --start-zip /home/jzatopa/.openclaw/media/inbound/START_reverse_engineering_package---35e28ac5-a822-4a78-bfe6-e973e63fd973.zip \
  --game-ovr-zip /home/jzatopa/.openclaw/media/inbound/GAME_OVR_reverse_engineering_package---5461e321-756c-48f6-a105-e13acb723264.zip
```

## Generated Artifacts

- `generated/reverse_engineering/package_review.md`
- `generated/reverse_engineering/package_review.json`
- `generated/reverse_engineering/imported/start/`
- `generated/reverse_engineering/imported/game_ovr/`

## Verified Facts

- The START package ZIP SHA-256 is `6772a1989d76e8fa706cd997f3d4cc0c55e3a7c3180fea43b91b83708245b404`.
- The GAME.OVR package ZIP SHA-256 is `c6cac25cf56e52892ce68dcb44361fbd4a853fab87fbf1c5b9eb017449b9d87d`.
- Local `START.EXE` SHA-256 remains `20d039d341c9d0851fe935d4eeb4de07e255e71aeb555cdb779d2ecf7e680597`.
- The supplied `START.unpacked.exe` is a valid MZ executable with SHA-256 `2694f750e7f5e43745ad8b8ca84aa6dd205e6a87d9be815082e77e4b86c44840`.
- The supplied `START.unpacked.exe` has entry `0000:002F`, stack `18A1:4000`, 708 relocations, a 2864-byte header, and a 75344-byte load image.
- Local `START.EXE` contains the string `Packed file is corrupt`, supporting the package claim that START is packed or has a packed-loader failure path.
- The supplied unpacked START artifact contains the Borland copyright string.
- Local `GAME.OVR` SHA-256 remains `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`.
- Local `GAME.OVR` starts with `FBOV`; its little-endian dword at offset 4 declares a 212521-byte payload.
- The supplied `GAME.OVR.payload_after_fbov_header.bin` exactly matches local `GAME.OVR[8:]`.

## Cautions

- The START unpacked executable is externally supplied best-effort evidence. Do not replace local `START.EXE` with it unless/until the unpacking method is reproduced locally.
- The GAME.OVR disassemblies are raw 8086 sweeps and include code/data ambiguity. They are useful for searching and anchoring, not source-equivalent output.
- The best next decompiler pass is to load the unpacked START artifact and GAME.OVR together in an overlay-aware workflow, then map segment/relocation context before promoting pseudocode into runtime behavior.
