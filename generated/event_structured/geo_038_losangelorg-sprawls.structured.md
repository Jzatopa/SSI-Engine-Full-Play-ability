# GEO 38: Losangelorg Sprawls

ECL block: `38`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8101`
- Text hint: 'THE DOOR TO ROOM '

```text
event 01 {
  exit_event();  // 0x8101
}
```

## Event 02

- Target: `0x85AB`
- Text hint: 'YOU ENTER THE ELEVATOR. DO YOU WISH TO USE IT?'

```text
event 02 {
  // 0x85AB-0x85B1
  if (area1.event_word_20A == 1) {
    area1.event_word_20A = 0;  // 0x85B2
  }
  if_=(<if compare flag is false, skip next op>);  // 0x85B8
  exit_event();  // 0x85B9
}
```

## Event 03

- Target: `0x875E`
- Text hint: 'A PLAQUE ON THE WALL READS,' RETURN

```text
event 03 {
  // 0x875E-0x8764
  if (mapDirection != 2) {
    exit_event();  // 0x8765
  }
  printclear('A PLAQUE ON THE WALL READS,');  // 0x8766
  print_return();  // 0x877E
  print_return();  // 0x877F
  print('    -- FLOOR NUMBER ');  // 0x8780
  print(area1.event_word_204);  // 0x8792
  print(' --');  // 0x8796
  print_return();  // 0x879C
  // 0x879D-0x87A3
  if (area1.event_word_204 == 13) {
    goto 0x8801;  // 0x87A4
    // branch body 0x8801
    print('TOWER ISLE CASINO COMPLEX --');  // 0x8801
    print_return();  // 0x8819
    print('MANAGEMENT NOT RESPONSIBLE FOR DAMAGED, LOST OR STOLEN PROPERTY.');  // 0x881A
    print('ROOMS 8505 - 8507 - LEFT HALL');  // 0x884F
    print_return();  // 0x8868
    print('SPARKHOUSE CAFE STRAIGHT AHEAD');  // 0x8869
    // 0x8885-0x888B
    if (area1.event_word_204 != 13) {
      goto 0x85AA;  // 0x888C
      // branch body 0x85AA
      exit_event();  // 0x85AA
    }
    printclear('A SIGN OVER THE DOOR READS,');  // 0x8890
    print_return();  // 0x88A8
    print_return();  // 0x88A9
    print('GREY LADY CARD ROOM');  // 0x88AA
    exit_event();  // 0x88BC
  }
  print('ROOMS ');  // 0x87A8
  print(area1.event_word_204);  // 0x87B0
  print('01 - ');  // 0x87B4
  print(area1.event_word_204);  // 0x87BB
  print('04 - RIGHT HALL');  // 0x87BF
  print_return();  // 0x87CE
  // 0x87CF-0x87D5
  if (area1.event_word_204 == 85) {
    goto 0x884F;  // 0x87D6
    // branch body 0x884F
    print('ROOMS 8505 - 8507 - LEFT HALL');  // 0x884F
    print_return();  // 0x8868
    print('SPARKHOUSE CAFE STRAIGHT AHEAD');  // 0x8869
    // 0x8885-0x888B
    if (area1.event_word_204 != 13) {
      goto 0x85AA;  // 0x888C
      // branch body 0x85AA
      // target 0x85AA already emitted
    }
    printclear('A SIGN OVER THE DOOR READS,');  // 0x8890
    print_return();  // 0x88A8
    print_return();  // 0x88A9
    print('GREY LADY CARD ROOM');  // 0x88AA
    exit_event();  // 0x88BC
  }
  print('ROOMS ');  // 0x87DA
  print(area1.event_word_204);  // 0x87E2
  print('05 - ');  // 0x87E6
  print(area1.event_word_204);  // 0x87ED
  print('08 - LEFT HALL');  // 0x87F1
  print('TOWER ISLE CASINO COMPLEX --');  // 0x8801
  print_return();  // 0x8819
  print('MANAGEMENT NOT RESPONSIBLE FOR DAMAGED, LOST OR STOLEN PROPERTY.');  // 0x881A
  print('ROOMS 8505 - 8507 - LEFT HALL');  // 0x884F
  print_return();  // 0x8868
  print('SPARKHOUSE CAFE STRAIGHT AHEAD');  // 0x8869
  // 0x8885-0x888B
  if (area1.event_word_204 != 13) {
    goto 0x85AA;  // 0x888C
    // branch body 0x85AA
    // target 0x85AA already emitted
  }
  printclear('A SIGN OVER THE DOOR READS,');  // 0x8890
  print_return();  // 0x88A8
  print_return();  // 0x88A9
  print('GREY LADY CARD ROOM');  // 0x88AA
  exit_event();  // 0x88BC
}
```

## Event 04

- Target: `0x8885`
- Text hint: 'A SIGN OVER THE DOOR READS,' RETURN

```text
event 04 {
  // 0x8885-0x888B
  if (area1.event_word_204 != 13) {
    goto 0x85AA;  // 0x888C
    // branch body 0x85AA
    exit_event();  // 0x85AA
  }
  printclear('A SIGN OVER THE DOOR READS,');  // 0x8890
  print_return();  // 0x88A8
  print_return();  // 0x88A9
  print('GREY LADY CARD ROOM');  // 0x88AA
  exit_event();  // 0x88BC
}
```

## Event 05

- Target: `0x88BD`
- Text hint: 'A SIGN OVER THE SOUTH DOOR READS,' RETURN

```text
event 05 {
  // 0x88BD-0x88C3
  if (area1.event_word_20A == 1) {
    area1.event_word_20A = 0;  // 0x88C4
  }
  if_=(<if compare flag is false, skip next op>);  // 0x88CA
  exit_event();  // 0x88CB
}
```

## Event 06

- Target: `0x8949`
- Text hint: 'A MAN IN A RAGGED MILITARY UNIFORM SITS AGAINST THE WALL HERE.'

```text
event 06 {
  // 0x8949-0x894F
  if (area1.event_word_204 != 13) {
    goto 0x85AA;  // 0x8950
    // branch body 0x85AA
    exit_event();  // 0x85AA
  }
  // 0x8954-0x895D
  area2.event_scratch0 = 64 & area1.event_word_296;  // 0x8954
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x895E
  }
  or(area1.event_word_296 = 64 | area1.event_word_296);  // 0x895F
  printclear('A MAN IN A RAGGED MILITARY UNIFORM SITS AGAINST THE WALL HERE.');  // 0x8968
  // 0x8BB9-0x8BC2
  area2.event_scratch0 = 1 & area1.event_word_298;  // 0x8BB9
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8BC3
  }
  exit_event();  // 0x8BC5
}
```

## Event 07

- Target: `0x8BB9`
- Text hint: 'YOU FLEE THE BATTLE.'

```text
event 07 {
  // 0x8BB9-0x8BC2
  area2.event_scratch0 = 1 & area1.event_word_298;  // 0x8BB9
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8BC3
  }
  exit_event();  // 0x8BC5
}
```

## Event 08

- Target: `0x8CDC`
- Text hint: "YOU ENTER AN EMPTY BARROOM. THE BARTENDER GREETS YOU. 'HI, PULL UP A STOOL. I'LL BUY YOU A DRINK!'"

```text
event 08 {
  // 0x8CDC-0x8CE2
  if (mapDirection != 2) {
    exit_event();  // 0x8CE3
  }
  or(area1.event_word_298 = 2 | area1.event_word_298);  // 0x8CE4
  printclear("YOU ENTER AN EMPTY BARROOM. THE BARTENDER GREETS YOU. 'HI, PULL UP A STOOL. I'LL BUY YOU A DRINK!'");  // 0x8CED
  // 0x8E4A-0x8E50
  if (mapDirection != 0) {
    exit_event();  // 0x8E51
  }
  // 0x8E52-0x8E5B
  area2.event_scratch0 = 4 & area1.event_word_298;  // 0x8E52
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8E5C
  }
  printclear('A CARD GAME IS BEING PLAYED AT ONE OF THE TABLES. AS YOU ENTER THE ROOM, A PLAYER LOOKS UP.');  // 0x8E5D
  // truncated at 0x9483
}
```

## Event 09

- Target: `0x8E4A`
- Text hint: 'A CARD GAME IS BEING PLAYED AT ONE OF THE TABLES. AS YOU ENTER THE ROOM, A PLAYER LOOKS UP.'

```text
event 09 {
  // 0x8E4A-0x8E50
  if (mapDirection != 0) {
    exit_event();  // 0x8E51
  }
  // 0x8E52-0x8E5B
  area2.event_scratch0 = 4 & area1.event_word_298;  // 0x8E52
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8E5C
  }
  printclear('A CARD GAME IS BEING PLAYED AT ONE OF THE TABLES. AS YOU ENTER THE ROOM, A PLAYER LOOKS UP.');  // 0x8E5D
  // truncated at 0x9483
}
```

## Event 10

- Target: `0x9483`
- Text hint: 'YOU ENTER THE SPARKHOUSE CAFE.'

```text
event 10 {
  // 0x9483-0x9489
  if (mapDirection != 2) {
    exit_event();  // 0x948A
  }
  printclear('YOU ENTER THE SPARKHOUSE CAFE.');  // 0x948B
  // 0x964B-0x9651
  if (area1.event_word_20A == 1) {
    area1.event_word_20A = 0;  // 0x9652
  }
  if_=(<if compare flag is false, skip next op>);  // 0x9658
  exit_event();  // 0x9659
}
```

## Event 11

- Target: `0x964B`
- Text hint: "THE WARREN DWELLERS SHOUT DOWN TO YOU. 'YOU DIDN'T FIND OUR CHILDREN...YOU MUST GO BACK!'"

```text
event 11 {
  // 0x964B-0x9651
  if (area1.event_word_20A == 1) {
    area1.event_word_20A = 0;  // 0x9652
  }
  if_=(<if compare flag is false, skip next op>);  // 0x9658
  exit_event();  // 0x9659
}
```

## Event 12

- Target: `0x9723`
- Text hint: 'RATWURST ATTACK!'

```text
event 12 {
  // 0x9723-0x972C
  area2.event_scratch0 = 1 & area1.event_word_21A;  // 0x9723
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x972D
  }
  area2.event_scratch0 = 1;  // 0x972E
  area2.event_scratch2 = 10;  // 0x9734
  printclear('RATWURST ATTACK!');  // 0x973A
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 11);  // 0x9749
  clearmonsters();  // 0x9753
  load_monster(monster_id: 11 copies: 10 cpic_id: 11);  // 0x9754
  combat();  // 0x975B
  // 0x975C-0x9762
  if (area2.word_58E <= 128) {
    goto 0x8CBB;  // 0x9763
    // branch body 0x8CBB
    printclear('YOU FLEE THE BATTLE.');  // 0x8CBB
    mapPosX = area1.lastXPos;  // 0x8CCD
    mapPosY = area1.lastYPos;  // 0x8CD4
    // 0x8CDC-0x8CE2
    if (mapDirection != 2) {
      exit_event();  // 0x8CE3
    }
    or(area1.event_word_298 = 2 | area1.event_word_298);  // 0x8CE4
    printclear("YOU ENTER AN EMPTY BARROOM. THE BARTENDER GREETS YOU. 'HI, PULL UP A STOOL. I'LL BUY YOU A DRINK!'");  // 0x8CED
    // 0x8E4A-0x8E50
    if (mapDirection != 0) {
      exit_event();  // 0x8E51
    }
    // 0x8E52-0x8E5B
    area2.event_scratch0 = 4 & area1.event_word_298;  // 0x8E52
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x8E5C
    }
    printclear('A CARD GAME IS BEING PLAYED AT ONE OF THE TABLES. AS YOU ENTER THE ROOM, A PLAYER LOOKS UP.');  // 0x8E5D
    // truncated at 0x9483
  }
  or(area1.event_word_21A = area2.event_scratch0 | area1.event_word_21A);  // 0x9767
  // 0x9771-0x9777
  if (area2.event_scratch0 == 4) {
    goto 0x977D;  // 0x9778
    // branch body 0x977D
    printclear("THE MAN THANKS YOU. 'YOU SAVED MY LIFE! THOSE RATS HAD ME TRAPPED AND WERE SAVING ME FOR DINNER!");  // 0x977D
    // 0x984B-0x9854
    area2.event_scratch0 = 2 & area1.event_word_21A;  // 0x984B
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9855
    }
    or(area1.event_word_21A = 2 | area1.event_word_21A);  // 0x9856
    printclear("'HELP!' YOU HEAR A SHOUT FROM THE SOUTH.");  // 0x985F
    // 0x9882-0x988B
    area2.event_scratch0 = 4 & area1.event_word_21A;  // 0x9882
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x988C
    }
    area2.event_scratch0 = 4;  // 0x988D
    area2.event_scratch2 = 8;  // 0x9893
    printclear('RATWURSTS HAVE CORNERED A MAN AT THE END OF THE TUNNEL.');  // 0x9899
    // 0x98D7-0x98E0
    area2.event_scratch0 = 8 & area1.event_word_21A;  // 0x98D7
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x98E1
    }
    load_character(index: 0);  // 0x98E2
    setup_monster(sprite_id: 255 max_distance: 0 pic_id: 11);  // 0x98E5
    exit_event();  // 0x98EC
  }
  exit_event();  // 0x977C
}
```

## Event 13

- Target: `0x984B`
- Text hint: "'HELP!' YOU HEAR A SHOUT FROM THE SOUTH."

```text
event 13 {
  // 0x984B-0x9854
  area2.event_scratch0 = 2 & area1.event_word_21A;  // 0x984B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9855
  }
  or(area1.event_word_21A = 2 | area1.event_word_21A);  // 0x9856
  printclear("'HELP!' YOU HEAR A SHOUT FROM THE SOUTH.");  // 0x985F
  // 0x9882-0x988B
  area2.event_scratch0 = 4 & area1.event_word_21A;  // 0x9882
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x988C
  }
  area2.event_scratch0 = 4;  // 0x988D
  area2.event_scratch2 = 8;  // 0x9893
  printclear('RATWURSTS HAVE CORNERED A MAN AT THE END OF THE TUNNEL.');  // 0x9899
  // 0x98D7-0x98E0
  area2.event_scratch0 = 8 & area1.event_word_21A;  // 0x98D7
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x98E1
  }
  load_character(index: 0);  // 0x98E2
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 11);  // 0x98E5
  exit_event();  // 0x98EC
}
```

## Event 14

- Target: `0x9882`
- Text hint: 'RATWURSTS HAVE CORNERED A MAN AT THE END OF THE TUNNEL.'

```text
event 14 {
  // 0x9882-0x988B
  area2.event_scratch0 = 4 & area1.event_word_21A;  // 0x9882
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x988C
  }
  area2.event_scratch0 = 4;  // 0x988D
  area2.event_scratch2 = 8;  // 0x9893
  printclear('RATWURSTS HAVE CORNERED A MAN AT THE END OF THE TUNNEL.');  // 0x9899
  // 0x98D7-0x98E0
  area2.event_scratch0 = 8 & area1.event_word_21A;  // 0x98D7
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x98E1
  }
  load_character(index: 0);  // 0x98E2
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 11);  // 0x98E5
  exit_event();  // 0x98EC
}
```

## Event 15

- Target: `0x98D7`
- Text hint: 'YOU HEAR RUNNING FOOTSTEPS DOWN THE TUNNEL AHEAD.'

```text
event 15 {
  // 0x98D7-0x98E0
  area2.event_scratch0 = 8 & area1.event_word_21A;  // 0x98D7
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x98E1
  }
  load_character(index: 0);  // 0x98E2
  setup_monster(sprite_id: 255 max_distance: 0 pic_id: 11);  // 0x98E5
  exit_event();  // 0x98EC
}
```

## Event 16

- Target: `0x99AF`
- Text hint: 'YOU HEAR RUNNING FOOTSTEPS DOWN THE TUNNEL AHEAD.'

```text
event 16 {
  // 0x99AF-0x99B8
  area2.event_scratch0 = 1 & area1.event_word_21C;  // 0x99AF
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x99B9
  }
  or(area1.event_word_21C = 1 | area1.event_word_21C);  // 0x99BA
  printclear('YOU HEAR RUNNING FOOTSTEPS DOWN THE TUNNEL AHEAD.');  // 0x99C3
  // 0x99ED-0x99F6
  area2.event_scratch0 = 2 & area1.event_word_21C;  // 0x99ED
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x99F7
  }
  setup_monster(sprite_id: 12 max_distance: 0 pic_id: 255);  // 0x99F8
  exit_event();  // 0x99FF
}
```

## Event 17

- Target: `0x99ED`
- Text hint: "YOU FIND THE GANG'S SUPPLIES." 'YOU ARE ATTACKED FROM BEHIND!' 'AUDIO CAPSULES ARE STORED HERE.'

```text
event 17 {
  // 0x99ED-0x99F6
  area2.event_scratch0 = 2 & area1.event_word_21C;  // 0x99ED
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x99F7
  }
  setup_monster(sprite_id: 12 max_distance: 0 pic_id: 255);  // 0x99F8
  exit_event();  // 0x99FF
}
```

## Event 18

- Target: `0x9A75`
- Text hint: "YOU FIND THE GANG'S SUPPLIES." 'YOU ARE ATTACKED FROM BEHIND!' 'AUDIO CAPSULES ARE STORED HERE.'

```text
event 18 {
  // 0x9A75-0x9A7E
  area2.event_scratch0 = 2 & area1.event_word_21C;  // 0x9A75
  if (area2.event_scratch0 == 0) {
    goto 0x9AC4;  // 0x9A7F
    // branch body 0x9AC4
    printclear('YOU ARE ATTACKED FROM BEHIND!');  // 0x9AC4
    printclear('AUDIO CAPSULES ARE STORED HERE.');  // 0x9B0F
    exit_event();  // 0x9B2A
  }
  // 0x9A83-0x9A8C
  area2.event_scratch0 = 8 & area1.event_word_21C;  // 0x9A83
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9A8D
  }
  printclear("YOU FIND THE GANG'S SUPPLIES.");  // 0x9A8E
  printclear('YOU ARE ATTACKED FROM BEHIND!');  // 0x9AC4
  printclear('AUDIO CAPSULES ARE STORED HERE.');  // 0x9B0F
  exit_event();  // 0x9B2A
}
```

## Event 19

- Target: `0x9B0F`
- Text hint: 'AUDIO CAPSULES ARE STORED HERE.'

```text
event 19 {
  printclear('AUDIO CAPSULES ARE STORED HERE.');  // 0x9B0F
  exit_event();  // 0x9B2A
}
```

## Event 20

- Target: `0x9B2B`
- Text hint: 'A SMALL OFFICE.'

```text
event 20 {
  printclear('A SMALL OFFICE.');  // 0x9B2B
  // 0x9B3A-0x9B43
  area2.event_scratch0 = 16 & area1.event_word_314;  // 0x9B3A
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x9B44
  }
  // 0x9B45-0x9B4E
  area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9B45
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9B4F
  }
  // 0x9B50-0x9B59
  area2.event_scratch0 = 32 & area1.event_word_298;  // 0x9B50
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9B5A
  }
  setup_monster(sprite_id: 5 max_distance: 0 pic_id: 255);  // 0x9B5B
  exit_event();  // 0x9B62
}
```

## Event 21

- Target: `0x9BAE`
- Text hint: 'A SMALL AUDIO PRODUCTION ROOM.'

```text
event 21 {
  // 0x9BAE-0x9BB4
  if (mapDirection != 1) {
    exit_event();  // 0x9BB5
  }
  printclear('A SMALL AUDIO PRODUCTION ROOM.');  // 0x9BB6
  exit_event();  // 0x9BD0
}
```

## Event 22

- Target: `0x9BD1`
- Text hint: "AS YOU ENTER, THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR FLICKERS OFF."

```text
event 22 {
  // 0x9BD1-0x9BD7
  if (mapDirection != 1) {
    exit_event();  // 0x9BD8
  }
  // 0x9BD9-0x9BE2
  area2.event_scratch0 = 16 & area1.event_word_314;  // 0x9BD9
  if (area2.event_scratch0 != 0) {
    goto 0x9C34;  // 0x9BE3
    // branch body 0x9C34
    // 0x9C34-0x9C3D
    area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9C34
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x9C3E
    }
    printclear("THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR IS ON.");  // 0x9C3F
    // 0x9C68-0x9C6E
    if (mapDirection != 1) {
      exit_event();  // 0x9C6F
    }
    // 0x9C70-0x9C79
    area2.event_scratch0 = 16 & area1.event_word_314;  // 0x9C70
    if (area2.event_scratch0 != 0) {
      goto 0x9F63;  // 0x9C7A
      // branch body 0x9F63
      // 0x9F63-0x9F6C
      area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9F63
      if (area2.event_scratch0 != 0) {
        goto 0x9F2B;  // 0x9F6D
        // branch body 0x9F2B
        printclear("BAD DOG GIVES YOU THE 'THUMBS UP' SIGN AS YOU ENTER THE BOOTH.");  // 0x9F2B
        // 0x9F63-0x9F6C
        area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9F63
        if (area2.event_scratch0 != 0) {
          goto 0x9F2B;  // 0x9F6D
        }
        or(area1.event_word_298 = 128 | area1.event_word_298);  // 0x9F71
        printclear("YOU ENTER THE BROADCAST BOOTH. A PURGE MEMBER SITS AT THE CONTROLS. HE SCREEDS VENOMOUSLY INTO THE MIKE.'");  // 0x9F7A
      }
      or(area1.event_word_298 = 128 | area1.event_word_298);  // 0x9F71
      printclear("YOU ENTER THE BROADCAST BOOTH. A PURGE MEMBER SITS AT THE CONTROLS. HE SCREEDS VENOMOUSLY INTO THE MIKE.'");  // 0x9F7A
    }
    picture(block_id: 60);  // 0x9C7E
    // 0x9C81-0x9C8A
    area2.event_scratch0 = 1 & area1.event_word_29A;  // 0x9C81
    if (area2.event_scratch0 != 0) {
      goto 0x9F2B;  // 0x9C8B
      // branch body 0x9F2B
      // target 0x9F2B already emitted
    }
    or(area1.event_word_29A = 1 | area1.event_word_29A);  // 0x9C8F
    printclear('YOU ENTER THE BROADCAST BOOTH. A DESERT RUNNER SITS AT THE CONTROLS. HE MOTIONS YOU TO SILENCE, FLICKS A SWITCH, AND SPEAKS INTO A MICROPHONE.');  // 0x9C98
    // truncated at 0x9F2B
  }
  // 0x9BE7-0x9BF0
  area2.event_scratch0 = 64 & area1.event_word_298;  // 0x9BE7
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9BF1
  }
  or(area1.event_word_298 = 64 | area1.event_word_298);  // 0x9BF2
  printclear("AS YOU ENTER, THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR FLICKERS OFF.");  // 0x9BFB
  // 0x9C34-0x9C3D
  area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9C34
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9C3E
  }
  printclear("THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR IS ON.");  // 0x9C3F
  // 0x9C68-0x9C6E
  if (mapDirection != 1) {
    exit_event();  // 0x9C6F
  }
  // 0x9C70-0x9C79
  area2.event_scratch0 = 16 & area1.event_word_314;  // 0x9C70
  if (area2.event_scratch0 != 0) {
    goto 0x9F63;  // 0x9C7A
    // branch body 0x9F63
    // target 0x9F63 already emitted
  }
  picture(block_id: 60);  // 0x9C7E
  // 0x9C81-0x9C8A
  area2.event_scratch0 = 1 & area1.event_word_29A;  // 0x9C81
  if (area2.event_scratch0 != 0) {
    goto 0x9F2B;  // 0x9C8B
    // branch body 0x9F2B
    // target 0x9F2B already emitted
  }
  or(area1.event_word_29A = 1 | area1.event_word_29A);  // 0x9C8F
  printclear('YOU ENTER THE BROADCAST BOOTH. A DESERT RUNNER SITS AT THE CONTROLS. HE MOTIONS YOU TO SILENCE, FLICKS A SWITCH, AND SPEAKS INTO A MICROPHONE.');  // 0x9C98
  // truncated at 0x9F2B
}
```

## Event 23

- Target: `0x9C68`
- Text hint: 'YOU ENTER THE BROADCAST BOOTH. A DESERT RUNNER SITS AT THE CONTROLS. HE MOTIONS YOU TO SILENCE, FLICKS A SWITCH, AND SPEAKS INTO A MICROPHONE.'

```text
event 23 {
  // 0x9C68-0x9C6E
  if (mapDirection != 1) {
    exit_event();  // 0x9C6F
  }
  // 0x9C70-0x9C79
  area2.event_scratch0 = 16 & area1.event_word_314;  // 0x9C70
  if (area2.event_scratch0 != 0) {
    goto 0x9F63;  // 0x9C7A
    // branch body 0x9F63
    // 0x9F63-0x9F6C
    area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9F63
    if (area2.event_scratch0 != 0) {
      goto 0x9F2B;  // 0x9F6D
      // branch body 0x9F2B
      printclear("BAD DOG GIVES YOU THE 'THUMBS UP' SIGN AS YOU ENTER THE BOOTH.");  // 0x9F2B
      // 0x9F63-0x9F6C
      area2.event_scratch0 = 128 & area1.event_word_298;  // 0x9F63
      if (area2.event_scratch0 != 0) {
        goto 0x9F2B;  // 0x9F6D
        // branch body 0x9F2B
        // target 0x9F2B already emitted
      }
      or(area1.event_word_298 = 128 | area1.event_word_298);  // 0x9F71
      printclear("YOU ENTER THE BROADCAST BOOTH. A PURGE MEMBER SITS AT THE CONTROLS. HE SCREEDS VENOMOUSLY INTO THE MIKE.'");  // 0x9F7A
    }
    or(area1.event_word_298 = 128 | area1.event_word_298);  // 0x9F71
    printclear("YOU ENTER THE BROADCAST BOOTH. A PURGE MEMBER SITS AT THE CONTROLS. HE SCREEDS VENOMOUSLY INTO THE MIKE.'");  // 0x9F7A
  }
  picture(block_id: 60);  // 0x9C7E
  // 0x9C81-0x9C8A
  area2.event_scratch0 = 1 & area1.event_word_29A;  // 0x9C81
  if (area2.event_scratch0 != 0) {
    goto 0x9F2B;  // 0x9C8B
    // branch body 0x9F2B
    // target 0x9F2B already emitted
  }
  or(area1.event_word_29A = 1 | area1.event_word_29A);  // 0x9C8F
  printclear('YOU ENTER THE BROADCAST BOOTH. A DESERT RUNNER SITS AT THE CONTROLS. HE MOTIONS YOU TO SILENCE, FLICKS A SWITCH, AND SPEAKS INTO A MICROPHONE.');  // 0x9C98
  // truncated at 0x9F2B
}
```
