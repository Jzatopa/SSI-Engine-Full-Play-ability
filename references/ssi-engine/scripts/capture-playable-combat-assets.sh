#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

GAME_DIR="${1:-../../generated/liveplay/first_map_capture/game}"
OUT="${2:-../../generated/java_combat_asset_renderer/playable_combat_assets_preview.png}"

mkdir -p target/playable-combat-assets
javac -d target/playable-combat-assets \
  src/main/java/engine/combat/BattlefieldBuffer.java \
  src/main/java/engine/combat/RecoveredBattlefieldGenerator.java \
  src/main/java/engine/combat/CombatPosition.java \
  src/main/java/engine/combat/Combatant.java \
  src/main/java/engine/combat/CombatTurnQueue.java \
  src/main/java/engine/combat/CombatEncounterFactory.java \
  src/main/java/engine/combat/CombatState.java \
  src/main/java/engine/combat/CombatController.java \
  src/main/java/engine/combat/RecoveredEnemyTactics.java \
  src/main/java/engine/combat/CombatAssetLoader.java \
  src/main/java/main/MatrixCubedPlayableCombatAssets.java

java -Djava.awt.headless=true -cp target/playable-combat-assets \
  main.MatrixCubedPlayableCombatAssets "$GAME_DIR" "--screenshot=$OUT"
