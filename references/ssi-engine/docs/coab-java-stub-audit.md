# COAB-to-Java Stub Audit

## Scope and evidence boundary

Audited against Java fork `f10f96f` plus the local Matrix Cubed changes and
COAB commit `9dc46f1`. COAB is evidence for Gold Box control flow and subsystem
shape. It is not evidence that AD&D record offsets, spell tables, item layouts,
or formulas apply to Matrix Cubed. The inspected COAB checkout has no root
license file, so no COAB source is copied here.

`GameMechanics` is the universal extension boundary. An empty `OptionalInt`
means unresolved; it must not silently become a successful zero.

## VM stubs COAB can clarify

| Java gap | COAB evidence | Clarification | Matrix status / next evidence |
|---|---|---|---|
| `PARTY_STRENGTH` | `ovr025.player_strength_group`, effective-stat/affect code | Aggregate an effective strength measure, not raw bytes blindly. | Universal stub. Recover Matrix opcode semantics and strength modifiers from `GAME.OVR`. |
| `PARTY_CHECK` | COAB party/player iteration and status logic | A predicate over eligible party members with title-specific selectors. | Universal stub; Matrix opcode profile does not select it. |
| `PARTY_SKILL_CHECK2/3` | `Player.SkillLevel`, COAB command dispatch | Resolve eligible members, skill id, roll/threshold, and output destination separately. | Matrix uses three-argument form. Skill records beyond proven pilot-rocket byte remain undecoded. |
| `SURPRISE` | `ovr003.CMD_PartySurprise` / `CMD_Surprise` | Encounter initiative state, not a UI-only flag. | Universal stub; Matrix maps opcode `23` to `SKILL_CHECK`. |
| `SKILL_CHECK` | COAB skill access and command framework | Title rules choose skill namespace and success convention. | Matrix-specific stub; decode skill table and opcode result convention. |
| `SPACE_COMBAT` | no portable COAB equivalent | Game-specific encounter subsystem. | Matrix-only unresolved handler; recover from `GAME.OVR`. |
| `TREASURE*` | `ovr003.CMD_Treasure`, `ovr006` distribution, `MoneySet` | Build a temporary treasure pool, then explicitly take/share/discard. | Universal inventory/treasure stub; Matrix ITEM0/MON0ITM layout differs. |
| `ROB` | `ovr008.RobMoney` / `RobItems` | Money scaling and probabilistic item loss are separate operations. | Universal stub; Matrix credits and item weight semantics need recovery. |
| encounter movement constants | `ovr008.calc_group_movement` | Min/max come from effective member movement, including effects. | Replaces hard-coded `6/12` once movement fields/effects are decoded. |
| `FIND_ITEM` | `ovr003.CMD_FindItem` | Search party inventories by script item identity and set selected-character state. | Universal stub; Matrix item identity/name is partly decoded, inventory chains are not complete. |
| `DESTROY_ITEM` | `ovr003.CMD_DestroyItems` | Remove matching items according to title quantity/equipped rules. | Universal stub; must not mutate recovered raw items yet. |
| `CLOCK2` | `ovr003.CMD_EclClock`, `ovr021.NormalizeClock` / `step_game_time` | Normalize minute/hour/day/year carries and process timed effects/rest. | Wired 2026-07-09: `VirtualMachine` routes `CLOCK2(amount, slot)` into `VirtualMemory.stepClock`, with ECL clock ids `0x4BC6..0x4BCC` backed by COAB word offsets `(0x6A00 + id*2) & 0xFFFF`. Effect timeout hooks and party aging remain deferred. |
| `CLOCK1` | not resolved in this pass | One-argument clock variant used by Pool of Radiance config. | Still unresolved/no-op; do not guess a fixed slot without title-specific evidence. |
| `NPC_ADD/FIND/REMOVE` | `ovr003.CMD_AddNPC`, `ovr017.load_npc` | NPC lifecycle includes load, party limits, morale/control, and treasure share. | Universal party service with title character decoder. |
| `WHO` | COAB selected-player and eligibility patterns | Select a party member and update selected-character memory consistently. | Existing Java UI path needs conformance tests, not COAB code copying. |
| `SPELL` | `Spells`, `SpellList`, `ovr010/013/014/023/024` | Casting is ruleset-owned: availability, target, range, save, damage/effect, duration. | Universal stub. Buck Rogers needs its own power/skill evidence; AD&D spell tables are not portable. |
| `HAS_EFFECT` | `Affect`, `ovr024`, `ovr025.FindAffect` | Effects require stable id, duration/data, add/remove hooks, and serialization. | Universal effect service; Matrix effect records not decoded. |
| `GIVE_EXP` | COAB post-combat/level flow and character EXP field | Award policy and splitting are ruleset/title-owned; persistence is character-format-owned. | Java can mutate EXP, but opcode split/mode semantics remain unresolved. |
| `UNKNOWN_44`, `48`-`4B` | no verified COAB mapping | Opcode numbers are profile-dependent; never infer semantics from numeric equality alone. | Explicit game-opcode stub until a title profile and local ECL evidence identify each operation. |

## Non-VM Java placeholders COAB can clarify

| Java gap | Clarification |
|---|---|
| `Character*.getMovementRate()` | COAB proves movement is stored/effective state modified by haste/slow and encumbrance. Matrix field is not yet proven. |
| `Character*.getTHACO()` | Ruleset calculation belongs behind mechanics; COAB AD&D THAC0 cannot be used for Buck Rogers. |
| `Character*.getSkills()` | COAB demonstrates typed skills and serialized values. Matrix needs a dedicated skill enum and verified offsets. |
| `CharacterForgottenRealms` item/equipped methods | COAB Item serialization can guide the AD&D adapter only. |
| `CharacterSheetImpl` fake values | Corrected: decoded movement/THAC0 are shown when positive; unsupported equipment/AC/damage fields say `UNRESOLVED`. |
| dungeon door opening | COAB map collision/action flow can guide a universal door interaction service; wall/door bit meanings remain title data. |
| renderer TODO ranges | UI/resource-format work, not mechanics; COAB may visually validate but does not define Matrix assets. |
| FRUA menu parsing | FRUA-specific profile adapter; unrelated to Matrix completion. |

## Combat stubs

COAB clarifies the required universal components: combatant preparation,
effective stats/effects, initiative/movement, occupancy for multi-tile actors,
pathfinding (`SteppingPath` and `ovr025/032`), target validation, action
selection, attacks, saves, morale, spells, victory, experience, treasure, and
state restoration. Current Matrix combat has verified asset loading, battlefield
generation, VM handoff, turn state, and partial original AI/item evidence, but
its range, terrain movement, initiative, damage, morale, equipped-weapon
selection, and several AI scores remain explicitly unresolved. COAB algorithms
must not be substituted for those Matrix formulas without DOS or `GAME.OVR`
validation.

## Completion order

1. Decode the complete Matrix skill and inventory/equipped records.
2. Connect `GameMechanics` through the VM and provide a Matrix implementation.
3. Replace encounter movement constants with decoded effective movement.
4. Implement Matrix item find/destroy and treasure using verified item identity.
5. Recover Matrix clock/effect hooks and NPC lifecycle.
6. Complete combat terrain/pathing, initiative, weapon/range/damage, morale,
   and outcome persistence against original captures.
7. Implement AD&D/COAB-informed adapters separately and run cross-title
   conformance tests to keep universal code honest.
