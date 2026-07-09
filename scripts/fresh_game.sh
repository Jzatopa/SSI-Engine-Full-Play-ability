#!/bin/bash
# Matrix Cubed fresh game: create char, add to team, begin adventuring, explore, save, combat
set -e

WORKSPACE="/home/jzatopa/.openclaw/workspace/matrix-cubed-re"
LIVEPLAY="/home/jzatopa/Downloads/matrix-cubed-liveplay"
POST="$WORKSPACE/generated/liveplay/post_combat"
SDIR="$POST/screens"

export DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy

echo "=== MATRIX CUBED FRESH GAME ==="

mkdir -p "$SDIR"

# Snapshot helper
snap() { 
    ffmpeg -y -f x11grab -video_size 1280x1024 -i :99.0 -vframes 1 "$SDIR/$1.png" 2>/dev/null || true
    echo "  [snap] $1"
}

# Kill stale
pkill -f dosbox-x 2>/dev/null || true
sleep 2

# Launch
echo "[launch]"
dosbox-x -conf "$LIVEPLAY/dosbox-conf/start.conf" &
DOSPID=$!
echo "  PID: $DOSPID"

# Wait for window
for attempt in $(seq 1 30); do
    WIN=$(xdotool search --name "DOSBox-X" 2>/dev/null | head -1)
    [ -n "$WIN" ] && break
    sleep 1
done
echo "  Window: $WIN"
sleep 10  # Boot + MATRIX.CFG + KEYS/GRAPHICS

snap "01_boot"

# === Step 1: Advance through title/KEYS screens ===
echo "[1] Title / KEYS screens (Enter x12)"
for i in $(seq 1 12); do
    xdotool key --window "$WIN" --delay 100 Return
    sleep 1
done
sleep 3
snap "02_after_title"

# === Step 2: Should be at Command Menu ===
# Command menu: 1=Create 2=Purge 3=Modify 4=Train 5=View 6=Add 7=Remove
#              8=Load 9=Save  A=Begin Adventuring  F10=Exit
# Press 1 for Create
echo "[2] Create character (option 1)"
xdotool key --window "$WIN" --delay 100 1
sleep 3
snap "03_create_menu"

# === Step 3: Character creation - Race selection ===
# Pick first race (Enter to select)
echo "[3] Pick race (Enter x2)"
xdotool key --window "$WIN" --delay 100 Return
sleep 2
snap "04_race_selected"

# === Step 4: Gender ===
# Pick first gender (Enter)
echo "[4] Pick gender (Enter)"
xdotool key --window "$WIN" --delay 100 Return
sleep 2
snap "05_gender_selected"

# === Step 5: Career ===
# Pick first career (Enter)
echo "[5] Pick career (Enter)"
xdotool key --window "$WIN" --delay 100 Return
sleep 2
snap "06_career_selected"

# === Step 6: Roll stats ===
# Keep rolling until reasonable stats (Enter to re-roll, wait then Enter to keep)
# For simplicity, just accept whatever we get
echo "[6] Roll stats - keeping first roll (Enter)"
sleep 2
xdotool key --window "$WIN" --delay 100 Return
sleep 2
snap "07_stats_accepted"

# === Step 7: Skill allocation ===
# Press DONE (tab to DONE then Enter, or just Enter if DONE is default)
# Actually we might need to press Tab then Enter to reach DONE
echo "[7] Skill allocation - pressing Tab then Enter for DONE"
xdotool key --window "$WIN" --delay 100 Tab
sleep 1
xdotool key --window "$WIN" --delay 100 Return
sleep 2
snap "08_skill_done"

# === Step 8: Name the character ===
# Type "HERO" and Enter
echo "[8] Naming character 'HERO'"
xdotool type --window "$WIN" --delay 50 HERO
sleep 1
xdotool key --window "$WIN" --delay 100 Return
sleep 3
snap "09_named"

# === Step 9: Back at command menu - Add to Team ===
# Press 6 for Add to Team
echo "[9] Add to Team (option 6)"
xdotool key --window "$WIN" --delay 100 6
sleep 3
snap "10_add_to_team"

# HERO should be the first character listed; press Enter to select
xdotool key --window "$WIN" --delay 100 Return
sleep 3
snap "11_hero_on_team"

# === Step 10: Save Current Game ===
# Press 9 for Save Current Game
echo "[10] Save Current Game (option 9)"
xdotool key --window "$WIN" --delay 100 9
sleep 3
# Select save slot A
xdotool key --window "$WIN" --delay 100 A
sleep 3
# Confirm
xdotool key --window "$WIN" --delay 100 Return
sleep 4
snap "12_save_game"

# === Step 11: Begin Adventuring ===
# Press A for Begin Adventuring
echo "[11] Begin Adventuring (option A)"
xdotool key --window "$WIN" --delay 100 A
sleep 5
snap "13_begin_adventure"

# === Step 12: Game started - explore! ===
echo "[12] Exploring..."
sleep 5
snap "14_game_started"

# Walk extensively in patterns to trigger encounters
for pattern in 1 2 3 4 5; do
    # Forward
    for i in $(seq 1 8); do
        xdotool key --window "$WIN" --delay 50 Up
        sleep 0.5
    done
    # Right
    for i in $(seq 1 3); do
        xdotool key --window "$WIN" --delay 50 Right
        sleep 0.5
    done
    # Forward more
    for i in $(seq 1 8); do
        xdotool key --window "$WIN" --delay 50 Up
        sleep 0.5
    done
    # Search
    xdotool key --window "$WIN" --delay 50 s
    sleep 2
    # Interact
    xdotool key --window "$WIN" --delay 50 space
    sleep 2
    # Walk back/around
    for i in $(seq 1 5); do
        xdotool key --window "$WIN" --delay 50 Down
        sleep 0.5
    done
    # Alternate
    for i in $(seq 1 3); do
        xdotool key --window "$WIN" --delay 50 Left
        sleep 0.5
    done
    for i in $(seq 1 8); do
        xdotool key --window "$WIN" --delay 50 Up
        sleep 0.5
    done
done

snap "15_explored"

# Phase 2: Wider exploration with diagonal searching
echo "  Phase 2: Wide exploration..."
for pattern in 1 2; do
    for i in $(seq 1 12); do
        xdotool key --window "$WIN" --delay 50 Up
        sleep 0.4
    done
    xdotool key --window "$WIN" --delay 50 s
    sleep 2
    xdotool key --window "$WIN" --delay 50 f
    sleep 2
    for i in $(seq 1 12); do
        xdotool key --window "$WIN" --delay 50 Down
        sleep 0.4
    done
    for i in $(seq 1 8); do
        xdotool key --window "$WIN" --delay 50 Right
        sleep 0.4
    done
    for i in $(seq 1 12); do
        xdotool key --window "$WIN" --delay 50 Up
        sleep 0.4
    done
    xdotool key --window "$WIN" --delay 50 space
    sleep 2
    for i in $(seq 1 8); do
        xdotool key --window "$WIN" --delay 50 Down
        sleep 0.4
    done
    for i in $(seq 1 3); do
        xdotool key --window "$WIN" --delay 50 Left
        sleep 0.4
    done
done

snap "16_wide_explored"

# === Step 13: Save game (F10 → Save) ===
echo "[13] Saving game..."
xdotool key --window "$WIN" --delay 100 F10
sleep 3
snap "17_f10_menu"

xdotool key --window "$WIN" --delay 100 s
sleep 2
xdotool key --window "$WIN" --delay 100 A
sleep 2
xdotool key --window "$WIN" --delay 100 Return
sleep 4
snap "18_saved"

# === Step 14: Copy saves ===
echo "[14] Copying save files to post_combat..."
mkdir -p "$POST"
cp "$LIVEPLAY/SAVE"/*.* "$POST/" 2>/dev/null || true
ls -la "$POST/"

# === Step 15: Cleanup ===
echo "[15] Cleanup..."
kill "$DOSPID" 2>/dev/null || true
sleep 1
pkill -f dosbox-x 2>/dev/null || true
echo "=== DONE ==="
