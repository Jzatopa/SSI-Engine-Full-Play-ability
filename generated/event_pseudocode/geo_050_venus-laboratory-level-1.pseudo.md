# GEO 50: Venus Laboratory, Level 1

ECL block: `50`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x830F`
- Text hint: 'AN ELEVATOR GOING DOWN. DO YOU USE IT?' 'YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?'

```text
event 01 {
  @0x830F: COMPARE Values: mapDirection == 1
  @0x8315: IF <> <if compare flag is false, skip next op>
  @0x8316: EXIT
}
```

## Event 02

- Target: `0x83A3`
- Text hint: 'YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?'

```text
event 02 {
  @0x83A3: PRINTCLEAR 'YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?'
  @0x8409: COMPARE Values: mapDirection == 1
  @0x840F: IF <> <if compare flag is false, skip next op>
  @0x8410: EXIT
}
```

## Event 04

- Target: `0x844F`
- Text hint: 'ENTERING THE LAB COMPLEX, YOU FIND THE SOURCE OF THE EARTHQUAKE. AN EXPLOSION LARGE ENOUGH TO BLOW AWAY THE ROOF HAS EXPOSED THE VENUSIAN SKY.'

```text
event 04 {
  @0x844F: AND area2.event_scratch0 = 1 & area1.event_word_2FE
  @0x8458: IF <> <if compare flag is false, skip next op>
  @0x8459: EXIT
}
```

## Event 05

- Target: `0x84D6`
- Text hint: 'THE BODIES OF ' ' SOLDIERS LIE HERE. THEY APPEAR TO HAVE BEEN CRUSHED BY ENORMOUS WEIGHTS.'

```text
event 05 {
  @0x84D6: COMPARE Values: mapDirection == 1
  @0x84DC: IF <> <if compare flag is false, skip next op>
  @0x84DD: EXIT
}
```

## Event 06

- Target: `0x852C`
- Text hint: 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'

```text
event 06 {
  @0x852C: COMPARE Values: mapDirection == 0
  @0x8532: IF <> <if compare flag is false, skip next op>
  @0x8533: EXIT
}
```

## Event 07

- Target: `0x8538`
- Text hint: 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'

```text
event 07 {
  @0x8538: COMPARE Values: mapDirection == 2
  @0x853E: IF <> <if compare flag is false, skip next op>
  @0x853F: EXIT
}
```

## Event 08

- Target: `0x8544`
- Text hint: 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'

```text
event 08 {
  @0x8544: COMPARE Values: mapDirection == 1
  @0x854A: IF <> <if compare flag is false, skip next op>
  @0x854B: EXIT
}
```

## Event 09

- Target: `0x8587`
- Text hint: "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"

```text
event 09 {
  @0x8587: COMPARE Values: mapDirection == 2
  @0x858D: IF <> <if compare flag is false, skip next op>
  @0x858E: EXIT
}
```

## Event 10

- Target: `0x8593`
- Text hint: "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"

```text
event 10 {
  @0x8593: COMPARE Values: area1.event_word_300 == 1
  @0x8599: IF = <if compare flag is false, skip next op>
  @0x859A: EXIT
}
```

## Event 11

- Target: `0x8696`
- Text hint: "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"

```text
event 11 {
  @0x8696: COMPARE Values: mapDirection == 0
  @0x869C: IF <> <if compare flag is false, skip next op>
  @0x869D: EXIT
}
```

## Event 12

- Target: `0x86D0`
- Text hint: 'YOU STEP INTO THE GRAVITY FIELD!'

```text
event 12 {
  @0x86D0: COMPARE Values: area1.event_word_300 == 1
  @0x86D6: IF = <if compare flag is false, skip next op>
  @0x86D7: EXIT
}
```

## Event 13

- Target: `0x8740`
- Text hint: 'THE CONTROLS TO THE GRAVITY FIELD ARE HERE. DO YOU TURN IT OFF?'

```text
event 13 {
  @0x8740: AND area2.event_scratch0 = 4 & area1.event_word_2FE
  @0x8749: IF <> <if compare flag is false, skip next op>
  @0x874A: EXIT
}
```

## Event 14

- Target: `0x87C3`
- Text hint: 'THE CONTROLS TO THE GRAVITY FIELD ARE HERE. DO YOU TURN IT OFF?'

```text
event 14 {
  @0x87C3: COMPARE Values: area1.event_word_300 == 1
  @0x87C9: IF = <if compare flag is false, skip next op>
  @0x87CA: EXIT
}
```

## Event 15

- Target: `0x882A`
- Text hint: "LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'" 'THE BODY OF A ' ' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.'

```text
event 15 {
  @0x882A: COMPARE Values: area1.event_word_300 == 1
  @0x8830: IF <> <if compare flag is false, skip next op>
  @0x8831: EXIT
}
```

## Event 16

- Target: `0x88F3`
- Text hint: 'THE BODY OF A ' ' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.'

```text
event 16 {
  @0x88F3: PRINTCLEAR 'THE BODY OF A '
  @0x8901: GOSUB 0xA3A8
  @0x8905: PRINT ' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.'
  @0x8932: AND area2.event_scratch0 = 8 & area1.event_word_2FE
  @0x893B: IF <> <if compare flag is false, skip next op>
  @0x893C: EXIT
}
```

## Event 17

- Target: `0x8932`
- Text hint: 'YOU HEAR SOUNDS TO THE WEST. LEANDER SPEAKS.'

```text
event 17 {
  @0x8932: AND area2.event_scratch0 = 8 & area1.event_word_2FE
  @0x893B: IF <> <if compare flag is false, skip next op>
  @0x893C: EXIT
}
```

## Event 18

- Target: `0x899B`
- Text hint: 'THIS LAB HAS BEEN RANSACKED.'

```text
event 18 {
  @0x899B: COMPARE Values: area1.event_word_2FC == 1
  @0x89A1: IF = <if compare flag is false, skip next op>
  @0x89A2: EXIT
}
```

## Event 19

- Target: `0x8BA6`
- Text hint: 'THIS LAB HAS BEEN RANSACKED.'

```text
event 19 {
  @0x8BA6: COMPARE Values: mapDirection == 2
  @0x8BAC: IF <> <if compare flag is false, skip next op>
  @0x8BAD: EXIT
}
```

## Event 20

- Target: `0x8BC7`
- Text hint: 'YOU HEAR A COMMOTION FROM THE SOUTH.' " LEANDER SAYS, 'WE SSTORE OUR DATA ARCHIVESS IN THERE.'"

```text
event 20 {
  @0x8BC7: COMPARE Values: mapDirection == 3
  @0x8BCD: IF <> <if compare flag is false, skip next op>
  @0x8BCE: EXIT
}
```

## Event 21

- Target: `0x8BD3`
- Text hint: 'YOU HEAR A COMMOTION FROM THE SOUTH.' " LEANDER SAYS, 'WE SSTORE OUR DATA ARCHIVESS IN THERE.'"

```text
event 21 {
  @0x8BD3: AND area2.event_scratch0 = 32 & area1.event_word_2FE
  @0x8BDC: IF <> <if compare flag is false, skip next op>
  @0x8BDD: EXIT
}
```

## Event 22

- Target: `0x8C39`
- Text hint: 'YOU ENTER A DATA ARCHIVE. '

```text
event 22 {
  @0x8C39: AND area2.event_scratch0 = 128 & area1.event_word_306
  @0x8C42: IF <> <if compare flag is false, skip next op>
  @0x8C43: EXIT
}
```

## Event 23

- Target: `0x8D8D`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 23 {
  @0x8D8D: COMPARE Values: area1.event_word_2FC == 1
  @0x8D93: IF = <if compare flag is false, skip next op>
  @0x8D94: GOTO 0x8E1B
  // follows GOTO 0x8E1B
    @0x8E1B: COMPARE Values: area1.event_word_2FC == 1
    @0x8E21: IF <> <if compare flag is false, skip next op>
    @0x8E22: EXIT
}
```

## Event 24

- Target: `0x8E1B`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 24 {
  @0x8E1B: COMPARE Values: area1.event_word_2FC == 1
  @0x8E21: IF <> <if compare flag is false, skip next op>
  @0x8E22: EXIT
}
```
