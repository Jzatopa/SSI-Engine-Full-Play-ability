from __future__ import annotations

import argparse
import json
from dataclasses import asdict
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "src"))

from matrix_cubed.formats.save import read_saved_character  # noqa: E402


SAMPLE_INTENTS = {
    "TST1": "terran male rocket_jock baseline",
    "TST2": "terran male rocket_jock baseline",
    "RAC1": "martian male rocket_jock race variant",
    "GEN1": "terran female rocket_jock gender variant",
    "CAR1": "terran male medic career variant",
}

CONFIRMED_ENUM_OFFSETS = [
    {
        "offset": "0x26",
        "field": "gender_id_candidate",
        "observations": {"0": "male", "1": "female"},
        "evidence": ["TST1", "TST2", "RAC1", "GEN1", "CAR1"],
    },
    {
        "offset": "0x27",
        "field": "race_id_candidate",
        "observations": {"1": "terran", "2": "martian"},
        "evidence": ["TST1", "TST2", "RAC1", "GEN1", "CAR1"],
    },
    {
        "offset": "0x28",
        "field": "career_id_candidate",
        "observations": {"1": "rocket_jock", "2": "medic"},
        "evidence": ["TST1", "TST2", "RAC1", "GEN1", "CAR1"],
    },
]


def main() -> None:
    parser = argparse.ArgumentParser(description="Summarize controlled Matrix Cubed save samples.")
    parser.add_argument("save_dir", type=Path)
    parser.add_argument("output_dir", type=Path)
    parser.add_argument("--baseline", default="TST2")
    args = parser.parse_args()

    characters = []
    raw_records = {}
    character_paths = sorted({*args.save_dir.glob("*.WHO"), *args.save_dir.glob("CHRDATA*.SAV")})
    for who_path in character_paths:
        character = read_saved_character(who_path)
        raw_records[character.stem] = who_path.read_bytes()
        row = asdict(character)
        row["intent"] = SAMPLE_INTENTS.get(character.stem) or SAMPLE_INTENTS.get(character.who.name, "unknown")
        row["who_path"] = str(character.who_path)
        row["stf_path"] = str(character.stf_path) if character.stf_path else None
        characters.append(row)

    baseline = raw_records.get(args.baseline)
    diffs = {}
    if baseline is not None:
        for stem, data in sorted(raw_records.items()):
            if stem == args.baseline:
                continue
            diffs[stem] = [
                {
                    "offset": f"0x{index:02x}",
                    "baseline": baseline[index],
                    "sample": value,
                }
                for index, value in enumerate(data)
                if index < len(baseline) and baseline[index] != value
            ]

    summary = {
        "save_dir": str(args.save_dir),
        "baseline": args.baseline,
        "characters": characters,
        "confirmed_enum_offsets": CONFIRMED_ENUM_OFFSETS,
        "byte_diffs_vs_baseline": diffs,
    }

    args.output_dir.mkdir(parents=True, exist_ok=True)
    (args.output_dir / "controlled_save_samples.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    (args.output_dir / "controlled_save_samples.md").write_text(_markdown(summary), encoding="utf-8")


def _markdown(summary: dict) -> str:
    lines = [
        "# Controlled Save Samples",
        "",
        f"Save directory: `{summary['save_dir']}`",
        f"Baseline for byte diffs: `{summary['baseline']}`",
        "",
        "## Characters",
        "",
        "| Stem | Intent | Race | Gender | Career | Level | XP | HP Candidate |",
        "| --- | --- | --- | --- | --- | ---: | ---: | ---: |",
    ]
    for character in summary["characters"]:
        who = character["who"]
        lines.append(
            f"| {character['stem']} | {character['intent']} | {who['race']} ({who['race_id']}) "
            f"| {who['gender']} ({who['gender_id']}) | {who['career']} ({who['career_id']}) "
            f"| {who['level']} | {who['experience']} | {who['hit_points_candidate']} |"
        )
    lines.extend(["", "## Confirmed Enum Offsets", ""])
    for item in summary["confirmed_enum_offsets"]:
        observations = ", ".join(f"{key}={value}" for key, value in item["observations"].items())
        evidence = ", ".join(item["evidence"])
        lines.append(f"- `{item['offset']}` `{item['field']}`: {observations}. Evidence: {evidence}.")
    lines.extend(["", "## Diff Notes", ""])
    lines.append("Byte diffs are generated in the JSON artifact. Many differences are expected because stats, age, HP, and name vary between random character rolls.")
    lines.append("")
    return "\n".join(lines)


if __name__ == "__main__":
    main()
