# Initial Findings

Date: 2026-06-19

## Scope

Local game copy analyzed:

`$MATRIX_CUBED_GAME_DIR`

## File Inventory

- 43 top-level files in the local game folder.
- 26 `.DAX` containers.
- 611 DAX logical blocks across all `.DAX` files.
- `ECL1.DAX` contains 33 blocks and is the first likely target for script/event reverse engineering.

## Executable

`START.EXE`

- Format: MS-DOS MZ executable.
- Declared file size: 70,277 bytes.
- Header size: 512 bytes.
- Load image size: 69,765 bytes.
- Relocations: 0.
- Entry CS:IP: `109B:0012`.
- Stack SS:SP: `12D3:0080`.
- Contains Borland runtime text: `Portions Copyright (c) 1983,90 Borland`.

Interpretation: likely built with Turbo Pascal or Borland Pascal-era tooling. Plain disassembly is noisy because code and data tables are interleaved and because overlay calls need to be understood.

## Overlay

`GAME.OVR`

- Size: 212,529 bytes.
- Starts with bytes/text `FBOV`, likely Borland overlay metadata.
- Contains high-value gameplay strings, especially ship combat, tactical combat, inventory, repair, credits, and event text.

Notable string clusters include:

- `what do you do?`
- `The entire party is killed!`
- `Congrats. The team gains experience!`
- `Enemy ship`
- `Try to dodge enemy ship?`
- `Select weapon to reload:`
- `Repairing Ship`
- `Use antidote on`

These strings give good anchor points for naming overlay routines once call sites are mapped.

## Data Containers

The DAX table format is confirmed and already decoded for images:

- 2-byte table size.
- 9-byte entries: block id, relative offset, raw size, packed size.
- Blocks use a simple run-length compression variant.

Largest/high-value data files:

- `PIC1.DAX`: 46 blocks, 399,904 raw bytes.
- `ECL1.DAX`: 33 blocks, 247,573 raw bytes.
- `BIGPIC1.DAX`: 6 blocks, 223,668 raw bytes.
- `8X8D1.DAX`: 13 blocks, 188,396 raw bytes.
- `SHIPS.DAX`: 41 blocks, 162,154 raw bytes.

## Source Reconstruction Direction

The first realistic source target should be a clean format/engine reimplementation:

1. DAX parser.
2. Image renderer.
3. ECL bytecode parser/disassembler.
4. GEO/map parser.
5. Overlay string/call-site notebook.
6. Engine subsystem pseudocode.

Exact original source recovery is not realistic from the binary alone because names, comments, and high-level Pascal structure are mostly gone.

## Generated Files

- `generated/inventory.md`
- `generated/start_exe_mz.json`
- `generated/dax_blocks.tsv`
- `generated/dax_blocks.json`
- `generated/start_exe_strings.json`
- `generated/game_ovr_strings.json`
- `generated/start_exe_i8086_disassembly.txt`
- `generated/ecl1_summary.md`
- `generated/ecl1_blocks/*.bin`
