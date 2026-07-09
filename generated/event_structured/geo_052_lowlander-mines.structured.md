# GEO 52: Lowlander Mines

ECL block: `49`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 02

- Target: `0x8C7F`
- Text hint: 'AN ELEVATOR UP. DO YOU GO?'

```text
event 02 {
  // 0x8C7F-0x8C85
  if (mapDirection != 2) {
    exit_event();  // 0x8C86
  }
  printclear('AN ELEVATOR UP. DO YOU GO?');  // 0x8C87
  // 0x8CCB-0x8CD4
  area2.event_scratch0 = 64 & area1.event_word_2E6;  // 0x8CCB
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8CD5
  }
  or(area1.event_word_2E6 = 64 | area1.event_word_2E6);  // 0x8CD6
  printclear('THE BLOODY TRAIL LEADS DOWN THE TUNNEL TO THE NORTH.');  // 0x8CDF
  // 0x8D0B-0x8D14
  area2.event_scratch0 = 2 & area1.event_word_2E8;  // 0x8D0B
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8D15
  }
  printclear('TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.');  // 0x8D16
  exit_event();  // 0x8D4B
}
```

## Event 03

- Target: `0x8CCB`
- Text hint: 'THE BLOODY TRAIL LEADS DOWN THE TUNNEL TO THE NORTH.'

```text
event 03 {
  // 0x8CCB-0x8CD4
  area2.event_scratch0 = 64 & area1.event_word_2E6;  // 0x8CCB
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8CD5
  }
  or(area1.event_word_2E6 = 64 | area1.event_word_2E6);  // 0x8CD6
  printclear('THE BLOODY TRAIL LEADS DOWN THE TUNNEL TO THE NORTH.');  // 0x8CDF
  // 0x8D0B-0x8D14
  area2.event_scratch0 = 2 & area1.event_word_2E8;  // 0x8D0B
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8D15
  }
  printclear('TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.');  // 0x8D16
  exit_event();  // 0x8D4B
}
```

## Event 04

- Target: `0x8D0B`
- Text hint: 'TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.'

```text
event 04 {
  // 0x8D0B-0x8D14
  area2.event_scratch0 = 2 & area1.event_word_2E8;  // 0x8D0B
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x8D15
  }
  printclear('TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.');  // 0x8D16
  exit_event();  // 0x8D4B
}
```

## Event 25

- Target: `0x9432`
- Text hint: '<string at area2.selected_player_name>' ' SEES A NEWLY WIRED COMMUNICATIONS CABLE RUNNING ALONG THE WEST WALL.' 'EAST'

```text
event 25 {
  // 0x9432-0x943B
  area2.event_scratch0 = 64 & area1.event_word_2E4;  // 0x9432
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x943C
  }
  area2.event_scratch0 = 1;  // 0x943D
  party_surprise(zone: 83, result: area2.event_scratch0);  // 0x9443
  // 0x944C-0x9452
  if (2 < area2.event_scratch0) {
    exit_event();  // 0x9453
  }
  load_character(index: area2.event_scratch1);  // 0x9454
  printclear('<string at area2.selected_player_name>');  // 0x9458
  print(' SEES A NEWLY WIRED COMMUNICATIONS CABLE RUNNING ALONG THE WEST WALL.');  // 0x945C
  gosub 0x9646;  // 0x949E
  print('EAST');  // 0x94A2
  gosub 0x9663;  // 0x94A8
  print('NORTH');  // 0x94AC
  gosub 0x9678;  // 0x94B3
  print('NORTHERN');  // 0x94B7
  gosub 0x968A;  // 0x94C0
  print('   - CITYWARD -');  // 0x94C4
  print_return();  // 0x94D3
  print('- AIR-CONDITIONING -');  // 0x94D4
  printclear('PARTS FOR A GIANT VENTILATOR FAN ARE HERE.');  // 0x952E
  // 0x9553-0x955C
  area2.event_scratch0 = 2 & area1.event_word_2E6;  // 0x9553
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x955D
  }
  setup_monster(sprite_id: 61 max_distance: 0 pic_id: 255);  // 0x955E
  exit_event();  // 0x9565
}
```

## Event 26

- Target: `0x949E`
- Text hint: 'EAST' 'NORTH' 'NORTHERN'

```text
event 26 {
  gosub 0x9646;  // 0x949E
  print('EAST');  // 0x94A2
  gosub 0x9663;  // 0x94A8
  print('NORTH');  // 0x94AC
  gosub 0x9678;  // 0x94B3
  print('NORTHERN');  // 0x94B7
  gosub 0x968A;  // 0x94C0
  print('   - CITYWARD -');  // 0x94C4
  print_return();  // 0x94D3
  print('- AIR-CONDITIONING -');  // 0x94D4
  printclear('PARTS FOR A GIANT VENTILATOR FAN ARE HERE.');  // 0x952E
  // 0x9553-0x955C
  area2.event_scratch0 = 2 & area1.event_word_2E6;  // 0x9553
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x955D
  }
  setup_monster(sprite_id: 61 max_distance: 0 pic_id: 255);  // 0x955E
  exit_event();  // 0x9565
}
```

## Event 27

- Target: `0x952E`
- Text hint: 'PARTS FOR A GIANT VENTILATOR FAN ARE HERE.'

```text
event 27 {
  printclear('PARTS FOR A GIANT VENTILATOR FAN ARE HERE.');  // 0x952E
  // 0x9553-0x955C
  area2.event_scratch0 = 2 & area1.event_word_2E6;  // 0x9553
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x955D
  }
  setup_monster(sprite_id: 61 max_distance: 0 pic_id: 255);  // 0x955E
  exit_event();  // 0x9565
}
```

## Event 28

- Target: `0x9553`
- Text hint: 'NORTH' 'EAST' 'EASTERN'

```text
event 28 {
  // 0x9553-0x955C
  area2.event_scratch0 = 2 & area1.event_word_2E6;  // 0x9553
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x955D
  }
  setup_monster(sprite_id: 61 max_distance: 0 pic_id: 255);  // 0x955E
  exit_event();  // 0x9565
}
```

## Event 29

- Target: `0x95FC`
- Text hint: 'NORTH' 'EAST' 'EASTERN'

```text
event 29 {
  gosub 0x9646;  // 0x95FC
  print('NORTH');  // 0x9600
  gosub 0x9663;  // 0x9607
  print('EAST');  // 0x960B
  gosub 0x9678;  // 0x9611
  print('EASTERN');  // 0x9615
  gosub 0x968A;  // 0x961E
  print('   - CITYWARD -');  // 0x9622
  print_return();  // 0x9631
  print('- SUPPLY CONVEYOR -');  // 0x9632
  printclear('THE TUNNELS SLANT UPWARDS TO THE ');  // 0x9646
  return;  // 0x9662
}
```

## Event 30

- Target: `0x969A`
- Text hint: 'YOU COME ACROSS SOME LOWLANDER MINERS. WITH THEIR BACKS TO YOU, THEY ARE STUDYING THE SOUTH WALL.'

```text
event 30 {
  // 0x969A-0x96A3
  area2.event_scratch0 = 4 & area1.event_word_2E6;  // 0x969A
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x96A4
  }
  printclear('YOU COME ACROSS SOME LOWLANDER MINERS. WITH THEIR BACKS TO YOU, THEY ARE STUDYING THE SOUTH WALL.');  // 0x96A5
  sprite(OFF);  // 0x96F1
  exit_event();  // 0x96F5
}
```

## Event 31

- Target: `0x986B`
- Text hint: 'URSADDERS AMBUSH YOU!'

```text
event 31 {
  // 0x986B-0x9874
  area2.event_scratch0 = 8 & area1.event_word_2E6;  // 0x986B
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9875
  }
  setup_monster(sprite_id: 61 max_distance: 0 pic_id: 255);  // 0x9876
  exit_event();  // 0x987D
}
```

## Event 32

- Target: `0x899B`
- Text hint: "'INTRUDER ALERT! TO ARMSS! TO ARMSS!'" "A SPEAKER NEAR YOU CRACKLES INTO LIFE. SCOT.DOS' VOICE ISSUES FORTH." "'TRACKING INTRUDERSS! QUADRANT 4 PERIMETER ALARM TRIPPED!'"

```text
event 32 {
  // 0x899B-0x89A4
  area2.event_scratch0 = 8 & area1.event_word_2E6;  // 0x899B
  if (area2.event_scratch0 == 0) {
    exit_event();  // 0x89A5
  }
  // 0x89A6-0x89AC
  if (area1.event_word_2EE == 1) {
    exit_event();  // 0x89AD
  }
  random(area2.event_scratch0 = random 1..99);  // 0x89AE
  // 0x89B4-0x89BA
  if (area2.event_scratch0 < 10) {
    exit_event();  // 0x89BB
  }
  // 0x89BC-0x89C2
  if (area1.event_word_214 < 3) {
    exit_event();  // 0x89C3
  }
  area2.event_scratch0 = area1.event_word_214;  // 0x89C4
  add(area1.event_word_214 = 1 + area1.event_word_214);  // 0x89CB
  // 0x89D4
  switch (area2.event_scratch0) {
    case 0: goto 0x89E6;
      // case 0 body
      gosub 0xA380;  // 0x89E6
      print("'INTRUDER ALERT! TO ARMSS! TO ARMSS!'");  // 0x89EA
      printclear("A SPEAKER NEAR YOU CRACKLES INTO LIFE. SCOT.DOS' VOICE ISSUES FORTH.");  // 0x8A0B
      gosub 0xA380;  // 0x8AD4
      print("'TRACKING INTRUDERSS! QUADRANT 4 PERIMETER ALARM TRIPPED!'");  // 0x8AD8
      gosub 0xA380;  // 0x8B09
      print("'BATTLE PLAN 7 DRILL! REPEAT, PLAN 7 DRILL!'");  // 0x8B0D
      // 0x8B33-0x8B39
      if (area1.event_word_2EE == 1) {
        goto 0x8B8E;  // 0x8B3A
        // branch body 0x8B8E
        // 0x8B8E-0x8B94
        if (mapDirection != 3) {
          exit_event();  // 0x8B95
        }
        printclear('THE ELEVATOR HAS BEEN DAMAGED IN THE EXPLOSION.');  // 0x8B96
        // 0x8C7F-0x8C85
        if (mapDirection != 2) {
          exit_event();  // 0x8C86
        }
        printclear('AN ELEVATOR UP. DO YOU GO?');  // 0x8C87
        // 0x8CCB-0x8CD4
        area2.event_scratch0 = 64 & area1.event_word_2E6;  // 0x8CCB
        if (area2.event_scratch0 != 0) {
          exit_event();  // 0x8CD5
        }
        or(area1.event_word_2E6 = 64 | area1.event_word_2E6);  // 0x8CD6
        printclear('THE BLOODY TRAIL LEADS DOWN THE TUNNEL TO THE NORTH.');  // 0x8CDF
        // 0x8D0B-0x8D14
        area2.event_scratch0 = 2 & area1.event_word_2E8;  // 0x8D0B
        if (area2.event_scratch0 == 0) {
          exit_event();  // 0x8D15
        }
        printclear('TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.');  // 0x8D16
        exit_event();  // 0x8D4B
      }
      printclear('THERE IS A DOWN ELEVATOR HERE. DO YOU USE IT?');  // 0x8B3E
      // 0x8B8E-0x8B94
      if (mapDirection != 3) {
        exit_event();  // 0x8B95
      }
      printclear('THE ELEVATOR HAS BEEN DAMAGED IN THE EXPLOSION.');  // 0x8B96
      // truncated at 0x8C7F
    case 1: goto 0x8A0B;
      // case 1 body
      printclear("A SPEAKER NEAR YOU CRACKLES INTO LIFE. SCOT.DOS' VOICE ISSUES FORTH.");  // 0x8A0B
      gosub 0xA380;  // 0x8AD4
      print("'TRACKING INTRUDERSS! QUADRANT 4 PERIMETER ALARM TRIPPED!'");  // 0x8AD8
      gosub 0xA380;  // 0x8B09
      print("'BATTLE PLAN 7 DRILL! REPEAT, PLAN 7 DRILL!'");  // 0x8B0D
      // 0x8B33-0x8B39
      if (area1.event_word_2EE == 1) {
        goto 0x8B8E;  // 0x8B3A
        // branch body 0x8B8E
        // target 0x8B8E already emitted
      }
      printclear('THERE IS A DOWN ELEVATOR HERE. DO YOU USE IT?');  // 0x8B3E
      // 0x8B8E-0x8B94
      if (mapDirection != 3) {
        exit_event();  // 0x8B95
      }
      printclear('THE ELEVATOR HAS BEEN DAMAGED IN THE EXPLOSION.');  // 0x8B96
      // 0x8C7F-0x8C85
      if (mapDirection != 2) {
        exit_event();  // 0x8C86
      }
      printclear('AN ELEVATOR UP. DO YOU GO?');  // 0x8C87
      // truncated at 0x8CCB
    case 2: goto 0x8AD4;
      // case 2 body
      gosub 0xA380;  // 0x8AD4
      print("'TRACKING INTRUDERSS! QUADRANT 4 PERIMETER ALARM TRIPPED!'");  // 0x8AD8
      gosub 0xA380;  // 0x8B09
      print("'BATTLE PLAN 7 DRILL! REPEAT, PLAN 7 DRILL!'");  // 0x8B0D
      // 0x8B33-0x8B39
      if (area1.event_word_2EE == 1) {
        goto 0x8B8E;  // 0x8B3A
        // branch body 0x8B8E
        // target 0x8B8E already emitted
      }
    case 3: goto 0x8B09;
  }
}
```

## Event 33

- Target: `0x9943`
- Text hint: 'URSADDERS AMBUSH YOU!'

```text
event 33 {
  // 0x9943-0x994C
  area2.event_scratch0 = 16 & area1.event_word_2E6;  // 0x9943
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x994D
  }
  or(area1.event_word_2E6 = 16 | area1.event_word_2E6);  // 0x994E
  area1.event_word_2EE = 1;  // 0x9957
  setup_monster(sprite_id: 61 max_distance: 1 pic_id: 255);  // 0x995D
  exit_event();  // 0x9964
}
```

## Event 34

- Target: `0xA0D0`
- Text hint: 'URSADDERS AMBUSH YOU!'

```text
event 34 {
  // 0xA0D0-0xA0D9
  area2.event_scratch0 = 128 & area1.event_word_2E6;  // 0xA0D0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0xA0DA
  }
  printclear('URSADDERS AMBUSH YOU!');  // 0xA0DB
  setup_monster(sprite_id: 41 max_distance: 1 pic_id: 255);  // 0xA0EE
  exit_event();  // 0xA0F5
}
```

## Event 35

- Target: `0xA129`
- Text hint: 'LLOROK LIES HERE NEAR DEATH. HE NEEDS THE ATTENTION OF A LOWLANDER MEDIC. DO YOU BRING HIM WITH YOU?'

```text
event 35 {
  // 0xA129-0xA132
  area2.event_scratch0 = 1 & area1.event_word_2E8;  // 0xA129
  if (area2.event_scratch0 != 0) {
    goto 0xA1B2;  // 0xA133
    // branch body 0xA1B2
    // 0xA1B2-0xA1B8
    if (area1.event_word_2F2 == 1) {
      exit_event();  // 0xA1B9
    }
    // 0xA1BA-0xA1C3
    area2.event_scratch0 = 2 & area1.event_word_2E8;  // 0xA1BA
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0xA1C4
    }
    printclear('LLOROK LIES HERE NEAR DEATH. HE NEEDS THE ATTENTION OF A LOWLANDER MEDIC. DO YOU BRING HIM WITH YOU?');  // 0xA1C5
    // 0xA23E-0xA244
    if (area1.event_word_2F4 <= 3) {
      exit_event();  // 0xA245
    }
    random(area2.event_scratch0 = random 1..99);  // 0xA246
    // 0xA24C-0xA252
    if (area2.event_scratch0 < 15) {
      exit_event();  // 0xA253
    }
    setup_monster(sprite_id: 41 max_distance: 0 pic_id: 255);  // 0xA254
    exit_event();  // 0xA25B
  }
  exit_event();  // 0xA138
}
```

## Event 36

- Target: `0xA23E`
- Text hint: 'NORTH' 'SOUTH AND WEST' 'SOUTHERN'

```text
event 36 {
  // 0xA23E-0xA244
  if (area1.event_word_2F4 <= 3) {
    exit_event();  // 0xA245
  }
  random(area2.event_scratch0 = random 1..99);  // 0xA246
  // 0xA24C-0xA252
  if (area2.event_scratch0 < 15) {
    exit_event();  // 0xA253
  }
  setup_monster(sprite_id: 41 max_distance: 0 pic_id: 255);  // 0xA254
  exit_event();  // 0xA25B
}
```

## Event 37

- Target: `0xA27D`
- Text hint: 'NORTH' 'SOUTH AND WEST' 'SOUTHERN'

```text
event 37 {
  random(area2.event_scratch0 = random 1..99);  // 0xA27D
  // 0xA283-0xA289
  if (area2.event_scratch0 < 15) {
    exit_event();  // 0xA28A
  }
  setup_monster(sprite_id: 61 max_distance: 2 pic_id: 255);  // 0xA28B
  exit_event();  // 0xA292
}
```

## Event 38

- Target: `0xA2ED`
- Text hint: 'NORTH' 'SOUTH AND WEST' 'SOUTHERN'

```text
event 38 {
  gosub 0x9646;  // 0xA2ED
  print('NORTH');  // 0xA2F1
  gosub 0x9663;  // 0xA2F8
  print('SOUTH AND WEST');  // 0xA2FC
  gosub 0x9678;  // 0xA30A
  print('SOUTHERN');  // 0xA30E
  gosub 0x968A;  // 0xA317
  print('   - SURFACE-WARD -');  // 0xA31B
  print_return();  // 0xA32D
  print('- SUPPLY CONVEYOR, ');  // 0xA32E
  // 0xA340-0xA346
  if (39 == area2.event_scratch1) {
    print('UP -');  // 0xA347
  }
  if_<>(<if compare flag is false, skip next op>);  // 0xA34D
  print('DOWN -');  // 0xA34E
  printclear('A VOICE BLARES OUT OF A SPEAKER. ');  // 0xA380
  exit_event();  // 0xA39D
}
```
