from __future__ import annotations

import importlib.util
from pathlib import Path

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.runtime import GameState


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "build_map_traversal_reference.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("build_map_traversal_reference", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    spec.loader.exec_module(module)
    return module


def test_traversal_reference_tracks_loaded_map_coverage() -> None:
    builder = load_builder()
    report = builder.build_reference(ROOT)

    assert report["summary"]["loaded_map_count"] == 25
    assert report["summary"]["covered_loaded_map_count"] == 20
    assert report["summary"]["uncovered_loaded_maps"] == [51, 80, 82, 113, 115]
    assert any(row["target_geo"] == 17 and row["target_loaded"] for row in report["ecl_loads"])
    assert any(row["target_geo"] == 33 and row["target_loaded"] for row in report["cell_edges"])


def test_runtime_ignores_unpromoted_local_event_cell_ids() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 17)
    state.map_id = 1
    state.wall_blocking = False
    state.row = 2
    state.col = 9
    state.facing = "east"

    assert state.move("east") is True
    assert state.map_id == 1
    assert "unpromoted local event cell 15" in state.log


def test_runtime_promotes_loaded_cell_transition_targets() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 17)
    state.map_id = 1
    state.wall_blocking = False
    state.row = 2
    state.col = 3
    state.facing = "east"

    assert state.move("east") is True
    assert state.map_id == 33
