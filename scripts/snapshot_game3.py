#!/usr/bin/env python3
"""Launch game, navigate systematically, capture via ffmpeg x11grab."""

import subprocess, time, signal
from pathlib import Path

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
SDIR = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens")
SDIR.mkdir(parents=True, exist_ok=True)
CONF = str(Path.home() / "Downloads/matrix-cubed-liveplay/dosbox-conf/start.conf")

def snap(name):
    png = SDIR / f"{name}.png"
    subprocess.run([
        "ffmpeg", "-y", "-f", "x11grab", "-video_size", "1280x1024",
        "-i", ":99.0+0,0", "-vframes", "1", str(png)
    ], env=ENV, capture_output=True, timeout=10)
    sz = png.stat().st_size if png.exists() else 0
    print(f"  [snap] {name} ({sz} bytes)")

def key(k, win=None):
    cmd = ["xdotool", "key", "--delay", "80"]
    if win: cmd.extend(["--window", win])
    cmd.append(k)
    subprocess.run(cmd, env=ENV, capture_output=True, timeout=5)

print("=== Game Snapshot Test ===")
proc = subprocess.Popen(["dosbox-x", "-conf", CONF], env=ENV, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
print(f"PID: {proc.pid}")

deadline = time.time() + 20
win = None
while time.time() < deadline:
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"], capture_output=True, text=True, env=ENV)
    wins = r.stdout.strip().split()
    if wins: win = wins[0]; break
    time.sleep(0.5)
if not win: print("FAIL: no window"); exit(1)
print(f"Window: {win}")

time.sleep(10)
snap("s00_boot")

# Press Enter to clear initial screens (KEYS / matte)
for i in range(3):
    key("Return", win); time.sleep(2)
snap("s01_after_enter_x3")

# Try more Enter presses
for i in range(3):
    key("Return", win); time.sleep(2)
snap("s02_after_enter_x6")

# Try number keys for main menu
for k in ["b","0","1","2","8","9","Escape"]:
    key(k, win); time.sleep(1.5)
    snap(f"s03_key_{k}")

# Try arrow-down + Enter
key("Down", win); time.sleep(1)
key("Return", win); time.sleep(2)
snap("s04_down_enter")

# Try F10 (context menu)
key("F10", win); time.sleep(2)
snap("s05_f10")

# Try Save from F10 menu
key("s", win); time.sleep(2)
snap("s06_f10_s")

# Try slot 1
key("1", win); time.sleep(2)
snap("s07_f10_s1")

key("Return", win); time.sleep(2)
snap("s08_f10_s1_enter")

# Escape to dismiss
key("Escape", win); time.sleep(1)
key("Escape", win); time.sleep(1)
snap("s09_escape_twice")

# Quit
key("F10", win); time.sleep(1)
key("q", win); time.sleep(1)
key("Return", win); time.sleep(3)
snap("s10_quit")

proc.send_signal(signal.SIGINT)
time.sleep(2)
if proc.poll() is None:
    proc.kill()
print("\n=== Done ===")
