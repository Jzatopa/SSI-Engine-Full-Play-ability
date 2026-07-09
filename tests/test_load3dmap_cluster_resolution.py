from __future__ import annotations

import importlib.util
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "resolve_load3dmap_cluster.py"


def load_builder():
    spec = importlib.util.spec_from_file_location("resolve_load3dmap_cluster", SCRIPT)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    assert spec.loader is not None
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_load3dmap_cluster_resolves_string_data_and_loader_window() -> None:
    builder = load_builder()
    report = builder.build_resolution()

    facts = {fact["id"]: fact for fact in report["facts"]}
    assert facts["load3dmap_anchor_is_string_data"]["confidence_percent"] == 99
    assert facts["post_string_code_is_loader_shaped"]["confidence_percent"] == 90
    assert report["resolved_roles"]["load3dmap_loader_code_window"]["payload_start"] == "0x30AD0"
    assert report["resolved_roles"]["load3dmap_loader_code_window"]["payload_end"] == "0x30C10"


def test_ghidra_3000_0c04_is_misaligned_epilogue_entry() -> None:
    builder = load_builder()
    report = builder.build_resolution()

    role = report["resolved_roles"]["3000:0c04"]
    assert role["role"] == "misaligned Ghidra function entry inside Load3DMap epilogue instruction"
    assert role["payload_linear"] == "0x30C04"
    assert role["confidence_percent"] == 99
