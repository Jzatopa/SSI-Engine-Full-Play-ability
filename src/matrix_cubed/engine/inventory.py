"""Item catalog and inventory system for Matrix Cubed."""

from __future__ import annotations

import json
from dataclasses import dataclass, fields
from pathlib import Path
from typing import Any


@dataclass(frozen=True)
class ItemTemplate:
    """A single item template from item0_templates.json (frozen / immutable)."""
    index: int
    location: int
    hands: int
    damage_large: dict[str, int]
    damage_medium: dict[str, int]
    rate: int
    protection: int
    damage_type: int
    melee_flag: int
    range: int
    class_restrictions: int
    ammo_type: int
    raw_hex: str
    itemptr: int | None = None
    name_codes: tuple[int, int, int] = (0, 0, 0)
    name: str | None = None
    name_evidence: str | None = None
    items_detail_record: dict[str, Any] | None = None
    detail_evidence: str | None = None


class ItemCatalog:
    """Loads and indexes all item templates from the generated data dir."""

    def __init__(self, generated_dir: Path) -> None:
        path = generated_dir / "data_model" / "item0_templates.json"
        with open(path) as f:
            raw: list[dict[str, Any]] = json.load(f)

        self._items: dict[int, ItemTemplate] = {}
        _known = {f.name for f in fields(ItemTemplate)}
        names = self._load_item_name_mapping(generated_dir)
        for row in raw:
            clean = {k: v for k, v in row.items() if k in _known}
            mapped = names.get(clean["index"])
            if mapped is not None:
                clean.update(mapped)
            self._items[clean["index"]] = ItemTemplate(**clean)

    @staticmethod
    def _load_item_name_mapping(generated_dir: Path) -> dict[int, dict[str, Any]]:
        path = generated_dir / "game_ovr" / "item_name_mapping.json"
        if not path.exists():
            return {}
        report = json.loads(path.read_text(encoding="utf-8"))
        rows = report.get("item0_name_records", [])
        mapping: dict[int, dict[str, Any]] = {}
        for row in rows:
            mapping[int(row["index"])] = {
                "itemptr": int(row["itemptr"]),
                "name_codes": tuple(int(code) for code in row["name_codes"]),
                "name": str(row["name"]),
                "name_evidence": str(row["name_evidence"]),
                "items_detail_record": row.get("items_detail_record"),
                "detail_evidence": row.get("detail_evidence"),
            }
        return mapping

    def lookup(self, index: int) -> ItemTemplate:
        return self._items[index]

    def list_all(self) -> list[ItemTemplate]:
        return [self._items[i] for i in sorted(self._items)]

    def __len__(self) -> int:
        return len(self._items)


class Equipment:
    """Equipment slots (location → item index)."""

    def __init__(self, catalog: ItemCatalog) -> None:
        self._catalog = catalog
        self._slots: dict[int, int] = {}

    def equip(self, slot: int, item_index: int) -> None:
        self._slots[slot] = item_index

    def unequip(self, slot: int) -> None:
        self._slots.pop(slot, None)

    def get(self, slot: int) -> ItemTemplate | None:
        idx = self._slots.get(slot)
        if idx is None:
            return None
        return self._catalog.lookup(idx)

    def iter_slots(self) -> list[tuple[int, ItemTemplate]]:
        return [(s, self._catalog.lookup(i)) for s, i in sorted(self._slots.items())]

    def __bool__(self) -> bool:
        return bool(self._slots)


class Inventory:
    """Carried items (list of item indices)."""

    def __init__(self) -> None:
        self._items: list[int] = []

    def add(self, item_index: int) -> None:
        self._items.append(item_index)

    def remove(self, item_index: int) -> bool:
        try:
            self._items.remove(item_index)
            return True
        except ValueError:
            return False

    def has(self, item_index: int) -> bool:
        return item_index in self._items

    def list_items(self) -> list[int]:
        return list(self._items)

    @property
    def count(self) -> int:
        return len(self._items)


# ── Helpers ─────────────────────────────────────────────────────────────────

def damage_string(t: ItemTemplate) -> str:
    """Human-readable damage string from medium damage dice."""
    d = t.damage_medium
    dice, sides, bonus = d["dice"], d["sides"], d["bonus"]
    if dice == 0 and sides == 0:
        return str(bonus) if bonus else "0"
    base = f"{dice}d{sides}"
    if bonus == 0:
        return base
    op = "+" if bonus > 0 else ""
    return f"{base}{op}{bonus}"


_SLOT_NAMES: dict[int, str] = {
    1: "Head", 2: "Neck", 3: "Shoulders", 4: "Arms",
    5: "Hands", 6: "Torso", 7: "Waist", 8: "Legs",
    9: "Feet", 10: "Shield", 11: "Back", 12: "Eyes",
    13: "Mouth", 14: "Fingers", 15: "Wrist",
    16: "Ankles", 17: "Groin", 18: "Chest",
}


def slot_name(location: int) -> str:
    return _SLOT_NAMES.get(location, f"Slot {location}")
