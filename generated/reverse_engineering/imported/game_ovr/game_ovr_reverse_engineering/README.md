# GAME.OVR reverse-engineering package

## Summary

`GAME.OVR` is not a normal DOS `MZ` executable. It is a Borland-style `FBOV` overlay file used by a 16-bit DOS program. The first 8 bytes are:

```text
46 42 4F 56 29 3E 03 00
FBOV + little-endian payload size 0x00033E29
```

The declared payload size is `0x33E29` / `212,521` bytes, exactly the file size minus the 8-byte `FBOV` header.

This file is therefore a load-on-demand code/data overlay, probably used by the unpacked `START.EXE` launcher. It is not self-contained in the same way as an `.EXE`, so a true standalone decompile is not reliable without combining it with the executable's overlay manager, segment tables, relocation data, and runtime context.

## Result

A perfect recovery of the original source is not possible from this file alone. The compiler/linker removed original comments, local variable names, source layout, and most high-level type information. What can be recovered is:

- raw overlay bytes after the FBOV header
- strings and offsets
- 8086 disassembly of the full file and payload
- useful keyword/context hits
- metadata and hash information

The recovered strings strongly suggest this is the main game overlay for **Buck Rogers: Matrix Cubed / Matrix Cubed**, including combat, party, save-game, mouse/joystick, shop, skill, and UI code/data.

## Files in this package

- `metadata.json`  
  File size, SHA-256, FBOV header values, entropy summary.

- `GAME.OVR.payload_after_fbov_header.bin`  
  Raw overlay payload with the 8-byte `FBOV` header removed.

- `GAME.OVR.raw_8086_disassembly.asm`  
  Best-effort disassembly of the entire file as 8086 real-mode code. This includes data misread as code, because the overlay has no complete public symbol map in this package.

- `GAME.OVR.payload_8086_disassembly.asm`  
  Best-effort disassembly of only the payload after the 8-byte `FBOV` header.

- `GAME.OVR.strings.txt`  
  Printable ASCII strings with file offsets.

- `GAME.OVR.strings.csv`  
  Same string extraction in CSV form.

- `GAME.OVR.pascal_style_strings.txt`  
  Heuristic extraction of Pascal-style length-prefixed strings. This contains false positives but is useful for DOS/Turbo-era binaries.

- `GAME.OVR.keyword_hits.txt`  
  Context around important strings such as credits, save-game messages, joystick setup, combat messages, and party status.

- `GAME.OVR.first_4k.hex.txt`  
  Hex/ASCII dump of the first 4 KiB.

## Important offsets

- `0x00000000`: `FBOV` magic
- `0x00000004`: declared payload size, little-endian, `0x00033E29`
- `0x00000008`: beginning of overlay payload
- `0x00000009`: `WARNING: Insufficient Memory`
- `0x00000189`: credits block begins
- `0x00004385`: `Enemy ship`
- `0x00009FDC`: menu strings: `View`, `Take`, `Divvy`, `Pool`, `Status`, `Exit`
- `0x00017568`: `Quit TO DOS`
- `0x0001AE32`: `Init Mouse/Joystick:`
- `0x0001F627`: save-disk prompt
- `0x00019828`, `0x00020D67`: `Matrix Countdown`

## Notes on “decompilation”

Because this is an FBOV overlay, the cleanest next step would be loading the unpacked `START.EXE` together with this `GAME.OVR` into a DOS-era-aware reverse-engineering tool such as IDA Freeware 5.x or a modern Ghidra workflow with custom FBOV/VROOMM overlay support. A raw 8086 disassembly is included, but it cannot distinguish code from embedded strings/tables everywhere.

This package is intended as a preservation/reverse-engineering aid, not a claim that the original source code was fully recovered.
