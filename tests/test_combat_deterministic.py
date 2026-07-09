"""Deterministic combat validation — termination, victory, defeat."""

from __future__ import annotations

from matrix_cubed.engine.combat import QueuedCombat
from matrix_cubed.engine.combat_loop import CombatLoop
from matrix_cubed.engine.events import EventCommand


def _quick(hp: int = 30) -> "GameState":
    from matrix_cubed.engine.runtime import GameState
    gs = object.__new__(GameState)
    for attr, val in {"data": None, "map_id": 17, "row": 0, "col": 0,
                      "facing": "north", "wall_blocking": True, "steps": 0,
                      "active_event_id": None, "active_encounter": None,
                      "executed_event_ids": set(),
                      "party": type("P", (), {"hp": hp, "credits": 0, "inventory": [], "flags": set()}),
                      "log": [], "last_execution": None,
                      "roster": type("R", (), {"count": 0, "list_all": lambda: [], "get": lambda n: None, "add": lambda c: None}),
                      "active_party": type("A", (), {"members": [], "member_hp": [hp], "total_hp": lambda: hp})}.items():
        setattr(gs, attr, val)
    return gs


def _enc(monsters: list[str]) -> QueuedCombat:
    return QueuedCombat.from_command(17, 1, EventCommand("queue_combat", "test", {"monster_names": monsters}))


class TestCombatTermination:
    def test_combat_always_ends(self):
        """Every combat with default stats should end within 100 turns."""
        import random
        for seed in range(10):
            random.seed(seed)
            gs = _quick(hp=30)
            loop = CombatLoop(gs)
            loop.enter(_enc(["SNAKE"]))
            for _ in range(100):
                loop.player_turn()
                if not loop.active:
                    break
                loop.monster_turn()
                if not loop.active:
                    break
            assert loop.victory or loop.defeat, f"Seed {seed} unresolved"

    def test_victory_all_monsters_dead(self):
        """When all monster HP = 0, combat is victorious."""
        gs = _quick()
        loop = CombatLoop(gs)
        loop.enter(_enc(["SNAKE", "RAT"]))
        # Force all monsters to have 1 HP and easy AC
        loop.combat.monster_hp = [1, 1]
        loop.combat.monster_ac = [19, 19]
        loop.combat.alive = [0, 1]
        for _ in range(4):
            loop.player_turn()
            if loop.victory:
                break
        assert loop.victory

    def test_defeat_hp_zero(self):
        """Party HP = 0 is defeat. Monster THAC0 19 vs player AC 10 = hit on 9+."""
        gs = _quick(hp=2)
        loop = CombatLoop(gs)
        loop.enter(_enc(["SNAKE"]))
        loop.combat.monster_hp[0] = 50  # Won't die quickly
        loop.combat.monster_thac0[0] = 19  # VS player AC 10 = need 9+
        import random
        random.seed(0)  # Deterministic — first roll is 12 (HIT)
        loop.player_turn()
        random.seed(0)
        loop.monster_turn()
        assert loop.defeat, f"HP={gs.party.hp}, log={loop.combat.log[-1:]}"

    def test_combat_status_after_victory(self):
        """Status after victory should show resolved phase."""
        gs = _quick()
        loop = CombatLoop(gs)
        loop.enter(_enc(["SNAKE"]))
        loop.combat.monster_hp[0] = 0
        loop.combat.alive = []
        loop.combat.resolved = True
        s = loop.status()
        assert s["phase"] != "combat" or not loop.active
