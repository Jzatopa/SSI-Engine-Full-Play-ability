# Reverse-Engineering Package Review

Imported externally supplied START.EXE and GAME.OVR reverse-engineering packages.

## Package Hashes

- `START reverse-engineering package` ZIP SHA-256: `6772a1989d76e8fa706cd997f3d4cc0c55e3a7c3180fea43b91b83708245b404`
- `GAME.OVR reverse-engineering package` ZIP SHA-256: `c6cac25cf56e52892ce68dcb44361fbd4a853fab87fbf1c5b9eb017449b9d87d`

## START.EXE

- Local original SHA-256: `20d039d341c9d0851fe935d4eeb4de07e255e71aeb555cdb779d2ecf7e680597`
- Supplied unpacked EXE SHA-256: `2694f750e7f5e43745ad8b8ca84aa6dd205e6a87d9be815082e77e4b86c44840`
- Supplied unpacked EXE entry: `0000:002F`
- Supplied unpacked EXE stack: `18A1:4000`
- Supplied unpacked EXE relocations: `708`
- Original contains `Packed file is corrupt`: `True`
- Unpacked contains Borland copyright: `True`

Verdict: The package START.EXE hash matches the local original. The supplied unpacked EXE is a derived MZ artifact and should be treated as externally supplied best-effort evidence until its unpacking method is reproduced locally.

## GAME.OVR

- Local original SHA-256: `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`
- FBOV magic present: `True`
- Declared FBOV payload size: `212521`
- Actual bytes after header: `212521`
- Supplied payload SHA-256: `14e9bb10f384564716fddebe8c4970188dc2982612cf516a31bc863dd4a2834e`
- Supplied payload matches local `GAME.OVR[8:]`: `True`

Verdict: The package payload exactly matches local GAME.OVR bytes after the 8-byte FBOV header. Raw disassemblies are useful search evidence but include code/data ambiguity until overlay segments and relocations are mapped.

## Integration Notes

- Full extracted package files are staged under `generated/reverse_engineering/imported/`.
- The START unpacked executable is not promoted as a replacement for `START.EXE`.
- The GAME.OVR payload is confirmed as a byte-identical derived view of the local overlay.
- Next useful decompiler work is to load the unpacked START artifact and GAME.OVR together with overlay-aware segment mapping.
