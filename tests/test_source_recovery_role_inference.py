from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "infer_source_recovery_roles.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("infer_source_recovery_roles", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def game_rows(report):
    game = next(program for program in report["programs"] if program["key"] == "game_ovr_payload")
    return {(row["entry"], row["name"]): row for row in game["functions"]}


def test_role_inference_identifies_high_value_anchor_candidates() -> None:
    builder = load_builder()
    report = builder.infer_roles()
    rows = game_rows(report)

    assert report["summary"]["function_count"] == 981
    assert report["summary"]["role_inferred_count"] == 23
    assert rows[("1000:eeec", "FUN_1000_eeec")]["likely_roles"] == ["items"]
    assert rows[("1000:fad0", "FUN_1000_fad0")]["likely_roles"] == ["save_load"]
    assert rows[("3000:006f", "FUN_3000_006f")]["likely_roles"] == ["map_loader", "wall_loader"]


def test_role_inference_keeps_empty_load3dmap_neighbor_low_confidence() -> None:
    builder = load_builder()
    report = builder.infer_roles()
    row = game_rows(report)[("3000:0c04", "FUN_3000_0c04")]

    assert row["likely_roles"] == ["map_loader", "wall_loader"]
    assert row["confidence"] == "low"
    assert row["outbound_call_count"] == 0
    assert any("stub-like" in item for item in row["action_summary"])
