# Matrix Skill-Check Opcode Recovery - 2026-07-08

This pass records current ECL evidence for Matrix Cubed skill-check opcode
recovery. It does not implement VM behavior.

## Local Evidence

- `references/ssi-engine/docs/coab-java-stub-audit.md` records that Matrix maps
  opcode `0x23` to `SKILL_CHECK`, while the generic ECL disassembler currently
  labels opcode `0x23` as `SURPRISE`.
- `scripts/recover_skill_check_opcodes.py` scans `generated/ecl1_disasm/` and
  emits repeatable artifacts under
  `generated/skill_check_recovery/2026-07-08/`.
- Current ECL listings contain three opcode `0x23` callsites:

| ECL block | Address | Operands | Recovered skill-table link |
|---:|---:|---|---|
| 34 | `0xA13D` | `area2.event_scratch1, area2.event_scratch2, area2.event_scratch3, area2.word_002` | variable first operand; unresolved |
| 95 | `0x9705` | `79, area2.event_scratch0, area2.event_scratch1, scratch.word_0002` | skill id `79`, `Etiquette`, `.WHO` offset `0x9B` |
| 98 | `0xA21C` | `area2.event_scratch1, area2.event_scratch2, area2.event_scratch3` | variable first operand; unresolved |

The same script records three direct `WHO` opcode prompt contexts for later
correlation:

- ECL35 `0x8EB5`: `WHO WILL REPROGRAM?`
- ECL35 `0xA168`: `WHO WILL FAST TALK?`
- ECL82 `0x8CB5`: `WHO MAKES THE ATTEMPT?`

## Boundary

The only promoted skill-name fact in this pass is the constant operand at
ECL95 `0x9705`: operand `79` maps through the recovered skill table to
`Etiquette` and `.WHO` offset `0x9B`.

The following remain unresolved:

- operand roles for the variable `0x23` callsites;
- whether the last operand is always a result/writeback slot;
- success roll, threshold, selected-character, party-skill, and advancement
  rules;
- whether the generic disassembler should be renamed globally or made
  game-profile aware;
- Java VM/combat integration.

## Qwen-Coder Sidecar

`scripts/qwen_skill_check_advisory.py` runs three bounded advisory jobs through
`ollama/qwen3-coder:30b`:

- `opcode_23_callsite_review`
- `who_skill_prompt_correlation`
- `disassembler_label_boundary`

The prompts and raw outputs are saved under
`generated/skill_check_recovery/2026-07-08/qwen/`. The outputs are advisory
only; local bytes, generated artifacts, source review, and tests decide what
gets accepted.

Accepted Qwen guidance:

- leave the generic disassembler label unchanged for now;
- require a Matrix-aware/profile-gated rename if opcode `0x23` is relabeled in
  the future;
- trace variable operands through local dataflow before naming skills or
  result slots;
- validate operand roles with VM/DOS execution before implementation.

Rejected or still unsupported Qwen claims:

- prompt wording alone does not prove `WHO WILL REPROGRAM?` maps to
  `Repair Computer`, `WHO WILL FAST TALK?` maps to `Fast Talk/Convince`, or
  `WHO MAKES THE ATTEMPT?` maps to `Jury Rig`;
- nearby `COMPARE Values: X == area2.selected_player_in_combat` rows prove
  WHO selection loops, not skill-check behavior;
- the current evidence does not prove all three `0x23` callsites share
  identical operand roles.

## Validation

Focused tests:

```bash
PYTHONPATH=src python3 -m pytest -q tests/test_skill_check_recovery.py
```

Generation:

```bash
python3 scripts/recover_skill_check_opcodes.py
python3 scripts/qwen_skill_check_advisory.py --timeout 300
```
