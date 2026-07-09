#!/usr/bin/env python3
"""Final save test: create char, begin, play, exit to DOS, check auto-save."""
import subprocess, time, os, hashlib
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
os.environ.update(ENV)
LIVEPLAY = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
SAVE = LIVEPLAY / "SAVE"

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

SAVE.mkdir(parents=True, exist_ok=True)

proc = subprocess.Popen(["dosbox-x", "-conf", str(LIVEPLAY / "dosbox-conf" / "start.conf")], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
for i in range(30):
    if fw(): break
    time.sleep(1)
time.sleep(10)

# Title screens
for _ in range(12):
    k("Return"); time.sleep(1)
time.sleep(3)
snap("/tmp/f01_title.png")

# Create character
k("1"); time.sleep(3)
k("Return"); time.sleep(2)  # Race
k("Return"); time.sleep(2)  # Gender
k("Return"); time.sleep(2)  # Career
k("Return"); time.sleep(3)  # Stats
k("Tab"); time.sleep(1); k("Return"); time.sleep(3)  # Skills DONE
# Type name TEST1
subprocess.run(["xdotool", "type", "--window", fw(), "--delay", "50", "TEST1"], capture_output=True, timeout=5)
time.sleep(1)
k("Return"); time.sleep(3)
snap("/tmp/f02_created.png")

# Add to Team
k("6"); time.sleep(3)
k("Return"); time.sleep(3)
snap("/tmp/f03_team.png")

# Save Current Game
h_before = h()
print(f"Before save: {h_before}", flush=True)
k("9"); time.sleep(3)
k("A"); time.sleep(3)
k("Return"); time.sleep(4)
h_after = h()
print(f"After save: {h_after}", flush=True)
print(f"Save changed: {h_before != h_after}", flush=True)
snap("/tmp/f04_save_menu.png")

# Begin Adventuring
k("1"); time.sleep(0.3); k("0"); time.sleep(10)
snap("/tmp/f05_adventure.png")
print(f"After begin: {h()}", flush=True)

# Explore briefly
for _ in range(5):
    k("Up"); time.sleep(0.5)
snap("/tmp/f06_explore.png")

# Try S for Save
h_before2 = h()
k("s"); time.sleep(5)
k("A"); time.sleep(3); k("Return"); time.sleep(4)
print(f"After S-save: {h()} (was {h_before2})", flush=True)
snap("/tmp/f07_s_save.png")

# Exit to DOS (F10 at command menu)
# First return to command menu by trying Escape
k("Escape"); time.sleep(3)
# Now F10 to exit
k("F10"); time.sleep(5)
print(f"After exit: {h()}", flush=True)
snap("/tmp/f08_exit.png")

# List all save files
print("\nSave files:", flush=True)
for p in sorted(SAVE.iterdir()):
    print(f"  {p.name}: {p.stat().st_size}B", flush=True)

proc.terminate(); time.sleep(1)
subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)
print("DONE", flush=True)
