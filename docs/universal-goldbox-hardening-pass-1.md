# Universal Gold Box Hardening Pass 1

## Goal

Keep the `ssi-engine` fork usable as a multi-title Gold Box engine while Matrix
Cubed combat is reconstructed. Matrix-specific rendering and evidence must not
leak into Forgotten Realms, Krynn, FRUA, or Countdown profiles.

## Changes

- Game profile discovery now uses an explicit registry of all 13 property
  resources already shipped by the engine. This works from Maven tests and a
  packaged JAR; the previous implementation assumed classpath resources were a
  filesystem directory and failed under the test classpath.
- `SsiEclCombatAdapter` now reads abilities through each character's own
  `getAbilityScoreTypes()` and levels through its own `ClassSelection`. It no
  longer imports Buck Rogers ability or class enums.
- Buck inventory evidence remains guarded by `CharacterBuckRogers`; other
  character formats report that no title-specific inventory evidence is
  attached.
- `CombatUiBridgeSelector` routes only `Buck Rogers - Matrix Cubed` to the
  Matrix Swing combat renderer.
- Other configured games use `LegacyGoldBoxCombatUiBridge`, which preserves
  the upstream noninteractive `COMBAT_RESULT=0` behavior until their tactical
  combat is implemented. This is an explicit compatibility path, not a claim
  that combat occurred.
- Shared headless transcripts now identify themselves as Gold Box rather than
  Matrix Cubed.

## COAB use

COAB was used as secondary evidence for subsystem boundaries: character-owned
effective stats and class levels, inventory/equipment, effects, movement,
combat state, and title-specific rules. No COAB source, AD&D table, record
offset, spell behavior, or combat formula was copied into this pass.

## Local multi-game validation

The optional integration suite accepts `-Dssi.test.curse.dir=...` or
`SSI_CURSE_DIR`; it defaults to the local Downloads fixture when present.

Verified local title hashes/configuration and all recognized content files for:

- Curse of the Azure Bonds
- Pool of Radiance
- Pools of Darkness
- Secret of the Silver Blades

The suite also loads every discovered Curse `MONCHA` id, constructs a neutral
combat seed without Buck types, and verifies the explicit legacy combat result.
Matrix Cubed and Curse were both launched from the packaged classpath and
reached normal mode startup.

## Remaining universal boundaries

- ECL opcode and `AbstractCharacter` value configuration are static globals;
  simultaneous different-game engine instances are unsafe. Sequential games
  are the supported mode.
- Non-Matrix tactical combat is not reconstructed. The legacy bridge preserves
  story flow but does not apply damage, spells, treasure, morale, or effects.
- `CombatEncounterFactory` still contains the recovered Matrix battlefield and
  default party. The legacy bridge does not execute its tactical controller,
  but a future pass should select encounter factories by profile too.
- Inventory/equipment for Forgotten Realms formats is still absent from the
  Java character model.
- The desktop was internally responsive, but X11 captures were black for both
  Matrix and Curse in this Wayland session; this did not isolate a Curse defect.

## Useful additional game fixtures

No additional games were required for this pass. The next most useful fixtures
for broader coverage are Countdown to Doomsday, Champions/Death Knights/Dark
Queen of Krynn, Gateway/Treasures of the Savage Frontier, and FRUA. Their
profiles exist but were not exercised against local files here.
