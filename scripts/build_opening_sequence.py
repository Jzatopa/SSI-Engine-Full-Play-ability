#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shutil
from pathlib import Path


ASSET_NAMES = [
    "TITLE_001_000.png",
    "TITLE_002_000.png",
    "TITLE_003_000.png",
    "TITLE_004_000.png",
    "BIGPIC1_112_000.png",
    "BIGPIC1_113_000.png",
    "BIGPIC1_114_000.png",
    "BIGPIC1_115_000.png",
    "BIGPIC1_116_000.png",
    "BIGPIC1_117_000.png",
    "CHARS_000_000.png",
    "CHARS_001_000.png",
    "CHARS_002_000.png",
    "CHARS_003_000.png",
    "CHARS_004_000.png",
    "CHARS_005_000.png",
    "CPIC1_001_000.png",
    "CPIC1_002_000.png",
    "CPIC1_003_000.png",
    "CPIC1_004_000.png",
    "CPIC1_005_000.png",
    "CPIC1_006_000.png",
]


def copy_assets(image_dir: Path, asset_dir: Path) -> dict[str, str]:
    asset_dir.mkdir(parents=True, exist_ok=True)
    copied: dict[str, str] = {}
    for name in ASSET_NAMES:
        src = image_dir / name
        if not src.exists():
            continue
        dst = asset_dir / name
        shutil.copy2(src, dst)
        copied[name] = f"assets/{name}"
    return copied


def build_sequence(asset_paths: dict[str, str]) -> dict:
    windows = {
        "full_screen_art": {
            "x": 0,
            "y": 0,
            "w": 320,
            "h": 200,
            "style": "image",
            "description": "Full DOS viewport used for title and story art.",
        },
        "setup_dialog": {
            "x": 24,
            "y": 30,
            "w": 272,
            "h": 126,
            "style": "bordered_text",
            "description": "START.EXE setup prompt window reconstructed from executable strings.",
        },
        "message_dialog": {
            "x": 44,
            "y": 70,
            "w": 232,
            "h": 58,
            "style": "bordered_text",
            "description": "Centered short status window for loading and prompts.",
        },
        "main_menu": {
            "x": 54,
            "y": 62,
            "w": 212,
            "h": 98,
            "style": "bordered_menu",
            "description": "Initial game menu window. Items are inferred from Gold Box startup conventions and will be verified against runtime captures.",
        },
        "credits_text": {
            "x": 18,
            "y": 14,
            "w": 284,
            "h": 172,
            "style": "scroll_text",
            "description": "Credits text from GAME.OVR strings.",
        },
        "character_menu": {
            "x": 32,
            "y": 28,
            "w": 256,
            "h": 138,
            "style": "bordered_menu",
            "description": "Character-management command menu found in START.EXE strings.",
        },
        "pick_character": {
            "x": 38,
            "y": 34,
            "w": 244,
            "h": 120,
            "style": "bordered_menu",
            "description": "Character chooser seeded from GAME.OVR Pick Character and Select/Exit strings.",
        },
        "character_sheet": {
            "x": 14,
            "y": 12,
            "w": 292,
            "h": 176,
            "style": "character_sheet",
            "description": "Character-sheet window reconstructed from CHARS/CPIC assets and nearby GAME.OVR character strings.",
        },
    }

    character_options = [
        "CREATE NEW CHARACTER",
        "PURGE CHARACTER",
        "MODIFY CHARACTER",
        "TRAIN CHARACTER",
        "VIEW CHARACTER",
        "ADD CHARACTER TO TEAM",
        "REMOVE CHARACTER FROM TEAM",
        "EXIT",
    ]

    character_sprites = [
        asset_paths.get("CHARS_000_000.png"),
        asset_paths.get("CHARS_001_000.png"),
        asset_paths.get("CHARS_002_000.png"),
        asset_paths.get("CHARS_003_000.png"),
        asset_paths.get("CHARS_004_000.png"),
        asset_paths.get("CHARS_005_000.png"),
    ]

    character_portraits = [
        asset_paths.get("CPIC1_001_000.png"),
        asset_paths.get("CPIC1_002_000.png"),
        asset_paths.get("CPIC1_003_000.png"),
        asset_paths.get("CPIC1_004_000.png"),
        asset_paths.get("CPIC1_005_000.png"),
        asset_paths.get("CPIC1_006_000.png"),
    ]

    steps = [
        {
            "id": "start-exe-graphics",
            "label": "START.EXE graphics setup",
            "window_set": ["setup_dialog"],
            "text": [
                "GRAPHICS ADAPTER TYPE:",
                "[1] EGA  [2] Tandy  [3] VGA",
            ],
            "source": "START.EXE strings offset 5287",
        },
        {
            "id": "start-exe-sound",
            "label": "START.EXE sound setup",
            "window_set": ["setup_dialog"],
            "text": [
                "SOUND TYPE:",
                "[1] PC speaker",
                "[2] Sound Blaster",
                "[3] Adlib",
                "[4] Roland MT32",
                "[5] Tandy 1000",
                "[6] Silent",
            ],
            "source": "START.EXE strings offsets 5444-5566",
        },
        {
            "id": "start-exe-input",
            "label": "START.EXE input setup",
            "window_set": ["setup_dialog"],
            "text": [
                "ALTERNATE INPUT TYPE:",
                "[1] JOYSTICK  [2] MOUSE  [3] NEITHER",
            ],
            "source": "START.EXE strings offset 5566",
        },
        {
            "id": "start-exe-save-path",
            "label": "START.EXE save path",
            "window_set": ["setup_dialog"],
            "text": [
                "PATH TO SAVE DATA (DEFAULT - C:\\SAVE):",
                "USING DEFAULT PATH: C:\\SAVE",
            ],
            "source": "START.EXE strings offsets 5639-5734",
        },
        {
            "id": "loading-overlay",
            "label": "Loading overlay",
            "window_set": ["message_dialog"],
            "text": ["Loading...Please Wait"],
            "source": "START.EXE string offset 29259",
        },
        {
            "id": "ssi-presents",
            "label": "SSI presents",
            "window_set": ["full_screen_art"],
            "image": asset_paths.get("TITLE_001_000.png"),
            "source": "TITLE.DAX block 001",
        },
        {
            "id": "buck-rogers-logo",
            "label": "Buck Rogers logo",
            "window_set": ["full_screen_art"],
            "image": asset_paths.get("TITLE_002_000.png"),
            "source": "TITLE.DAX block 002",
        },
        {
            "id": "copyright",
            "label": "Copyright",
            "window_set": ["full_screen_art"],
            "image": asset_paths.get("TITLE_003_000.png"),
            "source": "TITLE.DAX block 003",
        },
        {
            "id": "matrix-cubed-title",
            "label": "Matrix Cubed title",
            "window_set": ["full_screen_art"],
            "image": asset_paths.get("TITLE_004_000.png"),
            "source": "TITLE.DAX block 004",
        },
        {
            "id": "story-panel-earth",
            "label": "Opening story art 1",
            "window_set": ["full_screen_art"],
            "image": asset_paths.get("BIGPIC1_112_000.png"),
            "source": "BIGPIC1.DAX block 112",
        },
        {
            "id": "story-panel-ship",
            "label": "Opening story art 2",
            "window_set": ["full_screen_art"],
            "image": asset_paths.get("BIGPIC1_113_000.png"),
            "source": "BIGPIC1.DAX block 113",
        },
        {
            "id": "credits",
            "label": "Credits window",
            "window_set": ["credits_text"],
            "text": [
                "CREATED BY: SSI SPECIAL PROJECTS TEAM",
                "GAME DEVELOPMENT:",
                "PROGRAMMING: Rhonda Gilbert, Russ Brown, Kerry Bonin",
                "ENCOUNTER CODE: Dave Shelley",
                "GRAPHIC ARTS: Chris Carr, Laura Bowen, Tom Ono, Fred Butts, Ken Eklund",
                "MUSIC: Ralph Thomas & The Fat Man",
            ],
            "source": "GAME.OVR strings offsets 393-722",
        },
        {
            "id": "main-menu",
            "label": "Initial game menu",
            "window_set": ["main_menu"],
            "text": [
                "BUCK ROGERS: MATRIX CUBED",
                "LOAD SAVED GAME",
                "CREATE CHARACTERS",
                "VIEW CHARACTERS",
                "BEGIN GAME",
                "EXIT TO DOS",
            ],
            "source": "Menu entries are a reconstruction seed pending DOSBox capture/Ghidra validation.",
            "selected_index": 3,
        },
        {
            "id": "view-characters-selected",
            "label": "Main menu: View Characters",
            "window_set": ["main_menu"],
            "text": [
                "BUCK ROGERS: MATRIX CUBED",
                "LOAD SAVED GAME",
                "CREATE CHARACTERS",
                "VIEW CHARACTERS",
                "BEGIN GAME",
                "EXIT TO DOS",
            ],
            "source": "Steps forward from the seeded main menu item James selected: VIEW CHARACTERS.",
            "selected_index": 3,
        },
        {
            "id": "character-options-view",
            "label": "Character options",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options],
            "source": "START.EXE strings offsets 59986-60156: Create, Purge, Modify, Train, View, Add to Team, Remove from Team.",
            "selected_index": 5,
            "assets": character_sprites,
        },
        {
            "id": "pick-character-for-view",
            "label": "Pick character",
            "window_set": ["pick_character"],
            "text": [
                "PICK CHARACTER",
                "1  BUCK ROGERS",
                "2  WILMA DEERING",
                "3  ROCKETJOCK",
                "4  MEDIC",
                "",
                "SELECT   EXIT",
            ],
            "source": "GAME.OVR strings offsets 150247 and 150263: Pick Character / Select Exit. Names are sample roster placeholders until save/CHARS records are decoded.",
            "selected_index": 1,
            "assets": character_portraits,
        },
        {
            "id": "view-character-sheet",
            "label": "View Character",
            "window_set": ["character_sheet"],
            "text": [
                "BUCK ROGERS",
                "Race: Human       Career: Rocketjock",
                "Level: 1          Status: OK",
                "STR 15  DEX 16  CON 14",
                "INT 13  WIS 12  CHA 15",
                "AC: 8   HP: 12/12   Credits: 0",
                "",
                "View   Items   Exit",
            ],
            "source": "GAME.OVR character-view strings include View, Exit, Character name, and CHARS.DAX access. Stat values are reconstruction placeholders pending CHARS.DAX record decoding.",
            "selected_index": 7,
            "assets": [asset_paths.get("CHARS_000_000.png"), asset_paths.get("CPIC1_001_000.png")],
        },
        {
            "id": "option-create-new-character",
            "label": "Option: Create New Character",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Character name:", "Reroll stats?   Save"],
            "source": "START.EXE offset 59986 and GAME.OVR offsets 99554-99586: Create New Character / Reroll stats? / Character name: / Save.",
            "selected_index": 1,
            "assets": character_sprites,
        },
        {
            "id": "option-purge-character",
            "label": "Option: Purge Character",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Lose character?", "This removes the character record."],
            "source": "START.EXE offset 60015 and GAME.OVR offset 129547: Purge Character / Lose character?",
            "selected_index": 2,
            "assets": character_sprites,
        },
        {
            "id": "option-modify-character",
            "label": "Option: Modify Character",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Modify:", "Add   Subtract   Keep   Exit"],
            "source": "START.EXE offset 60038 and GAME.OVR offsets 102225-102234: Modify / Add Subtract Keep Exit.",
            "selected_index": 3,
            "assets": character_sprites,
        },
        {
            "id": "option-train-character",
            "label": "Option: Train Character",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Train", "Do you wish to train?"],
            "source": "START.EXE offset 60081 and GAME.OVR offsets 109065-109186: Train Character / train-conscious and max-level checks / Do you wish to train?",
            "selected_index": 4,
            "assets": character_sprites,
        },
        {
            "id": "option-view-character",
            "label": "Option: View Character",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Pick Character", "Select   Exit"],
            "source": "START.EXE offset 60104 and GAME.OVR offsets 150247-150263: View Character / Pick Character / Select Exit.",
            "selected_index": 5,
            "assets": character_sprites,
        },
        {
            "id": "option-add-character",
            "label": "Option: Add Character To Team",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Add a character:", "Add"],
            "source": "START.EXE offset 60126 and GAME.OVR offsets 104505-104523: Add Character to Team / Add a character: / Add.",
            "selected_index": 6,
            "assets": character_sprites,
        },
        {
            "id": "option-remove-character",
            "label": "Option: Remove Character From Team",
            "window_set": ["character_menu"],
            "text": ["CHARACTER OPTIONS", *character_options, "", "Remove from active team.", "Character remains in CHARS.DAX."],
            "source": "START.EXE offset 60156: Remove Character from Team. Exact confirmation text still needs DOSBox/Ghidra validation.",
            "selected_index": 7,
            "assets": character_sprites,
        },
    ]

    return {
        "game": "Buck Rogers: Matrix Cubed",
        "screen": {"w": 320, "h": 200},
        "coordinate_system": "DOS pixel coordinates",
        "status": "opening sequence reconstruction seed",
        "windows": windows,
        "steps": steps,
    }


def render_html(sequence: dict) -> str:
    data = json.dumps(sequence, indent=2)
    return f"""<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Matrix Cubed Opening Reconstruction</title>
<style>
:root {{
  color-scheme: dark;
  --bg: #07080b;
  --panel: #121720;
  --line: #3e76a8;
  --line2: #e0c86c;
  --text: #d8f6ff;
  --muted: #8aa2ad;
  --accent: #ffdf6e;
  --danger: #ff6f61;
}}
* {{ box-sizing: border-box; }}
body {{
  margin: 0;
  background: #07080b;
  color: var(--text);
  font-family: Arial, Helvetica, sans-serif;
}}
.shell {{
  min-height: 100vh;
  display: grid;
  grid-template-columns: minmax(0, 1fr) 340px;
}}
.stage-wrap {{
  display: grid;
  place-items: center;
  padding: 24px;
  background:
    linear-gradient(180deg, rgba(255,255,255,.04), transparent 22%),
    #07080b;
}}
.stage {{
  width: min(calc(100vw - 420px), calc((100vh - 80px) * 1.6), 1080px);
  aspect-ratio: 320 / 200;
  position: relative;
  background: #000;
  image-rendering: pixelated;
  box-shadow: 0 0 0 1px #24303a, 0 24px 80px rgba(0,0,0,.55);
  overflow: hidden;
}}
.stage::after {{
  content: "";
  position: absolute;
  inset: 0;
  pointer-events: none;
  background: repeating-linear-gradient(0deg, rgba(255,255,255,.035), rgba(255,255,255,.035) 1px, transparent 1px, transparent 3px);
  mix-blend-mode: screen;
  opacity: .22;
}}
.art {{
  position: absolute;
  image-rendering: pixelated;
  object-fit: contain;
}}
.dos-window {{
  position: absolute;
  padding: 2.2%;
  border: 2px solid var(--line2);
  outline: 2px solid #1b5981;
  background: #001321;
  box-shadow: inset 0 0 0 2px #000, 0 0 0 2px #000;
  color: var(--text);
  font-family: "Courier New", monospace;
  font-size: clamp(12px, 2.2vw, 22px);
  line-height: 1.28;
  overflow: hidden;
}}
.menu-line:first-child {{
  color: var(--accent);
  margin-bottom: .5em;
}}
.menu-line.selected {{
  background: #b8d8ff;
  color: #00101a;
}}
.asset-strip {{
  position: absolute;
  right: 4%;
  bottom: 5%;
  display: flex;
  gap: 6px;
  align-items: end;
  max-width: 55%;
  overflow: hidden;
}}
.asset-strip img {{
  width: clamp(22px, 5vw, 54px);
  height: auto;
  image-rendering: pixelated;
  object-fit: contain;
}}
.side {{
  border-left: 1px solid #26323d;
  background: #0d1118;
  padding: 18px;
  display: flex;
  flex-direction: column;
  gap: 14px;
}}
.title {{
  font-size: 18px;
  color: var(--accent);
  font-weight: 700;
}}
.meta, .source, .hint {{
  color: var(--muted);
  font-size: 13px;
  line-height: 1.45;
}}
.controls {{
  display: grid;
  grid-template-columns: repeat(3, 1fr);
  gap: 8px;
}}
button {{
  border: 1px solid #365267;
  background: #182333;
  color: var(--text);
  padding: 10px 8px;
  border-radius: 6px;
  cursor: pointer;
  font-weight: 700;
}}
button:hover {{ border-color: var(--accent); }}
.timeline {{
  display: flex;
  flex-direction: column;
  gap: 6px;
  overflow: auto;
  min-height: 0;
}}
.step {{
  text-align: left;
  font-weight: 500;
  padding: 8px;
  border-radius: 4px;
}}
.step.active {{
  border-color: var(--accent);
  color: #041017;
  background: var(--accent);
}}
pre {{
  margin: 0;
  padding: 10px;
  background: #070a0f;
  border: 1px solid #22303b;
  border-radius: 6px;
  color: #c6d8e0;
  font-size: 12px;
  overflow: auto;
  max-height: 220px;
}}
@media (max-width: 900px) {{
  .shell {{ grid-template-columns: 1fr; }}
  .side {{ border-left: 0; border-top: 1px solid #26323d; }}
  .stage {{ width: min(94vw, calc((100vh - 360px) * 1.6)); }}
}}
</style>
</head>
<body>
<main class="shell">
  <section class="stage-wrap">
    <div class="stage" id="stage"></div>
  </section>
  <aside class="side">
    <div>
      <div class="title">Opening Reconstruction</div>
      <div class="meta" id="label"></div>
      <div class="source" id="source"></div>
    </div>
    <div class="controls">
      <button id="prev">Prev</button>
      <button id="play">Play</button>
      <button id="next">Next</button>
    </div>
    <div class="hint">This page reconstructs the launch/opening flow from extracted Matrix Cubed assets and strings. The JSON below is the window-set seed for the Python runtime.</div>
    <pre id="windowJson"></pre>
    <div class="timeline" id="timeline"></div>
  </aside>
</main>
<script id="sequence" type="application/json">{data}</script>
<script>
const sequence = JSON.parse(document.getElementById('sequence').textContent);
const stage = document.getElementById('stage');
const label = document.getElementById('label');
const source = document.getElementById('source');
const windowJson = document.getElementById('windowJson');
const timeline = document.getElementById('timeline');
let index = 0;
let timer = null;

function pct(v, total) {{
  return (v / total * 100).toFixed(4) + '%';
}}

function makeWindow(win, step) {{
  const el = document.createElement('div');
  el.className = 'dos-window';
  el.style.left = pct(win.x, sequence.screen.w);
  el.style.top = pct(win.y, sequence.screen.h);
  el.style.width = pct(win.w, sequence.screen.w);
  el.style.height = pct(win.h, sequence.screen.h);
  const lines = step.text || [];
  const selected = Number.isInteger(step.selected_index) ? step.selected_index : -1;
  el.innerHTML = lines.map((line, i) => `<div class="menu-line ${{i === selected ? 'selected' : ''}}">${{escapeHtml(line)}}</div>`).join('');
  const assets = (step.assets || []).filter(Boolean);
  if (assets.length) {{
    const strip = document.createElement('div');
    strip.className = 'asset-strip';
    for (const src of assets.slice(0, 6)) {{
      const img = document.createElement('img');
      img.src = src;
      img.alt = '';
      strip.appendChild(img);
    }}
    el.appendChild(strip);
  }}
  return el;
}}

function renderArt(step) {{
  if (!step.image) return;
  const img = document.createElement('img');
  img.className = 'art';
  img.src = step.image;
  if (step.image.includes('TITLE_001')) {{
    img.style.left = '0%'; img.style.top = '28%'; img.style.width = '100%'; img.style.height = '36%';
  }} else if (step.image.includes('TITLE_002')) {{
    img.style.left = '5%'; img.style.top = '12%'; img.style.width = '90%'; img.style.height = '72%';
  }} else if (step.image.includes('TITLE_003')) {{
    img.style.left = '7.5%'; img.style.top = '40%'; img.style.width = '85%'; img.style.height = '16%';
  }} else if (step.image.includes('TITLE_004')) {{
    img.style.left = '0%'; img.style.top = '4%'; img.style.width = '100%'; img.style.height = '92%';
  }} else {{
    img.style.left = '2.5%'; img.style.top = '20%'; img.style.width = '95%'; img.style.height = '60%';
  }}
  stage.appendChild(img);
}}

function render() {{
  const step = sequence.steps[index];
  stage.innerHTML = '';
  renderArt(step);
  for (const name of step.window_set || []) {{
    const win = sequence.windows[name];
    if (!win || win.style === 'image') continue;
    stage.appendChild(makeWindow(win, step));
  }}
  label.textContent = `${{index + 1}} / ${{sequence.steps.length}} - ${{step.label}}`;
  source.textContent = step.source || '';
  const set = Object.fromEntries((step.window_set || []).map(name => [name, sequence.windows[name]]));
  windowJson.textContent = JSON.stringify({{ step: step.id, window_set: set }}, null, 2);
  [...timeline.children].forEach((btn, i) => btn.classList.toggle('active', i === index));
}}

function escapeHtml(value) {{
  return String(value)
    .replaceAll('&', '&amp;')
    .replaceAll('<', '&lt;')
    .replaceAll('>', '&gt;')
    .replaceAll('"', '&quot;')
    .replaceAll("'", '&#039;');
}}

function stop() {{
  if (timer) clearInterval(timer);
  timer = null;
  document.getElementById('play').textContent = 'Play';
}}

sequence.steps.forEach((step, i) => {{
  const btn = document.createElement('button');
  btn.className = 'step';
  btn.textContent = `${{i + 1}}. ${{step.label}}`;
  btn.addEventListener('click', () => {{ index = i; stop(); render(); }});
  timeline.appendChild(btn);
}});

document.getElementById('prev').addEventListener('click', () => {{
  index = (index + sequence.steps.length - 1) % sequence.steps.length;
  stop();
  render();
}});
document.getElementById('next').addEventListener('click', () => {{
  index = (index + 1) % sequence.steps.length;
  stop();
  render();
}});
document.getElementById('play').addEventListener('click', () => {{
  if (timer) {{ stop(); return; }}
  document.getElementById('play').textContent = 'Pause';
  timer = setInterval(() => {{
    index = (index + 1) % sequence.steps.length;
    render();
  }}, 1800);
}});

render();
</script>
</body>
</html>
"""


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("image_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()

    args.out_dir.mkdir(parents=True, exist_ok=True)
    asset_paths = copy_assets(args.image_dir, args.out_dir / "assets")
    sequence = build_sequence(asset_paths)
    (args.out_dir / "opening_sequence.json").write_text(json.dumps(sequence, indent=2) + "\n")
    (args.out_dir / "matrix_cubed_opening_sequence.html").write_text(render_html(sequence))


if __name__ == "__main__":
    main()
