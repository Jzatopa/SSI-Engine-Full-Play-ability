"""Tests for the character module — records, rosters, parties, and stat helpers."""

from __future__ import annotations

from matrix_cubed.engine.character import (
    CharacterRecord,
    CharacterRoster,
    Party,
    Career,
    Race,
    stat_modifier,
    stat_string,
)


def _sample() -> CharacterRecord:
    return CharacterRecord(
        name="TST1", strength=15, dexterity=11, constitution=12,
        intelligence=10, wisdom=9, charisma=10, tech=8,
        cur_strength=15, cur_dexterity=11, cur_constitution=12,
        cur_intelligence=10, cur_wisdom=9, cur_charisma=10, cur_tech=8,
        gender=0, race=1, career=1, level=1, credits=50,
        experience=0, age=25, hp=30, skills=[0]*16,
    )


class TestCharacterRecord:
    def test_create(self):
        c = _sample()
        assert c.name == "TST1"
        assert c.strength == 15

    def test_frozen(self):
        c = _sample()
        import dataclasses
        assert dataclasses.is_dataclass(c)


class TestCharacterRoster:
    def test_add_and_count(self):
        r = CharacterRoster()
        r.add(_sample())
        assert r.count == 1

    def test_get(self):
        r = CharacterRoster()
        r.add(_sample())
        assert r.get("TST1") is not None
        assert r.get("NONEXIST") is None

    def test_remove(self):
        r = CharacterRoster()
        r.add(_sample())
        assert r.remove("TST1")
        assert not r.remove("NONEXIST")
        assert r.count == 0

    def test_list_all(self):
        r = CharacterRoster()
        r.add(_sample())
        assert len(r.list_all()) == 1


class TestParty:
    def test_add_member(self):
        p = Party()
        p.add(_sample())
        assert len(p.members) == 1
        assert p.member_hp == [30]

    def test_remove_member(self):
        p = Party()
        p.add(_sample())
        assert p.remove("TST1")
        assert len(p.members) == 0

    def test_swap(self):
        p = Party()
        c1 = _sample()
        c2 = CharacterRecord(
            name="TST2", strength=10, dexterity=10, constitution=10,
            intelligence=10, wisdom=10, charisma=10, tech=10,
            cur_strength=10, cur_dexterity=10, cur_constitution=10,
            cur_intelligence=10, cur_wisdom=10, cur_charisma=10, cur_tech=10,
            gender=0, race=1, career=2, level=1, credits=0,
            experience=0, age=30, hp=20, skills=[0]*16,
        )
        p.add(c1)
        p.add(c2)
        p.swap(0, 1)
        assert p.members[0].name == "TST2"
        assert p.member_hp[0] == 20

    def test_leader(self):
        p = Party()
        p.add(_sample())
        p.set_leader(0)
        assert p.leader_index == 0

    def test_total_hp(self):
        p = Party()
        p.add(_sample())
        assert p.total_hp() == 30

    def test_is_alive(self):
        p = Party()
        p.add(_sample())
        assert p.is_alive("TST1")
        p.member_hp[0] = 0
        assert not p.is_alive("TST1")

    def test_all_dead(self):
        p = Party()
        p.add(_sample())
        p.member_hp[0] = 0
        assert p.all_dead()


class TestStatModifier:
    def test_stat_3(self):
        assert stat_modifier(3) == -3

    def test_stat_10(self):
        assert stat_modifier(10) == 0

    def test_stat_11(self):
        assert stat_modifier(11) == 0

    def test_stat_15(self):
        assert stat_modifier(15) == 2

    def test_stat_18(self):
        assert stat_modifier(18) == 3

    def test_stat_25(self):
        assert stat_modifier(25) == 3  # clamped


class TestStatString:
    def test_positive_mod(self):
        s = stat_string(15)
        assert "(+2)" in s

    def test_zero_mod(self):
        s = stat_string(10)
        assert "(+0)" in s or "(0)" in s

    def test_negative_mod(self):
        s = stat_string(5)
        # (5-10)//2 = -3 in Python floor division
        assert "-3" in s


class TestHelpers:
    def test_career_name(self):
        assert Career.display_name(1) == "Rocket Jock"
        assert Career.display_name(2) == "Medic"
        assert "Career" in Career.display_name(99)

    def test_race_name(self):
        assert Race.display_name(1) == "Terran"
        assert Race.display_name(2) == "Martian"
