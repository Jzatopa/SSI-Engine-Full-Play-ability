#!/usr/bin/env python3
"""Summarize symbolic/raw memory references in generated event listings."""

from __future__ import annotations

import argparse
import re
from collections import Counter, defaultdict
from pathlib import Path


REF_RE = re.compile(
    r"\b(?:area[12]\.(?:word_[0-9A-F]{3}|[A-Za-z_][A-Za-z0-9_]*)|"
    r"scratch\.word_[0-9A-F]{4}|abs_[0-9A-F]{4})\b"
)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("input_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    parser.add_argument("--limit", type=int, default=80)
    args = parser.parse_args()

    counts: Counter[str] = Counter()
    examples: dict[str, str] = {}
    by_file: defaultdict[str, Counter[str]] = defaultdict(Counter)

    for path in sorted(args.input_dir.glob("*.structured.md")):
        text = path.read_text(encoding="utf-8")
        for match in REF_RE.finditer(text):
            ref = match.group(0)
            counts[ref] += 1
            by_file[ref][path.name] += 1
            if ref not in examples:
                line_start = text.rfind("\n", 0, match.start()) + 1
                line_end = text.find("\n", match.end())
                if line_end == -1:
                    line_end = len(text)
                examples[ref] = text[line_start:line_end].strip()

    args.out_dir.mkdir(parents=True, exist_ok=True)

    tsv_lines = ["ref\tcount\ttop_file\texample"]
    for ref, count in counts.most_common():
        top_file, top_file_count = by_file[ref].most_common(1)[0]
        example = examples[ref].replace("\t", " ")
        tsv_lines.append(f"{ref}\t{count}\t{top_file}:{top_file_count}\t{example}")
    (args.out_dir / "memory_refs.tsv").write_text("\n".join(tsv_lines) + "\n", encoding="utf-8")

    markdown = [
        "# Memory Reference Summary",
        "",
        "Generated from structured event pseudocode.",
        "",
        f"Total unique references: {len(counts)}",
        "",
        f"## Top {args.limit}",
        "",
    ]
    for ref, count in counts.most_common(args.limit):
        top_file, top_file_count = by_file[ref].most_common(1)[0]
        markdown.append(f"- `{ref}`: {count} refs; top file `{top_file}` ({top_file_count}); example: `{examples[ref]}`")
    (args.out_dir / "memory_refs.md").write_text("\n".join(markdown) + "\n", encoding="utf-8")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
