#!/usr/bin/env python3
"""Skeptic verification pass: re-check qwen Ghidra↔COAB matches against actual COAB source.

ADVISORY OUTPUT ONLY. This pass takes non-none candidates from the initial matching run,
loads the actual COAB C# source for the proposed match, and asks qwen (skeptically):
does this specific Matrix function genuinely correspond to this COAB function?
Results: yes/partial/no verdicts with confidence and discriminating detail.

Spec: references/ssi-engine/docs/qwen-ghidra-matching-results-2026-07-08.md
(skeptic pass section)
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import sys
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any

try:
    import requests
except ImportError:
    print("ERROR: requests library not found. Install with: pip install requests", file=sys.stderr)
    sys.exit(1)


ROOT = Path(__file__).resolve().parents[1]
COAB_ENGINE_DIR = Path.home() / ".local/opt/coab/engine"
DECOMPILED_DIR = ROOT / "generated/ghidra/deep_game_ovr_payload/decompiled"

QWEN_ENDPOINT = "http://192.168.2.2:11434/api/generate"
QWEN_MODEL = "qwen3-coder:30b"
QWEN_TIMEOUT = 120  # seconds per call


@dataclass
class SkepticResult:
    """A single skeptic verification result."""
    target_entry: str
    coab_name: str
    coab_overlay: str
    skeptic_json: dict[str, Any] | None = None
    raw_text: str | None = None
    latency_ms: int = 0
    http_status: int = 0
    http_error: str | None = None
    extraction_error: str | None = None


def load_matches_jsonl(path: Path) -> dict[str, Any]:
    """Load matches.jsonl and index by target_entry for fast lookup."""
    matches = {}

    if not path.exists():
        return matches

    try:
        for line in path.read_text().strip().split('\n'):
            if not line.strip():
                continue
            try:
                record = json.loads(line)
                target_entry = record.get("target_entry")
                if target_entry:
                    matches[target_entry] = record
            except json.JSONDecodeError:
                pass
    except Exception as e:
        print(f"WARNING: Failed to load matches.jsonl: {e}", file=sys.stderr)

    return matches


def get_non_none_candidates(matches: dict[str, Any]) -> list[tuple[str, dict[str, Any]]]:
    """Extract non-none candidates from matches, sorted by entry."""
    non_none = []

    for entry, record in matches.items():
        qwen_json = record.get("qwen_json", {})
        verdict = qwen_json.get("verdict")
        candidates = qwen_json.get("candidates", [])

        # Include if verdict != "none" or candidates is non-empty
        if verdict != "none" or candidates:
            non_none.append((entry, qwen_json))

    return sorted(non_none, key=lambda x: x[0])


def file_for_entry(entry: str) -> Path | None:
    """Map a colon-form entry (e.g. '0000:38e0') to its decompiled/<seg>_<off>_*.c file."""
    if ":" not in entry:
        return None
    seg, off = entry.split(":", 1)
    matches = sorted(DECOMPILED_DIR.glob(f"{seg}_{off}_*.c"))
    return matches[0] if matches else None


def load_decompiled_c(entry: str) -> str | None:
    """Load the decompiled C function for a given entry."""
    path = file_for_entry(entry)
    if path and path.exists():
        return path.read_text(errors="replace")
    return None


def extract_coab_function_body(overlay: str, func_name: str) -> str | None:
    """Extract the body of a function from a COAB ovr*.cs file.

    Uses brace-depth scanning to find the matching close brace for the function.
    Returns the function body (from signature to closing brace), or None if not found.
    """
    cs_path = COAB_ENGINE_DIR / f"{overlay}.cs"

    if not cs_path.exists():
        return None

    text = cs_path.read_text(errors="replace")
    lines = text.split('\n')

    # Search for the function signature: internal static <type> <func_name>(
    pattern = rf'^\s*internal\s+static\s+\w+\s+{re.escape(func_name)}\s*\('

    start_line_idx = None
    for idx, line in enumerate(lines):
        if re.match(pattern, line):
            start_line_idx = idx
            break

    if start_line_idx is None:
        return None

    # Now scan forward from start_line_idx to find the matching closing brace
    # using a brace-depth counter
    brace_depth = 0
    found_opening_brace = False
    end_line_idx = None

    for idx in range(start_line_idx, len(lines)):
        line = lines[idx]

        for char in line:
            if char == '{':
                brace_depth += 1
                found_opening_brace = True
            elif char == '}':
                brace_depth -= 1
                if found_opening_brace and brace_depth == 0:
                    end_line_idx = idx
                    break

        if end_line_idx is not None:
            break

    if end_line_idx is None:
        return None

    # Extract lines from start to end, inclusive
    body_lines = lines[start_line_idx:end_line_idx + 1]
    return '\n'.join(body_lines)


def call_qwen_skeptic(
    target_entry: str,
    decompiled_c: str,
    coab_name: str,
    coab_source: str
) -> SkepticResult:
    """Call qwen with the skeptic prompt."""

    start_time = time.time()

    # Build prompt per skeptic spec
    user_prompt = f"""TARGET FUNCTION (Matrix Cubed GAME.OVR, entry {target_entry}):
{decompiled_c}

PROPOSED COAB MATCH (function {coab_name}):
{coab_source}

Question: Does the Matrix function genuinely correspond to this specific COAB function?
Be skeptical: default to "no" when resemblance is generic (shared "does a comparison"/"has a loop" is NOT correspondence).
"yes" only when specific structure/constants/behavior align.

Return strict JSON only:
{{
  "target_entry": "<entry>",
  "coab_name": "<name>",
  "skeptic_verdict": "yes|partial|no",
  "confidence": "high|medium|low",
  "discriminating_detail": "<one sentence naming the specific feature that confirms or refutes>"
}}
"""

    system_prompt = """You are a skeptical reverse-engineering verifier. Your job is to examine two function
implementations—one from Buck Rogers: Matrix Cubed and one from Curse of the Azure Bonds—and determine
whether they genuinely implement the same functionality or are false-positive matches.

CRITICAL RULES:
- "no" is the default when the resemblance is superficial or generic.
- "yes" only when two or more specific, independent structural features align
  (e.g., a distinctive constant AND a matching loop structure AND consistent control flow).
- "partial" only when the functions share significant structure but differ in important details
  (e.g., same core algorithm but different inputs/outputs).
- Shared vocabulary, generic loops, or "both do comparison" is NOT evidence of correspondence.
- Being skeptical is the point — this pass exists to kill false positives from the first run.

CONFIDENCE CALIBRATION:
- "high": you can name TWO OR MORE concrete structural features that align.
- "medium": one strong feature and general role consistency.
- "low": plausible but weak resemblance.

DISCRIMINATING DETAIL:
- Name one specific feature (a constant, loop structure, call pattern, control flow,
  memory access pattern) that confirms or refutes the match. This must be concrete
  and observable in the code.

Output STRICT JSON only, matching the schema. No prose outside the JSON.
"""

    payload = {
        "model": QWEN_MODEL,
        "system": system_prompt,
        "prompt": user_prompt,
        "stream": False,
        "format": "json",
        "options": {
            "temperature": 0.15,
            "top_p": 0.9,
            "num_ctx": 32768,
            "num_predict": 700,
            "seed": 42
        }
    }

    result = SkepticResult(
        target_entry=target_entry,
        coab_name=coab_name,
        coab_overlay=""
    )

    try:
        resp = requests.post(
            QWEN_ENDPOINT,
            json=payload,
            timeout=QWEN_TIMEOUT
        )
        elapsed_ms = int((time.time() - start_time) * 1000)

        result.latency_ms = elapsed_ms
        result.http_status = resp.status_code

        if resp.status_code != 200:
            result.http_error = f"HTTP {resp.status_code}: {resp.text[:200]}"
            return result

        # Try to parse JSON
        try:
            data = resp.json()
            if "response" in data:
                response_text = data["response"].strip()
                result.raw_text = response_text

                try:
                    result.skeptic_json = json.loads(response_text)
                except json.JSONDecodeError:
                    result.http_error = "Failed to parse qwen response as JSON"
            else:
                result.skeptic_json = data
                result.raw_text = resp.text

            return result

        except Exception as e:
            result.http_error = f"JSON parse error: {e}"
            result.raw_text = resp.text
            return result

    except requests.Timeout:
        elapsed_ms = int((time.time() - start_time) * 1000)
        result.latency_ms = elapsed_ms
        result.http_status = 504
        result.http_error = f"Timeout after {QWEN_TIMEOUT}s"
        return result
    except Exception as e:
        elapsed_ms = int((time.time() - start_time) * 1000)
        result.latency_ms = elapsed_ms
        result.http_status = 0
        result.http_error = str(e)
        return result


def get_existing_entries(skeptic_jsonl: Path) -> set[str]:
    """Load already-processed entries from skeptic.jsonl."""
    entries: set[str] = set()

    if not skeptic_jsonl.exists():
        return entries

    try:
        for line in skeptic_jsonl.read_text().strip().split('\n'):
            if not line.strip():
                continue
            try:
                record = json.loads(line)
                if "target_entry" in record:
                    entries.add(record["target_entry"])
            except json.JSONDecodeError:
                pass
    except Exception as e:
        print(f"WARNING: Failed to load existing skeptic results: {e}", file=sys.stderr)

    return entries


def run_skeptic_pass(
    matches: dict[str, Any],
    date: str,
    limit: int | None = None,
    pilot: bool = False
) -> tuple[list[SkepticResult], int]:
    """Main skeptic verification loop.

    Returns (results, total_pending).
    """

    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_skeptic" / date
    out_dir.mkdir(parents=True, exist_ok=True)

    skeptic_jsonl = out_dir / "skeptic.jsonl"

    # Get non-none candidates
    non_none = get_non_none_candidates(matches)

    # Get already-processed entries
    existing = get_existing_entries(skeptic_jsonl)

    # Filter to pending
    pending = [
        (entry, qwen_json) for entry, qwen_json in non_none
        if entry not in existing
    ]

    if limit is not None:
        pending = pending[:limit]

    total_pending = len(non_none) - len(existing)

    results: list[SkepticResult] = []

    print(f"Starting skeptic pass: {len(pending)} pending, {len(existing)} already done")
    print(f"Output: {skeptic_jsonl}")

    if pilot:
        print("PILOT MODE: first 6 only")

    # Append to skeptic.jsonl
    append_fh = skeptic_jsonl.open("a")

    try:
        for idx, (entry, qwen_json) in enumerate(pending, 1):
            candidates = qwen_json.get("candidates", [])

            if not candidates:
                print(f"  [{idx}/{len(pending)}] {entry}: no candidates, skipping")
                continue

            # Take top candidate
            top = candidates[0]
            coab_name = top.get("coab_name")
            coab_overlay = top.get("coab_overlay")

            if not coab_name or not coab_overlay:
                print(f"  [{idx}/{len(pending)}] {entry}: missing name/overlay, skipping")
                continue

            # Load decompiled C
            decompiled_c = load_decompiled_c(entry)
            if not decompiled_c:
                print(f"  [{idx}/{len(pending)}] {entry}: decompiled C not found, skipping")
                continue

            # Load COAB source
            coab_source = extract_coab_function_body(coab_overlay, coab_name)
            if not coab_source:
                result = SkepticResult(
                    target_entry=entry,
                    coab_name=coab_name,
                    coab_overlay=coab_overlay,
                    extraction_error=f"Could not extract function {coab_name} from {coab_overlay}.cs"
                )
                results.append(result)

                # Write to JSONL
                record = {
                    "target_entry": result.target_entry,
                    "coab_name": result.coab_name,
                    "coab_overlay": result.coab_overlay,
                    "skeptic_json": result.skeptic_json,
                    "raw_text": result.raw_text,
                    "latency_ms": result.latency_ms,
                    "http_status": result.http_status,
                    "http_error": result.http_error,
                    "extraction_error": result.extraction_error,
                    "skeptic_verdict": "unresolvable-name"
                }
                append_fh.write(json.dumps(record) + "\n")
                append_fh.flush()

                print(f"  [{idx}/{len(pending)}] {entry}: unresolvable-name ({coab_name})")
                continue

            # Call qwen
            result = call_qwen_skeptic(
                target_entry=entry,
                decompiled_c=decompiled_c,
                coab_name=coab_name,
                coab_source=coab_source
            )
            result.coab_overlay = coab_overlay
            results.append(result)

            # Write to JSONL
            record = {
                "target_entry": result.target_entry,
                "coab_name": result.coab_name,
                "coab_overlay": result.coab_overlay,
                "skeptic_json": result.skeptic_json,
                "raw_text": result.raw_text,
                "latency_ms": result.latency_ms,
                "http_status": result.http_status,
                "http_error": result.http_error,
                "extraction_error": result.extraction_error
            }

            if result.skeptic_json:
                record["skeptic_verdict"] = result.skeptic_json.get("skeptic_verdict")

            append_fh.write(json.dumps(record) + "\n")
            append_fh.flush()

            # Progress
            if result.http_error:
                status = f"ERR({result.http_status}): {result.http_error[:50]}"
            elif result.extraction_error:
                status = "UNRESOLVABLE"
            else:
                verdict = result.skeptic_json.get("skeptic_verdict") if result.skeptic_json else "?"
                confidence = result.skeptic_json.get("confidence") if result.skeptic_json else "?"
                status = f"OK {verdict}/{confidence} {result.latency_ms}ms"

            print(f"  [{idx}/{len(pending)}] {entry} {coab_name}: {status}", flush=True)

    finally:
        append_fh.close()

    return results, total_pending


def write_skeptic_rollup(date: str, results: list[SkepticResult]) -> None:
    """Write skeptic_rollup.tsv with summary per candidate."""

    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_skeptic" / date
    rollup_path = out_dir / "skeptic_rollup.tsv"

    with rollup_path.open("w", newline="") as fh:
        writer = csv.DictWriter(
            fh,
            fieldnames=["entry", "coab_name", "skeptic_verdict", "confidence", "discriminating_detail"],
            delimiter="\t"
        )
        writer.writeheader()

        for result in results:
            if result.skeptic_json:
                skeptic_verdict = result.skeptic_json.get("skeptic_verdict", "?")
                confidence = result.skeptic_json.get("confidence", "?")
                discriminating_detail = result.skeptic_json.get("discriminating_detail", "?")
            else:
                skeptic_verdict = "error" if result.http_error or result.extraction_error else "?"
                confidence = ""
                discriminating_detail = result.http_error or result.extraction_error or ""

            writer.writerow({
                "entry": result.target_entry,
                "coab_name": result.coab_name,
                "skeptic_verdict": skeptic_verdict,
                "confidence": confidence,
                "discriminating_detail": discriminating_detail
            })

    print(f"Rollup: {rollup_path}")


def write_manifest(
    date: str,
    results: list[SkepticResult],
    total_pending: int
) -> None:
    """Write manifest.json with metadata and counts."""

    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_skeptic" / date
    manifest_path = out_dir / "manifest.json"

    # Count verdicts
    verdicts: dict[str, int] = {}
    unresolvable_names = 0
    http_errors = 0

    for result in results:
        if result.extraction_error:
            unresolvable_names += 1
        elif result.http_error:
            http_errors += 1
        elif result.skeptic_json:
            verdict = result.skeptic_json.get("skeptic_verdict", "unknown")
            verdicts[verdict] = verdicts.get(verdict, 0) + 1

    manifest = {
        "model": QWEN_MODEL,
        "endpoint": QWEN_ENDPOINT,
        "settings": {
            "temperature": 0.15,
            "top_p": 0.9,
            "num_ctx": 32768,
            "num_predict": 700,
            "seed": 42,
            "format": "json",
            "stream": False
        },
        "input_source": "generated/qwen_advisory/ghidra_coab_matches/2026-07-08-full/matches.jsonl",
        "total_non_none_candidates": 97,
        "processed": len(results),
        "remaining": total_pending - len(results),
        "unresolvable_names": unresolvable_names,
        "http_errors": http_errors,
        "skeptic_verdicts": verdicts,
        "timeout": QWEN_TIMEOUT
    }

    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n")
    print(f"Manifest: {manifest_path}")


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Skeptic verification pass: re-check qwen matches against actual COAB source."
    )
    parser.add_argument(
        "--date",
        default="2026-07-08",
        help="Date string for output directory (default: 2026-07-08)"
    )
    parser.add_argument(
        "--limit",
        type=int,
        help="Process only first N pending candidates (for piloting)"
    )
    parser.add_argument(
        "--pilot",
        action="store_true",
        help="Run pilot mode (same as --limit 6)"
    )

    args = parser.parse_args()

    if args.pilot:
        args.limit = 6

    # Load matches
    print("Loading matches.jsonl...")
    matches_path = ROOT / "generated/qwen_advisory/ghidra_coab_matches/2026-07-08-full/matches.jsonl"
    matches = load_matches_jsonl(matches_path)
    print(f"  Loaded {len(matches)} total entries")

    non_none = get_non_none_candidates(matches)
    print(f"  Found {len(non_none)} non-none candidates")

    print("Starting skeptic pass...")
    results, total_pending = run_skeptic_pass(
        matches=matches,
        date=args.date,
        limit=args.limit,
        pilot=args.pilot
    )

    print(f"\nSkeptic pass complete: {len(results)} processed")

    # Write rollup
    write_skeptic_rollup(args.date, results)

    # Write manifest
    write_manifest(args.date, results, total_pending)

    return 0


if __name__ == "__main__":
    sys.exit(main())
