# First Map Liveplay Qwen OCR Reference

Generated during the 2026-06-30 first-map capture pass.

## Capture Runs

- `generated/liveplay/first_map_capture/`: seeded-save run, 20 nonblank screenshots, but boot/world frames are corrupted.
- `generated/liveplay/first_map_fresh_capture/`: fresh-character run, 26 nonblank screenshots, but boot/world frames are corrupted.
- `generated/liveplay/first_map_fresh_capture_noescape/`: fresh-character run without boot `Escape`, 25 nonblank screenshots, but boot/world frames are still corrupted.
- `generated/liveplay/first_map_direct_probe/`: direct live install boot probe, 1 nonblank screenshot, also corrupted.

Boundary: current DOSBox-X/Xvfb capture path did not produce a readable first-map game viewport. The OCR below is useful for menu/UI reference only. Do not promote the corrupted first-map frames as original map text evidence.

## Qwen OCR Results

Model: `ollama/qwen3.6:latest` via `openclaw infer model run --file`.

### `generated/liveplay/screens/team_00_menu.png`

```text
Main CPU Video Sound DOS Capture Drive Help
CREATE NEW CHARACTER
ADD CHARACTER TO TEAM
LOAD SAVED GAME
JOYSTICK/MOUSE INITIALIZE
EXIT TO DOS
CHOOSE A FUNCTION SELECT
```

Qwen usability verdict: high-contrast menu text is easy to read.

### `generated/liveplay/screens/team3_00_load_from.png`

```text
Main CPU Video Sound DOS Capture Drive Help
LOAD FROM: MATRIX COUNTDOWN
```

Qwen usability verdict: text is clearly legible with high contrast.

### `generated/liveplay/screens/gamesave_00_full_menu.png`

```text
Main CPU Video Sound DOS Capture Drive Help
NAME AC HP
CAR1 4 38
CREATE NEW CHARACTER
PURGE CHARACTER
MODIFY CHARACTER
ICON SELECT
VIEW CHARACTER
ADD CHARACTER TO TEAM
REMOVE CHARACTER FROM TEAM
SAVE CURRENT GAME
BEGIN ADVENTURING
EXIT TO DOS
CHOOSE A FUNCTION SELECT
```

Qwen usability verdict: text is legible despite the pixelated font.

### `generated/liveplay/screens/s00_boot.png`

```text
Quit DOSBox-X warning
You are currently running a program or game.
Are you sure to quit anyway now?
No Yes
Main CPU Video Sound DOS Capture Drive Help
THE 25TH CENTURY BUCK ROGERS
SCIENCE FICTION ROLE-PLAYING COMPUTER GAME, VOL II
@ 1992 TSR, INC.
(c) 1992 THE DILLE FAMILY TRUST
@ 1992 STRATEGIC SIMULATIONS, INC. ALL RIGHTS RESERVED
```

Qwen usability verdict: dialog obscures context, but title/menu text remains legible.

### `generated/liveplay/first_map_fresh_capture_noescape/screens/11_first_map_world.png`

```text
Main CPU Video Sound DOS Capture Drive Help
^ ^
```

Qwen usability verdict: the game viewport is corrupted and consists of illegible memory-dump-like characters rather than readable text. The actual game state is impossible to understand from this frame.

## Evidence Notes

- The capture script used for the attempts is `scripts/capture_first_map_liveplay.py`.
- The readable OCR results come from older known-good menu captures already present under `generated/liveplay/screens/`.
- New first-map capture attempts are retained as failure evidence because they show the current recording path is not reliable for viewport OCR.
- Pre/post save capture from the copied fresh runs produced no useful map-state mutation; the fresh run did not successfully save files.
