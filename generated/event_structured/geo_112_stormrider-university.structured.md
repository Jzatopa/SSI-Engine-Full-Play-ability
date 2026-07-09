# GEO 112: Stormrider University

ECL block: `112`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8620`
- Text hint: 'THE LANDING PAD. '

```text
event 01 {
  // 0x8620-0x8626
  if (mapDirection != 3) {
    exit_event();  // 0x8627
  }
  printclear('THE LANDING PAD. ');  // 0x8628
  // 0x8638
  switch (area1.event_word_372) {
    case 0: goto 0x821E;
      // case 0 body
      exit_event();  // 0x821E
    case 1: goto 0x864A;
      // case 1 body
      // 0x864A-0x8653
      area2.event_scratch0 = 1 & area1.event_word_370;  // 0x864A
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8654
      }
      setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8655
      exit_event();  // 0x865C
    case 2: goto 0x869E;
      // case 2 body
      print('DO YOU LEAVE THE UNIVERSITY?');  // 0x869E
      // 0x8765-0x876B
      if (mapDirection != 3) {
        exit_event();  // 0x876C
      }
      // 0x876D
      switch (area1.event_word_372) {
        case 0: goto 0x877F;
          // case 0 body
          // 0x877F-0x8788
          area2.event_scratch0 = 2 & area1.event_word_370;  // 0x877F
          if (area2.event_scratch0 != 0) {
            goto 0x88A0;  // 0x8789
            // branch body 0x88A0
            picture(block_id: 29);  // 0x88A0
            printclear('MAKALI IS HARD AT WORK. SHE IGNORES YOU.');  // 0x88A3
            // 0x88C6-0x88CC
            if (area1.event_word_214 != 1) {
              exit_event();  // 0x88CD
            }
            // 0x88CE-0x88D7
            area2.event_scratch0 = 128 & area1.event_word_376;  // 0x88CE
            if (area2.event_scratch0 != 0) {
              exit_event();  // 0x88D8
            }
            setup_monster(sprite_id: 63 max_distance: 0 pic_id: 255);  // 0x88D9
            exit_event();  // 0x88E0
          }
          or(area1.event_word_370 = 2 | area1.event_word_370);  // 0x878D
          setup_monster(sprite_id: 63 max_distance: 0 pic_id: 255);  // 0x8796
          exit_event();  // 0x879D
        case 1: goto 0x88C6;
          // case 1 body
          // 0x88C6-0x88CC
          if (area1.event_word_214 != 1) {
            exit_event();  // 0x88CD
          }
          // 0x88CE-0x88D7
          area2.event_scratch0 = 128 & area1.event_word_376;  // 0x88CE
          if (area2.event_scratch0 != 0) {
            exit_event();  // 0x88D8
          }
          setup_monster(sprite_id: 63 max_distance: 0 pic_id: 255);  // 0x88D9
          exit_event();  // 0x88E0
        case 2: goto 0x88A0;
          // case 2 body
          // target 0x88A0 already emitted
        case 3: goto 0x821E;
          // case 3 body
          // target 0x821E already emitted
      }
    case 3: goto 0x869E;
      // case 3 body
      // target 0x869E already emitted
  }
}
```

## Event 02

- Target: `0x8765`
- Text hint: 'MAKALI IS HARD AT WORK. SHE IGNORES YOU.'

```text
event 02 {
  // 0x8765-0x876B
  if (mapDirection != 3) {
    exit_event();  // 0x876C
  }
  // 0x876D
  switch (area1.event_word_372) {
    case 0: goto 0x877F;
      // case 0 body
      // 0x877F-0x8788
      area2.event_scratch0 = 2 & area1.event_word_370;  // 0x877F
      if (area2.event_scratch0 != 0) {
        goto 0x88A0;  // 0x8789
        // branch body 0x88A0
        picture(block_id: 29);  // 0x88A0
        printclear('MAKALI IS HARD AT WORK. SHE IGNORES YOU.');  // 0x88A3
        // 0x88C6-0x88CC
        if (area1.event_word_214 != 1) {
          exit_event();  // 0x88CD
        }
        // 0x88CE-0x88D7
        area2.event_scratch0 = 128 & area1.event_word_376;  // 0x88CE
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x88D8
        }
        setup_monster(sprite_id: 63 max_distance: 0 pic_id: 255);  // 0x88D9
        exit_event();  // 0x88E0
      }
      or(area1.event_word_370 = 2 | area1.event_word_370);  // 0x878D
      setup_monster(sprite_id: 63 max_distance: 0 pic_id: 255);  // 0x8796
      exit_event();  // 0x879D
    case 1: goto 0x88C6;
      // case 1 body
      // 0x88C6-0x88CC
      if (area1.event_word_214 != 1) {
        exit_event();  // 0x88CD
      }
      // 0x88CE-0x88D7
      area2.event_scratch0 = 128 & area1.event_word_376;  // 0x88CE
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x88D8
      }
      setup_monster(sprite_id: 63 max_distance: 0 pic_id: 255);  // 0x88D9
      exit_event();  // 0x88E0
    case 2: goto 0x88A0;
      // case 2 body
      // target 0x88A0 already emitted
    case 3: goto 0x821E;
      // case 3 body
      exit_event();  // 0x821E
  }
}
```

## Event 03

- Target: `0x8944`
- Text hint: 'AS YOU EXIT THE LABS, AN EXPLOSION ROCKS THE UNIVERSITY!'

```text
event 03 {
  // 0x8944-0x894D
  area2.event_scratch0 = 2 & area1.event_word_370;  // 0x8944
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x894E
  }
  // 0x894F-0x8955
  if (area1.event_word_372 != 0) {
    exit_event();  // 0x8956
  }
  area1.event_word_372 = 1;  // 0x8957
  printclear('AS YOU EXIT THE LABS, AN EXPLOSION ROCKS THE UNIVERSITY!');  // 0x895D
  exit_event();  // 0x898B
}
```

## Event 04

- Target: `0x8A5D`
- Text hint: 'YOU ENTER A LAB. '

```text
event 04 {
  // 0x8A5D-0x8A63
  if (mapDirection != 0) {
    exit_event();  // 0x8A64
  }
  goto 0x8A71;  // 0x8A65
  // branch body 0x8A71
    printclear('YOU ENTER A LAB. ');  // 0x8A71
    // 0x8A81
    switch (area1.event_word_372) {
      case 0: goto 0x8A93;
        // case 0 body
        print('STORMRIDERS WORK HERE.');  // 0x8A93
        // 0x8AA9-0x8AAF
        if (area1.event_word_214 != 1) {
          exit_event();  // 0x8AB0
        }
        // 0x8AB1-0x8AB7
        if (area1.event_word_202 > 2) {
          add(area1.event_word_202 = 1 + area1.event_word_202);  // 0x8AB8
        }
        if_>(<if compare flag is false, skip next op>);  // 0x8AC1
        exit_event();  // 0x8AC2
      case 1: goto 0x8AA9;
        // case 1 body
        // 0x8AA9-0x8AAF
        if (area1.event_word_214 != 1) {
          exit_event();  // 0x8AB0
        }
        // 0x8AB1-0x8AB7
        if (area1.event_word_202 > 2) {
          add(area1.event_word_202 = 1 + area1.event_word_202);  // 0x8AB8
        }
        if_>(<if compare flag is false, skip next op>);  // 0x8AC1
        exit_event();  // 0x8AC2
      case 2: goto 0x8B3B;
        // case 2 body
        // 0x8B3B-0x8B41
        if (area1.event_word_372 == 1) {
          exit_event();  // 0x8B42
        }
        print('STORMRIDERS WORK TO REPAIR THE DAMAGE.');  // 0x8B43
        subtract(area2.event_scratch0 = area2.event_scratch0 - 9);  // 0x8B65
        // 0x8B6E-0x8B75
        if (mapDirection != area2.event_scratch0) {
          exit_event();  // 0x8B76
        }
        printclear('YOU ENTER A DORM ROOM. ');  // 0x8B77
        // 0x8B8C
        switch (area1.event_word_372) {
          case 0: goto 0x8B9E;
          case 1: goto 0x8C47;
          case 2: goto 0x8C47;
          case 3: goto 0x8C5B;
        }
      case 3: goto 0x8B3B;
        // case 3 body
        // target 0x8B3B already emitted
    }
}
```

## Event 05

- Target: `0x8A69`
- Text hint: 'YOU ENTER A LAB. '

```text
event 05 {
  // 0x8A69-0x8A6F
  if (mapDirection != 2) {
    exit_event();  // 0x8A70
  }
  printclear('YOU ENTER A LAB. ');  // 0x8A71
  // 0x8A81
  switch (area1.event_word_372) {
    case 0: goto 0x8A93;
      // case 0 body
      print('STORMRIDERS WORK HERE.');  // 0x8A93
      // 0x8AA9-0x8AAF
      if (area1.event_word_214 != 1) {
        exit_event();  // 0x8AB0
      }
      // 0x8AB1-0x8AB7
      if (area1.event_word_202 > 2) {
        add(area1.event_word_202 = 1 + area1.event_word_202);  // 0x8AB8
      }
      if_>(<if compare flag is false, skip next op>);  // 0x8AC1
      exit_event();  // 0x8AC2
    case 1: goto 0x8AA9;
      // case 1 body
      // 0x8AA9-0x8AAF
      if (area1.event_word_214 != 1) {
        exit_event();  // 0x8AB0
      }
      // 0x8AB1-0x8AB7
      if (area1.event_word_202 > 2) {
        add(area1.event_word_202 = 1 + area1.event_word_202);  // 0x8AB8
      }
      if_>(<if compare flag is false, skip next op>);  // 0x8AC1
      exit_event();  // 0x8AC2
    case 2: goto 0x8B3B;
      // case 2 body
      // 0x8B3B-0x8B41
      if (area1.event_word_372 == 1) {
        exit_event();  // 0x8B42
      }
      print('STORMRIDERS WORK TO REPAIR THE DAMAGE.');  // 0x8B43
      subtract(area2.event_scratch0 = area2.event_scratch0 - 9);  // 0x8B65
      // 0x8B6E-0x8B75
      if (mapDirection != area2.event_scratch0) {
        exit_event();  // 0x8B76
      }
      printclear('YOU ENTER A DORM ROOM. ');  // 0x8B77
      // 0x8B8C
      switch (area1.event_word_372) {
        case 0: goto 0x8B9E;
          // case 0 body
          // 0x8B9E
          switch (area2.event_scratch0) {
            case 0: goto 0x8BB0;
            case 1: goto 0x8BEE;
            case 2: goto 0x8C36;
            case 3: goto 0x8C36;
          }
        case 1: goto 0x8C47;
          // case 1 body
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 2: goto 0x8C47;
          // case 2 body
          // target 0x8C47 already emitted
        case 3: goto 0x8C5B;
          // case 3 body
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
      }
    case 3: goto 0x8B3B;
      // case 3 body
      // target 0x8B3B already emitted
  }
}
```

## Event 09

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 09 {
  subtract(area2.event_scratch0 = area2.event_scratch0 - 9);  // 0x8B65
  // 0x8B6E-0x8B75
  if (mapDirection != area2.event_scratch0) {
    exit_event();  // 0x8B76
  }
  printclear('YOU ENTER A DORM ROOM. ');  // 0x8B77
  // 0x8B8C
  switch (area1.event_word_372) {
    case 0: goto 0x8B9E;
      // case 0 body
      // 0x8B9E
      switch (area2.event_scratch0) {
        case 0: goto 0x8BB0;
          // case 0 body
          print('A STORMRIDER LOOKS UP FROM HER BOOK, GREETS YOU, AND RETURNS TO HER READING.');  // 0x8BB0
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 1: goto 0x8BEE;
          // case 1 body
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 2: goto 0x8C36;
          // case 2 body
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 3: goto 0x8C36;
          // case 3 body
          // target 0x8C36 already emitted
      }
    case 1: goto 0x8C47;
      // case 1 body
      print('IT HAS BEEN WRECKED.');  // 0x8C47
      // 0x8C5B
      switch (area2.event_scratch0) {
        case 0: goto 0x8C6D;
          // case 0 body
          print(' A STORMRIDER STUDENT IS CLEANING UP. SHE IS FIXING A DESK SMASHED BY THE AMALTHEANS.');  // 0x8C6D
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            print('THE CONTROLS ARE SMASHED.');  // 0x8D7B
            // 0x8D93-0x8D99
            if (area1.event_word_372 != 1) {
              exit_event();  // 0x8D9A
            }
            // 0x8D9B-0x8DA4
            area2.event_scratch0 = 8 & area1.event_word_370;  // 0x8D9B
            if (area2.event_scratch0 != 0) {
              exit_event();  // 0x8DA5
            }
            or(area1.event_word_370 = 8 | area1.event_word_370);  // 0x8DA6
            setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8DAF
            exit_event();  // 0x8DB6
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 1: goto 0x8C47;
          // case 1 body
          // target 0x8C47 already emitted
        case 2: goto 0x8CB2;
          // case 2 body
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            // target 0x8D7B already emitted
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 3: goto 0x8C47;
          // case 3 body
          // target 0x8C47 already emitted
      }
    case 2: goto 0x8C47;
    case 3: goto 0x8C5B;
  }
}
```

## Event 10

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 10 {
  subtract(area2.event_scratch0 = area2.event_scratch0 - 9);  // 0x8B65
  // 0x8B6E-0x8B75
  if (mapDirection != area2.event_scratch0) {
    exit_event();  // 0x8B76
  }
  printclear('YOU ENTER A DORM ROOM. ');  // 0x8B77
  // 0x8B8C
  switch (area1.event_word_372) {
    case 0: goto 0x8B9E;
      // case 0 body
      // 0x8B9E
      switch (area2.event_scratch0) {
        case 0: goto 0x8BB0;
          // case 0 body
          print('A STORMRIDER LOOKS UP FROM HER BOOK, GREETS YOU, AND RETURNS TO HER READING.');  // 0x8BB0
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 1: goto 0x8BEE;
          // case 1 body
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 2: goto 0x8C36;
          // case 2 body
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 3: goto 0x8C36;
          // case 3 body
          // target 0x8C36 already emitted
      }
    case 1: goto 0x8C47;
      // case 1 body
      print('IT HAS BEEN WRECKED.');  // 0x8C47
      // 0x8C5B
      switch (area2.event_scratch0) {
        case 0: goto 0x8C6D;
          // case 0 body
          print(' A STORMRIDER STUDENT IS CLEANING UP. SHE IS FIXING A DESK SMASHED BY THE AMALTHEANS.');  // 0x8C6D
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            print('THE CONTROLS ARE SMASHED.');  // 0x8D7B
            // 0x8D93-0x8D99
            if (area1.event_word_372 != 1) {
              exit_event();  // 0x8D9A
            }
            // 0x8D9B-0x8DA4
            area2.event_scratch0 = 8 & area1.event_word_370;  // 0x8D9B
            if (area2.event_scratch0 != 0) {
              exit_event();  // 0x8DA5
            }
            or(area1.event_word_370 = 8 | area1.event_word_370);  // 0x8DA6
            setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8DAF
            exit_event();  // 0x8DB6
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 1: goto 0x8C47;
          // case 1 body
          // target 0x8C47 already emitted
        case 2: goto 0x8CB2;
          // case 2 body
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            // target 0x8D7B already emitted
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 3: goto 0x8C47;
          // case 3 body
          // target 0x8C47 already emitted
      }
    case 2: goto 0x8C47;
    case 3: goto 0x8C5B;
  }
}
```

## Event 11

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 11 {
  subtract(area2.event_scratch0 = area2.event_scratch0 - 9);  // 0x8B65
  // 0x8B6E-0x8B75
  if (mapDirection != area2.event_scratch0) {
    exit_event();  // 0x8B76
  }
  printclear('YOU ENTER A DORM ROOM. ');  // 0x8B77
  // 0x8B8C
  switch (area1.event_word_372) {
    case 0: goto 0x8B9E;
      // case 0 body
      // 0x8B9E
      switch (area2.event_scratch0) {
        case 0: goto 0x8BB0;
          // case 0 body
          print('A STORMRIDER LOOKS UP FROM HER BOOK, GREETS YOU, AND RETURNS TO HER READING.');  // 0x8BB0
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 1: goto 0x8BEE;
          // case 1 body
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 2: goto 0x8C36;
          // case 2 body
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 3: goto 0x8C36;
          // case 3 body
          // target 0x8C36 already emitted
      }
    case 1: goto 0x8C47;
      // case 1 body
      print('IT HAS BEEN WRECKED.');  // 0x8C47
      // 0x8C5B
      switch (area2.event_scratch0) {
        case 0: goto 0x8C6D;
          // case 0 body
          print(' A STORMRIDER STUDENT IS CLEANING UP. SHE IS FIXING A DESK SMASHED BY THE AMALTHEANS.');  // 0x8C6D
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            print('THE CONTROLS ARE SMASHED.');  // 0x8D7B
            // 0x8D93-0x8D99
            if (area1.event_word_372 != 1) {
              exit_event();  // 0x8D9A
            }
            // 0x8D9B-0x8DA4
            area2.event_scratch0 = 8 & area1.event_word_370;  // 0x8D9B
            if (area2.event_scratch0 != 0) {
              exit_event();  // 0x8DA5
            }
            or(area1.event_word_370 = 8 | area1.event_word_370);  // 0x8DA6
            setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8DAF
            exit_event();  // 0x8DB6
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 1: goto 0x8C47;
          // case 1 body
          // target 0x8C47 already emitted
        case 2: goto 0x8CB2;
          // case 2 body
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            // target 0x8D7B already emitted
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 3: goto 0x8C47;
          // case 3 body
          // target 0x8C47 already emitted
      }
    case 2: goto 0x8C47;
    case 3: goto 0x8C5B;
  }
}
```

## Event 12

- Target: `0x8B65`
- Text hint: 'YOU ENTER A DORM ROOM. '

```text
event 12 {
  subtract(area2.event_scratch0 = area2.event_scratch0 - 9);  // 0x8B65
  // 0x8B6E-0x8B75
  if (mapDirection != area2.event_scratch0) {
    exit_event();  // 0x8B76
  }
  printclear('YOU ENTER A DORM ROOM. ');  // 0x8B77
  // 0x8B8C
  switch (area1.event_word_372) {
    case 0: goto 0x8B9E;
      // case 0 body
      // 0x8B9E
      switch (area2.event_scratch0) {
        case 0: goto 0x8BB0;
          // case 0 body
          print('A STORMRIDER LOOKS UP FROM HER BOOK, GREETS YOU, AND RETURNS TO HER READING.');  // 0x8BB0
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 1: goto 0x8BEE;
          // case 1 body
          print('TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.');  // 0x8BEE
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 2: goto 0x8C36;
          // case 2 body
          print('NOBODY IS HERE.');  // 0x8C36
          print('IT HAS BEEN WRECKED.');  // 0x8C47
          // 0x8C5B
          switch (area2.event_scratch0) {
            case 0: goto 0x8C6D;
            case 1: goto 0x8C47;
            case 2: goto 0x8CB2;
            case 3: goto 0x8C47;
          }
        case 3: goto 0x8C36;
          // case 3 body
          // target 0x8C36 already emitted
      }
    case 1: goto 0x8C47;
      // case 1 body
      print('IT HAS BEEN WRECKED.');  // 0x8C47
      // 0x8C5B
      switch (area2.event_scratch0) {
        case 0: goto 0x8C6D;
          // case 0 body
          print(' A STORMRIDER STUDENT IS CLEANING UP. SHE IS FIXING A DESK SMASHED BY THE AMALTHEANS.');  // 0x8C6D
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            print('THE CONTROLS ARE SMASHED.');  // 0x8D7B
            // 0x8D93-0x8D99
            if (area1.event_word_372 != 1) {
              exit_event();  // 0x8D9A
            }
            // 0x8D9B-0x8DA4
            area2.event_scratch0 = 8 & area1.event_word_370;  // 0x8D9B
            if (area2.event_scratch0 != 0) {
              exit_event();  // 0x8DA5
            }
            or(area1.event_word_370 = 8 | area1.event_word_370);  // 0x8DA6
            setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8DAF
            exit_event();  // 0x8DB6
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 1: goto 0x8C47;
          // case 1 body
          // target 0x8C47 already emitted
        case 2: goto 0x8CB2;
          // case 2 body
          print(' MOST OF THE DAMAGE HAS BEEN REPAIRED.');  // 0x8CB2
          printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
          // 0x8CE9-0x8CEF
          if (area1.event_word_372 != 0) {
            goto 0x8D7B;  // 0x8CF0
            // branch body 0x8D7B
            // target 0x8D7B already emitted
          }
          print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
          exit_event();  // 0x8D0C
        case 3: goto 0x8C47;
          // case 3 body
          // target 0x8C47 already emitted
      }
    case 2: goto 0x8C47;
    case 3: goto 0x8C5B;
  }
}
```

## Event 13

- Target: `0x8CD4`
- Text hint: 'YOU ENTER AN ELEVATOR. '

```text
event 13 {
  printclear('YOU ENTER AN ELEVATOR. ');  // 0x8CD4
  // 0x8CE9-0x8CEF
  if (area1.event_word_372 != 0) {
    goto 0x8D7B;  // 0x8CF0
    // branch body 0x8D7B
    print('THE CONTROLS ARE SMASHED.');  // 0x8D7B
    // 0x8D93-0x8D99
    if (area1.event_word_372 != 1) {
      exit_event();  // 0x8D9A
    }
    // 0x8D9B-0x8DA4
    area2.event_scratch0 = 8 & area1.event_word_370;  // 0x8D9B
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8DA5
    }
    or(area1.event_word_370 = 8 | area1.event_word_370);  // 0x8DA6
    setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8DAF
    exit_event();  // 0x8DB6
  }
  print('THE CONTROLS COME TO LIFE.');  // 0x8CF4
  exit_event();  // 0x8D0C
}
```

## Event 14

- Target: `0x8D93`
- Text hint: 'YOU ENTER THE CLASSROOM COMPLEX. '

```text
event 14 {
  // 0x8D93-0x8D99
  if (area1.event_word_372 != 1) {
    exit_event();  // 0x8D9A
  }
  // 0x8D9B-0x8DA4
  area2.event_scratch0 = 8 & area1.event_word_370;  // 0x8D9B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8DA5
  }
  or(area1.event_word_370 = 8 | area1.event_word_370);  // 0x8DA6
  setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x8DAF
  exit_event();  // 0x8DB6
}
```

## Event 15

- Target: `0x8E4B`
- Text hint: 'YOU ENTER THE CLASSROOM COMPLEX. '

```text
event 15 {
  // 0x8E4B-0x8E51
  if (mapDirection != 1) {
    exit_event();  // 0x8E52
  }
  printclear('YOU ENTER THE CLASSROOM COMPLEX. ');  // 0x8E53
  // 0x8E6F-0x8E75
  if (area1.event_word_372 != 1) {
    exit_event();  // 0x8E76
  }
  // 0x8E77-0x8E80
  area2.event_scratch0 = 16 & area1.event_word_370;  // 0x8E77
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8E81
  }
  or(area1.event_word_370 = 16 | area1.event_word_370);  // 0x8E82
  setup_monster(sprite_id: 19 max_distance: 1 pic_id: 255);  // 0x8E8B
  exit_event();  // 0x8E92
}
```

## Event 16

- Target: `0x8F5C`
- Text hint: 'THE STUDENTS HERE HAVE BEEN MASSACRED. NOT ONE REMAINS ALIVE.' 'GRIM STUDENTS ARE REMOVING DEAD CLASSMATES FROM THIS ROOM.'

```text
event 16 {
  // 0x8F5C-0x8F62
  if (mapDirection != 0) {
    exit_event();  // 0x8F63
  }
  // 0x8F64
  switch (area1.event_word_372) {
    case 0: goto 0x94BD;
      // case 0 body
      subtract(area2.event_scratch0 = area2.event_scratch0 - 16);  // 0x94BD
      // 0x94C6
      switch (area2.event_scratch0) {
        case 0: goto 0x950C;
          // case 0 body
          printclear('A PHYSICS LECTURE');  // 0x950C
          return;  // 0x951C
        case 1: goto 0x951D;
          // case 1 body
          printclear('A LITERARY SEMINAR');  // 0x951D
          return;  // 0x952E
        case 2: goto 0x952F;
          // case 2 body
          printclear('A CLASS IN BOTANICAL GENETICS');  // 0x952F
          return;  // 0x9548
        case 3: goto 0x9549;
          // case 3 body
          printclear('A ASTROGATION LECTURE');  // 0x9549
          return;  // 0x955C
      }
    case 1: goto 0x8F76;
      // case 1 body
      printclear('THE STUDENTS HERE HAVE BEEN MASSACRED. NOT ONE REMAINS ALIVE.');  // 0x8F76
      printclear('GRIM STUDENTS ARE REMOVING DEAD CLASSMATES FROM THIS ROOM.');  // 0x8FA9
      // 0x8FDA-0x8FE0
      if (mapDirection != 0) {
        exit_event();  // 0x8FE1
      }
      // 0x8FE2
      switch (area1.event_word_372) {
        case 0: goto 0x94BD;
          // case 0 body
          // target 0x94BD already emitted
        case 1: goto 0x8FF4;
          // case 1 body
          // 0x8FF4-0x8FFD
          area2.event_scratch0 = 64 & area1.event_word_370;  // 0x8FF4
          if (area2.event_scratch0 != 0) {
            exit_event();  // 0x8FFE
          }
          setup_monster(sprite_id: 19 max_distance: 1 pic_id: 255);  // 0x8FFF
          exit_event();  // 0x9006
        case 2: goto 0x821E;
          // case 2 body
          exit_event();  // 0x821E
        case 3: goto 0x821E;
          // case 3 body
          // target 0x821E already emitted
      }
    case 2: goto 0x8FA9;
      // case 2 body
      printclear('GRIM STUDENTS ARE REMOVING DEAD CLASSMATES FROM THIS ROOM.');  // 0x8FA9
      // 0x8FDA-0x8FE0
      if (mapDirection != 0) {
        exit_event();  // 0x8FE1
      }
      // 0x8FE2
      switch (area1.event_word_372) {
        case 0: goto 0x94BD;
          // case 0 body
          // target 0x94BD already emitted
        case 1: goto 0x8FF4;
          // case 1 body
          // target 0x8FF4 already emitted
        case 2: goto 0x821E;
          // case 2 body
          // target 0x821E already emitted
        case 3: goto 0x821E;
          // case 3 body
          // target 0x821E already emitted
      }
    case 3: goto 0x94BD;
      // case 3 body
      // target 0x94BD already emitted
  }
}
```

## Event 17

- Target: `0x8FDA`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.'

```text
event 17 {
  // 0x8FDA-0x8FE0
  if (mapDirection != 0) {
    exit_event();  // 0x8FE1
  }
  // 0x8FE2
  switch (area1.event_word_372) {
    case 0: goto 0x94BD;
      // case 0 body
      subtract(area2.event_scratch0 = area2.event_scratch0 - 16);  // 0x94BD
      // 0x94C6
      switch (area2.event_scratch0) {
        case 0: goto 0x950C;
          // case 0 body
          printclear('A PHYSICS LECTURE');  // 0x950C
          return;  // 0x951C
        case 1: goto 0x951D;
          // case 1 body
          printclear('A LITERARY SEMINAR');  // 0x951D
          return;  // 0x952E
        case 2: goto 0x952F;
          // case 2 body
          printclear('A CLASS IN BOTANICAL GENETICS');  // 0x952F
          return;  // 0x9548
        case 3: goto 0x9549;
          // case 3 body
          printclear('A ASTROGATION LECTURE');  // 0x9549
          return;  // 0x955C
      }
    case 1: goto 0x8FF4;
      // case 1 body
      // 0x8FF4-0x8FFD
      area2.event_scratch0 = 64 & area1.event_word_370;  // 0x8FF4
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8FFE
      }
      setup_monster(sprite_id: 19 max_distance: 1 pic_id: 255);  // 0x8FFF
      exit_event();  // 0x9006
    case 2: goto 0x821E;
      // case 2 body
      exit_event();  // 0x821E
    case 3: goto 0x821E;
      // case 3 body
      // target 0x821E already emitted
  }
}
```

## Event 18

- Target: `0x938C`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.' 'THIS CLASSROOM IS EMPTY.'

```text
event 18 {
  // 0x938C-0x9392
  if (mapDirection != 1) {
    exit_event();  // 0x9393
  }
  // 0x9394
  switch (area1.event_word_372) {
    case 0: goto 0x94BD;
      // case 0 body
      subtract(area2.event_scratch0 = area2.event_scratch0 - 16);  // 0x94BD
      // 0x94C6
      switch (area2.event_scratch0) {
        case 0: goto 0x950C;
          // case 0 body
          printclear('A PHYSICS LECTURE');  // 0x950C
          return;  // 0x951C
        case 1: goto 0x951D;
          // case 1 body
          printclear('A LITERARY SEMINAR');  // 0x951D
          return;  // 0x952E
        case 2: goto 0x952F;
          // case 2 body
          printclear('A CLASS IN BOTANICAL GENETICS');  // 0x952F
          return;  // 0x9548
        case 3: goto 0x9549;
          // case 3 body
          printclear('A ASTROGATION LECTURE');  // 0x9549
          return;  // 0x955C
      }
    case 1: goto 0x821E;
      // case 1 body
      exit_event();  // 0x821E
    case 2: goto 0x821E;
      // case 2 body
      // target 0x821E already emitted
    case 3: goto 0x94BD;
      // case 3 body
      // target 0x94BD already emitted
  }
}
```

## Event 19

- Target: `0x93A7`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.' 'THIS CLASSROOM IS EMPTY.'

```text
event 19 {
  // 0x93A7-0x93AD
  if (mapDirection != 2) {
    exit_event();  // 0x93AE
  }
  // 0x93AF
  switch (area1.event_word_372) {
    case 0: goto 0x94BD;
      // case 0 body
      subtract(area2.event_scratch0 = area2.event_scratch0 - 16);  // 0x94BD
      // 0x94C6
      switch (area2.event_scratch0) {
        case 0: goto 0x950C;
          // case 0 body
          printclear('A PHYSICS LECTURE');  // 0x950C
          return;  // 0x951C
        case 1: goto 0x951D;
          // case 1 body
          printclear('A LITERARY SEMINAR');  // 0x951D
          return;  // 0x952E
        case 2: goto 0x952F;
          // case 2 body
          printclear('A CLASS IN BOTANICAL GENETICS');  // 0x952F
          return;  // 0x9548
        case 3: goto 0x9549;
          // case 3 body
          printclear('A ASTROGATION LECTURE');  // 0x9549
          return;  // 0x955C
      }
    case 1: goto 0x93C1;
      // case 1 body
      // 0x93C1-0x93CA
      area2.event_scratch0 = 32 & area1.event_word_370;  // 0x93C1
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x93CB
      }
      // 0x93CC-0x93D5
      area2.event_scratch0 = 1 & area1.event_word_376;  // 0x93CC
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x93D6
      }
      or(area1.event_word_376 = 1 | area1.event_word_376);  // 0x93D7
      setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x93E0
      exit_event();  // 0x93E7
    case 2: goto 0x821E;
      // case 2 body
      exit_event();  // 0x821E
    case 3: goto 0x821E;
      // case 3 body
      // target 0x821E already emitted
  }
}
```

## Event 20

- Target: `0x9422`
- Text hint: 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.' 'THIS CLASSROOM IS EMPTY.'

```text
event 20 {
  // 0x9422-0x9428
  if (mapDirection != 2) {
    exit_event();  // 0x9429
  }
  // 0x942A-0x9430
  if (area1.event_word_372 == 0) {
    goto 0x945A;  // 0x9431
    // branch body 0x945A
    printclear('THIS CLASSROOM IS EMPTY.');  // 0x945A
    // 0x9471-0x947A
    area2.event_scratch0 = 64 & area1.event_word_370;  // 0x9471
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x947B
    }
    // 0x947C-0x9485
    area2.event_scratch0 = 32 & area1.event_word_370;  // 0x947C
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9486
    }
    setup_monster(sprite_id: 255 max_distance: 0 pic_id: 255);  // 0x9487
    exit_event();  // 0x948E
  }
  printclear('THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.');  // 0x9435
  printclear('THIS CLASSROOM IS EMPTY.');  // 0x945A
  // 0x9471-0x947A
  area2.event_scratch0 = 64 & area1.event_word_370;  // 0x9471
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x947B
  }
  // 0x947C-0x9485
  area2.event_scratch0 = 32 & area1.event_word_370;  // 0x947C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9486
  }
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 255);  // 0x9487
  exit_event();  // 0x948E
}
```

## Event 21

- Target: `0x9471`
- Text hint: ' IS IN SESSION. THE PROFESSOR MOTIONS YOU OUT OF THE ROOM.' 'A PHYSICS LECTURE'

```text
event 21 {
  // 0x9471-0x947A
  area2.event_scratch0 = 64 & area1.event_word_370;  // 0x9471
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x947B
  }
  // 0x947C-0x9485
  area2.event_scratch0 = 32 & area1.event_word_370;  // 0x947C
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9486
  }
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 255);  // 0x9487
  exit_event();  // 0x948E
}
```

## Event 22

- Target: `0x955D`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 22 {
  // 0x955D-0x9563
  if (area1.event_word_372 != 1) {
    exit_event();  // 0x9564
  }
  // 0x9565-0x956E
  area2.event_scratch0 = 2 & area1.event_word_376;  // 0x9565
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x956F
  }
  or(area1.event_word_376 = 2 | area1.event_word_376);  // 0x9570
  area1.event_word_206 = 1;  // 0x9579
  setup_monster(sprite_id: 19 max_distance: 0 pic_id: 255);  // 0x957F
  exit_event();  // 0x9586
}
```

## Event 23

- Target: `0x9817`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 23 {
  // 0x9817-0x981D
  if (area1.event_word_206 != 1) {
    exit_event();  // 0x981E
  }
  // 0x981F-0x9825
  if (area1.event_word_208 != 0) {
    exit_event();  // 0x9826
  }
  // 0x9827-0x982D
  if (area1.event_word_208 == 2) {
    exit_event();  // 0x982E
  }
  exit_event();  // 0x9830
}
```

## Event 24

- Target: `0x9862`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 24 {
  // 0x9862-0x9868
  if (area1.event_word_206 != 1) {
    goto 0x829D;  // 0x9869
    // branch body 0x829D
    // 0x829D-0x82A3
    if (area1.event_word_372 == 2) {
      exit_event();  // 0x82A4
    }
    // 0x82A5-0x82AB
    if (area1.event_word_20E > 7) {
      add(area1.event_word_20E = 1 + area1.event_word_20E);  // 0x82AC
    }
    if_>(<if compare flag is false, skip next op>);  // 0x82B5
    exit_event();  // 0x82B6
  }
  // 0x986D-0x9873
  if (area1.event_word_208 != 0) {
    goto 0x829D;  // 0x9874
    // branch body 0x829D
    // target 0x829D already emitted
  }
  // 0x9878-0x987E
  if (area1.event_word_20A < 30) {
    goto 0x982F;  // 0x987F
    // branch body 0x982F
    exit_event();  // 0x9830
  }
  add(area1.event_word_20A = 1 + area1.event_word_20A);  // 0x9883
  exit_event();  // 0x988C
}
```

## Event 25

- Target: `0x988D`
- Text hint: 'YOU ENTER THE COMPUTER CORE. '

```text
event 25 {
  // 0x988D-0x9893
  if (mapDirection != 0) {
    exit_event();  // 0x9894
  }
  printclear('YOU ENTER THE COMPUTER CORE. ');  // 0x9895
  // 0x98AE-0x98B4
  if (area1.event_word_208 != 1) {
    exit_event();  // 0x98B5
  }
  print('IT IS WRECKED BY EXPLOSION.');  // 0x98B6
  // 0x98D0-0x98D6
  if (area1.event_word_206 != 1) {
    exit_event();  // 0x98D7
  }
  // 0x98D8-0x98DE
  if (area1.event_word_208 == 1) {
    exit_event();  // 0x98DF
  }
  // 0x98E0-0x98E6
  if (area1.event_word_208 == 0) {
    add(area1.event_word_20A = 1 + area1.event_word_20A);  // 0x98E7
  }
  // 0x98F0-0x98F6
  if (area1.event_word_20A == 31) {
    goto 0x98FC;  // 0x98F7
    // branch body 0x98FC
    exit_event();  // 0x98FD
  }
  exit_event();  // 0x98FB
}
```

## Event 26

- Target: `0x98D0`
- Text hint: 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?'

```text
event 26 {
  // 0x98D0-0x98D6
  if (area1.event_word_206 != 1) {
    exit_event();  // 0x98D7
  }
  // 0x98D8-0x98DE
  if (area1.event_word_208 == 1) {
    exit_event();  // 0x98DF
  }
  // 0x98E0-0x98E6
  if (area1.event_word_208 == 0) {
    add(area1.event_word_20A = 1 + area1.event_word_20A);  // 0x98E7
  }
  // 0x98F0-0x98F6
  if (area1.event_word_20A == 31) {
    goto 0x98FC;  // 0x98F7
    // branch body 0x98FC
    exit_event();  // 0x98FD
  }
  exit_event();  // 0x98FB
}
```

## Event 27

- Target: `0x992F`
- Text hint: 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?'

```text
event 27 {
  // 0x992F-0x9935
  if (area1.event_word_206 != 1) {
    exit_event();  // 0x9936
  }
  // 0x9937-0x993D
  if (area1.event_word_208 == 1) {
    exit_event();  // 0x993E
  }
  // 0x993F-0x9945
  if (area1.event_word_208 == 2) {
    exit_event();  // 0x9946
  }
  printclear('A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?');  // 0x9947
  // 0x9B35-0x9B3B
  if (mapDirection != 2) {
    exit_event();  // 0x9B3C
  }
  // 0x9B3D
  switch (area1.event_word_372) {
    case 0: goto 0x9B4F;
      // case 0 body
      printclear('YOU ENTER THE SCHOOL LIBRARY. STUDENTS MOVE ABOUT, MAKING USE OF THE IMPRESSIVE COLLECTION OF BOOKS.');  // 0x9B4F
      printclear('YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9B9F
      printclear('YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.');  // 0x9C12
      // 0x9C61-0x9C67
      if (area1.event_word_372 != 1) {
        exit_event();  // 0x9C68
      }
      // 0x9C69-0x9C72
      area2.event_scratch0 = 8 & area1.event_word_376;  // 0x9C69
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x9C73
      }
      or(area1.event_word_376 = 8 | area1.event_word_376);  // 0x9C74
      printclear('THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.');  // 0x9C7D
      // 0x9CB6-0x9CBC
      if (mapDirection != 2) {
        exit_event();  // 0x9CBD
      }
      printclear('YOU ENTER THE MAIN SECTION OF THE LIBRARY');  // 0x9CBE
      // 0x9CE0
      switch (area1.event_word_372) {
        case 0: goto 0x9CF2;
          // case 0 body
          print('. IT IS CROWDED WITH ACADEMIC ACTIVITY.');  // 0x9CF2
          // 0x9D15-0x9D1E
          area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
          if (area2.event_scratch0 != 0) {
            goto 0x9E6F;  // 0x9D1F
            // branch body 0x9E6F
            print('. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9E6F
            // 0x9E8C-0x9E92
            if (mapDirection != 3) {
              exit_event();  // 0x9E93
            }
            printclear('YOU ENTER THE LIBRARY ANNEX');  // 0x9E94
            // 0x9EAC
            switch (area1.event_word_372) {
              case 0: goto 0x9CF2;
              case 1: goto 0x9EBE;
              case 2: goto 0xA06B;
              case 3: goto 0xA06B;
            }
          }
          or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
          exit_event();  // 0x9D2D
        case 1: goto 0x9D15;
          // case 1 body
          // 0x9D15-0x9D1E
          area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
          if (area2.event_scratch0 != 0) {
            goto 0x9E6F;  // 0x9D1F
            // branch body 0x9E6F
            // target 0x9E6F already emitted
          }
          or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
          exit_event();  // 0x9D2D
        case 2: goto 0x9E6F;
          // case 2 body
          // target 0x9E6F already emitted
        case 3: goto 0x9E6F;
          // case 3 body
          // target 0x9E6F already emitted
      }
    case 1: goto 0x9B9F;
      // case 1 body
      printclear('YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9B9F
      printclear('YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.');  // 0x9C12
      // 0x9C61-0x9C67
      if (area1.event_word_372 != 1) {
        exit_event();  // 0x9C68
      }
      // 0x9C69-0x9C72
      area2.event_scratch0 = 8 & area1.event_word_376;  // 0x9C69
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x9C73
      }
      or(area1.event_word_376 = 8 | area1.event_word_376);  // 0x9C74
      printclear('THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.');  // 0x9C7D
      // 0x9CB6-0x9CBC
      if (mapDirection != 2) {
        exit_event();  // 0x9CBD
      }
    case 2: goto 0x9B9F;
    case 3: goto 0x9C12;
  }
}
```

## Event 28

- Target: `0x821E`
- Text hint: 'A GROUP OF STUDENTS RUSH BY TALKING ABOUT '

```text
event 28 {
  exit_event();  // 0x821E
}
```

## Event 29

- Target: `0x9B35`
- Text hint: 'YOU ENTER THE SCHOOL LIBRARY. STUDENTS MOVE ABOUT, MAKING USE OF THE IMPRESSIVE COLLECTION OF BOOKS.' 'YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.' 'YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.'

```text
event 29 {
  // 0x9B35-0x9B3B
  if (mapDirection != 2) {
    exit_event();  // 0x9B3C
  }
  // 0x9B3D
  switch (area1.event_word_372) {
    case 0: goto 0x9B4F;
      // case 0 body
      printclear('YOU ENTER THE SCHOOL LIBRARY. STUDENTS MOVE ABOUT, MAKING USE OF THE IMPRESSIVE COLLECTION OF BOOKS.');  // 0x9B4F
      printclear('YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9B9F
      printclear('YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.');  // 0x9C12
      // 0x9C61-0x9C67
      if (area1.event_word_372 != 1) {
        exit_event();  // 0x9C68
      }
      // 0x9C69-0x9C72
      area2.event_scratch0 = 8 & area1.event_word_376;  // 0x9C69
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x9C73
      }
      or(area1.event_word_376 = 8 | area1.event_word_376);  // 0x9C74
      printclear('THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.');  // 0x9C7D
      // 0x9CB6-0x9CBC
      if (mapDirection != 2) {
        exit_event();  // 0x9CBD
      }
      printclear('YOU ENTER THE MAIN SECTION OF THE LIBRARY');  // 0x9CBE
      // 0x9CE0
      switch (area1.event_word_372) {
        case 0: goto 0x9CF2;
          // case 0 body
          print('. IT IS CROWDED WITH ACADEMIC ACTIVITY.');  // 0x9CF2
          // 0x9D15-0x9D1E
          area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
          if (area2.event_scratch0 != 0) {
            goto 0x9E6F;  // 0x9D1F
            // branch body 0x9E6F
            print('. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9E6F
            // 0x9E8C-0x9E92
            if (mapDirection != 3) {
              exit_event();  // 0x9E93
            }
            printclear('YOU ENTER THE LIBRARY ANNEX');  // 0x9E94
            // 0x9EAC
            switch (area1.event_word_372) {
              case 0: goto 0x9CF2;
              case 1: goto 0x9EBE;
              case 2: goto 0xA06B;
              case 3: goto 0xA06B;
            }
          }
          or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
          exit_event();  // 0x9D2D
        case 1: goto 0x9D15;
          // case 1 body
          // 0x9D15-0x9D1E
          area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
          if (area2.event_scratch0 != 0) {
            goto 0x9E6F;  // 0x9D1F
            // branch body 0x9E6F
            // target 0x9E6F already emitted
          }
          or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
          exit_event();  // 0x9D2D
        case 2: goto 0x9E6F;
          // case 2 body
          // target 0x9E6F already emitted
        case 3: goto 0x9E6F;
          // case 3 body
          // target 0x9E6F already emitted
      }
    case 1: goto 0x9B9F;
      // case 1 body
      printclear('YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9B9F
      printclear('YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.');  // 0x9C12
      // 0x9C61-0x9C67
      if (area1.event_word_372 != 1) {
        exit_event();  // 0x9C68
      }
      // 0x9C69-0x9C72
      area2.event_scratch0 = 8 & area1.event_word_376;  // 0x9C69
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x9C73
      }
      or(area1.event_word_376 = 8 | area1.event_word_376);  // 0x9C74
      printclear('THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.');  // 0x9C7D
      // 0x9CB6-0x9CBC
      if (mapDirection != 2) {
        exit_event();  // 0x9CBD
      }
      printclear('YOU ENTER THE MAIN SECTION OF THE LIBRARY');  // 0x9CBE
      // 0x9CE0
      switch (area1.event_word_372) {
        case 0: goto 0x9CF2;
          // case 0 body
          // target 0x9CF2 already emitted
        case 1: goto 0x9D15;
          // case 1 body
          // target 0x9D15 already emitted
        case 2: goto 0x9E6F;
        case 3: goto 0x9E6F;
      }
    case 2: goto 0x9B9F;
    case 3: goto 0x9C12;
  }
}
```

## Event 30

- Target: `0x9C61`
- Text hint: 'THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.'

```text
event 30 {
  // 0x9C61-0x9C67
  if (area1.event_word_372 != 1) {
    exit_event();  // 0x9C68
  }
  // 0x9C69-0x9C72
  area2.event_scratch0 = 8 & area1.event_word_376;  // 0x9C69
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9C73
  }
  or(area1.event_word_376 = 8 | area1.event_word_376);  // 0x9C74
  printclear('THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.');  // 0x9C7D
  // 0x9CB6-0x9CBC
  if (mapDirection != 2) {
    exit_event();  // 0x9CBD
  }
  printclear('YOU ENTER THE MAIN SECTION OF THE LIBRARY');  // 0x9CBE
  // 0x9CE0
  switch (area1.event_word_372) {
    case 0: goto 0x9CF2;
      // case 0 body
      print('. IT IS CROWDED WITH ACADEMIC ACTIVITY.');  // 0x9CF2
      // 0x9D15-0x9D1E
      area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
      if (area2.event_scratch0 != 0) {
        goto 0x9E6F;  // 0x9D1F
        // branch body 0x9E6F
        print('. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9E6F
        // 0x9E8C-0x9E92
        if (mapDirection != 3) {
          exit_event();  // 0x9E93
        }
        printclear('YOU ENTER THE LIBRARY ANNEX');  // 0x9E94
        // 0x9EAC
        switch (area1.event_word_372) {
          case 0: goto 0x9CF2;
          case 1: goto 0x9EBE;
          case 2: goto 0xA06B;
          case 3: goto 0xA06B;
        }
      }
      or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
      exit_event();  // 0x9D2D
    case 1: goto 0x9D15;
      // case 1 body
      // 0x9D15-0x9D1E
      area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
      if (area2.event_scratch0 != 0) {
        goto 0x9E6F;  // 0x9D1F
        // branch body 0x9E6F
        // target 0x9E6F already emitted
      }
      or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
      exit_event();  // 0x9D2D
    case 2: goto 0x9E6F;
      // case 2 body
      // target 0x9E6F already emitted
    case 3: goto 0x9E6F;
      // case 3 body
      // target 0x9E6F already emitted
  }
}
```

## Event 31

- Target: `0x9CB6`
- Text hint: 'YOU ENTER THE MAIN SECTION OF THE LIBRARY'

```text
event 31 {
  // 0x9CB6-0x9CBC
  if (mapDirection != 2) {
    exit_event();  // 0x9CBD
  }
  printclear('YOU ENTER THE MAIN SECTION OF THE LIBRARY');  // 0x9CBE
  // 0x9CE0
  switch (area1.event_word_372) {
    case 0: goto 0x9CF2;
      // case 0 body
      print('. IT IS CROWDED WITH ACADEMIC ACTIVITY.');  // 0x9CF2
      // 0x9D15-0x9D1E
      area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
      if (area2.event_scratch0 != 0) {
        goto 0x9E6F;  // 0x9D1F
        // branch body 0x9E6F
        print('. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9E6F
        // 0x9E8C-0x9E92
        if (mapDirection != 3) {
          exit_event();  // 0x9E93
        }
        printclear('YOU ENTER THE LIBRARY ANNEX');  // 0x9E94
        // 0x9EAC
        switch (area1.event_word_372) {
          case 0: goto 0x9CF2;
          case 1: goto 0x9EBE;
          case 2: goto 0xA06B;
          case 3: goto 0xA06B;
        }
      }
      or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
      exit_event();  // 0x9D2D
    case 1: goto 0x9D15;
      // case 1 body
      // 0x9D15-0x9D1E
      area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
      if (area2.event_scratch0 != 0) {
        goto 0x9E6F;  // 0x9D1F
        // branch body 0x9E6F
        // target 0x9E6F already emitted
      }
      or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
      exit_event();  // 0x9D2D
    case 2: goto 0x9E6F;
      // case 2 body
      // target 0x9E6F already emitted
    case 3: goto 0x9E6F;
      // case 3 body
      // target 0x9E6F already emitted
  }
}
```

## Event 32

- Target: `0x9E8C`
- Text hint: 'YOU ENTER THE LIBRARY ANNEX'

```text
event 32 {
  // 0x9E8C-0x9E92
  if (mapDirection != 3) {
    exit_event();  // 0x9E93
  }
  printclear('YOU ENTER THE LIBRARY ANNEX');  // 0x9E94
  // 0x9EAC
  switch (area1.event_word_372) {
    case 0: goto 0x9CF2;
      // case 0 body
      print('. IT IS CROWDED WITH ACADEMIC ACTIVITY.');  // 0x9CF2
      // 0x9D15-0x9D1E
      area2.event_scratch0 = 16 & area1.event_word_376;  // 0x9D15
      if (area2.event_scratch0 != 0) {
        goto 0x9E6F;  // 0x9D1F
        // branch body 0x9E6F
        print('. IT HAS BEEN GUTTED BY FLAMES.');  // 0x9E6F
        // 0x9E8C-0x9E92
        if (mapDirection != 3) {
          exit_event();  // 0x9E93
        }
        printclear('YOU ENTER THE LIBRARY ANNEX');  // 0x9E94
        // 0x9EAC
        switch (area1.event_word_372) {
          case 0: goto 0x9CF2;
          case 1: goto 0x9EBE;
          case 2: goto 0xA06B;
          case 3: goto 0xA06B;
        }
      }
      or(area1.event_word_376 = 16 | area1.event_word_376);  // 0x9D23
      exit_event();  // 0x9D2D
    case 1: goto 0x9EBE;
      // case 1 body
      // 0x9EBE-0x9EC7
      area2.event_scratch0 = 32 & area1.event_word_376;  // 0x9EBE
      if (area2.event_scratch0 != 0) {
        goto 0xA06B;  // 0x9EC8
        // branch body 0xA06B
        // 0xA06B-0xA074
        area2.event_scratch0 = 64 & area1.event_word_376;  // 0xA06B
        if (area2.event_scratch0 != 0) {
          goto 0x9E6F;  // 0xA075
          // branch body 0x9E6F
          // target 0x9E6F already emitted
        }
        print('. DUE TO YOUR EFFORTS, IT IS INTACT.');  // 0xA079
        compare_and(Values: 1 == area1.event_word_372 && 0 == mapDirection);  // 0xA099
        if_<>(<if compare flag is false, skip next op>);  // 0xA0A4
        exit_event();  // 0xA0A5
      }
      or(area1.event_word_376 = 32 | area1.event_word_376);  // 0x9ECC
      print(". A SMALL FIRE IS BURNING IN THIS ROOM, AND IT'S BEGINNING TO SPREAD.");  // 0x9ED5
      // 0xA06B-0xA074
      area2.event_scratch0 = 64 & area1.event_word_376;  // 0xA06B
      if (area2.event_scratch0 != 0) {
        goto 0x9E6F;  // 0xA075
        // branch body 0x9E6F
        // target 0x9E6F already emitted
      }
      print('. DUE TO YOUR EFFORTS, IT IS INTACT.');  // 0xA079
      compare_and(Values: 1 == area1.event_word_372 && 0 == mapDirection);  // 0xA099
      if_<>(<if compare flag is false, skip next op>);  // 0xA0A4
      exit_event();  // 0xA0A5
    case 2: goto 0xA06B;
      // case 2 body
      // target 0xA06B already emitted
    case 3: goto 0xA06B;
      // case 3 body
      // target 0xA06B already emitted
  }
}
```

## Event 33

- Target: `0xA099`
- Text hint: 'YOU ENTER THE OFFICE OF CONTINUING EDUCATION.'

```text
event 33 {
  compare_and(Values: 1 == area1.event_word_372 && 0 == mapDirection);  // 0xA099
  if_<>(<if compare flag is false, skip next op>);  // 0xA0A4
  exit_event();  // 0xA0A5
}
```

## Event 34

- Target: `0x821E`
- Text hint: 'A GROUP OF STUDENTS RUSH BY TALKING ABOUT '

```text
event 34 {
  exit_event();  // 0x821E
}
```

## Event 35

- Target: `0xA0C1`
- Text hint: 'YOU ENTER THE OFFICE OF CONTINUING EDUCATION.'

```text
event 35 {
  // 0xA0C1-0xA0C7
  if (mapDirection != 0) {
    exit_event();  // 0xA0C8
  }
  // 0xA0C9-0xA0CF
  if (area1.event_word_372 == 1) {
    exit_event();  // 0xA0D0
  }
  // 0xA0D1-0xA0D7
  if (area1.event_word_372 == 2) {
    exit_event();  // 0xA0D8
  }
  printclear('YOU ENTER THE OFFICE OF CONTINUING EDUCATION.');  // 0xA0D9
  // 0xA119-0xA11F
  if (area1.event_word_372 == 1) {
    exit_event();  // 0xA120
  }
  printclear('YOU ENTER A STORE.');  // 0xA121
  area2.word_6DA = 32;  // 0xA132
  area2.word_7EC = 1;  // 0xA138
  exit_event();  // 0xA13F
}
```

## Event 36

- Target: `0xA119`
- Text hint: 'YOU ENTER A STORE.'

```text
event 36 {
  // 0xA119-0xA11F
  if (area1.event_word_372 == 1) {
    exit_event();  // 0xA120
  }
  printclear('YOU ENTER A STORE.');  // 0xA121
  area2.word_6DA = 32;  // 0xA132
  area2.word_7EC = 1;  // 0xA138
  exit_event();  // 0xA13F
}
```
