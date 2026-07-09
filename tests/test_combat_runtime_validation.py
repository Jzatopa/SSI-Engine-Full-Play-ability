from __future__ import annotations

import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "validate_combat_runtime.py"


def load_validator():
    spec = importlib.util.spec_from_file_location("validate_combat_runtime", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    spec.loader.exec_module(module)
    return module


def test_combat_runtime_validation_passes_with_boundaries() -> None:
    validator = load_validator()
    report = validator.build_report(ROOT)

    assert report["summary"]["status"] == "pass"
    assert report["summary"]["passing_check_count"] == report["summary"]["check_count"]
    assert report["caloris_event_7"]["map_id"] == 17
    assert report["caloris_event_7"]["event_id"] == 7
    assert report["caloris_event_7"]["monster_id"] == 52
    assert report["caloris_event_7"]["monster_name"] == "RAM WARRIOR"
    assert report["caloris_event_7"]["confidence"]["percent"] == 98

    # These saves are evidence files, not proof of original turn-by-turn combat
    # behavior; the report must keep that distinction visible.
    assert report["dos_evidence"]["save_compare"]["decoded_fields_unchanged"] is True
    assert report["runtime_simulation"]["confidence"]["percent"] < 50
    assert report["runtime_simulation"]["status"] == "pass"
