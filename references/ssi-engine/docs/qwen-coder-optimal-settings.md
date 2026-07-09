# Qwen-Coder Optimal Settings & Prompt Pattern (for James's OpenClaw)

Validated 2026-07-08 against `qwen3-coder:30b` on the RTX 3090 host
(`http://192.168.2.2:11434`, Ollama native API) for a structural
code-classification task (Ghidra↔COAB function matching). The general
settings and prompt *pattern* transfer to any deterministic classify /
extract / match job on this model. Tune the domain-specific rules per task.

## Settings (Ollama `/api/generate`, `stream:false`)

```json
{
  "model": "qwen3-coder:30b",
  "format": "json",
  "options": {
    "temperature": 0.15,
    "top_p": 0.9,
    "num_ctx": 32768,
    "num_predict": 700,
    "seed": 42
  }
}
```

### Why each value (the ones that actually matter)

- **`num_ctx: 32768` — the single most important setting.** Ollama's default
  context is ~4096 and it **silently truncates** anything longer, dropping the
  end of your prompt with no error. For any task where you paste a catalog,
  file, or long context, an undersized `num_ctx` is the #1 cause of
  "the model ignored half my input / gave empty answers." Set it explicitly to
  comfortably exceed prompt+output tokens (measure your longest prompt; 32k
  covered a ~9k-token catalog + a 300-line function with headroom).
- **`temperature: 0.15`** — classification/matching wants stable, repeatable
  judgments, not creativity. Low temp cut run-to-run drift. Do NOT use 0.0 on
  this model for reasoning-bearing output; a hair above zero avoids degenerate
  loops while staying deterministic enough.
- **`format: "json"`** — forces a parseable JSON object, no prose wrapper.
  Gave 100% parse success across ~30 calls. Pair it with an explicit JSON
  schema in the prompt; `format:json` alone doesn't constrain shape.
- **`seed`** — fixed seed + low temp = reproducible runs, so you can re-run
  after a prompt change and attribute the diff to the prompt, not sampling.
- **`num_predict: 700`** — cap output so a runaway generation can't stall a
  batch; size it to your schema's realistic maximum.

## Prompt pattern (what made the difference)

The settings get you parseable output; the **prompt** gets you *correct*
output. Three rules earned their keep, in priority order:

1. **Make "none"/negative a first-class, encouraged answer.** Without this,
   the model mode-collapses: when unsure it repeatedly rubber-stamps one or two
   familiar-looking labels at high confidence. Explicitly: "returning none is
   correct and expected for a large fraction of inputs; a wrong confident
   answer is worse than none; do not force a match."
2. **Calibrate confidence with a countable bar.** "high" only when the model
   can name TWO OR MORE independent concrete features; one weak resemblance is
   "low"; vocabulary coincidence is not evidence. This stopped the
   "everything is high" collapse and made the confidence field trustworthy.
3. **Encode the domain's known confusions as explicit disambiguation rules.**
   Generic reasoning anchors on the most *prominent* catalog label (here, the
   VM dispatcher) for any superficially similar input. A one-line rule ("X
   dispatches on numeric opcodes; letter-key dispatch is a menu handler, not X")
   removes a whole error class cheaply. Add these as you observe them.

### Structural template

- **System message:** role + the task's hard rules (negatives-are-good,
  confidence calibration, domain disambiguations, "strict JSON only").
- **User message:** the reference catalog/context, then the item to classify,
  then the exact JSON schema to emit — with a note that the empty/negative
  result is valid.
- Always demand an **evidence field** ("one sentence: the specific feature that
  supports this"). Two payoffs: it forces the model to justify rather than
  pattern-match, and — critically — the evidence stays useful even when the
  chosen label is wrong. In testing, a mislabeled match still described the
  function correctly ("dispatches on M/V/A/Q keys"), which is exactly what a
  human/verifier needs. **Judge on the evidence, not the label.**

## Operational notes

- Throughput: ~1–3 s/call for short bodies, up to ~11 s for large ones on the
  3090. A few-hundred-item batch is a background-hours job, not interactive.
- Always run a small pilot (8–12 items) and eyeball raw output before a full
  batch. Two failure modes look fine in aggregate counts but are visible in
  raw JSON: mode-collapse (everything one label) and over-rejection (everything
  none). Test both a low-signal slice AND a known-rich slice.
- The output is a **candidate funnel**, never authoritative — its job is to
  shrink N items to the small non-negative subset a stronger model or human
  then verifies. Optionally add a second qwen "skeptic" pass that re-checks
  each proposed match against the one candidate's actual source; free precision.
