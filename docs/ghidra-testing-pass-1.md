# Ghidra Testing Pass 1

Date: 2026-06-19

## Goal

Test whether Ghidra can import and analyze the Matrix Cubed DOS executable enough to support engine-level reverse engineering.

## Tool Setup

Installed the official Ghidra release locally under:

- `/home/jzatopa/.openclaw/workspace/tools/ghidra/ghidra_12.1.2_PUBLIC`

Downloaded asset:

- `ghidra_12.1.2_PUBLIC_20260605.zip`

The SHA-256 matched the official release hash:

- `b62e81a0390618466c019c60d8c2f796ced2509c4c1aea4a37644a77272cf99d`

Java was already available:

- OpenJDK 21.0.11

## Target

Only one executable target was found in the Matrix Cubed folder:

- `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/START.EXE`

Basic target facts:

- Format: MS-DOS MZ executable
- Size: 70,277 bytes
- MD5 from Ghidra: `96af2a91adc86972717ac7ca233ae5b9`

## Ghidra Import

The first import attempt failed because the project path was under `.openclaw`; Ghidra rejects project paths with hidden path elements.

The successful project path is:

- `/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-re/ghidra-project/MatrixCubed.gpr`

Import settings selected by Ghidra:

- Loader: `Old-style DOS Executable (MZ)`
- Language/compiler: `x86:LE:16:Real Mode:default`
- Image base: `0000:0000`

Auto-analysis completed successfully in roughly 3 seconds.

## Exported Summary

Added a Ghidra post-script:

- `scripts/ghidra/DumpProgramSummary.java`

It produced:

- `generated/ghidra/start_exe_summary.md`
- `generated/ghidra/ghidra_import.log`
- `generated/ghidra/ghidra_summary.log`

Summary highlights:

- Memory blocks:
  - `CODE_0`: `1000:0000` through `2000:09af`, 68,016 bytes
  - `CODE_1`: `209b:0000` through `209b:06d4`, 1,749 bytes
  - `DATA`: `209b:06d5` through `3000:1734`, 67,248 bytes
  - `HEADER`: 512 bytes
- Functions detected: 262
- Defined strings detected: 142

The strings include useful engine/domain vocabulary such as ship names, skills, statuses, item names, disk prompts, and audio driver filenames. These should help name functions and data tables in later passes.

## Result

Ghidra is usable for this project. It will not replace the custom ECL decoder, but it can speed up engine-level work by:

- identifying executable functions,
- surfacing static strings and data tables,
- helping name runtime systems,
- validating engine variables that the ECL scripts reference indirectly.

## Next Step

Use the Ghidra project to begin naming function clusters around:

- file/overlay loading, especially `GAME.OVR`,
- menu/input routines,
- character and party data routines,
- combat/encounter setup fields corresponding to unresolved ECL `AREA2` values.
