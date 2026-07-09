# Buck Rogers: Matrix Cubed Reverse Engineering Workspace

Private preservation and analysis workspace for James's local copy of Buck Rogers: Matrix Cubed.

## Local Source Material

- Game folder: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX`
- Archive: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source.7z`
- Extracted image gallery: `/home/jzatopa/Downloads/matrix-cubed-assets/images/index.html`

## Goals

1. Document the local file formats and data layout.
2. Recover source-like structure from `START.EXE`, `GAME.OVR`, and data-driven ECL/DAX content.
3. Build clean-room-style, readable reimplementation notes and scaffolding for private learning/preservation.

## Boundaries

- Do not publish or redistribute copyrighted code, assets, or a playable copy.
- Treat any reconstructed source as private research unless James separately clears rights.
- Prefer documented behavior and clean reimplementation over copying binary-derived code verbatim.

## Current Findings

- `START.EXE` is an MS-DOS MZ executable.
- The executable contains Borland runtime text, suggesting a Turbo Pascal/Borland Pascal lineage.
- `GAME.OVR` starts with `FBOV`, consistent with Borland overlay usage.
- Many visual assets are stored in `.DAX` containers and can be decoded into PNG.
- Gold Box behavior is likely split between engine code and ECL/DAX data blocks.

## Generated Outputs

Run:

```bash
python3 scripts/analyze_local_files.py
```

This writes inventory and block maps into `generated/`.

Current event-analysis layers:

- `generated/ecl1_disasm/`: byte-level ECL listings with suspect data/code boundaries preserved.
- `generated/event_atlas/`: GEO event IDs mapped to ECL targets and nearby text hints.
- `generated/event_pseudocode/`: readable per-event instruction traces.
- `generated/event_structured/`: structured first-pass pseudocode for mapped map events.
- `generated/suspect_boundaries/`: classification of remaining data/code boundary suspects.

Latest pass notes:

- `docs/complex-command-cleanup-pass-1.md`
- `docs/referenced-suspect-audit-pass-1.md`
- `docs/text-padding-range-pass-1.md`
- `docs/operand-05-and-prefix-target-pass-1.md`
- `docs/fallthrough-prefix-and-surprise-pass-1.md`
- `docs/unknown-prefix-normalization-pass-1.md`
