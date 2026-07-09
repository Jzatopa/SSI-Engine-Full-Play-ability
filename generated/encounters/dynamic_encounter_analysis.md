# Dynamic Encounter Table Analysis

This pass inspects dynamic encounter operands and extracts nearby `GETTABLE` sources when possible.

- dynamic rows analyzed: 13
- rows with table candidates: 6

## ECL 021 Event ? `0x83DE`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- No nearby table source found; likely state carried from another event path.

~~~text

~~~

## ECL 021 Event 4 `0x863A`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- `area2.event_scratch7` from `ecl.byte_0FCD[area2.event_scratch2]`: 0:10 COYODORG, 1:0, 2:0, 3:52 RAM WARRIOR, 4:50 SECURITY ROBOT, 5:52 RAM WARRIOR, 6:52 RAM WARRIOR, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:50 SECURITY ROBOT, 10:52 RAM WARRIOR, 11:52 RAM WARRIOR

~~~text
  // 0x8503-0x850A
  if (area1.event_word_20A == area1.event_word_20C) {
    goto 0x8613;  // 0x850B
    // branch body 0x8613
    // 0x8613-0x861C
    area2.event_scratch0 = area1.event_word_218 & 16;  // 0x8613
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x861D
    }
    or(area1.event_word_218 = area1.event_word_218 | 16);  // 0x861E
    add(area2.event_scratch2 = 3 + area2.event_scratch8);  // 0x8627
    gettable(area2.event_scratch7 = ecl.byte_0FCD[area2.event_scratch2]);  // 0x8630
    setup_monster(sprite_id: area2.event_scratch7 max_distance: 0 pic_id: 255);  // 0x863A
~~~

## ECL 021 Event 4 `0x86EC`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- `area2.event_scratch7` from `ecl.byte_0FCD[area2.event_scratch2]`: 0:10 COYODORG, 1:0, 2:0, 3:52 RAM WARRIOR, 4:50 SECURITY ROBOT, 5:52 RAM WARRIOR, 6:52 RAM WARRIOR, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:50 SECURITY ROBOT, 10:52 RAM WARRIOR, 11:52 RAM WARRIOR

~~~text
  // 0x84F8-0x84FE
  if (1 == area1.event_word_20C) {
    goto 0x86C5;  // 0x84FF
    // branch body 0x86C5
    // 0x86C5-0x86CE
    area2.event_scratch0 = area1.event_word_218 & 32;  // 0x86C5
    if (area2.event_scratch0 != 0) {
      exit_event();  // 0x86CF
    }
    or(area1.event_word_218 = area1.event_word_218 | 32);  // 0x86D0
    add(area2.event_scratch2 = 4 + area2.event_scratch8);  // 0x86D9
    gettable(area2.event_scratch7 = ecl.byte_0FCD[area2.event_scratch2]);  // 0x86E2
    setup_monster(sprite_id: area2.event_scratch7 max_distance: 0 pic_id: 255);  // 0x86EC
~~~

## ECL 021 Event 6 `0x8785`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- `area2.event_scratch7` from `ecl.byte_0FCD[area2.event_scratch2]`: 0:10 COYODORG, 1:0, 2:0, 3:52 RAM WARRIOR, 4:50 SECURITY ROBOT, 5:52 RAM WARRIOR, 6:52 RAM WARRIOR, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:50 SECURITY ROBOT, 10:52 RAM WARRIOR, 11:52 RAM WARRIOR

~~~text
  // 0x8756-0x875C
  if (3 != area1.event_word_20E) {
    exit_event();  // 0x875D
  }
  // 0x875E-0x8767
  area2.event_scratch0 = area1.event_word_218 & 64;  // 0x875E
  if (area2.event_scratch0 != 0) {
    exit_event();  // 0x8768
  }
  or(area1.event_word_218 = area1.event_word_218 | 64);  // 0x8769
  add(area2.event_scratch2 = 1 + area2.event_scratch8);  // 0x8772
  gettable(area2.event_scratch7 = ecl.byte_0FCD[area2.event_scratch2]);  // 0x877B
  setup_monster(sprite_id: area2.event_scratch7 max_distance: 0 pic_id: 255);  // 0x8785
~~~

## ECL 021 Event 7 `0x881D`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- `area2.event_scratch7` from `ecl.byte_0FCD[area2.event_scratch2]`: 0:10 COYODORG, 1:0, 2:0, 3:52 RAM WARRIOR, 4:50 SECURITY ROBOT, 5:52 RAM WARRIOR, 6:52 RAM WARRIOR, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:50 SECURITY ROBOT, 10:52 RAM WARRIOR, 11:52 RAM WARRIOR

~~~text
- Text hint: 'A SIGN ABOVE THE DOOR READS, ' RETURN

```text
event 07 {
  // 0x87F2-0x87F8
  if (3 != area1.event_word_20E) {
    exit_event();  // 0x87F9
  }
  random(area2.event_scratch0 = random 1..3);  // 0x87FA
  add(area2.event_scratch0 = 1 + area2.event_scratch0);  // 0x8800
  add(area2.event_scratch2 = area2.event_scratch0 + area2.event_scratch8);  // 0x8809
  gettable(area2.event_scratch7 = ecl.byte_0FCD[area2.event_scratch2]);  // 0x8813
  setup_monster(sprite_id: area2.event_scratch7 max_distance: 0 pic_id: 255);  // 0x881D
~~~

## ECL 021 Event 9 `0x88E4`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- `area2.event_scratch7` from `ecl.byte_0FCD[area2.event_scratch2]`: 0:10 COYODORG, 1:0, 2:0, 3:52 RAM WARRIOR, 4:50 SECURITY ROBOT, 5:52 RAM WARRIOR, 6:52 RAM WARRIOR, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:50 SECURITY ROBOT, 10:52 RAM WARRIOR, 11:52 RAM WARRIOR

~~~text

- Target: `0x88C9`
- Text hint: "A MECHANICAL VOICE INTONES, 'CAPTAIN HAS ACTIVATED SELF-DESTRUCT FROM HIS CABIN. DETONATION IN 50.'"

```text
event 09 {
  // 0x88C9-0x88CF
  if (2 != area1.event_word_20E) {
    exit_event();  // 0x88D0
  }
  add(area2.event_scratch2 = 1 + area2.event_scratch8);  // 0x88D1
  gettable(area2.event_scratch7 = ecl.byte_0FCD[area2.event_scratch2]);  // 0x88DA
  setup_monster(sprite_id: area2.event_scratch7 max_distance: 0 pic_id: 255);  // 0x88E4
~~~

## ECL 021 Event ? `0x8A09`

- Map: 21
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch7`
- Pic ref: `255`

- No nearby table source found; likely state carried from another event path.

~~~text

~~~

## ECL 033 Event ? `0x8392`

- Map: Losangelorg Sprawls
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch1`
- Pic ref: `area2.event_scratch2`

- No nearby table source found; likely state carried from another event path.

~~~text

~~~

## ECL 034 Event 1 `0x853F`

- Map: Historical Museum, Levels 2-1
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch1`
- Pic ref: `area2.event_scratch2`

- `area2.event_scratch1` from `abs_A2F0[area1.event_word_21C]`: 0:255 sentinel, 1:39 LG. E.C. GENNIE, 2:255 sentinel, 3:52 RAM WARRIOR, 4:52 RAM WARRIOR, 5:255 sentinel, 6:11 RATWURST, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:39 LG. E.C. GENNIE, 10:7 WARRIOR, 11:4 SID REFUGE
- `area2.event_scratch2` from `abs_A2EC[area1.event_word_21C]`: 0:112, 1:19 AMALTHEAN WARR, 2:11 RATWURST, 3:255 sentinel, 4:255 sentinel, 5:39 LG. E.C. GENNIE, 6:255 sentinel, 7:52 RAM WARRIOR, 8:52 RAM WARRIOR, 9:255 sentinel, 10:11 RATWURST, 11:52 RAM WARRIOR

~~~text
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
~~~

## ECL 036 Event ? `0x884D`

- Map: -
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch1`
- Pic ref: `area2.event_scratch2`

- No nearby table source found; likely state carried from another event path.

~~~text

~~~

## ECL 037 Event ? `0x82E6`

- Map: -
- Kind: `setup_monster`
- Monster ref: `area2.event_scratch1`
- Pic ref: `area2.event_scratch2`

- No nearby table source found; likely state carried from another event path.

~~~text

~~~

## ECL 080 Event 3 `0x863E`

- Map: Mars Prison, Level 1
- Kind: `load_monster`
- Monster ref: `area1.event_word_23A`
- Pic ref: `area1.event_word_23A`

- No nearby table source found; likely state carried from another event path.

~~~text
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
~~~

## ECL 080 Event ? `0xA367`

- Map: Mars Prison, Level 1
- Kind: `setup_monster`
- Monster ref: `area1.event_word_214`
- Pic ref: `area1.event_word_238`

- No nearby table source found; likely state carried from another event path.

~~~text

~~~
