"""Shop/vendor screen for Matrix Cubed — buy/sell from the item catalog."""

from __future__ import annotations

try:
    import pygame
except ModuleNotFoundError:  # pragma: no cover - exercised in headless envs without pygame
    pygame = None

from matrix_cubed.engine.inventory import ItemCatalog, Inventory, damage_string, slot_name

W, H = 1024, 768
BOT_H = 60

def item_name(item: "ItemTemplate") -> str:
    """Evidence-backed item name when the generated START.EXE mapping exists."""
    return item.name or f"Item {item.index}"


def item_index_from_label(label: str, catalog: ItemCatalog) -> int:
    if label.startswith("Item "):
        try:
            return int(label[5:])
        except ValueError:
            return 0
    for item in catalog.list_all():
        if item_name(item) == label:
            return item.index
    return 0


def run_shop(screen: pygame.Surface, clock: pygame.time.Clock,
             catalog: ItemCatalog, inventory: list[str],
             credits: int) -> tuple[list[str], int] | None:
    """Shop UI. Returns (updated_inventory, remaining_credits) or None if closed."""
    if pygame is None:
        raise RuntimeError("pygame is required to run the shop UI")
    sel = 0
    scroll = 0
    page_size = 20
    all_items = catalog.list_all()
    buy_mode = True

    while True:
        for ev in pygame.event.get():
            if ev.type == pygame.QUIT:
                return None
            if ev.type == pygame.KEYDOWN:
                if ev.key == pygame.K_ESCAPE:
                    return inventory, credits
                if ev.key == pygame.K_TAB:
                    buy_mode = not buy_mode
                    sel = 0; scroll = 0
                if ev.key == pygame.K_UP:
                    sel = max(0, sel - 1)
                    if sel < scroll:
                        scroll = max(0, scroll - 1)
                if ev.key == pygame.K_DOWN:
                    items = all_items if buy_mode else inventory
                    if not buy_mode and not items:
                        continue
                    sel = max(0, min(len(items) - 1, sel + 1))
                    if sel >= scroll + page_size:
                        scroll = min(sel, max(0, len(items) - page_size))
                if ev.key == pygame.K_RETURN:
                    if buy_mode and all_items:
                        item = all_items[sel]
                        price = max(10, item.index * 5 + 10)
                        if credits >= price:
                            credits -= price
                            inventory.append(item_name(item))
                    elif not buy_mode and inventory:
                        item_str = inventory[sel]
                        idx = item_index_from_label(item_str, catalog)
                        sell_price = max(2, idx * 2)
                        credits += sell_price
                        inventory.pop(sel)
                        sel = max(0, sel - 1)

        screen.fill((15, 10, 20))

        title_f = pygame.font.SysFont(None, 32)
        font = pygame.font.SysFont(None, 22)
        small = pygame.font.SysFont(None, 18)

        # Title
        mode = "BUY" if buy_mode else "SELL"
        title = title_f.render(f"SHOP — {mode}  (TAB to switch, ESC to exit)", True, (255, 200, 50))
        screen.blit(title, (W // 2 - title.get_width() // 2, 15))

        # Credits
        cr = font.render(f"Credits: {credits}", True, (255, 255, 100))
        screen.blit(cr, (20, 55))

        y = 85
        if buy_mode:
            visible = all_items[scroll:scroll + page_size]
            for i, item in enumerate(visible):
                idx = scroll + i
                cur = (255, 255, 100) if idx == sel else (200, 200, 200)
                prefix = ">" if idx == sel else " "
                name = item_name(item)
                price = max(10, item.index * 5 + 10)
                dmg = damage_string(item)
                slot = slot_name(item.location)
                sf = font.render(f"{prefix}{name:20s}  {dmg:8s}  [{slot}]  {price}cr", True, cur)
                screen.blit(sf, (20, y))
                y += 26
        else:
            if not inventory:
                sf = font.render("  No items to sell", True, (150, 150, 150))
                screen.blit(sf, (20, y))
            else:
                visible = inventory[scroll:scroll + page_size]
                for i, item_str in enumerate(visible):
                    idx = scroll + i
                    cur = (255, 255, 100) if idx == sel else (200, 200, 200)
                    prefix = ">" if idx == sel else " "
                    sell_price = max(2, item_index_from_label(item_str, catalog) * 2)
                    sf = font.render(f"{prefix}{item_str:20s}  sell: {sell_price}cr", True, cur)
                    screen.blit(sf, (20, y))
                    y += 26

        # Hint
        hint = small.render("UP/DOWN = select  |  ENTER = buy  |  TAB = buy/sell  |  ESC = exit", True, (80, 80, 100))
        screen.blit(hint, (W // 2 - hint.get_width() // 2, H - BOT_H - 20))

        pygame.display.flip()
        clock.tick(30)
