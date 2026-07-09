# GEO 82: NEO Installation

ECL block: `82`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 01 {
  @0x852F: EXIT
}
```

## Event 02

- Target: `0x867D`
- Text hint: 'AN ELEVATOR. DO YOU USE IT?'

```text
event 02 {
  @0x867D: PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?'
  @0x87DF: COMPARE Values: 1 == area1.event_word_352
  @0x87E5: IF <> <if compare flag is false, skip next op>
  @0x87E6: EXIT
}
```

## Event 03

- Target: `0x87DF`
- Text hint: "YOU FIND A BADLY INJURED MAN IN THE CORNER OF THE ROOM. 'PLEASE TAKE MY ARMOR... PUT IT TO GOOD USE.'"

```text
event 03 {
  @0x87DF: COMPARE Values: 1 == area1.event_word_352
  @0x87E5: IF <> <if compare flag is false, skip next op>
  @0x87E6: EXIT
}
```

## Event 04

- Target: `0x8855`
- Text hint: "A MAN WALKS UP. 'I HEARD ABOUT YOUR CONVERSATION WITH DR. HAMPSHIRE. THIS WEAPON MAY HELP YOUR INQUIRIES.'"

```text
event 04 {
  @0x8855: AND area2.event_scratch0 = 8 & area1.event_word_348
  @0x885E: IF <> <if compare flag is false, skip next op>
  @0x885F: EXIT
}
```

## Event 05

- Target: `0x88D2`
- Text hint: "A VOLUBLE, BESPECKLED MAN GREETS YOU ENTHUSIASTICALLY. 'WHAT DO YOU HAVE WITH YOU. HMM, NON-NEO DESIGN. SEE DR. HAMPSHIRE, HE'S AN EXPERT IN ELECTRONICS.'" "'I AM BUSY RIGHT NOW.'"

```text
event 05 {
  @0x88D2: AND area2.event_scratch0 = 32 & area1.event_word_348
  @0x88DB: IF <> <if compare flag is false, skip next op>
  @0x88DC: GOTO 0x8962
  // follows GOTO 0x8962
    @0x8962: PRINTCLEAR "'I AM BUSY RIGHT NOW.'"
    @0x8978: AND area2.event_scratch0 = 32 & area1.event_word_34A
    @0x8981: IF = <if compare flag is false, skip next op>
    @0x8982: EXIT
}
```

## Event 06

- Target: `0x8978`
- Text hint: 'YOU FIND A SET OF CODE 4 CARDS.'

```text
event 06 {
  @0x8978: AND area2.event_scratch0 = 32 & area1.event_word_34A
  @0x8981: IF = <if compare flag is false, skip next op>
  @0x8982: EXIT
}
```

## Event 07

- Target: `0x9D61`
- Text hint: "THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD." "THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'"

```text
event 07 {
  @0x9D61: AND area2.event_scratch0 = 8 & area1.event_word_34E
  @0x9D6A: IF = <if compare flag is false, skip next op>
  @0x9D6B: GOTO 0x9E5F
  // follows GOTO 0x9E5F
    @0x9E5F: PRINTCLEAR "THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'"
    @0x9E94: AND area2.event_scratch0 = 32 & area1.event_word_34E
    @0x9E9D: IF = <if compare flag is false, skip next op>
    @0x9E9E: GOTO 0x9EEA
    // follows GOTO 0x9EEA
      @0x9EEA: PRINTCLEAR 'THIS IS THE EMERGENCY HATCH.'
      @0x9F02: EXIT
}
```

## Event 09

- Target: `0x89AE`
- Text hint: "AN ELDERLY FELLOW RISES AT YOUR APPROACH. 'I AM DR. HAMPSHIRE. LET ME SEE THE DEVICE.'" "'I ALREADY TOLD YOU EVERYTHING I KNOW.'"

```text
event 09 {
  @0x89AE: AND area2.event_scratch0 = 16 & area1.event_word_348
  @0x89B7: IF <> <if compare flag is false, skip next op>
  @0x89B8: GOTO 0x8AEB
  // follows GOTO 0x8AEB
    @0x8AEB: PRINTCLEAR "'I ALREADY TOLD YOU EVERYTHING I KNOW.'"
    @0x8B0E: AND area2.event_scratch0 = 16 & area1.event_word_34A
    @0x8B17: IF <> <if compare flag is false, skip next op>
    @0x8B18: EXIT
}
```

## Event 10

- Target: `0x8B0E`
- Text hint: "YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'."

```text
event 10 {
  @0x8B0E: AND area2.event_scratch0 = 16 & area1.event_word_34A
  @0x8B17: IF <> <if compare flag is false, skip next op>
  @0x8B18: EXIT
}
```

## Event 11

- Target: `0x8C22`
- Text hint: 'THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..' RETURN

```text
event 11 {
  @0x8C22: AND area2.event_scratch0 = 32 & area1.event_word_34A
  @0x8C2B: IF <> <if compare flag is false, skip next op>
  @0x8C2C: EXIT
}
```

## Event 12

- Target: `0x9E94`
- Text hint: 'THIS IS THE EMERGENCY HATCH.'

```text
event 12 {
  @0x9E94: AND area2.event_scratch0 = 32 & area1.event_word_34E
  @0x9E9D: IF = <if compare flag is false, skip next op>
  @0x9E9E: GOTO 0x9EEA
  // follows GOTO 0x9EEA
    @0x9EEA: PRINTCLEAR 'THIS IS THE EMERGENCY HATCH.'
    @0x9F02: EXIT
}
```

## Event 14

- Target: `0x8F70`
- Text hint: 'THIS IS THE DANCE HALL.'

```text
event 14 {
  @0x8F70: COMPARE Values: 1 == area1.event_word_352
  @0x8F76: IF = <if compare flag is false, skip next op>
  @0x8F77: GOTO 0x8F92
  // follows GOTO 0x8F92
    @0x8F92: AND area2.event_scratch0 = 2 & area1.event_word_34C
    @0x8F9B: IF <> <if compare flag is false, skip next op>
    @0x8F9C: EXIT
}
```

## Event 15

- Target: `0x9385`
- Text hint: "MR. FREDRICKSON LOOKS UP. 'IT TOOK SOME TIME FOR YOUR FILES TO BE TRANSFERRED FROM SALVATION. FOR NOW, HERE ARE LEVEL 1 SECURITY PASSES. I'LL GET YOU BETTER ONES WHEN THE PAPERWORK COMES THROUGH."

```text
event 15 {
  @0x9385: AND area2.event_scratch0 = 64 & area1.event_word_34A
  @0x938E: IF <> <if compare flag is false, skip next op>
  @0x938F: GOTO 0x946A
  // follows GOTO 0x946A
    @0x946A: AND area2.event_scratch0 = 128 & area1.event_word_348
    @0x9473: IF <> <if compare flag is false, skip next op>
    @0x9474: GOTO 0x9537
    // follows GOTO 0x9537
      @0x9537: AND area2.event_scratch0 = 32 & area1.event_word_34C
      @0x9540: IF <> <if compare flag is false, skip next op>
      @0x9541: GOTO 0x95F4
      // follows GOTO 0x95F4
        @0x95F4: AND area2.event_scratch0 = 32 & area1.event_word_34A
        @0x95FD: IF = <if compare flag is false, skip next op>
        @0x95FE: GOTO 0x9856
}
```

## Event 16

- Target: `0x9029`
- Text hint: 'ZACHARY IS HERE PROTECTED BY A RAM INFILTRATION TEAM.'

```text
event 16 {
  @0x9029: AND area2.event_scratch0 = 2 & area1.event_word_34A
  @0x9032: IF <> <if compare flag is false, skip next op>
  @0x9033: EXIT
}
```

## Event 17

- Target: `0x90C6`
- Text hint: 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?'

```text
event 17 {
  @0x90C7: AND area2.event_scratch0 = 16 & area1.event_word_34E
  @0x90D0: IF <> <if compare flag is false, skip next op>
  @0x90D1: GOTO 0x91E5
  // follows GOTO 0x91E5
    @0x91E5: AND area2.event_scratch0 = 32 & area1.event_word_34E
    @0x91EE: IF <> <if compare flag is false, skip next op>
    @0x91EF: EXIT
}
```

## Event 18

- Target: `0x90C7`
- Text hint: 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?'

```text
event 18 {
  @0x90C7: AND area2.event_scratch0 = 16 & area1.event_word_34E
  @0x90D0: IF <> <if compare flag is false, skip next op>
  @0x90D1: GOTO 0x91E5
  // follows GOTO 0x91E5
    @0x91E5: AND area2.event_scratch0 = 32 & area1.event_word_34E
    @0x91EE: IF <> <if compare flag is false, skip next op>
    @0x91EF: EXIT
}
```

## Event 19

- Target: `0x9891`
- Text hint: 'YOU PUT ZACHARY IN THE JAIL.' 'AN EMPTY CELL.'

```text
event 19 {
  @0x9891: AND area2.event_scratch0 = area1.event_word_34A & 2
  @0x989A: IF = <if compare flag is false, skip next op>
  @0x989B: GOTO 0x98CD
  // follows GOTO 0x98CD
    @0x98CD: PRINTCLEAR 'AN EMPTY CELL.'
    @0x98DB: EXIT
}
```

## Event 20

- Target: `0x98DC`
- Text hint: 'AIRLOCK 1 IS BEFORE YOU.' 'THIS IS A CREW CABIN.'

```text
event 20 {
  @0x98DC: EXIT
}
```

## Event 21

- Target: `0x98DD`
- Text hint: 'AIRLOCK 1 IS BEFORE YOU.' 'THIS IS A CREW CABIN.'

```text
event 21 {
  @0x98DD: AND area2.event_scratch0 = 1 & area1.event_word_34E
  @0x98E6: IF <> <if compare flag is false, skip next op>
  @0x98E7: EXIT
}
```

## Event 22

- Target: `0x9C90`
- Text hint: "A GUARD APPROACHES. 'OUR SENSORS HAVE DETECTED UNUSUAL MAGNETIC READINGS FROM THE BASEMENT. THEY MAY BE INVOLVED IN YOUR INVESTIGATION. PLEASE KEEP THE DIRECTOR INFORMED OF ANY PROGRESS.'"

```text
event 22 {
  @0x9C90: COMPARE Values: 1 == area1.event_word_352
  @0x9C96: IF <> <if compare flag is false, skip next op>
  @0x9C97: GOTO 0x9CB3
  // follows GOTO 0x9CB3
    @0x9CB3: AND area2.event_scratch0 = 128 & area1.event_word_34E
    @0x9CBC: IF <> <if compare flag is false, skip next op>
    @0x9CBD: EXIT
}
```

## Event 23

- Target: `0x9988`
- Text hint: 'AIRLOCK 1 IS BEFORE YOU.' 'THIS IS A CREW CABIN.'

```text
event 23 {
  @0x9988: COMPARE Values: 0 == mapDirection
  @0x998E: IF <> <if compare flag is false, skip next op>
  @0x998F: EXIT
}
```

## Event 24

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 24 {
  @0x852F: EXIT
}
```

## Event 26

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 26 {
  @0x852F: EXIT
}
```

## Event 27

- Target: `0x9C15`
- Text hint: 'YOU SPOT THE SPY THAT ESCAPED! HE AND OTHERS ATTACK!'

```text
event 27 {
  @0x9C15: AND area2.event_scratch0 = 2 & area1.event_word_34E
  @0x9C1E: IF = <if compare flag is false, skip next op>
  @0x9C1F: EXIT
}
```

## Event 28

- Target: `0x99A7`
- Text hint: 'THIS IS A CREW CABIN.'

```text
event 28 {
  @0x99A7: PRINTCLEAR 'THIS IS A CREW CABIN.'
  @0x99BA: EXIT
}
```

## Event 29

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 29 {
  @0x852F: EXIT
}
```

## Event 33

- Target: `0x9F03`
- Text hint: "THE SECURITY CHIEF GREETS YOU. 'ONE OF MY MEN NOTED SOMEONE SUSPICIOUS ON THE CABIN LEVEL, BUT HE LOST THE MAN. YOU MIGHT WANT TO FOLLOW UP.'"

```text
event 33 {
  @0x9F03: AND area2.event_scratch0 = 32 & area1.event_word_34C
  @0x9F0C: IF = <if compare flag is false, skip next op>
  @0x9F0D: EXIT
}
```

## Event 34

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 34 {
  @0x852F: EXIT
}
```

## Event 36

- Target: `0x99D5`
- Text hint: "A SIGN READS, 'AIRLOCK 2.'"

```text
event 36 {
  @0x99D5: COMPARE Values: 3 == mapDirection
  @0x99DB: IF = <if compare flag is false, skip next op>
  @0x99DC: EXIT
}
```

## Event 37

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 37 {
  @0x852F: EXIT
}
```

## Event 38

- Target: `0x9B23`
- Text hint: 'THERE IS A LOT OF JUNK HERE. DO YOU WISH TO SEARCH?'

```text
event 38 {
  @0x9B23: AND area2.event_scratch0 = 64 & area1.event_word_34A
  @0x9B2C: IF <> <if compare flag is false, skip next op>
  @0x9B2D: EXIT
}
```
