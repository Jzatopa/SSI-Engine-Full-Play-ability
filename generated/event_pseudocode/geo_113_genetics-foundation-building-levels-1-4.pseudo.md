# GEO 113: Genetics Foundation Building, Levels 1-4

ECL block: `113`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8C12`
- Text hint: 'THIS ELEVATOR HAS BEEN DEACTIVATED.'

```text
event 01 {
  @0x8C12: PRINTCLEAR 'THIS ELEVATOR HAS BEEN DEACTIVATED.'
  @0x8C30: EXIT
}
```

## Event 02

- Target: `0x8C31`
- Text hint: 'YOU CLIMB DOWN.' 'YOU CLIMB UP.' 'AN ELEVATOR. DO YOU USE IT?'

```text
event 02 {
  @0x8C31: SAVE area2.event_scratch0 = 1
  @0x8C37: GOSUB 0xA0E4
  @0x8C3C: IF <> <if compare flag is false, skip next op>
  @0x8C3E: PRINTCLEAR 'YOU CLIMB DOWN.'
  @0x8C58: SAVE area2.event_scratch0 = 0
  @0x8C5E: GOSUB 0xA0E4
  @0x8C63: IF <> <if compare flag is false, skip next op>
  @0x8C65: PRINTCLEAR 'YOU CLIMB UP.'
  @0x8C81: PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?'
  @0x8D2D: SAVE area2.event_scratch0 = 1
  @0x8D33: GOSUB 0xA0E4
  @0x8D38: IF <> <if compare flag is false, skip next op>
  @0x8D3A: SAVE mapPosX = 0
  @0x8D40: SAVE mapPosY = 8
  @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
  @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
  @0x8D53: IF <> <if compare flag is false, skip next op>
  @0x8D54: GOTO 0x8DCF
  // follows GOTO 0x8DCF
    @0x8DCF: AND area2.event_scratch0 = 8 & area1.event_word_386
    @0x8DD8: IF <> <if compare flag is false, skip next op>
    @0x8DD9: PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.'
    @0x8E00: IF <> <if compare flag is false, skip next op>
    @0x8E01: GOTO 0x8DAD
    // follows GOTO 0x8DAD
      @0x8DAE: SAVE area2.event_scratch0 = 0
      @0x8DB4: GOSUB 0xA0E4
      @0x8DB9: IF <> <if compare flag is false, skip next op>
      @0x8DBB: SAVE mapPosX = 8
      @0x8DC1: SAVE mapPosY = 0
      @0x8DC7: CALL raw: 0x2DCB, id: 0xADCC
      @0x8DCB: GOTO 0x8D2D
      // follows GOTO 0x8D2D
        @0x8D2D: SAVE area2.event_scratch0 = 1
        @0x8D33: GOSUB 0xA0E4
        @0x8D38: IF <> <if compare flag is false, skip next op>
        @0x8D3A: SAVE mapPosX = 0
        @0x8D40: SAVE mapPosY = 8
        @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
        @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
        @0x8D53: IF <> <if compare flag is false, skip next op>
        @0x8D54: GOTO 0x8DCF
}
```

## Event 03

- Target: `0x8C58`
- Text hint: 'YOU CLIMB UP.' 'AN ELEVATOR. DO YOU USE IT?'

```text
event 03 {
  @0x8C58: SAVE area2.event_scratch0 = 0
  @0x8C5E: GOSUB 0xA0E4
  @0x8C63: IF <> <if compare flag is false, skip next op>
  @0x8C65: PRINTCLEAR 'YOU CLIMB UP.'
  @0x8C81: PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?'
  @0x8D2D: SAVE area2.event_scratch0 = 1
  @0x8D33: GOSUB 0xA0E4
  @0x8D38: IF <> <if compare flag is false, skip next op>
  @0x8D3A: SAVE mapPosX = 0
  @0x8D40: SAVE mapPosY = 8
  @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
  @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
  @0x8D53: IF <> <if compare flag is false, skip next op>
  @0x8D54: GOTO 0x8DCF
  // follows GOTO 0x8DCF
    @0x8DCF: AND area2.event_scratch0 = 8 & area1.event_word_386
    @0x8DD8: IF <> <if compare flag is false, skip next op>
    @0x8DD9: PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.'
    @0x8E00: IF <> <if compare flag is false, skip next op>
    @0x8E01: GOTO 0x8DAD
    // follows GOTO 0x8DAD
      @0x8DAE: SAVE area2.event_scratch0 = 0
      @0x8DB4: GOSUB 0xA0E4
      @0x8DB9: IF <> <if compare flag is false, skip next op>
      @0x8DBB: SAVE mapPosX = 8
      @0x8DC1: SAVE mapPosY = 0
      @0x8DC7: CALL raw: 0x2DCB, id: 0xADCC
      @0x8DCB: GOTO 0x8D2D
      // follows GOTO 0x8D2D
        @0x8D2D: SAVE area2.event_scratch0 = 1
        @0x8D33: GOSUB 0xA0E4
        @0x8D38: IF <> <if compare flag is false, skip next op>
        @0x8D3A: SAVE mapPosX = 0
        @0x8D40: SAVE mapPosY = 8
        @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
        @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
        @0x8D53: IF <> <if compare flag is false, skip next op>
        @0x8D54: GOTO 0x8DCF
}
```

## Event 04

- Target: `0x8C81`
- Text hint: 'AN ELEVATOR. DO YOU USE IT?'

```text
event 04 {
  @0x8C81: PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?'
  @0x8D2D: SAVE area2.event_scratch0 = 1
  @0x8D33: GOSUB 0xA0E4
  @0x8D38: IF <> <if compare flag is false, skip next op>
  @0x8D3A: SAVE mapPosX = 0
  @0x8D40: SAVE mapPosY = 8
  @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
  @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
  @0x8D53: IF <> <if compare flag is false, skip next op>
  @0x8D54: GOTO 0x8DCF
  // follows GOTO 0x8DCF
    @0x8DCF: AND area2.event_scratch0 = 8 & area1.event_word_386
    @0x8DD8: IF <> <if compare flag is false, skip next op>
    @0x8DD9: PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.'
    @0x8E00: IF <> <if compare flag is false, skip next op>
    @0x8E01: GOTO 0x8DAD
    // follows GOTO 0x8DAD
      @0x8DAE: SAVE area2.event_scratch0 = 0
      @0x8DB4: GOSUB 0xA0E4
      @0x8DB9: IF <> <if compare flag is false, skip next op>
      @0x8DBB: SAVE mapPosX = 8
      @0x8DC1: SAVE mapPosY = 0
      @0x8DC7: CALL raw: 0x2DCB, id: 0xADCC
      @0x8DCB: GOTO 0x8D2D
      // follows GOTO 0x8D2D
        @0x8D2D: SAVE area2.event_scratch0 = 1
        @0x8D33: GOSUB 0xA0E4
        @0x8D38: IF <> <if compare flag is false, skip next op>
        @0x8D3A: SAVE mapPosX = 0
        @0x8D40: SAVE mapPosY = 8
        @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
        @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
        @0x8D53: IF <> <if compare flag is false, skip next op>
        @0x8D54: GOTO 0x8DCF
}
```

## Event 05

- Target: `0x8D2D`
- Text hint: 'THERE IS A COMPUTER HERE.'

```text
event 05 {
  @0x8D2D: SAVE area2.event_scratch0 = 1
  @0x8D33: GOSUB 0xA0E4
  @0x8D38: IF <> <if compare flag is false, skip next op>
  @0x8D3A: SAVE mapPosX = 0
  @0x8D40: SAVE mapPosY = 8
  @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
  @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
  @0x8D53: IF <> <if compare flag is false, skip next op>
  @0x8D54: GOTO 0x8DCF
  // follows GOTO 0x8DCF
    @0x8DCF: AND area2.event_scratch0 = 8 & area1.event_word_386
    @0x8DD8: IF <> <if compare flag is false, skip next op>
    @0x8DD9: PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.'
    @0x8E00: IF <> <if compare flag is false, skip next op>
    @0x8E01: GOTO 0x8DAD
    // follows GOTO 0x8DAD
      @0x8DAE: SAVE area2.event_scratch0 = 0
      @0x8DB4: GOSUB 0xA0E4
      @0x8DB9: IF <> <if compare flag is false, skip next op>
      @0x8DBB: SAVE mapPosX = 8
      @0x8DC1: SAVE mapPosY = 0
      @0x8DC7: CALL raw: 0x2DCB, id: 0xADCC
      @0x8DCB: GOTO 0x8D2D
      // follows GOTO 0x8D2D
        // branch target 0x8D2D already shown
}
```

## Event 06

- Target: `0x8D4A`
- Text hint: 'THERE IS A COMPUTER HERE.'

```text
event 06 {
  @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
  @0x8D53: IF <> <if compare flag is false, skip next op>
  @0x8D54: GOTO 0x8DCF
  // follows GOTO 0x8DCF
    @0x8DCF: AND area2.event_scratch0 = 8 & area1.event_word_386
    @0x8DD8: IF <> <if compare flag is false, skip next op>
    @0x8DD9: PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.'
    @0x8E00: IF <> <if compare flag is false, skip next op>
    @0x8E01: GOTO 0x8DAD
    // follows GOTO 0x8DAD
      @0x8DAE: SAVE area2.event_scratch0 = 0
      @0x8DB4: GOSUB 0xA0E4
      @0x8DB9: IF <> <if compare flag is false, skip next op>
      @0x8DBB: SAVE mapPosX = 8
      @0x8DC1: SAVE mapPosY = 0
      @0x8DC7: CALL raw: 0x2DCB, id: 0xADCC
      @0x8DCB: GOTO 0x8D2D
      // follows GOTO 0x8D2D
        @0x8D2D: SAVE area2.event_scratch0 = 1
        @0x8D33: GOSUB 0xA0E4
        @0x8D38: IF <> <if compare flag is false, skip next op>
        @0x8D3A: SAVE mapPosX = 0
        @0x8D40: SAVE mapPosY = 8
        @0x8D46: CALL raw: 0x2DCB, id: 0xADCC
        @0x8D4A: AND area2.event_scratch0 = 4 & area1.event_word_386
        @0x8D53: IF <> <if compare flag is false, skip next op>
        @0x8D54: GOTO 0x8DCF
}
```

## Event 07

- Target: `0x8F12`
- Text hint: "'ROBOT CONTROL ROUTED TO SECONDARY CONTROL. INTRUDER ALERT!'"

```text
event 07 {
  @0x8F12: AND area2.event_scratch0 = 1 & area1.event_word_384
  @0x8F1B: IF <> <if compare flag is false, skip next op>
  @0x8F1C: EXIT
}
```

## Event 08

- Target: `0x8F60`
- Text hint: 'A CIRCLE OF DEACTIVATED ROBOTS IS HERE.'

```text
event 08 {
  @0x8F60: COMPARE Values: mapDirection == 2
  @0x8F66: IF <> <if compare flag is false, skip next op>
  @0x8F67: EXIT
}
```

## Event 09

- Target: `0x8FF0`
- Text hint: 'YOU ENTER A LARGE KITCHEN.'

```text
event 09 {
  @0x8FF0: AND area2.event_scratch0 = 4 & area1.event_word_384
  @0x8FF9: IF <> <if compare flag is false, skip next op>
  @0x8FFA: EXIT
}
```

## Event 10

- Target: `0x921E`
- Text hint: 'TO THE EAST IS THE ACCESS GRATE THAT THE STORMRIDERS TOLD YOU ABOUT. DO YOU GO THROUGH?'

```text
event 10 {
  @0x921E: COMPARE Values: mapDirection == 3
  @0x9224: IF = <if compare flag is false, skip next op>
  @0x9225: EXIT
}
```

## Event 11

- Target: `0x9298`
- Text hint: 'SOMEONE IS POUNDING ON THE NORTH DOOR FROM THE OTHER SIDE.'

```text
event 11 {
  @0x9298: COMPARE Values: area1.event_word_20C == 1
  @0x929E: IF = <if compare flag is false, skip next op>
  @0x929F: SAVE area1.event_word_20C = 0
  @0x92A5: IF = <if compare flag is false, skip next op>
  @0x92A6: EXIT
}
```

## Event 12

- Target: `0x92E3`
- Text hint: 'YOUR EQUIPMENT IS HERE!' ' YOU QUICKLY REARM.'

```text
event 12 {
  @0x92E3: AND area2.event_scratch0 = 8 & area1.event_word_384
  @0x92EC: IF <> <if compare flag is false, skip next op>
  @0x92ED: EXIT
}
```

## Event 13

- Target: `0x938A`
- Text hint: 'REMOTE ROBOT CONTROL CENTER'

```text
event 13 {
  @0x938A: AND area2.event_scratch0 = 16 & area1.event_word_384
  @0x9393: IF <> <if compare flag is false, skip next op>
  @0x9394: EXIT
}
```

## Event 14

- Target: `0x94B8`
- Text hint: 'REMOTE ROBOT CONTROL CENTER'

```text
event 14 {
  @0x94B8: COMPARE Values: mapDirection == 0
  @0x94BE: IF <> <if compare flag is false, skip next op>
  @0x94BF: EXIT
}
```

## Event 15

- Target: `0x94DE`
- Text hint: 'A SIGN OVER THE NORTH DOOR READS:' RETURN

```text
event 15 {
  @0x94DE: AND area2.event_scratch0 = 16 & area1.event_word_384
  @0x94E7: IF = <if compare flag is false, skip next op>
  @0x94E8: EXIT
}
```

## Event 16

- Target: `0x954D`
- Text hint: 'A SIGN OVER THE NORTH DOOR READS:' RETURN

```text
event 16 {
  @0x954D: COMPARE Values: mapDirection == 2
  @0x9553: IF = <if compare flag is false, skip next op>
  @0x9554: EXIT
}
```

## Event 17

- Target: `0x95A9`
- Text hint: 'YOU ENTER A COMMUNICATION CENTER. A SOLDIER RADIOS FOR HELP.'

```text
event 17 {
  @0x95A9: AND area2.event_scratch0 = 64 & area1.event_word_384
  @0x95B2: IF <> <if compare flag is false, skip next op>
  @0x95B3: EXIT
}
```

## Event 18

- Target: `0x9682`
- Text hint: 'YOU ENTER A COLD STORAGE ROOM.'

```text
event 18 {
  @0x9682: COMPARE Values: mapDirection == 2
  @0x9688: IF <> <if compare flag is false, skip next op>
  @0x9689: EXIT
}
```

## Event 19

- Target: `0x97AF`
- Text hint: 'THERE IS LIFE SUSPENSION EQUIPMENT HERE.'

```text
event 19 {
  @0x97AF: COMPARE Values: mapDirection == 1
  @0x97B5: IF <> <if compare flag is false, skip next op>
  @0x97B6: EXIT
}
```

## Event 20

- Target: `0x98B4`
- Text hint: '       QUARANTINE'

```text
event 20 {
  @0x98B4: GOSUB 0xA139
  @0x98B8: PRINT '       QUARANTINE'
  @0x98C8: EXIT
}
```

## Event 21

- Target: `0x98C9`
- Text hint: 'THE MAIN SECURITY COMPUTER IS HERE. ' 'IT IS DEACTIVATED.'

```text
event 21 {
  @0x98C9: AND area2.event_scratch0 = 2 & area1.event_word_386
  @0x98D2: IF <> <if compare flag is false, skip next op>
  @0x98D3: EXIT
}
```

## Event 22

- Target: `0x9979`
- Text hint: 'THE MAIN SECURITY COMPUTER IS HERE. ' 'IT IS DEACTIVATED.'

```text
event 22 {
  @0x9979: PRINTCLEAR 'THE MAIN SECURITY COMPUTER IS HERE. '
  @0x9997: AND area2.event_scratch0 = 4 & area1.event_word_386
  @0x99A0: IF <> <if compare flag is false, skip next op>
  @0x99A1: PRINT 'IT IS DEACTIVATED.'
  @0x99B2: IF <> <if compare flag is false, skip next op>
  @0x99B3: EXIT
}
```

## Event 23

- Target: `0x9A54`
- Text hint: 'YOU ENTER A GENETICS LAB. THERE ARE GROW TANKS ACROSS THE ROOM.'

```text
event 23 {
  @0x9A54: AND area2.event_scratch0 = 32 & area1.event_word_386
  @0x9A5D: IF <> <if compare flag is false, skip next op>
  @0x9A5E: EXIT
}
```

## Event 24

- Target: `0x9AEA`
- Text hint: 'YOU ENTER A GENETICS LAB. THERE ARE GROW TANKS ACROSS THE ROOM.'

```text
event 24 {
  @0x9AEA: COMPARE Values: mapDirection == 3
  @0x9AF0: IF <> <if compare flag is false, skip next op>
  @0x9AF1: EXIT
}
```

## Event 25

- Target: `0x9B27`
- Text hint: 'YOU APPROACH THE GROW VAT. IT IS FULL OF FLUID--READY TO USE.'

```text
event 25 {
  @0x9B27: AND area2.event_scratch0 = 64 & area1.event_word_386
  @0x9B30: IF <> <if compare flag is false, skip next op>
  @0x9B31: GOTO 0x9D2B
  // follows GOTO 0x9D2B
    @0x9D2B: PRINTCLEAR 'WASPHOPPERS POUR OUT OF THIS GROW VAT.'
    @0x9D4B: GOSUB 0xA19B
    @0x9D51: COMPARE Values: mapDirection == 2
    @0x9D57: GOTO 0x9AF0
    // follows GOTO 0x9AF0
      @0x9AF0: IF <> <if compare flag is false, skip next op>
      @0x9AF1: EXIT
}
```

## Event 26

- Target: `0x9D51`
- Text hint: 'THIS GROW VAT HAS BEEN DRAINED.'

```text
event 26 {
  @0x9D51: COMPARE Values: mapDirection == 2
  @0x9D57: GOTO 0x9AF0
  // follows GOTO 0x9AF0
    @0x9AF0: IF <> <if compare flag is false, skip next op>
    @0x9AF1: EXIT
}
```

## Event 27

- Target: `0x9D5B`
- Text hint: 'THIS GROW VAT HAS BEEN DRAINED.'

```text
event 27 {
  @0x9D5B: PRINTCLEAR 'THIS GROW VAT HAS BEEN DRAINED.'
  @0x9D76: EXIT
}
```

## Event 28

- Target: `0x9D77`
- Text hint: "MARIO QUINN'S BODY LIES HERE."

```text
event 28 {
  @0x9D77: AND area2.event_scratch0 = 64 & area1.event_word_386
  @0x9D80: IF = <if compare flag is false, skip next op>
  @0x9D81: EXIT
}
```

## Event 29

- Target: `0x9EFB`
- Text hint: "MARIO QUINN'S BODY LIES HERE."

```text
event 29 {
  @0x9EFB: AND area2.event_scratch0 = 64 & area1.event_word_386
  @0x9F04: IF = <if compare flag is false, skip next op>
  @0x9F05: EXIT
}
```

## Event 30

- Target: `0x9F21`
- Text hint: 'A GROUP OF STORMRIDERS MEET YOU. ONE SPEAKS.' 'THERE IS A COMPUTER TERMINAL HERE. ' 'CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.'

```text
event 30 {
  @0x9F21: AND area2.event_scratch0 = 8 & area1.event_word_386
  @0x9F2A: IF = <if compare flag is false, skip next op>
  @0x9F2B: EXIT
}
```

## Event 31

- Target: `0xA05E`
- Text hint: 'THERE IS A COMPUTER TERMINAL HERE. ' 'CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.' 'IT IS DEACTIVATED.'

```text
event 31 {
  @0xA05E: PRINTCLEAR 'THERE IS A COMPUTER TERMINAL HERE. '
  @0xA07C: AND area2.event_scratch0 = 8 & area1.event_word_386
  @0xA085: IF = <if compare flag is false, skip next op>
  @0xA086: PRINT 'CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.'
  @0xA0B9: IF = <if compare flag is false, skip next op>
  @0xA0BB: IF = <if compare flag is false, skip next op>
  @0xA0BD: PRINT 'IT IS DEACTIVATED.'
  @0xA0D0: EXIT
}
```
