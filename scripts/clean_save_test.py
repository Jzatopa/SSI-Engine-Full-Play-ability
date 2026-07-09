#!/usr/bin/env python3
"""Clean save flow: create char, save, begin adventuring, check saves."""
import subprocess, time, os, hashlib
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
os.environ.update(ENV)
LIVEPLAY = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")

# Check multiple possible save locations
SAVE_CANDIDATES = [LIVEPLAY / "SAVE", LIVEPLAY / "BUCK" / "SAVE"]
for d in SAVE_CANDIDATES:
    d.mkdir(parents=True, exist_ok=True)

def fw():
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"], capture_output=True, text=True, timeout=5)
    w = [s.strip() for s in r.stdout.strip().split() if s.strip()]
    return w[0] if w else None

def k(k):
    w = fw()
    if w: subprocess.run(["xdotool", "key", "--window", w, "--delay", "80", k], capture_output=True, timeout=5)

def find_save_files():
    results = {}
    for d in SAVE_CANDIDATES:
        if d.exists():
            for p in d.iterdir():
                if p.suffix.upper() in (".DAT", ".SAV", ".WHO", ".STF") and p.is_file():
                    rel = p.relative_to(LIVEPLAY)
                    results[str(rel)] = p.stat().st_size
    return results

subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
subprocess.run(["pkill", "-f", "zenity"], capture_output=True, timeout=5)
time.sleep(3)

print("Saves BEFORE:", flush=True)
for path, size in sorted(find_save_files().items()):
    print(f"  {path}: {size}B", flush=True)

proc = subprocess.Popen(["dosbox-x", "-conf", str(LIVEPLAY / "dosbox-conf" / "start.conf")],
                        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
for i in range(30):
    if fw(): break
    time.sleep(1)
time.sleep(10)

# Title x12
for _ in range(12):
    k("Return"); time.sleep(1)
time.sleep(3)

# Create character
k("1"); time.sleep(3)
k("Return"); time.sleep(2)
k("Return"); time.sleep(2)
k("Return"); time.sleep(2)
k("Return"); time.sleep(3)
k("Tab"); time.sleep(1); k("Return"); time.sleep(3)
subprocess.run(["xdotool", "type", "--window", fw(), "--delay", "50", "TEST1"], capture_output=True, timeout=5)
time.sleep(1)
k("Return"); time.sleep(3)

# Add to Team
k("6"); time.sleep(3)
k("Return"); time.sleep(3)
print("Created TEST1 and added to team", flush=True)

# Save Current Game
k("9"); time.sleep(3)
k("A"); time.sleep(3)
k("Return"); time.sleep(4)
print("Save Current Game (9 -> A -> Enter)", flush=True)

# Check saves
saves = find_save_files()
print("\nSaves AFTER SAVE:", flush=True)
for path, size in sorted(saves.items()):
    print(f"  {path}: {size}B", flush=True)

if not saves:
    print("NO SAVES FOUND - trying alternate MATRIX.CFG format", flush=True)

proc.terminate(); time.sleep(1)
subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)
print("DONE", flush=True)
