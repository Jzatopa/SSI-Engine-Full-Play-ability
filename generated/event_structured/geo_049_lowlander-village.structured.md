# GEO 49: Lowlander Village

ECL block: `49`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8B33`
- Text hint: 'THERE IS A DOWN ELEVATOR HERE. DO YOU USE IT?'

```text
event 01 {
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

## Event 05

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 05 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 06

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 06 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 07

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 07 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 08

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 08 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 09

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 09 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 10

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 10 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 11

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 11 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 12

- Target: `0x8D4C`
- Text hint: 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'

```text
event 12 {
  subtract(area2.event_scratch1 = area2.event_scratch1 - 5);  // 0x8D4C
  gettable(area1.event_word_20A = abs_A370[area2.event_scratch1]);  // 0x8D55
  gettable(area1.event_word_206 = abs_A378[area2.event_scratch1]);  // 0x8D5F
  // 0x8D69-0x8D70
  if (mapDirection != area1.event_word_20A) {
    exit_event();  // 0x8D71
  }
  // 0x8D72-0x8D7C
  area2.event_scratch0 = area1.event_word_206 & area1.event_word_2EA;  // 0x8D72
  if (area2.event_scratch0 != 0) {
    goto 0x8FF7;  // 0x8D7D
    // branch body 0x8FF7
    printclear("YOU'VE ALREADY SEARCHED THIS HUT.");  // 0x8FF7
    add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
    exit_event();  // 0x901F
  }
  or(area1.event_word_2EA = area1.event_word_206 | area1.event_word_2EA);  // 0x8D81
  // 0x8D8B
  switch (area1.event_word_2EC) {
    case 0: goto 0x8DA9;
      // case 0 body
      printclear('IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.');  // 0x8DA9
      goto 0x9015;  // 0x8DFE
      // branch body 0x9015
        add(area1.event_word_2EC = 1 + area1.event_word_2EC);  // 0x9015
        exit_event();  // 0x901F
    case 1: goto 0x8FC9;
      // case 1 body
      printclear('YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.');  // 0x8FC9
      goto 0x9015;  // 0x8FF3
      // branch body 0x9015
        // target 0x9015 already emitted
    case 2: goto 0x8E02;
      // case 2 body
      printclear('A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.');  // 0x8E02
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 3: goto 0x8FC9;
      // case 3 body
      // target 0x8FC9 already emitted
    case 4: goto 0x8EBB;
      // case 4 body
      printclear('A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.');  // 0x8EBB
      goto 0x9015;  // 0x8F15
      // branch body 0x9015
        // target 0x9015 already emitted
    case 5: goto 0x8FC9;
      // case 5 body
      // target 0x8FC9 already emitted
    case 6: goto 0x8F19;
      // case 6 body
      printclear('A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?');  // 0x8F19
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
    case 7: goto 0x8F62;
      // case 7 body
      printclear('YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.');  // 0x8F62
      goto 0x9015;  // 0x8FC5
      // branch body 0x9015
        // target 0x9015 already emitted
  }
}
```

## Event 13

- Target: `0x9020`
- Text hint: 'THE WOODEN WALLS HERE ARE MADE OF MILLED WOOD. THE AREA IS FREE OF PRIMITIVE TRAPPINGS.'

```text
event 13 {
  // 0x9020-0x9026
  if (mapDirection != 3) {
    exit_event();  // 0x9027
  }
  // 0x9028-0x9031
  area2.event_scratch0 = 8 & area1.event_word_2E4;  // 0x9028
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9032
  }
  printclear('THE WOODEN WALLS HERE ARE MADE OF MILLED WOOD. THE AREA IS FREE OF PRIMITIVE TRAPPINGS.');  // 0x9033
  or(area1.event_word_2E4 = 8 | area1.event_word_2E4);  // 0x9078
  // 0x9082-0x9088
  if (mapDirection != 2) {
    exit_event();  // 0x9089
  }
  gosub 0x90F3;  // 0x908A
  print('VENUSIAN DINOSAUR HIDE SHIELDS.');  // 0x908E
  // 0x90AB-0x90B1
  if (mapDirection != 3) {
    exit_event();  // 0x90B2
  }
  gosub 0x90F3;  // 0x90B3
  print('CRYSTAL TIPPED SPEARS.');  // 0x90B7
  // 0x90CD-0x90D3
  if (mapDirection != 1) {
    exit_event();  // 0x90D4
  }
  gosub 0x90F3;  // 0x90D5
  print('WOVEN PLANT FIBER HUT WALLS.');  // 0x90D9
  printclear('THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING ');  // 0x90F3
  return;  // 0x9144
}
```

## Event 14

- Target: `0x9082`
- Text hint: 'VENUSIAN DINOSAUR HIDE SHIELDS.'

```text
event 14 {
  // 0x9082-0x9088
  if (mapDirection != 2) {
    exit_event();  // 0x9089
  }
  gosub 0x90F3;  // 0x908A
  print('VENUSIAN DINOSAUR HIDE SHIELDS.');  // 0x908E
  // 0x90AB-0x90B1
  if (mapDirection != 3) {
    exit_event();  // 0x90B2
  }
  gosub 0x90F3;  // 0x90B3
  print('CRYSTAL TIPPED SPEARS.');  // 0x90B7
  // 0x90CD-0x90D3
  if (mapDirection != 1) {
    exit_event();  // 0x90D4
  }
  gosub 0x90F3;  // 0x90D5
  print('WOVEN PLANT FIBER HUT WALLS.');  // 0x90D9
  printclear('THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING ');  // 0x90F3
  return;  // 0x9144
}
```

## Event 15

- Target: `0x90AB`
- Text hint: 'CRYSTAL TIPPED SPEARS.'

```text
event 15 {
  // 0x90AB-0x90B1
  if (mapDirection != 3) {
    exit_event();  // 0x90B2
  }
  gosub 0x90F3;  // 0x90B3
  print('CRYSTAL TIPPED SPEARS.');  // 0x90B7
  // 0x90CD-0x90D3
  if (mapDirection != 1) {
    exit_event();  // 0x90D4
  }
  gosub 0x90F3;  // 0x90D5
  print('WOVEN PLANT FIBER HUT WALLS.');  // 0x90D9
  printclear('THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING ');  // 0x90F3
  return;  // 0x9144
}
```

## Event 16

- Target: `0x90CD`
- Text hint: 'WOVEN PLANT FIBER HUT WALLS.' 'THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING '

```text
event 16 {
  // 0x90CD-0x90D3
  if (mapDirection != 1) {
    exit_event();  // 0x90D4
  }
  gosub 0x90F3;  // 0x90D5
  print('WOVEN PLANT FIBER HUT WALLS.');  // 0x90D9
  printclear('THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING ');  // 0x90F3
  return;  // 0x9144
}
```

## Event 17

- Target: `0x9145`
- Text hint: 'YOU ENTER A SMALL WAREHOUSE. BUNDLES OF SPEARS, SHIELDS AND HUT WALL SECTIONS ARE STORED HERE, READY FOR SHIPPING.'

```text
event 17 {
  // 0x9145-0x914B
  if (mapDirection != 1) {
    exit_event();  // 0x914C
  }
  printclear('YOU ENTER A SMALL WAREHOUSE. BUNDLES OF SPEARS, SHIELDS AND HUT WALL SECTIONS ARE STORED HERE, READY FOR SHIPPING.');  // 0x914D
  // 0x91A8-0x91B1
  area2.event_scratch0 = 16 & area1.event_word_2E4;  // 0x91A8
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x91B2
  }
  printclear('THESE ROOMS ARE FULL OF LOCKERS. MOST CONTAIN LOWLANDER NATIVE GARB. A FEW HOLD MACHINE-WOVEN OVERALLS, TOUGH PLASTIC BOOTS, AND HARD HATS WITH MINING LAMPS.');  // 0x91B3
  // 0x9237-0x923D
  if (mapDirection != 0) {
    exit_event();  // 0x923E
  }
  print("A SIGN READS, 'HEAVY ELEVATOR.' THERE ARE NO CONTROLS HERE.");  // 0x923F
  // 0x9271-0x9277
  if (mapDirection != 0) {
    exit_event();  // 0x9278
  }
  printclear('A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.');  // 0x9279
  // 0x92D5-0x92DB
  if (mapDirection != 0) {
    exit_event();  // 0x92DC
  }
  printclear("THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND.");  // 0x92DD
  // 0x932C-0x9332
  if (mapDirection != 0) {
    exit_event();  // 0x9333
  }
  printclear('HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.');  // 0x9334
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // truncated at 0x93E4
}
```

## Event 18

- Target: `0x91A8`
- Text hint: 'THESE ROOMS ARE FULL OF LOCKERS. MOST CONTAIN LOWLANDER NATIVE GARB. A FEW HOLD MACHINE-WOVEN OVERALLS, TOUGH PLASTIC BOOTS, AND HARD HATS WITH MINING LAMPS.'

```text
event 18 {
  // 0x91A8-0x91B1
  area2.event_scratch0 = 16 & area1.event_word_2E4;  // 0x91A8
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x91B2
  }
  printclear('THESE ROOMS ARE FULL OF LOCKERS. MOST CONTAIN LOWLANDER NATIVE GARB. A FEW HOLD MACHINE-WOVEN OVERALLS, TOUGH PLASTIC BOOTS, AND HARD HATS WITH MINING LAMPS.');  // 0x91B3
  // 0x9237-0x923D
  if (mapDirection != 0) {
    exit_event();  // 0x923E
  }
  print("A SIGN READS, 'HEAVY ELEVATOR.' THERE ARE NO CONTROLS HERE.");  // 0x923F
  // 0x9271-0x9277
  if (mapDirection != 0) {
    exit_event();  // 0x9278
  }
  printclear('A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.');  // 0x9279
  // 0x92D5-0x92DB
  if (mapDirection != 0) {
    exit_event();  // 0x92DC
  }
  printclear("THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND.");  // 0x92DD
  // 0x932C-0x9332
  if (mapDirection != 0) {
    exit_event();  // 0x9333
  }
  printclear('HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.');  // 0x9334
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
  // truncated at 0x9432
}
```

## Event 19

- Target: `0x9237`
- Text hint: "A SIGN READS, 'HEAVY ELEVATOR.' THERE ARE NO CONTROLS HERE."

```text
event 19 {
  // 0x9237-0x923D
  if (mapDirection != 0) {
    exit_event();  // 0x923E
  }
  print("A SIGN READS, 'HEAVY ELEVATOR.' THERE ARE NO CONTROLS HERE.");  // 0x923F
  // 0x9271-0x9277
  if (mapDirection != 0) {
    exit_event();  // 0x9278
  }
  printclear('A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.');  // 0x9279
  // 0x92D5-0x92DB
  if (mapDirection != 0) {
    exit_event();  // 0x92DC
  }
  printclear("THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND.");  // 0x92DD
  // 0x932C-0x9332
  if (mapDirection != 0) {
    exit_event();  // 0x9333
  }
  printclear('HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.');  // 0x9334
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
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
  // truncated at 0x94B7
}
```

## Event 20

- Target: `0x9271`
- Text hint: 'A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.'

```text
event 20 {
  // 0x9271-0x9277
  if (mapDirection != 0) {
    exit_event();  // 0x9278
  }
  printclear('A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.');  // 0x9279
  // 0x92D5-0x92DB
  if (mapDirection != 0) {
    exit_event();  // 0x92DC
  }
  printclear("THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND.");  // 0x92DD
  // 0x932C-0x9332
  if (mapDirection != 0) {
    exit_event();  // 0x9333
  }
  printclear('HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.');  // 0x9334
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
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
  // truncated at 0x952E
}
```

## Event 21

- Target: `0x92D5`
- Text hint: "THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND."

```text
event 21 {
  // 0x92D5-0x92DB
  if (mapDirection != 0) {
    exit_event();  // 0x92DC
  }
  printclear("THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND.");  // 0x92DD
  // 0x932C-0x9332
  if (mapDirection != 0) {
    exit_event();  // 0x9333
  }
  printclear('HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.');  // 0x9334
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
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
  // truncated at 0x955E
}
```

## Event 22

- Target: `0x932C`
- Text hint: 'HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.'

```text
event 22 {
  // 0x932C-0x9332
  if (mapDirection != 0) {
    exit_event();  // 0x9333
  }
  printclear('HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.');  // 0x9334
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
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

## Event 23

- Target: `0x9365`
- Text hint: 'THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:' RETURN

```text
event 23 {
  // 0x9365-0x936E
  area2.event_scratch0 = 32 & area1.event_word_2E4;  // 0x9365
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x936F
  }
  printclear('THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:');  // 0x9370
  print_return();  // 0x93A6
  print('    - TERMINAL INACTIVE -');  // 0x93A7
  print_return();  // 0x93BD
  print('- CONTROL ROUTED TO STATION B -');  // 0x93BE
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
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

## Event 24

- Target: `0x93E4`
- Text hint: 'LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.'

```text
event 24 {
  // 0x93E4-0x93EA
  if (mapDirection != 2) {
    exit_event();  // 0x93EB
  }
  printclear('LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.');  // 0x93EC
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
