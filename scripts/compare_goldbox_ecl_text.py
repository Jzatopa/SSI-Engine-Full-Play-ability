#!/usr/bin/env python3
"""Extract ECL strings with Gold Box Explorer's whole-block scan and compare.

Gold Box Explorer scans decoded ECL block bytes for inline strings encoded as:

    0x80, length, packed_6bit_text...

The project disassembler already decodes operand strings with the same 6-bit
alphabet, but only along decoded instruction paths. This script keeps the GBE
scan separate so it can act as a coverage cross-check.
"""

from __future__ import annotations

import argparse
import ast
import csv
import json
import re
import string
import sys
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Iterable

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "src"))
sys.path.insert(0, str(ROOT))

from matrix_cubed.formats.dax import read_dax  # noqa: E402
from scripts.game_paths import default_game_dir  # noqa: E402


DEFAULT_GAME_DIR = default_game_dir()
DEFAULT_ECL_PATH = DEFAULT_GAME_DIR / "ECL1.DAX"
DEFAULT_LISTING_DIR = Path("generated") / "ecl1_disasm"
DEFAULT_EVENT_ATLAS = Path("generated") / "event_atlas" / "event_atlas.json"
DEFAULT_OUT_DIR = Path("generated") / "ecl_text_goldbox"

QUOTED_RE = re.compile(r"""(?P<q>'(?:\\.|[^'\\])*'|"(?:\\.|[^"\\])*")""")


@dataclass(frozen=True)
class EclTextHit:
    block_id: int
    offset: int
    encoded_length: int
    text: str


def inflate_char(value: int) -> str:
    if value <= 0x1F:
        value += 0x40
    return chr(value)


def decompress_goldbox_ecl_string(data: bytes) -> str:
    out: list[str] = []
    state = 1
    last = 0
    for byte in data:
        if state == 1:
            curr = (byte >> 2) & 0x3F
            if curr:
                out.append(inflate_char(curr))
            state = 2
        elif state == 2:
            curr = ((last << 4) | (byte >> 4)) & 0x3F
            if curr:
                out.append(inflate_char(curr))
            state = 3
        else:
            curr = ((last << 2) | (byte >> 6)) & 0x3F
            if curr:
                out.append(inflate_char(curr))
            curr = byte & 0x3F
            if curr:
                out.append(inflate_char(curr))
            state = 1
        last = byte
    return "".join(out)


def is_goldbox_readable_text(text: str) -> bool:
    invalid = set("_=[]()%<$*&\\/^>")
    stripped = text.strip()
    if len(stripped) <= 3:
        return False
    if stripped[0].isnumeric() or stripped[0] in string.punctuation:
        return False
    nospace = 0
    for ch in stripped:
        if ch.isspace():
            nospace = 0
        else:
            nospace += 1
        if nospace > 15:
            return False
        if ch in invalid:
            return False
    return True


def extract_goldbox_ecl_texts(block_id: int, data: bytes) -> list[EclTextHit]:
    hits: list[EclTextHit] = []
    for offset in range(0, max(0, len(data) - 2)):
        if data[offset] != 0x80:
            continue
        length = data[offset + 1]
        if offset + 1 + length >= len(data):
            continue
        packed = data[offset + 2 : offset + 2 + length]
        text = decompress_goldbox_ecl_string(packed).strip()
        if is_goldbox_readable_text(text):
            hits.append(EclTextHit(block_id, offset, length, text))
    return hits


def extract_all_goldbox_ecl_texts(ecl_path: Path) -> list[EclTextHit]:
    hits: list[EclTextHit] = []
    for block in read_dax(ecl_path):
        hits.extend(extract_goldbox_ecl_texts(block.block_id, block.data))
    return hits


def strings_from_quoted_text(raw: str) -> set[str]:
    values: set[str] = set()
    for match in QUOTED_RE.finditer(raw):
        try:
            value = ast.literal_eval(match.group("q"))
        except Exception:
            continue
        if isinstance(value, str) and value.strip():
            values.add(value.strip())
    return values


def collect_current_listing_strings(listing_dir: Path) -> set[str]:
    values: set[str] = set()
    if not listing_dir.exists():
        return values
    for path in sorted(listing_dir.glob("*.ecl.txt")):
        values.update(strings_from_quoted_text(path.read_text(encoding="utf-8")))
    return values


def iter_json_strings(value: object) -> Iterable[str]:
    if isinstance(value, dict):
        for item in value.values():
            yield from iter_json_strings(item)
    elif isinstance(value, list):
        for item in value:
            yield from iter_json_strings(item)
    elif isinstance(value, str):
        yield value


def collect_current_event_strings(event_atlas_path: Path) -> set[str]:
    values: set[str] = set()
    if not event_atlas_path.exists():
        return values
    data = json.loads(event_atlas_path.read_text(encoding="utf-8"))
    for raw in iter_json_strings(data):
        values.update(strings_from_quoted_text(raw))
        if raw.strip() and len(raw.strip()) > 3:
            values.add(raw.strip())
    return values


def normalize(text: str) -> str:
    return " ".join(text.split()).upper()


def compare_texts(
    goldbox_hits: list[EclTextHit],
    listing_strings: set[str],
    event_strings: set[str],
) -> dict[str, object]:
    goldbox_by_norm: dict[str, list[EclTextHit]] = {}
    for hit in goldbox_hits:
        goldbox_by_norm.setdefault(normalize(hit.text), []).append(hit)

    current_listing_norm = {normalize(value): value for value in listing_strings}
    current_event_norm = {normalize(value): value for value in event_strings}
    current_norm = set(current_listing_norm) | set(current_event_norm)

    exact_overlap = sorted(set(goldbox_by_norm) & current_norm)
    missing_norms = sorted(set(goldbox_by_norm) - current_norm)
    listing_only = sorted(set(goldbox_by_norm) & set(current_listing_norm))
    event_only = sorted(set(goldbox_by_norm) & set(current_event_norm))
    substring_overlap = sorted(
        norm_text
        for norm_text in goldbox_by_norm
        if norm_text in current_norm or any(norm_text in current or current in norm_text for current in current_norm)
    )
    substring_missing_norms = sorted(set(goldbox_by_norm) - set(substring_overlap))

    missing_rows = []
    for norm_text in missing_norms:
        for hit in goldbox_by_norm[norm_text]:
            missing_rows.append(asdict(hit))

    substring_missing_rows = []
    for norm_text in substring_missing_norms:
        for hit in goldbox_by_norm[norm_text]:
            substring_missing_rows.append(asdict(hit))

    return {
        "goldbox_hit_count": len(goldbox_hits),
        "goldbox_unique_text_count": len(goldbox_by_norm),
        "current_listing_unique_text_count": len(current_listing_norm),
        "current_event_unique_text_count": len(current_event_norm),
        "goldbox_exact_current_overlap_count": len(exact_overlap),
        "goldbox_listing_overlap_count": len(listing_only),
        "goldbox_event_overlap_count": len(event_only),
        "goldbox_missing_from_current_count": len(missing_norms),
        "goldbox_missing_hits_count": len(missing_rows),
        "goldbox_substring_current_overlap_count": len(substring_overlap),
        "goldbox_substring_missing_from_current_count": len(substring_missing_norms),
        "goldbox_substring_missing_hits_count": len(substring_missing_rows),
        "goldbox_missing_hits": missing_rows,
        "goldbox_substring_missing_hits": substring_missing_rows,
    }


def write_outputs(hits: list[EclTextHit], comparison: dict[str, object], out_dir: Path) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "ecl_text_compare.json").write_text(
        json.dumps(
            {
                "source": "Gold Box Explorer DaxEclFile.cs whole-block scan port",
                "comparison": comparison,
                "goldbox_hits": [asdict(hit) for hit in hits],
            },
            indent=2,
        ),
        encoding="utf-8",
    )

    with (out_dir / "goldbox_ecl_texts.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["block_id", "offset", "encoded_length", "text"], delimiter="\t")
        writer.writeheader()
        for hit in hits:
            writer.writerow(asdict(hit))

    missing = comparison["goldbox_missing_hits"]
    substring_missing = comparison["goldbox_substring_missing_hits"]
    with (out_dir / "goldbox_ecl_texts_missing_from_current.tsv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["block_id", "offset", "encoded_length", "text"], delimiter="\t")
        writer.writeheader()
        for row in missing:  # type: ignore[assignment]
            writer.writerow(row)

    with (out_dir / "goldbox_ecl_texts_still_missing_after_substring.tsv").open(
        "w", encoding="utf-8", newline=""
    ) as f:
        writer = csv.DictWriter(f, fieldnames=["block_id", "offset", "encoded_length", "text"], delimiter="\t")
        writer.writeheader()
        for row in substring_missing:  # type: ignore[assignment]
            writer.writerow(row)

    lines = [
        "# Gold Box Explorer ECL Text Comparison",
        "",
        "This report ports Gold Box Explorer's whole-block ECL text scan and compares it",
        "with the current generated ECL listings and event atlas text.",
        "",
        "## Summary",
        "",
        f"- Gold Box text hits: {comparison['goldbox_hit_count']}",
        f"- Gold Box unique texts: {comparison['goldbox_unique_text_count']}",
        f"- Current listing unique texts: {comparison['current_listing_unique_text_count']}",
        f"- Current event-atlas unique texts: {comparison['current_event_unique_text_count']}",
        f"- Gold Box texts already present in current outputs: {comparison['goldbox_exact_current_overlap_count']}",
        f"- Gold Box texts missing from current outputs: {comparison['goldbox_missing_from_current_count']}",
        f"- Gold Box texts present by exact or substring match: {comparison['goldbox_substring_current_overlap_count']}",
        f"- Gold Box texts still missing after substring match: {comparison['goldbox_substring_missing_from_current_count']}",
        "",
        "## Exact-Match Missing Gold Box Text Hits",
        "",
    ]
    if missing:
        lines.append("| ECL block | Offset | Packed bytes | Text |")
        lines.append("|---:|---:|---:|---|")
        for row in missing[:100]:  # type: ignore[index]
            text = str(row["text"]).replace("|", "\\|")
            lines.append(f"| {row['block_id']} | 0x{row['offset']:04X} | {row['encoded_length']} | {text} |")
        if len(missing) > 100:
            lines.append("")
            lines.append(f"Only the first 100 of {len(missing)} missing hits are shown here.")
    else:
        lines.append("No Gold Box whole-block text hits are missing from current outputs.")
    lines.extend(
        [
            "",
            "## Still Missing After Substring Match",
            "",
        ]
    )
    if substring_missing:
        lines.append("| ECL block | Offset | Packed bytes | Text |")
        lines.append("|---:|---:|---:|---|")
        for row in substring_missing[:100]:  # type: ignore[index]
            text = str(row["text"]).replace("|", "\\|")
            lines.append(f"| {row['block_id']} | 0x{row['offset']:04X} | {row['encoded_length']} | {text} |")
        if len(substring_missing) > 100:
            lines.append("")
            lines.append(f"Only the first 100 of {len(substring_missing)} substring-missing hits are shown here.")
    else:
        lines.append("Every Gold Box whole-block text hit appears in current outputs by exact or substring match.")
    lines.append("")
    (out_dir / "ecl_text_compare.md").write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--ecl", type=Path, default=DEFAULT_ECL_PATH)
    parser.add_argument("--listing-dir", type=Path, default=DEFAULT_LISTING_DIR)
    parser.add_argument("--event-atlas", type=Path, default=DEFAULT_EVENT_ATLAS)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    args = parser.parse_args()

    hits = extract_all_goldbox_ecl_texts(args.ecl)
    listing_strings = collect_current_listing_strings(args.listing_dir)
    event_strings = collect_current_event_strings(args.event_atlas)
    comparison = compare_texts(hits, listing_strings, event_strings)
    write_outputs(hits, comparison, args.out_dir)
    print(
        "Gold Box ECL text scan: "
        f"{comparison['goldbox_hit_count']} hits, "
        f"{comparison['goldbox_unique_text_count']} unique, "
        f"{comparison['goldbox_missing_from_current_count']} unique missing from current outputs"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
