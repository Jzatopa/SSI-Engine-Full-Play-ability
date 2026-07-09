#!/usr/bin/env python3
"""Test: press S for Save in game world."""
import subprocess, time, os, hashlib
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
os.environ.update(ENV)
LIVEPLAY = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SAVE = LIVEPLAY / "MATRIX" / "SAVE"

def fw():
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"], capture_output=True, text=True, timeout=5)
    w = [s.strip() for s in r.stdout.strip().split() if s.strip()]
    return w[0] if w else None

def k(k):
    w = fw()
    if w: subprocess.run(["xdotool", "key", "--window", w, "--delay", "80", k], capture_output=True, timeout=5)

def snap(p):
    subprocess.run(["ffmpeg", "-y", "-f", "x11grab", "-video_size", "1280x1024", "-i", ":99.0", "-vframes", "1", p], capture_output=True, timeout=5)

def h():
    p = SAVE / "SAVGAMA.DAT"
    return hashlib.md5(p.read_bytes()).hexdigest() if p.exists() else "MISSING"

subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
subprocess.run(["pkill", "-f", "zenity"], capture_output=True, timeout=5)
time.sleep(3)

proc = subprocess.Popen(["dosbox-x", "-conf", str(LIVEPLAY / "dosbox-conf" / "start.conf")], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
for i in range(30):
    if fw(): break
    time.sleep(1)
time.sleep(10)

for _ in range(10):
    k("Return"); time.sleep(1)
time.sleep(3)
snap("/tmp/s01_title.png")

k("8"); time.sleep(3)
k("A"); time.sleep(5)
k("Return"); time.sleep(5)
snap("/tmp/s02_loaded.png")

k("1"); time.sleep(0.3); k("0"); time.sleep(8)
snap("/tmp/s03_adventure.png")
time.sleep(5)

print(f"Pre-hash: {h()}", flush=True)

# Press S for Save
k("s"); time.sleep(5)
snap("/tmp/s04_after_s.png")

k("A"); time.sleep(3)
k("Return"); time.sleep(4)
snap("/tmp/s05_after_save.png")

print(f"Post-hash: {h()}", flush=True)
print(f"Changed: {h() == h()}", flush=True)

# Try alternate: F6 for Save (standard Gold Box)
print("--- Trying F6 ---", flush=True)
k("F6"); time.sleep(5)
snap("/tmp/s06_after_f6.png")
k("A"); time.sleep(3); k("Return"); time.sleep(4)
print(f"After F6: {h()}", flush=True)

# Try F8
print("--- Trying F8 ---", flush=True)
k("F8"); time.sleep(5)
snap("/tmp/s07_after_f8.png")
k("A"); time.sleep(3); k("Return"); time.sleep(4)
print(f"After F8: {h()}", flush=True)

# Try just Enter -> S
print("--- Trying Enter S A ---", flush=True)
k("Return"); time.sleep(3)
k("s"); time.sleep(3)
k("A"); time.sleep(3); k("Return"); time.sleep(4)
print(f"After Enter-S: {h()}", flush=True)

proc.terminate(); time.sleep(1)
subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)
print("Done", flush=True)
