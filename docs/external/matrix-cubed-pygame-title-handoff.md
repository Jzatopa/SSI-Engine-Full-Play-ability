# Matrix Cubed Source-Port / Reverse-Engineering Handoff

## Project goal

Reconstruct a playable modern source port / remake of **Buck Rogers: Matrix Cubed** from the original DOS runtime and data files.

This is **not** an exact recovery of the original source code. The realistic target is:

> A clean, maintainable Python/Pygame and/or C++/SDL2 source port that loads the original DOS data files, decodes the original SSI Gold Box resource formats, and reproduces the original game behavior closely enough to be playable.

The current active prototype is the **Python/Pygame debug/source-port prototype**. There is also a C++/SDL2 skeleton, but the Python prototype is currently the fastest place to continue graphics and resource decoding.

---

## Current recommended ZIP/package

The latest package used by the user was named approximately:

```text
matrix_cubed_pygame_title_compare_controls_fixed_with_data.zip
```

After extraction, the actual Python project folder was nested as:

```text
matrix_cubed_pygame_title_compare_controls_fixed_with_data/
  matrix_cubed_pygame_title_fixed_with_data/
    requirements.txt
    pyproject.toml
    src/
    data/
    docs/
```

The included `data/` folder contains the extracted original game files, so no external `--data` path should be needed.

---

## Known local run command

From the user’s Linux/Ubuntu system:

```bash
cd "$HOME/Downloads/matrix_cubed_pygame_title_compare_controls_fixed_with_data/matrix_cubed_pygame_title_fixed_with_data"
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r requirements.txt
python -m pip install -e .
python -m matrix_py
```

If the venv already exists:

```bash
cd "$HOME/Downloads/matrix_cubed_pygame_title_compare_controls_fixed_with_data/matrix_cubed_pygame_title_fixed_with_data"
source .venv/bin/activate
python -m pip install -e .
python -m matrix_py
```

Ubuntu note: use `python3 -m venv .venv`, not `python -m venv .venv`, unless `python-is-python3` is installed.

---

## User’s current verified state

The user successfully launched the Python/Pygame app.

Verified by user:

```text
- App opens.
- Data path works.
- DAX archive count is correct.
- DAX record count is correct.
- A title image is visible.
- The image is close, but not perfect.
- Many images do not render correctly yet.
- Some render modes look close, but something is off.
- Cycling candidates requires repeated key presses; user wants hold-to-cycle.
```

The DAX/record numbers expected in Asset Debug are approximately:

```text
DAX archives: 27
Records: 611
```

---

## Original game files included / expected

The original data folder should contain files such as:

```text
START.EXE
GAME.OVR
TITLE.DAX
PIC1.DAX
BIGPIC1.DAX
CPIC1.DAX
SPRIT1.DAX
COMSPR.DAX
CURSOR.DAX
BORDERS.DAX
8X8D0.DAX
8X8D1.DAX
BACK1.DAX
CHARS.DAX
ECL1.DAX
GEO1.DAX
WALLDEF1.DAX
ITEMS
ITEM0.DAX
MON0CHA.DAX
MON0ITM.DAX
MON0SPC.DAX
SHIPS.DAX
MUSIC.DAX
BUCKA.XMI
BUCKB.XMI
BUCKC.XMI
ADLIB.ADV
SBFM.ADV
MT32MPU.ADV
PCSPKR.ADV
TANDY.ADV
FATV9.AD
FATV9.BNK
FATV9.CAT
```

---

## Reference screenshot

The user supplied a DOSBox screenshot of the actual opening screen.

The screenshot shows:

```text
DOSBox 0.74-3
Program: START
VGA-style 640x480 DOSBox window
Actual game display appears as 320x200 scaled 2x.
```

Visual target:

```text
- Planet/background fills most of the screen.
- Large MATRIX CUBED logo.
- Bottom bar contains:
  MATRIX CUBED V1.0
  PLAY DEMO
```

The package should include the screenshot as something like:

```text
docs/reference_dosbox_title.png
```

If not present, add the user-supplied screenshot there.

Important conclusion:

> The actual opening screen is probably composited from multiple records/resources, not a single `TITLE.DAX` image.

Likely layers:

```text
1. planet/background art
2. MATRIX CUBED logo/title layer
3. bottom UI/text/menu layer
4. PLAY DEMO button/text
```

The title/background may involve `TITLE.DAX` plus possibly `BIGPIC1.DAX`, `PIC1.DAX`, or `BACK1.DAX`.

---

## Reverse-engineering findings so far

### START.EXE

- 16-bit DOS MZ executable.
- Appears packed/compressed.
- After unpacking, contains Borland/Turbo Pascal runtime strings.
- Acts like launcher/config/start runtime.
- References graphics/sound/input setup, save path, joystick calibration, overlay loading, and `GAME.OVR`.

### GAME.OVR

- Not a normal executable.
- Borland/VROOMM-style overlay file.
- Header: `FBOV`
- Companion overlay code/data loaded by `START.EXE`.
- Contains most of the program logic and game strings.
- Should be analyzed together with `START.EXE`, not as a flat independent executable.

### DAX archives

A DAX archive uses a directory followed by concatenated resource payloads.

Inferred container format:

```c
uint16_t dir_len_bytes;

repeat dir_len_bytes / 9:
  uint8_t  resource_id;
  uint32_t payload_offset_from_after_directory;
  uint16_t aux_field_probably_unpacked_size_or_metadata;
  uint16_t stored_size;

then concatenated payloads
```

Validated across all 27 `.DAX` files.

### DAX compression

The corrected DAX RLE decompression is Gold Box-style control-byte RLE:

```text
if high bit clear:
  copy next control + 1 literal bytes

if high bit set:
  repeat following byte 256 - control times
```

Pseudocode:

```python
def decompress_goldbox_rle(data: bytes) -> bytes:
    out = bytearray()
    i = 0
    while i < len(data):
        control = data[i]
        i += 1
        if control & 0x80:
            count = 256 - control
            value = data[i]
            i += 1
            out.extend([value] * count)
        else:
            count = control + 1
            out.extend(data[i:i + count])
            i += count
    return bytes(out)
```

This layer is likely correct because archive/record counts and many decompressed records validate.

### TITLE.DAX first-pass findings

`TITLE.DAX` contains 4 records.

Known record IDs:

```text
1
2
3
4
```

Current first-pass decoder observations:

```text
byte 0 = width units
byte 1 = height units
width  = byte0 * 4
height = byte1 * 4
pixel data appears to start at offset 0x0356 / decimal 854
format appears to be packed 4bpp
current nibble order used: high nibble first, then low nibble
```

Observed dimensions from decompressed records:

```text
Record 1: byte0 72,  byte1 40 -> 288 x 160
Record 2: byte0 144, byte1 36 -> 576 x 144
Record 3: byte0 32,  byte1 34 -> 128 x 136
Record 4: byte0 184, byte1 40 -> 736 x 160
```

Record 2 produces a recognizable Buck Rogers / Matrix Cubed title/logo, but not a complete exact DOSBox screen.

Confidence:

```text
DAX container: high
DAX RLE decompression: high
TITLE.DAX record 2 as logo/title art: high
TITLE.DAX full image composition: medium-low
Exact palette/control/placement meaning in 854-byte preamble: unresolved
```

---

## Inferred structured game data

These were inferred in an earlier structure pass:

| File | Inferred structure | Confidence |
|---|---|---:|
| `GEO1.DAX` | 25 records of `2-byte header + 32x32 map cells` = 1026 bytes | High |
| `WALLDEF1.DAX` | 11 wallsets of `39 x 60-byte wall entries` = 2340 bytes | High |
| `MON0CHA.DAX` | 63 fixed 259-byte monster/character records | High |
| `ITEM0.DAX` | 91 fixed 16-byte item records | High structurally |
| `ITEMS` | 39 fixed 9-byte rows | Medium |
| `MON0SPC.DAX` | variable 9-byte special/combat entries | Medium |
| `ECL1.DAX` | variable event/control/encounter scripts | Medium |
| `MON0ITM.DAX` | mixed monster item/equipment/script-like records | Medium-low |

### Save files

The user provided a DOSBox save ZIP.

Save analysis findings:

```text
SAVGAMA.DAT      = main/global save state, 2,901 bytes
CHRDATA1.SAV ... = character records, each 259 bytes
CHRDATA1.STF ... = per-character item/equipment records
```

Important confirmation:

> `CHRDATA*.SAV` files are exactly 259 bytes, matching the inferred `MON0CHA.DAX` record size. Player characters and monster/NPC records likely share the same base structure.

Known saved characters:

```text
CHRDATA1.SAV = ONE
CHRDATA2.SAV = THREE
CHRDATA3.SAV = TWO
CHRDATA4.SAV = FIVE
CHRDATA5.SAV = FOUR
```

`.STF` files split cleanly into 62-byte item/equipment records.

Example item names found:

```text
Spacesuit
Bolt Gun (100)
Stun Grenades
Rocket Pistol (10)
Rocket Lnchr. (10)
Needle Gun (10)
Sonic Stunner (10)
Mono Sword
Explosive Grenades
Battle armor
Heavy Body Armor
```

`SAVGAMA.DAT` visible strings included:

```text
Maelstrom Rider
HARRIER
M RIDER
DUKE'S HILL
```

---

## Relevant external reference repositories

The user asked to use Gold Box Explorer as a reference.

Clone locally:

```bash
cd "$HOME/Downloads"
git clone https://github.com/simeonpilgrim/goldboxexplorer.git
git clone https://github.com/bsimser/Gold-Box-Explorer.git
```

Expected local layout:

```text
Downloads/
  matrix_cubed_pygame_title_compare_controls_fixed_with_data/
  goldboxexplorer/
  Gold-Box-Explorer/
```

What to inspect:

```text
goldboxexplorer/
  Common/
  Explorer/
  Lib/

Gold-Box-Explorer/
  likely C# source folders containing DAX, image, and palette decoders
```

The Simeon Pilgrim repo appears to be a fork/version 1.2 of the original CodePlex project. The Bill Simser repo is the earlier Gold Box Explorer source.

Task:

> Study only the decoding logic. Do not blindly copy UI code. Port relevant DAX/image/palette decoding logic to Python.

Focus on any C# classes/functions related to:

```text
DAX archives
EGA palettes
TITLE
BIGPIC
PIC
CPIC
SPRIT
COMSPR
8x8 font
CURSOR
BORDERS
RLE decompression
image plane/nibble decoding
```

---

## Current problem to solve

### Main bug

Most decoded images do not render correctly.

Symptoms:

```text
- Some images are recognizable but visually off.
- Many images appear as stripes/noise.
- The current generic packed 4bpp decoder is insufficient.
```

Likely causes:

```text
1. Wrong palette mapping.
2. Wrong pixel-data offset.
3. Wrong width/height units for some archives.
4. The 854-byte TITLE preamble contains placement/palette/control info.
5. Images are composed from multiple records/layers.
6. Some files use planar EGA rather than packed 4bpp.
7. Some files use archive-specific headers.
8. Row stride / scanline padding is not handled correctly.
9. Nibble order may vary.
```

### Secondary UI problem

Debug candidate cycling currently requires one keypress per change.

User requested:

> Make it so the key can be held down.

---

## Immediate next implementation tasks

### 1. Fix hold-to-cycle controls

At minimum, in `src/matrix_py/app.py`, after `pygame.init()`:

```python
pygame.key.set_repeat(250, 60)
```

But the better approach is to use frame-based held-key logic inside the debug scene:

```python
keys = pygame.key.get_pressed()

if keys[pygame.K_RIGHT] or keys[pygame.K_r] or keys[pygame.K_SPACE]:
    cycle_next_candidate()

if keys[pygame.K_LEFT] or keys[pygame.K_t]:
    cycle_previous_candidate()
```

Throttle the repeat to avoid cycling too fast:

```python
self.repeat_timer += dt
if self.repeat_timer >= 0.06:
    self.repeat_timer = 0
    # apply held-key action
```

### 2. Improve debug viewer controls

Add or verify these controls:

```text
Left/Right       = previous/next candidate
Hold Left/Right  = continuous cycling
A/Z              = previous/next archive
R/F              = previous/next record
M/N              = previous/next render mode
P/O              = previous/next palette
[ / ]            = decrease/increase pixel offset
- / =            = decrease/increase row stride
G or 1           = toggle generated image
D or 2           = toggle DOSBox reference image
B or 3           = show both
S                = save current render PNG
J                = save current settings JSON
L                = load settings JSON
Esc              = back to menu
```

Display all current state onscreen:

```text
Archive: TITLE.DAX
Resource ID: 2
Record index: 2 / 4
Mode: TITLE packed 4bpp
Offset: 0x0356
Stride: auto / value
Width: 576
Height: 144
Palette: EGA default / variant name
Generated: ON
Reference: ON
JSON preset: loaded/not loaded
```

### 3. Add PNG export

On `S`, save the current generated image to:

```text
debug_output/
```

Suggested filename:

```text
debug_output/TITLE_id002_mode-title4bpp_offset0356_palette-ega.png
```

### 4. Add JSON setting save/load

On `J`, save current debug state:

```json
{
  "archive": "TITLE.DAX",
  "resource_id": 2,
  "mode": "title_packed_4bpp",
  "offset": 854,
  "width": 576,
  "height": 144,
  "stride": null,
  "nibble_order": "hi_lo",
  "palette": "ega_default",
  "scale": 1
}
```

Suggested path:

```text
debug_output/title_candidate_settings.json
```

On startup or `L`, load from that file if present.

Also create a stable default file:

```text
config/title_screen_composition.json
```

### 5. Improve title composition

Instead of choosing one `TITLE.DAX` record as the title screen, build a compositor/debug mode that can layer records and archive resources.

Investigate these resources as candidates for the DOSBox title screen:

```text
TITLE.DAX
BIGPIC1.DAX
PIC1.DAX
BACK1.DAX
BORDERS.DAX
8X8D0.DAX
```

The DOSBox screenshot likely corresponds to:

```text
base background: possibly PIC/BIGPIC/BACK
logo/title: TITLE.DAX resource 2
bottom UI/text: font-rendered or resource layer
```

Make the debug UI support side-by-side comparison with:

```text
docs/reference_dosbox_title.png
```

---

## Recommended Gold Box Explorer porting plan

### Step A: inventory decoder classes

Search the C# repos:

```bash
cd "$HOME/Downloads/goldboxexplorer"
grep -Rni "DAX\|BIGPIC\|CPIC\|TITLE\|SPRIT\|COMSPR\|palette\|EGA\|RLE" Common Lib Explorer | head -200
```

Also:

```bash
cd "$HOME/Downloads/Gold-Box-Explorer"
grep -Rni "DAX\|BIGPIC\|CPIC\|TITLE\|SPRIT\|COMSPR\|palette\|EGA\|RLE" . | head -200
```

Identify C# decoder methods and port them into Python modules.

### Step B: add Python decoder classes

Suggested new files:

```text
src/matrix_py/decoders/
  __init__.py
  goldbox_rle.py
  dax_archive.py
  palettes.py
  title.py
  bigpic.py
  pic.py
  cpic.py
  sprite.py
  font8x8.py
  compositor.py
```

Keep the old generic candidate decoder for debugging:

```text
src/matrix_py/decoders/candidate.py
```

### Step C: archive-specific route table

In asset loading:

```python
DECODER_BY_ARCHIVE = {
    "TITLE.DAX": TitleDecoder(),
    "BIGPIC1.DAX": BigPicDecoder(),
    "PIC1.DAX": PicDecoder(),
    "CPIC1.DAX": CpicDecoder(),
    "SPRIT1.DAX": SpriteDecoder(),
    "COMSPR.DAX": SpriteDecoder(),
    "CURSOR.DAX": CursorDecoder(),
    "BORDERS.DAX": BorderDecoder(),
    "8X8D0.DAX": Font8x8Decoder(),
}
```

### Step D: keep candidate mode

Even after adding real decoders, keep a debug fallback:

```python
if decoder_fails:
    use CandidateDecoder modes
```

---

## Suggested Agent Mode prompt for next environment

Use this exact prompt in a local agent environment that can see the project and cloned Gold Box Explorer repos:

```text
Use the local folders in ~/Downloads:
- matrix_cubed_pygame_title_compare_controls_fixed_with_data
- goldboxexplorer
- Gold-Box-Explorer

Study the Gold Box Explorer C# decoding code and port the relevant DAX/image decoding logic into the Python/Pygame Matrix Cubed prototype. Focus first on TITLE.DAX and the DOSBox reference screenshot at docs/reference_dosbox_title.png.

Do not attempt to recover exact original source. Do not rewrite the whole app. Improve the existing Python/Pygame prototype.

Implement:
1. Hold-to-cycle controls using either pygame.key.set_repeat or frame-based pygame.key.get_pressed with throttling.
2. Debug controls for archive, record, render mode, palette, offset, stride, nibble/planar mode, generated/reference toggles.
3. PNG export of current candidate render.
4. JSON save/load of current decoding settings.
5. A better TITLE.DAX decoder and title-screen compositor.
6. Archive-specific decoder stubs/classes for BIGPIC, PIC, CPIC, SPRIT/COMSPR, BORDERS, CURSOR, and 8X8 font formats.
7. Onscreen display of all current debug parameters.

Preserve the included original data files in data/. Keep the app runnable with:

cd "$HOME/Downloads/matrix_cubed_pygame_title_compare_controls_fixed_with_data/matrix_cubed_pygame_title_fixed_with_data"
source .venv/bin/activate
python -m pip install -e .
python -m matrix_py

After changes, provide:
- list of files changed
- exact run commands
- known remaining inaccuracies
- where PNG/JSON debug outputs are written
```

---

## Legal / licensing note

The project uses original game data/assets supplied by the user for private reverse-engineering/source-port work. Do not redistribute copyrighted original assets unless legally permitted.

Gold Box Explorer repositories may be under their own license terms. Check each repo’s `LICENSE` or headers before copying source code. Prefer to **study and reimplement** decoding logic rather than directly copying large code blocks unless the license allows it.

---

## Roadmap after graphics debug

After TITLE/BIGPIC/PIC rendering is improved:

1. Decode fonts/text rendering fully.
2. Decode CPIC portraits.
3. Decode SPRIT/COMSPR sprites.
4. Implement save parser debug screen in Python if not already present.
5. Render party roster and item inventory from `CHRDATA*.SAV` and `.STF`.
6. Render `GEO1.DAX` maps as 32x32 grids.
7. Decode `WALLDEF1.DAX` wallsets.
8. Decode `ECL1.DAX` event scripts.
9. Add minimal game scene:
   - show current location/map
   - move party marker
   - load map resources
10. Port stable decoders back to C++/SDL2 if desired.

---

## Prior artifacts/packages produced during this project

Earlier packages created during the project included:

```text
START_reverse_engineering_package.zip
GAME_OVR_reverse_engineering_package.zip
matrix_cubed_folder_analysis.zip
matrix_cubed_dax_reverse_engineering.zip
matrix_cubed_dax_extraction_tools.zip
matrix_cubed_dax_image_tools.zip
matrix_cubed_structure_inference.zip
matrix_cubed_overlay_analysis_package.zip
matrix_cubed_save_analysis_package.zip
matrix_cubed_sdl2_source_port_skeleton.zip
matrix_cubed_sdl2_source_port_with_save_debug.zip
matrix_cubed_sdl2_source_port_asset_loader.zip
matrix_cubed_pygame_prototype.zip
matrix_cubed_pygame_title_fixed.zip
matrix_cubed_pygame_title_fixed_with_data.zip
matrix_cubed_pygame_title_compare_with_data.zip
matrix_cubed_pygame_title_compare_controls_fixed_with_data.zip
```

The current continuation point should be the latest Pygame title-compare controls package with data included.

---

## Summary for next developer/agent

You are continuing a reverse-engineering/source-port project for **Buck Rogers: Matrix Cubed**.

Do not start over.

The project already has:

```text
- working DAX container parser
- working Gold Box-style RLE decompressor
- included original game data
- Pygame app loop
- menu navigation
- asset debug
- title/debug comparison screen
- DOSBox reference screenshot
- first-pass TITLE.DAX decoder
```

The next focus is:

```text
Make the debug viewer faster and more useful, then use Gold Box Explorer C# decoder logic to improve image rendering, starting with TITLE.DAX and the real DOSBox title screen.
```
