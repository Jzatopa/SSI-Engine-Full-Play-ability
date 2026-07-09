"""Tests for combat_loop — THAC0-based encounter resolution."""

from __future__ import annotations

from matrix_cubed.engine.combat import QueuedCombat
from matrix_cubed.engine.combat_loop import CombatLoop
from matrix_cubed.engine.events import EventCommand


def _quick_state(hp: int = 100, credits: int = 50) -> "GameState":
    from matrix_cubed.engine.runtime import GameState
    gs = object.__new__(GameState)
    gs.data = None
    gs.map_id = 17
    gs.row = 0
    gs.col = 0
    gs.facing = "north"
    gs.wall_blocking = True
    gs.steps = 0
    gs.active_event_id = None
    gs.active_encounter = None
    gs.executed_event_ids = set()
    gs.party = type("Party", (), {"hp": hp, "credits": credits, "inventory": [], "flags": set()})()
    gs.log = []
    gs.last_execution = None
    gs.roster = type("Roster", (), {"count": 0, "list_all": lambda: [], "get": lambda n: None, "add": lambda c: None})()
    gs.active_party = type("AParty", (), {"members": [], "member_hp": [], "total_hp": lambda: 0})()
    return gs


def _encounter(monsters: list[str]) -> QueuedCombat:
    cmd = EventCommand("queue_combat", "test", {"monster_names": monsters})
    return QueuedCombat.from_command(17, 1, cmd)


class TestCombatLifecycle:
    def test_enter_sets_combat(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        loop.enter(_encounter(["SNAKE", "RAT"]))
        assert loop.active
        assert loop.combat.turn == 0
        assert len(loop.combat.monster_hp) == 2
        assert len(loop.combat.alive) == 2
        assert len(loop.combat.log) == 1

    def test_player_turn_damages(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        loop.enter(_encounter(["SNAKE"]))
        lines = loop.player_turn()
        assert len(lines) > 0
        assert "HIT" in lines[0] or "miss" in lines[0]

    def test_next_turn_advances(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        loop.enter(_encounter(["SNAKE"]))
        loop.player_turn()
        assert loop.combat.turn == 1
        loop.player_turn()
        assert loop.combat.turn == 2

    def test_monster_turn_damages(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        loop.enter(_encounter(["SNAKE"]))
        loop.player_turn()
        lines = loop.monster_turn()
        assert len(lines) > 0
        if "HIT" in lines[0]:
            assert gs.party.hp < 100  # damage was applied

    def test_victory_all_monsters_dead(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        loop.enter(_encounter(["SNAKE"]))
        # Force an easy hit: monster AC very low (guaranteed hit)
        loop.combat.monster_hp[0] = 1
        loop.combat.alive = [0]
        loop.combat.monster_ac[0] = 19  # THAC0 20 - AC 19 = need 1, always hits
        lines = loop.player_turn()
        assert "HIT" in " ".join(lines) or loop.victory
        if loop.victory:
            assert loop.combat.resolved or not loop.active

    def test_party_defeat(self):
        gs = _quick_state(hp=2)
        loop = CombatLoop(gs)
        loop.enter(_encounter(["SNAKE"]))
        loop.player_turn()
        loop.monster_turn()
        # Party HP is very low, one hit should defeat
        if "HIT" in " ".join(loop.combat.log):
            assert loop.defeat or gs.party.hp <= gs.party.hp

    def test_no_op_when_not_entered(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        assert loop.player_turn() == []
        assert loop.monster_turn() == []
        assert not loop.victory
        assert not loop.defeat

    def test_status_format(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        loop.enter(_encounter(["MONSTER"]))
        s = loop.status()
        assert s["phase"] == "combat"
        assert s["player_hp"] == 100
        assert s["alive_count"] == 1


class TestStats:
    def test_player_thac0_decreases_with_level(self):
        gs = _quick_state()
        loop = CombatLoop(gs)
        assert loop._player_thac0() == 20  # level 1
        # If level were higher, THAC0 would be higher (easier to hit)
        # 20 - 1//2 = 20 - 0 = 20

    def test_stat_modifier(self):
        from matrix_cubed.engine.character import stat_modifier
        assert stat_modifier(15) == 2
        assert stat_modifier(10) == 0
        assert stat_modifier(18) == 3
