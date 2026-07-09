# GEO 51: Venus Laboratory, Level 2

ECL block: `50`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 03

- Target: `0x8409`
- Text hint: 'YOU FIND AN UP ELEVATOR. DO YOU USE IT?'

```text
event 03 {
  // 0x8409-0x840F
  if (mapDirection != 1) {
    exit_event();  // 0x8410
  }
  printclear('YOU FIND AN UP ELEVATOR. DO YOU USE IT?');  // 0x8411
  // 0x844F-0x8458
  area2.event_scratch0 = 1 & area1.event_word_2FE;  // 0x844F
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8459
  }
  picture(block_id: 82);  // 0x845A
  printclear('ENTERING THE LAB COMPLEX, YOU FIND THE SOURCE OF THE EARTHQUAKE. AN EXPLOSION LARGE ENOUGH TO BLOW AWAY THE ROOF HAS EXPOSED THE VENUSIAN SKY.');  // 0x845D
  // 0x84D6-0x84DC
  if (mapDirection != 1) {
    exit_event();  // 0x84DD
  }
  printclear('THE BODIES OF ');  // 0x84DE
  gosub 0xA3A8;  // 0x84EC
  print(' SOLDIERS LIE HERE. THEY APPEAR TO HAVE BEEN CRUSHED BY ENORMOUS WEIGHTS.');  // 0x84F0
  // 0x852C-0x8532
  if (mapDirection != 0) {
    exit_event();  // 0x8533
  }
  goto 0x84DE;  // 0x8534
  // branch body 0x84DE
    printclear('THE BODIES OF ');  // 0x84DE
    gosub 0xA3A8;  // 0x84EC
    print(' SOLDIERS LIE HERE. THEY APPEAR TO HAVE BEEN CRUSHED BY ENORMOUS WEIGHTS.');  // 0x84F0
    // 0x852C-0x8532
    if (mapDirection != 0) {
      exit_event();  // 0x8533
    }
    goto 0x84DE;  // 0x8534
    // branch body 0x84DE
      // target 0x84DE already emitted
}
```

## Event 25

- Target: `0x8EF2`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 25 {
  // 0x8EF2-0x8EFB
  area2.event_scratch0 = 64 & area1.event_word_2FE;  // 0x8EF2
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8EFC
  }
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x8EFD
  exit_event();  // 0x8F04
}
```

## Event 26

- Target: `0x916F`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 26 {
  // 0x916F-0x9178
  area2.event_scratch0 = 128 & area1.event_word_2FE;  // 0x916F
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9179
  }
  setup_monster(sprite_id: 5 max_distance: 2 pic_id: 255);  // 0x917A
  exit_event();  // 0x9181
}
```

## Event 27

- Target: `0x9234`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 27 {
  // 0x9234-0x923D
  area2.event_scratch0 = 1 & area1.event_word_306;  // 0x9234
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x923E
  }
  // 0x923F-0x9245
  if (area1.event_word_2FC == 1) {
    exit_event();  // 0x9246
  }
  setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x9247
  exit_event();  // 0x924E
}
```

## Event 28

- Target: `0x9340`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 28 {
  // 0x9340-0x9349
  area2.event_scratch0 = 2 & area1.event_word_306;  // 0x9340
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x934A
  }
  or(area1.event_word_306 = 2 | area1.event_word_306);  // 0x934B
  exit_event();  // 0x9355
}
```

## Event 29

- Target: `0x94BF`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 29 {
  // 0x94BF-0x94C8
  area2.event_scratch0 = 4 & area1.event_word_306;  // 0x94BF
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x94C9
  }
  // 0x94CA-0x94D0
  if (area1.event_word_2FC == 1) {
    goto 0x9657;  // 0x94D1
    // branch body 0x9657
    area2.event_scratch3 = 2;  // 0x9657
    goto 0xA1F8;  // 0x965D
    // branch body 0xA1F8
      // 0xA1F8-0xA1FE
      if (area1.event_word_2FC != 1) {
        exit_event();  // 0xA1FF
      }
      // 0xA200-0xA20A
      area2.event_scratch0 = area2.event_scratch3 & area1.event_word_308;  // 0xA200
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA20B
      }
      printclear('YOU RUN INTO A MERCURIAN PATROL!');  // 0xA20C
      setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0xA227
      exit_event();  // 0xA22E
  }
  setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x94D5
  exit_event();  // 0x94DC
}
```

## Event 30

- Target: `0x966B`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 30 {
  // 0x966B-0x9671
  if (mapDirection != 1) {
    exit_event();  // 0x9672
  }
  goto 0x968B;  // 0x9673
  // branch body 0x968B
    printclear('VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.');  // 0x968B
    exit_event();  // 0x96B1
}
```

## Event 31

- Target: `0x9677`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 31 {
  // 0x9677-0x967D
  if (mapDirection != 2) {
    exit_event();  // 0x967E
  }
  goto 0x968B;  // 0x967F
  // branch body 0x968B
    printclear('VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.');  // 0x968B
    exit_event();  // 0x96B1
}
```

## Event 32

- Target: `0x9683`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 32 {
  // 0x9683-0x9689
  if (mapDirection != 3) {
    exit_event();  // 0x968A
  }
  printclear('VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.');  // 0x968B
  exit_event();  // 0x96B1
}
```

## Event 33

- Target: `0x96B2`
- Text hint: 'YOU LEAVE THE GRAVITOL FACTORY.'

```text
event 33 {
  // 0x96B2-0x96B8
  if (mapDirection != 0) {
    exit_event();  // 0x96B9
  }
  goto 0x96C6;  // 0x96BA
  // branch body 0x96C6
    printclear('YOU LEAVE THE GRAVITOL FACTORY.');  // 0x96C6
    exit_event();  // 0x96E1
}
```

## Event 34

- Target: `0x96BE`
- Text hint: 'YOU LEAVE THE GRAVITOL FACTORY.'

```text
event 34 {
  // 0x96BE-0x96C4
  if (mapDirection != 3) {
    exit_event();  // 0x96C5
  }
  printclear('YOU LEAVE THE GRAVITOL FACTORY.');  // 0x96C6
  exit_event();  // 0x96E1
}
```

## Event 35

- Target: `0x96E2`
- Text hint: 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'

```text
event 35 {
  // 0x96E2-0x96E8
  if (mapDirection != 0) {
    exit_event();  // 0x96E9
  }
  goto 0x9702;  // 0x96EA
  // branch body 0x9702
    printclear('MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.');  // 0x9702
    exit_event();  // 0x972C
}
```

## Event 36

- Target: `0x96EE`
- Text hint: 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'

```text
event 36 {
  // 0x96EE-0x96F4
  if (mapDirection != 1) {
    exit_event();  // 0x96F5
  }
  goto 0x9702;  // 0x96F6
  // branch body 0x9702
    printclear('MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.');  // 0x9702
    exit_event();  // 0x972C
}
```

## Event 37

- Target: `0x96FA`
- Text hint: 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'

```text
event 37 {
  // 0x96FA-0x9700
  if (mapDirection != 2) {
    exit_event();  // 0x9701
  }
  printclear('MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.');  // 0x9702
  exit_event();  // 0x972C
}
```

## Event 38

- Target: `0x972D`
- Text hint: 'YOU ENTER A ROOM FULL OF MEDICINAL PROCESSING EQUIPMENT. ' ' SOLDIERS AIM THEIR GUNS AT LOWLANDERS LINED UP AGAINST THE WALL. '

```text
event 38 {
  // 0x972D-0x9733
  if (area1.event_word_208 == 1) {
    goto 0x9A35;  // 0x9734
    // branch body 0x9A35
    // 0x9A35-0x9A3E
    area2.event_scratch0 = 16 & area1.event_word_306;  // 0x9A35
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9A3F
    }
    printclear('CRUMPLED AGAINST THE WALL LIE THE BODIES OF LOWLANDER TECHNICIANS. THEY HAVE BEEN SHOT THROUGH THE HEAD.');  // 0x9A40
    // 0x9A9C-0x9AA5
    area2.event_scratch0 = 32 & area1.event_word_306;  // 0x9A9C
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9AA6
    }
    setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x9AA7
    exit_event();  // 0x9AAE
  }
  // 0x9738-0x973E
  if (area1.event_word_2FC == 1) {
    exit_event();  // 0x973F
  }
  // 0x9740-0x9749
  area2.event_scratch0 = 8 & area1.event_word_306;  // 0x9740
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x974A
  }
  or(area1.event_word_306 = 8 | area1.event_word_306);  // 0x974B
  printclear('YOU ENTER A ROOM FULL OF MEDICINAL PROCESSING EQUIPMENT. ');  // 0x9754
  gosub 0xA3A8;  // 0x9782
  print(' SOLDIERS AIM THEIR GUNS AT LOWLANDERS LINED UP AGAINST THE WALL. ');  // 0x9786
  // truncated at 0x9A35
}
```

## Event 39

- Target: `0x9A9C`
- Text hint: "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"

```text
event 39 {
  // 0x9A9C-0x9AA5
  area2.event_scratch0 = 32 & area1.event_word_306;  // 0x9A9C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9AA6
  }
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x9AA7
  exit_event();  // 0x9AAE
}
```

## Event 40

- Target: `0x9E2C`
- Text hint: "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"

```text
event 40 {
  // 0x9E2C-0x9E32
  if (area1.event_word_2FC == 1) {
    exit_event();  // 0x9E33
  }
  setup_monster(sprite_id: 61 max_distance: 0 pic_id: 255);  // 0x9E34
  exit_event();  // 0x9E3B
}
```

## Event 41

- Target: `0xA130`
- Text hint: "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"

```text
event 41 {
  // 0xA130-0xA136
  if (area1.event_word_2FC != 1) {
    exit_event();  // 0xA137
  }
  // 0xA138-0xA141
  area2.event_scratch0 = 1 & area1.event_word_308;  // 0xA138
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0xA142
  }
  or(area1.event_word_308 = 1 | area1.event_word_308);  // 0xA143
  gosub 0xA264;  // 0xA14C
  if_<>(<if compare flag is false, skip next op>);  // 0xA150
  exit_event();  // 0xA151
}
```

## Event 42

- Target: `0xA19C`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 42 {
  area2.event_scratch3 = 4;  // 0xA19C
  goto 0xA1F8;  // 0xA1A2
  // branch body 0xA1F8
    // 0xA1F8-0xA1FE
    if (area1.event_word_2FC != 1) {
      exit_event();  // 0xA1FF
    }
    // 0xA200-0xA20A
    area2.event_scratch0 = area2.event_scratch3 & area1.event_word_308;  // 0xA200
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA20B
    }
    printclear('YOU RUN INTO A MERCURIAN PATROL!');  // 0xA20C
    setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0xA227
    exit_event();  // 0xA22E
}
```

## Event 43

- Target: `0xA1A6`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 43 {
  area2.event_scratch3 = 8;  // 0xA1A6
  goto 0xA1F8;  // 0xA1AC
  // branch body 0xA1F8
    // 0xA1F8-0xA1FE
    if (area1.event_word_2FC != 1) {
      exit_event();  // 0xA1FF
    }
    // 0xA200-0xA20A
    area2.event_scratch0 = area2.event_scratch3 & area1.event_word_308;  // 0xA200
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA20B
    }
    printclear('YOU RUN INTO A MERCURIAN PATROL!');  // 0xA20C
    setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0xA227
    exit_event();  // 0xA22E
}
```

## Event 44

- Target: `0xA1B0`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 44 {
  area2.event_scratch3 = 16;  // 0xA1B0
  goto 0xA1F8;  // 0xA1B6
  // branch body 0xA1F8
    // 0xA1F8-0xA1FE
    if (area1.event_word_2FC != 1) {
      exit_event();  // 0xA1FF
    }
    // 0xA200-0xA20A
    area2.event_scratch0 = area2.event_scratch3 & area1.event_word_308;  // 0xA200
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA20B
    }
    printclear('YOU RUN INTO A MERCURIAN PATROL!');  // 0xA20C
    setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0xA227
    exit_event();  // 0xA22E
}
```

## Event 45

- Target: `0xA1BA`
- Text hint: 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'

```text
event 45 {
  // 0xA1BA-0xA1C0
  if (area1.event_word_2FC != 1) {
    exit_event();  // 0xA1C1
  }
  area2.event_scratch3 = 32;  // 0xA1C2
  // 0xA1C8-0xA1D2
  area2.event_scratch0 = area2.event_scratch3 & area1.event_word_308;  // 0xA1C8
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0xA1D3
  }
  printclear('MERCURIANS CHARGE OUT OF THE ELEVATOR!');  // 0xA1D4
  goto 0xA227;  // 0xA1F4
  // branch body 0xA227
    setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0xA227
    exit_event();  // 0xA22E
}
```
