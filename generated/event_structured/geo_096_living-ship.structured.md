# GEO 96: Living Ship

ECL block: `96`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 01 {
  exit_event();  // 0x8268
}
```

## Event 02

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 02 {
  exit_event();  // 0x8268
}
```

## Event 03

- Target: `0x839A`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 03 {
  // 0x839A-0x83A3
  area2.event_scratch0 = 105 & area1.event_word_26A;  // 0x839A
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x83A4
  }
  // 0x83A5-0x83AB
  if (0 != area1.event_word_3E0) {
    exit_event();  // 0x83AC
  }
  exit_event();  // 0x83AE
}
```

## Event 04

- Target: `0x83F3`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 04 {
  // 0x83F3-0x83FC
  area2.event_scratch0 = 160 & area1.event_word_3E6;  // 0x83F3
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x83FD
  }
  // 0x83FE-0x8404
  if (0 != area1.event_word_3E0) {
    exit_event();  // 0x8405
  }
  // 0x8406-0x840F
  area2.event_scratch0 = 35 & area1.event_word_26A;  // 0x8406
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8410
  }
  // 0x8411-0x841A
  area2.event_scratch0 = 16 & area1.event_word_26A;  // 0x8411
  if (area2.event_scratch0 != 0) {
    goto 0x87DB;  // 0x841B
    // branch body 0x87DB
    setup_monster(sprite_id: 44 max_distance: 0 pic_id: 255);  // 0x87DB
    exit_event();  // 0x87E2
  }
  setup_monster(sprite_id: 44 max_distance: 0 pic_id: 255);  // 0x841F
  exit_event();  // 0x8426
}
```

## Event 05

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 05 {
  exit_event();  // 0x8268
}
```

## Event 07

- Target: `0x881B`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 07 {
  // 0x881B-0x8824
  area2.event_scratch0 = 16 & area1.event_word_240;  // 0x881B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8825
  }
  setup_monster(sprite_id: 44 max_distance: 2 pic_id: 255);  // 0x8826
  exit_event();  // 0x882D
}
```

## Event 08

- Target: `0x88B4`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 08 {
  compare_and(Values: abs_C04E == 0 && mapDirection == 2);  // 0x88B4
  if_<>(<if compare flag is false, skip next op>);  // 0x88BF
  exit_event();  // 0x88C0
}
```

## Event 09

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 09 {
  exit_event();  // 0x8268
}
```

## Event 10

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 10 {
  exit_event();  // 0x8268
}
```

## Event 11

- Target: `0x8D4B`
- Text hint: 'ODDLY SHAPED EQUIPMENT IS STORED HERE.'

```text
event 11 {
  area2.event_scratch0 = 1;  // 0x8D4B
  goto 0x8D5B;  // 0x8D51
  // branch body 0x8D5B
    // 0x8D5B-0x8D61
    if (0 != abs_C04E) {
      exit_event();  // 0x8D62
    }
    // 0x8D63-0x8D6D
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_244;  // 0x8D63
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x8D6E
    }
    printclear('ODDLY SHAPED EQUIPMENT IS STORED HERE.');  // 0x8D6F
    // 0x8D8F-0x8D95
    if (255 == area1.event_word_3E4) {
      goto 0x8EAB;  // 0x8D96
      // branch body 0x8EAB
      print('EXAMINING IT, YOU SEE IT HOPELESSLY WRECKED.');  // 0x8EAB
      // 0x8ED1-0x8EDA
      area2.event_scratch0 = 8 & area1.event_word_246;  // 0x8ED1
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8EDB
      }
      area2.event_scratch0 = 8;  // 0x8EDC
      printclear('YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?');  // 0x8EE2
      area2.event_scratch0 = 16;  // 0x8F3D
      goto 0x8F58;  // 0x8F43
      // branch body 0x8F58
        printclear('');  // 0x8F58
        // 0x8F5B-0x8F64
        area2.event_scratch1 = 15 & area1.event_word_242;  // 0x8F5B
        if (area2.event_scratch1 != 0) {
          exit_event();  // 0x8F65
        }
        // 0x8F66-0x8F70
        area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x8F66
        if (area2.event_scratch1 != 0) {
          exit_event();  // 0x8F71
        }
        or(area1.event_word_246 = area2.event_scratch0 | area1.event_word_246);  // 0x8F72
        // 0x8F7C-0x8F82
        if (1 != area1.event_word_20A) {
          exit_event();  // 0x8F83
        }
        // 0x8F84-0x8F8A
        if (3 != area1.event_word_204) {
          exit_event();  // 0x8F8B
        }
        area2.event_scratch2 = 1;  // 0x8F8C
        area2.event_scratch3 = 2;  // 0x8F92
        exit_event();  // 0x8F99
    }
    // 0x8D9A-0x8DA4
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_3E4;  // 0x8D9A
    if (area2.event_scratch1 != 0) {
      goto 0x8EAB;  // 0x8DA5
      // branch body 0x8EAB
      // target 0x8EAB already emitted
    }
    print('MUCH OF IT IS BROKEN.');  // 0x8DA9
    print('EXAMINING IT, YOU SEE IT HOPELESSLY WRECKED.');  // 0x8EAB
    // 0x8ED1-0x8EDA
    area2.event_scratch0 = 8 & area1.event_word_246;  // 0x8ED1
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8EDB
    }
    area2.event_scratch0 = 8;  // 0x8EDC
    printclear('YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?');  // 0x8EE2
    area2.event_scratch0 = 16;  // 0x8F3D
    goto 0x8F58;  // 0x8F43
    // branch body 0x8F58
      // target 0x8F58 already emitted
}
```

## Event 12

- Target: `0x8D55`
- Text hint: 'ODDLY SHAPED EQUIPMENT IS STORED HERE.'

```text
event 12 {
  area2.event_scratch0 = 2;  // 0x8D55
  // 0x8D5B-0x8D61
  if (0 != abs_C04E) {
    exit_event();  // 0x8D62
  }
  // 0x8D63-0x8D6D
  area2.event_scratch1 = area2.event_scratch0 & area1.event_word_244;  // 0x8D63
  if (area2.event_scratch1 != 0) {
    exit_event();  // 0x8D6E
  }
  printclear('ODDLY SHAPED EQUIPMENT IS STORED HERE.');  // 0x8D6F
  // 0x8D8F-0x8D95
  if (255 == area1.event_word_3E4) {
    goto 0x8EAB;  // 0x8D96
    // branch body 0x8EAB
    print('EXAMINING IT, YOU SEE IT HOPELESSLY WRECKED.');  // 0x8EAB
    // 0x8ED1-0x8EDA
    area2.event_scratch0 = 8 & area1.event_word_246;  // 0x8ED1
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8EDB
    }
    area2.event_scratch0 = 8;  // 0x8EDC
    printclear('YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?');  // 0x8EE2
    area2.event_scratch0 = 16;  // 0x8F3D
    goto 0x8F58;  // 0x8F43
    // branch body 0x8F58
      printclear('');  // 0x8F58
      // 0x8F5B-0x8F64
      area2.event_scratch1 = 15 & area1.event_word_242;  // 0x8F5B
      if (area2.event_scratch1 != 0) {
        exit_event();  // 0x8F65
      }
      // 0x8F66-0x8F70
      area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x8F66
      if (area2.event_scratch1 != 0) {
        exit_event();  // 0x8F71
      }
      or(area1.event_word_246 = area2.event_scratch0 | area1.event_word_246);  // 0x8F72
      // 0x8F7C-0x8F82
      if (1 != area1.event_word_20A) {
        exit_event();  // 0x8F83
      }
      // 0x8F84-0x8F8A
      if (3 != area1.event_word_204) {
        exit_event();  // 0x8F8B
      }
      area2.event_scratch2 = 1;  // 0x8F8C
      area2.event_scratch3 = 2;  // 0x8F92
      exit_event();  // 0x8F99
  }
  // 0x8D9A-0x8DA4
  area2.event_scratch1 = area2.event_scratch0 & area1.event_word_3E4;  // 0x8D9A
  if (area2.event_scratch1 != 0) {
    goto 0x8EAB;  // 0x8DA5
    // branch body 0x8EAB
    // target 0x8EAB already emitted
  }
  print('MUCH OF IT IS BROKEN.');  // 0x8DA9
  print('EXAMINING IT, YOU SEE IT HOPELESSLY WRECKED.');  // 0x8EAB
  // 0x8ED1-0x8EDA
  area2.event_scratch0 = 8 & area1.event_word_246;  // 0x8ED1
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8EDB
  }
  area2.event_scratch0 = 8;  // 0x8EDC
  printclear('YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?');  // 0x8EE2
  area2.event_scratch0 = 16;  // 0x8F3D
  goto 0x8F58;  // 0x8F43
  // branch body 0x8F58
    // target 0x8F58 already emitted
}
```

## Event 13

- Target: `0x8ED1`
- Text hint: 'YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?'

```text
event 13 {
  // 0x8ED1-0x8EDA
  area2.event_scratch0 = 8 & area1.event_word_246;  // 0x8ED1
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8EDB
  }
  area2.event_scratch0 = 8;  // 0x8EDC
  printclear('YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?');  // 0x8EE2
  area2.event_scratch0 = 16;  // 0x8F3D
  goto 0x8F58;  // 0x8F43
  // branch body 0x8F58
    printclear('');  // 0x8F58
    // 0x8F5B-0x8F64
    area2.event_scratch1 = 15 & area1.event_word_242;  // 0x8F5B
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x8F65
    }
    // 0x8F66-0x8F70
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x8F66
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x8F71
    }
    or(area1.event_word_246 = area2.event_scratch0 | area1.event_word_246);  // 0x8F72
    // 0x8F7C-0x8F82
    if (1 != area1.event_word_20A) {
      exit_event();  // 0x8F83
    }
    // 0x8F84-0x8F8A
    if (3 != area1.event_word_204) {
      exit_event();  // 0x8F8B
    }
    area2.event_scratch2 = 1;  // 0x8F8C
    area2.event_scratch3 = 2;  // 0x8F92
    exit_event();  // 0x8F99
}
```

## Event 14

- Target: `0x8F3D`
- Text hint: ''

```text
event 14 {
  area2.event_scratch0 = 16;  // 0x8F3D
  goto 0x8F58;  // 0x8F43
  // branch body 0x8F58
    printclear('');  // 0x8F58
    // 0x8F5B-0x8F64
    area2.event_scratch1 = 15 & area1.event_word_242;  // 0x8F5B
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x8F65
    }
    // 0x8F66-0x8F70
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x8F66
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x8F71
    }
    or(area1.event_word_246 = area2.event_scratch0 | area1.event_word_246);  // 0x8F72
    // 0x8F7C-0x8F82
    if (1 != area1.event_word_20A) {
      exit_event();  // 0x8F83
    }
    // 0x8F84-0x8F8A
    if (3 != area1.event_word_204) {
      exit_event();  // 0x8F8B
    }
    area2.event_scratch2 = 1;  // 0x8F8C
    area2.event_scratch3 = 2;  // 0x8F92
    exit_event();  // 0x8F99
}
```

## Event 15

- Target: `0x8F47`
- Text hint: ''

```text
event 15 {
  // 0x8F47-0x8F4D
  if (2 == mapDirection) {
    goto 0x9040;  // 0x8F4E
    // branch body 0x9040
    // 0x9040-0x9046
    if (0 != area1.event_word_3E0) {
      exit_event();  // 0x9047
    }
    // 0x9048-0x9051
    area2.event_scratch0 = 179 & area1.event_word_26A;  // 0x9048
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9052
    }
    or(area1.event_word_26A = 128 | area1.event_word_26A);  // 0x9053
    exit_event();  // 0x905D
  }
  area2.event_scratch0 = 32;  // 0x8F52
  printclear('');  // 0x8F58
  // 0x8F5B-0x8F64
  area2.event_scratch1 = 15 & area1.event_word_242;  // 0x8F5B
  if (area2.event_scratch1 != 0) {
    exit_event();  // 0x8F65
  }
  // 0x8F66-0x8F70
  area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x8F66
  if (area2.event_scratch1 != 0) {
    exit_event();  // 0x8F71
  }
  or(area1.event_word_246 = area2.event_scratch0 | area1.event_word_246);  // 0x8F72
  // 0x8F7C-0x8F82
  if (1 != area1.event_word_20A) {
    exit_event();  // 0x8F83
  }
  // 0x8F84-0x8F8A
  if (3 != area1.event_word_204) {
    exit_event();  // 0x8F8B
  }
  area2.event_scratch2 = 1;  // 0x8F8C
  area2.event_scratch3 = 2;  // 0x8F92
  exit_event();  // 0x8F99
}
```

## Event 16

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 16 {
  exit_event();  // 0x8268
}
```

## Event 17

- Target: `0x90AC`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 17 {
  // 0x90AC-0x90B5
  area2.event_scratch0 = 3 & area1.event_word_242;  // 0x90AC
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x90B6
  }
  // 0x90B7-0x90BD
  if (0 != area1.event_word_3E0) {
    exit_event();  // 0x90BE
  }
  exit_event();  // 0x90C0
}
```

## Event 18

- Target: `0x95CF`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 18 {
  area2.event_scratch0 = 1;  // 0x95CF
  goto 0x95E9;  // 0x95D5
  // branch body 0x95E9
    printclear("THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED.");  // 0x95E9
    // 0x9622-0x9628
    if (255 == area1.event_word_3E4) {
      goto 0x9703;  // 0x9629
      // branch body 0x9703
      print('DO YOU USE A SONIC STUNNER ON THE NERVE?');  // 0x9703
      // truncated at 0x9B16
    }
    // 0x962D-0x9637
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x962D
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x9638
    }
    sprite(OFF);  // 0x9639
    goto 0x004C;  // 0x963A
    // branch body 0x004C
      // 0x8014-0x801A
      if (area1.LastEclBlockId == 96) {
        exit_event();  // 0x801B
      }
      // truncated at 0x801C
}
```

## Event 19

- Target: `0x95D9`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 19 {
  area2.event_scratch0 = 2;  // 0x95D9
  goto 0x95E9;  // 0x95DF
  // branch body 0x95E9
    printclear("THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED.");  // 0x95E9
    // 0x9622-0x9628
    if (255 == area1.event_word_3E4) {
      goto 0x9703;  // 0x9629
      // branch body 0x9703
      print('DO YOU USE A SONIC STUNNER ON THE NERVE?');  // 0x9703
      // truncated at 0x9B16
    }
    // 0x962D-0x9637
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x962D
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0x9638
    }
    sprite(OFF);  // 0x9639
    goto 0x004C;  // 0x963A
    // branch body 0x004C
      // 0x8014-0x801A
      if (area1.LastEclBlockId == 96) {
        exit_event();  // 0x801B
      }
      // truncated at 0x801C
}
```

## Event 20

- Target: `0x95E3`
- Text hint: "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."

```text
event 20 {
  area2.event_scratch0 = 4;  // 0x95E3
  printclear("THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED.");  // 0x95E9
  // 0x9622-0x9628
  if (255 == area1.event_word_3E4) {
    goto 0x9703;  // 0x9629
    // branch body 0x9703
    print('DO YOU USE A SONIC STUNNER ON THE NERVE?');  // 0x9703
    // truncated at 0x9B16
  }
  // 0x962D-0x9637
  area2.event_scratch1 = area2.event_scratch0 & area1.event_word_246;  // 0x962D
  if (area2.event_scratch1 != 0) {
    exit_event();  // 0x9638
  }
  sprite(OFF);  // 0x9639
  goto 0x004C;  // 0x963A
  // branch body 0x004C
    // 0x8014-0x801A
    if (area1.LastEclBlockId == 96) {
      exit_event();  // 0x801B
    }
    // truncated at 0x801C
}
```

## Event 21

- Target: `0x9B16`
- Text hint: 'THE ROOM SMELLS OF ANTISEPTIC.'

```text
event 21 {
  // 0x9B16-0x9B1F
  area2.event_scratch0 = 64 & area1.event_word_246;  // 0x9B16
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9B20
  }
  setup_monster(sprite_id: 45 max_distance: 1 pic_id: 255);  // 0x9B21
  exit_event();  // 0x9B28
}
```

## Event 22

- Target: `0x9B94`
- Text hint: 'THE ROOM SMELLS OF ANTISEPTIC.'

```text
event 22 {
  // 0x9B94-0x9B9D
  area2.event_scratch0 = 3 & area1.event_word_3E6;  // 0x9B94
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9B9E
  }
  // 0x9B9F-0x9BA5
  if (0 != area1.event_word_3E0) {
    exit_event();  // 0x9BA6
  }
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 255);  // 0x9BA7
  exit_event();  // 0x9BAE
}
```

## Event 23

- Target: `0x9F3C`
- Text hint: 'THE ROOM SMELLS OF ANTISEPTIC.'

```text
event 23 {
  // 0x9F3C-0x9F42
  if (2 != mapDirection) {
    exit_event();  // 0x9F43
  }
  printclear('THE ROOM SMELLS OF ANTISEPTIC.');  // 0x9F44
  // 0x9F60-0x9F66
  if (0 != abs_C04E) {
    exit_event();  // 0x9F67
  }
  printclear('MEDICAL SUPPLIES ARE SCATTERED ABOUT THE ROOM.');  // 0x9F68
  // 0x9F90-0x9F99
  area2.event_scratch0 = 32 & area1.event_word_242;  // 0x9F90
  if (area2.event_scratch0 != 0) {
    goto 0xA04D;  // 0x9F9A
    // branch body 0xA04D
    or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
    printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
    area2.event_scratch0 = 1;  // 0xA071
    area2.event_scratch1 = 2;  // 0xA077
    area2.event_scratch6 = 23;  // 0xA07D
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // 0xA14E-0xA157
      area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA158
      }
      gosub 0xA3D9;  // 0xA159
      or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
      exit_event();  // 0xA166
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  // 0x9F9E-0x9FA7
  area2.event_scratch0 = 16 & area1.event_word_242;  // 0x9F9E
  if (area2.event_scratch0 != 0) {
    goto 0xA000;  // 0x9FA8
    // branch body 0xA000
    printclear('THE AUTODOC ASKS IF YOU NEED TO BE HEALED.');  // 0xA000
    or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
    printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
    area2.event_scratch0 = 1;  // 0xA071
    area2.event_scratch1 = 2;  // 0xA077
    area2.event_scratch6 = 23;  // 0xA07D
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // target 0xA14E already emitted
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  printclear('THE AUTODOC LAYS TOPPLED ON THE FLOOR. DO YOU TRY TO REPAIR IT?');  // 0x9FAC
  printclear('THE AUTODOC ASKS IF YOU NEED TO BE HEALED.');  // 0xA000
  or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
  printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
  area2.event_scratch0 = 1;  // 0xA071
  area2.event_scratch1 = 2;  // 0xA077
  area2.event_scratch6 = 23;  // 0xA07D
  // 0xA083-0xA08A
  if (mapDirection != area2.event_scratch1) {
    exit_event();  // 0xA08B
  }
}
```

## Event 24

- Target: `0x9F60`
- Text hint: 'MEDICAL SUPPLIES ARE SCATTERED ABOUT THE ROOM.'

```text
event 24 {
  // 0x9F60-0x9F66
  if (0 != abs_C04E) {
    exit_event();  // 0x9F67
  }
  printclear('MEDICAL SUPPLIES ARE SCATTERED ABOUT THE ROOM.');  // 0x9F68
  // 0x9F90-0x9F99
  area2.event_scratch0 = 32 & area1.event_word_242;  // 0x9F90
  if (area2.event_scratch0 != 0) {
    goto 0xA04D;  // 0x9F9A
    // branch body 0xA04D
    or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
    printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
    area2.event_scratch0 = 1;  // 0xA071
    area2.event_scratch1 = 2;  // 0xA077
    area2.event_scratch6 = 23;  // 0xA07D
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // 0xA14E-0xA157
      area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA158
      }
      gosub 0xA3D9;  // 0xA159
      or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
      exit_event();  // 0xA166
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  // 0x9F9E-0x9FA7
  area2.event_scratch0 = 16 & area1.event_word_242;  // 0x9F9E
  if (area2.event_scratch0 != 0) {
    goto 0xA000;  // 0x9FA8
    // branch body 0xA000
    printclear('THE AUTODOC ASKS IF YOU NEED TO BE HEALED.');  // 0xA000
    or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
    printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
    area2.event_scratch0 = 1;  // 0xA071
    area2.event_scratch1 = 2;  // 0xA077
    area2.event_scratch6 = 23;  // 0xA07D
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // target 0xA14E already emitted
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  printclear('THE AUTODOC LAYS TOPPLED ON THE FLOOR. DO YOU TRY TO REPAIR IT?');  // 0x9FAC
  printclear('THE AUTODOC ASKS IF YOU NEED TO BE HEALED.');  // 0xA000
  or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
  printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
  area2.event_scratch0 = 1;  // 0xA071
  area2.event_scratch1 = 2;  // 0xA077
  area2.event_scratch6 = 23;  // 0xA07D
  // 0xA083-0xA08A
  if (mapDirection != area2.event_scratch1) {
    exit_event();  // 0xA08B
  }
  printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
  // 0xA0B8-0xA0BE
  if (255 == area1.event_word_3E4) {
    goto 0xA14E;  // 0xA0BF
    // branch body 0xA14E
    // target 0xA14E already emitted
  }
}
```

## Event 25

- Target: `0x9F90`
- Text hint: 'THE AUTODOC LAYS TOPPLED ON THE FLOOR. DO YOU TRY TO REPAIR IT?' 'THE AUTODOC ASKS IF YOU NEED TO BE HEALED.' 'THE AUTODOC IS BEYOND REPAIR.'

```text
event 25 {
  // 0x9F90-0x9F99
  area2.event_scratch0 = 32 & area1.event_word_242;  // 0x9F90
  if (area2.event_scratch0 != 0) {
    goto 0xA04D;  // 0x9F9A
    // branch body 0xA04D
    or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
    printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
    area2.event_scratch0 = 1;  // 0xA071
    area2.event_scratch1 = 2;  // 0xA077
    area2.event_scratch6 = 23;  // 0xA07D
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // 0xA14E-0xA157
      area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA158
      }
      gosub 0xA3D9;  // 0xA159
      or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
      exit_event();  // 0xA166
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  // 0x9F9E-0x9FA7
  area2.event_scratch0 = 16 & area1.event_word_242;  // 0x9F9E
  if (area2.event_scratch0 != 0) {
    goto 0xA000;  // 0x9FA8
    // branch body 0xA000
    printclear('THE AUTODOC ASKS IF YOU NEED TO BE HEALED.');  // 0xA000
    or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
    printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
    area2.event_scratch0 = 1;  // 0xA071
    area2.event_scratch1 = 2;  // 0xA077
    area2.event_scratch6 = 23;  // 0xA07D
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // target 0xA14E already emitted
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  printclear('THE AUTODOC LAYS TOPPLED ON THE FLOOR. DO YOU TRY TO REPAIR IT?');  // 0x9FAC
  printclear('THE AUTODOC ASKS IF YOU NEED TO BE HEALED.');  // 0xA000
  or(area1.event_word_242 = 32 | area1.event_word_242);  // 0xA04D
  printclear('THE AUTODOC IS BEYOND REPAIR.');  // 0xA056
  area2.event_scratch0 = 1;  // 0xA071
  area2.event_scratch1 = 2;  // 0xA077
  area2.event_scratch6 = 23;  // 0xA07D
  // 0xA083-0xA08A
  if (mapDirection != area2.event_scratch1) {
    exit_event();  // 0xA08B
  }
  printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
  // 0xA0B8-0xA0BE
  if (255 == area1.event_word_3E4) {
    goto 0xA14E;  // 0xA0BF
    // branch body 0xA14E
    // target 0xA14E already emitted
  }
  // 0xA0C3-0xA0CD
  area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
  if (area2.event_scratch1 != 0) {
    exit_event();  // 0xA0CE
  }
}
```

## Event 26

- Target: `0xA071`
- Text hint: 'CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. '

```text
event 26 {
  area2.event_scratch0 = 1;  // 0xA071
  area2.event_scratch1 = 2;  // 0xA077
  area2.event_scratch6 = 23;  // 0xA07D
  // 0xA083-0xA08A
  if (mapDirection != area2.event_scratch1) {
    exit_event();  // 0xA08B
  }
  printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
  // 0xA0B8-0xA0BE
  if (255 == area1.event_word_3E4) {
    goto 0xA14E;  // 0xA0BF
    // branch body 0xA14E
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
  }
  // 0xA0C3-0xA0CD
  area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
  if (area2.event_scratch1 != 0) {
    exit_event();  // 0xA0CE
  }
  print('SEARCH THE ROOM?');  // 0xA0CF
  // 0xA14E-0xA157
  area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0xA158
  }
  gosub 0xA3D9;  // 0xA159
  or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
  exit_event();  // 0xA166
}
```

## Event 27

- Target: `0xA191`
- Text hint: RETURN

```text
event 27 {
  area2.event_scratch0 = 2;  // 0xA191
  area2.event_scratch1 = 2;  // 0xA197
  area2.event_scratch6 = 64;  // 0xA19D
  goto 0xA083;  // 0xA1A3
  // branch body 0xA083
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // 0xA14E-0xA157
      area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA158
      }
      gosub 0xA3D9;  // 0xA159
      or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
      exit_event();  // 0xA166
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
}
```

## Event 28

- Target: `0xA1A7`
- Text hint: RETURN

```text
event 28 {
  area2.event_scratch0 = 4;  // 0xA1A7
  area2.event_scratch1 = 3;  // 0xA1AD
  area2.event_scratch6 = 56;  // 0xA1B3
  goto 0xA083;  // 0xA1B9
  // branch body 0xA083
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // 0xA14E-0xA157
      area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA158
      }
      gosub 0xA3D9;  // 0xA159
      or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
      exit_event();  // 0xA166
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
}
```

## Event 29

- Target: `0xA1BD`
- Text hint: RETURN

```text
event 29 {
  area2.event_scratch0 = 8;  // 0xA1BD
  area2.event_scratch1 = 1;  // 0xA1C3
  area2.event_scratch6 = 74;  // 0xA1C9
  goto 0xA083;  // 0xA1CF
  // branch body 0xA083
    // 0xA083-0xA08A
    if (mapDirection != area2.event_scratch1) {
      exit_event();  // 0xA08B
    }
    printclear('CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. ');  // 0xA08C
    // 0xA0B8-0xA0BE
    if (255 == area1.event_word_3E4) {
      goto 0xA14E;  // 0xA0BF
      // branch body 0xA14E
      // 0xA14E-0xA157
      area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0xA158
      }
      gosub 0xA3D9;  // 0xA159
      or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
      exit_event();  // 0xA166
    }
    // 0xA0C3-0xA0CD
    area2.event_scratch1 = area2.event_scratch0 & area1.event_word_248;  // 0xA0C3
    if (area2.event_scratch1 != 0) {
      exit_event();  // 0xA0CE
    }
    print('SEARCH THE ROOM?');  // 0xA0CF
    // 0xA14E-0xA157
    area2.event_scratch0 = 8 & area1.event_word_24A;  // 0xA14E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA158
    }
    gosub 0xA3D9;  // 0xA159
    or(area1.event_word_24A = 8 | area1.event_word_24A);  // 0xA15D
    exit_event();  // 0xA166
}
```

## Event 30

- Target: `0x8268`
- Text hint: 'THE TECHS NOTICE YOU. '

```text
event 30 {
  exit_event();  // 0x8268
}
```
