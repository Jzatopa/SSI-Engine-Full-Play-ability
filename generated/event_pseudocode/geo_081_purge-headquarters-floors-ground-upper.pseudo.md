# GEO 81: PURGE Headquarters, Floors Ground-Upper

ECL block: `81`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8777`
- Text hint: 'AN ELEVATOR GOING UP. DO YOU USE IT?'

```text
event 01 {
  @0x8777: PRINTCLEAR 'AN ELEVATOR GOING UP. DO YOU USE IT?'
  @0x87D0: EXIT
}
```

## Event 02

- Target: `0x87D0`
- Text hint: 'JANITORIAL SUPPLIES ARE STORED IN THIS ROOM.'

```text
event 02 {
  @0x87D0: EXIT
}
```

## Event 03

- Target: `0x87E0`
- Text hint: 'JANITORIAL SUPPLIES ARE STORED IN THIS ROOM.'

```text
event 03 {
  @0x87E0: AND area2.event_scratch0 = 4 & area1.event_word_30E
  @0x87E9: IF <> <if compare flag is false, skip next op>
  @0x87EA: EXIT
}
```

## Event 04

- Target: `0x8819`
- Text hint: 'THE DOOR SLIDES SHUT BEHIND YOU.'

```text
event 04 {
  @0x8819: COMPARE Values: mapDirection == 0
  @0x881F: IF <> <if compare flag is false, skip next op>
  @0x8820: EXIT
}
```

## Event 05

- Target: `0x883D`
- Text hint: 'THE EMPLOYEE CAFETERIA. '

```text
event 05 {
  @0x883D: COMPARE Values: mapDirection == 2
  @0x8843: IF <> <if compare flag is false, skip next op>
  @0x8844: EXIT
}
```

## Event 06

- Target: `0x8849`
- Text hint: 'THE EMPLOYEE CAFETERIA. '

```text
event 06 {
  @0x8849: COMPARE Values: mapDirection == 3
  @0x884F: IF <> <if compare flag is false, skip next op>
  @0x8850: EXIT
}
```

## Event 07

- Target: `0x890A`
- Text hint: 'YOU OVERHEAR TWO PURGE MEMBERS,'

```text
event 07 {
  @0x890A: COMPARE Values: area1.event_word_31E == 1
  @0x8910: IF = <if compare flag is false, skip next op>
  @0x8911: EXIT
}
```

## Event 08

- Target: `0x8979`
- Text hint: 'THIS AREA IS PARTITIONED INTO WORK CUBICLES. CLERKS RUSH AROUND, OBLIVIOUS TO YOUR PRESENCE.'

```text
event 08 {
  @0x8979: COMPARE Values: area1.event_word_31E == 1
  @0x897F: IF = <if compare flag is false, skip next op>
  @0x8980: EXIT
}
```

## Event 09

- Target: `0x89D3`
- Text hint: '' "'WOMEN'S ROOM.'"

```text
event 09 {
  @0x89D3: COMPARE Values: area1.event_word_31E == 1
  @0x89D9: IF = <if compare flag is false, skip next op>
  @0x89DA: EXIT
}
```

## Event 10

- Target: `0x89E7`
- Text hint: '' "'WOMEN'S ROOM.'"

```text
event 10 {
  @0x89E7: PRINTCLEAR ''
  @0x89EA: GOSUB 0x8A02
  @0x89EE: GOSUB 0x8A13
  @0x89F2: PRINT "'WOMEN'S ROOM.'"
  @0x8A01: EXIT
}
```

## Event 11

- Target: `0x8A21`
- Text hint: '' ' SOUTHERN' "'MEN'S ROOM,' AND "

```text
event 11 {
  @0x8A21: COMPARE Values: area1.event_word_202 == 1
  @0x8A27: IF = <if compare flag is false, skip next op>
  @0x8A28: EXIT
}
```

## Event 12

- Target: `0x8A7A`
- Text hint: "A UNIFORMED MAN SITS AT HIS COMPUTER. HE SPEAKS TO YOU OVER HIS BACK. 'I'M SORRY, COMMANDER SOOTH IS NOT IN RIGHT NOW...' HE TURNS AROUND."

```text
event 12 {
  @0x8A7A: SAVE area1.event_word_202 = 0
  @0x8A80: EXIT
}
```

## Event 13

- Target: `0x8A81`
- Text hint: "A UNIFORMED MAN SITS AT HIS COMPUTER. HE SPEAKS TO YOU OVER HIS BACK. 'I'M SORRY, COMMANDER SOOTH IS NOT IN RIGHT NOW...' HE TURNS AROUND."

```text
event 13 {
  @0x8A81: COMPARE Values: area1.event_word_31E == 1
  @0x8A87: IF = <if compare flag is false, skip next op>
  @0x8A88: EXIT
}
```

## Event 14

- Target: `0x8B56`
- Text hint: "YOU ENTER HANIBL SOOTH'S OFFICE. THE ONLY FURNITURE IS THE DESK ACROSS THE ROOM."

```text
event 14 {
  @0x8B56: COMPARE Values: mapDirection == 3
  @0x8B5C: IF <> <if compare flag is false, skip next op>
  @0x8B5D: EXIT
}
```

## Event 15

- Target: `0x8B9F`
- Text hint: 'YOU FIND A LETTER'

```text
event 15 {
  @0x8B9F: AND area2.event_scratch0 = 32 & area1.event_word_30E
  @0x8BA8: IF <> <if compare flag is false, skip next op>
  @0x8BA9: GOTO 0x8BCD
  // follows GOTO 0x8BCD
    @0x8BCD: PRINTCLEAR 'OVER THE DESK IS A MONITOR.'
    @0x8BE5: COMPARE Values: area1.event_word_31E == 1
    @0x8BEB: IF = <if compare flag is false, skip next op>
    @0x8BEC: PRINT ' ITS SCREEN IS BLANK.'
    @0x8BFF: IF = <if compare flag is false, skip next op>
    @0x8C01: IF = <if compare flag is false, skip next op>
    @0x8C02: EXIT
}
```

## Event 16

- Target: `0x8D28`
- Text hint: 'IN THIS CONFERENCE ROOM, A MEETING IS IN PROGRESS. PURGE MEMBERS SIT AROUND A TABLE. '

```text
event 16 {
  @0x8D28: COMPARE Values: area1.event_word_31E == 1
  @0x8D2E: IF = <if compare flag is false, skip next op>
  @0x8D2F: EXIT
}
```

## Event 17

- Target: `0x8EEB`
- Text hint: 'A PRINTING PRESS IS HERE' '.'

```text
event 17 {
  @0x8EEB: COMPARE Values: mapDirection == 0
  @0x8EF1: IF <> <if compare flag is false, skip next op>
  @0x8EF2: EXIT
}
```

## Event 18

- Target: `0x8F53`
- Text hint: 'BOXES OF BUTTONS AND STICKERS ARE STORED HERE.'

```text
event 18 {
  @0x8F53: COMPARE Values: mapDirection == 3
  @0x8F59: IF <> <if compare flag is false, skip next op>
  @0x8F5A: EXIT
}
```

## Event 19

- Target: `0x8F82`
- Text hint: 'A COMBAT TRAINING ROOM WITH A PADDED FLOOR. IT IS EMPTY.'

```text
event 19 {
  @0x8F82: COMPARE Values: mapDirection == 0
  @0x8F88: IF <> <if compare flag is false, skip next op>
  @0x8F89: EXIT
}
```

## Event 20

- Target: `0x8FB8`
- Text hint: ''

```text
event 20 {
  @0x8FB8: COMPARE Values: area1.event_word_31E == 1
  @0x8FBE: IF = <if compare flag is false, skip next op>
  @0x8FBF: EXIT
}
```

## Event 21

- Target: `0x913A`
- Text hint: '' ' SOUTHERN' "'HOLDING CELLS'"

```text
event 21 {
  @0x913A: COMPARE Values: mapDirection == 0
  @0x9140: IF = <if compare flag is false, skip next op>
  @0x9141: EXIT
}
```

## Event 22

- Target: `0x9167`
- Text hint: 'THIS CELL IS EMPTY.'

```text
event 22 {
  @0x9167: PRINTCLEAR 'THIS CELL IS EMPTY.'
  @0x9179: EXIT
}
```

## Event 23

- Target: `0x917A`
- Text hint: 'YOU ENTER A ROOM FULL OF COMPUTER AND COMMUNICATIONS EQUIPMENT. PURGE MEMBERS RUSH ABOUT, WHILE OTHERS SIT AT CONTROL CONSOLES.'

```text
event 23 {
  @0x917A: AND area2.event_scratch0 = 16 & area1.event_word_314
  @0x9183: IF <> <if compare flag is false, skip next op>
  @0x9184: EXIT
}
```

## Event 24

- Target: `0x955B`
- Text hint: "AN EMACIATED MAN IN A TATTERED LAB COAT APPROACHES. IT'S DR. ROMNEY!" 'DR. ROMNEY MEETS YOU IN THE HALL.'

```text
event 24 {
  @0x955B: COMPARE Values: area1.event_word_31E == 1
  @0x9561: IF <> <if compare flag is false, skip next op>
  @0x9562: EXIT
}
```

## Event 25

- Target: `0x96A5`
- Text hint: 'A PURGE FUNCTIONARY' 'AN OFFICE WORKER' ' PASSES YOU BY.'

```text
event 25 {
  @0x96A5: COMPARE Values: area1.event_word_312 == 1
  @0x96AB: IF = <if compare flag is false, skip next op>
  @0x96AC: GOTO 0x86F4
  // follows GOTO 0x86F4
    @0x86F4: COMPARE Values: area1.event_word_312 == 1
    @0x86FA: IF <> <if compare flag is false, skip next op>
    @0x86FB: EXIT
}
```
