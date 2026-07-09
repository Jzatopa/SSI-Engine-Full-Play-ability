# Ghidra Deep Pass 1

Date: 2026-06-26

## Scope

Ran local Ghidra 12.1.2 headless analysis against:

- `generated/reverse_engineering/imported/start/START.unpacked.exe`
- `generated/reverse_engineering/imported/game_ovr/game_ovr_reverse_engineering/GAME.OVR.payload_after_fbov_header.bin`

The installed 16-bit real-mode language id is:

```text
x86:LE:16:Real Mode
```

The compiler spec used by headless import is:

```text
default
```

Ghidra reports the combined language/compiler as `x86:LE:16:Real Mode:default`.

## Commands

START unpacked MZ import:

```bash
/home/jzatopa/.openclaw/workspace/tools/ghidra/ghidra_12.1.2_PUBLIC/support/analyzeHeadless \
  /home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-ghidra-project-deep \
  MatrixCubedDeep \
  -import /home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re/generated/reverse_engineering/imported/start/START.unpacked.exe \
  -processor 'x86:LE:16:Real Mode' \
  -cspec default \
  -scriptPath /home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re/scripts/ghidra \
  -postScript DumpDeepProgramSummary.java \
    /home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re/generated/ghidra/deep_start_unpacked \
    800 \
  -overwrite
```

GAME.OVR raw payload import:

```bash
/home/jzatopa/.openclaw/workspace/tools/ghidra/ghidra_12.1.2_PUBLIC/support/analyzeHeadless \
  /home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-ghidra-project-deep \
  MatrixCubedDeep \
  -import /home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re/generated/reverse_engineering/imported/game_ovr/game_ovr_reverse_engineering/GAME.OVR.payload_after_fbov_header.bin \
  -loader BinaryLoader \
  -processor 'x86:LE:16:Real Mode' \
  -cspec default \
  -scriptPath /home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re/scripts/ghidra \
  -postScript DumpDeepProgramSummary.java \
    /home/jzatopa/.openclaw/workspaces/goldenbox/matrix-cubed-re/generated/ghidra/deep_game_ovr_payload \
    800 \
  -overwrite
```

## Generated Artifacts

- `scripts/ghidra/DumpDeepProgramSummary.java`
- `generated/ghidra/deep_start_unpacked/program_summary.md`
- `generated/ghidra/deep_start_unpacked/functions.tsv`
- `generated/ghidra/deep_start_unpacked/strings.tsv`
- `generated/ghidra/deep_start_unpacked/decompile_summary.tsv`
- `generated/ghidra/deep_start_unpacked/decompiled/*.c`
- `generated/ghidra/deep_game_ovr_payload/program_summary.md`
- `generated/ghidra/deep_game_ovr_payload/functions.tsv`
- `generated/ghidra/deep_game_ovr_payload/strings.tsv`
- `generated/ghidra/deep_game_ovr_payload/decompile_summary.tsv`
- `generated/ghidra/deep_game_ovr_payload/decompiled/*.c`

The Ghidra project is stored outside the hidden OpenClaw path:

```text
/home/jzatopa/Documents/jameszatopaworkspace/matrix-cubed-ghidra-project-deep
```

## START.unpacked.exe Results

- Loader: `Old-style DOS Executable (MZ)`
- Language/compiler: `x86:LE:16:Real Mode:default`
- MD5 reported by Ghidra: `342095ccae84adc876f86dfce5e35ffe`
- Memory blocks: 52 executable `CODE_*` blocks plus `HEADER`
- Function count: 358
- Defined string count: 243
- Decompiled functions exported: 358
- Decompiled timeouts: 0

The entry decompile begins at `1000:002f` and shows a long startup/initialization chain across many code segments. Treat this as useful call-graph evidence, not source-equivalent output.

## GAME.OVR Payload Results

- Loader: `Raw Binary`
- Language/compiler: `x86:LE:16:Real Mode:default`
- MD5 reported by Ghidra: `1a6f200edd4745797e47c98d53aa81de`
- Memory block: one executable/writable initialized `ram` block from `0000:0000` to `3000:3e28`
- Function count: 623 candidate functions
- Defined string count: 13
- Decompiled functions exported: 623
- Decompiled timeouts: 0

The raw overlay import is useful for rough function discovery and C-like snippets, but it lacks the overlay manager's segment/relocation context. The low defined-string count is a Ghidra artifact; the project string extractors remain the better evidence for overlay text.

## Next Step

Use this Ghidra project to start naming anchors rather than treating anonymous decompiler output as source. Highest-value targets:

- START overlay loader calls and `GAME.OVR` references.
- GAME.OVR functions near known string anchors such as save/load, shop, combat, and `Load3DMap`.
- Cross-check Ghidra candidate functions against existing `generated/game_ovr/anchors.json`, `generated/game_ovr/map_scan.md`, and item-name evidence before changing runtime code.
