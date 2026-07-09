#!/usr/bin/env python3
"""Test Escape key in game world to reach command menu."""

import subprocess, time, sys, hashlib, shutil, os
from pathlib import Path

L = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SD = L / "MATRIX" / "SAVE"
CONF = str(L / "dosbox-conf" / "start.conf")
G = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay")
SCR = G / "screens"
ENV = {"DISPLAY":":99","SDL_VIDEODRIVER":"x11","SDL_AUDIODRIVER":"dummy"}
SCR.mkdir(parents=True, exist_ok=True)

def sn(n):
    p = SCR/f"z_{n}.png"
    subprocess.run(["ffmpeg","-y","-f","x11grab","-video_size","1280x1024","-i",":99.0","-vframes","1",str(p)],env=ENV,capture_output=True,timeout=10)
    sz = p.stat().st_size if p.exists() else 0
    print(f"  [snap] {n} ({sz}B)",flush=True)
def key(k, w=None):
    subprocess.run(["xdotool","key","--delay","80"]+(["--window",w] if w else [k]),env=ENV,capture_output=True,timeout=5)

# Restore saves
# Restore saves
for f in (G/"pre_combat").iterdir():
    if f.is_file(): shutil.copy2(f, SD / f.name)

# Clean start
subprocess.run("kill -9 $(pgrep dosbox-x 2>/dev/null) 2>/dev/null; sleep 2", shell=True)
proc = subprocess.Popen(["dosbox-x","-conf",CONF],env=ENV,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
d=time.time()+25; win=None
while time.time()<d:
    r=subprocess.run(["xdotool","search","--name","DOSBox-X"],capture_output=True,text=True,env=ENV)
    ws=r.stdout.strip().split()
    if ws: win=ws[0]; break
    time.sleep(0.5)
if not win: print("FAIL"); proc.kill(); exit(1)
print(f"PID={proc.pid} Window={win}")

time.sleep(15); sn("a00_boot")

# Advance to game world
for i in range(15):
    key("Return",win); time.sleep(1.2)
sn("a01_game_world")

# Try Escape to see what happens
key("Escape",win); time.sleep(3); sn("a02_escape1")
key("Escape",win); time.sleep(3); sn("a03_escape2")
key("Escape",win); time.sleep(3); sn("a04_escape3")

# Try 9 for Begin Adventuring in case we're at command menu
key("9",win); time.sleep(3); sn("a05_key9")
key("A",win); time.sleep(3); sn("a06_keyA")
key("Return",win); time.sleep(3); sn("a07_enter")

# Try F10 
key("F10",win); time.sleep(3); sn("a08_f10")
key("s",win); time.sleep(3); sn("a09_f10_s")
key("A",win); time.sleep(3); sn("a10_f10_s_a")
key("Return",win); time.sleep(3); sn("a11_f10_enter")

# Quit: F10 then q
key("F10",win); time.sleep(2)
key("q",win); time.sleep(2)
key("Return",win); time.sleep(4)
sn("a12_quit")

try: proc.wait(timeout=8)
except: proc.kill()

# Check saves
print("\nSAVE directory:")
for f in sorted(SD.iterdir()):
    if f.is_file():
        h = hashlib.sha256(f.read_bytes()).hexdigest()[:16]
        pre_h = hashlib.sha256((G/"pre_combat"/f.name).read_bytes()).hexdigest()[:16] if (G/"pre_combat"/f.name).exists() else "MISS"
        status = "CHANGED" if h != pre_h else "same"
        print(f"  {f.name} ({f.stat().st_size}B) [{h}] {status}")

print("\nDONE")
