# GEO 64: Luna Base

ECL block: `64`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x819B`
- Text hint: "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"

```text
event 01 {
  @0x819B: EXIT
}
```

## Event 02

- Target: `0x819C`
- Text hint: "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"

```text
event 02 {
  @0x819C: AND area2.event_scratch0 = area1.event_word_200 & 1
  @0x81A5: IF <> <if compare flag is false, skip next op>
  @0x81A6: EXIT
}
```

## Event 03

- Target: `0x819B`
- Text hint: "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"

```text
event 03 {
  @0x819B: EXIT
}
```

## Event 04

- Target: `0x81F6`
- Text hint: 'YOU SPOT DR. COLDOR AHEAD.'

```text
event 04 {
  @0x81F6: AND area2.event_scratch0 = area1.event_word_200 & 8
  @0x81FF: IF <> <if compare flag is false, skip next op>
  @0x8200: GOTO 0x8225
  // follows GOTO 0x8225
    @0x8225: COMPARE Values: 2 == mapDirection
    @0x822B: IF = <if compare flag is false, skip next op>
    @0x822C: EXIT
}
```

## Event 05

- Target: `0x8243`
- Text hint: "A GREY-SUITED MAN LOOKS UP. 'WHO ARE YOU HERE TO SEE?'"

```text
event 05 {
  @0x8243: COMPARE Values: 3 == mapDirection
  @0x8249: IF = <if compare flag is false, skip next op>
  @0x824A: EXIT
}
```

## Event 06

- Target: `0x8262`
- Text hint: "A GREY-SUITED MAN LOOKS UP. 'WHO ARE YOU HERE TO SEE?'"

```text
event 06 {
  @0x8262: COMPARE Values: 1 == mapDirection
  @0x8268: IF <> <if compare flag is false, skip next op>
  @0x8269: EXIT
}
```

## Event 07

- Target: `0x8350`
- Text hint: "A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS."

```text
event 07 {
  @0x8350: COMPARE Values: 1 == area1.event_word_20C
  @0x8356: IF = <if compare flag is false, skip next op>
  @0x8357: GOTO 0x8545
  // follows GOTO 0x8545
    @0x8545: AND area2.event_scratch0 = area1.event_word_200 & 4
    @0x854E: IF <> <if compare flag is false, skip next op>
    @0x854F: EXIT
}
```

## Event 08

- Target: `0x8579`
- Text hint: "'YOU'RE IN THE WRONG OFFICE.'"

```text
event 08 {
  @0x8579: COMPARE Values: 1 == area1.event_word_20C
  @0x857F: IF = <if compare flag is false, skip next op>
  @0x8580: GOTO 0x859E
  // follows GOTO 0x859E
    @0x859E: PRINTCLEAR 'POLICE RUSH YOU.'
    @0x85AD: GOTO 0x97FE
    // follows GOTO 0x97FE
      @0x97FE: SETUP MONSTER sprite_id: 14 max_distance: 0 pic_id: 255
      @0x9805: EXIT
}
```

## Event 09

- Target: `0x85B2`
- Text hint: 'A POLICEMAN STANDS BEFORE YOU. '

```text
event 09 {
  @0x85B2: COMPARE Values: 1 == area1.event_word_20C
  @0x85B8: IF = <if compare flag is false, skip next op>
  @0x85B9: GOTO 0x859E
  // follows GOTO 0x859E
    @0x859E: PRINTCLEAR 'POLICE RUSH YOU.'
    @0x85AD: GOTO 0x97FE
    // follows GOTO 0x97FE
      @0x97FE: SETUP MONSTER sprite_id: 14 max_distance: 0 pic_id: 255
      @0x9805: EXIT
}
```

## Event 10

- Target: `0x8667`
- Text hint: "MCKAY LOOKS UP. 'ALL RIGHT, WHAT DO YOU WANT?'"

```text
event 10 {
  @0x8667: COMPARE Values: 1 == area1.event_word_20C
  @0x866D: IF = <if compare flag is false, skip next op>
  @0x866E: GOTO 0x859E
  // follows GOTO 0x859E
    @0x859E: PRINTCLEAR 'POLICE RUSH YOU.'
    @0x85AD: GOTO 0x97FE
    // follows GOTO 0x97FE
      @0x97FE: SETUP MONSTER sprite_id: 14 max_distance: 0 pic_id: 255
      @0x9805: EXIT
}
```

## Event 11

- Target: `0x8785`
- Text hint: 'YOU REACH DR. COLDOR AS SHE IS ABOUT TO ENTER A JET CAR. '

```text
event 11 {
  @0x8785: AND area2.event_scratch0 = area1.event_word_200 & 2
  @0x878E: IF <> <if compare flag is false, skip next op>
  @0x878F: GOTO 0x89A7
  // follows GOTO 0x89A7
    @0x89A7: COMPARE Values: 1 == mapDirection
    @0x89AD: IF = <if compare flag is false, skip next op>
    @0x89AE: EXIT
}
```

## Event 12

- Target: `0x89C4`
- Text hint: 'THE STORE CONTAINS ROW AFTER ROW OF LUXURY GOODS AND FOODS.'

```text
event 12 {
  @0x89C4: COMPARE Values: 3 == mapDirection
  @0x89CA: IF <> <if compare flag is false, skip next op>
  @0x89CB: EXIT
}
```

## Event 13

- Target: `0x8A3C`
- Text hint: "THE PROPRIETOR COMES UP. 'MAY I HELP YOU?'"

```text
event 13 {
  @0x8A3C: COMPARE Values: 3 == mapDirection
  @0x8A42: IF = <if compare flag is false, skip next op>
  @0x8A43: EXIT
}
```

## Event 14

- Target: `0x8A5C`
- Text hint: "THE PROPRIETOR COMES UP. 'MAY I HELP YOU?'"

```text
event 14 {
  @0x8A5C: COMPARE Values: 1 == mapDirection
  @0x8A62: IF <> <if compare flag is false, skip next op>
  @0x8A63: EXIT
}
```

## Event 15

- Target: `0x8AB7`
- Text hint: "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"

```text
event 15 {
  @0x8AB7: GOTO 0x9856
  // follows GOTO 0x9856
    @0x9856: PRINTCLEAR 'THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?'
    // truncated: next decoded instruction is 0xA308
}
```

## Event 16

- Target: `0x8ABB`
- Text hint: "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"

```text
event 16 {
  @0x8ABB: COMPARE Values: 2 == mapDirection
  @0x8AC1: IF = <if compare flag is false, skip next op>
  @0x8AC2: EXIT
}
```

## Event 17

- Target: `0x8AE2`
- Text hint: "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"

```text
event 17 {
  @0x8AE2: COMPARE Values: 0 == mapDirection
  @0x8AE8: IF <> <if compare flag is false, skip next op>
  @0x8AE9: EXIT
}
```

## Event 18

- Target: `0x8CEC`
- Text hint: 'YOU QUICKLY SEARCH THE OFFICE. '

```text
event 18 {
  @0x8CEC: COMPARE Values: 0 == mapDirection
  @0x8CF2: IF <> <if compare flag is false, skip next op>
  @0x8CF3: EXIT
}
```

## Event 19

- Target: `0x8EC8`
- Text hint: 'THE BAR IS DIM AND HAZY. BLEARY EYED PATRONS SLUMP IN THEIR CHAIRS. DO YOU MINGLE?'

```text
event 19 {
  @0x8EC8: COMPARE Values: 1 == mapDirection
  @0x8ECE: IF = <if compare flag is false, skip next op>
  @0x8ECF: EXIT
}
```

## Event 20

- Target: `0x8EE3`
- Text hint: 'THE BAR IS DIM AND HAZY. BLEARY EYED PATRONS SLUMP IN THEIR CHAIRS. DO YOU MINGLE?'

```text
event 20 {
  @0x8EE3: COMPARE Values: 3 == mapDirection
  @0x8EE9: IF <> <if compare flag is false, skip next op>
  @0x8EEA: EXIT
}
```

## Event 21

- Target: `0x9080`
- Text hint: 'THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.'

```text
event 21 {
  @0x9080: COMPARE Values: 1 == mapDirection
  @0x9086: IF = <if compare flag is false, skip next op>
  @0x9087: EXIT
}
```

## Event 22

- Target: `0x909E`
- Text hint: 'THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.'

```text
event 22 {
  @0x909E: COMPARE Values: 3 == mapDirection
  @0x90A4: IF <> <if compare flag is false, skip next op>
  @0x90A5: EXIT
}
```

## Event 23

- Target: `0x90FD`
- Text hint: 'THE STUDY CONTAINS A REAL MAHOGANY DESK.'

```text
event 23 {
  @0x90FD: PRINTCLEAR 'THE STUDY CONTAINS A REAL MAHOGANY DESK.'
  @0x911E: AND area2.event_scratch0 = area1.event_word_200 & 128
  @0x9127: IF <> <if compare flag is false, skip next op>
  @0x9128: EXIT
}
```

## Event 24

- Target: `0x9184`
- Text hint: 'THE ROBO-CHEF LOOKS DISUSED.'

```text
event 24 {
  @0x9184: PRINTCLEAR 'THE ROBO-CHEF LOOKS DISUSED.'
  @0x919C: GOSUB 0xA320
  @0x91A0: EXIT
}
```

## Event 25

- Target: `0x91A1`
- Text hint: 'THE BED IS NEATLY MADE.'

```text
event 25 {
  @0x91A1: PRINTCLEAR 'THE BED IS NEATLY MADE.'
  @0x91B6: GOSUB 0xA320
  @0x91BA: EXIT
}
```

## Event 26

- Target: `0x91BB`
- Text hint: "TSAI'S HOUSE IS BUILT IN AN OPEN STYLE FILLED WITH OPULENT ARTWORK."

```text
event 26 {
  @0x91BB: COMPARE Values: 3 == mapDirection
  @0x91C1: IF = <if compare flag is false, skip next op>
  @0x91C2: EXIT
}
```

## Event 27

- Target: `0x91D8`
- Text hint: "TSAI'S HOUSE IS BUILT IN AN OPEN STYLE FILLED WITH OPULENT ARTWORK."

```text
event 27 {
  @0x91D8: COMPARE Values: 1 == mapDirection
  @0x91DE: IF <> <if compare flag is false, skip next op>
  @0x91DF: EXIT
}
```

## Event 28

- Target: `0x926D`
- Text hint: "AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'"

```text
event 28 {
  @0x926D: COMPARE Values: 2 == mapDirection
  @0x9273: IF = <if compare flag is false, skip next op>
  @0x9274: EXIT
}
```

## Event 29

- Target: `0x9286`
- Text hint: "AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'"

```text
event 29 {
  @0x9286: COMPARE Values: 0 == mapDirection
  @0x928C: IF <> <if compare flag is false, skip next op>
  @0x928D: EXIT
}
```

## Event 30

- Target: `0x9438`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 30 {
  @0x9438: COMPARE Values: 0 == mapDirection
  @0x943E: IF = <if compare flag is false, skip next op>
  @0x943F: EXIT
}
```

## Event 31

- Target: `0x9457`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 31 {
  @0x9457: EXIT
}
```

## Event 32

- Target: `0x9458`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 32 {
  @0x9458: COMPARE Values: 1 == area1.event_word_20C
  @0x945E: IF = <if compare flag is false, skip next op>
  @0x945F: EXIT
}
```

## Event 33

- Target: `0x946A`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 33 {
  @0x946A: COMPARE Values: 3 == mapDirection
  @0x9470: IF = <if compare flag is false, skip next op>
  @0x9471: EXIT
}
```

## Event 34

- Target: `0x9486`
- Text hint: "A BURLY MINER STEPS UP. 'WATCHA WANT?'"

```text
event 34 {
  @0x9486: COMPARE Values: 1 == mapDirection
  @0x948C: IF <> <if compare flag is false, skip next op>
  @0x948D: EXIT
}
```

## Event 35

- Target: `0x958A`
- Text hint: 'A HEAVY SECURITY FORCE IS IN THE LOBBY.' "A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'"

```text
event 35 {
  @0x958A: COMPARE Values: 0 == mapDirection
  @0x9590: IF <> <if compare flag is false, skip next op>
  @0x9591: EXIT
}
```

## Event 36

- Target: `0x973E`
- Text hint: 'A LARGE PRIVATE OFFICE.'

```text
event 36 {
  @0x973E: COMPARE Values: 1 == area1.event_word_214
  @0x9744: IF = <if compare flag is false, skip next op>
  @0x9745: EXIT
}
```

## Event 37

- Target: `0x974A`
- Text hint: 'A LARGE PRIVATE OFFICE.'

```text
event 37 {
  @0x974A: COMPARE Values: 2 == mapDirection
  @0x9750: IF = <if compare flag is false, skip next op>
  @0x9751: EXIT
}
```

## Event 38

- Target: `0x9766`
- Text hint: 'A LARGE PRIVATE OFFICE.'

```text
event 38 {
  @0x9766: PRINTCLEAR 'A LARGE PRIVATE OFFICE.'
  @0x977B: COMPARE Values: 1 == area1.event_word_214
  @0x9781: IF = <if compare flag is false, skip next op>
  @0x9782: EXIT
}
```

## Event 39

- Target: `0x9797`
- Text hint: 'A MEETING ROOM.'

```text
event 39 {
  @0x9797: PRINTCLEAR 'A MEETING ROOM.'
  @0x97A6: COMPARE Values: 1 == area1.event_word_214
  @0x97AC: IF = <if compare flag is false, skip next op>
  @0x97AD: EXIT
}
```

## Event 40

- Target: `0x97C2`
- Text hint: 'A SIGN ABOVE THE DOOR READS:' RETURN

```text
event 40 {
  @0x97C2: GOTO 0x9797
  // follows GOTO 0x9797
    @0x9797: PRINTCLEAR 'A MEETING ROOM.'
    @0x97A6: COMPARE Values: 1 == area1.event_word_214
    @0x97AC: IF = <if compare flag is false, skip next op>
    @0x97AD: EXIT
}
```
