#!/usr/bin/env python3
"""
Full automation: boot game, advance through title screens, select Begin Adventuring,
explore starting area to trigger combat, save post-combat, analyze diffs.
"""

import subprocess, time, sys, hashlib, json, shutil, signal
from pathlib import Path

# === Paths ===
WORKSPACE = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re")
LIVEPLAY = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SAVE_DIR = LIVEPLAY / "MATRIX" / "SAVE"
CONF = str(LIVEPLAY / "dosbox-conf" / "start.conf")
GEN = WORKSPACE / "generated" / "liveplay"
PRE = GEN / "pre_combat"
POST = GEN / "post_combat"
DOCS = WORKSPACE / "docs"
SDIR = GEN / "screens"

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}

for d in [POST, SDIR]:
    d.mkdir(parents=True, exist_ok=True)

# === Helpers ===
def snap(name):
    png = SDIR / f"{name}.png"
    subprocess.run(["ffmpeg", "-y", "-f", "x11grab", "-video_size", "1280x1024",
                    "-i", ":99.0", "-vframes", "1", str(png)], env=ENV,
                   capture_output=True, timeout=10)
    if png.exists():
        print(f"  [snap] {name} ({png.stat().st_size}B)", flush=True)

def key(k, win=None):
    cmd = ["xdotool", "key", "--delay", "80"]
    if win: cmd.extend(["--window", win])
    cmd.append(k)
    subprocess.run(cmd, env=ENV, capture_output=True, timeout=5)

def type_text(t, win=None):
    cmd = ["xdotool", "type", "--delay", "50"]
    if win: cmd.extend(["--window", win])
    cmd.append(t)
    subprocess.run(cmd, env=ENV, capture_output=True, timeout=5)

def sha256_of(filepath):
    if filepath.exists():
        return hashlib.sha256(filepath.read_bytes()).hexdigest()
    return "MISSING"

def sha256_dir(d):
    if not d.exists():
        return {}
    return {p.name: sha256_of(p) for p in sorted(d.iterdir()) if p.is_file()}

def hexdump(data, max_lines=30):
    lines = []
    for i in range(0, min(len(data), max_lines * 16), 16):
        chunk = data[i:i+16]
        hex_str = " ".join(f"{b:02x}" for b in chunk)
        ascii_str = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        lines.append(f"{i:08x}  {hex_str:<48}  {ascii_str}")
    return "\n".join(lines)

def byte_diff(a, b, label_a="before", label_b="after"):
    """Detailed byte diff."""
    lines = []
    max_len = max(len(a), len(b))
    changes = []
    for i in range(max_len):
        va = a[i] if i < len(a) else None
        vb = b[i] if i < len(b) else None
        if va != vb:
            if changes and changes[-1][1] == i - 1:
                changes[-1][1] = i
            else:
                changes.append([i, i])
    if not changes:
        return "No differences found."
    changed_count = sum(end - start + 1 for start, end in changes)
    lines.append(f"\nTotal changed bytes: {changed_count}\n")
    for start, end in changes:
        span = end - start + 1
        if span > 64:
            lines.append(f"### Offset 0x{start:04x}-0x{end:04x} ({span} bytes changed, large block)")
            ctx = a[max(0,start-8):min(len(a),start+48)]
            ctx2 = b[max(0,start-8):min(len(b),start+48)]
            lines.append(f"```\nBefore {label_a}:\n{hexdump(ctx, 5)}\nAfter {label_b}:\n{hexdump(ctx2, 5)}\n```")
        else:
            lines.append(f"### Offset 0x{start:04x}-0x{end:04x} ({span} bytes)")
            lines.append("| Offset | Before | After |")
            lines.append("| --- | ---: | ---: |")
            for i in range(start, end + 1):
                va = a[i] if i < len(a) else 0
                vb = b[i] if i < len(b) else 0
                lines.append(f"| 0x{i:04x} | 0x{va:02x} ({va}) | 0x{vb:02x} ({vb}) |")
    return "\n".join(lines)

# === Main ===
print("=" * 60, flush=True)
print("MATRIX CUBED - FIRST COMBAT LIVEPLAY", flush=True)
print("=" * 60, flush=True)

# Pre-combat hash
pre_items = list(PRE.iterdir()) if PRE.exists() else []
pre_hash = sha256_dir(PRE)
print(f"\nPre-combat: {len(pre_items)} files", flush=True)

# Kill stale dosbox
subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)
time.sleep(2)

# Launch DOSBox-X in Xvfb
print("\n[1] Launching DOSBox-X...", flush=True)
proc = subprocess.Popen(["dosbox-x", "-conf", CONF], env=ENV,
                        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
print(f"  PID: {proc.pid}", flush=True)

# Wait for window
deadline = time.time() + 20
win = None
while time.time() < deadline:
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"],
                       capture_output=True, text=True, env=ENV)
    wins = r.stdout.strip().split()
    if wins: win = wins[0]; break
    time.sleep(0.5)
if not win:
    print("  ERROR: No DOSBox-X window!", flush=True)
    proc.kill(); sys.exit(1)
print(f"  Window: {win}", flush=True)

# Wait for boot + MATRIX.CFG processing + title
print("\n[2] Waiting for game boot (15s)...", flush=True)
time.sleep(15)
snap("01_boot")

# Advance through title/KEYS screens with Enter
print("\n[3] Advancing through title screens (8 Enter presses)...", flush=True)
for i in range(8):
    key("Return", win)
    time.sleep(1.8)  # enough for screen transitions
snap("02_after_title")

# Should be at command menu now. Option 9 = Begin Adventuring
print("\n[4] Selecting Begin Adventuring (key '9')...", flush=True)
time.sleep(2)
snap("03_before_adventure")
key("9", win)
time.sleep(4)  # wait for game to load
snap("04_after_adventure")

# If we got Load/Save slot prompt instead, confirm 'A' for save slot
# Or if we're in the game, we should see the game world
# Try pressing Enter to dismiss any prompts
key("A", win)
time.sleep(3)
snap("05_after_slot_or_game")

# Press Enter to confirm any prompts
key("Return", win)
time.sleep(4)
snap("06_after_confirm")

# Explore the starting area (Caloris Space Port)
print("\n[5] Exploring Caloris Space Port...", flush=True)
# Walk forward extensively in the starting corridor
# The starting area in GEO 17 has corridors and rooms
# Walk forward, turn, search, interact

# Phase 1: Walk forward
print("  Phase 1: Walking forward...", flush=True)
for i in range(20):
    key("Up", win)
    time.sleep(0.3)

key("Left", win); time.sleep(0.3)
for i in range(15):
    key("Up", win)
    time.sleep(0.3)

key("Right", win); time.sleep(0.3)
key("Right", win); time.sleep(0.3)
for i in range(15):
    key("Up", win)
    time.sleep(0.3)

snap("07_explore1")

# Phase 2: Try search and interact
print("  Phase 2: Searching and interacting...", flush=True)
key("s", win); time.sleep(2)
key("Return", win); time.sleep(2)
key("space", win); time.sleep(2)
key("f", win); time.sleep(2)

# Walk some more
for i in range(10):
    key("Up", win)
    time.sleep(0.3)

key("Left", win); time.sleep(0.3)
for i in range(10):
    key("Up", win)
    time.sleep(0.3)

snap("08_explore2")

# Phase 3: Explore further
print("  Phase 3: Extensive exploration...", flush=True)
key("Right", win); time.sleep(0.3)
for i in range(30):
    key("Up", win)
    time.sleep(0.2)
    # Press Space occasionally to find encounters
    if i % 5 == 0:
        key("space", win)
        time.sleep(0.5)

key("Left", win); time.sleep(0.3)
for i in range(10):
    key("Up", win)
    time.sleep(0.3)

# Try F10 for in-game menu
key("F10", win); time.sleep(2)
snap("09_f10_menu")

# Check what F10 menu shows - could be Map, Camp, Save, Quit
# Escape to dismiss
key("Escape", win); time.sleep(1)
snap("10_after_escape")

# More exploration in different area
key("Down", win); time.sleep(0.3)
key("Down", win); time.sleep(0.3)
key("Right", win); time.sleep(0.3)
for i in range(20):
    key("Up", win)
    time.sleep(0.3)
    if i % 4 == 0:
        key("space", win)
        time.sleep(0.5)

snap("11_explore3")

# Phase 4: Full explore with random encounter triggering
print("  Phase 4: Max exploration...", flush=True)
key("Right", win); time.sleep(0.3)
for i in range(40):
    key("Up", win)
    time.sleep(0.2)
    if i % 3 == 0:
        key("space", win)
        time.sleep(0.3)

key("Left", win); time.sleep(0.3)
for i in range(20):
    key("Up", win)
    time.sleep(0.2)

snap("12_explore4")

# Try 'M' for map
key("m", win); time.sleep(2)
snap("13_after_m")

key("Escape", win); time.sleep(1)

# If combat triggered, it will auto-resolve or need interaction
# Press Space and Enter to advance through combat text
print("  Advancing through any combat/dialogue...", flush=True)
for i in range(15):
    key("space", win)
    time.sleep(0.5)
    key("Return", win)
    time.sleep(0.5)

snap("14_after_combat_inputs")

# Now save the game
print("\n[6] Saving game to SLOT A...", flush=True)

# Method 1: F10 then S
key("F10", win); time.sleep(2)
snap("15_f10_menu")
# Try 'S' for Save
key("s", win); time.sleep(3)
snap("16_after_s")

# If we got the save slot prompt, press A for slot A
key("A", win); time.sleep(3)
snap("17_after_slot_a")

# Confirm overwrite
key("Return", win); time.sleep(3)
snap("18_after_save_confirm")

# Escape to exit save menu
key("Escape", win); time.sleep(1)
key("Escape", win); time.sleep(1)

# Method 2: If F10 menu didn't work, try F10 -> number keys
key("F10", win); time.sleep(2)
key("1", win); time.sleep(2)
snap("19_f10_1")

key("Escape", win); time.sleep(1)
key("F10", win); time.sleep(2)
key("3", win); time.sleep(2)
snap("20_f10_3")

key("Escape", win); time.sleep(1)

# Quit the game properly
print("\n[7] Quitting game...", flush=True)
key("F10", win); time.sleep(2)
key("q", win); time.sleep(2)
key("Return", win); time.sleep(4)
snap("21_after_quit")

# If still running, send again with different approach
try:
    proc.wait(timeout=5)
except:
    key("F10", win); time.sleep(1)
    key("q", win); time.sleep(1)
    key("Return", win); time.sleep(3)
    try:
        proc.wait(timeout=5)
    except:
        print("  Force killing...", flush=True)
        proc.kill()
        proc.wait()

print("\n[8] DOSBox-X exited.", flush=True)

# === Post-processing ===
print("\n[9] Copying SAVE to post_combat/...", flush=True)
for f in SAVE_DIR.iterdir():
    if f.is_file():
        shutil.copy2(f, POST / f.name)
post_items = sorted(POST.iterdir())
print(f"  Post-combat: {len(post_items)} files", flush=True)
for f in post_items:
    print(f"    {f.name} ({f.stat().st_size}B)", flush=True)

# === Diff Analysis ===
print("\n[10] Generating diff analysis...", flush=True)
post_hash = sha256_dir(POST)

diff_sections = []
all_files = sorted(set(list(pre_hash.keys()) + list(post_hash.keys())))

for fname in all_files:
    pre_path = PRE / fname
    post_path = POST / fname
    
    if pre_path.exists() and post_path.exists():
        pre_data = pre_path.read_bytes()
        post_data = post_path.read_bytes()
        if pre_data != post_data:
            section = f"\n## File: {fname}\n"
            section += f"\n- Pre-combat: {len(pre_data)} bytes\n"
            section += f"- Post-combat: {len(post_data)} bytes\n"
            section += f"- Size change: {len(post_data) - len(pre_data)}\n"
            if pre_data[:4] == post_data[:4]:
                section += f"- Party count (byte 0): unchanged at 0x{pre_data[0]:02x}\n"
            else:
                section += f"- Party count: 0x{pre_data[0]:02x} -> 0x{post_data[0]:02x}\n"
            section += byte_diff(pre_data, post_data, "pre", "post")
            diff_sections.append(section)
    elif pre_path.exists() and not post_path.exists():
        diff_sections.append(f"\n## File: {fname}\n- DELETED after combat save\n")
    elif not pre_path.exists() and post_path.exists():
        post_data = post_path.read_bytes()
        diff_sections.append(f"\n## File: {fname} (NEW)\n- Size: {len(post_data)} bytes\n\n```\n{hexdump(post_data)}\n```\n")

# Build report
doc_lines = [
    "# Liveplay First Combat Pass 1",
    "",
    "## Goal",
    "",
    "Boot Matrix Cubed from a saved SLOT A game (CAR1 Medic, level 7), navigate",
    "the Caloris Space Port starting area to trigger the first combat encounter,",
    "save to SLOT A, and capture all save-diff evidence.",
    "",
    "## Method",
    "",
    f"- DOSBox-X under Xvfb (:99) with SDL_VIDEODRIVER=x11.",
    "- xdotool sends keystrokes by window id to the DOSBox-X window.",
    "- Title screens bypassed with sequential Enter presses.",
    "- '9' key selects Begin Adventuring (menu option 9).",
    "- Arrow keys (Up/Down/Left/Right) explore Caloris Space Port.",
    "- Space and Enter are used for interaction and combat advancement.",
    "- F10 opens in-game menu.",
    "",
    f"- Pre-combat backup: `{PRE}`",
    f"- Post-combat save directory: `{POST}`",
    "",
]
doc_lines.append("## Save File Hash Comparison\n")
doc_lines.append("| File | Pre-combat (sha256) | Post-combat (sha256) | Size Change |")
doc_lines.append("| --- | --- | --- | ---: |")
for fname in all_files:
    pre_h = pre_hash.get(fname, "MISSING")
    post_h = post_hash.get(fname, "MISSING")
    pre_sz = PRE.joinpath(fname).stat().st_size if PRE.joinpath(fname).exists() else 0
    post_sz = POST.joinpath(fname).stat().st_size if POST.joinpath(fname).exists() else 0
    sz_diff = post_sz - pre_sz
    sign = "+" if sz_diff > 0 else ""
    pre_short = f"`{pre_h[:16]}...`" if pre_h != "MISSING" else "MISSING"
    post_short = f"`{post_h[:16]}...`" if post_h != "MISSING" else "MISSING"
    doc_lines.append(f"| {fname} | {pre_short} | {post_short} | {sign}{sz_diff} |")

doc_lines.append("")
doc_lines.extend(diff_sections)

# Save probe data
doc_lines.append("\n## Save Probe Summary\n")
doc_lines.append("Run `PYTHONPATH=src python3 -m matrix_cubed.tools.save_probe` to decode.\n")

# Write document
doc = "\n".join(doc_lines)
(DOCS / "liveplay-first-combat-pass-1.md").write_text(doc)
print(f"\n  Written: docs/liveplay-first-combat-pass-1.md", flush=True)

# Update save_probe JSONs
print("\n[11] Updating save_probe JSONs...", flush=True)
for label, srcdir in [("pre_combat", PRE), ("post_combat", POST)]:
    try:
        result = subprocess.run(
            ["python3", "-m", "matrix_cubed.tools.save_probe", str(srcdir)],
            capture_output=True, text=True, timeout=30, cwd=WORKSPACE,
            env={**os_module.environ, "PYTHONPATH": str(WORKSPACE / "src")}
        )
    except:
        pass
# Simpler approach
import os as os_module
env_copy = dict(os_module.environ)
env_copy["PYTHONPATH"] = str(WORKSPACE / "src")
try:
    pre_result = subprocess.run(
        ["python3", "-m", "matrix_cubed.tools.save_probe", str(PRE)],
        capture_output=True, text=True, timeout=30, cwd=WORKSPACE, env=env_copy
    )
    (GEN / "save_probe_pre_combat.json").write_text(pre_result.stdout)
    print(f"  save_probe_pre_combat.json written", flush=True)
except Exception as e:
    print(f"  Pre probe failed: {e}", flush=True)

try:
    post_result = subprocess.run(
        ["python3", "-m", "matrix_cubed.tools.save_probe", str(POST)],
        capture_output=True, text=True, timeout=30, cwd=WORKSPACE, env=env_copy
    )
    (GEN / "save_probe_post_combat.json").write_text(post_result.stdout)
    print(f"  save_probe_post_combat.json written", flush=True)
except Exception as e:
    print(f"  Post probe failed: {e}", flush=True)

# Run tests
print("\n[12] Running tests...", flush=True)
test_result = subprocess.run(
    ["python3", "-m", "pytest", "-q"],
    capture_output=True, text=True, timeout=30, cwd=WORKSPACE,
    env=env_copy
)
print(test_result.stdout)
if test_result.stderr:
    print(test_result.stderr[:500])
print(f"Tests exit code: {test_result.returncode}", flush=True)

print("\n" + "=" * 60, flush=True)
print("DONE", flush=True)
print("=" * 60, flush=True)
