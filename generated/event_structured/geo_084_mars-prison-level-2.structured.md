# GEO 84: Mars Prison, Level 2

ECL block: `84`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x81F0`
- Text hint: 'AN ELEVATOR GOING DOWN. DO YOU USE IT?'

```text
event 01 {
  printclear('AN ELEVATOR GOING DOWN. DO YOU USE IT?');  // 0x81F0
  // 0x8272-0x8278
  if (mapDirection != 2) {
    exit_event();  // 0x8279
  }
  printclear('AN EMPTY COMPUTER LAB. ');  // 0x827A
  // 0x828F-0x8298
  area2.event_scratch0 = 1 & area1.event_word_310;  // 0x828F
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8299
  }
  area2.event_scratch1 = 1;  // 0x829A
  area2.event_scratch2 = 2;  // 0x82A0
  party_surprise(zone: 83, result: area2.event_scratch1);  // 0x82A6
  // 0x82AF-0x82B5
  if (area2.event_scratch2 > 2) {
    exit_event();  // 0x82B6
  }
  load_character(index: area2.event_scratch1);  // 0x82B7
  printclear('<string at area2.selected_player_name>');  // 0x82BC
  print(' NOTICES THAT A COMPUTER AT THE SOUTH END OF THE ROOM IS ON.');  // 0x82C0
  // 0x82F2-0x82FB
  area2.event_scratch0 = 1 & area1.event_word_310;  // 0x82F2
  if (area2.event_scratch0 != 0) {
    goto 0x84D1;  // 0x82FC
    // branch body 0x84D1
    printclear('THE COMPUTER IS OFF.');  // 0x84D1
    exit_event();  // 0x84E3
  }
  // 0x8300-0x8309
  area2.event_scratch0 = 2 & area1.event_word_310;  // 0x8300
  if (area2.event_scratch0 != 0) {
    goto 0x839D;  // 0x830A
    // branch body 0x839D
    printclear('THE COMPUTER SCREEN READS:');  // 0x839D
    print_return();  // 0x83B4
    print_return();  // 0x83B5
    print('- RUN CURRENT SEQUENCE? -');  // 0x83B6
    print_return();  // 0x83CC
    print_return();  // 0x83CD
    print_return();  // 0x83CE
    sprite(OFF);  // 0x83CF
    exit_event();  // 0x83D3
  }
  printclear('THE TERMINAL OF THIS COMPUTER IS ACTIVE. DO YOU TRY TO OPERATE THE COMPUTER?');  // 0x830E
  printclear('THE COMPUTER SCREEN READS:');  // 0x839D
  print_return();  // 0x83B4
  print_return();  // 0x83B5
  print('- RUN CURRENT SEQUENCE? -');  // 0x83B6
  print_return();  // 0x83CC
  print_return();  // 0x83CD
  print_return();  // 0x83CE
  sprite(OFF);  // 0x83CF
  exit_event();  // 0x83D3
}
```

## Event 04

- Target: `0x84E4`
- Text hint: 'A WEAPONS LABORATORY. '

```text
event 04 {
  // 0x84E4-0x84EA
  if (mapDirection != 1) {
    exit_event();  // 0x84EB
  }
  printclear('A WEAPONS LABORATORY. ');  // 0x84EC
  // 0x8500-0x8509
  area2.event_scratch0 = 4 & area1.event_word_310;  // 0x8500
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x850A
  }
  setup_monster(sprite_id: 12 max_distance: 2 pic_id: 255);  // 0x850B
  exit_event();  // 0x8512
}
```

## Event 08

- Target: `0x8905`
- Text hint: 'AN EMPTY PHYSICS LAB.'

```text
event 08 {
  // 0x8905-0x890B
  if (mapDirection != 2) {
    exit_event();  // 0x890C
  }
  printclear('AN EMPTY PHYSICS LAB.');  // 0x890D
  exit_event();  // 0x8920
}
```

## Event 10

- Target: `0x8C77`
- Text hint: 'AN EMPTY BOTANY LAB.'

```text
event 10 {
  // 0x8C77-0x8C7D
  if (mapDirection != 0) {
    exit_event();  // 0x8C7E
  }
  printclear('AN EMPTY BOTANY LAB.');  // 0x8C7F
  exit_event();  // 0x8C91
}
```

## Event 11

- Target: `0x8C92`
- Text hint: 'AN EMPTY BIOLOGY LAB.'

```text
event 11 {
  // 0x8C92-0x8C98
  if (mapDirection != 0) {
    exit_event();  // 0x8C99
  }
  printclear('AN EMPTY BIOLOGY LAB.');  // 0x8C9A
  exit_event();  // 0x8CAD
}
```

## Event 12

- Target: `0x8CAE`
- Text hint: 'A MEDIA LAB.'

```text
event 12 {
  // 0x8CAE-0x8CB4
  if (mapDirection != 0) {
    exit_event();  // 0x8CB5
  }
  printclear('A MEDIA LAB.');  // 0x8CB6
  // 0x8CC2-0x8CCB
  area2.event_scratch0 = 128 & area1.event_word_310;  // 0x8CC2
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8CCC
  }
  print(' PURGE SCIENTISTS ARE GATHERED AROUND A TABLE. ');  // 0x8CCD
  sprite(OFF);  // 0x8CF4
  exit_event();  // 0x8CF8
}
```

## Event 13

- Target: `0x8E99`
- Text hint: 'AUDIO AND VIDEO CAPSULES ARE STORED HERE.'

```text
event 13 {
  // 0x8E99-0x8E9F
  if (mapDirection != 3) {
    exit_event();  // 0x8EA0
  }
  printclear('AUDIO AND VIDEO CAPSULES ARE STORED HERE.');  // 0x8EA1
  exit_event();  // 0x8EC3
}
```

## Event 14

- Target: `0x8EC4`
- Text hint: 'A RESTING LOUNGE. NO ONE IS HERE.'

```text
event 14 {
  // 0x8EC4-0x8ECA
  if (mapDirection != 0) {
    exit_event();  // 0x8ECB
  }
  printclear('A RESTING LOUNGE. NO ONE IS HERE.');  // 0x8ECC
  exit_event();  // 0x8EE8
}
```

## Event 15

- Target: `0x8EE9`
- Text hint: 'A MEETING ROOM. A LARGE TABLE SURROUNDED BY CHAIRS IS HERE.'

```text
event 15 {
  // 0x8EE9-0x8EEF
  if (mapDirection != 2) {
    exit_event();  // 0x8EF0
  }
  printclear('A MEETING ROOM. A LARGE TABLE SURROUNDED BY CHAIRS IS HERE.');  // 0x8EF1
  exit_event();  // 0x8F21
}
```

## Event 16

- Target: `0x8F22`
- Text hint: 'A COMPUTER LAB. '

```text
event 16 {
  // 0x8F22-0x8F28
  if (mapDirection != 2) {
    exit_event();  // 0x8F29
  }
  printclear('A COMPUTER LAB. ');  // 0x8F2A
  // 0x8F39-0x8F42
  area2.event_scratch0 = 1 & area1.event_word_31C;  // 0x8F39
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8F43
  }
  area2.event_scratch1 = 1;  // 0x8F45
  area2.event_scratch2 = 2;  // 0x8F4B
  party_surprise(zone: 83, result: area2.event_scratch1);  // 0x8F51
  // 0x8F5A-0x8F60
  if (area2.event_scratch2 > 2) {
    exit_event();  // 0x8F61
  }
  load_character(index: area2.event_scratch1);  // 0x8F62
  printclear('<string at area2.selected_player_name>');  // 0x8F66
  print(' NOTICES A NOTE PAD SITTING AT THE COMPUTER DESK ACROSS THE ROOM.');  // 0x8F6A
  // 0x8FA0-0x8FA9
  area2.event_scratch0 = 1 & area1.event_word_31C;  // 0x8FA0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8FAA
  }
  printclear('YOU FIND A NOTE PAD SITTING ON THE COMPUTER DESK');  // 0x8FAB
  find_special(raw=(abs_000A));  // 0x8FD2
  exit_event();  // 0x8FDF
}
```

## Event 17

- Target: `0x8FA0`
- Text hint: 'YOU FIND A NOTE PAD SITTING ON THE COMPUTER DESK'

```text
event 17 {
  // 0x8FA0-0x8FA9
  area2.event_scratch0 = 1 & area1.event_word_31C;  // 0x8FA0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8FAA
  }
  printclear('YOU FIND A NOTE PAD SITTING ON THE COMPUTER DESK');  // 0x8FAB
  find_special(raw=(abs_000A));  // 0x8FD2
  exit_event();  // 0x8FDF
}
```

## Event 18

- Target: `0x8FEB`
- Text hint: 'A BROOM CLOSET.'

```text
event 18 {
  // 0x8FEB-0x8FF1
  if (mapDirection != 2) {
    exit_event();  // 0x8FF2
  }
  printclear('A BROOM CLOSET.');  // 0x8FF3
  exit_event();  // 0x9002
}
```

## Event 19

- Target: `0x9003`
- Text hint: 'AS YOU ENTER THE ROOM, HANIBL SOOTH RISES FROM A CHAIR. HE PULLS A CLUSTER OF ELECTRODES FROM HIS SCALP. A TECHNICIAN ATTENDS HIM.'

```text
event 19 {
  // 0x9003-0x9009
  if (mapDirection != 3) {
    exit_event();  // 0x900A
  }
  // 0x900B-0x9014
  area2.event_scratch0 = 2 & area1.event_word_31C;  // 0x900B
  if (area2.event_scratch0 != 0) {
    goto 0x9220;  // 0x9015
    // branch body 0x9220
    printclear('THE BODY OF THE PURGE COMMANDER, HANIBL SOOTH, LIES HERE');  // 0x9220
    // 0x924D-0x9256
    area2.event_scratch0 = 4 & area1.event_word_31C;  // 0x924D
    if (area2.event_scratch0 != 0) {
      print('.');  // 0x9257
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x925B
    exit_event();  // 0x925C
  }
  printclear('AS YOU ENTER THE ROOM, HANIBL SOOTH RISES FROM A CHAIR. HE PULLS A CLUSTER OF ELECTRODES FROM HIS SCALP. A TECHNICIAN ATTENDS HIM.');  // 0x9019
  printclear('THE BODY OF THE PURGE COMMANDER, HANIBL SOOTH, LIES HERE');  // 0x9220
  // 0x924D-0x9256
  area2.event_scratch0 = 4 & area1.event_word_31C;  // 0x924D
  if (area2.event_scratch0 != 0) {
    print('.');  // 0x9257
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x925B
  exit_event();  // 0x925C
}
```

## Event 20

- Target: `0x92C3`
- Text hint: "YOU HEAR HANIBL SOOTH'S VOICE TO THE EAST!"

```text
event 20 {
  // 0x92C3-0x92C9
  if (mapDirection != 0) {
    exit_event();  // 0x92CA
  }
  // 0x92CB-0x92D4
  area2.event_scratch0 = 16 & area1.event_word_31C;  // 0x92CB
  if (area2.event_scratch0 != 0) {
    goto 0x9584;  // 0x92D5
    // branch body 0x9584
    // 0x9584-0x958D
    area2.event_scratch0 = 32 & area1.event_word_31C;  // 0x9584
    if (area2.event_scratch0 == 0) {
      goto 0x95B4;  // 0x958E
      // branch body 0x95B4
      setup_monster(sprite_id: 12 max_distance: 0 pic_id: 255);  // 0x95B4
      exit_event();  // 0x95BB
    }
    // 0x9592-0x959B
    area2.event_scratch0 = 128 & area1.event_word_314;  // 0x9592
    if (area2.event_scratch0 == 0) {
      goto 0x9520;  // 0x959C
      // branch body 0x9520
      area2.word_58C = 100;  // 0x9520
      area2.surprise_result = 1;  // 0x9526
      setup_monster(sprite_id: 255 max_distance: 2 pic_id: 31);  // 0x952C
      exit_event();  // 0x9533
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x95A0
    printclear("DR. MALCOLN'S LAB.");  // 0x95A1
    if_<>(<if compare flag is false, skip next op>);  // 0x95B2
    exit_event();  // 0x95B3
  }
  printclear("YOU HEAR HANIBL SOOTH'S VOICE TO THE EAST!");  // 0x92D9
  area2.word_58C = 100;  // 0x9520
  area2.surprise_result = 1;  // 0x9526
  setup_monster(sprite_id: 255 max_distance: 2 pic_id: 31);  // 0x952C
  exit_event();  // 0x9533
}
```

## Event 21

- Target: `0x95DE`
- Text hint: 'THE SCREEN OF THIS COMPUTER READS:' RETURN

```text
event 21 {
  // 0x95DE-0x95E4
  if (area1.event_word_31E == 1) {
    goto 0x9631;  // 0x95E5
    // branch body 0x9631
    printclear('THESE COMPUTERS ARE INACTIVE.');  // 0x9631
    exit_event();  // 0x964A
  }
  printclear('THE SCREEN OF THIS COMPUTER READS:');  // 0x95E9
  print_return();  // 0x9606
  print_return();  // 0x9607
  print(' -- ACCESS DENIED --');  // 0x9608
  print_return();  // 0x961A
  print('--SOOTH.DOP OVERRIDE --');  // 0x961B
  exit_event();  // 0x9630
}
```

## Event 22

- Target: `0x964B`
- Text hint: 'THE SIGN OVER THE DOOR READS:' RETURN

```text
event 22 {
  // 0x964B-0x9651
  if (mapDirection != 1) {
    exit_event();  // 0x9652
  }
  printclear('THE SIGN OVER THE DOOR READS:');  // 0x9653
  print_return();  // 0x966C
  print_return();  // 0x966D
  print('-- MAIN COMPUTER TRUNK --');  // 0x966E
  exit_event();  // 0x9684
}
```

## Event 24

- Target: `0x982C`
- Text hint: 'THE MAIN COMPUTER IS SHUT DOWN.'

```text
event 24 {
  // 0x982C-0x9832
  if (area1.event_word_31E == 1) {
    printclear('THE MAIN COMPUTER IS SHUT DOWN.');  // 0x9833
  }
  if_=(<if compare flag is false, skip next op>);  // 0x984E
  exit_event();  // 0x984F
}
```
