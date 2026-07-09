# Qwen-Coder Advisory Orchestration - 2026-07-08

This pass used the local/network Qwen-Coder route as a bounded sidecar:

```bash
python3 scripts/qwen_coder_advisory.py --timeout 240
python3 scripts/qwen_coder_advisory.py --timeout 240 --only ghidra_triage ghidra_coab
```

The working model route was:

```bash
openclaw infer model run --model ollama/qwen3-coder:30b --prompt "..."
```

The unprefixed `qwen3-coder:30b` route was not used here because local testing
showed it resolves through the wrong provider. Qwen-Coder output in this pass
is advisory only: it narrows review targets, but no offset, function name,
opcode behavior, formula, map state, or port status is promoted without local
byte/source/test verification.

## Artifacts

- `scripts/qwen_coder_advisory.py` - repeatable orchestration script.
- `generated/qwen_advisory/2026-07-08/README.md` - run index.
- `generated/qwen_advisory/2026-07-08/*.prompt.txt` - exact prompts.
- `generated/qwen_advisory/2026-07-08/*.raw.txt` - raw Qwen-Coder outputs.
- `generated/qwen_advisory/2026-07-08/*.json` - run metadata.
- `generated/qwen_advisory/2026-07-08/ghidra_function_triage_candidates.tsv`
  - deterministic metadata-only candidate triage table for all 623 Ghidra
  `GAME.OVR` functions.

## Workstream Results

### 1. Ghidra Function Triage

Qwen-Coder reviewed the metadata-only triage method rather than classifying all
functions itself. The useful outcome is the validation boundary: the TSV is a
queueing aid only, and function subsystem labels need decompiled-body review,
string-reference tracing, and caller/callee checks before use.

Local assessment: useful for organizing the 623-function review, not evidence
of function semantics.

### 2. Ghidra to COAB Candidate Matching

Qwen-Coder produced only low-confidence candidates from the small selected
snippet sample:

| Ghidra file | Candidate COAB analogue | Confidence |
|---|---|---|
| `0000_6283_FUN_0000_6283.c` | `CleanupPlayersStateAfterCombat` | Low |
| `0000_6308_FUN_0000_6308.c` | `select_treasure` | Low |

Local assessment: weak output. Use only as a reminder to build a tighter
matching pass with more targeted snippets, call context, strings, and known
COAB functions. No match is confirmed.

### 3. Unknown Offset Clustering

Qwen-Coder aligned with the already verified `.WHO` evidence:

- gender/race/career at `0x26..0x28`;
- natural/base ability cluster at `0x10..0x16`;
- current ability cluster at `0x17..0x1D`;
- level candidate at `0x29`;
- credits at `0x2B` as little-endian 32-bit;
- experience at `0x2F` as little-endian 32-bit;
- age at `0x38`;
- hit point candidate at `0xE3`;
- `.STF` equipment and skill clusters remain candidates needing direct tests.

Local assessment: useful as a checklist because it matches existing evidence
and labels unresolved regions conservatively.

### 4. Test Matrix Generation

Qwen-Coder proposed useful next test categories around:

- Buck Rogers character fields and `.WHO` regressions;
- `PARTY_STRENGTH`, `PARTY_CHECK`, `SKILL_CHECK`, and
  `PARTY_SKILL_CHECK2/3`;
- `SURPRISE`, combat flow, initiative, quick-fight, and attack integration;
- `NPC_ADD`/`NPC_FIND`/`NPC_REMOVE`;
- `CLOCK1`/`CLOCK2`;
- `TREASURE*`, `ROB`, `FIND_ITEM`, and `DESTROY_ITEM`;
- save/load and cross-game compatibility boundaries.

Local assessment: useful as a planning matrix, but any COAB-derived opcode
mapping remains a candidate until checked against Matrix Cubed evidence.

### 5. Port-Map Comparison

Qwen-Coder's port-map review was partially stale against the current Java fork:
some items it called missing had already been ported as self-contained
packages or scaffolding. The useful part is the reminder to validate the final
integration surfaces: controller loop, attack resolver, pathing/LOS, effects,
movement, party/NPC/clock, loot, and VM opcode adapters.

Local assessment: use as a cautionary checklist, not as current status.

### 6. OCR/Text Sanity

Qwen-Coder confirmed the current evidence boundary:

- menu, save/load, and some combat UI OCR are usable as text reference;
- first-map viewport captures from the current DOSBox-X/Xvfb path are corrupted
  and must be rejected for map-state claims;
- no movement, map layout, or game-state claim should rely on those corrupted
  viewport frames.

Local assessment: useful and consistent with the capture artifacts.

## Next Local Validation Steps

1. Sample 10-20 functions from
   `generated/qwen_advisory/2026-07-08/ghidra_function_triage_candidates.tsv`
   by subsystem, opening each decompiled body and checking strings/callers.
2. Build a second Ghidra-to-COAB matcher with exact COAB function bodies and
   selected Ghidra call context instead of broad snippets.
3. Convert the test-matrix categories into focused Java tests only when the
   needed byte/source evidence exists.
4. Keep viewport OCR rejected until the DOS capture path produces readable map
   frames.
