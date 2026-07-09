# Matrix Skill Recovery - 2026-07-08

This pass recovered the Buck Rogers skill id/name table and wired verified
skill-byte reads into the Java `ssi-engine` fork.

## Evidence

- `START.EXE` contains the visible Pascal-string skill table. The recovered
  sequence starts with the category/header string `technical Skills`, then
  skill ids `1..84` from `Repair Electrical` through `Planetary Survival`.
- `GAME.OVR` decompiled functions access skill values as
  `character + 0x4C + skill_id`:
  - `generated/ghidra/deep_game_ovr_payload/decompiled/1000_8467_FUN_1000_8467.c`
  - `generated/ghidra/deep_game_ovr_payload/decompiled/2000_b375_FUN_2000_b375.c`
  - `generated/ghidra/deep_game_ovr_payload/decompiled/2000_5605_FUN_2000_5605.c`
- The prior verified `PILOT_ROCKET` byte at `.WHO` offset `0x7F` now aligns
  with skill id `0x33`: `0x4C + 0x33 = 0x7F`.
- Saved `.WHO`/`.SAV` fixtures validate non-zero values at the recovered
  offsets. Examples:
  - TST2: `First Aid=25`, `Astrogation=70`, `Pilot Rocket=85`,
    `Maneuver in 0G=85`, `Notice=40`;
  - CHRDATA1/CAR1 medic fixture: `Treat Light Wounds=50`,
    `Treat Critical Wounds=75`, `Treat Stun/Paralysis=60`,
    `Battle Tactics=5`, `Befriend Animal=55`.

## Generated Artifacts

- `scripts/recover_matrix_skills.py`
- `generated/skill_recovery/2026-07-08/README.md`
- `generated/skill_recovery/2026-07-08/skill_names.tsv`
- `generated/skill_recovery/2026-07-08/skill_names.json`
- `generated/skill_recovery/2026-07-08/sample_skill_values.tsv`
- `generated/skill_recovery/2026-07-08/sample_skill_values.json`

Qwen-Coder advisory outputs are under:

- `generated/skill_recovery/2026-07-08/qwen/`

All Qwen outputs are advisory only. The useful recommendations were to keep
skill id 0 as a header/non-skill, expose non-zero skills from `getSkills()`,
and test exact byte-backed sample values. Qwen also correctly warned that
specific id/name alignment depends on local START.EXE table validation.

## Java Changes

Nested repo commit:

```text
fdddd9f Decode Buck Rogers skill table
```

Changed:

- `character.buckrogers.CharacterSkillBuckRogers`
  - now enumerates all 84 recovered real skills;
  - each enum value carries `skillId` and computed `.WHO` offset
    `0x4C + skillId`.
- `data.character.AbstractCharacter`
  - adds protected `readFileUnsigned(int offset)` so game-specific byte tables
    can be read without bloating the universal `CharacterValueType` table.
- `data.character.CharacterBuckRogers`
  - `getSkillValue()` reads any Buck skill from its recovered offset;
  - `getSkills()` returns only non-zero skills.
- `data.character.CharacterBuckRogersTest`
  - covers synthetic multi-skill values;
  - regresses TST2 rocket-jock skill bytes;
  - regresses CHRDATA1/CAR1 medic skill bytes.

## Boundaries

- Skill names are recovered from local START.EXE, not guessed.
- Skill byte offsets are recovered from GAME.OVR accessors and validated with
  sample bytes.
- Skill-check opcode semantics, success thresholds, advancement rules, and
  combat/VM integration remain future work.
- `.STF` files remain inventory/item records in the current evidence; this
  pass does not treat them as the skill table.

## Validation

- `python3 scripts/recover_matrix_skills.py` -> 84 skills, 265 non-zero sample
  values.
- `python3 scripts/qwen_skill_recovery_advisory.py --timeout 300` -> 3 Qwen
  jobs, all return code 0.
- `../../.tools/apache-maven-3.9.9/bin/mvn -q -Dtest=data.character.CharacterBuckRogersTest test`
  in `references/ssi-engine` -> pass.
- `../../.tools/apache-maven-3.9.9/bin/mvn -q test` in `references/ssi-engine`
  -> pass.
- `references/ssi-engine/scripts/run-combat-scene.sh` ->
  `Final COMBAT_RESULT=0`.
