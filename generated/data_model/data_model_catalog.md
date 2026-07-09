# Matrix Cubed Data Model Catalog

This is a source-data pass over non-map, non-image model files. It favors conservative structure over overconfident names.

## File Summary

| File | Blocks | Raw sizes | Record-size hints |
| --- | ---: | --- | --- |
| `ITEM0.DAX` | 1 | 1456x1 | 16 |
| `MON0CHA.DAX` | 63 | 259x63 | 259 |
| `MON0ITM.DAX` | 42 | 62x3, 124x7, 186x13, 248x12, 310x4, 372x2, 434x1 | 62 |
| `MON0SPC.DAX` | 35 | 9x7, 18x8, 27x5, 36x1, 45x11, 54x1, 63x1, 72x1 | 9 |
| `SHIPS.DAX` | 41 | 108x6, 254x6, 326x2, 510x6, 582x1, 646x1, 838x2, 894x1, 1030x2, 1350x1, 2118x1, 2310x1, 2630x1, 3910x2, 5830x1, 9342x1, 17582x5, 31102x1 | - |

## Monster / Character Records

`MON0CHA.DAX` decodes as 63 fixed 259-byte records. Names and base stats line up with the Gold Box character/monster record family, but later combat fields are a Matrix Cubed variant and are not yet fully named.

| ID | Name | STR | INT | DEX | Candidate 0x45 | Candidate 0xE3 | Visuals |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | --- |
| 1 | SID REFUGE | 16 | 14 | 10 | 84 | 84 | H6 B8 I8 |
| 2 | SID REFUGE | 17 | 16 | 10 | 91 | 91 | H0 B0 I0 |
| 3 | SID REFUGE | 18 | 17 | 10 | 98 | 98 | H25 B25 I25 |
| 4 | SID REFUGE | 18 | 18 | 10 | 105 | 105 | H25 B25 I25 |
| 5 | PURGE COMMANDO | 14 | 10 | 10 | 56 | 56 | H25 B25 I25 |
| 6 | PURGE WARRIOR | 10 | 10 | 10 | 42 | 42 | H25 B25 I25 |
| 7 | WARRIOR | 18 | 17 | 10 | 63 | 63 | H6 B2 I0 |
| 8 | PURGE SEC ROBOT | 10 | 18 | 10 | 60 | 60 | H0 B0 I0 |
| 9 | ORG SKORP | 10 | 10 | 10 | 56 | 56 | H0 B0 I0 |
| 10 | COYODORG | 14 | 15 | 10 | 49 | 49 | H0 B0 I0 |
| 11 | RATWURST | 10 | 10 | 10 | 52 | 52 | H0 B0 I0 |
| 12 | GANG LEADER | 18 | 16 | 10 | 77 | 77 | H8 B5 I5 |
| 13 | GANG VETERAN | 18 | 16 | 10 | 56 | 56 | H8 B8 I2 |
| 14 | LUNARIAN WARR | 10 | 10 | 10 | 56 | 56 | H1 B1 I4 |
| 15 | LUNARIAN WARR | 15 | 17 | 17 | 56 | 56 | H12 B7 I7 |
| 16 | LUNARIAN LEADER | 14 | 13 | 10 | 70 | 70 | H35 B35 I8 |
| 17 | LUNAR SEC ROBOT | 10 | 10 | 10 | 105 | 105 | H0 B0 I0 |
| 18 | CARNIFERN | 10 | 10 | 0 | 91 | 91 | H0 B0 I0 |
| 19 | AMALTHEAN WARR | 10 | 10 | 10 | 84 | 84 | H8 B1 I1 |
| 20 | AMALTHEAN LEAD | 10 | 14 | 10 | 91 | 91 | H1 B1 I3 |
| 21 | AMALTH SEC BOT | 10 | 10 | 10 | 91 | 91 | H0 B0 I0 |
| 22 | VENUS DINOSAUR | 17 | 16 | 10 | 91 | 91 | H0 B0 I0 |
| 23 | LOWLANDER MINER | 17 | 10 | 10 | 28 | 28 | H0 B0 I0 |
| 24 | TERRINE WARRIOR | 16 | 14 | 10 | 38 | 38 | H9 B9 I0 |
| 25 | LOWLANDER | 17 | 10 | 10 | 28 | 28 | H0 B0 I0 |
| 26 | DESERT RUNNER | 16 | 16 | 10 | 42 | 42 | H5 B5 I0 |
| 27 | LOWLANDER | 19 | 15 | 15 | 28 | 28 | H0 B0 I0 |
| 28 | DESERT RUNNER | 19 | 18 | 15 | 55 | 55 | H5 B5 I0 |
| 29 | STORMRIDER | 19 | 14 | 15 | 84 | 84 | H13 B14 I14 |
| 30 | KILLER KANE | 16 | 18 | 17 | 53 | 53 | H0 B0 I0 |
| 31 | DR. J. MALCOLN | 16 | 19 | 10 | 120 | 120 | H0 B0 I0 |
| 32 | STAGE 5 ECG | 16 | 20 | 10 | 98 | 98 | H0 B0 I0 |
| 33 | MER. WARRIOR | 13 | 15 | 10 | 49 | 49 | H0 B0 I0 |
| 35 | MER. H.S. ROBOT | 14 | 14 | 3 | 77 | 77 | H0 B0 I0 |
| 36 | HYPERCRAB | 18 | 15 | 3 | 28 | 28 | H0 B0 I0 |
| 37 | HYPERSNAKE | 16 | 17 | 3 | 32 | 32 | H0 B0 I0 |
| 38 | TECHNICIAN | 17 | 17 | 10 | 55 | 55 | H0 B0 I0 |
| 39 | LG. E.C. GENNIE | 19 | 19 | 3 | 35 | 35 | H0 B0 I0 |
| 40 | SAND SQUID | 14 | 22 | 3 | 36 | 36 | H0 B0 I0 |
| 41 | URSADDER | 15 | 17 | 3 | 38 | 38 | H0 B0 I0 |
| 42 | ACID FROG | 14 | 15 | 3 | 36 | 36 | H0 B0 I0 |
| 43 | PIRATE WARRIOR | 17 | 17 | 10 | 46 | 46 | H7 B2 I0 |
| 44 | PIRATE LEADER | 18 | 18 | 10 | 58 | 58 | H2 B6 I6 |
| 45 | PIR. COM. ROBOT | 16 | 17 | 10 | 74 | 74 | H0 B0 I0 |
| 46 | RAM ASSASSIN | 13 | 16 | 10 | 57 | 57 | H2 B2 I0 |
| 47 | RAM G.D. GENNIE | 18 | 16 | 3 | 55 | 55 | H0 B0 I0 |
| 48 | ASSAULT ROBOT | 18 | 17 | 3 | 91 | 91 | H0 B0 I0 |
| 49 | COMBAT ROBOT | 16 | 16 | 3 | 108 | 108 | H0 B0 I0 |
| 50 | SECURITY ROBOT | 16 | 16 | 3 | 40 | 40 | H0 B0 I0 |
| 51 | DEFENSE ROBOT | 16 | 16 | 3 | 51 | 51 | H0 B0 I0 |
| 52 | RAM WARRIOR | 18 | 17 | 10 | 47 | 47 | H11 B11 I0 |
| 53 | TECHNICIAN | 12 | 18 | 13 | 32 | 32 | H0 B0 I0 |
| 54 | RAM CBT. GENNIE | 18 | 18 | 10 | 66 | 66 | H6 B8 I8 |
| 55 | LEANDER | 17 | 14 | 17 | 46 | 46 | H13 B7 I7 |
| 56 | ZANE | 4 | 12 | 12 | 8 | 8 | H0 B0 I0 |
| 57 | BUCK ROGERS | 17 | 18 | 14 | 63 | 63 | H0 B0 I0 |
| 58 | GANG MEMBER | 14 | 12 | 10 | 49 | 49 | H2 B8 I0 |
| 59 | GANG RECRUIT | 12 | 10 | 10 | 43 | 43 | H2 B7 I0 |
| 60 | D.R. WARRIOR | 19 | 17 | 14 | 58 | 58 | H5 B5 I0 |
| 61 | LL. WARRIOR | 17 | 14 | 10 | 42 | 42 | H19 B19 I0 |
| 62 | LL. WARRIOR | 19 | 15 | 13 | 42 | 42 | H19 B19 I0 |
| 63 | JOVIAN DRAGON | 10 | 19 | 10 | 102 | 102 | H0 B0 I0 |
| 64 | WASPHOPPER | 12 | 19 | 3 | 24 | 24 | H0 B0 I0 |

## Item Templates

`ITEM0.DAX` block 1 is 1456 bytes, exactly 91 records of 16 bytes. The byte layout matches the Gold Box item-template shape closely enough to decode combat and equipment properties.

- decoded template records: 91

## Effects

`MON0SPC.DAX` block sizes are multiples of 9 bytes and match the Gold Box effect-record shape.

- decoded effect records: 118

## Open Questions

- Confirm Matrix Cubed's MON0CHA combat field layout. Old Gold Box offsets for HP/AC/XP do not directly line up; offsets `0x45` and `0xE3` vary identically and look like high-value encounter/combat fields.
- `MON0ITM.DAX` block sizes are multiples of 62, but early blocks look like 16-bit code or embedded routines rather than simple item records; leave them as structural blocks until call sites identify their role.
- `SHIPS.DAX` mixes large art-like blocks and smaller data/code-like blocks; it needs a dedicated ship-system pass.
- Saved party records are not present in the extracted base directory; they will need live save files or installer/runtime-created save files.
