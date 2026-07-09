# Java Combat Interactive VM Handoff Scaffold Pass 1

Date: 2026-07-01

## Goal

Prepare the last bridge between VM/ECL combat and an interactive combat UI.

Previous pass:

```text
LOAD_MON -> queued monsters -> COMBAT -> SsiEclCombatAdapter -> EclCombatBridge -> CombatState -> headless resolver -> COMBAT_RESULT
```

This pass makes the resolver pluggable:

```text
LOAD_MON -> queued monsters -> COMBAT -> CombatState -> CombatUiBridge -> COMBAT_RESULT
```

The default remains deterministic/headless so tests and CI keep working.  OpenClaw can now inject a Swing bridge so the VM-created `CombatState` is played interactively, then returns `COMBAT_RESULT`.

## Files added

```text
references/ssi-engine/src/main/java/engine/combat/CombatSession.java
references/ssi-engine/src/main/java/engine/combat/CombatSessionResult.java
references/ssi-engine/src/main/java/engine/combat/CombatUiBridge.java
references/ssi-engine/src/main/java/engine/combat/HeadlessCombatUiBridge.java
references/ssi-engine/src/main/java/main/SwingCombatUiBridge.java
references/ssi-engine/src/main/java/main/MatrixCubedInteractiveHandoffDemo.java
references/ssi-engine/src/test/java/engine/combat/CombatUiBridgeTest.java
references/ssi-engine/scripts/run-interactive-combat-handoff-demo.sh
docs/java-combat-interactive-vm-handoff-scaffold-pass-1.md
```

## Files modified

```text
references/ssi-engine/src/main/java/engine/VirtualMachine.java
references/ssi-engine/src/main/java/engine/combat/EclCombatBridge.java
HANDOFF.md
```

## What changed

### `CombatSession`

Wraps the VM-created `CombatState` and the ECL monster seeds into a single object that can be handed to any resolver.

### `CombatSessionResult`

Carries the final result back to the VM bridge:

```text
combatResult
state
transcript
victory / defeat flags
action count
interactive flag
resolver name
```

### `CombatUiBridge`

Interface for combat handoff:

```java
CombatSessionResult resolve(CombatSession session);
```

### `HeadlessCombatUiBridge`

The prior deterministic auto-resolver extracted into a bridge implementation.  This keeps the VM path testable without Swing.

### `SwingCombatUiBridge`

A synchronous Swing handoff scaffold.  It accepts a VM-created `CombatSession`, launches the original-asset combat screen with that state, polls until victory/defeat, and returns a `CombatSessionResult`.

If the environment is headless, it safely falls back to `HeadlessCombatUiBridge`.

### `EclCombatBridge`

Now accepts any `CombatUiBridge`.

Default constructor:

```java
new EclCombatBridge()
```

uses headless mode.

Interactive path:

```java
new EclCombatBridge(new CombatEncounterFactory(), new SwingCombatUiBridge(gameDir))
```

uses the Swing handoff scaffold.

### `VirtualMachine`

Now exposes:

```java
setCombatUiBridge(CombatUiBridge uiBridge)
```

This rebuilds the internal `SsiEclCombatAdapter` with an `EclCombatBridge` that uses the injected UI bridge.

## OpenClaw integration target

In the Java runtime setup, after VM creation:

```java
vm.setCombatUiBridge(new SwingCombatUiBridge(Path.of("/path/to/MATRIX")));
```

Then ECL should flow like this:

```text
ECL LOAD_MON
  -> VM queues original monster resources

ECL COMBAT
  -> VM drains queued monsters
  -> SsiEclCombatAdapter converts them into MonsterSeed records
  -> CombatEncounterFactory creates CombatState
  -> SwingCombatUiBridge launches playable original-asset combat screen
  -> player resolves combat
  -> CombatSessionResult returns combatResult
  -> VirtualMachine writes COMBAT_RESULT
  -> ECL continues
```

## Run demo

From `references/ssi-engine`:

```bash
scripts/run-interactive-combat-handoff-demo.sh
```

In a graphical environment, it attempts to launch `SwingCombatUiBridge`.

In a headless environment, it falls back to `HeadlessCombatUiBridge` and still proves the same handoff API.

## Validation performed here

Maven is unavailable in this environment.  I validated with direct `javac`.

Headless bridge compile/run:

```text
passed
```

Swing handoff scaffold compile/run in headless fallback mode:

```text
passed
```

The demo resolved a four-Ratwurst encounter through the new session bridge and returned:

```text
COMBAT_RESULT=0
```

## OpenClaw validation commands

```bash
cd references/ssi-engine

mvn test -Dtest=RecoveredBattlefieldGeneratorTest,CombatStateTest,CombatTurnQueueTest,CombatControllerTest,CombatAssetLoaderTest,CombatEncounterFactoryTest,EclCombatBridgeTest,CombatUiBridgeTest

scripts/run-interactive-combat-handoff-demo.sh ../../generated/liveplay/first_map_capture/game
scripts/run-playable-combat-assets.sh ../../generated/liveplay/first_map_capture/game

mvn -q -DskipTests package
java -cp "target/classes:target/*" main.MatrixCubedCombatScene
```

Then wire the production VM creation path to:

```java
vm.setCombatUiBridge(new SwingCombatUiBridge(gameDir));
```

## Boundaries

This is a scaffold pass, not final proven interactive VM continuation.

Still needs OpenClaw/live runtime validation:

- Full Maven build.
- VM creation site identification.
- Injection of `SwingCombatUiBridge` into the real runtime VM.
- Confirming `COMBAT` blocks/resumes cleanly on the correct thread.
- Confirming Swing input focus and keyboard actions during ECL handoff.
- Confirming `COMBAT_RESULT` branch behavior after the screen closes.
- Exact original combat math and encounter placement.

## Why this is the right handoff point

The project now has all of the pieces required for an interactive combat loop:

```text
ECL LOAD_MON / COMBAT
  -> VM adapter
  -> CombatState
  -> pluggable CombatUiBridge
  -> original-asset Swing combat screen
  -> CombatSessionResult
  -> COMBAT_RESULT
```

The remaining work is mainly live OpenClaw runtime wiring and validation.
