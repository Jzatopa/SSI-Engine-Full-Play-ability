"""Tests for the inventory module — item catalog, equipment, inventory container."""

from __future__ import annotations

from pathlib import Path

from matrix_cubed.engine.inventory import (
    ItemCatalog,
    ItemTemplate,
    Equipment,
    Inventory,
    damage_string,
    slot_name,
)
from matrix_cubed.tools.shop import item_index_from_label, item_name


def test_catalog_loads_all_items():
    cat = ItemCatalog(Path("generated"))
    assert len(cat) == 91


def test_catalog_lookup():
    cat = ItemCatalog(Path("generated"))
    item = cat.lookup(0)
    assert isinstance(item, ItemTemplate)
    assert item.index == 0
    assert item.location == 1


def test_catalog_list_all():
    cat = ItemCatalog(Path("generated"))
    all_items = cat.list_all()
    assert len(all_items) == 91
    assert sorted(i.index for i in all_items) == list(range(91))


def test_equip_and_get():
    cat = ItemCatalog(Path("generated"))
    eq = Equipment(cat)
    eq.equip(1, 0)
    item = eq.get(1)
    assert item is not None
    assert item.index == 0


def test_unequip():
    cat = ItemCatalog(Path("generated"))
    eq = Equipment(cat)
    eq.equip(1, 0)
    eq.unequip(1)
    assert eq.get(1) is None


def test_inventory_add_remove():
    inv = Inventory()
    inv.add(5)
    inv.add(10)
    assert inv.count == 2
    assert inv.has(5)
    assert inv.remove(5)
    assert not inv.has(5)
    assert inv.count == 1


def test_inventory_remove_missing():
    inv = Inventory()
    assert not inv.remove(99)


def test_inventory_list():
    inv = Inventory()
    inv.add(1)
    inv.add(2)
    assert inv.list_items() == [1, 2]


def test_damage_string_dice():
    t = ItemTemplate(index=0, location=0, hands=1, damage_large={"dice":0,"sides":0,"bonus":0},
                     damage_medium={"dice":1,"sides":6,"bonus":0}, rate=0, protection=0,
                     damage_type=0, melee_flag=1, range=0, class_restrictions=0, ammo_type=0, raw_hex="")
    assert damage_string(t) == "1d6"


def test_damage_string_with_bonus():
    t = ItemTemplate(index=0, location=0, hands=1, damage_large={"dice":0,"sides":0,"bonus":0},
                     damage_medium={"dice":1,"sides":4,"bonus":2}, rate=0, protection=0,
                     damage_type=0, melee_flag=1, range=0, class_restrictions=0, ammo_type=0, raw_hex="")
    assert damage_string(t) == "1d4+2"


def test_damage_string_pure_bonus():
    t = ItemTemplate(index=0, location=0, hands=1, damage_large={"dice":0,"sides":0,"bonus":0},
                     damage_medium={"dice":0,"sides":0,"bonus":10}, rate=0, protection=0,
                     damage_type=0, melee_flag=1, range=0, class_restrictions=0, ammo_type=0, raw_hex="")
    assert damage_string(t) == "10"


def test_slot_name_known():
    assert slot_name(1) == "Head"
    assert slot_name(6) == "Torso"


def test_slot_name_unknown():
    assert slot_name(99) == "Slot 99"


def test_shop_item_name_uses_evidence_backed_mapping():
    cat = ItemCatalog(Path("generated"))
    assert item_name(cat.lookup(0)) == "Knife"
    assert item_name(cat.lookup(20)) == "Smartsuit"


def test_catalog_attaches_items_detail_evidence_without_promoting_stats():
    cat = ItemCatalog(Path("generated"))
    knife = cat.lookup(0)

    assert knife.itemptr == 1
    assert knife.items_detail_record is not None
    assert knife.items_detail_record["index"] == 1
    assert knife.items_detail_record["fields"]["medium_damage_candidate"] == {"dice": 1, "sides": 3, "bonus": 0}
    assert knife.detail_evidence is not None
    assert "itemptr*9" in knife.detail_evidence


def test_shop_resolves_decoded_label_back_to_item_index():
    cat = ItemCatalog(Path("generated"))

    assert item_index_from_label("Smartsuit", cat) == 20
    assert item_index_from_label("Item 20", cat) == 20
