"""Pygame overlay helpers for inventory and character sheet display."""

from __future__ import annotations

import pygame

from matrix_cubed.engine.character import CharacterRecord, Career, Race, stat_string
from matrix_cubed.engine.inventory import ItemCatalog, Inventory, damage_string, slot_name

W = 1024
H = 768
BOT_H = 60


def render_inventory_overlay(
    screen: pygame.Surface,
    items: list[str] | list[int],
    catalog: ItemCatalog | None,
    font: pygame.font.Font,
) -> None:
    """Semi-transparent inventory listing overlay.

    Accepts either list[str] (from legacy PartyState.inventory)
    or list[int] (from Inventory class).
    """
    overlay = pygame.Surface((W, H - BOT_H))
    overlay.set_alpha(200)
    overlay.fill((0, 0, 0))
    screen.blit(overlay, (0, 0))

    title = font.render("INVENTORY", True, (255, 255, 255))
    screen.blit(title, (W // 2 - title.get_width() // 2, 10))

    if not items:
        txt = font.render("Empty", True, (180, 180, 180))
        screen.blit(txt, (W // 2 - txt.get_width() // 2, 40))
    else:
        y = 40
        for idx in items:
            if isinstance(idx, int) and catalog:
                try:
                    t = catalog.lookup(idx)
                    line = f"#{idx}  {damage_string(t)}  [{slot_name(t.location)}]"
                except KeyError:
                    line = f"#{idx}  (unknown)"
            else:
                line = str(idx)
            sf = font.render(line, True, (220, 220, 200))
            screen.blit(sf, (20, y))
            y += 24


def render_character_overlay(
    screen: pygame.Surface,
    character: CharacterRecord,
    font: pygame.font.Font,
) -> None:
    """Semi-transparent character sheet overlay."""
    overlay = pygame.Surface((W, H - BOT_H))
    overlay.set_alpha(200)
    overlay.fill((0, 0, 0))
    screen.blit(overlay, (0, 0))

    title = font.render("CHARACTER SHEET", True, (255, 255, 255))
    screen.blit(title, (W // 2 - title.get_width() // 2, 10))

    lines = [
        f"Name: {character.name}",
        f"STR: {stat_string(character.strength)}",
        f"DEX: {stat_string(character.dexterity)}",
        f"CON: {stat_string(character.constitution)}",
        f"INT: {stat_string(character.intelligence)}",
        f"WIS: {stat_string(character.wisdom)}",
        f"CHA: {stat_string(character.charisma)}",
        f"TECH: {stat_string(character.tech)}",
        f"Level: {character.level}",
        f"Career: {Career.display_name(character.career)}",
        f"Race: {Race.display_name(character.race)}",
        f"HP: {character.hp}",
        f"Credits: {character.credits}",
    ]
    y = 40
    for line in lines:
        sf = font.render(line, True, (220, 220, 200))
        screen.blit(sf, (20, y))
        y += 24
