#!/usr/bin/env python3
"""Launch game, navigate systematically, capture screenshots via xwd."""

import subprocess, time
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
SDIR = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens")
SDIR.mkdir(parents=True, exist_ok=True)
CONF = str(Path.home() / "Downloads/matrix-cubed-liveplay/dosbox-conf/start.conf")

def snap(name):
    """Capture root window to XWD, convert to PNG."""
    xwd = SDIR / f"{name}.xwd"
    png = SDIR / f"{name}.png"
    subprocess.run(["xwd", "-root", "-out", str(xwd)], env=ENV, capture_output=True, timeout=5)
    subprocess.run(["convert", str(xwd), str(png)], capture_output=True, timeout=5)
    xwd.unlink(missing_ok=True)
    sz = png.stat().st_size if png.exists() else 0
    print(f"  [snap] {name} ({sz} bytes)")

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

print("=== Game Snapshot ===")
proc = subprocess.Popen(["dosbox-x", "-conf", CONF], env=ENV, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
print(f"PID: {proc.pid}")

# Wait for window
deadline = time.time() + 20
win = None
while time.time() < deadline:
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"], capture_output=True, text=True, env=ENV)
    wins = r.stdout.strip().split()
    if wins: win = wins[0]; break
    time.sleep(0.5)

if not win: print("FAIL: no window"); exit(1)
print(f"Window: {win}")

# Step 1: Wait for game load
time.sleep(10)
snap("s00_boot")

# Step 2: Press Enter to advance through KEYS screen / title screens
for i in range(5):
    key("Return", win); time.sleep(2)
snap("s01_title_advance")

# Step 3: Try various menu keys, screenshot after each
menu_keys = ["b", "B", "0", "1", "2", "8", "9", "Return", "Escape"]
for k in menu_keys:
    key(k, win); time.sleep(2)
    snap(f"s02_menu_{k}")

# Step 4: If we got into game, try F10 for in-game menu
key("F10", win); time.sleep(2)
snap("s03_f10")

# Step 5: Try save from menu
key("s", win); time.sleep(2)
snap("s04_save_menu")

key("1", win); time.sleep(2)
snap("s05_save_slot")

key("Return", win); time.sleep(3)
snap("s06_save_confirm")

key("Escape", win); time.sleep(1)
key("Escape", win); time.sleep(1)

# Step 6: Quit
key("F10", win); time.sleep(1)
key("q", win); time.sleep(1)
key("Return", win); time.sleep(3)
snap("s07_quit")

proc.wait(timeout=10)
print("\n=== Done ===")
