from __future__ import annotations

import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "audit_original_capture_targets.py"


def load_audit():
    spec = importlib.util.spec_from_file_location("audit_original_capture_targets", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    spec.loader.exec_module(module)
    return module


def test_original_capture_target_audit_preserves_missing_evidence_boundaries() -> None:
    audit = load_audit()
    report = audit.build_report(ROOT)

    assert report["summary"]["status"] == "partial"
    assert {"GEO2.DAX", "GEO3.DAX", "GEO4.DAX", "ECL2.DAX", "ECL3.DAX", "ECL4.DAX"}.issubset(
        set(report["summary"]["missing_archive_names"])
    )
    assert report["combat_savgama"]["status"] == "available"
    assert report["combat_savgama"]["byte_diff"]["total_changed_bytes"] == 0
    assert report["summary"]["needs_new_combat_state_capture"] is True
    assert report["decoded_transition_anchors"]["anchor_count"] > 0
    assert any(
        anchor["kind"] == "ecl_load" and anchor["target_geo"] in {1, 17, 64}
        for anchor in report["decoded_transition_anchors"]["anchors"]
    )

    targets = {target["id"]: target for target in report["captures"]["targets"]}
    assert targets["combat_state_changes"]["status"] == "available"
    assert targets["ship_service_menus"]["status"] == "missing"
    assert targets["caloris_luna_transitions"]["status"] == "missing"
