#!/usr/bin/env python3
"""Run bounded Qwen-Coder advisory jobs for Matrix skill-check opcode evidence."""

from __future__ import annotations

import argparse
import json
import subprocess
import textwrap
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
EVIDENCE_DIR = ROOT / "generated" / "skill_check_recovery" / "2026-07-08"
OUT_DIR = EVIDENCE_DIR / "qwen"
MODEL = "ollama/qwen3-coder:30b"


@dataclass(frozen=True)
class Job:
    name: str
    prompt: str


def read_text(path: Path, limit: int | None = None) -> str:
    text = path.read_text(encoding="utf-8", errors="replace")
    if limit is not None and len(text) > limit:
        return text[:limit] + f"\n\n[TRUNCATED at {limit} chars from {path}]\n"
    return text


def base_instruction(title: str) -> str:
    return textwrap.dedent(
        f"""
        Matrix Cubed skill-check opcode Qwen-Coder advisory job: {title}

        Use only the supplied evidence. Do not invent paths, offsets, APIs,
        opcode names, skill names, test results, DOS behavior, or original-game
        facts.

        Return compact Markdown, maximum 700 words, with these sections:
        VERIFIED_FROM_PROMPT, CANDIDATES, RISKS, LOCAL_VALIDATION_STEPS,
        UNSUPPORTED_CLAIMS.

        Treat all output as advisory. Local bytes, generated artifacts, source
        review, and tests decide what is accepted.
        """
    ).strip()


def jobs() -> list[Job]:
    callsites = read_text(EVIDENCE_DIR / "skill_check_opcodes.tsv", 16000)
    who_contexts = read_text(EVIDENCE_DIR / "who_contexts.tsv", 16000)
    readme = read_text(EVIDENCE_DIR / "README.md", 8000)
    skill_names = read_text(ROOT / "generated/skill_recovery/2026-07-08/skill_names.tsv", 9000)
    stub_audit = read_text(ROOT / "references/ssi-engine/docs/coab-java-stub-audit.md", 7000)
    disassembler = read_text(ROOT / "scripts/ecl_disassemble.py", 12000)

    return [
        Job(
            "opcode_23_callsite_review",
            base_instruction("opcode 0x23 callsite review")
            + "\n\nGoal: review whether the supplied callsite evidence supports treating Matrix "
            "ECL opcode 0x23 as a SKILL_CHECK candidate, and identify operand-role hypotheses "
            "that need local validation. Do not recommend VM integration in this pass.\n\n"
            f"Recovery README:\n{readme}\n\nCallsites TSV:\n{callsites}\n\nStub audit:\n{stub_audit}\n",
        ),
        Job(
            "who_skill_prompt_correlation",
            base_instruction("WHO prompt and skill table correlation")
            + "\n\nGoal: correlate WHO prompt rows, nearby ECL context, and recovered skill names. "
            "Return only candidates and validation steps; do not assign definitive skill checks "
            "from prompt wording alone.\n\n"
            f"WHO contexts TSV:\n{who_contexts}\n\nRecovered skill table:\n{skill_names}\n",
        ),
        Job(
            "disassembler_label_boundary",
            base_instruction("disassembler label boundary")
            + "\n\nGoal: advise the safest next change boundary for the generic ECL disassembler. "
            "Should opcode 0x23 be renamed globally now, gated by Matrix profile, or left as-is "
            "with generated evidence docs? Identify tests needed for any future rename.\n\n"
            f"Current disassembler excerpt:\n{disassembler}\n\nCallsites TSV:\n{callsites}\n",
        ),
    ]


def run_job(job: Job, timeout: int) -> dict[str, object]:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    prompt_path = OUT_DIR / f"{job.name}.prompt.txt"
    raw_path = OUT_DIR / f"{job.name}.raw.txt"
    json_path = OUT_DIR / f"{job.name}.json"
    prompt_path.write_text(job.prompt, encoding="utf-8")
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
    raw_path.write_text(stdout, encoding="utf-8")
    record = {
        "job": job.name,
        "model": MODEL,
        "started": started,
        "finished": finished,
        "returncode": returncode,
        "prompt_path": str(prompt_path.relative_to(ROOT)),
        "raw_path": str(raw_path.relative_to(ROOT)),
    }
    json_path.write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    return record


def write_index(records: list[dict[str, object]]) -> None:
    lines = [
        "# Qwen-Coder Skill-Check Opcode Advisory - 2026-07-08",
        "",
        f"Model: `{MODEL}`",
        "",
        "Boundary: advisory only. Local evidence and tests decide accepted claims.",
        "",
        "| Job | Return | Raw Output | Prompt |",
        "|---|---:|---|---|",
    ]
    for record in records:
        lines.append(
            f"| `{record['job']}` | {record['returncode']} | "
            f"`{record['raw_path']}` | `{record['prompt_path']}` |"
        )
    (OUT_DIR / "README.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


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
