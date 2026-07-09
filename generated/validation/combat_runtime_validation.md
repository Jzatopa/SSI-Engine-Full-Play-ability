# Combat Runtime Validation

This report validates the Caloris event-7 combat queue and records the current runtime combat scaffold.
It intentionally separates exact decoded encounter identity from unproven original combat mechanics.

## Summary

- Status: `pass`
- Checks: 5/5
- Boundary: Exact queue identity is verified from decoded local runtime evidence. DOS evidence currently anchors combat scene availability and save probes, not original turn-by-turn combat equivalence.

## Checks

| Check | Status | Note |
|---|---|---|
| `exact_event` | `pass` | Runtime probe targets Caloris GEO 017 event 7. |
| `exact_monster` | `pass` | Event 7 queues decoded monster id 52, RAM WARRIOR. |
| `dos_capture` | `pass` | A local DOS liveplay combat-input capture exists. |
| `save_pair` | `pass` | Pre/post combat save probes decode local party records. |
| `runtime_simulation` | `pass` | Current Python combat scaffold resolves the queued encounter deterministically. |

## Exact Encounter Evidence

- Map/event: GEO 017 event 7
- Encounter: `GEO 017 event 7: RAM WARRIOR`
- Monster: id `52`, `RAM WARRIOR`
- ECL address: `0x8C54`
- Resolution: `constant`
- Confidence: 98% - Constant SETUP_MONSTER operand resolves locally to MON0CHA id 52 in the generated source-runtime probe.

## DOS Evidence

- Combat capture: `/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens/14_after_combat_inputs.png`
- Capture SHA-256: `ce05dfe1e7b292bb09f6121ecb712a08605424597cd21726f5e4dafe58cd43d4`
- Pre SAVGAMA SHA-256: `ae0f4283336d809349e0dd08d997fd63920ae8be0e97d125eeb1da41b975f581`
- Post SAVGAMA SHA-256: `ae0f4283336d809349e0dd08d997fd63920ae8be0e97d125eeb1da41b975f581`
- Decoded save fields unchanged: `True`
- Confidence: 70% - Local DOS screenshots and saves are hashed; this pass does not OCR combat text or decode all save-state combat flags.

## Runtime Scaffold

- Seed: `52017`
- Status: `pass`
- Rounds: `12`
- Victory: `True`
- Defeat: `False`
- Confidence: 45% - Deterministic smoke of current Python combat scaffold only; damage/THAC0 fields are still derived from decoded ability scores, not proven original combat formulas.

## Next Steps

- Decode the SAVGAMA.DAT combat/session bytes around pre_combat versus post_combat saves.
- Capture an OCR-readable DOS combat transcript for Caloris event 7.
- Replace derived combat stats/formulas only when original combat fields or DOS turn logs validate them.
