#!/usr/bin/env python3
"""Probe SAVGAMA.DAT before/after state and character saves."""

from __future__ import annotations

import json
import sys
from dataclasses import asdict
from pathlib import Path

from matrix_cubed.formats.game_state import parse_game_state, diff_game_state, SAVGAMA_SIZE
from matrix_cubed.formats.save import read_saved_character
from matrix_cubed.formats.stf import read_stf


def _check_file(path: Path, label: str, expected_size: int | None = None) -> None:
    if not path.exists():
        print(f"  ⚠  {label}: NOT FOUND at {path}")
        return
    size = path.stat().st_size
    status = "OK" if expected_size is None or size == expected_size else f"MISMATCH (expected {expected_size})"
    print(f"  {'✓' if 'OK' in status else '✗'} {label}: {size} bytes {status}")


def main() -> None:
    import argparse
    parser = argparse.ArgumentParser(description="Analyze Matrix Cubed game state saves.")
    parser.add_argument("pre_dir", type=Path, help="Pre-combat save directory")
    parser.add_argument("post_dir", type=Path | None, nargs="?", default=None, help="Post-combat save directory")
    parser.add_argument("--json", action="store_true", help="Output JSON only")
    args = parser.parse_args()

    if not args.json:
        print("=" * 60)
        print("Matrix Cubed Game State Probe")
        print("=" * 60)

    pre_dat = args.pre_dir / "SAVGAMA.DAT"
    post_dat = args.post_dir / "SAVGAMA.DAT" if args.post_dir else None

    result: dict = {"pre_dir": str(args.pre_dir), "post_dir": str(args.post_dir) if args.post_dir else None}

    # Pre-combat state
    if not args.json:
        print(f"\n--- Pre-Combat ({args.pre_dir}) ---")
    if pre_dat.exists():
        pre_state = parse_game_state(pre_dat)
        result["pre"] = _state_to_dict(pre_state)
        if not args.json:
            print(f"  Area ID: {pre_state.position.area_id}")
            print(f"  Position: x={pre_state.position.x}, y={pre_state.position.y}, facing={pre_state.position.facing}")
            print(f"  Credits: {pre_state.credits}")
            print(f"  Team ({pre_state.team_size}): {[s for s in pre_state.team_slots if s]}")
    else:
        result["pre"] = None
        if not args.json:
            print("  PRE SAVGAMA.DAT: not found")

    # Pre-combat characters
    if not args.json:
        print(f"\n  Character saves:")
    for who_path in sorted(args.pre_dir.glob("CHRDATA*.SAV")):
        char = read_saved_character(who_path)
        stf = read_stf(who_path.with_suffix(".STF")) if who_path.with_suffix(".STF").exists() else None
        if not args.json:
            print(f"  Slot: {char.stem} -> {char.who.name} ({char.who.race}/{char.who.career})")
            print(f"    HP: {char.who.hit_points_candidate}, Level: {char.who.level}")
            print(f"    XP: {char.who.experience}, Credits: {char.who.credits}")
            print(f"    Stats: str={char.who.ability_scores['str']}, dex={char.who.ability_scores['dex']}, con={char.who.ability_scores['con']}")
            if stf:
                print(f"    Saved inventory records: {len(stf.records)}")

    # Post-combat
    if post_dat and post_dat.exists():
        post_state = parse_game_state(post_dat)
        result["post"] = _state_to_dict(post_state)

        if not args.json:
            print(f"\n--- Post-Combat ({args.post_dir}) ---")
            print(f"  Area ID: {post_state.position.area_id}")
            print(f"  Position: x={post_state.position.x}, y={post_state.position.y}, facing={post_state.position.facing}")
            print(f"  Credits: {post_state.credits}")
            print(f"  Team ({post_state.team_size}): {[s for s in post_state.team_slots if s]}")

        if not args.json:
            print(f"\n  Character saves:")
        for who_path in sorted(args.post_dir.glob("CHRDATA*.SAV")):
            char = read_saved_character(who_path)
            stf = read_stf(who_path.with_suffix(".STF")) if who_path.with_suffix(".STF").exists() else None
            if not args.json:
                print(f"  Slot: {char.stem} -> {char.who.name} ({char.who.race}/{char.who.career})")
                print(f"    HP: {char.who.hit_points_candidate}, Level: {char.who.level}")
                print(f"    XP: {char.who.experience}, Credits: {char.who.credits}")

        # Diff
        pre_bytes = pre_dat.read_bytes()
        post_bytes = post_dat.read_bytes()
        diff = diff_game_state(pre_bytes, post_bytes)
        result["diff"] = diff

        if not args.json:
            print(f"\n--- SAVGAMA.DAT Diff ---")
            print(f"  Changed bytes: {diff['total_changed_bytes']}")
            print(f"  Changed regions: {diff['changed_regions']}")
            for c in diff["changes"]:
                print(f"    0x{c['offset']:04X}: {c['before']:3d} (0x{c['before']:02X}) -> {c['after']:3d} (0x{c['after']:02X})")

        # Post-combat characters diff
        if not args.json:
            print(f"\n--- Character Diff ---")
    elif args.post_dir:
        result["post"] = None

    if args.json:
        print(json.dumps(result, indent=2, default=str))


def _state_to_dict(gs) -> dict:
    return {
        "area_id": gs.position.area_id,
        "position": {"x": gs.position.x, "y": gs.position.y, "facing": gs.position.facing},
        "credits": gs.credits,
        "team_size": gs.team_size,
        "team_slots": gs.team_slots,
    }


if __name__ == "__main__":
    main()
