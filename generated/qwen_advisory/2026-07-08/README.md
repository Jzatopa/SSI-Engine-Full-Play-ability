# Qwen-Coder Advisory Run - 2026-07-08

Model: `ollama/qwen3-coder:30b`

Boundary: all outputs are candidate advisory analysis only. Local evidence and tests decide implementation.

Additional artifact: `generated/qwen_advisory/2026-07-08/ghidra_function_triage_candidates.tsv` covers all 623 Ghidra GAME.OVR candidate functions plus a header row.

| Job | Return | Raw Output | Prompt |
|---|---:|---|---|
| `ghidra_triage_rule_review` | 0 | `generated/qwen_advisory/2026-07-08/ghidra_triage_rule_review.raw.txt` | `generated/qwen_advisory/2026-07-08/ghidra_triage_rule_review.prompt.txt` |
| `ghidra_coab_candidate_matching` | 0 | `generated/qwen_advisory/2026-07-08/ghidra_coab_candidate_matching.raw.txt` | `generated/qwen_advisory/2026-07-08/ghidra_coab_candidate_matching.prompt.txt` |
| `unknown_offset_clustering` | 0 | `generated/qwen_advisory/2026-07-08/unknown_offset_clustering.raw.txt` | `generated/qwen_advisory/2026-07-08/unknown_offset_clustering.prompt.txt` |
| `test_matrix_generation` | 0 | `generated/qwen_advisory/2026-07-08/test_matrix_generation.raw.txt` | `generated/qwen_advisory/2026-07-08/test_matrix_generation.prompt.txt` |
| `port_map_comparison` | 0 | `generated/qwen_advisory/2026-07-08/port_map_comparison.raw.txt` | `generated/qwen_advisory/2026-07-08/port_map_comparison.prompt.txt` |
| `ocr_text_sanity` | 0 | `generated/qwen_advisory/2026-07-08/ocr_text_sanity.raw.txt` | `generated/qwen_advisory/2026-07-08/ocr_text_sanity.prompt.txt` |
