# Qwen-Coder Ghidra↔COAB Matching — Design Spec

Design owner: Claude Code (Fable, coordinator). Implementation: Haiku subagent.
Purpose: use the free local qwen-coder endpoint to propose, for each decompiled
Matrix Cubed GAME.OVR function, its most likely COAB (named) counterpart —
producing a **candidate** table for later verification. Never authoritative.

## The matching problem (why it's fuzzy)

- Ghidra input: 623 decompiled C functions in
  `generated/ghidra/deep_game_ovr_payload/decompiled/*.c`, from Buck Rogers:
  Matrix Cubed's `GAME.OVR`. Entry addresses are Matrix's (`0000:XXXX`); all
  internal calls are unnamed (`FUN_0000_XXXX`).
- COAB catalog: 737 named functions across 33 `ovrNNN.cs` overlays, addresses
  annotated as `// sub_XXXXX` — but those are **Curse of the Azure Bonds**
  addresses from a *different binary*.
- Therefore addresses do NOT correspond across the two games. Matching must be
  on **behavior/structure**: control-flow shape, numeric constants, memory-word
  access patterns (e.g. `0x836`, `0x602`), string references, and call fan-out.
  The two share an engine lineage, so many routines are structurally similar.

## Approach: full-catalog-in-context classification (no embeddings)

The COAB catalog (~737 lines, name + overlay + role hint ≈ 9k tokens) fits
comfortably in qwen3-coder's context alongside one decompiled function. So per
Ghidra function: send the whole catalog + the function, ask for the top 1–3
COAB candidates with confidence and structural justification. 623 calls,
free, background. No vector store needed.

## Endpoint

- `http://192.168.2.2:11434` (Ollama native API, RTX 3090 host), model
  `qwen3-coder:30b`. Call `/api/generate` with `"stream": false`.

## Qwen settings (LOAD-BEARING — defaults produce garbage here)

```json
{
  "model": "qwen3-coder:30b",
  "options": {
    "temperature": 0.15,     // classification, not creativity — keep it low & stable
    "top_p": 0.9,
    "num_ctx": 32768,        // CRITICAL: Ollama defaults to 4096 and SILENTLY
                             // truncates the catalog, causing false "none"s.
                             // Must exceed catalog+function+prompt tokens.
    "num_predict": 700,      // enough for 3 candidates + reasoning JSON
    "seed": 42               // reproducible runs
  },
  "format": "json",          // force parseable JSON, no prose wrapper
  "stream": false
}
```

## Prompt template — v2 (calibrated after pilot mode-collapse)

Pilot v1 finding: qwen anchored 7/8 functions onto two generic catalog names
(`CMD_Compare`, `RunEclVm`) at "high" confidence, including three tiny
tail-call thunks that only resemble each other. v2 adds hard confidence
calibration, anti-anchoring, and degenerate-function handling.

SYSTEM (sent as the `system` field):
```
You are a reverse-engineering assistant matching decompiled functions between
two games that share the SSI Gold Box engine lineage. The TARGET function is
from Buck Rogers: Matrix Cubed (GAME.OVR). The CATALOG lists named functions
from Curse of the Azure Bonds (COAB), a different game on a related engine.

CRITICAL RULES:
- Memory addresses and sub_ numbers do NOT correspond between the two games.
  Never match on address equality. Match only on behavior: control-flow shape,
  distinctive numeric constants, memory-word access patterns, string use, and
  call structure.
- Many Matrix functions have NO COAB counterpart. "none" is correct and
  EXPECTED for a large fraction of functions. A wrong confident match is worse
  than "none". Do NOT force a match.

CONFIDENCE CALIBRATION (follow strictly):
- "high": ONLY when TWO OR MORE independent, specific structural features agree
  (e.g. a distinctive constant AND a matching loop/branch shape AND a
  consistent role). Rare. If you cannot name two concrete features, it is not
  high.
- "medium": one strong specific feature and a consistent role.
- "low": a plausible but weak resemblance, or role guess from vocabulary.
- Superficial similarity, generic control flow, or "this looks like a common
  dispatcher/comparator" is "low" at most — usually "none".

ANTI-ANCHORING:
- Do NOT repeatedly fall back to the same catalog entry (e.g. a comparator or
  VM-dispatch name) when unsure. If distinguishing evidence is absent, the
  answer is "none", never a generic familiar name used as a default.

DEGENERATE FUNCTIONS (return verdict "none", empty candidates):
- Fewer than ~8 meaningful statements, OR a single tail-call to another FUN_
  with no other logic (a thunk/wrapper), OR a body that only shuffles
  registers/undefined vars (unaff_, extraout_, in_AX artifacts) with no
  distinctive constants, loops, or string use. These carry insufficient signal
  to identify; do not guess. If several such stubs differ only by one constant,
  they are a thunk family, not a catalog match.
- If the decompilation carries corruption warnings (bad instruction data,
  overlapping instructions, halt_baddata, stack frame not set up normally), the
  body is unreliable — return "none" unless a string or distinctive constant
  still gives clear signal.

DISPATCH DISAMBIGUATION (avoid anchoring on the ECL VM):
- The ECL virtual machine (RunEclVm and similar) dispatches on NUMERIC opcode
  bytes read from a script stream. A function that dispatches on ASCII LETTER
  keys (e.g. 'M','V','A','Q','C','T') is a menu / keyboard input handler, NOT
  the ECL VM — prefer a menu/input/command catalog entry, or "none", over
  RunEclVm. Do not map every large switch/dispatch loop to the VM; the catalog
  has many distinct dispatchers.

- Output STRICT JSON only, matching the schema. No prose outside the JSON.
```

USER (per function):
```
COAB CATALOG (name | overlay | coab_addr | role-hint):
<catalog lines>

TARGET FUNCTION (Matrix Cubed GAME.OVR, entry <entry>):
<decompiled C>
REFERENCED STRINGS: <strings or "none">

Return JSON:
{
  "target_entry": "<entry>",
  "candidates": [
    {"coab_name": "<name from catalog, exact>", "coab_overlay": "<ovrNNN>",
     "confidence": "high|medium|low", "evidence": "<one sentence: the specific
     structural feature that supports this — constant, loop shape, call pattern>"}
  ],
  "verdict": "match|weak|none"
}
- 0 candidates with verdict "none" is valid and encouraged when appropriate.
- At most 3 candidates, best first. confidence must reflect structural evidence,
  not vocabulary coincidence.
```

## Output

- `generated/qwen_advisory/ghidra_coab_matches/<date>/matches.jsonl` — one line
  per Ghidra function (raw qwen JSON + call metadata: latency, returncode).
- A rollup TSV: entry, top_candidate, confidence, verdict — for scanning.
- A run manifest: model, settings, catalog hash, counts by verdict, failures.
- Resumable: skip entries already present in the JSONL on restart.

## Verification boundary

Every match is a **candidate**. High-confidence matches feed a later
agent/human verification pass that confirms against the actual COAB C# and the
Matrix binary before any COAB name or offset is adopted as Matrix evidence.
Low/weak/none are triage signal, not conclusions.
