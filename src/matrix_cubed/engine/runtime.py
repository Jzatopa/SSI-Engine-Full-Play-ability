"""Game runtime state for Matrix Cubed — movement, events, combat, party."""

from __future__ import annotations

from dataclasses import dataclass, field, replace
from typing import Literal

from matrix_cubed.data.repository import DialogChoice, Event, ReconstructedData, RuntimeMap
from matrix_cubed.engine.character import CharacterRecord, CharacterRoster, Party
from matrix_cubed.engine.combat import QueuedCombat
from matrix_cubed.engine.events import EventExecution, compile_event_commands


Direction = Literal["north", "east", "south", "west"]
Action = Literal["forward", "back", "left", "right", "turn_left", "turn_right"]

DIRECTIONS: tuple[Direction, ...] = ("north", "east", "south", "west")
VECTORS: dict[Direction, tuple[int, int]] = {
    "north": (0, -1),
    "east": (1, 0),
    "south": (0, 1),
    "west": (-1, 0),
}
WALL_INDEX: dict[Direction, int] = {"north": 0, "east": 1, "south": 2, "west": 3}
OPPOSITE: dict[Direction, Direction] = {"north": "south", "south": "north", "east": "west", "west": "east"}


@dataclass
class PartyState:
    """Legacy shared-resource party model. Kept for backward compatibility."""
    hp: int = 100
    credits: int = 0
    inventory: list[str] = field(default_factory=list)
    flags: set[str] = field(default_factory=set)


@dataclass(frozen=True)
class DialogSelection:
    map_id: int
    event_id: int
    label: str
    choice_index: int
    branch_target: int | None
    branch_target_hex: str
    selector: str
    evidence: str

    def to_dict(self) -> dict:
        return {
            "map_id": self.map_id,
            "event_id": self.event_id,
            "label": self.label,
            "choice_index": self.choice_index,
            "branch_target": self.branch_target,
            "branch_target_hex": self.branch_target_hex,
            "selector": self.selector,
            "evidence": self.evidence,
        }


@dataclass
class GameState:
    data: ReconstructedData
    map_id: int = 17
    row: int = 0
    col: int = 0
    facing: Direction = "south"
    wall_blocking: bool = True
    steps: int = 0
    active_event_id: int | None = None
    active_encounter: QueuedCombat | None = None
    last_execution: EventExecution | None = None
    last_dialog_selection: DialogSelection | None = None
    party: PartyState = field(default_factory=PartyState)
    log: list[str] = field(default_factory=list)

    # New: multi-character support
    roster: CharacterRoster = field(default_factory=CharacterRoster)
    active_party: Party = field(default_factory=Party)

    def add_character(self, char: CharacterRecord) -> None:
        """Register a character in the roster and optionally add to active party."""
        self.roster.add(char)
        if len(self.active_party.members) < 10:
            self.active_party.add(char)
            # Sync legacy state from first character
            self.party.credits = max(self.party.credits, char.credits)
            self.party.hp = max(self.party.hp, char.hp)

    def current_hp(self) -> int:
        """Return HP of the first active party member, falling back to shared HP."""
        if self.active_party.members:
            return self.active_party.member_hp[0] if self.active_party.member_hp else self.party.hp
        return self.party.hp

    def current_credits(self) -> int:
        """Return credits from first active party member, falling back to shared."""
        if self.active_party.members:
            return self.active_party.members[0].credits
        return self.party.credits

    def set_credits(self, amount: int) -> None:
        """Set credits in both legacy and active party stores."""
        self.party.credits = amount
        if self.active_party.members:
            old = self.active_party.members[0]
            new = replace(old, credits=amount)
            self.active_party.members[0] = new
            self.roster.replace(old.name, new)

    def apply_damage(self, amount: int) -> None:
        """Apply damage to both legacy and active_party. Rotates across members."""
        self.party.hp = max(0, self.party.hp - amount)
        if self.active_party.members and self.active_party.member_hp:
            # Track which member was last damaged, rotate to next
            if not hasattr(self, '_last_damaged_idx'):
                self._last_damaged_idx = -1
            n = len(self.active_party.member_hp)
            if n > 0:
                idx = (self._last_damaged_idx + 1) % n
                self._last_damaged_idx = idx
                self.active_party.member_hp[idx] = max(0, self.active_party.member_hp[idx] - amount)

    def add_credits(self, amount: int) -> None:
        """Add credits to both legacy and active party stores."""
        self.set_credits(self.party.credits + amount)

    @classmethod
    def start(cls, data: ReconstructedData, map_id: int = 17) -> "GameState":
        state = cls(data=data, map_id=map_id)
        start = next(
            (cell for cell in state.current_map.geo.cells if cell.event_id),
            state.current_map.geo.cells[0],
        )
        state.row = start.row
        state.col = start.col
        state.trigger_current_cell("entered map")
        return state

    @property
    def current_map(self) -> RuntimeMap:
        return self.data.map(self.map_id)

    @property
    def current_event(self) -> Event | None:
        if self.active_event_id is None:
            return None
        return self.current_map.events.get(self.active_event_id)

    def perform(self, action: Action) -> None:
        if action == "turn_left":
            self.facing = _turn(self.facing, -1)
            return
        if action == "turn_right":
            self.facing = _turn(self.facing, 1)
            return
        direction = self.facing
        if action == "back":
            direction = OPPOSITE[self.facing]
        elif action == "left":
            direction = _turn(self.facing, -1)
        elif action == "right":
            direction = _turn(self.facing, 1)
        self.move(direction)

    def move(self, direction: Direction) -> bool:
        dx, dy = VECTORS[direction]
        next_row = max(0, min(15, self.row + dy))
        next_col = max(0, min(15, self.col + dx))
        if (next_row, next_col) == (self.row, self.col):
            return False
        if self.wall_blocking and self.is_blocked(direction, next_row, next_col):
            self.log.append(f"blocked {direction}")
            return False
        self.row = next_row
        self.col = next_col
        self.steps += 1

        # Check for map transition (TILE_EXIT = event_id set, event_flag False)
        try:
            cell = self.current_map.geo.cell_at(self.row, self.col)
            if cell and cell.event_id and not cell.event_flag:
                transitions = self.data.cell_transition(self.map_id, self.row, self.col)
                if transitions:
                    transition = transitions[0]
                    target_col, target_row = self._target_entry_position(
                        transition.target_geo,
                        transition.target_col,
                        transition.target_row,
                    )
                    self.log.append(
                        f"TILE_EXIT: GEO {self.map_id:03} -> target {transition.target_geo} "
                        f"at ({target_col},{target_row})"
                    )
                    self.transition_to(transition.target_geo, target_col, target_row)
                elif cell.event_id in self.data.maps:
                    target_col, target_row = self._target_entry_position(cell.event_id)
                    self.log.append(
                        f"TILE_EXIT fallback: GEO {self.map_id:03} -> target {cell.event_id} "
                        f"at ({target_col},{target_row})"
                    )
                    self.transition_to(cell.event_id, target_col, target_row)
                else:
                    self.log.append(f"unpromoted local event cell {cell.event_id}")
        except (KeyError, IndexError, AttributeError) as exc:
            self.log.append(f"transition error: {exc}")

        self.trigger_current_cell("step")
        return True

    def transition_to(self, new_map_id: int, x: int, y: int) -> None:
        """Change to a new map at a specific position. Handles 1-122 map IDs."""
        try:
            _ = self.data.map(new_map_id)  # validate map exists
        except (KeyError, IndexError):
            self.log.append(f"transition failed: map {new_map_id} not loaded")
            return
        self.map_id = new_map_id
        self.row = max(0, min(15, y))
        self.col = max(0, min(15, x))
        self.steps += 1
        self.active_event_id = None
        self.log.append(f"entered GEO {new_map_id:03} at ({x},{y})")
        self.trigger_current_cell("entered map")

    def _target_entry_position(
        self,
        map_id: int,
        target_col: int | None = None,
        target_row: int | None = None,
    ) -> tuple[int, int]:
        if target_col is not None and target_row is not None:
            return target_col, target_row
        known = self.data.entry_position_for_map(map_id)
        if known is not None:
            return known
        return 1, 1

    def is_blocked(self, direction: Direction, next_row: int, next_col: int) -> bool:
        here = self.current_map.geo.cell_at(self.row, self.col)
        there = self.current_map.geo.cell_at(next_row, next_col)
        if here is None or there is None:
            return True
        return bool(here.walls[WALL_INDEX[direction]] or there.walls[WALL_INDEX[OPPOSITE[direction]]])

    def trigger_current_cell(self, reason: str) -> None:
        cell = self.current_map.geo.cell_at(self.row, self.col)
        new_id = cell.event_id if cell and cell.event_id else None
        if new_id != self.active_event_id:
            self.active_event_id = new_id
            if new_id is not None:
                self.log.append(f"{reason}: GEO {self.map_id:03} event {self.active_event_id}")

    def execute_current_event(self) -> EventExecution | None:
        event = self.current_event
        if event is None:
            self.last_execution = None
            return None
        source_map_id = self.map_id
        source_event_id = event.event_id
        execution = compile_event_commands(self.map_id, event, self._ecl_loads_for_event(event))
        for command in execution.commands:
            if command.kind == "show_text":
                continue
            if command.kind == "queue_combat":
                self.active_encounter = QueuedCombat.from_command(source_map_id, source_event_id, command)
                self.log.append(f"combat queued {self.active_encounter.summary}")
            elif command.kind == "grant_credits":
                amount = int(command.payload.get("amount") or 0)
                self.add_credits(amount)
            elif command.kind == "grant_item":
                item = str(command.payload.get("item") or "")
                if item:
                    self.party.inventory.append(item)
            elif command.kind == "damage_party":
                delta = int(command.payload.get("hp_delta") or 0)
                self.apply_damage(-delta)
            elif command.kind == "load_geo":
                target = int(command.payload["target_geo"])
                col = command.payload.get("target_col")
                row = command.payload.get("target_row")
                if col is None or row is None:
                    known = self.data.entry_position_for_map(target)
                    if known is None:
                        self.log.append(f"ECL LOAD GEO {target} skipped: no validated entry position")
                        continue
                    col, row = known
                self.log.append(
                    f"ECL LOAD GEO {target} from block {command.payload.get('ecl_block')} "
                    f"at ({col},{row})"
                )
                self.transition_to(target, int(col), int(row))
            elif command.kind == "mark_transition":
                self.party.flags.add(f"transition:{source_map_id}:{source_event_id}")
            elif command.kind == "mark_condition_checked":
                self.party.flags.add(f"checked:{source_map_id}:{source_event_id}")
        self.last_execution = execution
        return execution

    def _ecl_loads_for_event(self, event: Event) -> tuple:
        if event.target is None:
            return ()
        ecl_block = self.current_map.ecl_block
        if ecl_block is None:
            return ()
        return tuple(
            load
            for load in self.data.ecl_loads_for_block(ecl_block)
            if load.address and int(load.address, 16) == event.target
        )

    def execute_dialog_choice(self, choice_index: int = 0) -> DialogSelection | None:
        event = self.current_event
        if event is None or event.dialog is None:
            return None
        choice = next((row for row in event.dialog.choices if row.choice_index == choice_index), None)
        if choice is None:
            return None
        selection = self._select_dialog_choice(event, choice)
        self.last_dialog_selection = selection
        return selection

    def _select_dialog_choice(self, event: Event, choice: DialogChoice) -> DialogSelection:
        flag = f"dialog:{self.map_id}:{event.event_id}:{choice.choice_index}"
        self.party.flags.add(flag)
        branch = f" -> {choice.branch_target_hex}" if choice.branch_target_hex else ""
        self.log.append(f"dialog choice {event.event_id}: {choice.label}{branch}")
        return DialogSelection(
            map_id=self.map_id,
            event_id=event.event_id,
            label=choice.label,
            choice_index=choice.choice_index,
            branch_target=choice.branch_target,
            branch_target_hex=choice.branch_target_hex,
            selector=choice.selector,
            evidence=choice.evidence,
        )

    def execute_current_event_placeholder(self) -> str:
        execution = self.execute_current_event()
        return execution.event_type if execution else "no event"

    def snapshot(self) -> dict:
        event = self.current_event
        return {
            "map_id": self.map_id,
            "map_name": self.current_map.geo.name,
            "row": self.row,
            "col": self.col,
            "facing": self.facing,
            "steps": self.steps,
            "active_event_id": self.active_event_id,
            "active_event_type": event.event_type if event else None,
            "active_encounter": self.active_encounter.summary if self.active_encounter else None,
            "active_combat": self.active_encounter.to_dict() if self.active_encounter else None,
            "last_execution": self.last_execution.to_dict() if self.last_execution else None,
            "last_dialog_selection": self.last_dialog_selection.to_dict() if self.last_dialog_selection else None,
            "party": {
                "hp": self.party.hp,
                "credits": self.party.credits,
                "inventory": list(self.party.inventory),
                "flags": sorted(self.party.flags),
            },
            "active_party": {
                "count": len(self.active_party.members),
                "members": [c.name for c in self.active_party.members],
                "member_hp": list(self.active_party.member_hp),
                "total_hp": self.active_party.total_hp(),
            },
            "event_text": event.text if event else "",
            "encounters": [
                {
                    "monster_id": enc.monster_id,
                    "monster_ref": enc.monster_ref,
                    "monster_name": enc.monster_name,
                    "address": enc.address,
                    "kind": enc.kind,
                    "resolution": enc.resolution,
                    "candidate_resolution": enc.candidate_resolution,
                }
                for enc in (event.encounters if event else ())
            ],
            "log": list(self.log[-12:]),
        }


def _turn(direction: Direction, delta: int) -> Direction:
    index = DIRECTIONS.index(direction)
    return DIRECTIONS[(index + delta) % len(DIRECTIONS)]
