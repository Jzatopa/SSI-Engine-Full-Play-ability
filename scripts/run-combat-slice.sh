#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEFAULT_GAME_DIR="/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX"
GAME_DIR="${1:-${MATRIX_CUBED_GAME_DIR:-$DEFAULT_GAME_DIR}}"
LOCAL_MVN="/home/jzatopa/.openclaw/workspace/matrix-cubed-re/.tools/apache-maven-3.9.9/bin/mvn"
MVN_BIN="${MAVEN_BIN:-$(command -v mvn || true)}"

if [[ -z "$MVN_BIN" && -x "$LOCAL_MVN" ]]; then
  MVN_BIN="$LOCAL_MVN"
fi

if [[ ! -d "$GAME_DIR" ]]; then
  echo "Matrix Cubed game directory not found: $GAME_DIR" >&2
  echo "Pass a path as the first argument or set MATRIX_CUBED_GAME_DIR." >&2
  exit 1
fi

if [[ -z "$MVN_BIN" ]]; then
  echo "Maven not found. Install Maven or set MAVEN_BIN=/path/to/mvn." >&2
  exit 1
fi

cd "$ROOT_DIR"
"$MVN_BIN" -q -DskipTests package
java -cp "target/classes:target/*" main.MatrixCubedCombatSlice "$GAME_DIR"
