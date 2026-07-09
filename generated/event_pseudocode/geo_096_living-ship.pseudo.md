# GEO 96: Living Ship

ECL block: `96`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 01 {
  @0x8268: EXIT
}
```

## Event 02

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 02 {
  @0x8268: EXIT
}
```

## Event 03

- Target: `0x839A`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 03 {
  @0x839A: AND area2.event_scratch0 = 105 & area1.event_word_26A
  @0x83A3: IF <> <if compare flag is false, skip next op>
  @0x83A4: EXIT
}
```

## Event 04

- Target: `0x83F3`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 04 {
  @0x83F3: AND area2.event_scratch0 = 160 & area1.event_word_3E6
  @0x83FC: IF <> <if compare flag is false, skip next op>
  @0x83FD: EXIT
}
```

## Event 05

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 05 {
  @0x8268: EXIT
}
```

## Event 07

- Target: `0x881B`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 07 {
  @0x881B: AND area2.event_scratch0 = 16 & area1.event_word_240
  @0x8824: IF <> <if compare flag is false, skip next op>
  @0x8825: EXIT
}
```

## Event 08

- Target: `0x88B4`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 08 {
  @0x88B4: COMPARE AND Values: abs_C04E == 0 && mapDirection == 2
  @0x88BF: IF <> <if compare flag is false, skip next op>
  @0x88C0: EXIT
}
```

## Event 09

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 09 {
  @0x8268: EXIT
}
```

## Event 10

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 10 {
  @0x8268: EXIT
}
```

## Event 11

- Target: `0x8D4B`
- Text hint: 'ODDLY SHAPED EQUIPMENT IS STORED HERE.'

```text
event 11 {
  @0x8D4B: SAVE area2.event_scratch0 = 1
  @0x8D51: GOTO 0x8D5B
  // follows GOTO 0x8D5B
    @0x8D5B: COMPARE Values: 0 == abs_C04E
    @0x8D61: IF <> <if compare flag is false, skip next op>
    @0x8D62: EXIT
}
```

## Event 12

- Target: `0x8D55`
- Text hint: 'ODDLY SHAPED EQUIPMENT IS STORED HERE.'

```text
event 12 {
  @0x8D55: SAVE area2.event_scratch0 = 2
  @0x8D5B: COMPARE Values: 0 == abs_C04E
  @0x8D61: IF <> <if compare flag is false, skip next op>
  @0x8D62: EXIT
}
```

## Event 13

- Target: `0x8ED1`
- Text hint: 'YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?'

```text
event 13 {
  @0x8ED1: AND area2.event_scratch0 = 8 & area1.event_word_246
  @0x8EDA: IF <> <if compare flag is false, skip next op>
  @0x8EDB: EXIT
}
```

## Event 14

- Target: `0x8F3D`
- Text hint: ''

```text
event 14 {
  @0x8F3D: SAVE area2.event_scratch0 = 16
  @0x8F43: GOTO 0x8F58
  // follows GOTO 0x8F58
    @0x8F58: PRINTCLEAR ''
    @0x8F5B: AND area2.event_scratch1 = 15 & area1.event_word_242
    @0x8F64: IF <> <if compare flag is false, skip next op>
    @0x8F65: EXIT
}
```

## Event 15

- Target: `0x8F47`
- Text hint: ''

```text
event 15 {
  @0x8F47: COMPARE Values: 2 == mapDirection
  @0x8F4D: IF = <if compare flag is false, skip next op>
  @0x8F4E: GOTO 0x9040
  // follows GOTO 0x9040
    @0x9040: COMPARE Values: 0 == area1.event_word_3E0
    @0x9046: IF <> <if compare flag is false, skip next op>
    @0x9047: EXIT
}
```

## Event 16

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 16 {
  @0x8268: EXIT
}
```

## Event 17

- Target: `0x90AC`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 17 {
  @0x90AC: AND area2.event_scratch0 = 3 & area1.event_word_242
  @0x90B5: IF <> <if compare flag is false, skip next op>
  @0x90B6: EXIT
}
```

## Event 18

- Target: `0x95CF`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 18 {
  @0x95CF: SAVE area2.event_scratch0 = 1
  @0x95D5: GOTO 0x95E9
  // follows GOTO 0x95E9
    @0x95E9: PRINTCLEAR "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."
    @0x9622: COMPARE Values: 255 == area1.event_word_3E4
    @0x9628: IF = <if compare flag is false, skip next op>
    @0x9629: GOTO 0x9703
    // follows GOTO 0x9703
      @0x9703: PRINT 'DO YOU USE A SONIC STUNNER ON THE NERVE?'
      // truncated: next decoded instruction is 0x9B16
}
```

## Event 19

- Target: `0x95D9`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 19 {
  @0x95D9: SAVE area2.event_scratch0 = 2
  @0x95DF: GOTO 0x95E9
  // follows GOTO 0x95E9
    @0x95E9: PRINTCLEAR "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."
    @0x9622: COMPARE Values: 255 == area1.event_word_3E4
    @0x9628: IF = <if compare flag is false, skip next op>
    @0x9629: GOTO 0x9703
    // follows GOTO 0x9703
      @0x9703: PRINT 'DO YOU USE A SONIC STUNNER ON THE NERVE?'
      // truncated: next decoded instruction is 0x9B16
}
```

## Event 20

- Target: `0x95E3`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 20 {
  @0x95E3: SAVE area2.event_scratch0 = 4
  @0x95E9: PRINTCLEAR "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."
  @0x9622: COMPARE Values: 255 == area1.event_word_3E4
  @0x9628: IF = <if compare flag is false, skip next op>
  @0x9629: GOTO 0x9703
  // follows GOTO 0x9703
    @0x9703: PRINT 'DO YOU USE A SONIC STUNNER ON THE NERVE?'
    // truncated: next decoded instruction is 0x9B16
}
```

## Event 21

- Target: `0x9B16`
- Text hint: 'THE ROOM SMELLS OF ANTISEPTIC.'

```text
event 21 {
  @0x9B16: AND area2.event_scratch0 = 64 & area1.event_word_246
  @0x9B1F: IF <> <if compare flag is false, skip next op>
  @0x9B20: EXIT
}
```

## Event 22

- Target: `0x9B94`
- Text hint: 'THE ROOM SMELLS OF ANTISEPTIC.'

```text
event 22 {
  @0x9B94: AND area2.event_scratch0 = 3 & area1.event_word_3E6
  @0x9B9D: IF <> <if compare flag is false, skip next op>
  @0x9B9E: EXIT
}
```

## Event 23

- Target: `0x9F3C`
- Text hint: 'THE ROOM SMELLS OF ANTISEPTIC.'

```text
event 23 {
  @0x9F3C: COMPARE Values: 2 == mapDirection
  @0x9F42: IF <> <if compare flag is false, skip next op>
  @0x9F43: EXIT
}
```

## Event 24

- Target: `0x9F60`
- Text hint: 'MEDICAL SUPPLIES ARE SCATTERED ABOUT THE ROOM.'

```text
event 24 {
  @0x9F60: COMPARE Values: 0 == abs_C04E
  @0x9F66: IF <> <if compare flag is false, skip next op>
  @0x9F67: EXIT
}
```

## Event 25

- Target: `0x9F90`
- Text hint: 'THE AUTODOC LAYS TOPPLED ON THE FLOOR. DO YOU TRY TO REPAIR IT?' 'THE AUTODOC ASKS IF YOU NEED TO BE HEALED.' 'THE AUTODOC IS BEYOND REPAIR.'

```text
event 25 {
  @0x9F90: AND area2.event_scratch0 = 32 & area1.event_word_242
  @0x9F99: IF <> <if compare flag is false, skip next op>
  @0x9F9A: GOTO 0xA04D
  // follows GOTO 0xA04D
    @0xA04D: OR area1.event_word_242 = 32 | area1.event_word_242
    @0xA056: PRINTCLEAR 'THE AUTODOC IS BEYOND REPAIR.'
    @0xA071: SAVE area2.event_scratch0 = 1
    @0xA077: SAVE area2.event_scratch1 = 2
    @0xA07D: SAVE area2.event_scratch6 = 23
    @0xA083: COMPARE Values: mapDirection == area2.event_scratch1
    @0xA08A: IF <> <if compare flag is false, skip next op>
    @0xA08B: EXIT
}
```

## Event 26

- Target: `0xA071`
- Text hint: 'CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. '

```text
event 26 {
  @0xA071: SAVE area2.event_scratch0 = 1
  @0xA077: SAVE area2.event_scratch1 = 2
  @0xA07D: SAVE area2.event_scratch6 = 23
  @0xA083: COMPARE Values: mapDirection == area2.event_scratch1
  @0xA08A: IF <> <if compare flag is false, skip next op>
  @0xA08B: EXIT
}
```

## Event 27

- Target: `0xA191`
- Text hint: RETURN

```text
event 27 {
  @0xA191: SAVE area2.event_scratch0 = 2
  @0xA197: SAVE area2.event_scratch1 = 2
  @0xA19D: SAVE area2.event_scratch6 = 64
  @0xA1A3: GOTO 0xA083
  // follows GOTO 0xA083
    @0xA083: COMPARE Values: mapDirection == area2.event_scratch1
    @0xA08A: IF <> <if compare flag is false, skip next op>
    @0xA08B: EXIT
}
```

## Event 28

- Target: `0xA1A7`
- Text hint: RETURN

```text
event 28 {
  @0xA1A7: SAVE area2.event_scratch0 = 4
  @0xA1AD: SAVE area2.event_scratch1 = 3
  @0xA1B3: SAVE area2.event_scratch6 = 56
  @0xA1B9: GOTO 0xA083
  // follows GOTO 0xA083
    @0xA083: COMPARE Values: mapDirection == area2.event_scratch1
    @0xA08A: IF <> <if compare flag is false, skip next op>
    @0xA08B: EXIT
}
```

## Event 29

- Target: `0xA1BD`
- Text hint: RETURN

```text
event 29 {
  @0xA1BD: SAVE area2.event_scratch0 = 8
  @0xA1C3: SAVE area2.event_scratch1 = 1
  @0xA1C9: SAVE area2.event_scratch6 = 74
  @0xA1CF: GOTO 0xA083
  // follows GOTO 0xA083
    @0xA083: COMPARE Values: mapDirection == area2.event_scratch1
    @0xA08A: IF <> <if compare flag is false, skip next op>
    @0xA08B: EXIT
}
```

## Event 30

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 30 {
  @0x8268: EXIT
}
```
