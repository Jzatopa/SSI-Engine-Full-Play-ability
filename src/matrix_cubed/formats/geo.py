from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class GeoCell:
    row: int
    col: int
    north: int
    east: int
    south: int
    west: int
    event_id: int
    event_flag: bool
    door: int

    @property
    def walls(self) -> tuple[int, int, int, int]:
        return (self.north, self.east, self.south, self.west)


@dataclass(frozen=True)
class GeoMap:
    map_id: int
    name: str
    cells: tuple[GeoCell, ...]

    def cell_at(self, row: int, col: int) -> GeoCell | None:
        if row < 0 or row > 15 or col < 0 or col > 15:
            return None
        return self.cells[row * 16 + col]


def parse_geo_block(map_id: int, name: str, data: bytes) -> GeoMap:
    cells: list[GeoCell] = []
    for i in range(256):
        row, col = i >> 4, i & 0x0F
        ne = data[i + 2] if i + 2 < len(data) else 0
        sw = data[i + 258] if i + 258 < len(data) else 0
        event = data[i + 514] if i + 514 < len(data) else 0
        door = data[i + 770] if i + 770 < len(data) else 0
        cells.append(
            GeoCell(
                row=row,
                col=col,
                north=ne >> 4,
                east=ne & 0x0F,
                south=sw >> 4,
                west=sw & 0x0F,
                event_id=event & 0x7F,
                event_flag=bool(event & 0x80),
                door=door,
            )
        )
    return GeoMap(map_id, name, tuple(cells))
