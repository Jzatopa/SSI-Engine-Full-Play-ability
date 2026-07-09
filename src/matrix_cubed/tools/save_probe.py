from __future__ import annotations

import argparse
import json
from dataclasses import asdict
from pathlib import Path

from matrix_cubed.formats.save import read_saved_character


def main() -> None:
    parser = argparse.ArgumentParser(description="Inspect Matrix Cubed .WHO/.STF save characters.")
    parser.add_argument("save_dir", type=Path)
    args = parser.parse_args()

    rows = []
    character_paths = sorted({*args.save_dir.glob("*.WHO"), *args.save_dir.glob("CHRDATA*.SAV")})
    for who_path in character_paths:
        character = read_saved_character(who_path)
        row = asdict(character)
        row["who_path"] = str(character.who_path)
        row["stf_path"] = str(character.stf_path) if character.stf_path else None
        rows.append(row)
    print(json.dumps({"save_dir": str(args.save_dir), "characters": rows}, indent=2))


if __name__ == "__main__":
    main()
