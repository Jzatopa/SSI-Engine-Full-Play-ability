# GEO 82: NEO Installation

ECL block: `82`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 01 {
  exit_event();  // 0x852F
}
```

## Event 02

- Target: `0x867D`
- Text hint: 'AN ELEVATOR. DO YOU USE IT?'

```text
event 02 {
  printclear('AN ELEVATOR. DO YOU USE IT?');  // 0x867D
  // 0x87DF-0x87E5
  if (1 != area1.event_word_352) {
    exit_event();  // 0x87E6
  }
  // 0x87E7-0x87F0
  area2.event_scratch0 = 64 & area1.event_word_34E;  // 0x87E7
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x87F1
  }
  or(area1.event_word_34E = 64 | area1.event_word_34E);  // 0x87F2
  printclear("YOU FIND A BADLY INJURED MAN IN THE CORNER OF THE ROOM. 'PLEASE TAKE MY ARMOR... PUT IT TO GOOD USE.'");  // 0x87FB
  // 0x8855-0x885E
  area2.event_scratch0 = 8 & area1.event_word_348;  // 0x8855
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x885F
  }
  or(area1.event_word_348 = 8 | area1.event_word_348);  // 0x8860
  // 0x8869-0x8872
  area2.event_scratch0 = 16 & area1.event_word_348;  // 0x8869
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8873
  }
  printclear("A MAN WALKS UP. 'I HEARD ABOUT YOUR CONVERSATION WITH DR. HAMPSHIRE. THIS WEAPON MAY HELP YOUR INQUIRIES.'");  // 0x8874
  // 0x88D2-0x88DB
  area2.event_scratch0 = 32 & area1.event_word_348;  // 0x88D2
  if (area2.event_scratch0 != 0) {
    goto 0x8962;  // 0x88DC
    // branch body 0x8962
    printclear("'I AM BUSY RIGHT NOW.'");  // 0x8962
    // 0x8978-0x8981
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8978
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8982
    }
    // 0x8983-0x8989
    if (4 == area1.event_word_350) {
      exit_event();  // 0x898A
    }
    printclear('YOU FIND A SET OF CODE 4 CARDS.');  // 0x898B
    // 0x89AE-0x89B7
    area2.event_scratch0 = 16 & area1.event_word_348;  // 0x89AE
    if (area2.event_scratch0 != 0) {
      goto 0x8AEB;  // 0x89B8
      // branch body 0x8AEB
      printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
      // 0x8B0E-0x8B17
      area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8B18
      }
      printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
      // 0x8C22-0x8C2B
      area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C2C
      }
      // 0x8C2D-0x8C36
      area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C37
      }
      // 0x8C38-0x8C41
      area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C42
      }
      // 0x8C43-0x8C4C
      area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C4D
      }
      printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
      print_return();  // 0x8C7C
      print("'ARE YOU ZACHARY?'");  // 0x8C7D
      horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
      // 0x8CAA-0x8CB0
      if (1 == area2.event_scratch0) {
        goto 0x8DD1;  // 0x8CB1
        // branch body 0x8DD1
        printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
        exit_event();  // 0x8F6F
      }
      who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
      // 0x8CC9-0x8CCF
      if (1 != area2.selected_player_in_combat) {
        goto 0x8CB5;  // 0x8CD0
        // branch body 0x8CB5
        who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
        // 0x8CC9-0x8CCF
        if (1 != area2.selected_player_in_combat) {
          goto 0x8CB5;  // 0x8CD0
        }
        area2.event_scratch0 = 0;  // 0x8CD4
        area2.event_scratch1 = 3;  // 0x8CDA
        party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
        // 0x8CE9-0x8CEF
        if (2 < area2.event_scratch1) {
          goto 0x8DD1;  // 0x8CF0
        }
      }
    }
  }
}
```

## Event 03

- Target: `0x87DF`
- Text hint: "YOU FIND A BADLY INJURED MAN IN THE CORNER OF THE ROOM. 'PLEASE TAKE MY ARMOR... PUT IT TO GOOD USE.'"

```text
event 03 {
  // 0x87DF-0x87E5
  if (1 != area1.event_word_352) {
    exit_event();  // 0x87E6
  }
  // 0x87E7-0x87F0
  area2.event_scratch0 = 64 & area1.event_word_34E;  // 0x87E7
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x87F1
  }
  or(area1.event_word_34E = 64 | area1.event_word_34E);  // 0x87F2
  printclear("YOU FIND A BADLY INJURED MAN IN THE CORNER OF THE ROOM. 'PLEASE TAKE MY ARMOR... PUT IT TO GOOD USE.'");  // 0x87FB
  // 0x8855-0x885E
  area2.event_scratch0 = 8 & area1.event_word_348;  // 0x8855
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x885F
  }
  or(area1.event_word_348 = 8 | area1.event_word_348);  // 0x8860
  // 0x8869-0x8872
  area2.event_scratch0 = 16 & area1.event_word_348;  // 0x8869
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8873
  }
  printclear("A MAN WALKS UP. 'I HEARD ABOUT YOUR CONVERSATION WITH DR. HAMPSHIRE. THIS WEAPON MAY HELP YOUR INQUIRIES.'");  // 0x8874
  // 0x88D2-0x88DB
  area2.event_scratch0 = 32 & area1.event_word_348;  // 0x88D2
  if (area2.event_scratch0 != 0) {
    goto 0x8962;  // 0x88DC
    // branch body 0x8962
    printclear("'I AM BUSY RIGHT NOW.'");  // 0x8962
    // 0x8978-0x8981
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8978
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8982
    }
    // 0x8983-0x8989
    if (4 == area1.event_word_350) {
      exit_event();  // 0x898A
    }
    printclear('YOU FIND A SET OF CODE 4 CARDS.');  // 0x898B
    // 0x89AE-0x89B7
    area2.event_scratch0 = 16 & area1.event_word_348;  // 0x89AE
    if (area2.event_scratch0 != 0) {
      goto 0x8AEB;  // 0x89B8
      // branch body 0x8AEB
      printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
      // 0x8B0E-0x8B17
      area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8B18
      }
      printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
      // 0x8C22-0x8C2B
      area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C2C
      }
      // 0x8C2D-0x8C36
      area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C37
      }
      // 0x8C38-0x8C41
      area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C42
      }
      // 0x8C43-0x8C4C
      area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C4D
      }
      printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
      print_return();  // 0x8C7C
      print("'ARE YOU ZACHARY?'");  // 0x8C7D
      horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
      // 0x8CAA-0x8CB0
      if (1 == area2.event_scratch0) {
        goto 0x8DD1;  // 0x8CB1
        // branch body 0x8DD1
        printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
        exit_event();  // 0x8F6F
      }
      who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
      // 0x8CC9-0x8CCF
      if (1 != area2.selected_player_in_combat) {
        goto 0x8CB5;  // 0x8CD0
        // branch body 0x8CB5
        who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
        // 0x8CC9-0x8CCF
        if (1 != area2.selected_player_in_combat) {
          goto 0x8CB5;  // 0x8CD0
        }
        area2.event_scratch0 = 0;  // 0x8CD4
        area2.event_scratch1 = 3;  // 0x8CDA
        party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
        // 0x8CE9-0x8CEF
        if (2 < area2.event_scratch1) {
          goto 0x8DD1;  // 0x8CF0
        }
        printclear("'TELL US THE WORD:'");  // 0x8CF4
      }
    }
  }
}
```

## Event 04

- Target: `0x8855`
- Text hint: "A MAN WALKS UP. 'I HEARD ABOUT YOUR CONVERSATION WITH DR. HAMPSHIRE. THIS WEAPON MAY HELP YOUR INQUIRIES.'"

```text
event 04 {
  // 0x8855-0x885E
  area2.event_scratch0 = 8 & area1.event_word_348;  // 0x8855
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x885F
  }
  or(area1.event_word_348 = 8 | area1.event_word_348);  // 0x8860
  // 0x8869-0x8872
  area2.event_scratch0 = 16 & area1.event_word_348;  // 0x8869
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8873
  }
  printclear("A MAN WALKS UP. 'I HEARD ABOUT YOUR CONVERSATION WITH DR. HAMPSHIRE. THIS WEAPON MAY HELP YOUR INQUIRIES.'");  // 0x8874
  // 0x88D2-0x88DB
  area2.event_scratch0 = 32 & area1.event_word_348;  // 0x88D2
  if (area2.event_scratch0 != 0) {
    goto 0x8962;  // 0x88DC
    // branch body 0x8962
    printclear("'I AM BUSY RIGHT NOW.'");  // 0x8962
    // 0x8978-0x8981
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8978
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8982
    }
    // 0x8983-0x8989
    if (4 == area1.event_word_350) {
      exit_event();  // 0x898A
    }
    printclear('YOU FIND A SET OF CODE 4 CARDS.');  // 0x898B
    // 0x89AE-0x89B7
    area2.event_scratch0 = 16 & area1.event_word_348;  // 0x89AE
    if (area2.event_scratch0 != 0) {
      goto 0x8AEB;  // 0x89B8
      // branch body 0x8AEB
      printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
      // 0x8B0E-0x8B17
      area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8B18
      }
      printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
      // 0x8C22-0x8C2B
      area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C2C
      }
      // 0x8C2D-0x8C36
      area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C37
      }
      // 0x8C38-0x8C41
      area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C42
      }
      // 0x8C43-0x8C4C
      area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C4D
      }
      printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
      print_return();  // 0x8C7C
      print("'ARE YOU ZACHARY?'");  // 0x8C7D
      horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
      // 0x8CAA-0x8CB0
      if (1 == area2.event_scratch0) {
        goto 0x8DD1;  // 0x8CB1
        // branch body 0x8DD1
        printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
        exit_event();  // 0x8F6F
      }
      who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
      // 0x8CC9-0x8CCF
      if (1 != area2.selected_player_in_combat) {
        goto 0x8CB5;  // 0x8CD0
        // branch body 0x8CB5
        who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
        // 0x8CC9-0x8CCF
        if (1 != area2.selected_player_in_combat) {
          goto 0x8CB5;  // 0x8CD0
        }
        area2.event_scratch0 = 0;  // 0x8CD4
        area2.event_scratch1 = 3;  // 0x8CDA
        party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
        // 0x8CE9-0x8CEF
        if (2 < area2.event_scratch1) {
          goto 0x8DD1;  // 0x8CF0
        }
        printclear("'TELL US THE WORD:'");  // 0x8CF4
        input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
        // 0x8D0C-0x8D16
        if (32633 != abs_0004) {
          goto 0x8DD1;  // 0x8D17
        }
        exit_event();  // 0x8D1C
      }
      area2.event_scratch0 = 0;  // 0x8CD4
      area2.event_scratch1 = 3;  // 0x8CDA
      party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
      // 0x8CE9-0x8CEF
      if (2 < area2.event_scratch1) {
        goto 0x8DD1;  // 0x8CF0
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
    }
  }
}
```

## Event 05

- Target: `0x88D2`
- Text hint: "A VOLUBLE, BESPECKLED MAN GREETS YOU ENTHUSIASTICALLY. 'WHAT DO YOU HAVE WITH YOU. HMM, NON-NEO DESIGN. SEE DR. HAMPSHIRE, HE'S AN EXPERT IN ELECTRONICS.'" "'I AM BUSY RIGHT NOW.'"

```text
event 05 {
  // 0x88D2-0x88DB
  area2.event_scratch0 = 32 & area1.event_word_348;  // 0x88D2
  if (area2.event_scratch0 != 0) {
    goto 0x8962;  // 0x88DC
    // branch body 0x8962
    printclear("'I AM BUSY RIGHT NOW.'");  // 0x8962
    // 0x8978-0x8981
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8978
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8982
    }
    // 0x8983-0x8989
    if (4 == area1.event_word_350) {
      exit_event();  // 0x898A
    }
    printclear('YOU FIND A SET OF CODE 4 CARDS.');  // 0x898B
    // 0x89AE-0x89B7
    area2.event_scratch0 = 16 & area1.event_word_348;  // 0x89AE
    if (area2.event_scratch0 != 0) {
      goto 0x8AEB;  // 0x89B8
      // branch body 0x8AEB
      printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
      // 0x8B0E-0x8B17
      area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8B18
      }
      printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
      // 0x8C22-0x8C2B
      area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C2C
      }
      // 0x8C2D-0x8C36
      area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
      if (area2.event_scratch0 != 0) {
        exit_event();  // 0x8C37
      }
      // 0x8C38-0x8C41
      area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C42
      }
      // 0x8C43-0x8C4C
      area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
      if (area2.event_scratch0 == 0) {
        exit_event();  // 0x8C4D
      }
      printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
      print_return();  // 0x8C7C
      print("'ARE YOU ZACHARY?'");  // 0x8C7D
      horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
      // 0x8CAA-0x8CB0
      if (1 == area2.event_scratch0) {
        goto 0x8DD1;  // 0x8CB1
        // branch body 0x8DD1
        printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
        exit_event();  // 0x8F6F
      }
      who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
      // 0x8CC9-0x8CCF
      if (1 != area2.selected_player_in_combat) {
        goto 0x8CB5;  // 0x8CD0
        // branch body 0x8CB5
        who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
        // 0x8CC9-0x8CCF
        if (1 != area2.selected_player_in_combat) {
          goto 0x8CB5;  // 0x8CD0
        }
        area2.event_scratch0 = 0;  // 0x8CD4
        area2.event_scratch1 = 3;  // 0x8CDA
        party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
        // 0x8CE9-0x8CEF
        if (2 < area2.event_scratch1) {
          goto 0x8DD1;  // 0x8CF0
        }
        printclear("'TELL US THE WORD:'");  // 0x8CF4
        input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
        // 0x8D0C-0x8D16
        if (32633 != abs_0004) {
          goto 0x8DD1;  // 0x8D17
        }
        exit_event();  // 0x8D1C
      }
      area2.event_scratch0 = 0;  // 0x8CD4
      area2.event_scratch1 = 3;  // 0x8CDA
      party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
      // 0x8CE9-0x8CEF
      if (2 < area2.event_scratch1) {
        goto 0x8DD1;  // 0x8CF0
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
      printclear("'TELL US THE WORD:'");  // 0x8CF4
      input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
      // 0x8D0C-0x8D16
      if (32633 != abs_0004) {
        goto 0x8DD1;  // 0x8D17
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
    }
  }
}
```

## Event 06

- Target: `0x8978`
- Text hint: 'YOU FIND A SET OF CODE 4 CARDS.'

```text
event 06 {
  // 0x8978-0x8981
  area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8978
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8982
  }
  // 0x8983-0x8989
  if (4 == area1.event_word_350) {
    exit_event();  // 0x898A
  }
  printclear('YOU FIND A SET OF CODE 4 CARDS.');  // 0x898B
  // 0x89AE-0x89B7
  area2.event_scratch0 = 16 & area1.event_word_348;  // 0x89AE
  if (area2.event_scratch0 != 0) {
    goto 0x8AEB;  // 0x89B8
    // branch body 0x8AEB
    printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
    // 0x8B0E-0x8B17
    area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8B18
    }
    printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
    // 0x8C22-0x8C2B
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8C2C
    }
    // 0x8C2D-0x8C36
    area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8C37
    }
    // 0x8C38-0x8C41
    area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8C42
    }
    // 0x8C43-0x8C4C
    area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8C4D
    }
    printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
    print_return();  // 0x8C7C
    print("'ARE YOU ZACHARY?'");  // 0x8C7D
    horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
    // 0x8CAA-0x8CB0
    if (1 == area2.event_scratch0) {
      goto 0x8DD1;  // 0x8CB1
      // branch body 0x8DD1
      printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
      exit_event();  // 0x8F6F
    }
    who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
    // 0x8CC9-0x8CCF
    if (1 != area2.selected_player_in_combat) {
      goto 0x8CB5;  // 0x8CD0
      // branch body 0x8CB5
      who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
      // 0x8CC9-0x8CCF
      if (1 != area2.selected_player_in_combat) {
        goto 0x8CB5;  // 0x8CD0
        // branch body 0x8CB5
        // target 0x8CB5 already emitted
      }
      area2.event_scratch0 = 0;  // 0x8CD4
      area2.event_scratch1 = 3;  // 0x8CDA
      party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
      // 0x8CE9-0x8CEF
      if (2 < area2.event_scratch1) {
        goto 0x8DD1;  // 0x8CF0
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
      printclear("'TELL US THE WORD:'");  // 0x8CF4
      input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
      // 0x8D0C-0x8D16
      if (32633 != abs_0004) {
        goto 0x8DD1;  // 0x8D17
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
      exit_event();  // 0x8D1C
    }
    area2.event_scratch0 = 0;  // 0x8CD4
    area2.event_scratch1 = 3;  // 0x8CDA
    party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
    // 0x8CE9-0x8CEF
    if (2 < area2.event_scratch1) {
      goto 0x8DD1;  // 0x8CF0
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    printclear("'TELL US THE WORD:'");  // 0x8CF4
    input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
    // 0x8D0C-0x8D16
    if (32633 != abs_0004) {
      goto 0x8DD1;  // 0x8D17
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
  }
}
```

## Event 07

- Target: `0x9D61`
- Text hint: "THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD." "THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'"

```text
event 07 {
  // 0x9D61-0x9D6A
  area2.event_scratch0 = 8 & area1.event_word_34E;  // 0x9D61
  if (area2.event_scratch0 == 0) {
    goto 0x9E5F;  // 0x9D6B
    // branch body 0x9E5F
    printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
    // 0x9E94-0x9E9D
    area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
    if (area2.event_scratch0 == 0) {
      goto 0x9EEA;  // 0x9E9E
      // branch body 0x9EEA
      printclear('THIS IS THE EMERGENCY HATCH.');  // 0x9EEA
      exit_event();  // 0x9F02
    }
    exit_event();  // 0x9EA3
  }
  // 0x9D6F-0x9D78
  area2.event_scratch0 = 16 & area1.event_word_34E;  // 0x9D6F
  if (area2.event_scratch0 != 0) {
    goto 0x9E5F;  // 0x9D79
    // branch body 0x9E5F
    // target 0x9E5F already emitted
  }
  printclear("THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD.");  // 0x9D7D
  printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
  // 0x9E94-0x9E9D
  area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
  if (area2.event_scratch0 == 0) {
    goto 0x9EEA;  // 0x9E9E
    // branch body 0x9EEA
    // target 0x9EEA already emitted
  }
  exit_event();  // 0x9EA3
}
```

## Event 09

- Target: `0x89AE`
- Text hint: "AN ELDERLY FELLOW RISES AT YOUR APPROACH. 'I AM DR. HAMPSHIRE. LET ME SEE THE DEVICE.'" "'I ALREADY TOLD YOU EVERYTHING I KNOW.'"

```text
event 09 {
  // 0x89AE-0x89B7
  area2.event_scratch0 = 16 & area1.event_word_348;  // 0x89AE
  if (area2.event_scratch0 != 0) {
    goto 0x8AEB;  // 0x89B8
    // branch body 0x8AEB
    printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
    // 0x8B0E-0x8B17
    area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8B18
    }
    printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
    // 0x8C22-0x8C2B
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8C2C
    }
    // 0x8C2D-0x8C36
    area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8C37
    }
    // 0x8C38-0x8C41
    area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8C42
    }
    // 0x8C43-0x8C4C
    area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x8C4D
    }
    printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
    print_return();  // 0x8C7C
    print("'ARE YOU ZACHARY?'");  // 0x8C7D
    horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
    // 0x8CAA-0x8CB0
    if (1 == area2.event_scratch0) {
      goto 0x8DD1;  // 0x8CB1
      // branch body 0x8DD1
      printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
      exit_event();  // 0x8F6F
    }
    who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
    // 0x8CC9-0x8CCF
    if (1 != area2.selected_player_in_combat) {
      goto 0x8CB5;  // 0x8CD0
      // branch body 0x8CB5
      who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
      // 0x8CC9-0x8CCF
      if (1 != area2.selected_player_in_combat) {
        goto 0x8CB5;  // 0x8CD0
        // branch body 0x8CB5
        // target 0x8CB5 already emitted
      }
      area2.event_scratch0 = 0;  // 0x8CD4
      area2.event_scratch1 = 3;  // 0x8CDA
      party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
      // 0x8CE9-0x8CEF
      if (2 < area2.event_scratch1) {
        goto 0x8DD1;  // 0x8CF0
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
      printclear("'TELL US THE WORD:'");  // 0x8CF4
      input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
      // 0x8D0C-0x8D16
      if (32633 != abs_0004) {
        goto 0x8DD1;  // 0x8D17
        // branch body 0x8DD1
        // target 0x8DD1 already emitted
      }
      exit_event();  // 0x8D1C
    }
    area2.event_scratch0 = 0;  // 0x8CD4
    area2.event_scratch1 = 3;  // 0x8CDA
    party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
    // 0x8CE9-0x8CEF
    if (2 < area2.event_scratch1) {
      goto 0x8DD1;  // 0x8CF0
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    printclear("'TELL US THE WORD:'");  // 0x8CF4
    input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
    // 0x8D0C-0x8D16
    if (32633 != abs_0004) {
      goto 0x8DD1;  // 0x8D17
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    exit_event();  // 0x8D1C
  }
  printclear("AN ELDERLY FELLOW RISES AT YOUR APPROACH. 'I AM DR. HAMPSHIRE. LET ME SEE THE DEVICE.'");  // 0x89BC
  printclear("'I ALREADY TOLD YOU EVERYTHING I KNOW.'");  // 0x8AEB
  // 0x8B0E-0x8B17
  area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8B18
  }
}
```

## Event 10

- Target: `0x8B0E`
- Text hint: "YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'."

```text
event 10 {
  // 0x8B0E-0x8B17
  area2.event_scratch0 = 16 & area1.event_word_34A;  // 0x8B0E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8B18
  }
  printclear("YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'.");  // 0x8B19
  // 0x8C22-0x8C2B
  area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C2C
  }
  // 0x8C2D-0x8C36
  area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C37
  }
  // 0x8C38-0x8C41
  area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8C42
  }
  // 0x8C43-0x8C4C
  area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8C4D
  }
  printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
  print_return();  // 0x8C7C
  print("'ARE YOU ZACHARY?'");  // 0x8C7D
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
  // 0x8CAA-0x8CB0
  if (1 == area2.event_scratch0) {
    goto 0x8DD1;  // 0x8CB1
    // branch body 0x8DD1
    printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
    exit_event();  // 0x8F6F
  }
  who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
  // 0x8CC9-0x8CCF
  if (1 != area2.selected_player_in_combat) {
    goto 0x8CB5;  // 0x8CD0
    // branch body 0x8CB5
    who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
    // 0x8CC9-0x8CCF
    if (1 != area2.selected_player_in_combat) {
      goto 0x8CB5;  // 0x8CD0
      // branch body 0x8CB5
      // target 0x8CB5 already emitted
    }
    area2.event_scratch0 = 0;  // 0x8CD4
    area2.event_scratch1 = 3;  // 0x8CDA
    party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
    // 0x8CE9-0x8CEF
    if (2 < area2.event_scratch1) {
      goto 0x8DD1;  // 0x8CF0
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    printclear("'TELL US THE WORD:'");  // 0x8CF4
    input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
    // 0x8D0C-0x8D16
    if (32633 != abs_0004) {
      goto 0x8DD1;  // 0x8D17
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    exit_event();  // 0x8D1C
  }
  area2.event_scratch0 = 0;  // 0x8CD4
  area2.event_scratch1 = 3;  // 0x8CDA
  party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
  // 0x8CE9-0x8CEF
  if (2 < area2.event_scratch1) {
    goto 0x8DD1;  // 0x8CF0
    // branch body 0x8DD1
    // target 0x8DD1 already emitted
  }
  printclear("'TELL US THE WORD:'");  // 0x8CF4
  input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
  // 0x8D0C-0x8D16
  if (32633 != abs_0004) {
    goto 0x8DD1;  // 0x8D17
    // branch body 0x8DD1
    // target 0x8DD1 already emitted
  }
  exit_event();  // 0x8D1C
}
```

## Event 11

- Target: `0x8C22`
- Text hint: 'THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..' RETURN

```text
event 11 {
  // 0x8C22-0x8C2B
  area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x8C22
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C2C
  }
  // 0x8C2D-0x8C36
  area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x8C2D
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8C37
  }
  // 0x8C38-0x8C41
  area2.event_scratch0 = area1.event_word_34A & 16;  // 0x8C38
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8C42
  }
  // 0x8C43-0x8C4C
  area2.event_scratch0 = 1 & area1.event_word_356;  // 0x8C43
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8C4D
  }
  printclear('THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..');  // 0x8C4E
  print_return();  // 0x8C7C
  print("'ARE YOU ZACHARY?'");  // 0x8C7D
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH');  // 0x8C8E
  // 0x8CAA-0x8CB0
  if (1 == area2.event_scratch0) {
    goto 0x8DD1;  // 0x8CB1
    // branch body 0x8DD1
    printclear('THE MAN IS JOINED BY OTHERS FROM THE STALLS.');  // 0x8DD1
    exit_event();  // 0x8F6F
  }
  who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
  // 0x8CC9-0x8CCF
  if (1 != area2.selected_player_in_combat) {
    goto 0x8CB5;  // 0x8CD0
    // branch body 0x8CB5
    who(<select player> 'WHO MAKES THE ATTEMPT?');  // 0x8CB5
    // 0x8CC9-0x8CCF
    if (1 != area2.selected_player_in_combat) {
      goto 0x8CB5;  // 0x8CD0
      // branch body 0x8CB5
      // target 0x8CB5 already emitted
    }
    area2.event_scratch0 = 0;  // 0x8CD4
    area2.event_scratch1 = 3;  // 0x8CDA
    party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
    // 0x8CE9-0x8CEF
    if (2 < area2.event_scratch1) {
      goto 0x8DD1;  // 0x8CF0
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    printclear("'TELL US THE WORD:'");  // 0x8CF4
    input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
    // 0x8D0C-0x8D16
    if (32633 != abs_0004) {
      goto 0x8DD1;  // 0x8D17
      // branch body 0x8DD1
      // target 0x8DD1 already emitted
    }
    exit_event();  // 0x8D1C
  }
  area2.event_scratch0 = 0;  // 0x8CD4
  area2.event_scratch1 = 3;  // 0x8CDA
  party_surprise(zone: 76, result: area2.event_scratch0);  // 0x8CE0
  // 0x8CE9-0x8CEF
  if (2 < area2.event_scratch1) {
    goto 0x8DD1;  // 0x8CF0
    // branch body 0x8DD1
    // target 0x8DD1 already emitted
  }
  printclear("'TELL US THE WORD:'");  // 0x8CF4
  input_string(area2.event_scratch0 = <user input string>);  // 0x8D06
  // 0x8D0C-0x8D16
  if (32633 != abs_0004) {
    goto 0x8DD1;  // 0x8D17
    // branch body 0x8DD1
    // target 0x8DD1 already emitted
  }
  exit_event();  // 0x8D1C
}
```

## Event 12

- Target: `0x9E94`
- Text hint: 'THIS IS THE EMERGENCY HATCH.'

```text
event 12 {
  // 0x9E94-0x9E9D
  area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
  if (area2.event_scratch0 == 0) {
    goto 0x9EEA;  // 0x9E9E
    // branch body 0x9EEA
    printclear('THIS IS THE EMERGENCY HATCH.');  // 0x9EEA
    exit_event();  // 0x9F02
  }
  exit_event();  // 0x9EA3
}
```

## Event 14

- Target: `0x8F70`
- Text hint: 'THIS IS THE DANCE HALL.'

```text
event 14 {
  // 0x8F70-0x8F76
  if (1 == area1.event_word_352) {
    goto 0x8F92;  // 0x8F77
    // branch body 0x8F92
    // 0x8F92-0x8F9B
    area2.event_scratch0 = 2 & area1.event_word_34C;  // 0x8F92
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8F9C
    }
    printclear("A CROWD OF CIVILIANS IS HUDDLED BEHIND THE PLAYER PIANO. ONE CRIES, 'THANK GOD YOU'VE COME! YOU MUST ESCORT US TO AIRLOCK 1.' THE CROWD FORMS A RAGGED PACK BEHIND YOU.");  // 0x8F9D
    // 0x9029-0x9032
    area2.event_scratch0 = 2 & area1.event_word_34A;  // 0x9029
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9033
    }
    // 0x9034-0x903D
    area2.event_scratch0 = 8 & area1.event_word_34C;  // 0x9034
    if (area2.event_scratch0 == 0) {
      exit_event();  // 0x903E
    }
    printclear('ZACHARY IS HERE PROTECTED BY A RAM INFILTRATION TEAM.');  // 0x903F
    setup_monster(sprite_id: 51 max_distance: 0 pic_id: 255);  // 0x906A
    exit_event();  // 0x9071
  }
  printclear('THIS IS THE DANCE HALL.');  // 0x8F7B
  // 0x8F92-0x8F9B
  area2.event_scratch0 = 2 & area1.event_word_34C;  // 0x8F92
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8F9C
  }
  printclear("A CROWD OF CIVILIANS IS HUDDLED BEHIND THE PLAYER PIANO. ONE CRIES, 'THANK GOD YOU'VE COME! YOU MUST ESCORT US TO AIRLOCK 1.' THE CROWD FORMS A RAGGED PACK BEHIND YOU.");  // 0x8F9D
  // 0x9029-0x9032
  area2.event_scratch0 = 2 & area1.event_word_34A;  // 0x9029
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9033
  }
  // 0x9034-0x903D
  area2.event_scratch0 = 8 & area1.event_word_34C;  // 0x9034
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x903E
  }
  printclear('ZACHARY IS HERE PROTECTED BY A RAM INFILTRATION TEAM.');  // 0x903F
  setup_monster(sprite_id: 51 max_distance: 0 pic_id: 255);  // 0x906A
  exit_event();  // 0x9071
}
```

## Event 15

- Target: `0x9385`
- Text hint: "MR. FREDRICKSON LOOKS UP. 'IT TOOK SOME TIME FOR YOUR FILES TO BE TRANSFERRED FROM SALVATION. FOR NOW, HERE ARE LEVEL 1 SECURITY PASSES. I'LL GET YOU BETTER ONES WHEN THE PAPERWORK COMES THROUGH."

```text
event 15 {
  // 0x9385-0x938E
  area2.event_scratch0 = 64 & area1.event_word_34A;  // 0x9385
  if (area2.event_scratch0 != 0) {
    goto 0x946A;  // 0x938F
    // branch body 0x946A
    // 0x946A-0x9473
    area2.event_scratch0 = 128 & area1.event_word_348;  // 0x946A
    if (area2.event_scratch0 != 0) {
      goto 0x9537;  // 0x9474
      // branch body 0x9537
      // 0x9537-0x9540
      area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9537
      if (area2.event_scratch0 != 0) {
        goto 0x95F4;  // 0x9541
        // branch body 0x95F4
        // 0x95F4-0x95FD
        area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x95FE
        }
        // 0x9602-0x9608
        if (area1.event_word_352 == 1) {
          exit_event();  // 0x9609
        }
        printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
        printclear("MR. FREDRICKSON GETS UP. 'I'M SORRY, BUT NO NEW WORD ON YOUR PAPERWORK.");  // 0x9856
        // truncated at 0x9891
      }
      // 0x9545-0x954E
      area2.event_scratch0 = 16 & area1.event_word_348;  // 0x9545
      if (area2.event_scratch0 == 0) {
        goto 0x9856;  // 0x954F
        // branch body 0x9856
        printclear("MR. FREDRICKSON GETS UP. 'I'M SORRY, BUT NO NEW WORD ON YOUR PAPERWORK.");  // 0x9856
        // 0x9891-0x989A
        area2.event_scratch0 = area1.event_word_34A & 2;  // 0x9891
        if (area2.event_scratch0 == 0) {
          goto 0x98CD;  // 0x989B
        }
        // 0x989F-0x98A8
        area2.event_scratch0 = 64 & area1.event_word_34C;  // 0x989F
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x98A9
        }
        printclear('YOU PUT ZACHARY IN THE JAIL.');  // 0x98AA
        printclear('AN EMPTY CELL.');  // 0x98CD
        exit_event();  // 0x98DB
      }
      printclear("THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'");  // 0x9553
      // 0x95F4-0x95FD
      area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
      if (area2.event_scratch0 == 0) {
        goto 0x9856;  // 0x95FE
        // branch body 0x9856
        // target 0x9856 already emitted
      }
      // 0x9602-0x9608
      if (area1.event_word_352 == 1) {
        exit_event();  // 0x9609
      }
      printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
      // truncated at 0x9856
    }
    printclear("THE DIRECTOR LOOKS UP. 'SECURITY HAS COMPLETED THE NECESSARY FORMS TO GRANT YOU CODE 3 PASSCARDS.");  // 0x9478
    // 0x9537-0x9540
    area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9537
    if (area2.event_scratch0 != 0) {
      goto 0x95F4;  // 0x9541
      // branch body 0x95F4
      // target 0x95F4 already emitted
    }
    // 0x9545-0x954E
    area2.event_scratch0 = 16 & area1.event_word_348;  // 0x9545
    if (area2.event_scratch0 == 0) {
      goto 0x9856;  // 0x954F
      // branch body 0x9856
      // target 0x9856 already emitted
    }
    printclear("THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'");  // 0x9553
    // 0x95F4-0x95FD
    area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
    if (area2.event_scratch0 == 0) {
      goto 0x9856;  // 0x95FE
      // branch body 0x9856
      // target 0x9856 already emitted
    }
    // 0x9602-0x9608
    if (area1.event_word_352 == 1) {
      exit_event();  // 0x9609
    }
    printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
    // truncated at 0x9856
  }
  // 0x9393-0x9399
  if (0 > area1.event_word_350) {
    goto 0x9856;  // 0x939A
    // branch body 0x9856
    // target 0x9856 already emitted
  }
  printclear("MR. FREDRICKSON LOOKS UP. 'IT TOOK SOME TIME FOR YOUR FILES TO BE TRANSFERRED FROM SALVATION. FOR NOW, HERE ARE LEVEL 1 SECURITY PASSES. I'LL GET YOU BETTER ONES WHEN THE PAPERWORK COMES THROUGH.");  // 0x939E
}
```

## Event 16

- Target: `0x9029`
- Text hint: 'ZACHARY IS HERE PROTECTED BY A RAM INFILTRATION TEAM.'

```text
event 16 {
  // 0x9029-0x9032
  area2.event_scratch0 = 2 & area1.event_word_34A;  // 0x9029
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9033
  }
  // 0x9034-0x903D
  area2.event_scratch0 = 8 & area1.event_word_34C;  // 0x9034
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x903E
  }
  printclear('ZACHARY IS HERE PROTECTED BY A RAM INFILTRATION TEAM.');  // 0x903F
  setup_monster(sprite_id: 51 max_distance: 0 pic_id: 255);  // 0x906A
  exit_event();  // 0x9071
}
```

## Event 17

- Target: `0x90C6`
- Text hint: 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?'

```text
event 17 {
  // 0x90C7-0x90D0
  area2.event_scratch0 = 16 & area1.event_word_34E;  // 0x90C7
  if (area2.event_scratch0 != 0) {
    goto 0x91E5;  // 0x90D1
    // branch body 0x91E5
    // 0x91E5-0x91EE
    area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x91E5
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x91EF
    }
    printclear('THE COMPUTER ASKS FOR A PASSWORD:');  // 0x91F0
    input_string(area2.event_scratch0 = <user input string>);  // 0x920C
    // 0x9212-0x921E
    if (32633 != abs_0006) {
      goto 0x92B7;  // 0x921F
      // branch body 0x92B7
      printclear("'PASSWORD IS INCORRECT FOR DESIRED TASK. SECURITY HAS BEEN INFORMED.'");  // 0x92B7
      print_return();  // 0x92EE
      printclear('YOU NOTE A SUBROUTINE CONTAINING PASSWORDS. DO YOU TRY TO ACCESS?');  // 0x92EF
      // 0x9385-0x938E
      area2.event_scratch0 = 64 & area1.event_word_34A;  // 0x9385
      if (area2.event_scratch0 != 0) {
        goto 0x946A;  // 0x938F
        // branch body 0x946A
        // 0x946A-0x9473
        area2.event_scratch0 = 128 & area1.event_word_348;  // 0x946A
        if (area2.event_scratch0 != 0) {
          goto 0x9537;  // 0x9474
        }
        printclear("THE DIRECTOR LOOKS UP. 'SECURITY HAS COMPLETED THE NECESSARY FORMS TO GRANT YOU CODE 3 PASSCARDS.");  // 0x9478
        // 0x9537-0x9540
        area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9537
        if (area2.event_scratch0 != 0) {
          goto 0x95F4;  // 0x9541
        }
        // 0x9545-0x954E
        area2.event_scratch0 = 16 & area1.event_word_348;  // 0x9545
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x954F
        }
        printclear("THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'");  // 0x9553
        // 0x95F4-0x95FD
        area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x95FE
        }
        // 0x9602-0x9608
        if (area1.event_word_352 == 1) {
          exit_event();  // 0x9609
        }
        printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
        // truncated at 0x9856
      }
      // 0x9393-0x9399
      if (0 > area1.event_word_350) {
        goto 0x9856;  // 0x939A
        // branch body 0x9856
        printclear("MR. FREDRICKSON GETS UP. 'I'M SORRY, BUT NO NEW WORD ON YOUR PAPERWORK.");  // 0x9856
        // 0x9891-0x989A
        area2.event_scratch0 = area1.event_word_34A & 2;  // 0x9891
        if (area2.event_scratch0 == 0) {
          goto 0x98CD;  // 0x989B
        }
        // 0x989F-0x98A8
        area2.event_scratch0 = 64 & area1.event_word_34C;  // 0x989F
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x98A9
        }
        printclear('YOU PUT ZACHARY IN THE JAIL.');  // 0x98AA
        printclear('AN EMPTY CELL.');  // 0x98CD
        exit_event();  // 0x98DB
      }
      printclear("MR. FREDRICKSON LOOKS UP. 'IT TOOK SOME TIME FOR YOUR FILES TO BE TRANSFERRED FROM SALVATION. FOR NOW, HERE ARE LEVEL 1 SECURITY PASSES. I'LL GET YOU BETTER ONES WHEN THE PAPERWORK COMES THROUGH.");  // 0x939E
      // 0x946A-0x9473
      area2.event_scratch0 = 128 & area1.event_word_348;  // 0x946A
      if (area2.event_scratch0 != 0) {
        goto 0x9537;  // 0x9474
        // branch body 0x9537
        // 0x9537-0x9540
        area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9537
        if (area2.event_scratch0 != 0) {
          goto 0x95F4;  // 0x9541
        }
        // 0x9545-0x954E
        area2.event_scratch0 = 16 & area1.event_word_348;  // 0x9545
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x954F
        }
        printclear("THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'");  // 0x9553
        // 0x95F4-0x95FD
        area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x95FE
        }
        // 0x9602-0x9608
        if (area1.event_word_352 == 1) {
          exit_event();  // 0x9609
        }
        printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
        // truncated at 0x9856
      }
    }
  }
}
```

## Event 18

- Target: `0x90C7`
- Text hint: 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?'

```text
event 18 {
  // 0x90C7-0x90D0
  area2.event_scratch0 = 16 & area1.event_word_34E;  // 0x90C7
  if (area2.event_scratch0 != 0) {
    goto 0x91E5;  // 0x90D1
    // branch body 0x91E5
    // 0x91E5-0x91EE
    area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x91E5
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x91EF
    }
    printclear('THE COMPUTER ASKS FOR A PASSWORD:');  // 0x91F0
    input_string(area2.event_scratch0 = <user input string>);  // 0x920C
    // 0x9212-0x921E
    if (32633 != abs_0006) {
      goto 0x92B7;  // 0x921F
      // branch body 0x92B7
      printclear("'PASSWORD IS INCORRECT FOR DESIRED TASK. SECURITY HAS BEEN INFORMED.'");  // 0x92B7
      print_return();  // 0x92EE
      printclear('YOU NOTE A SUBROUTINE CONTAINING PASSWORDS. DO YOU TRY TO ACCESS?');  // 0x92EF
      // 0x9385-0x938E
      area2.event_scratch0 = 64 & area1.event_word_34A;  // 0x9385
      if (area2.event_scratch0 != 0) {
        goto 0x946A;  // 0x938F
        // branch body 0x946A
        // 0x946A-0x9473
        area2.event_scratch0 = 128 & area1.event_word_348;  // 0x946A
        if (area2.event_scratch0 != 0) {
          goto 0x9537;  // 0x9474
        }
        printclear("THE DIRECTOR LOOKS UP. 'SECURITY HAS COMPLETED THE NECESSARY FORMS TO GRANT YOU CODE 3 PASSCARDS.");  // 0x9478
        // 0x9537-0x9540
        area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9537
        if (area2.event_scratch0 != 0) {
          goto 0x95F4;  // 0x9541
        }
        // 0x9545-0x954E
        area2.event_scratch0 = 16 & area1.event_word_348;  // 0x9545
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x954F
        }
        printclear("THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'");  // 0x9553
        // 0x95F4-0x95FD
        area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x95FE
        }
        // 0x9602-0x9608
        if (area1.event_word_352 == 1) {
          exit_event();  // 0x9609
        }
        printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
        // truncated at 0x9856
      }
      // 0x9393-0x9399
      if (0 > area1.event_word_350) {
        goto 0x9856;  // 0x939A
        // branch body 0x9856
        printclear("MR. FREDRICKSON GETS UP. 'I'M SORRY, BUT NO NEW WORD ON YOUR PAPERWORK.");  // 0x9856
        // 0x9891-0x989A
        area2.event_scratch0 = area1.event_word_34A & 2;  // 0x9891
        if (area2.event_scratch0 == 0) {
          goto 0x98CD;  // 0x989B
        }
        // 0x989F-0x98A8
        area2.event_scratch0 = 64 & area1.event_word_34C;  // 0x989F
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x98A9
        }
        printclear('YOU PUT ZACHARY IN THE JAIL.');  // 0x98AA
        printclear('AN EMPTY CELL.');  // 0x98CD
        exit_event();  // 0x98DB
      }
      printclear("MR. FREDRICKSON LOOKS UP. 'IT TOOK SOME TIME FOR YOUR FILES TO BE TRANSFERRED FROM SALVATION. FOR NOW, HERE ARE LEVEL 1 SECURITY PASSES. I'LL GET YOU BETTER ONES WHEN THE PAPERWORK COMES THROUGH.");  // 0x939E
      // 0x946A-0x9473
      area2.event_scratch0 = 128 & area1.event_word_348;  // 0x946A
      if (area2.event_scratch0 != 0) {
        goto 0x9537;  // 0x9474
        // branch body 0x9537
        // 0x9537-0x9540
        area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9537
        if (area2.event_scratch0 != 0) {
          goto 0x95F4;  // 0x9541
        }
        // 0x9545-0x954E
        area2.event_scratch0 = 16 & area1.event_word_348;  // 0x9545
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x954F
        }
        printclear("THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'");  // 0x9553
        // 0x95F4-0x95FD
        area2.event_scratch0 = 32 & area1.event_word_34A;  // 0x95F4
        if (area2.event_scratch0 == 0) {
          goto 0x9856;  // 0x95FE
        }
        // 0x9602-0x9608
        if (area1.event_word_352 == 1) {
          exit_event();  // 0x9609
        }
        printclear("THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN.");  // 0x960A
        // truncated at 0x9856
      }
    }
  }
}
```

## Event 19

- Target: `0x9891`
- Text hint: 'YOU PUT ZACHARY IN THE JAIL.' 'AN EMPTY CELL.'

```text
event 19 {
  // 0x9891-0x989A
  area2.event_scratch0 = area1.event_word_34A & 2;  // 0x9891
  if (area2.event_scratch0 == 0) {
    goto 0x98CD;  // 0x989B
    // branch body 0x98CD
    printclear('AN EMPTY CELL.');  // 0x98CD
    exit_event();  // 0x98DB
  }
  // 0x989F-0x98A8
  area2.event_scratch0 = 64 & area1.event_word_34C;  // 0x989F
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x98A9
  }
  printclear('YOU PUT ZACHARY IN THE JAIL.');  // 0x98AA
  printclear('AN EMPTY CELL.');  // 0x98CD
  exit_event();  // 0x98DB
}
```

## Event 20

- Target: `0x98DC`
- Text hint: 'AIRLOCK 1 IS BEFORE YOU.' 'THIS IS A CREW CABIN.'

```text
event 20 {
  exit_event();  // 0x98DC
}
```

## Event 21

- Target: `0x98DD`
- Text hint: 'AIRLOCK 1 IS BEFORE YOU.' 'THIS IS A CREW CABIN.'

```text
event 21 {
  // 0x98DD-0x98E6
  area2.event_scratch0 = 1 & area1.event_word_34E;  // 0x98DD
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x98E7
  }
  // 0x98E8-0x98F1
  area2.event_scratch0 = 2 & area1.event_word_34C;  // 0x98E8
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x98F2
  }
  exit_event();  // 0x98F4
}
```

## Event 22

- Target: `0x9C90`
- Text hint: "A GUARD APPROACHES. 'OUR SENSORS HAVE DETECTED UNUSUAL MAGNETIC READINGS FROM THE BASEMENT. THEY MAY BE INVOLVED IN YOUR INVESTIGATION. PLEASE KEEP THE DIRECTOR INFORMED OF ANY PROGRESS.'"

```text
event 22 {
  // 0x9C90-0x9C96
  if (1 != area1.event_word_352) {
    goto 0x9CB3;  // 0x9C97
    // branch body 0x9CB3
    // 0x9CB3-0x9CBC
    area2.event_scratch0 = 128 & area1.event_word_34E;  // 0x9CB3
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9CBD
    }
    // 0x9CBE-0x9CC4
    if (0 == area1.event_word_350) {
      exit_event();  // 0x9CC5
    }
    printclear("A GUARD APPROACHES. 'OUR SENSORS HAVE DETECTED UNUSUAL MAGNETIC READINGS FROM THE BASEMENT. THEY MAY BE INVOLVED IN YOUR INVESTIGATION. PLEASE KEEP THE DIRECTOR INFORMED OF ANY PROGRESS.'");  // 0x9CC6
    // 0x9D61-0x9D6A
    area2.event_scratch0 = 8 & area1.event_word_34E;  // 0x9D61
    if (area2.event_scratch0 == 0) {
      goto 0x9E5F;  // 0x9D6B
      // branch body 0x9E5F
      printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
      // 0x9E94-0x9E9D
      area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
      if (area2.event_scratch0 == 0) {
        goto 0x9EEA;  // 0x9E9E
        // branch body 0x9EEA
        printclear('THIS IS THE EMERGENCY HATCH.');  // 0x9EEA
        exit_event();  // 0x9F02
      }
      exit_event();  // 0x9EA3
    }
    // 0x9D6F-0x9D78
    area2.event_scratch0 = 16 & area1.event_word_34E;  // 0x9D6F
    if (area2.event_scratch0 != 0) {
      goto 0x9E5F;  // 0x9D79
      // branch body 0x9E5F
      // target 0x9E5F already emitted
    }
    printclear("THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD.");  // 0x9D7D
    printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
    // 0x9E94-0x9E9D
    area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
    if (area2.event_scratch0 == 0) {
      goto 0x9EEA;  // 0x9E9E
      // branch body 0x9EEA
      // target 0x9EEA already emitted
    }
    exit_event();  // 0x9EA3
  }
  // 0x9C9B-0x9CA4
  area2.event_scratch0 = 4 & area1.event_word_34E;  // 0x9C9B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9CA5
  }
  or(area1.event_word_34E = 4 | area1.event_word_34E);  // 0x9CA6
  goto 0x865F;  // 0x9CAF
  // branch body 0x865F
    setup_monster(sprite_id: 49 max_distance: 0 pic_id: 255);  // 0x865F
    exit_event();  // 0x8666
}
```

## Event 23

- Target: `0x9988`
- Text hint: 'AIRLOCK 1 IS BEFORE YOU.' 'THIS IS A CREW CABIN.'

```text
event 23 {
  // 0x9988-0x998E
  if (0 != mapDirection) {
    exit_event();  // 0x998F
  }
  printclear('AIRLOCK 1 IS BEFORE YOU.');  // 0x9990
  printclear('THIS IS A CREW CABIN.');  // 0x99A7
  exit_event();  // 0x99BA
}
```

## Event 24

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 24 {
  exit_event();  // 0x852F
}
```

## Event 26

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 26 {
  exit_event();  // 0x852F
}
```

## Event 27

- Target: `0x9C15`
- Text hint: 'YOU SPOT THE SPY THAT ESCAPED! HE AND OTHERS ATTACK!'

```text
event 27 {
  // 0x9C15-0x9C1E
  area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x9C15
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9C1F
  }
  printclear('YOU SPOT THE SPY THAT ESCAPED! HE AND OTHERS ATTACK!');  // 0x9C20
  // 0x9C90-0x9C96
  if (1 != area1.event_word_352) {
    goto 0x9CB3;  // 0x9C97
    // branch body 0x9CB3
    // 0x9CB3-0x9CBC
    area2.event_scratch0 = 128 & area1.event_word_34E;  // 0x9CB3
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9CBD
    }
    // 0x9CBE-0x9CC4
    if (0 == area1.event_word_350) {
      exit_event();  // 0x9CC5
    }
    printclear("A GUARD APPROACHES. 'OUR SENSORS HAVE DETECTED UNUSUAL MAGNETIC READINGS FROM THE BASEMENT. THEY MAY BE INVOLVED IN YOUR INVESTIGATION. PLEASE KEEP THE DIRECTOR INFORMED OF ANY PROGRESS.'");  // 0x9CC6
    // 0x9D61-0x9D6A
    area2.event_scratch0 = 8 & area1.event_word_34E;  // 0x9D61
    if (area2.event_scratch0 == 0) {
      goto 0x9E5F;  // 0x9D6B
      // branch body 0x9E5F
      printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
      // 0x9E94-0x9E9D
      area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
      if (area2.event_scratch0 == 0) {
        goto 0x9EEA;  // 0x9E9E
        // branch body 0x9EEA
        printclear('THIS IS THE EMERGENCY HATCH.');  // 0x9EEA
        exit_event();  // 0x9F02
      }
      exit_event();  // 0x9EA3
    }
    // 0x9D6F-0x9D78
    area2.event_scratch0 = 16 & area1.event_word_34E;  // 0x9D6F
    if (area2.event_scratch0 != 0) {
      goto 0x9E5F;  // 0x9D79
      // branch body 0x9E5F
      // target 0x9E5F already emitted
    }
    printclear("THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD.");  // 0x9D7D
    printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
    // 0x9E94-0x9E9D
    area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
    if (area2.event_scratch0 == 0) {
      goto 0x9EEA;  // 0x9E9E
      // branch body 0x9EEA
      // target 0x9EEA already emitted
    }
    exit_event();  // 0x9EA3
  }
  // 0x9C9B-0x9CA4
  area2.event_scratch0 = 4 & area1.event_word_34E;  // 0x9C9B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9CA5
  }
  or(area1.event_word_34E = 4 | area1.event_word_34E);  // 0x9CA6
  goto 0x865F;  // 0x9CAF
  // branch body 0x865F
    setup_monster(sprite_id: 49 max_distance: 0 pic_id: 255);  // 0x865F
    exit_event();  // 0x8666
}
```

## Event 28

- Target: `0x99A7`
- Text hint: 'THIS IS A CREW CABIN.'

```text
event 28 {
  printclear('THIS IS A CREW CABIN.');  // 0x99A7
  exit_event();  // 0x99BA
}
```

## Event 29

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 29 {
  exit_event();  // 0x852F
}
```

## Event 33

- Target: `0x9F03`
- Text hint: "THE SECURITY CHIEF GREETS YOU. 'ONE OF MY MEN NOTED SOMEONE SUSPICIOUS ON THE CABIN LEVEL, BUT HE LOST THE MAN. YOU MIGHT WANT TO FOLLOW UP.'"

```text
event 33 {
  // 0x9F03-0x9F0C
  area2.event_scratch0 = 32 & area1.event_word_34C;  // 0x9F03
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9F0D
  }
  // 0x9F0E-0x9F17
  area2.event_scratch0 = 1 & area1.event_word_356;  // 0x9F0E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9F18
  }
  printclear("THE SECURITY CHIEF GREETS YOU. 'ONE OF MY MEN NOTED SOMEONE SUSPICIOUS ON THE CABIN LEVEL, BUT HE LOST THE MAN. YOU MIGHT WANT TO FOLLOW UP.'");  // 0x9F19
}
```

## Event 34

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 34 {
  exit_event();  // 0x852F
}
```

## Event 36

- Target: `0x99D5`
- Text hint: "A SIGN READS, 'AIRLOCK 2.'"

```text
event 36 {
  // 0x99D5-0x99DB
  if (3 == mapDirection) {
    exit_event();  // 0x99DC
  }
  // 0x99DD-0x99E3
  if (1 == area1.event_word_352) {
    goto 0x9A04;  // 0x99E4
    // branch body 0x9A04
    // 0x9A04-0x9A0D
    area2.event_scratch0 = 128 & area1.event_word_34C;  // 0x9A04
    if (area2.event_scratch0 != 0) {
      goto 0x99EC;  // 0x9A0E
      // branch body 0x99EC
      printclear("A SIGN READS, 'AIRLOCK 2.'");  // 0x99EC
      exit_event();  // 0x9A03
    }
    // 0x9A12-0x9A1B
    area2.event_scratch0 = 1 & area1.event_word_34E;  // 0x9A12
    if (area2.event_scratch0 == 0) {
      goto 0x99EC;  // 0x9A1C
      // branch body 0x99EC
      // target 0x99EC already emitted
    }
    printclear('RAM FORCES ATTACK!');  // 0x9A20
    exit_event();  // 0x9A32
  }
  goto 0x99EC;  // 0x99E8
  // branch body 0x99EC
    // target 0x99EC already emitted
}
```

## Event 37

- Target: `0x852F`
- Text hint: "'" area1.event_word_20C "'"

```text
event 37 {
  exit_event();  // 0x852F
}
```

## Event 38

- Target: `0x9B23`
- Text hint: 'THERE IS A LOT OF JUNK HERE. DO YOU WISH TO SEARCH?'

```text
event 38 {
  // 0x9B23-0x9B2C
  area2.event_scratch0 = 64 & area1.event_word_34A;  // 0x9B23
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9B2D
  }
  printclear('THERE IS A LOT OF JUNK HERE. DO YOU WISH TO SEARCH?');  // 0x9B2E
  // 0x9C15-0x9C1E
  area2.event_scratch0 = 2 & area1.event_word_34E;  // 0x9C15
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9C1F
  }
  printclear('YOU SPOT THE SPY THAT ESCAPED! HE AND OTHERS ATTACK!');  // 0x9C20
  // 0x9C90-0x9C96
  if (1 != area1.event_word_352) {
    goto 0x9CB3;  // 0x9C97
    // branch body 0x9CB3
    // 0x9CB3-0x9CBC
    area2.event_scratch0 = 128 & area1.event_word_34E;  // 0x9CB3
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9CBD
    }
    // 0x9CBE-0x9CC4
    if (0 == area1.event_word_350) {
      exit_event();  // 0x9CC5
    }
    printclear("A GUARD APPROACHES. 'OUR SENSORS HAVE DETECTED UNUSUAL MAGNETIC READINGS FROM THE BASEMENT. THEY MAY BE INVOLVED IN YOUR INVESTIGATION. PLEASE KEEP THE DIRECTOR INFORMED OF ANY PROGRESS.'");  // 0x9CC6
    // 0x9D61-0x9D6A
    area2.event_scratch0 = 8 & area1.event_word_34E;  // 0x9D61
    if (area2.event_scratch0 == 0) {
      goto 0x9E5F;  // 0x9D6B
      // branch body 0x9E5F
      printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
      // 0x9E94-0x9E9D
      area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
      if (area2.event_scratch0 == 0) {
        goto 0x9EEA;  // 0x9E9E
        // branch body 0x9EEA
        printclear('THIS IS THE EMERGENCY HATCH.');  // 0x9EEA
        exit_event();  // 0x9F02
      }
      exit_event();  // 0x9EA3
    }
    // 0x9D6F-0x9D78
    area2.event_scratch0 = 16 & area1.event_word_34E;  // 0x9D6F
    if (area2.event_scratch0 != 0) {
      goto 0x9E5F;  // 0x9D79
      // branch body 0x9E5F
      // target 0x9E5F already emitted
    }
    printclear("THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD.");  // 0x9D7D
    printclear("THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'");  // 0x9E5F
    // 0x9E94-0x9E9D
    area2.event_scratch0 = 32 & area1.event_word_34E;  // 0x9E94
    if (area2.event_scratch0 == 0) {
      goto 0x9EEA;  // 0x9E9E
      // branch body 0x9EEA
      // target 0x9EEA already emitted
    }
    exit_event();  // 0x9EA3
  }
  // 0x9C9B-0x9CA4
  area2.event_scratch0 = 4 & area1.event_word_34E;  // 0x9C9B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9CA5
  }
  or(area1.event_word_34E = 4 | area1.event_word_34E);  // 0x9CA6
  goto 0x865F;  // 0x9CAF
  // branch body 0x865F
    setup_monster(sprite_id: 49 max_distance: 0 pic_id: 255);  // 0x865F
    exit_event();  // 0x8666
}
```
