# GEO 113: Genetics Foundation Building, Levels 1-4

ECL block: `113`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8C12`
- Text hint: 'THIS ELEVATOR HAS BEEN DEACTIVATED.'

```text
event 01 {
  printclear('THIS ELEVATOR HAS BEEN DEACTIVATED.');  // 0x8C12
  exit_event();  // 0x8C30
}
```

## Event 02

- Target: `0x8C31`
- Text hint: 'YOU CLIMB DOWN.' 'YOU CLIMB UP.' 'AN ELEVATOR. DO YOU USE IT?'

```text
event 02 {
  area2.event_scratch0 = 1;  // 0x8C31
  gosub 0xA0E4;  // 0x8C37
  if_<>(<if compare flag is false, skip next op>);  // 0x8C3C
  printclear('YOU CLIMB DOWN.');  // 0x8C3E
  area2.event_scratch0 = 0;  // 0x8C58
  gosub 0xA0E4;  // 0x8C5E
  if_<>(<if compare flag is false, skip next op>);  // 0x8C63
  printclear('YOU CLIMB UP.');  // 0x8C65
  printclear('AN ELEVATOR. DO YOU USE IT?');  // 0x8C81
  area2.event_scratch0 = 1;  // 0x8D2D
  gosub 0xA0E4;  // 0x8D33
  if_<>(<if compare flag is false, skip next op>);  // 0x8D38
  mapPosX = 0;  // 0x8D3A
  mapPosY = 8;  // 0x8D40
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
  // 0x8D4A-0x8D53
  area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
  if (area2.event_scratch0 != 0) {
    goto 0x8DCF;  // 0x8D54
    // branch body 0x8DCF
    // 0x8DCF-0x8DD8
    area2.event_scratch0 = 8 & area1.event_word_386;  // 0x8DCF
    if (area2.event_scratch0 != 0) {
      printclear('THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.');  // 0x8DD9
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x8E00
    goto 0x8DAD;  // 0x8E01
    // branch body 0x8DAD
      area2.event_scratch0 = 0;  // 0x8DAE
      gosub 0xA0E4;  // 0x8DB4
      if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
      mapPosX = 8;  // 0x8DBB
      mapPosY = 0;  // 0x8DC1
      engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
      goto 0x8D2D;  // 0x8DCB
      // branch body 0x8D2D
        area2.event_scratch0 = 1;  // 0x8D2D
        gosub 0xA0E4;  // 0x8D33
        if_<>(<if compare flag is false, skip next op>);  // 0x8D38
        mapPosX = 0;  // 0x8D3A
        mapPosY = 8;  // 0x8D40
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
        // 0x8D4A-0x8D53
        area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
        if (area2.event_scratch0 != 0) {
          goto 0x8DCF;  // 0x8D54
        }
        printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
        area2.event_scratch0 = 0;  // 0x8DAE
        gosub 0xA0E4;  // 0x8DB4
        if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
        mapPosX = 8;  // 0x8DBB
        mapPosY = 0;  // 0x8DC1
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
        goto 0x8D2D;  // 0x8DCB
  }
  printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
  area2.event_scratch0 = 0;  // 0x8DAE
  gosub 0xA0E4;  // 0x8DB4
  if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
  mapPosX = 8;  // 0x8DBB
  mapPosY = 0;  // 0x8DC1
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
  goto 0x8D2D;  // 0x8DCB
  // branch body 0x8D2D
    // target 0x8D2D already emitted
}
```

## Event 03

- Target: `0x8C58`
- Text hint: 'YOU CLIMB UP.' 'AN ELEVATOR. DO YOU USE IT?'

```text
event 03 {
  area2.event_scratch0 = 0;  // 0x8C58
  gosub 0xA0E4;  // 0x8C5E
  if_<>(<if compare flag is false, skip next op>);  // 0x8C63
  printclear('YOU CLIMB UP.');  // 0x8C65
  printclear('AN ELEVATOR. DO YOU USE IT?');  // 0x8C81
  area2.event_scratch0 = 1;  // 0x8D2D
  gosub 0xA0E4;  // 0x8D33
  if_<>(<if compare flag is false, skip next op>);  // 0x8D38
  mapPosX = 0;  // 0x8D3A
  mapPosY = 8;  // 0x8D40
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
  // 0x8D4A-0x8D53
  area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
  if (area2.event_scratch0 != 0) {
    goto 0x8DCF;  // 0x8D54
    // branch body 0x8DCF
    // 0x8DCF-0x8DD8
    area2.event_scratch0 = 8 & area1.event_word_386;  // 0x8DCF
    if (area2.event_scratch0 != 0) {
      printclear('THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.');  // 0x8DD9
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x8E00
    goto 0x8DAD;  // 0x8E01
    // branch body 0x8DAD
      area2.event_scratch0 = 0;  // 0x8DAE
      gosub 0xA0E4;  // 0x8DB4
      if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
      mapPosX = 8;  // 0x8DBB
      mapPosY = 0;  // 0x8DC1
      engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
      goto 0x8D2D;  // 0x8DCB
      // branch body 0x8D2D
        area2.event_scratch0 = 1;  // 0x8D2D
        gosub 0xA0E4;  // 0x8D33
        if_<>(<if compare flag is false, skip next op>);  // 0x8D38
        mapPosX = 0;  // 0x8D3A
        mapPosY = 8;  // 0x8D40
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
        // 0x8D4A-0x8D53
        area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
        if (area2.event_scratch0 != 0) {
          goto 0x8DCF;  // 0x8D54
        }
        printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
        area2.event_scratch0 = 0;  // 0x8DAE
        gosub 0xA0E4;  // 0x8DB4
        if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
        mapPosX = 8;  // 0x8DBB
        mapPosY = 0;  // 0x8DC1
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
        goto 0x8D2D;  // 0x8DCB
  }
  printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
  area2.event_scratch0 = 0;  // 0x8DAE
  gosub 0xA0E4;  // 0x8DB4
  if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
  mapPosX = 8;  // 0x8DBB
  mapPosY = 0;  // 0x8DC1
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
  goto 0x8D2D;  // 0x8DCB
  // branch body 0x8D2D
    // target 0x8D2D already emitted
}
```

## Event 04

- Target: `0x8C81`
- Text hint: 'AN ELEVATOR. DO YOU USE IT?'

```text
event 04 {
  printclear('AN ELEVATOR. DO YOU USE IT?');  // 0x8C81
  area2.event_scratch0 = 1;  // 0x8D2D
  gosub 0xA0E4;  // 0x8D33
  if_<>(<if compare flag is false, skip next op>);  // 0x8D38
  mapPosX = 0;  // 0x8D3A
  mapPosY = 8;  // 0x8D40
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
  // 0x8D4A-0x8D53
  area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
  if (area2.event_scratch0 != 0) {
    goto 0x8DCF;  // 0x8D54
    // branch body 0x8DCF
    // 0x8DCF-0x8DD8
    area2.event_scratch0 = 8 & area1.event_word_386;  // 0x8DCF
    if (area2.event_scratch0 != 0) {
      printclear('THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.');  // 0x8DD9
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x8E00
    goto 0x8DAD;  // 0x8E01
    // branch body 0x8DAD
      area2.event_scratch0 = 0;  // 0x8DAE
      gosub 0xA0E4;  // 0x8DB4
      if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
      mapPosX = 8;  // 0x8DBB
      mapPosY = 0;  // 0x8DC1
      engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
      goto 0x8D2D;  // 0x8DCB
      // branch body 0x8D2D
        area2.event_scratch0 = 1;  // 0x8D2D
        gosub 0xA0E4;  // 0x8D33
        if_<>(<if compare flag is false, skip next op>);  // 0x8D38
        mapPosX = 0;  // 0x8D3A
        mapPosY = 8;  // 0x8D40
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
        // 0x8D4A-0x8D53
        area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
        if (area2.event_scratch0 != 0) {
          goto 0x8DCF;  // 0x8D54
        }
        printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
        area2.event_scratch0 = 0;  // 0x8DAE
        gosub 0xA0E4;  // 0x8DB4
        if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
        mapPosX = 8;  // 0x8DBB
        mapPosY = 0;  // 0x8DC1
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
        goto 0x8D2D;  // 0x8DCB
  }
  printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
  area2.event_scratch0 = 0;  // 0x8DAE
  gosub 0xA0E4;  // 0x8DB4
  if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
  mapPosX = 8;  // 0x8DBB
  mapPosY = 0;  // 0x8DC1
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
  goto 0x8D2D;  // 0x8DCB
  // branch body 0x8D2D
    // target 0x8D2D already emitted
}
```

## Event 05

- Target: `0x8D2D`
- Text hint: 'THERE IS A COMPUTER HERE.'

```text
event 05 {
  area2.event_scratch0 = 1;  // 0x8D2D
  gosub 0xA0E4;  // 0x8D33
  if_<>(<if compare flag is false, skip next op>);  // 0x8D38
  mapPosX = 0;  // 0x8D3A
  mapPosY = 8;  // 0x8D40
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
  // 0x8D4A-0x8D53
  area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
  if (area2.event_scratch0 != 0) {
    goto 0x8DCF;  // 0x8D54
    // branch body 0x8DCF
    // 0x8DCF-0x8DD8
    area2.event_scratch0 = 8 & area1.event_word_386;  // 0x8DCF
    if (area2.event_scratch0 != 0) {
      printclear('THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.');  // 0x8DD9
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x8E00
    goto 0x8DAD;  // 0x8E01
    // branch body 0x8DAD
      area2.event_scratch0 = 0;  // 0x8DAE
      gosub 0xA0E4;  // 0x8DB4
      if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
      mapPosX = 8;  // 0x8DBB
      mapPosY = 0;  // 0x8DC1
      engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
      goto 0x8D2D;  // 0x8DCB
      // branch body 0x8D2D
        // target 0x8D2D already emitted
  }
  printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
  area2.event_scratch0 = 0;  // 0x8DAE
  gosub 0xA0E4;  // 0x8DB4
  if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
  mapPosX = 8;  // 0x8DBB
  mapPosY = 0;  // 0x8DC1
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
  goto 0x8D2D;  // 0x8DCB
  // branch body 0x8D2D
    // target 0x8D2D already emitted
}
```

## Event 06

- Target: `0x8D4A`
- Text hint: 'THERE IS A COMPUTER HERE.'

```text
event 06 {
  // 0x8D4A-0x8D53
  area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
  if (area2.event_scratch0 != 0) {
    goto 0x8DCF;  // 0x8D54
    // branch body 0x8DCF
    // 0x8DCF-0x8DD8
    area2.event_scratch0 = 8 & area1.event_word_386;  // 0x8DCF
    if (area2.event_scratch0 != 0) {
      printclear('THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.');  // 0x8DD9
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x8E00
    goto 0x8DAD;  // 0x8E01
    // branch body 0x8DAD
      area2.event_scratch0 = 0;  // 0x8DAE
      gosub 0xA0E4;  // 0x8DB4
      if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
      mapPosX = 8;  // 0x8DBB
      mapPosY = 0;  // 0x8DC1
      engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
      goto 0x8D2D;  // 0x8DCB
      // branch body 0x8D2D
        area2.event_scratch0 = 1;  // 0x8D2D
        gosub 0xA0E4;  // 0x8D33
        if_<>(<if compare flag is false, skip next op>);  // 0x8D38
        mapPosX = 0;  // 0x8D3A
        mapPosY = 8;  // 0x8D40
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8D46
        // 0x8D4A-0x8D53
        area2.event_scratch0 = 4 & area1.event_word_386;  // 0x8D4A
        if (area2.event_scratch0 != 0) {
          goto 0x8DCF;  // 0x8D54
        }
        printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
        area2.event_scratch0 = 0;  // 0x8DAE
        gosub 0xA0E4;  // 0x8DB4
        if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
        mapPosX = 8;  // 0x8DBB
        mapPosY = 0;  // 0x8DC1
        engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
        goto 0x8D2D;  // 0x8DCB
  }
  printclear('THERE IS A COMPUTER HERE.');  // 0x8D58
  area2.event_scratch0 = 0;  // 0x8DAE
  gosub 0xA0E4;  // 0x8DB4
  if_<>(<if compare flag is false, skip next op>);  // 0x8DB9
  mapPosX = 8;  // 0x8DBB
  mapPosY = 0;  // 0x8DC1
  engine_call(raw: 0x2DCB, id: 0xADCC);  // 0x8DC7
  goto 0x8D2D;  // 0x8DCB
  // branch body 0x8D2D
    // target 0x8D2D already emitted
}
```

## Event 07

- Target: `0x8F12`
- Text hint: "'ROBOT CONTROL ROUTED TO SECONDARY CONTROL. INTRUDER ALERT!'"

```text
event 07 {
  // 0x8F12-0x8F1B
  area2.event_scratch0 = 1 & area1.event_word_384;  // 0x8F12
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8F1C
  }
  or(area1.event_word_384 = 1 | area1.event_word_384);  // 0x8F1D
  gosub 0xA11B;  // 0x8F26
  printclear("'ROBOT CONTROL ROUTED TO SECONDARY CONTROL. INTRUDER ALERT!'");  // 0x8F2A
  gosub 0xA0D8;  // 0x8F5A
  // 0x8F60-0x8F66
  if (mapDirection != 2) {
    exit_event();  // 0x8F67
  }
  // 0x8F68-0x8F71
  area2.event_scratch0 = 2 & area1.event_word_384;  // 0x8F68
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8F72
  }
  // 0x8F73-0x8F7C
  area2.event_scratch0 = 1 & area1.event_word_384;  // 0x8F73
  if (area2.event_scratch0 == 0) {
    printclear('A CIRCLE OF DEACTIVATED ROBOTS IS HERE.');  // 0x8F7D
  }
  if_=(<if compare flag is false, skip next op>);  // 0x8F9E
  exit_event();  // 0x8F9F
}
```

## Event 08

- Target: `0x8F60`
- Text hint: 'A CIRCLE OF DEACTIVATED ROBOTS IS HERE.'

```text
event 08 {
  // 0x8F60-0x8F66
  if (mapDirection != 2) {
    exit_event();  // 0x8F67
  }
  // 0x8F68-0x8F71
  area2.event_scratch0 = 2 & area1.event_word_384;  // 0x8F68
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8F72
  }
  // 0x8F73-0x8F7C
  area2.event_scratch0 = 1 & area1.event_word_384;  // 0x8F73
  if (area2.event_scratch0 == 0) {
    printclear('A CIRCLE OF DEACTIVATED ROBOTS IS HERE.');  // 0x8F7D
  }
  if_=(<if compare flag is false, skip next op>);  // 0x8F9E
  exit_event();  // 0x8F9F
}
```

## Event 09

- Target: `0x8FF0`
- Text hint: 'YOU ENTER A LARGE KITCHEN.'

```text
event 09 {
  // 0x8FF0-0x8FF9
  area2.event_scratch0 = 4 & area1.event_word_384;  // 0x8FF0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8FFA
  }
  or(area1.event_word_384 = 4 | area1.event_word_384);  // 0x8FFB
  printclear('YOU ENTER A LARGE KITCHEN.');  // 0x9004
  // 0x921E-0x9224
  if (mapDirection == 3) {
    exit_event();  // 0x9225
  }
  printclear('TO THE EAST IS THE ACCESS GRATE THAT THE STORMRIDERS TOLD YOU ABOUT. DO YOU GO THROUGH?');  // 0x9226
  // truncated at 0x9298
}
```

## Event 10

- Target: `0x921E`
- Text hint: 'TO THE EAST IS THE ACCESS GRATE THAT THE STORMRIDERS TOLD YOU ABOUT. DO YOU GO THROUGH?'

```text
event 10 {
  // 0x921E-0x9224
  if (mapDirection == 3) {
    exit_event();  // 0x9225
  }
  printclear('TO THE EAST IS THE ACCESS GRATE THAT THE STORMRIDERS TOLD YOU ABOUT. DO YOU GO THROUGH?');  // 0x9226
  // 0x9298-0x929E
  if (area1.event_word_20C == 1) {
    area1.event_word_20C = 0;  // 0x929F
  }
  if_=(<if compare flag is false, skip next op>);  // 0x92A5
  exit_event();  // 0x92A6
}
```

## Event 11

- Target: `0x9298`
- Text hint: 'SOMEONE IS POUNDING ON THE NORTH DOOR FROM THE OTHER SIDE.'

```text
event 11 {
  // 0x9298-0x929E
  if (area1.event_word_20C == 1) {
    area1.event_word_20C = 0;  // 0x929F
  }
  if_=(<if compare flag is false, skip next op>);  // 0x92A5
  exit_event();  // 0x92A6
}
```

## Event 12

- Target: `0x92E3`
- Text hint: 'YOUR EQUIPMENT IS HERE!' ' YOU QUICKLY REARM.'

```text
event 12 {
  // 0x92E3-0x92EC
  area2.event_scratch0 = 8 & area1.event_word_384;  // 0x92E3
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x92ED
  }
  or(area1.event_word_384 = 8 | area1.event_word_384);  // 0x92EE
  printclear('YOUR EQUIPMENT IS HERE!');  // 0x92F7
  delay();  // 0x930C
  print(' YOU QUICKLY REARM.');  // 0x930D
  exit_event();  // 0x9320
}
```

## Event 13

- Target: `0x938A`
- Text hint: 'REMOTE ROBOT CONTROL CENTER'

```text
event 13 {
  // 0x938A-0x9393
  area2.event_scratch0 = 16 & area1.event_word_384;  // 0x938A
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9394
  }
  setup_monster(sprite_id: 50 max_distance: 0 pic_id: 255);  // 0x9395
  exit_event();  // 0x939C
}
```

## Event 14

- Target: `0x94B8`
- Text hint: 'REMOTE ROBOT CONTROL CENTER'

```text
event 14 {
  // 0x94B8-0x94BE
  if (mapDirection != 0) {
    exit_event();  // 0x94BF
  }
  gosub 0xA139;  // 0x94C0
  print('REMOTE ROBOT CONTROL CENTER');  // 0x94C4
  // 0x94DE-0x94E7
  area2.event_scratch0 = 16 & area1.event_word_384;  // 0x94DE
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x94E8
  }
  // 0x94E9-0x94F2
  area2.event_scratch0 = 32 & area1.event_word_384;  // 0x94E9
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x94F3
  }
  or(area1.event_word_384 = 32 | area1.event_word_384);  // 0x94F4
  setup_monster(sprite_id: 51 max_distance: 2 pic_id: 255);  // 0x94FD
  exit_event();  // 0x9504
}
```

## Event 15

- Target: `0x94DE`
- Text hint: 'A SIGN OVER THE NORTH DOOR READS:' RETURN

```text
event 15 {
  // 0x94DE-0x94E7
  area2.event_scratch0 = 16 & area1.event_word_384;  // 0x94DE
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x94E8
  }
  // 0x94E9-0x94F2
  area2.event_scratch0 = 32 & area1.event_word_384;  // 0x94E9
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x94F3
  }
  or(area1.event_word_384 = 32 | area1.event_word_384);  // 0x94F4
  setup_monster(sprite_id: 51 max_distance: 2 pic_id: 255);  // 0x94FD
  exit_event();  // 0x9504
}
```

## Event 16

- Target: `0x954D`
- Text hint: 'A SIGN OVER THE NORTH DOOR READS:' RETURN

```text
event 16 {
  // 0x954D-0x9553
  if (mapDirection == 2) {
    exit_event();  // 0x9554
  }
  // 0x9555-0x955B
  if (mapDirection == 0) {
    exit_event();  // 0x955C
  }
  printclear('A SIGN OVER THE NORTH DOOR READS:');  // 0x955D
  print_return();  // 0x9579
  print_return();  // 0x957A
  print('     HIGH SECURITY LAB');  // 0x957B
  print_return();  // 0x958F
  print('  AUTHORIZED PERSONNEL ONLY');  // 0x9590
  exit_event();  // 0x95A8
}
```

## Event 17

- Target: `0x95A9`
- Text hint: 'YOU ENTER A COMMUNICATION CENTER. A SOLDIER RADIOS FOR HELP.'

```text
event 17 {
  // 0x95A9-0x95B2
  area2.event_scratch0 = 64 & area1.event_word_384;  // 0x95A9
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x95B3
  }
  or(area1.event_word_384 = 64 | area1.event_word_384);  // 0x95B4
  printclear('YOU ENTER A COMMUNICATION CENTER. A SOLDIER RADIOS FOR HELP.');  // 0x95BD
  // 0x9682-0x9688
  if (mapDirection != 2) {
    exit_event();  // 0x9689
  }
  printclear('YOU ENTER A COLD STORAGE ROOM.');  // 0x968A
  // 0x97AF-0x97B5
  if (mapDirection != 1) {
    exit_event();  // 0x97B6
  }
  printclear('THERE IS LIFE SUSPENSION EQUIPMENT HERE.');  // 0x97B7
  // 0x97D8-0x97E1
  area2.event_scratch0 = 128 & area1.event_word_384;  // 0x97D8
  if (area2.event_scratch0 == 0) {
    if_=(<if compare flag is false, skip next op>);  // 0x97E3
  }
  // 0x97E5-0x97EE
  area2.event_scratch0 = 1 & area1.event_word_386;  // 0x97E5
  if (area2.event_scratch0 != 0) {
    if_<>(<if compare flag is false, skip next op>);  // 0x97F0
  }
  exit_event();  // 0x97F1
}
```

## Event 18

- Target: `0x9682`
- Text hint: 'YOU ENTER A COLD STORAGE ROOM.'

```text
event 18 {
  // 0x9682-0x9688
  if (mapDirection != 2) {
    exit_event();  // 0x9689
  }
  printclear('YOU ENTER A COLD STORAGE ROOM.');  // 0x968A
  // 0x97AF-0x97B5
  if (mapDirection != 1) {
    exit_event();  // 0x97B6
  }
  printclear('THERE IS LIFE SUSPENSION EQUIPMENT HERE.');  // 0x97B7
  // 0x97D8-0x97E1
  area2.event_scratch0 = 128 & area1.event_word_384;  // 0x97D8
  if (area2.event_scratch0 == 0) {
    if_=(<if compare flag is false, skip next op>);  // 0x97E3
  }
  // 0x97E5-0x97EE
  area2.event_scratch0 = 1 & area1.event_word_386;  // 0x97E5
  if (area2.event_scratch0 != 0) {
    if_<>(<if compare flag is false, skip next op>);  // 0x97F0
  }
  exit_event();  // 0x97F1
}
```

## Event 19

- Target: `0x97AF`
- Text hint: 'THERE IS LIFE SUSPENSION EQUIPMENT HERE.'

```text
event 19 {
  // 0x97AF-0x97B5
  if (mapDirection != 1) {
    exit_event();  // 0x97B6
  }
  printclear('THERE IS LIFE SUSPENSION EQUIPMENT HERE.');  // 0x97B7
  // 0x97D8-0x97E1
  area2.event_scratch0 = 128 & area1.event_word_384;  // 0x97D8
  if (area2.event_scratch0 == 0) {
    if_=(<if compare flag is false, skip next op>);  // 0x97E3
  }
  // 0x97E5-0x97EE
  area2.event_scratch0 = 1 & area1.event_word_386;  // 0x97E5
  if (area2.event_scratch0 != 0) {
    if_<>(<if compare flag is false, skip next op>);  // 0x97F0
  }
  exit_event();  // 0x97F1
}
```

## Event 20

- Target: `0x98B4`
- Text hint: '       QUARANTINE'

```text
event 20 {
  gosub 0xA139;  // 0x98B4
  print('       QUARANTINE');  // 0x98B8
  exit_event();  // 0x98C8
}
```

## Event 21

- Target: `0x98C9`
- Text hint: 'THE MAIN SECURITY COMPUTER IS HERE. ' 'IT IS DEACTIVATED.'

```text
event 21 {
  // 0x98C9-0x98D2
  area2.event_scratch0 = 2 & area1.event_word_386;  // 0x98C9
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x98D3
  }
  setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x98D4
  exit_event();  // 0x98DB
}
```

## Event 22

- Target: `0x9979`
- Text hint: 'THE MAIN SECURITY COMPUTER IS HERE. ' 'IT IS DEACTIVATED.'

```text
event 22 {
  printclear('THE MAIN SECURITY COMPUTER IS HERE. ');  // 0x9979
  // 0x9997-0x99A0
  area2.event_scratch0 = 4 & area1.event_word_386;  // 0x9997
  if (area2.event_scratch0 != 0) {
    print('IT IS DEACTIVATED.');  // 0x99A1
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x99B2
  exit_event();  // 0x99B3
}
```

## Event 23

- Target: `0x9A54`
- Text hint: 'YOU ENTER A GENETICS LAB. THERE ARE GROW TANKS ACROSS THE ROOM.'

```text
event 23 {
  // 0x9A54-0x9A5D
  area2.event_scratch0 = 32 & area1.event_word_386;  // 0x9A54
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9A5E
  }
  setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x9A5F
  exit_event();  // 0x9A66
}
```

## Event 24

- Target: `0x9AEA`
- Text hint: 'YOU ENTER A GENETICS LAB. THERE ARE GROW TANKS ACROSS THE ROOM.'

```text
event 24 {
  // 0x9AEA-0x9AF0
  if (mapDirection != 3) {
    exit_event();  // 0x9AF1
  }
  printclear('YOU ENTER A GENETICS LAB. THERE ARE GROW TANKS ACROSS THE ROOM.');  // 0x9AF2
  // 0x9B27-0x9B30
  area2.event_scratch0 = 64 & area1.event_word_386;  // 0x9B27
  if (area2.event_scratch0 != 0) {
    goto 0x9D2B;  // 0x9B31
    // branch body 0x9D2B
    printclear('WASPHOPPERS POUR OUT OF THIS GROW VAT.');  // 0x9D2B
    gosub 0xA19B;  // 0x9D4B
    compare(Values: mapDirection == 2);  // 0x9D51
    goto 0x9AF0;  // 0x9D57
    // branch body 0x9AF0
      if_<>(<if compare flag is false, skip next op>);  // 0x9AF0
      exit_event();  // 0x9AF1
  }
  printclear('YOU APPROACH THE GROW VAT. IT IS FULL OF FLUID--READY TO USE.');  // 0x9B35
  printclear('WASPHOPPERS POUR OUT OF THIS GROW VAT.');  // 0x9D2B
  gosub 0xA19B;  // 0x9D4B
  compare(Values: mapDirection == 2);  // 0x9D51
  goto 0x9AF0;  // 0x9D57
  // branch body 0x9AF0
    // target 0x9AF0 already emitted
}
```

## Event 25

- Target: `0x9B27`
- Text hint: 'YOU APPROACH THE GROW VAT. IT IS FULL OF FLUID--READY TO USE.'

```text
event 25 {
  // 0x9B27-0x9B30
  area2.event_scratch0 = 64 & area1.event_word_386;  // 0x9B27
  if (area2.event_scratch0 != 0) {
    goto 0x9D2B;  // 0x9B31
    // branch body 0x9D2B
    printclear('WASPHOPPERS POUR OUT OF THIS GROW VAT.');  // 0x9D2B
    gosub 0xA19B;  // 0x9D4B
    compare(Values: mapDirection == 2);  // 0x9D51
    goto 0x9AF0;  // 0x9D57
    // branch body 0x9AF0
      if_<>(<if compare flag is false, skip next op>);  // 0x9AF0
      exit_event();  // 0x9AF1
  }
  printclear('YOU APPROACH THE GROW VAT. IT IS FULL OF FLUID--READY TO USE.');  // 0x9B35
  printclear('WASPHOPPERS POUR OUT OF THIS GROW VAT.');  // 0x9D2B
  gosub 0xA19B;  // 0x9D4B
  compare(Values: mapDirection == 2);  // 0x9D51
  goto 0x9AF0;  // 0x9D57
  // branch body 0x9AF0
    // target 0x9AF0 already emitted
}
```

## Event 26

- Target: `0x9D51`
- Text hint: 'THIS GROW VAT HAS BEEN DRAINED.'

```text
event 26 {
  compare(Values: mapDirection == 2);  // 0x9D51
  goto 0x9AF0;  // 0x9D57
  // branch body 0x9AF0
    if_<>(<if compare flag is false, skip next op>);  // 0x9AF0
    exit_event();  // 0x9AF1
}
```

## Event 27

- Target: `0x9D5B`
- Text hint: 'THIS GROW VAT HAS BEEN DRAINED.'

```text
event 27 {
  printclear('THIS GROW VAT HAS BEEN DRAINED.');  // 0x9D5B
  exit_event();  // 0x9D76
}
```

## Event 28

- Target: `0x9D77`
- Text hint: "MARIO QUINN'S BODY LIES HERE."

```text
event 28 {
  // 0x9D77-0x9D80
  area2.event_scratch0 = 64 & area1.event_word_386;  // 0x9D77
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9D81
  }
  // 0x9D82-0x9D8B
  area2.event_scratch0 = 128 & area1.event_word_386;  // 0x9D82
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9D8C
  }
  or(area1.event_word_386 = 128 | area1.event_word_386);  // 0x9D8D
  setup_monster(sprite_id: 64 max_distance: 2 pic_id: 255);  // 0x9D96
  exit_event();  // 0x9D9D
}
```

## Event 29

- Target: `0x9EFB`
- Text hint: "MARIO QUINN'S BODY LIES HERE."

```text
event 29 {
  // 0x9EFB-0x9F04
  area2.event_scratch0 = 64 & area1.event_word_386;  // 0x9EFB
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9F05
  }
  printclear("MARIO QUINN'S BODY LIES HERE.");  // 0x9F06
  // 0x9F21-0x9F2A
  area2.event_scratch0 = 8 & area1.event_word_386;  // 0x9F21
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9F2B
  }
  // 0x9F2C-0x9F35
  area2.event_scratch0 = 1 & area1.event_word_38C;  // 0x9F2C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9F36
  }
  or(area1.event_word_38C = 1 | area1.event_word_38C);  // 0x9F37
  picture(block_id: 29);  // 0x9F40
  printclear('A GROUP OF STORMRIDERS MEET YOU. ONE SPEAKS.');  // 0x9F43
  printclear('THERE IS A COMPUTER TERMINAL HERE. ');  // 0xA05E
  // 0xA07C-0xA085
  area2.event_scratch0 = 8 & area1.event_word_386;  // 0xA07C
  if (area2.event_scratch0 == 0) {
    print('CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.');  // 0xA086
  }
  if_=(<if compare flag is false, skip next op>);  // 0xA0B9
  if_=(<if compare flag is false, skip next op>);  // 0xA0BB
  print('IT IS DEACTIVATED.');  // 0xA0BD
  exit_event();  // 0xA0D0
}
```

## Event 30

- Target: `0x9F21`
- Text hint: 'A GROUP OF STORMRIDERS MEET YOU. ONE SPEAKS.' 'THERE IS A COMPUTER TERMINAL HERE. ' 'CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.'

```text
event 30 {
  // 0x9F21-0x9F2A
  area2.event_scratch0 = 8 & area1.event_word_386;  // 0x9F21
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9F2B
  }
  // 0x9F2C-0x9F35
  area2.event_scratch0 = 1 & area1.event_word_38C;  // 0x9F2C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9F36
  }
  or(area1.event_word_38C = 1 | area1.event_word_38C);  // 0x9F37
  picture(block_id: 29);  // 0x9F40
  printclear('A GROUP OF STORMRIDERS MEET YOU. ONE SPEAKS.');  // 0x9F43
  printclear('THERE IS A COMPUTER TERMINAL HERE. ');  // 0xA05E
  // 0xA07C-0xA085
  area2.event_scratch0 = 8 & area1.event_word_386;  // 0xA07C
  if (area2.event_scratch0 == 0) {
    print('CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.');  // 0xA086
  }
  if_=(<if compare flag is false, skip next op>);  // 0xA0B9
  if_=(<if compare flag is false, skip next op>);  // 0xA0BB
  print('IT IS DEACTIVATED.');  // 0xA0BD
  exit_event();  // 0xA0D0
}
```

## Event 31

- Target: `0xA05E`
- Text hint: 'THERE IS A COMPUTER TERMINAL HERE. ' 'CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.' 'IT IS DEACTIVATED.'

```text
event 31 {
  printclear('THERE IS A COMPUTER TERMINAL HERE. ');  // 0xA05E
  // 0xA07C-0xA085
  area2.event_scratch0 = 8 & area1.event_word_386;  // 0xA07C
  if (area2.event_scratch0 == 0) {
    print('CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.');  // 0xA086
  }
  if_=(<if compare flag is false, skip next op>);  // 0xA0B9
  if_=(<if compare flag is false, skip next op>);  // 0xA0BB
  print('IT IS DEACTIVATED.');  // 0xA0BD
  exit_event();  // 0xA0D0
}
```
