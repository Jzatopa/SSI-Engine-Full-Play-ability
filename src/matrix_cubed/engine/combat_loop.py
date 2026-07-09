"""THAC0-based combat loop — actual monster stats from MonsterDB."""

from __future__ import annotations

import random
from dataclasses import dataclass, field
from typing import Any

from matrix_cubed.engine.combat import QueuedCombat
from matrix_cubed.engine.runtime import GameState
from matrix_cubed.engine.character import stat_modifier
from matrix_cubed.engine.monster_db import MonsterDB


@dataclass
class CombatState:
    """Mutable combat state for one encounter."""
    encounter: QueuedCombat
    turn: int = 0
    monster_hp: list[int] = field(default_factory=list)
    monster_ac: list[int] = field(default_factory=list)
    monster_thac0: list[int] = field(default_factory=list)
    monster_dmg: list[int] = field(default_factory=list)
    alive: list[int] = field(default_factory=list)
    log: list[str] = field(default_factory=list)
    resolved: bool = False


class CombatLoop:
    """THAC0-based combat with MonsterDB stat lookup."""

    PLAYER_THAC0_BASE = 20
    MONSTER_THAC0_DEFAULT = 19
    PLAYER_DAMAGE_DIE = 6
    MONSTER_DAMAGE_DEFAULT = 2

    def __init__(self, gs: GameState, monster_db: MonsterDB | None = None) -> None:
        self.gs = gs
        self.monster_db = monster_db or MonsterDB()
        self.combat: CombatState | None = None

    # ── Lifecycle ──────────────────────────────────────────────────────────

    def enter(self, enc: QueuedCombat) -> None:
        """Initialise with monster stats from DB + encounter copies."""
        hp: list[int] = []
        ac: list[int] = []
        thac0: list[int] = []
        dmg: list[int] = []
        names: list[str] = []

        # Prefer the detailed encounters data (with copies/stats) over flat names
        encounter_items = list(enc.encounters) if enc.encounters else []

        if encounter_items:
            for e in encounter_items:
                ename = e.get("monster_name") or ""
                copies = e.get("copies")
                if isinstance(copies, int) and copies > 1:
                    names.extend([ename] * copies)
                else:
                    names.append(ename)
        else:
            names = list(enc.monster_names)

        if not names:
            names = list(enc.display_names())

        for name in names:
            stats = self.monster_db.combat_stats_for_name(name)
            hp.append(stats["hp"])
            ac.append(stats["ac"])
            thac0.append(stats["thac0"])
            dmg.append(stats["damage"])

        self.combat = CombatState(
            encounter=enc,
            monster_hp=hp,
            monster_ac=ac,
            monster_thac0=thac0,
            monster_dmg=dmg,
            alive=list(range(len(names))),
            log=[f"Combat! {', '.join(names)}"],
        )

    def player_turn(self) -> list[str]:
        """Player attacks all alive monsters."""
        if not self.combat or self.combat.resolved:
            return []
        self.combat.turn += 1
        lines: list[str] = []

        for idx in list(self.combat.alive):
            name = self._monster_name(idx)
            mod = self._player_attack_bonus()
            roll = random.randint(1, 20)
            thac0 = self._player_thac0()
            target_ac = self.combat.monster_ac[idx] if idx < len(self.combat.monster_ac) else 10
            hit_needed = thac0 - target_ac

            if roll == 20 or (roll + mod >= hit_needed):
                dmg_val = self._player_damage()
                self.combat.monster_hp[idx] -= dmg_val
                action = "HIT"
                lines.append(f"{name}: d20 {roll}{self._mod_str(mod)} vs AC {target_ac} = {action} ({dmg_val})")
                if self.combat.monster_hp[idx] <= 0:
                    lines.append(f"{name} is defeated!")
                    self.combat.alive.remove(idx)
            else:
                lines.append(f"{name}: d20 {roll}{self._mod_str(mod)} vs AC {target_ac} = miss")

        if not self.combat.alive:
            self.combat.resolved = True
            self.combat.log.append("Victory! All enemies defeated.")

        self.combat.log.extend(lines)
        return lines

    def monster_turn(self) -> list[str]:
        """All alive monsters attack the party."""
        if not self.combat or self.combat.resolved:
            return []
        lines: list[str] = []

        for idx in list(self.combat.alive):
            name = self._monster_name(idx)
            roll = random.randint(1, 20)
            monster_thac0 = self.combat.monster_thac0[idx] if idx < len(self.combat.monster_thac0) else self.MONSTER_THAC0_DEFAULT
            target_ac = self._player_ac()
            hit_needed = monster_thac0 - target_ac

            if roll == 20 or roll >= hit_needed:
                dmg_val = self.combat.monster_dmg[idx] if idx < len(self.combat.monster_dmg) else self.MONSTER_DAMAGE_DEFAULT
                self.gs.apply_damage(dmg_val)
                lines.append(f"{name}: d20 {roll} vs AC {target_ac} = HIT ({dmg_val})")
                if self.gs.party.hp <= 0:
                    lines.append("Party has been defeated!")
                    self.combat.resolved = True
                    break
            else:
                lines.append(f"{name}: d20 {roll} vs AC {target_ac} = miss")

        self.combat.log.extend(lines)
        return lines

    # ── Rewards ────────────────────────────────────────────────────────────

    def rewards_summary(self) -> dict[str, int | list[str]]:
        """Calculate post-combat rewards from defeated monster stats."""
        if not self.combat or not self.combat.resolved:
            return {"xp": 0, "credits": 0, "items": []}

        total_xp = 0
        total_credits = 0
        items: list[str] = []

        for idx, name in enumerate(self.combat.encounter.monster_names):
            if idx >= len(self.combat.monster_hp) or self.combat.monster_hp[idx] > 0:
                continue  # Only reward for killed monsters
            mon = self.monster_db.by_name(name)
            if mon:
                stats = mon.get("stats", {})
                xp = 10 + stats.get("strength", 10) * 5
                total_xp += xp
                total_credits += stats.get("strength", 10)
            else:
                total_xp += 50
                total_credits += 10

        # Credits from encounter definitions
        for enc in self.combat.encounter.encounters:
            pass  # ECL encounters may have reward fields

        return {"xp": total_xp, "credits": total_credits, "items": items}

    # ── Queries ────────────────────────────────────────────────────────────

    @property
    def active(self) -> bool:
        return self.combat is not None and not self.combat.resolved

    @property
    def victory(self) -> bool:
        return self.combat is not None and not self.combat.alive

    @property
    def defeat(self) -> bool:
        return self.gs.party.hp <= 0

    def status(self) -> dict[str, Any]:
        if not self.combat:
            return {"phase": "idle"}
        return {
            "phase": "combat",
            "turn": self.combat.turn,
            "player_hp": self.gs.party.hp,
            "player_thac0": self._player_thac0(),
            "monster_names": list(self.combat.encounter.monster_names),
            "monster_hp": list(self.combat.monster_hp),
            "alive_count": len(self.combat.alive),
            "log": list(self.combat.log),
        }

    # ── Stat helpers ───────────────────────────────────────────────────────

    def _player_strength(self) -> int:
        return self.gs.active_party.members[0].strength if self.gs.active_party.members else 10

    def _player_level(self) -> int:
        return self.gs.active_party.members[0].level if self.gs.active_party.members else 1

    def _player_thac0(self) -> int:
        return self.PLAYER_THAC0_BASE - self._player_level() // 2

    def _player_attack_bonus(self) -> int:
        return stat_modifier(self._player_strength())

    def _player_ac(self) -> int:
        return 10 - stat_modifier(self._player_strength())

    def _player_damage(self) -> int:
        return max(1, self.PLAYER_DAMAGE_DIE // 2 + stat_modifier(self._player_strength()))

    @staticmethod
    def _mod_str(mod: int) -> str:
        return f"{mod:+d}" if mod else ""

    def _monster_name(self, idx: int) -> str:
        names = self.combat.encounter.monster_names if self.combat else ()
        return names[idx] if idx < len(names) else f"Monster {idx}"
