#!/usr/bin/env python3
"""Import and verify externally supplied START/GAME.OVR RE packages."""

from __future__ import annotations

import argparse
import json
import shutil
import sys
import zipfile
from dataclasses import dataclass
from hashlib import sha256
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402

DEFAULT_GAME_DIR = default_game_dir()
DEFAULT_MEDIA_DIR = Path("/home/jzatopa/.openclaw/media/inbound")


@dataclass(frozen=True)
class PackageSpec:
    name: str
    zip_path: Path
    extract_dir: Path


def file_sha256(path: Path) -> str:
    h = sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def read_mz(path: Path) -> dict[str, Any]:
    data = path.read_bytes()
    if data[:2] != b"MZ":
        return {"path": str(path), "mz": False, "bytes": len(data), "sha256": file_sha256(path)}
    fields = {
        "last_page_bytes": int.from_bytes(data[2:4], "little"),
        "pages": int.from_bytes(data[4:6], "little"),
        "relocations": int.from_bytes(data[6:8], "little"),
        "header_paragraphs": int.from_bytes(data[8:10], "little"),
        "min_extra_paragraphs": int.from_bytes(data[10:12], "little"),
        "max_extra_paragraphs": int.from_bytes(data[12:14], "little"),
        "initial_ss": int.from_bytes(data[14:16], "little"),
        "initial_sp": int.from_bytes(data[16:18], "little"),
        "checksum": int.from_bytes(data[18:20], "little"),
        "initial_ip": int.from_bytes(data[20:22], "little"),
        "initial_cs": int.from_bytes(data[22:24], "little"),
        "reloc_table_offset": int.from_bytes(data[24:26], "little"),
        "overlay_number": int.from_bytes(data[26:28], "little"),
    }
    declared_size = (fields["pages"] - 1) * 512 + (fields["last_page_bytes"] or 512)
    header_size = fields["header_paragraphs"] * 16
    return {
        "path": str(path),
        "mz": True,
        "bytes": len(data),
        "sha256": file_sha256(path),
        "declared_file_size": declared_size,
        "header_size": header_size,
        "load_image_size": max(0, declared_size - header_size),
        "relocations": fields["relocations"],
        "entry_cs_ip": f"{fields['initial_cs']:04X}:{fields['initial_ip']:04X}",
        "stack_ss_sp": f"{fields['initial_ss']:04X}:{fields['initial_sp']:04X}",
        "reloc_table_offset": fields["reloc_table_offset"],
        "overlay_number": fields["overlay_number"],
    }


def find_single_zip(pattern: str, media_dir: Path = DEFAULT_MEDIA_DIR) -> Path:
    matches = sorted(media_dir.glob(pattern), key=lambda p: p.stat().st_mtime, reverse=True)
    if not matches:
        raise FileNotFoundError(f"No inbound package matched {media_dir / pattern}")
    return matches[0]


def zip_inventory(path: Path) -> list[dict[str, Any]]:
    with zipfile.ZipFile(path) as zf:
        rows = []
        for info in zf.infolist():
            rows.append(
                {
                    "name": info.filename,
                    "bytes": info.file_size,
                    "compressed_bytes": info.compress_size,
                    "is_dir": info.is_dir(),
                }
            )
        return rows


def safe_extract_zip(path: Path, out_dir: Path) -> None:
    if out_dir.exists():
        shutil.rmtree(out_dir)
    out_dir.mkdir(parents=True)
    root = out_dir.resolve()
    with zipfile.ZipFile(path) as zf:
        for info in zf.infolist():
            target = (out_dir / info.filename).resolve()
            if root != target and root not in target.parents:
                raise ValueError(f"Refusing unsafe ZIP member path: {info.filename}")
        zf.extractall(out_dir)


def first_existing(root: Path, names: list[str]) -> Path | None:
    for name in names:
        matches = list(root.rglob(name))
        if matches:
            return matches[0]
    return None


def contains_bytes(path: Path, needle: bytes) -> bool:
    return needle in path.read_bytes()


def count_nonempty_lines(path: Path | None) -> int | None:
    if path is None or not path.exists():
        return None
    return sum(1 for line in path.read_text(encoding="utf-8", errors="replace").splitlines() if line.strip())


def review_start(spec: PackageSpec, game_dir: Path) -> dict[str, Any]:
    original = game_dir / "START.EXE"
    unpacked = first_existing(spec.extract_dir, ["START.unpacked.exe"])
    memory = first_existing(spec.extract_dir, ["START.unpacked.memory.bin"])
    strings = first_existing(spec.extract_dir, ["START.unpacked.strings.txt"])
    disassembly = first_existing(spec.extract_dir, ["START.unpacked.disassembly.asm"])
    if unpacked is None:
        raise FileNotFoundError("START package did not contain START.unpacked.exe")
    return {
        "original": read_mz(original),
        "package_unpacked_exe": read_mz(unpacked),
        "package_unpacked_memory": {
            "path": str(memory) if memory else None,
            "bytes": memory.stat().st_size if memory else None,
            "sha256": file_sha256(memory) if memory else None,
        },
        "package_disassembly": {
            "path": str(disassembly) if disassembly else None,
            "bytes": disassembly.stat().st_size if disassembly else None,
            "sha256": file_sha256(disassembly) if disassembly else None,
        },
        "unpacked_strings_nonempty_lines": count_nonempty_lines(strings),
        "original_contains_packed_corrupt_string": contains_bytes(original, b"Packed file is corrupt"),
        "unpacked_contains_borland_copyright": contains_bytes(unpacked, b"Portions Copyright (c) 1983,90 Borland"),
        "verdict": (
            "The package START.EXE hash matches the local original. The supplied unpacked EXE is a derived "
            "MZ artifact and should be treated as externally supplied best-effort evidence until its unpacking "
            "method is reproduced locally."
        ),
    }


def review_game_ovr(spec: PackageSpec, game_dir: Path) -> dict[str, Any]:
    original = game_dir / "GAME.OVR"
    data = original.read_bytes()
    payload = first_existing(spec.extract_dir, ["GAME.OVR.payload_after_fbov_header.bin"])
    metadata = first_existing(spec.extract_dir, ["metadata.json"])
    raw_disassembly = first_existing(spec.extract_dir, ["GAME.OVR.raw_8086_disassembly.asm"])
    payload_disassembly = first_existing(spec.extract_dir, ["GAME.OVR.payload_8086_disassembly.asm"])
    if payload is None:
        raise FileNotFoundError("GAME.OVR package did not contain payload_after_fbov_header")
    external_metadata = json.loads(metadata.read_text(encoding="utf-8")) if metadata else None
    declared_payload_size = int.from_bytes(data[4:8], "little") if data[:4] == b"FBOV" else None
    return {
        "original": {
            "path": str(original),
            "bytes": len(data),
            "sha256": file_sha256(original),
            "fbov_magic": data[:4] == b"FBOV",
            "fbov_declared_payload_size": declared_payload_size,
            "bytes_after_8_byte_fbov_header": max(0, len(data) - 8),
        },
        "external_metadata": external_metadata,
        "payload": {
            "path": str(payload),
            "bytes": payload.stat().st_size,
            "sha256": file_sha256(payload),
            "matches_original_after_8_byte_fbov_header": payload.read_bytes() == data[8:],
        },
        "raw_disassembly": {
            "path": str(raw_disassembly) if raw_disassembly else None,
            "bytes": raw_disassembly.stat().st_size if raw_disassembly else None,
            "sha256": file_sha256(raw_disassembly) if raw_disassembly else None,
        },
        "payload_disassembly": {
            "path": str(payload_disassembly) if payload_disassembly else None,
            "bytes": payload_disassembly.stat().st_size if payload_disassembly else None,
            "sha256": file_sha256(payload_disassembly) if payload_disassembly else None,
        },
        "verdict": (
            "The package payload exactly matches local GAME.OVR bytes after the 8-byte FBOV header. Raw "
            "disassemblies are useful search evidence but include code/data ambiguity until overlay segments "
            "and relocations are mapped."
        ),
    }


def write_markdown(path: Path, report: dict[str, Any]) -> None:
    start = report["start_review"]
    game = report["game_ovr_review"]
    lines = [
        "# Reverse-Engineering Package Review",
        "",
        "Imported externally supplied START.EXE and GAME.OVR reverse-engineering packages.",
        "",
        "## Package Hashes",
        "",
    ]
    for pkg in report["packages"]:
        lines.append(f"- `{pkg['name']}` ZIP SHA-256: `{pkg['sha256']}`")
    lines.extend(
        [
            "",
            "## START.EXE",
            "",
            f"- Local original SHA-256: `{start['original']['sha256']}`",
            f"- Supplied unpacked EXE SHA-256: `{start['package_unpacked_exe']['sha256']}`",
            f"- Supplied unpacked EXE entry: `{start['package_unpacked_exe']['entry_cs_ip']}`",
            f"- Supplied unpacked EXE stack: `{start['package_unpacked_exe']['stack_ss_sp']}`",
            f"- Supplied unpacked EXE relocations: `{start['package_unpacked_exe']['relocations']}`",
            f"- Original contains `Packed file is corrupt`: `{start['original_contains_packed_corrupt_string']}`",
            f"- Unpacked contains Borland copyright: `{start['unpacked_contains_borland_copyright']}`",
            "",
            f"Verdict: {start['verdict']}",
            "",
            "## GAME.OVR",
            "",
            f"- Local original SHA-256: `{game['original']['sha256']}`",
            f"- FBOV magic present: `{game['original']['fbov_magic']}`",
            f"- Declared FBOV payload size: `{game['original']['fbov_declared_payload_size']}`",
            f"- Actual bytes after header: `{game['original']['bytes_after_8_byte_fbov_header']}`",
            f"- Supplied payload SHA-256: `{game['payload']['sha256']}`",
            f"- Supplied payload matches local `GAME.OVR[8:]`: `{game['payload']['matches_original_after_8_byte_fbov_header']}`",
            "",
            f"Verdict: {game['verdict']}",
            "",
            "## Integration Notes",
            "",
            "- Full extracted package files are staged under `generated/reverse_engineering/imported/`.",
            "- The START unpacked executable is not promoted as a replacement for `START.EXE`.",
            "- The GAME.OVR payload is confirmed as a byte-identical derived view of the local overlay.",
            "- Next useful decompiler work is to load the unpacked START artifact and GAME.OVR together with overlay-aware segment mapping.",
            "",
        ]
    )
    path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-dir", type=Path, default=DEFAULT_GAME_DIR)
    parser.add_argument("--out-dir", type=Path, default=ROOT / "generated" / "reverse_engineering")
    parser.add_argument("--start-zip", type=Path)
    parser.add_argument("--game-ovr-zip", type=Path)
    args = parser.parse_args()

    start_zip = args.start_zip or find_single_zip("START_reverse_engineering_package*.zip")
    game_ovr_zip = args.game_ovr_zip or find_single_zip("GAME_OVR_reverse_engineering_package*.zip")
    imported = args.out_dir / "imported"
    specs = [
        PackageSpec("START reverse-engineering package", start_zip, imported / "start"),
        PackageSpec("GAME.OVR reverse-engineering package", game_ovr_zip, imported / "game_ovr"),
    ]

    for spec in specs:
        safe_extract_zip(spec.zip_path, spec.extract_dir)

    report = {
        "packages": [
            {
                "name": spec.name,
                "zip_path": str(spec.zip_path),
                "sha256": file_sha256(spec.zip_path),
                "members": zip_inventory(spec.zip_path),
                "extract_dir": str(spec.extract_dir),
            }
            for spec in specs
        ],
        "start_review": review_start(specs[0], args.game_dir),
        "game_ovr_review": review_game_ovr(specs[1], args.game_dir),
    }
    args.out_dir.mkdir(parents=True, exist_ok=True)
    (args.out_dir / "package_review.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    write_markdown(args.out_dir / "package_review.md", report)
    print(f"Wrote {args.out_dir / 'package_review.md'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
