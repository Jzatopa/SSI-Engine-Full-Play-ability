#!/usr/bin/env python3
"""Emit reproducible static evidence for the GAME.OVR tactical-combat AI cluster."""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402

DEFAULT_GAME_OVR = default_game_dir() / "GAME.OVR"
DEFAULT_ITEMS = DEFAULT_GAME_OVR.parent / "ITEMS"
OUT_DIR = ROOT / "generated" / "combat_ai"
KNOWN_SHA256 = "d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67"
KNOWN_ITEMS_SHA256 = "9175c15b2390e12f007eed627fa5568a64bc761b81df0d5f43102f1669ca3a5c"

FUNCTIONS = [
    {
        "entry": "0000:cb18",
        "file_offset": 52000,
        "role": "automated_actor_action_loop_candidate",
        "confidence": "high",
        "verified_observations": [
            "Loops over an actor while its combat-state action field remains active.",
            "Reads a remembered combatant pointer from actor combat-state offsets +8/+10.",
            "Enumerates candidate indices through DAT_0000_74ba and resolves pointers through DAT_0000_707f/DAT_0000_7081.",
            "Dispatches target/actor pairs to movement, engagement, or attack-support helpers.",
        ],
    },
    {
        "entry": "0000:d18e",
        "file_offset": 53654,
        "role": "attack_option_score_candidate",
        "confidence": "medium",
        "verified_observations": [
            "Returns a byte-sized computed score.",
            "Combines linked-record fields, actor/target relation helpers, status checks, and a table-derived multiplier.",
        ],
    },
    {
        "entry": "0000:d3bf",
        "file_offset": 54215,
        "role": "linked_attack_option_selector_candidate",
        "confidence": "high",
        "verified_observations": [
            "Walks a linked list at actor offsets +0xf7/+0xf9.",
            "Indexes a 9-byte table at DAT_0000_536e using each record byte +0x2e.",
            "Scores table type 0 through 0000:d18e and retains the greatest score.",
            "Handles table types 1 and 6 through distinct branches.",
        ],
    },
    {
        "entry": "0000:d805",
        "file_offset": 55309,
        "role": "remembered_target_validation_and_search_candidate",
        "confidence": "high",
        "verified_observations": [
            "Validates or clears the remembered target at combat-state offsets +8/+10.",
            "Searches candidate combatants with an explicit 0x14 (20) iteration bound.",
            "Stores the selected candidate pointer back at combat-state offsets +8/+10.",
        ],
    },
]


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def decode_items_table(path: Path) -> dict[str, object]:
    if not path.is_file():
        raise FileNotFoundError(f"ITEMS input not found: {path}")
    data = path.read_bytes()
    if len(data) % 9:
        raise ValueError(f"ITEMS size must be divisible by 9, got {len(data)}")
    return {
        "source": str(path),
        "source_size": len(data),
        "source_sha256": sha256(data),
        "known_source_sha256_match": sha256(data) == KNOWN_ITEMS_SHA256,
        "record_size": 9,
        "record_count": len(data) // 9,
        "alignment": "record index equals 1-based ITEM0 itemptr; record 0 is the all-zero sentinel",
        "runtime_base": "DAT_0000_536e",
        "proven_accessors": {
            "byte_0": "DAT_0000_536e + itemptr*9: item family/category branches",
            "byte_1": "DAT_0000_536f + itemptr*9: copied into a derived runtime field",
            "byte_2": "DAT_0000_5370 + itemptr*9: attack/effect subtype branches and option scoring",
            "byte_4": "DAT_0000_5372 + itemptr*9: copied to runtime field +0xdd",
            "byte_5": "DAT_0000_5373 + itemptr*9: copied to runtime field +0xdf",
            "byte_6": "DAT_0000_5374 + itemptr*9: copied to runtime field +0xe1",
            "byte_7": "DAT_0000_5375 + itemptr*9: normalized to at least 1 in a combat/item check",
            "byte_8": "DAT_0000_5376 + itemptr*9: gates runtime item-effect dispatch",
        },
        "records": [
            {
                "itemptr": index,
                "offset": index * 9,
                "raw_hex": data[index * 9 : index * 9 + 9].hex(" "),
                "bytes": list(data[index * 9 : index * 9 + 9]),
            }
            for index in range(len(data) // 9)
        ],
        "unresolved": "Exact semantic names for numeric fields and original attack-option score weights remain unresolved.",
    }


def analyze(path: Path, items_path: Path = DEFAULT_ITEMS) -> dict[str, object]:
    if not path.is_file():
        raise FileNotFoundError(f"GAME.OVR input not found: {path}")
    data = path.read_bytes()
    digest = sha256(data)
    functions = []
    offsets = [item["file_offset"] for item in FUNCTIONS]
    for index, item in enumerate(FUNCTIONS):
        start = int(item["file_offset"])
        end = offsets[index + 1] if index + 1 < len(offsets) else min(len(data), start + 512)
        row = dict(item)
        row["evidence_slice"] = {
            "start": start,
            "end_exclusive": end,
            "size": end - start,
            "sha256": sha256(data[start:end]),
            "head_hex": data[start : min(end, start + 32)].hex(),
        }
        functions.append(row)
    return {
        "schema": "matrix-cubed-combat-ai-evidence-v1",
        "source": str(path),
        "source_size": len(data),
        "source_sha256": digest,
        "known_source_sha256_match": digest == KNOWN_SHA256,
        "items_runtime_table": decode_items_table(items_path),
        "functions": functions,
        "safe_runtime_invariants": [
            "Automated actors retain a remembered target pointer while it remains valid.",
            "Candidate target search has an explicit bound of 20 attempts.",
            "Attack-option selection is data-driven and score-based.",
        ],
        "unresolved": [
            "Exact semantics and raw contents of the 9-byte DAT_0000_536e table.",
            "Exact candidate ranking performed by unresolved helper calls.",
            "Exact movement/path dispatch and morale thresholds.",
        ],
        "boundary": "Static pseudocode evidence; labels are conservative reconstruction names, not original SSI symbols.",
    }


def write_report(report: dict[str, object]) -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    (OUT_DIR / "combat_ai_evidence.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    lines = [
        "# GAME.OVR Tactical Combat AI Evidence",
        "",
        f"- Source SHA-256: `{report['source_sha256']}`",
        f"- Known local binary match: `{report['known_source_sha256_match']}`",
        f"- ITEMS SHA-256: `{report['items_runtime_table']['source_sha256']}`",
        f"- ITEMS records: `{report['items_runtime_table']['record_count']}` × `9` bytes",
        f"- Boundary: {report['boundary']}",
        "",
        "## Candidate functions",
        "",
    ]
    for function in report["functions"]:
        lines.extend(
            [
                f"### `{function['entry']}` / file offset `{function['file_offset']}`",
                "",
                f"Role: `{function['role']}` ({function['confidence']} confidence)",
                "",
                *[f"- {observation}" for observation in function["verified_observations"]],
                "",
            ]
        )
    lines.extend(["## Unresolved", "", *[f"- {item}" for item in report["unresolved"]], ""])
    (OUT_DIR / "combat_ai_evidence.md").write_text("\n".join(lines), encoding="utf-8")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("game_ovr", nargs="?", type=Path, default=DEFAULT_GAME_OVR)
    parser.add_argument("--items", type=Path, default=DEFAULT_ITEMS)
    args = parser.parse_args()
    report = analyze(args.game_ovr, args.items)
    write_report(report)
    print(f"Wrote {OUT_DIR / 'combat_ai_evidence.json'}")


if __name__ == "__main__":
    main()
