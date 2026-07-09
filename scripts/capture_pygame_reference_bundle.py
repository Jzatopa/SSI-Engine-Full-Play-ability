#!/usr/bin/env python3
"""Generate Pygame-only reference screenshots/state for non-Pygame review."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
from typing import Any

import pygame
from PIL import Image

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.character import CharacterRecord
from matrix_cubed.engine.combat_loop import CombatLoop
from matrix_cubed.engine.monster_db import MonsterDB
from matrix_cubed.engine.runtime import GameState
from matrix_cubed.engine.wall_set_db import WallSetDB
from matrix_cubed.tools.overlays import render_character_overlay, render_inventory_overlay
from matrix_cubed.tools.pygame_runner import BOT_H, FPS, H, TILE, TILE_COL, VP_H, VP_W, VP_X, W
from matrix_cubed.tools.wall_renderer import WallRenderer
from matrix_cubed.engine.inventory import ItemCatalog
from matrix_cubed.engine.map_engine import Direction as MapDir, MapEngine


G2M = {"north": MapDir.NORTH, "east": MapDir.EAST, "south": MapDir.SOUTH, "west": MapDir.WEST}
DIR_VEC = {"north": (0, -1), "east": (1, 0), "south": (0, 1), "west": (-1, 0)}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def image_evidence(path: Path) -> dict[str, Any]:
    with Image.open(path) as image:
        colors = image.convert("RGB").getcolors(maxcolors=10_000_000) or []
        nonblack = sum(count for count, color in colors if color != (0, 0, 0))
        return {
            "path": str(path),
            "size": path.stat().st_size,
            "sha256": sha256(path),
            "width": image.width,
            "height": image.height,
            "unique_colors": len(colors),
            "nonblack_pixels": nonblack,
        }


def sample_character() -> CharacterRecord:
    return CharacterRecord(
        name="CAR1",
        strength=14,
        dexterity=13,
        constitution=12,
        intelligence=12,
        wisdom=10,
        charisma=9,
        tech=12,
        cur_strength=14,
        cur_dexterity=13,
        cur_constitution=12,
        cur_intelligence=12,
        cur_wisdom=10,
        cur_charisma=9,
        cur_tech=12,
        gender=1,
        race=1,
        career=1,
        level=7,
        credits=100,
        experience=12000,
        age=25,
        hp=38,
        skills=[0] * 16,
    )


class ReferenceRenderer:
    def __init__(self, generated_dir: Path) -> None:
        pygame.init()
        self.screen = pygame.display.set_mode((W, H))
        pygame.display.set_caption("Matrix Cubed Reference Capture")
        self.data = ReconstructedData.from_generated(generated_dir)
        self.map_engine = MapEngine(self.data)
        self.wall_renderer = WallRenderer()
        self.wall_sets = WallSetDB()
        self.catalog = ItemCatalog(generated_dir)
        self.font = pygame.font.SysFont(None, 22)
        self.big_font = pygame.font.SysFont(None, 30)

    def close(self) -> None:
        pygame.quit()

    def base_state(self) -> GameState:
        state = GameState.start(self.data, 17)
        state.add_character(sample_character())
        state.set_credits(100)
        return state

    def sync_map(self, state: GameState) -> None:
        self.map_engine.load_map(state.map_id)
        self.map_engine.start_map(state.map_id, state.col, state.row, G2M[state.facing])

    def draw_world(self, state: GameState, event_text: str = "", choices: list[str] | None = None) -> None:
        self.sync_map(state)
        self.screen.fill((0, 0, 0))
        self._draw_map(state)
        self._draw_viewport(state, event_text=event_text, choices=choices or [])
        self._draw_bottom(state)
        pygame.display.flip()

    def _draw_map(self, state: GameState) -> None:
        sf = pygame.Surface((320, 320))
        sf.fill((20, 20, 20))
        grid = self.map_engine.get_overhead_view()
        for y, row in enumerate(grid[:16]):
            for x, tile in enumerate(row[:16]):
                pygame.draw.rect(sf, TILE_COL.get(tile, (10, 10, 10)), (x * TILE, y * TILE, TILE, TILE))
        cx, cy = state.col * TILE + TILE // 2, state.row * TILE + TILE // 2
        pygame.draw.circle(sf, (0, 220, 0), (cx, cy), TILE // 3)
        dx, dy = DIR_VEC.get(state.facing, (0, 0))
        pygame.draw.circle(sf, (255, 255, 200), (cx + dx * TILE // 3, cy + dy * TILE // 3), 3)
        self.screen.blit(sf, (0, 0))

    def _draw_viewport(self, state: GameState, event_text: str, choices: list[str]) -> None:
        sf = pygame.Surface((VP_W, VP_H))
        sf.fill((15, 15, 20))
        grid = self.map_engine.get_overhead_view()
        self.wall_renderer.render(sf, grid, state.col, state.row, G2M[state.facing], wall_set=self.wall_sets.get(state.map_id, default=1))
        pygame.draw.line(sf, (60, 55, 50), (0, VP_H // 2), (VP_W, VP_H // 2), 1)
        sf.blit(self.font.render(f"[{state.facing[0].upper()}]", True, (120, 120, 120)), (4, 4))
        if event_text:
            box_h = 88 + min(len(choices), 4) * 22
            box = pygame.Surface((VP_W - 40, box_h))
            box.set_alpha(210)
            box.fill((10, 10, 10))
            y = VP_H - box_h - 12
            sf.blit(box, (20, y))
            sf.blit(self.font.render(event_text[:82], True, (255, 255, 100)), (30, y + 20))
            for idx, choice in enumerate(choices[:4]):
                sf.blit(self.font.render(f"{idx + 1}. {choice}", True, (180, 220, 255)), (34, y + 50 + idx * 22))
        self.screen.blit(sf, (VP_X, 0))

    def _draw_bottom(self, state: GameState) -> None:
        sf = pygame.Surface((W, BOT_H))
        sf.fill((40, 40, 40))
        fields = [
            f"Pos: ({state.col},{state.row})",
            f"HP: {state.current_hp()} / {state.active_party.members[0].name if state.active_party.members else 'None'}",
            f"Credits: {state.current_credits()}",
            f"Steps: {state.steps}",
        ]
        for i, text in enumerate(fields):
            sf.blit(self.font.render(text, True, (220, 220, 220)), (10 + (i % 2) * 220, 5 + (i // 2) * 22))
        self.screen.blit(sf, (0, H - BOT_H))

    def draw_combat(self, state: GameState, loop: CombatLoop) -> None:
        self.screen.fill((15, 10, 10))
        status = loop.status()
        self.screen.blit(self.big_font.render("COMBAT", True, (255, 60, 60)), (W // 2 - 50, 18))
        hp_str = " | ".join(f"{name}({hp})" for name, hp in zip(status["monster_names"], status["monster_hp"]))
        self.screen.blit(self.font.render(f"Turn {status['turn']} | HP: {status['player_hp']} | {hp_str}", True, (220, 220, 220)), (24, 60))
        for idx, line in enumerate(status["log"][-12:]):
            self.screen.blit(self.font.render(line, True, (220, 220, 180)), (34, 120 + idx * 26))
        self.screen.blit(self.font.render("SPACE=next  I=inv  C=char  O=shop  F5=save  ESC=quit", True, (130, 130, 130)), (W // 2 - 220, H - 40))
        pygame.display.flip()

    def save(self, path: Path) -> dict[str, Any]:
        path.parent.mkdir(parents=True, exist_ok=True)
        pygame.image.save(self.screen, path)
        return image_evidence(path)


def event_state(renderer: ReferenceRenderer, event_id: int) -> tuple[GameState, dict[str, Any]]:
    state = renderer.base_state()
    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == event_id)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("reference capture")
    execution = state.execute_current_event()
    event = state.current_event
    choices = [choice.label for choice in event.dialog.choices] if event and event.dialog else []
    return state, {"snapshot": state.snapshot(), "commands": [command.to_dict() for command in execution.commands] if execution else [], "choices": choices}


def build_bundle(out_dir: Path, generated_dir: Path) -> dict[str, Any]:
    renderer = ReferenceRenderer(generated_dir)
    screenshots: dict[str, Any] = {}
    states: dict[str, Any] = {}
    try:
        state = renderer.base_state()
        renderer.draw_world(state)
        screenshots["caloris_world"] = renderer.save(out_dir / "screens" / "caloris_world.png")
        states["caloris_world"] = state.snapshot()

        state.party.inventory.extend(["Rocket Pistol", "Medkit"])
        renderer.draw_world(state)
        render_inventory_overlay(renderer.screen, state.party.inventory, renderer.catalog, renderer.font)
        pygame.display.flip()
        screenshots["inventory_overlay"] = renderer.save(out_dir / "screens" / "inventory_overlay.png")

        renderer.draw_world(state)
        render_character_overlay(renderer.screen, state.active_party.members[0], renderer.font)
        pygame.display.flip()
        screenshots["character_overlay"] = renderer.save(out_dir / "screens" / "character_overlay.png")

        dialog_state, dialog_payload = event_state(renderer, 20)
        renderer.draw_world(dialog_state, event_text=(dialog_payload["snapshot"].get("event_text") or "").strip(), choices=dialog_payload["choices"])
        screenshots["caloris_romney_dialog"] = renderer.save(out_dir / "screens" / "caloris_romney_dialog.png")
        states["caloris_romney_dialog"] = dialog_payload

        autodoc_state, autodoc_payload = event_state(renderer, 28)
        renderer.draw_world(autodoc_state, event_text=(autodoc_payload["snapshot"].get("event_text") or "").strip(), choices=autodoc_payload["choices"])
        screenshots["caloris_autodoc_dialog"] = renderer.save(out_dir / "screens" / "caloris_autodoc_dialog.png")
        states["caloris_autodoc_dialog"] = autodoc_payload

        combat_state, combat_payload = event_state(renderer, 7)
        loop = CombatLoop(combat_state, MonsterDB())
        assert combat_state.active_encounter is not None
        loop.enter(combat_state.active_encounter)
        loop.player_turn()
        renderer.draw_combat(combat_state, loop)
        screenshots["caloris_combat"] = renderer.save(out_dir / "screens" / "caloris_combat.png")
        states["caloris_combat"] = {"probe": combat_payload, "combat_status": loop.status(), "queued": combat_state.active_encounter.to_dict()}
    finally:
        renderer.close()

    return {
        "source": "scripts/capture_pygame_reference_bundle.py",
        "status": "pass",
        "screenshots": screenshots,
        "states": states,
        "summary": {
            "screenshot_count": len(screenshots),
            "all_nonblank": all(row["nonblack_pixels"] > 1000 for row in screenshots.values()),
        },
    }


def write_markdown(report: dict[str, Any], path: Path) -> None:
    lines = [
        "# Pygame Reference Bundle",
        "",
        "Generated by `scripts/capture_pygame_reference_bundle.py` for review on systems that cannot run Pygame.",
        "",
        f"- Status: `{report['status']}`",
        f"- Screenshots: `{report['summary']['screenshot_count']}`",
        f"- All nonblank: `{report['summary']['all_nonblank']}`",
        "",
        "| Label | Path | SHA-256 | Colors | Nonblack pixels |",
        "| --- | --- | --- | ---: | ---: |",
    ]
    for label, row in report["screenshots"].items():
        lines.append(f"| `{label}` | `{row['path']}` | `{row['sha256']}` | {row['unique_colors']} | {row['nonblack_pixels']} |")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out-dir", type=Path, default=Path("generated/runtime_validation/pygame_reference_bundle"))
    parser.add_argument("--generated-dir", type=Path, default=Path("generated"))
    args = parser.parse_args()

    report = build_bundle(args.out_dir, args.generated_dir)
    args.out_dir.mkdir(parents=True, exist_ok=True)
    (args.out_dir / "pygame_reference_bundle.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    write_markdown(report, args.out_dir / "pygame_reference_bundle.md")
    print(json.dumps(report["summary"], indent=2))
    return 0 if report["summary"]["all_nonblank"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
