# GEO 34: Historical Museum, Levels 2-1

ECL block: `34`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 01 {
  @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
  @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 02

- Target: `0x8A5E`
- Text hint: 'A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.'

```text
event 02 {
  @0x8A5E: COMPARE Values: 10 == abs_C04E
  @0x8A64: IF <> <if compare flag is false, skip next op>
  @0x8A65: EXIT
}
```

## Event 03

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 03 {
  @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
  @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 04

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 04 {
  @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
  @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 05

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 05 {
  @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
  @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 06

- Target: `0x8C53`
- Text hint: 'A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.'

```text
event 06 {
  @0x8C53: PRINTCLEAR 'A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.'
  @0x8C8B: AND area2.event_scratch0 = 1 & area1.event_word_2C2
  @0x8C94: IF <> <if compare flag is false, skip next op>
  @0x8C95: GOTO 0x8EE2
  // follows GOTO 0x8EE2
    @0x8EE2: AND area2.event_scratch0 = 4 & area1.event_word_2C2
    @0x8EEB: IF <> <if compare flag is false, skip next op>
    @0x8EEC: GOTO 0x9851
    // follows GOTO 0x9851
      @0x9851: COMPARE Values: 0 == abs_C04E
      @0x9857: IF <> <if compare flag is false, skip next op>
      @0x9858: EXIT
}
```

## Event 07

- Target: `0x8C8B`
- Text hint: 'A BROOM CLOSET.' RETURN

```text
event 07 {
  @0x8C8B: AND area2.event_scratch0 = 1 & area1.event_word_2C2
  @0x8C94: IF <> <if compare flag is false, skip next op>
  @0x8C95: GOTO 0x8EE2
  // follows GOTO 0x8EE2
    @0x8EE2: AND area2.event_scratch0 = 4 & area1.event_word_2C2
    @0x8EEB: IF <> <if compare flag is false, skip next op>
    @0x8EEC: GOTO 0x9851
    // follows GOTO 0x9851
      @0x9851: COMPARE Values: 0 == abs_C04E
      @0x9857: IF <> <if compare flag is false, skip next op>
      @0x9858: EXIT
}
```

## Event 08

- Target: `0x8F11`
- Text hint: 'A DISPLAY OF FLORA AND FAUNA THAT WENT EXTINCT DURING THE 21ST CENTURY.'

```text
event 08 {
  @0x8F11: COMPARE Values: 2 == mapDirection
  @0x8F17: IF <> <if compare flag is false, skip next op>
  @0x8F18: EXIT
}
```

## Event 09

- Target: `0x8F53`
- Text hint: 'CALIFORNIA CONDOR.'

```text
event 09 {
  @0x8F53: GOSUB 0xA15E
  @0x8F57: PRINT 'CALIFORNIA CONDOR.'
  @0x8F68: EXIT
}
```

## Event 10

- Target: `0x8F69`
- Text hint: 'BLACK RHINO.'

```text
event 10 {
  @0x8F69: GOSUB 0xA15E
  @0x8F6D: PRINT 'BLACK RHINO.'
  @0x8F79: EXIT
}
```

## Event 11

- Target: `0x8F7A`
- Text hint: 'POODLE.'

```text
event 11 {
  @0x8F7A: GOSUB 0xA15E
  @0x8F7E: PRINT 'POODLE.'
  @0x8F87: EXIT
}
```

## Event 12

- Target: `0x8F88`
- Text hint: 'MOCKINGBIRD.'

```text
event 12 {
  @0x8F88: GOSUB 0xA15E
  @0x8F8C: PRINT 'MOCKINGBIRD.'
  @0x8F98: EXIT
}
```

## Event 13

- Target: `0x8F99`
- Text hint: 'GORILLA.'

```text
event 13 {
  @0x8F99: GOSUB 0xA15E
  @0x8F9D: PRINT 'GORILLA.'
  @0x8FA6: EXIT
}
```

## Event 14

- Target: `0x8FA7`
- Text hint: 'THIS ROOM IS A SATURN 1ST-STAGE BOOSTER. ITS CONTENTS DEPICT THE SPACE PROGRAM.'

```text
event 14 {
  @0x8FA7: COMPARE Values: 3 == mapDirection
  @0x8FAD: IF <> <if compare flag is false, skip next op>
  @0x8FAE: EXIT
}
```

## Event 15

- Target: `0x8FEF`
- Text hint: 'SPACESUIT WORN BY ARMSTRONG.'

```text
event 15 {
  @0x8FEF: GOSUB 0xA16E
  @0x8FF3: PRINT 'SPACESUIT WORN BY ARMSTRONG.'
  @0x900B: EXIT
}
```

## Event 16

- Target: `0x900C`
- Text hint: 'HELMET WORN BY COSMONAUT YURI GAGARIN.'

```text
event 16 {
  @0x900C: GOSUB 0xA16E
  @0x9010: PRINT 'HELMET WORN BY COSMONAUT YURI GAGARIN.'
  @0x9030: EXIT
}
```

## Event 17

- Target: `0x9031`
- Text hint: 'WARPED MIRROR OF THE HUBBLE TELESCOPE.'

```text
event 17 {
  @0x9031: GOSUB 0xA16E
  @0x9035: PRINT 'WARPED MIRROR OF THE HUBBLE TELESCOPE.'
  @0x9055: EXIT
}
```

## Event 18

- Target: `0x9056`
- Text hint: 'MODEL ICBM.'

```text
event 18 {
  @0x9056: GOSUB 0xA15E
  @0x905A: PRINT 'MODEL ICBM.'
  @0x9066: EXIT
}
```

## Event 19

- Target: `0x9067`
- Text hint: 'THE HISTORY OF WAR IS DEPICTED IN THIS ROOM.'

```text
event 19 {
  @0x9067: COMPARE Values: 1 == mapDirection
  @0x906D: IF <> <if compare flag is false, skip next op>
  @0x906E: EXIT
}
```

## Event 20

- Target: `0x9094`
- Text hint: "A MODEL OF MASTERLINK IS MOUNTED ON THE WALL, AND BELOW IT, AN EPITAPH TO LT. COL. ANTHONY 'BUCK' ROGERS, WHO DIED ON HIS MISSION TO DESTROY THE WEAPON."

```text
event 20 {
  @0x9094: PRINTCLEAR "A MODEL OF MASTERLINK IS MOUNTED ON THE WALL, AND BELOW IT, AN EPITAPH TO LT. COL. ANTHONY 'BUCK' ROGERS, WHO DIED ON HIS MISSION TO DESTROY THE WEAPON."
  @0x9109: EXIT
}
```

## Event 21

- Target: `0x910A`
- Text hint: "A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT."

```text
event 21 {
  @0x910A: EXIT
}
```

## Event 22

- Target: `0x910B`
- Text hint: "A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT."

```text
event 22 {
  @0x910B: PRINTCLEAR "A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT."
  @0x9168: EXIT
}
```

## Event 23

- Target: `0x9169`
- Text hint: 'A BUST OF NAPOLEON - KILLING EN MASSE BECOMES ALL THE RAGE.'

```text
event 23 {
  @0x9169: PRINTCLEAR 'A BUST OF NAPOLEON - KILLING EN MASSE BECOMES ALL THE RAGE.'
  @0x9199: EXIT
}
```

## Event 24

- Target: `0x919A`
- Text hint: 'THIS ROOM IS DEDICATED TO THE RISE OF MODERN CIVILIZATION.'

```text
event 24 {
  @0x919A: COMPARE Values: 2 == mapDirection
  @0x91A0: IF <> <if compare flag is false, skip next op>
  @0x91A1: EXIT
}
```

## Event 25

- Target: `0x91D2`
- Text hint: 'STEAM POWERED LOOM, HERALDING THE BIRTH OF THE WORK FORCE.'

```text
event 25 {
  @0x91D2: GOSUB 0xA15E
  @0x91D6: PRINT 'STEAM POWERED LOOM, HERALDING THE BIRTH OF THE WORK FORCE.'
  @0x9205: EXIT
}
```

## Event 26

- Target: `0x9206`
- Text hint: "MONEY OF ALL KINDS, FROM DOUBLOONS TO CREDIT CARDS, ARE IN A CASE. THE CAPTION READS, 'THE JONESES MOVE IN.'"

```text
event 26 {
  @0x9206: PRINTCLEAR "MONEY OF ALL KINDS, FROM DOUBLOONS TO CREDIT CARDS, ARE IN A CASE. THE CAPTION READS, 'THE JONESES MOVE IN.'"
  @0x925A: EXIT
}
```

## Event 27

- Target: `0x925B`
- Text hint: 'PRINTING PRESS, ENABLING THE STANDARDIZATION OF KNOWLEDGE AND FREING HUMANITY FROM THE NEED TO REMEMBER.'

```text
event 27 {
  @0x925B: GOSUB 0xA16E
  @0x925F: PRINT 'PRINTING PRESS, ENABLING THE STANDARDIZATION OF KNOWLEDGE AND FREING HUMANITY FROM THE NEED TO REMEMBER.'
  @0x92B0: EXIT
}
```

## Event 28

- Target: `0x92B1`
- Text hint: 'A MOVIE THEATER.' RETURN

```text
event 28 {
  @0x92B1: COMPARE Values: 2 == mapDirection
  @0x92B7: IF <> <if compare flag is false, skip next op>
  @0x92B8: EXIT
}
```

## Event 29

- Target: `0x94A4`
- Text hint: 'A LARGE DNA HELIX MODELED WITH STICKS AND COLORED BALLS. '

```text
event 29 {
  @0x94A4: COMPARE Values: 0 == mapDirection
  @0x94AA: IF <> <if compare flag is false, skip next op>
  @0x94AB: EXIT
}
```

## Event 30

- Target: `0x95C7`
- Text hint: 'A HUGE COMPUTER CALLED ENIAC FILLS THE ROOM.'

```text
event 30 {
  @0x95C7: COMPARE Values: 0 == area1.event_word_21A
  @0x95CD: IF <> <if compare flag is false, skip next op>
  @0x95CE: EXIT
}
```

## Event 31

- Target: `0x9851`
- Text hint: 'A BROOM CLOSET.'

```text
event 31 {
  @0x9851: COMPARE Values: 0 == abs_C04E
  @0x9857: IF <> <if compare flag is false, skip next op>
  @0x9858: EXIT
}
```

## Event 32

- Target: `0x9869`
- Text hint: 'THE WARRIORS ARE QUESTIONING STEFI MERCILESSLY. '

```text
event 32 {
  @0x9869: AND area2.event_scratch0 = 32 & area1.event_word_2C0
  @0x9872: IF <> <if compare flag is false, skip next op>
  @0x9873: EXIT
}
```

## Event 33

- Target: `0x9AFB`
- Text hint: 'THE SECRET DOOR THAT CHADE TOLD YOU ABOUT STANDS AJAR. '

```text
event 33 {
  @0x9AFB: AND area2.event_scratch0 = 32 & area1.event_word_2C0
  @0x9B04: IF = <if compare flag is false, skip next op>
  @0x9B05: EXIT
}
```

## Event 34

- Target: `0x9B4B`
- Text hint: 'A GIFT SHOP.'

```text
event 34 {
  @0x9B4B: COMPARE Values: 10 == abs_C04E
  @0x9B51: IF <> <if compare flag is false, skip next op>
  @0x9B52: GOTO 0x85F6
  // follows GOTO 0x85F6
    @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
    @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 35

- Target: `0x9E5E`
- Text hint: 'A GIFT SHOP.'

```text
event 35 {
  @0x9E5E: AND area2.event_scratch0 = 15 & area1.event_word_2C4
  @0x9E67: IF = <if compare flag is false, skip next op>
  @0x9E68: GOTO 0x85F6
  // follows GOTO 0x85F6
    @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
    @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 36

- Target: `0x9EB6`
- Text hint: 'A GIFT SHOP.'

```text
event 36 {
  @0x9EB6: PRINTCLEAR 'A GIFT SHOP.'
  @0x9EC2: AND area2.event_scratch0 = 8 & area1.event_word_2C2
  @0x9ECB: IF <> <if compare flag is false, skip next op>
  @0x9ECC: EXIT
}
```

## Event 37

- Target: `0x9F55`
- Text hint: 'EXPLOSIVES OF ALL KINDS, ALL THE BETTER TO KILL YOU WITH.'

```text
event 37 {
  @0x9F55: PRINTCLEAR 'EXPLOSIVES OF ALL KINDS, ALL THE BETTER TO KILL YOU WITH.'
  @0x9FB8: AND area2.event_scratch0 = 128 & area1.event_word_2CA
  @0x9FC1: IF = <if compare flag is false, skip next op>
  @0x9FC2: GOTO 0x85F6
  // follows GOTO 0x85F6
    @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
    @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```

## Event 38

- Target: `0x9FB8`
- Text hint: 'AN EXHIBIT OF A '

```text
event 38 {
  @0x9FB8: AND area2.event_scratch0 = 128 & area1.event_word_2CA
  @0x9FC1: IF = <if compare flag is false, skip next op>
  @0x9FC2: GOTO 0x85F6
  // follows GOTO 0x85F6
    @0x85F6: ADD area1.event_word_218 = 1 + area1.event_word_218
    @0x85FF: ON GOTO area1.event_word_20E of [0x860E, 0x88B3, 0x898C]
}
```
