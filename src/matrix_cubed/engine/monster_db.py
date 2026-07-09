"""Monster stat lookup — wires decoded MON0CHA data into combat encounters.

Derives combat stats (HP, AC, THAC0, damage) from ability scores
using Gold Box conventions, since the binary offset for direct
combat stats is still a candidate field.
"""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any

from matrix_cubed.engine.character import stat_modifier

MONSTER_DATA_PATH = Path("generated") / "data_model" / "mon0cha_monsters.json"
ENCOUNTER_XREF_PATH = Path("generated") / "encounters" / "encounter_monster_xref.json"


class MonsterDB:
    """Loaded monster records with stat derivation."""

    def __init__(self) -> None:
        self._monsters: dict[int, dict[str, Any]] = {}
        self._by_name: dict[str, dict[str, Any]] = {}
        self._load()

    def _load(self) -> None:
        if not MONSTER_DATA_PATH.exists():
            return
        for m in json.loads(MONSTER_DATA_PATH.read_text()):
            mid = int(m["id"])
            self._monsters[mid] = m
            name = m.get("name", "").strip().upper()
            if name:
                self._by_name[name] = m

    # ── Stat derivation ───────────────────────────────────────────────────

    def hit_points(self, monster: dict[str, Any]) -> int:
        """Derive HP from CON, with a base of ~30 for monsters."""
        con = monster.get("stats", {}).get("constitution", 10)
        return 15 + con * 2

    def armor_class(self, monster: dict[str, Any]) -> int:
        """Derive AC from DEX (high DEX = better AC = harder to hit)."""
        dex = monster.get("stats", {}).get("dexterity", 10)
        return 10 - stat_modifier(dex)

    def thac0(self, monster: dict[str, Any]) -> int:
        """Derive THAC0 from STR (high STR = better THAC0 = easier to hit)."""
        base = 19
        str_val = monster.get("stats", {}).get("strength", 10)
        return base - stat_modifier(str_val)

    def damage(self, monster: dict[str, Any]) -> int:
        """Derive damage from STR."""
        str_val = monster.get("stats", {}).get("strength", 10)
        return max(1, 2 + stat_modifier(str_val))

    def combat_stats(self, monster: dict[str, Any]) -> dict[str, int]:
        """Return full combat stat block for a monster."""
        return {
            "hp": self.hit_points(monster),
            "ac": self.armor_class(monster),
            "thac0": self.thac0(monster),
            "damage": self.damage(monster),
        }

    # ── Lookup ────────────────────────────────────────────────────────────

    def by_name(self, name: str) -> dict[str, Any] | None:
        return self._by_name.get(name.upper().strip())

    def by_id(self, mid: int) -> dict[str, Any] | None:
        return self._monsters.get(mid)

    def combat_stats_for_name(self, name: str) -> dict[str, int]:
        """Get combat stats for a named monster, or defaults if unknown."""
        mon = self.by_name(name)
        if mon:
            return self.combat_stats(mon)
        return {"hp": 20, "ac": 10, "thac0": 19, "damage": 2}
