#!/usr/bin/env python3
from __future__ import annotations

import json
from pathlib import Path


def option(key: str, label: str, target: str, evidence: str = "", note: str = "") -> dict:
    item = {"key": key, "label": label, "target": target}
    if evidence:
        item["evidence"] = evidence
    if note:
        item["note"] = note
    return item


def node(
    node_id: str,
    title: str,
    kind: str,
    evidence: list[str],
    options: list[dict],
    notes: list[str] | None = None,
) -> dict:
    return {
        "id": node_id,
        "title": title,
        "kind": kind,
        "evidence": evidence,
        "options": options,
        "notes": notes or [],
    }


def build_map() -> dict:
    nodes = [
        node(
            "graphics_adapter",
            "Graphics Adapter Type",
            "setup_prompt",
            ["START.EXE offset 5287: GRAPHICS ADAPTER TYPE: [1] EGA [2] Tandy [3] VGA"],
            [
                option("1", "EGA", "sound_type"),
                option("2", "Tandy", "sound_type"),
                option("3", "VGA", "sound_type"),
            ],
        ),
        node(
            "sound_type",
            "Sound Type",
            "setup_prompt",
            ["START.EXE offsets 5444-5566: SOUND TYPE choices"],
            [
                option("1", "PC speaker", "alternate_input"),
                option("2", "Sound Blaster", "alternate_input"),
                option("3", "Adlib", "alternate_input"),
                option("4", "Roland MT32", "alternate_input"),
                option("5", "Tandy 1000", "alternate_input"),
                option("6", "Silent", "alternate_input"),
            ],
        ),
        node(
            "alternate_input",
            "Alternate Input Type",
            "setup_prompt",
            ["START.EXE offset 5566: ALTERNATE INPUT TYPE: [1] JOYSTICK [2] MOUSE [3] NEITHER"],
            [
                option("1", "Joystick", "joystick_calibration", note="Calibration prompts follow if selected."),
                option("2", "Mouse", "save_path"),
                option("3", "Neither", "save_path"),
            ],
        ),
        node(
            "joystick_calibration",
            "Joystick Calibration",
            "setup_prompt",
            [
                "START.EXE offset 45461: upper-left calibration prompt",
                "START.EXE offset 45461: lower-right calibration prompt",
            ],
            [
                option("button 1", "Confirm upper-left", "joystick_calibration_lower"),
                option("abort", "Could not read joystick", "alternate_input"),
            ],
            ["The exact abort/retry loop needs live DOS validation."],
        ),
        node(
            "joystick_calibration_lower",
            "Joystick Calibration Lower Right",
            "setup_prompt",
            ["START.EXE offset 45461: Push JOYSTICK #1 to the extreme lower right position and press BUTTON #1."],
            [option("button 1", "Confirm lower-right", "save_path")],
        ),
        node(
            "save_path",
            "Save Path",
            "setup_prompt",
            [
                "START.EXE offsets 5639-5734: SAVE / PATH TO SAVE DATA / USING DEFAULT PATH / :\\SAVE",
                "START.EXE offset 5734: :\\BUCK\\SAVE",
            ],
            [
                option("Enter", "Use default save path", "loading_overlay"),
                option("text", "Type save path", "loading_overlay"),
            ],
        ),
        node(
            "loading_overlay",
            "Loading",
            "status",
            ["START.EXE offset 29259: Loading...Please Wait"],
            [option("auto", "Continue when overlay loads", "title_sequence")],
        ),
        node(
            "title_sequence",
            "Title And Story Sequence",
            "presentation",
            [
                "TITLE.DAX blocks 001-004",
                "BIGPIC1.DAX blocks 112-117",
                "START.EXE offset 60968: Press button or enter to continue",
            ],
            [
                option("Enter", "Advance title/story screens", "startup_command_menu"),
                option("button", "Advance title/story screens", "startup_command_menu"),
                option("auto", "Timed screens may advance without input", "startup_command_menu"),
            ],
            ["Exact timing and skip behavior still needs live DOS capture."],
        ),
        node(
            "startup_command_menu",
            "Startup Command Menu",
            "menu",
            [
                "START.EXE offsets 59986-60298: character, load/save, begin, and exit command labels",
                "START.EXE offset 59934: Select Exit:",
            ],
            [
                option("1", "Create New Character", "create_character"),
                option("2", "Purge Character", "purge_character"),
                option("3", "Modify Character", "modify_character"),
                option("4", "Train Character", "train_character"),
                option("5", "View Character", "view_character_pick"),
                option("6", "Add Character to Team", "add_character"),
                option("7", "Remove Character from Team", "remove_character"),
                option("8", "Load Saved Game", "load_saved_game"),
                option("9", "Save Current Game", "save_current_game"),
                option("10", "Begin Adventuring", "game_start"),
                option("11", "Exit to DOS", "exit_to_dos"),
            ],
            ["The earlier reconstruction used a compact inferred menu; this node is the stronger string-evidence map."],
        ),
        node(
            "create_character",
            "Create New Character",
            "character_flow",
            [
                "START.EXE offset 59986: Create New Character",
                "GAME.OVR offset 99509: Pick Race",
                "GAME.OVR offset 99531: Pick Gender",
                "GAME.OVR offset 99543: Pick Class",
                "GAME.OVR offset 99554: Reroll stats?",
                "GAME.OVR offset 99569: Character name:",
                "GAME.OVR offset 99586: Save",
            ],
            [
                option("select race", "Pick Race", "create_pick_gender"),
                option("Exit", "Abort creation", "startup_command_menu"),
            ],
        ),
        node(
            "create_pick_gender",
            "Create Character: Pick Gender",
            "character_flow",
            ["GAME.OVR offset 99531: Pick Gender"],
            [option("select gender", "Pick Gender", "create_pick_class"), option("Exit", "Back", "startup_command_menu")],
        ),
        node(
            "create_pick_class",
            "Create Character: Pick Class/Career",
            "character_flow",
            [
                "GAME.OVR offset 99543: Pick Class",
                "START.EXE offsets 61712-61760: Rocket Jock, Medic, Warrior, Engineer, Rogue",
                "START.EXE offsets 61812-61854: Martian, Venusian, Mercurian, Tinker, Desert Runner",
            ],
            [
                option("select class", "Pick Class", "create_reroll_stats"),
                option("Exit", "Back", "startup_command_menu"),
            ],
        ),
        node(
            "create_reroll_stats",
            "Create Character: Reroll Stats",
            "character_flow",
            ["GAME.OVR offset 99554: Reroll stats?"],
            [
                option("Yes", "Reroll stats", "create_reroll_stats"),
                option("No", "Keep stats", "create_name"),
            ],
        ),
        node(
            "create_name",
            "Create Character: Name",
            "character_flow",
            ["GAME.OVR offset 99569: Character name:"],
            [option("text", "Enter character name", "create_skills")],
        ),
        node(
            "create_skills",
            "Create Character: Skills",
            "character_flow",
            [
                "START.EXE offsets 62116-62242: skill category labels",
                "GAME.OVR offsets 154711-154769: General skills, skill points, maximum per skill",
                "GAME.OVR offsets 156204-156292: skill point and unspent-points checks",
            ],
            [
                option("Add", "Add skill point", "create_skills"),
                option("Subtract", "Subtract skill point", "create_skills"),
                option("Keep", "Keep skill choices", "create_save"),
                option("Exit", "Exit skill allocation", "create_save", note="May prompt about unspent points."),
            ],
        ),
        node(
            "create_save",
            "Create Character: Save",
            "character_flow",
            ["GAME.OVR offset 99586: Save"],
            [
                option("Save", "Save character to CHARS.DAX", "startup_command_menu"),
                option("Exit", "Return without saving", "startup_command_menu"),
            ],
        ),
        node(
            "purge_character",
            "Purge Character",
            "character_flow",
            [
                "START.EXE offset 60015: Purge Character",
                "GAME.OVR offset 129547: Lose character?",
                "GAME.OVR offset 150247: Pick Character",
            ],
            [
                option("Select", "Choose character to purge", "purge_confirm"),
                option("Exit", "Return", "startup_command_menu"),
            ],
        ),
        node(
            "purge_confirm",
            "Purge Character: Confirm",
            "character_flow",
            ["GAME.OVR offset 129547: Lose character?"],
            [
                option("Yes", "Delete character", "startup_command_menu"),
                option("No", "Cancel", "startup_command_menu"),
            ],
        ),
        node(
            "modify_character",
            "Modify Character",
            "character_flow",
            [
                "START.EXE offset 60038: Modify Character",
                "GAME.OVR offset 102225: Modify:",
                "GAME.OVR offset 102234: Add Subtract Keep Exit",
            ],
            [
                option("Select", "Choose character to modify", "modify_skills"),
                option("Exit", "Return", "startup_command_menu"),
            ],
        ),
        node(
            "modify_skills",
            "Modify Character: Skills",
            "character_flow",
            ["GAME.OVR offset 102234: Add Subtract Keep Exit"],
            [
                option("Add", "Add point", "modify_skills"),
                option("Subtract", "Subtract point", "modify_skills"),
                option("Keep", "Save changes", "startup_command_menu"),
                option("Exit", "Cancel or exit", "startup_command_menu"),
            ],
        ),
        node(
            "train_character",
            "Train Character",
            "character_flow",
            [
                "START.EXE offset 60081: Train Character",
                "GAME.OVR offset 109065: conscious/max-level checks",
                "GAME.OVR offset 109186: Do you wish to train?",
            ],
            [
                option("Select", "Choose character to train", "train_confirm"),
                option("Exit", "Return", "startup_command_menu"),
            ],
        ),
        node(
            "train_confirm",
            "Train Character: Confirm",
            "character_flow",
            ["GAME.OVR offset 109186: Do you wish to train?"],
            [
                option("Yes", "Train selected character", "startup_command_menu"),
                option("No", "Cancel", "startup_command_menu"),
            ],
        ),
        node(
            "view_character_pick",
            "View Character: Pick",
            "character_flow",
            [
                "START.EXE offset 60104: View Character",
                "GAME.OVR offset 150247: Pick Character",
                "GAME.OVR offset 150263: Select Exit",
            ],
            [
                option("Select", "View selected character", "view_character_sheet"),
                option("Exit", "Return", "startup_command_menu"),
            ],
        ),
        node(
            "view_character_sheet",
            "View Character: Sheet",
            "character_flow",
            [
                "GAME.OVR offset 139315: name",
                "GAME.OVR offset 139342: career",
                "GAME.OVR offset 139446: career skills",
                "GAME.OVR offset 143132: Skills",
            ],
            [
                option("View", "Cycle/details", "view_character_sheet"),
                option("Exit", "Return", "startup_command_menu"),
            ],
            ["Exact sub-tabs need live capture or deeper disassembly."],
        ),
        node(
            "add_character",
            "Add Character To Team",
            "character_flow",
            [
                "START.EXE offset 60126: Add Character to Team",
                "GAME.OVR offset 104505: Add a character:",
                "GAME.OVR offset 104523: Add",
            ],
            [
                option("Add", "Add selected roster character to active team", "startup_command_menu"),
                option("Exit", "Return", "startup_command_menu"),
            ],
        ),
        node(
            "remove_character",
            "Remove Character From Team",
            "character_flow",
            ["START.EXE offset 60156: Remove Character from Team"],
            [
                option("Select", "Remove selected active team member", "startup_command_menu"),
                option("Exit", "Return", "startup_command_menu"),
            ],
            ["Exact confirmation text is not yet identified in strings."],
        ),
        node(
            "load_saved_game",
            "Load Saved Game",
            "save_flow",
            [
                "START.EXE offset 60190: Load Saved Game",
                "GAME.OVR offset 134527: Load Which Game:",
                "GAME.OVR offset 127429: from saved game",
                "GAME.OVR offset 128551: Is your save disk in drive",
            ],
            [
                option("slot/name", "Choose saved game", "startup_command_menu", note="Loaded game returns to command/menu or map depending save state."),
                option("Exit", "Cancel", "startup_command_menu"),
            ],
        ),
        node(
            "save_current_game",
            "Save Current Game",
            "save_flow",
            [
                "START.EXE offset 60214: Save Current Game",
                "START.EXE offset 29338: Saving...Please Wait",
                "GAME.OVR offset 136472: Save Which Game:",
                "GAME.OVR offset 129678: Overwrite Rename Abort save",
            ],
            [
                option("slot/name", "Choose save target", "save_confirm"),
                option("Exit", "Cancel", "startup_command_menu"),
            ],
        ),
        node(
            "save_confirm",
            "Save Current Game: Confirm",
            "save_flow",
            ["GAME.OVR offset 129678: Overwrite Rename Abort save"],
            [
                option("Overwrite", "Overwrite existing save", "startup_command_menu"),
                option("Rename", "Enter new file name", "save_current_game"),
                option("Abort save", "Cancel", "startup_command_menu"),
            ],
        ),
        node(
            "exit_to_dos",
            "Exit To DOS",
            "exit_flow",
            [
                "START.EXE offset 60298: Exit to DOS",
                "GAME.OVR offset 98188: Game NOT saved. Quit anyway?",
            ],
            [
                option("Yes", "Quit to DOS", "dos_exit"),
                option("No", "Return", "startup_command_menu"),
            ],
        ),
        node(
            "dos_exit",
            "DOS Exit",
            "terminal",
            ["Terminal state inferred from Exit to DOS."],
            [],
        ),
        node(
            "game_start",
            "Begin Adventuring / Game Starts",
            "terminal",
            [
                "START.EXE offset 60239: Begin Adventuring",
                "GAME.OVR offset 65336: A battle begins...",
                "Existing runtime prototype starts at GEO 017 Caloris Space Port.",
            ],
            [],
            ["This is the requested boundary: startup input mapping stops once the adventuring runtime begins."],
        ),
    ]

    return {
        "game": "Buck Rogers: Matrix Cubed",
        "scope": "startup inputs from executable setup through Begin Adventuring",
        "status": "string-evidence map with marked inferred transitions",
        "entry_node": "graphics_adapter",
        "terminal_nodes": ["game_start", "dos_exit"],
        "nodes": nodes,
    }


def render_markdown(input_map: dict) -> str:
    lines = [
        "# Matrix Cubed Startup Input Map",
        "",
        f"Status: {input_map['status']}",
        f"Scope: {input_map['scope']}",
        "",
        "## Nodes",
        "",
    ]
    for item in input_map["nodes"]:
        lines.append(f"### {item['title']} (`{item['id']}`)")
        lines.append("")
        lines.append(f"- Kind: `{item['kind']}`")
        for evidence in item["evidence"]:
            lines.append(f"- Evidence: {evidence}")
        for note in item.get("notes", []):
            lines.append(f"- Note: {note}")
        if item["options"]:
            lines.append("")
            lines.append("| Input | Result | Target |")
            lines.append("| --- | --- | --- |")
            for opt in item["options"]:
                detail = opt["label"]
                if opt.get("note"):
                    detail += f" ({opt['note']})"
                lines.append(f"| `{opt['key']}` | {detail} | `{opt['target']}` |")
        else:
            lines.append("")
            lines.append("Terminal node.")
        lines.append("")
    return "\n".join(lines)


def render_html(input_map: dict) -> str:
    data = json.dumps(input_map, indent=2)
    cards = []
    for item in input_map["nodes"]:
        evidence = "".join(f"<li>{escape(e)}</li>" for e in item["evidence"])
        notes = "".join(f"<li>{escape(n)}</li>" for n in item.get("notes", []))
        options = "".join(
            f"<tr><td><code>{escape(opt['key'])}</code></td><td>{escape(opt['label'])}</td><td><a href='#{escape(opt['target'])}'>{escape(opt['target'])}</a></td></tr>"
            for opt in item["options"]
        )
        table = (
            "<table><thead><tr><th>Input</th><th>Result</th><th>Target</th></tr></thead>"
            f"<tbody>{options}</tbody></table>"
            if item["options"]
            else "<p class='terminal'>Terminal node.</p>"
        )
        note_block = f"<h4>Notes</h4><ul>{notes}</ul>" if notes else ""
        cards.append(
            f"<section class='card' id='{escape(item['id'])}'>"
            f"<div class='kind'>{escape(item['kind'])}</div>"
            f"<h2>{escape(item['title'])}</h2>"
            f"<h4>Evidence</h4><ul>{evidence}</ul>"
            f"{note_block}{table}</section>"
        )
    return f"""<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Matrix Cubed Startup Input Map</title>
<style>
* {{ box-sizing: border-box; }}
body {{
  margin: 0;
  background: #0b0e12;
  color: #dbe7ee;
  font-family: Arial, Helvetica, sans-serif;
}}
header {{
  position: sticky;
  top: 0;
  z-index: 2;
  padding: 16px 20px;
  background: #111923;
  border-bottom: 1px solid #2b3c4b;
}}
h1 {{ margin: 0 0 4px; font-size: 22px; letter-spacing: 0; }}
.sub {{ color: #9eb2bf; font-size: 14px; }}
main {{
  display: grid;
  grid-template-columns: 280px minmax(0, 1fr);
  gap: 18px;
  padding: 18px;
}}
nav {{
  position: sticky;
  top: 84px;
  align-self: start;
  max-height: calc(100vh - 100px);
  overflow: auto;
  padding: 12px;
  background: #101720;
  border: 1px solid #273746;
  border-radius: 8px;
}}
nav a {{
  display: block;
  color: #b9d7e9;
  text-decoration: none;
  padding: 7px 6px;
  border-radius: 4px;
  font-size: 13px;
}}
nav a:hover {{ background: #1b2a38; }}
.grid {{
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(360px, 1fr));
  gap: 14px;
}}
.card {{
  border: 1px solid #2b3c4b;
  border-radius: 8px;
  background: #101720;
  padding: 14px;
}}
.kind {{
  color: #f2d56b;
  font-size: 12px;
  text-transform: uppercase;
  letter-spacing: 0;
}}
h2 {{ margin: 4px 0 10px; font-size: 18px; }}
h4 {{ margin: 12px 0 6px; font-size: 13px; color: #9eb2bf; }}
ul {{ margin: 0; padding-left: 18px; }}
li {{ margin: 4px 0; line-height: 1.35; }}
table {{ width: 100%; border-collapse: collapse; margin-top: 10px; font-size: 13px; }}
th, td {{ border-top: 1px solid #263747; padding: 7px 6px; text-align: left; vertical-align: top; }}
th {{ color: #f2d56b; font-weight: 700; }}
code {{ color: #f5f0b8; }}
a {{ color: #8fd0ff; }}
.terminal {{ color: #9eb2bf; }}
pre {{
  margin: 18px 0 0;
  padding: 12px;
  overflow: auto;
  background: #080b10;
  border: 1px solid #273746;
  border-radius: 8px;
  font-size: 12px;
}}
@media (max-width: 900px) {{
  main {{ grid-template-columns: 1fr; }}
  nav {{ position: static; max-height: none; }}
  .grid {{ grid-template-columns: 1fr; }}
}}
</style>
</head>
<body>
<header>
  <h1>Matrix Cubed Startup Input Map</h1>
  <div class="sub">{escape(input_map['scope'])} - {escape(input_map['status'])}</div>
</header>
<main>
  <nav>
    {''.join(f"<a href='#{escape(item['id'])}'>{escape(item['title'])}</a>" for item in input_map['nodes'])}
  </nav>
  <div>
    <div class="grid">
      {''.join(cards)}
    </div>
    <pre>{escape(data)}</pre>
  </div>
</main>
</body>
</html>
"""


def escape(value: object) -> str:
    return (
        str(value)
        .replace("&", "&amp;")
        .replace("<", "&lt;")
        .replace(">", "&gt;")
        .replace('"', "&quot;")
        .replace("'", "&#039;")
    )


def main() -> None:
    out_dir = Path("generated/startup_input_map")
    out_dir.mkdir(parents=True, exist_ok=True)
    input_map = build_map()
    (out_dir / "startup_input_map.json").write_text(json.dumps(input_map, indent=2) + "\n", encoding="utf-8")
    (out_dir / "startup_input_map.md").write_text(render_markdown(input_map), encoding="utf-8")
    (out_dir / "startup_input_map.html").write_text(render_html(input_map), encoding="utf-8")


if __name__ == "__main__":
    main()
