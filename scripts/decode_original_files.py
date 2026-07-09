#!/usr/bin/env python3
"""Conservative structural decoder for the original Matrix Cubed files.

This pass is intentionally evidence-first. It decompresses DAX blocks and
records hashes, sizes, string candidates, and layout hints, but does not assign
semantic labels unless the project already has local evidence for that family.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from collections import Counter
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()
DEFAULT_OUT_DIR = Path("generated") / "original_files"

KNOWN_RECORD_HINTS: dict[str, list[dict[str, Any]]] = {
    "GEO1.DAX": [{"record_size": 1026, "basis": "existing GEO1 parser consumes 25 map blocks"}],
    "ITEM0.DAX": [{"record_size": 16, "basis": "existing data_model item template decoder"}],
    "ITEMS": [{"record_size": 9, "basis": "existing GAME.OVR ITEMS side-file analysis"}],
    "MON0CHA.DAX": [{"record_size": 259, "basis": "existing monster/character record decoder"}],
    "MON0SPC.DAX": [{"record_size": 9, "basis": "existing effect record decoder"}],
    "MON0ITM.DAX": [{"record_size": 62, "basis": "existing data_model structural hint only"}],
}

DAX_SEMANTIC_STATUS: dict[str, str] = {
    "ECL1.DAX": "partially decoded: ECL block extraction/disassembly exists",
    "GEO1.DAX": "partially decoded: 25 map blocks parsed",
    "ITEM0.DAX": "partially decoded: 91 item templates parsed",
    "MON0CHA.DAX": "partially decoded: 63 monster/character records parsed",
    "MON0SPC.DAX": "partially decoded: 9-byte effect records parsed",
    "WALLDEF1.DAX": "partially decoded: wall texture PNG export exists",
}


def signed(byte: int) -> int:
    return byte - 256 if byte >= 128 else byte


def printable(byte: int) -> bool:
    return byte == 9 or 32 <= byte < 127


def dax_decompress(raw_size: int, packed: bytes) -> tuple[bytes, list[str]]:
    warnings: list[str] = []
    if raw_size == 0:
        return packed, warnings
    out = bytearray()
    inp = 0
    while inp < len(packed) and len(out) < raw_size:
        run = signed(packed[inp])
        inp += 1
        if run >= 0:
            count = run + 1
            chunk = packed[inp : inp + count]
            out.extend(chunk)
            if len(chunk) != count:
                warnings.append("literal run truncated by packed input")
                break
            inp += count
        else:
            count = -run
            if inp >= len(packed):
                warnings.append("repeat run missing value byte")
                break
            out.extend(bytes([packed[inp]]) * count)
            inp += 1
    if len(out) < raw_size:
        warnings.append(f"decoded shorter than raw_size: {len(out)} < {raw_size}")
        out.extend(b"\x00" * (raw_size - len(out)))
    if len(out) > raw_size:
        warnings.append(f"decoded longer than raw_size: {len(out)} > {raw_size}")
        out = out[:raw_size]
    if inp < len(packed):
        trailing = packed[inp:]
        if any(trailing):
            warnings.append(f"unused non-zero packed tail: {len(trailing)} bytes")
    return bytes(out), warnings


def ascii_runs(data: bytes, min_len: int = 4, limit: int = 80) -> list[dict[str, Any]]:
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
                }
            )
            if len(rows) >= limit:
                break
        start = None
    return rows


def pascal_candidates(data: bytes, min_len: int = 4, max_len: int = 64, limit: int = 80) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for off, size in enumerate(data):
        if not (min_len <= size <= max_len):
            continue
        end = off + 1 + size
        if end > len(data):
            continue
        raw = data[off + 1 : end]
        if not all(printable(byte) for byte in raw):
            continue
        text = raw.decode("ascii", errors="replace")
        if sum(ch.isalpha() for ch in text) < 3:
            continue
        rows.append({"offset": off, "length": size, "text": text})
        if len(rows) >= limit:
            break
    return rows


def byte_histogram(data: bytes) -> dict[str, int]:
    counts = Counter(data)
    return {f"{byte:02x}": count for byte, count in counts.most_common(16)}


def divisor_hints(size: int) -> list[int]:
    candidates = [2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 18, 24, 32, 36, 48, 62, 64, 91, 128, 259, 512, 702, 758, 982, 1026, 2710, 7870, 16818, 37278]
    return [value for value in candidates if size and size % value == 0]


def file_kind(path: Path) -> str:
    suffix = path.suffix.upper()
    if suffix == ".DAX":
        return "DAX container"
    if suffix == ".EXE":
        return "DOS MZ executable"
    if suffix == ".OVR":
        return "Borland overlay candidate"
    if suffix in {".ADV", ".AD", ".BNK", ".CAT", ".XMI"}:
        return "audio/music/driver data"
    if path.name == "ITEMS":
        return "fixed-size side data"
    return "unknown binary"


def decode_dax(path: Path) -> tuple[dict[str, Any], list[dict[str, Any]]]:
    data = path.read_bytes()
    warnings: list[str] = []
    if len(data) < 2:
        return {"valid": False, "warnings": ["file too short for DAX header"], "blocks": []}, []
    toc_len = int.from_bytes(data[:2], "little")
    data_offset = toc_len + 2
    if toc_len % 9 != 0:
        warnings.append(f"toc_len not divisible by 9: {toc_len}")
    if data_offset > len(data):
        warnings.append(f"toc extends beyond file: {data_offset} > {len(data)}")

    blocks: list[dict[str, Any]] = []
    catalog_rows: list[dict[str, Any]] = []
    seen_ids: Counter[int] = Counter()
    for entry_offset in range(2, min(data_offset, len(data)), 9):
        if entry_offset + 9 > len(data):
            warnings.append(f"truncated toc entry at {entry_offset}")
            break
        block_id = data[entry_offset]
        rel = int.from_bytes(data[entry_offset + 1 : entry_offset + 5], "little")
        raw_size = int.from_bytes(data[entry_offset + 5 : entry_offset + 7], "little")
        packed_size = int.from_bytes(data[entry_offset + 7 : entry_offset + 9], "little")
        packed_start = data_offset + rel
        packed_end = packed_start + packed_size
        packed = data[packed_start:packed_end]
        block_warnings: list[str] = []
        if packed_end > len(data):
            block_warnings.append(f"packed range extends beyond file: {packed_end} > {len(data)}")
        decoded, decompress_warnings = dax_decompress(raw_size, packed)
        block_warnings.extend(decompress_warnings)
        seen_ids[block_id] += 1
        hints = divisor_hints(len(decoded))
        known_hints = KNOWN_RECORD_HINTS.get(path.name, [])
        block = {
            "id": block_id,
            "toc_entry_offset": entry_offset,
            "packed_relative_offset": rel,
            "packed_absolute_offset": packed_start,
            "raw_size": raw_size,
            "packed_size": packed_size,
            "decoded_size": len(decoded),
            "decoded_sha256": hashlib.sha256(decoded).hexdigest(),
            "packed_sha256": hashlib.sha256(packed).hexdigest(),
            "raw_size_matches_decoded_size": raw_size == len(decoded),
            "compression_ratio": round(packed_size / raw_size, 4) if raw_size else None,
            "record_size_divisors": hints,
            "known_record_hints": known_hints,
            "head_hex": decoded[:64].hex(" "),
            "tail_hex": decoded[-32:].hex(" ") if decoded else "",
            "ascii_candidates": ascii_runs(decoded),
            "pascal_candidates": pascal_candidates(decoded),
            "byte_histogram_top16": byte_histogram(decoded),
            "warnings": block_warnings,
        }
        blocks.append(block)
        catalog_rows.append(
            {
                "file": path.name,
                "id": block_id,
                "raw_size": raw_size,
                "packed_size": packed_size,
                "decoded_sha256": block["decoded_sha256"],
                "warnings": "; ".join(block_warnings),
            }
        )

    duplicate_ids = [block_id for block_id, count in sorted(seen_ids.items()) if count > 1]
    if duplicate_ids:
        warnings.append(f"duplicate block ids: {duplicate_ids}")
    return (
        {
            "valid": not any("extends beyond" in warning or "shorter than raw_size" in warning for warning in warnings),
            "file": path.name,
            "bytes": len(data),
            "sha256": hashlib.sha256(data).hexdigest(),
            "toc_len": toc_len,
            "data_offset": data_offset,
            "block_count": len(blocks),
            "semantic_status": DAX_SEMANTIC_STATUS.get(path.name, "structural decode only: semantic format not yet named"),
            "warnings": warnings,
            "blocks": blocks,
        },
        catalog_rows,
    )


def decode_non_dax(path: Path) -> dict[str, Any]:
    data = path.read_bytes()
    record_hints = []
    for hint in KNOWN_RECORD_HINTS.get(path.name, []):
        size = int(hint["record_size"])
        record_hints.append({**hint, "record_count_if_exact": len(data) // size if len(data) % size == 0 else None})
    return {
        "file": path.name,
        "kind": file_kind(path),
        "bytes": len(data),
        "sha256": hashlib.sha256(data).hexdigest(),
        "head_hex": data[:128].hex(" "),
        "ascii_candidates": ascii_runs(data, limit=120),
        "pascal_candidates": pascal_candidates(data, limit=120),
        "record_hints": record_hints,
        "semantic_status": "file-level structural evidence only",
    }


def load_existing_dax_counts(path: Path) -> dict[str, int]:
    if not path.exists():
        return {}
    rows = json.loads(path.read_text(encoding="utf-8"))
    counts: Counter[str] = Counter()
    for row in rows:
        counts[row["file"]] += 1
    return dict(counts)


def write_tsv(path: Path, rows: list[dict[str, Any]], columns: list[str]) -> None:
    with path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=columns, delimiter="\t", extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def render_summary(inventory: list[dict[str, Any]], validations: list[dict[str, Any]]) -> str:
    lines = [
        "# Original File Structural Decode",
        "",
        "This directory is generated by `scripts/decode_original_files.py`. It records reproducible structural evidence for every original Matrix Cubed file without inventing semantic labels for unknown formats.",
        "",
        "## Coverage",
        "",
        "| Kind | Files | Bytes |",
        "| --- | ---: | ---: |",
    ]
    by_kind: dict[str, list[dict[str, Any]]] = {}
    for row in inventory:
        by_kind.setdefault(row["kind"], []).append(row)
    for kind, rows in sorted(by_kind.items()):
        lines.append(f"| {kind} | {len(rows)} | {sum(row['bytes'] for row in rows)} |")

    lines.extend(["", "## DAX Validation", "", "| File | Blocks | Existing blocks | Match | Warnings |", "| --- | ---: | ---: | --- | --- |"])
    for row in validations:
        lines.append(
            f"| `{row['file']}` | {row['decoded_block_count']} | {row.get('existing_block_count', '')} | {row['matches_existing_count']} | {row['warning_count']} |"
        )
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    args = parser.parse_args()

    game_dir = args.game_dir
    out_dir = args.out_dir
    dax_dir = out_dir / "dax"
    file_dir = out_dir / "files"
    dax_dir.mkdir(parents=True, exist_ok=True)
    file_dir.mkdir(parents=True, exist_ok=True)

    existing_counts = load_existing_dax_counts(Path("generated") / "dax_blocks.json")
    inventory: list[dict[str, Any]] = []
    catalog: list[dict[str, Any]] = []
    validations: list[dict[str, Any]] = []
    undecoded: list[dict[str, Any]] = []

    for path in sorted(p for p in game_dir.iterdir() if p.is_file()):
        row = {
            "file": path.name,
            "path": str(path),
            "kind": file_kind(path),
            "bytes": path.stat().st_size,
            "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
        }
        inventory.append(row)
        if path.suffix.upper() == ".DAX":
            decoded, catalog_rows = decode_dax(path)
            (dax_dir / f"{path.name.lower()}.json").write_text(json.dumps(decoded, indent=2) + "\n", encoding="utf-8")
            catalog.extend(catalog_rows)
            warnings = decoded["warnings"] + [warning for block in decoded["blocks"] for warning in block["warnings"]]
            validations.append(
                {
                    "file": path.name,
                    "decoded_block_count": decoded["block_count"],
                    "existing_block_count": existing_counts.get(path.name),
                    "matches_existing_count": existing_counts.get(path.name) == decoded["block_count"],
                    "warning_count": len(warnings),
                    "warnings": warnings[:40],
                }
            )
            if decoded["semantic_status"].startswith("structural decode only"):
                undecoded.append(
                    {
                        "file": path.name,
                        "status": decoded["semantic_status"],
                        "block_count": decoded["block_count"],
                        "next_step": "inspect block-specific byte layout or locate runtime references before naming fields",
                    }
                )
        else:
            decoded = decode_non_dax(path)
            (file_dir / f"{path.name.lower()}.json").write_text(json.dumps(decoded, indent=2) + "\n", encoding="utf-8")
            if decoded["semantic_status"].endswith("only"):
                undecoded.append(
                    {
                        "file": path.name,
                        "status": decoded["semantic_status"],
                        "next_step": "identify format-specific parser or runtime call site before semantic decode",
                    }
                )

    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "inventory.json").write_text(json.dumps(inventory, indent=2) + "\n", encoding="utf-8")
    (out_dir / "dax_catalog.json").write_text(json.dumps(catalog, indent=2) + "\n", encoding="utf-8")
    (out_dir / "validations.json").write_text(json.dumps(validations, indent=2) + "\n", encoding="utf-8")
    (out_dir / "undecoded_files.json").write_text(json.dumps(undecoded, indent=2) + "\n", encoding="utf-8")
    (out_dir / "summary.md").write_text(render_summary(inventory, validations), encoding="utf-8")
    write_tsv(out_dir / "inventory.tsv", inventory, ["file", "kind", "bytes", "sha256", "path"])
    write_tsv(
        out_dir / "dax_catalog.tsv",
        catalog,
        ["file", "id", "raw_size", "packed_size", "decoded_sha256", "warnings"],
    )

    bad_counts = [row for row in validations if not row["matches_existing_count"]]
    warning_count = sum(row["warning_count"] for row in validations)
    print(f"Wrote original file structural decode to {out_dir}")
    print(f"Files inventoried: {len(inventory)}")
    print(f"DAX blocks cataloged: {len(catalog)}")
    print(f"DAX count mismatches vs generated/dax_blocks.json: {len(bad_counts)}")
    print(f"DAX warnings: {warning_count}")
    return 1 if bad_counts or warning_count else 0


if __name__ == "__main__":
    raise SystemExit(main())
