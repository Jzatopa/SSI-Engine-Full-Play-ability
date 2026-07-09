#!/usr/bin/env python3
"""Build a self-contained static map/event viewer for Matrix Cubed data."""

from __future__ import annotations

import argparse
import json
import os
import re
from html import escape
from pathlib import Path


ASSET_PREFIXES = ("BACK1_", "PIC1_", "CPIC1_", "SPRIT1_", "WALLDEF", "SHIPS_", "CHARS_")
MENU_BODY_RE = re.compile(r"MENU:\s*(.+)")
ON_GOTO_BODY_RE = re.compile(r"ON GOTO\s+(.+?)\s+of\s+\[([^\]]+)\]")


def read_wallsets(path: Path) -> dict[int, dict[str, str]]:
    rows: dict[int, dict[str, str]] = {}
    if not path.exists():
        return rows
    lines = path.read_text(encoding="utf-8").splitlines()
    header = lines[0].split("\t")
    for line in lines[1:]:
        values = line.split("\t")
        row = dict(zip(header, values))
        if row.get("geo_id"):
            rows[int(row["geo_id"])] = row
    return rows


def collect_assets(asset_dir: Path, limit: int = 36) -> list[dict[str, str]]:
    if not asset_dir.exists():
        return []
    assets = []
    for path in sorted(asset_dir.glob("*.png")):
        if path.name.startswith(ASSET_PREFIXES):
            assets.append({"name": path.name, "url": path.as_uri()})
        if len(assets) >= limit:
            break
    return assets


def find_prefixed_file(directory: Path | None, geo_id: int) -> str:
    if directory is None or not directory.exists():
        return ""
    matches = sorted(directory.glob(f"geo_{geo_id:03d}_*"))
    return matches[0].resolve().as_uri() if matches else ""


def find_prefixed_path(directory: Path | None, geo_id: int) -> Path | None:
    if directory is None or not directory.exists():
        return None
    matches = sorted(directory.glob(f"geo_{geo_id:03d}_*"))
    return matches[0] if matches else None


def read_event_sections(path: Path | None, limit: int = 2400) -> dict[str, str]:
    if path is None or not path.exists():
        return {}
    text = path.read_text(encoding="utf-8")
    sections: dict[str, str] = {}
    matches = list(re.finditer(r"^## Event\s+(\d+)\s*$", text, re.MULTILINE))
    for index, match in enumerate(matches):
        event_id = str(int(match.group(1)))
        start = match.end()
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        body = text[start:end].strip()
        if len(body) > limit:
            body = body[:limit].rstrip() + "\n..."
        sections[event_id] = body
    return sections


def classify_event(text: str, pseudocode: str) -> str:
    haystack = f"{text}\n{pseudocode}".upper()
    if any(word in haystack for word in ("COMBAT", "BATTLE", "MONSTER", "SURPRISE")):
        return "combat"
    if any(word in haystack for word in ("DAMAGE", "POISON", "WOUND")):
        return "damage"
    if any(word in haystack for word in ("GIVE", "ITEM", "MONEY", "REWARD", "CREDIT")):
        return "reward"
    if any(word in haystack for word in ("TELEPORT", "LOAD MAP", "GEO", "LEAVE", "EXIT TO")):
        return "transition"
    if any(word in haystack for word in ("COMPARE", " IF ", "GOTO", "AND ", " OR ")):
        return "condition"
    if text:
        return "text"
    return "unknown"


def existing_wallsets(wall_texture_dir: Path | None) -> set[str]:
    if wall_texture_dir is None or not wall_texture_dir.exists():
        return set()
    wallsets = set()
    for path in wall_texture_dir.glob("walldef1_*_wall_01_view_00.png"):
        parts = path.name.split("_")
        if len(parts) >= 2:
            wallsets.add(parts[1])
    return wallsets


def choose_wall_texture_set(wallsets: dict[str, str], available: set[str]) -> str:
    for value in (wallsets.get("walldef_1"), wallsets.get("walldef_2"), wallsets.get("walldef_3")):
        if not value:
            continue
        try:
            key = f"{int(value):03d}"
        except ValueError:
            continue
        if key in available:
            return key
    return ""


def choose_surface_textures(wall_texture_dir: Path | None, wall_texture_set: str) -> dict[str, str]:
    if wall_texture_dir is None or not wall_texture_dir.exists() or not wall_texture_set:
        return {}
    candidates = {
        "ceiling": f"walldef1_{wall_texture_set}_wall_01_view_00.png",
        "floor": f"walldef1_{wall_texture_set}_wall_02_view_00.png",
    }
    return {kind: name for kind, name in candidates.items() if (wall_texture_dir / name).exists()}


def load_dialog_reference(path: Path | None) -> dict | None:
    if path is None or not path.exists():
        return None
    return json.loads(path.read_text(encoding="utf-8"))


def instruction_address(row: dict) -> int | None:
    try:
        return int(row.get("address"))
    except (TypeError, ValueError):
        return None


def parse_menu_labels(instructions: list[dict]) -> list[str]:
    labels: list[str] = []
    for row in instructions:
        match = MENU_BODY_RE.search(row.get("body", ""))
        if not match:
            continue
        for label in re.findall(r"'([^']+)'", match.group(1)):
            clean = label.strip()
            if clean and clean not in labels:
                labels.append(clean)
    return labels


def parse_on_goto_targets(instructions: list[dict]) -> list[dict]:
    branches: list[dict] = []
    for row in instructions:
        match = ON_GOTO_BODY_RE.search(row.get("body", ""))
        if not match:
            continue
        selector = match.group(1).strip()
        targets = []
        for value in match.group(2).split(","):
            value = value.strip()
            if not value:
                continue
            try:
                targets.append(int(value, 16))
            except ValueError:
                continue
        branches.append({"selector": selector, "targets": targets, "row": row.get("row", "")})
    return branches


def build_dialog_index(dialog_reference: dict | None) -> dict[int, dict[int, dict]]:
    if not dialog_reference:
        return {}
    attachments_by_owner: dict[tuple[int, int], list[dict]] = {}
    for attachment in dialog_reference.get("missing_text_attachments", []):
        try:
            key = (int(attachment["block_id"]), int(attachment["owner_target"]))
        except (KeyError, TypeError, ValueError):
            continue
        attachments_by_owner.setdefault(key, []).append(attachment)

    index: dict[int, dict[int, dict]] = {}
    for block_id_text, regions in (dialog_reference.get("branch_regions") or {}).items():
        try:
            block_id = int(block_id_text)
        except ValueError:
            continue
        for region in regions:
            try:
                target = int(region["target"])
            except (KeyError, TypeError, ValueError):
                continue
            instructions = region.get("instructions") or []
            attachments = attachments_by_owner.get((block_id, target), [])
            menu_labels = parse_menu_labels(instructions)
            if not menu_labels:
                menu_labels = []
                for attachment in attachments:
                    text = str(attachment.get("text", "")).strip()
                    if text and text not in menu_labels:
                        menu_labels.append(text)
            branches = parse_on_goto_targets(instructions)
            branch_targets = branches[0]["targets"] if branches else []
            choices = []
            for choice_index, label in enumerate(menu_labels):
                branch_target = branch_targets[choice_index] if choice_index < len(branch_targets) else None
                attachment = next((row for row in attachments if str(row.get("text", "")).strip() == label), None)
                choices.append(
                    {
                        "label": label,
                        "choiceIndex": choice_index,
                        "branchTarget": branch_target,
                        "branchTargetHex": f"0x{branch_target:04X}" if branch_target is not None else "",
                        "selector": branches[0]["selector"] if branches else "",
                        "evidence": attachment.get("previous_row") if attachment else (branches[0]["row"] if branches else ""),
                    }
                )
            if not choices and branches:
                for branch_index, branch_target in enumerate(branch_targets):
                    choices.append(
                        {
                            "label": f"Choice {branch_index + 1}",
                            "choiceIndex": branch_index,
                            "branchTarget": branch_target,
                            "branchTargetHex": f"0x{branch_target:04X}",
                            "selector": branches[0]["selector"],
                            "evidence": branches[0]["row"],
                        }
                    )
            if choices:
                index.setdefault(block_id, {})[target] = {
                    "status": "ecl_dialog_reference",
                    "target": target,
                    "targetHex": f"0x{target:04X}",
                    "incoming": region.get("incoming", []),
                    "summary": attachments[0].get("owner_summary", "") if attachments else "",
                    "choices": choices,
                }
    return index


def build_runtime_seed(
    maps: list[dict],
    wall_texture_dir: Path | None = None,
    wall_texture_base: str = "",
    pseudocode_dir: Path | None = None,
    structured_dir: Path | None = None,
    encounter_xref_json: Path | None = None,
    dialog_reference_json: Path | None = None,
) -> dict:
    available_wallsets = existing_wallsets(wall_texture_dir)
    dialog_index = build_dialog_index(load_dialog_reference(dialog_reference_json))
    encounters_by_ecl: dict[int, list[dict]] = {}
    if encounter_xref_json is not None and encounter_xref_json.exists():
        for row in json.loads(encounter_xref_json.read_text(encoding="utf-8")):
            encounters_by_ecl.setdefault(int(row["ecl_block"]), []).append(row)
    seed_maps = []
    for item in maps:
        wallsets = item.get("wallsets") or {}
        atlas = item.get("atlas") or {}
        events = atlas.get("events") or {}
        pseudocode_sections = read_event_sections(find_prefixed_path(pseudocode_dir, item["id"]))
        structured_sections = read_event_sections(find_prefixed_path(structured_dir, item["id"]))
        ecl_block = atlas.get("ecl_block")
        encounter_rows = encounters_by_ecl.get(int(ecl_block), []) if ecl_block is not None else []
        wall_texture_set = choose_wall_texture_set(wallsets, available_wallsets)
        seed_maps.append(
            {
                "id": item["id"],
                "name": item["name"],
                "eclBlock": ecl_block,
                "wallsets": [
                    value
                    for value in (wallsets.get("walldef_1"), wallsets.get("walldef_2"), wallsets.get("walldef_3"))
                    if value
                ],
                "wallTextureSet": wall_texture_set,
                "surfaceTextures": choose_surface_textures(wall_texture_dir, wall_texture_set),
                "cells": [
                    {
                        "row": cell["row"],
                        "col": cell["col"],
                        "walls": [cell["north"], cell["east"], cell["south"], cell["west"]],
                        "eventId": cell["event_id"],
                        "eventFlag": cell["event_flag"],
                        "door": cell["door"],
                    }
                    for cell in item["cells"]
                ],
                "events": {
                    event_id: {
                        "target": event.get("target"),
                        "text": event.get("text", ""),
                        "type": classify_event(event.get("text", ""), structured_sections.get(str(int(event_id)), "") or pseudocode_sections.get(str(int(event_id)), "")),
                        "pseudocode": pseudocode_sections.get(str(int(event_id)), ""),
                        "structured": structured_sections.get(str(int(event_id)), ""),
                        "dialog": dialog_index.get(int(ecl_block), {}).get(int(event.get("target")))
                        if ecl_block is not None and event.get("target") is not None
                        else None,
                        "encounters": event_encounters(
                            encounter_rows,
                            structured_sections.get(str(int(event_id)), ""),
                            pseudocode_sections.get(str(int(event_id)), ""),
                        ),
                    }
                    for event_id, event in events.items()
                },
            }
        )
    return {"maps": seed_maps, "wallTextureBase": wall_texture_base}


def event_encounters(rows: list[dict], structured: str, pseudocode: str) -> list[dict]:
    haystack = f"{structured}\n{pseudocode}"
    matches = []
    seen: set[tuple[str, str, str]] = set()
    for row in rows:
        address = row.get("address", "")
        if not address or address not in haystack:
            continue
        monster = row.get("monster") or {}
        key = (address, row.get("kind", ""), str(row.get("monster_ref", "")))
        if key in seen:
            continue
        seen.add(key)
        matches.append(
            {
                "address": address,
                "kind": row.get("kind"),
                "resolution": row.get("resolution"),
                "monsterId": row.get("monster_id"),
                "monsterRef": row.get("monster_ref"),
                "monsterName": monster.get("name"),
                "maxDistance": row.get("max_distance"),
                "copies": row.get("copies"),
                "picRef": row.get("pic_ref"),
                "stats": monster.get("stats"),
                "candidateFields": monster.get("matrix_variant_candidates"),
                "candidateResolution": row.get("candidate_resolution"),
            }
        )
    return matches


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("maps_json", type=Path)
    parser.add_argument("event_atlas_json", type=Path)
    parser.add_argument("wallsets_tsv", type=Path)
    parser.add_argument("asset_dir", type=Path)
    parser.add_argument("out_html", type=Path)
    parser.add_argument("--structured-dir", type=Path)
    parser.add_argument("--pseudocode-dir", type=Path)
    parser.add_argument("--runtime-json", type=Path)
    parser.add_argument("--playable-html", type=Path)
    parser.add_argument("--wall-texture-dir", type=Path)
    parser.add_argument("--encounter-xref-json", type=Path)
    parser.add_argument("--dialog-reference-json", type=Path)
    args = parser.parse_args()

    maps = json.loads(args.maps_json.read_text(encoding="utf-8"))
    atlas = json.loads(args.event_atlas_json.read_text(encoding="utf-8"))
    wallsets = read_wallsets(args.wallsets_tsv)
    assets = collect_assets(args.asset_dir)

    atlas_by_geo = {item["geo_id"]: item for item in atlas}
    for item in maps:
        item["atlas"] = atlas_by_geo.get(item["id"], {})
        item["wallsets"] = wallsets.get(item["id"], {})
        item["structuredUrl"] = find_prefixed_file(args.structured_dir, item["id"])
        item["pseudocodeUrl"] = find_prefixed_file(args.pseudocode_dir, item["id"])

    payload = {
        "maps": maps,
        "assets": assets,
        "assetGallery": (args.asset_dir / "index.html").as_uri() if (args.asset_dir / "index.html").exists() else "",
    }

    wall_texture_base = ""
    if args.wall_texture_dir and args.wall_texture_dir.exists():
        wall_texture_base = os.path.relpath(args.wall_texture_dir.resolve(), args.out_html.parent.resolve()).replace(os.sep, "/")
    runtime_seed = build_runtime_seed(
        maps,
        args.wall_texture_dir,
        wall_texture_base,
        args.pseudocode_dir,
        args.structured_dir,
        args.encounter_xref_json,
        args.dialog_reference_json,
    )
    if args.runtime_json is not None:
        args.runtime_json.parent.mkdir(parents=True, exist_ok=True)
        args.runtime_json.write_text(json.dumps(runtime_seed, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")

    html = HTML_TEMPLATE.replace("__PAYLOAD__", json.dumps(payload, ensure_ascii=False))
    args.out_html.parent.mkdir(parents=True, exist_ok=True)
    args.out_html.write_text(html, encoding="utf-8")

    if args.playable_html is not None:
        playable_html = PLAYABLE_TEMPLATE.replace("__RUNTIME_SEED__", json.dumps(runtime_seed, ensure_ascii=False))
        args.playable_html.parent.mkdir(parents=True, exist_ok=True)
        args.playable_html.write_text(playable_html, encoding="utf-8")
    return 0


HTML_TEMPLATE = r"""<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Matrix Cubed Map Viewer</title>
  <style>
    :root {
      color-scheme: dark;
      --bg: #101214;
      --panel: #181b1e;
      --panel-2: #20252a;
      --line: #3d454d;
      --line-2: #59636e;
      --text: #e8ecef;
      --muted: #a9b2bb;
      --accent: #58c4a2;
      --event: #f4c95d;
      --door: #da7b55;
      --cell: #262b30;
      --cell-alt: #22272c;
      --focus: #8ed0ff;
    }
    * { box-sizing: border-box; }
    body {
      margin: 0;
      min-height: 100vh;
      background: var(--bg);
      color: var(--text);
      font: 14px/1.4 system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
    }
    header {
      height: 56px;
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 16px;
      padding: 0 18px;
      border-bottom: 1px solid var(--line);
      background: #14171a;
    }
    h1 {
      margin: 0;
      font-size: 18px;
      font-weight: 650;
      letter-spacing: 0;
    }
    main {
      display: grid;
      grid-template-columns: 260px minmax(460px, 1fr) 340px;
      min-height: calc(100vh - 56px);
    }
    aside, section {
      min-width: 0;
    }
    .left, .right {
      background: var(--panel);
      border-right: 1px solid var(--line);
      overflow: auto;
      max-height: calc(100vh - 56px);
    }
    .right {
      border-right: 0;
      border-left: 1px solid var(--line);
    }
    .center {
      display: grid;
      grid-template-rows: minmax(0, 1fr) 150px;
      min-height: calc(100vh - 56px);
      background: #121518;
    }
    .map-list {
      display: grid;
      gap: 4px;
      padding: 10px;
    }
    .map-button {
      appearance: none;
      border: 1px solid transparent;
      background: transparent;
      color: var(--text);
      border-radius: 6px;
      padding: 8px 10px;
      text-align: left;
      cursor: pointer;
      display: grid;
      gap: 2px;
    }
    .map-button:hover { background: var(--panel-2); }
    .map-button.active {
      border-color: var(--accent);
      background: #1b2c28;
    }
    .map-id { color: var(--muted); font-size: 12px; }
    .toolbar {
      display: flex;
      align-items: center;
      gap: 10px;
      min-width: 0;
    }
    select {
      min-width: 220px;
      max-width: 44vw;
      background: var(--panel-2);
      color: var(--text);
      border: 1px solid var(--line);
      border-radius: 6px;
      padding: 7px 10px;
    }
    .stat {
      color: var(--muted);
      white-space: nowrap;
      font-size: 13px;
    }
    .canvas-wrap {
      display: grid;
      place-items: center;
      min-height: 0;
      padding: 18px;
    }
    canvas {
      width: min(78vh, 100%);
      max-width: 760px;
      aspect-ratio: 1 / 1;
      image-rendering: pixelated;
      border: 1px solid var(--line);
      background: var(--cell);
    }
    .asset-strip {
      border-top: 1px solid var(--line);
      background: #15191c;
      overflow-x: auto;
      display: flex;
      gap: 10px;
      align-items: center;
      padding: 12px;
    }
    .thumb {
      width: 108px;
      height: 112px;
      flex: 0 0 auto;
      display: grid;
      grid-template-rows: 84px 1fr;
      gap: 6px;
      color: var(--muted);
      font-size: 11px;
    }
    .thumb img {
      max-width: 108px;
      max-height: 84px;
      object-fit: contain;
      image-rendering: pixelated;
      background: #08090a;
      border: 1px solid var(--line);
    }
    .thumb span {
      overflow: hidden;
      text-overflow: ellipsis;
      white-space: nowrap;
      min-width: 0;
    }
    .panel {
      padding: 14px;
      border-bottom: 1px solid var(--line);
    }
    h2 {
      margin: 0 0 10px;
      font-size: 14px;
      font-weight: 650;
      color: var(--text);
    }
    .kv {
      display: grid;
      grid-template-columns: 92px 1fr;
      gap: 6px 10px;
      color: var(--muted);
      font-size: 13px;
    }
    .kv strong {
      color: var(--text);
      font-weight: 550;
    }
    .events {
      display: grid;
      gap: 8px;
    }
    .event {
      border: 1px solid var(--line);
      border-radius: 6px;
      padding: 8px;
      background: #15191c;
    }
    .event.active {
      border-color: var(--focus);
      background: #142331;
    }
    .event-title {
      color: var(--event);
      font-size: 12px;
      margin-bottom: 4px;
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 8px;
    }
    .event-links {
      display: inline-flex;
      gap: 8px;
      flex: 0 0 auto;
    }
    .event-text {
      color: var(--text);
      font-size: 12px;
      overflow-wrap: anywhere;
    }
    .cell-readout {
      color: var(--muted);
      min-height: 60px;
      font-size: 13px;
    }
    a { color: var(--focus); text-decoration: none; }
    a:hover { text-decoration: underline; }
    @media (max-width: 980px) {
      main { grid-template-columns: 1fr; }
      .left, .right { max-height: none; border: 0; border-bottom: 1px solid var(--line); }
      .center { min-height: 560px; }
      header { height: auto; min-height: 56px; flex-wrap: wrap; padding: 10px 12px; }
      select { max-width: 100%; min-width: 0; }
    }
  </style>
</head>
<body>
  <header>
    <h1>Matrix Cubed Map Viewer</h1>
    <div class="toolbar">
      <select id="mapSelect"></select>
      <span class="stat" id="mapStat"></span>
    </div>
  </header>
  <main>
    <aside class="left">
      <div class="map-list" id="mapList"></div>
    </aside>
    <section class="center">
      <div class="canvas-wrap">
        <canvas id="mapCanvas" width="768" height="768"></canvas>
      </div>
      <div class="asset-strip" id="assetStrip"></div>
    </section>
    <aside class="right">
      <div class="panel">
        <h2>Map</h2>
        <div class="kv" id="mapMeta"></div>
      </div>
      <div class="panel">
        <h2>Cell</h2>
        <div class="cell-readout" id="cellReadout">-</div>
      </div>
      <div class="panel">
        <h2>Events</h2>
        <div class="events" id="events"></div>
      </div>
    </aside>
  </main>
  <script>
    const DATA = __PAYLOAD__;
    const canvas = document.getElementById('mapCanvas');
    const ctx = canvas.getContext('2d');
    const mapList = document.getElementById('mapList');
    const mapSelect = document.getElementById('mapSelect');
    const mapMeta = document.getElementById('mapMeta');
    const eventsEl = document.getElementById('events');
    const cellReadout = document.getElementById('cellReadout');
    const mapStat = document.getElementById('mapStat');
    const assetStrip = document.getElementById('assetStrip');
    let currentIndex = 0;
    let selectedCell = null;
    let selectedEventId = null;

    function esc(value) {
      return String(value ?? '').replace(/[&<>"']/g, ch => ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[ch]));
    }

    function init() {
      DATA.maps.forEach((map, index) => {
        const option = document.createElement('option');
        option.value = index;
        option.textContent = `${String(map.id).padStart(3, '0')} ${map.name}`;
        mapSelect.appendChild(option);

        const button = document.createElement('button');
        button.className = 'map-button';
        button.innerHTML = `<span>${esc(map.name)}</span><span class="map-id">GEO ${String(map.id).padStart(3, '0')}</span>`;
        button.addEventListener('click', () => selectMap(index));
        mapList.appendChild(button);
      });
      mapSelect.addEventListener('change', event => selectMap(Number(event.target.value)));
      canvas.addEventListener('mousemove', event => handlePointer(event, false));
      canvas.addEventListener('click', event => handlePointer(event, true));
      renderAssets();
      selectMap(0);
    }

    function selectMap(index) {
      currentIndex = index;
      selectedCell = null;
      selectedEventId = null;
      mapSelect.value = String(index);
      [...mapList.children].forEach((button, i) => button.classList.toggle('active', i === index));
      render();
    }

    function render() {
      const map = DATA.maps[currentIndex];
      renderMapMeta(map);
      renderEvents(map);
      drawMap(map);
      cellReadout.textContent = '-';
      mapStat.textContent = `GEO ${String(map.id).padStart(3, '0')} / ${map.cells.length} cells`;
    }

    function renderMapMeta(map) {
      const wallsets = map.wallsets || {};
      const ecl = map.atlas?.ecl_block ?? wallsets.ecl_block ?? '';
      const values = [
        ['GEO', String(map.id).padStart(3, '0')],
        ['Name', map.name],
        ['ECL', ecl || '-'],
        ['Highest event', map.highest_event],
        ['Wallsets', [wallsets.walldef_1, wallsets.walldef_2, wallsets.walldef_3].filter(Boolean).join(', ') || '-'],
        ['Source', wallsets.source_addr || '-'],
      ];
      const links = [
        map.structuredUrl ? `<a href="${map.structuredUrl}">Structured</a>` : '',
        map.pseudocodeUrl ? `<a href="${map.pseudocodeUrl}">Pseudocode</a>` : '',
      ].filter(Boolean).join(' · ');
      mapMeta.innerHTML = values.map(([k, v]) => `<span>${esc(k)}</span><strong>${esc(v)}</strong>`).join('')
        + (links ? `<span>Files</span><strong>${links}</strong>` : '');
    }

    function renderEvents(map) {
      const events = map.atlas?.events || {};
      const rows = Object.entries(events).slice(0, 80);
      if (!rows.length) {
        eventsEl.innerHTML = '<div class="event"><div class="event-text">No decoded event text.</div></div>';
        return;
      }
      eventsEl.innerHTML = rows.map(([id, evt]) => `
        <div class="event ${String(selectedEventId) === String(id) ? 'active' : ''}" id="event-${esc(id)}" data-event-id="${esc(id)}">
          <div class="event-title">
            <span>Event ${esc(id)} · ${esc('0x' + Number(evt.target).toString(16).toUpperCase())}</span>
            <span class="event-links">${map.structuredUrl ? `<a href="${map.structuredUrl}">Structured</a>` : ''}</span>
          </div>
          <div class="event-text">${esc(evt.text || '')}</div>
        </div>
      `).join('');
      for (const node of eventsEl.querySelectorAll('.event[data-event-id]')) {
        node.addEventListener('click', () => {
          selectedEventId = node.dataset.eventId;
          const eventCell = DATA.maps[currentIndex].cells.find(c => String(c.event_id) === String(selectedEventId));
          if (eventCell) selectedCell = eventCell;
          renderEvents(DATA.maps[currentIndex]);
          drawMap(DATA.maps[currentIndex]);
          scrollSelectedEvent();
        });
      }
    }

    function drawMap(map) {
      const size = canvas.width;
      const cell = size / 16;
      ctx.clearRect(0, 0, size, size);
      for (const c of map.cells) {
        const x = c.col * cell;
        const y = c.row * cell;
        ctx.fillStyle = ((c.row + c.col) % 2) ? '#22272c' : '#262b30';
        ctx.fillRect(x, y, cell, cell);
        if (c.event_id) {
          const isSelectedEvent = String(c.event_id) === String(selectedEventId);
          ctx.fillStyle = isSelectedEvent ? 'rgba(142, 208, 255, 0.68)' : (c.event_flag ? 'rgba(244, 201, 93, 0.5)' : 'rgba(88, 196, 162, 0.36)');
          ctx.fillRect(x + 4, y + 4, cell - 8, cell - 8);
          ctx.fillStyle = '#101214';
          ctx.font = '18px system-ui';
          ctx.textAlign = 'center';
          ctx.textBaseline = 'middle';
          ctx.fillText(String(c.event_id), x + cell / 2, y + cell / 2);
        }
        if (c.door) {
          ctx.fillStyle = '#da7b55';
          ctx.fillRect(x + cell - 12, y + 5, 7, 7);
        }
        drawWalls(c, x, y, cell);
      }
      if (selectedCell) {
        ctx.strokeStyle = '#8ed0ff';
        ctx.lineWidth = 4;
        ctx.strokeRect(selectedCell.col * cell + 2, selectedCell.row * cell + 2, cell - 4, cell - 4);
      }
    }

    function wallColor(value) {
      if (!value) return null;
      if (value === 11) return '#e8ecef';
      if (value === 8) return '#58c4a2';
      return '#59636e';
    }

    function drawWalls(c, x, y, cell) {
      ctx.lineWidth = 4;
      const walls = [
        ['north', x, y, x + cell, y],
        ['east', x + cell, y, x + cell, y + cell],
        ['south', x, y + cell, x + cell, y + cell],
        ['west', x, y, x, y + cell],
      ];
      for (const [key, x1, y1, x2, y2] of walls) {
        const color = wallColor(c[key]);
        if (!color) continue;
        ctx.strokeStyle = color;
        ctx.beginPath();
        ctx.moveTo(x1, y1);
        ctx.lineTo(x2, y2);
        ctx.stroke();
      }
    }

    function handlePointer(event, selectEvent) {
      const rect = canvas.getBoundingClientRect();
      const scale = canvas.width / rect.width;
      const x = (event.clientX - rect.left) * scale;
      const y = (event.clientY - rect.top) * scale;
      const col = Math.max(0, Math.min(15, Math.floor(x / (canvas.width / 16))));
      const row = Math.max(0, Math.min(15, Math.floor(y / (canvas.height / 16))));
      const map = DATA.maps[currentIndex];
      const cell = map.cells.find(c => c.row === row && c.col === col);
      if (!cell) return;
      selectedCell = cell;
      if (selectEvent && cell.event_id) {
        selectedEventId = cell.event_id;
        renderEvents(map);
        scrollSelectedEvent();
      }
      cellReadout.innerHTML = `
        <div>Row <strong>${row}</strong>, Col <strong>${col}</strong></div>
        <div>Walls N/E/S/W: <strong>${cell.north}/${cell.east}/${cell.south}/${cell.west}</strong></div>
        <div>Event: <strong>${cell.event_id || '-'}</strong> ${cell.event_flag ? 'flagged' : ''}</div>
        <div>Door: <strong>${cell.door || '-'}</strong></div>
      `;
      drawMap(map);
    }

    function scrollSelectedEvent() {
      if (!selectedEventId) return;
      const node = document.getElementById(`event-${selectedEventId}`);
      if (node) node.scrollIntoView({ block: 'nearest' });
    }

    function renderAssets() {
      const gallery = DATA.assetGallery ? `<a href="${DATA.assetGallery}">Asset Gallery</a>` : '';
      assetStrip.innerHTML = DATA.assets.map(asset => `
        <div class="thumb"><img src="${asset.url}" alt=""><span>${esc(asset.name)}</span></div>
      `).join('') + (gallery ? `<div class="thumb"><span>${gallery}</span></div>` : '');
    }

    init();
  </script>
</body>
</html>
"""


PLAYABLE_TEMPLATE = r"""<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Matrix Cubed Runtime Prototype</title>
  <style>
    :root {
      color-scheme: dark;
      --bg: #0f1113;
      --panel: #181b1f;
      --panel-2: #20262b;
      --line: #3e474f;
      --muted: #aab3bc;
      --text: #eef2f4;
      --accent: #5ec3a1;
      --event: #f1c75b;
      --danger: #d97d5c;
      --focus: #8ccdf7;
      --cell-a: #252b30;
      --cell-b: #20262b;
    }
    * { box-sizing: border-box; }
    body {
      margin: 0;
      min-height: 100vh;
      background: var(--bg);
      color: var(--text);
      font: 14px/1.4 system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
    }
    header {
      min-height: 58px;
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 14px;
      padding: 10px 16px;
      border-bottom: 1px solid var(--line);
      background: #14171a;
    }
    h1 {
      margin: 0;
      font-size: 18px;
      font-weight: 650;
      letter-spacing: 0;
    }
    main {
      min-height: calc(100vh - 58px);
      display: grid;
      grid-template-columns: minmax(420px, 1fr) 360px;
    }
    .stage {
      display: grid;
      grid-template-rows: minmax(0, 1fr) auto;
      min-width: 0;
      background: #121518;
    }
    .view-wrap {
      min-height: 0;
      display: grid;
      grid-template-rows: minmax(240px, 1fr) 190px;
      gap: 14px;
      padding: 18px;
    }
    .viewport-shell, .map-shell {
      min-width: 0;
      display: grid;
      justify-items: center;
      gap: 8px;
    }
    .viewport-shell {
      align-content: center;
    }
    .map-shell {
      align-content: start;
    }
    .canvas-label {
      color: var(--muted);
      font-size: 12px;
      justify-self: stretch;
      max-width: 820px;
      display: flex;
      justify-content: space-between;
      gap: 10px;
    }
    #viewCanvas {
      width: min(68vw, 720px);
      max-width: 720px;
      aspect-ratio: 4 / 3;
      image-rendering: pixelated;
      border: 1px solid var(--line);
      background: #08090a;
    }
    #mapCanvas {
      width: min(30vh, 260px);
      max-width: 260px;
      aspect-ratio: 1 / 1;
      image-rendering: pixelated;
      border: 1px solid var(--line);
      background: var(--cell-a);
    }
    .controls {
      display: grid;
      grid-template-columns: minmax(220px, 1fr) auto auto auto;
      gap: 12px;
      align-items: center;
      padding: 12px 16px;
      border-top: 1px solid var(--line);
      background: #15191c;
    }
    select, button {
      min-height: 36px;
      background: var(--panel-2);
      color: var(--text);
      border: 1px solid var(--line);
      border-radius: 6px;
      padding: 7px 10px;
      font: inherit;
    }
    button {
      cursor: pointer;
      min-width: 40px;
    }
    button:hover { border-color: var(--focus); }
    .pad {
      display: grid;
      grid-template-columns: 40px 40px 40px;
      gap: 5px;
      justify-content: end;
    }
    .pad .up { grid-column: 2; }
    .pad .left { grid-column: 1; }
    .pad .down { grid-column: 2; }
    .pad .right { grid-column: 3; grid-row: 2; }
    .toggle {
      display: inline-flex;
      gap: 8px;
      align-items: center;
      color: var(--muted);
      white-space: nowrap;
      user-select: none;
    }
    .toggle input { width: 18px; height: 18px; }
    .mode {
      display: inline-grid;
      grid-template-columns: auto auto;
      border: 1px solid var(--line);
      border-radius: 6px;
      overflow: hidden;
    }
    .mode button {
      min-width: 74px;
      border: 0;
      border-radius: 0;
      background: transparent;
    }
    .mode button.active {
      background: #20322e;
      color: var(--accent);
    }
    aside {
      min-width: 0;
      border-left: 1px solid var(--line);
      background: var(--panel);
      max-height: calc(100vh - 58px);
      overflow: auto;
    }
    .panel {
      padding: 14px;
      border-bottom: 1px solid var(--line);
    }
    h2 {
      margin: 0 0 10px;
      font-size: 14px;
      font-weight: 650;
    }
    .kv {
      display: grid;
      grid-template-columns: 98px 1fr;
      gap: 7px 10px;
      color: var(--muted);
      font-size: 13px;
    }
    .kv strong {
      color: var(--text);
      font-weight: 550;
      overflow-wrap: anywhere;
    }
    .event-box {
      min-height: 128px;
      padding: 10px;
      border: 1px solid var(--line);
      border-radius: 6px;
      background: #14181b;
      color: var(--text);
      overflow-wrap: anywhere;
    }
    .event-title {
      color: var(--event);
      font-size: 12px;
      margin-bottom: 6px;
    }
    .event-type {
      display: inline-block;
      margin: 0 0 8px;
      padding: 2px 7px;
      border: 1px solid var(--line);
      border-radius: 999px;
      color: var(--accent);
      font-size: 12px;
      line-height: 1.4;
    }
    .event-actions {
      display: flex;
      flex-wrap: wrap;
      gap: 8px;
      margin: 10px 0;
    }
    .event-actions button {
      min-width: 0;
      min-height: 32px;
      font-size: 12px;
    }
    .encounter-list {
      display: grid;
      gap: 6px;
      margin: 8px 0 10px;
    }
    .encounter-row {
      padding: 7px 8px;
      border: 1px solid var(--line);
      border-radius: 6px;
      background: #111518;
      font-size: 12px;
    }
    .encounter-row strong {
      color: var(--text);
      font-weight: 650;
    }
    .encounter-row span {
      color: var(--muted);
    }
    details {
      margin-top: 10px;
      border-top: 1px solid var(--line);
      padding-top: 8px;
    }
    summary {
      cursor: pointer;
      color: var(--focus);
      font-size: 12px;
      margin-bottom: 8px;
    }
    pre {
      max-height: 260px;
      overflow: auto;
      margin: 0;
      padding: 10px;
      border-radius: 6px;
      background: #0c0f11;
      color: #dbe3e8;
      white-space: pre-wrap;
      overflow-wrap: anywhere;
      font: 12px/1.45 ui-monospace, SFMono-Regular, Menlo, Consolas, monospace;
    }
    .log {
      display: grid;
      gap: 8px;
      max-height: 340px;
      overflow: auto;
    }
    .log-row {
      border: 1px solid var(--line);
      border-radius: 6px;
      padding: 8px;
      background: #14181b;
      font-size: 12px;
    }
    .muted { color: var(--muted); }
    @media (max-width: 940px) {
      main { grid-template-columns: 1fr; }
      aside { max-height: none; border-left: 0; border-top: 1px solid var(--line); }
      .controls { grid-template-columns: 1fr; }
      .view-wrap { grid-template-rows: auto auto; padding: 12px; }
      #mapCanvas { width: min(86vw, 320px); }
      .pad { justify-content: center; }
      header { align-items: flex-start; flex-direction: column; }
    }
  </style>
</head>
<body>
  <header>
    <h1>Matrix Cubed Runtime Prototype</h1>
    <div class="muted" id="headerStatus"></div>
  </header>
  <main>
    <section class="stage">
      <div class="view-wrap">
        <div class="viewport-shell">
          <div class="canvas-label"><span>First-person view</span><span id="viewStatus"></span></div>
          <canvas id="viewCanvas" width="640" height="480"></canvas>
        </div>
        <div class="map-shell">
          <div class="canvas-label"><span>Tactical map</span><span>debug view</span></div>
          <canvas id="mapCanvas" width="512" height="512"></canvas>
        </div>
      </div>
      <div class="controls">
        <select id="mapSelect"></select>
        <label class="toggle"><input type="checkbox" id="wallToggle"> wall blocking</label>
        <div class="mode" aria-label="Movement mode">
          <button type="button" id="turnMode" class="active">turn</button>
          <button type="button" id="strafeMode">strafe</button>
        </div>
        <div class="pad" aria-label="Movement controls">
          <button class="up" type="button" data-action="forward" title="Move forward">↑</button>
          <button class="left" type="button" data-action="left" title="Turn or strafe left">←</button>
          <button class="down" type="button" data-action="back" title="Move backward">↓</button>
          <button class="right" type="button" data-action="right" title="Turn or strafe right">→</button>
        </div>
      </div>
    </section>
    <aside>
      <div class="panel">
        <h2>State</h2>
        <div class="kv" id="stateMeta"></div>
      </div>
      <div class="panel">
        <h2>Current Event</h2>
        <div class="event-box" id="eventBox"></div>
      </div>
      <div class="panel">
        <h2>Event Log</h2>
        <div class="log" id="eventLog"></div>
      </div>
    </aside>
  </main>
  <script>
    const DATA = __RUNTIME_SEED__;
    const mapCanvas = document.getElementById('mapCanvas');
    const mapCtx = mapCanvas.getContext('2d');
    const viewCanvas = document.getElementById('viewCanvas');
    const viewCtx = viewCanvas.getContext('2d');
    const mapSelect = document.getElementById('mapSelect');
    const wallToggle = document.getElementById('wallToggle');
    const turnMode = document.getElementById('turnMode');
    const strafeMode = document.getElementById('strafeMode');
    const stateMeta = document.getElementById('stateMeta');
    const eventBox = document.getElementById('eventBox');
    const eventLog = document.getElementById('eventLog');
    const headerStatus = document.getElementById('headerStatus');
    const viewStatus = document.getElementById('viewStatus');

    const state = {
      mapIndex: findDefaultMapIndex(),
      row: 0,
      col: 0,
      facing: 'south',
      movementMode: 'turn',
      steps: 0,
      activeEventId: null,
      partyHp: 100,
      credits: 0,
      inventory: [],
      flags: [],
      activeEncounter: null,
      log: [],
    };
    const textureCache = new Map();

    function esc(value) {
      return String(value ?? '').replace(/[&<>"']/g, ch => ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[ch]));
    }

    function findDefaultMapIndex() {
      const eventMap = DATA.maps.findIndex(map => Object.keys(map.events || {}).length > 0);
      return eventMap >= 0 ? eventMap : 0;
    }

    function cellAt(map, row, col) {
      return map.cells.find(cell => cell.row === row && cell.col === col);
    }

    function currentMap() {
      return DATA.maps[state.mapIndex];
    }

    function firstOpenCell(map) {
      return map.cells.find(cell => cell.eventId) || map.cells.find(cell => cell.row > 0 && cell.col > 0) || map.cells[0];
    }

    function init() {
      DATA.maps.forEach((map, index) => {
        const option = document.createElement('option');
        option.value = index;
        option.textContent = `${String(map.id).padStart(3, '0')} ${map.name}`;
        mapSelect.appendChild(option);
      });
      mapSelect.addEventListener('change', () => selectMap(Number(mapSelect.value)));
      wallToggle.addEventListener('change', render);
      turnMode.addEventListener('click', () => setMovementMode('turn'));
      strafeMode.addEventListener('click', () => setMovementMode('strafe'));
      document.querySelectorAll('button[data-action]').forEach(button => {
        button.addEventListener('click', () => performAction(button.dataset.action));
      });
      window.addEventListener('keydown', event => {
        const key = event.key.toLowerCase();
        const actions = {
          arrowup: 'forward',
          w: 'forward',
          arrowdown: 'back',
          s: 'back',
          arrowleft: 'left',
          a: 'left',
          arrowright: 'right',
          d: 'right',
          q: 'turnLeft',
          e: 'turnRight',
        };
        if (!actions[key]) return;
        event.preventDefault();
        performAction(actions[key]);
      });
      selectMap(state.mapIndex);
    }

    function setMovementMode(mode) {
      state.movementMode = mode;
      turnMode.classList.toggle('active', mode === 'turn');
      strafeMode.classList.toggle('active', mode === 'strafe');
      render();
    }

    function selectMap(index) {
      state.mapIndex = index;
      const start = firstOpenCell(currentMap());
      state.row = start?.row ?? 0;
      state.col = start?.col ?? 0;
      state.activeEventId = null;
      state.steps = 0;
      state.log = [];
      mapSelect.value = String(index);
      triggerCurrentCell('entered map');
      render();
    }

    function directionFor(dx, dy) {
      if (dx === 1) return 'east';
      if (dx === -1) return 'west';
      if (dy === -1) return 'north';
      return 'south';
    }

    function wallIndex(direction) {
      return { north: 0, east: 1, south: 2, west: 3 }[direction];
    }

    function vectorFor(direction) {
      return {
        north: [0, -1],
        east: [1, 0],
        south: [0, 1],
        west: [-1, 0],
      }[direction];
    }

    function leftOf(direction) {
      return { north: 'west', west: 'south', south: 'east', east: 'north' }[direction];
    }

    function rightOf(direction) {
      return { north: 'east', east: 'south', south: 'west', west: 'north' }[direction];
    }

    function oppositeOf(direction) {
      return { north: 'south', south: 'north', east: 'west', west: 'east' }[direction];
    }

    function turn(side) {
      state.facing = side === 'left' ? leftOf(state.facing) : rightOf(state.facing);
      render();
    }

    function performAction(action) {
      if (action === 'turnLeft') return turn('left');
      if (action === 'turnRight') return turn('right');
      if (action === 'left' && state.movementMode === 'turn') return turn('left');
      if (action === 'right' && state.movementMode === 'turn') return turn('right');

      let direction = state.facing;
      if (action === 'back') direction = oppositeOf(state.facing);
      if (action === 'left') direction = leftOf(state.facing);
      if (action === 'right') direction = rightOf(state.facing);
      const [dx, dy] = vectorFor(direction);
      move(dx, dy, direction);
    }

    function move(dx, dy, explicitDirection = null) {
      const direction = explicitDirection || directionFor(dx, dy);
      const map = currentMap();
      const nextRow = Math.max(0, Math.min(15, state.row + dy));
      const nextCol = Math.max(0, Math.min(15, state.col + dx));
      if (nextRow === state.row && nextCol === state.col) {
        render();
        return;
      }
      if (wallToggle.checked && isBlocked(map, direction, nextRow, nextCol)) {
        addLog(`Blocked ${direction}`, cellAt(map, state.row, state.col));
        render();
        return;
      }
      state.row = nextRow;
      state.col = nextCol;
      state.steps += 1;
      triggerCurrentCell('step');
      render();
    }

    function isBlocked(map, direction, nextRow, nextCol) {
      const here = cellAt(map, state.row, state.col);
      const there = cellAt(map, nextRow, nextCol);
      if (!here || !there) return true;
      const opposite = { north: 'south', south: 'north', east: 'west', west: 'east' }[direction];
      return Boolean(here.walls[wallIndex(direction)] || there.walls[wallIndex(opposite)]);
    }

    function triggerCurrentCell(reason) {
      const map = currentMap();
      const cell = cellAt(map, state.row, state.col);
      const eventId = cell?.eventId ? String(cell.eventId) : null;
      state.activeEventId = eventId;
      if (eventId) addLog(`${reason}: event ${eventId}`, cell);
    }

    function addLog(label, cell) {
      const map = currentMap();
      const eventId = cell?.eventId ? String(cell.eventId) : null;
      const event = eventId ? map.events[eventId] : null;
      const text = event?.text || '';
      const last = state.log[0];
      const signature = `${map.id}:${state.row}:${state.col}:${label}:${text}`;
      if (last?.signature === signature) return;
      state.log.unshift({
        signature,
        label,
        map: map.name,
        geo: map.id,
        row: state.row,
        col: state.col,
        eventId,
        text,
      });
      state.log = state.log.slice(0, 24);
    }

    function executeCurrentEvent() {
      const map = currentMap();
      const cell = cellAt(map, state.row, state.col);
      if (!cell?.eventId) return;
      const eventId = String(cell.eventId);
      const event = map.events[eventId] || {};
      const type = event.type || 'unknown';
      if (type === 'combat') {
        const monsters = encounterNames(event);
        state.activeEncounter = `GEO ${String(map.id).padStart(3, '0')} event ${eventId}${monsters ? `: ${monsters}` : ''}`;
        addLog(`Combat placeholder queued for event ${eventId}${monsters ? ` (${monsters})` : ''}`, cell);
      } else if (type === 'reward') {
        state.credits += 100;
        addInventory(`event ${eventId} reward placeholder`);
        addLog(`Reward placeholder applied for event ${eventId}`, cell);
      } else if (type === 'damage') {
        state.partyHp = Math.max(0, state.partyHp - 10);
        addLog(`Damage placeholder applied for event ${eventId}`, cell);
      } else if (type === 'transition') {
        addFlag(`transition:${map.id}:${eventId}`);
        addLog(`Transition candidate marked for event ${eventId}`, cell);
      } else if (type === 'condition') {
        addFlag(`checked:${map.id}:${eventId}`);
        addLog(`Condition placeholder evaluated for event ${eventId}`, cell);
      } else if (type === 'text') {
        addLog(`Dialogue displayed for event ${eventId}`, cell);
      } else {
        addLog(`Unknown event behavior inspected for event ${eventId}`, cell);
      }
      render();
    }

    function executeDialogChoice(eventId, choiceIndex) {
      const map = currentMap();
      const cell = cellAt(map, state.row, state.col);
      const event = map.events[String(eventId)] || {};
      const dialog = event.dialog || {};
      const choice = (dialog.choices || [])[choiceIndex];
      if (!choice) return;
      addFlag(`dialog:${map.id}:${eventId}:${choice.choiceIndex}`);
      const branch = choice.branchTargetHex ? ` -> ${choice.branchTargetHex}` : '';
      addLog(`Dialog choice: ${choice.label}${branch}`, cell);
      state.lastDialog = {
        map: map.id,
        eventId: String(eventId),
        label: choice.label,
        branchTargetHex: choice.branchTargetHex || '',
        evidence: choice.evidence || '',
      };
      render();
    }

    function encounterNames(event) {
      const names = (event?.encounters || [])
        .map(row => row.monsterName || candidateNames(row) || (row.monsterRef ? `dynamic ${row.monsterRef}` : 'unknown'))
        .filter(Boolean);
      return [...new Set(names)].join(', ');
    }

    function candidateNames(row) {
      const candidates = row.candidateResolution?.candidate_monsters || [];
      if (!candidates.length) return '';
      return candidates.map(monster => monster.name || `id ${monster.id}`).join(' / ');
    }

    function addInventory(item) {
      if (!state.inventory.includes(item)) state.inventory.push(item);
      state.inventory = state.inventory.slice(-8);
    }

    function addFlag(flag) {
      if (!state.flags.includes(flag)) state.flags.push(flag);
      state.flags = state.flags.slice(-10);
    }

    function drawSurfaceFallback(kind, y, height) {
      const gradient = kind === 'ceiling'
        ? viewCtx.createLinearGradient(0, 0, 0, height)
        : viewCtx.createLinearGradient(0, y, 0, y + height);
      if (kind === 'ceiling') {
        gradient.addColorStop(0, '#0b0d10');
        gradient.addColorStop(1, '#192025');
      } else {
        gradient.addColorStop(0, '#22272b');
        gradient.addColorStop(1, '#0d0f11');
      }
      viewCtx.fillStyle = gradient;
      viewCtx.fillRect(0, y, viewCanvas.width, height);
    }

    function drawSurface(kind, y, height) {
      const texture = surfaceTexture(kind);
      if (texture?.complete && texture.naturalWidth) {
        viewCtx.save();
        viewCtx.imageSmoothingEnabled = false;
        const pattern = viewCtx.createPattern(texture, 'repeat');
        if (pattern) {
          viewCtx.fillStyle = pattern;
          viewCtx.translate(0, y);
          viewCtx.fillRect(0, 0, viewCanvas.width, height);
        } else {
          drawSurfaceFallback(kind, y, height);
        }
        viewCtx.restore();
        if (kind === 'floor') {
          const shade = viewCtx.createLinearGradient(0, y, 0, y + height);
          shade.addColorStop(0, 'rgba(255,255,255,0.12)');
          shade.addColorStop(1, 'rgba(0,0,0,0.42)');
          viewCtx.fillStyle = shade;
          viewCtx.fillRect(0, y, viewCanvas.width, height);
        } else {
          viewCtx.fillStyle = 'rgba(0,0,0,0.22)';
          viewCtx.fillRect(0, y, viewCanvas.width, height);
        }
        return;
      }
      drawSurfaceFallback(kind, y, height);
    }

    function render() {
      drawViewport();
      drawMap();
      renderState();
      renderEvent();
      renderLog();
    }

    function projectedRects() {
      return [
        { x: 24, y: 34, w: 592, h: 412 },
        { x: 112, y: 88, w: 416, h: 304 },
        { x: 196, y: 140, w: 248, h: 204 },
        { x: 268, y: 188, w: 104, h: 108 },
        { x: 308, y: 224, w: 24, h: 32 },
      ];
    }

    function stepCell(row, col, direction, distance = 1) {
      const [dx, dy] = vectorFor(direction);
      return { row: row + dy * distance, col: col + dx * distance };
    }

    function isInside(row, col) {
      return row >= 0 && row < 16 && col >= 0 && col < 16;
    }

    function wallValueAt(map, row, col, direction) {
      if (!isInside(row, col)) return 11;
      const cell = cellAt(map, row, col);
      return cell ? cell.walls[wallIndex(direction)] : 11;
    }

    function drawViewport() {
      const map = currentMap();
      const w = viewCanvas.width;
      const h = viewCanvas.height;
      const rects = projectedRects();
      viewCtx.clearRect(0, 0, w, h);

      drawSurface('ceiling', 0, h / 2);
      drawSurface('floor', h / 2, h / 2);

      viewCtx.strokeStyle = '#39434c';
      viewCtx.lineWidth = 2;
      for (let i = 0; i < rects.length - 1; i += 1) {
        drawPerspectiveFrame(rects[i], rects[i + 1]);
      }

      let blockedAt = null;
      for (let depth = 0; depth < rects.length - 1; depth += 1) {
        const here = stepCell(state.row, state.col, state.facing, depth);
        if (!isInside(here.row, here.col)) {
          blockedAt = depth;
          drawFrontWall(rects[depth], 11, depth);
          break;
        }
        const cell = cellAt(map, here.row, here.col);
        const left = leftOf(state.facing);
        const right = rightOf(state.facing);
        if (wallValueAt(map, here.row, here.col, left)) {
          drawSideWall(rects[depth], rects[depth + 1], 'left', wallValueAt(map, here.row, here.col, left), depth);
        }
        if (wallValueAt(map, here.row, here.col, right)) {
          drawSideWall(rects[depth], rects[depth + 1], 'right', wallValueAt(map, here.row, here.col, right), depth);
        }
        drawCellMarker(cell, rects[depth], rects[depth + 1], depth);
        const frontWall = wallValueAt(map, here.row, here.col, state.facing);
        if (frontWall) {
          blockedAt = depth;
          drawFrontWall(rects[depth + 1], frontWall, depth);
          break;
        }
      }

      drawViewportHud(blockedAt);
    }

    function drawPerspectiveFrame(near, far) {
      viewCtx.strokeStyle = '#303942';
      viewCtx.lineWidth = 1.5;
      viewCtx.strokeRect(far.x, far.y, far.w, far.h);
      for (const [x1, y1, x2, y2] of [
        [near.x, near.y, far.x, far.y],
        [near.x + near.w, near.y, far.x + far.w, far.y],
        [near.x, near.y + near.h, far.x, far.y + far.h],
        [near.x + near.w, near.y + near.h, far.x + far.w, far.y + far.h],
      ]) {
        viewCtx.beginPath();
        viewCtx.moveTo(x1, y1);
        viewCtx.lineTo(x2, y2);
        viewCtx.stroke();
      }
    }

    function viewWallColor(value, depth) {
      const shade = Math.max(0, 38 - depth * 6);
      if (value === 8) return `rgb(${60 - depth * 6}, ${120 - depth * 8}, ${102 - depth * 6})`;
      if (value === 11) return `rgb(${92 - depth * 8}, ${101 - depth * 8}, ${110 - depth * 8})`;
      if (value >= 12) return `rgb(${80 - depth * 7}, ${72 - depth * 6}, ${64 - depth * 5})`;
      return `rgb(${shade + 24}, ${shade + 30}, ${shade + 36})`;
    }

    function drawPolygon(points, fill, stroke = '#9aa7b2') {
      viewCtx.fillStyle = fill;
      viewCtx.strokeStyle = stroke;
      viewCtx.lineWidth = 2;
      viewCtx.beginPath();
      points.forEach(([x, y], index) => {
        if (index === 0) viewCtx.moveTo(x, y);
        else viewCtx.lineTo(x, y);
      });
      viewCtx.closePath();
      viewCtx.fill();
      viewCtx.stroke();
    }

    function drawSideWall(near, far, side, value, depth) {
      const points = side === 'left'
        ? [[near.x, near.y], [far.x, far.y], [far.x, far.y + far.h], [near.x, near.y + near.h]]
        : [[near.x + near.w, near.y], [far.x + far.w, far.y], [far.x + far.w, far.y + far.h], [near.x + near.w, near.y + near.h]];
      const viewId = textureViewForSide(side, depth);
      const texture = wallTexture(value, viewId);
      if (texture?.complete && texture.naturalWidth) {
        drawTexturedPolygon(points, texture, near, side);
      } else {
        drawPolygon(points, viewWallColor(value, depth), '#aab3bc');
      }
    }

    function drawFrontWall(rect, value, depth) {
      const inset = Math.max(0, 4 - depth);
      const texture = wallTexture(value, textureViewForFront(depth));
      if (texture?.complete && texture.naturalWidth) {
        viewCtx.imageSmoothingEnabled = false;
        viewCtx.drawImage(texture, rect.x + inset, rect.y + inset, rect.w - inset * 2, rect.h - inset * 2);
      } else {
        viewCtx.fillStyle = viewWallColor(value, depth);
        viewCtx.fillRect(rect.x + inset, rect.y + inset, rect.w - inset * 2, rect.h - inset * 2);
      }
      viewCtx.strokeStyle = '#c3ccd4';
      viewCtx.lineWidth = 2;
      viewCtx.strokeRect(rect.x + inset, rect.y + inset, rect.w - inset * 2, rect.h - inset * 2);
      viewCtx.strokeStyle = 'rgba(255,255,255,0.18)';
      viewCtx.beginPath();
      viewCtx.moveTo(rect.x + inset, rect.y + inset);
      viewCtx.lineTo(rect.x + rect.w - inset, rect.y + rect.h - inset);
      viewCtx.moveTo(rect.x + rect.w - inset, rect.y + inset);
      viewCtx.lineTo(rect.x + inset, rect.y + rect.h - inset);
      viewCtx.stroke();
    }

    function textureViewForSide(side, depth) {
      if (depth <= 0) return side === 'left' ? 7 : 8;
      if (depth === 1) return side === 'left' ? 4 : 5;
      if (depth === 2) return side === 'left' ? 0 : 2;
      return side === 'left' ? 0 : 2;
    }

    function textureViewForFront(depth) {
      return [6, 3, 1, 9][Math.min(depth, 3)];
    }

    function wallTexture(wallValue, viewId) {
      const map = currentMap();
      if (!DATA.wallTextureBase || !map.wallTextureSet || !wallValue) return null;
      const wall = Math.max(1, Math.min(15, Number(wallValue)));
      const key = `${map.wallTextureSet}:${wall}:${viewId}`;
      if (textureCache.has(key)) return textureCache.get(key);
      const img = new Image();
      img.onload = () => render();
      img.onerror = () => textureCache.set(key, null);
      img.src = `${DATA.wallTextureBase}/walldef1_${map.wallTextureSet}_wall_${String(wall).padStart(2, '0')}_view_${String(viewId).padStart(2, '0')}.png`;
      textureCache.set(key, img);
      return img;
    }

    function surfaceTexture(kind) {
      const map = currentMap();
      const name = map.surfaceTextures?.[kind];
      if (!DATA.wallTextureBase || !name) return null;
      const key = `surface:${map.wallTextureSet}:${kind}:${name}`;
      if (textureCache.has(key)) return textureCache.get(key);
      const img = new Image();
      img.onload = () => render();
      img.onerror = () => textureCache.set(key, null);
      img.src = `${DATA.wallTextureBase}/${name}`;
      textureCache.set(key, img);
      return img;
    }

    function drawTexturedPolygon(points, texture, near, side) {
      const minX = Math.min(...points.map(p => p[0]));
      const maxX = Math.max(...points.map(p => p[0]));
      const minY = Math.min(...points.map(p => p[1]));
      const maxY = Math.max(...points.map(p => p[1]));
      viewCtx.save();
      viewCtx.beginPath();
      points.forEach(([x, y], index) => {
        if (index === 0) viewCtx.moveTo(x, y);
        else viewCtx.lineTo(x, y);
      });
      viewCtx.closePath();
      viewCtx.clip();
      viewCtx.imageSmoothingEnabled = false;
      const width = Math.max(8, maxX - minX);
      const height = Math.max(8, maxY - minY);
      viewCtx.drawImage(texture, minX, minY, width, height);
      viewCtx.restore();
      viewCtx.strokeStyle = '#c3ccd4';
      viewCtx.lineWidth = 2;
      viewCtx.beginPath();
      points.forEach(([x, y], index) => {
        if (index === 0) viewCtx.moveTo(x, y);
        else viewCtx.lineTo(x, y);
      });
      viewCtx.closePath();
      viewCtx.stroke();
    }

    function drawCellMarker(cell, near, far, depth) {
      if (!cell || (!cell.eventId && !cell.door)) return;
      const cx = far.x + far.w / 2;
      const cy = far.y + far.h - Math.max(10, far.h * 0.18);
      const radius = Math.max(5, 14 - depth * 3);
      if (cell.eventId) {
        viewCtx.fillStyle = cell.eventFlag ? '#f1c75b' : '#5ec3a1';
        viewCtx.beginPath();
        viewCtx.arc(cx, cy, radius, 0, Math.PI * 2);
        viewCtx.fill();
        viewCtx.fillStyle = '#0f1113';
        viewCtx.font = `${Math.max(10, 15 - depth * 2)}px system-ui`;
        viewCtx.textAlign = 'center';
        viewCtx.textBaseline = 'middle';
        viewCtx.fillText(String(cell.eventId), cx, cy);
      }
      if (cell.door) {
        viewCtx.fillStyle = '#d97d5c';
        viewCtx.fillRect(cx + radius + 4, cy - radius, radius, radius);
      }
    }

    function drawViewportHud(blockedAt) {
      const map = currentMap();
      const cell = cellAt(map, state.row, state.col);
      viewCtx.fillStyle = 'rgba(8, 9, 10, 0.72)';
      viewCtx.fillRect(12, 12, 250, 54);
      viewCtx.fillStyle = '#eef2f4';
      viewCtx.font = '15px system-ui';
      viewCtx.textAlign = 'left';
      viewCtx.textBaseline = 'top';
      viewCtx.fillText(`${map.name}`, 24, 22);
      viewCtx.fillStyle = '#aab3bc';
      viewCtx.font = '13px system-ui';
      const blockedText = blockedAt === null ? 'open ahead' : `wall ${blockedAt + 1} step${blockedAt ? 's' : ''} ahead`;
      viewCtx.fillText(`facing ${state.facing} · ${blockedText}`, 24, 44);

      if (cell?.eventId) {
        viewCtx.fillStyle = 'rgba(15, 17, 19, 0.78)';
        viewCtx.fillRect(386, 392, 238, 70);
        viewCtx.fillStyle = '#f1c75b';
        viewCtx.font = '13px system-ui';
        viewCtx.fillText(`current event ${cell.eventId}`, 398, 404);
        viewCtx.fillStyle = '#eef2f4';
        viewCtx.font = '12px system-ui';
        const text = currentMap().events[String(cell.eventId)]?.text || 'no decoded text attached';
        viewCtx.fillText(text.slice(0, 38), 398, 426);
      }
      viewStatus.textContent = `facing ${state.facing}`;
    }

    function drawMap() {
      const map = currentMap();
      const size = mapCanvas.width;
      const unit = size / 16;
      mapCtx.clearRect(0, 0, size, size);
      for (const cell of map.cells) {
        const x = cell.col * unit;
        const y = cell.row * unit;
        mapCtx.fillStyle = ((cell.row + cell.col) % 2) ? '#20262b' : '#252b30';
        mapCtx.fillRect(x, y, unit, unit);
        if (cell.eventId) {
          const active = String(cell.eventId) === String(state.activeEventId) && cell.row === state.row && cell.col === state.col;
          mapCtx.fillStyle = active ? 'rgba(140,205,247,0.72)' : (cell.eventFlag ? 'rgba(241,199,91,0.48)' : 'rgba(94,195,161,0.34)');
          mapCtx.fillRect(x + 4, y + 4, unit - 8, unit - 8);
          mapCtx.fillStyle = '#0f1113';
          mapCtx.font = '14px system-ui';
          mapCtx.textAlign = 'center';
          mapCtx.textBaseline = 'middle';
          mapCtx.fillText(String(cell.eventId), x + unit / 2, y + unit / 2);
        }
        if (cell.door) {
          mapCtx.fillStyle = '#d97d5c';
          mapCtx.fillRect(x + unit - 10, y + 4, 6, 6);
        }
        drawWalls(cell, x, y, unit);
      }
      drawPlayer(unit);
    }

    function wallColor(value) {
      if (!value) return null;
      if (value === 11) return '#eef2f4';
      if (value === 8) return '#5ec3a1';
      return '#59636e';
    }

    function drawWalls(cell, x, y, unit) {
      mapCtx.lineWidth = 3;
      const edges = [
        [cell.walls[0], x, y, x + unit, y],
        [cell.walls[1], x + unit, y, x + unit, y + unit],
        [cell.walls[2], x, y + unit, x + unit, y + unit],
        [cell.walls[3], x, y, x, y + unit],
      ];
      for (const [value, x1, y1, x2, y2] of edges) {
        const color = wallColor(value);
        if (!color) continue;
        mapCtx.strokeStyle = color;
        mapCtx.beginPath();
        mapCtx.moveTo(x1, y1);
        mapCtx.lineTo(x2, y2);
        mapCtx.stroke();
      }
    }

    function drawPlayer(unit) {
      const cx = state.col * unit + unit / 2;
      const cy = state.row * unit + unit / 2;
      mapCtx.fillStyle = '#f7f2d8';
      mapCtx.strokeStyle = '#0f1113';
      mapCtx.lineWidth = 2;
      mapCtx.beginPath();
      mapCtx.arc(cx, cy, unit * 0.28, 0, Math.PI * 2);
      mapCtx.fill();
      mapCtx.stroke();
      const angle = { north: -Math.PI / 2, east: 0, south: Math.PI / 2, west: Math.PI }[state.facing];
      mapCtx.strokeStyle = '#0f1113';
      mapCtx.lineWidth = 3;
      mapCtx.beginPath();
      mapCtx.moveTo(cx, cy);
      mapCtx.lineTo(cx + Math.cos(angle) * unit * 0.26, cy + Math.sin(angle) * unit * 0.26);
      mapCtx.stroke();
    }

    function renderState() {
      const map = currentMap();
      const cell = cellAt(map, state.row, state.col);
      headerStatus.textContent = `GEO ${String(map.id).padStart(3, '0')} · row ${state.row}, col ${state.col}`;
      stateMeta.innerHTML = [
        ['Map', `${String(map.id).padStart(3, '0')} ${map.name}`],
        ['Position', `row ${state.row}, col ${state.col}`],
        ['Facing', state.facing],
        ['Steps', state.steps],
        ['Party HP', state.partyHp],
        ['Credits', state.credits],
        ['Inventory', state.inventory.join(', ') || '-'],
        ['Flags', state.flags.join(', ') || '-'],
        ['Encounter', state.activeEncounter || '-'],
        ['Dialog', state.lastDialog ? `${state.lastDialog.label}${state.lastDialog.branchTargetHex ? ` -> ${state.lastDialog.branchTargetHex}` : ''}` : '-'],
        ['ECL block', map.eclBlock || '-'],
        ['Wallsets', map.wallsets?.join(', ') || '-'],
        ['Texture set', map.wallTextureSet || '-'],
        ['Cell walls', cell ? cell.walls.join('/') : '-'],
        ['Door', cell?.door || '-'],
      ].map(([key, value]) => `<span>${esc(key)}</span><strong>${esc(value)}</strong>`).join('');
    }

    function renderEvent() {
      const map = currentMap();
      const cell = cellAt(map, state.row, state.col);
      if (!cell?.eventId) {
        eventBox.innerHTML = '<div class="muted">No event on this cell.</div>';
        return;
      }
      const event = map.events[String(cell.eventId)];
      const structured = event?.structured || '';
      const pseudocode = event?.pseudocode || '';
      const encounters = renderEncounterRows(event?.encounters || []);
      const dialogChoices = renderDialogChoices(event, cell.eventId);
      const dialogEvidence = renderDialogEvidence(event?.dialog);
      eventBox.innerHTML = `
        <div class="event-title">Event ${esc(cell.eventId)}${event?.target ? ` · target ${esc(event.target)}` : ''}</div>
        <div class="event-type">${esc(event?.type || 'unknown')}</div>
        ${encounters}
        <div>${esc(event?.text || 'Event target exists, but no nearby decoded text has been attached yet.')}</div>
        <div class="event-actions">
          <button type="button" id="runEventButton">Run placeholder behavior</button>
          ${dialogChoices}
        </div>
        ${dialogEvidence}
        ${structured ? `<details open><summary>Structured logic</summary><pre>${esc(structured)}</pre></details>` : ''}
        ${pseudocode ? `<details ${structured ? '' : 'open'}><summary>Pseudocode</summary><pre>${esc(pseudocode)}</pre></details>` : ''}
      `;
      document.getElementById('runEventButton')?.addEventListener('click', executeCurrentEvent);
      document.querySelectorAll('button[data-dialog-choice]').forEach(button => {
        button.addEventListener('click', () => executeDialogChoice(cell.eventId, Number(button.dataset.dialogChoice)));
      });
    }

    function renderDialogChoices(event, eventId) {
      const choices = event?.dialog?.choices || [];
      if (!choices.length) return '';
      return choices.map((choice, index) => {
        const branch = choice.branchTargetHex ? ` ${choice.branchTargetHex}` : '';
        return `<button type="button" data-dialog-choice="${index}" title="${esc(choice.evidence || 'ECL dialog reference')}">${esc(choice.label)}${esc(branch)}</button>`;
      }).join('');
    }

    function renderDialogEvidence(dialog) {
      if (!dialog?.choices?.length) return '';
      const rows = dialog.choices.map(choice => `${choice.label}${choice.branchTargetHex ? ` -> ${choice.branchTargetHex}` : ''}${choice.selector ? ` via ${choice.selector}` : ''}`).join('\n');
      return `<details><summary>ECL dialog reference</summary><pre>${esc(rows)}</pre></details>`;
    }

    function renderEncounterRows(rows) {
      if (!rows.length) return '';
      return `<div class="encounter-list">${rows.map(row => {
        const candidates = candidateNames(row);
        const name = row.monsterName || candidates || (row.monsterRef ? `dynamic ${row.monsterRef}` : 'unknown monster');
        const stats = row.stats ? `STR ${row.stats.strength}, INT ${row.stats.intelligence}, DEX ${row.stats.dexterity}` : row.resolution;
        const count = row.copies ? ` copies ${row.copies}` : '';
        const distance = row.maxDistance ? ` distance ${row.maxDistance}` : '';
        const note = row.candidateResolution?.index_note ? ` · ${row.candidateResolution.index_note}` : '';
        return `<div class="encounter-row"><strong>${esc(name)}</strong> <span>${esc(row.kind || '')} ${esc(row.address || '')}${esc(distance)}${esc(count)} · ${esc(stats || '')}${esc(note)}</span></div>`;
      }).join('')}</div>`;
    }

    function renderLog() {
      if (!state.log.length) {
        eventLog.innerHTML = '<div class="muted">No events triggered yet.</div>';
        return;
      }
      eventLog.innerHTML = state.log.map(row => `
        <div class="log-row">
          <div class="event-title">${esc(row.label)} · ${esc(row.map)} (${esc(row.row)}, ${esc(row.col)})</div>
          <div>${esc(row.text || 'No decoded text attached.')}</div>
        </div>
      `).join('');
    }

    init();
  </script>
</body>
</html>
"""


if __name__ == "__main__":
    raise SystemExit(main())
