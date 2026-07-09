#!/usr/bin/env python3
"""Audit original-file coverage and targeted DOS capture gaps.

This report is deliberately conservative: it inventories what is present in
James' local game directories, hashes existing liveplay evidence, and marks
the requested menus/transitions/combat-state changes that still need targeted
DOS captures.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path
from typing import Any

from PIL import Image

from matrix_cubed.formats.game_state import SAVGAMA_SIZE, diff_game_state

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIRS = (
    default_game_dir(),
    Path("/home/jzatopa/Downloads/matrix-cubed-liveplay"),
)

EXPECTED_ARCHIVES = ("GEO1.DAX", "GEO2.DAX", "GEO3.DAX", "GEO4.DAX", "ECL1.DAX", "ECL2.DAX", "ECL3.DAX", "ECL4.DAX")

CAPTURE_TARGETS = (
    {
        "id": "ship_service_menus",
        "label": "ship-service menus",
        "available_patterns": ("ship", "service"),
        "minimum_required": 1,
        "note": "No existing capture is confidently tied to original ship-service UI.",
    },
    {
        "id": "choice_dialogs",
        "label": "choice dialogs",
        "available_patterns": ("after_interaction", "after_search"),
        "minimum_required": 1,
        "note": "Existing captures anchor interaction/search scene families, not OCR-confirmed choices.",
    },
    {
        "id": "caloris_luna_transitions",
        "label": "Caloris/Luna transitions",
        "available_patterns": ("luna", "caloris", "transition"),
        "minimum_required": 1,
        "note": "Traversal data exists, but no exact DOS transition capture is present.",
    },
    {
        "id": "combat_state_changes",
        "label": "combat state changes",
        "available_patterns": ("combat",),
        "minimum_required": 1,
        "note": "Combat UI capture exists; current pre/post SAVGAMA pair is byte-identical.",
    },
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def file_evidence(path: Path) -> dict[str, Any]:
    row: dict[str, Any] = {
        "path": str(path),
        "exists": path.exists(),
    }
    if path.exists():
        row.update({"size": path.stat().st_size, "sha256": sha256(path)})
    return row


def image_evidence(path: Path) -> dict[str, Any]:
    row = file_evidence(path)
    if row["exists"]:
        with Image.open(path) as image:
            row.update({"width": image.width, "height": image.height})
    return row


def list_files(game_dirs: tuple[Path, ...]) -> dict[str, list[Path]]:
    files: dict[str, list[Path]] = {}
    for game_dir in game_dirs:
        if not game_dir.exists():
            continue
        for path in game_dir.iterdir():
            if path.is_file():
                files.setdefault(path.name.upper(), []).append(path)
    return files


def audit_expected_archives(game_dirs: tuple[Path, ...]) -> dict[str, Any]:
    files = list_files(game_dirs)
    rows = []
    for name in EXPECTED_ARCHIVES:
        matches = files.get(name, [])
        rows.append(
            {
                "file": name,
                "present": bool(matches),
                "locations": [file_evidence(path) for path in matches],
            }
        )
    missing = [row["file"] for row in rows if not row["present"]]
    return {
        "status": "partial" if missing else "complete",
        "game_dirs": [str(path) for path in game_dirs],
        "expected": rows,
        "missing": missing,
        "conclusion": (
            "The supplied local game files contain GEO1.DAX and ECL1.DAX only; "
            "no GEO2-4/ECL2-4 archives are present in the audited directories."
            if missing
            else "All expected GEO/ECL archive names are present."
        ),
    }


def all_capture_images(root: Path) -> list[Path]:
    base = root / "generated" / "liveplay"
    if not base.exists():
        return []
    return sorted(base.glob("**/*.png"))


def matching_captures(images: list[Path], patterns: tuple[str, ...]) -> list[Path]:
    rows = []
    for path in images:
        lowered = path.name.lower()
        if any(pattern in lowered for pattern in patterns):
            rows.append(path)
    return rows


def audit_capture_targets(root: Path) -> dict[str, Any]:
    images = all_capture_images(root)
    targets = []
    for target in CAPTURE_TARGETS:
        matches = matching_captures(images, target["available_patterns"])
        status = "available" if len(matches) >= int(target["minimum_required"]) else "missing"
        targets.append(
            {
                "id": target["id"],
                "label": target["label"],
                "status": status,
                "note": target["note"],
                "matching_capture_count": len(matches),
                "captures": [image_evidence(path) for path in matches[:12]],
            }
        )
    return {
        "status": "partial" if any(target["status"] == "missing" for target in targets) else "available",
        "liveplay_image_count": len(images),
        "targets": targets,
    }


def savgama_evidence(root: Path) -> dict[str, Any]:
    pre = root / "generated" / "liveplay" / "pre_combat" / "SAVGAMA.DAT"
    post = root / "generated" / "liveplay" / "post_combat" / "SAVGAMA.DAT"
    row: dict[str, Any] = {
        "pre": file_evidence(pre),
        "post": file_evidence(post),
        "status": "missing",
    }
    if not pre.exists() or not post.exists():
        return row
    if pre.stat().st_size != SAVGAMA_SIZE or post.stat().st_size != SAVGAMA_SIZE:
        row["status"] = "invalid_size"
        return row
    diff = diff_game_state(pre.read_bytes(), post.read_bytes())
    row.update(
        {
            "status": "available",
            "byte_diff": diff,
            "state_mutation_proven": diff["total_changed_bytes"] > 0,
            "interpretation": (
                "Current pre/post combat SAVGAMA.DAT evidence is byte-identical; "
                "it does not prove original combat/session state mutation."
                if diff["total_changed_bytes"] == 0
                else "Pre/post combat SAVGAMA.DAT bytes differ and need region-level interpretation."
            ),
        }
    )
    return row


def decoded_transition_anchors(root: Path) -> dict[str, Any]:
    path = root / "generated" / "traversal" / "map_traversal_reference.json"
    if not path.exists():
        return {"path": str(path), "exists": False, "anchors": []}
    data = json.loads(path.read_text(encoding="utf-8"))
    anchors: list[dict[str, Any]] = []
    for row in data.get("ecl_loads", []):
        target_geo = row.get("target_geo")
        ecl_block = row.get("ecl_block")
        if target_geo in {1, 17, 64} or ecl_block in {1, 17, 64}:
            anchors.append(
                {
                    "kind": "ecl_load",
                    "ecl_block": ecl_block,
                    "address": row.get("address"),
                    "target_geo": target_geo,
                    "map_pos_x": row.get("map_pos_x"),
                    "map_pos_y": row.get("map_pos_y"),
                    "target_loaded": row.get("target_loaded"),
                }
            )
    for row in data.get("cell_edges", []):
        if row.get("source_geo") in {1, 64}:
            anchors.append(
                {
                    "kind": "cell_edge",
                    "source_geo": row.get("source_geo"),
                    "source_name": row.get("source_name"),
                    "row": row.get("row"),
                    "col": row.get("col"),
                    "target_geo": row.get("target_geo"),
                    "target_loaded": row.get("target_loaded"),
                    "interpretation": row.get("interpretation"),
                }
            )
    return {
        "path": str(path),
        "exists": True,
        "anchor_count": len(anchors),
        "anchors": anchors,
        "boundary": "Decoded traversal anchors are route targets for capture, not DOS-screen validation by themselves.",
    }


def build_report(root: Path, game_dirs: tuple[Path, ...] = DEFAULT_GAME_DIRS) -> dict[str, Any]:
    archive_audit = audit_expected_archives(game_dirs)
    capture_audit = audit_capture_targets(root)
    save_audit = savgama_evidence(root)
    transition_anchors = decoded_transition_anchors(root)
    missing_capture_targets = [target["id"] for target in capture_audit["targets"] if target["status"] == "missing"]
    needs_new_combat_state_capture = not bool(save_audit.get("state_mutation_proven"))
    return {
        "source": "scripts/audit_original_capture_targets.py",
        "summary": {
            "status": "partial",
            "archive_status": archive_audit["status"],
            "capture_status": capture_audit["status"],
            "missing_archive_names": archive_audit["missing"],
            "missing_capture_targets": missing_capture_targets,
            "needs_new_combat_state_capture": needs_new_combat_state_capture,
            "boundary": (
                "This audit records current local evidence and capture gaps. "
                "It does not infer absent archives from other releases or claim OCR-confirmed DOS text."
            ),
        },
        "archives": archive_audit,
        "captures": capture_audit,
        "decoded_transition_anchors": transition_anchors,
        "combat_savgama": save_audit,
        "recommended_next_captures": [
            "Ship-service menu route with screenshots before selection, each menu page, and save/memory snapshot after service actions.",
            "OCR-readable choice-dialog capture for Caloris Dr. Romney/autodoc and one branch selection.",
            "Caloris-to-Luna/Luna-to-Caloris transition capture with pre/post SAVGAMA.DAT and screen after arrival.",
            "Combat capture that actually changes SAVGAMA.DAT or character files, with pre/post byte diff retained.",
        ],
    }


def write_markdown(report: dict[str, Any], path: Path) -> None:
    lines = [
        "# Original Archive and DOS Capture Target Audit",
        "",
        "Generated by `scripts/audit_original_capture_targets.py`.",
        "",
        "## Summary",
        "",
        f"- Status: `{report['summary']['status']}`",
        f"- Archive status: `{report['summary']['archive_status']}`",
        f"- Capture status: `{report['summary']['capture_status']}`",
        f"- Missing archive names: `{', '.join(report['summary']['missing_archive_names']) or '-'}`",
        f"- Missing capture targets: `{', '.join(report['summary']['missing_capture_targets']) or '-'}`",
        f"- Needs new combat state capture: `{report['summary']['needs_new_combat_state_capture']}`",
        f"- Boundary: {report['summary']['boundary']}",
        "",
        "## GEO/ECL Archives",
        "",
        report["archives"]["conclusion"],
        "",
        "| File | Present | Locations |",
        "| --- | --- | --- |",
    ]
    for row in report["archives"]["expected"]:
        locations = "<br>".join(f"`{location['path']}`" for location in row["locations"]) or "-"
        lines.append(f"| `{row['file']}` | `{row['present']}` | {locations} |")

    lines.extend(["", "## Capture Targets", "", "| Target | Status | Captures | Note |", "| --- | --- | ---: | --- |"])
    for target in report["captures"]["targets"]:
        lines.append(
            f"| {target['label']} | `{target['status']}` | {target['matching_capture_count']} | {target['note']} |"
        )

    anchors = report["decoded_transition_anchors"]
    lines.extend(
        [
            "",
            "## Decoded Transition Anchors",
            "",
            f"- Source: `{anchors['path']}`",
            f"- Anchor count: `{anchors.get('anchor_count', 0)}`",
            f"- Boundary: {anchors.get('boundary', 'Traversal anchor file missing.')}",
            "",
            "| Kind | Source/ECL | Target GEO | Position | Interpretation |",
            "| --- | --- | ---: | --- | --- |",
        ]
    )
    for anchor in anchors.get("anchors", [])[:32]:
        if anchor["kind"] == "ecl_load":
            source = f"ECL {anchor.get('ecl_block')} @ {anchor.get('address')}"
            position = (
                f"{anchor.get('map_pos_x')},{anchor.get('map_pos_y')}"
                if anchor.get("map_pos_x") is not None and anchor.get("map_pos_y") is not None
                else "-"
            )
            interpretation = f"target_loaded={anchor.get('target_loaded')}"
        else:
            source = f"GEO {anchor.get('source_geo')} cell {anchor.get('row')},{anchor.get('col')}"
            position = "-"
            interpretation = str(anchor.get("interpretation"))
        lines.append(f"| {anchor['kind']} | `{source}` | {anchor.get('target_geo')} | `{position}` | {interpretation} |")

    save = report["combat_savgama"]
    diff = save.get("byte_diff", {})
    lines.extend(
        [
            "",
            "## Combat Save-State Evidence",
            "",
            f"- Pre SAVGAMA: `{save['pre']['path']}`",
            f"- Pre SHA-256: `{save['pre'].get('sha256', '-')}`",
            f"- Post SAVGAMA: `{save['post']['path']}`",
            f"- Post SHA-256: `{save['post'].get('sha256', '-')}`",
            f"- Changed bytes: `{diff.get('total_changed_bytes', '-')}`",
            f"- State mutation proven: `{save.get('state_mutation_proven', False)}`",
            f"- Interpretation: {save.get('interpretation', 'SAVGAMA pair unavailable.')}",
            "",
            "## Recommended Next Captures",
            "",
        ]
    )
    for item in report["recommended_next_captures"]:
        lines.append(f"- {item}")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--out-json", type=Path, default=Path("generated/validation/original_capture_target_audit.json"))
    parser.add_argument("--out-md", type=Path, default=Path("generated/validation/original_capture_target_audit.md"))
    args = parser.parse_args()

    root = args.root.resolve()
    report = build_report(root)
    args.out_json.parent.mkdir(parents=True, exist_ok=True)
    args.out_json.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    write_markdown(report, args.out_md)
    print(
        "audit complete: "
        f"{len(report['summary']['missing_archive_names'])} missing archive names, "
        f"{len(report['summary']['missing_capture_targets'])} missing capture targets"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
