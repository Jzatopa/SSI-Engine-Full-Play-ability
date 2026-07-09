# Data Model Catalog Pass 1

Date: 2026-06-20

## Goal

Move beyond visual/map/event reconstruction into source-data decoding for the systems needed by a playable reimplementation.

This pass focuses on:

- monster/character records,
- item templates,
- special/effect records,
- structural block summaries for remaining model files.

## What Changed

Added:

- `scripts/build_data_model_catalog.py`
- `generated/data_model/data_block_catalog.json`
- `generated/data_model/data_model_catalog.md`
- `generated/data_model/mon0cha_monsters.json`
- `generated/data_model/mon0cha_monsters.tsv`
- `generated/data_model/item0_templates.json`
- `generated/data_model/item0_templates.tsv`
- `generated/data_model/mon0spc_effects.json`
- `generated/data_model/mon0spc_effects.tsv`

## Results

Decoded or cataloged:

- `MON0CHA.DAX`: 63 fixed 259-byte monster/character records.
- `ITEM0.DAX`: 91 fixed 16-byte item-template records.
- `MON0SPC.DAX`: 118 fixed 9-byte effect records across 35 blocks.
- `MON0ITM.DAX`: blocks split into 62-byte structural records; later aligned-payload analysis proves a 16-byte ITEM0-shaped payload at record offset 46. The first 46 bytes, non-exact payloads, and equipped state remain unresolved.
- `SHIPS.DAX`: structural catalog only; appears to mix large art-like blocks with smaller data/code-like blocks.

## Important Findings

`MON0CHA.DAX` is now a useful source-data table:

- names decode cleanly as Pascal-style strings,
- base stat offsets line up with the Gold Box character/monster family,
- examples include `SID REFUGE`, `PURGE COMMANDO`, `KILLER KANE`, `BUCK ROGERS`, `JOVIAN DRAGON`, and `WASPHOPPER`.

However, Matrix Cubed's 259-byte records are not a direct copy of the older 0x11D PoolRad layout:

- old Gold Box HP/AC/XP offsets are mostly zero here,
- offsets `0x45` and `0xE3` vary identically across all records and look like important Matrix Cubed-specific combat/encounter values,
- later combat field names must be confirmed by call sites or live battle captures before being treated as source truth.

`ITEM0.DAX` matches a 16-byte item-template shape closely enough to decode:

- location,
- hands,
- large/small-medium damage dice,
- rate,
- protection,
- damage/melee flags,
- range,
- class restrictions,
- ammo type.

`MON0SPC.DAX` matches the Gold Box 9-byte effect-record shape:

- effect code,
- duration,
- effect data,
- table flag,
- next-effect pointer.

## Qwen Advisory

James asked to use Qwen when it saves tokens without losing quality.

Historical note: this pass used an early Qwen 3.6 advisory attempt before the project standard was tightened to Qwen Coder only. It responded, but it incorrectly called Matrix Cubed a PS1 project and suggested some nonexistent paths. Useful guidance from it was limited to the broad priority of:

- opcode coverage,
- memory/global layout,
- deterministic runtime loop,
- shared data loaders for desktop/web.

I used that only as a high-level sanity check and did the actual decode directly from local files.

Current policy: future "Qwen" usage means `qwen3-coder:30b`, not Qwen 3.6.

## Validation

Checks performed:

- Python compile for `scripts/build_data_model_catalog.py`.
- Generated all JSON/TSV/Markdown outputs.
- Confirmed output counts:
  - 182 cataloged model blocks,
  - 63 `MON0CHA` monster/character records,
  - 91 `ITEM0` templates,
  - 118 `MON0SPC` effect records.
- Ran an offset-variance scan on `MON0CHA.DAX` to avoid overlabeling old Gold Box combat fields.

## Next Step

Highest-leverage next pass:

1. Cross-reference `MON0CHA` record IDs against ECL `LOAD MONSTER` and `SETUP MONSTER` operands.
2. Add monster names and candidate stats into the runtime encounter/action bridge.
3. Start a focused `MON0CHA` field-identification notebook by correlating offsets with battle behavior, ECL usage, and live captures.
4. Do a separate `SHIPS.DAX` pass because ship combat is a major subsystem and the block shapes differ sharply from character/item/effect records.
