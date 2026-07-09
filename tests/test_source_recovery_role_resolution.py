from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "resolve_source_recovery_roles.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("resolve_source_recovery_roles", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def by_entry(report):
    return {row["entry"]: row for row in report["resolutions"]}


def test_role_resolution_resolves_all_23_candidates() -> None:
    builder = load_builder()
    report = builder.build_resolution()

    assert report["summary"]["candidate_count"] == 23
    assert report["summary"]["resolved_count"] == 23
    assert report["summary"]["status_counts"] == {
        "resolved_bad_decode": 2,
        "resolved_static": 18,
        "resolved_stub_or_boundary": 3,
    }


def test_role_resolution_pins_key_subsystem_decisions() -> None:
    builder = load_builder()
    rows = by_entry(builder.build_resolution())

    assert rows["0000:fb92"]["resolved_role"] == "combat_roster_and_battlefield_setup"
    assert rows["1000:eb60"]["resolved_role"] == "item_type_classification_dispatch"
    assert rows["2000:13fd"]["resolved_role"] == "save_serialized_party_size_calculator"
    assert rows["3000:006f"]["resolved_role"] == "wall_segment_decode_or_emit_routine"
    assert rows["3000:0c04"]["status"] == "resolved_bad_decode"
    assert rows["3000:0c04"]["resolved_role"] == "misaligned_load3dmap_epilogue_entry"
    assert "0x30AD0-0x30C10" in rows["3000:0c04"]["implementation_use"]
