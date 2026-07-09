#!/usr/bin/env python3
"""
Brute-force scan: load game, begin adventuring, try multiple key sequences to save.
"""

import subprocess, time, os, sys
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

def get_save_hash():
    """Get MD5 of SAVGAMA.DAT to detect changes."""
    sav = SAVE / "SAVGAMA.DAT"
    if sav.exists():
        import hashlib
        return hashlib.md5(sav.read_bytes()).hexdigest()
    return "MISSING"

def run():
    print("=" * 60, flush=True)
    print("MATRIX CUBED - SAVE KEY SCANNER", flush=True)
    print("=" * 60, flush=True)

    # Kill stale
    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True, timeout=5)
    subprocess.run(["pkill", "-f", "zenity"], capture_output=True, timeout=5)
    time.sleep(3)

    # Save pre state
    pre_hash = get_save_hash()
    pre_files = {p.name: p.read_bytes() for p in SAVE.iterdir() if p.is_file()}
    print(f"Pre hash: {pre_hash}", flush=True)

    # Launch
    proc = subprocess.Popen(["dosbox-x", "-conf", CONF],
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    for i in range(30):
        win = find_window()
        if win:
            break
        time.sleep(1)
    time.sleep(10)

    # Advance through title
    for _ in range(10):
        send_key("Return")
        time.sleep(1)
    time.sleep(3)
    snap("scan_01_title")

    # Load save: option 8 then slot A
    send_key("8")
    time.sleep(3)
    send_key("A")
    time.sleep(5)
    send_key("Return")
    time.sleep(5)
    snap("scan_02_loaded")

    # Begin Adventuring: 1 then 0
    send_key("1")
    time.sleep(0.3)
    send_key("0")
    time.sleep(8)
    snap("scan_03_adventuring")

    # Wait for game world
    time.sleep(5)
    snap("scan_04_game_world")

    # === TRY MULTIPLE SAVE KEY SEQUENCES ===
    # Each sequence: capture hash before, send keys, capture hash after
    
    sequences = [
        ("F5_S_A", ["F5", "s", "A", "Return"]),
        ("F5_S_A_Return", ["F5", "s", "A", "Return"]),
        ("F7_S_A", ["F7", "s", "A", "Return"]),
        ("Ctrl_O_S_A", ["Ctrl+o", "s", "A", "Return"]),
        ("Escape_S_A", ["Escape", "s", "A", "Return"]),
        ("F10_S_A", ["F10", "s", "A", "Return"]),
        ("F10_S_S", ["F10", "s", "s", "Return"]),
        ("F10_Enter_S_A", ["F10", "Return", "s", "A", "Return"]),
        ("S_A_Return", ["s", "A", "Return"]),
    ]

    for seq_name, keys in sequences:
        print(f"\n=== Trying: {seq_name} ===", flush=True)
        before_hash = get_save_hash()
        
        for k in keys:
            send_key(k)
            time.sleep(2)
        
        time.sleep(4)  # Give game time to save
        
        after_hash = get_save_hash()
        if after_hash != before_hash:
            print(f"  ✓ SAVGAMA CHANGED! Sequence: {seq_name}", flush=True)
            print(f"    Before: {before_hash}", flush=True)
            print(f"    After:  {after_hash}", flush=True)
            snap(f"scan_hit_{seq_name}")
            # Found it! Copy saves and exit
            for p in SAVE.iterdir():
                if p.is_file():
                    dest = POST / p.name
                    dest.write_bytes(p.read_bytes())
            proc.terminate()
            return
        else:
            print(f"  ✗ No change", flush=True)
        
        snap(f"scan_{seq_name}")
        
        # After each failed attempt, go back to game world
        # Most sequences will leave us at some state, press Escape a few times to recover
        for _ in range(5):
            send_key("Escape")
            time.sleep(1)

    print("\n=== None of the save sequences worked ===", flush=True)
    proc.terminate()
    time.sleep(1)
    subprocess.run(["pkill", "-f", "dosbox-x"], capture_output=True)
    print("Done", flush=True)

if __name__ == "__main__":
    run()
