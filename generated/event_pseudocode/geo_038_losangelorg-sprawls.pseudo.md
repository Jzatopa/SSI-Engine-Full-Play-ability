# GEO 38: Losangelorg Sprawls

ECL block: `38`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8101`
- Text hint: 'THE DOOR TO ROOM '

```text
event 01 {
  @0x8101: EXIT
}
```

## Event 02

- Target: `0x85AB`
- Text hint: 'YOU ENTER THE ELEVATOR. DO YOU WISH TO USE IT?'

```text
event 02 {
  @0x85AB: COMPARE Values: area1.event_word_20A == 1
  @0x85B1: IF = <if compare flag is false, skip next op>
  @0x85B2: SAVE area1.event_word_20A = 0
  @0x85B8: IF = <if compare flag is false, skip next op>
  @0x85B9: EXIT
}
```

## Event 03

- Target: `0x875E`
- Text hint: 'A PLAQUE ON THE WALL READS,' RETURN

```text
event 03 {
  @0x875E: COMPARE Values: mapDirection == 2
  @0x8764: IF <> <if compare flag is false, skip next op>
  @0x8765: EXIT
}
```

## Event 04

- Target: `0x8885`
- Text hint: 'A SIGN OVER THE DOOR READS,' RETURN

```text
event 04 {
  @0x8885: COMPARE Values: area1.event_word_204 == 13
  @0x888B: IF <> <if compare flag is false, skip next op>
  @0x888C: GOTO 0x85AA
  // follows GOTO 0x85AA
    @0x85AA: EXIT
}
```

## Event 05

- Target: `0x88BD`
- Text hint: 'A SIGN OVER THE SOUTH DOOR READS,' RETURN

```text
event 05 {
  @0x88BD: COMPARE Values: area1.event_word_20A == 1
  @0x88C3: IF = <if compare flag is false, skip next op>
  @0x88C4: SAVE area1.event_word_20A = 0
  @0x88CA: IF = <if compare flag is false, skip next op>
  @0x88CB: EXIT
}
```

## Event 06

- Target: `0x8949`
- Text hint: 'A MAN IN A RAGGED MILITARY UNIFORM SITS AGAINST THE WALL HERE.'

```text
event 06 {
  @0x8949: COMPARE Values: area1.event_word_204 == 13
  @0x894F: IF <> <if compare flag is false, skip next op>
  @0x8950: GOTO 0x85AA
  // follows GOTO 0x85AA
    @0x85AA: EXIT
}
```

## Event 07

- Target: `0x8BB9`
- Text hint: 'YOU FLEE THE BATTLE.'

```text
event 07 {
  @0x8BB9: AND area2.event_scratch0 = 1 & area1.event_word_298
  @0x8BC2: IF <> <if compare flag is false, skip next op>
  @0x8BC3: EXIT
}
```

## Event 08

- Target: `0x8CDC`
- Text hint: "YOU ENTER AN EMPTY BARROOM. THE BARTENDER GREETS YOU. 'HI, PULL UP A STOOL. I'LL BUY YOU A DRINK!'"

```text
event 08 {
  @0x8CDC: COMPARE Values: mapDirection == 2
  @0x8CE2: IF <> <if compare flag is false, skip next op>
  @0x8CE3: EXIT
}
```

## Event 09

- Target: `0x8E4A`
- Text hint: 'A CARD GAME IS BEING PLAYED AT ONE OF THE TABLES. AS YOU ENTER THE ROOM, A PLAYER LOOKS UP.'

```text
event 09 {
  @0x8E4A: COMPARE Values: mapDirection == 0
  @0x8E50: IF <> <if compare flag is false, skip next op>
  @0x8E51: EXIT
}
```

## Event 10

- Target: `0x9483`
- Text hint: 'YOU ENTER THE SPARKHOUSE CAFE.'

```text
event 10 {
  @0x9483: COMPARE Values: mapDirection == 2
  @0x9489: IF <> <if compare flag is false, skip next op>
  @0x948A: EXIT
}
```

## Event 11

- Target: `0x964B`
- Text hint: "THE WARREN DWELLERS SHOUT DOWN TO YOU. 'YOU DIDN'T FIND OUR CHILDREN...YOU MUST GO BACK!'"

```text
event 11 {
  @0x964B: COMPARE Values: area1.event_word_20A == 1
  @0x9651: IF = <if compare flag is false, skip next op>
  @0x9652: SAVE area1.event_word_20A = 0
  @0x9658: IF = <if compare flag is false, skip next op>
  @0x9659: EXIT
}
```

## Event 12

- Target: `0x9723`
- Text hint: 'RATWURST ATTACK!'

```text
event 12 {
  @0x9723: AND area2.event_scratch0 = 1 & area1.event_word_21A
  @0x972C: IF <> <if compare flag is false, skip next op>
  @0x972D: EXIT
}
```

## Event 13

- Target: `0x984B`
- Text hint: "'HELP!' YOU HEAR A SHOUT FROM THE SOUTH."

```text
event 13 {
  @0x984B: AND area2.event_scratch0 = 2 & area1.event_word_21A
  @0x9854: IF <> <if compare flag is false, skip next op>
  @0x9855: EXIT
}
```

## Event 14

- Target: `0x9882`
- Text hint: 'RATWURSTS HAVE CORNERED A MAN AT THE END OF THE TUNNEL.'

```text
event 14 {
  @0x9882: AND area2.event_scratch0 = 4 & area1.event_word_21A
  @0x988B: IF <> <if compare flag is false, skip next op>
  @0x988C: EXIT
}
```

## Event 15

- Target: `0x98D7`
- Text hint: 'YOU HEAR RUNNING FOOTSTEPS DOWN THE TUNNEL AHEAD.'

```text
event 15 {
  @0x98D7: AND area2.event_scratch0 = 8 & area1.event_word_21A
  @0x98E0: IF <> <if compare flag is false, skip next op>
  @0x98E1: EXIT
}
```

## Event 16

- Target: `0x99AF`
- Text hint: 'YOU HEAR RUNNING FOOTSTEPS DOWN THE TUNNEL AHEAD.'

```text
event 16 {
  @0x99AF: AND area2.event_scratch0 = 1 & area1.event_word_21C
  @0x99B8: IF <> <if compare flag is false, skip next op>
  @0x99B9: EXIT
}
```

## Event 17

- Target: `0x99ED`
- Text hint: "YOU FIND THE GANG'S SUPPLIES." 'YOU ARE ATTACKED FROM BEHIND!' 'AUDIO CAPSULES ARE STORED HERE.'

```text
event 17 {
  @0x99ED: AND area2.event_scratch0 = 2 & area1.event_word_21C
  @0x99F6: IF <> <if compare flag is false, skip next op>
  @0x99F7: EXIT
}
```

## Event 18

- Target: `0x9A75`
- Text hint: "YOU FIND THE GANG'S SUPPLIES." 'YOU ARE ATTACKED FROM BEHIND!' 'AUDIO CAPSULES ARE STORED HERE.'

```text
event 18 {
  @0x9A75: AND area2.event_scratch0 = 2 & area1.event_word_21C
  @0x9A7E: IF = <if compare flag is false, skip next op>
  @0x9A7F: GOTO 0x9AC4
  // follows GOTO 0x9AC4
    @0x9AC4: PRINTCLEAR 'YOU ARE ATTACKED FROM BEHIND!'
    @0x9B0F: PRINTCLEAR 'AUDIO CAPSULES ARE STORED HERE.'
    @0x9B2A: EXIT
}
```

## Event 19

- Target: `0x9B0F`
- Text hint: 'AUDIO CAPSULES ARE STORED HERE.'

```text
event 19 {
  @0x9B0F: PRINTCLEAR 'AUDIO CAPSULES ARE STORED HERE.'
  @0x9B2A: EXIT
}
```

## Event 20

- Target: `0x9B2B`
- Text hint: 'A SMALL OFFICE.'

```text
event 20 {
  @0x9B2B: PRINTCLEAR 'A SMALL OFFICE.'
  @0x9B3A: AND area2.event_scratch0 = 16 & area1.event_word_314
  @0x9B43: IF = <if compare flag is false, skip next op>
  @0x9B44: EXIT
}
```

## Event 21

- Target: `0x9BAE`
- Text hint: 'A SMALL AUDIO PRODUCTION ROOM.'

```text
event 21 {
  @0x9BAE: COMPARE Values: mapDirection == 1
  @0x9BB4: IF <> <if compare flag is false, skip next op>
  @0x9BB5: EXIT
}
```

## Event 22

- Target: `0x9BD1`
- Text hint: "AS YOU ENTER, THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR FLICKERS OFF."

```text
event 22 {
  @0x9BD1: COMPARE Values: mapDirection == 1
  @0x9BD7: IF <> <if compare flag is false, skip next op>
  @0x9BD8: EXIT
}
```

## Event 23

- Target: `0x9C68`
- Text hint: 'YOU ENTER THE BROADCAST BOOTH. A DESERT RUNNER SITS AT THE CONTROLS. HE MOTIONS YOU TO SILENCE, FLICKS A SWITCH, AND SPEAKS INTO A MICROPHONE.'

```text
event 23 {
  @0x9C68: COMPARE Values: mapDirection == 1
  @0x9C6E: IF <> <if compare flag is false, skip next op>
  @0x9C6F: EXIT
}
```
