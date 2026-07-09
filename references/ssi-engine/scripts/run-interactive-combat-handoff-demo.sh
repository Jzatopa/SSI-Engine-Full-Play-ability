#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

GAME_DIR="${1:-../../generated/liveplay/first_map_capture/game}"

mkdir -p target/interactive-combat-handoff
javac -d target/interactive-combat-handoff \
  src/main/java/engine/combat/BattlefieldBuffer.java \
  src/main/java/engine/combat/RecoveredBattlefieldGenerator.java \
  src/main/java/engine/combat/CombatPosition.java \
  src/main/java/engine/combat/Combatant.java \
  src/main/java/engine/combat/CombatTurnQueue.java \
  src/main/java/engine/combat/CombatState.java \
  src/main/java/engine/combat/CombatController.java \
  src/main/java/engine/combat/RecoveredEnemyTactics.java \
  src/main/java/engine/combat/CombatEncounterFactory.java \
  src/main/java/engine/combat/CombatSession.java \
  src/main/java/engine/combat/CombatSessionResult.java \
  src/main/java/engine/combat/CombatUiBridge.java \
  src/main/java/engine/combat/HeadlessCombatUiBridge.java \
  src/main/java/engine/combat/EclCombatBridge.java \
  src/main/java/engine/combat/CombatAssetLoader.java \
  src/main/java/main/MatrixCubedPlayableCombatAssets.java \
  src/main/java/main/SwingCombatUiBridge.java \
  src/main/java/main/MatrixCubedInteractiveHandoffDemo.java

java -cp target/interactive-combat-handoff main.MatrixCubedInteractiveHandoffDemo "$GAME_DIR"
