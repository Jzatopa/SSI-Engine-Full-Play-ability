# GEO 49: Lowlander Village

ECL block: `49`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x8B33`
- Text hint: 'THERE IS A DOWN ELEVATOR HERE. DO YOU USE IT?'

```text
event 01 {
  @0x8B33: COMPARE Values: area1.event_word_2EE == 1
  @0x8B39: IF = <if compare flag is false, skip next op>
  @0x8B3A: GOTO 0x8B8E
  // follows GOTO 0x8B8E
    @0x8B8E: COMPARE Values: mapDirection == 3
    @0x8B94: IF <> <if compare flag is false, skip next op>
    @0x8B95: EXIT
}
```

## Event 05

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 05 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 06

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 06 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 07

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 07 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 08

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 08 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 09

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 09 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 10

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 10 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 11

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 11 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 12

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 12 {
  @0x8D4C: SUBTRACT area2.event_scratch1 = area2.event_scratch1 - 5
  @0x8D55: GETTABLE area1.event_word_20A = abs_A370[area2.event_scratch1]
  @0x8D5F: GETTABLE area1.event_word_206 = abs_A378[area2.event_scratch1]
  @0x8D69: COMPARE Values: mapDirection == area1.event_word_20A
  @0x8D70: IF <> <if compare flag is false, skip next op>
  @0x8D71: EXIT
}
```

## Event 13

- Target: `0x9020`
- Text hint: 'THE WOODEN WALLS HERE ARE MADE OF MILLED WOOD. THE AREA IS FREE OF PRIMITIVE TRAPPINGS.'

```text
event 13 {
  @0x9020: COMPARE Values: mapDirection == 3
  @0x9026: IF <> <if compare flag is false, skip next op>
  @0x9027: EXIT
}
```

## Event 14

- Target: `0x9082`
- Text hint: 'VENUSIAN DINOSAUR HIDE SHIELDS.'

```text
event 14 {
  @0x9082: COMPARE Values: mapDirection == 2
  @0x9088: IF <> <if compare flag is false, skip next op>
  @0x9089: EXIT
}
```

## Event 15

- Target: `0x90AB`
- Text hint: 'CRYSTAL TIPPED SPEARS.'

```text
event 15 {
  @0x90AB: COMPARE Values: mapDirection == 3
  @0x90B1: IF <> <if compare flag is false, skip next op>
  @0x90B2: EXIT
}
```

## Event 16

- Target: `0x90CD`
- Text hint: 'WOVEN PLANT FIBER HUT WALLS.' 'THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING '

```text
event 16 {
  @0x90CD: COMPARE Values: mapDirection == 1
  @0x90D3: IF <> <if compare flag is false, skip next op>
  @0x90D4: EXIT
}
```

## Event 17

- Target: `0x9145`
- Text hint: 'YOU ENTER A SMALL WAREHOUSE. BUNDLES OF SPEARS, SHIELDS AND HUT WALL SECTIONS ARE STORED HERE, READY FOR SHIPPING.'

```text
event 17 {
  @0x9145: COMPARE Values: mapDirection == 1
  @0x914B: IF <> <if compare flag is false, skip next op>
  @0x914C: EXIT
}
```

## Event 18

- Target: `0x91A8`
- Text hint: 'THESE ROOMS ARE FULL OF LOCKERS. MOST CONTAIN LOWLANDER NATIVE GARB. A FEW HOLD MACHINE-WOVEN OVERALLS, TOUGH PLASTIC BOOTS, AND HARD HATS WITH MINING LAMPS.'

```text
event 18 {
  @0x91A8: AND area2.event_scratch0 = 16 & area1.event_word_2E4
  @0x91B1: IF <> <if compare flag is false, skip next op>
  @0x91B2: EXIT
}
```

## Event 19

- Target: `0x9237`
- Text hint: "A SIGN READS, 'HEAVY ELEVATOR.' THERE ARE NO CONTROLS HERE."

```text
event 19 {
  @0x9237: COMPARE Values: mapDirection == 0
  @0x923D: IF <> <if compare flag is false, skip next op>
  @0x923E: EXIT
}
```

## Event 20

- Target: `0x9271`
- Text hint: 'A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.'

```text
event 20 {
  @0x9271: COMPARE Values: mapDirection == 0
  @0x9277: IF <> <if compare flag is false, skip next op>
  @0x9278: EXIT
}
```

## Event 21

- Target: `0x92D5`
- Text hint: "THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND."

```text
event 21 {
  @0x92D5: COMPARE Values: mapDirection == 0
  @0x92DB: IF <> <if compare flag is false, skip next op>
  @0x92DC: EXIT
}
```

## Event 22

- Target: `0x932C`
- Text hint: 'HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.'

```text
event 22 {
  @0x932C: COMPARE Values: mapDirection == 0
  @0x9332: IF <> <if compare flag is false, skip next op>
  @0x9333: EXIT
}
```

## Event 23

- Target: `0x9365`
- Text hint: 'THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:' RETURN

```text
event 23 {
  @0x9365: AND area2.event_scratch0 = 32 & area1.event_word_2E4
  @0x936E: IF <> <if compare flag is false, skip next op>
  @0x936F: EXIT
}
```

## Event 24

- Target: `0x93E4`
- Text hint: 'LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.'

```text
event 24 {
  @0x93E4: COMPARE Values: mapDirection == 2
  @0x93EA: IF <> <if compare flag is false, skip next op>
  @0x93EB: EXIT
}
```
