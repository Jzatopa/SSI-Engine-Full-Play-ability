# GEO 17: Caloris Space Port

ECL block: `17`

First-pass pseudocode reconstructed from decoded ECL instructions. This is not original source.

## Event 01

- Target: `0x880A`
- Text hint: "'WELCOME TO CALORIS. I AM LORD BERKELEY'S CHANCELLOR, ALPHONSE DE SADE. LORD BERKELEY SENDS HIS GREETINGS. THE CORONATION WILL BEGIN SHORTLY.' HE TURNS HIS BACK AND QUICKLY MOVES AWAY."

```text
event 01 {
  @0x880A: AND area2.event_scratch0 = 4 & area1.event_word_25E
  @0x8813: IF <> <if compare flag is false, skip next op>
  @0x8814: GOTO 0x88B8
  // follows GOTO 0x88B8
    @0x88B8: SAVE area1.event_word_22A = abs_0001
    @0x88BF: SAVE area1.event_word_226 = 0
    @0x88C5: SAVE scratch.word_0000 = abs_000C
    @0x88D7: SAVE scratch.word_0208 = abs_0007
    @0x88E4: GOTO 0x8D1B
    // follows GOTO 0x8D1B
      @0x8D1B: COMPARE Values: 1 == area1.event_word_208
      @0x8D21: IF = <if compare flag is false, skip next op>
      @0x8D22: EXIT
}
```

## Event 02

- Target: `0x88E8`
- Text hint: 'LUNARIANS STAND WATCH. DO YOU QUESTION THEM?'

```text
event 02 {
  @0x88E8: COMPARE Values: 0 == area1.event_word_258
  @0x88EE: IF = <if compare flag is false, skip next op>
  @0x88EF: GOTO 0x89C0
  // follows GOTO 0x89C0
    @0x89C0: SAVE area1.event_word_22A = abs_0001
    @0x89C7: SAVE area1.event_word_226 = 0
    @0x89CD: SAVE scratch.word_0000 = abs_0006
    @0x89D9: SAVE scratch.word_0208 = abs_0004
    @0x89E3: GOTO 0x8D1B
    // follows GOTO 0x8D1B
      @0x8D1B: COMPARE Values: 1 == area1.event_word_208
      @0x8D21: IF = <if compare flag is false, skip next op>
      @0x8D22: EXIT
}
```

## Event 03

- Target: `0x8579`
- Text hint: "'WELCOME TO CALORIS. I AM LORD BERKELEY'S CHANCELLOR, ALPHONSE DE SADE. LORD BERKELEY SENDS HIS GREETINGS. THE CORONATION WILL BEGIN SHORTLY.' HE TURNS HIS BACK AND QUICKLY MOVES AWAY."

```text
event 03 {
  @0x8579: EXIT
}
```

## Event 04

- Target: `0x8A30`
- Text hint: 'THE TELLTALE ON THE DOOR READS,'

```text
event 04 {
  @0x8A30: SAVE area1.event_word_22A = abs_0001
  @0x8A37: SAVE area1.event_word_226 = 1
  @0x8A3D: GOTO 0x8D1B
  // follows GOTO 0x8D1B
    @0x8D1B: COMPARE Values: 1 == area1.event_word_208
    @0x8D21: IF = <if compare flag is false, skip next op>
    @0x8D22: EXIT
}
```

## Event 05

- Target: `0x8A41`
- Text hint: 'THE TELLTALE ON THE DOOR READS,'

```text
event 05 {
  @0x8A41: SAVE area1.event_word_22A = abs_0001
  @0x8A48: SAVE area1.event_word_226 = 1
  @0x8A4E: GOTO 0x8D1B
  // follows GOTO 0x8D1B
    @0x8D1B: COMPARE Values: 1 == area1.event_word_208
    @0x8D21: IF = <if compare flag is false, skip next op>
    @0x8D22: EXIT
}
```

## Event 06

- Target: `0x8A52`
- Text hint: 'THE TELLTALE ON THE DOOR READS,'

```text
event 06 {
  @0x8A52: COMPARE Values: 0 == area1.event_word_258
  @0x8A58: IF <> <if compare flag is false, skip next op>
  @0x8A59: GOTO 0x8A89
  // follows GOTO 0x8A89
    @0x8A89: COMPARE Values: 3 == area1.event_word_258
    @0x8A8F: IF >= <if compare flag is false, skip next op>
    @0x8A90: EXIT
}
```

## Event 07

- Target: `0x8C46`
- Text hint: 'THE TELLTALE ON THE DOOR READS,' RETURN

```text
event 07 {
  @0x8C46: AND area2.event_scratch0 = 8 & area1.event_word_25A
  @0x8C4F: IF <> <if compare flag is false, skip next op>
  @0x8C50: GOTO 0x8CF5
  // follows GOTO 0x8CF5
    @0x8CF5: SAVE area1.event_word_22A = abs_0001
    @0x8CFC: SAVE scratch.word_0000 = abs_0007
    @0x8D09: SAVE scratch.word_0208 = abs_0006
    @0x8D15: SAVE area1.event_word_226 = 0
    @0x8D1B: COMPARE Values: 1 == area1.event_word_208
    @0x8D21: IF = <if compare flag is false, skip next op>
    @0x8D22: EXIT
}
```

## Event 08

- Target: `0x8D74`
- Text hint: "A SERVICE DROID APPROACHES YOU. 'WELCOME TO THE RISING SUN. ARE YOU STAYING?'"

```text
event 08 {
  @0x8D74: COMPARE Values: 0 == abs_C04E
  @0x8D7A: IF <> <if compare flag is false, skip next op>
  @0x8D7B: EXIT
}
```

## Event 09

- Target: `0x8DD2`
- Text hint: 'AN OLD ROCKET JOCK WITH BLEARY EYES GREETS YOU WITH A SLURRED VOICE.'

```text
event 09 {
  @0x8DD2: AND area2.event_scratch0 = 1 & area1.event_word_25C
  @0x8DDB: IF = <if compare flag is false, skip next op>
  @0x8DDC: EXIT
}
```

## Event 10

- Target: `0x8E2E`
- Text hint: "A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '" '<string at area2.selected_player_name>' '<string at scratch.word_0208>'

```text
event 10 {
  @0x8E2F: EXIT
}
```

## Event 11

- Target: `0x8E9E`
- Text hint: "A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '" '<string at area2.selected_player_name>' '<string at scratch.word_0208>'

```text
event 11 {
  @0x8E9E: AND area2.event_scratch0 = 1 & area1.event_word_25C
  @0x8EA7: IF <> <if compare flag is false, skip next op>
  @0x8EA8: GOTO 0x8F19
  // follows GOTO 0x8F19
    @0x8F19: AND area2.event_scratch0 = 4 & area1.event_word_25C
    @0x8F22: IF <> <if compare flag is false, skip next op>
    @0x8F23: EXIT
}
```

## Event 12

- Target: `0x8F39`
- Text hint: 'YOU ENTER A DOCKSIDE BAR. '

```text
event 12 {
  @0x8F39: EXIT
}
```

## Event 13

- Target: `0x8F3A`
- Text hint: 'YOU ENTER A DOCKSIDE BAR. '

```text
event 13 {
  @0x8F3A: COMPARE Values: 2 == mapDirection
  @0x8F40: IF <> <if compare flag is false, skip next op>
  @0x8F41: EXIT
}
```

## Event 14

- Target: `0x90EE`
- Text hint: "A TINNY VOICE INTONES, 'THIS IS A CARGO ELEVATOR ONLY. PLEASE EXIT.'"

```text
event 14 {
  @0x90EE: PRINTCLEAR "A TINNY VOICE INTONES, 'THIS IS A CARGO ELEVATOR ONLY. PLEASE EXIT.'"
}
```

## Event 15

- Target: `0x9125`
- Text hint: 'TECHNICIANS ARE BUSY AT THEIR COM STATIONS.'

```text
event 15 {
  @0x9125: COMPARE Values: 0 == abs_C04E
  @0x912B: IF <> <if compare flag is false, skip next op>
  @0x912C: EXIT
}
```

## Event 16

- Target: `0x9178`
- Text hint: 'THE PORTMASTER IS TOO BUSY TO SPEAK TO YOU.' 'HONOR GUARDS STAND AT ATTENTION. '

```text
event 16 {
  @0x9178: COMPARE Values: 0 == abs_C04E
  @0x917E: IF <> <if compare flag is false, skip next op>
  @0x917F: EXIT
}
```

## Event 17

- Target: `0x91A6`
- Text hint: 'HONOR GUARDS STAND AT ATTENTION. '

```text
event 17 {
  @0x91A6: PRINTCLEAR 'HONOR GUARDS STAND AT ATTENTION. '
  @0x91C2: EXIT
}
```

## Event 18

- Target: `0x91C3`
- Text hint: "CHANCELLOR DE SADE SHAKES YOUR HAND GRACIOUSLY. '"

```text
event 18 {
  @0x91C3: COMPARE Values: 1 == area1.event_word_20E
  @0x91C9: IF = <if compare flag is false, skip next op>
  @0x91CA: GOTO 0x96B7
  // follows GOTO 0x96B7
    @0x96B7: COMPARE Values: 0 == abs_C04E
    @0x96BD: IF <> <if compare flag is false, skip next op>
    @0x96BE: EXIT
}
```

## Event 19

- Target: `0x92FB`
- Text hint: "CHANCELLOR DE SADE SHAKES YOUR HAND GRACIOUSLY. '" 'WITH BERKELEY DEAD, THERE IS NO NEED TO CONTINUE ANY NEGOTIATIONS ON AN ALLIANCE. NEVERTHELESS,' 'IT IS GOOD THAT YOU WERE HERE, AND TO SHOW OUR APPRECIATION,'

```text
event 19 {
  @0x92FB: AND area2.event_scratch0 = 8 & area1.event_word_25E
  @0x9304: IF = <if compare flag is false, skip next op>
  @0x9305: GOTO 0x96B7
  // follows GOTO 0x96B7
    @0x96B7: COMPARE Values: 0 == abs_C04E
    @0x96BD: IF <> <if compare flag is false, skip next op>
    @0x96BE: EXIT
}
```

## Event 20

- Target: `0x96CF`
- Text hint: "A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DESPERATELY. 'I AM DR. ROMNEY. PLEASE HELP ME GET TO THE SUN KING. IT IS MOST URGENT.'"

```text
event 20 {
  @0x96CF: COMPARE Values: 0 == area1.event_word_258
  @0x96D5: IF <> <if compare flag is false, skip next op>
  @0x96D6: EXIT
}
```

## Event 21

- Target: `0x9B80`
- Text hint: 'THIS IS A PRIVATE RESIDENCE.'

```text
event 21 {
  @0x9B80: COMPARE Values: 0 == abs_C04E
  @0x9B86: IF <> <if compare flag is false, skip next op>
  @0x9B87: EXIT
}
```

## Event 22

- Target: `0x9BA1`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 22 {
  @0x9BA1: EXIT
}
```

## Event 23

- Target: `0x9BA1`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 23 {
  @0x9BA1: EXIT
}
```

## Event 24

- Target: `0x9BA2`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 24 {
  @0x9BA2: SAVE scratch.word_0208 = abs_000C
  @0x9BB4: GOTO 0xA086
  // follows GOTO 0xA086
    @0xA086: PRINTCLEAR 'A PLAQUE READS,'
    @0xA095: PRINT RETURN
}
```

## Event 25

- Target: `0x9BB8`
- Text hint: 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'

```text
event 25 {
  @0x9BB8: COMPARE Values: 1 == area1.event_word_20E
  @0x9BBE: IF = <if compare flag is false, skip next op>
  @0x9BBF: GOTO 0xA008
  // follows GOTO 0xA008
    @0xA008: COMPARE Values: 3 == mapDirection
    @0xA00E: IF <> <if compare flag is false, skip next op>
    @0xA00F: EXIT
}
```

## Event 26

- Target: `0xA036`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 26 {
  @0xA036: SAVE scratch.word_0208 = abs_0009
  @0xA045: GOTO 0xA086
  // follows GOTO 0xA086
    @0xA086: PRINTCLEAR 'A PLAQUE READS,'
    @0xA095: PRINT RETURN
}
```

## Event 27

- Target: `0xA049`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 27 {
  @0xA049: EXIT
}
```

## Event 28

- Target: `0xA0AA`
- Text hint: "THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'"

```text
event 28 {
  @0xA0AA: PRINTCLEAR "THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'"
  @0xA176: SAVE scratch.word_0208 = abs_0005
  @0xA181: GOTO 0xA086
  // follows GOTO 0xA086
    @0xA086: PRINTCLEAR 'A PLAQUE READS,'
    @0xA095: PRINT RETURN
}
```

## Event 29

- Target: `0xA04A`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 29 {
  @0xA04A: SAVE scratch.word_0208 = abs_000B
  @0xA05B: GOTO 0xA086
  // follows GOTO 0xA086
    @0xA086: PRINTCLEAR 'A PLAQUE READS,'
    @0xA095: PRINT RETURN
}
```

## Event 30

- Target: `0xA176`
- Text hint: "HOLD ON, A MESSAGE FOR YOU IS JUST COMING IN.'"

```text
event 30 {
  @0xA176: SAVE scratch.word_0208 = abs_0005
  @0xA181: GOTO 0xA086
  // follows GOTO 0xA086
    @0xA086: PRINTCLEAR 'A PLAQUE READS,'
    @0xA095: PRINT RETURN
}
```

## Event 31

- Target: `0xA05F`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 31 {
  @0xA05F: SAVE scratch.word_0208 = abs_000B
  @0xA070: GOTO 0xA086
  // follows GOTO 0xA086
    @0xA086: PRINTCLEAR 'A PLAQUE READS,'
    @0xA095: PRINT RETURN
}
```

## Event 32

- Target: `0xA074`
- Text hint: 'A PLAQUE READS,' RETURN

```text
event 32 {
  @0xA074: SAVE scratch.word_0208 = abs_000C
  @0xA086: PRINTCLEAR 'A PLAQUE READS,'
  @0xA095: PRINT RETURN
}
```
