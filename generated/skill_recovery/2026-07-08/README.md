# Matrix Cubed Skill Recovery - 2026-07-08

Evidence boundary: skill names are extracted from START.EXE Pascal strings; skill value offsets are derived from GAME.OVR decompiled accessors that use `character + 0x4C + skill_id`; sample values come from local 259-byte `.WHO`/`.SAV` files.

## Skill Ids

| Skill ID | WHO Offset | START.EXE Offset | Name |
|---:|---:|---:|---|
| 1 / 0x01 | 0x4D | 0x0F336 | Repair Electrical |
| 2 / 0x02 | 0x4E | 0x0F351 | Repair Mechanical |
| 3 / 0x03 | 0x4F | 0x0F36C | Repair Nuclear Engine |
| 4 / 0x04 | 0x50 | 0x0F387 | Repair Life Support |
| 5 / 0x05 | 0x51 | 0x0F3A2 | Repair Rocket Hull |
| 6 / 0x06 | 0x52 | 0x0F3BD | Jury Rig |
| 7 / 0x07 | 0x53 | 0x0F3CF | Bypass Security |
| 8 / 0x08 | 0x54 | 0x0F3E8 | Open Lock |
| 9 / 0x09 | 0x55 | 0x0F3FB | Commo Operation |
| 10 / 0x0A | 0x56 | 0x0F414 | Sensor Operation |
| 11 / 0x0B | 0x57 | 0x0F42E | Demolitions |
| 12 / 0x0C | 0x58 | 0x0F443 | Cook |
| 13 / 0x0D | 0x59 | 0x0F450 | First Aid |
| 14 / 0x0E | 0x5A | 0x0F463 | Repair Weapon |
| 15 / 0x0F | 0x5B | 0x0F47A | Repair Computer |
| 16 / 0x10 | 0x5C | 0x0F492 | Life Suspension Tech |
| 17 / 0x11 | 0x5D | 0x0F4AD | Treat Light Wounds |
| 18 / 0x12 | 0x5E | 0x0F4C8 | Treat Serious Wounds |
| 19 / 0x13 | 0x5F | 0x0F4E3 | Treat Critical Wounds |
| 20 / 0x14 | 0x60 | 0x0F4FE | Treat Poisoning |
| 21 / 0x15 | 0x61 | 0x0F517 | Treat Stun/Paralysis |
| 22 / 0x16 | 0x62 | 0x0F532 | Treat Disease |
| 23 / 0x17 | 0x63 | 0x0F549 | Diagnose |
| 24 / 0x18 | 0x64 | 0x0F55B | General Knowledge |
| 25 / 0x19 | 0x65 | 0x0F575 | Ship Lore |
| 26 / 0x1A | 0x66 | 0x0F587 | Composition |
| 27 / 0x1B | 0x67 | 0x0F59B | Mathematics |
| 28 / 0x1C | 0x68 | 0x0F5B0 | Physics |
| 29 / 0x1D | 0x69 | 0x0F5C0 | Geology |
| 30 / 0x1E | 0x6A | 0x0F5D0 | Planetology |
| 31 / 0x1F | 0x6B | 0x0F5E5 | Battle Tactics |
| 32 / 0x20 | 0x6C | 0x0F5FD | Chemistry |
| 33 / 0x21 | 0x6D | 0x0F60F | Biology |
| 34 / 0x22 | 0x6E | 0x0F61F | Design Engineering |
| 35 / 0x23 | 0x6F | 0x0F63A | History |
| 36 / 0x24 | 0x70 | 0x0F64A | Astronomy |
| 37 / 0x25 | 0x71 | 0x0F65D | Botany |
| 38 / 0x26 | 0x72 | 0x0F66C | Literature |
| 39 / 0x27 | 0x73 | 0x0F67F | Economics |
| 40 / 0x28 | 0x74 | 0x0F691 | Metallurgy |
| 41 / 0x29 | 0x75 | 0x0F6A4 | Speak/Read Lang. |
| 42 / 0x2A | 0x76 | 0x0F6BD | Law |
| 43 / 0x2B | 0x77 | 0x0F6C9 | Programming |
| 44 / 0x2C | 0x78 | 0x0F6DE | Crytography |
| 45 / 0x2D | 0x79 | 0x0F6F2 | Library Search |
| 46 / 0x2E | 0x7A | 0x0F70A | Astrogation |
| 47 / 0x2F | 0x7B | 0x0F71F | Navigation |
| 48 / 0x30 | 0x7C | 0x0F733 | Mimic |
| 49 / 0x31 | 0x7D | 0x0F741 | Memorize |
| 50 / 0x32 | 0x7E | 0x0F752 | Disguise |
| 51 / 0x33 | 0x7F | 0x0F764 | Pilot Rocket |
| 52 / 0x34 | 0x80 | 0x0F77A | Pilot Fixed Wing |
| 53 / 0x35 | 0x81 | 0x0F794 | Drive Ground Car |
| 54 / 0x36 | 0x82 | 0x0F7AE | Pilot Rotor Wing |
| 55 / 0x37 | 0x83 | 0x0F7C8 | Drive Motorcycle |
| 56 / 0x38 | 0x84 | 0x0F7E1 | Use Jetpack |
| 57 / 0x39 | 0x85 | 0x0F7F6 | Pilot Ship/Sub |
| 58 / 0x3A | 0x86 | 0x0F80D | Drive Hvy Grnd Vehc |
| 59 / 0x3B | 0x87 | 0x0F828 | Drive Jetcar |
| 60 / 0x3C | 0x88 | 0x0F83E | Animal Riding |
| 61 / 0x3D | 0x89 | 0x0F854 | Hide in Shadows |
| 62 / 0x3E | 0x8A | 0x0F86D | Move Silently |
| 63 / 0x3F | 0x8B | 0x0F884 | Pick Pockets |
| 64 / 0x40 | 0x8C | 0x0F89A | Acrobatics |
| 65 / 0x41 | 0x8D | 0x0F8AE | Climb |
| 66 / 0x42 | 0x8E | 0x0F8BD | Swimming |
| 67 / 0x43 | 0x8F | 0x0F8CE | Maneuver in 0G |
| 68 / 0x44 | 0x90 | 0x0F8E6 | Play Instrumnt |
| 69 / 0x45 | 0x91 | 0x0F8FD | Paint/Draw |
| 70 / 0x46 | 0x92 | 0x0F910 | Hypnosis |
| 71 / 0x47 | 0x93 | 0x0F921 | Act |
| 72 / 0x48 | 0x94 | 0x0F92E | Intimidate |
| 73 / 0x49 | 0x95 | 0x0F942 | Leadership |
| 74 / 0x4A | 0x96 | 0x0F956 | Befriend Animal |
| 75 / 0x4B | 0x97 | 0x0F96F | Animal Training |
| 76 / 0x4C | 0x98 | 0x0F987 | Fast Talk/Convince |
| 77 / 0x4D | 0x99 | 0x0F9A2 | Singing |
| 78 / 0x4E | 0x9A | 0x0F9B3 | Distract |
| 79 / 0x4F | 0x9B | 0x0F9C5 | Etiquette |
| 80 / 0x50 | 0x9C | 0x0F9D8 | Tracking |
| 81 / 0x51 | 0x9D | 0x0F9EA | Shadowing |
| 82 / 0x52 | 0x9E | 0x0F9FD | Read Lips |
| 83 / 0x53 | 0x9F | 0x0FA0F | Notice |
| 84 / 0x54 | 0xA0 | 0x0FA1F | Planetary Survival |

## Non-Zero Sample Values

| Sample | Career ID | Skill | Value |
|---|---:|---|---:|
| CHRDATA1 (CAR1) | 2 | Treat Light Wounds | 50 |
| CHRDATA1 (CAR1) | 2 | Treat Serious Wounds | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Critical Wounds | 75 |
| CHRDATA1 (CAR1) | 2 | Treat Poisoning | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Stun/Paralysis | 60 |
| CHRDATA1 (CAR1) | 2 | Diagnose | 15 |
| CHRDATA1 (CAR1) | 2 | Battle Tactics | 5 |
| CHRDATA1 (CAR1) | 2 | Maneuver in 0G | 80 |
| CHRDATA1 (CAR1) | 2 | Befriend Animal | 55 |
| GEN1 (GEN1) | 1 | First Aid | 25 |
| GEN1 (GEN1) | 1 | Mathematics | 25 |
| GEN1 (GEN1) | 1 | Astronomy | 20 |
| GEN1 (GEN1) | 1 | Astrogation | 70 |
| GEN1 (GEN1) | 1 | Pilot Rocket | 85 |
| GEN1 (GEN1) | 1 | Pilot Fixed Wing | 10 |
| GEN1 (GEN1) | 1 | Drive Ground Car | 40 |
| GEN1 (GEN1) | 1 | Pilot Rotor Wing | 10 |
| GEN1 (GEN1) | 1 | Drive Motorcycle | 10 |
| GEN1 (GEN1) | 1 | Use Jetpack | 50 |
| GEN1 (GEN1) | 1 | Pilot Ship/Sub | 10 |
| GEN1 (GEN1) | 1 | Drive Hvy Grnd Vehc | 10 |
| GEN1 (GEN1) | 1 | Drive Jetcar | 10 |
| GEN1 (GEN1) | 1 | Maneuver in 0G | 85 |
| GEN1 (GEN1) | 1 | Notice | 40 |
| RAC1 (RAC1) | 1 | First Aid | 25 |
| RAC1 (RAC1) | 1 | Mathematics | 25 |
| RAC1 (RAC1) | 1 | Astronomy | 20 |
| RAC1 (RAC1) | 1 | Astrogation | 70 |
| RAC1 (RAC1) | 1 | Pilot Rocket | 85 |
| RAC1 (RAC1) | 1 | Pilot Fixed Wing | 10 |
| RAC1 (RAC1) | 1 | Drive Ground Car | 40 |
| RAC1 (RAC1) | 1 | Pilot Rotor Wing | 10 |
| RAC1 (RAC1) | 1 | Drive Motorcycle | 10 |
| RAC1 (RAC1) | 1 | Use Jetpack | 50 |
| RAC1 (RAC1) | 1 | Pilot Ship/Sub | 10 |
| RAC1 (RAC1) | 1 | Drive Hvy Grnd Vehc | 10 |
| RAC1 (RAC1) | 1 | Drive Jetcar | 10 |
| RAC1 (RAC1) | 1 | Maneuver in 0G | 85 |
| RAC1 (RAC1) | 1 | Notice | 40 |
| TST1 (TST1) | 1 | First Aid | 25 |
| TST1 (TST1) | 1 | Mathematics | 25 |
| TST1 (TST1) | 1 | Astronomy | 20 |
| TST1 (TST1) | 1 | Astrogation | 70 |
| TST1 (TST1) | 1 | Pilot Rocket | 85 |
| TST1 (TST1) | 1 | Pilot Fixed Wing | 10 |
| TST1 (TST1) | 1 | Drive Ground Car | 40 |
| TST1 (TST1) | 1 | Pilot Rotor Wing | 10 |
| TST1 (TST1) | 1 | Drive Motorcycle | 10 |
| TST1 (TST1) | 1 | Use Jetpack | 50 |
| TST1 (TST1) | 1 | Pilot Ship/Sub | 10 |
| TST1 (TST1) | 1 | Drive Hvy Grnd Vehc | 10 |
| TST1 (TST1) | 1 | Drive Jetcar | 10 |
| TST1 (TST1) | 1 | Maneuver in 0G | 85 |
| TST1 (TST1) | 1 | Notice | 40 |
| TST2 (TST2) | 1 | First Aid | 25 |
| TST2 (TST2) | 1 | Mathematics | 25 |
| TST2 (TST2) | 1 | Astronomy | 20 |
| TST2 (TST2) | 1 | Astrogation | 70 |
| TST2 (TST2) | 1 | Pilot Rocket | 85 |
| TST2 (TST2) | 1 | Pilot Fixed Wing | 10 |
| TST2 (TST2) | 1 | Drive Ground Car | 40 |
| TST2 (TST2) | 1 | Pilot Rotor Wing | 10 |
| TST2 (TST2) | 1 | Drive Motorcycle | 10 |
| TST2 (TST2) | 1 | Use Jetpack | 50 |
| TST2 (TST2) | 1 | Pilot Ship/Sub | 10 |
| TST2 (TST2) | 1 | Drive Hvy Grnd Vehc | 10 |
| TST2 (TST2) | 1 | Drive Jetcar | 10 |
| TST2 (TST2) | 1 | Maneuver in 0G | 85 |
| TST2 (TST2) | 1 | Notice | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Light Wounds | 50 |
| CHRDATA1 (CAR1) | 2 | Treat Serious Wounds | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Critical Wounds | 75 |
| CHRDATA1 (CAR1) | 2 | Treat Poisoning | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Stun/Paralysis | 60 |
| CHRDATA1 (CAR1) | 2 | Diagnose | 15 |
| CHRDATA1 (CAR1) | 2 | Battle Tactics | 5 |
| CHRDATA1 (CAR1) | 2 | Maneuver in 0G | 80 |
| CHRDATA1 (CAR1) | 2 | Befriend Animal | 55 |
| GEN1 (GEN1) | 1 | First Aid | 25 |
| GEN1 (GEN1) | 1 | Mathematics | 25 |
| GEN1 (GEN1) | 1 | Astronomy | 20 |
| GEN1 (GEN1) | 1 | Astrogation | 70 |
| GEN1 (GEN1) | 1 | Pilot Rocket | 85 |
| GEN1 (GEN1) | 1 | Pilot Fixed Wing | 10 |
| GEN1 (GEN1) | 1 | Drive Ground Car | 40 |
| GEN1 (GEN1) | 1 | Pilot Rotor Wing | 10 |
| GEN1 (GEN1) | 1 | Drive Motorcycle | 10 |
| GEN1 (GEN1) | 1 | Use Jetpack | 50 |
| GEN1 (GEN1) | 1 | Pilot Ship/Sub | 10 |
| GEN1 (GEN1) | 1 | Drive Hvy Grnd Vehc | 10 |
| GEN1 (GEN1) | 1 | Drive Jetcar | 10 |
| GEN1 (GEN1) | 1 | Maneuver in 0G | 85 |
| GEN1 (GEN1) | 1 | Notice | 40 |
| RAC1 (RAC1) | 1 | First Aid | 25 |
| RAC1 (RAC1) | 1 | Mathematics | 25 |
| RAC1 (RAC1) | 1 | Astronomy | 20 |
| RAC1 (RAC1) | 1 | Astrogation | 70 |
| RAC1 (RAC1) | 1 | Pilot Rocket | 85 |
| RAC1 (RAC1) | 1 | Pilot Fixed Wing | 10 |
| RAC1 (RAC1) | 1 | Drive Ground Car | 40 |
| RAC1 (RAC1) | 1 | Pilot Rotor Wing | 10 |
| RAC1 (RAC1) | 1 | Drive Motorcycle | 10 |
| RAC1 (RAC1) | 1 | Use Jetpack | 50 |
| RAC1 (RAC1) | 1 | Pilot Ship/Sub | 10 |
| RAC1 (RAC1) | 1 | Drive Hvy Grnd Vehc | 10 |
| RAC1 (RAC1) | 1 | Drive Jetcar | 10 |
| RAC1 (RAC1) | 1 | Maneuver in 0G | 85 |
| RAC1 (RAC1) | 1 | Notice | 40 |
| TST1 (TST1) | 1 | First Aid | 25 |
| TST1 (TST1) | 1 | Mathematics | 25 |
| TST1 (TST1) | 1 | Astronomy | 20 |
| TST1 (TST1) | 1 | Astrogation | 70 |
| TST1 (TST1) | 1 | Pilot Rocket | 85 |
| TST1 (TST1) | 1 | Pilot Fixed Wing | 10 |
| TST1 (TST1) | 1 | Drive Ground Car | 40 |
| TST1 (TST1) | 1 | Pilot Rotor Wing | 10 |
| TST1 (TST1) | 1 | Drive Motorcycle | 10 |
| TST1 (TST1) | 1 | Use Jetpack | 50 |
| TST1 (TST1) | 1 | Pilot Ship/Sub | 10 |
| TST1 (TST1) | 1 | Drive Hvy Grnd Vehc | 10 |
| TST1 (TST1) | 1 | Drive Jetcar | 10 |
| TST1 (TST1) | 1 | Maneuver in 0G | 85 |
| TST1 (TST1) | 1 | Notice | 40 |
| TST2 (TST2) | 1 | First Aid | 25 |
| TST2 (TST2) | 1 | Mathematics | 25 |
| TST2 (TST2) | 1 | Astronomy | 20 |
| TST2 (TST2) | 1 | Astrogation | 70 |
| TST2 (TST2) | 1 | Pilot Rocket | 85 |
| TST2 (TST2) | 1 | Pilot Fixed Wing | 10 |
| TST2 (TST2) | 1 | Drive Ground Car | 40 |
| TST2 (TST2) | 1 | Pilot Rotor Wing | 10 |
| TST2 (TST2) | 1 | Drive Motorcycle | 10 |
| TST2 (TST2) | 1 | Use Jetpack | 50 |
| TST2 (TST2) | 1 | Pilot Ship/Sub | 10 |
| TST2 (TST2) | 1 | Drive Hvy Grnd Vehc | 10 |
| TST2 (TST2) | 1 | Drive Jetcar | 10 |
| TST2 (TST2) | 1 | Maneuver in 0G | 85 |
| TST2 (TST2) | 1 | Notice | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Light Wounds | 50 |
| CHRDATA1 (CAR1) | 2 | Treat Serious Wounds | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Critical Wounds | 75 |
| CHRDATA1 (CAR1) | 2 | Treat Poisoning | 40 |
| CHRDATA1 (CAR1) | 2 | Treat Stun/Paralysis | 60 |
| CHRDATA1 (CAR1) | 2 | Diagnose | 15 |
| CHRDATA1 (CAR1) | 2 | Battle Tactics | 5 |
| CHRDATA1 (CAR1) | 2 | Maneuver in 0G | 80 |
| CHRDATA1 (CAR1) | 2 | Befriend Animal | 55 |
| GEN1 (GEN1) | 1 | First Aid | 25 |
| GEN1 (GEN1) | 1 | Mathematics | 25 |
| GEN1 (GEN1) | 1 | Astronomy | 20 |
| GEN1 (GEN1) | 1 | Astrogation | 70 |
| GEN1 (GEN1) | 1 | Pilot Rocket | 85 |
| GEN1 (GEN1) | 1 | Pilot Fixed Wing | 10 |
| GEN1 (GEN1) | 1 | Drive Ground Car | 40 |
| GEN1 (GEN1) | 1 | Pilot Rotor Wing | 10 |
| GEN1 (GEN1) | 1 | Drive Motorcycle | 10 |
| GEN1 (GEN1) | 1 | Use Jetpack | 50 |
| GEN1 (GEN1) | 1 | Pilot Ship/Sub | 10 |
| GEN1 (GEN1) | 1 | Drive Hvy Grnd Vehc | 10 |
| GEN1 (GEN1) | 1 | Drive Jetcar | 10 |
| GEN1 (GEN1) | 1 | Maneuver in 0G | 85 |
| GEN1 (GEN1) | 1 | Notice | 40 |
| RAC1 (RAC1) | 1 | First Aid | 25 |
| RAC1 (RAC1) | 1 | Mathematics | 25 |
| RAC1 (RAC1) | 1 | Astronomy | 20 |
| RAC1 (RAC1) | 1 | Astrogation | 70 |
| RAC1 (RAC1) | 1 | Pilot Rocket | 85 |
| RAC1 (RAC1) | 1 | Pilot Fixed Wing | 10 |
| RAC1 (RAC1) | 1 | Drive Ground Car | 40 |
| RAC1 (RAC1) | 1 | Pilot Rotor Wing | 10 |
| RAC1 (RAC1) | 1 | Drive Motorcycle | 10 |
| RAC1 (RAC1) | 1 | Use Jetpack | 50 |
| RAC1 (RAC1) | 1 | Pilot Ship/Sub | 10 |
| RAC1 (RAC1) | 1 | Drive Hvy Grnd Vehc | 10 |
| RAC1 (RAC1) | 1 | Drive Jetcar | 10 |
| RAC1 (RAC1) | 1 | Maneuver in 0G | 85 |
| RAC1 (RAC1) | 1 | Notice | 40 |
| TST1 (TST1) | 1 | First Aid | 25 |
| TST1 (TST1) | 1 | Mathematics | 25 |
| TST1 (TST1) | 1 | Astronomy | 20 |
| TST1 (TST1) | 1 | Astrogation | 70 |
| TST1 (TST1) | 1 | Pilot Rocket | 85 |
| TST1 (TST1) | 1 | Pilot Fixed Wing | 10 |
| TST1 (TST1) | 1 | Drive Ground Car | 40 |
| TST1 (TST1) | 1 | Pilot Rotor Wing | 10 |
| TST1 (TST1) | 1 | Drive Motorcycle | 10 |
| TST1 (TST1) | 1 | Use Jetpack | 50 |
| TST1 (TST1) | 1 | Pilot Ship/Sub | 10 |
| TST1 (TST1) | 1 | Drive Hvy Grnd Vehc | 10 |
| TST1 (TST1) | 1 | Drive Jetcar | 10 |
| TST1 (TST1) | 1 | Maneuver in 0G | 85 |
| TST1 (TST1) | 1 | Notice | 40 |
| TST2 (TST2) | 1 | First Aid | 25 |
| TST2 (TST2) | 1 | Mathematics | 25 |
| TST2 (TST2) | 1 | Astronomy | 20 |
| TST2 (TST2) | 1 | Astrogation | 70 |
| TST2 (TST2) | 1 | Pilot Rocket | 85 |
| TST2 (TST2) | 1 | Pilot Fixed Wing | 10 |
| TST2 (TST2) | 1 | Drive Ground Car | 40 |
| TST2 (TST2) | 1 | Pilot Rotor Wing | 10 |
| TST2 (TST2) | 1 | Drive Motorcycle | 10 |
| TST2 (TST2) | 1 | Use Jetpack | 50 |
| TST2 (TST2) | 1 | Pilot Ship/Sub | 10 |
| TST2 (TST2) | 1 | Drive Hvy Grnd Vehc | 10 |
| TST2 (TST2) | 1 | Drive Jetcar | 10 |
| TST2 (TST2) | 1 | Maneuver in 0G | 85 |
| TST2 (TST2) | 1 | Notice | 40 |
| CHRDATA1 (ONE) | 1 | First Aid | 25 |
| CHRDATA1 (ONE) | 1 | Mathematics | 25 |
| CHRDATA1 (ONE) | 1 | Astronomy | 20 |
| CHRDATA1 (ONE) | 1 | Astrogation | 70 |
| CHRDATA1 (ONE) | 1 | Pilot Rocket | 85 |
| CHRDATA1 (ONE) | 1 | Pilot Fixed Wing | 10 |
| CHRDATA1 (ONE) | 1 | Drive Ground Car | 40 |
| CHRDATA1 (ONE) | 1 | Pilot Rotor Wing | 10 |
| CHRDATA1 (ONE) | 1 | Drive Motorcycle | 10 |
| CHRDATA1 (ONE) | 1 | Use Jetpack | 50 |
| CHRDATA1 (ONE) | 1 | Pilot Ship/Sub | 10 |
| CHRDATA1 (ONE) | 1 | Drive Hvy Grnd Vehc | 10 |
| CHRDATA1 (ONE) | 1 | Drive Jetcar | 10 |
| CHRDATA1 (ONE) | 1 | Maneuver in 0G | 85 |
| CHRDATA1 (ONE) | 1 | Notice | 40 |
| CHRDATA2 (THREE) | 2 | Treat Light Wounds | 50 |
| CHRDATA2 (THREE) | 2 | Treat Serious Wounds | 40 |
| CHRDATA2 (THREE) | 2 | Treat Critical Wounds | 75 |
| CHRDATA2 (THREE) | 2 | Treat Poisoning | 40 |
| CHRDATA2 (THREE) | 2 | Treat Stun/Paralysis | 60 |
| CHRDATA2 (THREE) | 2 | Diagnose | 15 |
| CHRDATA2 (THREE) | 2 | Battle Tactics | 5 |
| CHRDATA2 (THREE) | 2 | Maneuver in 0G | 80 |
| CHRDATA2 (THREE) | 2 | Befriend Animal | 55 |
| CHRDATA3 (TWO) | 3 | Repair Electrical | 10 |
| CHRDATA3 (TWO) | 3 | Repair Mechanical | 10 |
| CHRDATA3 (TWO) | 3 | Jury Rig | 50 |
| CHRDATA3 (TWO) | 3 | Demolitions | 25 |
| CHRDATA3 (TWO) | 3 | First Aid | 70 |
| CHRDATA3 (TWO) | 3 | Repair Weapon | 10 |
| CHRDATA3 (TWO) | 3 | Battle Tactics | 50 |
| CHRDATA3 (TWO) | 3 | Use Jetpack | 20 |
| CHRDATA3 (TWO) | 3 | Move Silently | 20 |
| CHRDATA3 (TWO) | 3 | Maneuver in 0G | 85 |
| CHRDATA3 (TWO) | 3 | Leadership | 50 |
| CHRDATA3 (TWO) | 3 | Notice | 20 |
| CHRDATA4 (FIVE) | 2 | Treat Light Wounds | 50 |
| CHRDATA4 (FIVE) | 2 | Treat Serious Wounds | 40 |
| CHRDATA4 (FIVE) | 2 | Treat Critical Wounds | 75 |
| CHRDATA4 (FIVE) | 2 | Treat Poisoning | 40 |
| CHRDATA4 (FIVE) | 2 | Treat Stun/Paralysis | 60 |
| CHRDATA4 (FIVE) | 2 | Diagnose | 15 |
| CHRDATA4 (FIVE) | 2 | Battle Tactics | 5 |
| CHRDATA4 (FIVE) | 2 | Maneuver in 0G | 80 |
| CHRDATA4 (FIVE) | 2 | Befriend Animal | 55 |
| CHRDATA5 (FOUR) | 5 | Bypass Security | 60 |
| CHRDATA5 (FOUR) | 5 | Open Lock | 60 |
| CHRDATA5 (FOUR) | 5 | First Aid | 10 |
| CHRDATA5 (FOUR) | 5 | Mathematics | 10 |
| CHRDATA5 (FOUR) | 5 | Programming | 50 |
| CHRDATA5 (FOUR) | 5 | Hide in Shadows | 40 |
| CHRDATA5 (FOUR) | 5 | Move Silently | 50 |
| CHRDATA5 (FOUR) | 5 | Pick Pockets | 40 |
| CHRDATA5 (FOUR) | 5 | Climb | 30 |
| CHRDATA5 (FOUR) | 5 | Maneuver in 0G | 70 |
| CHRDATA5 (FOUR) | 5 | Fast Talk/Convince | 40 |
| CHRDATA5 (FOUR) | 5 | Read Lips | 10 |
| CHRDATA5 (FOUR) | 5 | Notice | 40 |
