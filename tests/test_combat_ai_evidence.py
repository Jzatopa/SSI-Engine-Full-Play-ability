from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "analyze_combat_ai.py"


def load_analyzer():
    spec = importlib.util.spec_from_file_location("analyze_combat_ai", SCRIPT)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_combat_ai_report_preserves_verified_offsets_and_boundaries() -> None:
    analyzer = load_analyzer()
    report = analyzer.analyze(analyzer.DEFAULT_GAME_OVR)

    assert report["source_sha256"] == analyzer.KNOWN_SHA256
    assert report["known_source_sha256_match"] is True
    assert [row["file_offset"] for row in report["functions"]] == [52000, 53654, 54215, 55309]
    assert "20 attempts" in report["safe_runtime_invariants"][1]
    assert any("9-byte" in item for item in report["unresolved"])
    assert all(row["evidence_slice"]["size"] > 0 for row in report["functions"])
    table = report["items_runtime_table"]
    assert table["source_sha256"] == analyzer.KNOWN_ITEMS_SHA256
    assert table["known_source_sha256_match"] is True
    assert table["record_size"] == 9
    assert table["record_count"] == 39
    assert table["records"][0]["bytes"] == [0] * 9
    assert table["records"][1]["bytes"] == [0, 4, 0, 0, 1, 3, 0, 0, 0]
