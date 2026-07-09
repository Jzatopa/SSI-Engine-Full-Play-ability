"""Combat validation — simulate first Caloris Space Port encounter."""

from __future__ import annotations

from pathlib import Path

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.runtime import GameState
from matrix_cubed.engine.character import CharacterRecord, stat_modifier
from matrix_cubed.engine.combat import QueuedCombat
from matrix_cubed.engine.monster_db import MonsterDB
from matrix_cubed.engine.level_up import grant_xp


def _hero() -> CharacterRecord:
    """Create a test character matching a fresh level-1 character."""
    return CharacterRecord(
        name="VAL", strength=13, dexterity=11, constitution=14,
        intelligence=10, wisdom=9, charisma=12, tech=10,
        cur_strength=13, cur_dexterity=11, cur_constitution=14,
        cur_intelligence=10, cur_wisdom=9, cur_charisma=12, cur_tech=10,
        gender=0, race=1, career=1, level=1, credits=50,
        experience=0, age=25, hp=30, skills=[0]*16,
    )


def main() -> None:
    data = ReconstructedData.from_generated(Path("generated"))
    gs = GameState.start(data, map_id=17)
    gs.add_character(_hero())

    char = gs.active_party.members[0]
    db = MonsterDB()

    log_steps: list[str] = []

    def info(msg: str) -> None:
        log_steps.append(msg)
        print(f"  {msg}")

    print("=== MATRIX CUBED COMBAT VALIDATION ===")
    print(f"Map: {gs.current_map.geo.name} (GEO {gs.map_id:03})")
    print(f"Start position: ({gs.col}, {gs.row}) facing {gs.facing}")
    info(f"Character: {char.name} STR={char.strength} ({stat_modifier(char.strength):+d}) "
          f"LVL={char.level} HP={char.hp}")

    # Check starting cell
    cell = gs.current_map.geo.cell_at(gs.row, gs.col)
    if cell and cell.event_id:
        info(f"Start cell event: {cell.event_id} (flag={cell.event_flag})")

    # Walk forward to trigger first event
    print("\n--- Movement ---")
    for step in range(5):
        prev_event = gs.active_event_id
        gs.perform("forward")
        pos = (gs.col, gs.row)
        cell = gs.current_map.geo.cell_at(gs.row, gs.col)
        event_id = cell.event_id if cell else None

        if gs.active_encounter:
            enc = gs.active_encounter
            info(f"Step {step + 1}: pos={pos} → COMBAT: {', '.join(enc.monster_names)}")
            monster_stats = db.combat_stats_for_name(enc.monster_names[0]) if enc.monster_names else {}
            info(f"  Monster stats: {monster_stats}")

            # Resolve combat
            from matrix_cubed.engine.combat_loop import CombatLoop
            loop = CombatLoop(gs, db)
            loop.enter(enc)

            turn = 0
            while loop.active and turn < 50:
                loop.player_turn()
                if not loop.active:
                    break
                loop.monster_turn()
                turn += 1

            if loop.victory:
                rewards = loop.rewards_summary()
                new_char, xp_lines = grant_xp(char, rewards["xp"])
                gs.active_party.members[0] = new_char
                gs.active_party.member_hp[0] = new_char.hp
                gs.add_credits(rewards["credits"])
                info(f"  Victorious in {turn} turns! XP={rewards['xp']}, Credits={rewards['credits']}")
                info(f"  Final HP={gs.party.hp}, Level={new_char.level}")
                for line in loop.combat.log:
                    print(f"    [{line}]")
            elif loop.defeat:
                info(f"  Defeated after {turn} turns")
            break
        elif event_id and event_id != prev_event:
            gs.execute_current_event()
            snap = gs.snapshot()
            info(f"Step {step + 1}: pos={pos} → Event {event_id} ({snap.get('active_event_type','?')})")
        elif gs.map_id != 17:
            info(f"Step {step + 1}: pos={pos} → TRANSITION to GEO {gs.map_id:03}")
            break
        else:
            info(f"Step {step + 1}: pos={pos} (no event)")

    print("\n=== VALIDATION SUMMARY ===")
    print(f"Final position: ({gs.col}, {gs.row}) on GEO {gs.map_id:03}")
    print(f"Final HP: {gs.party.hp}, Credits: {gs.party.credits}")
    print(f"Level: {gs.active_party.members[0].level if gs.active_party.members else '?'}")


if __name__ == "__main__":
    main()
