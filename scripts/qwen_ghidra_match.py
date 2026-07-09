#!/usr/bin/env python3
"""Batch harness: use local qwen-coder LLM to propose COAB function matches.

ADVISORY OUTPUT ONLY. These are candidate matches proposed by an LLM, not verified
facts. All high/medium/low-confidence matches must pass local verification against
the actual COAB C# and the Matrix Cubed binary before adoption.

Spec: references/ssi-engine/docs/qwen-ghidra-matching-spec.md
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import sys
import time
from dataclasses import asdict, dataclass
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
STRINGS_TSV = ROOT / "generated/ghidra/deep_game_ovr_payload/strings.tsv"

QWEN_ENDPOINT = "http://192.168.2.2:11434/api/generate"
QWEN_MODEL = "qwen3-coder:30b"
QWEN_TIMEOUT = 120  # seconds per call


@dataclass(frozen=True)
class CoabFunction:
    """A COAB function catalog entry."""
    name: str
    overlay: str
    coab_addr: str
    role_hint: str


@dataclass
class MatchResult:
    """A single function match attempt."""
    target_entry: str
    qwen_json: dict[str, Any] | None = None
    raw_text: str | None = None
    latency_ms: int = 0
    http_status: int = 0
    http_error: str | None = None


def extract_coab_catalog() -> list[CoabFunction]:
    """Extract function signatures from all ovr*.cs files.

    Scans for lines matching:
      internal static <type> <name>(...) [// sub_XXXXX]

    Returns list of CoabFunction records.
    """
    catalog: list[CoabFunction] = []

    if not COAB_ENGINE_DIR.exists():
        print(f"ERROR: COAB engine dir not found: {COAB_ENGINE_DIR}", file=sys.stderr)
        sys.exit(1)

    ovr_files = sorted(COAB_ENGINE_DIR.glob("ovr*.cs"))
    if not ovr_files:
        print(f"ERROR: no ovr*.cs files found in {COAB_ENGINE_DIR}", file=sys.stderr)
        sys.exit(1)

    for ovr_file in ovr_files:
        overlay = ovr_file.stem  # e.g. "ovr006"
        text = ovr_file.read_text(errors="replace")

        # Pattern: internal static <type> <name>(
        # Capture name and optional // sub_XXXXX comment
        pattern = r'^\s*internal\s+static\s+\w+\s+(\w+)\s*\([^)]*\)(?:\s*//\s*(sub_[0-9A-Fa-f]+))?'

        for line_idx, line in enumerate(text.split('\n'), 1):
            match = re.match(pattern, line)
            if match:
                func_name = match.group(1)
                coab_addr = match.group(2) or "-"
                role_hint = ""  # Leave blank per spec

                catalog.append(CoabFunction(
                    name=func_name,
                    overlay=overlay,
                    coab_addr=coab_addr,
                    role_hint=role_hint
                ))

    return catalog


def load_strings_dict() -> dict[str, str]:
    """Load strings.tsv into a dict: address -> text."""
    strings: dict[str, str] = {}

    if not STRINGS_TSV.exists():
        return strings

    try:
        with STRINGS_TSV.open(newline="", errors="replace") as fh:
            reader = csv.DictReader(fh, delimiter="\t")
            for row in reader:
                if row.get("address") and row.get("text"):
                    strings[row["address"]] = row["text"]
    except Exception as e:
        print(f"WARNING: Failed to load strings.tsv: {e}", file=sys.stderr)

    return strings


def extract_referenced_strings(decompiled_c: str, strings_dict: dict[str, str]) -> str:
    """Extract strings referenced in the decompiled C function.

    Looks for hex addresses like 0x1234, matches against strings dict.
    Returns comma-separated list or "none".
    """
    # Find hex-like patterns
    hex_pattern = r'\b0x([0-9A-Fa-f]+)\b'
    found_strings: list[str] = []

    for match in re.finditer(hex_pattern, decompiled_c):
        hex_val = match.group(1)
        addr_variants = [
            f"0000:{hex_val}",
            f"1000:{hex_val}",
            f"2000:{hex_val}",
            f"3000:{hex_val}",
        ]

        for addr in addr_variants:
            if addr in strings_dict:
                found_strings.append(f"{strings_dict[addr]} ({addr})")
                break

    if found_strings:
        return ", ".join(found_strings[:5])  # Limit to first 5
    return "none"


def call_qwen(
    catalog_text: str,
    target_entry: str,
    decompiled_c: str,
    referenced_strings: str
) -> MatchResult:
    """Call qwen endpoint with the full prompt per spec."""

    start_time = time.time()

    # Build prompt per spec
    user_prompt = f"""COAB CATALOG (name | overlay | coab_addr | role-hint):
{catalog_text}

TARGET FUNCTION (Matrix Cubed GAME.OVR, entry {target_entry}):
{decompiled_c}
REFERENCED STRINGS: {referenced_strings}

Return JSON:
{{
  "target_entry": "<entry>",
  "candidates": [
    {{"coab_name": "<name from catalog, exact>", "coab_overlay": "<ovrNNN>",
     "confidence": "high|medium|low", "evidence": "<one sentence: the specific
     structural feature that supports this — constant, loop shape, call pattern>"}}
  ],
  "verdict": "match|weak|none"
}}
- 0 candidates with verdict "none" is valid and encouraged when appropriate.
- At most 3 candidates, best first. confidence must reflect structural evidence,
  not vocabulary coincidence.
"""

    system_prompt = """You are a reverse-engineering assistant matching decompiled functions between
two games that share the SSI Gold Box engine lineage. The TARGET function is
from Buck Rogers: Matrix Cubed (GAME.OVR). The CATALOG lists named functions
from Curse of the Azure Bonds (COAB), a different game on a related engine.

CRITICAL RULES:
- Memory addresses and sub_ numbers do NOT correspond between the two games.
  Never match on address equality. Match only on behavior: control-flow shape,
  distinctive numeric constants, memory-word access patterns, string use, and
  call structure.
- Many Matrix functions have NO COAB counterpart. "none" is correct and
  EXPECTED for a large fraction of functions. A wrong confident match is worse
  than "none". Do NOT force a match.

CONFIDENCE CALIBRATION (follow strictly):
- "high": ONLY when TWO OR MORE independent, specific structural features agree
  (e.g. a distinctive constant AND a matching loop/branch shape AND a
  consistent role). Rare. If you cannot name two concrete features, it is not
  high.
- "medium": one strong specific feature and a consistent role.
- "low": a plausible but weak resemblance, or role guess from vocabulary.
- Superficial similarity, generic control flow, or "this looks like a common
  dispatcher/comparator" is "low" at most — usually "none".

ANTI-ANCHORING:
- Do NOT repeatedly fall back to the same catalog entry (e.g. a comparator or
  VM-dispatch name) when unsure. If distinguishing evidence is absent, the
  answer is "none", never a generic familiar name used as a default.

DEGENERATE FUNCTIONS (return verdict "none", empty candidates):
- Fewer than ~8 meaningful statements, OR a single tail-call to another FUN_
  with no other logic (a thunk/wrapper), OR a body that only shuffles
  registers/undefined vars (unaff_, extraout_, in_AX artifacts) with no
  distinctive constants, loops, or string use. These carry insufficient signal
  to identify; do not guess. If several such stubs differ only by one constant,
  they are a thunk family, not a catalog match.
- If the decompilation carries corruption warnings (bad instruction data,
  overlapping instructions, halt_baddata, stack frame not set up normally), the
  body is unreliable — return "none" unless a string or distinctive constant
  still gives clear signal.

DISPATCH DISAMBIGUATION (avoid anchoring on the ECL VM):
- The ECL virtual machine (RunEclVm and similar) dispatches on NUMERIC opcode
  bytes read from a script stream. A function that dispatches on ASCII LETTER
  keys (e.g. 'M','V','A','Q','C','T') is a menu / keyboard input handler, NOT
  the ECL VM — prefer a menu/input/command catalog entry, or "none", over
  RunEclVm. Do not map every large switch/dispatch loop to the VM; the catalog
  has many distinct dispatchers.

- Output STRICT JSON only, matching the schema. No prose outside the JSON.
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

    try:
        resp = requests.post(
            QWEN_ENDPOINT,
            json=payload,
            timeout=QWEN_TIMEOUT
        )
        elapsed_ms = int((time.time() - start_time) * 1000)

        result = MatchResult(
            target_entry=target_entry,
            http_status=resp.status_code,
            latency_ms=elapsed_ms
        )

        if resp.status_code != 200:
            result.http_error = f"HTTP {resp.status_code}: {resp.text[:200]}"
            return result

        # Try to parse JSON
        try:
            data = resp.json()
            if "response" in data:
                # Ollama wraps the model response in "response" field
                response_text = data["response"].strip()
                result.raw_text = response_text

                # Try to parse the response as JSON
                try:
                    result.qwen_json = json.loads(response_text)
                except json.JSONDecodeError:
                    result.http_error = "Failed to parse qwen response as JSON"
            else:
                result.qwen_json = data
                result.raw_text = resp.text

            return result

        except Exception as e:
            result.http_error = f"JSON parse error: {e}"
            result.raw_text = resp.text
            return result

    except requests.Timeout:
        elapsed_ms = int((time.time() - start_time) * 1000)
        return MatchResult(
            target_entry=target_entry,
            http_status=504,
            http_error=f"Timeout after {QWEN_TIMEOUT}s",
            latency_ms=elapsed_ms
        )
    except Exception as e:
        elapsed_ms = int((time.time() - start_time) * 1000)
        return MatchResult(
            target_entry=target_entry,
            http_status=0,
            http_error=str(e),
            latency_ms=elapsed_ms
        )


def entry_from_filename(filename: str) -> str | None:
    """Extract entry (e.g. '0000:00b2') from filename like '0000_00b2_FUN_0000_00b2.c'."""
    # Format: <segment>_<offset>_FUN_<segment>_<offset>.c
    match = re.match(r'^([0-9a-f]{4})_([0-9a-f]{4})_', filename)
    if match:
        return f"{match.group(1)}:{match.group(2)}"
    return None


def get_existing_entries(matches_jsonl: Path) -> set[str]:
    """Load already-processed entries from matches.jsonl."""
    entries: set[str] = set()

    if not matches_jsonl.exists():
        return entries

    try:
        for line in matches_jsonl.read_text().strip().split('\n'):
            if not line.strip():
                continue
            try:
                record = json.loads(line)
                if "target_entry" in record:
                    entries.add(record["target_entry"])
            except json.JSONDecodeError:
                pass
    except Exception as e:
        print(f"WARNING: Failed to load existing matches: {e}", file=sys.stderr)

    return entries


def file_for_entry(entry: str) -> Path | None:
    """Map a colon-form entry (e.g. '0000:38e0') to its decompiled/<seg>_<off>_*.c file."""
    if ":" not in entry:
        return None
    seg, off = entry.split(":", 1)
    matches = sorted(DECOMPILED_DIR.glob(f"{seg}_{off}_*.c"))
    return matches[0] if matches else None


def run_matching(
    catalog: list[CoabFunction],
    strings_dict: dict[str, str],
    date: str,
    limit: int | None = None,
    entries: list[str] | None = None
) -> tuple[list[MatchResult], int]:
    """Main matching loop over decompiled functions.

    If `entries` is given, process exactly those colon-form entries (targeted mode).
    Otherwise process all decompiled functions. Returns (results, total_pending).
    """

    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_matches" / date
    out_dir.mkdir(parents=True, exist_ok=True)

    matches_jsonl = out_dir / "matches.jsonl"

    # Build catalog text
    catalog_lines = [
        f"{f.name} | {f.overlay} | {f.coab_addr} | {f.role_hint}"
        for f in catalog
    ]
    catalog_text = "\n".join(catalog_lines)

    # Get existing entries
    existing = get_existing_entries(matches_jsonl)

    # Collect candidate functions: targeted entries or all decompiled files
    if entries is not None:
        candidate_files: list[Path] = []
        for ent in entries:
            fp = file_for_entry(ent)
            if fp is None:
                print(f"WARN: no decompiled file found for entry {ent}")
                continue
            candidate_files.append(fp)
    else:
        candidate_files = sorted(DECOMPILED_DIR.glob("*.c"))

    pending_files = [
        f for f in candidate_files
        if entry_from_filename(f.name) not in existing
    ]

    if limit is not None:
        pending_files = pending_files[:limit]

    total_pending = len(candidate_files) - len([
        f for f in candidate_files if entry_from_filename(f.name) in existing
    ])

    results: list[MatchResult] = []

    print(f"Starting matching: {len(pending_files)} pending, {len(existing)} already done")
    print(f"Output: {matches_jsonl}")

    # Append to matches.jsonl
    append_fh = matches_jsonl.open("a")

    try:
        for idx, file_path in enumerate(pending_files, 1):
            entry = entry_from_filename(file_path.name)
            if not entry:
                print(f"WARN: Could not extract entry from {file_path.name}")
                continue

            # Read decompiled function
            decompiled_c = file_path.read_text(errors="replace")

            # Extract referenced strings
            referenced_strings = extract_referenced_strings(decompiled_c, strings_dict)

            # Call qwen
            result = call_qwen(
                catalog_text=catalog_text,
                target_entry=entry,
                decompiled_c=decompiled_c,
                referenced_strings=referenced_strings
            )
            results.append(result)

            # Write to JSONL
            record = {
                "target_entry": result.target_entry,
                "qwen_json": result.qwen_json,
                "raw_text": result.raw_text,
                "latency_ms": result.latency_ms,
                "http_status": result.http_status,
                "http_error": result.http_error
            }
            append_fh.write(json.dumps(record) + "\n")
            append_fh.flush()

            # Progress
            if idx % 25 == 0:
                status = "OK" if result.http_status == 200 else f"ERR({result.http_status})"
                print(f"  [{idx}/{len(pending_files)}] {entry} {status} {result.latency_ms}ms", flush=True)

    finally:
        append_fh.close()

    return results, total_pending


def write_rollup(date: str, results: list[MatchResult]) -> None:
    """Write matches_rollup.tsv with top candidate per function."""

    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_matches" / date
    rollup_path = out_dir / "matches_rollup.tsv"

    with rollup_path.open("w", newline="") as fh:
        writer = csv.DictWriter(
            fh,
            fieldnames=["entry", "top_candidate", "confidence", "verdict"],
            delimiter="\t"
        )
        writer.writeheader()

        for result in results:
            if result.qwen_json and "candidates" in result.qwen_json:
                candidates = result.qwen_json.get("candidates", [])
                top_candidate = candidates[0]["coab_name"] if candidates else ""
                confidence = candidates[0]["confidence"] if candidates else ""
            else:
                top_candidate = ""
                confidence = ""

            verdict = result.qwen_json.get("verdict", "") if result.qwen_json else ""

            writer.writerow({
                "entry": result.target_entry,
                "top_candidate": top_candidate,
                "confidence": confidence,
                "verdict": verdict
            })

    print(f"Rollup: {rollup_path}")


def write_manifest(
    date: str,
    catalog: list[CoabFunction],
    results: list[MatchResult],
    total_pending: int
) -> None:
    """Write run_manifest.json with metadata and counts."""

    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_matches" / date
    manifest_path = out_dir / "run_manifest.json"

    # Hash the catalog
    catalog_text = "\n".join(
        f"{f.name} | {f.overlay} | {f.coab_addr} | {f.role_hint}"
        for f in catalog
    )
    catalog_sha256 = hashlib.sha256(catalog_text.encode()).hexdigest()

    # Count verdicts
    verdicts: dict[str, int] = {}
    parse_failures = 0
    errors = 0

    for result in results:
        if result.http_error:
            errors += 1
        elif result.qwen_json is None:
            parse_failures += 1
        else:
            verdict = result.qwen_json.get("verdict", "unknown")
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
        "catalog_sha256": catalog_sha256,
        "catalog_count": len(catalog),
        "total_functions": 623,
        "processed": len(results),
        "remaining": total_pending - len(results),
        "verdicts": verdicts,
        "parse_failures": parse_failures,
        "http_errors": errors,
        "timeout": QWEN_TIMEOUT
    }

    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n")
    print(f"Manifest: {manifest_path}")


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Batch matching: qwen-coder on decompiled Matrix Cubed functions vs COAB catalog."
    )
    parser.add_argument(
        "--date",
        default="2026-07-08",
        help="Date string for output directory (default: 2026-07-08)"
    )
    parser.add_argument(
        "--limit",
        type=int,
        help="Process only first N pending functions (for piloting)"
    )
    parser.add_argument(
        "--rollup",
        action="store_true",
        help="Only write rollup and manifest from existing matches.jsonl"
    )
    parser.add_argument(
        "--entries",
        help="Comma-separated colon-form entries to process exactly "
             "(e.g. '0000:38e0,0000:bebd'). Targeted mode."
    )

    args = parser.parse_args()

    # Extract catalog
    print("Extracting COAB catalog...")
    catalog = extract_coab_catalog()
    print(f"  Found {len(catalog)} COAB functions")

    # Write catalog
    out_dir = ROOT / "generated/qwen_advisory/ghidra_coab_matches" / args.date
    out_dir.mkdir(parents=True, exist_ok=True)

    catalog_path = out_dir / "coab_catalog.tsv"
    with catalog_path.open("w", newline="") as fh:
        writer = csv.writer(fh, delimiter="\t")
        writer.writerow(["name", "overlay", "coab_addr", "role_hint"])
        for f in catalog:
            writer.writerow([f.name, f.overlay, f.coab_addr, f.role_hint])
    print(f"Catalog: {catalog_path} ({len(catalog)} lines)")

    # Rollup-only mode
    if args.rollup:
        matches_jsonl = out_dir / "matches.jsonl"
        if matches_jsonl.exists():
            results = []
            for line in matches_jsonl.read_text().strip().split('\n'):
                if line.strip():
                    try:
                        record = json.loads(line)
                        result = MatchResult(
                            target_entry=record["target_entry"],
                            qwen_json=record.get("qwen_json"),
                            latency_ms=record.get("latency_ms", 0),
                            http_status=record.get("http_status", 0)
                        )
                        results.append(result)
                    except Exception:
                        pass

            write_rollup(args.date, results)
            write_manifest(args.date, catalog, results, len(results))
        return 0

    # Normal matching mode
    print("Loading strings...")
    strings_dict = load_strings_dict()
    print(f"  Loaded {len(strings_dict)} strings")

    entries_list = None
    if args.entries:
        entries_list = [e.strip() for e in args.entries.split(",") if e.strip()]
        print(f"Targeted mode: {len(entries_list)} entries")

    print("Starting matching loop...")
    results, total_pending = run_matching(
        catalog=catalog,
        strings_dict=strings_dict,
        date=args.date,
        limit=args.limit,
        entries=entries_list
    )

    print(f"\nMatching complete: {len(results)} processed")

    # Write rollup
    write_rollup(args.date, results)

    # Write manifest
    write_manifest(args.date, catalog, results, total_pending)

    return 0


if __name__ == "__main__":
    sys.exit(main())
