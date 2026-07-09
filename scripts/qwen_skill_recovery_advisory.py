#!/usr/bin/env python3
"""Run bounded Qwen-Coder advisory jobs for Matrix skill recovery."""

from __future__ import annotations

import argparse
import json
import subprocess
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "generated" / "skill_recovery" / "2026-07-08" / "qwen"
EVIDENCE_DIR = ROOT / "generated" / "skill_recovery" / "2026-07-08"
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


def base_instruction(title: str) -> str:
    return f"""Matrix Cubed skill recovery Qwen-Coder advisory job: {title}

Use only the supplied evidence. Do not invent paths, offsets, APIs, skill names,
test results, or original-game facts.

Return compact Markdown with these sections:
VERIFIED_FROM_PROMPT, CANDIDATES, RISKS, LOCAL_VALIDATION_STEPS,
UNSUPPORTED_CLAIMS.

Treat all output as advisory. Local byte/source/test evidence decides what gets
implemented."""


def jobs() -> list[Job]:
    skill_names = read_text(EVIDENCE_DIR / "skill_names.tsv", 9000)
    sample_values = read_text(EVIDENCE_DIR / "sample_skill_values.tsv", 12000)
    readme = read_text(EVIDENCE_DIR / "README.md", 8000)
    decompiled = "\n\n".join(
        f"## {path.name}\n{read_text(path, 5000)}"
        for path in [
            ROOT / "generated/ghidra/deep_game_ovr_payload/decompiled/1000_8467_FUN_1000_8467.c",
            ROOT / "generated/ghidra/deep_game_ovr_payload/decompiled/2000_b375_FUN_2000_b375.c",
            ROOT / "generated/ghidra/deep_game_ovr_payload/decompiled/2000_5605_FUN_2000_5605.c",
        ]
        if path.exists()
    )
    java = "\n\n".join(
        f"## {path.relative_to(ROOT)}\n{read_text(path, 5000)}"
        for path in [
            ROOT / "references/ssi-engine/src/main/java/character/buckrogers/CharacterSkillBuckRogers.java",
            ROOT / "references/ssi-engine/src/main/java/data/character/CharacterBuckRogers.java",
            ROOT / "references/ssi-engine/src/test/java/data/character/CharacterBuckRogersTest.java",
        ]
        if path.exists()
    )
    return [
        Job(
            "skill_table_mapping_review",
            base_instruction("skill table mapping review")
            + "\n\nGoal: review whether the supplied evidence supports mapping skill ids 1..84 to "
            "START.EXE names and WHO offsets 0x4C + skill_id. Identify validation gaps.\n\n"
            f"Skill table:\n{skill_names}\n\nDecompiler evidence:\n{decompiled}\n",
        ),
        Job(
            "sample_skill_value_clustering",
            base_instruction("sample skill value clustering")
            + "\n\nGoal: cluster non-zero saved skill values by career/sample and identify which "
            "fields are verified enough for Java regression tests. Do not infer unobserved careers.\n\n"
            f"Skill recovery README:\n{readme}\n\nSample values:\n{sample_values}\n",
        ),
        Job(
            "java_skill_decode_boundary",
            base_instruction("Java implementation boundary")
            + "\n\nGoal: advise the safest Java change boundary. Should the enum include all recovered "
            "skill names? Should getSkills expose all 84 or only non-zero values? What focused tests "
            "should be added? Do not recommend combat or VM integration in this pass.\n\n"
            f"Current Java evidence:\n{java}\n\nSkill table:\n{skill_names}\n",
        ),
    ]


def run_job(job: Job, timeout: int) -> dict[str, object]:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    prompt_path = OUT_DIR / f"{job.name}.prompt.txt"
    raw_path = OUT_DIR / f"{job.name}.raw.txt"
    json_path = OUT_DIR / f"{job.name}.json"
    prompt_path.write_text(job.prompt)
    started = datetime.now().isoformat(timespec="seconds")
    try:
        proc = subprocess.run(
            ["openclaw", "infer", "model", "run", "--model", MODEL, "--prompt", job.prompt],
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


def write_index(records: list[dict[str, object]]) -> None:
    lines = [
        "# Qwen-Coder Skill Recovery Advisory - 2026-07-08",
        "",
        f"Model: `{MODEL}`",
        "",
        "Boundary: advisory only. Local bytes, generated artifacts, source review, and tests decide implementation.",
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
    args = parser.parse_args()
    records = []
    for job in jobs():
        print(f"RUN {job.name}", flush=True)
        records.append(run_job(job, args.timeout))
    write_index(records)
    failures = [record for record in records if record["returncode"] != 0]
    if failures:
        print(f"Completed with {len(failures)} failures; see {OUT_DIR}")
        return 1
    print(f"Completed {len(records)} Qwen jobs; see {OUT_DIR}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
