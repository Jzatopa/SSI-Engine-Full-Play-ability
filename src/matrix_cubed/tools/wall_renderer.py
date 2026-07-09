"""First-person wall renderer for Matrix Cubed — tile-based raycasting.

Loads decoded 8×16 wall textures and projects them into the
first-person viewport with correct depth and clipping.
"""

from __future__ import annotations

from pathlib import Path

import pygame

from matrix_cubed.engine.map_engine import Direction

_TEX_DIR = Path("generated") / "wall_textures"

# Viewport dimensions (must match Pygame runner)
VIEW_W = 704
VIEW_H = 708

# Wall projection constants
WALL_BASE_H = 708        # full-height wall at distance 1
WALL_BASE_W = 64         # width of one wall column at distance 1
DEPTH_FACTOR = 0.55       # each step = 55% of previous size
VIEW_COLS = 17            # number of "ray" columns to cast (matching 16-tile view)


class WallRenderer:
    """Loads walldef1 textures and renders a first-person view."""

    def __init__(self) -> None:
        self._tex: dict[tuple[int, int, int], pygame.Surface] = {}
        self._load()

    def _load(self) -> None:
        """Load textures via PIL (readable without video mode), convert to pygame."""
        from PIL import Image
        for p in _TEX_DIR.glob("*.png"):
            try:
                parts = p.stem.split("_")
                ws = int(parts[1]); wi = int(parts[3]); v = int(parts[5])
                pil_img = Image.open(p).convert("RGBA")
                mode = pil_img.mode
                size = pil_img.size
                raw = pil_img.tobytes()
                surf = pygame.image.frombytes(raw, size, mode)
                self._tex[(ws, wi, v)] = surf
            except (ValueError, IndexError, Exception):
                continue

    def get_tex(self, wall_set: int, wall_id: int, view: int) -> pygame.Surface | None:
        return self._tex.get((wall_set, wall_id, min(view, 9)))

    @property
    def count(self) -> int:
        return len(self._tex)

    # ── Main render entry point ───────────────────────────────────────────

    def render(self, surf: pygame.Surface, grid: list[list[int]],
               px: int, py: int, facing: Direction, wall_set: int = 1) -> None:
        """Render the first-person view onto *surf*.

        Uses a simple column-based raycast.  Each column maps to one
        tile-coordinate offset from the player's facing direction.
        """
        # Floor / ceiling
        ch = surf.get_height()
        cw = surf.get_width()
        mid = ch // 2
        pygame.draw.rect(surf, (25, 25, 35), (0, 0, cw, mid))       # ceiling
        pygame.draw.rect(surf, (40, 35, 30), (0, mid, cw, ch - mid)) # floor

        dx, dy = _dir_vec(facing)
        rx, ry = _right_vec(facing)   # perpendicular for lateral columns

        for col in range(VIEW_COLS):
            lateral = col - (VIEW_COLS // 2)  # -8 .. 0 .. +8

            for depth in range(1, 5):  # 4 tiles deep
                # Tile this ray hits
                tx = px + dx * depth + rx * lateral
                ty = py + dy * depth + ry * lateral

                if not (0 <= tx < 16 and 0 <= ty < 16):
                    continue

                tile = grid[ty][tx]
                if tile == 0:  # Wall
                    w = max(4, int(WALL_BASE_W * (DEPTH_FACTOR ** (depth - 1))))
                    h = max(4, int(WALL_BASE_H * (DEPTH_FACTOR ** depth)))
                    x = int((cw - w) * (col / (VIEW_COLS - 1)))
                    y = mid - h // 2

                    view = (tx * 3 + ty * 7 + depth) % 10
                    tex = self.get_tex(wall_set, max(1, min(15, tile + 1)), view)
                    if tex:
                        scaled = pygame.transform.scale(tex, (w, h))
                        surf.blit(scaled, (x, y))
                    else:
                        pygame.draw.rect(surf, (80, 70, 60), (x, y, w, h))
                    break  # Wall blocks deeper tiles in this column
                elif tile != 1:  # Not floor — draw as wall substitute
                    w = max(4, int(WALL_BASE_W * (DEPTH_FACTOR ** (depth - 1))))
                    h = max(4, int(WALL_BASE_H * (DEPTH_FACTOR ** depth)))
                    x = int((cw - w) * (col / (VIEW_COLS - 1)))
                    y = mid - h // 2
                    col_map = {2: (100, 80, 40), 3: (120, 40, 120), 4: (200, 200, 50),
                               5: (200, 120, 40), 6: (100, 80, 40), 7: (100, 80, 40),
                               8: (60, 60, 100), 255: (0, 0, 0)}
                    colour = col_map.get(tile, (60, 50, 40))
                    pygame.draw.rect(surf, colour, (x, y, w, h))
                    break


def _dir_vec(d: Direction) -> tuple[int, int]:
    return {Direction.NORTH: (0, -1), Direction.EAST: (1, 0),
            Direction.SOUTH: (0, 1), Direction.WEST: (-1, 0)}.get(d, (0, -1))


def _right_vec(d: Direction) -> tuple[int, int]:
    return {Direction.NORTH: (1, 0), Direction.EAST: (0, 1),
            Direction.SOUTH: (-1, 0), Direction.WEST: (0, -1)}.get(d, (1, 0))
