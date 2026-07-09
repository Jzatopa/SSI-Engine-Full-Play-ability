from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from matrix_cubed.formats.geo import GeoCell, GeoMap


@dataclass(frozen=True)
class Monster:
    monster_id: int
    name: str
    stats: dict[str, int]
    candidate_fields: dict[str, int]
    visuals: dict[str, Any]


@dataclass(frozen=True)
class EncounterRef:
    address: str
    kind: str
    resolution: str
    monster_id: int | None
    monster_ref: str
    monster_name: str | None
    max_distance: str | None
    copies: str | None
    pic_ref: str | None
    stats: dict[str, int] | None
    candidate_resolution: dict[str, Any] | None = None


@dataclass(frozen=True)
class DialogChoice:
    label: str
    choice_index: int
    branch_target: int | None
    branch_target_hex: str
    selector: str
    evidence: str


@dataclass(frozen=True)
class DialogRef:
    status: str
    target: int
    target_hex: str
    incoming: tuple[str, ...]
    summary: str
    choices: tuple[DialogChoice, ...]


@dataclass(frozen=True)
class Event:
    event_id: int
    target: int | None
    text: str
    event_type: str
    structured: str
    pseudocode: str
    encounters: tuple[EncounterRef, ...]
    dialog: DialogRef | None = None


@dataclass(frozen=True)
class RuntimeMap:
    geo: GeoMap
    ecl_block: int | None
    wallsets: tuple[str, ...]
    events: dict[int, Event]


@dataclass(frozen=True)
class CellTransitionRef:
    """Evidence-backed map transition from a decoded traversal cell edge."""

    source_geo: int
    row: int
    col: int
    target_geo: int
    evidence: str
    target_col: int | None = None
    target_row: int | None = None


@dataclass(frozen=True)
class EclLoadRef:
    """Evidence-backed ECL LOAD FILES reference to a GEO block."""

    ecl_block: int
    target_geo: int
    evidence: str
    address: str = ""
    raw_operands: str = ""
    map_pos_x: int | None = None
    map_pos_y: int | None = None


class ReconstructedData:
    def __init__(
        self,
        maps: dict[int, RuntimeMap],
        monsters: dict[int, Monster],
        cell_transitions_by_cell: dict[tuple[int, int, int], list[CellTransitionRef]] | None = None,
        ecl_loads_by_block: dict[int, list[EclLoadRef]] | None = None,
    ):
        self.maps = maps
        self.monsters = monsters
        self.cell_transitions_by_cell = cell_transitions_by_cell or {}
        self.ecl_loads_by_block = ecl_loads_by_block or {}
        self.entry_positions_by_map = self._build_entry_positions()

    @classmethod
    def from_generated(cls, generated_dir: Path) -> "ReconstructedData":
        runtime_seed = _read_json(generated_dir / "viewer" / "matrix_cubed_runtime_seed.json")
        monster_rows = _read_json(generated_dir / "data_model" / "mon0cha_monsters.json")
        monsters = {
            int(row["id"]): Monster(
                monster_id=int(row["id"]),
                name=row["name"],
                stats=dict(row.get("stats") or {}),
                candidate_fields=dict(row.get("matrix_variant_candidates") or {}),
                visuals=dict(row.get("visuals") or {}),
            )
            for row in monster_rows
        }
        maps = {int(row["id"]): _runtime_map_from_seed(row) for row in runtime_seed.get("maps", [])}
        cell_transitions, ecl_loads = _load_traversal_refs(generated_dir / "traversal" / "map_traversal_reference.json")
        return cls(maps, monsters, cell_transitions, ecl_loads)

    def map(self, map_id: int) -> RuntimeMap:
        return self.maps[map_id]

    def find_ecl(self, map_id: int) -> dict[str, Any] | None:
        """Compatibility adapter for MapEngine's older repository protocol."""

        runtime_map = self.maps.get(map_id)
        if runtime_map is None:
            return None
        return {
            "geo": runtime_map.geo,
            "ecl_block": runtime_map.ecl_block,
            "events": runtime_map.events,
            "wallsets": runtime_map.wallsets,
        }

    def cell_transition(self, source_geo: int, row: int, col: int) -> list[CellTransitionRef]:
        """Return promoted cell transitions proven by the traversal reference."""

        return self.cell_transitions_by_cell.get((source_geo, row, col), [])

    def ecl_loads_for_block(self, ecl_block: int) -> list[EclLoadRef]:
        """Return decoded ECL GEO load references for future event-transition work."""

        return self.ecl_loads_by_block.get(ecl_block, [])

    def entry_position_for_map(self, map_id: int) -> tuple[int, int] | None:
        """Return a validated target entry position as (col, row), if known."""

        return self.entry_positions_by_map.get(map_id)

    def _build_entry_positions(self) -> dict[int, tuple[int, int]]:
        positions: dict[int, tuple[int, int]] = {}
        for refs in self.ecl_loads_by_block.values():
            for ref in refs:
                if ref.map_pos_x is None or ref.map_pos_y is None:
                    continue
                target = self.maps.get(ref.target_geo)
                if target is None or target.ecl_block != ref.ecl_block:
                    continue
                positions.setdefault(ref.target_geo, (ref.map_pos_x, ref.map_pos_y))
        return positions


def _load_traversal_refs(
    traversal_path: Path,
) -> tuple[dict[tuple[int, int, int], list[CellTransitionRef]], dict[int, list[EclLoadRef]]]:
    """Load transition evidence generated by scripts/build_map_traversal_reference.py."""

    cell_transitions: dict[tuple[int, int, int], list[CellTransitionRef]] = {}
    ecl_loads: dict[int, list[EclLoadRef]] = {}
    if not traversal_path.is_file():
        return cell_transitions, ecl_loads

    traversal = _read_json(traversal_path)
    entry_positions_by_target = _target_entry_positions_from_traversal(traversal)
    for row in traversal.get("cell_edges", []):
        if row.get("interpretation") != "promoted_transition" or not row.get("target_loaded"):
            continue
        source_geo = int(row["source_geo"])
        cell_row = int(row["row"])
        cell_col = int(row["col"])
        target_geo = int(row["target_geo"])
        target_col, target_row = entry_positions_by_target.get(target_geo, (None, None))
        ref = CellTransitionRef(
            source_geo=source_geo,
            row=cell_row,
            col=cell_col,
            target_geo=target_geo,
            evidence=str(row.get("interpretation") or ""),
            target_col=target_col,
            target_row=target_row,
        )
        cell_transitions.setdefault((source_geo, cell_row, cell_col), []).append(ref)

    for row in traversal.get("ecl_loads", []):
        if not row.get("target_loaded"):
            continue
        ecl_block = int(row["ecl_block"])
        ref = EclLoadRef(
            ecl_block=ecl_block,
            target_geo=int(row["target_geo"]),
            evidence=str(row.get("row") or row.get("address") or ""),
            address=str(row.get("address") or ""),
            raw_operands=str(row.get("raw_operands") or ""),
            map_pos_x=_optional_int(row.get("map_pos_x")),
            map_pos_y=_optional_int(row.get("map_pos_y")),
        )
        ecl_loads.setdefault(ecl_block, []).append(ref)

    return cell_transitions, ecl_loads


def _target_entry_positions_from_traversal(traversal: dict[str, Any]) -> dict[int, tuple[int, int]]:
    positions: dict[int, tuple[int, int]] = {}
    by_target: dict[int, list[tuple[int, int, int]]] = {}
    for row in traversal.get("ecl_loads", []):
        if not row.get("target_loaded"):
            continue
        target_geo = row.get("target_geo")
        x = _optional_int(row.get("map_pos_x"))
        y = _optional_int(row.get("map_pos_y"))
        if target_geo is None or x is None or y is None:
            continue
        by_target.setdefault(int(target_geo), []).append((int(row["ecl_block"]), x, y))

    for target_geo, refs in by_target.items():
        # Prefer the target map's own ECL block when present. That marks map-entry
        # coordinates without borrowing a route-specific LOAD FILES row.
        own_block_refs = [(x, y) for ecl_block, x, y in refs if ecl_block == target_geo]
        unique_own = set(own_block_refs)
        if len(unique_own) == 1:
            positions[target_geo] = next(iter(unique_own))
            continue
        unique_any = {(x, y) for _, x, y in refs}
        if len(unique_any) == 1:
            positions[target_geo] = next(iter(unique_any))
    return positions


def _optional_int(value: Any) -> int | None:
    if value is None:
        return None
    return int(value)


def _runtime_map_from_seed(row: dict[str, Any]) -> RuntimeMap:
    cells = tuple(
        GeoCell(
            row=int(cell["row"]),
            col=int(cell["col"]),
            north=int(cell["walls"][0]),
            east=int(cell["walls"][1]),
            south=int(cell["walls"][2]),
            west=int(cell["walls"][3]),
            event_id=int(cell.get("eventId") or 0),
            event_flag=bool(cell.get("eventFlag")),
            door=int(cell.get("door") or 0),
        )
        for cell in row.get("cells", [])
    )
    events = {int(event_id): _event_from_seed(int(event_id), event) for event_id, event in (row.get("events") or {}).items()}
    return RuntimeMap(
        geo=GeoMap(map_id=int(row["id"]), name=row["name"], cells=cells),
        ecl_block=row.get("eclBlock"),
        wallsets=tuple(row.get("wallsets") or ()),
        events=events,
    )


def _event_from_seed(event_id: int, row: dict[str, Any]) -> Event:
    encounters = tuple(_encounter_from_seed(item) for item in row.get("encounters", []))
    return Event(
        event_id=event_id,
        target=row.get("target"),
        text=row.get("text", ""),
        event_type=row.get("type", "unknown"),
        structured=row.get("structured", ""),
        pseudocode=row.get("pseudocode", ""),
        encounters=encounters,
        dialog=_dialog_from_seed(row.get("dialog")),
    )


def _dialog_from_seed(row: dict[str, Any] | None) -> DialogRef | None:
    if not row:
        return None
    return DialogRef(
        status=row.get("status", ""),
        target=int(row.get("target") or 0),
        target_hex=row.get("targetHex", ""),
        incoming=tuple(row.get("incoming") or ()),
        summary=row.get("summary", ""),
        choices=tuple(_dialog_choice_from_seed(choice) for choice in row.get("choices", [])),
    )


def _dialog_choice_from_seed(row: dict[str, Any]) -> DialogChoice:
    branch_target = row.get("branchTarget")
    return DialogChoice(
        label=row.get("label", ""),
        choice_index=int(row.get("choiceIndex") or 0),
        branch_target=int(branch_target) if branch_target is not None else None,
        branch_target_hex=row.get("branchTargetHex", ""),
        selector=row.get("selector", ""),
        evidence=row.get("evidence", ""),
    )


def _encounter_from_seed(row: dict[str, Any]) -> EncounterRef:
    return EncounterRef(
        address=row.get("address", ""),
        kind=row.get("kind", ""),
        resolution=row.get("resolution", ""),
        monster_id=row.get("monsterId"),
        monster_ref=str(row.get("monsterRef") or ""),
        monster_name=row.get("monsterName"),
        max_distance=row.get("maxDistance"),
        copies=row.get("copies"),
        pic_ref=row.get("picRef"),
        stats=row.get("stats"),
        candidate_resolution=row.get("candidateResolution"),
    )


def _read_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))
