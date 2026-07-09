# Engine Completion Plan — Full Gold Box Playability (2026-07-09)

Synthesis of a six-agent survey (VM opcode inventory, COAB subsystem map, Java
wiring status, docs staleness, qwen infra, validation gaps) run under James's
2026-07-09 project frame: near-preservation universal Java Gold Box engine,
COAB as porting source, Matrix Cubed first proof target, Curse of the Azure
Bonds second validation target. Supersedes the port-order tail of
`coab-combat-port-map.md` and the priority list in `coab-java-stub-audit.md`
(both remain valid as reference; this is the live tracker).

## 1. Where the engine actually stands (measured, not remembered)

**VM opcodes: 63 implemented / 4 wired-partial / 35 stubs.**
Wired-partial: COMBAT (real path, formulas mid-port), ENCOUNTER_MENU (state
machine real; movement min/max hardcoded), CALL (address whitelist), CLOCK2
(GameClock-wired; CLOCK1 unresolved).

**Matrix-selected stub opcodes (Lane 1 candidates):** SPACE_COMBAT (0x1F!),
SKILL_CHECK (0x23), PARTY_SKILL_CHECK2/3, FIND_ITEM (0x32), DESTROY_ITEM
(0x40), TREASURE / TREASURE_MULTICOIN / TREASURE_MULTICOIN4, ROB, GIVE_EXP,
DAMAGE, NPC_FIND, CLOCK1, SPELL, HAS_EFFECT, STORE, PARTY_STRENGTH,
PARTY_CHECK, SURPRISE, sound events (2C/43), PROGRAM, COPY_PROTECTION,
CLEAR_BOX, UNKNOWN_44/48-4B.

**Defects found by the survey (fix regardless of lane):**
- `GameMechanics`/`UnresolvedGameMechanics` are STILL not referenced by
  `VirtualMachine` — the evidence boundary exists, is tested, and is unused;
  every mechanic stub is a hand-rolled empty lambda instead.
- `PARTY_SKILL_CHECK3` unconditionally writes literal `100` — a fabricated
  success value in the live VM (violates evidence discipline; must become an
  unresolved-path, not a fake pass).
- Crash risks: `UNUSED_1F` and `UNUSED_42` have NO IMPL entry — dispatch =
  `NoSuchElementException`; both are selected by Curse/Krynn/Pool profiles,
  so this blocks Lane 2 titles at first touch. FRUA profile cannot even start
  (16 ambiguous opcode ids, zero disambiguation properties) — defer FRUA,
  documented.
- `CharacterBuckRogers.getMovementRate()/getTHACO()` still hardcode 0
  (character sheet shows UNRESOLVED); `BuckRogersEmbeddedItem.getType()`
  always UNRESOLVED (blocks equip-slot/weapon classification); door opening
  auto-succeeds (no lock/bash).

**COAB subsystem parity (approx lines → Java status):**
| Subsystem | ~Lines | Java status |
|---|---|---|
| Combat core (loop/AI/turns) | 8,208 | wired-partial (attack+AI+initiative+round live) |
| Spells / effects / affects | 7,357 | not-ported (largest remaining) |
| Exploration/encounter glue | 3,646 | wired |
| NPC lifecycle | 3,396 | wired-partial (`engine/party` ported, VM NPC_ADD/REMOVE thin, NPC_FIND stub) |
| Treasure & money | 3,323 | ported-unwired (`engine/loot` has zero external references) |
| Camp / rest / memorization | 1,778 | not-ported |
| Item use / equip / identify | 1,555 | not-ported |
| Shops / temple / training | 780 | not-ported |
| Clock / game time | 215 | wired-partial (CLOCK2 yes, CLOCK1 no) |

**Unwired ported packages:** `engine/loot` (11 classes/3 tests) and
`engine/party` (6/2). `engine/combat/map` got wired into the AI view by
GoldenBox's slice 2, but `CombatState.canMoveCurrentTo` still uses raw
manhattan distance (movement budget unwired).

## 2. Strategy (James-confirmed 2026-07-09)

Port COAB into the Java fork behind ruleset/profile boundaries — confirmed.
Two sequencing corrections applied:
1. **Lane 1 is playthrough-blocker-driven, not subsystem-driven.** Build the
   auto-playthrough prober; port what the game actually hits, in hit order.
2. **AD&D-only subsystems (spells/memorization/temple/training) wait for
   Lane 2**, where Curse of the Azure Bonds + COAB-as-oracle can validate
   them. Nothing gets ported that cannot be validated in its own lane.

## 3. Lane 0 — hygiene (1 pass, Sonnet, small)

a. Wire `GameMechanics` into `VirtualMachine` (constructor-injected,
   `UnresolvedGameMechanics` default); route ALL mechanic stubs through it;
   replace `PARTY_SKILL_CHECK3`'s literal 100 with the unresolved path.
b. Add safe no-op IMPL entries + log lines for `UNUSED_1F`/`UNUSED_42`.
c. Docs refresh: fold this plan's opcode inventory into
   `coab-java-stub-audit.md` (9 audit-gap opcodes found missing), fix stale
   COLLABORATION/port-map lines.

## 4. Lane 1 — Matrix Cubed full playability (playthrough-driven)

1. **Playthrough prober** (1 pass): extend the headless harness to walk
   Matrix ECL blocks and emit a ranked blocker report (stub opcode → hit
   count → ECL context). This replaces planning judgment with measurement;
   re-run after every slice.
2. **Wire what's already ported** (1–2 passes): `engine/loot` → TREASURE*/ROB
   opcodes; `engine/party` → NPC_ADD/NPC_REMOVE handlers (+ NPC_FIND via the
   labeled mod_id adaptation); movement budget → `CombatState.canMoveCurrentTo`.
3. **Skill checks** (1 pass): SKILL_CHECK/PARTY_SKILL_CHECK2/3 semantics via
   GameMechanics — GoldenBox's recovered 84-skill table + opcode-0x23
   callsite evidence (Etiquette/0x9B) is the Matrix input; COAB the flow.
4. **Blocker-ordered remainder** (prober decides; expected: GIVE_EXP, DAMAGE,
   FIND_ITEM/DESTROY_ITEM, STORE/shops-lite, CLOCK1 evidence, PARTY_STRENGTH/
   PARTY_CHECK, SURPRISE). Shops (ovr005, 780 lines) port when STORE blocks.
5. **SPACE_COMBAT**: Matrix-specific, no COAB source. Auto-resolve stub for
   playability first; real recovery from GAME.OVR/DOS later. Explicitly
   labeled.
6. **Character-sheet honesty**: movement/THAC0-analog decode when evidence
   lands (OpenClaw's .WHO lane); item type classification from ITEM0.

## 5. Lane 2 — Curse bring-up + AD&D subsystems

1. **COAB-as-oracle harness**: build COAB under mono (checkout at
   `~/.local/opt/coab`, bundles Curse data), script a combat, capture
   transcripts → cross-validate our initiative/attack/AI/dying/clock ports.
   Survey confirms this is feasible NOW and it upgrades all "COAB-faithful"
   claims to "validated against the running reference."
2. **Curse boot in our engine** (after Lane 0's crash fixes): detection
   already works; drive title screen → party → first dungeon.
3. **AD&D subsystem ports, validated by Curse**: spells/effects/affects
   (7.4k lines — split: effect plumbing first, spell tables as AD&D flavor),
   camp/rest/memorization, item use/equip/identify, temple/training.
4. Free authenticity check available immediately: diff
   `RecoveredEnemyTactics` (real Matrix GAME.OVR evidence) vs
   `QuickFightPlanner` decisions on identical states — a qwen triage job.

## 6. Token economy (how each pass runs)

qwen drafts (free: per-overlay C#→Java draft, test matrices, diff triage)
→ Sonnet hardens (boundary-respecting code + conformance tests)
→ Fable gates (integration seams, universal/flavor boundary, silent-error review)
→ GoldenBox runs disjoint claims in parallel (skills/DOS-capture/decode lanes).
Paid tokens concentrate at the gate. Commit before/after every agent round.

## 7. 3090 / qwen infrastructure

Verified healthy (2026-07-09): endpoint up, qwen3-coder:30b fully GPU-resident
(17.95GB VRAM, zero CPU spill), openclaw.json contextWindow==num_ctx on all
models, task-packet prompt present, five task scripts compile.

One build item (small, worth it): **`scripts/qwen_run.py`** — consolidate the
five scripts' duplicated HTTP/prompt/resume code into one generic runner with
verbs (classify/extract/review/skeptic/draft), JSONL checkpoint/resume as
standard, task-packet SYSTEM rules baked in. Closes the real gaps (no common
harness, no resume standard, no generic entrypoint OpenClaw can shell to).
Deliberate non-goals for a single-user rig: job queues, telemetry, metering,
model-dispatch rules — YAGNI; revisit only if multi-user.

qwen lanes for this plan: overlay draft translation (Lane 1.4/5.3 feeder),
test-matrix generation, RecoveredEnemyTactics-vs-planner diff triage (5.4),
recurring docs-staleness checks.

## 8. Definition of done

Lane 1: Matrix Cubed start→finish playthrough in the Java engine (prober
reports zero blocking stubs on the golden path; smoke suite covers create→
explore→fight→shop→level→save/load). Lane 2: Curse boots, plays its first
dungeon + combat with spells/rest/temple live, COAB-oracle transcripts match
on the ported subsystems. Then: licensing/attribution pass before any public
release (still deferred, still mandatory).
