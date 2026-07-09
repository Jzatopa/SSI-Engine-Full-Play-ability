from __future__ import annotations

import importlib.util
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "build_map_viewer.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("build_map_viewer", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    spec.loader.exec_module(module)
    return module


def load_seed_inputs() -> list[dict]:
    maps = json.loads((ROOT / "generated" / "geo1" / "geo1_maps.json").read_text(encoding="utf-8"))
    atlas = json.loads((ROOT / "generated" / "event_atlas" / "event_atlas.json").read_text(encoding="utf-8"))
    wallsets = load_builder().read_wallsets(ROOT / "generated" / "geo1" / "wallsets.tsv")
    atlas_by_geo = {item["geo_id"]: item for item in atlas}
    for item in maps:
        item["atlas"] = atlas_by_geo.get(item["id"], {})
        item["wallsets"] = wallsets.get(item["id"], {})
    return maps


def test_runtime_seed_adds_surface_textures_for_caloris() -> None:
    builder = load_builder()
    seed = builder.build_runtime_seed(
        load_seed_inputs(),
        ROOT / "generated" / "wall_textures",
        "../wall_textures",
    )
    caloris = next(map_row for map_row in seed["maps"] if map_row["id"] == 17)

    assert caloris["wallTextureSet"] == "005"
    assert caloris["surfaceTextures"] == {
        "ceiling": "walldef1_005_wall_01_view_00.png",
        "floor": "walldef1_005_wall_02_view_00.png",
    }


def test_runtime_seed_attaches_ecl_dialog_choices() -> None:
    builder = load_builder()
    seed = builder.build_runtime_seed(
        load_seed_inputs(),
        ROOT / "generated" / "wall_textures",
        "../wall_textures",
        dialog_reference_json=ROOT / "generated" / "ecl_text_goldbox" / "ecl_dialog_reference.json",
    )
    caloris = next(map_row for map_row in seed["maps"] if map_row["id"] == 17)

    romney = caloris["events"]["20"]["dialog"]
    autodoc = caloris["events"]["28"]["dialog"]

    assert romney["status"] == "ecl_dialog_reference"
    assert [choice["label"] for choice in romney["choices"]] == ["HELP ROMNEY"]
    assert [choice["label"] for choice in autodoc["choices"]] == ["SOMEONE ELSE?"]


def test_playable_template_executes_dialog_choices_and_surface_textures() -> None:
    builder = load_builder()
    template = builder.PLAYABLE_TEMPLATE

    assert "function executeDialogChoice" in template
    assert "data-dialog-choice" in template
    assert "function surfaceTexture" in template
    assert "drawSurface('ceiling'" in template
    assert "drawSurface('floor'" in template
