# GEO 112: Stormrider University

ECL block: `112`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8620`
- Text hint: 'THE LANDING PAD. '

```text
event 01 {
  @0x8620: COMPARE Values: mapDirection == 3
  @0x8626: IF <> <if compare flag is false, skip next op>
  @0x8627: EXIT
}
```

## Event 02

- Target: `0x8765`
- Text hint: 'MAKALI IS HARD AT WORK. SHE IGNORES YOU.'

```text
event 02 {
  @0x8765: COMPARE Values: mapDirection == 3
  @0x876B: IF <> <if compare flag is false, skip next op>
  @0x876C: EXIT
}
```

## Event 03

- Target: `0x8944`
- Text hint: 'AS YOU EXIT THE LABS, AN EXPLOSION ROCKS THE UNIVERSITY!'

```text
event 03 {
  @0x8944: AND area2.event_scratch0 = 2 & area1.event_word_370
  @0x894D: IF = <if compare flag is false, skip next op>
  @0x894E: EXIT
}
```

## Event 04

- Target: `0x8A5D`
- Text hint: 'YOU ENTER A LAB. '

```text
event 04 {
  @0x8A5D: COMPARE Values: mapDirection == 0
  @0x8A63: IF <> <if compare flag is false, skip next op>
  @0x8A64: EXIT
}
```

## Event 05

- Target: `0x8A69`
- Text hint: 'YOU ENTER A LAB. '

```text
event 05 {
  @0x8A69: COMPARE Values: mapDirection == 2
  @0x8A6F: IF <> <if compare flag is false, skip next op>
  @0x8A70: EXIT
}
```

## Event 09

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 09 {
  @0x8B65: SUBTRACT area2.event_scratch0 = area2.event_scratch0 - 9
  @0x8B6E: COMPARE Values: mapDirection == area2.event_scratch0
  @0x8B75: IF <> <if compare flag is false, skip next op>
  @0x8B76: EXIT
}
```

## Event 10

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 10 {
  @0x8B65: SUBTRACT area2.event_scratch0 = area2.event_scratch0 - 9
  @0x8B6E: COMPARE Values: mapDirection == area2.event_scratch0
  @0x8B75: IF <> <if compare flag is false, skip next op>
  @0x8B76: EXIT
}
```

## Event 11

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 11 {
  @0x8B65: SUBTRACT area2.event_scratch0 = area2.event_scratch0 - 9
  @0x8B6E: COMPARE Values: mapDirection == area2.event_scratch0
  @0x8B75: IF <> <if compare flag is false, skip next op>
  @0x8B76: EXIT
}
```

## Event 12

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 12 {
  @0x8B65: SUBTRACT area2.event_scratch0 = area2.event_scratch0 - 9
  @0x8B6E: COMPARE Values: mapDirection == area2.event_scratch0
  @0x8B75: IF <> <if compare flag is false, skip next op>
  @0x8B76: EXIT
}
```

## Event 13

- Target: `0x8CD4`
- Text hint: 'YOU ENTER AN ELEVATOR. '

```text
event 13 {
  @0x8CD4: PRINTCLEAR 'YOU ENTER AN ELEVATOR. '
  @0x8CE9: COMPARE Values: area1.event_word_372 == 0
  @0x8CEF: IF <> <if compare flag is false, skip next op>
  @0x8CF0: GOTO 0x8D7B
  // follows GOTO 0x8D7B
    @0x8D7B: PRINT 'THE CONTROLS ARE SMASHED.'
    @0x8D93: COMPARE Values: area1.event_word_372 == 1
    @0x8D99: IF <> <if compare flag is false, skip next op>
    @0x8D9A: EXIT
}
```

## Event 14

- Target: `0x8D93`
- Text hint: 'YOU ENTER THE CLASSROOM COMPLEX. '

```text
event 14 {
  @0x8D93: COMPARE Values: area1.event_word_372 == 1
  @0x8D99: IF <> <if compare flag is false, skip next op>
  @0x8D9A: EXIT
}
```

## Event 15

- Target: `0x8E4B`
- Text hint: 'YOU ENTER THE CLASSROOM COMPLEX. '

```text
event 15 {
  @0x8E4B: COMPARE Values: mapDirection == 1
  @0x8E51: IF <> <if compare flag is false, skip next op>
  @0x8E52: EXIT
}
```

## Event 16

- Target: `0x8F5C`
- Text hint: 'THE STUDENTS HERE HAVE BEEN MASSACRED. NOT ONE REMAINS ALIVE.' 'GRIM STUDENTS ARE REMOVING DEAD CLASSMATES FROM THIS ROOM.'

```text
event 16 {
  @0x8F5C: COMPARE Values: mapDirection == 0
  @0x8F62: IF <> <if compare flag is false, skip next op>
  @0x8F63: EXIT
}
```

## Event 17

- Target: `0x8FDA`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.'

```text
event 17 {
  @0x8FDA: COMPARE Values: mapDirection == 0
  @0x8FE0: IF <> <if compare flag is false, skip next op>
  @0x8FE1: EXIT
}
```

## Event 18

- Target: `0x938C`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.' 'THIS CLASSROOM IS EMPTY.'

```text
event 18 {
  @0x938C: COMPARE Values: mapDirection == 1
  @0x9392: IF <> <if compare flag is false, skip next op>
  @0x9393: EXIT
}
```

## Event 19

- Target: `0x93A7`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.' 'THIS CLASSROOM IS EMPTY.'

```text
event 19 {
  @0x93A7: COMPARE Values: mapDirection == 2
  @0x93AD: IF <> <if compare flag is false, skip next op>
  @0x93AE: EXIT
}
```

## Event 20

- Target: `0x9422`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.' 'THIS CLASSROOM IS EMPTY.'

```text
event 20 {
  @0x9422: COMPARE Values: mapDirection == 2
  @0x9428: IF <> <if compare flag is false, skip next op>
  @0x9429: EXIT
}
```

## Event 21

- Target: `0x9471`
- Text hint: ' IS IN SESSION. THE PROFESSOR MOTIONS YOU OUT OF THE ROOM.' 'A PHYSICS LECTURE'

```text
event 21 {
  @0x9471: AND area2.event_scratch0 = 64 & area1.event_word_370
  @0x947A: IF = <if compare flag is false, skip next op>
  @0x947B: EXIT
}
```

## Event 22

- Target: `0x955D`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 22 {
  @0x955D: COMPARE Values: area1.event_word_372 == 1
  @0x9563: IF <> <if compare flag is false, skip next op>
  @0x9564: EXIT
}
```

## Event 23

- Target: `0x9817`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 23 {
  @0x9817: COMPARE Values: area1.event_word_206 == 1
  @0x981D: IF <> <if compare flag is false, skip next op>
  @0x981E: EXIT
}
```

## Event 24

- Target: `0x9862`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 24 {
  @0x9862: COMPARE Values: area1.event_word_206 == 1
  @0x9868: IF <> <if compare flag is false, skip next op>
  @0x9869: GOTO 0x829D
  // follows GOTO 0x829D
    @0x829D: COMPARE Values: area1.event_word_372 == 2
    @0x82A3: IF = <if compare flag is false, skip next op>
    @0x82A4: EXIT
}
```

## Event 25

- Target: `0x988D`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 25 {
  @0x988D: COMPARE Values: mapDirection == 0
  @0x9893: IF <> <if compare flag is false, skip next op>
  @0x9894: EXIT
}
```

## Event 26

- Target: `0x98D0`
- Text hint: 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?'

```text
event 26 {
  @0x98D0: COMPARE Values: area1.event_word_206 == 1
  @0x98D6: IF <> <if compare flag is false, skip next op>
  @0x98D7: EXIT
}
```

## Event 27

- Target: `0x992F`
- Text hint: 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?'

```text
event 27 {
  @0x992F: COMPARE Values: area1.event_word_206 == 1
  @0x9935: IF <> <if compare flag is false, skip next op>
  @0x9936: EXIT
}
```

## Event 28

- Target: `0x821E`
- Text hint: 'A GROUP OF STUDENTS RUSH BY TALKING ABOUT '

```text
event 28 {
  @0x821E: EXIT
}
```

## Event 29

- Target: `0x9B35`
- Text hint: 'YOU ENTER THE SCHOOL LIBRARY. STUDENTS MOVE ABOUT, MAKING USE OF THE IMPRESSIVE COLLECTION OF BOOKS.' 'YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.' 'YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.'

```text
event 29 {
  @0x9B35: COMPARE Values: mapDirection == 2
  @0x9B3B: IF <> <if compare flag is false, skip next op>
  @0x9B3C: EXIT
}
```

## Event 30

- Target: `0x9C61`
- Text hint: 'THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.'

```text
event 30 {
  @0x9C61: COMPARE Values: area1.event_word_372 == 1
  @0x9C67: IF <> <if compare flag is false, skip next op>
  @0x9C68: EXIT
}
```

## Event 31

- Target: `0x9CB6`
- Text hint: 'YOU ENTER THE MAIN SECTION OF THE LIBRARY'

```text
event 31 {
  @0x9CB6: COMPARE Values: mapDirection == 2
  @0x9CBC: IF <> <if compare flag is false, skip next op>
  @0x9CBD: EXIT
}
```

## Event 32

- Target: `0x9E8C`
- Text hint: 'YOU ENTER THE LIBRARY ANNEX'

```text
event 32 {
  @0x9E8C: COMPARE Values: mapDirection == 3
  @0x9E92: IF <> <if compare flag is false, skip next op>
  @0x9E93: EXIT
}
```

## Event 33

- Target: `0xA099`
- Text hint: 'YOU ENTER THE OFFICE OF CONTINUING EDUCATION.'

```text
event 33 {
  @0xA099: COMPARE AND Values: 1 == area1.event_word_372 && 0 == mapDirection
  @0xA0A4: IF <> <if compare flag is false, skip next op>
  @0xA0A5: EXIT
}
```

## Event 34

- Target: `0x821E`
- Text hint: 'A GROUP OF STUDENTS RUSH BY TALKING ABOUT '

```text
event 34 {
  @0x821E: EXIT
}
```

## Event 35

- Target: `0xA0C1`
- Text hint: 'YOU ENTER THE OFFICE OF CONTINUING EDUCATION.'

```text
event 35 {
  @0xA0C1: COMPARE Values: mapDirection == 0
  @0xA0C7: IF <> <if compare flag is false, skip next op>
  @0xA0C8: EXIT
}
```

## Event 36

- Target: `0xA119`
- Text hint: 'YOU ENTER A STORE.'

```text
event 36 {
  @0xA119: COMPARE Values: area1.event_word_372 == 1
  @0xA11F: IF = <if compare flag is false, skip next op>
  @0xA120: EXIT
}
```
