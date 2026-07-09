# Matrix Cubed Handoff Bundle

Date: 2026-06-30

This bundle is a compact transfer package for the current Matrix Cubed reconstruction state.

## Included Project Files

- `HANDOFF.md`: current project status, run commands, known boundaries, and next work.
- `README.md`: repository overview.
- `pyproject.toml`: Python package metadata.
- `docs/ssi-engine-reference-acceleration-plan.md`: how the Java `ssi-engine` reference should speed up Python reconstruction.
- `scripts/run_ssi_engine_reference.sh`: classpath-based Java reference launcher.
- `generated/ssi_engine_probe/xwininfo_tree.txt`: Xvfb evidence that `ssi-engine` opened a `Buck Rogers - Matrix Cubed` window.

## Included Gold Box Explorer Fix Files

- `goldbox-explorer/Explorer/FileDto.cs`: Linux/Mono fallback for `shell32.dll` file-type lookup.
- `goldbox-explorer/Common/Plugins/Hex/NativeMethods.cs`: guarded `user32.dll` caret wrappers.
- `goldbox-explorer/Common/Plugins/GeoDax/GeoDaxFile.cs`: fixed `WALLDEF.DAX` path combine bug.
- `goldbox-explorer/launch-goldbox-explorer.sh`: launcher now rebuilds before running.

## Validation Summary

- `ssi-engine` builds under Java 21 with local Maven 3.9.9.
- `ssi-engine` launches Matrix Cubed by classpath and detects the game properties under Xvfb.
- Gold Box Explorer builds with Mono/xbuild and opens a window under Xvfb with no exception matches in the launch log.

## Boundary

`ssi-engine` is GPL-3.0. Use it immediately as behavior/reference evidence. Direct substantial Python ports need attribution and license handling; prefer test-backed reimplementation in the existing Python architecture unless the project intentionally adopts compatible terms.
