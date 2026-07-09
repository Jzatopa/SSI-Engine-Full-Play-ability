#!/usr/bin/env python3
"""Quick boot test with proper config."""

import subprocess, time; from pathlib import Path
ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
SDIR = Path("/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens")
SDIR.mkdir(exist_ok=True)
CONF = str(Path.home() / "Downloads/matrix-cubed-liveplay/dosbox-conf/start.conf")

def snap(name):
    png = SDIR/f"{name}.png"
    subprocess.run(["ffmpeg","-y","-f","x11grab","-video_size","1280x1024","-i",":99.0","-vframes","1",str(png)], env=ENV,capture_output=True,timeout=10)
    print(f"  [snap] {name} ({png.stat().st_size}B)",flush=True)
def key(k, w=None):
    subprocess.run(["xdotool","key","--delay","80"]+(["--window",w] if w else [k]), env=ENV,capture_output=True,timeout=5)
def wait_win(name, t=20):
    d=time.time()+t
    while time.time()<d:
        r=subprocess.run(["xdotool","search","--name",name],capture_output=True,text=True,env=ENV)
        w=r.stdout.strip().split()
        if w: return w[0]
        time.sleep(0.5)
    return None

subprocess.run(["pkill","-f","dosbox-x"],capture_output=True); time.sleep(2)
proc=subprocess.Popen(["dosbox-x","-conf",CONF],env=ENV,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
win=wait_win("DOSBox-X")
if not win: print("FAIL"); proc.kill(); exit(1)
print(f"PID={proc.pid} Window={win}")

time.sleep(15); snap("00_boot")

# Dismiss any quit dialog
key("Escape",win); time.sleep(1); key("Escape",win); time.sleep(1); snap("01_dismiss")

# Title/credits screens
for i in range(12):
    key("Return",win); time.sleep(1.5)
snap("02_after_titles")

# Try pressing various keys to see what's shown
key("1",win); time.sleep(2); snap("03_key_1")
key("Escape",win); time.sleep(2); snap("04_esc")
key("9",win); time.sleep(3); snap("05_key_9")
key("A",win); time.sleep(3); snap("06_key_A")
key("Return",win); time.sleep(3); snap("07_enter")
key("0",win); time.sleep(3); snap("08_key_0")

proc.terminate(); time.sleep(2); proc.kill()
print("DONE")
