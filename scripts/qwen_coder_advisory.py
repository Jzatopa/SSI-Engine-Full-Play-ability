#!/usr/bin/env python3
"""Run bounded Qwen-Coder advisory passes over Matrix Cubed evidence.

The outputs are candidate analysis only. They are meant to reduce search space;
they do not promote offsets, names, formulas, or behavior into verified facts.
"""

from __future__ import annotations

import argparse
import csv
import json
import subprocess
import textwrap
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "generated" / "qwen_advisory" / "2026-07-08"
MODEL = "ollama/qwen3-coder:30b"


@dataclass(frozen=True)
class Job:
    name: str
    prompt: str


def read_text(path: Path, limit: int | None = None) -> str:
    text = path.read_text(errors="replace")
    if limit is not None and len(text) > limit:
        return text[:limit] + f"\n\n[TRUNCATED at {limit} chars from {path}]\n"
    return text


def tsv_rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", errors="replace") as fh:
        return list(csv.DictReader(fh, delimiter="\t"))


def run_qwen(job: Job, timeout: int) -> dict[str, object]:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    raw_path = OUT_DIR / f"{job.name}.raw.txt"
    prompt_path = OUT_DIR / f"{job.name}.prompt.txt"
    json_path = OUT_DIR / f"{job.name}.json"
    prompt_path.write_text(job.prompt)
    cmd = [
        "openclaw",
        "infer",
        "model",
        "run",
        "--model",
        MODEL,
        "--prompt",
        job.prompt,
    ]
    started = datetime.now().isoformat(timespec="seconds")
    try:
        proc = subprocess.run(
            cmd,
            cwd=ROOT,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=timeout,
            check=False,
        )
        stdout = proc.stdout
        returncode = proc.returncode
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout or ""
        if isinstance(stdout, bytes):
            stdout = stdout.decode(errors="replace")
        stdout += f"\n\n[TIMEOUT after {timeout}s]\n"
        returncode = 124
    finished = datetime.now().isoformat(timespec="seconds")
    raw_path.write_text(stdout)
    record = {
        "job": job.name,
        "model": MODEL,
        "started": started,
        "finished": finished,
        "returncode": returncode,
        "prompt_path": str(prompt_path.relative_to(ROOT)),
        "raw_path": str(raw_path.relative_to(ROOT)),
    }
    json_path.write_text(json.dumps(record, indent=2) + "\n")
    return record


def base_instruction(title: str) -> str:
    return textwrap.dedent(
        f"""
        Matrix Cubed reconstruction Qwen-Coder advisory job: {title}

        Use only the supplied evidence. Do not invent paths, offsets, APIs,
        names, source files, test results, or original-game facts.

        Return compact Markdown, maximum 700 words, with these sections:
        VERIFIED_FROM_PROMPT, CANDIDATES, RISKS, LOCAL_VALIDATION_STEPS,
        UNSUPPORTED_CLAIMS.

        Treat every match/name as a candidate until a local agent verifies it
        against original bytes, generated artifacts, source code, and tests.
        """
    ).strip()


def ghidra_triage_jobs() -> list[Job]:
    functions = tsv_rows(ROOT / "generated/ghidra/deep_game_ovr_payload/functions.tsv")
    strings = read_text(ROOT / "generated/ghidra/deep_game_ovr_payload/strings.tsv")
    write_deterministic_triage(functions)
    by_segment: dict[str, list[dict[str, str]]] = {}
    for row in functions:
        by_segment.setdefault(row["entry"].split(":")[0], []).append(row)
    summary = "\n".join(
        f"segment {segment}: count={len(rows)} max_body={max(int(r['body_addresses']) for r in rows)} "
        f"thunks={sum(1 for r in rows if r['is_thunk'] == 'true')}"
        for segment, rows in sorted(by_segment.items())
    )
    prompt = (
        base_instruction("Ghidra function triage rule review")
        + "\n\nGoal: review an all-623-function candidate triage artifact generated from metadata. "
        "Do not classify all rows yourself. Instead, critique the heuristic, identify risks, and "
        "propose local validation steps. Artifact path: "
        "generated/qwen_advisory/2026-07-08/ghidra_function_triage_candidates.tsv.\n\n"
        "Subsystem choices used: overlay/runtime, text/ui, menu/input, save/load, file/resource, "
        "combat, combat-ai, map/navigation, character/party, skills/effects, items/loot/shop, "
        "space/ship, graphics/sound, tiny-thunk/helper, unknown.\n\n"
        f"Defined strings table:\n{strings}\n\nSegment summary:\n{summary}\n"
    )
    return [Job("ghidra_triage_rule_review", prompt)]


def write_deterministic_triage(functions: list[dict[str, str]]) -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    path = OUT_DIR / "ghidra_function_triage_candidates.tsv"
    with path.open("w", newline="") as fh:
        writer = csv.writer(fh, delimiter="\t")
        writer.writerow(["entry", "name", "body_addresses", "subsystem_candidate", "confidence", "why", "validation_step"])
        for row in functions:
            body = int(row["body_addresses"])
            segment = row["entry"].split(":")[0]
            if row["is_thunk"] == "true" or body <= 5:
                subsystem, confidence, why = "tiny-thunk/helper", "medium", "thunk flag or very small body"
            elif segment == "3000":
                subsystem, confidence, why = "map/navigation", "low", "3000 segment has prior map/source-recovery anchors"
            elif segment == "2000":
                subsystem, confidence, why = "save/load", "low", "2000 segment contains save/load strings in Ghidra string table"
            elif segment == "1000":
                subsystem, confidence, why = "text/ui", "low", "1000 segment contains selection/leadership UI strings"
            elif body >= 120:
                subsystem, confidence, why = "unknown", "low", "large function needing snippet review"
            else:
                subsystem, confidence, why = "unknown", "low", "metadata only"
            writer.writerow([row["entry"], row["name"], row["body_addresses"], subsystem, confidence, why, "open decompiled snippet and cross-check strings/callers"])


def selected_decompiled_snippets(limit: int = 2) -> str:
    decompiled = ROOT / "generated/ghidra/deep_game_ovr_payload/decompiled"
    preferred_entries = [
        "0000_6",
        "1000_5",
        "2000_",
        "3000_",
        "0000_d",
        "0000_e",
    ]
    files: list[Path] = []
    for prefix in preferred_entries:
        files.extend(sorted(decompiled.glob(f"{prefix}*.c"))[:3])
    if len(files) < limit:
        files.extend(sorted(decompiled.glob("*.c"), key=lambda p: p.stat().st_size, reverse=True)[:limit])
    seen: set[Path] = set()
    snippets: list[str] = []
    for path in files:
        if path in seen:
            continue
        seen.add(path)
        snippets.append(f"## {path.name}\n{read_text(path, 800)}")
        if len(snippets) >= limit:
            break
    return "\n\n".join(snippets)


def coab_matching_job() -> Job:
    coab_summary = subprocess.run(
        [
            "bash",
            "-lc",
            "find ~/.local/opt/coab/engine ~/.local/opt/coab/Classes -maxdepth 2 -type f -name '*.cs' "
            "| xargs rg -n \"internal static|public static|class |PlayerQuickFight|MainCombatLoop|BattleRoundChecks|Treasure|Rob|load_npc|CMD_|Skill|Clock\" -S",
        ],
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
        check=False,
    ).stdout[:2500]
    prompt = (
        base_instruction("Ghidra-to-COAB candidate matching")
        + "\n\nGoal: propose likely COAB analogues for selected GAME.OVR decompiled snippets. "
        "Return a table: ghidra_file, likely_subsystem, possible_coab_file_function, confidence, "
        "why, exact local validation steps. Do not claim a match as verified.\n\n"
        f"COAB symbol/keyword summary:\n{coab_summary}\n\n"
        f"Selected GAME.OVR decompiled snippets:\n{selected_decompiled_snippets()}\n"
    )
    return Job("ghidra_coab_candidate_matching", prompt)


def offset_clustering_job() -> Job:
    files = [
        ROOT / "generated/liveplay/controlled_save_samples.md",
        ROOT / "generated/liveplay/save_probe_pre_combat.json",
        ROOT / "generated/data_model/data_model_catalog.md",
        ROOT / "generated/data_model/mon0cha_monsters.tsv",
        ROOT / "generated/data_model/mon0spc_effects.tsv",
        ROOT / "src/matrix_cubed/formats/save.py",
        ROOT / "src/matrix_cubed/engine/save_load.py",
    ]
    evidence = "\n\n".join(f"## {p.relative_to(ROOT)}\n{read_text(p, 4500)}" for p in files if p.exists())
    prompt = (
        base_instruction("Unknown offset clustering")
        + "\n\nGoal: cluster likely character/save/monster/effect fields and propose testable hypotheses. "
        "Use labels like VERIFIED, CANDIDATE, or UNKNOWN. Do not assign final names to unknown bytes.\n\n"
        f"Evidence:\n{evidence}\n"
    )
    return Job("unknown_offset_clustering", prompt)


def test_matrix_job() -> Job:
    files = [
        ROOT / "references/ssi-engine/docs/coab-java-stub-audit.md",
        ROOT / "references/ssi-engine/docs/coab-combat-port-map.md",
        ROOT / "HANDOFF.md",
        ROOT / "references/ssi-engine/src/test/java/data/character/CharacterBuckRogersTest.java",
        ROOT / "references/ssi-engine/src/test/java/engine/combat/ai/QuickFightPlannerTest.java",
        ROOT / "references/ssi-engine/src/test/java/engine/party/NpcPartyServiceTest.java",
        ROOT / "references/ssi-engine/src/test/java/engine/time/GameClockTest.java",
    ]
    evidence = "\n\n".join(f"## {p.relative_to(ROOT)}\n{read_text(p, 3500)}" for p in files if p.exists())
    prompt = (
        base_instruction("Test matrix generation")
        + "\n\nGoal: propose a prioritized test matrix for the next Matrix Cubed Java passes. "
        "Group by character fields, skill checks, VM opcodes, combat integration, party/NPC/clock, "
        "save/load, and cross-game compatibility. For each test include fixture/evidence needed and "
        "what must remain unresolved.\n\n"
        f"Evidence:\n{evidence}\n"
    )
    return Job("test_matrix_generation", prompt)


def port_map_job() -> Job:
    files = [
        ROOT / "references/ssi-engine/docs/coab-combat-port-map.md",
        ROOT / "references/ssi-engine/docs/coab-provenance-audit-2026-07-08.md",
        ROOT / "references/ssi-engine/docs/coab-java-stub-audit.md",
    ]
    package_listing = subprocess.run(
        [
            "bash",
            "-lc",
            "find references/ssi-engine/src/main/java/engine references/ssi-engine/src/main/java/data/character "
            "-type f -name '*.java' | sort",
        ],
        cwd=ROOT,
        text=True,
        stdout=subprocess.PIPE,
        check=False,
    ).stdout
    evidence = "\n\n".join(f"## {p.relative_to(ROOT)}\n{read_text(p, 5000)}" for p in files if p.exists())
    prompt = (
        base_instruction("COAB port-map comparison")
        + "\n\nGoal: compare the documented port plan/audit against the current Java package listing. "
        "Identify likely missing integration surfaces, branch risks, adapter boundaries, and validation "
        "steps. Do not recommend editing files currently claimed by Claude; produce an integration checklist.\n\n"
        f"Current package listing:\n{package_listing}\n\nEvidence:\n{evidence}\n"
    )
    return Job("port_map_comparison", prompt)


def ocr_sanity_job() -> Job:
    files = [
        ROOT / "generated/liveplay/first_map_qwen_ocr.md",
        ROOT / "generated/liveplay/first_map_capture/capture_manifest.md",
        ROOT / "generated/runtime_validation/pygame_reference_bundle/qwen_ocr.md",
        ROOT / "HANDOFF.md",
    ]
    evidence = "\n\n".join(f"## {p.relative_to(ROOT)}\n{read_text(p, 4500)}" for p in files if p.exists())
    prompt = (
        base_instruction("OCR/text sanity boundary")
        + "\n\nGoal: audit what OCR/text evidence may be used now, what must remain rejected, and "
        "what capture fixes or validation steps are needed before OCR can support original-game claims. "
        "Return a table of usable, candidate, and rejected evidence.\n\n"
        f"Evidence:\n{evidence}\n"
    )
    return Job("ocr_text_sanity", prompt)


def all_jobs() -> list[Job]:
    return [
        *ghidra_triage_jobs(),
        coab_matching_job(),
        offset_clustering_job(),
        test_matrix_job(),
        port_map_job(),
        ocr_sanity_job(),
    ]


def write_index(records: list[dict[str, object]]) -> None:
    lines = [
        "# Qwen-Coder Advisory Run - 2026-07-08",
        "",
        f"Model: `{MODEL}`",
        "",
        "Boundary: all outputs are candidate advisory analysis only. Local evidence and tests decide implementation.",
        "",
        "Additional artifact: `generated/qwen_advisory/2026-07-08/ghidra_function_triage_candidates.tsv` "
        "covers all 623 Ghidra GAME.OVR candidate functions plus a header row.",
        "",
        "| Job | Return | Raw Output | Prompt |",
        "|---|---:|---|---|",
    ]
    for record in records:
        lines.append(
            f"| `{record['job']}` | {record['returncode']} | "
            f"`{record['raw_path']}` | `{record['prompt_path']}` |"
        )
    (OUT_DIR / "README.md").write_text("\n".join(lines) + "\n")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--timeout", type=int, default=300)
    parser.add_argument("--only", nargs="*", help="Run only jobs whose names contain one of these strings")
    args = parser.parse_args()

    jobs = all_jobs()
    if args.only:
        jobs = [job for job in jobs if any(token in job.name for token in args.only)]
    records = []
    for job in jobs:
        print(f"RUN {job.name}", flush=True)
        records.append(run_qwen(job, args.timeout))
    write_index(records)
    failures = [record for record in records if record["returncode"] != 0]
    if failures:
        print(f"Completed with {len(failures)} Qwen job failures; see {OUT_DIR}")
        return 1
    print(f"Completed {len(records)} Qwen jobs; see {OUT_DIR}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
