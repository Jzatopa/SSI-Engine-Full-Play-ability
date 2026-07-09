# GEO 80: Mars Prison, Level 1

ECL block: `80`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 02

- Target: `0x90F8`
- Text hint: 'A HOLE HERE LEADS INTO AN ENVIROCELL. CLIMB DOWN?' "YOU BURST INTO THE PRISON'S SURVEILLANCE ROOM." ' IT IS EMPTY.'

```text
event 02 {
  @0x90F8: PRINTCLEAR 'A HOLE HERE LEADS INTO AN ENVIROCELL. CLIMB DOWN?'
  @0x9142: COMPARE Values: 13 == area1.event_word_21C
  @0x9148: IF <> <if compare flag is false, skip next op>
  @0x914A: PRINTCLEAR "YOU BURST INTO THE PRISON'S SURVEILLANCE ROOM."
  @0x9170: AND area2.event_scratch0 = 16 & area1.event_word_208
  @0x9179: IF <> <if compare flag is false, skip next op>
  @0x917A: PRINT ' IT IS EMPTY.'
  @0x9187: IF <> <if compare flag is false, skip next op>
  @0x9188: EXIT
}
```

## Event 03

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 03 {
  @0x8352: COMPARE Values: area1.event_word_21A == mapDirection
  @0x8359: SAVE area1.event_word_21A = mapDirection
  @0x8360: IF = <if compare flag is false, skip next op>
  @0x8362: COMPARE Values: 255 == area1.event_word_212
  @0x8368: IF = <if compare flag is false, skip next op>
  @0x8369: EXIT
}
```

## Event 05

- Target: `0x9363`
- Text hint: 'THE PRISON AUTOSURGEONS FIND YOU.'

```text
event 05 {
  @0x9363: AND area2.event_scratch0 = 128 & area1.event_word_208
  @0x936C: IF <> <if compare flag is false, skip next op>
  @0x936D: GOTO 0x950A
  // follows GOTO 0x950A
    @0x950A: OR area1.event_word_208 = 128 | area1.event_word_208
    @0x9513: SAVE area1.event_word_228 = 255
    @0x9519: PRINTCLEAR 'THE HULK IS A LADDER TO THE HATCH ABOVE. GO UP?'
    @0x954B: PRINTCLEAR 'A HATCH. GO DOWN?'
    @0x9566: AND area2.event_scratch0 = 4 & area1.event_word_20A
    @0x956F: IF <> <if compare flag is false, skip next op>
    @0x9570: GOTO 0x8330
    // follows GOTO 0x8330
      @0x8330: COMPARE Values: 8 == area1.event_word_204
      @0x8336: IF <> <if compare flag is false, skip next op>
      @0x8337: COMPARE Values: 9 == area1.event_word_204
      @0x833D: IF <> <if compare flag is false, skip next op>
      @0x833F: PRINTCLEAR 'THE CONSOLE IS DEAD.'
      @0x8351: EXIT
}
```

## Event 06

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 06 {
  @0x8352: COMPARE Values: area1.event_word_21A == mapDirection
  @0x8359: SAVE area1.event_word_21A = mapDirection
  @0x8360: IF = <if compare flag is false, skip next op>
  @0x8362: COMPARE Values: 255 == area1.event_word_212
  @0x8368: IF = <if compare flag is false, skip next op>
  @0x8369: EXIT
}
```

## Event 07

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 07 {
  @0x8352: COMPARE Values: area1.event_word_21A == mapDirection
  @0x8359: SAVE area1.event_word_21A = mapDirection
  @0x8360: IF = <if compare flag is false, skip next op>
  @0x8362: COMPARE Values: 255 == area1.event_word_212
  @0x8368: IF = <if compare flag is false, skip next op>
  @0x8369: EXIT
}
```

## Event 09

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 09 {
  @0x8352: COMPARE Values: area1.event_word_21A == mapDirection
  @0x8359: SAVE area1.event_word_21A = mapDirection
  @0x8360: IF = <if compare flag is false, skip next op>
  @0x8362: COMPARE Values: 255 == area1.event_word_212
  @0x8368: IF = <if compare flag is false, skip next op>
  @0x8369: EXIT
}
```
