# START.EXE reverse-engineering notes

Input: START.EXE
SHA-256: 20d039d341c9d0851fe935d4eeb4de07e255e71aeb555cdb779d2ecf7e680597
Original file type: MS-DOS MZ executable, 16-bit.
Original packed file size: 70277 bytes.

Findings:
- The executable was packed/compressed with a DOS stub that prints "Packed file is corrupt" on failure.
- The unpacked code contains Borland/Turbo Pascal runtime strings, including "Runtime error" and "Portions Copyright (c) 1983,90 Borland".
- The visible application strings identify it as "Matrix Cubed v1.0 / Play Demo" and reference GAME.OVR, graphics/sound/input setup, save paths, joystick calibration, and overlay loading.
- The recovered program is almost certainly not the full game logic. It appears to be a launcher/configuration/start program that loads GAME.OVR.

Recovered execution metadata:
- Original entry point after unpacking: CS:IP = 0000:002F
- Original stack after unpacking: SS:SP = 18A1:4000
- Unpacked load image size: 75344 bytes
- Relocation entries recovered: 708
- Packer commands processed: 668

Files in this package:
- START.unpacked.exe: best-effort reconstructed unpacked MZ EXE with relocation table.
- START.unpacked.memory.bin: raw relocated in-memory image after unpacking.
- START.unpacked.loadimage.unrelocated.bin: raw load image with relocation words de-adjusted by the simulated load base.
- START.unpacked.disassembly.asm: full 8086 disassembly of the relocated memory image.
- START.unpacked.strings.txt: printable strings from the unpacked image.

Important limitation:
Original Pascal source cannot be reconstructed exactly from a compiled DOS EXE. Function names, variable names, comments, types, and high-level structure are mostly lost. The practical outputs are an unpacked executable, disassembly, strings, and manually reconstructed pseudocode for specific routines.
