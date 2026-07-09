# GEO 81: PURGE Headquarters, Floors Ground-Upper

ECL block: `81`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8777`
- Text hint: 'AN ELEVATOR GOING UP. DO YOU USE IT?'

```text
event 01 {
  printclear('AN ELEVATOR GOING UP. DO YOU USE IT?');  // 0x8777
  exit_event();  // 0x87D0
}
```

## Event 02

- Target: `0x87D0`
- Text hint: 'JANITORIAL SUPPLIES ARE STORED IN THIS ROOM.'

```text
event 02 {
  exit_event();  // 0x87D0
}
```

## Event 03

- Target: `0x87E0`
- Text hint: 'JANITORIAL SUPPLIES ARE STORED IN THIS ROOM.'

```text
event 03 {
  // 0x87E0-0x87E9
  area2.event_scratch0 = 4 & area1.event_word_30E;  // 0x87E0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x87EA
  }
  printclear('JANITORIAL SUPPLIES ARE STORED IN THIS ROOM.');  // 0x87EB
  // 0x8819-0x881F
  if (mapDirection != 0) {
    exit_event();  // 0x8820
  }
  printclear('THE DOOR SLIDES SHUT BEHIND YOU.');  // 0x8821
  exit_event();  // 0x883C
}
```

## Event 04

- Target: `0x8819`
- Text hint: 'THE DOOR SLIDES SHUT BEHIND YOU.'

```text
event 04 {
  // 0x8819-0x881F
  if (mapDirection != 0) {
    exit_event();  // 0x8820
  }
  printclear('THE DOOR SLIDES SHUT BEHIND YOU.');  // 0x8821
  exit_event();  // 0x883C
}
```

## Event 05

- Target: `0x883D`
- Text hint: 'THE EMPLOYEE CAFETERIA. '

```text
event 05 {
  // 0x883D-0x8843
  if (mapDirection != 2) {
    exit_event();  // 0x8844
  }
  goto 0x8149;  // 0x8845
  // branch body 0x8149
    printclear('YOU ENTER THE LOBBY OF PURGE HEADQUARTERS.');  // 0x8149
    // 0x816C-0x8175
    area2.event_scratch0 = 2 & area1.event_word_30E;  // 0x816C
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8176
    }
    // 0x8177-0x817D
    if (area1.event_word_31E == 1) {
      exit_event();  // 0x817E
    }
    printclear('A TERRAN WOMAN IN AN OLIVE GREEN UNIFORM LOOKS UP FROM HER DESK. ');  // 0x8180
    // 0x81B4-0x81BA
    if (area1.event_word_312 == 1) {
      goto 0x82C8;  // 0x81BB
      // branch body 0x82C8
      printclear("THE RECEPTIONIST TENSES. 'I DON'T KNOW WHO YOU THINK YOU ARE, BUT I KNOW HOW TO DEAL WITH YOU! GUARDS!'");  // 0x82C8
      area1.LastEclBlockId = 81;  // 0x8362
      // 0x8368-0x836E
      if (area2.tried_to_exit_map == 1) {
        goto 0x8406;  // 0x836F
        // branch body 0x8406
        printclear('DO YOU LEAVE PURGE HQ?');  // 0x8406
        // 0x8426-0x842F
        area2.event_scratch0 = 8 & area1.event_word_314;  // 0x8426
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x8430
        }
        area2.event_scratch0 = 8;  // 0x8431
        printclear('THE DOOR IS SEALED. THE LOCK LOOKS TRICKY. ');  // 0x8437
        sprite(OFF);  // 0x845B
        exit_event();  // 0x845F
      }
      // 0x8373-0x8379
      if (mapPosY == 2) {
        area2.event_scratch0 = 1;  // 0x837A
      }
      if_=(<if compare flag is false, skip next op>);  // 0x8380
      goto 0x84A6;  // 0x8381
      // branch body 0x84A6
        compare_and(Values: 2 == mapDirection && 7 == mapPosX);  // 0x84A6
        if_<>(<if compare flag is false, skip next op>);  // 0x84B1
        exit_event();  // 0x84B2
    }
    print_return();  // 0x81BF
    print("SHE EYES YOU WARILY. 'DO YOU HAVE BUSINESS WITH US?'");  // 0x81C0
    printclear("THE RECEPTIONIST TENSES. 'I DON'T KNOW WHO YOU THINK YOU ARE, BUT I KNOW HOW TO DEAL WITH YOU! GUARDS!'");  // 0x82C8
    area1.LastEclBlockId = 81;  // 0x8362
    // 0x8368-0x836E
    if (area2.tried_to_exit_map == 1) {
      goto 0x8406;  // 0x836F
      // branch body 0x8406
      // target 0x8406 already emitted
    }
    // 0x8373-0x8379
    if (mapPosY == 2) {
      area2.event_scratch0 = 1;  // 0x837A
    }
    if_=(<if compare flag is false, skip next op>);  // 0x8380
    goto 0x84A6;  // 0x8381
    // branch body 0x84A6
      // target 0x84A6 already emitted
}
```

## Event 06

- Target: `0x8849`
- Text hint: 'THE EMPLOYEE CAFETERIA. '

```text
event 06 {
  // 0x8849-0x884F
  if (mapDirection != 3) {
    exit_event();  // 0x8850
  }
  printclear('THE EMPLOYEE CAFETERIA. ');  // 0x8851
  // 0x8866-0x886C
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x886D
  }
  // 0x886E-0x8874
  if (area1.event_word_312 == 1) {
    print('IT IS EMPTY.');  // 0x8875
  }
  if_=(<if compare flag is false, skip next op>);  // 0x8881
  exit_event();  // 0x8882
}
```

## Event 07

- Target: `0x890A`
- Text hint: 'YOU OVERHEAR TWO PURGE MEMBERS,'

```text
event 07 {
  // 0x890A-0x8910
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x8911
  }
  // 0x8912-0x8918
  if (area1.event_word_312 == 1) {
    exit_event();  // 0x8919
  }
  // 0x891A-0x8923
  area2.event_scratch0 = 8 & area1.event_word_30E;  // 0x891A
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8924
  }
  printclear('YOU OVERHEAR TWO PURGE MEMBERS,');  // 0x8925
  find_special(raw=(abs_000E));  // 0x8940
  exit_event();  // 0x8951
}
```

## Event 08

- Target: `0x8979`
- Text hint: 'THIS AREA IS PARTITIONED INTO WORK CUBICLES. CLERKS RUSH AROUND, OBLIVIOUS TO YOUR PRESENCE.'

```text
event 08 {
  // 0x8979-0x897F
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x8980
  }
  // 0x8981-0x8987
  if (mapDirection != 1) {
    exit_event();  // 0x8988
  }
  printclear('THIS AREA IS PARTITIONED INTO WORK CUBICLES. CLERKS RUSH AROUND, OBLIVIOUS TO YOUR PRESENCE.');  // 0x8989
  // 0x89D3-0x89D9
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x89DA
  }
  // 0x89DB-0x89E1
  if (mapDirection != 3) {
    exit_event();  // 0x89E2
  }
  goto 0x8989;  // 0x89E3
  // branch body 0x8989
    printclear('THIS AREA IS PARTITIONED INTO WORK CUBICLES. CLERKS RUSH AROUND, OBLIVIOUS TO YOUR PRESENCE.');  // 0x8989
    // 0x89D3-0x89D9
    if (area1.event_word_31E == 1) {
      exit_event();  // 0x89DA
    }
    // 0x89DB-0x89E1
    if (mapDirection != 3) {
      exit_event();  // 0x89E2
    }
    goto 0x8989;  // 0x89E3
    // branch body 0x8989
      // target 0x8989 already emitted
}
```

## Event 09

- Target: `0x89D3`
- Text hint: '' "'WOMEN'S ROOM.'"

```text
event 09 {
  // 0x89D3-0x89D9
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x89DA
  }
  // 0x89DB-0x89E1
  if (mapDirection != 3) {
    exit_event();  // 0x89E2
  }
  goto 0x8989;  // 0x89E3
  // branch body 0x8989
    printclear('THIS AREA IS PARTITIONED INTO WORK CUBICLES. CLERKS RUSH AROUND, OBLIVIOUS TO YOUR PRESENCE.');  // 0x8989
    // 0x89D3-0x89D9
    if (area1.event_word_31E == 1) {
      exit_event();  // 0x89DA
    }
    // 0x89DB-0x89E1
    if (mapDirection != 3) {
      exit_event();  // 0x89E2
    }
    goto 0x8989;  // 0x89E3
    // branch body 0x8989
      // target 0x8989 already emitted
}
```

## Event 10

- Target: `0x89E7`
- Text hint: '' "'WOMEN'S ROOM.'"

```text
event 10 {
  printclear('');  // 0x89E7
  gosub 0x8A02;  // 0x89EA
  gosub 0x8A13;  // 0x89EE
  print("'WOMEN'S ROOM.'");  // 0x89F2
  exit_event();  // 0x8A01
}
```

## Event 11

- Target: `0x8A21`
- Text hint: '' ' SOUTHERN' "'MEN'S ROOM,' AND "

```text
event 11 {
  // 0x8A21-0x8A27
  if (area1.event_word_202 == 1) {
    exit_event();  // 0x8A28
  }
  printclear('');  // 0x8A29
  gosub 0x8A02;  // 0x8A2C
  print(' SOUTHERN');  // 0x8A30
  gosub 0x8A13;  // 0x8A3A
  print("'MEN'S ROOM,' AND ");  // 0x8A3E
  gosub 0x8A02;  // 0x8A4F
  print(' EASTERN DOOR');  // 0x8A53
  gosub 0x8A13;  // 0x8A60
  print("'GENNIE'S ROOM'");  // 0x8A64
  area1.event_word_202 = 1;  // 0x8A73
  exit_event();  // 0x8A79
}
```

## Event 12

- Target: `0x8A7A`
- Text hint: "A UNIFORMED MAN SITS AT HIS COMPUTER. HE SPEAKS TO YOU OVER HIS BACK. 'I'M SORRY, COMMANDER SOOTH IS NOT IN RIGHT NOW...' HE TURNS AROUND."

```text
event 12 {
  area1.event_word_202 = 0;  // 0x8A7A
  exit_event();  // 0x8A80
}
```

## Event 13

- Target: `0x8A81`
- Text hint: "A UNIFORMED MAN SITS AT HIS COMPUTER. HE SPEAKS TO YOU OVER HIS BACK. 'I'M SORRY, COMMANDER SOOTH IS NOT IN RIGHT NOW...' HE TURNS AROUND."

```text
event 13 {
  // 0x8A81-0x8A87
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x8A88
  }
  // 0x8A89-0x8A92
  area2.event_scratch0 = 16 & area1.event_word_30E;  // 0x8A89
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8A93
  }
  printclear("A UNIFORMED MAN SITS AT HIS COMPUTER. HE SPEAKS TO YOU OVER HIS BACK. 'I'M SORRY, COMMANDER SOOTH IS NOT IN RIGHT NOW...' HE TURNS AROUND.");  // 0x8A94
  // 0x8B56-0x8B5C
  if (mapDirection != 3) {
    exit_event();  // 0x8B5D
  }
  printclear("YOU ENTER HANIBL SOOTH'S OFFICE. THE ONLY FURNITURE IS THE DESK ACROSS THE ROOM.");  // 0x8B5E
  // 0x8B9F-0x8BA8
  area2.event_scratch0 = 32 & area1.event_word_30E;  // 0x8B9F
  if (area2.event_scratch0 != 0) {
    goto 0x8BCD;  // 0x8BA9
    // branch body 0x8BCD
    printclear('OVER THE DESK IS A MONITOR.');  // 0x8BCD
    // 0x8BE5-0x8BEB
    if (area1.event_word_31E == 1) {
      print(' ITS SCREEN IS BLANK.');  // 0x8BEC
    }
    if_=(<if compare flag is false, skip next op>);  // 0x8BFF
    if_=(<if compare flag is false, skip next op>);  // 0x8C01
    exit_event();  // 0x8C02
  }
  printclear('YOU FIND A LETTER');  // 0x8BAD
  find_special(raw=(abs_0002));  // 0x8BBD
  exit_event();  // 0x8BC2
}
```

## Event 14

- Target: `0x8B56`
- Text hint: "YOU ENTER HANIBL SOOTH'S OFFICE. THE ONLY FURNITURE IS THE DESK ACROSS THE ROOM."

```text
event 14 {
  // 0x8B56-0x8B5C
  if (mapDirection != 3) {
    exit_event();  // 0x8B5D
  }
  printclear("YOU ENTER HANIBL SOOTH'S OFFICE. THE ONLY FURNITURE IS THE DESK ACROSS THE ROOM.");  // 0x8B5E
  // 0x8B9F-0x8BA8
  area2.event_scratch0 = 32 & area1.event_word_30E;  // 0x8B9F
  if (area2.event_scratch0 != 0) {
    goto 0x8BCD;  // 0x8BA9
    // branch body 0x8BCD
    printclear('OVER THE DESK IS A MONITOR.');  // 0x8BCD
    // 0x8BE5-0x8BEB
    if (area1.event_word_31E == 1) {
      print(' ITS SCREEN IS BLANK.');  // 0x8BEC
    }
    if_=(<if compare flag is false, skip next op>);  // 0x8BFF
    if_=(<if compare flag is false, skip next op>);  // 0x8C01
    exit_event();  // 0x8C02
  }
  printclear('YOU FIND A LETTER');  // 0x8BAD
  find_special(raw=(abs_0002));  // 0x8BBD
  exit_event();  // 0x8BC2
}
```

## Event 15

- Target: `0x8B9F`
- Text hint: 'YOU FIND A LETTER'

```text
event 15 {
  // 0x8B9F-0x8BA8
  area2.event_scratch0 = 32 & area1.event_word_30E;  // 0x8B9F
  if (area2.event_scratch0 != 0) {
    goto 0x8BCD;  // 0x8BA9
    // branch body 0x8BCD
    printclear('OVER THE DESK IS A MONITOR.');  // 0x8BCD
    // 0x8BE5-0x8BEB
    if (area1.event_word_31E == 1) {
      print(' ITS SCREEN IS BLANK.');  // 0x8BEC
    }
    if_=(<if compare flag is false, skip next op>);  // 0x8BFF
    if_=(<if compare flag is false, skip next op>);  // 0x8C01
    exit_event();  // 0x8C02
  }
  printclear('YOU FIND A LETTER');  // 0x8BAD
  find_special(raw=(abs_0002));  // 0x8BBD
  exit_event();  // 0x8BC2
}
```

## Event 16

- Target: `0x8D28`
- Text hint: 'IN THIS CONFERENCE ROOM, A MEETING IS IN PROGRESS. PURGE MEMBERS SIT AROUND A TABLE. '

```text
event 16 {
  // 0x8D28-0x8D2E
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x8D2F
  }
  // 0x8D30-0x8D39
  area2.event_scratch0 = 64 & area1.event_word_31C;  // 0x8D30
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8D3A
  }
  printclear('IN THIS CONFERENCE ROOM, A MEETING IS IN PROGRESS. PURGE MEMBERS SIT AROUND A TABLE. ');  // 0x8D3B
  sprite(OFF);  // 0x8D7E
  exit_event();  // 0x8D82
}
```

## Event 17

- Target: `0x8EEB`
- Text hint: 'A PRINTING PRESS IS HERE' '.'

```text
event 17 {
  // 0x8EEB-0x8EF1
  if (mapDirection != 0) {
    exit_event();  // 0x8EF2
  }
  printclear('A PRINTING PRESS IS HERE');  // 0x8EF3
  // 0x8F08-0x8F11
  area2.event_scratch0 = 128 & area1.event_word_30E;  // 0x8F08
  if (area2.event_scratch0 != 0) {
    print('.');  // 0x8F12
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8F16
  exit_event();  // 0x8F17
}
```

## Event 18

- Target: `0x8F53`
- Text hint: 'BOXES OF BUTTONS AND STICKERS ARE STORED HERE.'

```text
event 18 {
  // 0x8F53-0x8F59
  if (mapDirection != 3) {
    exit_event();  // 0x8F5A
  }
  printclear('BOXES OF BUTTONS AND STICKERS ARE STORED HERE.');  // 0x8F5B
  exit_event();  // 0x8F81
}
```

## Event 19

- Target: `0x8F82`
- Text hint: 'A COMBAT TRAINING ROOM WITH A PADDED FLOOR. IT IS EMPTY.'

```text
event 19 {
  // 0x8F82-0x8F88
  if (mapDirection != 0) {
    exit_event();  // 0x8F89
  }
  printclear('A COMBAT TRAINING ROOM WITH A PADDED FLOOR. IT IS EMPTY.');  // 0x8F8A
  exit_event();  // 0x8FB7
}
```

## Event 20

- Target: `0x8FB8`
- Text hint: ''

```text
event 20 {
  // 0x8FB8-0x8FBE
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x8FBF
  }
  // 0x8FC0-0x8FC9
  area2.event_scratch0 = 64 & area1.event_word_30E;  // 0x8FC0
  if (area2.event_scratch0 != 0) {
    goto 0x9167;  // 0x8FCA
    // branch body 0x9167
    printclear('THIS CELL IS EMPTY.');  // 0x9167
    exit_event();  // 0x9179
  }
  exit_event();  // 0x8FCF
}
```

## Event 21

- Target: `0x913A`
- Text hint: '' ' SOUTHERN' "'HOLDING CELLS'"

```text
event 21 {
  // 0x913A-0x9140
  if (mapDirection == 0) {
    exit_event();  // 0x9141
  }
  printclear('');  // 0x9142
  gosub 0x8A02;  // 0x9145
  print(' SOUTHERN');  // 0x9149
  gosub 0x8A13;  // 0x9153
  print("'HOLDING CELLS'");  // 0x9157
  exit_event();  // 0x9166
}
```

## Event 22

- Target: `0x9167`
- Text hint: 'THIS CELL IS EMPTY.'

```text
event 22 {
  printclear('THIS CELL IS EMPTY.');  // 0x9167
  exit_event();  // 0x9179
}
```

## Event 23

- Target: `0x917A`
- Text hint: 'YOU ENTER A ROOM FULL OF COMPUTER AND COMMUNICATIONS EQUIPMENT. PURGE MEMBERS RUSH ABOUT, WHILE OTHERS SIT AT CONTROL CONSOLES.'

```text
event 23 {
  // 0x917A-0x9183
  area2.event_scratch0 = 16 & area1.event_word_314;  // 0x917A
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9184
  }
  // 0x9185-0x918B
  if (area1.event_word_31A == 1) {
    goto 0x953C;  // 0x918C
    // branch body 0x953C
    setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x953C
    exit_event();  // 0x9543
  }
  area1.event_word_312 = 1;  // 0x9190
  printclear('YOU ENTER A ROOM FULL OF COMPUTER AND COMMUNICATIONS EQUIPMENT. PURGE MEMBERS RUSH ABOUT, WHILE OTHERS SIT AT CONTROL CONSOLES.');  // 0x9196
  // truncated at 0x953C
}
```

## Event 24

- Target: `0x955B`
- Text hint: "AN EMACIATED MAN IN A TATTERED LAB COAT APPROACHES. IT'S DR. ROMNEY!" 'DR. ROMNEY MEETS YOU IN THE HALL.'

```text
event 24 {
  // 0x955B-0x9561
  if (area1.event_word_31E != 1) {
    exit_event();  // 0x9562
  }
  // 0x9563-0x956C
  area2.event_scratch0 = 32 & area1.event_word_314;  // 0x9563
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x956D
  }
  or(area1.event_word_314 = 32 | area1.event_word_314);  // 0x956E
  // 0x9577-0x9580
  area2.event_scratch0 = 64 & area1.event_word_30E;  // 0x9577
  if (area2.event_scratch0 != 0) {
    goto 0x9639;  // 0x9581
    // branch body 0x9639
    printclear('DR. ROMNEY MEETS YOU IN THE HALL.');  // 0x9639
    // 0x96A5-0x96AB
    if (area1.event_word_312 == 1) {
      goto 0x86F4;  // 0x96AC
      // branch body 0x86F4
      // 0x86F4-0x86FA
      if (area1.event_word_312 != 1) {
        exit_event();  // 0x86FB
      }
      // 0x86FC-0x8702
      if (area1.event_word_31E == 1) {
        exit_event();  // 0x8703
      }
      // 0x8704-0x870A
      if (area1.event_word_204 < 8) {
        goto 0x8719;  // 0x870B
        // branch body 0x8719
        random(area2.event_scratch0 = random 1..99);  // 0x8719
        // 0x871F-0x8725
        if (area2.event_scratch0 < 10) {
          exit_event();  // 0x8726
        }
        // 0x8727-0x872D
        if (area1.event_word_316 < 3) {
          exit_event();  // 0x872E
        }
        add(area1.event_word_316 = 1 + area1.event_word_316);  // 0x872F
        printclear('ROVING PURGE GUARDS ATTACK!');  // 0x8738
        setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x8750
        exit_event();  // 0x8757
      }
      add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x870F
      exit_event();  // 0x8718
    }
    // 0x96B0-0x96B6
    if (area1.event_word_31E == 1) {
      exit_event();  // 0x96B7
    }
    // 0x96B8-0x96BE
    if (area1.event_word_204 < 8) {
      goto 0x96CD;  // 0x96BF
      // branch body 0x96CD
      random(area2.event_scratch0 = random 1..99);  // 0x96CD
      // 0x96D3-0x96D9
      if (area2.event_scratch0 < 10) {
        exit_event();  // 0x96DA
      }
      area1.event_word_204 = 0;  // 0x96DB
      random(area2.event_scratch0 = random 1..2);  // 0x96E1
      // 0x96E7-0x96ED
      if (area2.event_scratch0 == 1) {
        printclear('A PURGE FUNCTIONARY');  // 0x96EE
      }
      if_<>(<if compare flag is false, skip next op>);  // 0x9700
      printclear('AN OFFICE WORKER');  // 0x9701
      print(' PASSES YOU BY.');  // 0x9710
    }
    add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x96C3
    exit_event();  // 0x96CC
  }
  printclear("AN EMACIATED MAN IN A TATTERED LAB COAT APPROACHES. IT'S DR. ROMNEY!");  // 0x9585
  printclear('DR. ROMNEY MEETS YOU IN THE HALL.');  // 0x9639
  // 0x96A5-0x96AB
  if (area1.event_word_312 == 1) {
    goto 0x86F4;  // 0x96AC
    // branch body 0x86F4
    // target 0x86F4 already emitted
  }
  // 0x96B0-0x96B6
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x96B7
  }
  // 0x96B8-0x96BE
  if (area1.event_word_204 < 8) {
    goto 0x96CD;  // 0x96BF
    // branch body 0x96CD
    // target 0x96CD already emitted
  }
  add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x96C3
  exit_event();  // 0x96CC
}
```

## Event 25

- Target: `0x96A5`
- Text hint: 'A PURGE FUNCTIONARY' 'AN OFFICE WORKER' ' PASSES YOU BY.'

```text
event 25 {
  // 0x96A5-0x96AB
  if (area1.event_word_312 == 1) {
    goto 0x86F4;  // 0x96AC
    // branch body 0x86F4
    // 0x86F4-0x86FA
    if (area1.event_word_312 != 1) {
      exit_event();  // 0x86FB
    }
    // 0x86FC-0x8702
    if (area1.event_word_31E == 1) {
      exit_event();  // 0x8703
    }
    // 0x8704-0x870A
    if (area1.event_word_204 < 8) {
      goto 0x8719;  // 0x870B
      // branch body 0x8719
      random(area2.event_scratch0 = random 1..99);  // 0x8719
      // 0x871F-0x8725
      if (area2.event_scratch0 < 10) {
        exit_event();  // 0x8726
      }
      // 0x8727-0x872D
      if (area1.event_word_316 < 3) {
        exit_event();  // 0x872E
      }
      add(area1.event_word_316 = 1 + area1.event_word_316);  // 0x872F
      printclear('ROVING PURGE GUARDS ATTACK!');  // 0x8738
      setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x8750
      exit_event();  // 0x8757
    }
    add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x870F
    exit_event();  // 0x8718
  }
  // 0x96B0-0x96B6
  if (area1.event_word_31E == 1) {
    exit_event();  // 0x96B7
  }
  // 0x96B8-0x96BE
  if (area1.event_word_204 < 8) {
    goto 0x96CD;  // 0x96BF
    // branch body 0x96CD
    random(area2.event_scratch0 = random 1..99);  // 0x96CD
    // 0x96D3-0x96D9
    if (area2.event_scratch0 < 10) {
      exit_event();  // 0x96DA
    }
    area1.event_word_204 = 0;  // 0x96DB
    random(area2.event_scratch0 = random 1..2);  // 0x96E1
    // 0x96E7-0x96ED
    if (area2.event_scratch0 == 1) {
      printclear('A PURGE FUNCTIONARY');  // 0x96EE
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x9700
    printclear('AN OFFICE WORKER');  // 0x9701
    print(' PASSES YOU BY.');  // 0x9710
  }
  add(area1.event_word_204 = 1 + area1.event_word_204);  // 0x96C3
  exit_event();  // 0x96CC
}
```
