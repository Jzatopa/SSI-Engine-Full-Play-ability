from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "triage_unknown_source_recovery_batch.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("triage_unknown_source_recovery_batch", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_unknown_batch_resolves_100_game_ovr_unknowns() -> None:
    builder = load_builder()
    report = builder.build_batch()

    assert report["summary"]["batch_id"] == "unknown_batch_001"
    assert report["summary"]["eligible_game_unknown_count"] == 600
    assert report["summary"]["selected_count"] == 100
    assert len(report["resolutions"]) == 100
    assert all(row["recovered_file"].startswith("generated/source_recovery/game_ovr_payload/") for row in report["resolutions"])
    assert not any(row["status"] == "deferred_insufficient_static_evidence" for row in report["resolutions"])


def test_unknown_batch_uses_only_conservative_static_categories() -> None:
    builder = load_builder()
    report = builder.build_batch()

    assert report["summary"]["status_counts"] == {
        "resolved_bad_decode": 24,
        "resolved_static_shape": 39,
        "resolved_stub_or_boundary": 37,
    }
    assert report["summary"]["category_counts"] == {
        "bad_decode_or_mixed_code_data": 24,
        "return_only_stub_or_boundary": 37,
        "single_call_wrapper": 39,
    }
    assert all("original" not in row["static_category"] for row in report["resolutions"])
