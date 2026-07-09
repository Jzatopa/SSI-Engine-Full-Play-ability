# Compiler Runtime Qwen Coder Pass 1

## Goal

Use only Qwen Coder as the model-side analyst to identify the likely compiler/runtime family behind the Matrix Cubed DOS binaries, while Codex only gathers deterministic local evidence and verifies commands.

## Evidence Given To Qwen Coder

- `START.EXE` is an MS-DOS MZ executable.
- `GAME.OVR` is data and begins with `FBOV`.
- `START.EXE` contains:
  - `Runtime error`
  - `Overlay error, program abort!`
  - `Please insert overlay disk.`
  - `Portions Copyright (c) 1983,90 Borland`
- `GAME.OVR` begins with `FBOV` and memory-error text.
- Binary-mode i8086 disassembly shows normal stack-frame code such as `push bp`, `mov sp,bp`, `sub sp,...`, and many far calls.
- No `.map`, `.sym`, `.tds`, `.obj`, or `.lib` files were found in the local game copy.

## Qwen Coder Verdict

Qwen Coder's bounded conclusion:

- Most likely family: Borland 16-bit DOS x86 toolchain/runtime.
- Overlay status: likely Borland overlay manager/runtime, with high confidence.
- Exact compiler/version: not proven.
- C vs C++ vs Pascal: not proven from current evidence.

Qwen's first pass suggested Borland Turbo C++ / Borland C++. The follow-up pass widened that to Borland C/C++ or Turbo Pascal-era runtime after seeing that exact version evidence was insufficient.

## Recovery Implication

The best current path is not to rebuild with the original compiler. The practical path remains:

1. Use Ghidra/16-bit x86 analysis to identify overlay entry points, stack frames, far-call conventions, and runtime helpers.
2. Recover C-like pseudocode/structures where decompiler output is stable.
3. Keep implementing the playable runtime in modern source from verified behavior and decoded data.

The evidence supports recoverable function-level structure and C-like pseudocode in places, but does not yet support restoring original high-level source, original structs, or an exact original compiler build.

## Token Counts

Qwen Coder API metadata:

- First prompt: `prompt_eval_count=962`, `eval_count=341`, total `1303`.
- Follow-up prompt: `prompt_eval_count=627`, `eval_count=322`, total `949`.
- Total Qwen Coder tokens reported by Ollama: `2252`.

Codex-side exact token telemetry is not exposed by the local tools. Approximate visible/tool context processed for this pass was about 4k tool-output tokens plus orchestration text. Treat the Codex token number as approximate, not metered.

Raw Qwen artifacts:

- `generated/qwen_advisory/compiler_runtime_identification.json`
- `generated/qwen_advisory/compiler_runtime_identification_followup.json`

## Next Checks

- Load `START.EXE` and `GAME.OVR` in Ghidra with 16-bit x86/DOS assumptions and mark `FBOV` overlay boundaries.
- Search for Borland runtime/overlay manager signatures inside Ghidra, not just strings.
- Identify a small, already-understood routine from live behavior and confirm whether decompiler output forms stable C-like control flow.
