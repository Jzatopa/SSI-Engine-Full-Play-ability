from __future__ import annotations

from pathlib import Path

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.runtime import GameState


ROOT = Path(__file__).resolve().parents[1]


def test_caloris_event_7_resolves_ram_warrior() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 17)
    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == 7)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("test")

    event = state.current_event
    assert event is not None
    assert event.event_type == "combat"
    assert any(enc.monster_name == "RAM WARRIOR" for enc in event.encounters)

    result = state.execute_current_event_placeholder()
    assert result == "combat"
    assert state.active_encounter is not None
    assert "RAM WARRIOR" in state.active_encounter.summary
    assert state.active_encounter.monster_names == ("RAM WARRIOR",)
    assert state.last_execution is not None
    assert [command.kind for command in state.last_execution.commands] == ["show_text", "queue_combat"]
    combat_command = state.last_execution.commands[1]
    assert combat_command.payload["monster_names"] == ["RAM WARRIOR"]
    assert combat_command.payload["encounters"][0]["monster_id"] == 52


def test_wall_blocking_prevents_out_of_bounds_move() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 17)
    state.row = 0
    state.col = 0
    assert state.move("north") is False
    assert (state.row, state.col) == (0, 0)


def test_reward_event_promotes_runtime_commands() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    map_id, reward_event = next(
        (map_id, event)
        for map_id, runtime_map in data.maps.items()
        for event in runtime_map.events.values()
        if event.event_type == "reward"
    )
    state = GameState.start(data, map_id)
    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == reward_event.event_id)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("test")

    execution = state.execute_current_event()
    assert execution is not None
    assert "grant_credits" in [command.kind for command in execution.commands]
    assert state.party.credits == 100
    assert state.party.inventory == [f"event {reward_event.event_id} reward placeholder"]


def test_dynamic_table_encounter_keeps_candidate_monsters() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 21)
    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == 4)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("test")

    event = state.current_event
    assert event is not None
    assert event.event_type == "combat"
    assert event.encounters[0].resolution == "candidate_table"
    assert event.encounters[0].candidate_resolution is not None

    execution = state.execute_current_event()
    assert execution is not None
    combat_command = next(command for command in execution.commands if command.kind == "queue_combat")
    assert combat_command.payload["monster_names"] == []
    assert combat_command.payload["unresolved_monster_refs"] == ["area2.event_scratch7"]
    assert combat_command.payload["candidate_monster_names"] == [
        "MER. WARRIOR",
        "PIRATE LEADER",
        "RAM WARRIOR",
        "SECURITY ROBOT",
    ]
    assert state.active_encounter is not None
    assert "RAM WARRIOR" in state.active_encounter.summary
    assert state.active_encounter.monster_names == ()
    assert state.active_encounter.unresolved_monster_refs == ("area2.event_scratch7",)


def test_caloris_romney_dialog_choice_executes_in_runtime() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 17)
    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == 20)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("test")

    event = state.current_event
    assert event is not None
    assert event.dialog is not None
    assert [choice.label for choice in event.dialog.choices] == ["HELP ROMNEY"]

    execution = state.execute_current_event()
    assert execution is not None
    assert [command.kind for command in execution.commands][:2] == ["show_text", "offer_dialog_choices"]

    selection = state.execute_dialog_choice(0)
    assert selection is not None
    assert selection.label == "HELP ROMNEY"
    assert selection.branch_target is None
    assert "dialog:17:20:0" in state.party.flags
    assert state.snapshot()["last_dialog_selection"]["label"] == "HELP ROMNEY"


def test_caloris_autodoc_dialog_choice_executes_in_runtime() -> None:
    data = ReconstructedData.from_generated(ROOT / "generated")
    state = GameState.start(data, 17)
    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == 28)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("test")

    event = state.current_event
    assert event is not None
    assert event.dialog is not None
    assert [choice.label for choice in event.dialog.choices] == ["SOMEONE ELSE?"]

    selection = state.execute_dialog_choice(0)
    assert selection is not None
    assert selection.label == "SOMEONE ELSE?"
    assert "dialog:17:28:0" in state.party.flags


def main() -> None:
    test_caloris_event_7_resolves_ram_warrior()
    test_wall_blocking_prevents_out_of_bounds_move()
    test_reward_event_promotes_runtime_commands()
    test_dynamic_table_encounter_keeps_candidate_monsters()
    test_caloris_romney_dialog_choice_executes_in_runtime()
    test_caloris_autodoc_dialog_choice_executes_in_runtime()


if __name__ == "__main__":
    main()
