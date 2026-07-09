#!/bin/bash
# Matrix Cubed combat run: load saved game, explore until combat, save after
set -e

WORKSPACE="/home/jzatopa/.openclaw/workspace/matrix-cubed-re"
LIVEPLAY="/home/jzatopa/Downloads/matrix-cubed-liveplay"
CONF="$LIVEPLAY/dosbox-conf/start.conf"
SAVE="$LIVEPLAY/MATRIX/SAVE"
POST="$WORKSPACE/generated/liveplay/post_combat"

export DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy

echo "=== MATRIX CUBED COMBAT RUN ==="

# Pre-backup
mkdir -p "$POST"
cp "$SAVE"/*.* "$POST/" 2>/dev/null || true
echo "[pre-copy saved]"

# Kill stale DOSBox-X
pkill -f dosbox-x 2>/dev/null || true
sleep 2

# Launch DOSBox-X
echo "[launch]"
dosbox-x -conf "$CONF" &
DOSPID=$!
echo "  DOSBox-X PID: $DOSPID"

# Wait for window
for attempt in $(seq 1 30); do
    WIN=$(xdotool search --name "DOSBox-X" 2>/dev/null | head -1)
    if [ -n "$WIN" ]; then break; fi
    sleep 1
done
echo "  Window: $WIN"
sleep 8  # Wait for boot + config

# === Step 1: Advance through title screens ===
echo "[step 1] Title screens - pressing Enter 10x"
for i in $(seq 1 10); do
    xdotool key --window "$WIN" --delay 100 Return
    sleep 1
done
sleep 3

# === Step 2: Command menu - press 9 for Begin Adventuring ===
echo "[step 2] Begin Adventuring"
xdotool key --window "$WIN" --delay 100 9
sleep 3

# === Step 3: Load slot A ===
echo "[step 3] Load save slot A"
xdotool key --window "$WIN" --delay 100 A
sleep 4

# Confirm
xdotool key --window "$WIN" --delay 100 Return
sleep 5

# Take screenshot
ffmpeg -y -f x11grab -video_size 1280x1024 -i :99.0 -vframes 1 \
    "$POST/step4_after_load.png" 2>/dev/null || true

# === Step 4: Game loaded - explore ===
echo "[step 4] Game loaded - exploring for combat..."

# The Caloris Space Port is the starting area (GEO 17)
# Walk extensively in all directions to trigger random/event encounters
TOTAL_STEPS=200

for step in $(seq 1 $TOTAL_STEPS); do
    # Alternate direction patterns to cover ground
    case $((step % 12)) in
        0|1|2)   DIR=Up ;;
        3|4|5)   DIR=Down ;;
        6|7|8)   DIR=Left ;;
        9|10|11) DIR=Right ;;
    esac

    xdotool key --window "$WIN" --delay 50 "$DIR"
    
    # Press Space every 3rd step to interact/search
    if [ $((step % 3)) -eq 0 ]; then
        xdotool key --window "$WIN" --delay 50 space
        sleep 1
    fi

    # Press F every 5th step (fast/search mode)
    if [ $((step % 5)) -eq 0 ]; then
        xdotool key --window "$WIN" --delay 50 f
        sleep 1
    fi

    sleep 0.4
done

sleep 2
ffmpeg -y -f x11grab -video_size 1280x1024 -i :99.0 -vframes 1 \
    "$POST/step5_after_explore.png" 2>/dev/null || true

# === Step 5: F10 → Save game ===
echo "[step 5] Saving game..."
xdotool key --window "$WIN" --delay 100 F10
sleep 4

# Press S for Save
xdotool key --window "$WIN" --delay 100 s
sleep 3

# Press A for slot A
xdotool key --window "$WIN" --delay 100 A
sleep 3

# Confirm
xdotool key --window "$WIN" --delay 100 Return
sleep 4

ffmpeg -y -f x11grab -video_size 1280x1024 -i :99.0 -vframes 1 \
    "$POST/step6_after_save.png" 2>/dev/null || true

# === Step 6: Copy post-combat save files ===
echo "[step 6] Copying save files..."
cp "$SAVE"/*.* "$POST/" 2>/dev/null || true

# === Step 7: Kill DOSBox-X ===
echo "[step 7] Cleanup..."
kill "$DOSPID" 2>/dev/null || true
sleep 1
pkill -f dosbox-x 2>/dev/null || true

echo "=== DONE ==="
ls -la "$POST/"
