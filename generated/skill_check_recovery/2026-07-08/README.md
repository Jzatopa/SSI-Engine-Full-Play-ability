# Matrix Cubed Skill-Check Opcode Recovery - 2026-07-08

This artifact records ECL opcode `0x23` callsites as Matrix `SKILL_CHECK` candidates.
The current generic listing still labels them as `SURPRISE`; operand semantics are not implemented here.

## Summary

- opcode `0x23` callsites: 3
- callsites with constant first operand that maps to the recovered skill table: 1
- callsites with variable first operand: 2
- WHO prompt contexts recorded for correlation: 3

## 0x23 Callsites

| ECL block | Address | Operands | Candidate skill | Context |
|---:|---:|---|---|---|
| 34 | 0xA13D | `area2.event_scratch1, area2.event_scratch2, area2.event_scratch3, area2.word_002` | variable/unknown | region 0xA131 |
| 95 | 0x9705 | `79, area2.event_scratch0, area2.event_scratch1, scratch.word_0002` | 79 / Etiquette (.WHO 0x9B) | region 0x96F9 |
| 98 | 0xA21C | `area2.event_scratch1, area2.event_scratch2, area2.event_scratch3` | variable/unknown | region 0xA202 |

## Boundary

- `candidate_skill_id` is only filled when operand 0 is a numeric id present in the recovered skill table.
- Variable operands need backward dataflow through nearby `SAVE`, `RANDOM`, and branch rows before they can be named.
- No runtime opcode behavior, roll threshold, selected-character rule, advancement rule, or VM writeback rule is promoted by this artifact.
