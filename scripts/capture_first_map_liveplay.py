#!/usr/bin/env python3
"""Capture a first-map DOSBox liveplay route with screenshots and save evidence."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import time
from pathlib import Path
from typing import Any

from PIL import Image


DEFAULT_SOURCE_GAME = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
DEFAULT_SAVE_SEED = Path("generated/liveplay/pre_combat")
DEFAULT_OUT_DIR = Path("generated/liveplay/first_map_capture")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def copy_game_tree(source: Path, target: Path, save_seed: Path | None) -> Path:
    if target.exists():
        shutil.rmtree(target)
    ignore = shutil.ignore_patterns("dosbox-conf", "MATRIX", "BUCK", "Journal")
    shutil.copytree(source, target, ignore=ignore)
    save_dir = target / "MATRIX" / "SAVE"
    save_dir.mkdir(parents=True, exist_ok=True)
    if save_seed is not None:
        for path in sorted(save_seed.iterdir()):
            if path.is_file():
                shutil.copy2(path, save_dir / path.name)
    (target / "BUCK" / "SAVE").mkdir(parents=True, exist_ok=True)
    return save_dir


def write_conf(game_dir: Path, conf_path: Path) -> None:
    conf_path.parent.mkdir(parents=True, exist_ok=True)
    conf_path.write_text(
        "\n".join(
            [
                "[sdl]",
                "windowresolution=640x480",
                "output=surface",
                "usescancodes=false",
                "",
                "[cpu]",
                "cycles=max",
                "",
                "[dos]",
                "xms=true",
                "",
                "[autoexec]",
                f"mount c {game_dir}",
                "c:",
                "start.exe",
                "",
            ]
        ),
        encoding="utf-8",
    )


class CaptureRun:
    def __init__(self, out_dir: Path, display: str, window_size: str) -> None:
        self.out_dir = out_dir
        self.screen_dir = out_dir / "screens"
        self.screen_dir.mkdir(parents=True, exist_ok=True)
        self.display = display
        self.window_size = window_size
        self.env = {**os.environ, "DISPLAY": display, "SDL_AUDIODRIVER": "dummy"}
        self.window_id: str | None = None
        self.screens: list[dict[str, Any]] = []
        self.keys: list[dict[str, Any]] = []

    def find_window(self, timeout: float = 20.0) -> str:
        deadline = time.time() + timeout
        while time.time() < deadline:
            result = subprocess.run(
                ["xdotool", "search", "--name", "DOSBox-X"],
                env=self.env,
                capture_output=True,
                text=True,
                timeout=5,
            )
            windows = result.stdout.strip().split()
            if windows:
                self.window_id = windows[0]
                return windows[0]
            time.sleep(0.5)
        raise RuntimeError("DOSBox-X window not found")

    def key(self, key_name: str, delay: float = 0.8) -> None:
        if self.window_id is None:
            self.find_window(timeout=5)
        subprocess.run(["pkill", "-f", "zenity"], env=self.env, capture_output=True, timeout=3)
        subprocess.run(["xdotool", "search", "--name", "Quit", "windowclose"], env=self.env, capture_output=True, timeout=3)
        subprocess.run(
            ["xdotool", "key", "--window", str(self.window_id), "--delay", "80", key_name],
            env=self.env,
            capture_output=True,
            timeout=5,
        )
        self.keys.append({"key": key_name, "time": round(time.time(), 3)})
        time.sleep(delay)

    def key_many(self, key_name: str, count: int, delay: float = 0.8) -> None:
        for _ in range(count):
            self.key(key_name, delay=delay)

    def type_text(self, text: str, delay: float = 0.8) -> None:
        if self.window_id is None:
            self.find_window(timeout=5)
        subprocess.run(
            ["xdotool", "type", "--window", str(self.window_id), "--delay", "60", text],
            env=self.env,
            capture_output=True,
            timeout=5,
        )
        self.keys.append({"type": text, "time": round(time.time(), 3)})
        time.sleep(delay)

    def snap(self, label: str) -> Path:
        path = self.screen_dir / f"{len(self.screens):02d}_{label}.png"
        subprocess.run(
            [
                "ffmpeg",
                "-y",
                "-f",
                "x11grab",
                "-video_size",
                self.window_size,
                "-i",
                f"{self.display}.0",
                "-vframes",
                "1",
                str(path),
            ],
            env=self.env,
            capture_output=True,
            timeout=15,
        )
        evidence = image_evidence(path)
        evidence["label"] = label
        self.screens.append(evidence)
        print(f"[snap] {label}: {path} {evidence.get('size', 0)} bytes", flush=True)
        return path


def image_evidence(path: Path) -> dict[str, Any]:
    row: dict[str, Any] = {"path": str(path), "exists": path.exists()}
    if not path.exists():
        return row
    row.update({"size": path.stat().st_size, "sha256": sha256(path)})
    with Image.open(path) as image:
        colors = image.convert("RGB").getcolors(maxcolors=1_000_000)
        row.update(
            {
                "width": image.width,
                "height": image.height,
                "unique_colors": len(colors) if colors is not None else None,
            }
        )
    return row


def file_evidence(path: Path) -> dict[str, Any]:
    row: dict[str, Any] = {"path": str(path), "exists": path.exists()}
    if path.exists():
        row.update({"size": path.stat().st_size, "sha256": sha256(path)})
    return row


def save_manifest(save_dir: Path) -> list[dict[str, Any]]:
    return [file_evidence(path) for path in sorted(save_dir.iterdir()) if path.is_file()]


def copy_saves(save_dir: Path, target: Path) -> list[dict[str, Any]]:
    target.mkdir(parents=True, exist_ok=True)
    for path in sorted(save_dir.iterdir()):
        if path.is_file():
            shutil.copy2(path, target / path.name)
    return save_manifest(target)


def backup_save_dir(save_dir: Path, backup_dir: Path) -> None:
    if backup_dir.exists():
        shutil.rmtree(backup_dir)
    backup_dir.mkdir(parents=True, exist_ok=True)
    if save_dir.exists():
        for path in sorted(save_dir.iterdir()):
            if path.is_file():
                shutil.copy2(path, backup_dir / path.name)


def restore_save_dir(save_dir: Path, backup_dir: Path) -> None:
    save_dir.mkdir(parents=True, exist_ok=True)
    for path in sorted(save_dir.iterdir()):
        if path.is_file():
            path.unlink()
    if backup_dir.exists():
        for path in sorted(backup_dir.iterdir()):
            if path.is_file():
                shutil.copy2(path, save_dir / path.name)


def run_capture(args: argparse.Namespace) -> dict[str, Any]:
    out_dir = args.out_dir.resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    source_game = args.source_game.resolve()
    save_seed = None if args.fresh else args.save_seed.resolve()
    if args.direct_use_source:
        game_dir = source_game
        conf_path = source_game / "dosbox-conf" / "start.conf"
        save_dir = source_game / "MATRIX" / "SAVE"
        backup_save_dir(save_dir, out_dir / "save_backup")
    else:
        game_dir = out_dir / "game"
        conf_path = out_dir / "dosbox.conf"
        save_dir = copy_game_tree(source_game, game_dir, save_seed)
        write_conf(game_dir, conf_path)

    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
    time.sleep(1)

    capture = CaptureRun(out_dir, os.environ.get("DISPLAY", args.display), args.window_size)
    pre_saves = copy_saves(save_dir, out_dir / "pre_saves")
    proc = subprocess.Popen(["dosbox-x", "-conf", str(conf_path)], env=capture.env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    post_saves: list[dict[str, Any]]
    try:
        capture.find_window(timeout=30)
        time.sleep(args.boot_wait)
        capture.snap("boot")

        if args.probe_only:
            capture.keys.append({"probe_only": True, "time": round(time.time(), 3)})
        else:
            if not args.no_boot_escape:
                capture.key("Escape", delay=1.0)
                capture.snap("after_escape")

            capture.key_many("Return", args.title_returns, delay=1.0)
            capture.snap("after_title_sequence")

            if args.fresh:
                capture.key("1", delay=2.0)
                capture.snap("create_character")
                capture.key("Return", delay=1.5)
                capture.snap("race_default")
                capture.key("Return", delay=1.5)
                capture.snap("gender_default")
                capture.key("Return", delay=1.5)
                capture.snap("career_default")
                capture.key("Return", delay=2.0)
                capture.snap("rolled_stats")
                capture.key("Tab", delay=0.8)
                capture.key("Return", delay=2.0)
                capture.snap("skills_done")
                capture.type_text(args.character_name, delay=0.8)
                capture.key("Return", delay=2.0)
                capture.snap("named_character")
                capture.key("6", delay=2.0)
                capture.snap("add_to_team")
                capture.key("Return", delay=2.0)
                capture.snap("team_roster")
                capture.key("A", delay=5.0)
            else:
                capture.key("8", delay=2.0)
                capture.snap("load_saved_game_menu")
                capture.key("A", delay=2.5)
                capture.snap("after_slot_a")
                capture.key("Return", delay=2.0)
                capture.snap("after_load_confirm")
                capture.key("1", delay=0.3)
                capture.key("0", delay=5.0)
            capture.snap("first_map_world")

            route = [
                ("search", ["s", "Return"]),
                ("inspect_space", ["space", "Return"]),
                ("step_forward_1", ["Up"]),
                ("step_forward_2", ["Up"]),
                ("turn_right", ["Right"]),
                ("step_after_turn", ["Up"]),
                ("search_after_walk", ["s", "Return"]),
                ("turn_left", ["Left"]),
                ("step_left_route", ["Up"]),
                ("open_command_menu", ["F10"]),
                ("close_command_menu", ["Escape"]),
            ]
            for label, keys in route:
                for key_name in keys:
                    capture.key(key_name, delay=1.2)
                capture.snap(label)

            capture.key("F10", delay=1.5)
            capture.key("s", delay=1.5)
            capture.snap("save_menu")
            capture.key("A", delay=1.5)
            capture.key("Return", delay=2.5)
            capture.snap("after_save")
    finally:
        post_saves = copy_saves(save_dir, out_dir / "post_saves")
        proc.terminate()
        try:
            proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            proc.kill()
        subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
        if args.direct_use_source:
            restore_save_dir(save_dir, out_dir / "save_backup")

    report = {
        "source": "scripts/capture_first_map_liveplay.py",
        "source_game": str(source_game),
        "copied_game": str(game_dir),
        "dosbox_conf": str(conf_path),
        "mode": "fresh" if args.fresh else "load_seed",
        "save_seed": str(save_seed) if save_seed is not None else None,
        "screens": capture.screens,
        "keys": capture.keys,
        "pre_saves": pre_saves,
        "post_saves": post_saves,
        "summary": {
            "screen_count": len(capture.screens),
            "nonblank_screen_count": sum(1 for row in capture.screens if row.get("unique_colors", 0) and row.get("unique_colors", 0) > 1),
            "save_file_count": len(post_saves),
        },
    }
    return report


def write_markdown(report: dict[str, Any], path: Path) -> None:
    lines = [
        "# First Map DOS Liveplay Capture",
        "",
        "Generated by `scripts/capture_first_map_liveplay.py`.",
        "",
        "## Summary",
        "",
        f"- Screens: `{report['summary']['screen_count']}`",
        f"- Nonblank screens: `{report['summary']['nonblank_screen_count']}`",
        f"- Save files copied: `{report['summary']['save_file_count']}`",
        f"- Save seed: `{report['save_seed']}`",
        f"- Copied game: `{report['copied_game']}`",
        "",
        "## Screens",
        "",
        "| Label | Path | SHA-256 | Colors |",
        "| --- | --- | --- | ---: |",
    ]
    for row in report["screens"]:
        lines.append(f"| {row['label']} | `{row['path']}` | `{row.get('sha256', '-')}` | {row.get('unique_colors', '-')} |")
    lines.extend(["", "## Save Files", "", "| File | Pre SHA-256 | Post SHA-256 |", "| --- | --- | --- |"])
    by_name = {Path(row["path"]).name: row for row in report["post_saves"]}
    for pre in report["pre_saves"]:
        name = Path(pre["path"]).name
        post = by_name.get(name, {})
        lines.append(f"| `{name}` | `{pre.get('sha256', '-')}` | `{post.get('sha256', '-')}` |")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--source-game", type=Path, default=DEFAULT_SOURCE_GAME)
    parser.add_argument("--save-seed", type=Path, default=DEFAULT_SAVE_SEED)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    parser.add_argument("--fresh", action="store_true", help="Create a fresh one-character party instead of loading seed saves.")
    parser.add_argument("--direct-use-source", action="store_true", help="Run the source game directory directly with SAVE backup/restore.")
    parser.add_argument("--probe-only", action="store_true", help="Only boot and capture one frame.")
    parser.add_argument("--character-name", default="HERO")
    parser.add_argument("--display", default=":99")
    parser.add_argument("--window-size", default="1280x1024")
    parser.add_argument("--boot-wait", type=float, default=10.0)
    parser.add_argument("--title-returns", type=int, default=12)
    parser.add_argument("--no-boot-escape", action="store_true")
    args = parser.parse_args()

    report = run_capture(args)
    args.out_dir.mkdir(parents=True, exist_ok=True)
    (args.out_dir / "capture_manifest.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    write_markdown(report, args.out_dir / "capture_manifest.md")
    print(
        f"captured {report['summary']['screen_count']} screens "
        f"({report['summary']['nonblank_screen_count']} nonblank)"
    )
    return 0 if report["summary"]["nonblank_screen_count"] > 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
