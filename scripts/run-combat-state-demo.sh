#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

mkdir -p target/combat-state-demo
javac -d target/combat-state-demo \
  src/main/java/engine/combat/BattlefieldBuffer.java \
  src/main/java/engine/combat/RecoveredBattlefieldGenerator.java \
  src/main/java/engine/combat/CombatPosition.java \
  src/main/java/engine/combat/Combatant.java \
  src/main/java/engine/combat/CombatTurnQueue.java \
  src/main/java/engine/combat/CombatEncounterFactory.java \
  src/main/java/engine/combat/CombatState.java \
  src/main/java/main/MatrixCubedCombatStateDemo.java

java -cp target/combat-state-demo main.MatrixCubedCombatStateDemo
