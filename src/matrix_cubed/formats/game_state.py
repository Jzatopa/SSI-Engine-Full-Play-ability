"""SAVGAMA.DAT parser for Buck Rogers Matrix Cubed game state.

SAVGAMA.DAT is a 2901-byte binary file storing:
  - Current map area ID (2 bytes, offset 0x00)
  - Party position (x, y, facing 3 bytes, offset 0x02)
  - Party roster slot map (character stems, 4*9=36 bytes, offset 0x05)
  - Credits (4 bytes, offset 0x2C)
  - Event flag arrays / visited tiles / map exit data at higher offsets
  - Active encounter state near the end

Offset tables below are liveplay-verified samples; many fields remain unknown.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

SAVGAMA_SIZE = 2901


@dataclass(frozen=True)
class PartyPosition:
    area_id: int           # map area ID (0-based)
    x: int
    y: int
    facing: int            # 0=N, 1=E, 2=S, 3=W


@dataclass(frozen=True)
class GameState:
    position: PartyPosition
    credits: int
    team_size: int
    team_slots: list[str]          # character names (empty string = empty slot)
    raw_area_id: bytes
    raw_position: bytes
    raw_credits: bytes
    raw_full: bytes                # full 2901 bytes for reference

    # Flag / event regions (known offsets, many unknown)
    event_flag_area: bytes | None = None      # offset 0x4C, size 256
    map_exit_table: bytes | None = None       # offset 0x160, size ~130


def parse_game_state(path: Path | str) -> GameState:
    data = Path(path).read_bytes()
    if len(data) != SAVGAMA_SIZE:
        raise ValueError(f"expected {SAVGAMA_SIZE}-byte SAVGAMA.DAT, got {len(data)} bytes")

    area_id = _u16(data, 0x00)
    pos_x = data[0x02]
    pos_y = data[0x03]
    facing = data[0x04] & 0x03
    credits = _u32(data, 0x2C)

    # Team roster slot names at offset 0x05, 9 slots * 4 bytes each = 36 bytes
    team_slots: list[str] = []
    team_size = 0
    for slot_i in range(9):
        slot_off = 0x05 + slot_i * 4
        name = data[slot_off : slot_off + 4].rstrip(b"\x00 ").decode("ascii", errors="replace")
        if name:
            team_size += 1
        team_slots.append(name)

    # Known flag/event region candidates
    event_flag_area = data[0x4C:0x4C+256] if 0x4C + 256 <= len(data) else None
    map_exit_table = data[0x160:0x160+130] if 0x160 + 130 <= len(data) else None

    return GameState(
        position=PartyPosition(area_id=area_id, x=pos_x, y=pos_y, facing=facing),
        credits=credits,
        team_size=team_size,
        team_slots=team_slots,
        raw_area_id=data[0x00:0x02],
        raw_position=data[0x02:0x05],
        raw_credits=data[0x2C:0x30],
        raw_full=data,
        event_flag_area=event_flag_area,
        map_exit_table=map_exit_table,
    )


def load_game_state_bytes(path: Path | str) -> bytes:
    data = Path(path).read_bytes()
    assert len(data) == SAVGAMA_SIZE
    return data


def diff_game_state(before: bytes, after: bytes) -> dict[str, object]:
    assert len(before) == len(after) == SAVGAMA_SIZE
    changes: list[dict] = []
    changed_regions: set[str] = set()
    for i in range(SAVGAMA_SIZE):
        if before[i] != after[i]:
            changes.append({"offset": i, "before": before[i], "after": after[i]})
            region = (i // 16) * 16
            changed_regions.add(f"0x{region:04X}")
    return {
        "total_changed_bytes": len(changes),
        "changed_regions": sorted(changed_regions),
        "changes": changes,
        "before_md5": _md5(before),
        "after_md5": _md5(after),
    }


def _u16(data: bytes, offset: int) -> int:
    return int.from_bytes(data[offset : offset + 2], "little")


def _u32(data: bytes, offset: int) -> int:
    return int.from_bytes(data[offset : offset + 4], "little")


def _md5(data: bytes) -> str:
    import hashlib
    return hashlib.md5(data).hexdigest()
