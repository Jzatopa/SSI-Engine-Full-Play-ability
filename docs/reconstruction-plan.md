# Reconstruction Plan

## Practical Target

The realistic target is not the exact original SSI source tree. The compiler discarded original names, comments, and high-level structure. The practical target is a source-like reconstruction:

- file-format parsers for local assets,
- documented engine subsystems,
- named routines and data structures,
- pseudocode for binary routines,
- eventually a clean reimplementation scaffold that can load the local data.

## Workstreams

### 1. Data Formats

- DAX container table and run-length compression.
- Image block formats: EGA, VGA, sprites, strata/mixed blocks.
- ECL game scripting blocks in `ECL1.DAX`.
- GEO/maps in `GEO1.DAX`.
- Characters, items, monsters, ships, music, and wall definitions.

### 2. Executable And Overlay

- Parse MZ header, relocation table, entry point, stack pointer, and image layout.
- Identify Borland Pascal runtime signatures.
- Map overlay segments in `GAME.OVR`.
- Extract and cluster strings by offset to name likely systems.
- Disassemble 16-bit code and annotate call sites around known strings.

### 3. Engine Architecture

Initial subsystem buckets from strings/assets:

- startup/configuration,
- graphics adapter and sound driver selection,
- DAX asset loading,
- text/dialog rendering,
- character and party management,
- tactical combat,
- ship combat,
- inventory and repair,
- ECL interpreter/event dispatch,
- save/load.

### 4. Source-Like Reimplementation

Recommended private scaffold:

- `src/formats/` for DAX/ECL/GEO parsers,
- `src/engine/` for renderer/input/audio abstractions,
- `src/game/` for Matrix Cubed-specific state machines,
- `tools/` for extraction, diffing, and validation against original data.

Use the local game data as external input. Do not embed copyrighted assets.

## Immediate Next Steps

1. Build a DAX block map and classify each file/block.
2. Decode `ECL1.DAX` block boundaries and compare with public Gold Box ECL research.
3. Generate 16-bit disassembly of `START.EXE` load image with relocation metadata.
4. Cluster `GAME.OVR` strings and label likely overlay routines.
5. Start a function notebook with offsets, names, evidence, and pseudocode.
