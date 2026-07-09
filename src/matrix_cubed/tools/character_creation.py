"""Character creation flow for Matrix Cubed — name, race, career, stats."""

from __future__ import annotations

import pygame

from matrix_cubed.engine.character import (
    CharacterRecord,
    Career,
    Race,
    stat_string,
)

W, H = 1024, 768

FONT_L = 36
FONT_M = 24
FONT_S = 18

_CAREER_NAMES = {c.value: c.display_name(c.value) for c in Career}
_RACE_NAMES = {r.value: r.display_name(r.value) for r in Race}


def _center(text: str, font: pygame.font.Font, y: int) -> tuple[pygame.Surface, tuple[int, int]]:
    sf = font.render(text, True, (255, 255, 255))
    x = W // 2 - sf.get_width() // 2
    return sf, (x, y)


def _button(text: str, font: pygame.font.Font, rect: pygame.Rect) -> None:
    """Draw a button outline — caller fills before."""
    pygame.draw.rect(pygame.display.get_surface(), (100, 100, 100), rect, 2)


def run_character_creation(screen: pygame.Surface, clock: pygame.time.Clock) -> CharacterRecord | None:
    """Full character creation flow. Returns CharacterRecord or None if cancelled."""
    name = ""
    race_idx = 0
    career_idx = 0
    step = 0  # 0=name, 1=race, 2=career, 3=review

    races = [1, 2]
    careers = [1, 2]

    # Starting stats (Gold Box standard array)
    stats = {"str": 10, "dex": 10, "con": 10, "int": 10, "wis": 10, "cha": 10, "tech": 10}
    stat_points = 14  # points remaining to assign
    stat_order = ["str", "dex", "con", "int", "wis", "cha", "tech"]
    stat_sel = 0  # which stat is selected

    while True:
        for ev in pygame.event.get():
            if ev.type == pygame.QUIT:
                return None
            if ev.type == pygame.KEYDOWN:
                if ev.key == pygame.K_ESCAPE:
                    if step == 0:
                        return None
                    step -= 1
                    continue

                if step == 0:  # Name entry
                    if ev.key == pygame.K_RETURN and name.strip():
                        step = 1
                    elif ev.key == pygame.K_BACKSPACE:
                        name = name[:-1]
                    elif ev.unicode.isprintable() and len(name) < 12:
                        name += ev.unicode

                elif step == 1:  # Race selection
                    if ev.key == pygame.K_UP:
                        race_idx = (race_idx - 1) % len(races)
                    elif ev.key == pygame.K_DOWN:
                        race_idx = (race_idx + 1) % len(races)
                    elif ev.key == pygame.K_RETURN:
                        step = 2

                elif step == 2:  # Career selection
                    if ev.key == pygame.K_UP:
                        career_idx = (career_idx - 1) % len(careers)
                    elif ev.key == pygame.K_DOWN:
                        career_idx = (career_idx + 1) % len(careers)
                    elif ev.key == pygame.K_RETURN:
                        step = 3

                elif step == 3:  # Stat assignment
                    if ev.key == pygame.K_LEFT:
                        stat_sel = (stat_sel - 1) % len(stat_order)
                    elif ev.key == pygame.K_RIGHT:
                        stat_sel = (stat_sel + 1) % len(stat_order)
                    elif ev.key == pygame.K_UP and stat_points > 0:
                        s = stat_order[stat_sel]
                        if stats[s] < 18:
                            stats[s] += 1
                            stat_points -= 1
                    elif ev.key == pygame.K_DOWN and stats[stat_order[stat_sel]] > 3:
                        s = stat_order[stat_sel]
                        stats[s] -= 1
                        stat_points += 1
                    elif ev.key == pygame.K_RETURN:
                        # Confirm
                        race = races[race_idx]
                        career = careers[career_idx]
                        return CharacterRecord(
                            name=name.strip()[:12] or "HERO",
                            strength=stats["str"], dexterity=stats["dex"],
                            constitution=stats["con"], intelligence=stats["int"],
                            wisdom=stats["wis"], charisma=stats["cha"],
                            tech=stats["tech"],
                            cur_strength=stats["str"], cur_dexterity=stats["dex"],
                            cur_constitution=stats["con"], cur_intelligence=stats["int"],
                            cur_wisdom=stats["wis"], cur_charisma=stats["cha"],
                            cur_tech=stats["tech"],
                            gender=0, race=race, career=career,
                            level=1, credits=50, experience=0, age=25,
                            hp=30, skills=[0]*16,
                        )

        # ── Render ────────────────────────────────────────────────────────
        screen.fill((15, 15, 25))
        title_f = pygame.font.SysFont(None, FONT_L)
        font = pygame.font.SysFont(None, FONT_M)
        small = pygame.font.SysFont(None, FONT_S)

        if step == 0:  # Name
            title, _ = _center("CREATE CHARACTER", title_f, 30)
            screen.blit(title, (W // 2 - title.get_width() // 2, 30))

            lbl = font.render("Enter character name:", True, (180, 180, 180))
            screen.blit(lbl, (W // 2 - lbl.get_width() // 2, 150))

            name_sf = font.render(name + ("_" if len(name) < 12 else ""), True, (255, 255, 100))
            name_rect = pygame.Rect(0, 0, 400, 40)
            name_rect.center = (W // 2, 220)
            pygame.draw.rect(screen, (40, 40, 60), name_rect)
            screen.blit(name_sf, (name_rect.x + 10, name_rect.y + 8))

            hint = small.render("Enter name, press ENTER to continue, ESC to cancel", True, (100, 100, 100))
            screen.blit(hint, (W // 2 - hint.get_width() // 2, 280))

        elif step == 1:  # Race
            title, _ = _center("CHOOSE RACE", title_f, 30)
            screen.blit(title, (W // 2 - title.get_width() // 2, 30))
            for i, r_id in enumerate(races):
                color = (255, 255, 100) if i == race_idx else (200, 200, 200)
                name = _RACE_NAMES[r_id]
                desc = {"Terran": "Balanced stats, adaptable", "Martian": "Tough, high CON"}.get(name, "")
                sf = font.render(f"> {name}" if i == race_idx else f"  {name}", True, color)
                screen.blit(sf, (W // 2 - sf.get_width() // 2, 150 + i * 50))
                if desc:
                    dsf = small.render(desc, True, (140, 140, 140))
                    screen.blit(dsf, (W // 2 - dsf.get_width() // 2, 175 + i * 50))

        elif step == 2:  # Career
            title, _ = _center("CHOOSE CAREER", title_f, 30)
            screen.blit(title, (W // 2 - title.get_width() // 2, 30))
            for i, c_id in enumerate(careers):
                color = (255, 255, 100) if i == career_idx else (200, 200, 200)
                name = _CAREER_NAMES[c_id]
                skills = ", ".join(Career.skill_names(c_id))
                sf = font.render(f"> {name}" if i == career_idx else f"  {name}", True, color)
                screen.blit(sf, (W // 2 - sf.get_width() // 2, 150 + i * 50))
                dsf = small.render(f"Skills: {skills}", True, (140, 140, 140))
                screen.blit(dsf, (W // 2 - dsf.get_width() // 2, 175 + i * 50))

        elif step == 3:  # Stats
            title, _ = _center("ASSIGN STATS", title_f, 30)
            screen.blit(title, (W // 2 - title.get_width() // 2, 30))

            pts = font.render(f"Points remaining: {stat_points}", True,
                              (255, 100, 100) if stat_points > 0 else (100, 255, 100))
            screen.blit(pts, (W // 2 - pts.get_width() // 2, 80))

            for i, s in enumerate(stat_order):
                y = 130 + i * 40
                val = stats[s]
                cur = (255, 255, 100) if i == stat_sel else (220, 220, 220)
                label = font.render(f"{s.upper():>5} : {stat_string(val)}", True, cur)
                screen.blit(label, (W // 2 - label.get_width() // 2, y))
                if i == stat_sel:
                    hl = small.render("^ +1    v -1", True, (120, 120, 120))
                    screen.blit(hl, (W // 2 + 120, y + 2))

            if stat_points == 0:
                ok = small.render("Press ENTER to confirm character", True, (150, 255, 150))
                screen.blit(ok, (W // 2 - ok.get_width() // 2, 450))

        pygame.display.flip()
        clock.tick(FPS)
