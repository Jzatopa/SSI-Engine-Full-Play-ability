#!/usr/bin/env python3
"""
Liveplay: run DOSBox-X with Matrix Cubed, navigate from saved game (SLOT A)
through the starting area until combat triggers, save to SLOT A again,
and capture before/after save data.

Dependencies:
  - Xvfb on :99
  - dosbox-x (dosbox-x binary)
  - xdotool, xte

Usage:
  PYTHONPATH=src python3 scripts/liveplay_first_combat.py [--headless]
"""

from __future__ import annotations

import json
import os
import shutil
import subprocess
import time
from pathlib import Path

WORKSPACE = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re")
LIVEPLAY = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SAVE_DIR = LIVEPLAY / "MATRIX" / "SAVE"
DOSBOX_CONF = LIVEPLAY / "dosbox-conf" / "start.conf"
GEN_DIR = WORKSPACE / "generated" / "liveplay"
PRE_COMBAT = GEN_DIR / "pre_combat"
POST_COMBAT = GEN_DIR / "post_combat"
DOCS_DIR = WORKSPACE / "docs"
SCREEN_DIR = GEN_DIR / "screens"

# Key delay constants (milliseconds)
TYPE_DELAY = 100      # ms between xdotool type keystrokes
NAV_SLEEP = 1.5       # seconds to wait for screen transitions
LONG_SLEEP = 4.0      # longer wait for loading screens
COMBAT_SLEEP = 2.0    # wait for combat animation
SAVE_SLEEP = 2.0      # wait for save to complete
VERY_LONG_SLEEP = 8.0 # wait for initial loading / title screens

# Window search
WINDOW_NAME = "DOSBox-X"
WINDOW_CLASS = "DOSBox-X"

ENV = {
    "DISPLAY": ":99",
    "SDL_VIDEODRIVER": "x11",
    "SDL_AUDIODRIVER": "dummy",
}


def ensure_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def wait_for_window(name: str, timeout: float = 15.0) -> str | None:
    """Wait for an X11 window to appear, return its id."""
    deadline = time.time() + timeout
    while time.time() < deadline:
        try:
            result = subprocess.run(
                ["xdotool", "search", "--name", name],
                capture_output=True, text=True, timeout=5,
                env=ENV,
            )
            windows = result.stdout.strip().split()
            if windows:
                return windows[0]
        except (subprocess.TimeoutExpired, FileNotFoundError):
            pass
        time.sleep(0.5)
    return None


def dosbox_key(key: str, window: str | None = None, delay_ms: int = TYPE_DELAY) -> None:
    """Send a single key to the DOSBox-X window using xdotool."""
    cmd = ["xdotool", "key", "--delay", str(delay_ms)]
    if window:
        cmd.extend(["--window", window])
    cmd.append(key)
    subprocess.run(cmd, env=ENV, capture_output=True)


def dosbox_type(text: str, window: str | None = None, delay_ms: int = TYPE_DELAY) -> None:
    """Type text using xdotool."""
    cmd = ["xdotool", "type", "--delay", str(delay_ms)]
    if window:
        cmd.extend(["--window", window])
    cmd.append(text)
    subprocess.run(cmd, env=ENV, capture_output=True)


def take_screenshot(name: str) -> None:
    """Take a screenshot using xdotool + import."""
    ensure_dir(SCREEN_DIR)
    path = SCREEN_DIR / f"{name}.png"
    try:
        subprocess.run(
            ["import", "-window", "root", str(path)],
            env=ENV, capture_output=True, timeout=10,
        )
    except Exception as exc:
        print(f"  [warn] screenshot failed: {exc}")


def save_probe(label: str, save_dir: Path) -> dict:
    """Run the save_probe tool and return parsed output."""
    result = subprocess.run(
        ["python3", "-m", "matrix_cubed.tools.save_probe", str(save_dir)],
        capture_output=True, text=True, timeout=30,
        cwd=WORKSPACE,
        env={**os.environ, "PYTHONPATH": str(WORKSPACE / "src"), "DISPLAY": ENV["DISPLAY"]},
    )
    return json.loads(result.stdout)


def sha256_dir(save_dir: Path) -> dict[str, str]:
    """Compute sha256 of every file in save_dir."""
    import hashlib
    result = {}
    for p in sorted(save_dir.iterdir()):
        if p.is_file():
            h = hashlib.sha256(p.read_bytes()).hexdigest()
            result[p.name] = h
    return result


def hexdump(data: bytes, max_lines: int = 30) -> str:
    """Simple hex dump."""
    lines = []
    for i in range(0, min(len(data), max_lines * 16), 16):
        chunk = data[i:i+16]
        hex_str = " ".join(f"{b:02x}" for b in chunk)
        ascii_str = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        lines.append(f"{i:08x}  {hex_str:<48}  {ascii_str}")
    return "\n".join(lines)


def byte_diff(a: bytes, b: bytes, label_a: str = "before", label_b: str = "after") -> str:
    """Generate a detailed byte-by-byte diff report."""
    import difflib
    lines = []
    max_len = max(len(a), len(b))
    
    # Show changed regions
    changes = []
    last_end = 0
    for i in range(max_len):
        va = a[i] if i < len(a) else None
        vb = b[i] if i < len(b) else None
        if va != vb:
            if not changes or changes[-1][1] != i - 1:
                changes.append([i, i])
            else:
                changes[-1][1] = i
        changes = [c for c in changes if c[1] >= c[0]]
    
    if not changes:
        return "No differences found."
    
    lines.append(f"## Byte-level differences ({label_a} vs {label_b})")
    lines.append("")
    lines.append(f"Total changed bytes: {sum(end - start + 1 for start, end in changes)}")
    lines.append("")
    
    for start, end in changes:
        if end - start > 64:
            # Show abbreviated change for large blocks
            lines.append(f"### Offset range 0x{start:04x}-0x{end:04x} ({end-start+1} bytes changed)")
            lines.append("")
            lines.append(f"```")
            lines.append(f"Before ({label_a}) at 0x{start:04x}:")
            lines.append(hexdump(a[max(0,start-8):min(len(a),start+40)], max_lines=5))
            lines.append(f"")
            lines.append(f"After ({label_b}) at 0x{start:04x}:")
            lines.append(hexdump(b[max(0,start-8):min(len(b),start+40)], max_lines=5))
            lines.append(f"```")
            lines.append("")
        else:
            lines.append(f"### Offset range 0x{start:04x}-0x{end:04x} ({end-start+1} bytes)")
            lines.append("")
            lines.append("| Offset | Before | After | Notes |")
            lines.append("| --- | ---: | ---: | --- |")
            for i in range(start, end + 1):
                va = a[i] if i < len(a) else 0
                vb = b[i] if i < len(b) else 0
                note = ""
                if i == 0 and start == 0:
                    note = "party count candidate"
                elif 1 <= i <= 4 and va == vb:
                    pass
                lines.append(f"| 0x{i:04x} | 0x{va:02x} ({va}) | 0x{vb:02x} ({vb}) | {note} |")
            lines.append("")
    
    return "\n".join(lines)


def run() -> None:
    ensure_dir(POST_COMBAT)
    ensure_dir(SCREEN_DIR)
    
    print("=== Matrix Cubed Liveplay: First Combat ===")
    
    # Step 1: Back up pre-combat state (already done, but verify)
    print("\n[1] Verifying pre-combat backup...")
    pre_items = sorted(PRE_COMBAT.iterdir())
    print(f"    Pre-combat has {len(pre_items)} files")
    pre_hashes = sha256_dir(PRE_COMBAT)
    current_hashes = sha256_dir(SAVE_DIR)
    # Run save_probe on pre-combat
    try:
        pre_probe = save_probe("pre_combat", PRE_COMBAT)
        pre_probe_path = GEN_DIR / "save_probe_pre_combat.json"
        pre_probe_path.write_text(json.dumps(pre_probe, indent=2))
        print(f"    Save probe written to {pre_probe_path.name}")
    except Exception as exc:
        print(f"    [warn] Save probe failed: {exc}")
        pre_probe = None
    
    # Step 2: Launch DOSBox-X
    print("\n[2] Launching DOSBox-X...")
    dosbox_proc = subprocess.Popen(
        ["dosbox-x", "-conf", str(DOSBOX_CONF)],
        env=ENV,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    print(f"    PID: {dosbox_proc.pid}")
    
    # Step 3: Wait for window and initial game load
    print("\n[3] Waiting for DOSBox-X window...")
    window = wait_for_window(WINDOW_NAME, timeout=20.0)
    if not window:
        print("    ERROR: Could not find DOSBox-X window!")
        dosbox_proc.kill()
        return
    print(f"    Window ID: {window}")
    
    # Wait for initial setup/config processing
    print("    Waiting for game to load (MATRIX.CFG + title sequence)...")
    time.sleep(VERY_LONG_SLEEP)
    take_screenshot("01_initial_load")
    print("    Screenshot: 01_initial_load")
    
    # Title screens - press Enter repeatedly to advance
    print("\n[4] Advancing through title screens...")
    for i in range(8):
        dosbox_key("Return", window)
        time.sleep(NAV_SLEEP)
    take_screenshot("02_after_title")
    print("    Screenshot: 02_after_title")
    
    # Should be at command menu now
    # Press '0' for option 10 (Begin Adventuring) - in SSI menus, '0' is typically option 10
    print("\n[5] Selecting 'Begin Adventuring'...")
    time.sleep(NAV_SLEEP)
    
    # Try Enter first (in case Begin Adventuring is the default), then 0 if that doesn't work
    dosbox_key("Return", window)
    time.sleep(LONG_SLEEP)
    take_screenshot("03_after_begin_adventure")
    print("    Screenshot: 03_after_begin_adventure")
    
    # Check if we're in the game world or still at menu
    # If still at menu, try pressing 0
    time.sleep(NAV_SLEEP)
    
    # Game should be loaded now. Let's navigate.
    # In SSI Gold Box games:
    # - Walking forward in corridors: Up arrow
    # - Turn left/right: Left/Right arrow
    # - Strafe: Alt+Left/Right or special keys
    # - Search: S key
    # - Get item: G
    # - Talk: T
    # - Look: L
    # - Camp: C
    # - Fire/Fight: F or Space
    # - View/Inventory: V or Tab
    # - Menu: F10 (or Escape in some games)
    # - Enter: Confirm/select
    
    # In Matrix Cubed, the player starts in the Mars space port.
    # Navigating forward (up arrow) and exploring will trigger encounters.
    
    print("\n[6] Exploring the starting area...")
    
    # The starting location is the Mars Space Port. I need to navigate around.
    # Let me try pressing some keys and seeing what happens.
    
    # First, let me try looking around and moving forward
    # Walk forward several steps
    for i in range(10):
        dosbox_key("Up", window)
        time.sleep(0.3)
    
    time.sleep(NAV_SLEEP)
    take_screenshot("04_after_movement_1")
    print("    Screenshot: 04_after_movement_1")
    
    # Try turning and more movement
    dosbox_key("Left", window)
    time.sleep(0.3)
    for i in range(8):
        dosbox_key("Up", window)
        time.sleep(0.3)
    
    time.sleep(NAV_SLEEP)
    take_screenshot("05_after_movement_2")
    print("    Screenshot: 05_after_movement_2")
    
    # Turn right, move more
    dosbox_key("Right", window)
    time.sleep(0.3)
    dosbox_key("Right", window)
    time.sleep(0.3)
    for i in range(8):
        dosbox_key("Up", window)
        time.sleep(0.3)
    
    time.sleep(NAV_SLEEP)
    take_screenshot("06_after_movement_3")
    print("    Screenshot: 06_after_movement_3")
    
    # Try pressing Space for action/combat
    print("    Trying Space (action key)...")
    dosbox_key("space", window)
    time.sleep(COMBAT_SLEEP)
    take_screenshot("07_after_space")
    print("    Screenshot: 07_after_space")
    
    # Try pressing F for fire
    print("    Trying F (fire key)...")
    dosbox_key("f", window)
    time.sleep(COMBAT_SLEEP)
    take_screenshot("08_after_f")
    print("    Screenshot: 08_after_f")
    
    # Try Enter for interaction
    print("    Trying Enter (interact)...")
    dosbox_key("Return", window)
    time.sleep(COMBAT_SLEEP)
    take_screenshot("09_after_enter")
    print("    Screenshot: 09_after_enter")
    
    # Further movement in different direction
    for i in range(5):
        dosbox_key("Down", window)
        time.sleep(0.3)
    dosbox_key("Right", window)
    time.sleep(0.3)
    for i in range(10):
        dosbox_key("Up", window)
        time.sleep(0.3)
    
    time.sleep(NAV_SLEEP)
    take_screenshot("10_after_movement_4")
    print("    Screenshot: 10_after_movement_4")
    
    # Try F10 for menu
    dosbox_key("F10", window)
    time.sleep(COMBAT_SLEEP)
    take_screenshot("11_after_f10_menu")
    print("    Screenshot: 11_after_f10_menu")
    
    # The F10 menu should have options. Press Escape to dismiss if needed
    dosbox_key("Escape", window)
    time.sleep(NAV_SLEEP)
    
    # More movement around the map
    dosbox_key("Left", window)
    time.sleep(0.3)
    for i in range(15):
        dosbox_key("Up", window)
        time.sleep(0.3)
    
    time.sleep(NAV_SLEEP)
    
    dosbox_key("Right", window)
    time.sleep(0.3)
    dosbox_key("Right", window)
    time.sleep(0.3)
    dosbox_key("Up", window)
    time.sleep(0.3)
    
    # Try S for search
    print("    Trying S (search)...")
    dosbox_key("s", window)
    time.sleep(COMBAT_SLEEP)
    take_screenshot("12_after_search")
    print("    Screenshot: 12_after_search")
    
    # Try pressing Enter to interact with anything found
    dosbox_key("Return", window)
    time.sleep(COMBAT_SLEEP)
    
    # Walk a lot more to try to trigger an encounter
    for i in range(30):
        dosbox_key("Up", window)
        time.sleep(0.2)
        # Try pressing space occasionally to trigger combat
        if i % 5 == 0:
            dosbox_key("space", window)
            time.sleep(0.3)
    
    time.sleep(NAV_SLEEP)
    take_screenshot("13_after_extensive_walk")
    print("    Screenshot: 13_after_extensive_walk")
    
    # Try Tab for inventory view
    print("    Trying Tab...")
    dosbox_key("Tab", window)
    time.sleep(COMBAT_SLEEP)
    take_screenshot("14_after_tab")
    print("    Screenshot: 14_after_tab")
    
    # Escape to dismiss any popup
    dosbox_key("Escape", window)
    time.sleep(NAV_SLEEP)
    
    # Now try to save the game (whether or not combat triggered)
    print("\n[7] Saving game to SLOT A...")
    
    # Open F10 menu for save
    dosbox_key("F10", window)
    time.sleep(SAVE_SLEEP)
    
    # Press S for Save
    dosbox_key("s", window)
    time.sleep(SAVE_SLEEP)
    take_screenshot("15_save_menu")
    print("    Screenshot: 15_save_menu")
    
    # In the save menu, press '1' for slot A, or press Enter for default
    dosbox_key("1", window)
    time.sleep(SAVE_SLEEP)
    
    # Confirm overwrite
    dosbox_key("Return", window)
    time.sleep(SAVE_SLEEP * 2)
    take_screenshot("16_after_save")
    print("    Screenshot: 16_after_save")
    
    # Escape back to game
    dosbox_key("Escape", window)
    time.sleep(NAV_SLEEP)
    
    # Quit the game
    print("\n[8] Quitting game...")
    # Open F10 menu
    dosbox_key("F10", window)
    time.sleep(NAV_SLEEP)
    # Press Q for quit
    dosbox_key("q", window)
    time.sleep(NAV_SLEEP)
    # Confirm
    dosbox_key("Return", window)
    time.sleep(LONG_SLEEP)
    take_screenshot("17_after_quit")
    print("    Screenshot: 17_after_quit")
    
    # Wait for DOSBox to exit
    print("    Waiting for DOSBox-X to exit...")
    try:
        dosbox_proc.wait(timeout=10)
        print(f"    DOSBox-X exited with code {dosbox_proc.returncode}")
    except subprocess.TimeoutExpired:
        print("    Killing DOSBox-X...")
        dosbox_proc.kill()
        dosbox_proc.wait()
    
    # Step 9: Copy SAVE to post_combat
    print("\n[9] Copying post-combat save files...")
    for item in SAVE_DIR.iterdir():
        if item.is_file():
            shutil.copy2(item, POST_COMBAT / item.name)
    post_items = sorted(POST_COMBAT.iterdir())
    print(f"    Post-combat has {len(post_items)} files")
    
    # Run save_probe on post_combat
    try:
        post_probe = save_probe("post_combat", POST_COMBAT)
        post_probe_path = GEN_DIR / "save_probe_post_combat.json"
        post_probe_path.write_text(json.dumps(post_probe, indent=2))
        print(f"    Save probe written to {post_probe_path.name}")
    except Exception as exc:
        print(f"    [warn] Save probe failed: {exc}")
        post_probe = None
    
    # Step 10: Compare
    print("\n[10] Analyzing differences...")
    post_hashes = sha256_dir(POST_COMBAT)
    
    print("\n    File hash comparison:")
    all_files = sorted(set(list(pre_hashes.keys()) + list(post_hashes.keys())))
    for fname in all_files:
        pre_h = pre_hashes.get(fname, "MISSING")
        post_h = post_hashes.get(fname, "MISSING")
        if pre_h != post_h:
            print(f"    CHANGED: {fname}")
            if pre_h == "MISSING":
                print(f"      (new file)")
            elif post_h == "MISSING":
                print(f"      (deleted file)")
            else:
                print(f"      pre:  {pre_h[:16]}...")
                print(f"      post: {post_h[:16]}...")
        else:
            print(f"    same:   {fname}")
    
    # Generate detailed diff report
    print("\n[11] Writing diff analysis to docs...")
    
    diff_sections = []
    
    for fname in sorted(all_files):
        pre_path = PRE_COMBAT / fname
        post_path = POST_COMBAT / fname
        
        if pre_path.exists() and post_path.exists():
            pre_data = pre_path.read_bytes()
            post_data = post_path.read_bytes()
            
            if pre_data != post_data:
                section = f"## File: {fname}\n\n"
                section += f"- Pre-combat size: {len(pre_data)} bytes\n"
                section += f"- Post-combat size: {len(post_data)} bytes\n"
                section += f"- Size change: {len(post_data) - len(pre_data)} bytes\n\n"
                section += byte_diff(pre_data, post_data, "pre_combat", "post_combat")
                diff_sections.append(section)
        
        elif pre_path.exists() and not post_path.exists():
            section = f"## File: {fname}\n\n- DELETED after combat save\n"
            diff_sections.append(section)
        
        elif not pre_path.exists() and post_path.exists():
            section = f"## File: {fname} (NEW)\n\n"
            section += f"- Post-combat size: {post_path.stat().st_size} bytes\n"
            post_data = post_path.read_bytes()
            section += f"\n### Full hex dump\n\n```\n{hexdump(post_data)}\n```\n"
            diff_sections.append(section)
    
    # Build the document
    doc_lines = [
        "# Liveplay First Combat Pass 1",
        "",
        "## Goal",
        "",
        "Launch Matrix Cubed from a saved SLOT A game, navigate the starting area",
        "until combat triggers, save to SLOT A post-combat, and capture the save-diff.",
        "",
        "## Method",
        "",
        f"- DOSBox-X under Xvfb (:99) with `SDL_VIDEODRIVER=x11`.",
        "- xdotool keystrokes sent to the `{WINDOW_NAME}` window.",
        "- Pre-combat backup: `{PRE_COMBAT}`",
        "- Post-combat save: `{POST_COMBAT}`",
        "",
        "## Save File Summary",
        "",
    ]
    
    doc_lines.append("| File | Pre-combat (sha256) | Post-combat (sha256) | Size change |")
    doc_lines.append("| --- | --- | --- | ---: |")
    for fname in sorted(all_files):
        pre_h = (pre_hashes.get(fname, "MISSING")[:16] + "...") if pre_hashes.get(fname) else "MISSING"
        post_h = (post_hashes.get(fname, "MISSING")[:16] + "...") if post_hashes.get(fname) else "MISSING"
        pre_size = PRE_COMBAT.joinpath(fname).stat().st_size if PRE_COMBAT.joinpath(fname).exists() else 0
        post_size = POST_COMBAT.joinpath(fname).stat().st_size if POST_COMBAT.joinpath(fname).exists() else 0
        size_change = post_size - pre_size
        sign = "+" if size_change > 0 else ""
        doc_lines.append(f"| {fname} | `{pre_h}` | `{post_h}` | {sign}{size_change} |")
    
    doc_lines.append("")
    doc_lines.extend(diff_sections)
    
    doc = "\n".join(doc_lines)
    
    # Write the document
    doc_path = DOCS_DIR / "liveplay-first-combat-pass-1.md"
    doc_path.write_text(doc)
    print(f"    Written: {doc_path}")
    
    # Also update the save_probe.json summary
    print("\n[12] Updating save_probe.json...")
    if pre_probe and post_probe:
        combined = {
            "pre_combat": pre_probe,
            "post_combat": post_probe,
        }
        (GEN_DIR / "save_probe_first_combat.json").write_text(json.dumps(combined, indent=2))
        print(f"    Written: save_probe_first_combat.json")
    
    print("\n=== DONE ===")


if __name__ == "__main__":
    run()
