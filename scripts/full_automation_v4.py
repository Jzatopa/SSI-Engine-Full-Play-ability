#!/usr/bin/env python3
"""Focused automation: boot, explore, ESC to command menu, save, quit."""

import subprocess, time, sys, hashlib, json, shutil, os
from pathlib import Path

W = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re")
L = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SD = L / "MATRIX" / "SAVE"
CONF = str(L / "dosbox-conf" / "start.conf")
G = W / "generated" / "liveplay"
PRE = G / "pre_combat"
POST = G / "post_combat"
DOCS = W / "docs"
SCR = G / "screens"
ENV = {"DISPLAY":":99","SDL_VIDEODRIVER":"x11","SDL_AUDIODRIVER":"dummy"}
for d in [POST, SCR]: d.mkdir(parents=True, exist_ok=True)

def sn(n):
    p = SCR / f"v4_{n}.png"
    subprocess.run(["ffmpeg","-y","-f","x11grab","-video_size","1280x1024","-i",":99.0","-vframes","1",str(p)],env=ENV,capture_output=True,timeout=10)
    sz = p.stat().st_size if p.exists() else 0
    print(f"  [snap] {n} ({sz}B)",flush=True)

def k(key, w=None):
    subprocess.run(["xdotool","key","--delay","80"]+(["--window",w] if w else [key]),env=ENV,capture_output=True,timeout=5)

def ww(name="DOSBox-X",t=25):
    d=time.time()+t
    while time.time()<d:
        r=subprocess.run(["xdotool","search","--name",name],capture_output=True,text=True,env=ENV)
        ws=r.stdout.strip().split()
        if ws: return ws[0]
        time.sleep(0.5)
    return None

# Kill old with SIGKILL to avoid quit dialog
for p in (subprocess.run(["pgrep","-f","dosbox-x"],capture_output=True,text=True,env=ENV).stdout.strip().split()):
    if p: subprocess.run(["kill","-9",p],capture_output=True,env=ENV)
time.sleep(3)

proc = subprocess.Popen(["dosbox-x","-conf",CONF],env=ENV,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
win = ww()
if not win: print("FAIL"); proc.kill(); exit(1)
print(f"PID={proc.pid} Window={win}",flush=True)

time.sleep(15); sn("00_boot")

# Escape to dismiss any quit dialog
k("Escape",win); time.sleep(1); sn("01_esc")

# Advance through all screens
for i in range(15):
    k("Return",win); time.sleep(1.5)
sn("02_titles")

# Should be in game world (tile map). Walk around.
print("Exploring...",flush=True)
# Walk in all directions to trigger encounters
for d in ["Up","Left","Right","Down"]:
    for _ in range(20):
        k(d,win); time.sleep(0.2)
    sn(f"03_walk_{d}")

# Try Space and F for actions
for _ in range(10): k("space",win); time.sleep(0.4); k("f",win); time.sleep(0.4)
sn("04_actions")

# Walk more
for _ in range(40): k("Up",win); time.sleep(0.2)
sn("05_walk")

# NOW try to save: Escape to menu, then 8 for save, A for slot, Enter
print("Saving via Escape menu...",flush=True)
k("Escape",win); time.sleep(3); sn("06_menu")
k("8",win); time.sleep(2); sn("07_save")
k("A",win); time.sleep(2); sn("08_slot")
k("Return",win); time.sleep(3); sn("09_confirm")

# If we get Overwrite/Rename/Abort, press Enter for Overwrite
k("Return",win); time.sleep(3); sn("10_overwrite")

# Escape to back out
k("Escape",win); time.sleep(1); k("Escape",win); time.sleep(1)

# Quit: at command menu, press 11 (0) for Exit
k("Escape",win); time.sleep(2)
k("Escape",win); time.sleep(2)
sn("11_pre_quit")

# Try 0 for Exit to DOS
k("0",win); time.sleep(2); sn("12_quit_confirm")
k("Return",win); time.sleep(4); sn("13_quit")

try: proc.wait(timeout=10)
except:
    try: proc.terminate(); proc.wait(timeout=5)
    except: proc.kill()

# Copy saves
print("Post-processing...",flush=True)
for f in SD.iterdir():
    if f.is_file(): shutil.copy2(f, POST / f.name)

# Diff
import hashlib as hl
ph = {p.name: hl.sha256(p.read_bytes()).hexdigest() for p in PRE.iterdir() if p.is_file()} if PRE.exists() else {}
qh = {p.name: hl.sha256(p.read_bytes()).hexdigest() for p in POST.iterdir() if p.is_file()} if POST.exists() else {}
allf = sorted(set(list(ph.keys())+list(qh.keys())))
doc = ["# Liveplay First Combat Pass 1\n","## Method\n","Boot from MATRIX.CFG (1,6,3,...), advance titles, PLAY enters game world (tile map view).\nExplore with arrows, Escape to command menu, 8-A-Enter to save, 0 to quit.\n","## Results\n"]
changed = [f for f in allf if ph.get(f)!=qh.get(f)]
if not changed:
    doc.append("**No save files changed.** The game did not save or no state change occurred.\n")
else:
    doc.append("| File | Pre | Post |\n| --- | --- | --- |")
    for f in changed:
        doc.append(f"| {f} | `{ph.get(f,'MISS')[:16]}...` | `{qh.get(f,'MISS')[:16]}...` |")
doc.append("\n## Screenshots\n")
doc.append("Screenshots in `generated/liveplay/screens/` (v4_ prefix). Key:\n")
doc.append("- v4_00_boot: initial boot\n- v4_02_titles: after advancing through all screens\n- v4_06_menu: after Escape (command menu?)\n- v4_12_quit_confirm: after selecting Exit\n")
(DOCS/"liveplay-first-combat-pass-1.md").write_text("\n".join(doc))
print(f"Docs written. Changed files: {len(changed)}",flush=True)

# Tests
env = dict(os.environ); env["PYTHONPATH"]=str(W/"src")
r = subprocess.run(["python3","-m","pytest","-q"],capture_output=True,text=True,timeout=30,cwd=W,env=env)
print(r.stdout or "",flush=True)
if "failed" in (r.stdout or ""): print(f"Tests failed ({r.returncode})",flush=True)
else: print("All tests passed!",flush=True)

print("DONE",flush=True)
