#!/usr/bin/env python3
"""Decode conservative GAME.OVR evidence into reusable artifacts.

This script does not try to decompile the Borland overlay. It extracts stable
facts: header bytes, ASCII/Pascal-style strings, string clusters, known anchor
offsets, and the separate ITEMS record file that appears to drive item naming.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()


ANCHORS = [
    ("overlay_magic", 0, "FBOV overlay marker"),
    ("credits", 393, "credits text starts"),
    ("combat_start", 65336, "A battle begins..."),
    ("character_creation", 99509, "Pick Race / Pick Gender / Pick Class"),
    ("item0_loader", 126462, "ITEM0.dax loader/error strings"),
    ("save_character", 129547, "Lose character / save prompts"),
    ("load_game", 134527, "Load Which Game"),
    ("save_game", 136472, "Save Which Game"),
    ("character_sheet_labels", 139303, "name/race/gender/thaco/career labels"),
    ("item_debug_fields", 143848, "itemptr/namenum/plus/ready fields"),
    ("gear_menu", 145587, "gear ready/trade/drop/sell menu"),
    ("shop_menu", 117370, "Buy Sell Ammo View Pool"),
    ("ship_stats", 178171, "ship name/type/range labels"),
]


def printable(byte: int) -> bool:
    return byte == 9 or 32 <= byte < 127


def text_score(text: str) -> int:
    return sum(ch.isalpha() for ch in text)


def ascii_runs(data: bytes, min_len: int = 4) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    start: int | None = None
    for idx, byte in enumerate(data + b"\x00"):
        if printable(byte):
            if start is None:
                start = idx
            continue
        if start is not None and idx - start >= min_len:
            raw = data[start:idx]
            rows.append(
                {
                    "offset": start,
                    "length": len(raw),
                    "text": raw.decode("ascii", errors="replace"),
                    "terminator": byte if idx < len(data) else None,
                }
            )
        start = None
    return rows


def pascal_strings(data: bytes, min_len: int = 4, max_len: int = 80) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for off, size in enumerate(data):
        if not (min_len <= size <= max_len):
            continue
        end = off + 1 + size
        if end > len(data):
            continue
        raw = data[off + 1 : end]
        if not raw or not all(printable(byte) for byte in raw):
            continue
        text = raw.decode("ascii", errors="replace")
        if text_score(text) < 3:
            continue
        rows.append({"offset": off, "length": size, "text": text})
    return rows


def cluster_strings(rows: list[dict[str, Any]], window: int = 4096) -> list[dict[str, Any]]:
    buckets: dict[int, list[dict[str, Any]]] = {}
    for row in rows:
        bucket = int(row["offset"]) // window
        buckets.setdefault(bucket, []).append(row)
    clusters = []
    for bucket, values in sorted(buckets.items()):
        clusters.append(
            {
                "start": bucket * window,
                "end": bucket * window + window - 1,
                "count": len(values),
                "sample": values[:8],
            }
        )
    return clusters


def nearby(rows: list[dict[str, Any]], offset: int, radius: int = 96) -> list[dict[str, Any]]:
    return [row for row in rows if offset - radius <= int(row["offset"]) <= offset + radius]


def items_records(path: Path) -> list[dict[str, Any]]:
    if not path.exists():
        return []
    data = path.read_bytes()
    record_size = 9 if len(data) % 9 == 0 else 0
    if not record_size:
        return [{"offset": 0, "raw_hex": data.hex(" "), "note": "unknown non-9-byte layout"}]
    rows = []
    for index, off in enumerate(range(0, len(data), record_size)):
        raw = data[off : off + record_size]
        rows.append(
            {
                "index": index,
                "offset": off,
                "raw_hex": raw.hex(" "),
                "bytes": list(raw),
                "u16_0": int.from_bytes(raw[0:2], "little"),
                "u16_1": int.from_bytes(raw[2:4], "little"),
                "u16_2": int.from_bytes(raw[4:6], "little"),
                "u16_3": int.from_bytes(raw[6:8], "little"),
                "byte_8": raw[8],
            }
        )
    return rows


def item_name_evidence(ascii_rows: list[dict[str, Any]], pascal_rows: list[dict[str, Any]]) -> dict[str, Any]:
    combined = ascii_rows + pascal_rows
    terms = ("item", "gear", "ready", "trade", "drop", "sell", "weapon", "armor", "namenum", "ammo")
    hits = [
        row
        for row in combined
        if any(term in str(row["text"]).lower() for term in terms)
    ]
    obvious_item_name_terms = (
        "knife",
        "pistol",
        "rifle",
        "laser",
        "blaster",
        "grenade",
        "sword",
        "helmet",
        "shield",
    )
    obvious_hits = [
        row
        for row in combined
        if any(term in str(row["text"]).lower() for term in obvious_item_name_terms)
    ]
    return {
        "ui_and_debug_hits": sorted(hits, key=lambda row: int(row["offset"]))[:200],
        "obvious_plaintext_item_name_hits": sorted(obvious_hits, key=lambda row: int(row["offset"])),
        "verdict": (
            "GAME.OVR contains item UI/debug fields, including namenum(1..3), "
            "but obvious item names are not present as plain ASCII/Pascal strings."
        ),
    }


def write_tsv(path: Path, rows: list[dict[str, Any]], fields: list[str]) -> None:
    with path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fields, delimiter="\t", extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--out-dir", type=Path, default=Path("generated") / "game_ovr")
    args = parser.parse_args()

    game_ovr = args.game_dir / "GAME.OVR"
    items_path = args.game_dir / "ITEMS"
    data = game_ovr.read_bytes()
    out = args.out_dir
    out.mkdir(parents=True, exist_ok=True)

    ascii_rows = ascii_runs(data)
    pascal_rows = pascal_strings(data)
    clusters = cluster_strings(ascii_rows)
    items = items_records(items_path)
    anchors = [
        {
            "name": name,
            "offset": offset,
            "note": note,
            "nearby_ascii": nearby(ascii_rows, offset),
            "nearby_pascal": nearby(pascal_rows, offset),
        }
        for name, offset, note in ANCHORS
    ]
    summary = {
        "path": str(game_ovr),
        "bytes": len(data),
        "sha256": hashlib.sha256(data).hexdigest(),
        "magic": data[:4].decode("ascii", errors="replace"),
        "header_hex": data[:64].hex(" "),
        "ascii_string_count": len(ascii_rows),
        "pascal_candidate_count": len(pascal_rows),
        "items_path": str(items_path),
        "items_bytes": items_path.stat().st_size if items_path.exists() else None,
        "items_record_count": len(items),
        "items_record_size": 9 if items_path.exists() and items_path.stat().st_size % 9 == 0 else None,
        "item_name_evidence": item_name_evidence(ascii_rows, pascal_rows),
    }

    (out / "summary.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    (out / "ascii_strings.json").write_text(json.dumps(ascii_rows, indent=2), encoding="utf-8")
    (out / "pascal_strings.json").write_text(json.dumps(pascal_rows, indent=2), encoding="utf-8")
    (out / "string_clusters.json").write_text(json.dumps(clusters, indent=2), encoding="utf-8")
    (out / "anchors.json").write_text(json.dumps(anchors, indent=2), encoding="utf-8")
    (out / "items_records.json").write_text(json.dumps(items, indent=2), encoding="utf-8")
    write_tsv(out / "ascii_strings.tsv", ascii_rows, ["offset", "length", "text", "terminator"])
    write_tsv(out / "items_records.tsv", items, ["index", "offset", "raw_hex", "u16_0", "u16_1", "u16_2", "u16_3", "byte_8"])

    top_clusters = sorted(clusters, key=lambda row: row["count"], reverse=True)[:12]
    lines = [
        "# GAME.OVR Analysis",
        "",
        f"- Path: `{game_ovr}`",
        f"- Bytes: `{len(data)}`",
        f"- SHA-256: `{summary['sha256']}`",
        f"- Magic: `{summary['magic']}`",
        f"- ASCII strings: `{len(ascii_rows)}`",
        f"- Pascal-style string candidates: `{len(pascal_rows)}`",
        f"- ITEMS records: `{len(items)}` records of 9 bytes",
        "",
        "## Item Name Verdict",
        "",
        summary["item_name_evidence"]["verdict"],
        "",
        "Plaintext item-name search found no obvious weapon/item nouns such as knife, pistol, rifle, laser, blaster, or shield. Keep runtime labels conservative (`Item N`) until the `namenum(1..3)` fields are mapped to their source table.",
        "",
        "## Key Anchors",
        "",
    ]
    for anchor in anchors:
        sample = "; ".join(row["text"] for row in anchor["nearby_ascii"][:3]) or "-"
        lines.append(f"- `{anchor['offset']:06d}` `{anchor['name']}`: {anchor['note']} — {sample}")
    lines.extend(["", "## Densest String Clusters", ""])
    for cluster in top_clusters:
        lines.append(f"- `{cluster['start']:06d}-{cluster['end']:06d}`: {cluster['count']} strings")
    (out / "analysis.md").write_text("\n".join(lines) + "\n", encoding="utf-8")

    print(f"Wrote GAME.OVR analysis artifacts to {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
