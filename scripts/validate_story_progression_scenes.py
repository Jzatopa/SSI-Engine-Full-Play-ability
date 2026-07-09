#!/usr/bin/env python3
"""Validate high-value story progression scenes against local evidence."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

from PIL import Image


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def image_evidence(path: Path) -> dict:
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


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def require(condition: bool, note: str, checks: list[dict]) -> None:
    checks.append({"status": "pass" if condition else "fail", "note": note})


def scene_status(checks: list[dict]) -> str:
    return "pass" if all(check["status"] == "pass" for check in checks) else "fail"


def build_report(root: Path) -> dict:
    seed = load_json(root / "generated" / "viewer" / "matrix_cubed_runtime_seed.json")
    caloris = next(map_row for map_row in seed["maps"] if map_row["id"] == 17)
    geo21 = next(map_row for map_row in seed["maps"] if map_row["id"] == 21)
    caloris_probe = load_json(root / "generated" / "source_runtime" / "caloris_event_7_probe.json")
    geo21_probe = load_json(root / "generated" / "source_runtime" / "geo021_event_4_dynamic_probe.json")

    captures = {
        "loaded_game_world": image_evidence(root / "generated" / "liveplay" / "screens" / "z_a01_game_world.png"),
        "post_interaction": image_evidence(root / "generated" / "liveplay" / "screens" / "12_after_interaction.png"),
        "combat_inputs": image_evidence(root / "generated" / "liveplay" / "screens" / "14_after_combat_inputs.png"),
        "search_exploration": image_evidence(root / "generated" / "liveplay" / "screens" / "f_04_after_search.png"),
    }

    scenes = []

    checks: list[dict] = []
    require(caloris["surfaceTextures"].get("ceiling") == "walldef1_005_wall_01_view_00.png", "Caloris ceiling texture is present in runtime seed.", checks)
    require(caloris["surfaceTextures"].get("floor") == "walldef1_005_wall_02_view_00.png", "Caloris floor texture is present in runtime seed.", checks)
    require((root / "generated" / "wall_textures" / caloris["surfaceTextures"].get("ceiling", "")).exists(), "Ceiling texture PNG exists on disk.", checks)
    require((root / "generated" / "wall_textures" / caloris["surfaceTextures"].get("floor", "")).exists(), "Floor texture PNG exists on disk.", checks)
    require(captures["loaded_game_world"]["exists"], "DOS liveplay capture exists for loaded game-world baseline.", checks)
    scenes.append(
        {
            "id": "caloris_surface_sprites",
            "title": "Caloris floor and ceiling sprites",
            "status": scene_status(checks),
            "dos_capture": captures["loaded_game_world"],
            "checks": checks,
            "limits": "Capture confirms an original-game world baseline exists; this pass does not pixel-match viewport textures to DOS.",
        }
    )

    checks = []
    romney = caloris["events"]["20"]
    require("DR. ROMNEY" in romney["text"], "Caloris event 20 is the Dr. Romney encounter.", checks)
    require([choice["label"] for choice in romney["dialog"]["choices"]] == ["HELP ROMNEY"], "ECL dialog reference exposes HELP ROMNEY as an executable choice.", checks)
    require(captures["post_interaction"]["exists"], "DOS liveplay has an interaction-stage capture available.", checks)
    scenes.append(
        {
            "id": "caloris_romney_dialog",
            "title": "Caloris Dr. Romney dialog choice",
            "status": scene_status(checks),
            "dos_capture": captures["post_interaction"],
            "checks": checks,
            "limits": "Runtime choice is tied to decoded ECL text/reference evidence; the current DOS capture is not OCR-confirmed for this exact text.",
        }
    )

    checks = []
    autodoc = caloris["events"]["28"]
    require("DO YOU NEED HEALING" in autodoc["text"], "Caloris event 28 is the autodoc healing prompt.", checks)
    require([choice["label"] for choice in autodoc["dialog"]["choices"]] == ["SOMEONE ELSE?"], "ECL dialog reference exposes SOMEONE ELSE? as an executable choice.", checks)
    require(captures["post_interaction"]["exists"], "DOS liveplay has an interaction-stage capture available.", checks)
    scenes.append(
        {
            "id": "caloris_autodoc_dialog",
            "title": "Caloris autodoc branch choice",
            "status": scene_status(checks),
            "dos_capture": captures["post_interaction"],
            "checks": checks,
            "limits": "Runtime choice is tied to decoded ECL text/reference evidence; exact DOS prompt capture remains a later liveplay target.",
        }
    )

    checks = []
    require(caloris_probe["map_id"] == 17 and caloris_probe["active_event_id"] == 7, "Source-runtime probe targets Caloris event 7.", checks)
    require(caloris_probe["active_event_type"] == "combat", "Caloris event 7 is classified as combat.", checks)
    require("RAM WARRIOR" in caloris_probe["active_encounter"], "Caloris event 7 queues RAM WARRIOR.", checks)
    require(captures["combat_inputs"]["exists"], "DOS liveplay has a combat-input capture available.", checks)
    scenes.append(
        {
            "id": "caloris_ram_warrior_combat",
            "title": "Caloris RAM Warrior combat progression",
            "status": scene_status(checks),
            "dos_capture": captures["combat_inputs"],
            "checks": checks,
            "limits": "Combat queue is decoded locally; the DOS capture anchors combat UI availability, not a turn-by-turn equivalence check.",
        }
    )

    checks = []
    require(geo21["events"]["4"]["type"] == "combat", "GEO 021 event 4 is a combat candidate in the HTML runtime seed.", checks)
    candidates = geo21_probe["active_combat"]["candidate_monster_names"]
    require({"MER. WARRIOR", "PIRATE LEADER", "RAM WARRIOR", "SECURITY ROBOT"}.issubset(candidates), "Dynamic encounter candidate table is preserved.", checks)
    require(captures["search_exploration"]["exists"], "DOS liveplay has a search/exploration capture available.", checks)
    scenes.append(
        {
            "id": "geo021_dynamic_combat",
            "title": "GEO 021 dynamic combat branch",
            "status": scene_status(checks),
            "dos_capture": captures["search_exploration"],
            "checks": checks,
            "limits": "Dynamic encounter candidates are locally decoded; exact branch selection still needs a targeted DOS route capture.",
        }
    )

    return {
        "source": "scripts/validate_story_progression_scenes.py",
        "summary": {
            "scene_count": len(scenes),
            "passing_scene_count": sum(1 for scene in scenes if scene["status"] == "pass"),
            "evidence_limit": "DOS screenshots are hashed and tied to scene families; exact prompt OCR/pixel equivalence is marked where still pending.",
        },
        "captures": captures,
        "scenes": scenes,
    }


def write_markdown(report: dict, path: Path) -> None:
    lines = [
        "# Story Progression Scene Validation",
        "",
        "This report ties the HTML runtime seed and source-runtime probes to local DOS liveplay captures.",
        "It separates confirmed local reconstruction checks from capture limits so uncertain text/menu ownership is not overstated.",
        "",
        "## Summary",
        "",
        f"- Scenes: {report['summary']['scene_count']}",
        f"- Passing scenes: {report['summary']['passing_scene_count']}",
        f"- Evidence limit: {report['summary']['evidence_limit']}",
        "",
        "## Scenes",
        "",
    ]
    for scene in report["scenes"]:
        capture = scene["dos_capture"]
        lines.extend(
            [
                f"### {scene['title']}",
                "",
                f"- Status: `{scene['status']}`",
                f"- DOS capture: `{capture['path']}`",
                f"- Capture SHA-256: `{capture.get('sha256', '-')}`",
                f"- Capture dimensions: `{capture.get('width', '-')}x{capture.get('height', '-')}`",
                f"- Limit: {scene['limits']}",
                "",
                "| Check | Status |",
                "|---|---|",
            ]
        )
        for check in scene["checks"]:
            lines.append(f"| {check['note']} | `{check['status']}` |")
        lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--out-json", type=Path, default=Path("generated/validation/story_progression_scene_validation.json"))
    parser.add_argument("--out-md", type=Path, default=Path("generated/validation/story_progression_scene_validation.md"))
    args = parser.parse_args()

    root = args.root.resolve()
    report = build_report(root)
    args.out_json.parent.mkdir(parents=True, exist_ok=True)
    args.out_json.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    write_markdown(report, args.out_md)
    print(
        f"validated {report['summary']['passing_scene_count']}/"
        f"{report['summary']['scene_count']} story progression scenes"
    )
    return 0 if report["summary"]["passing_scene_count"] == report["summary"]["scene_count"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
