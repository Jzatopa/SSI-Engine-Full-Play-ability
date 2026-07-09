# GEO 51: Venus Laboratory, Level 2

ECL block: `50`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 03

- Target: `0x8409`
- Text hint: 'YOU FIND AN UP ELEVATOR. DO YOU USE IT?'

```text
event 03 {
  @0x8409: COMPARE Values: mapDirection == 1
  @0x840F: IF <> <if compare flag is false, skip next op>
  @0x8410: EXIT
}
```

## Event 25

- Target: `0x8EF2`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 25 {
  @0x8EF2: AND area2.event_scratch0 = 64 & area1.event_word_2FE
  @0x8EFB: IF <> <if compare flag is false, skip next op>
  @0x8EFC: EXIT
}
```

## Event 26

- Target: `0x916F`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 26 {
  @0x916F: AND area2.event_scratch0 = 128 & area1.event_word_2FE
  @0x9178: IF <> <if compare flag is false, skip next op>
  @0x9179: EXIT
}
```

## Event 27

- Target: `0x9234`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 27 {
  @0x9234: AND area2.event_scratch0 = 1 & area1.event_word_306
  @0x923D: IF <> <if compare flag is false, skip next op>
  @0x923E: EXIT
}
```

## Event 28

- Target: `0x9340`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 28 {
  @0x9340: AND area2.event_scratch0 = 2 & area1.event_word_306
  @0x9349: IF <> <if compare flag is false, skip next op>
  @0x934A: EXIT
}
```

## Event 29

- Target: `0x94BF`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 29 {
  @0x94BF: AND area2.event_scratch0 = 4 & area1.event_word_306
  @0x94C8: IF <> <if compare flag is false, skip next op>
  @0x94C9: EXIT
}
```

## Event 30

- Target: `0x966B`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 30 {
  @0x966B: COMPARE Values: mapDirection == 1
  @0x9671: IF <> <if compare flag is false, skip next op>
  @0x9672: EXIT
}
```

## Event 31

- Target: `0x9677`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 31 {
  @0x9677: COMPARE Values: mapDirection == 2
  @0x967D: IF <> <if compare flag is false, skip next op>
  @0x967E: EXIT
}
```

## Event 32

- Target: `0x9683`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 32 {
  @0x9683: COMPARE Values: mapDirection == 3
  @0x9689: IF <> <if compare flag is false, skip next op>
  @0x968A: EXIT
}
```

## Event 33

- Target: `0x96B2`
- Text hint: 'YOU LEAVE THE GRAVITOL FACTORY.'

```text
event 33 {
  @0x96B2: COMPARE Values: mapDirection == 0
  @0x96B8: IF <> <if compare flag is false, skip next op>
  @0x96B9: EXIT
}
```

## Event 34

- Target: `0x96BE`
- Text hint: 'YOU LEAVE THE GRAVITOL FACTORY.'

```text
event 34 {
  @0x96BE: COMPARE Values: mapDirection == 3
  @0x96C4: IF <> <if compare flag is false, skip next op>
  @0x96C5: EXIT
}
```

## Event 35

- Target: `0x96E2`
- Text hint: 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'

```text
event 35 {
  @0x96E2: COMPARE Values: mapDirection == 0
  @0x96E8: IF <> <if compare flag is false, skip next op>
  @0x96E9: EXIT
}
```

## Event 36

- Target: `0x96EE`
- Text hint: 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'

```text
event 36 {
  @0x96EE: COMPARE Values: mapDirection == 1
  @0x96F4: IF <> <if compare flag is false, skip next op>
  @0x96F5: EXIT
}
```

## Event 37

- Target: `0x96FA`
- Text hint: 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'

```text
event 37 {
  @0x96FA: COMPARE Values: mapDirection == 2
  @0x9700: IF <> <if compare flag is false, skip next op>
  @0x9701: EXIT
}
```

## Event 38

- Target: `0x972D`
- Text hint: 'YOU ENTER A ROOM FULL OF MEDICINAL PROCESSING EQUIPMENT. ' ' SOLDIERS AIM THEIR GUNS AT LOWLANDERS LINED UP AGAINST THE WALL. '

```text
event 38 {
  @0x972D: COMPARE Values: area1.event_word_208 == 1
  @0x9733: IF = <if compare flag is false, skip next op>
  @0x9734: GOTO 0x9A35
  // follows GOTO 0x9A35
    @0x9A35: AND area2.event_scratch0 = 16 & area1.event_word_306
    @0x9A3E: IF <> <if compare flag is false, skip next op>
    @0x9A3F: EXIT
}
```

## Event 39

- Target: `0x9A9C`
- Text hint: "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"

```text
event 39 {
  @0x9A9C: AND area2.event_scratch0 = 32 & area1.event_word_306
  @0x9AA5: IF <> <if compare flag is false, skip next op>
  @0x9AA6: EXIT
}
```

## Event 40

- Target: `0x9E2C`
- Text hint: "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"

```text
event 40 {
  @0x9E2C: COMPARE Values: area1.event_word_2FC == 1
  @0x9E32: IF = <if compare flag is false, skip next op>
  @0x9E33: EXIT
}
```

## Event 41

- Target: `0xA130`
- Text hint: "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"

```text
event 41 {
  @0xA130: COMPARE Values: area1.event_word_2FC == 1
  @0xA136: IF <> <if compare flag is false, skip next op>
  @0xA137: EXIT
}
```

## Event 42

- Target: `0xA19C`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 42 {
  @0xA19C: SAVE area2.event_scratch3 = 4
  @0xA1A2: GOTO 0xA1F8
  // follows GOTO 0xA1F8
    @0xA1F8: COMPARE Values: area1.event_word_2FC == 1
    @0xA1FE: IF <> <if compare flag is false, skip next op>
    @0xA1FF: EXIT
}
```

## Event 43

- Target: `0xA1A6`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 43 {
  @0xA1A6: SAVE area2.event_scratch3 = 8
  @0xA1AC: GOTO 0xA1F8
  // follows GOTO 0xA1F8
    @0xA1F8: COMPARE Values: area1.event_word_2FC == 1
    @0xA1FE: IF <> <if compare flag is false, skip next op>
    @0xA1FF: EXIT
}
```

## Event 44

- Target: `0xA1B0`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 44 {
  @0xA1B0: SAVE area2.event_scratch3 = 16
  @0xA1B6: GOTO 0xA1F8
  // follows GOTO 0xA1F8
    @0xA1F8: COMPARE Values: area1.event_word_2FC == 1
    @0xA1FE: IF <> <if compare flag is false, skip next op>
    @0xA1FF: EXIT
}
```

## Event 45

- Target: `0xA1BA`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 45 {
  @0xA1BA: COMPARE Values: area1.event_word_2FC == 1
  @0xA1C0: IF <> <if compare flag is false, skip next op>
  @0xA1C1: EXIT
}
```
