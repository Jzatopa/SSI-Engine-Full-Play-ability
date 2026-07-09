"""Tests for the wall renderer — texture loading and viewport rendering."""

from __future__ import annotations

import pygame

from matrix_cubed.engine.map_engine import Direction
from matrix_cubed.tools.wall_renderer import WallRenderer


class TestWallRenderer:
    def setup_method(self) -> None:
        pygame.init()
        pygame.display.set_mode((100, 100))
        self.wr = WallRenderer()

    def teardown_method(self) -> None:
        pygame.quit()

    def test_loads_all_textures(self):
        assert self.wr.count == 1650, f"Expected 1650 textures, got {self.wr.count}"

    def test_get_known_texture(self):
        tex = self.wr.get_tex(1, 1, 0)
        assert tex is not None
        assert tex.get_size() == (8, 16)

    def test_get_unknown_returns_none(self):
        tex = self.wr.get_tex(999, 999, 999)
        assert tex is None

    def test_render_doesnt_crash(self):
        surf = pygame.Surface((700, 700))
        grid = [[1]*16 for _ in range(16)]
        # Add a wall at (3,3)
        grid[3][3] = 0
        self.wr.render(surf, grid, 1, 1, Direction.NORTH)
        # No assertion — just shouldn't crash
        assert surf.get_at((0, 0)) is not None

    def test_render_with_wall_set(self):
        """Ensure different wall sets don't crash rendering."""
        surf = pygame.Surface((700, 700))
        grid = [[1]*16 for _ in range(16)]
        grid[2][2] = 0  # Wall
        for ws in [1, 3, 5]:
            self.wr.render(surf, grid, 1, 1, Direction.EAST, wall_set=ws)
