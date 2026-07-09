# GEO 35: Asteroid Base

ECL block: `35`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8543`
- Text hint: 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY ' '1' '2'

```text
event 01 {
  @0x8543: PRINTCLEAR 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY '
  @0x8566: COMPARE Values: 1 == area2.event_scratch0
  @0x856C: IF = <if compare flag is false, skip next op>
  @0x856D: PRINT '1'
  @0x8571: IF <> <if compare flag is false, skip next op>
  @0x8572: PRINT '2'
  @0x8576: PRINT ' AND CERES BASE.'
  @0x8585: EXIT
}
```

## Event 02

- Target: `0x8543`
- Text hint: 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY ' '1' '2'

```text
event 02 {
  @0x8543: PRINTCLEAR 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY '
  @0x8566: COMPARE Values: 1 == area2.event_scratch0
  @0x856C: IF = <if compare flag is false, skip next op>
  @0x856D: PRINT '1'
  @0x8571: IF <> <if compare flag is false, skip next op>
  @0x8572: PRINT '2'
  @0x8576: PRINT ' AND CERES BASE.'
  @0x8585: EXIT
}
```

## Event 03

- Target: `0x8586`
- Text hint: "THIS DOOR READS 'SECURITY STATION.'"

```text
event 03 {
  @0x8586: COMPARE Values: 2 == mapDirection
  @0x858C: IF <> <if compare flag is false, skip next op>
  @0x858D: PRINTCLEAR "THIS DOOR READS 'SECURITY STATION.'"
  @0x85AB: EXIT
}
```

## Event 04

- Target: `0x840C`
- Text hint: 'A HUGE EXPLOSION ROCKS THE BASE! THE DEMOLITION CHARGES HAVE DETONATED!'

```text
event 04 {
  @0x840C: EXIT
}
```

## Event 05

- Target: `0x85AC`
- Text hint: "GUARDS STOP YOU. 'THE COMMAND CENTER IS OFF LIMITS.'"

```text
event 05 {
  @0x85AC: COMPARE Values: 0 == mapDirection
  @0x85B2: IF <> <if compare flag is false, skip next op>
  @0x85B3: EXIT
}
```

## Event 06

- Target: `0x862A`
- Text hint: "'ARMORY.'"

```text
event 06 {
  @0x862A: EXIT
}
```

## Event 07

- Target: `0x862B`
- Text hint: "'ARMORY.'"

```text
event 07 {
  @0x862B: COMPARE Values: 3 == mapDirection
  @0x8631: IF = <if compare flag is false, skip next op>
  @0x8632: EXIT
}
```

## Event 08

- Target: `0x863E`
- Text hint: "A NAME PLATE ON THIS DOOR READS, 'GEN. MAVROUDIS, BASE COMMANDER.'"

```text
event 08 {
  @0x863E: COMPARE Values: 2 == mapDirection
  @0x8644: IF = <if compare flag is false, skip next op>
  @0x8645: EXIT
}
```

## Event 09

- Target: `0x867C`
- Text hint: "THIS DOOR IS MARKED 'LASER CONTROL.'"

```text
event 09 {
  @0x867C: COMPARE Values: 2 == mapDirection
  @0x8682: IF = <if compare flag is false, skip next op>
  @0x8683: EXIT
}
```

## Event 10

- Target: `0x86A3`
- Text hint: 'VARIOUS MAINTAINENCE ITEMS ARE STORED HERE.'

```text
event 10 {
  @0x86A3: PRINTCLEAR 'VARIOUS MAINTAINENCE ITEMS ARE STORED HERE.'
  @0x86C7: EXIT
}
```

## Event 11

- Target: `0x86C8`
- Text hint: "'GUARD QUARTERS.'"

```text
event 11 {
  @0x86C8: COMPARE Values: 0 == mapDirection
  @0x86CE: IF <> <if compare flag is false, skip next op>
  @0x86CF: EXIT
}
```

## Event 12

- Target: `0x86E1`
- Text hint: 'YOU ENTER THE COMMAND CENTER.'

```text
event 12 {
  @0x86E1: COMPARE Values: 0 == abs_C04E
  @0x86E7: IF <> <if compare flag is false, skip next op>
  @0x86E8: EXIT
}
```

## Event 13

- Target: `0x8917`
- Text hint: "A SIGN ON THE WEST DOOR READS, 'CONFERENCE ROOM.' STENCILED ON THE EAST DOOR IS 'MESS HALL.'"

```text
event 13 {
  @0x8917: COMPARE Values: 0 == abs_C04E
  @0x891D: IF <> <if compare flag is false, skip next op>
  @0x891E: EXIT
}
```

## Event 14

- Target: `0x8968`
- Text hint: 'THE MESS HALL IS ' 'EMPTY.'

```text
event 14 {
  @0x8968: COMPARE Values: 1 == mapDirection
  @0x896E: IF <> <if compare flag is false, skip next op>
  @0x896F: EXIT
}
```

## Event 15

- Target: `0x89E9`
- Text hint: 'THIS IS A ILL-EQUIPPED KITCHEN. PROCESSED FOOD SUPPLIES LINE THE WALLS.'

```text
event 15 {
  @0x89E9: COMPARE Values: 2 == mapDirection
  @0x89EF: IF <> <if compare flag is false, skip next op>
  @0x89F0: EXIT
}
```

## Event 16

- Target: `0x8A2B`
- Text hint: 'YOU ENTER THE SECURITY AREA' '.'

```text
event 16 {
  @0x8A2B: COMPARE Values: 0 == abs_C04E
  @0x8A31: IF <> <if compare flag is false, skip next op>
  @0x8A32: EXIT
}
```

## Event 17

- Target: `0x8C29`
- Text hint: 'THIS DOOR IS STENCILED ' "'WOMAN" "'MEN"

```text
event 17 {
  @0x8C29: PRINTCLEAR 'THIS DOOR IS STENCILED '
  @0x8C3E: COMPARE Values: 17 == area2.event_scratch0
  @0x8C44: IF <> <if compare flag is false, skip next op>
  @0x8C45: PRINT "'WOMAN"
  @0x8C4D: IF = <if compare flag is false, skip next op>
  @0x8C4E: PRINT "'MEN"
  @0x8C54: PRINT "'S LAVATORY.'"
  @0x8C61: EXIT
}
```

## Event 18

- Target: `0x8C29`
- Text hint: 'THIS DOOR IS STENCILED ' "'WOMAN" "'MEN"

```text
event 18 {
  @0x8C29: PRINTCLEAR 'THIS DOOR IS STENCILED '
  @0x8C3E: COMPARE Values: 17 == area2.event_scratch0
  @0x8C44: IF <> <if compare flag is false, skip next op>
  @0x8C45: PRINT "'WOMAN"
  @0x8C4D: IF = <if compare flag is false, skip next op>
  @0x8C4E: PRINT "'MEN"
  @0x8C54: PRINT "'S LAVATORY.'"
  @0x8C61: EXIT
}
```

## Event 19

- Target: `0x8C62`
- Text hint: "'CONFERENCE ROOM.'"

```text
event 19 {
  @0x8C62: COMPARE Values: 0 == abs_C04E
  @0x8C68: IF <> <if compare flag is false, skip next op>
  @0x8C69: EXIT
}
```

## Event 20

- Target: `0x8C7C`
- Text hint: 'THE ARMORY IS POORLY STOCKED. ONLY A FEW RIFLES ARE HERE.'

```text
event 20 {
  @0x8C7C: AND area2.event_scratch0 = area1.event_word_3AC & 16
  @0x8C85: IF <> <if compare flag is false, skip next op>
  @0x8C86: EXIT
}
```

## Event 21

- Target: `0x8D1B`
- Text hint: "THIS IS THE BASE'S POWER CENTER. HUGE CABLES SNAKE IN AND OUT OF THIS ROOM."

```text
event 21 {
  @0x8D1B: COMPARE Values: 0 == mapDirection
  @0x8D21: IF <> <if compare flag is false, skip next op>
  @0x8D22: EXIT
}
```

## Event 22

- Target: `0x8D60`
- Text hint: "'RESTRICTED ACCESS' IS PRINTED ON THE DOOR. YOU HEAR A STEADY HUM."

```text
event 22 {
  @0x8D60: COMPARE Values: 3 == mapDirection
  @0x8D66: IF <> <if compare flag is false, skip next op>
  @0x8D67: EXIT
}
```

## Event 23

- Target: `0x8D9E`
- Text hint: 'THE LARGE CONFERENCE ROOM IS EMPTY, BUT RECENTLY USED.'

```text
event 23 {
  @0x8D9E: COMPARE Values: 0 == abs_C04E
  @0x8DA4: IF <> <if compare flag is false, skip next op>
  @0x8DA5: EXIT
}
```

## Event 24

- Target: `0x8E52`
- Text hint: "MAVROUDIS' OFFICE IS IMMACULATE, AND SMELLS STRONGLY OF LEATHER. AGAINST THE EAST WALL IS A COMPUTER."

```text
event 24 {
  @0x8E52: COMPARE Values: 0 == mapDirection
  @0x8E58: IF <> <if compare flag is false, skip next op>
  @0x8E59: EXIT
}
```

## Event 25

- Target: `0x8EAA`
- Text hint: 'THE SECURITY PROGRAM HAS BEEN TRIPPED. THE COMPUTER HAS LOCKED ITS FILES, AND THE BASE ALERT HAS BEEN SOUNDED.'

```text
event 25 {
  @0x8EAA: AND area2.event_scratch0 = area1.event_word_3AE & 128
  @0x8EB3: IF <> <if compare flag is false, skip next op>
  @0x8EB4: EXIT
}
```

## Event 26

- Target: `0x9174`
- Text hint: "THE GENERAL'S LIVING QUARTERS ARE SPARSELY FURNISHED."

```text
event 26 {
  @0x9174: COMPARE Values: 1 == mapDirection
  @0x917A: IF <> <if compare flag is false, skip next op>
  @0x917B: EXIT
}
```

## Event 27

- Target: `0x91A8`
- Text hint: 'THE HUM OF MACHINERY FILLS THE ROOM. LARGE CONSOLES LINE THE WALLS.'

```text
event 27 {
  @0x91A8: PRINTCLEAR 'THE HUM OF MACHINERY FILLS THE ROOM. LARGE CONSOLES LINE THE WALLS.'
  @0x91DE: EXIT
}
```

## Event 28

- Target: `0x91DF`
- Text hint: 'THIS ROOM APPEARS TO BE A DEDICATED COMMUNICATIONS AREA.'

```text
event 28 {
  @0x91DF: COMPARE Values: 0 == abs_C04E
  @0x91E5: IF <> <if compare flag is false, skip next op>
  @0x91E6: EXIT
}
```

## Event 29

- Target: `0x9215`
- Text hint: '<string at area2.selected_player_name>' ' NOTICES A RAM HEAVY CRUISER ORBITING THE BASE.'

```text
event 29 {
  @0x9215: AND area2.event_scratch0 = area1.event_word_3B0 & 32
  @0x921E: IF <> <if compare flag is false, skip next op>
  @0x921F: GOTO 0x92B2
  // follows GOTO 0x92B2
    @0x92B2: PRINTCLEAR 'THE SENSORS NOW SHOW DEBRIS. THE RAM HEAVY CRUISER HAS BEEN DESTROYED.'
    @0x92EA: EXIT
}
```

## Event 30

- Target: `0x92EB`
- Text hint: 'THIS CONFERENCE ROOM IS DOMINATED BY RAM INSIGNIAS BOTH ON THE WALLS AND CARVED INTO THE TABLE.'

```text
event 30 {
  @0x92EB: COMPARE Values: 0 == mapDirection
  @0x92F1: IF <> <if compare flag is false, skip next op>
  @0x92F2: EXIT
}
```

## Event 31

- Target: `0x933F`
- Text hint: 'THIS ROOM HOLDS BRAND NEW EQUIPMENT. A MASTER CONTROL CONSOLE IS ON THE EAST WALL.'

```text
event 31 {
  @0x933F: COMPARE Values: 0 == mapDirection
  @0x9345: IF <> <if compare flag is false, skip next op>
  @0x9346: EXIT
}
```

## Event 32

- Target: `0x944F`
- Text hint: "THIS DOOR READS 'LASER PLATFORM. DO NOT ENTER.'"

```text
event 32 {
  @0x944F: COMPARE Values: 2 == mapDirection
  @0x9455: IF = <if compare flag is false, skip next op>
  @0x9456: EXIT
}
```

## Event 33

- Target: `0x947F`
- Text hint: 'THE SMOKING RUINS OF THE CONSOLE ARE ALL THAT REMAIN.'

```text
event 33 {
  @0x947F: AND area2.event_scratch0 = area1.event_word_3B0 & 64
  @0x9488: IF <> <if compare flag is false, skip next op>
  @0x9489: PRINTCLEAR 'THE SMOKING RUINS OF THE CONSOLE ARE ALL THAT REMAIN.'
  @0x94B4: IF <> <if compare flag is false, skip next op>
  @0x94B5: EXIT
}
```

## Event 34

- Target: `0x97C5`
- Text hint: 'A LASER OF UNBELIEVABLE SIZE TOWERS ABOVE YOU -- YET STILL A SMALLER VERSION OF THE DOOMSDAY LASER.'

```text
event 34 {
  @0x97C5: COMPARE Values: 0 == abs_C04E
  @0x97CB: IF <> <if compare flag is false, skip next op>
  @0x97CC: EXIT
}
```

## Event 35

- Target: `0x994F`
- Text hint: 'THE SECURITY MONITORS DISPLAY DIFFERENT SECTIONS OF THE BASE EACH MINUTE.' 'CURRENTLY, THE MONITOR IS DISPLAYING '

```text
event 35 {
  @0x994F: AND area2.event_scratch0 = area1.event_word_3AC & 32
  @0x9958: IF <> <if compare flag is false, skip next op>
  @0x9959: GOTO 0x9998
  // follows GOTO 0x9998
    @0x9998: ADD area1.event_word_214 = area1.event_word_214 + 1
    @0x99A1: PRINTCLEAR 'CURRENTLY, THE MONITOR IS DISPLAYING '
    @0x99C0: ON GOTO area1.event_word_214 of [0x99D8, 0x99D8, 0x99D8, 0x9A3A, 0x9A54, 0x9B51]
}
```

## Event 36

- Target: `0x9BFA`
- Text hint: 'THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.'

```text
event 36 {
  @0x9BFA: AND area2.event_scratch0 = area1.event_word_3AC & 64
  @0x9C03: IF <> <if compare flag is false, skip next op>
  @0x9C04: EXIT
}
```

## Event 37

- Target: `0x9D15`
- Text hint: "THE GENERAL'S BATHROOM. UNDER THE SINK YOU FIND A WAD OF PAPER CONTAINING SOME NUMBERS. THEY APPEAR TO BE AN ACCESS CODE."

```text
event 37 {
  @0x9D15: AND area2.event_scratch0 = area1.event_word_3B0 & 128
  @0x9D1E: IF <> <if compare flag is false, skip next op>
  @0x9D1F: EXIT
}
```
