#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.game_paths import default_game_dir  # noqa: E402

GAME_DIR = default_game_dir()
OUT = ROOT / "generated"


def read_mz(path: Path) -> dict:
    data = path.read_bytes()
    if data[:2] != b"MZ":
        return {"path": str(path), "mz": False}
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
    file_size = (fields["pages"] - 1) * 512 + (fields["last_page_bytes"] or 512)
    header_size = fields["header_paragraphs"] * 16
    fields.update(
        {
            "path": str(path),
            "mz": True,
            "declared_file_size": file_size,
            "actual_file_size": len(data),
            "header_size": header_size,
            "load_image_size": max(0, file_size - header_size),
            "entry_cs_ip": f"{fields['initial_cs']:04X}:{fields['initial_ip']:04X}",
            "stack_ss_sp": f"{fields['initial_ss']:04X}:{fields['initial_sp']:04X}",
        }
    )
    relocs = []
    off = fields["reloc_table_offset"]
    for _ in range(fields["relocations"]):
        if off + 4 > len(data):
            break
        relocs.append(
            {
                "offset": int.from_bytes(data[off : off + 2], "little"),
                "segment": int.from_bytes(data[off + 2 : off + 4], "little"),
            }
        )
        off += 4
    fields["relocation_sample"] = relocs[:32]
    return fields


def dax_blocks(path: Path) -> list[dict]:
    data = path.read_bytes()
    if len(data) < 2:
        return []
    toc_len = int.from_bytes(data[:2], "little")
    data_offset = toc_len + 2
    if data_offset > len(data) or toc_len % 9 != 0:
        return []
    rows = []
    for off in range(2, data_offset, 9):
        if off + 9 > len(data):
            break
        rows.append(
            {
                "file": path.name,
                "id": data[off],
                "offset": int.from_bytes(data[off + 1 : off + 5], "little"),
                "raw_size": int.from_bytes(data[off + 5 : off + 7], "little"),
                "packed_size": int.from_bytes(data[off + 7 : off + 9], "little"),
            }
        )
    return rows


def strings_with_offsets(path: Path, limit: int = 500) -> list[dict]:
    proc = subprocess.run(["strings", "-a", "-td", str(path)], check=True, text=True, capture_output=True)
    rows = []
    for line in proc.stdout.splitlines():
        m = re.match(r"\s*(\d+)\s+(.*)", line)
        if not m:
            continue
        text = m.group(2)
        if len(text) < 4:
            continue
        rows.append({"offset": int(m.group(1)), "text": text})
        if len(rows) >= limit:
            break
    return rows


def write_inventory(files: list[dict]) -> None:
    lines = ["# Local File Inventory", "", "| File | Bytes | Kind |", "|---|---:|---|"]
    for row in files:
        lines.append(f"| `{row['name']}` | {row['bytes']} | {row['kind']} |")
    (OUT / "inventory.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    files = []
    for path in sorted(p for p in GAME_DIR.iterdir() if p.is_file()):
        kind = "unknown"
        if path.suffix.upper() == ".DAX":
            kind = "DAX container"
        elif path.suffix.upper() == ".EXE":
            kind = "DOS MZ executable"
        elif path.suffix.upper() == ".OVR":
            kind = "Borland overlay candidate"
        elif path.suffix.upper() in {".ADV", ".AD", ".BNK", ".XMI"}:
            kind = "audio/music/driver"
        files.append({"name": path.name, "bytes": path.stat().st_size, "kind": kind})
    write_inventory(files)
    (OUT / "start_exe_mz.json").write_text(json.dumps(read_mz(GAME_DIR / "START.EXE"), indent=2), encoding="utf-8")
    blocks = []
    for path in sorted(GAME_DIR.glob("*.DAX")):
        blocks.extend(dax_blocks(path))
    (OUT / "dax_blocks.json").write_text(json.dumps(blocks, indent=2), encoding="utf-8")
    with (OUT / "dax_blocks.tsv").open("w", encoding="utf-8") as f:
        f.write("file\tid\toffset\traw_size\tpacked_size\n")
        for row in blocks:
            f.write(f"{row['file']}\t{row['id']}\t{row['offset']}\t{row['raw_size']}\t{row['packed_size']}\n")
    (OUT / "start_exe_strings.json").write_text(
        json.dumps(strings_with_offsets(GAME_DIR / "START.EXE"), indent=2), encoding="utf-8"
    )
    (OUT / "game_ovr_strings.json").write_text(
        json.dumps(strings_with_offsets(GAME_DIR / "GAME.OVR", 1200), indent=2), encoding="utf-8"
    )
    print(f"Wrote analysis outputs to {OUT}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
