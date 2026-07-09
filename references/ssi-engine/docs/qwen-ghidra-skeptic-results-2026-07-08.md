# Qwen Skeptic Pass — Results & Honest Read (2026-07-08)

Second qwen pass: re-checked the 97 non-none candidates from the first run
against the *actual COAB source* of each proposed match. Output:
`generated/qwen_advisory/ghidra_coab_skeptic/2026-07-08/`.

## Raw outcome

| Skeptic verdict | Count |
|---|---|
| yes | 0 |
| partial | 0 |
| no | 87 |
| unresolvable-name | 10 |

Bucket-anchor kill: all 79 first-run CMD_Compare/RunEclVm matches → "no".

## Interpretation (corrects the subagent's over-strong conclusion)

The subagent concluded "no Matrix function corresponds to COAB." That is **not
supported** — a 0-yes rate is the mirror image of the first run's mode-collapse
and must be read skeptically itself. What the evidence actually shows:

1. **Bucket anchors correctly killed (real signal).** Spot-checked rejections
   of CMD_Compare/RunEclVm carried concrete, correct reasoning (e.g. `0000:00d2`
   is a timer/delay poll on 0x602/0x836, genuinely NOT the ECL VM dispatch it
   was matched to). The skeptic did its main job: it removed the first run's
   generic-similarity noise.
2. **The better leads were unverifiable, not disproven.** The ~8 specific-named
   candidates (sub_29677, compare_variables, CMD_Random, MovePositionForward,
   AffectPoisonPlus0…) all returned "no" **with empty discriminating_detail** —
   no captured reasoning, so those verdicts are unreliable, not conclusive. And
   10 candidates were "unresolvable-name" precisely because COAB itself only has
   those functions as raw `sub_XXXX` stubs (unnamed, unimplemented) — i.e. COAB's
   own low-level incompleteness blocks verification, not a proven non-match.

## Meta-finding: the naive matching approach hit its ceiling

Whole-catalog semantic matching of decompiled 16-bit Ghidra C against COAB's
clean C# is a hard cross-representation problem, and this round shows why the
yield is low:
- GAME.OVR's sampled functions are mostly low-level plumbing (timers, thunks,
  memory ops) with no clean *named* COAB twin.
- The base model anchored these onto the few semantically-legible catalog names
  (ovr003 command handlers) → 91/97 candidates in one overlay → mostly artifact.
- The genuine low-level correspondences, if any, live among COAB's own unnamed
  `sub_` functions, which can't be verified by name.

## Recommendation: park this avenue (good ROI on the negative result)

Stop spending cycles on automated Ghidra↔COAB matching for now — it hit a real
ceiling, learned cheaply and for free. What was realized instead:
- A validated, reusable qwen methodology + settings (`qwen-coder-optimal-settings.md`).
- A documented understanding of the anchoring dynamics and the approach's limits.

Authenticity validation is better served right now by (a) DOS-capture combat
validation (host-side, OpenClaw-positioned) and (b) direct COAB-source porting
with conformance tests (already working). If Ghidra↔COAB matching is revisited,
it needs a different signal — call-graph topology, string/data-reference
anchoring, or matching against Matrix-specific evidence — not whole-catalog
semantic guessing. All outputs remain candidate/advisory; nothing adopted as
Matrix evidence.
