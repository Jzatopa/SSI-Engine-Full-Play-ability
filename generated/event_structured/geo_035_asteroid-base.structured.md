# GEO 35: Asteroid Base

ECL block: `35`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8543`
- Text hint: 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY ' '1' '2'

```text
event 01 {
  printclear('YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY ');  // 0x8543
  // 0x8566-0x856C
  if (1 == area2.event_scratch0) {
    print('1');  // 0x856D
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8571
  print('2');  // 0x8572
  print(' AND CERES BASE.');  // 0x8576
  exit_event();  // 0x8585
}
```

## Event 02

- Target: `0x8543`
- Text hint: 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY ' '1' '2'

```text
event 02 {
  printclear('YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY ');  // 0x8543
  // 0x8566-0x856C
  if (1 == area2.event_scratch0) {
    print('1');  // 0x856D
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8571
  print('2');  // 0x8572
  print(' AND CERES BASE.');  // 0x8576
  exit_event();  // 0x8585
}
```

## Event 03

- Target: `0x8586`
- Text hint: "THIS DOOR READS 'SECURITY STATION.'"

```text
event 03 {
  // 0x8586-0x858C
  if (2 != mapDirection) {
    printclear("THIS DOOR READS 'SECURITY STATION.'");  // 0x858D
  }
  exit_event();  // 0x85AB
}
```

## Event 04

- Target: `0x840C`
- Text hint: 'A HUGE EXPLOSION ROCKS THE BASE! THE DEMOLITION CHARGES HAVE DETONATED!'

```text
event 04 {
  exit_event();  // 0x840C
}
```

## Event 05

- Target: `0x85AC`
- Text hint: "GUARDS STOP YOU. 'THE COMMAND CENTER IS OFF LIMITS.'"

```text
event 05 {
  // 0x85AC-0x85B2
  if (0 != mapDirection) {
    exit_event();  // 0x85B3
  }
  // 0x85B4-0x85BD
  area2.event_scratch0 = area1.event_word_3AC & 8;  // 0x85B4
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x85BE
  }
  // 0x85BF-0x85C8
  area2.event_scratch0 = area1.event_word_3B0 & 1;  // 0x85BF
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x85C9
  }
  area1.event_word_208 = 3;  // 0x85CA
  gosub 0x9ED5;  // 0x85D0
  printclear("GUARDS STOP YOU. 'THE COMMAND CENTER IS OFF LIMITS.'");  // 0x85D4
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK');  // 0x85FE
  // 0x8611-0x8617
  if (0 == area2.event_scratch0) {
    goto 0xA208;  // 0x8618
    // branch body 0xA208
    mapPosX = area1.lastXPos;  // 0xA208
    mapPosY = area1.lastYPos;  // 0xA20F
    printclear("THE GENERAL SAYS, 'YOU'VE KEPT ME WAITING, SUAREZ. I DISLIKE THAT.'");  // 0xA217
  }
  gosub 0xA0AC;  // 0x861C
  or(area1.event_word_3AC = area1.event_word_3AC | 8);  // 0x8620
  exit_event();  // 0x8629
}
```

## Event 06

- Target: `0x862A`
- Text hint: "'ARMORY.'"

```text
event 06 {
  exit_event();  // 0x862A
}
```

## Event 07

- Target: `0x862B`
- Text hint: "'ARMORY.'"

```text
event 07 {
  // 0x862B-0x8631
  if (3 == mapDirection) {
    exit_event();  // 0x8632
  }
  printclear("'ARMORY.'");  // 0x8633
  exit_event();  // 0x863D
}
```

## Event 08

- Target: `0x863E`
- Text hint: "A NAME PLATE ON THIS DOOR READS, 'GEN. MAVROUDIS, BASE COMMANDER.'"

```text
event 08 {
  // 0x863E-0x8644
  if (2 == mapDirection) {
    exit_event();  // 0x8645
  }
  printclear("A NAME PLATE ON THIS DOOR READS, 'GEN. MAVROUDIS, BASE COMMANDER.'");  // 0x8646
  exit_event();  // 0x867B
}
```

## Event 09

- Target: `0x867C`
- Text hint: "THIS DOOR IS MARKED 'LASER CONTROL.'"

```text
event 09 {
  // 0x867C-0x8682
  if (2 == mapDirection) {
    exit_event();  // 0x8683
  }
  printclear("THIS DOOR IS MARKED 'LASER CONTROL.'");  // 0x8684
  exit_event();  // 0x86A2
}
```

## Event 10

- Target: `0x86A3`
- Text hint: 'VARIOUS MAINTAINENCE ITEMS ARE STORED HERE.'

```text
event 10 {
  printclear('VARIOUS MAINTAINENCE ITEMS ARE STORED HERE.');  // 0x86A3
  exit_event();  // 0x86C7
}
```

## Event 11

- Target: `0x86C8`
- Text hint: "'GUARD QUARTERS.'"

```text
event 11 {
  // 0x86C8-0x86CE
  if (0 != mapDirection) {
    exit_event();  // 0x86CF
  }
  printclear("'GUARD QUARTERS.'");  // 0x86D0
  exit_event();  // 0x86E0
}
```

## Event 12

- Target: `0x86E1`
- Text hint: 'YOU ENTER THE COMMAND CENTER.'

```text
event 12 {
  // 0x86E1-0x86E7
  if (0 != abs_C04E) {
    exit_event();  // 0x86E8
  }
  // 0x86E9-0x86EF
  if (mapDirection == 3) {
    exit_event();  // 0x86F0
  }
  compare_and(Values: 11 == mapPosY && 1 == mapDirection);  // 0x86F1
  if_=(<if compare flag is false, skip next op>);  // 0x86FC
  exit_event();  // 0x86FD
}
```

## Event 13

- Target: `0x8917`
- Text hint: "A SIGN ON THE WEST DOOR READS, 'CONFERENCE ROOM.' STENCILED ON THE EAST DOOR IS 'MESS HALL.'"

```text
event 13 {
  // 0x8917-0x891D
  if (0 != abs_C04E) {
    exit_event();  // 0x891E
  }
  printclear("A SIGN ON THE WEST DOOR READS, 'CONFERENCE ROOM.' STENCILED ON THE EAST DOOR IS 'MESS HALL.'");  // 0x891F
  exit_event();  // 0x8967
}
```

## Event 14

- Target: `0x8968`
- Text hint: 'THE MESS HALL IS ' 'EMPTY.'

```text
event 14 {
  // 0x8968-0x896E
  if (1 != mapDirection) {
    exit_event();  // 0x896F
  }
  printclear('THE MESS HALL IS ');  // 0x8970
  // 0x8980-0x8989
  area2.event_scratch0 = area1.event_word_3AC & 2;  // 0x8980
  if (area2.event_scratch0 != 0) {
    print('EMPTY.');  // 0x898A
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8992
  exit_event();  // 0x8993
}
```

## Event 15

- Target: `0x89E9`
- Text hint: 'THIS IS A ILL-EQUIPPED KITCHEN. PROCESSED FOOD SUPPLIES LINE THE WALLS.'

```text
event 15 {
  // 0x89E9-0x89EF
  if (2 != mapDirection) {
    exit_event();  // 0x89F0
  }
  printclear('THIS IS A ILL-EQUIPPED KITCHEN. PROCESSED FOOD SUPPLIES LINE THE WALLS.');  // 0x89F1
  exit_event();  // 0x8A2A
}
```

## Event 16

- Target: `0x8A2B`
- Text hint: 'YOU ENTER THE SECURITY AREA' '.'

```text
event 16 {
  // 0x8A2B-0x8A31
  if (0 != abs_C04E) {
    exit_event();  // 0x8A32
  }
  printclear('YOU ENTER THE SECURITY AREA');  // 0x8A33
  // 0x8A4B-0x8A54
  area2.event_scratch0 = area1.event_word_3AC & 4;  // 0x8A4B
  if (area2.event_scratch0 != 0) {
    print('.');  // 0x8A55
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8A59
  exit_event();  // 0x8A5A
}
```

## Event 17

- Target: `0x8C29`
- Text hint: 'THIS DOOR IS STENCILED ' "'WOMAN" "'MEN"

```text
event 17 {
  printclear('THIS DOOR IS STENCILED ');  // 0x8C29
  // 0x8C3E-0x8C44
  if (17 != area2.event_scratch0) {
    print("'WOMAN");  // 0x8C45
  }
  if_=(<if compare flag is false, skip next op>);  // 0x8C4D
  print("'MEN");  // 0x8C4E
  print("'S LAVATORY.'");  // 0x8C54
  exit_event();  // 0x8C61
}
```

## Event 18

- Target: `0x8C29`
- Text hint: 'THIS DOOR IS STENCILED ' "'WOMAN" "'MEN"

```text
event 18 {
  printclear('THIS DOOR IS STENCILED ');  // 0x8C29
  // 0x8C3E-0x8C44
  if (17 != area2.event_scratch0) {
    print("'WOMAN");  // 0x8C45
  }
  if_=(<if compare flag is false, skip next op>);  // 0x8C4D
  print("'MEN");  // 0x8C4E
  print("'S LAVATORY.'");  // 0x8C54
  exit_event();  // 0x8C61
}
```

## Event 19

- Target: `0x8C62`
- Text hint: "'CONFERENCE ROOM.'"

```text
event 19 {
  // 0x8C62-0x8C68
  if (0 != abs_C04E) {
    exit_event();  // 0x8C69
  }
  printclear("'CONFERENCE ROOM.'");  // 0x8C6A
  exit_event();  // 0x8C7B
}
```

## Event 20

- Target: `0x8C7C`
- Text hint: 'THE ARMORY IS POORLY STOCKED. ONLY A FEW RIFLES ARE HERE.'

```text
event 20 {
  // 0x8C7C-0x8C85
  area2.event_scratch0 = area1.event_word_3AC & 16;  // 0x8C7C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C86
  }
  printclear('THE ARMORY IS POORLY STOCKED. ONLY A FEW RIFLES ARE HERE.');  // 0x8C87
  // 0x8D1B-0x8D21
  if (0 != mapDirection) {
    exit_event();  // 0x8D22
  }
  printclear("THIS IS THE BASE'S POWER CENTER. HUGE CABLES SNAKE IN AND OUT OF THIS ROOM.");  // 0x8D23
  exit_event();  // 0x8D5F
}
```

## Event 21

- Target: `0x8D1B`
- Text hint: "THIS IS THE BASE'S POWER CENTER. HUGE CABLES SNAKE IN AND OUT OF THIS ROOM."

```text
event 21 {
  // 0x8D1B-0x8D21
  if (0 != mapDirection) {
    exit_event();  // 0x8D22
  }
  printclear("THIS IS THE BASE'S POWER CENTER. HUGE CABLES SNAKE IN AND OUT OF THIS ROOM.");  // 0x8D23
  exit_event();  // 0x8D5F
}
```

## Event 22

- Target: `0x8D60`
- Text hint: "'RESTRICTED ACCESS' IS PRINTED ON THE DOOR. YOU HEAR A STEADY HUM."

```text
event 22 {
  // 0x8D60-0x8D66
  if (3 != mapDirection) {
    exit_event();  // 0x8D67
  }
  printclear("'RESTRICTED ACCESS' IS PRINTED ON THE DOOR. YOU HEAR A STEADY HUM.");  // 0x8D68
  exit_event();  // 0x8D9D
}
```

## Event 23

- Target: `0x8D9E`
- Text hint: 'THE LARGE CONFERENCE ROOM IS EMPTY, BUT RECENTLY USED.'

```text
event 23 {
  // 0x8D9E-0x8DA4
  if (0 != abs_C04E) {
    exit_event();  // 0x8DA5
  }
  printclear('THE LARGE CONFERENCE ROOM IS EMPTY, BUT RECENTLY USED.');  // 0x8DA6
  area2.event_scratch1 = 1;  // 0x8DD2
  area2.event_scratch2 = 2;  // 0x8DD8
  // 0x8DDE-0x8DE7
  area2.event_scratch0 = area1.event_word_3AE & 2;  // 0x8DDE
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8DE8
  }
  or(area1.event_word_3AE = area1.event_word_3AE | 2);  // 0x8DE9
  party_surprise(zone: 83, result: area2.event_scratch1);  // 0x8DF2
  // 0x8DFB-0x8E01
  if (2 < area2.event_scratch2) {
    exit_event();  // 0x8E02
  }
  printclear('<string at area2.selected_player_name>');  // 0x8E04
  print(" NOTICES A FALLEN NOTE. IT READS, 'KANE IS READY TO DEAL. ENVOY WILL ARRIVE WITHIN THE HOUR.'");  // 0x8E08
  exit_event();  // 0x8E51
}
```

## Event 24

- Target: `0x8E52`
- Text hint: "MAVROUDIS' OFFICE IS IMMACULATE, AND SMELLS STRONGLY OF LEATHER. AGAINST THE EAST WALL IS A COMPUTER."

```text
event 24 {
  // 0x8E52-0x8E58
  if (0 != mapDirection) {
    exit_event();  // 0x8E59
  }
  printclear("MAVROUDIS' OFFICE IS IMMACULATE, AND SMELLS STRONGLY OF LEATHER. AGAINST THE EAST WALL IS A COMPUTER.");  // 0x8E5A
  exit_event();  // 0x8EA9
}
```

## Event 25

- Target: `0x8EAA`
- Text hint: 'THE SECURITY PROGRAM HAS BEEN TRIPPED. THE COMPUTER HAS LOCKED ITS FILES, AND THE BASE ALERT HAS BEEN SOUNDED.'

```text
event 25 {
  // 0x8EAA-0x8EB3
  area2.event_scratch0 = area1.event_word_3AE & 128;  // 0x8EAA
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8EB4
  }
  who(<select player> 'WHO WILL REPROGRAM?');  // 0x8EB5
  // 0x8EC7-0x8ECD
  if (1 != area2.selected_player_in_combat) {
    goto 0x8EB5;  // 0x8ECE
    // branch body 0x8EB5
    who(<select player> 'WHO WILL REPROGRAM?');  // 0x8EB5
    // 0x8EC7-0x8ECD
    if (1 != area2.selected_player_in_combat) {
      goto 0x8EB5;  // 0x8ECE
      // branch body 0x8EB5
      // target 0x8EB5 already emitted
    }
    gosub 0x9EBF;  // 0x8ED2
    // 0x8ED6-0x8EDC
    if (2 >= area2.event_scratch2) {
      goto 0x8F4A;  // 0x8EDD
      // branch body 0x8F4A
      // 0x8F4A-0x8F53
      area2.event_scratch0 = area1.event_word_3AE & 1;  // 0x8F4A
      if (area2.event_scratch0 != 0) {
        goto 0x8F8C;  // 0x8F54
        // branch body 0x8F8C
        printclear('WHAT INFORMATION DO YOU ATTEMPT TO ACCESS?');  // 0x8F8C
        // 0x8FAF-0x8FB8
        area2.event_scratch0 = area1.event_word_3AE & 2;  // 0x8FAF
        if (area2.event_scratch0 != 0) {
          goto 0x8FED;  // 0x8FB9
        }
        horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'QUIT', 'MAVROUDIS', 'DOOMSDAY LASER');  // 0x8FBD
        // 0x8FDE
        switch (area2.event_scratch0) {
          case 0: goto 0x9025;
          case 1: goto 0x903B;
          case 2: goto 0x909B;
        }
      }
      printclear('YOU HAVE LOGGED ON, AND ARE FACING AN ACCESS PROMPT.');  // 0x8F58
      or(area1.event_word_3AE = area1.event_word_3AE | 1);  // 0x8F82
      printclear('WHAT INFORMATION DO YOU ATTEMPT TO ACCESS?');  // 0x8F8C
      // 0x8FAF-0x8FB8
      area2.event_scratch0 = area1.event_word_3AE & 2;  // 0x8FAF
      if (area2.event_scratch0 != 0) {
        goto 0x8FED;  // 0x8FB9
        // branch body 0x8FED
        horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'QUIT', 'MAVORUDIS', 'DOOMSDAY LASER', 'KANE');  // 0x8FED
        // 0x9013
        switch (area2.event_scratch0) {
          case 0: goto 0x9025;
          case 1: goto 0x903B;
          case 2: goto 0x909B;
          case 3: goto 0x9115;
        }
      }
      horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'QUIT', 'MAVROUDIS', 'DOOMSDAY LASER');  // 0x8FBD
      // 0x8FDE
      switch (area2.event_scratch0) {
        case 0: goto 0x9025;
        case 1: goto 0x903B;
        case 2: goto 0x909B;
      }
    }
    printclear('THE SECURITY PROGRAM HAS BEEN TRIPPED. THE COMPUTER HAS LOCKED ITS FILES, AND THE BASE ALERT HAS BEEN SOUNDED.');  // 0x8EE1
    or(area1.event_word_3B0 = area1.event_word_3B0 | 16);  // 0x8F37
    or(area1.event_word_3AE = area1.event_word_3AE | 128);  // 0x8F40
    exit_event();  // 0x8F49
  }
  gosub 0x9EBF;  // 0x8ED2
  // 0x8ED6-0x8EDC
  if (2 >= area2.event_scratch2) {
    goto 0x8F4A;  // 0x8EDD
    // branch body 0x8F4A
    // target 0x8F4A already emitted
  }
  printclear('THE SECURITY PROGRAM HAS BEEN TRIPPED. THE COMPUTER HAS LOCKED ITS FILES, AND THE BASE ALERT HAS BEEN SOUNDED.');  // 0x8EE1
  or(area1.event_word_3B0 = area1.event_word_3B0 | 16);  // 0x8F37
  or(area1.event_word_3AE = area1.event_word_3AE | 128);  // 0x8F40
  exit_event();  // 0x8F49
}
```

## Event 26

- Target: `0x9174`
- Text hint: "THE GENERAL'S LIVING QUARTERS ARE SPARSELY FURNISHED."

```text
event 26 {
  // 0x9174-0x917A
  if (1 != mapDirection) {
    exit_event();  // 0x917B
  }
  printclear("THE GENERAL'S LIVING QUARTERS ARE SPARSELY FURNISHED.");  // 0x917C
  exit_event();  // 0x91A7
}
```

## Event 27

- Target: `0x91A8`
- Text hint: 'THE HUM OF MACHINERY FILLS THE ROOM. LARGE CONSOLES LINE THE WALLS.'

```text
event 27 {
  printclear('THE HUM OF MACHINERY FILLS THE ROOM. LARGE CONSOLES LINE THE WALLS.');  // 0x91A8
  exit_event();  // 0x91DE
}
```

## Event 28

- Target: `0x91DF`
- Text hint: 'THIS ROOM APPEARS TO BE A DEDICATED COMMUNICATIONS AREA.'

```text
event 28 {
  // 0x91DF-0x91E5
  if (0 != abs_C04E) {
    exit_event();  // 0x91E6
  }
  printclear('THIS ROOM APPEARS TO BE A DEDICATED COMMUNICATIONS AREA.');  // 0x91E7
  exit_event();  // 0x9214
}
```

## Event 29

- Target: `0x9215`
- Text hint: '<string at area2.selected_player_name>' ' NOTICES A RAM HEAVY CRUISER ORBITING THE BASE.'

```text
event 29 {
  // 0x9215-0x921E
  area2.event_scratch0 = area1.event_word_3B0 & 32;  // 0x9215
  if (area2.event_scratch0 != 0) {
    goto 0x92B2;  // 0x921F
    // branch body 0x92B2
    printclear('THE SENSORS NOW SHOW DEBRIS. THE RAM HEAVY CRUISER HAS BEEN DESTROYED.');  // 0x92B2
    exit_event();  // 0x92EA
  }
  // 0x9223-0x922C
  area2.event_scratch0 = area1.event_word_3AC & 128;  // 0x9223
  if (area2.event_scratch0 != 0) {
    goto 0x9282;  // 0x922D
    // branch body 0x9282
    load_character(index: area1.event_word_20A);  // 0x9282
    printclear('<string at area2.selected_player_name>');  // 0x9286
    print(' NOTICES A RAM HEAVY CRUISER ORBITING THE BASE.');  // 0x928A
    exit_event();  // 0x92B1
  }
  area2.event_scratch1 = 1;  // 0x9231
  area2.event_scratch2 = 2;  // 0x9237
  party_surprise(zone: 9, result: area2.event_scratch1);  // 0x923D
  // 0x9246-0x924C
  if (2 >= area2.event_scratch2) {
    goto 0x9272;  // 0x924D
    // branch body 0x9272
    area1.event_word_20A = area2.event_scratch1;  // 0x9272
    or(area1.event_word_3AC = area1.event_word_3AC | 128);  // 0x9279
    load_character(index: area1.event_word_20A);  // 0x9282
    printclear('<string at area2.selected_player_name>');  // 0x9286
    print(' NOTICES A RAM HEAVY CRUISER ORBITING THE BASE.');  // 0x928A
    exit_event();  // 0x92B1
  }
  area2.event_scratch1 = 1;  // 0x9251
  area2.event_scratch2 = 2;  // 0x9257
  party_surprise(zone: 10, result: area2.event_scratch1);  // 0x925D
  // 0x9266-0x926C
  if (2 >= area2.event_scratch2) {
    goto 0x9272;  // 0x926D
    // branch body 0x9272
    // target 0x9272 already emitted
  }
  exit_event();  // 0x9271
}
```

## Event 30

- Target: `0x92EB`
- Text hint: 'THIS CONFERENCE ROOM IS DOMINATED BY RAM INSIGNIAS BOTH ON THE WALLS AND CARVED INTO THE TABLE.'

```text
event 30 {
  // 0x92EB-0x92F1
  if (0 != mapDirection) {
    exit_event();  // 0x92F2
  }
  printclear('THIS CONFERENCE ROOM IS DOMINATED BY RAM INSIGNIAS BOTH ON THE WALLS AND CARVED INTO THE TABLE.');  // 0x92F3
  exit_event();  // 0x933E
}
```

## Event 31

- Target: `0x933F`
- Text hint: 'THIS ROOM HOLDS BRAND NEW EQUIPMENT. A MASTER CONTROL CONSOLE IS ON THE EAST WALL.'

```text
event 31 {
  // 0x933F-0x9345
  if (0 != mapDirection) {
    exit_event();  // 0x9346
  }
  printclear('THIS ROOM HOLDS BRAND NEW EQUIPMENT. A MASTER CONTROL CONSOLE IS ON THE EAST WALL.');  // 0x9347
  // 0x9388-0x9391
  area2.event_scratch0 = area1.event_word_3B0 & 8;  // 0x9388
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9392
  }
  printclear('MAVROUDIS, SUAREZ AND THE GUARDS ARE HERE, GATHERED AROUND THE CONSOLE.');  // 0x9394
  // 0x944F-0x9455
  if (2 == mapDirection) {
    exit_event();  // 0x9456
  }
  printclear("THIS DOOR READS 'LASER PLATFORM. DO NOT ENTER.'");  // 0x9457
  exit_event();  // 0x947E
}
```

## Event 32

- Target: `0x944F`
- Text hint: "THIS DOOR READS 'LASER PLATFORM. DO NOT ENTER.'"

```text
event 32 {
  // 0x944F-0x9455
  if (2 == mapDirection) {
    exit_event();  // 0x9456
  }
  printclear("THIS DOOR READS 'LASER PLATFORM. DO NOT ENTER.'");  // 0x9457
  exit_event();  // 0x947E
}
```

## Event 33

- Target: `0x947F`
- Text hint: 'THE SMOKING RUINS OF THE CONSOLE ARE ALL THAT REMAIN.'

```text
event 33 {
  // 0x947F-0x9488
  area2.event_scratch0 = area1.event_word_3B0 & 64;  // 0x947F
  if (area2.event_scratch0 != 0) {
    printclear('THE SMOKING RUINS OF THE CONSOLE ARE ALL THAT REMAIN.');  // 0x9489
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x94B4
  exit_event();  // 0x94B5
}
```

## Event 34

- Target: `0x97C5`
- Text hint: 'A LASER OF UNBELIEVABLE SIZE TOWERS ABOVE YOU -- YET STILL A SMALLER VERSION OF THE DOOMSDAY LASER.'

```text
event 34 {
  // 0x97C5-0x97CB
  if (0 != abs_C04E) {
    exit_event();  // 0x97CC
  }
  printclear('A LASER OF UNBELIEVABLE SIZE TOWERS ABOVE YOU -- YET STILL A SMALLER VERSION OF THE DOOMSDAY LASER.');  // 0x97CD
  // 0x994F-0x9958
  area2.event_scratch0 = area1.event_word_3AC & 32;  // 0x994F
  if (area2.event_scratch0 != 0) {
    goto 0x9998;  // 0x9959
    // branch body 0x9998
    add(area1.event_word_214 = area1.event_word_214 + 1);  // 0x9998
    printclear('CURRENTLY, THE MONITOR IS DISPLAYING ');  // 0x99A1
    // 0x99C0
    switch (area1.event_word_214) {
      case 0: goto 0x99D8;
        // case 0 body
        print('LAUNCH BAY ');  // 0x99D8
        // 0x99E4-0x99EA
        if (1 == area1.event_word_214) {
          print('1.');  // 0x99EB
        }
        if_=(<if compare flag is false, skip next op>);  // 0x99F0
        goto 0x9BDC;  // 0x99F1
        // branch body 0x9BDC
          printclear('DO YOU CONTINUE TO WATCH?');  // 0x9BDD
          // 0x9BFA-0x9C03
          area2.event_scratch0 = area1.event_word_3AC & 64;  // 0x9BFA
          if (area2.event_scratch0 != 0) {
            exit_event();  // 0x9C04
          }
          printclear('THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.');  // 0x9C05
          horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK');  // 0x9C55
          // 0x9C68-0x9C6E
          if (1 == area2.event_scratch0) {
            goto 0x9C77;  // 0x9C6F
          }
          goto 0xA208;  // 0x9C73
      case 1: goto 0x99D8;
        // case 1 body
        // target 0x99D8 already emitted
      case 2: goto 0x99D8;
        // case 2 body
        // target 0x99D8 already emitted
      case 3: goto 0x9A3A;
        // case 3 body
        print('THE MAIN CONFERENCE ROOM.');  // 0x9A3A
        goto 0x9BDC;  // 0x9A50
        // branch body 0x9BDC
          // target 0x9BDC already emitted
      case 4: goto 0x9A54;
        // case 4 body
        print("AN AREA WITH DOOR LABLED 'LASER CONTROL.' ");  // 0x9A54
        // 0x9A77-0x9A80
        area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9A77
        if (area2.event_scratch0 == 0) {
          goto 0x9BDC;  // 0x9A81
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        // 0x9A85-0x9A8E
        area2.event_scratch0 = area1.event_word_3B6 & 8;  // 0x9A85
        if (area2.event_scratch0 != 0) {
          goto 0x9BDC;  // 0x9A8F
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        print('YOU SEE THE GENERAL AND SUAREZ PRESS A KEYCODE FOR ACCESS.');  // 0x9A93
        print('THE COMMAND CENTER.');  // 0x9B51
        area1.event_word_214 = 0;  // 0x9B63
        // 0x9B69-0x9B72
        area2.event_scratch0 = area1.event_word_3B0 & 8;  // 0x9B69
        if (area2.event_scratch0 != 0) {
          goto 0x9BDC;  // 0x9B73
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        // 0x9B77-0x9B80
        area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9B77
        if (area2.event_scratch0 != 0) {
          goto 0x9BDC;  // 0x9B81
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        printclear('THE GENERAL IS HAVING A CONVERSATION WITH A MAN IN A RED CAPE.');  // 0x9B86
        printclear('DO YOU CONTINUE TO WATCH?');  // 0x9BDD
        // 0x9BFA-0x9C03
        area2.event_scratch0 = area1.event_word_3AC & 64;  // 0x9BFA
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x9C04
        }
        printclear('THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.');  // 0x9C05
        horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK');  // 0x9C55
        // 0x9C68-0x9C6E
        if (1 == area2.event_scratch0) {
          goto 0x9C77;  // 0x9C6F
          // branch body 0x9C77
          or(area1.event_word_3AC = area1.event_word_3AC | 64);  // 0x9C77
          area1.event_word_208 = 4;  // 0x9C80
          area2.surprise_result = 2;  // 0x9C86
          gosub 0x9ED5;  // 0x9C8C
        }
      case 5: goto 0x9B51;
    }
  }
}
```

## Event 35

- Target: `0x994F`
- Text hint: 'THE SECURITY MONITORS DISPLAY DIFFERENT SECTIONS OF THE BASE EACH MINUTE.' 'CURRENTLY, THE MONITOR IS DISPLAYING '

```text
event 35 {
  // 0x994F-0x9958
  area2.event_scratch0 = area1.event_word_3AC & 32;  // 0x994F
  if (area2.event_scratch0 != 0) {
    goto 0x9998;  // 0x9959
    // branch body 0x9998
    add(area1.event_word_214 = area1.event_word_214 + 1);  // 0x9998
    printclear('CURRENTLY, THE MONITOR IS DISPLAYING ');  // 0x99A1
    // 0x99C0
    switch (area1.event_word_214) {
      case 0: goto 0x99D8;
        // case 0 body
        print('LAUNCH BAY ');  // 0x99D8
        // 0x99E4-0x99EA
        if (1 == area1.event_word_214) {
          print('1.');  // 0x99EB
        }
        if_=(<if compare flag is false, skip next op>);  // 0x99F0
        goto 0x9BDC;  // 0x99F1
        // branch body 0x9BDC
          printclear('DO YOU CONTINUE TO WATCH?');  // 0x9BDD
          // 0x9BFA-0x9C03
          area2.event_scratch0 = area1.event_word_3AC & 64;  // 0x9BFA
          if (area2.event_scratch0 != 0) {
            exit_event();  // 0x9C04
          }
          printclear('THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.');  // 0x9C05
          horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK');  // 0x9C55
          // 0x9C68-0x9C6E
          if (1 == area2.event_scratch0) {
            goto 0x9C77;  // 0x9C6F
          }
          goto 0xA208;  // 0x9C73
      case 1: goto 0x99D8;
        // case 1 body
        // target 0x99D8 already emitted
      case 2: goto 0x99D8;
        // case 2 body
        // target 0x99D8 already emitted
      case 3: goto 0x9A3A;
        // case 3 body
        print('THE MAIN CONFERENCE ROOM.');  // 0x9A3A
        goto 0x9BDC;  // 0x9A50
        // branch body 0x9BDC
          // target 0x9BDC already emitted
      case 4: goto 0x9A54;
        // case 4 body
        print("AN AREA WITH DOOR LABLED 'LASER CONTROL.' ");  // 0x9A54
        // 0x9A77-0x9A80
        area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9A77
        if (area2.event_scratch0 == 0) {
          goto 0x9BDC;  // 0x9A81
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        // 0x9A85-0x9A8E
        area2.event_scratch0 = area1.event_word_3B6 & 8;  // 0x9A85
        if (area2.event_scratch0 != 0) {
          goto 0x9BDC;  // 0x9A8F
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        print('YOU SEE THE GENERAL AND SUAREZ PRESS A KEYCODE FOR ACCESS.');  // 0x9A93
        print('THE COMMAND CENTER.');  // 0x9B51
        area1.event_word_214 = 0;  // 0x9B63
        // 0x9B69-0x9B72
        area2.event_scratch0 = area1.event_word_3B0 & 8;  // 0x9B69
        if (area2.event_scratch0 != 0) {
          goto 0x9BDC;  // 0x9B73
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        // 0x9B77-0x9B80
        area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9B77
        if (area2.event_scratch0 != 0) {
          goto 0x9BDC;  // 0x9B81
          // branch body 0x9BDC
          // target 0x9BDC already emitted
        }
        printclear('THE GENERAL IS HAVING A CONVERSATION WITH A MAN IN A RED CAPE.');  // 0x9B86
        printclear('DO YOU CONTINUE TO WATCH?');  // 0x9BDD
        // 0x9BFA-0x9C03
        area2.event_scratch0 = area1.event_word_3AC & 64;  // 0x9BFA
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x9C04
        }
        printclear('THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.');  // 0x9C05
        horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK');  // 0x9C55
        // 0x9C68-0x9C6E
        if (1 == area2.event_scratch0) {
          goto 0x9C77;  // 0x9C6F
          // branch body 0x9C77
          or(area1.event_word_3AC = area1.event_word_3AC | 64);  // 0x9C77
          area1.event_word_208 = 4;  // 0x9C80
          area2.surprise_result = 2;  // 0x9C86
          gosub 0x9ED5;  // 0x9C8C
          gosub 0xA0AC;  // 0x9C90
          and(area1.event_word_3B0 = area1.event_word_3B0 & 239);  // 0x9C94
          printclear('YOU HIDE THE BODIES AND CHANGE INTO THEIR UNIFORMS. YOU FIND A SECURITY PASS AS WELL.');  // 0x9C9D
          // 0x9D15-0x9D1E
          area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9D15
          if (area2.event_scratch0 != 0) {
            exit_event();  // 0x9D1F
          }
        }
      case 5: goto 0x9B51;
    }
  }
}
```

## Event 36

- Target: `0x9BFA`
- Text hint: 'THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.'

```text
event 36 {
  // 0x9BFA-0x9C03
  area2.event_scratch0 = area1.event_word_3AC & 64;  // 0x9BFA
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9C04
  }
  printclear('THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.');  // 0x9C05
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK');  // 0x9C55
  // 0x9C68-0x9C6E
  if (1 == area2.event_scratch0) {
    goto 0x9C77;  // 0x9C6F
    // branch body 0x9C77
    or(area1.event_word_3AC = area1.event_word_3AC | 64);  // 0x9C77
    area1.event_word_208 = 4;  // 0x9C80
    area2.surprise_result = 2;  // 0x9C86
    gosub 0x9ED5;  // 0x9C8C
    gosub 0xA0AC;  // 0x9C90
    and(area1.event_word_3B0 = area1.event_word_3B0 & 239);  // 0x9C94
    printclear('YOU HIDE THE BODIES AND CHANGE INTO THEIR UNIFORMS. YOU FIND A SECURITY PASS AS WELL.');  // 0x9C9D
    // 0x9D15-0x9D1E
    area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9D15
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9D1F
    }
    // 0x9D20-0x9D29
    area2.event_scratch0 = area1.event_word_3B6 & 8;  // 0x9D20
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9D2A
    }
    printclear("THE GENERAL'S BATHROOM. UNDER THE SINK YOU FIND A WAD OF PAPER CONTAINING SOME NUMBERS. THEY APPEAR TO BE AN ACCESS CODE.");  // 0x9D2B
    or(area1.event_word_3B6 = area1.event_word_3B6 | 8);  // 0x9D89
    exit_event();  // 0x9D92
  }
  goto 0xA208;  // 0x9C73
  // branch body 0xA208
    mapPosX = area1.lastXPos;  // 0xA208
    mapPosY = area1.lastYPos;  // 0xA20F
    printclear("THE GENERAL SAYS, 'YOU'VE KEPT ME WAITING, SUAREZ. I DISLIKE THAT.'");  // 0xA217
}
```

## Event 37

- Target: `0x9D15`
- Text hint: "THE GENERAL'S BATHROOM. UNDER THE SINK YOU FIND A WAD OF PAPER CONTAINING SOME NUMBERS. THEY APPEAR TO BE AN ACCESS CODE."

```text
event 37 {
  // 0x9D15-0x9D1E
  area2.event_scratch0 = area1.event_word_3B0 & 128;  // 0x9D15
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9D1F
  }
  // 0x9D20-0x9D29
  area2.event_scratch0 = area1.event_word_3B6 & 8;  // 0x9D20
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9D2A
  }
  printclear("THE GENERAL'S BATHROOM. UNDER THE SINK YOU FIND A WAD OF PAPER CONTAINING SOME NUMBERS. THEY APPEAR TO BE AN ACCESS CODE.");  // 0x9D2B
  or(area1.event_word_3B6 = area1.event_word_3B6 | 8);  // 0x9D89
  exit_event();  // 0x9D92
}
```
