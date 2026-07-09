# GEO 52: Lowlander Mines

ECL block: `49`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 02

- Target: `0x8C7F`
- Text hint: 'AN ELEVATOR UP. DO YOU GO?'

```text
event 02 {
  @0x8C7F: COMPARE Values: mapDirection == 2
  @0x8C85: IF <> <if compare flag is false, skip next op>
  @0x8C86: EXIT
}
```

## Event 03

- Target: `0x8CCB`
- Text hint: 'THE BLOODY TRAIL LEADS DOWN THE TUNNEL TO THE NORTH.'

```text
event 03 {
  @0x8CCB: AND area2.event_scratch0 = 64 & area1.event_word_2E6
  @0x8CD4: IF <> <if compare flag is false, skip next op>
  @0x8CD5: EXIT
}
```

## Event 04

- Target: `0x8D0B`
- Text hint: 'TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.'

```text
event 04 {
  @0x8D0B: AND area2.event_scratch0 = 2 & area1.event_word_2E8
  @0x8D14: IF = <if compare flag is false, skip next op>
  @0x8D15: EXIT
}
```

## Event 25

- Target: `0x9432`
- Text hint: '<string at area2.selected_player_name>' ' SEES A NEWLY WIRED COMMUNICATIONS CABLE RUNNING ALONG THE WEST WALL.' 'EAST'

```text
event 25 {
  @0x9432: AND area2.event_scratch0 = 64 & area1.event_word_2E4
  @0x943B: IF <> <if compare flag is false, skip next op>
  @0x943C: EXIT
}
```

## Event 26

- Target: `0x949E`
- Text hint: 'EAST' 'NORTH' 'NORTHERN'

```text
event 26 {
  @0x949E: GOSUB 0x9646
  @0x94A2: PRINT 'EAST'
  @0x94A8: GOSUB 0x9663
  @0x94AC: PRINT 'NORTH'
  @0x94B3: GOSUB 0x9678
  @0x94B7: PRINT 'NORTHERN'
  @0x94C0: GOSUB 0x968A
  @0x94C4: PRINT '   - CITYWARD -'
  @0x94D3: PRINT RETURN
}
```

## Event 27

- Target: `0x952E`
- Text hint: 'PARTS FOR A GIANT VENTILATOR FAN ARE HERE.'

```text
event 27 {
  @0x952E: PRINTCLEAR 'PARTS FOR A GIANT VENTILATOR FAN ARE HERE.'
  @0x9553: AND area2.event_scratch0 = 2 & area1.event_word_2E6
  @0x955C: IF <> <if compare flag is false, skip next op>
  @0x955D: EXIT
}
```

## Event 28

- Target: `0x9553`
- Text hint: 'NORTH' 'EAST' 'EASTERN'

```text
event 28 {
  @0x9553: AND area2.event_scratch0 = 2 & area1.event_word_2E6
  @0x955C: IF <> <if compare flag is false, skip next op>
  @0x955D: EXIT
}
```

## Event 29

- Target: `0x95FC`
- Text hint: 'NORTH' 'EAST' 'EASTERN'

```text
event 29 {
  @0x95FC: GOSUB 0x9646
  @0x9600: PRINT 'NORTH'
  @0x9607: GOSUB 0x9663
  @0x960B: PRINT 'EAST'
  @0x9611: GOSUB 0x9678
  @0x9615: PRINT 'EASTERN'
  @0x961E: GOSUB 0x968A
  @0x9622: PRINT '   - CITYWARD -'
  @0x9631: PRINT RETURN
}
```

## Event 30

- Target: `0x969A`
- Text hint: 'YOU COME ACROSS SOME LOWLANDER MINERS. WITH THEIR BACKS TO YOU, THEY ARE STUDYING THE SOUTH WALL.'

```text
event 30 {
  @0x969A: AND area2.event_scratch0 = 4 & area1.event_word_2E6
  @0x96A3: IF <> <if compare flag is false, skip next op>
  @0x96A4: EXIT
}
```

## Event 31

- Target: `0x986B`
- Text hint: 'URSADDERS AMBUSH YOU!'

```text
event 31 {
  @0x986B: AND area2.event_scratch0 = 8 & area1.event_word_2E6
  @0x9874: IF <> <if compare flag is false, skip next op>
  @0x9875: EXIT
}
```

## Event 32

- Target: `0x899B`
- Text hint: "'INTRUDER ALERT! TO ARMSS! TO ARMSS!'" "A SPEAKER NEAR YOU CRACKLES INTO LIFE. SCOT.DOS' VOICE ISSUES FORTH." "'TRACKING INTRUDERSS! QUADRANT 4 PERIMETER ALARM TRIPPED!'"

```text
event 32 {
  @0x899B: AND area2.event_scratch0 = 8 & area1.event_word_2E6
  @0x89A4: IF = <if compare flag is false, skip next op>
  @0x89A5: EXIT
}
```

## Event 33

- Target: `0x9943`
- Text hint: 'URSADDERS AMBUSH YOU!'

```text
event 33 {
  @0x9943: AND area2.event_scratch0 = 16 & area1.event_word_2E6
  @0x994C: IF <> <if compare flag is false, skip next op>
  @0x994D: EXIT
}
```

## Event 34

- Target: `0xA0D0`
- Text hint: 'URSADDERS AMBUSH YOU!'

```text
event 34 {
  @0xA0D0: AND area2.event_scratch0 = 128 & area1.event_word_2E6
  @0xA0D9: IF <> <if compare flag is false, skip next op>
  @0xA0DA: EXIT
}
```

## Event 35

- Target: `0xA129`
- Text hint: 'LLOROK LIES HERE NEAR DEATH. HE NEEDS THE ATTENTION OF A LOWLANDER MEDIC. DO YOU BRING HIM WITH YOU?'

```text
event 35 {
  @0xA129: AND area2.event_scratch0 = 1 & area1.event_word_2E8
  @0xA132: IF <> <if compare flag is false, skip next op>
  @0xA133: GOTO 0xA1B2
  // follows GOTO 0xA1B2
    @0xA1B2: COMPARE Values: area1.event_word_2F2 == 1
    @0xA1B8: IF = <if compare flag is false, skip next op>
    @0xA1B9: EXIT
}
```

## Event 36

- Target: `0xA23E`
- Text hint: 'NORTH' 'SOUTH AND WEST' 'SOUTHERN'

```text
event 36 {
  @0xA23E: COMPARE Values: area1.event_word_2F4 == 3
  @0xA244: IF <= <if compare flag is false, skip next op>
  @0xA245: EXIT
}
```

## Event 37

- Target: `0xA27D`
- Text hint: 'NORTH' 'SOUTH AND WEST' 'SOUTHERN'

```text
event 37 {
  @0xA27D: RANDOM area2.event_scratch0 = random 1..99
  @0xA283: COMPARE Values: area2.event_scratch0 == 15
  @0xA289: IF < <if compare flag is false, skip next op>
  @0xA28A: EXIT
}
```

## Event 38

- Target: `0xA2ED`
- Text hint: 'NORTH' 'SOUTH AND WEST' 'SOUTHERN'

```text
event 38 {
  @0xA2ED: GOSUB 0x9646
  @0xA2F1: PRINT 'NORTH'
  @0xA2F8: GOSUB 0x9663
  @0xA2FC: PRINT 'SOUTH AND WEST'
  @0xA30A: GOSUB 0x9678
  @0xA30E: PRINT 'SOUTHERN'
  @0xA317: GOSUB 0x968A
  @0xA31B: PRINT '   - SURFACE-WARD -'
  @0xA32D: PRINT RETURN
}
```
