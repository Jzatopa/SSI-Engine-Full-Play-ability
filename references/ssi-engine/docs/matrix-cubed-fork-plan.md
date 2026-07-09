# Matrix Cubed Java Fork Plan

## Direction

Use this fork as the primary Java runtime line for Buck Rogers: Matrix Cubed.
The runtime should compile from source and load original game data from a
user-provided directory. Prior Python/Pygame reconstruction artifacts remain
reference evidence, tests, and decoded-data notes, not the new runtime base.

## Current Baseline

- Upstream base: `https://gitlab.com/farmboy0/ssi-engine.git`
- Local fork branch: `matrix-cubed-fork`
- Base commit: `f10f96f`
- Build system: Maven
- Java target: 17
- License: GPLv3
- Local original game path:
  `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX`

## First Validation Targets

1. Build with `mvn test`.
2. Launch Matrix Cubed with `./scripts/run-matrix-cubed.sh`.
3. Run the first combat slice with `./scripts/run-combat-slice.sh`.
4. Run the first ECL combat scene with `./scripts/run-combat-scene.sh`.
5. Open the Swing combat debug scene with `./scripts/run-matrix-cubed-combat-debug.sh`.
6. Open the static combat asset proof with `./scripts/run-combat-static-screen.sh`.
7. Capture a repeatable title/menu/world smoke test.
8. Verify original data detection from `TITLE.DAX` MD5.
9. Verify first dungeon render, movement, search, save, and load.
10. Verify ECL dialog/menu behavior against local decoded evidence.
11. Identify and prioritize missing party/combat behavior.

## First Combat Slice

`main.MatrixCubedCombatSlice` is the first Java vertical slice for combat.
It loads `MON0CHA.DAX` block 52 from the original Matrix Cubed directory,
prints the decoded `RAM WARRIOR` combatant fields, and runs a deterministic
console fight against a fixed test hero.

Boundary: monster identity and basic fields are read from original files;
the attack loop is a visible deterministic scaffold, not original-validated
combat logic.

## First ECL Combat Scene

`main.MatrixCubedCombatScene` is the first headless harness that drives combat
through original ECL and the Java VM. It loads ECL 17, jumps to address
`0x8C54`, chooses `RETURN THE INSULT`, executes the scene text, runs the
original `LOAD_MON` opcodes, and reaches the Java `COMBAT` handler.

The current observed branch loads monster ids `47` and `52`, then the scaffold
combat consumes the first queued monster (`RAM G.D. GENNIE`) and resolves with
`COMBAT_RESULT=0`.

Boundary: this proves the VM can reach combat through original ECL in a
headless harness. It is not yet a Swing UI capture and still uses scaffold
combat formulas.

## Swing Combat Debug Scene

`main.MatrixCubedCombatDebug` opens the normal Swing UI and jumps to the
Caloris post-choice combat branch at ECL 17 address `0x8CBD`. This avoids the
pre-combat dialog choice and lets the player advance through the combat text
with Enter/Space.

Boundary: Xvfb smoke confirms the window starts without crashing, but visual
capture of the actual combat text is still a next validation step.

## Static Combat Asset Screen

`main.MatrixCubedCombatStaticScreen` loads original `MARSCOM.DAX` block 1 and
`COMSPR.DAX` block 1 with the Java DAX/VGA decoders and displays a fixed
Swing proof screen.

Boundary: this is not the original tactical-combat layout. It proves that the
Java fork can decode and display original combat-screen asset files in a
static state.

## Modernization Order

1. Keep classic rendering as the correctness baseline.
2. Add tests and launch scripts before changing gameplay behavior.
3. Separate engine core, original-data loading, UI rendering, and tools.
4. Add an optional enhanced asset override layer by original asset ID.
5. Generate HD assets into an ignored/output directory with provenance
   manifests; never overwrite decoded original assets.

## AI Asset Upgrade Rules

- The original extracted asset remains the source of truth.
- AI-generated/upscaled images are optional replacement assets.
- Every generated asset needs a manifest entry with source file, source id,
  source hash, generation model/tool, prompt/settings when available, and
  human review status.
- Runtime must fall back to original assets when no HD override exists.
- Do not bundle original or derivative game assets into a public engine
  release without rights clearance.
