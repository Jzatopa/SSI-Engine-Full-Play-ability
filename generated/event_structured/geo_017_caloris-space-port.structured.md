# GEO 17: Caloris Space Port

ECL block: `17`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x880A`
- Text hint: "'WELCOME TO CALORIS. I AM LORD BERKELEY'S CHANCELLOR, ALPHONSE DE SADE. LORD BERKELEY SENDS HIS GREETINGS. THE CORONATION WILL BEGIN SHORTLY.' HE TURNS HIS BACK AND QUICKLY MOVES AWAY."

```text
event 01 {
  // 0x880A-0x8813
  area2.event_scratch0 = 4 & area1.event_word_25E;  // 0x880A
  if (area2.event_scratch0 != 0) {
    goto 0x88B8;  // 0x8814
    // branch body 0x88B8
    area1.event_word_22A = abs_0001;  // 0x88B8
    area1.event_word_226 = 0;  // 0x88BF
    scratch.word_0000 = abs_000C;  // 0x88C5
    scratch.word_0208 = abs_0007;  // 0x88D7
    goto 0x8D1B;  // 0x88E4
    // branch body 0x8D1B
      // 0x8D1B-0x8D21
      if (1 == area1.event_word_208) {
        exit_event();  // 0x8D22
      }
      printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
      print_return();  // 0x8D3E
      print_return();  // 0x8D3F
      print('BERTH ');  // 0x8D40
      print('<string at area1.event_word_22A>');  // 0x8D48
      // 0x8D4C-0x8D52
      if (1 == area1.event_word_226) {
        exit_event();  // 0x8D53
      }
      print_return();  // 0x8D54
      print('SHIP:  ');  // 0x8D55
      print('<string at scratch.word_0000>');  // 0x8D5E
      print_return();  // 0x8D62
      print('HOMEPORT:  ');  // 0x8D63
      print('<string at scratch.word_0208>');  // 0x8D6F
      exit_event();  // 0x8D73
  }
  picture(block_id: 86);  // 0x8818
  or(area1.event_word_25E = 4 | area1.event_word_25E);  // 0x881B
  printclear("'WELCOME TO CALORIS. I AM LORD BERKELEY'S CHANCELLOR, ALPHONSE DE SADE. LORD BERKELEY SENDS HIS GREETINGS. THE CORONATION WILL BEGIN SHORTLY.' HE TURNS HIS BACK AND QUICKLY MOVES AWAY.");  // 0x8824
  area1.event_word_22A = abs_0001;  // 0x88B8
  area1.event_word_226 = 0;  // 0x88BF
  scratch.word_0000 = abs_000C;  // 0x88C5
  scratch.word_0208 = abs_0007;  // 0x88D7
  goto 0x8D1B;  // 0x88E4
  // branch body 0x8D1B
    // target 0x8D1B already emitted
}
```

## Event 02

- Target: `0x88E8`
- Text hint: 'LUNARIANS STAND WATCH. DO YOU QUESTION THEM?'

```text
event 02 {
  // 0x88E8-0x88EE
  if (0 == area1.event_word_258) {
    goto 0x89C0;  // 0x88EF
    // branch body 0x89C0
    area1.event_word_22A = abs_0001;  // 0x89C0
    area1.event_word_226 = 0;  // 0x89C7
    scratch.word_0000 = abs_0006;  // 0x89CD
    scratch.word_0208 = abs_0004;  // 0x89D9
    goto 0x8D1B;  // 0x89E3
    // branch body 0x8D1B
      // 0x8D1B-0x8D21
      if (1 == area1.event_word_208) {
        exit_event();  // 0x8D22
      }
      printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
      print_return();  // 0x8D3E
      print_return();  // 0x8D3F
      print('BERTH ');  // 0x8D40
      print('<string at area1.event_word_22A>');  // 0x8D48
      // 0x8D4C-0x8D52
      if (1 == area1.event_word_226) {
        exit_event();  // 0x8D53
      }
      print_return();  // 0x8D54
      print('SHIP:  ');  // 0x8D55
      print('<string at scratch.word_0000>');  // 0x8D5E
      print_return();  // 0x8D62
      print('HOMEPORT:  ');  // 0x8D63
      print('<string at scratch.word_0208>');  // 0x8D6F
      exit_event();  // 0x8D73
  }
  // 0x88F3-0x88FC
  area2.event_scratch0 = 16 & area1.event_word_25A;  // 0x88F3
  if (area2.event_scratch0 != 0) {
    goto 0x89C0;  // 0x88FD
    // branch body 0x89C0
    // target 0x89C0 already emitted
  }
  printclear('LUNARIANS STAND WATCH. DO YOU QUESTION THEM?');  // 0x8901
  area1.event_word_22A = abs_0001;  // 0x89C0
  area1.event_word_226 = 0;  // 0x89C7
  scratch.word_0000 = abs_0006;  // 0x89CD
  scratch.word_0208 = abs_0004;  // 0x89D9
  goto 0x8D1B;  // 0x89E3
  // branch body 0x8D1B
    // target 0x8D1B already emitted
}
```

## Event 03

- Target: `0x8579`
- Text hint: "'WELCOME TO CALORIS. I AM LORD BERKELEY'S CHANCELLOR, ALPHONSE DE SADE. LORD BERKELEY SENDS HIS GREETINGS. THE CORONATION WILL BEGIN SHORTLY.' HE TURNS HIS BACK AND QUICKLY MOVES AWAY."

```text
event 03 {
  exit_event();  // 0x8579
}
```

## Event 04

- Target: `0x8A30`
- Text hint: 'THE TELLTALE ON THE DOOR READS,'

```text
event 04 {
  area1.event_word_22A = abs_0001;  // 0x8A30
  area1.event_word_226 = 1;  // 0x8A37
  goto 0x8D1B;  // 0x8A3D
  // branch body 0x8D1B
    // 0x8D1B-0x8D21
    if (1 == area1.event_word_208) {
      exit_event();  // 0x8D22
    }
    printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
    print_return();  // 0x8D3E
    print_return();  // 0x8D3F
    print('BERTH ');  // 0x8D40
    print('<string at area1.event_word_22A>');  // 0x8D48
    // 0x8D4C-0x8D52
    if (1 == area1.event_word_226) {
      exit_event();  // 0x8D53
    }
    print_return();  // 0x8D54
    print('SHIP:  ');  // 0x8D55
    print('<string at scratch.word_0000>');  // 0x8D5E
    print_return();  // 0x8D62
    print('HOMEPORT:  ');  // 0x8D63
    print('<string at scratch.word_0208>');  // 0x8D6F
    exit_event();  // 0x8D73
}
```

## Event 05

- Target: `0x8A41`
- Text hint: 'THE TELLTALE ON THE DOOR READS,'

```text
event 05 {
  area1.event_word_22A = abs_0001;  // 0x8A41
  area1.event_word_226 = 1;  // 0x8A48
  goto 0x8D1B;  // 0x8A4E
  // branch body 0x8D1B
    // 0x8D1B-0x8D21
    if (1 == area1.event_word_208) {
      exit_event();  // 0x8D22
    }
    printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
    print_return();  // 0x8D3E
    print_return();  // 0x8D3F
    print('BERTH ');  // 0x8D40
    print('<string at area1.event_word_22A>');  // 0x8D48
    // 0x8D4C-0x8D52
    if (1 == area1.event_word_226) {
      exit_event();  // 0x8D53
    }
    print_return();  // 0x8D54
    print('SHIP:  ');  // 0x8D55
    print('<string at scratch.word_0000>');  // 0x8D5E
    print_return();  // 0x8D62
    print('HOMEPORT:  ');  // 0x8D63
    print('<string at scratch.word_0208>');  // 0x8D6F
    exit_event();  // 0x8D73
}
```

## Event 06

- Target: `0x8A52`
- Text hint: 'THE TELLTALE ON THE DOOR READS,'

```text
event 06 {
  // 0x8A52-0x8A58
  if (0 != area1.event_word_258) {
    goto 0x8A89;  // 0x8A59
    // branch body 0x8A89
    // 0x8A89-0x8A8F
    if (3 >= area1.event_word_258) {
      exit_event();  // 0x8A90
    }
    // 0x8A91-0x8A9A
    area2.event_scratch0 = 16 & area1.event_word_25E;  // 0x8A91
    if (area2.event_scratch0 != 0) {
      goto 0x8C27;  // 0x8A9B
      // branch body 0x8C27
      setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x8C27
      exit_event();  // 0x8C2E
    }
    // 0x8A9F-0x8AA8
    area2.event_scratch0 = 2 & area1.event_word_25E;  // 0x8A9F
    if (area2.event_scratch0 == 0) {
      goto 0x8A5D;  // 0x8AA9
      // branch body 0x8A5D
      area1.event_word_22A = abs_0001;  // 0x8A5D
      area1.event_word_226 = 0;  // 0x8A64
      scratch.word_0000 = abs_0006;  // 0x8A6A
      scratch.word_0208 = abs_0009;  // 0x8A76
      goto 0x8D1B;  // 0x8A85
      // branch body 0x8D1B
        // 0x8D1B-0x8D21
        if (1 == area1.event_word_208) {
          exit_event();  // 0x8D22
        }
        printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
        print_return();  // 0x8D3E
        print_return();  // 0x8D3F
        print('BERTH ');  // 0x8D40
        print('<string at area1.event_word_22A>');  // 0x8D48
        // 0x8D4C-0x8D52
        if (1 == area1.event_word_226) {
          exit_event();  // 0x8D53
        }
        print_return();  // 0x8D54
        print('SHIP:  ');  // 0x8D55
        print('<string at scratch.word_0000>');  // 0x8D5E
        print_return();  // 0x8D62
        print('HOMEPORT:  ');  // 0x8D63
        print('<string at scratch.word_0208>');  // 0x8D6F
        exit_event();  // 0x8D73
    }
    exit_event();  // 0x8AAE
  }
  area1.event_word_22A = abs_0001;  // 0x8A5D
  area1.event_word_226 = 0;  // 0x8A64
  scratch.word_0000 = abs_0006;  // 0x8A6A
  scratch.word_0208 = abs_0009;  // 0x8A76
  goto 0x8D1B;  // 0x8A85
  // branch body 0x8D1B
    // target 0x8D1B already emitted
}
```

## Event 07

- Target: `0x8C46`
- Text hint: 'THE TELLTALE ON THE DOOR READS,' RETURN

```text
event 07 {
  // 0x8C46-0x8C4F
  area2.event_scratch0 = 8 & area1.event_word_25A;  // 0x8C46
  if (area2.event_scratch0 != 0) {
    goto 0x8CF5;  // 0x8C50
    // branch body 0x8CF5
    area1.event_word_22A = abs_0001;  // 0x8CF5
    scratch.word_0000 = abs_0007;  // 0x8CFC
    scratch.word_0208 = abs_0006;  // 0x8D09
    area1.event_word_226 = 0;  // 0x8D15
    // 0x8D1B-0x8D21
    if (1 == area1.event_word_208) {
      exit_event();  // 0x8D22
    }
    printclear('THE TELLTALE ON THE DOOR READS,');  // 0x8D23
    print_return();  // 0x8D3E
    print_return();  // 0x8D3F
    print('BERTH ');  // 0x8D40
    print('<string at area1.event_word_22A>');  // 0x8D48
    // 0x8D4C-0x8D52
    if (1 == area1.event_word_226) {
      exit_event();  // 0x8D53
    }
    print_return();  // 0x8D54
    print('SHIP:  ');  // 0x8D55
    print('<string at scratch.word_0000>');  // 0x8D5E
    print_return();  // 0x8D62
    print('HOMEPORT:  ');  // 0x8D63
    print('<string at scratch.word_0208>');  // 0x8D6F
    exit_event();  // 0x8D73
  }
  setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x8C54
  exit_event();  // 0x8C5B
}
```

## Event 08

- Target: `0x8D74`
- Text hint: "A SERVICE DROID APPROACHES YOU. 'WELCOME TO THE RISING SUN. ARE YOU STAYING?'"

```text
event 08 {
  // 0x8D74-0x8D7A
  if (0 != abs_C04E) {
    exit_event();  // 0x8D7B
  }
  printclear("A SERVICE DROID APPROACHES YOU. 'WELCOME TO THE RISING SUN. ARE YOU STAYING?'");  // 0x8D7C
  // 0x8DD2-0x8DDB
  area2.event_scratch0 = 1 & area1.event_word_25C;  // 0x8DD2
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8DDC
  }
  printclear('AN OLD ROCKET JOCK WITH BLEARY EYES GREETS YOU WITH A SLURRED VOICE.');  // 0x8DDD
  exit_event();  // 0x8E2F
}
```

## Event 09

- Target: `0x8DD2`
- Text hint: 'AN OLD ROCKET JOCK WITH BLEARY EYES GREETS YOU WITH A SLURRED VOICE.'

```text
event 09 {
  // 0x8DD2-0x8DDB
  area2.event_scratch0 = 1 & area1.event_word_25C;  // 0x8DD2
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8DDC
  }
  printclear('AN OLD ROCKET JOCK WITH BLEARY EYES GREETS YOU WITH A SLURRED VOICE.');  // 0x8DDD
  exit_event();  // 0x8E2F
}
```

## Event 10

- Target: `0x8E2E`
- Text hint: "A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '" '<string at area2.selected_player_name>' '<string at scratch.word_0208>'

```text
event 10 {
  exit_event();  // 0x8E2F
}
```

## Event 11

- Target: `0x8E9E`
- Text hint: "A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '" '<string at area2.selected_player_name>' '<string at scratch.word_0208>'

```text
event 11 {
  // 0x8E9E-0x8EA7
  area2.event_scratch0 = 1 & area1.event_word_25C;  // 0x8E9E
  if (area2.event_scratch0 != 0) {
    goto 0x8F19;  // 0x8EA8
    // branch body 0x8F19
    // 0x8F19-0x8F22
    area2.event_scratch0 = 4 & area1.event_word_25C;  // 0x8F19
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8F23
    }
    // 0x8F24-0x8F2D
    area2.event_scratch0 = 2 & area1.event_word_25E;  // 0x8F24
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8F2E
    }
    area1.event_word_20E = 2;  // 0x8F2F
    goto 0x8EB2;  // 0x8F35
    // branch body 0x8EB2
      printclear("A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '");  // 0x8EB2
      scratch.word_0208 = abs_0024;  // 0x8ED8
      print('<string at area2.selected_player_name>');  // 0x8F02
      print('<string at scratch.word_0208>');  // 0x8F06
      print_return();  // 0x8F0A
      print('<string at area2.selected_player_name>');  // 0x8F0B
      print('<string at scratch.word_0208>');  // 0x8F0F
      print("'");  // 0x8F13
      // 0x8F19-0x8F22
      area2.event_scratch0 = 4 & area1.event_word_25C;  // 0x8F19
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8F23
      }
      // 0x8F24-0x8F2D
      area2.event_scratch0 = 2 & area1.event_word_25E;  // 0x8F24
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8F2E
      }
      area1.event_word_20E = 2;  // 0x8F2F
      goto 0x8EB2;  // 0x8F35
      // branch body 0x8EB2
        // target 0x8EB2 already emitted
  }
  area1.event_word_20E = 1;  // 0x8EAC
  printclear("A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '");  // 0x8EB2
  scratch.word_0208 = abs_0024;  // 0x8ED8
  print('<string at area2.selected_player_name>');  // 0x8F02
  print('<string at scratch.word_0208>');  // 0x8F06
  print_return();  // 0x8F0A
  print('<string at area2.selected_player_name>');  // 0x8F0B
  print('<string at scratch.word_0208>');  // 0x8F0F
  print("'");  // 0x8F13
  // 0x8F19-0x8F22
  area2.event_scratch0 = 4 & area1.event_word_25C;  // 0x8F19
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8F23
  }
  // 0x8F24-0x8F2D
  area2.event_scratch0 = 2 & area1.event_word_25E;  // 0x8F24
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8F2E
  }
  area1.event_word_20E = 2;  // 0x8F2F
  goto 0x8EB2;  // 0x8F35
  // branch body 0x8EB2
    // target 0x8EB2 already emitted
}
```

## Event 12

- Target: `0x8F39`
- Text hint: 'YOU ENTER A DOCKSIDE BAR. '

```text
event 12 {
  exit_event();  // 0x8F39
}
```

## Event 13

- Target: `0x8F3A`
- Text hint: 'YOU ENTER A DOCKSIDE BAR. '

```text
event 13 {
  // 0x8F3A-0x8F40
  if (2 != mapDirection) {
    exit_event();  // 0x8F41
  }
  printclear('YOU ENTER A DOCKSIDE BAR. ');  // 0x8F42
  sprite(OFF);  // 0x8F59
  exit_event();  // 0x8F5D
}
```

## Event 14

- Target: `0x90EE`
- Text hint: "A TINNY VOICE INTONES, 'THIS IS A CARGO ELEVATOR ONLY. PLEASE EXIT.'"

```text
event 14 {
  printclear("A TINNY VOICE INTONES, 'THIS IS A CARGO ELEVATOR ONLY. PLEASE EXIT.'");  // 0x90EE
  exit_event();  // 0x9124
}
```

## Event 15

- Target: `0x9125`
- Text hint: 'TECHNICIANS ARE BUSY AT THEIR COM STATIONS.'

```text
event 15 {
  // 0x9125-0x912B
  if (0 != abs_C04E) {
    exit_event();  // 0x912C
  }
  printclear('TECHNICIANS ARE BUSY AT THEIR COM STATIONS.');  // 0x912D
  // 0x9151-0x915A
  area2.event_scratch0 = 128 & area1.event_word_25A;  // 0x9151
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x915B
  }
  // 0x915C-0x9165
  area2.event_scratch0 = 8 & area1.event_word_25E;  // 0x915C
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9166
  }
  print(" ONE SAYS, '");  // 0x9167
  gosub 0xA1C5;  // 0x9173
  // 0x9178-0x917E
  if (0 != abs_C04E) {
    exit_event();  // 0x917F
  }
  printclear('THE PORTMASTER IS TOO BUSY TO SPEAK TO YOU.');  // 0x9180
  printclear('HONOR GUARDS STAND AT ATTENTION. ');  // 0x91A6
  exit_event();  // 0x91C2
}
```

## Event 16

- Target: `0x9178`
- Text hint: 'THE PORTMASTER IS TOO BUSY TO SPEAK TO YOU.' 'HONOR GUARDS STAND AT ATTENTION. '

```text
event 16 {
  // 0x9178-0x917E
  if (0 != abs_C04E) {
    exit_event();  // 0x917F
  }
  printclear('THE PORTMASTER IS TOO BUSY TO SPEAK TO YOU.');  // 0x9180
  printclear('HONOR GUARDS STAND AT ATTENTION. ');  // 0x91A6
  exit_event();  // 0x91C2
}
```

## Event 17

- Target: `0x91A6`
- Text hint: 'HONOR GUARDS STAND AT ATTENTION. '

```text
event 17 {
  printclear('HONOR GUARDS STAND AT ATTENTION. ');  // 0x91A6
  exit_event();  // 0x91C2
}
```

## Event 18

- Target: `0x91C3`
- Text hint: "CHANCELLOR DE SADE SHAKES YOUR HAND GRACIOUSLY. '"

```text
event 18 {
  // 0x91C3-0x91C9
  if (1 == area1.event_word_20E) {
    goto 0x96B7;  // 0x91CA
    // branch body 0x96B7
    // 0x96B7-0x96BD
    if (0 != abs_C04E) {
      exit_event();  // 0x96BE
    }
    printclear('NOBODY IS HERE.');  // 0x96BF
    exit_event();  // 0x96CE
  }
  // 0x91CE-0x91D7
  area2.event_scratch0 = 3 & area1.event_word_25E;  // 0x91CE
  if (area2.event_scratch0 != 0) {
    goto 0x96B7;  // 0x91D8
    // branch body 0x96B7
    // target 0x96B7 already emitted
  }
  // 0x91DC-0x91E5
  area2.event_scratch0 = 8 & area1.event_word_25E;  // 0x91DC
  if (area2.event_scratch0 == 0) {
    goto 0x96B7;  // 0x91E6
    // branch body 0x96B7
    // target 0x96B7 already emitted
  }
  setup_monster(sprite_id: 33 max_distance: 0 pic_id: 255);  // 0x91EA
  exit_event();  // 0x91F1
}
```

## Event 19

- Target: `0x92FB`
- Text hint: "CHANCELLOR DE SADE SHAKES YOUR HAND GRACIOUSLY. '" 'WITH BERKELEY DEAD, THERE IS NO NEED TO CONTINUE ANY NEGOTIATIONS ON AN ALLIANCE. NEVERTHELESS,' 'IT IS GOOD THAT YOU WERE HERE, AND TO SHOW OUR APPRECIATION,'

```text
event 19 {
  // 0x92FB-0x9304
  area2.event_scratch0 = 8 & area1.event_word_25E;  // 0x92FB
  if (area2.event_scratch0 == 0) {
    goto 0x96B7;  // 0x9305
    // branch body 0x96B7
    // 0x96B7-0x96BD
    if (0 != abs_C04E) {
      exit_event();  // 0x96BE
    }
    printclear('NOBODY IS HERE.');  // 0x96BF
    exit_event();  // 0x96CE
  }
  // 0x9309-0x9312
  area2.event_scratch0 = 32 & area1.event_word_25C;  // 0x9309
  if (area2.event_scratch0 != 0) {
    goto 0x9618;  // 0x9313
    // branch body 0x9618
    // 0x9618-0x9621
    area2.event_scratch0 = 64 & area1.event_word_25C;  // 0x9618
    if (area2.event_scratch0 == 0) {
      goto 0x96B7;  // 0x9622
      // branch body 0x96B7
      // target 0x96B7 already emitted
    }
    // 0x9626-0x962F
    area2.event_scratch0 = 128 & area1.event_word_25C;  // 0x9626
    if (area2.event_scratch0 != 0) {
      goto 0x96B7;  // 0x9630
      // branch body 0x96B7
      // target 0x96B7 already emitted
    }
    setup_monster(sprite_id: 255 max_distance: 0 pic_id: 86);  // 0x9634
    exit_event();  // 0x963B
  }
  // 0x9317-0x931D
  if (3 >= area1.event_word_258) {
    exit_event();  // 0x931E
  }
  picture(block_id: 86);  // 0x931F
  printclear("CHANCELLOR DE SADE SHAKES YOUR HAND GRACIOUSLY. '");  // 0x9322
  // 0x934A-0x9353
  area2.event_scratch0 = 2 & area1.event_word_25A;  // 0x934A
  if (area2.event_scratch0 != 0) {
    print('WITH BERKELEY DEAD, THERE IS NO NEED TO CONTINUE ANY NEGOTIATIONS ON AN ALLIANCE. NEVERTHELESS,');  // 0x9354
  }
  if_=(<if compare flag is false, skip next op>);  // 0x939F
  print('IT IS GOOD THAT YOU WERE HERE, AND TO SHOW OUR APPRECIATION,');  // 0x93A0
  print(" HERE IS PAYMENT FOR YOUR SERVICES.'");  // 0x93D0
  // truncated at 0x9618
}
```

## Event 20

- Target: `0x96CF`
- Text hint: "A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DESPERATELY. 'I AM DR. ROMNEY. PLEASE HELP ME GET TO THE SUN KING. IT IS MOST URGENT.'"

```text
event 20 {
  // 0x96CF-0x96D5
  if (0 != area1.event_word_258) {
    exit_event();  // 0x96D6
  }
  area1.event_word_258 = 1;  // 0x96D7
  printclear("A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DESPERATELY. 'I AM DR. ROMNEY. PLEASE HELP ME GET TO THE SUN KING. IT IS MOST URGENT.'");  // 0x96DD
  // truncated at 0x9B80
}
```

## Event 21

- Target: `0x9B80`
- Text hint: 'THIS IS A PRIVATE RESIDENCE.'

```text
event 21 {
  // 0x9B80-0x9B86
  if (0 != abs_C04E) {
    exit_event();  // 0x9B87
  }
  printclear('THIS IS A PRIVATE RESIDENCE.');  // 0x9B88
  exit_event();  // 0x9BA0
}
```

## Event 22

- Target: `0x9BA1`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 22 {
  exit_event();  // 0x9BA1
}
```

## Event 23

- Target: `0x9BA1`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 23 {
  exit_event();  // 0x9BA1
}
```

## Event 24

- Target: `0x9BA2`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 24 {
  scratch.word_0208 = abs_000C;  // 0x9BA2
  goto 0xA086;  // 0x9BB4
  // branch body 0xA086
    printclear('A PLAQUE READS,');  // 0xA086
    print_return();  // 0xA095
    print_return();  // 0xA096
    print("       '");  // 0xA097
    print('<string at scratch.word_0208>');  // 0xA0A0
    print(".'");  // 0xA0A4
    exit_event();  // 0xA0A9
}
```

## Event 25

- Target: `0x9BB8`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 25 {
  // 0x9BB8-0x9BBE
  if (1 == area1.event_word_20E) {
    goto 0xA008;  // 0x9BBF
    // branch body 0xA008
    // 0xA008-0xA00E
    if (3 != mapDirection) {
      exit_event();  // 0xA00F
    }
    printclear('PEOPLE MILL ABOUT, WAITING FOR THE SUN KING.');  // 0xA010
    scratch.word_0208 = abs_0009;  // 0xA036
    goto 0xA086;  // 0xA045
    // branch body 0xA086
      printclear('A PLAQUE READS,');  // 0xA086
      print_return();  // 0xA095
      print_return();  // 0xA096
      print("       '");  // 0xA097
      print('<string at scratch.word_0208>');  // 0xA0A0
      print(".'");  // 0xA0A4
      exit_event();  // 0xA0A9
  }
  // 0x9BC3-0x9BCC
  area2.event_scratch0 = 8 & area1.event_word_25E;  // 0x9BC3
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9BCD
  }
  printclear('THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.');  // 0x9BCE
  // truncated at 0xA008
}
```

## Event 26

- Target: `0xA036`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 26 {
  scratch.word_0208 = abs_0009;  // 0xA036
  goto 0xA086;  // 0xA045
  // branch body 0xA086
    printclear('A PLAQUE READS,');  // 0xA086
    print_return();  // 0xA095
    print_return();  // 0xA096
    print("       '");  // 0xA097
    print('<string at scratch.word_0208>');  // 0xA0A0
    print(".'");  // 0xA0A4
    exit_event();  // 0xA0A9
}
```

## Event 27

- Target: `0xA049`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 27 {
  exit_event();  // 0xA049
}
```

## Event 28

- Target: `0xA0AA`
- Text hint: "THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'"

```text
event 28 {
  printclear("THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'");  // 0xA0AA
  scratch.word_0208 = abs_0005;  // 0xA176
  goto 0xA086;  // 0xA181
  // branch body 0xA086
    printclear('A PLAQUE READS,');  // 0xA086
    print_return();  // 0xA095
    print_return();  // 0xA096
    print("       '");  // 0xA097
    print('<string at scratch.word_0208>');  // 0xA0A0
    print(".'");  // 0xA0A4
    exit_event();  // 0xA0A9
}
```

## Event 29

- Target: `0xA04A`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 29 {
  scratch.word_0208 = abs_000B;  // 0xA04A
  goto 0xA086;  // 0xA05B
  // branch body 0xA086
    printclear('A PLAQUE READS,');  // 0xA086
    print_return();  // 0xA095
    print_return();  // 0xA096
    print("       '");  // 0xA097
    print('<string at scratch.word_0208>');  // 0xA0A0
    print(".'");  // 0xA0A4
    exit_event();  // 0xA0A9
}
```

## Event 30

- Target: `0xA176`
- Text hint: "HOLD ON, A MESSAGE FOR YOU IS JUST COMING IN.'"

```text
event 30 {
  scratch.word_0208 = abs_0005;  // 0xA176
  goto 0xA086;  // 0xA181
  // branch body 0xA086
    printclear('A PLAQUE READS,');  // 0xA086
    print_return();  // 0xA095
    print_return();  // 0xA096
    print("       '");  // 0xA097
    print('<string at scratch.word_0208>');  // 0xA0A0
    print(".'");  // 0xA0A4
    exit_event();  // 0xA0A9
}
```

## Event 31

- Target: `0xA05F`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 31 {
  scratch.word_0208 = abs_000B;  // 0xA05F
  goto 0xA086;  // 0xA070
  // branch body 0xA086
    printclear('A PLAQUE READS,');  // 0xA086
    print_return();  // 0xA095
    print_return();  // 0xA096
    print("       '");  // 0xA097
    print('<string at scratch.word_0208>');  // 0xA0A0
    print(".'");  // 0xA0A4
    exit_event();  // 0xA0A9
}
```

## Event 32

- Target: `0xA074`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 32 {
  scratch.word_0208 = abs_000C;  // 0xA074
  printclear('A PLAQUE READS,');  // 0xA086
  print_return();  // 0xA095
  print_return();  // 0xA096
  print("       '");  // 0xA097
  print('<string at scratch.word_0208>');  // 0xA0A0
  print(".'");  // 0xA0A4
  exit_event();  // 0xA0A9
}
```
