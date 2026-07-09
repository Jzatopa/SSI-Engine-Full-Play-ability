from __future__ import annotations

from pathlib import Path

from dataclasses import replace

from matrix_cubed.data.repository import Event
from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.runtime import GameState


ROOT = Path(__file__).resolve().parents[1]


def test_cell_transition_lookup_uses_promoted_traversal_evidence() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")

    transitions = data.cell_transition(1, 2, 4)

    assert len(transitions) == 1
    assert transitions[0].source_geo == 1
    assert transitions[0].target_geo == 33
    assert transitions[0].target_col is None
    assert transitions[0].target_row is None
    assert transitions[0].evidence == "promoted_transition"


def test_ecl_load_lookup_preserves_loaded_geo_references() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")

    loads = data.ecl_loads_for_block(17)

    assert any(load.target_geo == 17 for load in loads)
    assert all(load.evidence for load in loads)


def test_ecl_load_coordinates_become_target_entry_positions() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")

    assert data.entry_position_for_map(1) == (9, 4)
    assert data.entry_position_for_map(34) == (7, 15)
    assert data.entry_position_for_map(64) == (11, 15)


def test_reconstructed_data_exposes_map_engine_repository_adapter() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")

    ecl = data.find_ecl(17)

    assert ecl is not None
    assert ecl["geo"].map_id == 17
    assert ecl["ecl_block"] == 17


def test_promoted_cell_transition_uses_validated_target_coordinates() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState(data=data, map_id=112, row=4, col=2, wall_blocking=False)

    assert state.move("east") is True

    assert state.map_id == 34
    assert (state.col, state.row) == (7, 15)


def test_unloaded_or_unpromoted_traversal_rows_are_not_runtime_transitions() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")

    assert data.cell_transition(1, 2, 10) == []


def test_move_applies_promoted_cell_transition() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState(data=data, map_id=1, row=2, col=3, wall_blocking=False)

    assert state.move("east") is True

    assert state.map_id == 33
    assert (state.col, state.row) == (1, 1)
    assert "TILE_EXIT: GEO 001 -> target 33 at (1,1)" in state.log


def test_move_does_not_promote_unresolved_loaded_event_id_without_evidence() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState(data=data, map_id=1, row=2, col=9, wall_blocking=False)

    assert state.move("east") is True

    assert state.map_id == 1
    assert "unpromoted local event cell 15" in state.log


def test_exact_ecl_load_file_target_executes_load_geo_command() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    runtime_map = data.map(34)
    event = Event(
        event_id=99,
        target=0x8063,
        text="",
        event_type="transition",
        structured="synthetic exact LOAD FILES address",
        pseudocode="",
        encounters=(),
    )
    data.maps[34] = replace(runtime_map, events={**runtime_map.events, 99: event})
    state = GameState(data=data, map_id=34, row=0, col=0, active_event_id=99)

    execution = state.execute_current_event()

    assert execution is not None
    assert any(command.kind == "load_geo" for command in execution.commands)
    assert (state.map_id, state.col, state.row) == (34, 7, 15)
    assert "transition:34:99" in state.party.flags
    assert any("ECL LOAD GEO 34 from block 34 at (7,15)" == row for row in state.log)
