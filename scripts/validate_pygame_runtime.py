#!/usr/bin/env python3
"""Run a headless Pygame smoke test for the desktop runtime."""

from __future__ import annotations

import argparse
import json
import threading
import time
from pathlib import Path
from typing import Any

import pygame
from PIL import Image

from matrix_cubed.tools.pygame_runner import Runner


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out-dir", type=Path, default=Path("generated/runtime_validation"))
    parser.add_argument("--screenshot-name", default="pygame_runner_xvfb_smoke.png")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    args.out_dir.mkdir(parents=True, exist_ok=True)
    screenshot = args.out_dir / args.screenshot_name
    report_path = args.out_dir / "pygame_runner_xvfb_smoke.json"
    report: dict[str, Any] = {
        "events_posted": [],
        "screenshot": str(screenshot),
        "status": "started",
    }

    def post_key(key: int, delay: float = 0.0) -> None:
        if delay:
            time.sleep(delay)
        pygame.event.post(pygame.event.Event(pygame.KEYDOWN, key=key, mod=0))
        pygame.event.post(pygame.event.Event(pygame.KEYUP, key=key, mod=0))
        report["events_posted"].append(pygame.key.name(key))

    def driver() -> None:
        time.sleep(0.8)
        post_key(pygame.K_DOWN)
        post_key(pygame.K_RETURN, 0.2)
        post_key(pygame.K_i, 1.0)
        post_key(pygame.K_i, 0.4)
        post_key(pygame.K_w, 0.2)
        time.sleep(0.6)
        surface = pygame.display.get_surface()
        if surface is not None:
            pygame.image.save(surface, screenshot)
            report["screenshot_exists_midrun"] = screenshot.exists()
            report["display_size"] = list(surface.get_size())
        post_key(pygame.K_ESCAPE)

    threading.Thread(target=driver, daemon=True).start()
    try:
        Runner().run()
    except SystemExit as exc:
        report["system_exit_code"] = exc.code
        report["status"] = "exited"
    except Exception as exc:
        report["status"] = "error"
        report["error"] = repr(exc)
        raise
    finally:
        report["screenshot_exists"] = screenshot.exists()
        if screenshot.exists():
            report["screenshot_size_bytes"] = screenshot.stat().st_size
            image = Image.open(screenshot).convert("RGB")
            colors = image.getcolors(maxcolors=10_000_000) or []
            report["screenshot_dimensions"] = list(image.size)
            report["unique_colors"] = len(colors)
            report["nonblack_pixels"] = sum(count for count, color in colors if color != (0, 0, 0))
        report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
        print(json.dumps(report, indent=2))

    return 0 if (
        report["status"] == "exited"
        and report["screenshot_exists"]
        and report.get("unique_colors", 0) > 20
        and report.get("nonblack_pixels", 0) > 100_000
    ) else 1


if __name__ == "__main__":
    raise SystemExit(main())
