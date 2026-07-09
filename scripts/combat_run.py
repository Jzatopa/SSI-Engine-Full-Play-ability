#!/usr/bin/env python3
"""
Matrix Cubed combat run (Python).
Handles window recreation during video mode changes by re-finding the window.
"""

import subprocess, time, hashlib, os, sys
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
    """Find and return the current DOSBox-X window ID, or None."""
    r = subprocess.run(["xdotool", "search", "--name", "DOSBox-X"],
                       capture_output=True, text=True, timeout=5)
    wins = [w.strip() for w in r.stdout.strip().split() if w.strip()]
    return wins[0] if wins else None

def key(k, retries=5):
    """Send key to DOSBox-X window, retrying if window changes."""
    for attempt in range(retries):
        win = find_window()
        if not win:
            print(f"  [wait for window] attempt {attempt+1}", flush=True)
            time.sleep(2)
            continue
        # Close any blocking dialogs first
        subprocess.run(["xdotool", "search", "--name", "Quit", "windowclose"],
                       capture_output=True, timeout=3)
        r = subprocess.run(["xdotool", "key", "--window", win, "--delay", "80", k],
                           capture_output=True, text=True, timeout=5)
        if r.returncode == 0:
            return True
        # BadWindow - wait for new window
        time.sleep(1)
    return False

def key_chain(*keys, delay=0.8):
    """Send multiple keys in sequence."""
    for k in keys:
        key(k)
        time.sleep(delay)

def type_text(text, delay=0.05):
    """Type text."""
    win = find_window()
    if not win:
        return False
    subprocess.run(["xdotool", "type", "--window", win, "--delay", "50", text],
                   capture_output=True, timeout=5)
    return True

def run():
    print("=" * 60, flush=True)
    print("MATRIX CUBED - FRESH GAME + COMBAT RUN (Python)", flush=True)
    print("=" * 60, flush=True)

    # Kill stale processes
    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
    subprocess.run(["pkill", "-f", "zenity"], capture_output=True, timeout=5)
    time.sleep(3)

    # Clear save dir so game starts fresh
    for p in SAVE.iterdir():
        if p.is_file():
            p.unlink()
    for p in [SAVE]:
        p.mkdir(parents=True, exist_ok=True)
    print("  SAVE directory cleared for fresh start", flush=True)

    # Launch
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
        print("  ERROR: No window found!", flush=True)
        sys.exit(1)

    time.sleep(8)  # boot

    # Kill any zenity quit dialog still lingering
    subprocess.run(["pkill", "-f", "zenity"], capture_output=True)
    time.sleep(1)
    # Close any quit dialog windows
    subprocess.run(["xdotool", "search", "--name", "Quit", "windowclose"],
                   capture_output=True, timeout=3)
    time.sleep(1)

    # === Step 1: Title screens ===
    print("\n[1] Title screens (Enter x12)", flush=True)
    for i in range(12):
        key("Return")
        time.sleep(1)
    time.sleep(3)
    snap("01_after_title")

    # === Step 2: Command menu - Create (1) ===
    print("\n[2] Create character", flush=True)
    key("1")
    time.sleep(3)
    snap("02_create_menu")

    # === Step 3-5: Race, Gender, Career ===
    print("\n[3] Race selection", flush=True)
    key("Return")
    time.sleep(2)
    snap("03_race")
    
    print("\n[4] Gender", flush=True)
    key("Return")
    time.sleep(2)
    snap("04_gender")
    
    print("\n[5] Career", flush=True)
    key("Return")
    time.sleep(2)
    snap("05_career")

    # === Step 6: Roll stats ===
    print("\n[6] Roll & keep stats", flush=True)
    key("Return")
    time.sleep(3)
    snap("06_stats")

    # === Step 7: Skills ===
    print("\n[7] Skills (DONE)", flush=True)
    key("Tab")
    time.sleep(1)
    key("Return")
    time.sleep(3)
    snap("07_skills")

    # === Step 8: Name ===
    print("\n[8] Name character: HERO", flush=True)
    type_text("HERO")
    time.sleep(1)
    key("Return")
    time.sleep(3)
    snap("08_named")

    # === Step 9: Add to Team ===
    print("\n[9] Add to Team (6)", flush=True)
    key("6")
    time.sleep(3)
    snap("09_add_team")
    key("Return")
    time.sleep(3)
    snap("10_hero_on_team")

    # === Step 10: Save Current Game ===
    print("\n[10] Save game (9)", flush=True)
    key("9")
    time.sleep(3)
    key("A")
    time.sleep(2)
    key("Return")
    time.sleep(4)
    snap("11_saved")

    # === Step 11: Begin Adventuring ===
    print("\n[11] Begin Adventuring (A)", flush=True)
    print("  (window may recreate here)", flush=True)
    key("A")
    time.sleep(8)
    snap("12_begin_adventure")

    # === Step 12: Explore ===
    print("\n[12] Exploring Caloris Space Port...", flush=True)
    time.sleep(5)
    snap("13_game_world")

    # Movement patterns
    for phase in range(4):
        print(f"  Phase {phase+1}/4", flush=True)
        for _ in range(10):
            key("Up")
            time.sleep(0.5)
        for _ in range(4):
            key("Right")
            time.sleep(0.5)
        for _ in range(10):
            key("Up")
            time.sleep(0.5)
        # Search / interact
        key("s")
        time.sleep(2)
        key("space")
        time.sleep(2)
        # Return/alternate
        for _ in range(6):
            key("Down")
            time.sleep(0.5)
        for _ in range(4):
            key("Left")
            time.sleep(0.5)
        # Shorter forward
        for _ in range(6):
            key("Up")
            time.sleep(0.5)
        key("f")
        time.sleep(2)
        key("space")
        time.sleep(2)

    snap("14_explored")

    # === Step 13: In-game save ===
    print("\n[13] In-game save (F10 -> S -> A)", flush=True)
    key("F10")
    time.sleep(3)
    snap("15_f10_menu")
    key("s")
    time.sleep(2)
    key("A")
    time.sleep(2)
    key("Return")
    time.sleep(4)
    snap("16_saved_ingame")

    # === Step 14: Copy saves ===
    print("\n[14] Copy saves", flush=True)
    for p in SAVE.iterdir():
        dest = POST / p.name
        if p.is_file():
            with open(p, "rb") as src:
                with open(dest, "wb") as dst:
                    dst.write(src.read())
    snap("17_final_state")

    # === Step 15: Cleanup ===
    print("\n[15] Cleanup", flush=True)
    proc.terminate()
    time.sleep(1)
    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)

    print(f"\n=== DONE ===", flush=True)
    print(f"Saves in: {POST}", flush=True)
    for p in sorted(POST.iterdir()):
        if p.is_file():
            print(f"  {p.name}: {p.stat().st_size}B", flush=True)


if __name__ == "__main__":
    run()
