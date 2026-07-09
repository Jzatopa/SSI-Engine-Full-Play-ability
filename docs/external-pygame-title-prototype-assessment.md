# External Pygame Title Prototype Assessment

Date: 2026-06-27

## Goal

Compare the separately supplied Matrix Cubed Pygame title/debug prototype against the current `matrix-cubed-re` reconstruction and decide whether to integrate it directly or keep it as a second track.

## Imported Evidence

- Raw external handoff: `docs/external/matrix-cubed-pygame-title-handoff.md`
- DOSBox title reference screenshot: `docs/reference_dosbox_title.png`
- External handoff SHA-256: `c46fb644450942edcce79251ca1e4bca3bdef64dd815f945a1ae4be0d8ca349e`
- Reference screenshot SHA-256: `fbe4b1df88aa7496257efd64b2c4b5e8393619bb3f9022386fae197ba680e651`
- External project path inspected:
  - `<local external pygame title prototype>`

## Verdict

The external package is not further along than the current project as a game reconstruction. It is a useful older graphics/debug prototype and should be treated as a second-track reference for title-screen and image-decoder work.

The current `matrix-cubed-re` repo remains the authoritative project because it already has:

- playable Python/Pygame runtime scaffolding,
- map movement and first-person wall rendering,
- combat loop,
- save/load parsing and writing,
- decoded item names from START.EXE/ITEM0 evidence,
- monster and item catalogs,
- ECL/GEO/generated data artifacts,
- Ghidra evidence exports for START/GAME.OVR,
- 140 passing tests.

The external package has useful pieces not yet fully represented in the current runtime:

- a DOSBox reference screenshot for the real title screen,
- a compact `TITLE.DAX` candidate renderer,
- a visual title comparison scene,
- notes about the likely layered title composition,
- a small debug UI pattern for cycling candidate renders.

## Data Comparison

Both source folders contain 27 `.DAX` archives. The current original game directory has one extra configuration file:

- `MATRIX.CFG`

No unique original data asset from the external package was found missing from the current original source folder.

## Integration Decision

Do not replace the current runtime with `matrix_py`. Instead:

1. Preserve the external handoff and screenshot as evidence.
2. Port only the useful graphics/debug ideas into the current `matrix_cubed` package.
3. Keep Gold Box Explorer as the reference source for DAX/image/palette behavior.
4. Validate each decoder against local bytes, screenshots, and generated outputs before using it in runtime menus.

## Next Graphics Track

The next focused pass should add a title/image-debug path to the current repo:

- Add a `TITLE.DAX` decoder module or script using the known DAX parser.
- Generate candidate PNGs for each `TITLE.DAX` block.
- Compare candidates against `docs/reference_dosbox_title.png`.
- Port or reimplement Gold Box Explorer image decoding logic for `TITLE`, `BIGPIC`, `PIC`, `CPIC`, `SPRIT`, `COMSPR`, `BORDERS`, `CURSOR`, and `8X8D0`.
- Add a lightweight debug viewer only after static PNG generation proves the decoder is improving.

## Caution

The external handoff contains plausible but not fully verified image-format conclusions. Treat its `TITLE.DAX` offset, packed-4bpp mode, dimensions, and composition theory as hypotheses until reproduced with local scripts.
