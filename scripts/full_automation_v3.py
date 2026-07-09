#!/usr/bin/env python3
"""
Final Matrix Cubed automation: proper config, boot to game world, explore, combat, save.
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
for d in [POST, SDIR]: d.mkdir(parents=True, exist_ok=True)

def snap(name):
    png = SDIR / f"f_{name}.png"
    subprocess.run(["ffmpeg","-y","-f","x11grab","-video_size","1280x1024","-i",":99.0","-vframes","1",str(png)], env=ENV,capture_output=True,timeout=10)
    sz = png.stat().st_size if png.exists() else 0
    print(f"  [snap] {name} ({sz}B)", flush=True)

def key(k, win=None):
    cmd = ["xdotool","key","--delay","80"]
    if win: cmd.extend(["--window", win])
    cmd.append(k)
    subprocess.run(cmd, env=ENV, capture_output=True, timeout=5)

def wait_win(name="DOSBox-X", t=25):
    d = time.time() + t
    while time.time() < d:
        r = subprocess.run(["xdotool","search","--name",name], capture_output=True,text=True,env=ENV)
        ws = r.stdout.strip().split()
        if ws: return ws[0]
        time.sleep(0.5)
    return None

def sha256_dir(d):
    if not d.exists(): return {}
    return {p.name: hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(d.iterdir()) if p.is_file()}

def hexdump(data, ml=30):
    lines = []
    for i in range(0, min(len(data), ml*16), 16):
        chunk = data[i:i+16]
        lines.append(f"{i:08x}  {' '.join(f'{b:02x}' for b in chunk):<48}  {''.join(chr(b) if 32<=b<127 else '.' for b in chunk)}")
    return "\n".join(lines)

def byte_diff(a, b):
    lines = []; ml = max(len(a),len(b)); ch = []
    for i in range(ml):
        va = a[i] if i<len(a) else None; vb = b[i] if i<len(b) else None
        if va != vb:
            if ch and ch[-1][1]==i-1: ch[-1][1]=i
            else: ch.append([i,i])
    if not ch: return "No differences."
    total = sum(e-s+1 for s,e in ch)
    lines.append(f"\nTotal changed: {total}B\n")
    for s,e in ch:
        span = e-s+1
        if span > 64:
            lines.append(f"### 0x{s:04x}-0x{e:04x} ({span}B)")
            lines.append(f"```\nPre:\n{hexdump(a[max(0,s-8):min(len(a),s+48)],5)}\nPost:\n{hexdump(b[max(0,s-8):min(len(b),s+48)],5)}\n```")
        else:
            lines.append(f"### 0x{s:04x}-0x{e:04x} ({span}B)")
            lines.append("| Offset | Pre | Post |")
            lines.append("| --- | ---: | ---: |")
            for i in range(s, e+1):
                va = a[i] if i<len(a) else 0; vb = b[i] if i<len(b) else 0
                lines.append(f"| 0x{i:04x} | 0x{va:02x} ({va}) | 0x{vb:02x} ({vb}) |")
    return "\n".join(lines)

print("="*60, flush=True)
print("MATRIX CUBED - FIRST COMBAT LIVEPLAY v3", flush=True)
print("="*60, flush=True)

pre_hash = sha256_dir(PRE)
print(f"\nPre-combat: {len(pre_hash)} files in {PRE}", flush=True)

# Kill stale dosbox
subprocess.run(["kill"] + [p for p in (subprocess.run(["pgrep","-f","dosbox-x"],capture_output=True,text=True,env=ENV).stdout.strip().split()) if p], capture_output=True, env=ENV)
time.sleep(2)

# Launch
print("\n[1] Launching DOSBox-X...", flush=True)
proc = subprocess.Popen(["dosbox-x","-conf",CONF], env=ENV, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
win = wait_win()
if not win: print("ERROR: no window"); proc.kill(); sys.exit(1)
print(f"  PID={proc.pid} Window={win}", flush=True)

time.sleep(15)
snap("00_boot")

# Dismiss any dialog
key("Escape",win); time.sleep(1)
snap("01_after_esc")

# Advance through titles (need enough Enter presses for all screens)
print("\n[2] Title/credits/PLAY/DEMO...", flush=True)
for i in range(15):
    key("Return",win); time.sleep(1.5)
snap("02_after_titles")

# Should now be in the game world (PLAY was selected, saved game loaded)
# Explore!
print("\n[3] Exploring Caloris Space Port...", flush=True)

# Walk forward a lot
for phase in range(5):
    for _ in range(30):
        key("Up",win); time.sleep(0.2)
        if _ % 5 == 0:
            key("space",win); time.sleep(0.4)
    if phase % 2 == 0:
        key("Left",win); time.sleep(0.3)
    else:
        key("Right",win); time.sleep(0.3)
    snap(f"03_explore_p{phase}")

# Try searching
key("s",win); time.sleep(1); key("Return",win); time.sleep(2)
snap("04_after_search")

# More walking + trying Space for interactions
for _ in range(50):
    key("Up",win); time.sleep(0.2)
    if _ % 3 == 0: key("space",win); time.sleep(0.3)
    if _ % 7 == 0: key("Return",win); time.sleep(0.3)
snap("05_explore_deep")

# Try F10 for game menu
key("F10",win); time.sleep(2)
snap("06_f10_menu")

# Escape out
key("Escape",win); time.sleep(2)
snap("07_after_esc_menu")

# More movement trying to find enemies
for _ in range(40):
    key("Up",win); time.sleep(0.2)
    if _ % 4 == 0: key("space",win); time.sleep(0.4)
    if _ % 6 == 0: key("f",win); time.sleep(0.3)
snap("08_explore_final")

# Try Tab for inventory
key("Tab",win); time.sleep(2)
snap("09_tab")
key("Escape",win); time.sleep(2)

# Save - F10 -> S -> A -> Enter
print("\n[4] Saving game...", flush=True)
key("F10",win); time.sleep(2)
snap("10_f10")
key("s",win); time.sleep(3)
snap("11_f10_s")
key("A",win); time.sleep(3)
snap("12_slot_a")
key("Return",win); time.sleep(4)
snap("13_save_confirm")
key("Escape",win); time.sleep(2)

# Quit
print("\n[5] Quitting...", flush=True)
key("F10",win); time.sleep(2)
snap("14_f10_quit")
key("q",win); time.sleep(2)
key("Return",win); time.sleep(4)
snap("15_quit")

try: proc.wait(timeout=8)
except:
    try: proc.terminate(); proc.wait(timeout=3)
    except: proc.kill()

print("\n[6] Post-processing...", flush=True)
for f in SAVE_DIR.iterdir():
    if f.is_file(): shutil.copy2(f, POST / f.name)
post_hash = sha256_dir(POST)

# Diff analysis
print("\n[7] Diff analysis...", flush=True)
diff_sections = []
all_files = sorted(set(list(pre_hash.keys()) + list(post_hash.keys())))
for fname in all_files:
    pp = PRE/fname; qp = POST/fname
    if pp.exists() and qp.exists():
        a,b = pp.read_bytes(), qp.read_bytes()
        if a != b:
            s = f"\n## {fname}\n- Pre: {len(a)}B, Post: {len(b)}B, Change: {len(b)-len(a)}\n"
            s += byte_diff(a,b); diff_sections.append(s)
    elif pp.exists() and not qp.exists():
        diff_sections.append(f"\n## {fname}\n- DELETED\n")
    elif not pp.exists() and qp.exists():
        data = qp.read_bytes()
        diff_sections.append(f"\n## {fname} (NEW)\n- {len(data)}B\n\n```\n{hexdump(data)}\n```\n")

doc = [
    "# Liveplay First Combat Pass 1\n",
    "## Goal\n",
    "Boot Matrix Cubed from SLOT A (CAR1 Medic, lv7), explore starting area to trigger",
    "first combat, save to SLOT A post-combat, diff save data.\n",
    "## Method\n",
    "- MATRIX.CFG: `1,6,3,C:\\\MATRIX\\\SAVE\\\,C:\\\BUCK\\\SAVE\\\`",
    "- DOSBox-X under Xvfb :99, xdotool keystrokes",
    "- 15 Enter presses advance title/credits/PLAY to game world",
    "- Arrow keys + Space/Enter explore, F10->s->A->Enter saves\n",
    "## File Changes\n",
]
doc.append("| File | Pre (sha256) | Post (sha256) | Size Change |\n| --- | --- | --- | ---: |")
for fname in all_files:
    ps = PRE.joinpath(fname).stat().st_size if PRE.joinpath(fname).exists() else 0
    qs = POST.joinpath(fname).stat().st_size if POST.joinpath(fname).exists() else 0
    ph = (pre_hash.get(fname,"MISSING")[:16]+"...") if pre_hash.get(fname) else "MISSING"
    qh = (post_hash.get(fname,"MISSING")[:16]+"...") if post_hash.get(fname) else "MISSING"
    doc.append(f"| {fname} | `{ph}` | `{qh}` | {qs-ps:+d} |")
doc.append(""); doc.extend(diff_sections)
(DOCS / "liveplay-first-combat-pass-1.md").write_text("\n".join(doc))
print(f"  Written: docs/liveplay-first-combat-pass-1.md", flush=True)

# Save probes
env_copy = dict(os.environ); env_copy["PYTHONPATH"] = str(WORKSPACE / "src")
for label, srcdir in [("pre_combat", PRE), ("post_combat", POST)]:
    try:
        r = subprocess.run(["python3","-m","matrix_cubed.tools.save_probe",str(srcdir)], capture_output=True, text=True, timeout=30, cwd=WORKSPACE, env=env_copy)
        (GEN / f"save_probe_{label}.json").write_text(r.stdout or "{}")
        print(f"  save_probe_{label}.json written", flush=True)
    except Exception as e:
        print(f"  Probe failed: {e}", flush=True)

# Tests
print("\n[8] Tests...", flush=True)
r = subprocess.run(["python3","-m","pytest","-q"], capture_output=True,text=True,timeout=30,cwd=WORKSPACE,env=env_copy)
print(r.stdout or "", flush=True)
if "failed" in r.stdout:
    print(f"  Some tests failed (exit code {r.returncode})", flush=True)
else:
    print("  All tests passed!", flush=True)

print("\n=== DONE ===", flush=True)
