# Matrix Cubed Encounter Monster Cross-Reference

This pass joins ECL monster setup/load commands to decoded `MON0CHA.DAX` records when the operand is a direct constant.

## Summary

- total encounter-related command rows: 184
- setup_monster rows: 180
- load_monster rows: 4
- encounter_menu rows: 0
- direct constant rows linked to `MON0CHA`: 142
- dynamic rows narrowed to finite table candidates: 11
- dynamic rows needing runtime expression resolution: 2
- sentinel/pic-only rows: 29

## Most Referenced Direct Monsters

| Count | Monster |
| ---: | --- |
| 23 | RAM WARRIOR |
| 18 | PURGE COMMANDO |
| 18 | GANG LEADER |
| 13 | PIRATE LEADER |
| 13 | AMALTHEAN WARR |
| 10 | SECURITY ROBOT |
| 8 | COMBAT ROBOT |
| 7 | MER. WARRIOR |
| 7 | LL. WARRIOR |
| 6 | PIR. COM. ROBOT |
| 4 | DEFENSE ROBOT |
| 3 | RAM G.D. GENNIE |
| 3 | JOVIAN DRAGON |
| 2 | URSADDER |
| 1 | RATWURST |
| 1 | LUNARIAN WARR |
| 1 | HYPERCRAB |
| 1 | WASPHOPPER |
| 1 | SAND SQUID |
| 1 | LG. E.C. GENNIE |

## Direct Constant References

| ECL | Map | Address | Kind | ID | Monster | Distance | Pic/CPIC |
| ---: | --- | --- | --- | ---: | --- | --- | --- |
| 17 | Caloris Space Port | `0x85E9` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 17 | Caloris Space Port | `0x86ED` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 17 | Caloris Space Port | `0x8732` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 17 | Caloris Space Port | `0x87B0` | `setup_monster` | 33 | MER. WARRIOR | 0 | 255 |
| 17 | Caloris Space Port | `0x89EF` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 17 | Caloris Space Port | `0x8C27` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 17 | Caloris Space Port | `0x8C54` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 17 | Caloris Space Port | `0x91EA` | `setup_monster` | 33 | MER. WARRIOR | 0 | 255 |
| 21 | 21 | `0x8AC6` | `setup_monster` | 47 | RAM G.D. GENNIE | 0 | 255 |
| 33 | Losangelorg Sprawls | `0x8C1C` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 33 | Losangelorg Sprawls | `0x942F` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 33 | Losangelorg Sprawls | `0x966B` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 33 | Losangelorg Sprawls | `0x9B3B` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 33 | Losangelorg Sprawls | `0x9ED5` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 34 | Historical Museum, Levels 2-1 | `0x84B7` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 34 | Historical Museum, Levels 2-1 | `0x8A85` | `setup_monster` | 52 | RAM WARRIOR | 1 | 255 |
| 34 | Historical Museum, Levels 2-1 | `0x8BF2` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 34 | Historical Museum, Levels 2-1 | `0x988D` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 34 | Historical Museum, Levels 2-1 | `0x9E87` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 34 | Historical Museum, Levels 2-1 | `0x9FDD` | `setup_monster` | 50 | SECURITY ROBOT | 2 | 255 |
| 35 | Asteroid Base | `0x9EFB` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 36 |  | `0x89D7` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 36 |  | `0x8A2D` | `setup_monster` | 49 | COMBAT ROBOT | 0 | 255 |
| 36 |  | `0x8D35` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 36 |  | `0x90E6` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 36 |  | `0x921D` | `setup_monster` | 49 | COMBAT ROBOT | 0 | 255 |
| 36 |  | `0x985A` | `setup_monster` | 49 | COMBAT ROBOT | 0 | 255 |
| 36 |  | `0x9C6C` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 37 |  | `0x8384` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0x86A5` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 37 |  | `0x870F` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0x87F1` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0x8ACA` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0x8BBC` | `setup_monster` | 12 | GANG LEADER | 1 | 255 |
| 37 |  | `0x904F` | `setup_monster` | 52 | RAM WARRIOR | 1 | 255 |
| 37 |  | `0x9095` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 37 |  | `0x9278` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0x93A9` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 37 |  | `0x94A8` | `setup_monster` | 12 | GANG LEADER | 1 | 255 |
| 37 |  | `0x988C` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0xA192` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 37 |  | `0xA1EE` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 38 | Losangelorg Sprawls | `0x9754` | `load_monster` | 11 | RATWURST |  | 11 |
| 38 | Losangelorg Sprawls | `0x99F8` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 38 | Losangelorg Sprawls | `0x9B5B` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 49 | Lowlander Village | `0x8536` | `setup_monster` | 61 | LL. WARRIOR | 2 | 255 |
| 49 | Lowlander Village | `0x955E` | `setup_monster` | 61 | LL. WARRIOR | 0 | 255 |
| 49 | Lowlander Village | `0x9876` | `setup_monster` | 61 | LL. WARRIOR | 0 | 255 |
| 49 | Lowlander Village | `0x995D` | `setup_monster` | 61 | LL. WARRIOR | 1 | 255 |
| 49 | Lowlander Village | `0xA0EE` | `setup_monster` | 41 | URSADDER | 1 | 255 |
| 49 | Lowlander Village | `0xA254` | `setup_monster` | 41 | URSADDER | 0 | 255 |
| 49 | Lowlander Village | `0xA28B` | `setup_monster` | 61 | LL. WARRIOR | 2 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x85A3` | `setup_monster` | 61 | LL. WARRIOR | 2 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x874B` | `setup_monster` | 5 | PURGE COMMANDO | 1 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x89B7` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x8C94` | `setup_monster` | 5 | PURGE COMMANDO | 1 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x8CCE` | `setup_monster` | 33 | MER. WARRIOR | 1 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x8DD2` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x8E6E` | `setup_monster` | 33 | MER. WARRIOR | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x8EAB` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x8EFD` | `setup_monster` | 5 | PURGE COMMANDO | 1 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x917A` | `setup_monster` | 5 | PURGE COMMANDO | 2 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x9247` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x94D5` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x9AA7` | `setup_monster` | 5 | PURGE COMMANDO | 1 | 255 |
| 50 | Venus Laboratory, Level 1 | `0x9E34` | `setup_monster` | 61 | LL. WARRIOR | 0 | 255 |
| 50 | Venus Laboratory, Level 1 | `0xA227` | `setup_monster` | 33 | MER. WARRIOR | 0 | 255 |
| 64 | Luna Base | `0x97C6` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 64 | Luna Base | `0x97FE` | `setup_monster` | 14 | LUNARIAN WARR | 0 | 255 |
| 65 | Tsai Weaponry Labs | `0x85A4` | `setup_monster` | 5 | PURGE COMMANDO | 2 | 255 |
| 65 | Tsai Weaponry Labs | `0x85D4` | `setup_monster` | 5 | PURGE COMMANDO | 2 | 255 |
| 66 | RAM Battler, Deimos Level 19-41 | `0x9494` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 66 | RAM Battler, Deimos Level 19-41 | `0x94DF` | `setup_monster` | 52 | RAM WARRIOR | 1 | 255 |
| 66 | RAM Battler, Deimos Level 19-41 | `0x9976` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 66 | RAM Battler, Deimos Level 19-41 | `0x9A90` | `setup_monster` | 50 | SECURITY ROBOT | 1 | 255 |
| 66 | RAM Battler, Deimos Level 19-41 | `0x9B98` | `setup_monster` | 52 | RAM WARRIOR | 1 | 255 |
| 80 | Mars Prison, Level 1 | `0x8402` | `setup_monster` | 47 | RAM G.D. GENNIE | 0 | 255 |
| 80 | Mars Prison, Level 1 | `0x9371` | `setup_monster` | 49 | COMBAT ROBOT | 1 | 255 |
| 80 | Mars Prison, Level 1 | `0x9F60` | `setup_monster` | 50 | SECURITY ROBOT | 2 | 255 |
| 80 | Mars Prison, Level 1 | `0x9FD6` | `setup_monster` | 52 | RAM WARRIOR | 1 | 255 |
| 81 | PURGE Headquarters, Floors Ground-Upper | `0x8750` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 81 | PURGE Headquarters, Floors Ground-Upper | `0x953C` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 82 | NEO Installation | `0x8610` | `setup_monster` | 52 | RAM WARRIOR | 0 | 255 |
| 82 | NEO Installation | `0x8641` | `setup_monster` | 47 | RAM G.D. GENNIE | 0 | 255 |
| 82 | NEO Installation | `0x865F` | `setup_monster` | 49 | COMBAT ROBOT | 0 | 255 |
| 82 | NEO Installation | `0x906A` | `setup_monster` | 51 | DEFENSE ROBOT | 0 | 255 |
| 84 | Mars Prison, Level 2 | `0x8179` | `setup_monster` | 5 | PURGE COMMANDO | 0 | 255 |
| 84 | Mars Prison, Level 2 | `0x81D7` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 84 | Mars Prison, Level 2 | `0x850B` | `setup_monster` | 12 | GANG LEADER | 2 | 255 |
| 84 | Mars Prison, Level 2 | `0x95B4` | `setup_monster` | 12 | GANG LEADER | 0 | 255 |
| 96 | Living Ship | `0x82D4` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 96 | Living Ship | `0x8362` | `setup_monster` | 36 | HYPERCRAB | 0 | 255 |
| 96 | Living Ship | `0x841F` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 96 | Living Ship | `0x87DB` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 96 | Living Ship | `0x8826` | `setup_monster` | 44 | PIRATE LEADER | 2 | 255 |
| 96 | Living Ship | `0x8D1B` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 96 | Living Ship | `0x9B21` | `setup_monster` | 45 | PIR. COM. ROBOT | 1 | 255 |
| 97 | Living Ship | `0x83E6` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 97 | Living Ship | `0x847A` | `setup_monster` | 45 | PIR. COM. ROBOT | 0 | 255 |
| 97 | Living Ship | `0x84B4` | `setup_monster` | 45 | PIR. COM. ROBOT | 0 | 255 |
| 97 | Living Ship | `0x8BA7` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 97 | Living Ship | `0x8FAF` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 97 | Living Ship | `0x947F` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 97 | Living Ship | `0x983F` | `setup_monster` | 44 | PIRATE LEADER | 1 | 255 |
| 97 | Living Ship | `0x9AAD` | `setup_monster` | 45 | PIR. COM. ROBOT | 0 | 255 |
| 98 |  | `0x81A4` | `setup_monster` | 45 | PIR. COM. ROBOT | 0 | 255 |
| 98 |  | `0x87D0` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 98 |  | `0x8B5D` | `setup_monster` | 45 | PIR. COM. ROBOT | 0 | 255 |
| 98 |  | `0x9472` | `setup_monster` | 44 | PIRATE LEADER | 1 | 255 |
| 98 |  | `0x9AEE` | `setup_monster` | 44 | PIRATE LEADER | 0 | 255 |
| 112 | Stormrider University | `0x840D` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 112 | Stormrider University | `0x8443` | `setup_monster` | 19 | AMALTHEAN WARR | 2 | 255 |
| 112 | Stormrider University | `0x84A0` | `setup_monster` | 63 | JOVIAN DRAGON | 2 | 255 |
| 112 | Stormrider University | `0x8655` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 112 | Stormrider University | `0x8796` | `setup_monster` | 63 | JOVIAN DRAGON | 0 | 255 |
| 112 | Stormrider University | `0x88D9` | `setup_monster` | 63 | JOVIAN DRAGON | 0 | 255 |
| 112 | Stormrider University | `0x8ACE` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 112 | Stormrider University | `0x8DAF` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 112 | Stormrider University | `0x8E8B` | `setup_monster` | 19 | AMALTHEAN WARR | 1 | 255 |
| 112 | Stormrider University | `0x8FFF` | `setup_monster` | 19 | AMALTHEAN WARR | 1 | 255 |
| 112 | Stormrider University | `0x93E0` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 112 | Stormrider University | `0x957F` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x8A36` | `setup_monster` | 19 | AMALTHEAN WARR | area2.event_scratch0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x8A86` | `setup_monster` | 19 | AMALTHEAN WARR | 2 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x8B47` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x8BA6` | `setup_monster` | 49 | COMBAT ROBOT | 2 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x8FA0` | `setup_monster` | 51 | DEFENSE ROBOT | 0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x9395` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x94FD` | `setup_monster` | 51 | DEFENSE ROBOT | 2 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x98D4` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x9A5F` | `setup_monster` | 19 | AMALTHEAN WARR | 0 | 255 |
| 113 | Genetics Foundation Building, Levels 1-4 | `0x9D96` | `setup_monster` | 64 | WASPHOPPER | 2 | 255 |
| 114 | Jupiter Finale | `0x8373` | `setup_monster` | 49 | COMBAT ROBOT | 0 | 255 |
| 114 | Jupiter Finale | `0x85AF` | `setup_monster` | 40 | SAND SQUID | 1 | 255 |
| 114 | Jupiter Finale | `0x9E1B` | `setup_monster` | 33 | MER. WARRIOR | 2 | 255 |
| 114 | Jupiter Finale | `0x9F95` | `setup_monster` | 49 | COMBAT ROBOT | 2 | 255 |
| 114 | Jupiter Finale | `0xA025` | `setup_monster` | 33 | MER. WARRIOR | 0 | 255 |
| 114 | Jupiter Finale | `0xA087` | `setup_monster` | 52 | RAM WARRIOR | 1 | 255 |
| 114 | Jupiter Finale | `0xA0D6` | `setup_monster` | 50 | SECURITY ROBOT | 0 | 255 |
| 114 | Jupiter Finale | `0xA19C` | `load_monster` | 39 | LG. E.C. GENNIE |  | 39 |
| 114 | Jupiter Finale | `0xA1A4` | `load_monster` | 32 | STAGE 5 ECG |  | 32 |
| 114 | Jupiter Finale | `0xA341` | `setup_monster` | 51 | DEFENSE ROBOT | 0 | 255 |

## Finite Table Candidates

These rows still use variable operands at runtime, but the local ECL table bytes now constrain the possible monster records.

| ECL | Map | Address | Ref | Candidates | Table Evidence |
| ---: | --- | --- | --- | --- | --- |
| 21 | 21 | `0x83DE` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (4 + area2.event_scratch8; event_scratch8 source unresolved) |
| 21 | 21 | `0x863A` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (3 + area2.event_scratch8; event_scratch8 source unresolved) |
| 21 | 21 | `0x86EC` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (4 + area2.event_scratch8; event_scratch8 source unresolved) |
| 21 | 21 | `0x8785` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (1 + area2.event_scratch8; event_scratch8 source unresolved) |
| 21 | 21 | `0x881D` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (random 2..4 + area2.event_scratch8; event_scratch8 source unresolved) |
| 21 | 21 | `0x88E4` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (1 + area2.event_scratch8; event_scratch8 source unresolved) |
| 21 | 21 | `0x8A09` | `area2.event_scratch7` | RAM WARRIOR, SECURITY ROBOT, PIRATE LEADER, MER. WARRIOR | 0x8FCD values [0, 0, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 52, 50, 52, 52, 52, 44, 44, 44, 44, 44, 33, 50, 33, 50, 50] (random 2..5 + area2.event_scratch8; event_scratch8 source unresolved) |
| 33 | Losangelorg Sprawls | `0x8392` | `area2.event_scratch1` | STAGE 5 ECG | 0xA2EB values [32, 255, 255] (area2.event_scratch0 = random 1..3, or 1..2 when abs_C04E path runs) |
| 34 | Historical Museum, Levels 2-1 | `0x853F` | `area2.event_scratch1` | LG. E.C. GENNIE, RAM WARRIOR | 0xA2F0 values [39, 255, 52] (area1.event_word_21C = random 1..3) |
| 36 |  | `0x884D` | `area2.event_scratch1` | LG. E.C. GENNIE, RAM WARRIOR | 0x9E4A values [39, 255, 52] (area1.event_word_21E = random 1..3) |
| 37 |  | `0x82E6` | `area2.event_scratch1` | STAGE 5 ECG | 0xA3E6 values [32, 255, 255] (area2.event_scratch0 = random 1..3, or 1..2 when abs_C04E path runs) |

## Dynamic References

These operands are expressions or memory values. They need ECL data-flow resolution before they can be bound to `MON0CHA` records.

| ECL | Map | Address | Kind | Monster Ref | Pic Ref | Raw |
| ---: | --- | --- | --- | --- | --- | --- |
| 80 | Mars Prison, Level 1 | `0x863E` | `load_monster` | `area1.event_word_23A` | `area1.event_word_23A` | `0x863E 0x0B LOAD MONSTER monster_id: area1.event_word_23A copies: area2.event_scratch0 cpic_id: area1.event_word_23A` |
| 80 | Mars Prison, Level 1 | `0xA367` | `setup_monster` | `area1.event_word_214` | `area1.event_word_238` | `0xA367 0x0C SETUP MONSTER sprite_id: area1.event_word_214 max_distance: 0 pic_id: area1.event_word_238` |
