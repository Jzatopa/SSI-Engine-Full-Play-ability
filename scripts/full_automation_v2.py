#!/usr/bin/env python3
"""
Clean Matrix Cubed automation with proper DOSBox-X handling.
"""

import subprocess, time, sys, hashlib, json, shutil, os
from pathlib import Path

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
for d in [POST, SDIR, PRE]: d.mkdir(parents=True, exist_ok=True)

def snap(name):
    png = SDIR / f"{name}.png"
    subprocess.run(["ffmpeg", "-y", "-f", "x11grab", "-video_size", "1280x1024",
                    "-i", ":99.0", "-vframes", "1", str(png)], env=ENV, capture_output=True, timeout=10)
    sz = png.stat().st_size if png.exists() else 0
    print(f"  [snap] {name} ({sz}B)", flush=True)

def key(k, win=None):
    cmd = ["xdotool", "key", "--delay", "80"]
    if win: cmd.extend(["--window", win])
    cmd.append(k)
    subprocess.run(cmd, env=ENV, capture_output=True, timeout=5)

def wait_for_window(name, timeout=20):
    deadline = time.time() + timeout
    while time.time() < deadline:
        r = subprocess.run(["xdotool", "search", "--name", name], capture_output=True, text=True, env=ENV)
        wins = r.stdout.strip().split()
        if wins: return wins[0]
        time.sleep(0.5)
    return None

def sha256_dir(d):
    if not d.exists(): return {}
    return {p.name: hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(d.iterdir()) if p.is_file()}

def hexdump(data, max_lines=30):
    lines = []
    for i in range(0, min(len(data), max_lines * 16), 16):
        chunk = data[i:i+16]; h = " ".join(f"{b:02x}" for b in chunk)
        a = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        lines.append(f"{i:08x}  {h:<48}  {a}")
    return "\n".join(lines)

def byte_diff(a, b):
    lines = []; max_len = max(len(a), len(b)); changes = []
    for i in range(max_len):
        va = a[i] if i < len(a) else None; vb = b[i] if i < len(b) else None
        if va != vb:
            if changes and changes[-1][1] == i - 1: changes[-1][1] = i
            else: changes.append([i, i])
    if not changes: return "No differences found."
    count = sum(e-s+1 for s,e in changes)
    lines.append(f"\nTotal changed bytes: {count}\n")
    for start, end in changes:
        span = end - start + 1
        if span > 64:
            lines.append(f"### 0x{start:04x}-0x{end:04x} ({span}B, large block)")
            ctx = a[max(0,start-8):min(len(a),start+48)]
            ctx2 = b[max(0,start-8):min(len(b),start+48)]
            lines.append(f"```\nPre:\n{hexdump(ctx, 5)}\nPost:\n{hexdump(ctx2, 5)}\n```")
        else:
            lines.append(f"### 0x{start:04x}-0x{end:04x} ({span}B)")
            lines.append("| Offset | Pre | Post |")
            lines.append("| --- | ---: | ---: |")
            for i in range(start, end+1):
                va = a[i] if i < len(a) else 0; vb = b[i] if i < len(b) else 0
                lines.append(f"| 0x{i:04x} | 0x{va:02x} ({va}) | 0x{vb:02x} ({vb}) |")
    return "\n".join(lines)

print("=" * 60, flush=True)
print("MATRIX CUBED - FIRST COMBAT LIVEPLAY v2", flush=True)
print("=" * 60, flush=True)

pre_hash = sha256_dir(PRE)
print(f"\nPre-combat: {len(pre_hash)} files", flush=True)

# Clean: kill only specific known PIDs, avoid pkill
old_pids = subprocess.run(["pgrep", "-f", "dosbox-x"], capture_output=True, text=True, env=ENV)
for pid_str in old_pids.stdout.strip().split():
    if pid_str:
        subprocess.run(["kill", pid_str], capture_output=True, timeout=5, env=ENV)
        time.sleep(0.5)
time.sleep(3)

# Launch DOSBox-X
print("\n[1] Launching DOSBox-X...", flush=True)
proc = subprocess.Popen(["dosbox-x", "-conf", CONF], env=ENV, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
print(f"  PID: {proc.pid}", flush=True)

win = wait_for_window("DOSBox-X", timeout=20)
if not win: print("ERROR: No window!"); proc.kill(); sys.exit(1)
print(f"  Window: {win}", flush=True)

time.sleep(15)
snap("01_boot")

# Dismiss any quit dialog from previous runs
key("Escape", win); time.sleep(1)
key("Escape", win); time.sleep(1)
snap("02_after_dismiss")

# Advance through title/credits screens
print("\n[2] Title screens...", flush=True)
for i in range(10):
    key("Return", win); time.sleep(1.5)
snap("03_after_title")

# We should now see MATRIX CUBED V1.0 with PLAY/DEMO
# Press Enter for PLAY
print("\n[3] Select PLAY...", flush=True)
key("Return", win); time.sleep(3)
snap("04_after_play")

# Now we should see the command menu (CREATE NEW CHARACTER, PURGE, etc.)
# CAR1 should already be visible as the active character
# Press 9 for Begin Adventuring
print("\n[4] Begin Adventuring...", flush=True)
key("9", win); time.sleep(3)
snap("05_after_adventure")

# Might see "LOAD WHICH GAME: A B C..." or go directly
key("A", win); time.sleep(3)
snap("06_after_slot")

key("Return", win); time.sleep(4)
snap("07_after_confirm")

# Check: are we in the game world?
# Try F10 for in-game menu
key("F10", win); time.sleep(2)
snap("08_f10")

# Explore
print("\n[5] Exploring...", flush=True)
for i in range(30):
    key("Up", win); time.sleep(0.25)
    if i % 5 == 0:
        key("space", win); time.sleep(0.5)
snap("09_explore1")

key("Left", win); time.sleep(0.3)
for i in range(20):
    key("Up", win); time.sleep(0.25)
    if i % 5 == 0:
        key("space", win); time.sleep(0.5)
snap("10_explore2")

# Try search
key("s", win); time.sleep(1)
key("Return", win); time.sleep(2)

# More movement
key("Right", win); time.sleep(0.3)
key("Right", win); time.sleep(0.3)
for i in range(30):
    key("Up", win); time.sleep(0.25)
    if i % 3 == 0:
        key("space", win); time.sleep(0.4)
snap("11_explore3")

# Press Enter many times to advance any combat text
for i in range(20):
    key("Return", win); time.sleep(0.3)
    key("space", win); time.sleep(0.3)

key("Escape", win); time.sleep(1)
snap("12_after_interaction")

# Save game
print("\n[6] Saving...", flush=True)
key("F10", win); time.sleep(2)
snap("13_f10")
key("s", win); time.sleep(3)
snap("14_save")
key("A", win); time.sleep(3)
snap("15_slot")
key("Return", win); time.sleep(4)
snap("16_saved")
key("Escape", win); time.sleep(2)
key("Escape", win); time.sleep(2)

# Quit
print("\n[7] Quitting...", flush=True)
key("F10", win); time.sleep(2)
snap("17_f10_quit")
key("q", win); time.sleep(2)
key("Return", win); time.sleep(4)
snap("18_quit")

try: proc.wait(timeout=8)
except: proc.kill()

print("\n[8] Post-processing...", flush=True)
for f in SAVE_DIR.iterdir():
    if f.is_file(): shutil.copy2(f, POST / f.name)
post_hash = sha256_dir(POST)

# Compare
print("\n[9] Diff analysis...", flush=True)
diff_sections = []
all_files = sorted(set(list(pre_hash.keys()) + list(post_hash.keys())))
for fname in all_files:
    pre_path = PRE / fname; post_path = POST / fname
    if pre_path.exists() and post_path.exists():
        a, b = pre_path.read_bytes(), post_path.read_bytes()
        if a != b:
            s = f"\n## {fname}\n- Pre: {len(a)}B, Post: {len(b)}B, Change: {len(b)-len(a)}\n"
            s += byte_diff(a, b); diff_sections.append(s)
    elif pre_path.exists() and not post_path.exists():
        diff_sections.append(f"\n## {fname}\n- DELETED\n")
    elif not pre_path.exists() and post_path.exists():
        data = post_path.read_bytes()
        diff_sections.append(f"\n## {fname} (NEW)\n- {len(data)}B\n\n```\n{hexdump(data)}\n```\n")

doc = [ "# Liveplay First Combat Pass 1\n", "## Goal\n", "Boot Matrix Cubed from SLOT A (CAR1 Medic, level 7), explore Caloris Space Port to", "trigger combat, save post-combat, and diff save data.\n", "## Method\n", "- DOSBox-X under Xvfb :99 via xdotool keystrokes", "- Enter advances title/credit screens", "- Return at MATRIX CUBED V1.0 selects PLAY", "- '9' selects Begin Adventuring, 'A' chooses slot A", "- Arrow keys + Space/Enter explore and interact", "- F10 -> S -> A -> Enter to save\n", "## File Changes\n" ]
doc.append("| File | Pre | Post | Change |\n| --- | --- | --- | ---: |")
for fname in all_files:
    pre_sz = PRE.joinpath(fname).stat().st_size if PRE.joinpath(fname).exists() else 0
    post_sz = POST.joinpath(fname).stat().st_size if POST.joinpath(fname).exists() else 0
    ph = (pre_hash.get(fname,"MISSING")[:16]+"...") if pre_hash.get(fname) else "MISSING"
    pp = (post_hash.get(fname,"MISSING")[:16]+"...") if post_hash.get(fname) else "MISSING"
    doc.append(f"| {fname} | `{ph}` | `{pp}` | {post_sz-pre_sz:+d} |")
doc.append(""); doc.extend(diff_sections)
(DOCS / "liveplay-first-combat-pass-1.md").write_text("\n".join(doc))
print(f"  Written: docs/liveplay-first-combat-pass-1.md", flush=True)

# Save probes
env_copy = dict(os.environ); env_copy["PYTHONPATH"] = str(WORKSPACE / "src")
subprocess.run(["python3","-m","matrix_cubed.tools.save_probe",str(PRE)], capture_output=True,text=True,timeout=30,cwd=WORKSPACE,env=env_copy)
try:
    r = subprocess.run(["python3","-m","matrix_cubed.tools.save_probe",str(POST)], capture_output=True,text=True,timeout=30,cwd=WORKSPACE,env=env_copy)
    (GEN/"save_probe_post_combat.json").write_text(r.stdout or "{}")
except: pass
try:
    r = subprocess.run(["python3","-m","matrix_cubed.tools.save_probe",str(PRE)], capture_output=True,text=True,timeout=30,cwd=WORKSPACE,env=env_copy)
    (GEN/"save_probe_pre_combat.json").write_text(r.stdout or "{}")
except: pass

# Tests
print("\n[10] Tests...", flush=True)
r = subprocess.run(["python3","-m","pytest","-q"], capture_output=True,text=True,timeout=30,cwd=WORKSPACE,env=env_copy)
print(r.stdout or "", flush=True)
if r.returncode != 0: print(f"  Tests: {r.returncode} failures", flush=True)
else: print("  All tests passed!", flush=True)

print("\n=== DONE ===", flush=True)
