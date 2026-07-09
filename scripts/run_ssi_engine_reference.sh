#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SSI_ENGINE_DIR="${SSI_ENGINE_DIR:-$ROOT/references/ssi-engine}"
MATRIX_DIR="${MATRIX_DIR:-/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX}"
MAVEN="${MAVEN:-$ROOT/.tools/apache-maven-3.9.9/bin/mvn}"

if [ ! -d "$SSI_ENGINE_DIR" ]; then
  echo "Missing ssi-engine checkout: $SSI_ENGINE_DIR" >&2
  exit 1
fi

if [ ! -d "$MATRIX_DIR" ]; then
  echo "Missing Matrix Cubed game directory: $MATRIX_DIR" >&2
  exit 1
fi

if [ ! -d "$SSI_ENGINE_DIR/target/classes" ]; then
  if [ ! -x "$MAVEN" ]; then
    echo "Missing Maven executable: $MAVEN" >&2
    exit 1
  fi
  (cd "$SSI_ENGINE_DIR" && "$MAVEN" package)
fi

cd "$SSI_ENGINE_DIR"
exec java -cp 'target/classes:target/*' main.Goldbox "$MATRIX_DIR" --no-title
