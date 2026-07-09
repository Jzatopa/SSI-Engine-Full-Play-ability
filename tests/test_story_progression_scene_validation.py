from __future__ import annotations

import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "validate_story_progression_scenes.py"


def load_validator():
    spec = importlib.util.spec_from_file_location("validate_story_progression_scenes", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    spec.loader.exec_module(module)
    return module


def test_story_progression_scene_validation_passes() -> None:
    validator = load_validator()
    report = validator.build_report(ROOT)

    assert report["summary"]["scene_count"] == 5
    assert report["summary"]["passing_scene_count"] == 5
    scene_ids = {scene["id"] for scene in report["scenes"]}
    assert {
        "caloris_surface_sprites",
        "caloris_romney_dialog",
        "caloris_autodoc_dialog",
        "caloris_ram_warrior_combat",
        "geo021_dynamic_combat",
    } == scene_ids
