"""Tests for monster stat lookup and derivation."""

from __future__ import annotations

from matrix_cubed.engine.monster_db import MonsterDB


class TestMonsterDB:
    def setup_method(self) -> None:
        self.db = MonsterDB()

    def test_loads_monsters(self):
        assert len(self.db._monsters) > 0

    def test_lookup_by_name(self):
        mon = self.db.by_name("RAM WARRIOR")
        assert mon is not None
        assert mon["name"] == "RAM WARRIOR"
        stats = mon.get("stats", {})
        assert stats.get("strength", 0) == 18

    def test_lookup_by_id(self):
        mon = self.db.by_id(52)
        assert mon is not None
        assert mon["name"] == "RAM WARRIOR"

    def test_hit_points_derived(self):
        mon = self.db.by_name("RAM WARRIOR")
        hp = self.db.hit_points(mon)
        assert hp > 0, f"HP should be positive, got {hp}"

    def test_armor_class(self):
        mon = self.db.by_name("RAM WARRIOR")
        ac = self.db.armor_class(mon)
        assert 5 <= ac <= 15, f"AC should be in reasonable range, got {ac}"

    def test_thac0(self):
        mon = self.db.by_name("RAM WARRIOR")
        thac0 = self.db.thac0(mon)
        assert 10 <= thac0 <= 25, f"THAC0 should be in reasonable range, got {thac0}"

    def test_damage(self):
        mon = self.db.by_name("RAM WARRIOR")
        dmg = self.db.damage(mon)
        assert dmg > 0, f"Damage should be positive, got {dmg}"

    def test_combat_stats_returns_expected_keys(self):
        mon = self.db.by_name("RAM WARRIOR")
        stats = self.db.combat_stats(mon)
        assert set(stats.keys()) == {"hp", "ac", "thac0", "damage"}

    def test_unknown_name_returns_defaults(self):
        stats = self.db.combat_stats_for_name("NONEXISTENT MONSTER")
        assert stats["hp"] == 20
        assert stats["ac"] == 10

    def test_strong_monster_has_higher_damage(self):
        weak = self.db.combat_stats_for_name("SID REFUGE")  # STR 16
        ram = self.db.combat_stats_for_name("RAM WARRIOR")   # STR 18
        # RAM WARRIOR should have at least as much damage
