#!/usr/bin/env python3
"""
Systematic game navigation: advance through title screens, reach command menu,
select Begin Adventuring, and explore starting area to trigger first combat.
"""

import subprocess, time, signal, sys
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
SDIR = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens")
SDIR.mkdir(parents=True, exist_ok=True)
CONF = str(Path.home() / "Downloads/matrix-cubed-liveplay/dosbox-conf/start.conf")

def snap(name):
    png = SDIR / f"{name}.png"
    subprocess.run([
        "ffmpeg", "-y", "-f", "x11grab", "-video_size", "1280x1024",
        "-i", ":99.0", "-vframes", "1", str(png)
    ], env=ENV, capture_output=True, timeout=10)
    sz = png.stat().st_size if png.exists() else 0
    print(f"  [snap] {name} ({sz}B)", flush=True)

def key(k, win=None):
    cmd = ["xdotool", "key", "--delay", "80"]
    if win: cmd.extend(["--window", win])
    cmd.append(k)
    subprocess.run(cmd, env=ENV, capture_output=True, timeout=5)

# Kill any running dosbox
subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)
time.sleep(1)

print("=== Navigating Matrix Cubed ===", flush=True)

# Launch
proc = subprocess.Popen(["dosbox-x", "-conf", CONF], env=ENV,
                        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
print(f"PID: {proc.pid}", flush=True)

# Wait for window
deadline = time.time() + 20
win = None
while time.time() < deadline:
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"],
                       capture_output=True, text=True, env=ENV)
    wins = r.stdout.strip().split()
    if wins: win = wins[0]; break
    time.sleep(0.5)
if not win: print("FAIL: no window", flush=True); proc.kill(); sys.exit(1)
print(f"Window: {win}", flush=True)

# Step 1: Wait for game boot
print("\n--- Step 1: Boot ---", flush=True)
time.sleep(12)  # Wait for long boot+autoexec
snap("n01_boot")

# Step 2: Advance through title screens - press Enter many times
print("\n--- Step 2: Title screens ---", flush=True)
for i in range(10):
    key("Return", win)
    time.sleep(1.5)
    if i == 3 or i == 6:
        snap(f"n02_title_{i}")

# Step 3: Check if we reached the menu
# Try selecting Begin Adventuring (option 10)
# In SSI menus with 11 options, key '0' = option 10, then key '1' again = option 11
print("\n--- Step 3: Select menu option ---", flush=True)
time.sleep(2)
snap("n03_before_menu_selection")

# Try '0' for option 10 (Begin Adventuring)
key("0", win)
time.sleep(3)
snap("n04_after_key_0")

# If we're now in the game, we should see the game world
# If not, we might need '1' then '0'
key("Escape", win)
time.sleep(2)
snap("n05_after_escape")

# Try '1' then '0'
key("1", win)
time.sleep(1)
key("0", win)
time.sleep(3)
snap("n06_after_10")

# Try Escape to go back
key("Escape", win)
time.sleep(2)
snap("n07_after_escape2")

# Try pressing Down arrow + Enter for menu navigation
for _ in range(9):
    key("Down", win)
    time.sleep(0.3)
key("Return", win)
time.sleep(3)
snap("n08_after_down_enter")

# Try pressing B for Begin
key("Escape", win)
time.sleep(1)
key("b", win)
time.sleep(2)
snap("n09_after_b")

# Try pressing F10 to bring up in-game menu
key("F10", win)
time.sleep(2)
snap("n10_f10")

# Try the number 8 for Load Saved Game
key("Escape", win)
time.sleep(1)
key("8", win)
time.sleep(3)
snap("n11_after_8")

# In load game menu, press 1 for slot A
key("1", win)
time.sleep(3)
snap("n12_after_load_1")

# Press Enter to confirm
key("Return", win)
time.sleep(4)
snap("n13_after_load_enter")

# Try S (for Save) or other menu keys
key("Escape", win)
time.sleep(1)
key("9", win)
time.sleep(3)
snap("n14_after_9")

# If we're anywhere - try Down arrow + Enter repeatedly
key("Escape", win)
time.sleep(1)
for _ in range(8):
    key("Down", win)
    time.sleep(0.3)
key("Return", win)
time.sleep(3)
snap("n15_after_scroll_enter")

# Check F10 again
key("F10", win)
time.sleep(2)
snap("n16_f10_again")

key("Escape", win)
time.sleep(2)
snap("n17_after_esc_final")

# Try 'q' to quit if needed  
key("q", win)
time.sleep(2)
snap("n18_q")

# Clean up - close DOSBox-X properly
key("F10", win)
time.sleep(1)
key("q", win)
time.sleep(1)
key("Return", win)
time.sleep(3)
snap("n99_quit")

# Wait for exit
try:
    proc.wait(timeout=5)
except:
    proc.kill()

print("\n=== Done ===", flush=True)
