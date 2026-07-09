# GEO 34: Historical Museum, Levels 2-1

ECL block: `34`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 01 {
  add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
  // 0x85FF
  switch (area1.event_word_20E) {
    case 0: goto 0x860E;
      // case 0 body
      // 0x860E-0x8617
      area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
      if (area2.event_scratch0 != 0) {
        goto 0x84F8;  // 0x8618
        // branch body 0x84F8
        // 0x84F8-0x84FE
        if (39 < area1.event_word_206) {
          exit_event();  // 0x84FF
        }
        // 0x8500-0x8506
        if (8 > area1.event_word_2BC) {
          exit_event();  // 0x8507
        }
        random(area2.event_scratch0 = random 1..99);  // 0x8508
        // 0x850E-0x8514
        if (9 > area2.event_scratch0) {
          exit_event();  // 0x8515
        }
        add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
        area1.event_word_206 = 0;  // 0x851F
        random(area1.event_word_21C = random 1..3);  // 0x8525
        gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
        gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
        setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
        exit_event();  // 0x8548
      }
      random(area2.event_scratch0 = random 1..5);  // 0x861C
      add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
      // 0x862B-0x8632
      if (area2.event_scratch0 < area1.event_word_218) {
        goto 0x84F8;  // 0x8633
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      area1.event_word_218 = 0;  // 0x8637
      // 0x863D-0x8646
      area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
      if (area2.event_scratch0 == 0) {
        goto 0x8714;  // 0x8647
        // branch body 0x8714
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
          if_>(<if compare flag is false, skip next op>);  // 0x88DA
          goto 0x890F;  // 0x88DB
      }
      // 0x864B-0x8654
      area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
      if (area2.event_scratch0 == 0) {
        goto 0x8751;  // 0x8655
        // branch body 0x8751
        or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
        // 0x875A-0x8763
        area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8764
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
        horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
        // 0x87CC
        switch (area1.event_word_20A) {
          case 0: goto 0x87DB;
          case 1: goto 0x883B;
          case 2: goto 0x8892;
        }
      }
      // 0x8659-0x8662
      area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
      if (area2.event_scratch0 == 0) {
        goto 0x84F8;  // 0x8663
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
      printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
      or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
      printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
      goto 0x88AB;  // 0x874D
      // branch body 0x88AB
        // target 0x88AB already emitted
    case 1: goto 0x88B3;
    case 2: goto 0x898C;
  }
}
```

## Event 02

- Target: `0x8A5E`
- Text hint: 'A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.'

```text
event 02 {
  // 0x8A5E-0x8A64
  if (10 != abs_C04E) {
    exit_event();  // 0x8A65
  }
  // 0x8A66-0x8A6C
  if (0 != area1.event_word_2CE) {
    goto 0x8AE8;  // 0x8A6D
    // branch body 0x8AE8
    // 0x8AE8-0x8AF1
    area2.event_scratch0 = 1 & area1.event_word_2CC;  // 0x8AE8
    if (area2.event_scratch0 != 0) {
      goto 0x8BE7;  // 0x8AF2
      // branch body 0x8BE7
      // 0x8BE7-0x8BF0
      area2.event_scratch0 = 2 & area1.event_word_2CC;  // 0x8BE7
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8BF1
      }
      setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x8BF2
      exit_event();  // 0x8BF9
    }
    or(area1.event_word_2CC = 1 | area1.event_word_2CC);  // 0x8AF6
    exit_event();  // 0x8B00
  }
  // 0x8A71-0x8A7A
  area2.event_scratch0 = 1 & area1.event_word_2BE;  // 0x8A71
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8A7B
  }
  or(area1.event_word_2BE = 1 | area1.event_word_2BE);  // 0x8A7C
  setup_monster(sprite_id: 52 max_distance: 1 pic_id: 255);  // 0x8A85
  exit_event();  // 0x8A8C
}
```

## Event 03

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 03 {
  add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
  // 0x85FF
  switch (area1.event_word_20E) {
    case 0: goto 0x860E;
      // case 0 body
      // 0x860E-0x8617
      area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
      if (area2.event_scratch0 != 0) {
        goto 0x84F8;  // 0x8618
        // branch body 0x84F8
        // 0x84F8-0x84FE
        if (39 < area1.event_word_206) {
          exit_event();  // 0x84FF
        }
        // 0x8500-0x8506
        if (8 > area1.event_word_2BC) {
          exit_event();  // 0x8507
        }
        random(area2.event_scratch0 = random 1..99);  // 0x8508
        // 0x850E-0x8514
        if (9 > area2.event_scratch0) {
          exit_event();  // 0x8515
        }
        add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
        area1.event_word_206 = 0;  // 0x851F
        random(area1.event_word_21C = random 1..3);  // 0x8525
        gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
        gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
        setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
        exit_event();  // 0x8548
      }
      random(area2.event_scratch0 = random 1..5);  // 0x861C
      add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
      // 0x862B-0x8632
      if (area2.event_scratch0 < area1.event_word_218) {
        goto 0x84F8;  // 0x8633
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      area1.event_word_218 = 0;  // 0x8637
      // 0x863D-0x8646
      area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
      if (area2.event_scratch0 == 0) {
        goto 0x8714;  // 0x8647
        // branch body 0x8714
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
          if_>(<if compare flag is false, skip next op>);  // 0x88DA
          goto 0x890F;  // 0x88DB
      }
      // 0x864B-0x8654
      area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
      if (area2.event_scratch0 == 0) {
        goto 0x8751;  // 0x8655
        // branch body 0x8751
        or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
        // 0x875A-0x8763
        area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8764
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
        horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
        // 0x87CC
        switch (area1.event_word_20A) {
          case 0: goto 0x87DB;
          case 1: goto 0x883B;
          case 2: goto 0x8892;
        }
      }
      // 0x8659-0x8662
      area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
      if (area2.event_scratch0 == 0) {
        goto 0x84F8;  // 0x8663
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
      printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
      or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
      printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
      goto 0x88AB;  // 0x874D
      // branch body 0x88AB
        // target 0x88AB already emitted
    case 1: goto 0x88B3;
    case 2: goto 0x898C;
  }
}
```

## Event 04

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 04 {
  add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
  // 0x85FF
  switch (area1.event_word_20E) {
    case 0: goto 0x860E;
      // case 0 body
      // 0x860E-0x8617
      area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
      if (area2.event_scratch0 != 0) {
        goto 0x84F8;  // 0x8618
        // branch body 0x84F8
        // 0x84F8-0x84FE
        if (39 < area1.event_word_206) {
          exit_event();  // 0x84FF
        }
        // 0x8500-0x8506
        if (8 > area1.event_word_2BC) {
          exit_event();  // 0x8507
        }
        random(area2.event_scratch0 = random 1..99);  // 0x8508
        // 0x850E-0x8514
        if (9 > area2.event_scratch0) {
          exit_event();  // 0x8515
        }
        add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
        area1.event_word_206 = 0;  // 0x851F
        random(area1.event_word_21C = random 1..3);  // 0x8525
        gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
        gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
        setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
        exit_event();  // 0x8548
      }
      random(area2.event_scratch0 = random 1..5);  // 0x861C
      add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
      // 0x862B-0x8632
      if (area2.event_scratch0 < area1.event_word_218) {
        goto 0x84F8;  // 0x8633
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      area1.event_word_218 = 0;  // 0x8637
      // 0x863D-0x8646
      area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
      if (area2.event_scratch0 == 0) {
        goto 0x8714;  // 0x8647
        // branch body 0x8714
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
          if_>(<if compare flag is false, skip next op>);  // 0x88DA
          goto 0x890F;  // 0x88DB
      }
      // 0x864B-0x8654
      area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
      if (area2.event_scratch0 == 0) {
        goto 0x8751;  // 0x8655
        // branch body 0x8751
        or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
        // 0x875A-0x8763
        area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8764
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
        horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
        // 0x87CC
        switch (area1.event_word_20A) {
          case 0: goto 0x87DB;
          case 1: goto 0x883B;
          case 2: goto 0x8892;
        }
      }
      // 0x8659-0x8662
      area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
      if (area2.event_scratch0 == 0) {
        goto 0x84F8;  // 0x8663
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
      printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
      or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
      printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
      goto 0x88AB;  // 0x874D
      // branch body 0x88AB
        // target 0x88AB already emitted
    case 1: goto 0x88B3;
    case 2: goto 0x898C;
  }
}
```

## Event 05

- Target: `0x85F6`
- Text hint: "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'" 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'

```text
event 05 {
  add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
  // 0x85FF
  switch (area1.event_word_20E) {
    case 0: goto 0x860E;
      // case 0 body
      // 0x860E-0x8617
      area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
      if (area2.event_scratch0 != 0) {
        goto 0x84F8;  // 0x8618
        // branch body 0x84F8
        // 0x84F8-0x84FE
        if (39 < area1.event_word_206) {
          exit_event();  // 0x84FF
        }
        // 0x8500-0x8506
        if (8 > area1.event_word_2BC) {
          exit_event();  // 0x8507
        }
        random(area2.event_scratch0 = random 1..99);  // 0x8508
        // 0x850E-0x8514
        if (9 > area2.event_scratch0) {
          exit_event();  // 0x8515
        }
        add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
        area1.event_word_206 = 0;  // 0x851F
        random(area1.event_word_21C = random 1..3);  // 0x8525
        gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
        gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
        setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
        exit_event();  // 0x8548
      }
      random(area2.event_scratch0 = random 1..5);  // 0x861C
      add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
      // 0x862B-0x8632
      if (area2.event_scratch0 < area1.event_word_218) {
        goto 0x84F8;  // 0x8633
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      area1.event_word_218 = 0;  // 0x8637
      // 0x863D-0x8646
      area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
      if (area2.event_scratch0 == 0) {
        goto 0x8714;  // 0x8647
        // branch body 0x8714
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
          if_>(<if compare flag is false, skip next op>);  // 0x88DA
          goto 0x890F;  // 0x88DB
      }
      // 0x864B-0x8654
      area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
      if (area2.event_scratch0 == 0) {
        goto 0x8751;  // 0x8655
        // branch body 0x8751
        or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
        // 0x875A-0x8763
        area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8764
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
        horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
        // 0x87CC
        switch (area1.event_word_20A) {
          case 0: goto 0x87DB;
          case 1: goto 0x883B;
          case 2: goto 0x8892;
        }
      }
      // 0x8659-0x8662
      area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
      if (area2.event_scratch0 == 0) {
        goto 0x84F8;  // 0x8663
        // branch body 0x84F8
        // target 0x84F8 already emitted
      }
      or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
      printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
      or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
      printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
      goto 0x88AB;  // 0x874D
      // branch body 0x88AB
        // target 0x88AB already emitted
    case 1: goto 0x88B3;
    case 2: goto 0x898C;
  }
}
```

## Event 06

- Target: `0x8C53`
- Text hint: 'A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.'

```text
event 06 {
  printclear('A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.');  // 0x8C53
  // 0x8C8B-0x8C94
  area2.event_scratch0 = 1 & area1.event_word_2C2;  // 0x8C8B
  if (area2.event_scratch0 != 0) {
    goto 0x8EE2;  // 0x8C95
    // branch body 0x8EE2
    // 0x8EE2-0x8EEB
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x8EE2
    if (area2.event_scratch0 != 0) {
      goto 0x9851;  // 0x8EEC
      // branch body 0x9851
      // 0x9851-0x9857
      if (0 != abs_C04E) {
        exit_event();  // 0x9858
      }
      printclear('A BROOM CLOSET.');  // 0x9859
      exit_event();  // 0x9868
    }
    // 0x8EF0-0x8EF6
    if (0 != abs_C04E) {
      exit_event();  // 0x8EF7
    }
    printclear('CHADE STILL SLEEPS HERE.');  // 0x8EF8
    goto 0x8CE6;  // 0x8F0D
    // branch body 0x8CE6
      print_return();  // 0x8CE6
      print_return();  // 0x8CE7
      print('DO YOU WAKE HIM?');  // 0x8CE8
      // 0x8EE2-0x8EEB
      area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x8EE2
      if (area2.event_scratch0 != 0) {
        goto 0x9851;  // 0x8EEC
        // branch body 0x9851
        // target 0x9851 already emitted
      }
      // 0x8EF0-0x8EF6
      if (0 != abs_C04E) {
        exit_event();  // 0x8EF7
      }
      printclear('CHADE STILL SLEEPS HERE.');  // 0x8EF8
      goto 0x8CE6;  // 0x8F0D
      // branch body 0x8CE6
        // target 0x8CE6 already emitted
  }
  or(area1.event_word_2C2 = 1 | area1.event_word_2C2);  // 0x8C99
  printclear('A BROOM CLOSET.');  // 0x8CA2
  print_return();  // 0x8CB1
  print('AN OLD MAN, DOUBTLESS PROFESSOR CHADE, SLEEPS ON A CARDBOARD BOX.');  // 0x8CB2
  print_return();  // 0x8CE6
  print_return();  // 0x8CE7
  print('DO YOU WAKE HIM?');  // 0x8CE8
  // truncated at 0x8EE2
}
```

## Event 07

- Target: `0x8C8B`
- Text hint: 'A BROOM CLOSET.' RETURN

```text
event 07 {
  // 0x8C8B-0x8C94
  area2.event_scratch0 = 1 & area1.event_word_2C2;  // 0x8C8B
  if (area2.event_scratch0 != 0) {
    goto 0x8EE2;  // 0x8C95
    // branch body 0x8EE2
    // 0x8EE2-0x8EEB
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x8EE2
    if (area2.event_scratch0 != 0) {
      goto 0x9851;  // 0x8EEC
      // branch body 0x9851
      // 0x9851-0x9857
      if (0 != abs_C04E) {
        exit_event();  // 0x9858
      }
      printclear('A BROOM CLOSET.');  // 0x9859
      exit_event();  // 0x9868
    }
    // 0x8EF0-0x8EF6
    if (0 != abs_C04E) {
      exit_event();  // 0x8EF7
    }
    printclear('CHADE STILL SLEEPS HERE.');  // 0x8EF8
    goto 0x8CE6;  // 0x8F0D
    // branch body 0x8CE6
      print_return();  // 0x8CE6
      print_return();  // 0x8CE7
      print('DO YOU WAKE HIM?');  // 0x8CE8
      // 0x8EE2-0x8EEB
      area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x8EE2
      if (area2.event_scratch0 != 0) {
        goto 0x9851;  // 0x8EEC
        // branch body 0x9851
        // target 0x9851 already emitted
      }
      // 0x8EF0-0x8EF6
      if (0 != abs_C04E) {
        exit_event();  // 0x8EF7
      }
      printclear('CHADE STILL SLEEPS HERE.');  // 0x8EF8
      goto 0x8CE6;  // 0x8F0D
      // branch body 0x8CE6
        // target 0x8CE6 already emitted
  }
  or(area1.event_word_2C2 = 1 | area1.event_word_2C2);  // 0x8C99
  printclear('A BROOM CLOSET.');  // 0x8CA2
  print_return();  // 0x8CB1
  print('AN OLD MAN, DOUBTLESS PROFESSOR CHADE, SLEEPS ON A CARDBOARD BOX.');  // 0x8CB2
  print_return();  // 0x8CE6
  print_return();  // 0x8CE7
  print('DO YOU WAKE HIM?');  // 0x8CE8
  // 0x8EE2-0x8EEB
  area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x8EE2
  if (area2.event_scratch0 != 0) {
    goto 0x9851;  // 0x8EEC
    // branch body 0x9851
    // target 0x9851 already emitted
  }
  // 0x8EF0-0x8EF6
  if (0 != abs_C04E) {
    exit_event();  // 0x8EF7
  }
  printclear('CHADE STILL SLEEPS HERE.');  // 0x8EF8
  // truncated at 0x8F0D
}
```

## Event 08

- Target: `0x8F11`
- Text hint: 'A DISPLAY OF FLORA AND FAUNA THAT WENT EXTINCT DURING THE 21ST CENTURY.'

```text
event 08 {
  // 0x8F11-0x8F17
  if (2 != mapDirection) {
    exit_event();  // 0x8F18
  }
  printclear('A DISPLAY OF FLORA AND FAUNA THAT WENT EXTINCT DURING THE 21ST CENTURY.');  // 0x8F19
  exit_event();  // 0x8F52
}
```

## Event 09

- Target: `0x8F53`
- Text hint: 'CALIFORNIA CONDOR.'

```text
event 09 {
  gosub 0xA15E;  // 0x8F53
  print('CALIFORNIA CONDOR.');  // 0x8F57
  exit_event();  // 0x8F68
}
```

## Event 10

- Target: `0x8F69`
- Text hint: 'BLACK RHINO.'

```text
event 10 {
  gosub 0xA15E;  // 0x8F69
  print('BLACK RHINO.');  // 0x8F6D
  exit_event();  // 0x8F79
}
```

## Event 11

- Target: `0x8F7A`
- Text hint: 'POODLE.'

```text
event 11 {
  gosub 0xA15E;  // 0x8F7A
  print('POODLE.');  // 0x8F7E
  exit_event();  // 0x8F87
}
```

## Event 12

- Target: `0x8F88`
- Text hint: 'MOCKINGBIRD.'

```text
event 12 {
  gosub 0xA15E;  // 0x8F88
  print('MOCKINGBIRD.');  // 0x8F8C
  exit_event();  // 0x8F98
}
```

## Event 13

- Target: `0x8F99`
- Text hint: 'GORILLA.'

```text
event 13 {
  gosub 0xA15E;  // 0x8F99
  print('GORILLA.');  // 0x8F9D
  exit_event();  // 0x8FA6
}
```

## Event 14

- Target: `0x8FA7`
- Text hint: 'THIS ROOM IS A SATURN 1ST-STAGE BOOSTER. ITS CONTENTS DEPICT THE SPACE PROGRAM.'

```text
event 14 {
  // 0x8FA7-0x8FAD
  if (3 != mapDirection) {
    exit_event();  // 0x8FAE
  }
  printclear('THIS ROOM IS A SATURN 1ST-STAGE BOOSTER. ITS CONTENTS DEPICT THE SPACE PROGRAM.');  // 0x8FAF
  exit_event();  // 0x8FEE
}
```

## Event 15

- Target: `0x8FEF`
- Text hint: 'SPACESUIT WORN BY ARMSTRONG.'

```text
event 15 {
  gosub 0xA16E;  // 0x8FEF
  print('SPACESUIT WORN BY ARMSTRONG.');  // 0x8FF3
  exit_event();  // 0x900B
}
```

## Event 16

- Target: `0x900C`
- Text hint: 'HELMET WORN BY COSMONAUT YURI GAGARIN.'

```text
event 16 {
  gosub 0xA16E;  // 0x900C
  print('HELMET WORN BY COSMONAUT YURI GAGARIN.');  // 0x9010
  exit_event();  // 0x9030
}
```

## Event 17

- Target: `0x9031`
- Text hint: 'WARPED MIRROR OF THE HUBBLE TELESCOPE.'

```text
event 17 {
  gosub 0xA16E;  // 0x9031
  print('WARPED MIRROR OF THE HUBBLE TELESCOPE.');  // 0x9035
  exit_event();  // 0x9055
}
```

## Event 18

- Target: `0x9056`
- Text hint: 'MODEL ICBM.'

```text
event 18 {
  gosub 0xA15E;  // 0x9056
  print('MODEL ICBM.');  // 0x905A
  exit_event();  // 0x9066
}
```

## Event 19

- Target: `0x9067`
- Text hint: 'THE HISTORY OF WAR IS DEPICTED IN THIS ROOM.'

```text
event 19 {
  // 0x9067-0x906D
  if (1 != mapDirection) {
    exit_event();  // 0x906E
  }
  printclear('THE HISTORY OF WAR IS DEPICTED IN THIS ROOM.');  // 0x906F
  exit_event();  // 0x9093
}
```

## Event 20

- Target: `0x9094`
- Text hint: "A MODEL OF MASTERLINK IS MOUNTED ON THE WALL, AND BELOW IT, AN EPITAPH TO LT. COL. ANTHONY 'BUCK' ROGERS, WHO DIED ON HIS MISSION TO DESTROY THE WEAPON."

```text
event 20 {
  printclear("A MODEL OF MASTERLINK IS MOUNTED ON THE WALL, AND BELOW IT, AN EPITAPH TO LT. COL. ANTHONY 'BUCK' ROGERS, WHO DIED ON HIS MISSION TO DESTROY THE WEAPON.");  // 0x9094
  exit_event();  // 0x9109
}
```

## Event 21

- Target: `0x910A`
- Text hint: "A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT."

```text
event 21 {
  exit_event();  // 0x910A
}
```

## Event 22

- Target: `0x910B`
- Text hint: "A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT."

```text
event 22 {
  printclear("A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT.");  // 0x910B
  exit_event();  // 0x9168
}
```

## Event 23

- Target: `0x9169`
- Text hint: 'A BUST OF NAPOLEON - KILLING EN MASSE BECOMES ALL THE RAGE.'

```text
event 23 {
  printclear('A BUST OF NAPOLEON - KILLING EN MASSE BECOMES ALL THE RAGE.');  // 0x9169
  exit_event();  // 0x9199
}
```

## Event 24

- Target: `0x919A`
- Text hint: 'THIS ROOM IS DEDICATED TO THE RISE OF MODERN CIVILIZATION.'

```text
event 24 {
  // 0x919A-0x91A0
  if (2 != mapDirection) {
    exit_event();  // 0x91A1
  }
  printclear('THIS ROOM IS DEDICATED TO THE RISE OF MODERN CIVILIZATION.');  // 0x91A2
  exit_event();  // 0x91D1
}
```

## Event 25

- Target: `0x91D2`
- Text hint: 'STEAM POWERED LOOM, HERALDING THE BIRTH OF THE WORK FORCE.'

```text
event 25 {
  gosub 0xA15E;  // 0x91D2
  print('STEAM POWERED LOOM, HERALDING THE BIRTH OF THE WORK FORCE.');  // 0x91D6
  exit_event();  // 0x9205
}
```

## Event 26

- Target: `0x9206`
- Text hint: "MONEY OF ALL KINDS, FROM DOUBLOONS TO CREDIT CARDS, ARE IN A CASE. THE CAPTION READS, 'THE JONESES MOVE IN.'"

```text
event 26 {
  printclear("MONEY OF ALL KINDS, FROM DOUBLOONS TO CREDIT CARDS, ARE IN A CASE. THE CAPTION READS, 'THE JONESES MOVE IN.'");  // 0x9206
  exit_event();  // 0x925A
}
```

## Event 27

- Target: `0x925B`
- Text hint: 'PRINTING PRESS, ENABLING THE STANDARDIZATION OF KNOWLEDGE AND FREING HUMANITY FROM THE NEED TO REMEMBER.'

```text
event 27 {
  gosub 0xA16E;  // 0x925B
  print('PRINTING PRESS, ENABLING THE STANDARDIZATION OF KNOWLEDGE AND FREING HUMANITY FROM THE NEED TO REMEMBER.');  // 0x925F
  exit_event();  // 0x92B0
}
```

## Event 28

- Target: `0x92B1`
- Text hint: 'A MOVIE THEATER.' RETURN

```text
event 28 {
  // 0x92B1-0x92B7
  if (2 != mapDirection) {
    exit_event();  // 0x92B8
  }
  printclear('A MOVIE THEATER.');  // 0x92B9
  print_return();  // 0x92C8
  print_return();  // 0x92C9
  print('YOUR BOOTS STICK TO THE FLOOR.');  // 0x92CA
  // 0x94A4-0x94AA
  if (0 != mapDirection) {
    exit_event();  // 0x94AB
  }
  printclear('A LARGE DNA HELIX MODELED WITH STICKS AND COLORED BALLS. ');  // 0x94AC
  // 0x94DA-0x94E3
  area2.event_scratch0 = 8 & area1.event_word_2BE;  // 0x94DA
  if (area2.event_scratch0 != 0) {
    goto 0x953A;  // 0x94E4
    // branch body 0x953A
    // 0x953A-0x9543
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x953A
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x9544
    }
    // 0x9545-0x954E
    area2.event_scratch0 = 2 & area1.event_word_2BE;  // 0x9545
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x954F
    }
    // 0x9550-0x9559
    area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x9550
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x955A
    }
    or(area1.event_word_2BE = 16 | area1.event_word_2BE);  // 0x955B
    print("CHADE BLUNDERS ABOUT THE ROOM. 'I COULD'VE SWORN MY NOTES WERE IN HERE. MAYBE THEY'RE IN THE COMPUTER ROOM TO THE SOUTHWEST.'");  // 0x9564
    // 0x95C7-0x95CD
    if (0 != area1.event_word_21A) {
      exit_event();  // 0x95CE
    }
    // 0x95CF-0x95D5
    if (1 != mapDirection) {
      exit_event();  // 0x95D6
    }
    printclear('A HUGE COMPUTER CALLED ENIAC FILLS THE ROOM.');  // 0x95D7
    // 0x95FB-0x9604
    area2.event_scratch0 = 32 & area1.event_word_2BE;  // 0x95FB
    if (area2.event_scratch0 != 0) {
      goto 0x9642;  // 0x9605
      // branch body 0x9642
      // 0x9643-0x964C
      area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x9643
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x964D
      }
      // 0x964E-0x9657
      area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x964E
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x9658
      }
      // 0x9659-0x9662
      area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9659
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x9663
      }
      or(area1.event_word_2BE = 64 | area1.event_word_2BE);  // 0x9664
      printclear("CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'");  // 0x966D
      // 0x9851-0x9857
      if (0 != abs_C04E) {
        exit_event();  // 0x9858
      }
      printclear('A BROOM CLOSET.');  // 0x9859
      exit_event();  // 0x9868
    }
    or(area1.event_word_2BE = 32 | area1.event_word_2BE);  // 0x9609
    print(' A MICROCHIP A BILLION TIMES MORE POWERFUL SITS ON A TABLE.');  // 0x9612
    // 0x9643-0x964C
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x9643
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x964D
    }
    // 0x964E-0x9657
    area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x964E
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x9658
    }
    // 0x9659-0x9662
    area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9659
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9663
    }
    or(area1.event_word_2BE = 64 | area1.event_word_2BE);  // 0x9664
    printclear("CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'");  // 0x966D
    // truncated at 0x9851
  }
  mapPosY = 4;  // 0x94E8
  or(area1.event_word_2BE = 8 | area1.event_word_2BE);  // 0x94EE
  print_return();  // 0x94F7
  print_return();  // 0x94F8
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 32);  // 0x94F9
  exit_event();  // 0x9500
}
```

## Event 29

- Target: `0x94A4`
- Text hint: 'A LARGE DNA HELIX MODELED WITH STICKS AND COLORED BALLS. '

```text
event 29 {
  // 0x94A4-0x94AA
  if (0 != mapDirection) {
    exit_event();  // 0x94AB
  }
  printclear('A LARGE DNA HELIX MODELED WITH STICKS AND COLORED BALLS. ');  // 0x94AC
  // 0x94DA-0x94E3
  area2.event_scratch0 = 8 & area1.event_word_2BE;  // 0x94DA
  if (area2.event_scratch0 != 0) {
    goto 0x953A;  // 0x94E4
    // branch body 0x953A
    // 0x953A-0x9543
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x953A
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x9544
    }
    // 0x9545-0x954E
    area2.event_scratch0 = 2 & area1.event_word_2BE;  // 0x9545
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x954F
    }
    // 0x9550-0x9559
    area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x9550
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x955A
    }
    or(area1.event_word_2BE = 16 | area1.event_word_2BE);  // 0x955B
    print("CHADE BLUNDERS ABOUT THE ROOM. 'I COULD'VE SWORN MY NOTES WERE IN HERE. MAYBE THEY'RE IN THE COMPUTER ROOM TO THE SOUTHWEST.'");  // 0x9564
    // 0x95C7-0x95CD
    if (0 != area1.event_word_21A) {
      exit_event();  // 0x95CE
    }
    // 0x95CF-0x95D5
    if (1 != mapDirection) {
      exit_event();  // 0x95D6
    }
    printclear('A HUGE COMPUTER CALLED ENIAC FILLS THE ROOM.');  // 0x95D7
    // 0x95FB-0x9604
    area2.event_scratch0 = 32 & area1.event_word_2BE;  // 0x95FB
    if (area2.event_scratch0 != 0) {
      goto 0x9642;  // 0x9605
      // branch body 0x9642
      // 0x9643-0x964C
      area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x9643
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x964D
      }
      // 0x964E-0x9657
      area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x964E
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x9658
      }
      // 0x9659-0x9662
      area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9659
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x9663
      }
      or(area1.event_word_2BE = 64 | area1.event_word_2BE);  // 0x9664
      printclear("CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'");  // 0x966D
      // 0x9851-0x9857
      if (0 != abs_C04E) {
        exit_event();  // 0x9858
      }
      printclear('A BROOM CLOSET.');  // 0x9859
      exit_event();  // 0x9868
    }
    or(area1.event_word_2BE = 32 | area1.event_word_2BE);  // 0x9609
    print(' A MICROCHIP A BILLION TIMES MORE POWERFUL SITS ON A TABLE.');  // 0x9612
    // 0x9643-0x964C
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x9643
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x964D
    }
    // 0x964E-0x9657
    area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x964E
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x9658
    }
    // 0x9659-0x9662
    area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9659
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9663
    }
    or(area1.event_word_2BE = 64 | area1.event_word_2BE);  // 0x9664
    printclear("CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'");  // 0x966D
    // truncated at 0x9851
  }
  mapPosY = 4;  // 0x94E8
  or(area1.event_word_2BE = 8 | area1.event_word_2BE);  // 0x94EE
  print_return();  // 0x94F7
  print_return();  // 0x94F8
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 32);  // 0x94F9
  exit_event();  // 0x9500
}
```

## Event 30

- Target: `0x95C7`
- Text hint: 'A HUGE COMPUTER CALLED ENIAC FILLS THE ROOM.'

```text
event 30 {
  // 0x95C7-0x95CD
  if (0 != area1.event_word_21A) {
    exit_event();  // 0x95CE
  }
  // 0x95CF-0x95D5
  if (1 != mapDirection) {
    exit_event();  // 0x95D6
  }
  printclear('A HUGE COMPUTER CALLED ENIAC FILLS THE ROOM.');  // 0x95D7
  // 0x95FB-0x9604
  area2.event_scratch0 = 32 & area1.event_word_2BE;  // 0x95FB
  if (area2.event_scratch0 != 0) {
    goto 0x9642;  // 0x9605
    // branch body 0x9642
    // 0x9643-0x964C
    area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x9643
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x964D
    }
    // 0x964E-0x9657
    area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x964E
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x9658
    }
    // 0x9659-0x9662
    area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9659
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9663
    }
    or(area1.event_word_2BE = 64 | area1.event_word_2BE);  // 0x9664
    printclear("CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'");  // 0x966D
    // 0x9851-0x9857
    if (0 != abs_C04E) {
      exit_event();  // 0x9858
    }
    printclear('A BROOM CLOSET.');  // 0x9859
    exit_event();  // 0x9868
  }
  or(area1.event_word_2BE = 32 | area1.event_word_2BE);  // 0x9609
  print(' A MICROCHIP A BILLION TIMES MORE POWERFUL SITS ON A TABLE.');  // 0x9612
  // 0x9643-0x964C
  area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x9643
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x964D
  }
  // 0x964E-0x9657
  area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x964E
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9658
  }
  // 0x9659-0x9662
  area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9659
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9663
  }
  or(area1.event_word_2BE = 64 | area1.event_word_2BE);  // 0x9664
  printclear("CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'");  // 0x966D
  // truncated at 0x9851
}
```

## Event 31

- Target: `0x9851`
- Text hint: 'A BROOM CLOSET.'

```text
event 31 {
  // 0x9851-0x9857
  if (0 != abs_C04E) {
    exit_event();  // 0x9858
  }
  printclear('A BROOM CLOSET.');  // 0x9859
  exit_event();  // 0x9868
}
```

## Event 32

- Target: `0x9869`
- Text hint: 'THE WARRIORS ARE QUESTIONING STEFI MERCILESSLY. '

```text
event 32 {
  // 0x9869-0x9872
  area2.event_scratch0 = 32 & area1.event_word_2C0;  // 0x9869
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9873
  }
  // 0x9874-0x987D
  area2.event_scratch0 = 64 & area1.event_word_2BE;  // 0x9874
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x987E
  }
  // 0x987F-0x9888
  area2.event_scratch0 = 64 & area1.event_word_2C0;  // 0x987F
  if (area2.event_scratch0 != 0) {
    goto 0x9AB4;  // 0x9889
    // branch body 0x9AB4
    printclear('THE WARRIORS ARE QUESTIONING STEFI MERCILESSLY. ');  // 0x9AB4
    goto 0x994E;  // 0x9ADB
    // branch body 0x994E
      sprite(OFF);  // 0x994E
      goto 0x004C;  // 0x994F
      // branch body 0x004C
        area1.inDungeon = 132;  // 0x8014
        // truncated at 0x801A
  }
  setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x988D
  exit_event();  // 0x9894
}
```

## Event 33

- Target: `0x9AFB`
- Text hint: 'THE SECRET DOOR THAT CHADE TOLD YOU ABOUT STANDS AJAR. '

```text
event 33 {
  // 0x9AFB-0x9B04
  area2.event_scratch0 = 32 & area1.event_word_2C0;  // 0x9AFB
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9B05
  }
  // 0x9B06-0x9B0F
  area2.event_scratch0 = 128 & area1.event_word_2C0;  // 0x9B06
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9B10
  }
  or(area1.event_word_2C0 = 128 | area1.event_word_2C0);  // 0x9B11
  printclear('THE SECRET DOOR THAT CHADE TOLD YOU ABOUT STANDS AJAR. ');  // 0x9B1A
  goto 0x833D;  // 0x9B47
  // branch body 0x833D
    // 0x833D-0x8346
    area2.event_scratch0 = 32 & area1.event_word_2C0;  // 0x833D
    if (area2.event_scratch0 == 0) {
      goto 0x8336;  // 0x8347
      // branch body 0x8336
      area2.word_592 = 255;  // 0x8336
      // 0x833D-0x8346
      area2.event_scratch0 = 32 & area1.event_word_2C0;  // 0x833D
      if (area2.event_scratch0 == 0) {
        goto 0x8336;  // 0x8347
        // branch body 0x8336
        // target 0x8336 already emitted
      }
      print('DO YOU GO THROUGH THE DOOR?');  // 0x834B
      // 0x8372-0x837B
      area2.event_scratch0 = 16 & area1.event_word_2C4;  // 0x8372
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x837C
      }
      // 0x837D-0x8386
      area2.event_scratch0 = 4 & area1.event_word_2C4;  // 0x837D
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8387
      }
      printclear('DO YOU WANT TO REMOVE THE BARRICADE?');  // 0x8388
      area1.event_word_202 = 0;  // 0x83B6
      area2.word_58C = 80;  // 0x83BC
      // 0x83C2-0x83CB
      area2.event_scratch0 = 32 & area1.event_word_2C8;  // 0x83C2
      if (area2.event_scratch0 == 0) {
        add(area1.event_word_206 = 2 + area1.event_word_206);  // 0x83CC
      }
      if_<>(<if compare flag is false, skip next op>);  // 0x83D5
      add(area1.event_word_206 = 3 + area1.event_word_206);  // 0x83D6
      if_<>(<if compare flag is false, skip next op>);  // 0x83DF
      add(area1.time_minutes_tens = 2 + area1.time_minutes_tens);  // 0x83E0
      // 0x83E9-0x83EF
      if (0 != area1.event_word_212) {
        goto 0x848B;  // 0x83F0
        // branch body 0x848B
        add(area1.event_word_214 = 1 + area1.event_word_214);  // 0x848B
        // 0x8494-0x849A
        if (1 > area1.event_word_214) {
          goto 0x84D8;  // 0x849B
        }
        // 0x849F-0x84A6
        if (area1.event_word_216 != mapDirection) {
          goto 0x84B7;  // 0x84A7
        }
        area2.event_scratch1 = 62;  // 0x84AB
        gosub 0xA131;  // 0x84B1
        if_<>(<if compare flag is false, skip next op>);  // 0x84B5
        setup_monster(sprite_id: 50 max_distance: 0 pic_id: 255);  // 0x84B7
        exit_event();  // 0x84BE
      }
      and(area1.event_word_204 = 63 & abs_C04F);  // 0x83F4
      // 0x83FD
      switch (area1.event_word_204) {
        case 0: goto 0x84F8;
        case 1: goto 0x85F6;
        case 2: goto 0x8A5E;
        case 3: goto 0x85F6;
        case 4: goto 0x85F6;
        case 5: goto 0x85F6;
        case 6: goto 0x8C53;
        case 7: goto 0x8C8B;
        case 8: goto 0x8F11;
        case 9: goto 0x8F53;
        case 10: goto 0x8F69;
        case 11: goto 0x8F7A;
        case 12: goto 0x8F88;
        case 13: goto 0x8F99;
        case 14: goto 0x8FA7;
        case 15: goto 0x8FEF;
        case 16: goto 0x900C;
        case 17: goto 0x9031;
        case 18: goto 0x9056;
        case 19: goto 0x9067;
        case 20: goto 0x9094;
        case 21: goto 0x910A;
        case 22: goto 0x910B;
        case 23: goto 0x9169;
        case 24: goto 0x919A;
        case 25: goto 0x91D2;
        case 26: goto 0x9206;
        case 27: goto 0x925B;
        case 28: goto 0x92B1;
        case 29: goto 0x94A4;
        case 30: goto 0x95C7;
        case 31: goto 0x9851;
        case 32: goto 0x9869;
        case 33: goto 0x9AFB;
        case 34: goto 0x9B4B;
        case 35: goto 0x9E5E;
        case 36: goto 0x9EB6;
        case 37: goto 0x9F55;
        case 38: goto 0x9FB8;
        // 27 additional cases omitted in this pass
      }
    }
}
```

## Event 34

- Target: `0x9B4B`
- Text hint: 'A GIFT SHOP.'

```text
event 34 {
  // 0x9B4B-0x9B51
  if (10 != abs_C04E) {
    goto 0x85F6;  // 0x9B52
    // branch body 0x85F6
    add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
    // 0x85FF
    switch (area1.event_word_20E) {
      case 0: goto 0x860E;
        // case 0 body
        // 0x860E-0x8617
        area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8618
          // branch body 0x84F8
          // 0x84F8-0x84FE
          if (39 < area1.event_word_206) {
            exit_event();  // 0x84FF
          }
          // 0x8500-0x8506
          if (8 > area1.event_word_2BC) {
            exit_event();  // 0x8507
          }
          random(area2.event_scratch0 = random 1..99);  // 0x8508
          // 0x850E-0x8514
          if (9 > area2.event_scratch0) {
            exit_event();  // 0x8515
          }
          add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
          area1.event_word_206 = 0;  // 0x851F
          random(area1.event_word_21C = random 1..3);  // 0x8525
          gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
          gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
          setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
          exit_event();  // 0x8548
        }
        random(area2.event_scratch0 = random 1..5);  // 0x861C
        add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
        // 0x862B-0x8632
        if (area2.event_scratch0 < area1.event_word_218) {
          goto 0x84F8;  // 0x8633
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        area1.event_word_218 = 0;  // 0x8637
        // 0x863D-0x8646
        area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
        if (area2.event_scratch0 == 0) {
          goto 0x8714;  // 0x8647
          // branch body 0x8714
          or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
          printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
          goto 0x88AB;  // 0x874D
        }
        // 0x864B-0x8654
        area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
        if (area2.event_scratch0 == 0) {
          goto 0x8751;  // 0x8655
          // branch body 0x8751
          or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
          // 0x875A-0x8763
          area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
          if (area2.event_scratch0 != 0) {
            goto 0x84F8;  // 0x8764
          }
          printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
          horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
          // 0x87CC
          switch (area1.event_word_20A) {
            case 0: goto 0x87DB;
            case 1: goto 0x883B;
            case 2: goto 0x8892;
          }
        }
        // 0x8659-0x8662
        area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
        if (area2.event_scratch0 == 0) {
          goto 0x84F8;  // 0x8663
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
        printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
      case 1: goto 0x88B3;
      case 2: goto 0x898C;
    }
  }
}
```

## Event 35

- Target: `0x9E5E`
- Text hint: 'A GIFT SHOP.'

```text
event 35 {
  // 0x9E5E-0x9E67
  area2.event_scratch0 = 15 & area1.event_word_2C4;  // 0x9E5E
  if (area2.event_scratch0 == 0) {
    goto 0x85F6;  // 0x9E68
    // branch body 0x85F6
    add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
    // 0x85FF
    switch (area1.event_word_20E) {
      case 0: goto 0x860E;
        // case 0 body
        // 0x860E-0x8617
        area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8618
          // branch body 0x84F8
          // 0x84F8-0x84FE
          if (39 < area1.event_word_206) {
            exit_event();  // 0x84FF
          }
          // 0x8500-0x8506
          if (8 > area1.event_word_2BC) {
            exit_event();  // 0x8507
          }
          random(area2.event_scratch0 = random 1..99);  // 0x8508
          // 0x850E-0x8514
          if (9 > area2.event_scratch0) {
            exit_event();  // 0x8515
          }
          add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
          area1.event_word_206 = 0;  // 0x851F
          random(area1.event_word_21C = random 1..3);  // 0x8525
          gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
          gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
          setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
          exit_event();  // 0x8548
        }
        random(area2.event_scratch0 = random 1..5);  // 0x861C
        add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
        // 0x862B-0x8632
        if (area2.event_scratch0 < area1.event_word_218) {
          goto 0x84F8;  // 0x8633
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        area1.event_word_218 = 0;  // 0x8637
        // 0x863D-0x8646
        area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
        if (area2.event_scratch0 == 0) {
          goto 0x8714;  // 0x8647
          // branch body 0x8714
          or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
          printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
          goto 0x88AB;  // 0x874D
        }
        // 0x864B-0x8654
        area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
        if (area2.event_scratch0 == 0) {
          goto 0x8751;  // 0x8655
          // branch body 0x8751
          or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
          // 0x875A-0x8763
          area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
          if (area2.event_scratch0 != 0) {
            goto 0x84F8;  // 0x8764
          }
          printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
          horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
          // 0x87CC
          switch (area1.event_word_20A) {
            case 0: goto 0x87DB;
            case 1: goto 0x883B;
            case 2: goto 0x8892;
          }
        }
        // 0x8659-0x8662
        area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
        if (area2.event_scratch0 == 0) {
          goto 0x84F8;  // 0x8663
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
        printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
      case 1: goto 0x88B3;
      case 2: goto 0x898C;
    }
  }
}
```

## Event 36

- Target: `0x9EB6`
- Text hint: 'A GIFT SHOP.'

```text
event 36 {
  printclear('A GIFT SHOP.');  // 0x9EB6
  // 0x9EC2-0x9ECB
  area2.event_scratch0 = 8 & area1.event_word_2C2;  // 0x9EC2
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9ECC
  }
  or(area1.event_word_2C2 = 8 | area1.event_word_2C2);  // 0x9ECD
  print(' MAGAZINES, T-SHIRTS AND CURIOS LAY ABOUT THE ROOM, BROKEN AND SHREDDED.');  // 0x9ED6
  printclear('EXPLOSIVES OF ALL KINDS, ALL THE BETTER TO KILL YOU WITH.');  // 0x9F55
  // 0x9FB8-0x9FC1
  area2.event_scratch0 = 128 & area1.event_word_2CA;  // 0x9FB8
  if (area2.event_scratch0 == 0) {
    goto 0x85F6;  // 0x9FC2
    // branch body 0x85F6
    add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
    // 0x85FF
    switch (area1.event_word_20E) {
      case 0: goto 0x860E;
        // case 0 body
        // 0x860E-0x8617
        area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8618
          // branch body 0x84F8
          // 0x84F8-0x84FE
          if (39 < area1.event_word_206) {
            exit_event();  // 0x84FF
          }
          // 0x8500-0x8506
          if (8 > area1.event_word_2BC) {
            exit_event();  // 0x8507
          }
          random(area2.event_scratch0 = random 1..99);  // 0x8508
          // 0x850E-0x8514
          if (9 > area2.event_scratch0) {
            exit_event();  // 0x8515
          }
          add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
          area1.event_word_206 = 0;  // 0x851F
          random(area1.event_word_21C = random 1..3);  // 0x8525
          gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
          gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
          setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
          exit_event();  // 0x8548
        }
        random(area2.event_scratch0 = random 1..5);  // 0x861C
        add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
        // 0x862B-0x8632
        if (area2.event_scratch0 < area1.event_word_218) {
          goto 0x84F8;  // 0x8633
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        area1.event_word_218 = 0;  // 0x8637
        // 0x863D-0x8646
        area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
        if (area2.event_scratch0 == 0) {
          goto 0x8714;  // 0x8647
          // branch body 0x8714
          or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
          printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
          goto 0x88AB;  // 0x874D
        }
        // 0x864B-0x8654
        area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
        if (area2.event_scratch0 == 0) {
          goto 0x8751;  // 0x8655
          // branch body 0x8751
          or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
          // 0x875A-0x8763
          area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
          if (area2.event_scratch0 != 0) {
            goto 0x84F8;  // 0x8764
          }
          printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
          horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
          // 0x87CC
          switch (area1.event_word_20A) {
            case 0: goto 0x87DB;
            case 1: goto 0x883B;
            case 2: goto 0x8892;
          }
        }
        // 0x8659-0x8662
        area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
        if (area2.event_scratch0 == 0) {
          goto 0x84F8;  // 0x8663
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
        printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
      case 1: goto 0x88B3;
      case 2: goto 0x898C;
    }
  }
}
```

## Event 37

- Target: `0x9F55`
- Text hint: 'EXPLOSIVES OF ALL KINDS, ALL THE BETTER TO KILL YOU WITH.'

```text
event 37 {
  printclear('EXPLOSIVES OF ALL KINDS, ALL THE BETTER TO KILL YOU WITH.');  // 0x9F55
  // 0x9FB8-0x9FC1
  area2.event_scratch0 = 128 & area1.event_word_2CA;  // 0x9FB8
  if (area2.event_scratch0 == 0) {
    goto 0x85F6;  // 0x9FC2
    // branch body 0x85F6
    add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
    // 0x85FF
    switch (area1.event_word_20E) {
      case 0: goto 0x860E;
        // case 0 body
        // 0x860E-0x8617
        area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8618
          // branch body 0x84F8
          // 0x84F8-0x84FE
          if (39 < area1.event_word_206) {
            exit_event();  // 0x84FF
          }
          // 0x8500-0x8506
          if (8 > area1.event_word_2BC) {
            exit_event();  // 0x8507
          }
          random(area2.event_scratch0 = random 1..99);  // 0x8508
          // 0x850E-0x8514
          if (9 > area2.event_scratch0) {
            exit_event();  // 0x8515
          }
          add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
          area1.event_word_206 = 0;  // 0x851F
          random(area1.event_word_21C = random 1..3);  // 0x8525
          gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
          gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
          setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
          exit_event();  // 0x8548
        }
        random(area2.event_scratch0 = random 1..5);  // 0x861C
        add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
        // 0x862B-0x8632
        if (area2.event_scratch0 < area1.event_word_218) {
          goto 0x84F8;  // 0x8633
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        area1.event_word_218 = 0;  // 0x8637
        // 0x863D-0x8646
        area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
        if (area2.event_scratch0 == 0) {
          goto 0x8714;  // 0x8647
          // branch body 0x8714
          or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
          printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
          goto 0x88AB;  // 0x874D
        }
        // 0x864B-0x8654
        area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
        if (area2.event_scratch0 == 0) {
          goto 0x8751;  // 0x8655
          // branch body 0x8751
          or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
          // 0x875A-0x8763
          area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
          if (area2.event_scratch0 != 0) {
            goto 0x84F8;  // 0x8764
          }
          printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
          horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
          // 0x87CC
          switch (area1.event_word_20A) {
            case 0: goto 0x87DB;
            case 1: goto 0x883B;
            case 2: goto 0x8892;
          }
        }
        // 0x8659-0x8662
        area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
        if (area2.event_scratch0 == 0) {
          goto 0x84F8;  // 0x8663
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
        printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
      case 1: goto 0x88B3;
      case 2: goto 0x898C;
    }
  }
}
```

## Event 38

- Target: `0x9FB8`
- Text hint: 'AN EXHIBIT OF A '

```text
event 38 {
  // 0x9FB8-0x9FC1
  area2.event_scratch0 = 128 & area1.event_word_2CA;  // 0x9FB8
  if (area2.event_scratch0 == 0) {
    goto 0x85F6;  // 0x9FC2
    // branch body 0x85F6
    add(area1.event_word_218 = 1 + area1.event_word_218);  // 0x85F6
    // 0x85FF
    switch (area1.event_word_20E) {
      case 0: goto 0x860E;
        // case 0 body
        // 0x860E-0x8617
        area2.event_scratch0 = 4 & area1.event_word_2C0;  // 0x860E
        if (area2.event_scratch0 != 0) {
          goto 0x84F8;  // 0x8618
          // branch body 0x84F8
          // 0x84F8-0x84FE
          if (39 < area1.event_word_206) {
            exit_event();  // 0x84FF
          }
          // 0x8500-0x8506
          if (8 > area1.event_word_2BC) {
            exit_event();  // 0x8507
          }
          random(area2.event_scratch0 = random 1..99);  // 0x8508
          // 0x850E-0x8514
          if (9 > area2.event_scratch0) {
            exit_event();  // 0x8515
          }
          add(area1.event_word_2BC = 1 + area1.event_word_2BC);  // 0x8516
          area1.event_word_206 = 0;  // 0x851F
          random(area1.event_word_21C = random 1..3);  // 0x8525
          gettable(area2.event_scratch1 = abs_A2F0[area1.event_word_21C]);  // 0x852B
          gettable(area2.event_scratch2 = abs_A2EC[area1.event_word_21C]);  // 0x8535
          setup_monster(sprite_id: area2.event_scratch1 max_distance: 0 pic_id: area2.event_scratch2);  // 0x853F
          exit_event();  // 0x8548
        }
        random(area2.event_scratch0 = random 1..5);  // 0x861C
        add(area2.event_scratch0 = 10 + area2.event_scratch0);  // 0x8622
        // 0x862B-0x8632
        if (area2.event_scratch0 < area1.event_word_218) {
          goto 0x84F8;  // 0x8633
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        area1.event_word_218 = 0;  // 0x8637
        // 0x863D-0x8646
        area2.event_scratch0 = 1 & area1.event_word_2C0;  // 0x863D
        if (area2.event_scratch0 == 0) {
          goto 0x8714;  // 0x8647
          // branch body 0x8714
          or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
          printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
          goto 0x88AB;  // 0x874D
        }
        // 0x864B-0x8654
        area2.event_scratch0 = 2 & area1.event_word_2C0;  // 0x864B
        if (area2.event_scratch0 == 0) {
          goto 0x8751;  // 0x8655
          // branch body 0x8751
          or(area1.event_word_2C0 = 2 | area1.event_word_2C0);  // 0x8751
          // 0x875A-0x8763
          area2.event_scratch0 = 4 & area1.event_word_2C2;  // 0x875A
          if (area2.event_scratch0 != 0) {
            goto 0x84F8;  // 0x8764
          }
          printclear("A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?");  // 0x8768
          horizontal_menu(area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING');  // 0x87B3
          // 0x87CC
          switch (area1.event_word_20A) {
            case 0: goto 0x87DB;
            case 1: goto 0x883B;
            case 2: goto 0x8892;
          }
        }
        // 0x8659-0x8662
        area2.event_scratch0 = 16 & area1.event_word_2BE;  // 0x8659
        if (area2.event_scratch0 == 0) {
          goto 0x84F8;  // 0x8663
          // branch body 0x84F8
          // target 0x84F8 already emitted
        }
        or(area1.event_word_2C0 = 4 | area1.event_word_2C0);  // 0x8667
        printclear("YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'");  // 0x8670
        or(area1.event_word_2C0 = 1 | area1.event_word_2C0);  // 0x8714
        printclear('YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.');  // 0x871D
        goto 0x88AB;  // 0x874D
        // branch body 0x88AB
          area1.event_word_218 = 0;  // 0x88AB
          // 0x88B3-0x88B9
          if (2 == mapPosX) {
            goto 0x8950;  // 0x88BA
          }
          // 0x88BE-0x88C4
          if (0 == mapDirection) {
            goto 0x8950;  // 0x88C5
          }
          add(area1.event_word_210 = 1 + area1.event_word_210);  // 0x88C9
          // 0x88D2-0x88D8
          if (2 == area1.event_word_210) {
            exit_event();  // 0x88D9
          }
      case 1: goto 0x88B3;
      case 2: goto 0x898C;
    }
  }
}
```
