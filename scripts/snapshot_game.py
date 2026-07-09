#!/usr/bin/env python3
"""Quick script to launch DOSBox-X and take screenshots at key moments."""

import subprocess
import time
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
SCREEN_DIR = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens")
SCREEN_DIR.mkdir(parents=True, exist_ok=True)

def snap(name):
    path = SCREEN_DIR / f"{name}.png"
    subprocess.run(["import", "-window", "root", str(path)], env=ENV, capture_output=True, timeout=10)
    print(f"  Screenshot: {name}")

def key(k, window=None, delay=100):
    cmd = ["xdotool", "key", "--delay", str(delay)]
    if window: cmd.extend(["--window", window])
    cmd.append(k)
    subprocess.run(cmd, env=ENV, capture_output=True)

# Launch
print("Launching DOSBox-X...")
proc = subprocess.Popen(["dosbox-x", "-conf", str(Path.home() / "Downloads/matrix-cubed-liveplay/dosbox-conf/start.conf")], env=ENV)

# Wait for window
import shlex
deadline = time.time() + 20
window = None
while time.time() < deadline:
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"], capture_output=True, text=True, env=ENV)
    wins = r.stdout.strip().split()
    if wins:
        window = wins[0]
        break
    time.sleep(0.5)

if not window:
    print("ERROR: No DOSBox-X window found!")
    proc.kill()
    exit(1)

print(f"Window: {window}")

# Wait for initial load
time.sleep(8)
snap("snap_00_after_boot")

# Press Enter for any title screens
for i in range(6):
    key("Return", window)
    time.sleep(1.5)
snap("snap_01_after_enter_title")

# Try pressing 0 for option 10 (Begin Adventuring) - Common SSI convention
key("0", window)
time.sleep(3)
snap("snap_02_after_0")

# If that didn't work, try Enter
key("Return", window)
time.sleep(3)
snap("snap_03_after_return")

# Try pressing B for Begin Adventuring
key("b", window)
time.sleep(3)
snap("snap_04_after_b")

# Try pressing 1 for Load Game
key("1", window)
time.sleep(3)
snap("snap_05_after_1")

# If in load game menu, press 1 again for slot A
key("Return", window)
time.sleep(3)
snap("snap_06_after_load_enter")

# Try pressing 8 for Load Saved Game
key("8", window)
time.sleep(3)
snap("snap_07_after_8")

# Press Enter to select
key("Return", window)
time.sleep(3)
snap("snap_08_after_8_enter")

print("\nRunning more extensive navigation...")

# Try pressing Escape to back up
key("Escape", window)
time.sleep(2)
snap("snap_09_after_esc")

# Try pressing F10 for menu
key("F10", window)
time.sleep(2)
snap("snap_10_after_f10")

# Try pressing numbers 1-9 for menu options
for n in range(1, 12):
    key(str(n % 10), window)  # 10 -> 0, 11 -> 1
    time.sleep(2)
    snap(f"snap_1{n:02d}_after_key_{n}")

proc.kill()
print("\nDone")
