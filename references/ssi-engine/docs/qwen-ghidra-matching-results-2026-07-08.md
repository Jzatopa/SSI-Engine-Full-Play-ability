# Qwen Ghidra↔COAB Matching — Full Run Results (2026-07-08)

Output: `generated/qwen_advisory/ghidra_coab_matches/2026-07-08-full/`
(matches.jsonl, matches_rollup.tsv, run_manifest.json, coab_catalog.tsv).
Model `qwen3-coder:30b` @ `192.168.2.2`, settings per
`qwen-coder-optimal-settings.md`. 623/623 processed, 0 parse failures,
0 HTTP errors, ~1s/function.

## Distribution

| Verdict | Count | % |
|---|---|---|
| none | 527 | 85% |
| match | 62 | 10% |
| weak | 34 | 5% |
| **non-none total** | **97** | **15%** |

Confidence among non-none: high 39, medium 57, low 1.

Healthy shape: not mode-collapsed (v1 was ~all-match/high), not
over-rejecting (v2-clean concern). The 527 "none" is high-value on its own —
it narrows 623 functions to a 97-candidate review set, and correctly rejects
thunks and corrupt decompilations.

## Anchoring caveat (READ before using the matches)

Top-candidate names are concentrated: **CMD_Compare 48, RunEclVm 31** = 81%
of non-none; 91/97 candidates are overlay `ovr003` (COAB's ECL command
interpreter). This is **partly legitimate** (GAME.OVR's core genuinely is the
ECL VM + command handlers, which resemble ovr003) and **partly residual
bucket-anchoring** (CMD_Compare absorbs "does some comparison/arithmetic";
RunEclVm absorbs "has a dispatch loop"). The v2 disambiguation rule reduced
but did not eliminate this — 32% RunEclVm is above the 20% re-look threshold.

**Therefore: judge on the evidence field, not the label.** Two tiers of
trust in the output:
- **Higher-signal candidates** — the ~18 that picked a *specific* name over
  the two buckets (`sub_2619A`, `sub_29677`, `compare_variables`, `CMD_Random`,
  `MovePositionForward`, `AffectPoisonPlus0`, `sub_30168`, …), and any
  CMD_Compare/RunEclVm whose evidence cites a **distinctive constant or
  numeric-opcode dispatch** (e.g. `0000:39b7` "bVar1 = in_AL ^ 0xe1",
  `0000:d64a` "constant 0x7e in multiple calls"). Verify these first.
- **Lower-signal / probable bucket noise** — CMD_Compare/RunEclVm matches whose
  evidence is generic ("conditional logic on ZF/OF/SF flags", "arithmetic on
  memory values"). Treat as weak leads.

## Recommended next step (free, high-value): qwen skeptic pass

Do NOT hand-verify all 97 blind. Instead run a second qwen job that, per
non-none candidate, is given the target function AND the *actual COAB C#
source* of its proposed match, and asked: does this specific function really
correspond — yes/partial/no — and name the discriminating detail. This tests
each candidate against ground truth, collapses the bucket-anchored false
positives, and elevates the real ovr003 matches, turning 97 candidates into a
short high-precision list for final human/Matrix-binary confirmation. Still
candidate-only until confirmed against the Matrix binary; no COAB name/offset
is adopted as Matrix evidence from this run alone.
