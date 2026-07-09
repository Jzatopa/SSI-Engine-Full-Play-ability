# GEO 66: RAM Battler, Deimos Level 19-41

ECL block: `66`

Structured first-pass pseudocode. This is reconstructed analysis, not original source.

## Event 01

- Target: `0x8283`
- Text hint: 'THIS LADDER LEADS DOWN TO THE COMPUTER LEVEL.' RETURN

```text
event 01 {
  // 0x8283-0x8289
  if (area1.event_word_21E == 1) {
    goto 0x84E5;  // 0x828A
    // branch body 0x84E5
    area1.event_word_220 = 1;  // 0x84E5
    printclear('THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.');  // 0x84EB
    // 0x852B-0x8534
    area2.event_scratch0 = 8 & area1.event_word_212;  // 0x852B
    if (area2.event_scratch0 != 0) {
      printclear('SPARKS RAIN FROM THIS SHORTED PANEL.');  // 0x8535
    }
    if_<>(<if compare flag is false, skip next op>);  // 0x8553
    exit_event();  // 0x8554
  }
  // 0x828E-0x8297
  area2.event_scratch0 = 1 & area1.event_word_212;  // 0x828E
  if (area2.event_scratch0 == 0) {
    printclear('THIS LADDER LEADS DOWN TO THE COMPUTER LEVEL.');  // 0x8298
  }
  if_=(<if compare flag is false, skip next op>);  // 0x82BD
  print_return();  // 0x82BE
  if_=(<if compare flag is false, skip next op>);  // 0x82BF
  print_return();  // 0x82C0
  print('DO YOU DESCEND? ');  // 0x82C1
  // 0x82EF-0x82F5
  if (area1.event_word_21C == 4) {
    goto 0x83C1;  // 0x82F6
    // branch body 0x83C1
    printclear('A FIREBALL ENGULFS YOU AS THE SHIP EXPLODES.');  // 0x83C1
    exit_event();  // 0x83E6
  }
  // 0x82FA-0x8303
  area2.event_scratch0 = 2 & area1.event_word_212;  // 0x82FA
  if (area2.event_scratch0 == 0) {
    printclear("THE COMPUTER BLARES, 'PROBABILITY OF VESSEL DESTRUCTION IS 99%. ADVISE IMMEDIATE EVACUATION.'");  // 0x8304
  }
  if_=(<if compare flag is false, skip next op>);  // 0x834D
  printclear("'AIR LOCK'");  // 0x834F
  print_return();  // 0x835A
  print_return();  // 0x835B
  print_return();  // 0x835C
  print('USE THE ESCAPE POD?');  // 0x835D
  // 0x836F-0x8379
  area1.event_word_212 = 2 | area1.event_word_212;  // 0x836F
  if (area1.event_word_212 != 0) {
    add(area1.event_word_21C = 1 + area1.event_word_21C);  // 0x837A
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8383
  exit_event();  // 0x8384
}
```

## Event 02

- Target: `0x82EF`
- Text hint: "THE COMPUTER BLARES, 'PROBABILITY OF VESSEL DESTRUCTION IS 99%. ADVISE IMMEDIATE EVACUATION.'" "'AIR LOCK'" RETURN

```text
event 02 {
  // 0x82EF-0x82F5
  if (area1.event_word_21C == 4) {
    goto 0x83C1;  // 0x82F6
    // branch body 0x83C1
    printclear('A FIREBALL ENGULFS YOU AS THE SHIP EXPLODES.');  // 0x83C1
    exit_event();  // 0x83E6
  }
  // 0x82FA-0x8303
  area2.event_scratch0 = 2 & area1.event_word_212;  // 0x82FA
  if (area2.event_scratch0 == 0) {
    printclear("THE COMPUTER BLARES, 'PROBABILITY OF VESSEL DESTRUCTION IS 99%. ADVISE IMMEDIATE EVACUATION.'");  // 0x8304
  }
  if_=(<if compare flag is false, skip next op>);  // 0x834D
  printclear("'AIR LOCK'");  // 0x834F
  print_return();  // 0x835A
  print_return();  // 0x835B
  print_return();  // 0x835C
  print('USE THE ESCAPE POD?');  // 0x835D
  // 0x836F-0x8379
  area1.event_word_212 = 2 | area1.event_word_212;  // 0x836F
  if (area1.event_word_212 != 0) {
    add(area1.event_word_21C = 1 + area1.event_word_21C);  // 0x837A
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8383
  exit_event();  // 0x8384
}
```

## Event 03

- Target: `0x83FB`
- Text hint: 'THIS LADDER LEADS UP TO THE CONTROL LEVEL.' RETURN

```text
event 03 {
  // 0x83FB-0x8404
  area2.event_scratch0 = 4 & area1.event_word_212;  // 0x83FB
  if (area2.event_scratch0 == 0) {
    printclear('THIS LADDER LEADS UP TO THE CONTROL LEVEL.');  // 0x8405
  }
  if_=(<if compare flag is false, skip next op>);  // 0x8428
  print_return();  // 0x8429
  if_=(<if compare flag is false, skip next op>);  // 0x842A
  print_return();  // 0x842B
  print('CLIMB UP? ');  // 0x842C
  area1.event_word_220 = 1;  // 0x84E5
  printclear('THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.');  // 0x84EB
  // 0x852B-0x8534
  area2.event_scratch0 = 8 & area1.event_word_212;  // 0x852B
  if (area2.event_scratch0 != 0) {
    printclear('SPARKS RAIN FROM THIS SHORTED PANEL.');  // 0x8535
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8553
  exit_event();  // 0x8554
}
```

## Event 04

- Target: `0x84E5`
- Text hint: 'THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.' 'SPARKS RAIN FROM THIS SHORTED PANEL.'

```text
event 04 {
  area1.event_word_220 = 1;  // 0x84E5
  printclear('THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.');  // 0x84EB
  // 0x852B-0x8534
  area2.event_scratch0 = 8 & area1.event_word_212;  // 0x852B
  if (area2.event_scratch0 != 0) {
    printclear('SPARKS RAIN FROM THIS SHORTED PANEL.');  // 0x8535
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8553
  exit_event();  // 0x8554
}
```

## Event 05

- Target: `0x852B`
- Text hint: 'SPARKS RAIN FROM THIS SHORTED PANEL.'

```text
event 05 {
  // 0x852B-0x8534
  area2.event_scratch0 = 8 & area1.event_word_212;  // 0x852B
  if (area2.event_scratch0 != 0) {
    printclear('SPARKS RAIN FROM THIS SHORTED PANEL.');  // 0x8535
  }
  if_<>(<if compare flag is false, skip next op>);  // 0x8553
  exit_event();  // 0x8554
}
```

## Event 06

- Target: `0x8A10`
- Text hint: "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES."

```text
event 06 {
  picture(block_id: 30);  // 0x8A10
  printclear("'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES.");  // 0x8A13
  // truncated at 0x8EB0
}
```

## Event 07

- Target: `0x8EB0`
- Text hint: 'THERE IS A SHUFFLE ON THE OTHER SIDE OF THE PRISON DOOR. A VOICE WHISPERS, '

```text
event 07 {
  // 0x8EB0-0x8EB9
  area2.event_scratch0 = 32 & area1.event_word_212;  // 0x8EB0
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8EBA
  }
  area1.event_word_21A = 2;  // 0x8EBB
  or(area1.event_word_212 = 32 | area1.event_word_212);  // 0x8EC1
  printclear('THERE IS A SHUFFLE ON THE OTHER SIDE OF THE PRISON DOOR. A VOICE WHISPERS, ');  // 0x8ECA
  // 0x8F06-0x8F0C
  if (area1.event_word_3C0 == 1) {
    goto 0x8F7C;  // 0x8F0D
    // branch body 0x8F7C
    print("'KANE TOLD US TO EXPECT YOU. WE SMUGGLED IN YOUR WEAPONS. DON'T FORGET THE DEAL.");  // 0x8F7C
    // 0x909C-0x90A2
    if (area1.event_word_230 == 1) {
      exit_event();  // 0x90A3
    }
    printclear('THIS DOOR REQUIRES A RAM SECURITY PASSCARD. ');  // 0x90A4
    // 0x90C8-0x90CE
    if (area1.event_word_22C == 1) {
      print('YOU DO NOT HAVE THE ONE IT REQUIRES.');  // 0x90CF
    }
    area1.event_word_230 = 0;  // 0x90F5
    area1.event_word_224 = 0;  // 0x90FB
    area1.event_word_222 = 0;  // 0x9101
    compare_and(Values: 0 == mapPosX && 4 == mapPosY);  // 0x9107
    if_=(<if compare flag is false, skip next op>);  // 0x9112
    area1.event_word_21A = 2;  // 0x9113
    compare_and(Values: 9 == mapPosX && 1 == mapPosY);  // 0x9119
    if_=(<if compare flag is false, skip next op>);  // 0x9124
    area1.event_word_21A = 4;  // 0x9125
    compare_and(Values: 6 == mapPosX && 5 == mapPosY);  // 0x912B
    if_=(<if compare flag is false, skip next op>);  // 0x9136
    area1.event_word_21A = 4;  // 0x9137
    compare_and(Values: 4 == mapPosX && 5 == mapPosY);  // 0x913D
    if_=(<if compare flag is false, skip next op>);  // 0x9148
    area1.event_word_21A = 4;  // 0x9149
    compare_and(Values: 7 == mapPosX && 12 == mapPosY);  // 0x914F
    if_=(<if compare flag is false, skip next op>);  // 0x915A
    area1.event_word_21A = 4;  // 0x915B
    compare_and(Values: 15 == mapPosX && 3 == mapPosY);  // 0x9161
    if_=(<if compare flag is false, skip next op>);  // 0x916C
    area1.event_word_21A = 3;  // 0x916D
    compare_and(Values: 3 == mapPosX && 2 == mapPosY);  // 0x9173
    if_=(<if compare flag is false, skip next op>);  // 0x917E
    area1.event_word_21A = 5;  // 0x917F
    compare_and(Values: 4 == mapPosX && 4 == mapPosY);  // 0x9185
    if_=(<if compare flag is false, skip next op>);  // 0x9190
    area1.event_word_21A = 5;  // 0x9191
    exit_event();  // 0x9197
  }
  print("'YOU'RE IN THE RAM BATTLER, DEIMOS. MY CODE NAME IS OILER. I'M WITH NEO. I NEED YOUR HELP.'");  // 0x8F11
  print("'KANE TOLD US TO EXPECT YOU. WE SMUGGLED IN YOUR WEAPONS. DON'T FORGET THE DEAL.");  // 0x8F7C
  // 0x909C-0x90A2
  if (area1.event_word_230 == 1) {
    exit_event();  // 0x90A3
  }
  printclear('THIS DOOR REQUIRES A RAM SECURITY PASSCARD. ');  // 0x90A4
  // 0x90C8-0x90CE
  if (area1.event_word_22C == 1) {
    print('YOU DO NOT HAVE THE ONE IT REQUIRES.');  // 0x90CF
  }
  area1.event_word_230 = 0;  // 0x90F5
  area1.event_word_224 = 0;  // 0x90FB
  area1.event_word_222 = 0;  // 0x9101
  compare_and(Values: 0 == mapPosX && 4 == mapPosY);  // 0x9107
  if_=(<if compare flag is false, skip next op>);  // 0x9112
  area1.event_word_21A = 2;  // 0x9113
  compare_and(Values: 9 == mapPosX && 1 == mapPosY);  // 0x9119
  if_=(<if compare flag is false, skip next op>);  // 0x9124
  area1.event_word_21A = 4;  // 0x9125
  compare_and(Values: 6 == mapPosX && 5 == mapPosY);  // 0x912B
  // truncated at 0x9136
}
```

## Event 08

- Target: `0x909C`
- Text hint: 'THIS DOOR REQUIRES A RAM SECURITY PASSCARD. ' 'YOU DO NOT HAVE THE ONE IT REQUIRES.'

```text
event 08 {
  // 0x909C-0x90A2
  if (area1.event_word_230 == 1) {
    exit_event();  // 0x90A3
  }
  printclear('THIS DOOR REQUIRES A RAM SECURITY PASSCARD. ');  // 0x90A4
  // 0x90C8-0x90CE
  if (area1.event_word_22C == 1) {
    print('YOU DO NOT HAVE THE ONE IT REQUIRES.');  // 0x90CF
  }
  area1.event_word_230 = 0;  // 0x90F5
  area1.event_word_224 = 0;  // 0x90FB
  area1.event_word_222 = 0;  // 0x9101
  compare_and(Values: 0 == mapPosX && 4 == mapPosY);  // 0x9107
  if_=(<if compare flag is false, skip next op>);  // 0x9112
  area1.event_word_21A = 2;  // 0x9113
  compare_and(Values: 9 == mapPosX && 1 == mapPosY);  // 0x9119
  if_=(<if compare flag is false, skip next op>);  // 0x9124
  area1.event_word_21A = 4;  // 0x9125
  compare_and(Values: 6 == mapPosX && 5 == mapPosY);  // 0x912B
  if_=(<if compare flag is false, skip next op>);  // 0x9136
  area1.event_word_21A = 4;  // 0x9137
  compare_and(Values: 4 == mapPosX && 5 == mapPosY);  // 0x913D
  if_=(<if compare flag is false, skip next op>);  // 0x9148
  area1.event_word_21A = 4;  // 0x9149
  compare_and(Values: 7 == mapPosX && 12 == mapPosY);  // 0x914F
  if_=(<if compare flag is false, skip next op>);  // 0x915A
  area1.event_word_21A = 4;  // 0x915B
  compare_and(Values: 15 == mapPosX && 3 == mapPosY);  // 0x9161
  if_=(<if compare flag is false, skip next op>);  // 0x916C
  area1.event_word_21A = 3;  // 0x916D
  compare_and(Values: 3 == mapPosX && 2 == mapPosY);  // 0x9173
  if_=(<if compare flag is false, skip next op>);  // 0x917E
  area1.event_word_21A = 5;  // 0x917F
  compare_and(Values: 4 == mapPosX && 4 == mapPosY);  // 0x9185
  if_=(<if compare flag is false, skip next op>);  // 0x9190
  area1.event_word_21A = 5;  // 0x9191
  exit_event();  // 0x9197
}
```

## Event 09

- Target: `0x90F5`
- Text hint: 'THIS AIRSHAFT LEADS DOWNWARD. DESCEND? '

```text
event 09 {
  area1.event_word_230 = 0;  // 0x90F5
  area1.event_word_224 = 0;  // 0x90FB
  area1.event_word_222 = 0;  // 0x9101
  compare_and(Values: 0 == mapPosX && 4 == mapPosY);  // 0x9107
  if_=(<if compare flag is false, skip next op>);  // 0x9112
  area1.event_word_21A = 2;  // 0x9113
  compare_and(Values: 9 == mapPosX && 1 == mapPosY);  // 0x9119
  if_=(<if compare flag is false, skip next op>);  // 0x9124
  area1.event_word_21A = 4;  // 0x9125
  compare_and(Values: 6 == mapPosX && 5 == mapPosY);  // 0x912B
  if_=(<if compare flag is false, skip next op>);  // 0x9136
  area1.event_word_21A = 4;  // 0x9137
  compare_and(Values: 4 == mapPosX && 5 == mapPosY);  // 0x913D
  if_=(<if compare flag is false, skip next op>);  // 0x9148
  area1.event_word_21A = 4;  // 0x9149
  compare_and(Values: 7 == mapPosX && 12 == mapPosY);  // 0x914F
  if_=(<if compare flag is false, skip next op>);  // 0x915A
  area1.event_word_21A = 4;  // 0x915B
  compare_and(Values: 15 == mapPosX && 3 == mapPosY);  // 0x9161
  if_=(<if compare flag is false, skip next op>);  // 0x916C
  area1.event_word_21A = 3;  // 0x916D
  compare_and(Values: 3 == mapPosX && 2 == mapPosY);  // 0x9173
  if_=(<if compare flag is false, skip next op>);  // 0x917E
  area1.event_word_21A = 5;  // 0x917F
  compare_and(Values: 4 == mapPosX && 4 == mapPosY);  // 0x9185
  if_=(<if compare flag is false, skip next op>);  // 0x9190
  area1.event_word_21A = 5;  // 0x9191
  exit_event();  // 0x9197
}
```

## Event 10

- Target: `0x9198`
- Text hint: 'THIS AIRSHAFT LEADS DOWNWARD. DESCEND? '

```text
event 10 {
  area1.event_word_21A = 1;  // 0x9198
  // 0x919E-0x91A4
  if (area1.event_word_224 == 1) {
    exit_event();  // 0x91A5
  }
  printclear('THIS AIRSHAFT LEADS DOWNWARD. DESCEND? ');  // 0x91A6
  area1.event_word_21A = 1;  // 0x91F1
  // 0x91F7-0x91FD
  if (area1.event_word_224 == 1) {
    exit_event();  // 0x91FE
  }
  printclear('THIS SHAFT LEADS UPWARD. ASCEND? ');  // 0x91FF
  printclear('YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. ');  // 0x9291
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'PRIMARY REC', 'REC II', 'GUEST QTRS', 'EXIT');  // 0x92B9
  area2.event_scratch3 = 0;  // 0x92E0
  // 0x92E6
  switch (area2.event_scratch0) {
    case 0: goto 0x9EE5;
      // case 0 body
      compare_and(Values: 5 == mapPosX && 5 == mapPosY);  // 0x9EE5
      if_=(<if compare flag is false, skip next op>);  // 0x9EF0
      goto 0x9F3C;  // 0x9EF1
      // branch body 0x9F3C
        area2.event_scratch3 = 5;  // 0x9F3C
        printclear('');  // 0x9F42
        return;  // 0x9F45
    case 1: goto 0x9F02;
      // case 1 body
      compare_and(Values: 8 == mapPosX && 12 == mapPosY);  // 0x9F02
      if_=(<if compare flag is false, skip next op>);  // 0x9F0D
      goto 0x9F3C;  // 0x9F0E
      // branch body 0x9F3C
        // target 0x9F3C already emitted
    case 2: goto 0x9F1F;
      // case 2 body
      compare_and(Values: 5 == mapPosX && 4 == mapPosY);  // 0x9F1F
      if_=(<if compare flag is false, skip next op>);  // 0x9F2A
      goto 0x9F3C;  // 0x9F2B
      // branch body 0x9F3C
        // target 0x9F3C already emitted
    case 3: goto 0x9F3C;
      // case 3 body
      // target 0x9F3C already emitted
  }
}
```

## Event 11

- Target: `0x91F1`
- Text hint: 'THIS SHAFT LEADS UPWARD. ASCEND? ' 'YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. '

```text
event 11 {
  area1.event_word_21A = 1;  // 0x91F1
  // 0x91F7-0x91FD
  if (area1.event_word_224 == 1) {
    exit_event();  // 0x91FE
  }
  printclear('THIS SHAFT LEADS UPWARD. ASCEND? ');  // 0x91FF
  printclear('YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. ');  // 0x9291
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'PRIMARY REC', 'REC II', 'GUEST QTRS', 'EXIT');  // 0x92B9
  area2.event_scratch3 = 0;  // 0x92E0
  // 0x92E6
  switch (area2.event_scratch0) {
    case 0: goto 0x9EE5;
      // case 0 body
      compare_and(Values: 5 == mapPosX && 5 == mapPosY);  // 0x9EE5
      if_=(<if compare flag is false, skip next op>);  // 0x9EF0
      goto 0x9F3C;  // 0x9EF1
      // branch body 0x9F3C
        area2.event_scratch3 = 5;  // 0x9F3C
        printclear('');  // 0x9F42
        return;  // 0x9F45
    case 1: goto 0x9F02;
      // case 1 body
      compare_and(Values: 8 == mapPosX && 12 == mapPosY);  // 0x9F02
      if_=(<if compare flag is false, skip next op>);  // 0x9F0D
      goto 0x9F3C;  // 0x9F0E
      // branch body 0x9F3C
        // target 0x9F3C already emitted
    case 2: goto 0x9F1F;
      // case 2 body
      compare_and(Values: 5 == mapPosX && 4 == mapPosY);  // 0x9F1F
      if_=(<if compare flag is false, skip next op>);  // 0x9F2A
      goto 0x9F3C;  // 0x9F2B
      // branch body 0x9F3C
        // target 0x9F3C already emitted
    case 3: goto 0x9F3C;
      // case 3 body
      // target 0x9F3C already emitted
  }
}
```

## Event 12

- Target: `0x9291`
- Text hint: 'YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. '

```text
event 12 {
  printclear('YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. ');  // 0x9291
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'PRIMARY REC', 'REC II', 'GUEST QTRS', 'EXIT');  // 0x92B9
  area2.event_scratch3 = 0;  // 0x92E0
  // 0x92E6
  switch (area2.event_scratch0) {
    case 0: goto 0x9EE5;
      // case 0 body
      compare_and(Values: 5 == mapPosX && 5 == mapPosY);  // 0x9EE5
      if_=(<if compare flag is false, skip next op>);  // 0x9EF0
      goto 0x9F3C;  // 0x9EF1
      // branch body 0x9F3C
        area2.event_scratch3 = 5;  // 0x9F3C
        printclear('');  // 0x9F42
        return;  // 0x9F45
    case 1: goto 0x9F02;
      // case 1 body
      compare_and(Values: 8 == mapPosX && 12 == mapPosY);  // 0x9F02
      if_=(<if compare flag is false, skip next op>);  // 0x9F0D
      goto 0x9F3C;  // 0x9F0E
      // branch body 0x9F3C
        // target 0x9F3C already emitted
    case 2: goto 0x9F1F;
      // case 2 body
      compare_and(Values: 5 == mapPosX && 4 == mapPosY);  // 0x9F1F
      if_=(<if compare flag is false, skip next op>);  // 0x9F2A
      goto 0x9F3C;  // 0x9F2B
      // branch body 0x9F3C
        // target 0x9F3C already emitted
    case 3: goto 0x9F3C;
      // case 3 body
      // target 0x9F3C already emitted
  }
}
```

## Event 13

- Target: `0x9336`
- Text hint: 'THIS ROOM IS EMPTY. IT LOOKS LIKE THE ' "WOMEN'S LOCKER ROOM."

```text
event 13 {
  // 0x9336-0x933F
  area2.event_scratch0 = 1 & area1.event_word_214;  // 0x9336
  if (area2.event_scratch0 == 0) {
    printclear('THIS ROOM IS EMPTY. IT LOOKS LIKE THE ');  // 0x9340
  }
  print("WOMEN'S LOCKER ROOM.");  // 0x9360
  or(area1.event_word_214 = 1 | area1.event_word_214);  // 0x9372
  exit_event();  // 0x937B
}
```

## Event 14

- Target: `0x937C`
- Text hint: 'TOWELS ARE LUMPED AROUND IN DAMP PILES. THIS IS THE ' "MEN'S LOCKER ROOM"

```text
event 14 {
  // 0x937C-0x9385
  area2.event_scratch0 = 2 & area1.event_word_214;  // 0x937C
  if (area2.event_scratch0 == 0) {
    printclear('TOWELS ARE LUMPED AROUND IN DAMP PILES. THIS IS THE ');  // 0x9386
  }
  print("MEN'S LOCKER ROOM");  // 0x93B0
  // 0x93CB-0x93D1
  if (area1.event_word_222 == 1) {
    exit_event();  // 0x93D2
  }
  printclear("A COMPUTERIZED VOICE SAYS, 'THIS ROOM IS OCCUPIED.'");  // 0x93D3
  area1.event_word_218 = 0;  // 0x93FD
  area1.event_word_222 = 1;  // 0x9404
  // 0x940B-0x9411
  if (area1.event_word_22A == 4) {
    goto 0x9494;  // 0x9412
    // branch body 0x9494
    setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x9494
    exit_event();  // 0x949B
  }
  printclear('YOU INTERRUPT TWO CREW MEMBERS AND THEIR GAME OF ');  // 0x9416
  random(area2.event_scratch0 = random 1..3);  // 0x943E
  // 0x9444
  switch (area2.event_scratch0) {
    case 0: goto 0x9F46;
      // case 0 body
      print("HANDBALL. ONE SAYS 'ARE YOU DEAF? THE COMPUTER SAID THIS ROOM WAS OCCUPIED. ");  // 0x9F46
      return;  // 0x9F82
    case 1: goto 0x9F83;
      // case 1 body
      print("HALF-SQUARES. 'EXCUSE ME, BUT THIS ROOM IS IN USE. ");  // 0x9F83
      return;  // 0x9FAD
    case 2: goto 0x9FAE;
      // case 2 body
      print("SQUASH. ONE THROWS DOWN HIS RACKET. 'WE'RE USING THIS ROOM. ");  // 0x9FAE
      return;  // 0x9FDE
    case 3: goto 0x9FDF;
      // case 3 body
      print("RACQUETBALL. 'WE STILL HAVE AN HOUR RESERVAD. ");  // 0x9FDF
      return;  // 0xA005
  }
}
```

## Event 15

- Target: `0x93CB`
- Text hint: "A COMPUTERIZED VOICE SAYS, 'THIS ROOM IS OCCUPIED.'"

```text
event 15 {
  // 0x93CB-0x93D1
  if (area1.event_word_222 == 1) {
    exit_event();  // 0x93D2
  }
  printclear("A COMPUTERIZED VOICE SAYS, 'THIS ROOM IS OCCUPIED.'");  // 0x93D3
  area1.event_word_218 = 0;  // 0x93FD
  area1.event_word_222 = 1;  // 0x9404
  // 0x940B-0x9411
  if (area1.event_word_22A == 4) {
    goto 0x9494;  // 0x9412
    // branch body 0x9494
    setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x9494
    exit_event();  // 0x949B
  }
  printclear('YOU INTERRUPT TWO CREW MEMBERS AND THEIR GAME OF ');  // 0x9416
  random(area2.event_scratch0 = random 1..3);  // 0x943E
  // 0x9444
  switch (area2.event_scratch0) {
    case 0: goto 0x9F46;
      // case 0 body
      print("HANDBALL. ONE SAYS 'ARE YOU DEAF? THE COMPUTER SAID THIS ROOM WAS OCCUPIED. ");  // 0x9F46
      return;  // 0x9F82
    case 1: goto 0x9F83;
      // case 1 body
      print("HALF-SQUARES. 'EXCUSE ME, BUT THIS ROOM IS IN USE. ");  // 0x9F83
      return;  // 0x9FAD
    case 2: goto 0x9FAE;
      // case 2 body
      print("SQUASH. ONE THROWS DOWN HIS RACKET. 'WE'RE USING THIS ROOM. ");  // 0x9FAE
      return;  // 0x9FDE
    case 3: goto 0x9FDF;
      // case 3 body
      print("RACQUETBALL. 'WE STILL HAVE AN HOUR RESERVAD. ");  // 0x9FDF
      return;  // 0xA005
  }
}
```

## Event 16

- Target: `0x940B`
- Text hint: 'YOU INTERRUPT TWO CREW MEMBERS AND THEIR GAME OF ' "GET OUT OF HERE!'" 'YOU ARE SHOVED INTO THE HALLWAY.'

```text
event 16 {
  // 0x940B-0x9411
  if (area1.event_word_22A == 4) {
    goto 0x9494;  // 0x9412
    // branch body 0x9494
    setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x9494
    exit_event();  // 0x949B
  }
  printclear('YOU INTERRUPT TWO CREW MEMBERS AND THEIR GAME OF ');  // 0x9416
  random(area2.event_scratch0 = random 1..3);  // 0x943E
  // 0x9444
  switch (area2.event_scratch0) {
    case 0: goto 0x9F46;
      // case 0 body
      print("HANDBALL. ONE SAYS 'ARE YOU DEAF? THE COMPUTER SAID THIS ROOM WAS OCCUPIED. ");  // 0x9F46
      return;  // 0x9F82
    case 1: goto 0x9F83;
      // case 1 body
      print("HALF-SQUARES. 'EXCUSE ME, BUT THIS ROOM IS IN USE. ");  // 0x9F83
      return;  // 0x9FAD
    case 2: goto 0x9FAE;
      // case 2 body
      print("SQUASH. ONE THROWS DOWN HIS RACKET. 'WE'RE USING THIS ROOM. ");  // 0x9FAE
      return;  // 0x9FDE
    case 3: goto 0x9FDF;
      // case 3 body
      print("RACQUETBALL. 'WE STILL HAVE AN HOUR RESERVAD. ");  // 0x9FDF
      return;  // 0xA005
  }
}
```

## Event 17

- Target: `0x94DF`
- Text hint: 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.'

```text
event 17 {
  setup_monster(sprite_id: 52 max_distance: 1 pic_id: 255);  // 0x94DF
  exit_event();  // 0x94E6
}
```

## Event 18

- Target: `0x9602`
- Text hint: 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.'

```text
event 18 {
  printclear('THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.');  // 0x9602
  // 0x964D-0x9656
  area2.event_scratch0 = 8 & area1.event_word_214;  // 0x964D
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9657
  }
  printclear('THIS ROOM OBVIOUSLY BELONGS TO SOMEONE OF HIGH RANK. A MAN IS SLEEPING ON THE WIDE BED. BESIDE HIM IS A RAM SECURITY CARD.');  // 0x9658
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'WAKE MAN', 'TAKE CARD', 'LEAVE');  // 0x96B7
  printclear('');  // 0x96D4
  // 0x96D7-0x96DD
  if (area2.event_scratch0 == 2) {
    goto 0x9B13;  // 0x96DE
    // branch body 0x9B13
    mapPosX = area1.event_word_232;  // 0x9B13
    mapPosY = area1.event_word_234;  // 0x9B1A
    random(area2.event_scratch0 = random 1..99);  // 0x9B22
    // 0x9B28-0x9B2E
    if (area2.event_scratch0 < 7) {
      area2.event_scratch0 = area1.event_word_21A;  // 0x9B30
    }
    // 0x9B37
    switch (area2.event_scratch0) {
      case 0: goto 0x9B4F;
        // case 0 body
        printclear("THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'");  // 0x9B4F
        exit_event();  // 0x9B97
      case 1: goto 0x9B97;
        // case 1 body
        exit_event();  // 0x9B97
      case 2: goto 0x9B97;
        // case 2 body
        // target 0x9B97 already emitted
      case 3: goto 0x9B98;
        // case 3 body
        setup_monster(sprite_id: 52 max_distance: 1 pic_id: 255);  // 0x9B98
        exit_event();  // 0x9B9F
      case 4: goto 0x9CCE;
        // case 4 body
        printclear('CREW MEMBERS IN EXERCISE OUTFITS PASS YOU. ');  // 0x9CCE
        random(area2.event_scratch0 = random 1..99);  // 0x9CF2
        // 0x9CF8-0x9CFE
        if (area2.event_scratch0 < 35) {
          exit_event();  // 0x9CFF
        }
        print('YOU HEAR ONE SAY, ');  // 0x9D00
        random(area2.event_scratch0 = random 1..3);  // 0x9D11
        // 0x9D17
        switch (area2.event_scratch0) {
          case 0: goto 0xA084;
          case 1: goto 0xA0E2;
          case 2: goto 0xA164;
        }
      case 5: goto 0x9D28;
        // case 5 body
        // 0x9D28-0x9D2E
        if (area1.event_word_216 == 1) {
          exit_event();  // 0x9D2F
        }
        printclear('A DELEGATE WITH RAM BODYGUARDS PASSES YOU QUICKLY. ');  // 0x9D30
        // 0x9D5A-0x9D60
        if (area1.event_word_3C0 == 1) {
          print('A GUARD WINKS AT YOU BEFORE THE GROUP DISAPPEARS FROM SIGHT.');  // 0x9D61
        }
        if_=(<if compare flag is false, skip next op>);  // 0x9D91
        area1.event_word_216 = 1;  // 0x9D92
        if_=(<if compare flag is false, skip next op>);  // 0x9D98
        exit_event();  // 0x9D99
    }
  }
  or(area1.event_word_214 = 8 | area1.event_word_214);  // 0x96E2
  // 0x96EB-0x96F1
  if (area2.event_scratch0 == 1) {
    printclear('YOU GRAB THE CARD, BUT THE MAN SITS UP. ');  // 0x96F2
  }
  if_=(<if compare flag is false, skip next op>);  // 0x9713
  area1.event_word_22C = 1;  // 0x9714
  print('HE BLINKS THE SLEEP OUT OF HIS EYES AND HITS AN ALARM BESIDE HIM.');  // 0x971A
  printclear('THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?');  // 0x979D
  // truncated at 0x98B6
}
```

## Event 19

- Target: `0x964D`
- Text hint: 'THIS ROOM OBVIOUSLY BELONGS TO SOMEONE OF HIGH RANK. A MAN IS SLEEPING ON THE WIDE BED. BESIDE HIM IS A RAM SECURITY CARD.' ''

```text
event 19 {
  // 0x964D-0x9656
  area2.event_scratch0 = 8 & area1.event_word_214;  // 0x964D
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x9657
  }
  printclear('THIS ROOM OBVIOUSLY BELONGS TO SOMEONE OF HIGH RANK. A MAN IS SLEEPING ON THE WIDE BED. BESIDE HIM IS A RAM SECURITY CARD.');  // 0x9658
  horizontal_menu(area2.event_scratch0 = <selected index from menu> MENU: 'WAKE MAN', 'TAKE CARD', 'LEAVE');  // 0x96B7
  printclear('');  // 0x96D4
  // 0x96D7-0x96DD
  if (area2.event_scratch0 == 2) {
    goto 0x9B13;  // 0x96DE
    // branch body 0x9B13
    mapPosX = area1.event_word_232;  // 0x9B13
    mapPosY = area1.event_word_234;  // 0x9B1A
    random(area2.event_scratch0 = random 1..99);  // 0x9B22
    // 0x9B28-0x9B2E
    if (area2.event_scratch0 < 7) {
      area2.event_scratch0 = area1.event_word_21A;  // 0x9B30
    }
    // 0x9B37
    switch (area2.event_scratch0) {
      case 0: goto 0x9B4F;
        // case 0 body
        printclear("THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'");  // 0x9B4F
        exit_event();  // 0x9B97
      case 1: goto 0x9B97;
        // case 1 body
        exit_event();  // 0x9B97
      case 2: goto 0x9B97;
        // case 2 body
        // target 0x9B97 already emitted
      case 3: goto 0x9B98;
        // case 3 body
        setup_monster(sprite_id: 52 max_distance: 1 pic_id: 255);  // 0x9B98
        exit_event();  // 0x9B9F
      case 4: goto 0x9CCE;
        // case 4 body
        printclear('CREW MEMBERS IN EXERCISE OUTFITS PASS YOU. ');  // 0x9CCE
        random(area2.event_scratch0 = random 1..99);  // 0x9CF2
        // 0x9CF8-0x9CFE
        if (area2.event_scratch0 < 35) {
          exit_event();  // 0x9CFF
        }
        print('YOU HEAR ONE SAY, ');  // 0x9D00
        random(area2.event_scratch0 = random 1..3);  // 0x9D11
        // 0x9D17
        switch (area2.event_scratch0) {
          case 0: goto 0xA084;
          case 1: goto 0xA0E2;
          case 2: goto 0xA164;
        }
      case 5: goto 0x9D28;
        // case 5 body
        // 0x9D28-0x9D2E
        if (area1.event_word_216 == 1) {
          exit_event();  // 0x9D2F
        }
        printclear('A DELEGATE WITH RAM BODYGUARDS PASSES YOU QUICKLY. ');  // 0x9D30
        // 0x9D5A-0x9D60
        if (area1.event_word_3C0 == 1) {
          print('A GUARD WINKS AT YOU BEFORE THE GROUP DISAPPEARS FROM SIGHT.');  // 0x9D61
        }
        if_=(<if compare flag is false, skip next op>);  // 0x9D91
        area1.event_word_216 = 1;  // 0x9D92
        if_=(<if compare flag is false, skip next op>);  // 0x9D98
        exit_event();  // 0x9D99
    }
  }
  or(area1.event_word_214 = 8 | area1.event_word_214);  // 0x96E2
  // 0x96EB-0x96F1
  if (area2.event_scratch0 == 1) {
    printclear('YOU GRAB THE CARD, BUT THE MAN SITS UP. ');  // 0x96F2
  }
  if_=(<if compare flag is false, skip next op>);  // 0x9713
  area1.event_word_22C = 1;  // 0x9714
  print('HE BLINKS THE SLEEP OUT OF HIS EYES AND HITS AN ALARM BESIDE HIM.');  // 0x971A
  printclear('THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?');  // 0x979D
  // 0x98B6-0x98BC
  if (area1.event_word_276 == 1) {
    goto 0x9A90;  // 0x98BD
    // branch body 0x9A90
    setup_monster(sprite_id: 50 max_distance: 1 pic_id: 255);  // 0x9A90
    exit_event();  // 0x9A97
  }
  printclear('THIS DOOR REQUIRES A SECURITY CARD. USE THE CARD? ');  // 0x98C1
  // truncated at 0x9962
}
```

## Event 20

- Target: `0x979D`
- Text hint: 'THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?'

```text
event 20 {
  printclear('THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?');  // 0x979D
  // 0x98B6-0x98BC
  if (area1.event_word_276 == 1) {
    goto 0x9A90;  // 0x98BD
    // branch body 0x9A90
    setup_monster(sprite_id: 50 max_distance: 1 pic_id: 255);  // 0x9A90
    exit_event();  // 0x9A97
  }
  printclear('THIS DOOR REQUIRES A SECURITY CARD. USE THE CARD? ');  // 0x98C1
  // 0x9962-0x996B
  area2.event_scratch0 = 32 & area1.event_word_214;  // 0x9962
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x996C
  }
  or(area1.event_word_214 = 32 | area1.event_word_214);  // 0x996D
  setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x9976
  exit_event();  // 0x997D
}
```

## Event 21

- Target: `0x98B6`
- Text hint: 'THIS DOOR REQUIRES A SECURITY CARD. USE THE CARD? '

```text
event 21 {
  // 0x98B6-0x98BC
  if (area1.event_word_276 == 1) {
    goto 0x9A90;  // 0x98BD
    // branch body 0x9A90
    setup_monster(sprite_id: 50 max_distance: 1 pic_id: 255);  // 0x9A90
    exit_event();  // 0x9A97
  }
  printclear('THIS DOOR REQUIRES A SECURITY CARD. USE THE CARD? ');  // 0x98C1
  // 0x9962-0x996B
  area2.event_scratch0 = 32 & area1.event_word_214;  // 0x9962
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x996C
  }
  or(area1.event_word_214 = 32 | area1.event_word_214);  // 0x996D
  setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x9976
  exit_event();  // 0x997D
}
```

## Event 22

- Target: `0x9962`
- Text hint: "THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'"

```text
event 22 {
  // 0x9962-0x996B
  area2.event_scratch0 = 32 & area1.event_word_214;  // 0x9962
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x996C
  }
  or(area1.event_word_214 = 32 | area1.event_word_214);  // 0x996D
  setup_monster(sprite_id: 52 max_distance: 0 pic_id: 255);  // 0x9976
  exit_event();  // 0x997D
}
```

## Event 23

- Target: `0x99C5`
- Text hint: "THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'"

```text
event 23 {
  // 0x99C5-0x99CB
  if (area1.event_word_276 == 1) {
    exit_event();  // 0x99CC
  }
  exit_event();  // 0x99CE
}
```
