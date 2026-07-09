from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any

from matrix_cubed.engine.events import EventCommand


@dataclass(frozen=True)
class QueuedCombat:
    map_id: int
    event_id: int
    monster_names: tuple[str, ...] = ()
    candidate_monster_names: tuple[str, ...] = ()
    unresolved_monster_refs: tuple[str, ...] = ()
    encounters: tuple[dict[str, Any], ...] = field(default_factory=tuple)

    @classmethod
    def from_command(cls, map_id: int, event_id: int, command: EventCommand) -> "QueuedCombat":
        return cls(
            map_id=map_id,
            event_id=event_id,
            monster_names=tuple(command.payload.get("monster_names") or ()),
            candidate_monster_names=tuple(command.payload.get("candidate_monster_names") or ()),
            unresolved_monster_refs=tuple(command.payload.get("unresolved_monster_refs") or ()),
            encounters=tuple(command.payload.get("encounters") or ()),
        )

    @property
    def display_names(self) -> tuple[str, ...]:
        return self.monster_names or self.candidate_monster_names or self.unresolved_monster_refs

    @property
    def summary(self) -> str:
        suffix = f": {', '.join(self.display_names)}" if self.display_names else ""
        return f"GEO {self.map_id:03} event {self.event_id}{suffix}"

    def to_dict(self) -> dict[str, Any]:
        return {
            "map_id": self.map_id,
            "event_id": self.event_id,
            "summary": self.summary,
            "monster_names": list(self.monster_names),
            "candidate_monster_names": list(self.candidate_monster_names),
            "unresolved_monster_refs": list(self.unresolved_monster_refs),
            "encounters": list(self.encounters),
        }
