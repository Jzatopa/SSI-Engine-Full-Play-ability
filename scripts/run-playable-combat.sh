#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

mkdir -p target/playable-combat
javac -d target/playable-combat \
  src/main/java/engine/combat/BattlefieldBuffer.java \
  src/main/java/engine/combat/RecoveredBattlefieldGenerator.java \
  src/main/java/engine/combat/CombatPosition.java \
  src/main/java/engine/combat/Combatant.java \
  src/main/java/engine/combat/CombatTurnQueue.java \
  src/main/java/engine/combat/CombatEncounterFactory.java \
  src/main/java/engine/combat/CombatState.java \
  src/main/java/engine/combat/CombatController.java \
  src/main/java/engine/combat/RecoveredEnemyTactics.java \
  src/main/java/main/MatrixCubedPlayableCombat.java

java -cp target/playable-combat main.MatrixCubedPlayableCombat
