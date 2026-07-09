# ECL Disassembly Pass 1

Date: 2026-06-19

## What Changed

Added `scripts/ecl_disassemble.py`, a Python first-pass ECL disassembler adapted from Simeon Pilgrim's ECLDump approach.

The script follows ECL entry points, `GOTO`, `GOSUB`, and `ON GOTO` branches instead of doing a blind linear sweep.

Run:

```bash
python3 scripts/ecl_disassemble.py \
  "$MATRIX_CUBED_GAME_DIR/ECL1.DAX" \
  generated/ecl1_disasm
```

## Output

- 33 ECL listings written to `generated/ecl1_disasm/`.
- Summary table: `generated/ecl1_disasm/summary.tsv`.
- 1,487 decoded `PRINT` / `PRINTCLEAR` lines found in the listings.

## Confirmed Opcode Table

The first pass recognizes opcodes `0x00` through `0x40` from ECLDump:

- flow: `EXIT`, `GOTO`, `GOSUB`, `RETURN`, `NEWECL`
- conditionals: `COMPARE`, `COMPARE AND`, `IF =`, `IF <>`, `IF <`, `IF >`, `IF <=`, `IF >=`
- state/math: `SAVE`, `ADD`, `SUBTRACT`, `DIVIDE`, `MULTIPLY`, `RANDOM`, `AND`, `OR`
- display/dialog: `PRINT`, `PRINTCLEAR`, `PICTURE`, `HORIZONTAL MENU`, `VERTICAL MENU`, `PARLAY`
- encounter/combat: `SETUP MONSTER`, `LOAD MONSTER`, `CLEARMONSTERS`, `COMBAT`, `ENCOUNTER MENU`, `SURPRISE`, `DAMAGE`, `TREASURE`
- map/resource: `LOAD FILES`, `LOAD PIECES`, `CALL`, `PROGRAM`

## Readable Startup Example

`generated/ecl1_disasm/ecl1_001.ecl.txt` now clearly shows:

- hidden startup prompt: `DO YOU WANT TO START FROM SCRATCH OR USE THE JUMPER?`
- menu options: `JUMPER`, `START`
- initial GEO load: `Load GEO 1`
- wall definition load: `Load WALLDEF 127 127 7`
- initial position: `mapPosX = 9`, `mapPosY = 4`, `mapDirection = 3`
- `NEWECL` loads the selected area/event block.

## Useful Content Found

Examples of recovered event text:

- `THE AIRLOCK IS SEALED.`
- `SCOT.DOS APPEARS ON THE SCREEN.`
- `A PRISONER TRANSFER IS TAKING PLACE ON THE DOCKS AT BERTH A.`
- `SECURITY BOTS GUARD THE AIRLOCK.`
- `RAM WARRIORS STAND BY THE AIRLOCK WITH GUARD DOGS.`
- `THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'`
- `WHERE DO YOU WISH TO GO?`
- `YOU ENTER 'THE LOST ORBIT' -- SALVATION'S PORT LOUNGE.`

## Current Limitations

- Some branch targets decode to bytes above the known opcode range. These are probably data/table/string targets or alignment artifacts, but Matrix Cubed may also have Buck Rogers-specific commands.
- Memory names are inherited from Gold Box ECLDump and need Matrix Cubed-specific validation.
- ECL block purposes are only partially identified. Block 1 is clearly startup/jumper logic. Block 17 appears to include Caloris/port/coronation-area events.

## Follow-Up Fix

The first Python port initially kept the conditional `skip next op` state active too long. That caused some false fallthrough into table/data bytes. The decoder now resets that state after the affected instruction and separately records suspect branch/data targets whose first byte is outside the known opcode table.

After regeneration:

- `ECL1` block 1 decodes with 32 instructions and 0 unknown opcodes.
- All listings include a `Suspect branch/data targets not decoded as code` section where applicable.
- The regenerated atlas uses the cleaner listings.

## Next Target

Parse `GEO1.DAX` so ECL block ids can be tied to map/area records and event trigger locations.
