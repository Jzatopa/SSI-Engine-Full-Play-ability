# GEO 66: RAM Battler, Deimos Level 19-41

ECL block: `66`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8283`
- Text hint: 'THIS LADDER LEADS DOWN TO THE COMPUTER LEVEL.' RETURN

```text
event 01 {
  @0x8283: COMPARE Values: area1.event_word_21E == 1
  @0x8289: IF = <if compare flag is false, skip next op>
  @0x828A: GOTO 0x84E5
  // follows GOTO 0x84E5
    @0x84E5: SAVE area1.event_word_220 = 1
    @0x84EB: PRINTCLEAR 'THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.'
    @0x852B: AND area2.event_scratch0 = 8 & area1.event_word_212
    @0x8534: IF <> <if compare flag is false, skip next op>
    @0x8535: PRINTCLEAR 'SPARKS RAIN FROM THIS SHORTED PANEL.'
    @0x8553: IF <> <if compare flag is false, skip next op>
    @0x8554: EXIT
}
```

## Event 02

- Target: `0x82EF`
- Text hint: "THE COMPUTER BLARES, 'PROBABILITY OF VESSEL DESTRUCTION IS 99%. ADVISE IMMEDIATE EVACUATION.'" "'AIR LOCK'" RETURN

```text
event 02 {
  @0x82EF: COMPARE Values: area1.event_word_21C == 4
  @0x82F5: IF = <if compare flag is false, skip next op>
  @0x82F6: GOTO 0x83C1
  // follows GOTO 0x83C1
    @0x83C1: PRINTCLEAR 'A FIREBALL ENGULFS YOU AS THE SHIP EXPLODES.'
    @0x83E6: EXIT
}
```

## Event 03

- Target: `0x83FB`
- Text hint: 'THIS LADDER LEADS UP TO THE CONTROL LEVEL.' RETURN

```text
event 03 {
  @0x83FB: AND area2.event_scratch0 = 4 & area1.event_word_212
  @0x8404: IF = <if compare flag is false, skip next op>
  @0x8405: PRINTCLEAR 'THIS LADDER LEADS UP TO THE CONTROL LEVEL.'
  @0x8428: IF = <if compare flag is false, skip next op>
  @0x8429: PRINT RETURN
}
```

## Event 04

- Target: `0x84E5`
- Text hint: 'THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.' 'SPARKS RAIN FROM THIS SHORTED PANEL.'

```text
event 04 {
  @0x84E5: SAVE area1.event_word_220 = 1
  @0x84EB: PRINTCLEAR 'THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.'
  @0x852B: AND area2.event_scratch0 = 8 & area1.event_word_212
  @0x8534: IF <> <if compare flag is false, skip next op>
  @0x8535: PRINTCLEAR 'SPARKS RAIN FROM THIS SHORTED PANEL.'
  @0x8553: IF <> <if compare flag is false, skip next op>
  @0x8554: EXIT
}
```

## Event 05

- Target: `0x852B`
- Text hint: 'SPARKS RAIN FROM THIS SHORTED PANEL.'

```text
event 05 {
  @0x852B: AND area2.event_scratch0 = 8 & area1.event_word_212
  @0x8534: IF <> <if compare flag is false, skip next op>
  @0x8535: PRINTCLEAR 'SPARKS RAIN FROM THIS SHORTED PANEL.'
  @0x8553: IF <> <if compare flag is false, skip next op>
  @0x8554: EXIT
}
```

## Event 06

- Target: `0x8A10`
- Text hint: "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES."

```text
event 06 {
  @0x8A10: PICTURE block_id: 30
  @0x8A13: PRINTCLEAR "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES."
  // truncated: next decoded instruction is 0x8EB0
}
```

## Event 07

- Target: `0x8EB0`
- Text hint: 'THERE IS A SHUFFLE ON THE OTHER SIDE OF THE PRISON DOOR. A VOICE WHISPERS, '

```text
event 07 {
  @0x8EB0: AND area2.event_scratch0 = 32 & area1.event_word_212
  @0x8EB9: IF <> <if compare flag is false, skip next op>
  @0x8EBA: EXIT
}
```

## Event 08

- Target: `0x909C`
- Text hint: 'THIS DOOR REQUIRES A RAM SECURITY PASSCARD. ' 'YOU DO NOT HAVE THE ONE IT REQUIRES.'

```text
event 08 {
  @0x909C: COMPARE Values: area1.event_word_230 == 1
  @0x90A2: IF = <if compare flag is false, skip next op>
  @0x90A3: EXIT
}
```

## Event 09

- Target: `0x90F5`
- Text hint: 'THIS AIRSHAFT LEADS DOWNWARD. DESCEND? '

```text
event 09 {
  @0x90F5: SAVE area1.event_word_230 = 0
  @0x90FB: SAVE area1.event_word_224 = 0
  @0x9101: SAVE area1.event_word_222 = 0
  @0x9107: COMPARE AND Values: 0 == mapPosX && 4 == mapPosY
  @0x9112: IF = <if compare flag is false, skip next op>
  @0x9113: SAVE area1.event_word_21A = 2
  @0x9119: COMPARE AND Values: 9 == mapPosX && 1 == mapPosY
  @0x9124: IF = <if compare flag is false, skip next op>
  @0x9125: SAVE area1.event_word_21A = 4
  @0x912B: COMPARE AND Values: 6 == mapPosX && 5 == mapPosY
  @0x9136: IF = <if compare flag is false, skip next op>
  @0x9137: SAVE area1.event_word_21A = 4
  @0x913D: COMPARE AND Values: 4 == mapPosX && 5 == mapPosY
  @0x9148: IF = <if compare flag is false, skip next op>
  @0x9149: SAVE area1.event_word_21A = 4
  @0x914F: COMPARE AND Values: 7 == mapPosX && 12 == mapPosY
  @0x915A: IF = <if compare flag is false, skip next op>
  @0x915B: SAVE area1.event_word_21A = 4
  @0x9161: COMPARE AND Values: 15 == mapPosX && 3 == mapPosY
  @0x916C: IF = <if compare flag is false, skip next op>
  @0x916D: SAVE area1.event_word_21A = 3
  @0x9173: COMPARE AND Values: 3 == mapPosX && 2 == mapPosY
  @0x917E: IF = <if compare flag is false, skip next op>
  @0x917F: SAVE area1.event_word_21A = 5
  @0x9185: COMPARE AND Values: 4 == mapPosX && 4 == mapPosY
  @0x9190: IF = <if compare flag is false, skip next op>
  @0x9191: SAVE area1.event_word_21A = 5
  @0x9197: EXIT
}
```

## Event 10

- Target: `0x9198`
- Text hint: 'THIS AIRSHAFT LEADS DOWNWARD. DESCEND? '

```text
event 10 {
  @0x9198: SAVE area1.event_word_21A = 1
  @0x919E: COMPARE Values: area1.event_word_224 == 1
  @0x91A4: IF = <if compare flag is false, skip next op>
  @0x91A5: EXIT
}
```

## Event 11

- Target: `0x91F1`
- Text hint: 'THIS SHAFT LEADS UPWARD. ASCEND? ' 'YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. '

```text
event 11 {
  @0x91F1: SAVE area1.event_word_21A = 1
  @0x91F7: COMPARE Values: area1.event_word_224 == 1
  @0x91FD: IF = <if compare flag is false, skip next op>
  @0x91FE: EXIT
}
```

## Event 12

- Target: `0x9291`
- Text hint: 'YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. '

```text
event 12 {
  @0x9291: PRINTCLEAR 'YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. '
  @0x92B9: HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'PRIMARY REC', 'REC II', 'GUEST QTRS', 'EXIT'
  @0x92E0: SAVE area2.event_scratch3 = 0
  @0x92E6: ON GOSUB area2.event_scratch0 of [0x9EE5, 0x9F02, 0x9F1F, 0x9F3C]
  // possible branch 0x92E6
    @0x92E6: ON GOSUB area2.event_scratch0 of [0x9EE5, 0x9F02, 0x9F1F, 0x9F3C]
    // possible branch 0x92E6
      // branch target 0x92E6 already shown
    // possible branch 0x9EE5
      @0x9EE5: COMPARE AND Values: 5 == mapPosX && 5 == mapPosY
      @0x9EF0: IF = <if compare flag is false, skip next op>
      @0x9EF1: GOTO 0x9F3C
      // follows GOTO 0x9F3C
        @0x9F3C: SAVE area2.event_scratch3 = 5
        @0x9F42: PRINTCLEAR ''
        @0x9F45: RETURN
    // possible branch 0x9F02
      @0x9F02: COMPARE AND Values: 8 == mapPosX && 12 == mapPosY
      @0x9F0D: IF = <if compare flag is false, skip next op>
      @0x9F0E: GOTO 0x9F3C
      // follows GOTO 0x9F3C
        // branch target 0x9F3C already shown
    // possible branch 0x9F1F
      @0x9F1F: COMPARE AND Values: 5 == mapPosX && 4 == mapPosY
      @0x9F2A: IF = <if compare flag is false, skip next op>
      @0x9F2B: GOTO 0x9F3C
      // follows GOTO 0x9F3C
        // branch target 0x9F3C already shown
    // possible branch 0x9F3C
      // branch target 0x9F3C already shown
  // possible branch 0x9EE5
    // branch target 0x9EE5 already shown
  // possible branch 0x9F02
    // branch target 0x9F02 already shown
  // possible branch 0x9F1F
    // branch target 0x9F1F already shown
  // possible branch 0x9F3C
    // branch target 0x9F3C already shown
}
```

## Event 13

- Target: `0x9336`
- Text hint: 'THIS ROOM IS EMPTY. IT LOOKS LIKE THE ' "WOMEN'S LOCKER ROOM."

```text
event 13 {
  @0x9336: AND area2.event_scratch0 = 1 & area1.event_word_214
  @0x933F: IF = <if compare flag is false, skip next op>
  @0x9340: PRINTCLEAR 'THIS ROOM IS EMPTY. IT LOOKS LIKE THE '
  @0x9360: PRINT "WOMEN'S LOCKER ROOM."
  @0x9372: OR area1.event_word_214 = 1 | area1.event_word_214
  @0x937B: EXIT
}
```

## Event 14

- Target: `0x937C`
- Text hint: 'TOWELS ARE LUMPED AROUND IN DAMP PILES. THIS IS THE ' "MEN'S LOCKER ROOM"

```text
event 14 {
  @0x937C: AND area2.event_scratch0 = 2 & area1.event_word_214
  @0x9385: IF = <if compare flag is false, skip next op>
  @0x9386: PRINTCLEAR 'TOWELS ARE LUMPED AROUND IN DAMP PILES. THIS IS THE '
  @0x93B0: PRINT "MEN'S LOCKER ROOM"
  @0x93CB: COMPARE Values: area1.event_word_222 == 1
  @0x93D1: IF = <if compare flag is false, skip next op>
  @0x93D2: EXIT
}
```

## Event 15

- Target: `0x93CB`
- Text hint: "A COMPUTERIZED VOICE SAYS, 'THIS ROOM IS OCCUPIED.'"

```text
event 15 {
  @0x93CB: COMPARE Values: area1.event_word_222 == 1
  @0x93D1: IF = <if compare flag is false, skip next op>
  @0x93D2: EXIT
}
```

## Event 16

- Target: `0x940B`
- Text hint: 'YOU INTERRUPT TWO CREW MEMBERS AND THEIR GAME OF ' "GET OUT OF HERE!'" 'YOU ARE SHOVED INTO THE HALLWAY.'

```text
event 16 {
  @0x940B: COMPARE Values: area1.event_word_22A == 4
  @0x9411: IF = <if compare flag is false, skip next op>
  @0x9412: GOTO 0x9494
  // follows GOTO 0x9494
    @0x9494: SETUP MONSTER sprite_id: 52 max_distance: 0 pic_id: 255
    @0x949B: EXIT
}
```

## Event 17

- Target: `0x94DF`
- Text hint: 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.'

```text
event 17 {
  @0x94DF: SETUP MONSTER sprite_id: 52 max_distance: 1 pic_id: 255
  @0x94E6: EXIT
}
```

## Event 18

- Target: `0x9602`
- Text hint: 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.'

```text
event 18 {
  @0x9602: PRINTCLEAR 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.'
  @0x964D: AND area2.event_scratch0 = 8 & area1.event_word_214
  @0x9656: IF <> <if compare flag is false, skip next op>
  @0x9657: EXIT
}
```

## Event 19

- Target: `0x964D`
- Text hint: 'THIS ROOM OBVIOUSLY BELONGS TO SOMEONE OF HIGH RANK. A MAN IS SLEEPING ON THE WIDE BED. BESIDE HIM IS A RAM SECURITY CARD.' ''

```text
event 19 {
  @0x964D: AND area2.event_scratch0 = 8 & area1.event_word_214
  @0x9656: IF <> <if compare flag is false, skip next op>
  @0x9657: EXIT
}
```

## Event 20

- Target: `0x979D`
- Text hint: 'THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?'

```text
event 20 {
  @0x979D: PRINTCLEAR 'THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?'
  @0x98B6: COMPARE Values: area1.event_word_276 == 1
  @0x98BC: IF = <if compare flag is false, skip next op>
  @0x98BD: GOTO 0x9A90
  // follows GOTO 0x9A90
    @0x9A90: SETUP MONSTER sprite_id: 50 max_distance: 1 pic_id: 255
    @0x9A97: EXIT
}
```

## Event 21

- Target: `0x98B6`
- Text hint: 'THIS DOOR REQUIRES A SECURITY CARD. USE THE CARD? '

```text
event 21 {
  @0x98B6: COMPARE Values: area1.event_word_276 == 1
  @0x98BC: IF = <if compare flag is false, skip next op>
  @0x98BD: GOTO 0x9A90
  // follows GOTO 0x9A90
    @0x9A90: SETUP MONSTER sprite_id: 50 max_distance: 1 pic_id: 255
    @0x9A97: EXIT
}
```

## Event 22

- Target: `0x9962`
- Text hint: "THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'"

```text
event 22 {
  @0x9962: AND area2.event_scratch0 = 32 & area1.event_word_214
  @0x996B: IF <> <if compare flag is false, skip next op>
  @0x996C: EXIT
}
```

## Event 23

- Target: `0x99C5`
- Text hint: "THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'"

```text
event 23 {
  @0x99C5: COMPARE Values: area1.event_word_276 == 1
  @0x99CB: IF = <if compare flag is false, skip next op>
  @0x99CC: EXIT
}
```
