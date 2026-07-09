# SSI Engine Full Play-ability

Near-preservation-level Java SSI Gold Box engine reconstruction work. Buck
Rogers: Matrix Cubed is the first proof target, with the architecture intended
to support the broader SSI Gold Box catalog.

Original game files are not included in this repository. Local validation uses
user-provided installs through paths such as `MATRIX_CUBED_GAME_DIR`.

## Goals

1. Build a universal Java SSI Gold Box engine core.
2. Keep gameplay logic UI-neutral, with Swing/AWT as the first desktop frontend
   adapter.
3. Port and test relevant COAB behavior into Java while citing source
   repo/commit/file.
4. Validate first against Buck Rogers: Matrix Cubed, then other locally
   available Gold Box titles.
5. Preserve original gameplay quirks when known and document them for possible
   later optional cleanup.

## Boundaries

- Do not commit or redistribute original game binaries, save files, screenshots,
  extracted art, or a playable game copy.
- Keep original game installs external and user-provided.
- Do not promote title-specific values from another game or source until they
  are validated against local original files or runtime behavior.
- Licensing and attribution cleanup is required before any public release.

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
