"""Pygame desktop frontend for Matrix Cubed — exploration + combat."""

from __future__ import annotations

import sys
from pathlib import Path

import pygame

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.map_engine import Direction as MapDir, MapEngine
from matrix_cubed.engine.runtime import GameState
from matrix_cubed.engine.combat_loop import CombatLoop
from matrix_cubed.engine.monster_db import MonsterDB
from matrix_cubed.tools.wall_renderer import WallRenderer
from matrix_cubed.engine.wall_set_db import WallSetDB
from matrix_cubed.engine.inventory import ItemCatalog
from matrix_cubed.engine.character import CharacterRecord
from matrix_cubed.tools.overlays import render_inventory_overlay, render_character_overlay

# ── Layout ─────────────────────────────────────────────────────────────────
W, H = 1024, 768
FPS = 30
MAP_SZ = 320
TILE = MAP_SZ // 16
BOT_H = 60
VP_X = MAP_SZ
VP_W = W - MAP_SZ
VP_H = H - BOT_H
EV_Y = VP_H - 60

TILE_COL = {0: (40, 40, 40), 1: (180, 180, 180), 2: (139, 69, 19),
            3: (128, 0, 128), 4: (255, 255, 0), 5: (255, 165, 0), 255: (0, 0, 0)}

DIR_VEC = {"north": (0, -1), "east": (1, 0), "south": (0, 1), "west": (-1, 0)}
G2M = {"north": MapDir.NORTH, "east": MapDir.EAST, "south": MapDir.SOUTH, "west": MapDir.WEST}
M2N = {MapDir.NORTH: "N", MapDir.EAST: "E", MapDir.SOUTH: "S", MapDir.WEST: "W"}


def _center(text: str, font: pygame.font.Font, y: int) -> tuple[pygame.Surface, tuple[int, int]]:
    sf = font.render(text, True, (255, 255, 255))
    return sf, (W // 2 - sf.get_width() // 2, y)



from matrix_cubed.tools.character_creation import run_character_creation


class Runner:
    def __init__(self) -> None:
        pygame.init()
        self.screen = pygame.display.set_mode((W, H))
        pygame.display.set_caption("Matrix Cubed")
        self.clock = pygame.time.Clock()

        self.data = ReconstructedData.from_generated(Path("generated"))
        self.gs = GameState.start(self.data, 17)

        # Show main menu / character creation before entering world
        if not self._main_menu():
            pygame.quit()
            sys.exit()

        self.meng = MapEngine(self.data)
        self.meng.load_map(17)
        g2m = G2M[self.gs.facing]
        self.meng.start_map(17, self.gs.col, self.gs.row, g2m)

        self.combat = CombatLoop(self.gs, MonsterDB())
        self.wall_renderer = WallRenderer()
        self.wall_set_db = WallSetDB()
        self.in_combat = False
        self.event_txt = ""
        self.event_ttl = 0
        self.dialog_choices: list[str] = []
        self.show_inv = False  # I toggles inventory overlay
        self.show_char = False  # C toggles character sheet
        self.catalog = ItemCatalog(Path("generated"))


    # ── Main menu ─────────────────────────────────────────────────────────
    def _main_menu(self) -> bool:
        """Show title / main menu. Returns True to play, False to quit."""
        options = ["New Game", "Continue", "Quit"]
        sel = 0
        while True:
            for ev in pygame.event.get():
                if ev.type == pygame.QUIT:
                    return False
                if ev.type == pygame.KEYDOWN:
                    if ev.key == pygame.K_UP:
                        sel = (sel - 1) % len(options)
                    elif ev.key == pygame.K_DOWN:
                        sel = (sel + 1) % len(options)
                    elif ev.key == pygame.K_RETURN:
                        if sel == 0:  # New Game
                            char = run_character_creation(self.screen, self.clock)
                            if char:
                                self.gs.add_character(char)
                                return True
                            return False
                        elif sel == 1:  # Continue — load from save
                            from matrix_cubed.engine.save_load import load_game_state
                            # Check autosave first, then most recent timestamped save
                            auto = Path("saves") / "autosave"
                            save_dir = auto if (auto / "SAVGAMA.DAT").exists() else None
                            if not save_dir:
                                saves_root = Path("saves")
                                if saves_root.exists():
                                    for d in sorted(saves_root.iterdir(), reverse=True):
                                        if d.is_dir() and d.name != "autosave" and (d / "SAVGAMA.DAT").exists():
                                            save_dir = d
                                            break
                            if not save_dir:
                                save_dir = Path("generated") / "liveplay" / "post_combat"
                                if not (save_dir / "SAVGAMA.DAT").exists():
                                    save_dir = None
                            if save_dir:
                                try:
                                    state = load_game_state(save_dir)
                                    self.gs = GameState.start(self.data, state["map_id"])
                                    self.gs.row = state["row"]
                                    self.gs.col = state["col"]
                                    self.gs.facing = state["facing"]
                                    for c in state["roster"].list_all():
                                        self.gs.add_character(c)
                                    self.gs.set_credits(state["credits"])
                                except Exception as exc:
                                    print(f"Load failed: {exc}")
                            if self.gs.active_party.members or self.gs.party.hp > 0:
                                return True
                            return True
                        else:
                            return False

            self.screen.fill((10, 10, 20))
            tf = pygame.font.SysFont(None, 48)
            title, _ = _center("MATRIX CUBED", tf, 100)
            self.screen.blit(title, (W // 2 - title.get_width() // 2, 100))

            f = pygame.font.SysFont(None, 28)
            for i, opt in enumerate(options):
                color = (255, 200, 50) if i == sel else (180, 180, 180)
                sf = f.render(f"> {opt}" if i == sel else f"  {opt}", True, color)
                self.screen.blit(sf, (W // 2 - sf.get_width() // 2, 280 + i * 50))

            sf2 = pygame.font.SysFont(None, 18).render(
                "Buck Rogers: Matrix Cubed — Source Reconstruction", True, (80, 80, 100))
            self.screen.blit(sf2, (W // 2 - sf2.get_width() // 2, H - 40))

            pygame.display.flip()
            self.clock.tick(FPS)

    # ── Input ──────────────────────────────────────────────────────────────
    def _move(self) -> None:
        k = pygame.key.get_pressed()
        act = next((a for a, key in
                    [("forward", pygame.K_w), ("back", pygame.K_s),
                     ("left", pygame.K_a), ("right", pygame.K_d),
                     ("turn_left", pygame.K_q), ("turn_right", pygame.K_e)]
                    if k[key]), None)
        if act:
            prev_map = self.gs.map_id
            prev = self.gs.active_event_id
            self.gs.perform(act)
            # Sync MapEngine if GEO changed (transition)
            if self.gs.map_id != prev_map:
                self.meng.load_map(self.gs.map_id)
                self.meng.start_map(self.gs.map_id, self.gs.col, self.gs.row,
                                    G2M[self.gs.facing])
            else:
                ctx = self.meng.context
                if ctx:
                    ctx.player_x, ctx.player_y = self.gs.col, self.gs.row
                    ctx.facing = G2M[self.gs.facing]
            self._check_event(prev)

    def _check_event(self, prev: int | None) -> None:
        cur = self.gs.active_event_id
        if cur is not None and cur != prev:
            self.gs.execute_current_event()
            if self.gs.active_encounter and not self.in_combat:
                self.in_combat = True
                self.combat.enter(self.gs.active_encounter)
                return
            snap = self.gs.snapshot()
            txt = (snap.get("event_text") or "").strip()
            event = self.gs.current_event
            self.dialog_choices = [choice.label for choice in event.dialog.choices] if event and event.dialog else []
            self.event_txt = txt or f"Event {cur}"
            self.event_ttl = FPS * 4

    # ── Render ─────────────────────────────────────────────────────────────
    def _map(self) -> None:
        sf = pygame.Surface((MAP_SZ, MAP_SZ))
        sf.fill((20, 20, 20))
        g = self.meng.get_overhead_view()
        for y, row in enumerate(g[:16]):
            for x, t in enumerate(row[:16]):
                pygame.draw.rect(sf, TILE_COL.get(t, (10, 10, 10)), (x * TILE, y * TILE, TILE, TILE))
        cx, cy = self.gs.col * TILE + TILE // 2, self.gs.row * TILE + TILE // 2
        pygame.draw.circle(sf, (0, 220, 0), (cx, cy), TILE // 3)
        dx, dy = DIR_VEC.get(self.gs.facing, (0, 0))
        pygame.draw.circle(sf, (255, 255, 200), (cx + dx * TILE // 3, cy + dy * TILE // 3), 3)
        self.screen.blit(sf, (0, 0))

    def _vp(self) -> None:
        sf = pygame.Surface((VP_W, VP_H))
        sf.fill((15, 15, 20))

        # Render first-person walls
        grid = self.meng.get_overhead_view() if self.meng else []
        if grid:
            ws = self.wall_set_db.get(self.gs.map_id, default=1)
            self.wall_renderer.render(sf, grid, self.gs.col, self.gs.row,
                                      G2M.get(self.gs.facing, MapDir.NORTH),
                                      wall_set=ws)

        # Floor divider line
        mid = VP_H // 2
        pygame.draw.line(sf, (60, 55, 50), (0, mid), (VP_W, mid), 1)

        # Facing indicator (small compass in corner)
        f = pygame.font.SysFont(None, 20)
        d = M2N.get(G2M.get(self.gs.facing, MapDir.NORTH), '?')
        sf.blit(f.render(f"[{d}]", True, (120, 120, 120)), (4, 4))

        # Event text overlay
        if self.event_txt and self.event_ttl > 0:
            box_h = 80 + min(len(self.dialog_choices), 4) * 22
            b = pygame.Surface((VP_W - 40, box_h))
            b.set_alpha(200)
            b.fill((10, 10, 10))
            sf.blit(b, (20, EV_Y))
            font = pygame.font.SysFont(None, 28)
            small = pygame.font.SysFont(None, 22)
            l2 = font.render(self.event_txt[:80], True, (255, 255, 100))
            sf.blit(l2, (30, EV_Y + 25))
            for index, label in enumerate(self.dialog_choices[:4]):
                row = small.render(f"{index + 1}. {label}", True, (180, 220, 255))
                sf.blit(row, (34, EV_Y + 56 + index * 22))

        self.screen.blit(sf, (VP_X, 0))

    def _bot(self) -> None:
        sf = pygame.Surface((W, BOT_H))
        sf.fill((40, 40, 40))
        f = pygame.font.SysFont(None, 22)
        hp_display = self.gs.current_hp()
        cr_display = self.gs.current_credits()
        party_line = f"HP: {hp_display} / {self.gs.active_party.members[0].name if self.gs.active_party.members else 'None'}"
        for i, t in enumerate([f"Pos: ({self.gs.col},{self.gs.row})", party_line,
                                f"Credits: {cr_display}", f"Steps: {self.gs.steps}"]):
            sf.blit(f.render(t, True, (220, 220, 220)), (10 + (i % 2) * 200, 5 + (i // 2) * 22))
        self.screen.blit(sf, (0, H - BOT_H))

    def _combat_ui(self) -> None:
        sf = pygame.Surface((W, H - BOT_H))
        sf.fill((15, 10, 10))
        s = self.combat.status()
        f = pygame.font.SysFont(None, 24)
        tf = pygame.font.SysFont(None, 32)

        tf.render("COMBAT", True, (255, 60, 60))
        sf.blit(tf.render("COMBAT", True, (255, 60, 60)), (W // 2 - 50, 10))
        hp_str = " | ".join(f"{n}({h})" for n, h in zip(s["monster_names"], s["monster_hp"]))
        sf.blit(f.render(f"Turn {s['turn']} | HP: {s['player_hp']} | {hp_str}", True, (200, 200, 200)), (20, 50))

        if self.combat.victory:
            sf.blit(tf.render("VICTORY! SPACE to continue.  (F5 to save)", True, (0, 255, 0)), (W // 2 - 180, 100))
        elif self.combat.defeat:
            sf.blit(tf.render("GAME OVER — Press ESC to quit or Space to retry", True, (255, 0, 0)), (W // 2 - 200, 100))

        for i, line in enumerate(s["log"][-12:]):
            sf.blit(f.render(line, True, (220, 220, 180)), (30, 140 + i * 26))

        if not self.combat.victory and not self.combat.defeat:
            sf.blit(f.render("SPACE=next  I=inv  C=char  O=shop  F5=save  ESC=quit", True, (120, 120, 120)), (W // 2 - 220, H - BOT_H - 30))

        self.screen.blit(sf, (0, 0))

    def _save_game(self) -> None:
        """Save to timestamped dir + autosave slot for Continue."""
        from matrix_cubed.engine.save_load import save_game
        from datetime import datetime
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        save_dir = Path("saves") / f"save_{ts}"
        results = save_game(save_dir, self.gs)
        # Also write to autosave slot for Continue
        auto = Path("saves") / "autosave"
        auto.mkdir(parents=True, exist_ok=True)
        save_game(auto, self.gs)
        print(f"Saved to {save_dir} + autosave: {len(results)} files")

    # ── Loop ───────────────────────────────────────────────────────────────
    def run(self) -> None:
        while True:
            for ev in pygame.event.get():
                if ev.type == pygame.QUIT or (ev.type == pygame.KEYDOWN and ev.key == pygame.K_ESCAPE):
                    pygame.quit(); sys.exit()
                if ev.type == pygame.KEYDOWN and ev.key == pygame.K_i:
                    self.show_inv = not self.show_inv
                    self.show_char = False
                if ev.type == pygame.KEYDOWN and ev.key == pygame.K_c:
                    self.show_char = not self.show_char
                    self.show_inv = False
                if ev.type == pygame.KEYDOWN and ev.key == pygame.K_s and pygame.key.get_mods() & pygame.KMOD_CTRL:
                    self._save_game()
                if ev.type == pygame.KEYDOWN and ev.key == pygame.K_F5:
                    self._save_game()
                if ev.type == pygame.KEYDOWN and ev.key == pygame.K_o:
                    from matrix_cubed.tools.shop import run_shop
                    result = run_shop(self.screen, self.clock, self.catalog,
                                      self.gs.party.inventory, self.gs.party.credits)
                    if result:
                        self.gs.party.inventory, self.gs.party.credits = result
                if ev.type == pygame.KEYDOWN and pygame.K_1 <= ev.key <= pygame.K_9 and self.dialog_choices:
                    choice_index = ev.key - pygame.K_1
                    selection = self.gs.execute_dialog_choice(choice_index)
                    if selection:
                        self.event_txt = f"{selection.label} selected"
                        self.dialog_choices = []
                        self.event_ttl = FPS * 3
                if ev.type == pygame.KEYDOWN and ev.key == pygame.K_SPACE:
                    if self.in_combat:
                        if self.combat.victory or self.combat.defeat:
                            if self.combat.victory and self.gs.active_party.members:
                                rewards = self.combat.rewards_summary()
                                from matrix_cubed.engine.level_up import grant_xp
                                char = self.gs.active_party.members[0]
                                new_char, lines = grant_xp(char, rewards["xp"])
                                self.gs.active_party.members[0] = new_char
                                self.gs.active_party.member_hp[0] = new_char.hp
                                if rewards["credits"]:
                                    self.gs.add_credits(rewards["credits"])
                                    lines.append(f"+{rewards['credits']} credits")
                                for l in lines:
                                    self.gs.log.append(l)
                            self.in_combat = False
                            self.gs.active_encounter = None
                            continue
                        self.combat.player_turn()
                        if not self.combat.victory:
                            self.combat.monster_turn()
                    elif self.event_txt:
                        self.gs.execute_current_event()
                        event = self.gs.current_event
                        self.dialog_choices = [choice.label for choice in event.dialog.choices] if event and event.dialog else []
                        if self.gs.active_encounter and not self.in_combat:
                            self.in_combat = True
                            self.combat.enter(self.gs.active_encounter)
                        if not self.dialog_choices:
                            self.event_txt = ""
                            self.event_ttl = 0

            if not self.in_combat:
                self._move()

            if self.event_ttl > 0:
                self.event_ttl -= 1
                if self.event_ttl == 0:
                    self.event_txt = ""

            self.screen.fill((0, 0, 0))
            if self.in_combat:
                self._combat_ui()
            else:
                self._map(); self._vp()
            self._bot()
            if self.show_inv and not self.in_combat:
                f = pygame.font.SysFont(None, 22)
                render_inventory_overlay(self.screen, self.gs.party.inventory, self.catalog, f)
            if self.show_char and not self.in_combat:
                f = pygame.font.SysFont(None, 22)
                char = self.gs.active_party.members[0] if self.gs.active_party.members else None
                if char:
                    render_character_overlay(self.screen, char, f)
            pygame.display.flip()
            self.clock.tick(FPS)


if __name__ == "__main__":
    Runner().run()
