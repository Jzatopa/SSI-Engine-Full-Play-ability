# GEO 84: Mars Prison, Level 2

ECL block: `84`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x81F0`
- Text hint: 'AN ELEVATOR GOING DOWN. DO YOU USE IT?'

```text
event 01 {
  @0x81F0: PRINTCLEAR 'AN ELEVATOR GOING DOWN. DO YOU USE IT?'
  @0x8272: COMPARE Values: mapDirection == 2
  @0x8278: IF <> <if compare flag is false, skip next op>
  @0x8279: EXIT
}
```

## Event 04

- Target: `0x84E4`
- Text hint: 'A WEAPONS LABORATORY. '

```text
event 04 {
  @0x84E4: COMPARE Values: mapDirection == 1
  @0x84EA: IF <> <if compare flag is false, skip next op>
  @0x84EB: EXIT
}
```

## Event 08

- Target: `0x8905`
- Text hint: 'AN EMPTY PHYSICS LAB.'

```text
event 08 {
  @0x8905: COMPARE Values: mapDirection == 2
  @0x890B: IF <> <if compare flag is false, skip next op>
  @0x890C: EXIT
}
```

## Event 10

- Target: `0x8C77`
- Text hint: 'AN EMPTY BOTANY LAB.'

```text
event 10 {
  @0x8C77: COMPARE Values: mapDirection == 0
  @0x8C7D: IF <> <if compare flag is false, skip next op>
  @0x8C7E: EXIT
}
```

## Event 11

- Target: `0x8C92`
- Text hint: 'AN EMPTY BIOLOGY LAB.'

```text
event 11 {
  @0x8C92: COMPARE Values: mapDirection == 0
  @0x8C98: IF <> <if compare flag is false, skip next op>
  @0x8C99: EXIT
}
```

## Event 12

- Target: `0x8CAE`
- Text hint: 'A MEDIA LAB.'

```text
event 12 {
  @0x8CAE: COMPARE Values: mapDirection == 0
  @0x8CB4: IF <> <if compare flag is false, skip next op>
  @0x8CB5: EXIT
}
```

## Event 13

- Target: `0x8E99`
- Text hint: 'AUDIO AND VIDEO CAPSULES ARE STORED HERE.'

```text
event 13 {
  @0x8E99: COMPARE Values: mapDirection == 3
  @0x8E9F: IF <> <if compare flag is false, skip next op>
  @0x8EA0: EXIT
}
```

## Event 14

- Target: `0x8EC4`
- Text hint: 'A RESTING LOUNGE. NO ONE IS HERE.'

```text
event 14 {
  @0x8EC4: COMPARE Values: mapDirection == 0
  @0x8ECA: IF <> <if compare flag is false, skip next op>
  @0x8ECB: EXIT
}
```

## Event 15

- Target: `0x8EE9`
- Text hint: 'A MEETING ROOM. A LARGE TABLE SURROUNDED BY CHAIRS IS HERE.'

```text
event 15 {
  @0x8EE9: COMPARE Values: mapDirection == 2
  @0x8EEF: IF <> <if compare flag is false, skip next op>
  @0x8EF0: EXIT
}
```

## Event 16

- Target: `0x8F22`
- Text hint: 'A COMPUTER LAB. '

```text
event 16 {
  @0x8F22: COMPARE Values: mapDirection == 2
  @0x8F28: IF <> <if compare flag is false, skip next op>
  @0x8F29: EXIT
}
```

## Event 17

- Target: `0x8FA0`
- Text hint: 'YOU FIND A NOTE PAD SITTING ON THE COMPUTER DESK'

```text
event 17 {
  @0x8FA0: AND area2.event_scratch0 = 1 & area1.event_word_31C
  @0x8FA9: IF <> <if compare flag is false, skip next op>
  @0x8FAA: EXIT
}
```

## Event 18

- Target: `0x8FEB`
- Text hint: 'A BROOM CLOSET.'

```text
event 18 {
  @0x8FEB: COMPARE Values: mapDirection == 2
  @0x8FF1: IF <> <if compare flag is false, skip next op>
  @0x8FF2: EXIT
}
```

## Event 19

- Target: `0x9003`
- Text hint: 'AS YOU ENTER THE ROOM, HANIBL SOOTH RISES FROM A CHAIR. HE PULLS A CLUSTER OF ELECTRODES FROM HIS SCALP. A TECHNICIAN ATTENDS HIM.'

```text
event 19 {
  @0x9003: COMPARE Values: mapDirection == 3
  @0x9009: IF <> <if compare flag is false, skip next op>
  @0x900A: EXIT
}
```

## Event 20

- Target: `0x92C3`
- Text hint: "YOU HEAR HANIBL SOOTH'S VOICE TO THE EAST!"

```text
event 20 {
  @0x92C3: COMPARE Values: mapDirection == 0
  @0x92C9: IF <> <if compare flag is false, skip next op>
  @0x92CA: EXIT
}
```

## Event 21

- Target: `0x95DE`
- Text hint: 'THE SCREEN OF THIS COMPUTER READS:' RETURN

```text
event 21 {
  @0x95DE: COMPARE Values: area1.event_word_31E == 1
  @0x95E4: IF = <if compare flag is false, skip next op>
  @0x95E5: GOTO 0x9631
  // follows GOTO 0x9631
    @0x9631: PRINTCLEAR 'THESE COMPUTERS ARE INACTIVE.'
    @0x964A: EXIT
}
```

## Event 22

- Target: `0x964B`
- Text hint: 'THE SIGN OVER THE DOOR READS:' RETURN

```text
event 22 {
  @0x964B: COMPARE Values: mapDirection == 1
  @0x9651: IF <> <if compare flag is false, skip next op>
  @0x9652: EXIT
}
```

## Event 24

- Target: `0x982C`
- Text hint: 'THE MAIN COMPUTER IS SHUT DOWN.'

```text
event 24 {
  @0x982C: COMPARE Values: area1.event_word_31E == 1
  @0x9832: IF = <if compare flag is false, skip next op>
  @0x9833: PRINTCLEAR 'THE MAIN COMPUTER IS SHUT DOWN.'
  @0x984E: IF = <if compare flag is false, skip next op>
  @0x984F: EXIT
}
```
