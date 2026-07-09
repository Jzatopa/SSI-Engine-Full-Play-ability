"""Wall set lookup — maps GEO IDs to wall definition sets."""

from __future__ import annotations

from pathlib import Path
from typing import Any

_WALLSET_PATH = Path("generated") / "geo1" / "wallsets.tsv"


class WallSetDB:
    """Maps geo_id → wall_set (walldef_3) from the decoded wallset data."""

    def __init__(self) -> None:
        self._map: dict[int, int] = {}
        self._load()

    def _load(self) -> None:
        if not _WALLSET_PATH.exists():
            return
        for line in _WALLSET_PATH.read_text().strip().split("\n")[1:]:  # Skip header
            parts = line.split("\t")
            if len(parts) >= 7:
                try:
                    geo_id = int(parts[0])
                    walldef3 = parts[6].strip()
                    ws = int(walldef3)
                    # wall_set naming: odd numbers 1-22 → texture file IDs
                    # 3 → 003, 5 → 005, 7 → 007, 11 → 011, etc.
                    self._map[geo_id] = ws
                except (ValueError, IndexError):
                    continue

    def get(self, geo_id: int, default: int = 1) -> int:
        """Return wall_set ID for a GEO map, with 1 as fallback."""
        return self._map.get(geo_id, default)

    @property
    def count(self) -> int:
        return len(self._map)

    def list_maps(self) -> list[tuple[int, int]]:
        return sorted(self._map.items())
