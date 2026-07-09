# GEO 80: Mars Prison, Level 1

ECL block: `80`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 02

- Target: `0x90F8`
- Text hint: 'A HOLE HERE LEADS INTO AN ENVIROCELL. CLIMB DOWN?' "YOU BURST INTO THE PRISON'S SURVEILLANCE ROOM." ' IT IS EMPTY.'

```text
event 02 {
  printclear('A HOLE HERE LEADS INTO AN ENVIROCELL. CLIMB DOWN?');  // 0x90F8
  // 0x9142-0x9148
  if (13 != area1.event_word_21C) {
    printclear("YOU BURST INTO THE PRISON'S SURVEILLANCE ROOM.");  // 0x914A
  }
  // 0x9170-0x9179
  area2.event_scratch0 = 16 & area1.event_word_208;  // 0x9170
  if (area2.event_scratch0 != 0) {
    print(' IT IS EMPTY.');  // 0x917A
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x9187
  exit_event();  // 0x9188
}
```

## Event 03

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 03 {
  compare(Values: area1.event_word_21A == mapDirection);  // 0x8352
  area1.event_word_21A = mapDirection;  // 0x8359
  if_=(<if compare flag is false, skip next op>);  // 0x8360
  // 0x8362-0x8368
  if (255 == area1.event_word_212) {
    exit_event();  // 0x8369
  }
  // 0x836A-0x8373
  area2.event_scratch0 = 128 & area1.event_word_208;  // 0x836A
  if (area2.event_scratch0 != 0) {
    add(area1.event_word_232 = 1 + area1.event_word_232);  // 0x8375
  }
  // 0x837E-0x8384
  if (12 < area1.event_word_232) {
    random(area2.event_scratch0 = random 1..70);  // 0x8386
  }
  // 0x838C-0x8393
  if (area1.event_word_232 > area2.event_scratch0) {
    add(area1.event_word_234 = 1 + area1.event_word_234);  // 0x8395
  }
  // 0x839E-0x83A4
  if (3 > area1.event_word_234) {
    area1.event_word_234 = 0;  // 0x83A5
  }
  // 0x83AB
  switch (area1.event_word_234) {
    case 0: goto 0x8427;
      // case 0 body
      gettable(area2.event_scratch0 = abs_A3BD[area1.event_word_21A]);  // 0x8427
      // 0x8431-0x843B
      area2.event_scratch0 = area2.event_scratch0 & area1.event_word_216;  // 0x8431
      if (area2.event_scratch0 == 0) {
        goto 0x849D;  // 0x843C
        // branch body 0x849D
        area1.event_word_22A = 0;  // 0x849D
        gosub 0xA345;  // 0x84A3
        // 0x84A7-0x84AD
        if (0 == area1.event_word_234) {
          printclear('A TOUGH PRISON GANG!');  // 0x84AE
        }
        if_<>(<if compare flag is false, skip next op>);  // 0x84C0
        printclear('TWO CONVICTS.');  // 0x84C1
        gosub 0xA31E;  // 0x84CE
        if_=(<if compare flag is false, skip next op>);  // 0x84D2
        if_>(<if compare flag is false, skip next op>);  // 0x84D4
        goto 0x8626;  // 0x84D5
        // branch body 0x8626
          clearmonsters();  // 0x8626
          gettable(area2.event_scratch0 = abs_A3CD[area1.event_word_21A]);  // 0x8627
          // 0x8631-0x8637
          if (0 != area1.event_word_234) {
            area2.event_scratch0 = 2;  // 0x8638
          }
          load_monster(monster_id: area1.event_word_23A copies: area2.event_scratch0 cpic_id: area1.event_word_23A);  // 0x863E
          combat();  // 0x8648
          // 0x8649-0x864F
          if (128 > area2.word_58E) {
            printclear('YOU STOP WHEN THE FELONS ARE THOROUGHLY BEATEN.');  // 0x8651
          }
          // 0x881D-0x8823
          if (255 == area1.event_word_236) {
            compare(Values: 30 == area1.event_word_226);  // 0x8825
          }
          if_=(<if compare flag is false, skip next op>);  // 0x882B
          goto 0x8930;  // 0x882C
      }
      and(area2.event_scratch0 = 3 & area1.event_word_216);  // 0x8440
      // 0x8449-0x844F
      if (0 == area2.event_scratch0) {
        random(area1.event_word_21A = random 1..2);  // 0x8450
      }
      if_=(<if compare flag is false, skip next op>);  // 0x8456
      goto 0x8427;  // 0x8457
      // branch body 0x8427
        // target 0x8427 already emitted
    case 1: goto 0x94BD;
      // case 1 body
      printclear('THE PRISON AUTOSURGEONS FIND YOU.');  // 0x94BD
      exit_event();  // 0x94DA
    case 2: goto 0x849D;
      // case 2 body
      // target 0x849D already emitted
  }
}
```

## Event 05

- Target: `0x9363`
- Text hint: 'THE PRISON AUTOSURGEONS FIND YOU.'

```text
event 05 {
  // 0x9363-0x936C
  area2.event_scratch0 = 128 & area1.event_word_208;  // 0x9363
  if (area2.event_scratch0 != 0) {
    goto 0x950A;  // 0x936D
    // branch body 0x950A
    or(area1.event_word_208 = 128 | area1.event_word_208);  // 0x950A
    area1.event_word_228 = 255;  // 0x9513
    printclear('THE HULK IS A LADDER TO THE HATCH ABOVE. GO UP?');  // 0x9519
    printclear('A HATCH. GO DOWN?');  // 0x954B
    // 0x9566-0x956F
    area2.event_scratch0 = 4 & area1.event_word_20A;  // 0x9566
    if (area2.event_scratch0 != 0) {
      goto 0x8330;  // 0x9570
      // branch body 0x8330
      // 0x8330-0x8336
      if (8 != area1.event_word_204) {
        compare(Values: 9 == area1.event_word_204);  // 0x8337
      }
      if_<>(<if compare flag is false, skip next op>);  // 0x833D
      printclear('THE CONSOLE IS DEAD.');  // 0x833F
      exit_event();  // 0x8351
    }
    // 0x9574-0x957D
    area2.event_scratch0 = 16 & area1.event_word_20A;  // 0x9574
    if (area2.event_scratch0 != 0) {
      picture(block_id: 98);  // 0x957E
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x9581
    goto 0x9608;  // 0x9582
    // branch body 0x9608
      printclear("SCOT SHRIEKS. 'DIGITAL SHARKS - EATING ME ALIVE!");  // 0x9608
      // 0x962F-0x9635
      if (5 < area1.event_word_21E) {
        print(' SHUT ALL DATA CELLS!');  // 0x9636
      }
      if_>(<if compare flag is false, skip next op>);  // 0x9649
      print(' HELP!');  // 0x964A
      print("'");  // 0x9652
      // truncated at 0x9C4B
  }
  setup_monster(sprite_id: 49 max_distance: 1 pic_id: 255);  // 0x9371
  exit_event();  // 0x9378
}
```

## Event 06

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 06 {
  compare(Values: area1.event_word_21A == mapDirection);  // 0x8352
  area1.event_word_21A = mapDirection;  // 0x8359
  if_=(<if compare flag is false, skip next op>);  // 0x8360
  // 0x8362-0x8368
  if (255 == area1.event_word_212) {
    exit_event();  // 0x8369
  }
  // 0x836A-0x8373
  area2.event_scratch0 = 128 & area1.event_word_208;  // 0x836A
  if (area2.event_scratch0 != 0) {
    add(area1.event_word_232 = 1 + area1.event_word_232);  // 0x8375
  }
  // 0x837E-0x8384
  if (12 < area1.event_word_232) {
    random(area2.event_scratch0 = random 1..70);  // 0x8386
  }
  // 0x838C-0x8393
  if (area1.event_word_232 > area2.event_scratch0) {
    add(area1.event_word_234 = 1 + area1.event_word_234);  // 0x8395
  }
  // 0x839E-0x83A4
  if (3 > area1.event_word_234) {
    area1.event_word_234 = 0;  // 0x83A5
  }
  // 0x83AB
  switch (area1.event_word_234) {
    case 0: goto 0x8427;
      // case 0 body
      gettable(area2.event_scratch0 = abs_A3BD[area1.event_word_21A]);  // 0x8427
      // 0x8431-0x843B
      area2.event_scratch0 = area2.event_scratch0 & area1.event_word_216;  // 0x8431
      if (area2.event_scratch0 == 0) {
        goto 0x849D;  // 0x843C
        // branch body 0x849D
        area1.event_word_22A = 0;  // 0x849D
        gosub 0xA345;  // 0x84A3
        // 0x84A7-0x84AD
        if (0 == area1.event_word_234) {
          printclear('A TOUGH PRISON GANG!');  // 0x84AE
        }
        if_<>(<if compare flag is false, skip next op>);  // 0x84C0
        printclear('TWO CONVICTS.');  // 0x84C1
        gosub 0xA31E;  // 0x84CE
        if_=(<if compare flag is false, skip next op>);  // 0x84D2
        if_>(<if compare flag is false, skip next op>);  // 0x84D4
        goto 0x8626;  // 0x84D5
        // branch body 0x8626
          clearmonsters();  // 0x8626
          gettable(area2.event_scratch0 = abs_A3CD[area1.event_word_21A]);  // 0x8627
          // 0x8631-0x8637
          if (0 != area1.event_word_234) {
            area2.event_scratch0 = 2;  // 0x8638
          }
          load_monster(monster_id: area1.event_word_23A copies: area2.event_scratch0 cpic_id: area1.event_word_23A);  // 0x863E
          combat();  // 0x8648
          // 0x8649-0x864F
          if (128 > area2.word_58E) {
            printclear('YOU STOP WHEN THE FELONS ARE THOROUGHLY BEATEN.');  // 0x8651
          }
          // 0x881D-0x8823
          if (255 == area1.event_word_236) {
            compare(Values: 30 == area1.event_word_226);  // 0x8825
          }
          if_=(<if compare flag is false, skip next op>);  // 0x882B
          goto 0x8930;  // 0x882C
      }
      and(area2.event_scratch0 = 3 & area1.event_word_216);  // 0x8440
      // 0x8449-0x844F
      if (0 == area2.event_scratch0) {
        random(area1.event_word_21A = random 1..2);  // 0x8450
      }
      if_=(<if compare flag is false, skip next op>);  // 0x8456
      goto 0x8427;  // 0x8457
      // branch body 0x8427
        // target 0x8427 already emitted
    case 1: goto 0x94BD;
      // case 1 body
      printclear('THE PRISON AUTOSURGEONS FIND YOU.');  // 0x94BD
      exit_event();  // 0x94DA
    case 2: goto 0x849D;
      // case 2 body
      // target 0x849D already emitted
  }
}
```

## Event 07

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 07 {
  compare(Values: area1.event_word_21A == mapDirection);  // 0x8352
  area1.event_word_21A = mapDirection;  // 0x8359
  if_=(<if compare flag is false, skip next op>);  // 0x8360
  // 0x8362-0x8368
  if (255 == area1.event_word_212) {
    exit_event();  // 0x8369
  }
  // 0x836A-0x8373
  area2.event_scratch0 = 128 & area1.event_word_208;  // 0x836A
  if (area2.event_scratch0 != 0) {
    add(area1.event_word_232 = 1 + area1.event_word_232);  // 0x8375
  }
  // 0x837E-0x8384
  if (12 < area1.event_word_232) {
    random(area2.event_scratch0 = random 1..70);  // 0x8386
  }
  // 0x838C-0x8393
  if (area1.event_word_232 > area2.event_scratch0) {
    add(area1.event_word_234 = 1 + area1.event_word_234);  // 0x8395
  }
  // 0x839E-0x83A4
  if (3 > area1.event_word_234) {
    area1.event_word_234 = 0;  // 0x83A5
  }
  // 0x83AB
  switch (area1.event_word_234) {
    case 0: goto 0x8427;
      // case 0 body
      gettable(area2.event_scratch0 = abs_A3BD[area1.event_word_21A]);  // 0x8427
      // 0x8431-0x843B
      area2.event_scratch0 = area2.event_scratch0 & area1.event_word_216;  // 0x8431
      if (area2.event_scratch0 == 0) {
        goto 0x849D;  // 0x843C
        // branch body 0x849D
        area1.event_word_22A = 0;  // 0x849D
        gosub 0xA345;  // 0x84A3
        // 0x84A7-0x84AD
        if (0 == area1.event_word_234) {
          printclear('A TOUGH PRISON GANG!');  // 0x84AE
        }
        if_<>(<if compare flag is false, skip next op>);  // 0x84C0
        printclear('TWO CONVICTS.');  // 0x84C1
        gosub 0xA31E;  // 0x84CE
        if_=(<if compare flag is false, skip next op>);  // 0x84D2
        if_>(<if compare flag is false, skip next op>);  // 0x84D4
        goto 0x8626;  // 0x84D5
        // branch body 0x8626
          clearmonsters();  // 0x8626
          gettable(area2.event_scratch0 = abs_A3CD[area1.event_word_21A]);  // 0x8627
          // 0x8631-0x8637
          if (0 != area1.event_word_234) {
            area2.event_scratch0 = 2;  // 0x8638
          }
          load_monster(monster_id: area1.event_word_23A copies: area2.event_scratch0 cpic_id: area1.event_word_23A);  // 0x863E
          combat();  // 0x8648
          // 0x8649-0x864F
          if (128 > area2.word_58E) {
            printclear('YOU STOP WHEN THE FELONS ARE THOROUGHLY BEATEN.');  // 0x8651
          }
          // 0x881D-0x8823
          if (255 == area1.event_word_236) {
            compare(Values: 30 == area1.event_word_226);  // 0x8825
          }
          if_=(<if compare flag is false, skip next op>);  // 0x882B
          goto 0x8930;  // 0x882C
      }
      and(area2.event_scratch0 = 3 & area1.event_word_216);  // 0x8440
      // 0x8449-0x844F
      if (0 == area2.event_scratch0) {
        random(area1.event_word_21A = random 1..2);  // 0x8450
      }
      if_=(<if compare flag is false, skip next op>);  // 0x8456
      goto 0x8427;  // 0x8457
      // branch body 0x8427
        // target 0x8427 already emitted
    case 1: goto 0x94BD;
      // case 1 body
      printclear('THE PRISON AUTOSURGEONS FIND YOU.');  // 0x94BD
      exit_event();  // 0x94DA
    case 2: goto 0x849D;
      // case 2 body
      // target 0x849D already emitted
  }
}
```

## Event 09

- Target: `0x8352`
- Text hint: 'YOU HEAR DOG GENNIES!' 'THE DOGS MOVE OFF.'

```text
event 09 {
  compare(Values: area1.event_word_21A == mapDirection);  // 0x8352
  area1.event_word_21A = mapDirection;  // 0x8359
  if_=(<if compare flag is false, skip next op>);  // 0x8360
  // 0x8362-0x8368
  if (255 == area1.event_word_212) {
    exit_event();  // 0x8369
  }
  // 0x836A-0x8373
  area2.event_scratch0 = 128 & area1.event_word_208;  // 0x836A
  if (area2.event_scratch0 != 0) {
    add(area1.event_word_232 = 1 + area1.event_word_232);  // 0x8375
  }
  // 0x837E-0x8384
  if (12 < area1.event_word_232) {
    random(area2.event_scratch0 = random 1..70);  // 0x8386
  }
  // 0x838C-0x8393
  if (area1.event_word_232 > area2.event_scratch0) {
    add(area1.event_word_234 = 1 + area1.event_word_234);  // 0x8395
  }
  // 0x839E-0x83A4
  if (3 > area1.event_word_234) {
    area1.event_word_234 = 0;  // 0x83A5
  }
  // 0x83AB
  switch (area1.event_word_234) {
    case 0: goto 0x8427;
      // case 0 body
      gettable(area2.event_scratch0 = abs_A3BD[area1.event_word_21A]);  // 0x8427
      // 0x8431-0x843B
      area2.event_scratch0 = area2.event_scratch0 & area1.event_word_216;  // 0x8431
      if (area2.event_scratch0 == 0) {
        goto 0x849D;  // 0x843C
        // branch body 0x849D
        area1.event_word_22A = 0;  // 0x849D
        gosub 0xA345;  // 0x84A3
        // 0x84A7-0x84AD
        if (0 == area1.event_word_234) {
          printclear('A TOUGH PRISON GANG!');  // 0x84AE
        }
        if_<>(<if compare flag is false, skip next op>);  // 0x84C0
        printclear('TWO CONVICTS.');  // 0x84C1
        gosub 0xA31E;  // 0x84CE
        if_=(<if compare flag is false, skip next op>);  // 0x84D2
        if_>(<if compare flag is false, skip next op>);  // 0x84D4
        goto 0x8626;  // 0x84D5
        // branch body 0x8626
          clearmonsters();  // 0x8626
          gettable(area2.event_scratch0 = abs_A3CD[area1.event_word_21A]);  // 0x8627
          // 0x8631-0x8637
          if (0 != area1.event_word_234) {
            area2.event_scratch0 = 2;  // 0x8638
          }
          load_monster(monster_id: area1.event_word_23A copies: area2.event_scratch0 cpic_id: area1.event_word_23A);  // 0x863E
          combat();  // 0x8648
          // 0x8649-0x864F
          if (128 > area2.word_58E) {
            printclear('YOU STOP WHEN THE FELONS ARE THOROUGHLY BEATEN.');  // 0x8651
          }
          // 0x881D-0x8823
          if (255 == area1.event_word_236) {
            compare(Values: 30 == area1.event_word_226);  // 0x8825
          }
          if_=(<if compare flag is false, skip next op>);  // 0x882B
          goto 0x8930;  // 0x882C
      }
      and(area2.event_scratch0 = 3 & area1.event_word_216);  // 0x8440
      // 0x8449-0x844F
      if (0 == area2.event_scratch0) {
        random(area1.event_word_21A = random 1..2);  // 0x8450
      }
      if_=(<if compare flag is false, skip next op>);  // 0x8456
      goto 0x8427;  // 0x8457
      // branch body 0x8427
        // target 0x8427 already emitted
    case 1: goto 0x94BD;
      // case 1 body
      printclear('THE PRISON AUTOSURGEONS FIND YOU.');  // 0x94BD
      exit_event();  // 0x94DA
    case 2: goto 0x849D;
      // case 2 body
      // target 0x849D already emitted
  }
}
```
