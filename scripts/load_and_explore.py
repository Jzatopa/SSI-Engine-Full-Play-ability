#!/usr/bin/env python3
"""
Load existing save (slot A), Begin Adventuring, explore, get to combat, save after.
"""

import subprocess, time, sys, os
from pathlib import Path

WORKSPACE = Path(os.environ.get("WORKSPACE", "/home/jzatopa/.openclaw/workspace/matrix-cubed-re"))
LIVEPLAY = Path("/home/jzatopa/Downloads/matrix-cubed-liveplay")
CONF = str(LIVEPLAY / "dosbox-conf" / "start.conf")
SAVE = LIVEPLAY / "MATRIX" / "SAVE"
POST = WORKSPACE / "generated" / "liveplay" / "post_combat"
SDIR = POST / "screens"

ENV = {"DISPLAY": ":99", "SDL_VIDEODRIVER": "x11", "SDL_AUDIODRIVER": "dummy"}
os.environ.update(ENV)

POST.mkdir(parents=True, exist_ok=True)
SDIR.mkdir(parents=True, exist_ok=True)

def snap(name):
    png = SDIR / f"{name}.png"
    subprocess.run(["ffmpeg", "-y", "-f", "x11grab", "-video_size", "1280x1024",
                    "-i", ":99.0", "-vframes", "1", str(png)],
                   capture_output=True, timeout=10)
    if png.exists():
        print(f"  [snap] {name} ({png.stat().st_size}B)", flush=True)

def find_window():
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"],
                       capture_output=True, text=True, timeout=5)
    wins = [w.strip() for w in r.stdout.strip().split() if w.strip()]
    return wins[0] if wins else None

def send_key(k, retries=3):
    for attempt in range(retries):
        win = find_window()
        if not win:
            time.sleep(2)
            continue
        subprocess.run(["xdotool", "search", "--name", "Quit", "windowclose"],
                       capture_output=True, timeout=3)
        r = subprocess.run(["xdotool", "key", "--window", win, "--delay", "80", k],
                           capture_output=True, text=True, timeout=5)
        if r.returncode == 0:
            return True
        time.sleep(1)
    return False

def send_char(text, delay=0.05):
    win = find_window()
    if not win:
        return False
    subprocess.run(["xdotool", "type", "--window", win, "--delay", "50", text],
                   capture_output=True, timeout=5)
    return True

def run():
    print("=" * 60, flush=True)
    print("MATRIX CUBED - LOAD SAVE + EXPLORE", flush=True)
    print("=" * 60, flush=True)

    # Kill stale
    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
    subprocess.run(["pkill", "-f", "zenity"], capture_output=True, timeout=5)
    time.sleep(3)

    # Save pre-combat state
    (POST / "pre_combat").mkdir(parents=True, exist_ok=True)
    for p in SAVE.iterdir():
        if p.is_file():
            dest = POST / "pre_combat" / p.name
            dest.write_bytes(p.read_bytes())

    # Launch DOSBox-X
    print("[launch]", flush=True)
    proc = subprocess.Popen(["dosbox-x", "-conf", CONF],
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    print(f"  PID: {proc.pid}", flush=True)

    # Wait for window
    for i in range(30):
        win = find_window()
        if win:
            print(f"  Window: {win}", flush=True)
            break
        time.sleep(1)
    else:
        print("  ERROR: No window!", flush=True)
        sys.exit(1)
    time.sleep(8)

    # === STEP 1: Title screens ===
    print("\n[1] Title (Enter x10)", flush=True)
    for _ in range(10):
        send_key("Return")
        time.sleep(1)
    time.sleep(3)
    snap("01_after_title")

    # === STEP 2: Load Saved Game (option 8) ===
    print("\n[2] Load Saved Game (8)", flush=True)
    send_key("8")
    time.sleep(3)
    snap("02_load_menu")

    # === STEP 3: Select slot A ===
    print("\n[3] Slot A", flush=True)
    send_key("A")
    time.sleep(4)
    snap("03_loaded")

    # Press Enter to confirm/continue
    send_key("Return")
    time.sleep(4)
    snap("04_after_confirm")

    # === STEP 4: Should be at command menu. Begin Adventuring. ===
    print("\n[4] Begin Adventuring (1 then 0 = option 10)", flush=True)
    send_key("1")
    time.sleep(0.3)
    send_key("0")
    time.sleep(8)
    snap("05_adventuring")

    # === STEP 5: Game world - explore ===
    print("\n[5] Exploring...", flush=True)
    time.sleep(5)
    snap("06_game_world")

    # Exploration pattern: walk N, E, N, search, space, walk around, repeat
    for phase in range(5):
        print(f"  Phase {phase+1}/5", flush=True)
        # Walk forward
        for _ in range(10):
            send_key("Up")
            time.sleep(0.4)
        # Turn right
        for _ in range(3):
            send_key("Right") 
            time.sleep(0.4)
        # Walk more
        for _ in range(8):
            send_key("Up")
            time.sleep(0.4)
        # Search
        send_key("s")
        time.sleep(2)
        # Interact
        send_key("space")
        time.sleep(2)
        # Turn around walk down
        for _ in range(3):
            send_key("Down")
            time.sleep(0.4)
        # Turn left
        for _ in range(3):
            send_key("Left")
            time.sleep(0.4)
        # Search again
        send_key("s")
        time.sleep(2)
        send_key("space")
        time.sleep(2)

    snap("07_explored")

    # === STEP 6: Return to command menu and save ===
    # Escape returns to command menu from game world
    print("\n[6] Escape to command menu", flush=True)
    time.sleep(2)
    send_key("Escape")
    time.sleep(5)
    snap("08_command_menu")
    
    # Save Current Game (option 9)
    print("  Save Current Game (9)", flush=True)
    send_key("9")
    time.sleep(3)
    snap("09_save_menu")
    
    # Slot A
    send_key("A")
    time.sleep(3)
    
    # Confirm
    send_key("Return")
    time.sleep(4)
    snap("10_saved")

    # === STEP 7: Copy saves ===
    print("\n[7] Copy post-combat saves", flush=True)
    (POST / "post_combat").mkdir(parents=True, exist_ok=True)
    for p in SAVE.iterdir():
        if p.is_file():
            dest = POST / "post_combat" / p.name
            dest.write_bytes(p.read_bytes())
            print(f"  {p.name}: {p.stat().st_size}B", flush=True)

    # === STEP 8: Cleanup ===
    print("\n[8] Cleanup", flush=True)
    proc.terminate()
    time.sleep(1)
    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)

    print("\n=== DONE ===", flush=True)

if __name__ == "__main__":
    run()
