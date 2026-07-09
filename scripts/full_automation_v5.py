#!/usr/bin/env python3
"""Focused run with game-generated MATRIX.CFG format."""

import subprocess, time, sys, hashlib, shutil, os
from pathlib import Path

W = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re")
L = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SD = L / "MATRIX" / "SAVE"
CONF = str(L / "dosbox-conf" / "start.conf")
G = W / "generated" / "liveplay"
PRE = G / "pre_combat"
POST = G / "post_combat"
DOCS = W / "docs"
ENV = {"DISPLAY":":99","SDL_VIDEODRIVER":"x11","SDL_AUDIODRIVER":"dummy"}
POST.mkdir(parents=True, exist_ok=True)

# Ensure save files exist
if not list(SD.iterdir()):
    shutil.copytree(PRE, SD, dirs_exist_ok=True)
    print("Restored saves to SAVE dir", flush=True)

pre_hash = {p.name: hashlib.sha256(p.read_bytes()).hexdigest() for p in PRE.iterdir() if p.is_file()}
print(f"Pre-combat: {len(pre_hash)} files", flush=True)

# Cleanup with SIGKILL
subprocess.run("kill -9 $(pgrep dosbox-x 2>/dev/null) 2>/dev/null; sleep 2", shell=True)
time.sleep(2)

proc = subprocess.Popen(["dosbox-x","-conf",CONF],env=ENV,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
d=time.time()+25; win=None
while time.time()<d:
    r=subprocess.run(["xdotool","search","--name","DOSBox-X"],capture_output=True,text=True,env=ENV)
    ws=r.stdout.strip().split()
    if ws: win=ws[0]; break
    time.sleep(0.5)
if not win: print("FAIL"); proc.kill(); exit(1)
print(f"PID={proc.pid} Window={win}",flush=True)

time.sleep(15)

# 20 Enter presses to clear all screens
for i in range(20):
    subprocess.run(["xdotool","key","--delay","80","--window",win,"Return"],env=ENV,capture_output=True,timeout=5)
    time.sleep(1.2)

# Should be in game world. Try to save: Escape->8->A->Enter
time.sleep(3)
subprocess.run(["xdotool","key","--delay","80","--window",win,"Escape"],env=ENV,capture_output=True,timeout=5)
time.sleep(3)
subprocess.run(["xdotool","key","--delay","80","--window",win,"8"],env=ENV,capture_output=True,timeout=5)
time.sleep(2)
subprocess.run(["xdotool","key","--delay","80","--window",win,"A"],env=ENV,capture_output=True,timeout=5)
time.sleep(2)
subprocess.run(["xdotool","key","--delay","80","--window",win,"Return"],env=ENV,capture_output=True,timeout=5)
time.sleep(3)
# Try Enter again for Overwrite
subprocess.run(["xdotool","key","--delay","80","--window",win,"Return"],env=ENV,capture_output=True,timeout=5)
time.sleep(3)
subprocess.run(["xdotool","key","--delay","80","--window",win,"Escape"],env=ENV,capture_output=True,timeout=2)

# Quit
subprocess.run(["xdotool","key","--delay","80","--window",win,"Escape"],env=ENV,capture_output=True,timeout=5)
time.sleep(2)
subprocess.run(["xdotool","key","--delay","80","--window",win,"0"],env=ENV,capture_output=True,timeout=5)
time.sleep(2)
subprocess.run(["xdotool","key","--delay","80","--window",win,"Return"],env=ENV,capture_output=True,timeout=5)
time.sleep(4)

try: proc.wait(timeout=8)
except: proc.kill()

# Copy saves
for f in SD.iterdir():
    if f.is_file(): shutil.copy2(f, POST / f.name)

# Hash and diff
post_hash = {}
for f in POST.iterdir():
    if f.is_file(): post_hash[f.name] = hashlib.sha256(f.read_bytes()).hexdigest()

allf = sorted(set(list(pre_hash.keys()) + list(post_hash.keys())))
changed = [f for f in allf if pre_hash.get(f) != post_hash.get(f)]
print(f"\nChanged files: {len(changed)}", flush=True)
for f in changed:
    print(f"  {f}: pre={pre_hash.get(f,'MISS')[:16]} post={post_hash.get(f,'MISS')[:16]}", flush=True)

# Check actual SAVE dir
saves = list(SD.iterdir())
print(f"\nSAVE directory: {len(saves)} files", flush=True)
for f in saves:
    if f.is_file():
        print(f"  {f.name} ({f.stat().st_size}B) [{hashlib.sha256(f.read_bytes()).hexdigest()[:16]}]", flush=True)

# Report
doc = [
    "# Liveplay First Combat Pass 1 (v5)\n",
    "## Method\n",
    "- MATRIX.CFG: game-generated comma format `1,0,0,0,0,40,1,4,1,0`",
    "- DOSBox-X under Xvfb :99 via xdotool",
    "- 20 Enter presses to advance through all screens to game world",
    "- Escape → 8 → A → Enter → Enter to save",
    "- Escape → 0 → Enter to quit\n",
    "## Results\n",
]
doc.append("| File | Pre | Post |\n| --- | --- | --- |")
for f in allf:
    ph = pre_hash.get(f,"MISS")[:16]
    qh = post_hash.get(f,"MISS")[:16]
    doc.append(f"| {f} | {ph}... | {qh}... |")
doc.append("")
if changed:
    doc.append(f"**{len(changed)} file(s) changed.**\n")
    for f in changed:
        doc.append(f"- {f}: `{pre_hash.get(f,'MISS')[:16]}...` → `{post_hash.get(f,'MISS')[:16]}...`\n")
else:
    doc.append("**No files changed.**\n")
doc.append(f"\nSAVE directory contents:\n")
for f in SD.iterdir():
    if f.is_file():
        doc.append(f"- {f.name} ({f.stat().st_size}B) [{hashlib.sha256(f.read_bytes()).hexdigest()[:16]}...]\n")

(DOCS/"liveplay-first-combat-pass-1.md").write_text("\n".join(doc))
print(f"\nDoc written to {DOCS/'liveplay-first-combat-pass-1.md'}", flush=True)

# Tests
env = dict(os.environ); env["PYTHONPATH"]=str(W/"src")
r = subprocess.run(["python3","-m","pytest","-q"],capture_output=True,text=True,timeout=30,cwd=W,env=env)
print(r.stdout or "", flush=True)
if "failed" in (r.stdout or ""): print(f"Tests: {r.returncode} failed", flush=True)
else: print("All tests passed!", flush=True)
print("DONE", flush=True)
