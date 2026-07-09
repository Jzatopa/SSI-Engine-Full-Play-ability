from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any

from matrix_cubed.data.repository import EclLoadRef, EncounterRef, Event


@dataclass(frozen=True)
class EventCommand:
    kind: str
    label: str
    payload: dict[str, Any] = field(default_factory=dict)
    evidence: str = ""

    def to_dict(self) -> dict[str, Any]:
        return {
            "kind": self.kind,
            "label": self.label,
            "payload": self.payload,
            "evidence": self.evidence,
        }


@dataclass(frozen=True)
class EventExecution:
    map_id: int
    event_id: int
    event_type: str
    commands: tuple[EventCommand, ...]

    @property
    def summary(self) -> str:
        return ", ".join(command.kind for command in self.commands) or "no-op"

    def to_dict(self) -> dict[str, Any]:
        return {
            "map_id": self.map_id,
            "event_id": self.event_id,
            "event_type": self.event_type,
            "summary": self.summary,
            "commands": [command.to_dict() for command in self.commands],
        }


def compile_event_commands(
    map_id: int,
    event: Event,
    ecl_loads: tuple[EclLoadRef, ...] = (),
) -> EventExecution:
    commands: list[EventCommand] = []
    if event.text:
        commands.append(
            EventCommand(
                kind="show_text",
                label="Show decoded event text",
                payload={"text": event.text},
                evidence="event_atlas text extraction",
            )
        )
    if event.dialog and event.dialog.choices:
        commands.append(_dialog_command(event))
    for load in ecl_loads:
        commands.append(_ecl_load_command(load))

    if event.event_type == "combat":
        commands.append(_combat_command(event))
    elif event.event_type == "reward":
        commands.extend(_reward_commands(event))
    elif event.event_type == "damage":
        commands.append(
            EventCommand(
                kind="damage_party",
                label="Apply placeholder party damage",
                payload={"hp_delta": -10},
                evidence="event classification until ECL operand semantics are promoted",
            )
        )
    elif event.event_type == "transition":
        commands.append(
            EventCommand(
                kind="mark_transition",
                label="Record map/event transition placeholder",
                payload={"target": event.target},
                evidence="event classification and target address",
            )
        )
    elif event.event_type == "condition":
        commands.append(
            EventCommand(
                kind="mark_condition_checked",
                label="Record condition evaluation placeholder",
                payload={"target": event.target},
                evidence="event classification until branch conditions are promoted",
            )
        )
    elif not commands:
        commands.append(
            EventCommand(
                kind="inspect_only",
                label="No runtime behavior promoted yet",
                payload={"target": event.target},
                evidence="event remains in pseudocode/structured form",
            )
        )

    return EventExecution(map_id=map_id, event_id=event.event_id, event_type=event.event_type, commands=tuple(commands))


def _ecl_load_command(load: EclLoadRef) -> EventCommand:
    return EventCommand(
        kind="load_geo",
        label="Execute decoded ECL LOAD FILES map transition",
        payload={
            "ecl_block": load.ecl_block,
            "target_geo": load.target_geo,
            "target_col": load.map_pos_x,
            "target_row": load.map_pos_y,
            "address": load.address,
            "raw_operands": load.raw_operands,
        },
        evidence=load.evidence,
    )


def _combat_command(event: Event) -> EventCommand:
    encounters = [_encounter_payload(encounter) for encounter in event.encounters]
    names = sorted({row["monster_name"] for row in encounters if row["monster_name"]})
    unresolved_refs = sorted({row["monster_ref"] for row in encounters if not row["monster_name"] and row["monster_ref"]})
    candidate_names = sorted(
        {
            candidate["name"]
            for encounter in event.encounters
            for candidate in _candidate_monsters(encounter)
            if candidate.get("name")
        }
    )
    return EventCommand(
        kind="queue_combat",
        label="Queue decoded encounter",
        payload={
            "encounters": encounters,
            "monster_names": names,
            "unresolved_monster_refs": unresolved_refs,
            "candidate_monster_names": candidate_names,
        },
        evidence="SETUP_MONSTER operands cross-referenced to MON0CHA.DAX",
    )


def _dialog_command(event: Event) -> EventCommand:
    assert event.dialog is not None
    return EventCommand(
        kind="offer_dialog_choices",
        label="Offer decoded ECL dialog choices",
        payload={
            "target": event.dialog.target,
            "target_hex": event.dialog.target_hex,
            "incoming": list(event.dialog.incoming),
            "summary": event.dialog.summary,
            "choices": [
                {
                    "label": choice.label,
                    "choice_index": choice.choice_index,
                    "branch_target": choice.branch_target,
                    "branch_target_hex": choice.branch_target_hex,
                    "selector": choice.selector,
                    "evidence": choice.evidence,
                }
                for choice in event.dialog.choices
            ],
        },
        evidence="generated ECL dialog reference branch-target attachment",
    )


def _encounter_payload(encounter: EncounterRef) -> dict[str, Any]:
    return {
        "monster_id": encounter.monster_id,
        "monster_ref": encounter.monster_ref,
        "monster_name": encounter.monster_name,
        "address": encounter.address,
        "kind": encounter.kind,
        "resolution": encounter.resolution,
        "max_distance": encounter.max_distance,
        "copies": encounter.copies,
        "pic_ref": encounter.pic_ref,
        "stats": encounter.stats,
        "candidate_resolution": encounter.candidate_resolution,
    }


def _candidate_monsters(encounter: EncounterRef) -> tuple[dict[str, Any], ...]:
    if not encounter.candidate_resolution:
        return ()
    return tuple(encounter.candidate_resolution.get("candidate_monsters") or ())


def _reward_commands(event: Event) -> list[EventCommand]:
    return [
        EventCommand(
            kind="grant_credits",
            label="Grant placeholder credits",
            payload={"amount": 100},
            evidence="reward classification until specific ECL reward operands are promoted",
        ),
        EventCommand(
            kind="grant_item",
            label="Grant placeholder inventory marker",
            payload={"item": f"event {event.event_id} reward placeholder"},
            evidence="reward classification until item-table operands are promoted",
        ),
    ]
