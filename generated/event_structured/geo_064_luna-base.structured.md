# GEO 64: Luna Base

ECL block: `64`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x819B`
- Text hint: "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"

```text
event 01 {
  exit_event();  // 0x819B
}
```

## Event 02

- Target: `0x819C`
- Text hint: "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"

```text
event 02 {
  // 0x819C-0x81A5
  area2.event_scratch0 = area1.event_word_200 & 1;  // 0x819C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x81A6
  }
  or(area1.event_word_200 = area1.event_word_200 | 1);  // 0x81A7
  printclear("AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'");  // 0x81B0
  // 0x81F6-0x81FF
  area2.event_scratch0 = area1.event_word_200 & 8;  // 0x81F6
  if (area2.event_scratch0 != 0) {
    goto 0x8225;  // 0x8200
    // branch body 0x8225
    // 0x8225-0x822B
    if (2 == mapDirection) {
      exit_event();  // 0x822C
    }
    scratch.word_0258 = abs_000C;  // 0x822D
    goto 0x9830;  // 0x823F
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  or(area1.event_word_200 = area1.event_word_200 | 8);  // 0x8204
  printclear('YOU SPOT DR. COLDOR AHEAD.');  // 0x820D
  exit_event();  // 0x8224
}
```

## Event 03

- Target: `0x819B`
- Text hint: "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"

```text
event 03 {
  exit_event();  // 0x819B
}
```

## Event 04

- Target: `0x81F6`
- Text hint: 'YOU SPOT DR. COLDOR AHEAD.'

```text
event 04 {
  // 0x81F6-0x81FF
  area2.event_scratch0 = area1.event_word_200 & 8;  // 0x81F6
  if (area2.event_scratch0 != 0) {
    goto 0x8225;  // 0x8200
    // branch body 0x8225
    // 0x8225-0x822B
    if (2 == mapDirection) {
      exit_event();  // 0x822C
    }
    scratch.word_0258 = abs_000C;  // 0x822D
    goto 0x9830;  // 0x823F
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  or(area1.event_word_200 = area1.event_word_200 | 8);  // 0x8204
  printclear('YOU SPOT DR. COLDOR AHEAD.');  // 0x820D
  exit_event();  // 0x8224
}
```

## Event 05

- Target: `0x8243`
- Text hint: "A GREY-SUITED MAN LOOKS UP. 'WHO ARE YOU HERE TO SEE?'"

```text
event 05 {
  // 0x8243-0x8249
  if (3 == mapDirection) {
    exit_event();  // 0x824A
  }
  scratch.word_0258 = abs_000D;  // 0x824B
  goto 0x9830;  // 0x825E
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 06

- Target: `0x8262`
- Text hint: "A GREY-SUITED MAN LOOKS UP. 'WHO ARE YOU HERE TO SEE?'"

```text
event 06 {
  // 0x8262-0x8268
  if (1 != mapDirection) {
    exit_event();  // 0x8269
  }
  // 0x826A-0x8270
  if (1 == area1.event_word_20C) {
    goto 0x82C8;  // 0x8271
    // branch body 0x82C8
    printclear("A MAN SHOUTS, 'TERRORISTS!'");  // 0x82C8
    goto 0x97FE;  // 0x82E0
    // branch body 0x97FE
      setup_monster(sprite_id: 14 max_distance: 0 pic_id: 255);  // 0x97FE
      exit_event();  // 0x9805
  }
  printclear("A GREY-SUITED MAN LOOKS UP. 'WHO ARE YOU HERE TO SEE?'");  // 0x8275
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LT. JENNER', 'POLICE CHIEF');  // 0x82A1
  // 0x82BC
  switch (area2.event_scratch0) {
    case 0: goto 0x82E4;
      // case 0 body
      printclear("'AH, YES. GO RIGHT AND STRAIGHT.'");  // 0x82E4
      compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x8302
      if_=(<if compare flag is false, skip next op>);  // 0x830D
      goto 0x8333;  // 0x830E
      // branch body 0x8333
        printclear("'THROUGH THE DOOR ON THE LEFT.'");  // 0x8333
        // 0x8350-0x8356
        if (1 == area1.event_word_20C) {
          goto 0x8545;  // 0x8357
          // branch body 0x8545
          // 0x8545-0x854E
          area2.event_scratch0 = area1.event_word_200 & 4;  // 0x8545
          if (area2.event_scratch0 != 0) {
            exit_event();  // 0x854F
          }
          or(area1.event_word_200 = area1.event_word_200 | 4);  // 0x8550
          printclear('JENNER LEAVES AS OTHERS RUSH IN.');  // 0x8559
          goto 0x97FE;  // 0x8574
        }
        // 0x835B-0x8364
        area2.event_scratch0 = area1.event_word_200 & 2;  // 0x835B
        if (area2.event_scratch0 != 0) {
          goto 0x8495;  // 0x8365
          // branch body 0x8495
          // 0x8495-0x849B
          if (1 == area1.event_word_214) {
            goto 0x84EB;  // 0x849C
          }
          compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x84A0
          if_=(<if compare flag is false, skip next op>);  // 0x84AB
          goto 0x851B;  // 0x84AC
        }
        or(area1.event_word_200 = area1.event_word_200 | 2);  // 0x8369
        printclear("A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS.");  // 0x8372
        // 0x8495-0x849B
        if (1 == area1.event_word_214) {
          goto 0x84EB;  // 0x849C
          // branch body 0x84EB
          printclear("'COLDOR IS IN THE TSAI LABS. DEAL WITH HER HOW YOU WILL.'");  // 0x84EB
          printclear("'JUST GET A MEETING WITH THEM AND I WILL RAID IT.'");  // 0x851B
          exit_event();  // 0x8544
        }
        compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x84A0
        if_=(<if compare flag is false, skip next op>);  // 0x84AB
        goto 0x851B;  // 0x84AC
        // branch body 0x851B
          printclear("'JUST GET A MEETING WITH THEM AND I WILL RAID IT.'");  // 0x851B
          exit_event();  // 0x8544
    case 1: goto 0x8302;
      // case 1 body
      compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x8302
      if_=(<if compare flag is false, skip next op>);  // 0x830D
      goto 0x8333;  // 0x830E
      // branch body 0x8333
        // target 0x8333 already emitted
  }
}
```

## Event 07

- Target: `0x8350`
- Text hint: "A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS."

```text
event 07 {
  // 0x8350-0x8356
  if (1 == area1.event_word_20C) {
    goto 0x8545;  // 0x8357
    // branch body 0x8545
    // 0x8545-0x854E
    area2.event_scratch0 = area1.event_word_200 & 4;  // 0x8545
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x854F
    }
    or(area1.event_word_200 = area1.event_word_200 | 4);  // 0x8550
    printclear('JENNER LEAVES AS OTHERS RUSH IN.');  // 0x8559
    goto 0x97FE;  // 0x8574
    // branch body 0x97FE
      setup_monster(sprite_id: 14 max_distance: 0 pic_id: 255);  // 0x97FE
      exit_event();  // 0x9805
  }
  // 0x835B-0x8364
  area2.event_scratch0 = area1.event_word_200 & 2;  // 0x835B
  if (area2.event_scratch0 != 0) {
    goto 0x8495;  // 0x8365
    // branch body 0x8495
    // 0x8495-0x849B
    if (1 == area1.event_word_214) {
      goto 0x84EB;  // 0x849C
      // branch body 0x84EB
      printclear("'COLDOR IS IN THE TSAI LABS. DEAL WITH HER HOW YOU WILL.'");  // 0x84EB
      printclear("'JUST GET A MEETING WITH THEM AND I WILL RAID IT.'");  // 0x851B
      exit_event();  // 0x8544
    }
    compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x84A0
    if_=(<if compare flag is false, skip next op>);  // 0x84AB
    goto 0x851B;  // 0x84AC
    // branch body 0x851B
      printclear("'JUST GET A MEETING WITH THEM AND I WILL RAID IT.'");  // 0x851B
      exit_event();  // 0x8544
  }
  or(area1.event_word_200 = area1.event_word_200 | 2);  // 0x8369
  printclear("A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS.");  // 0x8372
  // 0x8495-0x849B
  if (1 == area1.event_word_214) {
    goto 0x84EB;  // 0x849C
    // branch body 0x84EB
    // target 0x84EB already emitted
  }
  compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x84A0
  if_=(<if compare flag is false, skip next op>);  // 0x84AB
  goto 0x851B;  // 0x84AC
  // branch body 0x851B
    // target 0x851B already emitted
}
```

## Event 08

- Target: `0x8579`
- Text hint: "'YOU'RE IN THE WRONG OFFICE.'"

```text
event 08 {
  // 0x8579-0x857F
  if (1 == area1.event_word_20C) {
    goto 0x859E;  // 0x8580
    // branch body 0x859E
    printclear('POLICE RUSH YOU.');  // 0x859E
    goto 0x97FE;  // 0x85AD
    // branch body 0x97FE
      setup_monster(sprite_id: 14 max_distance: 0 pic_id: 255);  // 0x97FE
      exit_event();  // 0x9805
  }
  printclear("'YOU'RE IN THE WRONG OFFICE.'");  // 0x8584
  exit_event();  // 0x859D
}
```

## Event 09

- Target: `0x85B2`
- Text hint: 'A POLICEMAN STANDS BEFORE YOU. '

```text
event 09 {
  // 0x85B2-0x85B8
  if (1 == area1.event_word_20C) {
    goto 0x859E;  // 0x85B9
    // branch body 0x859E
    printclear('POLICE RUSH YOU.');  // 0x859E
    goto 0x97FE;  // 0x85AD
    // branch body 0x97FE
      setup_monster(sprite_id: 14 max_distance: 0 pic_id: 255);  // 0x97FE
      exit_event();  // 0x9805
  }
  // 0x85BD-0x85C3
  if (0 != mapDirection) {
    exit_event();  // 0x85C4
  }
  printclear('A POLICEMAN STANDS BEFORE YOU. ');  // 0x85C5
  compare_and(Values: area1.event_word_20E == 1 && area1.event_word_210 == 1);  // 0x85E0
  if_<>(<if compare flag is false, skip next op>);  // 0x85EB
  goto 0x860D;  // 0x85EC
  // branch body 0x860D
    print("'YOU'RE NOT ALLOWED HERE.' ");  // 0x860D
    sprite(OFF);  // 0x8625
    exit_event();  // 0x8629
}
```

## Event 10

- Target: `0x8667`
- Text hint: "MCKAY LOOKS UP. 'ALL RIGHT, WHAT DO YOU WANT?'"

```text
event 10 {
  // 0x8667-0x866D
  if (1 == area1.event_word_20C) {
    goto 0x859E;  // 0x866E
    // branch body 0x859E
    printclear('POLICE RUSH YOU.');  // 0x859E
    goto 0x97FE;  // 0x85AD
    // branch body 0x97FE
      setup_monster(sprite_id: 14 max_distance: 0 pic_id: 255);  // 0x97FE
      exit_event();  // 0x9805
  }
  // 0x8672-0x867B
  area2.event_scratch0 = area1.event_word_200 & 16;  // 0x8672
  if (area2.event_scratch0 != 0) {
    goto 0x86EB;  // 0x867C
    // branch body 0x86EB
    printclear('THE OFFICE IS EMPTY.');  // 0x86EB
    gosub 0xA320;  // 0x86FD
    exit_event();  // 0x8701
  }
  or(area1.event_word_200 = area1.event_word_200 | 16);  // 0x8680
  // 0x8689-0x868F
  if (1 == area1.event_word_212) {
    goto 0x86EB;  // 0x8690
    // branch body 0x86EB
    // target 0x86EB already emitted
  }
  printclear("MCKAY LOOKS UP. 'ALL RIGHT, WHAT DO YOU WANT?'");  // 0x8694
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'A CUT', 'DR. COLDOR', 'POWER FOR NEO');  // 0x86BA
  // 0x86DC
  switch (area2.event_scratch0) {
    case 0: goto 0x8702;
      // case 0 body
      printclear("'EXTORTION IS SO CRUDE.");  // 0x8702
      goto 0x8751;  // 0x8717
      // branch body 0x8751
        print(" STILL, MEET ME AT KOI'S OFFICES. WE WILL DISCUSS IT.'");  // 0x8751
        // 0x8785-0x878E
        area2.event_scratch0 = area1.event_word_200 & 2;  // 0x8785
        if (area2.event_scratch0 != 0) {
          goto 0x89A7;  // 0x878F
          // branch body 0x89A7
          // 0x89A7-0x89AD
          if (1 == mapDirection) {
            exit_event();  // 0x89AE
          }
          scratch.word_0258 = abs_000B;  // 0x89AF
          goto 0x9830;  // 0x89C0
        }
        // 0x8793-0x879C
        area2.event_scratch0 = area1.event_word_200 & 32;  // 0x8793
        if (area2.event_scratch0 != 0) {
          goto 0x89A7;  // 0x879D
          // branch body 0x89A7
          // target 0x89A7 already emitted
        }
        or(area1.event_word_200 = area1.event_word_200 | 32);  // 0x87A1
        printclear('YOU REACH DR. COLDOR AS SHE IS ABOUT TO ENTER A JET CAR. ');  // 0x87AA
        sprite(OFF);  // 0x87D8
        exit_event();  // 0x87DC
    case 1: goto 0x871B;
      // case 1 body
      printclear("'HER WORK IS ESSENTIAL TO US.");  // 0x871B
      goto 0x8751;  // 0x8734
      // branch body 0x8751
        // target 0x8751 already emitted
    case 2: goto 0x8738;
      // case 2 body
      printclear('WE HAVE DONE SO MUCH ALREADY.');  // 0x8738
      print(" STILL, MEET ME AT KOI'S OFFICES. WE WILL DISCUSS IT.'");  // 0x8751
      // 0x8785-0x878E
      area2.event_scratch0 = area1.event_word_200 & 2;  // 0x8785
      if (area2.event_scratch0 != 0) {
        goto 0x89A7;  // 0x878F
        // branch body 0x89A7
        // target 0x89A7 already emitted
      }
      // 0x8793-0x879C
      area2.event_scratch0 = area1.event_word_200 & 32;  // 0x8793
      if (area2.event_scratch0 != 0) {
        goto 0x89A7;  // 0x879D
        // branch body 0x89A7
        // target 0x89A7 already emitted
      }
      or(area1.event_word_200 = area1.event_word_200 | 32);  // 0x87A1
      printclear('YOU REACH DR. COLDOR AS SHE IS ABOUT TO ENTER A JET CAR. ');  // 0x87AA
      sprite(OFF);  // 0x87D8
      exit_event();  // 0x87DC
  }
}
```

## Event 11

- Target: `0x8785`
- Text hint: 'YOU REACH DR. COLDOR AS SHE IS ABOUT TO ENTER A JET CAR. '

```text
event 11 {
  // 0x8785-0x878E
  area2.event_scratch0 = area1.event_word_200 & 2;  // 0x8785
  if (area2.event_scratch0 != 0) {
    goto 0x89A7;  // 0x878F
    // branch body 0x89A7
    // 0x89A7-0x89AD
    if (1 == mapDirection) {
      exit_event();  // 0x89AE
    }
    scratch.word_0258 = abs_000B;  // 0x89AF
    goto 0x9830;  // 0x89C0
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  // 0x8793-0x879C
  area2.event_scratch0 = area1.event_word_200 & 32;  // 0x8793
  if (area2.event_scratch0 != 0) {
    goto 0x89A7;  // 0x879D
    // branch body 0x89A7
    // target 0x89A7 already emitted
  }
  or(area1.event_word_200 = area1.event_word_200 | 32);  // 0x87A1
  printclear('YOU REACH DR. COLDOR AS SHE IS ABOUT TO ENTER A JET CAR. ');  // 0x87AA
  sprite(OFF);  // 0x87D8
  exit_event();  // 0x87DC
}
```

## Event 12

- Target: `0x89C4`
- Text hint: 'THE STORE CONTAINS ROW AFTER ROW OF LUXURY GOODS AND FOODS.'

```text
event 12 {
  // 0x89C4-0x89CA
  if (3 != mapDirection) {
    exit_event();  // 0x89CB
  }
  // 0x89CC-0x89D2
  if (1 == area1.event_word_20C) {
    goto 0x8A08;  // 0x89D3
    // branch body 0x8A08
    printclear('PATRONS PANIC AND SCATTER AT YOUR APPROACH. POLICE ARRIVE.');  // 0x8A08
    // 0x8A3C-0x8A42
    if (3 == mapDirection) {
      exit_event();  // 0x8A43
    }
    scratch.word_0258 = abs_000E;  // 0x8A44
    goto 0x9830;  // 0x8A58
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  printclear('THE STORE CONTAINS ROW AFTER ROW OF LUXURY GOODS AND FOODS.');  // 0x89D7
  exit_event();  // 0x8A07
}
```

## Event 13

- Target: `0x8A3C`
- Text hint: "THE PROPRIETOR COMES UP. 'MAY I HELP YOU?'"

```text
event 13 {
  // 0x8A3C-0x8A42
  if (3 == mapDirection) {
    exit_event();  // 0x8A43
  }
  scratch.word_0258 = abs_000E;  // 0x8A44
  goto 0x9830;  // 0x8A58
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 14

- Target: `0x8A5C`
- Text hint: "THE PROPRIETOR COMES UP. 'MAY I HELP YOU?'"

```text
event 14 {
  // 0x8A5C-0x8A62
  if (1 != mapDirection) {
    exit_event();  // 0x8A63
  }
  // 0x8A64-0x8A6A
  if (1 == area1.event_word_20C) {
    goto 0x8A08;  // 0x8A6B
    // branch body 0x8A08
    printclear('PATRONS PANIC AND SCATTER AT YOUR APPROACH. POLICE ARRIVE.');  // 0x8A08
    // 0x8A3C-0x8A42
    if (3 == mapDirection) {
      exit_event();  // 0x8A43
    }
    scratch.word_0258 = abs_000E;  // 0x8A44
    goto 0x9830;  // 0x8A58
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  picture(block_id: 107);  // 0x8A6F
  printclear("THE PROPRIETOR COMES UP. 'MAY I HELP YOU?'");  // 0x8A72
  goto 0x9856;  // 0x8AB7
  // branch body 0x9856
    printclear('THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?');  // 0x9856
    // truncated at 0xA308
}
```

## Event 15

- Target: `0x8AB7`
- Text hint: "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"

```text
event 15 {
  goto 0x9856;  // 0x8AB7
  // branch body 0x9856
    printclear('THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?');  // 0x9856
    // truncated at 0xA308
}
```

## Event 16

- Target: `0x8ABB`
- Text hint: "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"

```text
event 16 {
  // 0x8ABB-0x8AC1
  if (2 == mapDirection) {
    exit_event();  // 0x8AC2
  }
  scratch.word_0258 = abs_0015;  // 0x8AC3
  goto 0x9830;  // 0x8ADE
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 17

- Target: `0x8AE2`
- Text hint: "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"

```text
event 17 {
  // 0x8AE2-0x8AE8
  if (0 != mapDirection) {
    exit_event();  // 0x8AE9
  }
  // 0x8AEA-0x8AF0
  if (1 == area1.event_word_20C) {
    goto 0x8B6A;  // 0x8AF1
    // branch body 0x8B6A
    // 0x8B6A-0x8B70
    if (1 == area1.event_word_216) {
      exit_event();  // 0x8B71
    }
    printclear('PEOPLE FLEE AT YOUR APPROACH. POLICE SOON ARRIVE.');  // 0x8B72
    // 0x8B9F-0x8BA8
    area2.event_scratch0 = area1.event_word_200 & 2;  // 0x8B9F
    if (area2.event_scratch0 != 0) {
      goto 0x8BF6;  // 0x8BA9
      // branch body 0x8BF6
      printclear("WHEN YOU FLASH THE FORGED BADGE, UDU SAYS, 'FEEL FREE TO LOOK AROUND.'");  // 0x8BF6
      exit_event();  // 0x8C2E
    }
    printclear('UDU IS FRIENDLY, BUT ADAMANTLY OPPOSES YOUR ENTRY. ');  // 0x8BAD
    sprite(OFF);  // 0x8BD7
    exit_event();  // 0x8BDB
  }
  // 0x8AF5-0x8AFB
  if (1 == area1.event_word_212) {
    exit_event();  // 0x8AFC
  }
  printclear("A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'");  // 0x8AFD
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'LOOK AROUND', 'SEE SENATOR', 'NOTHING');  // 0x8B37
  // 0x8B5B
  switch (area2.event_scratch0) {
    case 0: goto 0x8B9F;
      // case 0 body
      // 0x8B9F-0x8BA8
      area2.event_scratch0 = area1.event_word_200 & 2;  // 0x8B9F
      if (area2.event_scratch0 != 0) {
        goto 0x8BF6;  // 0x8BA9
        // branch body 0x8BF6
        // target 0x8BF6 already emitted
      }
      printclear('UDU IS FRIENDLY, BUT ADAMANTLY OPPOSES YOUR ENTRY. ');  // 0x8BAD
      sprite(OFF);  // 0x8BD7
      exit_event();  // 0x8BDB
    case 1: goto 0x8C5D;
      // case 1 body
      printclear("'THE SENATOR IS NOT IN JUST NOW. ");  // 0x8C5D
      // 0x8C79-0x8C82
      area2.event_scratch1 = area1.event_word_200 & 2;  // 0x8C79
      if (area2.event_scratch1 != 0) {
        goto 0x8CBF;  // 0x8C83
        // branch body 0x8CBF
        print("YOU MAY WAIT IN HIS OFFICE WHILE I TRY TO REACH HIM.'");  // 0x8CBF
        // 0x8CEC-0x8CF2
        if (0 != mapDirection) {
          exit_event();  // 0x8CF3
        }
        // 0x8CF4-0x8CFA
        if (1 == area1.event_word_212) {
          goto 0x8DFF;  // 0x8CFB
          // branch body 0x8DFF
          // 0x8DFF-0x8E05
          if (1 == area1.event_word_214) {
            exit_event();  // 0x8E06
          }
          printclear("KOI, MCKAY AND TSAI ARE SITTING HERE. KOI STATES, 'SO WHAT CAN WE DO TO KEEP YOU QUIET?'");  // 0x8E07
          // 0x8EC8-0x8ECE
          if (1 == mapDirection) {
            exit_event();  // 0x8ECF
          }
          scratch.word_0258 = abs_0009;  // 0x8ED0
          goto 0x9830;  // 0x8EDF
        }
        // 0x8CFF-0x8D05
        if (1 == area1.event_word_210) {
          exit_event();  // 0x8D06
        }
        printclear('YOU QUICKLY SEARCH THE OFFICE. ');  // 0x8D07
        // 0x8D22-0x8D2B
        area2.event_scratch0 = area1.event_word_202 & 1;  // 0x8D22
        if (area2.event_scratch0 == 0) {
          goto 0x8D76;  // 0x8D2C
          // branch body 0x8D76
          print('YOU CANNOT FIND ANY INCRIMINATING EVIDENCE.');  // 0x8D76
          // 0x8D9B-0x8DA1
          if (1 != area1.event_word_20C) {
            goto 0x8DC1;  // 0x8DA2
          }
          // 0x8DA6-0x8DAC
          if (1 == area1.event_word_216) {
            exit_event();  // 0x8DAD
          }
          printclear('POLICE ARRIVE.');  // 0x8DAE
          printclear("UDU ENTERS. 'I'M SORRY, BUT SENATOR KOI WILL NOT BE IN. LEAVE WHEN YOU WISH.'");  // 0x8DC1
          exit_event();  // 0x8DFE
        }
        print('YOU FIND ILLEGAL STOCK TRANSFERS LINKING THE SENATOR TO TSAI WEAPONRY.');  // 0x8D30
        gosub 0xA33C;  // 0x8D68
        area1.event_word_210 = 1;  // 0x8D6C
      }
    case 2: goto 0xA308;
  }
}
```

## Event 18

- Target: `0x8CEC`
- Text hint: 'YOU QUICKLY SEARCH THE OFFICE. '

```text
event 18 {
  // 0x8CEC-0x8CF2
  if (0 != mapDirection) {
    exit_event();  // 0x8CF3
  }
  // 0x8CF4-0x8CFA
  if (1 == area1.event_word_212) {
    goto 0x8DFF;  // 0x8CFB
    // branch body 0x8DFF
    // 0x8DFF-0x8E05
    if (1 == area1.event_word_214) {
      exit_event();  // 0x8E06
    }
    printclear("KOI, MCKAY AND TSAI ARE SITTING HERE. KOI STATES, 'SO WHAT CAN WE DO TO KEEP YOU QUIET?'");  // 0x8E07
    // 0x8EC8-0x8ECE
    if (1 == mapDirection) {
      exit_event();  // 0x8ECF
    }
    scratch.word_0258 = abs_0009;  // 0x8ED0
    goto 0x9830;  // 0x8EDF
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  // 0x8CFF-0x8D05
  if (1 == area1.event_word_210) {
    exit_event();  // 0x8D06
  }
  printclear('YOU QUICKLY SEARCH THE OFFICE. ');  // 0x8D07
  // 0x8D22-0x8D2B
  area2.event_scratch0 = area1.event_word_202 & 1;  // 0x8D22
  if (area2.event_scratch0 == 0) {
    goto 0x8D76;  // 0x8D2C
    // branch body 0x8D76
    print('YOU CANNOT FIND ANY INCRIMINATING EVIDENCE.');  // 0x8D76
    // 0x8D9B-0x8DA1
    if (1 != area1.event_word_20C) {
      goto 0x8DC1;  // 0x8DA2
      // branch body 0x8DC1
      printclear("UDU ENTERS. 'I'M SORRY, BUT SENATOR KOI WILL NOT BE IN. LEAVE WHEN YOU WISH.'");  // 0x8DC1
      exit_event();  // 0x8DFE
    }
    // 0x8DA6-0x8DAC
    if (1 == area1.event_word_216) {
      exit_event();  // 0x8DAD
    }
    printclear('POLICE ARRIVE.');  // 0x8DAE
    printclear("UDU ENTERS. 'I'M SORRY, BUT SENATOR KOI WILL NOT BE IN. LEAVE WHEN YOU WISH.'");  // 0x8DC1
    exit_event();  // 0x8DFE
  }
  print('YOU FIND ILLEGAL STOCK TRANSFERS LINKING THE SENATOR TO TSAI WEAPONRY.');  // 0x8D30
  gosub 0xA33C;  // 0x8D68
  area1.event_word_210 = 1;  // 0x8D6C
  goto 0x8D9A;  // 0x8D72
  // branch body 0x8D9A
    // 0x8D9B-0x8DA1
    if (1 != area1.event_word_20C) {
      goto 0x8DC1;  // 0x8DA2
      // branch body 0x8DC1
      // target 0x8DC1 already emitted
    }
    // 0x8DA6-0x8DAC
    if (1 == area1.event_word_216) {
      exit_event();  // 0x8DAD
    }
    printclear('POLICE ARRIVE.');  // 0x8DAE
    printclear("UDU ENTERS. 'I'M SORRY, BUT SENATOR KOI WILL NOT BE IN. LEAVE WHEN YOU WISH.'");  // 0x8DC1
    exit_event();  // 0x8DFE
}
```

## Event 19

- Target: `0x8EC8`
- Text hint: 'THE BAR IS DIM AND HAZY. BLEARY EYED PATRONS SLUMP IN THEIR CHAIRS. DO YOU MINGLE?'

```text
event 19 {
  // 0x8EC8-0x8ECE
  if (1 == mapDirection) {
    exit_event();  // 0x8ECF
  }
  scratch.word_0258 = abs_0009;  // 0x8ED0
  goto 0x9830;  // 0x8EDF
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 20

- Target: `0x8EE3`
- Text hint: 'THE BAR IS DIM AND HAZY. BLEARY EYED PATRONS SLUMP IN THEIR CHAIRS. DO YOU MINGLE?'

```text
event 20 {
  // 0x8EE3-0x8EE9
  if (3 != mapDirection) {
    exit_event();  // 0x8EEA
  }
  // 0x8EEB-0x8EF1
  if (1 == area1.event_word_20C) {
    goto 0x8A08;  // 0x8EF2
    // branch body 0x8A08
    printclear('PATRONS PANIC AND SCATTER AT YOUR APPROACH. POLICE ARRIVE.');  // 0x8A08
    // 0x8A3C-0x8A42
    if (3 == mapDirection) {
      exit_event();  // 0x8A43
    }
    scratch.word_0258 = abs_000E;  // 0x8A44
    goto 0x9830;  // 0x8A58
    // branch body 0x9830
      printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
      print_return();  // 0x9848
      print("'");  // 0x9849
      print('<string at scratch.word_0258>');  // 0x984D
      print("'");  // 0x9851
      exit_event();  // 0x9855
  }
  printclear('THE BAR IS DIM AND HAZY. BLEARY EYED PATRONS SLUMP IN THEIR CHAIRS. DO YOU MINGLE?');  // 0x8EF6
  // 0x9080-0x9086
  if (1 == mapDirection) {
    exit_event();  // 0x9087
  }
  scratch.word_0258 = abs_000C;  // 0x9088
  goto 0x9830;  // 0x909A
  // branch body 0x9830
    // target 0x9830 already emitted
}
```

## Event 21

- Target: `0x9080`
- Text hint: 'THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.'

```text
event 21 {
  // 0x9080-0x9086
  if (1 == mapDirection) {
    exit_event();  // 0x9087
  }
  scratch.word_0258 = abs_000C;  // 0x9088
  goto 0x9830;  // 0x909A
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 22

- Target: `0x909E`
- Text hint: 'THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.'

```text
event 22 {
  // 0x909E-0x90A4
  if (3 != mapDirection) {
    exit_event();  // 0x90A5
  }
  // 0x90A6-0x90AC
  if (1 == area1.event_word_20C) {
    goto 0x90D8;  // 0x90AD
    // branch body 0x90D8
    // 0x90D8-0x90DE
    if (1 == area1.event_word_21A) {
      goto 0x90B1;  // 0x90DF
      // branch body 0x90B1
      printclear('THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.');  // 0x90B1
      exit_event();  // 0x90D7
    }
    printclear('POLICE ARE HERE WAITING.');  // 0x90E3
    printclear('THE STUDY CONTAINS A REAL MAHOGANY DESK.');  // 0x90FD
    // 0x911E-0x9127
    area2.event_scratch0 = area1.event_word_200 & 128;  // 0x911E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9128
    }
    // 0x9129-0x9132
    area2.event_scratch0 = area1.event_word_202 & 2;  // 0x9129
    if (area2.event_scratch0 == 0) {
      gosub 0xA320;  // 0x9133
    }
    if_=(<if compare flag is false, skip next op>);  // 0x9137
    exit_event();  // 0x9138
  }
  printclear('THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.');  // 0x90B1
  exit_event();  // 0x90D7
}
```

## Event 23

- Target: `0x90FD`
- Text hint: 'THE STUDY CONTAINS A REAL MAHOGANY DESK.'

```text
event 23 {
  printclear('THE STUDY CONTAINS A REAL MAHOGANY DESK.');  // 0x90FD
  // 0x911E-0x9127
  area2.event_scratch0 = area1.event_word_200 & 128;  // 0x911E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9128
  }
  // 0x9129-0x9132
  area2.event_scratch0 = area1.event_word_202 & 2;  // 0x9129
  if (area2.event_scratch0 == 0) {
    gosub 0xA320;  // 0x9133
  }
  if_=(<if compare flag is false, skip next op>);  // 0x9137
  exit_event();  // 0x9138
}
```

## Event 24

- Target: `0x9184`
- Text hint: 'THE ROBO-CHEF LOOKS DISUSED.'

```text
event 24 {
  printclear('THE ROBO-CHEF LOOKS DISUSED.');  // 0x9184
  gosub 0xA320;  // 0x919C
  exit_event();  // 0x91A0
}
```

## Event 25

- Target: `0x91A1`
- Text hint: 'THE BED IS NEATLY MADE.'

```text
event 25 {
  printclear('THE BED IS NEATLY MADE.');  // 0x91A1
  gosub 0xA320;  // 0x91B6
  exit_event();  // 0x91BA
}
```

## Event 26

- Target: `0x91BB`
- Text hint: "TSAI'S HOUSE IS BUILT IN AN OPEN STYLE FILLED WITH OPULENT ARTWORK."

```text
event 26 {
  // 0x91BB-0x91C1
  if (3 == mapDirection) {
    exit_event();  // 0x91C2
  }
  scratch.word_0258 = abs_000B;  // 0x91C3
  goto 0x9830;  // 0x91D4
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 27

- Target: `0x91D8`
- Text hint: "TSAI'S HOUSE IS BUILT IN AN OPEN STYLE FILLED WITH OPULENT ARTWORK."

```text
event 27 {
  // 0x91D8-0x91DE
  if (1 != mapDirection) {
    exit_event();  // 0x91DF
  }
  // 0x91E0-0x91E9
  area2.event_scratch0 = area1.event_word_204 & 1;  // 0x91E0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x91EA
  }
  printclear("TSAI'S HOUSE IS BUILT IN AN OPEN STYLE FILLED WITH OPULENT ARTWORK.");  // 0x91EB
  // 0x9221-0x922A
  area2.event_scratch0 = area1.event_word_202 & 4;  // 0x9221
  if (area2.event_scratch0 == 0) {
    gosub 0xA320;  // 0x922B
  }
  if_=(<if compare flag is false, skip next op>);  // 0x922F
  exit_event();  // 0x9230
}
```

## Event 28

- Target: `0x926D`
- Text hint: "AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'"

```text
event 28 {
  // 0x926D-0x9273
  if (2 == mapDirection) {
    exit_event();  // 0x9274
  }
  scratch.word_0258 = abs_0007;  // 0x9275
  goto 0x9830;  // 0x9282
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 29

- Target: `0x9286`
- Text hint: "AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'"

```text
event 29 {
  // 0x9286-0x928C
  if (0 != mapDirection) {
    exit_event();  // 0x928D
  }
  // 0x928E-0x9297
  area2.event_scratch0 = area1.event_word_204 & 128;  // 0x928E
  if (area2.event_scratch0 != 0) {
    goto 0x941F;  // 0x9298
    // branch body 0x941F
    printclear('THE COMPUTER IS INOPERATIVE.');  // 0x941F
    exit_event();  // 0x9437
  }
  // 0x929C-0x92A2
  if (1 == area1.event_word_20C) {
    goto 0x93F8;  // 0x92A3
    // branch body 0x93F8
    // 0x93F8-0x93FE
    if (1 == area1.event_word_21C) {
      goto 0x92A7;  // 0x93FF
      // branch body 0x92A7
      printclear("AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'");  // 0x92A7
      // 0x93F8-0x93FE
      if (1 == area1.event_word_21C) {
        goto 0x92A7;  // 0x93FF
        // branch body 0x92A7
        // target 0x92A7 already emitted
      }
      printclear('POLICE ARE WAITING FOR YOU.');  // 0x9403
      goto 0x97FE;  // 0x941B
      // branch body 0x97FE
        setup_monster(sprite_id: 14 max_distance: 0 pic_id: 255);  // 0x97FE
        exit_event();  // 0x9805
    }
    printclear('POLICE ARE WAITING FOR YOU.');  // 0x9403
    goto 0x97FE;  // 0x941B
    // branch body 0x97FE
      // target 0x97FE already emitted
  }
  printclear("AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'");  // 0x92A7
  // 0x93F8-0x93FE
  if (1 == area1.event_word_21C) {
    goto 0x92A7;  // 0x93FF
    // branch body 0x92A7
    // target 0x92A7 already emitted
  }
  printclear('POLICE ARE WAITING FOR YOU.');  // 0x9403
  goto 0x97FE;  // 0x941B
  // branch body 0x97FE
    // target 0x97FE already emitted
}
```

## Event 30

- Target: `0x9438`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 30 {
  // 0x9438-0x943E
  if (0 == mapDirection) {
    exit_event();  // 0x943F
  }
  scratch.word_0258 = abs_000D;  // 0x9440
  goto 0x9830;  // 0x9453
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 31

- Target: `0x9457`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 31 {
  exit_event();  // 0x9457
}
```

## Event 32

- Target: `0x9458`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 32 {
  // 0x9458-0x945E
  if (1 == area1.event_word_20C) {
    exit_event();  // 0x945F
  }
  area2.training_class_mask = 127;  // 0x9460
  program(StartGameMenu);  // 0x9466
  // 0x946A-0x9470
  if (3 == mapDirection) {
    exit_event();  // 0x9471
  }
  scratch.word_0258 = abs_000A;  // 0x9472
  goto 0x9830;  // 0x9482
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 33

- Target: `0x946A`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 33 {
  // 0x946A-0x9470
  if (3 == mapDirection) {
    exit_event();  // 0x9471
  }
  scratch.word_0258 = abs_000A;  // 0x9472
  goto 0x9830;  // 0x9482
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 34

- Target: `0x9486`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 34 {
  // 0x9486-0x948C
  if (1 != mapDirection) {
    exit_event();  // 0x948D
  }
  // 0x948E-0x9497
  area2.event_scratch0 = area1.event_word_204 & 2;  // 0x948E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9498
  }
  printclear("A BURLY MINER STEPS UP. 'WATCHA WANT?'");  // 0x9499
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'INFORMATION', 'DEMO CHARGES', 'NOTHING');  // 0x94B9
  // 0x94DD
  switch (area2.event_scratch0) {
    case 0: goto 0x94EC;
      // case 0 body
      printclear("'YOU WON'T GET IT.' HE STOMPS OFF.");  // 0x94EC
      exit_event();  // 0x9509
    case 1: goto 0x950A;
      // case 1 body
      // 0x950A-0x9513
      area2.event_scratch0 = area1.event_word_200 & 2;  // 0x950A
      if (area2.event_scratch0 == 0) {
        goto 0x9547;  // 0x9514
        // branch body 0x9547
        printclear("'EVERYONE WOULD LIKE 'EM. YOU AIN'T GOT NO AUTHORITY SO BLAST OFF.' HE STOMPS OFF.");  // 0x9547
        // 0x958A-0x9590
        if (0 != mapDirection) {
          exit_event();  // 0x9591
        }
        // 0x9592-0x9598
        if (1 == area1.event_word_214) {
          exit_event();  // 0x9599
        }
        // 0x959A-0x95A0
        if (1 != area1.event_word_20C) {
          goto 0x95CB;  // 0x95A1
          // branch body 0x95CB
          printclear("A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'");  // 0x95CB
          // 0x973E-0x9744
          if (1 == area1.event_word_214) {
            exit_event();  // 0x9745
          }
          goto 0x97C6;  // 0x9746
        }
        printclear('A HEAVY SECURITY FORCE IS IN THE LOBBY.');  // 0x95A5
        printclear("A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'");  // 0x95CB
        // 0x973E-0x9744
        if (1 == area1.event_word_214) {
          exit_event();  // 0x9745
        }
        goto 0x97C6;  // 0x9746
        // branch body 0x97C6
          setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x97C6
          exit_event();  // 0x97CD
      }
      printclear("'HERE'S ALL WE CAN SPARE.'");  // 0x9518
      printclear("'EVERYONE WOULD LIKE 'EM. YOU AIN'T GOT NO AUTHORITY SO BLAST OFF.' HE STOMPS OFF.");  // 0x9547
      // 0x958A-0x9590
      if (0 != mapDirection) {
        exit_event();  // 0x9591
      }
      // 0x9592-0x9598
      if (1 == area1.event_word_214) {
        exit_event();  // 0x9599
      }
      // 0x959A-0x95A0
      if (1 != area1.event_word_20C) {
        goto 0x95CB;  // 0x95A1
        // branch body 0x95CB
        // target 0x95CB already emitted
      }
      printclear('A HEAVY SECURITY FORCE IS IN THE LOBBY.');  // 0x95A5
      printclear("A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'");  // 0x95CB
      // 0x973E-0x9744
      if (1 == area1.event_word_214) {
        exit_event();  // 0x9745
      }
      goto 0x97C6;  // 0x9746
      // branch body 0x97C6
        // target 0x97C6 already emitted
    case 2: goto 0xA308;
      // case 2 body
      mapPosX = area1.lastXPos;  // 0xA308
      mapPosY = area1.lastYPos;  // 0xA30F
      party_surprise(zone: 43, result: 0);  // 0xA317
      return;  // 0xA31F
  }
}
```

## Event 35

- Target: `0x958A`
- Text hint: 'A HEAVY SECURITY FORCE IS IN THE LOBBY.' "A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'"

```text
event 35 {
  // 0x958A-0x9590
  if (0 != mapDirection) {
    exit_event();  // 0x9591
  }
  // 0x9592-0x9598
  if (1 == area1.event_word_214) {
    exit_event();  // 0x9599
  }
  // 0x959A-0x95A0
  if (1 != area1.event_word_20C) {
    goto 0x95CB;  // 0x95A1
    // branch body 0x95CB
    printclear("A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'");  // 0x95CB
    // 0x973E-0x9744
    if (1 == area1.event_word_214) {
      exit_event();  // 0x9745
    }
    goto 0x97C6;  // 0x9746
    // branch body 0x97C6
      setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x97C6
      exit_event();  // 0x97CD
  }
  printclear('A HEAVY SECURITY FORCE IS IN THE LOBBY.');  // 0x95A5
  printclear("A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'");  // 0x95CB
  // 0x973E-0x9744
  if (1 == area1.event_word_214) {
    exit_event();  // 0x9745
  }
  goto 0x97C6;  // 0x9746
  // branch body 0x97C6
    // target 0x97C6 already emitted
}
```

## Event 36

- Target: `0x973E`
- Text hint: 'A LARGE PRIVATE OFFICE.'

```text
event 36 {
  // 0x973E-0x9744
  if (1 == area1.event_word_214) {
    exit_event();  // 0x9745
  }
  goto 0x97C6;  // 0x9746
  // branch body 0x97C6
    setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x97C6
    exit_event();  // 0x97CD
}
```

## Event 37

- Target: `0x974A`
- Text hint: 'A LARGE PRIVATE OFFICE.'

```text
event 37 {
  // 0x974A-0x9750
  if (2 == mapDirection) {
    exit_event();  // 0x9751
  }
  scratch.word_0258 = abs_000A;  // 0x9752
  goto 0x9830;  // 0x9762
  // branch body 0x9830
    printclear('A SIGN ABOVE THE DOOR READS:');  // 0x9830
    print_return();  // 0x9848
    print("'");  // 0x9849
    print('<string at scratch.word_0258>');  // 0x984D
    print("'");  // 0x9851
    exit_event();  // 0x9855
}
```

## Event 38

- Target: `0x9766`
- Text hint: 'A LARGE PRIVATE OFFICE.'

```text
event 38 {
  printclear('A LARGE PRIVATE OFFICE.');  // 0x9766
  // 0x977B-0x9781
  if (1 == area1.event_word_214) {
    exit_event();  // 0x9782
  }
  print('GUARDS RUSH IN.');  // 0x9783
  printclear('A MEETING ROOM.');  // 0x9797
  // 0x97A6-0x97AC
  if (1 == area1.event_word_214) {
    exit_event();  // 0x97AD
  }
  print('GUARDS RUSH IN.');  // 0x97AE
  goto 0x9797;  // 0x97C2
  // branch body 0x9797
    printclear('A MEETING ROOM.');  // 0x9797
    // 0x97A6-0x97AC
    if (1 == area1.event_word_214) {
      exit_event();  // 0x97AD
    }
    print('GUARDS RUSH IN.');  // 0x97AE
    goto 0x9797;  // 0x97C2
    // branch body 0x9797
      // target 0x9797 already emitted
}
```

## Event 39

- Target: `0x9797`
- Text hint: 'A MEETING ROOM.'

```text
event 39 {
  printclear('A MEETING ROOM.');  // 0x9797
  // 0x97A6-0x97AC
  if (1 == area1.event_word_214) {
    exit_event();  // 0x97AD
  }
  print('GUARDS RUSH IN.');  // 0x97AE
  goto 0x9797;  // 0x97C2
  // branch body 0x9797
    // target 0x9797 already emitted
}
```

## Event 40

- Target: `0x97C2`
- Text hint: 'A SIGN ABOVE THE DOOR READS:' RETURN

```text
event 40 {
  goto 0x9797;  // 0x97C2
  // branch body 0x9797
    printclear('A MEETING ROOM.');  // 0x9797
    // 0x97A6-0x97AC
    if (1 == area1.event_word_214) {
      exit_event();  // 0x97AD
    }
    print('GUARDS RUSH IN.');  // 0x97AE
    goto 0x9797;  // 0x97C2
    // branch body 0x9797
      // target 0x9797 already emitted
}
```
