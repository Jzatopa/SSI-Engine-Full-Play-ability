# I Spent 30 Minutes Hardening Qwen Coder as a Coding Sidecar, Then A/B Tested It vs. Writing The Code Myself

**Setup:** RTX 3090, `qwen3-coder:30b` via Ollama, running as a sub-agent inside my main coding loop (Codex/Ralph).

**Context:** I'm reverse-engineering a 1992 DOS game (Buck Rogers: Matrix Cubed) and building a playable reconstruction. I wanted Qwen to help generate Python code in parallel while I validated and fixed things. The original wrapper was heavily constraining it to advisory-only output — it would tell Codex what files to inspect but never actually produce code.

I spent 30 minutes hardening the wrapper, then A/B tested the same coding task with and without Qwen's help.

## The Hardening Problem

The original wrapper (Ralph/Qwen sidecar) was designed for *safety first*:

- **Forced advisory format:** Qwen was told to return `TASK_UNDERSTANDING → VERIFIED_FACTS → FILES_TO_INSPECT → HYPOTHESES → IMPLEMENTATION_PLAN → VALIDATION_PLAN → RISKS → UNSUPPORTED_CLAIMS_AUDIT`. Even when I asked "write this function," it returned "Codex should go inspect combat.py and then write the function."
- **Fixed seed (7) at temperature 0.1:** Every call produced identical output. Iteration was useless.
- **Overly aggressive rejection guard:** Phrases like "for example" and "such as" triggered rejection, even when Qwen was correctly repeating prompt evidence.
- **Max 2048 output tokens:** Too tight for real code generation.

## What I Changed

| Change | Before | After |
|--------|--------|-------|
| **Output format** | Advisory only | `--DIRECT` flag skips advisory, sends prompt raw with "generate output" system prompt |
| **Temperature/seed** | 0.1, seed=7 (deterministic) | 0.35, no seed (varied results per call) |
| **Max tokens** | 2048 | 32768 |
| **Rejection guard** | Blocked "for example", "such as" | Only blocks "might be named", "could be called" |
| **Verification** | None | Every output includes a VERIFICATION section |

Results after hardening? **First time the wrapper ever produced Python code.** A complete 100+ line Pygame runner with correct layout, colors, and input handling.

## The A/B Test

I wired the same combat resolution module two different ways:

### Pass A: With Qwen (--DIRECT mode)

1. Fired Qwen with a detailed prompt about the combat API and needed functions
2. While Qwen generated (90 seconds), I reviewed the existing runtime code
3. Qwen returned a decent 100-line scaffold with correct structure
4. But **7 issues to fix**: missing imports, dead variable (`hit = True` never used), single-monster-only targeting, wrong log source, wrong status dict format
5. I fixed them, wrote tests, integrated into the runner

**My time: ~4 minutes. Qwen time: ~1.5 minutes (parallel).**

### Pass B: Without Qwen

1. Wrote the same combat module from first principles
2. Used a clean `@dataclass` for state, properties for victory/defeat queries
3. Wrote tests, integrated into the runner

**My time: ~3 minutes. Qwen time: 0.**

### Results

| Metric | With Qwen | Without Qwen |
|--------|-----------|--------------|
| Lines of new code | 150 (100 + 50 fixes) | 93 |
| Bugs to fix | 7 | 0 |
| My Codex token cost | ~3k tokens ($0.08) | ~2k tokens ($0.06) |
| Qwen token cost | $0 (local) | $0 (N/A) |
| Total wall time | ~4 min | ~3 min |

**Qwen's version was slightly worse in every measurable way** for this task. The scaffold saved me ~90 seconds of typing but cost me more than that in diagnosing and fixing its assumptions. The no-Qwen version was cleaner, less code, and correct on first try.

## When Qwen Actually Helped (Earlier in Testing)

Earlier in the testing phase (before this A/B), Qwen generated a complete Pygame runner scaffold — window init, rendering structure, color constants, input skeleton, event text overlay. That scaffold was **genuinely useful** because:

- It was 100+ lines of boilerplate (more structure than logic)
- The "wrongness" was mostly API mismatches (I said `ReconstructedData()` instead of `ReconstructedData.from_generated()`), which took seconds to fix
- I didn't have to type out the rendering loop skeleton from scratch

**Rule of thumb from this:** Qwen is best for tasks where structure > correctness — big UI scaffolds, boilerplate-heavy modules, data format dumpers. For focused logic (<100 lines), writing from scratch is faster.

## The Real Bottleneck

The original wrapper was so over-constrained that Qwen couldn't produce *anything* useful. After opening it up, Qwen produced *something* useful but needed supervision. My time savings were negative for the compact combat module but positive for the larger runner scaffold.

The limiting factor isn't model quality — it's that every output needs human review before trust, and for small modules the review time exceeds the writing time. I'd estimate the efficiency break-even point is around **150–200 lines of boilerplate**.

## What I Wish I Knew Before Starting

1. **The advisory-only wrapper pattern kills Qwen's usefulness for coding.** If your sidecar returns `FILES_TO_INSPECT` instead of code, you're using it wrong for code gen. Add a direct-output mode.
2. **Remove the fixed seed for iteration.** At 0.1 temp + seed 7, every call gives identical output. With no seed, iteration gives variety and you can take the best result.
3. **Don't over-guard the rejection.** "For example" is how LLMs hedge — it's not a hallucination. Only catch explicit invention patterns.
4. **For compact tasks, just write it yourself.** The overhead of prompting + waiting + reviewing + fixing exceeds the typing time for anything under ~100 lines.

---

*[This was done with a local 3090 running qwen3-coder:30b. Full wrapper changes and test artifacts in the linked repo. Happy to answer questions about the hardening process or the game reconstruction.]*
