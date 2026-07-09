from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "build_source_recovery_corpus.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("build_source_recovery_corpus", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_source_recovery_corpus_covers_all_decompiled_functions() -> None:
    builder = load_builder()
    manifest = builder.build_corpus()
    by_key = {program["key"]: program for program in manifest["programs"]}

    assert manifest["not_source_equivalent"] is True
    assert by_key["start_unpacked"]["recovered_file_count"] == 358
    assert by_key["start_unpacked"]["missing_output_count"] == 0
    assert by_key["game_ovr_payload"]["recovered_file_count"] == 623
    assert by_key["game_ovr_payload"]["missing_output_count"] == 0

    load3d_candidates = [
        role
        for row in by_key["game_ovr_payload"]["functions"]
        for role in row["roles"]
        if role["anchor"] == "load3dmap_error"
    ]
    assert {role["role"] for role in load3d_candidates} == {"map_loader"}
    assert {role["file_offset"] for role in load3d_candidates} == {199365}


def test_game_ovr_recovered_headers_include_original_offset_mapping() -> None:
    builder = load_builder()
    manifest = builder.build_corpus()
    game = next(program for program in manifest["programs"] if program["key"] == "game_ovr_payload")
    function = next(row for row in game["functions"] if row["entry"] == "3000:0c04")
    recovered = ROOT / function["recovered_file"]
    text = recovered.read_text(encoding="utf-8")

    assert function["original_file_offset"] == function["linear"] + 8
    assert "Original GAME.OVR file offset: 199692" in text
    assert "relocation and overlay-manager context are not recovered" in text
