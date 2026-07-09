from __future__ import annotations

import argparse
import json
from pathlib import Path

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.runtime import GameState


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--generated-dir", type=Path, default=Path("generated"))
    parser.add_argument("--map-id", type=int, default=17)
    parser.add_argument("--event-id", type=int)
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--out", type=Path)
    args = parser.parse_args()

    data = ReconstructedData.from_generated(args.generated_dir)
    state = GameState.start(data, args.map_id)
    if args.event_id is not None:
        cell = next((cell for cell in state.current_map.geo.cells if cell.event_id == args.event_id), None)
        if cell is None:
            raise SystemExit(f"event {args.event_id} not found on GEO {args.map_id:03}")
        state.row = cell.row
        state.col = cell.col
        state.trigger_current_cell("probe")
    if args.execute:
        state.execute_current_event()
    payload = state.snapshot()
    text = json.dumps(payload, indent=2) + "\n"
    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(text, encoding="utf-8")
    else:
        print(text, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
