# GEO 50: Venus Laboratory, Level 1

ECL block: `50`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x830F`
- Text hint: 'AN ELEVATOR GOING DOWN. DO YOU USE IT?' 'YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?'

```text
event 01 {
  // 0x830F-0x8315
  if (mapDirection != 1) {
    exit_event();  // 0x8316
  }
  printclear('AN ELEVATOR GOING DOWN. DO YOU USE IT?');  // 0x8317
  printclear('YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?');  // 0x83A3
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

## Event 02

- Target: `0x83A3`
- Text hint: 'YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?'

```text
event 02 {
  printclear('YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?');  // 0x83A3
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

## Event 04

- Target: `0x844F`
- Text hint: 'ENTERING THE LAB COMPLEX, YOU FIND THE SOURCE OF THE EARTHQUAKE. AN EXPLOSION LARGE ENOUGH TO BLOW AWAY THE ROOF HAS EXPOSED THE VENUSIAN SKY.'

```text
event 04 {
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

## Event 05

- Target: `0x84D6`
- Text hint: 'THE BODIES OF ' ' SOLDIERS LIE HERE. THEY APPEAR TO HAVE BEEN CRUSHED BY ENORMOUS WEIGHTS.'

```text
event 05 {
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

## Event 06

- Target: `0x852C`
- Text hint: 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'

```text
event 06 {
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

## Event 07

- Target: `0x8538`
- Text hint: 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'

```text
event 07 {
  // 0x8538-0x853E
  if (mapDirection != 2) {
    exit_event();  // 0x853F
  }
  goto 0x84DE;  // 0x8540
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

## Event 08

- Target: `0x8544`
- Text hint: 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'

```text
event 08 {
  // 0x8544-0x854A
  if (mapDirection != 1) {
    exit_event();  // 0x854B
  }
  printclear('YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.');  // 0x854C
  // 0x8587-0x858D
  if (mapDirection != 2) {
    exit_event();  // 0x858E
  }
  goto 0x854C;  // 0x858F
  // branch body 0x854C
    printclear('YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.');  // 0x854C
    // 0x8587-0x858D
    if (mapDirection != 2) {
      exit_event();  // 0x858E
    }
    goto 0x854C;  // 0x858F
    // branch body 0x854C
      // target 0x854C already emitted
}
```

## Event 09

- Target: `0x8587`
- Text hint: "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"

```text
event 09 {
  // 0x8587-0x858D
  if (mapDirection != 2) {
    exit_event();  // 0x858E
  }
  goto 0x854C;  // 0x858F
  // branch body 0x854C
    printclear('YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.');  // 0x854C
    // 0x8587-0x858D
    if (mapDirection != 2) {
      exit_event();  // 0x858E
    }
    goto 0x854C;  // 0x858F
    // branch body 0x854C
      // target 0x854C already emitted
}
```

## Event 10

- Target: `0x8593`
- Text hint: "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"

```text
event 10 {
  // 0x8593-0x8599
  if (area1.event_word_300 == 1) {
    exit_event();  // 0x859A
  }
  // 0x859B-0x85A1
  if (mapDirection != 1) {
    exit_event();  // 0x85A2
  }
  setup_monster(sprite_id: 61 max_distance: 2 pic_id: 255);  // 0x85A3
  exit_event();  // 0x85AA
}
```

## Event 11

- Target: `0x8696`
- Text hint: "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"

```text
event 11 {
  // 0x8696-0x869C
  if (mapDirection != 0) {
    exit_event();  // 0x869D
  }
  // 0x869E-0x86A4
  if (area1.event_word_300 == 1) {
    exit_event();  // 0x86A5
  }
  printclear("LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'");  // 0x86A6
  // 0x86D0-0x86D6
  if (area1.event_word_300 == 1) {
    exit_event();  // 0x86D7
  }
  printclear('YOU STEP INTO THE GRAVITY FIELD!');  // 0x86D8
  // 0x8740-0x8749
  area2.event_scratch0 = 4 & area1.event_word_2FE;  // 0x8740
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x874A
  }
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x874B
  exit_event();  // 0x8752
}
```

## Event 12

- Target: `0x86D0`
- Text hint: 'YOU STEP INTO THE GRAVITY FIELD!'

```text
event 12 {
  // 0x86D0-0x86D6
  if (area1.event_word_300 == 1) {
    exit_event();  // 0x86D7
  }
  printclear('YOU STEP INTO THE GRAVITY FIELD!');  // 0x86D8
  // 0x8740-0x8749
  area2.event_scratch0 = 4 & area1.event_word_2FE;  // 0x8740
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x874A
  }
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x874B
  exit_event();  // 0x8752
}
```

## Event 13

- Target: `0x8740`
- Text hint: 'THE CONTROLS TO THE GRAVITY FIELD ARE HERE. DO YOU TURN IT OFF?'

```text
event 13 {
  // 0x8740-0x8749
  area2.event_scratch0 = 4 & area1.event_word_2FE;  // 0x8740
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x874A
  }
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x874B
  exit_event();  // 0x8752
}
```

## Event 14

- Target: `0x87C3`
- Text hint: 'THE CONTROLS TO THE GRAVITY FIELD ARE HERE. DO YOU TURN IT OFF?'

```text
event 14 {
  // 0x87C3-0x87C9
  if (area1.event_word_300 == 1) {
    exit_event();  // 0x87CA
  }
  printclear('THE CONTROLS TO THE GRAVITY FIELD ARE HERE. DO YOU TURN IT OFF?');  // 0x87CB
  // 0x882A-0x8830
  if (area1.event_word_300 != 1) {
    exit_event();  // 0x8831
  }
  // 0x8832-0x883B
  area2.event_scratch0 = 64 & area1.event_word_308;  // 0x8832
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x883C
  }
  picture(block_id: 55);  // 0x883D
  printclear("LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'");  // 0x8840
  printclear('THE BODY OF A ');  // 0x88F3
  gosub 0xA3A8;  // 0x8901
  print(' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.');  // 0x8905
  // 0x8932-0x893B
  area2.event_scratch0 = 8 & area1.event_word_2FE;  // 0x8932
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x893C
  }
  gosub 0xA264;  // 0x893D
  if_<>(<if compare flag is false, skip next op>);  // 0x8941
  exit_event();  // 0x8942
}
```

## Event 15

- Target: `0x882A`
- Text hint: "LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'" 'THE BODY OF A ' ' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.'

```text
event 15 {
  // 0x882A-0x8830
  if (area1.event_word_300 != 1) {
    exit_event();  // 0x8831
  }
  // 0x8832-0x883B
  area2.event_scratch0 = 64 & area1.event_word_308;  // 0x8832
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x883C
  }
  picture(block_id: 55);  // 0x883D
  printclear("LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'");  // 0x8840
  printclear('THE BODY OF A ');  // 0x88F3
  gosub 0xA3A8;  // 0x8901
  print(' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.');  // 0x8905
  // 0x8932-0x893B
  area2.event_scratch0 = 8 & area1.event_word_2FE;  // 0x8932
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x893C
  }
  gosub 0xA264;  // 0x893D
  if_<>(<if compare flag is false, skip next op>);  // 0x8941
  exit_event();  // 0x8942
}
```

## Event 16

- Target: `0x88F3`
- Text hint: 'THE BODY OF A ' ' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.'

```text
event 16 {
  printclear('THE BODY OF A ');  // 0x88F3
  gosub 0xA3A8;  // 0x8901
  print(' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.');  // 0x8905
  // 0x8932-0x893B
  area2.event_scratch0 = 8 & area1.event_word_2FE;  // 0x8932
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x893C
  }
  gosub 0xA264;  // 0x893D
  if_<>(<if compare flag is false, skip next op>);  // 0x8941
  exit_event();  // 0x8942
}
```

## Event 17

- Target: `0x8932`
- Text hint: 'YOU HEAR SOUNDS TO THE WEST. LEANDER SPEAKS.'

```text
event 17 {
  // 0x8932-0x893B
  area2.event_scratch0 = 8 & area1.event_word_2FE;  // 0x8932
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x893C
  }
  gosub 0xA264;  // 0x893D
  if_<>(<if compare flag is false, skip next op>);  // 0x8941
  exit_event();  // 0x8942
}
```

## Event 18

- Target: `0x899B`
- Text hint: 'THIS LAB HAS BEEN RANSACKED.'

```text
event 18 {
  // 0x899B-0x89A1
  if (area1.event_word_2FC == 1) {
    exit_event();  // 0x89A2
  }
  // 0x89A3-0x89AC
  area2.event_scratch0 = 16 & area1.event_word_2FE;  // 0x89A3
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x89AD
  }
  or(area1.event_word_2FE = 16 | area1.event_word_2FE);  // 0x89AE
  setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x89B7
  exit_event();  // 0x89BE
}
```

## Event 19

- Target: `0x8BA6`
- Text hint: 'THIS LAB HAS BEEN RANSACKED.'

```text
event 19 {
  // 0x8BA6-0x8BAC
  if (mapDirection != 2) {
    exit_event();  // 0x8BAD
  }
  printclear('THIS LAB HAS BEEN RANSACKED.');  // 0x8BAE
  exit_event();  // 0x8BC6
}
```

## Event 20

- Target: `0x8BC7`
- Text hint: 'YOU HEAR A COMMOTION FROM THE SOUTH.' " LEANDER SAYS, 'WE SSTORE OUR DATA ARCHIVESS IN THERE.'"

```text
event 20 {
  // 0x8BC7-0x8BCD
  if (mapDirection != 3) {
    exit_event();  // 0x8BCE
  }
  goto 0x8BAE;  // 0x8BCF
  // branch body 0x8BAE
    printclear('THIS LAB HAS BEEN RANSACKED.');  // 0x8BAE
    exit_event();  // 0x8BC6
}
```

## Event 21

- Target: `0x8BD3`
- Text hint: 'YOU HEAR A COMMOTION FROM THE SOUTH.' " LEANDER SAYS, 'WE SSTORE OUR DATA ARCHIVESS IN THERE.'"

```text
event 21 {
  // 0x8BD3-0x8BDC
  area2.event_scratch0 = 32 & area1.event_word_2FE;  // 0x8BD3
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8BDD
  }
  printclear('YOU HEAR A COMMOTION FROM THE SOUTH.');  // 0x8BDE
  gosub 0xA264;  // 0x8BFC
  if_=(<if compare flag is false, skip next op>);  // 0x8C00
  print(" LEANDER SAYS, 'WE SSTORE OUR DATA ARCHIVESS IN THERE.'");  // 0x8C01
  // 0x8C39-0x8C42
  area2.event_scratch0 = 128 & area1.event_word_306;  // 0x8C39
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C43
  }
  printclear('YOU ENTER A DATA ARCHIVE. ');  // 0x8C44
  // 0x8C5B-0x8C61
  if (area1.event_word_2FC == 1) {
    goto 0x8CCE;  // 0x8C62
    // branch body 0x8CCE
    setup_monster(sprite_id: 33 max_distance: 1 pic_id: 255);  // 0x8CCE
    exit_event();  // 0x8CD5
  }
  gosub 0xA3A8;  // 0x8C66
  print(' FORCES ARE PUTTING COMPUTER DATA CAPSULES IN SACKS.');  // 0x8C6A
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x8C94
  exit_event();  // 0x8C9B
}
```

## Event 22

- Target: `0x8C39`
- Text hint: 'YOU ENTER A DATA ARCHIVE. '

```text
event 22 {
  // 0x8C39-0x8C42
  area2.event_scratch0 = 128 & area1.event_word_306;  // 0x8C39
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C43
  }
  printclear('YOU ENTER A DATA ARCHIVE. ');  // 0x8C44
  // 0x8C5B-0x8C61
  if (area1.event_word_2FC == 1) {
    goto 0x8CCE;  // 0x8C62
    // branch body 0x8CCE
    setup_monster(sprite_id: 33 max_distance: 1 pic_id: 255);  // 0x8CCE
    exit_event();  // 0x8CD5
  }
  gosub 0xA3A8;  // 0x8C66
  print(' FORCES ARE PUTTING COMPUTER DATA CAPSULES IN SACKS.');  // 0x8C6A
  setup_monster(sprite_id: 5 max_distance: 1 pic_id: 255);  // 0x8C94
  exit_event();  // 0x8C9B
}
```

## Event 23

- Target: `0x8D8D`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 23 {
  // 0x8D8D-0x8D93
  if (area1.event_word_2FC == 1) {
    goto 0x8E1B;  // 0x8D94
    // branch body 0x8E1B
    // 0x8E1B-0x8E21
    if (area1.event_word_2FC != 1) {
      exit_event();  // 0x8E22
    }
    // 0x8E23-0x8E29
    if (area1.event_word_304 <= 5) {
      exit_event();  // 0x8E2A
    }
    // 0x8E2B-0x8E31
    if (area1.event_word_204 < 8) {
      goto 0x8E40;  // 0x8E32
      // branch body 0x8E40
      random(area2.event_scratch0 = random 1..99);  // 0x8E40
      // 0x8E46-0x8E4C
      if (area2.event_scratch0 < 12) {
        exit_event();  // 0x8E4D
      }
      area1.event_word_204 = 0;  // 0x8E4E
      add(area1.event_word_304 = 1 + area1.event_word_304);  // 0x8E54
      random(area2.event_scratch0 = random 1..1);  // 0x8E5D
      // 0x8E63-0x8E69
      if (area2.event_scratch0 == 1) {
        goto 0x8EAB;  // 0x8E6A
        // branch body 0x8EAB
        setup_monster(sprite_id: 50 max_distance: 0 pic_id: 255);  // 0x8EAB
        exit_event();  // 0x8EB2
      }
      setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0x8E6E
      exit_event();  // 0x8E75
    }
    add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x8E36
    exit_event();  // 0x8E3F
  }
  // 0x8D98-0x8D9E
  if (area1.event_word_302 <= 3) {
    exit_event();  // 0x8D9F
  }
  // 0x8DA0-0x8DA6
  if (area1.event_word_204 < 10) {
    goto 0x8DB5;  // 0x8DA7
    // branch body 0x8DB5
    random(area2.event_scratch0 = random 1..99);  // 0x8DB5
    // 0x8DBB-0x8DC1
    if (area2.event_scratch0 < 12) {
      exit_event();  // 0x8DC2
    }
    add(area1.event_word_302 = 1 + area1.event_word_302);  // 0x8DC3
    area1.event_word_204 = 0;  // 0x8DCC
    setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x8DD2
    exit_event();  // 0x8DD9
  }
  add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x8DAB
  exit_event();  // 0x8DB4
}
```

## Event 24

- Target: `0x8E1B`
- Text hint: 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'

```text
event 24 {
  // 0x8E1B-0x8E21
  if (area1.event_word_2FC != 1) {
    exit_event();  // 0x8E22
  }
  // 0x8E23-0x8E29
  if (area1.event_word_304 <= 5) {
    exit_event();  // 0x8E2A
  }
  // 0x8E2B-0x8E31
  if (area1.event_word_204 < 8) {
    goto 0x8E40;  // 0x8E32
    // branch body 0x8E40
    random(area2.event_scratch0 = random 1..99);  // 0x8E40
    // 0x8E46-0x8E4C
    if (area2.event_scratch0 < 12) {
      exit_event();  // 0x8E4D
    }
    area1.event_word_204 = 0;  // 0x8E4E
    add(area1.event_word_304 = 1 + area1.event_word_304);  // 0x8E54
    random(area2.event_scratch0 = random 1..1);  // 0x8E5D
    // 0x8E63-0x8E69
    if (area2.event_scratch0 == 1) {
      goto 0x8EAB;  // 0x8E6A
      // branch body 0x8EAB
      setup_monster(sprite_id: 50 max_distance: 0 pic_id: 255);  // 0x8EAB
      exit_event();  // 0x8EB2
    }
    setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0x8E6E
    exit_event();  // 0x8E75
  }
  add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x8E36
  exit_event();  // 0x8E3F
}
```
