#!/usr/bin/env python3
"""Build a bounded combat validation report from decoded and DOS evidence.

This is intentionally not a claim of original turn-by-turn combat equivalence.
It verifies the exact Caloris event-7 combat queue, ties it to local DOS
capture/save evidence, and records the current deterministic runtime scaffold.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import random
from pathlib import Path
from typing import Any

from PIL import Image

from matrix_cubed.data.repository import ReconstructedData
from matrix_cubed.engine.character import CharacterRecord
from matrix_cubed.engine.combat_loop import CombatLoop
from matrix_cubed.engine.monster_db import MonsterDB
from matrix_cubed.engine.runtime import GameState


DEFAULT_SEED = 52017


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def load_json(path: Path) -> dict[str, Any]:
    return json.loads(path.read_text(encoding="utf-8"))


def image_evidence(path: Path) -> dict[str, Any]:
    if not path.exists():
        return {"path": str(path), "exists": False}
    with Image.open(path) as image:
        width, height = image.size
    return {
        "path": str(path),
        "exists": True,
        "width": width,
        "height": height,
        "sha256": sha256(path),
    }


def file_evidence(path: Path) -> dict[str, Any]:
    if not path.exists():
        return {"path": str(path), "exists": False}
    return {
        "path": str(path),
        "exists": True,
        "size": path.stat().st_size,
        "sha256": sha256(path),
    }


def character_from_probe(row: dict[str, Any]) -> CharacterRecord:
    who = row["who"]
    scores = who["ability_scores"]
    current = who["current_ability_scores"]
    return CharacterRecord(
        name=who["name"],
        strength=scores["str"],
        dexterity=scores["dex"],
        constitution=scores["con"],
        intelligence=scores["int"],
        wisdom=scores["wis"],
        charisma=scores["cha"],
        tech=scores["tech"],
        cur_strength=current["str"],
        cur_dexterity=current["dex"],
        cur_constitution=current["con"],
        cur_intelligence=current["int"],
        cur_wisdom=current["wis"],
        cur_charisma=current["cha"],
        cur_tech=current["tech"],
        gender=who["gender_id"],
        race=who["race_id"],
        career=who["career_id"],
        level=who["level"],
        credits=who["credits"],
        experience=who["experience"],
        age=who["age"],
        hp=who["hit_points_candidate"],
        skills=[0] * 16,
    )


def save_character_summary(probe: dict[str, Any]) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for character in probe.get("characters", []):
        who = character.get("who", {})
        rows.append(
            {
                "stem": character.get("stem"),
                "name": who.get("name"),
                "hp": who.get("hit_points_candidate"),
                "level": who.get("level"),
                "experience": who.get("experience"),
                "credits": who.get("credits"),
            }
        )
    return rows


def compare_save_summaries(pre: list[dict[str, Any]], post: list[dict[str, Any]]) -> dict[str, Any]:
    by_stem = {row["stem"]: row for row in post}
    changed: list[dict[str, Any]] = []
    for before in pre:
        after = by_stem.get(before["stem"])
        if after is None:
            changed.append({"stem": before["stem"], "status": "missing_after"})
            continue
        deltas = {
            key: {"pre": before[key], "post": after[key]}
            for key in ("hp", "level", "experience", "credits")
            if before.get(key) != after.get(key)
        }
        if deltas:
            changed.append({"stem": before["stem"], "status": "changed", "deltas": deltas})
    return {
        "pre_count": len(pre),
        "post_count": len(post),
        "changed_decoded_fields": changed,
        "decoded_fields_unchanged": len(pre) == len(post) and not changed,
    }


def run_runtime_simulation(root: Path, seed: int) -> dict[str, Any]:
    data = ReconstructedData.from_generated(root / "generated")
    state = GameState.start(data, 17)
    pre_probe = load_json(root / "generated" / "liveplay" / "save_probe_pre_combat.json")
    for row in pre_probe["characters"]:
        state.add_character(character_from_probe(row))

    cell = next(cell for cell in state.current_map.geo.cells if cell.event_id == 7)
    state.row = cell.row
    state.col = cell.col
    state.trigger_current_cell("combat validation")
    execution = state.execute_current_event()
    if state.active_encounter is None:
        return {
            "status": "fail",
            "seed": seed,
            "reason": "Caloris event 7 did not queue active combat in runtime.",
        }

    random.seed(seed)
    loop = CombatLoop(state, MonsterDB())
    loop.enter(state.active_encounter)
    rounds = 0
    while loop.active and rounds < 50:
        loop.player_turn()
        if loop.active:
            loop.monster_turn()
        rounds += 1

    rewards = loop.rewards_summary()
    return {
        "status": "pass" if loop.combat is not None and loop.combat.resolved else "fail",
        "seed": seed,
        "rounds": rounds,
        "victory": loop.victory,
        "defeat": loop.defeat,
        "final_status": loop.status(),
        "rewards": rewards,
        "queued_combat": state.active_encounter.to_dict(),
        "compiled_commands": [command.to_dict() for command in execution.commands] if execution else [],
        "confidence": {
            "percent": 45,
            "basis": (
                "Deterministic smoke of current Python combat scaffold only; "
                "damage/THAC0 fields are still derived from decoded ability scores, "
                "not proven original combat formulas."
            ),
        },
    }


def build_report(root: Path, seed: int = DEFAULT_SEED) -> dict[str, Any]:
    caloris_probe = load_json(root / "generated" / "source_runtime" / "caloris_event_7_probe.json")
    pre_probe = load_json(root / "generated" / "liveplay" / "save_probe_pre_combat.json")
    post_probe = load_json(root / "generated" / "liveplay" / "save_probe_post_combat.json")
    pre_summary = save_character_summary(pre_probe)
    post_summary = save_character_summary(post_probe)
    save_compare = compare_save_summaries(pre_summary, post_summary)
    simulation = run_runtime_simulation(root, seed)

    encounter = caloris_probe["active_combat"]["encounters"][0]
    checks = [
        {
            "id": "exact_event",
            "status": "pass" if caloris_probe["map_id"] == 17 and caloris_probe["active_event_id"] == 7 else "fail",
            "note": "Runtime probe targets Caloris GEO 017 event 7.",
        },
        {
            "id": "exact_monster",
            "status": "pass" if encounter.get("monster_id") == 52 and encounter.get("monster_name") == "RAM WARRIOR" else "fail",
            "note": "Event 7 queues decoded monster id 52, RAM WARRIOR.",
        },
        {
            "id": "dos_capture",
            "status": "pass" if (root / "generated" / "liveplay" / "screens" / "14_after_combat_inputs.png").exists() else "fail",
            "note": "A local DOS liveplay combat-input capture exists.",
        },
        {
            "id": "save_pair",
            "status": "pass" if save_compare["pre_count"] and save_compare["post_count"] else "fail",
            "note": "Pre/post combat save probes decode local party records.",
        },
        {
            "id": "runtime_simulation",
            "status": simulation["status"],
            "note": "Current Python combat scaffold resolves the queued encounter deterministically.",
        },
    ]

    return {
        "source": "scripts/validate_combat_runtime.py",
        "summary": {
            "status": "pass" if all(check["status"] == "pass" for check in checks) else "fail",
            "check_count": len(checks),
            "passing_check_count": sum(1 for check in checks if check["status"] == "pass"),
            "boundary": (
                "Exact queue identity is verified from decoded local runtime evidence. "
                "DOS evidence currently anchors combat scene availability and save probes, "
                "not original turn-by-turn combat equivalence."
            ),
        },
        "checks": checks,
        "caloris_event_7": {
            "map_id": caloris_probe["map_id"],
            "event_id": caloris_probe["active_event_id"],
            "event_type": caloris_probe["active_event_type"],
            "active_encounter": caloris_probe["active_encounter"],
            "monster_id": encounter.get("monster_id"),
            "monster_name": encounter.get("monster_name"),
            "address": encounter.get("address"),
            "resolution": encounter.get("resolution"),
            "confidence": {
                "percent": 98,
                "basis": "Constant SETUP_MONSTER operand resolves locally to MON0CHA id 52 in the generated source-runtime probe.",
            },
        },
        "dos_evidence": {
            "combat_capture": image_evidence(root / "generated" / "liveplay" / "screens" / "14_after_combat_inputs.png"),
            "pre_savgama": file_evidence(root / "generated" / "liveplay" / "pre_combat" / "SAVGAMA.DAT"),
            "post_savgama": file_evidence(root / "generated" / "liveplay" / "post_combat" / "SAVGAMA.DAT"),
            "save_compare": save_compare,
            "confidence": {
                "percent": 70,
                "basis": "Local DOS screenshots and saves are hashed; this pass does not OCR combat text or decode all save-state combat flags.",
            },
        },
        "runtime_simulation": simulation,
        "next_steps": [
            "Decode the SAVGAMA.DAT combat/session bytes around pre_combat versus post_combat saves.",
            "Capture an OCR-readable DOS combat transcript for Caloris event 7.",
            "Replace derived combat stats/formulas only when original combat fields or DOS turn logs validate them.",
        ],
    }


def write_markdown(report: dict[str, Any], path: Path) -> None:
    lines = [
        "# Combat Runtime Validation",
        "",
        "This report validates the Caloris event-7 combat queue and records the current runtime combat scaffold.",
        "It intentionally separates exact decoded encounter identity from unproven original combat mechanics.",
        "",
        "## Summary",
        "",
        f"- Status: `{report['summary']['status']}`",
        f"- Checks: {report['summary']['passing_check_count']}/{report['summary']['check_count']}",
        f"- Boundary: {report['summary']['boundary']}",
        "",
        "## Checks",
        "",
        "| Check | Status | Note |",
        "|---|---|---|",
    ]
    for check in report["checks"]:
        lines.append(f"| `{check['id']}` | `{check['status']}` | {check['note']} |")

    event = report["caloris_event_7"]
    lines.extend(
        [
            "",
            "## Exact Encounter Evidence",
            "",
            f"- Map/event: GEO {event['map_id']:03} event {event['event_id']}",
            f"- Encounter: `{event['active_encounter']}`",
            f"- Monster: id `{event['monster_id']}`, `{event['monster_name']}`",
            f"- ECL address: `{event['address']}`",
            f"- Resolution: `{event['resolution']}`",
            f"- Confidence: {event['confidence']['percent']}% - {event['confidence']['basis']}",
            "",
            "## DOS Evidence",
            "",
            f"- Combat capture: `{report['dos_evidence']['combat_capture']['path']}`",
            f"- Capture SHA-256: `{report['dos_evidence']['combat_capture'].get('sha256', '-')}`",
            f"- Pre SAVGAMA SHA-256: `{report['dos_evidence']['pre_savgama'].get('sha256', '-')}`",
            f"- Post SAVGAMA SHA-256: `{report['dos_evidence']['post_savgama'].get('sha256', '-')}`",
            f"- Decoded save fields unchanged: `{report['dos_evidence']['save_compare']['decoded_fields_unchanged']}`",
            f"- Confidence: {report['dos_evidence']['confidence']['percent']}% - {report['dos_evidence']['confidence']['basis']}",
            "",
            "## Runtime Scaffold",
            "",
            f"- Seed: `{report['runtime_simulation']['seed']}`",
            f"- Status: `{report['runtime_simulation']['status']}`",
            f"- Rounds: `{report['runtime_simulation'].get('rounds', '-')}`",
            f"- Victory: `{report['runtime_simulation'].get('victory', '-')}`",
            f"- Defeat: `{report['runtime_simulation'].get('defeat', '-')}`",
            f"- Confidence: {report['runtime_simulation']['confidence']['percent']}% - {report['runtime_simulation']['confidence']['basis']}",
            "",
            "## Next Steps",
            "",
        ]
    )
    for step in report["next_steps"]:
        lines.append(f"- {step}")
    lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--seed", type=int, default=DEFAULT_SEED)
    parser.add_argument("--out-json", type=Path, default=Path("generated/validation/combat_runtime_validation.json"))
    parser.add_argument("--out-md", type=Path, default=Path("generated/validation/combat_runtime_validation.md"))
    args = parser.parse_args()

    root = args.root.resolve()
    report = build_report(root, args.seed)
    args.out_json.parent.mkdir(parents=True, exist_ok=True)
    args.out_json.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    write_markdown(report, args.out_md)
    print(
        f"combat validation {report['summary']['passing_check_count']}/"
        f"{report['summary']['check_count']} checks"
    )
    return 0 if report["summary"]["status"] == "pass" else 1


if __name__ == "__main__":
    raise SystemExit(main())
