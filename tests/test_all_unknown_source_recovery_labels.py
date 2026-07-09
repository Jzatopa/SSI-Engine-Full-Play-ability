from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "label_all_unknown_source_recovery.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("label_all_unknown_source_recovery", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_all_unknown_labels_cover_every_prior_unknown_function() -> None:
    builder = load_builder()
    report = builder.build_labels()

    assert report["summary"]["total_unknown_labeled"] == 958
    assert report["summary"]["already_in_unknown_batch_001"] == 100
    assert report["summary"]["newly_labeled_outside_batch_001"] == 858
    assert report["summary"]["program_counts"] == {
        "game_ovr_payload": 600,
        "start_unpacked": 358,
    }
    assert len(report["labels"]) == 958


def test_all_unknown_labels_include_confidence_scope_and_no_name_claims() -> None:
    builder = load_builder()
    report = builder.build_labels()

    assert any(row["label"] == "insufficient_static_evidence" for row in report["labels"])
    assert all(0 < row["confidence_percent"] <= 100 for row in report["labels"])
    assert all(
        row["confidence_scope"]
        == "Confidence applies to the static shape label, not original name or runtime behavior."
        for row in report["labels"]
    )
    assert "Confidence is not about original function names." in report["confidence_policy"]
