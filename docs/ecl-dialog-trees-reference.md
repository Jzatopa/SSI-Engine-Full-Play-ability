# Matrix Cubed ECL Dialog Trees Reference

This file is generated from decoded ECL listings plus the Gold Box whole-block text scan.
It is a reference for dialog/menu reconstruction, not proof that every nearby packed string is owned by the displayed instruction.

## Summary

- Missing Gold Box text hit rows attached: 123
- Unique normalized still-missing strings: 75
- Compiled dialog conversation rows: 14
- Address mapping: `vm_address = 0x8000 + decoded ECL block offset`
- `branch_target_region`: 122
- `prompt_or_menu_region`: 1

## Compiled Dialog Conversations

These compact rows are intended for runtime and capture validation. They retain confidence labels because nearby missing-text attachments are not proof of ownership by themselves.

| GEO | Event | Target | Choices | Confidence |
|---:|---:|---:|---|---|
| 17 Caloris Space Port | 20 | 0x96CF | HELP ROMNEY | attached_missing_text_near_branch |
| 17 Caloris Space Port | 28 | 0xA0AA | SOMEONE ELSE? | attached_missing_text_near_branch |
| 38 Losangelorg Sprawls | 5 | 0x88BD | SMOKING GUN SLOTS | attached_missing_text_near_branch |
| 38 Losangelorg Sprawls | 6 | 0x8949 | SOMEONE ELSE? | attached_missing_text_near_branch |
| 51 Venus Laboratory, Level 2 | 25 | 0x8EF2 | MOVE CLOSER | attached_missing_text_near_branch |
| 64 Luna Base | 5 | 0x8243 | COPERNICUS POLICE | attached_missing_text_near_branch |
| 64 Luna Base | 7 | 0x8350 | HE CONTINUES, | attached_missing_text_near_branch |
| 64 Luna Base | 33 | 0x946A | GIOTTO MINING | attached_missing_text_near_branch |
| 66 RAM Battler, Deimos Level 19-41 | 6 | 0x8A10 | HE CONTINUES; HIS OFFER | attached_missing_text_near_branch |
| 66 RAM Battler, Deimos Level 19-41 | 17 | 0x94DF | DECLINE | attached_missing_text_near_branch |
| 81 PURGE Headquarters, Floors Ground-Upper | 24 | 0x955B | HE CONTINUES | attached_missing_text_near_branch |
| 82 NEO Installation | 18 | 0x90C7 | WHO WILL TRY?; WILBUR | attached_missing_text_near_branch |
| 112 Stormrider University | 27 | 0x992F | DEFUSE; SOMEONE ELSE? | attached_missing_text_near_branch |
| 113 Genetics Foundation Building, Levels 1-4 | 18 | 0x9682 | WHO TRIES? | attached_missing_text_near_branch |

## Still-Missing Text Attachments

| # | ECL | VM address | Text | Attachment | Owner target | Owner summary |
|---:|---:|---:|---|---|---:|---|
| 1 | 1 | 0x8A34 | BIGPIC | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 2 | 19 | 0x92D6 | BLUFF | branch_target_region | 0x91C7 | 0x925F 0x01 GOTO 0x004C |
| 3 | 1 | 0x81A7 | BOXPIC | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 4 | 18 | 0x883B | BUCK CONTINUES, | branch_target_region | 0x82B0 | 0x82BA 0x00 EXIT |
| 5 | 33 | 0x9ADB | CHEER | branch_target_region | 0x9A0B | 0x9A3E 0x00 EXIT |
| 6 | 95 | 0x9091 | CHOOSE: | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 7 | 80 | 0x97E6 | CLOSE LINKS | branch_target_region | 0x9608 | 0x9652 0x11 PRINT "'" |
| 8 | 19 | 0x98B4 | CONTROLS: | branch_target_region | 0x97F3 | 0x9850 0x13 RETURN |
| 8 | 95 | 0x90E5 | CONTROLS: | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 9 | 20 | 0x9AE8 | CONVINCE | branch_target_region | 0x97EE | 0x98A7 0x13 RETURN |
| 9 | 96 | 0xA293 | CONVINCE | branch_target_region | 0xA1D3 | 0xA1D7 0x11 PRINT 'THEY ATTACK!' |
| 9 | 97 | 0x9B49 | CONVINCE | branch_target_region | 0x9A92 | 0x9AB4 0x00 EXIT |
| 9 | 98 | 0x9FAA | CONVINCE | branch_target_region | 0x9E8F | 0x9EA3 0x12 PRINTCLEAR 'THE WALLS HERE ARE LIVID AND BULGE WITH AN UNHEALTHY PULSE. DO YOU TRY TO TREAT IT?' |
| 10 | 64 | 0x824E | COPERNICUS POLICE | branch_target_region | 0x8243 | 0x824A 0x00 EXIT |
| 11 | 95 | 0x946D | CURRENT FUEL: | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 12 | 33 | 0x96C8 | DECLINE | branch_target_region | 0x9657 | 0x9672 0x00 EXIT |
| 12 | 37 | 0x876C | DECLINE | branch_target_region | 0x86F0 | 0x8716 0x00 EXIT |
| 12 | 66 | 0x8932 | DECLINE | branch_target_region | 0x8629 | 0x8672 0x11 PRINT 'THE AIR LOCK BEGINS CYCLING.' |
| 12 | 66 | 0x954B | DECLINE | branch_target_region | 0x94DF | 0x94E6 0x00 EXIT |
| 13 | 112 | 0x99D3 | DEFUSE | branch_target_region | 0x992F | 0x9947 0x12 PRINTCLEAR 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?' |
| 14 | 20 | 0x82FB | DEPOSIT | branch_target_region | 0x829C | 0x82F4 0x01 GOTO 0x004C |
| 15 | 36 | 0x913A | DOOR IN FRONT OF YOU | branch_target_region | 0x90B6 | 0x90ED 0x00 EXIT |
| 16 | 1 | 0x8165 | DROPBUCK | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 17 | 1 | 0x810B | DUEL | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 18 | 20 | 0x98BE | EETBUGS B+G | branch_target_region | 0x97EE | 0x98A7 0x13 RETURN |
| 19 | 82 | 0x8D0F | ELROY | prompt_or_menu_region | 0x8CB5 | 0x8CF4 0x12 PRINTCLEAR "'TELL US THE WORD:'" |
| 20 | 19 | 0x98F7 | ENGINES: | branch_target_region | 0x97F3 | 0x9850 0x13 RETURN |
| 20 | 95 | 0x9107 | ENGINES: | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 21 | 95 | 0x9167 | ENGN | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 22 | 17 | 0x89D0 | EPHESUS | branch_target_region | 0x89C0 | 0x89CD 0x09 SAVE scratch.word_0000 = abs_0006 |
| 23 | 33 | 0x983C | FIGHT MONKS | branch_target_region | 0x97AA | 0x97D2 0x00 EXIT |
| 24 | 1 | 0x83BC | FIGHT WHICH SHIP TYPE? | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 25 | 64 | 0x9475 | GIOTTO MINING | branch_target_region | 0x946A | 0x9471 0x00 EXIT |
| 26 | 37 | 0x8397 | GROTESQUES | branch_target_region | 0x834C | 0x838B 0x00 EXIT |
| 27 | 66 | 0x8B57 | HE CONTINUES | branch_target_region | 0x8A10 | 0x8A13 0x12 PRINTCLEAR "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES." |
| 27 | 81 | 0x9617 | HE CONTINUES | branch_target_region | 0x955B | 0x9585 0x12 PRINTCLEAR "AN EMACIATED MAN IN A TATTERED LAB COAT APPROACHES. IT'S DR. ROMNEY!" |
| 28 | 50 | 0x8882 | HE CONTINUES, | branch_target_region | 0x882A | 0x8840 0x12 PRINTCLEAR "LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'" |
| 28 | 64 | 0x8450 | HE CONTINUES, | branch_target_region | 0x8350 | 0x8372 0x12 PRINTCLEAR "A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS." |
| 29 | 80 | 0x99D7 | HELP HIM | branch_target_region | 0x9608 | 0x9652 0x11 PRINT "'" |
| 30 | 33 | 0x8C7D | HELP LEECHES | branch_target_region | 0x8BFD | 0x8C23 0x00 EXIT |
| 31 | 17 | 0x98E0 | HELP ROMNEY | branch_target_region | 0x96CF | 0x96DD 0x12 PRINTCLEAR "A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DESPERATELY. 'I AM DR. ROMNEY. PLEASE HELP ME GET TO THE SUN KING. IT IS MOST URGENT.'" |
| 32 | 66 | 0x8B63 | HIS OFFER | branch_target_region | 0x8A10 | 0x8A13 0x12 PRINTCLEAR "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES." |
| 33 | 48 | 0x8F66 | HIS SPEECH | branch_target_region | 0x8E9B | 0x8EA8 0x00 EXIT |
| 33 | 113 | 0x8600 | HIS SPEECH | branch_target_region | 0x8014 | 0x8060 0x00 EXIT |
| 34 | 18 | 0x9D6C | HOW MUCH? | branch_target_region | 0x9D42 | 0x9D42 0x12 PRINTCLEAR 'YOU LEAVE THE BAR.' |
| 34 | 20 | 0x9653 | HOW MUCH? | branch_target_region | 0x9632 | 0x9647 0x13 RETURN |
| 35 | 95 | 0x9153 | HULL | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 36 | 19 | 0x9874 | HULL: | branch_target_region | 0x97F3 | 0x9850 0x13 RETURN |
| 36 | 95 | 0x90C3 | HULL: | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 37 | 37 | 0x97D7 | KILL HIM | branch_target_region | 0x948C | 0x94AF 0x00 EXIT |
| 37 | 84 | 0x8BED | KILL HIM | branch_target_region | 0x8921 | 0x8976 0x00 EXIT |
| 38 | 36 | 0x853C | KNOCK | branch_target_region | 0x8507 | 0x8527 0x01 GOTO 0x004C |
| 39 | 34 | 0x9726 | LOOK FOR HIS NOTES | branch_target_region | 0x9642 | 0x966D 0x12 PRINTCLEAR "CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'" |
| 40 | 95 | 0x92EF | MISSILE | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 40 | 95 | 0x95C0 | MISSILE | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 41 | 50 | 0x8F39 | MOVE CLOSER | branch_target_region | 0x8EF2 | 0x8F04 0x00 EXIT |
| 42 | 49 | 0x8455 | OPEN LOCK | branch_target_region | 0x844D | 0x8451 0x00 EXIT |
| 43 | 81 | 0x8463 | OPEN LOCKS | branch_target_region | 0x8426 | 0x845F 0x00 EXIT |
| 44 | 97 | 0x8040 | PE:PE:BPDB | branch_target_region | 0x8014 | 0x803B 0x01 GOTO 0x80D7 |
| 45 | 1 | 0x8750 | PERSON # | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 45 | 1 | 0x8814 | PERSON # | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 45 | 1 | 0x8933 | PERSON # | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 46 | 36 | 0x852E | PICK LOCK | branch_target_region | 0x8507 | 0x8527 0x01 GOTO 0x004C |
| 47 | 1 | 0x8A65 | PICTURE: | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 48 | 1 | 0x811E | PREV | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 48 | 1 | 0x816D | PREV | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 48 | 1 | 0x81BA | PREV | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 48 | 64 | 0xA39E | PREV | branch_target_region | 0xA33C | 0xA357 0x13 RETURN |
| 49 | 1 | 0x868F | PRSKILL | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 50 | 95 | 0x949D | REFUEL | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 51 | 33 | 0x8898 | RESIDENTS | branch_target_region | 0x87CD | 0x87D5 0x12 PRINTCLEAR 'A LOCKER ROOM MADE INTO A KITCHEN.' |
| 52 | 36 | 0x8186 | RISER? | branch_target_region | 0x8168 | 0x8183 0x09 SAVE scratch.word_0208 = abs_0006 |
| 53 | 84 | 0x9A8B | SEE FILES | branch_target_region | 0x99E0 | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" |
| 53 | 84 | 0x9B0F | SEE FILES | branch_target_region | 0x99E0 | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" |
| 53 | 84 | 0x9B7B | SEE FILES | branch_target_region | 0x99E0 | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" |
| 53 | 84 | 0x9BE6 | SEE FILES | branch_target_region | 0x99E0 | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" |
| 54 | 19 | 0x9893 | SENSORS: | branch_target_region | 0x97F3 | 0x9850 0x13 RETURN |
| 54 | 95 | 0x90D4 | SENSORS: | branch_target_region | 0x8ED8 | 0x8EF5 0x01 GOTO 0x004C |
| 55 | 65 | 0x8740 | SHE CONTINUES | branch_target_region | 0x861B | 0x8641 0x00 EXIT |
| 56 | 1 | 0x8452 | SHIP # | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 57 | 1 | 0x8629 | SKILL | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 58 | 38 | 0x893B | SMOKING GUN SLOTS | branch_target_region | 0x88BD | 0x88F5 0x11 PRINT 'RED RIVER BAR' |
| 59 | 17 | 0xA12F | SOMEONE ELSE? | branch_target_region | 0xA0AA | 0xA0AA 0x12 PRINTCLEAR "THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'" |
| 59 | 38 | 0x8B85 | SOMEONE ELSE? | branch_target_region | 0x8949 | 0x8968 0x12 PRINTCLEAR 'A MAN IN A RAGGED MILITARY UNIFORM SITS AGAINST THE WALL HERE.' |
| 59 | 112 | 0x9AF6 | SOMEONE ELSE? | branch_target_region | 0x992F | 0x9947 0x12 PRINTCLEAR 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?' |
| 60 | 1 | 0x81A0 | SPRITE | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 61 | 98 | 0xA0A2 | USE DEVICE | branch_target_region | 0xA071 | 0xA08B 0x01 GOTO 0x004C |
| 62 | 1 | 0x8640 | VIEW | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 63 | 64 | 0xA04E | WHICH FILE? | branch_target_region | 0x9856 | 0x9856 0x12 PRINTCLEAR 'THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?' |
| 64 | 1 | 0x8700 | WHICH ONE? | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 64 | 1 | 0x87C3 | WHICH ONE? | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 64 | 1 | 0x8887 | WHICH ONE? | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 64 | 20 | 0x833A | WHICH ONE? | branch_target_region | 0x829C | 0x82F4 0x01 GOTO 0x004C |
| 64 | 20 | 0x838C | WHICH ONE? | branch_target_region | 0x829C | 0x82F4 0x01 GOTO 0x004C |
| 65 | 37 | 0x83A3 | WHITE MONKS | branch_target_region | 0x834C | 0x838B 0x00 EXIT |
| 66 | 18 | 0x991A | WHO BETS? | branch_target_region | 0x9895 | 0x9895 0x12 PRINTCLEAR 'AN UNKEMPT LOOKING ROCKET JOCK STEPS UP.' |
| 67 | 66 | 0x9C01 | WHO TRIES? | branch_target_region | 0x9B98 | 0x9B9F 0x00 EXIT |
| 67 | 81 | 0x820C | WHO TRIES? | branch_target_region | 0x8149 | 0x81C0 0x11 PRINT "SHE EYES YOU WARILY. 'DO YOU HAVE BUSINESS WITH US?'" |
| 67 | 84 | 0x8350 | WHO TRIES? | branch_target_region | 0x82F2 | 0x830E 0x12 PRINTCLEAR 'THE TERMINAL OF THIS COMPUTER IS ACTIVE. DO YOU TRY TO OPERATE THE COMPUTER?' |
| 67 | 84 | 0x8880 | WHO TRIES? | branch_target_region | 0x8811 | 0x881C 0x12 PRINTCLEAR 'SEARCHING THE LAB, YOU FIND PARTS OF A DISMANTLED LASER RIFLE.' |
| 67 | 84 | 0x9A0B | WHO TRIES? | branch_target_region | 0x99E0 | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" |
| 67 | 112 | 0x9FCB | WHO TRIES? | branch_target_region | 0x9EBE | 0x9ED5 0x11 PRINT ". A SMALL FIRE IS BURNING IN THIS ROOM, AND IT'S BEGINNING TO SPREAD." |
| 67 | 113 | 0x9725 | WHO TRIES? | branch_target_region | 0x9682 | 0x968A 0x12 PRINTCLEAR 'YOU ENTER A COLD STORAGE ROOM.' |
| 68 | 80 | 0xA38E | WHO WILL DO IT? | branch_target_region | 0xA345 | 0xA373 0x13 RETURN |
| 68 | 114 | 0xA379 | WHO WILL DO IT? | branch_target_region | 0xA341 | 0xA348 0x00 EXIT |
| 69 | 20 | 0x9B07 | WHO WILL TRY? | branch_target_region | 0x97EE | 0x98A7 0x13 RETURN |
| 69 | 20 | 0x9B3C | WHO WILL TRY? | branch_target_region | 0x97EE | 0x98A7 0x13 RETURN |
| 69 | 36 | 0x9CF2 | WHO WILL TRY? | branch_target_region | 0x9C6C | 0x9C73 0x00 EXIT |
| 69 | 37 | 0xA345 | WHO WILL TRY? | branch_target_region | 0xA287 | 0xA28B 0x11 PRINT ' NOTICES A TRIPWIRE STRETCHED ACROSS THE RUBBLE. DO YOU TRY TO DISARM THE DEMO CHARGES?' |
| 69 | 64 | 0xA036 | WHO WILL TRY? | branch_target_region | 0x9856 | 0x9856 0x12 PRINTCLEAR 'THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?' |
| 69 | 65 | 0x9765 | WHO WILL TRY? | branch_target_region | 0x9734 | 0x9761 0x00 EXIT |
| 69 | 82 | 0x9124 | WHO WILL TRY? | branch_target_region | 0x90C7 | 0x90E8 0x12 PRINTCLEAR 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?' |
| 69 | 82 | 0x9329 | WHO WILL TRY? | branch_target_region | 0x92B7 | 0x92EF 0x12 PRINTCLEAR 'YOU NOTE A SUBROUTINE CONTAINING PASSWORDS. DO YOU TRY TO ACCESS?' |
| 69 | 96 | 0xA310 | WHO WILL TRY? | branch_target_region | 0xA1D3 | 0xA1D7 0x11 PRINT 'THEY ATTACK!' |
| 69 | 97 | 0x9BC0 | WHO WILL TRY? | branch_target_region | 0x9A92 | 0x9AB4 0x00 EXIT |
| 69 | 98 | 0xA021 | WHO WILL TRY? | branch_target_region | 0x9E8F | 0x9EA3 0x12 PRINTCLEAR 'THE WALLS HERE ARE LIVID AND BULGE WITH AN UNHEALTHY PULSE. DO YOU TRY TO TREAT IT?' |
| 70 | 82 | 0x82E3 | WILBUR | branch_target_region | 0x82AA | 0x82AA 0x12 PRINTCLEAR 'A GUARD STEPS UP AND ASKS FOR A PASSWORD. WHAT DO YOU SAY?' |
| 70 | 82 | 0x9161 | WILBUR | branch_target_region | 0x90C7 | 0x90E8 0x12 PRINTCLEAR 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?' |
| 71 | 1 | 0x8A49 | WILD | branch_target_region | 0x835A | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |
| 72 | 80 | 0x9674 | WILL SOMEONE TRY TO | branch_target_region | 0x9608 | 0x9652 0x11 PRINT "'" |
| 73 | 1 | 0x8297 | X POSITION: | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 74 | 1 | 0x82A9 | Y POSITION: | branch_target_region | 0x80C9 | 0x80CA 0x00 EXIT |
| 75 | 113 | 0x8CCD | YOU GO TO FLOOR | branch_target_region | 0x8C81 | 0x8C81 0x12 PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?' |

## Dialog Trees By ECL Block

### ECL 1 - GEO 1: Luna Base

Attached still-missing strings:
- 0x810B: owner 0x80C9; `branch_target_region` `DUEL`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x811E: owner 0x80C9; `branch_target_region` `PREV`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x8165: owner 0x80C9; `branch_target_region` `DROPBUCK`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x816D: owner 0x80C9; `branch_target_region` `PREV`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x81A0: owner 0x80C9; `branch_target_region` `SPRITE`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x81A7: owner 0x80C9; `branch_target_region` `BOXPIC`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x81BA: owner 0x80C9; `branch_target_region` `PREV`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x8297: owner 0x80C9; `branch_target_region` `X POSITION:`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x82A9: owner 0x80C9; `branch_target_region` `Y POSITION:`. incoming: 0x8022 GOTO 0x80C9; 0x80C5 GOTO 0x80C9; entry CampInterrupted; entry PreCampCheck; entry SearchLocation; entry vm_run_1
- 0x83BC: owner 0x835A; `branch_target_region` `FIGHT WHICH SHIP TYPE?`. incoming: 0x8078 GOTO 0x835A
- 0x8452: owner 0x835A; `branch_target_region` `SHIP #`. incoming: 0x8078 GOTO 0x835A
- 0x8629: owner 0x835A; `branch_target_region` `SKILL`. incoming: 0x8078 GOTO 0x835A
- 0x8640: owner 0x835A; `branch_target_region` `VIEW`. incoming: 0x8078 GOTO 0x835A
- 0x868F: owner 0x835A; `branch_target_region` `PRSKILL`. incoming: 0x8078 GOTO 0x835A
- 0x8700: owner 0x835A; `branch_target_region` `WHICH ONE?`. incoming: 0x8078 GOTO 0x835A
- 0x8750: owner 0x835A; `branch_target_region` `PERSON #`. incoming: 0x8078 GOTO 0x835A
- 0x87C3: owner 0x835A; `branch_target_region` `WHICH ONE?`. incoming: 0x8078 GOTO 0x835A
- 0x8814: owner 0x835A; `branch_target_region` `PERSON #`. incoming: 0x8078 GOTO 0x835A
- 0x8887: owner 0x835A; `branch_target_region` `WHICH ONE?`. incoming: 0x8078 GOTO 0x835A
- 0x8933: owner 0x835A; `branch_target_region` `PERSON #`. incoming: 0x8078 GOTO 0x835A
- 0x8A34: owner 0x835A; `branch_target_region` `BIGPIC`. incoming: 0x8078 GOTO 0x835A
- 0x8A49: owner 0x835A; `branch_target_region` `WILD`. incoming: 0x8078 GOTO 0x835A
- 0x8A65: owner 0x835A; `branch_target_region` `PICTURE:`. incoming: 0x8078 GOTO 0x835A

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8014 | entry ecl_initial_entry | `0x8026 0x12 PRINTCLEAR 'DO YOU WANT TO START FROM SCRATCH OR USE THE JUMPER?'` |
| 0x8050 |  | `0x8050 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'JUMPER', 'START'` |

### ECL 2

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8038 | entry SearchLocation | `0x8046 0x12 PRINTCLEAR 'FIGHT HERE?'` |

### ECL 17 - GEO 17: Caloris Space Port

Attached still-missing strings:
- 0x89D0: owner 0x89C0; `branch_target_region` `EPHESUS`. incoming: 0x88EF GOTO 0x89C0; 0x88FD GOTO 0x89C0
- 0x98E0: owner 0x96CF; `branch_target_region` `HELP ROMNEY`. incoming: 0x8510 ON GOTO area2.event_scratch1 choice 20
- 0xA12F: owner 0xA0AA; `branch_target_region` `SOMEONE ELSE?`. incoming: 0x8510 ON GOTO area2.event_scratch1 choice 28

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x80F6 | 0x80CD ON GOTO area2.event_scratch0 choice 2<br>0x80F2 GOTO 0x80F6 | `0x80F6 0x12 PRINTCLEAR 'THE AIRLOCK IS SEALED.'` |
| 0x840B | 0x82FF GOTO 0x840B | `0x840E 0x12 PRINTCLEAR 'SCOT.DOS APPEARS ON THE SCREEN. '` |
|  |  | `0x8438 0x11 PRINT "'A PRISONER TRANSFER IS TAKING PLACE ON THE DOCKS AT BERTH A. I'M SURE IT'S RELATED TO THE EARLIER KIDNAPPING."` |
|  |  | `0x849C 0x11 PRINT ' '` |
|  |  | `0x84A7 0x12 PRINTCLEAR "SCOT.DOS LOOKS GRIM. 'THIS IS MORE SERIOUS THAN I THOUGHT. HURRY, LAUNCH PREPARATIONS ARE BEGINNING."` |
| 0x84F5 | 0x8498 GOTO 0x84F5 | `0x84F5 0x11 PRINT "'"` |
| 0x880A | 0x8510 ON GOTO area2.event_scratch1 choice 1 | `0x8824 0x12 PRINTCLEAR "'WELCOME TO CALORIS. I AM LORD BERKELEY'S CHANCELLOR, ALPHONSE DE SADE. LORD BERKELEY SENDS HIS GREETINGS. THE CORONATION WILL BEGIN SHORTLY.' HE TURNS HIS BACK AND QUICKLY MOVES AWAY."` |
| 0x88E8 | 0x8510 ON GOTO area2.event_scratch1 choice 2 | `0x8901 0x12 PRINTCLEAR 'LUNARIANS STAND WATCH. DO YOU QUESTION THEM?'` |
| 0x8D1B | 0x88E4 GOTO 0x8D1B<br>0x89E3 GOTO 0x8D1B<br>0x8A3D GOTO 0x8D1B<br>0x8A4E GOTO 0x8D1B<br>0x8A85 GOTO 0x8D1B | `0x8D23 0x12 PRINTCLEAR 'THE TELLTALE ON THE DOOR READS,'` |
|  |  | `0x8D3E 0x33 PRINT RETURN` |
|  |  | `0x8D3F 0x33 PRINT RETURN` |
|  |  | `0x8D40 0x11 PRINT 'BERTH '` |
|  |  | `0x8D48 0x11 PRINT '<string at area1.event_word_22A>'` |
|  |  | `0x8D54 0x33 PRINT RETURN` |
|  |  | `0x8D55 0x11 PRINT 'SHIP:  '` |
|  |  | `0x8D5E 0x11 PRINT '<string at scratch.word_0000>'` |
|  |  | `0x8D62 0x33 PRINT RETURN` |
|  |  | `0x8D63 0x11 PRINT 'HOMEPORT:  '` |
|  |  | `0x8D6F 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x8D74 | 0x8510 ON GOTO area2.event_scratch1 choice 8 | `0x8D7C 0x12 PRINTCLEAR "A SERVICE DROID APPROACHES YOU. 'WELCOME TO THE RISING SUN. ARE YOU STAYING?'"` |
| 0x8DD2 | 0x8510 ON GOTO area2.event_scratch1 choice 9 | `0x8DDD 0x12 PRINTCLEAR 'AN OLD ROCKET JOCK WITH BLEARY EYES GREETS YOU WITH A SLURRED VOICE.'` |
| 0x8EB2 | 0x8F35 GOTO 0x8EB2 | `0x8EB2 0x12 PRINTCLEAR "A DISEMBODIED VOICE ECHOES THROUGH THE HALL, '"` |
|  |  | `0x8F02 0x11 PRINT '<string at area2.selected_player_name>'` |
|  |  | `0x8F06 0x11 PRINT '<string at scratch.word_0208>'` |
|  |  | `0x8F0A 0x33 PRINT RETURN` |
|  |  | `0x8F0B 0x11 PRINT '<string at area2.selected_player_name>'` |
|  |  | `0x8F0F 0x11 PRINT '<string at scratch.word_0208>'` |
|  |  | `0x8F13 0x11 PRINT "'"` |
| 0x8F3A | 0x8510 ON GOTO area2.event_scratch1 choice 13 | `0x8F42 0x12 PRINTCLEAR 'YOU ENTER A DOCKSIDE BAR. '` |
| 0x90EE | 0x8510 ON GOTO area2.event_scratch1 choice 14 | `0x90EE 0x12 PRINTCLEAR "A TINNY VOICE INTONES, 'THIS IS A CARGO ELEVATOR ONLY. PLEASE EXIT.'"` |
| 0x9125 | 0x8510 ON GOTO area2.event_scratch1 choice 15 | `0x912D 0x12 PRINTCLEAR 'TECHNICIANS ARE BUSY AT THEIR COM STATIONS.'` |
|  |  | `0x9167 0x11 PRINT " ONE SAYS, '"` |
| 0x9178 | 0x8510 ON GOTO area2.event_scratch1 choice 16 | `0x9180 0x12 PRINTCLEAR 'THE PORTMASTER IS TOO BUSY TO SPEAK TO YOU.'` |
| 0x91A6 | 0x8510 ON GOTO area2.event_scratch1 choice 17 | `0x91A6 0x12 PRINTCLEAR 'HONOR GUARDS STAND AT ATTENTION. '` |
| 0x92FB | 0x8510 ON GOTO area2.event_scratch1 choice 19 | `0x9322 0x12 PRINTCLEAR "CHANCELLOR DE SADE SHAKES YOUR HAND GRACIOUSLY. '"` |
|  |  | `0x9354 0x11 PRINT 'WITH BERKELEY DEAD, THERE IS NO NEED TO CONTINUE ANY NEGOTIATIONS ON AN ALLIANCE. NEVERTHELESS,'` |
|  |  | `0x93A0 0x11 PRINT 'IT IS GOOD THAT YOU WERE HERE, AND TO SHOW OUR APPRECIATION,'` |
|  |  | `0x93D0 0x11 PRINT " HERE IS PAYMENT FOR YOUR SERVICES.'"` |
| 0x96B7 | 0x91CA GOTO 0x96B7<br>0x91D8 GOTO 0x96B7<br>0x91E6 GOTO 0x96B7<br>0x9305 GOTO 0x96B7<br>0x9622 GOTO 0x96B7<br>0x9630 GOTO 0x96B7 | `0x96BF 0x12 PRINTCLEAR 'NOBODY IS HERE.'` |
| 0x96CF | 0x8510 ON GOTO area2.event_scratch1 choice 20 | `0x96DD 0x12 PRINTCLEAR "A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DESPERATELY. 'I AM DR. ROMNEY. PLEASE HELP ME GET TO THE SUN KING. IT IS MOST URGENT.'"` |
| 0x9B80 | 0x8510 ON GOTO area2.event_scratch1 choice 21 | `0x9B88 0x12 PRINTCLEAR 'THIS IS A PRIVATE RESIDENCE.'` |
| 0x9BB8 | 0x8510 ON GOTO area2.event_scratch1 choice 25 | `0x9BCE 0x12 PRINTCLEAR 'THE HALL IS THRONGED WITH DIGNITARIES AND PERSONAGES FROM DIVERSE CULTURES: DANCERS, MUSICIANS, LUNARIANS, VENUSIANS, AND TERRANS.'` |
| 0xA008 | 0x9BBF GOTO 0xA008 | `0xA010 0x12 PRINTCLEAR 'PEOPLE MILL ABOUT, WAITING FOR THE SUN KING.'` |
| 0xA086 | 0x9BB4 GOTO 0xA086<br>0xA045 GOTO 0xA086<br>0xA05B GOTO 0xA086<br>0xA070 GOTO 0xA086<br>0xA181 GOTO 0xA086 | `0xA086 0x12 PRINTCLEAR 'A PLAQUE READS,'` |
|  |  | `0xA095 0x33 PRINT RETURN` |
|  |  | `0xA096 0x33 PRINT RETURN` |
|  |  | `0xA097 0x11 PRINT "       '"` |
|  |  | `0xA0A0 0x11 PRINT '<string at scratch.word_0208>'` |
|  |  | `0xA0A4 0x11 PRINT ".'"` |
| 0xA0AA | 0x8510 ON GOTO area2.event_scratch1 choice 28 | `0xA0AA 0x12 PRINTCLEAR "THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'"` |
| 0xA1C5 | 0x84A0 GOSUB 0xA1C5<br>0x9173 GOSUB 0xA1C5 | `0xA1C5 0x11 PRINT "HOLD ON, A MESSAGE FOR YOU IS JUST COMING IN.'"` |

### ECL 18 - GEO 18: Asteroid

Attached still-missing strings:
- 0x883B: owner 0x82B0; `branch_target_region` `BUCK CONTINUES,`. incoming: 0x8276 GOTO 0x82B0
- 0x991A: owner 0x9895; `branch_target_region` `WHO BETS?`. incoming: 0x9714 ON GOTO area1.event_word_26C choice 3
- 0x9D6C: owner 0x9D42; `branch_target_region` `HOW MUCH?`. incoming: 0x9494 ON GOTO area2.event_scratch0 choice 3

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x9128 | 0x9181 GOTO 0x9128<br>entry CampInterrupted<br>entry PreCampCheck<br>entry SearchLocation<br>entry vm_run_1 | `0x9132 0x12 PRINTCLEAR 'WHERE DO YOU WISH TO GO?'` |
| 0x9147 |  | `0x9147 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'BAR', 'CLINIC', 'DEPOT', 'TRAINING', 'PORT'` |
| 0x918F | 0x916C ON GOSUB area2.event_scratch0 choice 4 | `0x918F 0x12 PRINTCLEAR 'YOU ARE IN THE SALVATION PORT AREA.'` |
|  |  | `0x91AD 0x33 PRINT RETURN` |
|  |  | `0x91AE 0x33 PRINT RETURN` |
| 0x937C | 0x916C ON GOSUB area2.event_scratch0 choice 1 | `0x9382 0x12 PRINTCLEAR 'THE AUTODOC HEALS EVERYONE IN THE TEAM.'` |
| 0x9432 | 0x916C ON GOSUB area2.event_scratch0 choice 0 | `0x9438 0x12 PRINTCLEAR "YOU ENTER 'THE LOST ORBIT' -- SALVATION'S PORT LOUNGE."` |
| 0x9464 | 0x9CE9 GOTO 0x9464 | `0x9464 0x33 PRINT RETURN` |
|  |  | `0x9465 0x33 PRINT RETURN` |
|  |  | `0x9466 0x11 PRINT 'WHAT DO YOU DO?'` |
| 0x9475 |  | `0x9475 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'BUY DRINKS', 'TALK', 'WAIT', 'EXIT'` |
| 0x94A6 | 0x9494 ON GOTO area2.event_scratch0 choice 0 | `0x94AF 0x12 PRINTCLEAR 'A ROUND OF DRINKS WILL COST '` |
|  |  | `0x94C7 0x11 PRINT area2.event_scratch2` |
|  |  | `0x94CB 0x11 PRINT ' CREDITS.'` |
| 0x95C2 | 0x9494 ON GOTO area2.event_scratch0 choice 1 | `0x95D6 0x12 PRINTCLEAR 'YOU CHAT WITH THE OTHER PATRONS. '` |
| 0x961B | 0x95F9 GOTO 0x961B<br>0x9604 GOTO 0x961B | `0x961B 0x11 PRINT 'NOTHING NOTEWORTHY HAPPENS.'` |
| 0x9638 | 0x9494 ON GOTO area2.event_scratch0 choice 2 | `0x964C 0x12 PRINTCLEAR 'YOU WAIT IN THE BAR. '` |
| 0x9663 | 0x95C9 GOTO 0x9663<br>0x963F GOTO 0x9663 | `0x9663 0x12 PRINTCLEAR 'THE BARTENDER YELLS, HEY! '` |
| 0x968C | 0x9680 ON GOTO area2.event_scratch0 choice 0 | `0x968C 0x11 PRINT 'YOU BUMS GONNA BUY A DRINK...OR WHAT?'` |
| 0x96AF | 0x9680 ON GOTO area2.event_scratch0 choice 1 | `0x96AF 0x11 PRINT "THIS AIN'T NO PUBLIC PARK! BUY A DRINK...OR BLAST OUTTA HERE!"` |
| 0x96E0 | 0x96AB GOTO 0x96E0 | `0x96E0 0x33 PRINT RETURN` |
|  |  | `0x96E1 0x33 PRINT RETURN` |
|  |  | `0x96E2 0x11 PRINT 'DO YOU BUY A DRINK?'` |
| 0x972F | 0x9714 ON GOTO area1.event_word_26C choice 0 | `0x972F 0x12 PRINTCLEAR "A CLERK APPROACHES YOUR TABLE. 'HEARD ABOUT WHAT HAPPENED IN NEW LONDONORG?"` |
| 0x97CA | 0x9714 ON GOTO area1.event_word_26C choice 1 | `0x97CD 0x12 PRINTCLEAR "CARLTON TURABIAN WALKS UP. 'STEP IT UP, FOLKS! DON'T YOU HAVE BETTER THINGS TO DO?'"` |
| 0x9823 | 0x9714 ON GOTO area1.event_word_26C choice 2 | `0x9823 0x12 PRINTCLEAR "A NEO CAPTAIN BUYS A ROUND OF DRINKS. 'WE JUST SHOT UP A RAM CRUISER OFF AURORA!'"` |
| 0x9895 | 0x9714 ON GOTO area1.event_word_26C choice 3 | `0x9895 0x12 PRINTCLEAR 'AN UNKEMPT LOOKING ROCKET JOCK STEPS UP.'` |
| 0x9B01 | 0x9714 ON GOTO area1.event_word_26C choice 4 | `0x9B04 0x12 PRINTCLEAR 'YOU NOTICE CARLTON TURABIAN DRINKING IN A BACK BOOTH.'` |
| 0x9B5B | 0x9714 ON GOTO area1.event_word_26C choice 5 | `0x9B5B 0x12 PRINTCLEAR 'AN OLD WARRIOR EYES YOU WITH APPROVAL. HE DRAWS A FINE MONO SWORD.'` |
| 0x9C6C | 0x9714 ON GOTO area1.event_word_26C choice 6 | `0x9C6C 0x12 PRINTCLEAR "A MINER TELLS YOU ABOUT JUPITER, 'I'D LIKE TO GET INTO DIP MINING THE JUPITER ATMOSPHERE, BUT THOSE STORMRIDERS GOT IT ALL TIED UP!'"` |
| 0x9D42 | 0x9494 ON GOTO area2.event_scratch0 choice 3 | `0x9D42 0x12 PRINTCLEAR 'YOU LEAVE THE BAR.'` |

### ECL 19

Attached still-missing strings:
- 0x92D6: owner 0x91C7; `branch_target_region` `BLUFF`. incoming: 0x892A GOTO 0x91C7; 0x8A36 ON GOTO area1.word_14A choice 0; 0x8A8C ON GOTO area1.event_word_202 choice 1; 0x8AC9 ON GOTO area1.event_word_202 choice 2; 0x8AF1 ON GOTO area1.event_word_202 choice 1; 0x8BDD ON GOTO area1.event_word_202 choice 1; 0x8C0D ON GOTO area1.event_word_202 choice 1; 0x8C32 ON GOTO area1.event_word_202 choice 2; 0x8C55 ON GOTO area1.event_word_202 choice 1; 0x8C87 ON GOTO area1.event_word_202 choice 1; 0x8CB9 ON GOTO area1.event_word_202 choice 2; 0x8CDD ON GOTO area1.event_word_202 choice 1; 0x8CFE ON GOTO area1.event_word_202 choice 1; 0x8D28 ON GOTO area1.event_word_202 choice 1; 0x8D55 ON GOTO area1.event_word_202 choice 2; 0x8D79 ON GOTO area1.event_word_202 choice 1; 0x8D9A ON GOTO area1.event_word_202 choice 1; 0x8DBA ON GOTO area1.event_word_202 choice 1
- 0x9874: owner 0x97F3; `branch_target_region` `HULL:`. incoming: 0x924B GOSUB 0x97F3
- 0x9893: owner 0x97F3; `branch_target_region` `SENSORS:`. incoming: 0x924B GOSUB 0x97F3
- 0x98B4: owner 0x97F3; `branch_target_region` `CONTROLS:`. incoming: 0x924B GOSUB 0x97F3
- 0x98F7: owner 0x97F3; `branch_target_region` `ENGINES:`. incoming: 0x924B GOSUB 0x97F3

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8847 | 0x8816 GOTO 0x8847<br>0x8821 GOTO 0x8847<br>0x882C GOTO 0x8847<br>0x8838 GOTO 0x8847 | `0x8847 0x12 PRINTCLEAR "YOU CAN'T MOVE..."` |
| 0x8A7B |  | `0x8A7B 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'HIELO', 'EXIT'` |
| 0x8AA6 |  | `0x8AA6 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'NEW ELYSIUM', 'VENUS LOWLANDS', 'EXIT'` |
| 0x8ADB |  | `0x8ADB 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'NEW ELYSIUM', 'EXIT'` |
| 0x8AFD | 0x8A36 ON GOTO area1.word_14A choice 3 | `0x8B00 0x12 PRINTCLEAR 'MOVE INTO AN APPROACH PATTERN?'` |
| 0x8BCA |  | `0x8BCA 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'PAVONIS', 'EXIT'` |
| 0x8BFC |  | `0x8BFC 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'CERES', 'EXIT'` |
| 0x8C19 | 0x8BF8 GOTO 0x8C19 | `0x8C19 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'CERES', 'RAM BASE', 'EXIT'` |
| 0x8C44 |  | `0x8C44 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'VESTA', 'EXIT'` |
| 0x8C74 | 0x8C9A GOTO 0x8C74 | `0x8C74 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'FORTUNA', 'EXIT'` |
| 0x8C9E |  | `0x8C9E 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'FORTUNA', 'NEO BASE', 'EXIT'` |
| 0x8CCB |  | `0x8CCB 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'PALLAS', 'EXIT'` |
| 0x8CEC |  | `0x8CEC 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'PSYCHE', 'EXIT'` |
| 0x8D18 |  | `0x8D18 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'JUNO', 'EXIT'` |
| 0x8D37 |  | `0x8D37 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'JUNO', 'FUNGUS ASTEROID', 'EXIT'` |
| 0x8D67 |  | `0x8D67 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'HYGEIA', 'EXIT'` |
| 0x8D88 |  | `0x8D88 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'AURORA', 'EXIT'` |
| 0x8DA9 |  | `0x8DA9 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'THULE', 'EXIT'` |
| 0x91C7 | 0x892A GOTO 0x91C7<br>0x8A36 ON GOTO area1.word_14A choice 0<br>0x8A8C ON GOTO area1.event_word_202 choice 1<br>0x8AC9 ON GOTO area1.event_word_202 choice 2<br>0x8AF1 ON GOTO area1.event_word_202 choice 1<br>0x8BDD ON GOTO area1.event_word_202 choice 1<br>0x8C0D ON GOTO area1.event_word_202 choice 1<br>0x8C32 ON GOTO area1.event_word_202 choice 2<br>0x8C55 ON GOTO area1.event_word_202 choice 1<br>0x8C87 ON GOTO area1.event_word_202 choice 1<br>0x8CB9 ON GOTO area1.event_word_202 choice 2<br>0x8CDD ON GOTO area1.event_word_202 choice 1<br>0x8CFE ON GOTO area1.event_word_202 choice 1<br>0x8D28 ON GOTO area1.event_word_202 choice 1<br>0x8D55 ON GOTO area1.event_word_202 choice 2<br>0x8D79 ON GOTO area1.event_word_202 choice 1<br>0x8D9A ON GOTO area1.event_word_202 choice 1<br>0x8DBA ON GOTO area1.event_word_202 choice 1 | `0x91C7 0x12 PRINTCLEAR ''` |
|  |  | `0x9239 0x12 PRINTCLEAR 'SENSORS IDENTIFY A '` |
|  |  | `0x924F 0x11 PRINT ' ON LR SCANNER.'` |
| 0x95BC | 0x95A9 GOTO 0x95BC | `0x95BC 0x12 PRINTCLEAR 'DOCKING AT'` |
|  |  | `0x95C7 0x33 PRINT RETURN` |
|  |  | `0x95C8 0x11 PRINT 'SPACEPORT...'` |
| 0x9604 | 0x8E67 GOTO 0x9604<br>0x95A5 GOTO 0x9604<br>0x95B8 GOTO 0x9604 | `0x9604 0x12 PRINTCLEAR 'PORT AUTHORITY DENIES YOU DOCKING CLEARANCE.'` |
| 0x97C8 | 0x8E6B GOSUB 0x97C8<br>0x8E79 GOSUB 0x97C8 | `0x97C8 0x12 PRINTCLEAR 'SCANNING...'` |
| 0x97F3 | 0x924B GOSUB 0x97F3 | `0x97FA 0x11 PRINT 'RAM SCOUT'` |
|  |  | `0x980B 0x11 PRINT 'RAM MED.'` |
|  |  | `0x981B 0x11 PRINT 'RAM HVY.'` |
|  |  | `0x982B 0x11 PRINT 'PIR. MED.'` |
|  |  | `0x983C 0x11 PRINT 'MER. MED.'` |
|  |  | `0x9846 0x11 PRINT ' CRUISER '` |
| 0x9C16 | 0x8E96 GOSUB 0x9C16 | `0x9C25 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x9C4A 0x11 PRINT ' MAKES A PERFECT LANDING!'` |
| 0x9C62 | 0x9C46 GOTO 0x9C62 | `0x9C62 0x11 PRINT ' GIVES EVERYONE A ROUGH RIDE.'` |
| 0x9C95 | 0x9C30 GOTO 0x9C95 | `0x9C95 0x11 PRINT ' LOSES CONTROL OF THE SHIP.'` |
| 0x9E24 | 0x9C3B GOTO 0x9E24 | `0x9E24 0x11 PRINT ' SLIPS A LITTLE ON THE THROTTLE.'` |
| 0xA32C | 0x8E9A GOSUB 0xA32C<br>0x95F7 GOSUB 0xA32C | `0xA344 0x12 PRINTCLEAR 'STEFI STAYS IN THE SHIP WHILE YOU ADVENTURE.'` |
| 0xA36A | 0x8E58 GOSUB 0xA36A<br>0x8E92 GOSUB 0xA36A | `0xA36A 0x12 PRINTCLEAR 'HIGH WINDS AND LIGHTNING RAGE OVER THE PLANET.'` |

### ECL 20

Attached still-missing strings:
- 0x82FB: owner 0x829C; `branch_target_region` `DEPOSIT`. incoming: 0x80DF ON GOTO area1.event_word_202 choice 0; 0x81E6 ON GOTO area1.event_word_202 choice 0
- 0x833A: owner 0x829C; `branch_target_region` `WHICH ONE?`. incoming: 0x80DF ON GOTO area1.event_word_202 choice 0; 0x81E6 ON GOTO area1.event_word_202 choice 0
- 0x838C: owner 0x829C; `branch_target_region` `WHICH ONE?`. incoming: 0x80DF ON GOTO area1.event_word_202 choice 0; 0x81E6 ON GOTO area1.event_word_202 choice 0
- 0x9653: owner 0x9632; `branch_target_region` `HOW MUCH?`. incoming: 0x8088 GOSUB 0x9632; 0x93DE GOSUB 0x9632
- 0x98BE: owner 0x97EE; `branch_target_region` `EETBUGS B+G`. incoming: 0x865C GOSUB 0x97EE
- 0x9AE8: owner 0x97EE; `branch_target_region` `CONVINCE`. incoming: 0x865C GOSUB 0x97EE
- 0x9B07: owner 0x97EE; `branch_target_region` `WHO WILL TRY?`. incoming: 0x865C GOSUB 0x97EE
- 0x9B3C: owner 0x97EE; `branch_target_region` `WHO WILL TRY?`. incoming: 0x865C GOSUB 0x97EE

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x80A2 |  | `0x80A2 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'BANK', 'DOWNTOWN', 'HOSPITAL', 'PORT', 'TRAINING'` |
| 0x8162 |  | `0x8162 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'PORT'` |
| 0x8176 | 0x8111 GOTO 0x8176 | `0x8176 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'BAR', 'RESTAURANT', 'PORT'` |
| 0x819F | 0x811C GOTO 0x819F | `0x819F 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'HOSPITAL', 'SHOP', 'PORT'` |
| 0x81C6 | 0x8127 GOTO 0x81C6 | `0x81C6 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'BANK', 'DOWNTOWN', 'HOSPITAL', 'PORT'` |
| 0x81F8 | 0x8132 GOTO 0x81F8 | `0x81F8 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'BAR', 'PORT'` |
| 0x8214 | 0x813D GOTO 0x8214 | `0x8214 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'SHOP', 'PORT'` |
| 0x8230 | 0x8148 GOTO 0x8230 | `0x8230 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'SHOP', 'TRAINING', 'PORT'` |
| 0x8257 | 0x8153 GOTO 0x8257 | `0x8257 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'SHOP', 'PORT'` |
| 0x8273 | 0x815E GOTO 0x8273 | `0x8273 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'BAR', 'RESTAURANT', 'PORT'` |
| 0x829C | 0x80DF ON GOTO area1.event_word_202 choice 0<br>0x81E6 ON GOTO area1.event_word_202 choice 0 | `0x829C 0x12 PRINTCLEAR 'YOU ARE AT THE '` |
|  |  | `0x82B2 0x11 PRINT 'MAIN'` |
|  |  | `0x82BD 0x11 PRINT ' BRANCH OF THE BANK OF LUNA.'` |
|  |  | `0x82D5 0x33 PRINT RETURN` |
|  |  | `0x82D6 0x33 PRINT RETURN` |
|  |  | `0x82D7 0x11 PRINT 'CURRENT BALANCE: '` |
|  |  | `0x82E7 0x11 PRINT area1.event_word_3C4` |
|  |  | `0x82EB 0x11 PRINT ' CR'` |
|  |  | `0x82F1 0x33 PRINT RETURN` |
|  |  | `0x82F2 0x33 PRINT RETURN` |
| 0x8476 |  | `0x8476 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'BAR', 'LIBRARY', 'RESTAURANT', 'SHOP', 'EXIT'` |
| 0x84B2 | 0x80DF ON GOTO area1.event_word_202 choice 2<br>0x81B7 ON GOTO area1.event_word_202 choice 0<br>0x81E6 ON GOTO area1.event_word_202 choice 2 | `0x84B2 0x12 PRINTCLEAR 'YOU ARE IN THE '` |
|  |  | `0x84C5 0x11 PRINT ' HOSPITAL.'` |
|  |  | `0x84D0 0x33 PRINT RETURN` |
|  |  | `0x84D1 0x33 PRINT RETURN` |
| 0x8616 | 0x8190 ON GOTO area1.event_word_202 choice 0<br>0x8208 ON GOTO area1.event_word_202 choice 0<br>0x828D ON GOTO area1.event_word_202 choice 0<br>0x849D ON GOTO area1.event_word_202 choice 0 | `0x8629 0x12 PRINTCLEAR 'NO BARTENDER WILL LET YOU IN.'` |
| 0x869C | 0x8056 ON GOTO area1.event_word_252 choice 3<br>0x8ACF ON GOTO area1.event_word_250 choice 1 | `0x86A3 0x12 PRINTCLEAR 'YOU ARE REFUSED SERVICE.'` |
| 0x8B38 | 0x8AFE GOTO 0x8B38 | `0x8B63 0x12 PRINTCLEAR 'YOU HEAR A TECH SAY, '` |
|  |  | `0x8B7D 0x11 PRINT "'THAT HEAVY CRUISER JUST LEFT DOCK A FEW HOURS AGO. GLAD ITS IN THE AREA.'"` |
|  |  | `0x8BB9 0x11 PRINT "'THAT ASTEROID BASE SEEMS A REAL HOT SPOT BETWEEN RAM AND NEO. DO YOU THINK THEY'LL TRY TO REBUILD IT A THIRD TIME?'"` |
| 0x8C1E | 0x8B09 GOTO 0x8C1E | `0x8C40 0x12 PRINTCLEAR "'A SHIPMENT WENT TO TERRA,' SAYS A WOMAN SCARRED BY A LASER BURN. 'ALL HEAVY WEAPONS. FETCHED A PRETTY PRICE, THEY DID, AND IT LOOKS LIKE WE'LL GET RE-ORDERS.'"` |
| 0x8CCF | 0x8B14 GOTO 0x8CCF | `0x8CFC 0x12 PRINTCLEAR "A SECURITY OFFICER SAYS, 'THE MAN WAS HALF ROBOT, I TELL YOU. "` |
|  |  | `0x8D35 0x11 PRINT "HE WAS ON HIS WAY TO COPERNICUS, MUTTERING ABOUT A MATRIX ALMOST BEING COMPLETE.'"` |
|  |  | `0x8D76 0x11 PRINT "HE WAS NEARLY DEAD. HE SHOUTED THAT HE WOULD RETURN STRONGER THAN EVER.'"` |
| 0x8DC3 | 0x8CE1 GOTO 0x8DC3<br>0x8CEF GOTO 0x8DC3 | `0x8DE9 0x12 PRINTCLEAR "A SECURITY OFFICER SAYS, 'DOING A TOUR OF ALL THE MASS DRIVERS. THE BRASS IS WORRIED ABOUT A REVOLUTION ON TERRA.'"` |
| 0x8E47 | 0x8B1F GOTO 0x8E47 | `0x8E60 0x12 PRINTCLEAR "A TERRAN MENTIONS A MIRACLE DEVICE. 'A MATTER OF WEEKS, AND IT WILL BE DONE. EARTH WILL RISE AGAIN UNDER A GREAT VISIONARY.'"` |
| 0x8EDD | 0x8AF3 GOTO 0x8EDD | `0x8F0F 0x12 PRINTCLEAR 'MEN BEGIN TO GATHER AT A BACK TABLE, TRICKLING IN BY ONES AND TWOS.'` |
| 0x8F45 |  | `0x8F45 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'ATTACK', 'WAIT', 'LEAVE'` |
| 0x8FDD | 0x80DB GOTO 0x8FDD | `0x8FDD 0x12 PRINTCLEAR 'THE MEN HAVE FOLLOWED YOU.'` |
|  |  | `0x8FF4 0x33 PRINT RETURN` |
|  |  | `0x8FF5 0x33 PRINT RETURN` |
|  |  | `0x8FF6 0x33 PRINT RETURN` |
|  |  | `0x8FF7 0x33 PRINT RETURN` |
|  |  | `0x8FF8 0x11 PRINT 'THEY ATTACK!'` |
| 0x9240 | 0x938D GOTO 0x9240<br>0x9398 GOTO 0x9240 | `0x9240 0x12 PRINTCLEAR 'YOU SEARCH THE STACKS FOR ANY IMPORTANT INFORMATION.'` |
| 0x93AB | 0x81B7 ON GOTO area1.event_word_202 choice 1<br>0x8224 ON GOTO area1.event_word_202 choice 0<br>0x8248 ON GOTO area1.event_word_202 choice 0<br>0x8267 ON GOTO area1.event_word_202 choice 0<br>0x849D ON GOTO area1.event_word_202 choice 3 | `0x93DB 0x12 PRINTCLEAR ''` |
| 0x940E |  | `0x940E 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'SUPPLYCO', 'TITAN BLADES', 'EXIT'` |
| 0x943B | 0x93E9 GOTO 0x943B | `0x943B 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'HOT SPOT WEAPONS', 'QUIPMENTLAND', 'EXIT'` |
| 0x946E | 0x93F4 GOTO 0x946E | `0x946E 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: "APHRODITE'S", 'NEW E. SUPPLIES', 'EXIT'` |
| 0x94A1 | 0x93FF GOTO 0x94A1 | `0x94A1 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'HIGGERT METALS', 'TECH WEAPONS', 'EXIT'` |
| 0x94D3 | 0x940A GOTO 0x94D3 | `0x94D3 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: "GUNS R' US", 'USEM GRENADES', 'EXIT'` |
| 0x9632 | 0x8088 GOSUB 0x9632<br>0x93DE GOSUB 0x9632 | `0x9632 0x11 PRINT 'WHERE DO YOU WISH TO GO?'` |
| 0x9661 | 0x82B9 GOSUB 0x9661<br>0x84C1 GOSUB 0x9661 | `0x9668 0x11 PRINT 'MERCURY'` |
|  |  | `0x9678 0x11 PRINT 'VENUS'` |
|  |  | `0x9686 0x11 PRINT 'LUNA'` |
|  |  | `0x9693 0x11 PRINT 'MARS'` |
|  |  | `0x96A0 0x11 PRINT 'CERES'` |
|  |  | `0x96AE 0x11 PRINT 'FORTUNA'` |
| 0x96B8 | 0x8084 GOSUB 0x96B8<br>0x937E GOSUB 0x96B8 | `0x96B8 0x12 PRINTCLEAR 'YOU ARE AT THE '` |
|  |  | `0x96CE 0x11 PRINT 'HIELO ORBITAL SPACESTATION OVER MERCURY'` |
|  |  | `0x96F6 0x11 PRINT 'NEW ELYSIUM SPACEPORT ON VENUS'` |
|  |  | `0x9717 0x11 PRINT 'TYCHO SPACEPORT ON THE SURFACE OF LUNA'` |
|  |  | `0x973E 0x11 PRINT 'PAVONIS SPACEPORT OVER MARS'` |
|  |  | `0x975D 0x11 PRINT 'SPACEPORT AT '` |
|  |  | `0x976B 0x11 PRINT 'CERES'` |
|  |  | `0x9779 0x11 PRINT 'VESTA'` |
|  |  | `0x9787 0x11 PRINT 'FORTUNA'` |
|  |  | `0x9797 0x11 PRINT 'PALLAS'` |
|  |  | `0x97A6 0x11 PRINT 'PSYCHE'` |
|  |  | `0x97B5 0x11 PRINT 'JUNO'` |
| 0x97EE | 0x865C GOSUB 0x97EE | `0x97EE 0x12 PRINTCLEAR "YOU ARE IN '"` |
|  |  | `0x9801 0x11 PRINT 'THE BOLD ROCKET'` |
|  |  | `0x9817 0x11 PRINT 'THE ONE EYED GENNIE'` |
|  |  | `0x9830 0x11 PRINT "JIMBO'S ROCKET BAR"` |
|  |  | `0x9848 0x11 PRINT "BRETSKI'S"` |
|  |  | `0x9859 0x11 PRINT 'CLUB CERES'` |
|  |  | `0x986B 0x11 PRINT "RICK'S LOUNGE"` |
|  |  | `0x987F 0x11 PRINT "OID'S"` |
|  |  | `0x988D 0x11 PRINT 'THE QUEEN OF HEARTS'` |
|  |  | `0x989F 0x11 PRINT ".' "` |
|  |  | `0x98A5 0x33 PRINT RETURN` |
|  |  | `0x98A6 0x33 PRINT RETURN` |

### ECL 21 - GEO 21: 21

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8206 | entry vm_run_1 | `0x824D 0x12 PRINTCLEAR "THIS LEADS TO THE BOARDING TUBE TO YOUR SHIP. DO YOU CONTINUE?'"` |
| 0x834D | 0x8235 GOTO 0x834D<br>0x8249 GOTO 0x834D | `0x8355 0x12 PRINTCLEAR 'THIS DOOR IS SEALED SHUT.'` |
| 0x843D | 0x838C ON GOTO area2.event_scratch0 choice 2 | `0x843D 0x12 PRINTCLEAR 'YOU ARE AT A LADDER. WHERE DO YOU GO?'` |
| 0x8473 |  | `0x8473 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'UP', 'DOWN', 'STAY'` |
| 0x8496 | 0x8463 GOTO 0x8496 | `0x8496 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'UP', 'STAY'` |
| 0x84B1 | 0x846F GOTO 0x84B1 | `0x84B1 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'DOWN', 'STAY'` |
| 0x850F | 0x860F GOTO 0x850F | `0x850F 0x12 PRINTCLEAR 'THESE CONTROLS ARE DAMAGED.'` |
|  |  | `0x853D 0x12 PRINTCLEAR 'AN EXPERT PROGRAMMER MIGHT BE ABLE TO REROUTE CONTROL THROUGH HERE, BUT THE SYSTEM IS DEGRADING FAST. DO YOU TRY?'` |
| 0x888D | 0x838C ON GOTO area2.event_scratch0 choice 8 | `0x8895 0x12 PRINTCLEAR 'A SIGN ABOVE THE DOOR READS, '` |
|  |  | `0x88AE 0x33 PRINT RETURN` |
|  |  | `0x88AF 0x33 PRINT RETURN` |
|  |  | `0x88B0 0x11 PRINT "        'CAPTAIN'S QUARTERS'"` |
| 0x8BD6 | 0x89C8 ON GOTO area1.event_word_20E choice 2 | `0x8BF3 0x12 PRINTCLEAR "A MECHANICAL VOICE INTONES, 'CAPTAIN HAS ACTIVATED SELF-DESTRUCT FROM HIS CABIN. DETONATION IN 50.'"` |
| 0x8C42 | 0x89C8 ON GOTO area1.event_word_20E choice 3 | `0x8C59 0x12 PRINTCLEAR "A SPEAKER BLARES. 'IF INTRUDERS REACH PRISON LEVEL, KILL THE PRISONERS.'"` |
| 0x8C94 | 0x89C8 ON GOTO area1.event_word_20E choice 4 | `0x8CB6 0x12 PRINTCLEAR "SCOT CONTACTS YOU. 'ENEMY FORCES ARE TRYING TO FORCE THEIR WAY INTO THE SHIP. RETURN IMMEDIATELY!'"` |
| 0x8D05 | 0x8CB2 GOTO 0x8D05 | `0x8D05 0x12 PRINTCLEAR "YOUR SHIP'S ALARM INDICATES SOMEONE IS TRYING TO ENTER YOUR SHIP."` |
| 0x8D8D | 0x8D81 GOTO 0x8D8D | `0x8D8D 0x12 PRINTCLEAR area1.event_word_228` |
|  |  | `0x8D91 0x11 PRINT ' TO DETONATION.'` |
|  |  | `0x8DA9 0x11 PRINT ' THE SHIP EXPLODES AROUND YOU.'` |

### ECL 32

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8316 | 0x82E6 GOTO 0x8316 | `0x8316 0x12 PRINTCLEAR 'YOU LAND AT TOWER ISLE.'` |
| 0x839C | 0x82F2 ON GOTO area2.event_scratch0 choice 4 | `0x83D3 0x12 PRINTCLEAR 'YOU APPROACH '` |
|  |  | `0x83E0 0x11 PRINT '<string at scratch.word_0000>'` |
|  |  | `0x83E4 0x11 PRINT ' WITH THE PASSCARD BUCK ROGERS GAVE YOU. DO YOU ENTER?'` |
| 0x841C | 0x83CF GOTO 0x841C | `0x841C 0x12 PRINTCLEAR "YOU CAN GET RED CARRIN'S BOAT AT THE TOWER ISLE DOCK. DO YOU?"` |
| 0x84F5 | 0x834B GOTO 0x84F5<br>0x836B GOTO 0x84F5<br>0x837E GOTO 0x84F5<br>0x8398 GOTO 0x84F5<br>0x83C1 GOTO 0x84F5<br>0x849D GOTO 0x84F5<br>0x84AF GOTO 0x84F5<br>0x84C8 GOTO 0x84F5<br>0x84DF GOTO 0x84F5 | `0x84F5 0x12 PRINTCLEAR 'REGULATIONS DISALLOW YOUR ENTRANCE TO THE NEWPORG '` |
|  |  | `0x851E 0x11 PRINT '<string at scratch.word_0000>'` |
|  |  | `0x8522 0x11 PRINT ' WITHOUT POSSESSION OF THE PROPERLY AUTHORIZED PASSCARD.'` |
| 0x8550 | 0x8291 ON GOTO area2.event_scratch0 choice 0 | `0x855B 0x12 PRINTCLEAR 'YOU REACH YOUR BOAT. DO YOU USE IT?'` |
| 0x85B5 | 0x8557 GOTO 0x85B5 | `0x85B5 0x12 PRINTCLEAR 'YOU LAND AT SANTA CATALINA ISLAND. DO YOU RETURN TO YOUR BOAT?'` |
| 0x85F4 | 0x8291 ON GOTO area2.event_scratch0 choice 1 | `0x85F4 0x12 PRINTCLEAR 'A SECTION OF THE SPRAWL HAS BEEN WALLED OFF. FURTHER DOWN YOU SEE AN OPENING. DO YOU GO THROUGH IT?'` |
| 0x8648 | 0x8291 ON GOTO area2.event_scratch0 choice 2 | `0x865F 0x12 PRINTCLEAR 'AS YOU APPROACH THE BUILDING, A NEO AGENT BECKONS TO YOU FROM NEARBY. IT IS WILMA DEERING.'` |
| 0x89B4 | 0x8652 GOTO 0x89B4 | `0x89B4 0x12 PRINTCLEAR 'YOU ARE AT PURGE HEADQUARTERS.'` |
| 0x8A60 | 0x8291 ON GOTO area2.event_scratch0 choice 3 | `0x8A79 0x12 PRINTCLEAR "AS YOU APPROACH THE MESA, A BEEPING SOUND ISSUES FROM THE DEVICE YOU FOUND IN THE GANG'S QUARTER."` |
| 0x8B8C | 0x8A75 GOTO 0x8B8C | `0x8B8C 0x12 PRINTCLEAR 'DO YOU ENTER THE HISTORICAL MUSEUM?'` |
| 0x8BB0 | 0x8291 ON GOTO area2.event_scratch0 choice 4 | `0x8BB0 0x12 PRINTCLEAR "DUKE'S HILL SPACEPORT. YOUR SHIP IS HERE. DO YOU LEAVE EARTH?"` |
| 0x8BFF | 0x8291 ON GOTO area2.event_scratch0 choice 5 | `0x8C25 0x12 PRINTCLEAR 'A THIEF STEALS '` |
|  |  | `0x8C34 0x11 PRINT '<string at area2.selected_player_name>'` |
|  |  | `0x8C38 0x11 PRINT "'S WALLET! HE SPRINTS TOWARDS A TUNNEL DUG INTO SOME RUBBLE. DO YOU CHASE HIM?"` |
| 0x8CA4 | 0x8D10 GOTO 0x8CA4 | `0x8CA4 0x12 PRINTCLEAR "YOU FIND A SMALL BUILDING. THE SIGN OVER THE DOOR READS, 'KRUN -- HOME OF QUALITY ROCK 'N ROLL.' DO YOU ENTER?"` |
| 0x8D06 | 0x8CA0 GOTO 0x8D06 | `0x8D2B 0x12 PRINTCLEAR 'YOU APPROACH '` |
|  |  | `0x8D46 0x11 PRINT 'THE KRUN BUILDING. MAD DOG RUNS UP TO YOU.'` |
| 0x8F38 | 0x8D42 GOTO 0x8F38 | `0x8F38 0x11 PRINT 'A SMALL BUILDING. A DESERT RUNNER RUNS UP TO YOU.'` |
| 0x8FC8 | 0x8D1E GOTO 0x8FC8 | `0x8FC8 0x12 PRINTCLEAR "BAD DOG MEETS YOU. 'HEY, COOL, YOU'RE BACK! READY TO GO FIGHT THE BAD GUYS?'"` |
| 0x9047 | 0x8291 ON GOTO area2.event_scratch0 choice 7 | `0x905B 0x12 PRINTCLEAR 'SOME WARREN DWELLERS ARE GATHERED AROUND A LARGE SEWER DRAIN. DO YOU APPROACH THEM?'` |
| 0x92B4 | 0x91E6 GOTO 0x92B4 | `0x92CB 0x12 PRINTCLEAR 'CLIMBING OVER A SAND DUNE, YOU SEE A GROUP IN THE DISTANCE. RAM SOLDIERS GUARD A LINE OF DESERT RUNNERS IN CHAINS.'` |
| 0x94C6 | 0x91D0 GOTO 0x94C6 | `0x94DE 0x12 PRINTCLEAR 'A WARREN DWELLER CARRYING A RADIO PASSES YOU. YOU HEAR SOME OF THE BROADCAST.'` |
| 0x96CA | 0x826E GOSUB 0x96CA | `0x96DE 0x12 PRINTCLEAR 'A SMALL CROWD HAS GATHERED AROUND A GARISHLY PAINTED HAND CART. DO YOU INVESTIGATE?'` |
| 0x9B52 | 0x9B37 GOSUB 0x9B52 | `0x9B52 0x12 PRINTCLEAR 'YOU ENTER THE DESERT.'` |
| 0x9B66 | 0x9B42 GOSUB 0x9B66 | `0x9B66 0x12 PRINTCLEAR 'YOU WALK ALONG A MUDDY RIVER.'` |
| 0x9B80 | 0x9B4D GOSUB 0x9B80 | `0x9B80 0x12 PRINTCLEAR 'YOU WALK ON A RUINED FREEWAY.'` |
| 0x9B9A | 0x9B2C GOSUB 0x9B9A | `0x9B9A 0x12 PRINTCLEAR 'YOU ENTER THE POVERTY STRICKEN SPRAWL.'` |
| 0x9CA7 | 0x9C8B GOTO 0x9CA7 | `0x9CB2 0x12 PRINTCLEAR "YOU DON'T HAVE A BOAT!"` |
| 0x9CCA | 0x9C96 GOTO 0x9CCA | `0x9CCA 0x12 PRINTCLEAR 'YOU CROSS THE BAY ON A NEWPORG BRIDGE.'` |
| 0x9CEF | 0x9C80 GOTO 0x9CEF | `0x9D22 0x12 PRINTCLEAR 'YOU MAY ONLY DOCK AT TOWER ISLE IN THE FJORD.'` |
|  |  | `0x9D48 0x12 PRINTCLEAR 'THE ROUGH SURF MAKES IT IMPOSSIBLE TO LAND HERE.'` |

### ECL 33 - GEO 33: Losangelorg Sprawls

Attached still-missing strings:
- 0x8898: owner 0x87CD; `branch_target_region` `RESIDENTS`. incoming: 0x82CB ON GOTO area1.event_word_206 choice 6
- 0x8C7D: owner 0x8BFD; `branch_target_region` `HELP LEECHES`. incoming: 0x82CB ON GOTO area1.event_word_206 choice 10
- 0x96C8: owner 0x9657; `branch_target_region` `DECLINE`. incoming: 0x82CB ON GOTO area1.event_word_206 choice 14
- 0x983C: owner 0x97AA; `branch_target_region` `FIGHT MONKS`. incoming: 0x82CB ON GOTO area1.event_word_206 choice 16
- 0x9ADB: owner 0x9A0B; `branch_target_region` `CHEER`. incoming: 0x82CB ON GOTO area1.event_word_206 choice 17

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x81E4 | 0x81BE GOTO 0x81E4 | `0x81E4 0x12 PRINTCLEAR '<string at scratch.word_0000>'` |
|  |  | `0x81E8 0x11 PRINT 'UP'` |
|  |  | `0x81ED 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x820D | 0x81C9 GOTO 0x820D | `0x820D 0x12 PRINTCLEAR '<string at scratch.word_0000>'` |
|  |  | `0x8211 0x11 PRINT 'DOWN'` |
|  |  | `0x8217 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x8225 | 0x81D4 GOTO 0x8225 | `0x8225 0x12 PRINTCLEAR 'THE TUNNEL LEADS OUT INTO THE SPRAWLS. DO YOU LEAVE?'` |
| 0x825E | 0x81DF GOTO 0x825E | `0x826C 0x12 PRINTCLEAR 'A PASSAGE LEADS DOWN'` |
|  |  | `0x827E 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x829A | 0x818D GOTO 0x829A | `0x829A 0x12 PRINTCLEAR 'RUBBLE HAS JAMMED THE DOOR CLOSED.'` |
| 0x83F8 | 0x82CB ON GOTO area1.event_word_206 choice 1 | `0x8410 0x12 PRINTCLEAR 'A CROWDED MARKETPLACE. HAWKERS SHOUT THEIR WARES.'` |
| 0x8514 | 0x82CB ON GOTO area1.event_word_206 choice 2 | `0x8514 0x12 PRINTCLEAR 'A MAN WITH DISEASED SKIN'` |
| 0x8547 | 0x82CB ON GOTO area1.event_word_206 choice 3 | `0x8547 0x12 PRINTCLEAR 'A LITTLE GIRL, GRIME SMEARED ACROSS HER FACE,'` |
| 0x857F | 0x82CB ON GOTO area1.event_word_206 choice 4 | `0x857F 0x12 PRINTCLEAR 'A YOUNG WOMAN, PRETTY EXCEPT FOR HER BLACKENED TEETH'` |
| 0x85BE | 0x8543 GOTO 0x85BE<br>0x857B GOTO 0x85BE | `0x85BE 0x11 PRINT ' OFFERS TO SELL YOU A '` |
|  |  | `0x85D2 0x11 PRINT '<string at scratch.word_0208>'` |
|  |  | `0x85D6 0x11 PRINT '. DO YOU BUY IT?'` |
| 0x86AC | 0x82CB ON GOTO area1.event_word_206 choice 5 | `0x86BA 0x12 PRINTCLEAR 'A GYMNASIUM, BASKETBALL HOOPS BENT AWRY, CEILING CAVED IN, BLEACHERS CANNIBALIZED FOR KINDLING. SCORES OF PEOPLE EYE YOU. DO YOU ASK ABOUT CHADE?'` |
| 0x87CD | 0x82CB ON GOTO area1.event_word_206 choice 6 | `0x87D5 0x12 PRINTCLEAR 'A LOCKER ROOM MADE INTO A KITCHEN.'` |
| 0x8B5A | 0x8268 GOTO 0x8B5A | `0x8B6D 0x12 PRINTCLEAR 'THE DOOR IS ALL BUT SEAMLESS.'` |
| 0x9126 | 0x9251 GOTO 0x9126 | `0x9126 0x33 PRINT RETURN` |
|  |  | `0x9127 0x11 PRINT 'LOA-LOA RETURNS TO HER COUNCIL.'` |
| 0x91F1 | 0x925F GOTO 0x91F1<br>0x926D GOTO 0x91F1 | `0x9204 0x12 PRINTCLEAR 'NOBODY IS HERE.'` |
| 0x9214 | 0x9200 GOTO 0x9214 | `0x921E 0x11 PRINT "'WE NEED TO FIND GARGOYLE. I HAVE MY GANG LOOKING FOR HIM, TOO.'"` |
| 0x92B7 | 0x8DC4 GOTO 0x92B7 | `0x92C6 0x11 PRINT "'WELL, WELL, GARGOYLE. TIME TO TALK.' SHE TAKES HIM IN THE OTHER ROOM. MUFFLED SCREAMS COME FROM THE ROOM, AND THEN SILENCE."` |
| 0x93C6 | 0x82CB ON GOTO area1.event_word_206 choice 12 | `0x940F 0x12 PRINTCLEAR 'THE ROOM SHOWS SIGNS OF RECENT USE.'` |
| 0x9626 | 0x82CB ON GOTO area1.event_word_206 choice 13 | `0x9631 0x12 PRINTCLEAR 'A LEECH WOMAN TATTOOS HER KIDS.'` |
| 0x973A | 0x82CB ON GOTO area1.event_word_206 choice 15 | `0x976C 0x12 PRINTCLEAR 'DEAD LEECHES LITTER THE SHADOWS. YOU HEAR THE SOUNDS OF BATTLE TO THE WEST.'` |
| 0x9DE3 | 0x82CB ON GOTO area1.event_word_206 choice 18 | `0x9DFF 0x12 PRINTCLEAR "A MAN WHISPERS FROM THE SHADOWS. 'DON'T LOOK, JUST LISTEN. ISHA WISHES TO SPEAK TO YOU. THE GANGS HATE HER, SO SHE MUST HIDE. SHE SEEKS SOCIAL REFORM.'"` |

### ECL 34 - GEO 34: Historical Museum, Levels 2-1

Attached still-missing strings:
- 0x9726: owner 0x9642; `branch_target_region` `LOOK FOR HIS NOTES`. incoming: 0x9605 GOTO 0x9642

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x80E9 | entry vm_run_1 | `0x8105 0x12 PRINTCLEAR ''` |
| 0x813F | 0x810F GOTO 0x813F | `0x8145 0x12 PRINTCLEAR 'DO YOU WANT TO LEAVE THE MUSEUM?'` |
| 0x833D | 0x812A GOTO 0x833D<br>0x9B47 GOTO 0x833D | `0x834B 0x11 PRINT 'DO YOU GO THROUGH THE DOOR?'` |
| 0x8372 | 0x813A GOTO 0x8372 | `0x8388 0x12 PRINTCLEAR 'DO YOU WANT TO REMOVE THE BARRICADE?'` |
| 0x84D8 | 0x849B GOTO 0x84D8 | `0x84DE 0x12 PRINTCLEAR 'YOU ELUDE THE SECURITY BOT.'` |
| 0x860E | 0x85FF ON GOTO area1.event_word_20E choice 0 | `0x8670 0x12 PRINTCLEAR "YOU SEE A WOMAN DOWN THE HALL. CHADE STOPS ABRUPTLY. 'FATHER,' SHE SAYS. 'DO YOU KNOW WHO THESE PEOPLE ARE?'"` |
| 0x8714 | 0x8647 GOTO 0x8714 | `0x871D 0x12 PRINTCLEAR 'YOU SEE THE SWIRL OF SKIRTS AS A WOMAN DUCKS DOWN THE HALL.'` |
| 0x8751 | 0x8655 GOTO 0x8751 | `0x8768 0x12 PRINTCLEAR "A WOMAN STANDS JUST OUT OF RANGE DOWN THE HALL. 'WHO ARE YOU?' SHE CALLS. WHAT DO YOU TELL HER?"` |
| 0x87B3 |  | `0x87B3 0x2B HORIZONTAL MENU area1.event_word_20A = <selected index from menu> MENU: 'TRUTH', 'LIE', 'NOTHING'` |
| 0x87DB | 0x87CC ON GOTO area1.event_word_20A choice 0 | `0x87DB 0x12 PRINTCLEAR "'I'M SORRY YOU'VE COME ALL THIS WAY FOR NOTHING, BUT CHADE'S DEAD. CAUGHT A FEVER IN THE SPRAWLS AND NEVER RECOVERED.'"` |
| 0x883B | 0x87CC ON GOTO area1.event_word_20A choice 1 | `0x883B 0x12 PRINTCLEAR "'BUT YOU LOOK SO LIKE THE MERCENARIES I SEE HERE AND THERE. PERHAPS YOU'RE JUST LOST. THE EXIT IS TO THE SOUTH.'"` |
| 0x8892 | 0x87CC ON GOTO area1.event_word_20A choice 2<br>0x8837 GOTO 0x8892 | `0x8892 0x11 PRINT ' SHE RACES OFF DOWN THE HALL.'` |
| 0x88B3 | 0x85FF ON GOTO area1.event_word_20E choice 1 | `0x88DF 0x12 PRINTCLEAR "CHADE TUGS AT YOU. 'THE NORTHWEST. I'M SURE SHE'S THERE.'"` |
| 0x890F | 0x88DB GOTO 0x890F | `0x890F 0x12 PRINTCLEAR "'YOU CAN GO YOUR WAY,' SAYS CHADE. 'BUT I'M GOING AFTER STEFI.' HE RUNS OFF."` |
| 0x8950 | 0x88BA GOTO 0x8950<br>0x88C5 GOTO 0x8950 | `0x896F 0x12 PRINTCLEAR "'THE DOOR TO THE NORTH. HURRY!'"` |
| 0x898C | 0x85FF ON GOTO area1.event_word_20E choice 2 | `0x89CD 0x11 PRINT ' NOTICES MORE TRACKS.'` |
| 0x89E4 | 0x89B5 GOTO 0x89E4 | `0x89F8 0x11 PRINT ' NOTICES THE TRACKS OF MANY PEOPLE IN THE DUST.'` |
| 0x8A1F | 0x89E0 GOTO 0x8A1F | `0x8A1F 0x11 PRINT ' THEY LEAD TO THE '` |
|  |  | `0x8A37 0x11 PRINT 'NORTH.'` |
|  |  | `0x8A40 0x11 PRINT 'WEST.'` |
| 0x8C53 | 0x83FD ON GOTO area1.event_word_204 choice 6 | `0x8C53 0x12 PRINTCLEAR 'A DONATION BOX STANDS NEXT TO THE ENTRANCE, LONG SINCE BROKEN INTO.'` |
| 0x8C8B | 0x83FD ON GOTO area1.event_word_204 choice 7 | `0x8CA2 0x12 PRINTCLEAR 'A BROOM CLOSET.'` |
|  |  | `0x8CB1 0x33 PRINT RETURN` |
|  |  | `0x8CB2 0x11 PRINT 'AN OLD MAN, DOUBTLESS PROFESSOR CHADE, SLEEPS ON A CARDBOARD BOX.'` |
| 0x8CE6 | 0x8F0D GOTO 0x8CE6 | `0x8CE6 0x33 PRINT RETURN` |
|  |  | `0x8CE7 0x33 PRINT RETURN` |
|  |  | `0x8CE8 0x11 PRINT 'DO YOU WAKE HIM?'` |
| 0x8EE2 | 0x8C95 GOTO 0x8EE2 | `0x8EF8 0x12 PRINTCLEAR 'CHADE STILL SLEEPS HERE.'` |
| 0x8F11 | 0x83FD ON GOTO area1.event_word_204 choice 8 | `0x8F19 0x12 PRINTCLEAR 'A DISPLAY OF FLORA AND FAUNA THAT WENT EXTINCT DURING THE 21ST CENTURY.'` |
| 0x8F53 | 0x83FD ON GOTO area1.event_word_204 choice 9 | `0x8F57 0x11 PRINT 'CALIFORNIA CONDOR.'` |
| 0x8F69 | 0x83FD ON GOTO area1.event_word_204 choice 10 | `0x8F6D 0x11 PRINT 'BLACK RHINO.'` |
| 0x8F7A | 0x83FD ON GOTO area1.event_word_204 choice 11 | `0x8F7E 0x11 PRINT 'POODLE.'` |
| 0x8F88 | 0x83FD ON GOTO area1.event_word_204 choice 12 | `0x8F8C 0x11 PRINT 'MOCKINGBIRD.'` |
| 0x8F99 | 0x83FD ON GOTO area1.event_word_204 choice 13 | `0x8F9D 0x11 PRINT 'GORILLA.'` |
| 0x8FA7 | 0x83FD ON GOTO area1.event_word_204 choice 14 | `0x8FAF 0x12 PRINTCLEAR 'THIS ROOM IS A SATURN 1ST-STAGE BOOSTER. ITS CONTENTS DEPICT THE SPACE PROGRAM.'` |
| 0x8FEF | 0x83FD ON GOTO area1.event_word_204 choice 15 | `0x8FF3 0x11 PRINT 'SPACESUIT WORN BY ARMSTRONG.'` |
| 0x900C | 0x83FD ON GOTO area1.event_word_204 choice 16 | `0x9010 0x11 PRINT 'HELMET WORN BY COSMONAUT YURI GAGARIN.'` |
| 0x9031 | 0x83FD ON GOTO area1.event_word_204 choice 17 | `0x9035 0x11 PRINT 'WARPED MIRROR OF THE HUBBLE TELESCOPE.'` |
| 0x9056 | 0x83FD ON GOTO area1.event_word_204 choice 18 | `0x905A 0x11 PRINT 'MODEL ICBM.'` |
| 0x9067 | 0x83FD ON GOTO area1.event_word_204 choice 19 | `0x906F 0x12 PRINTCLEAR 'THE HISTORY OF WAR IS DEPICTED IN THIS ROOM.'` |
| 0x9094 | 0x83FD ON GOTO area1.event_word_204 choice 20 | `0x9094 0x12 PRINTCLEAR "A MODEL OF MASTERLINK IS MOUNTED ON THE WALL, AND BELOW IT, AN EPITAPH TO LT. COL. ANTHONY 'BUCK' ROGERS, WHO DIED ON HIS MISSION TO DESTROY THE WEAPON."` |
| 0x910B | 0x83FD ON GOTO area1.event_word_204 choice 22 | `0x910B 0x12 PRINTCLEAR "A HUGE SPHEROID WITH FINS BEARING THE INSCRIPTION 'FAT BOY' - MASS DESTRUCTION PROVES TO BE AN ALMOST VIABLE DETERRENT."` |
| 0x9169 | 0x83FD ON GOTO area1.event_word_204 choice 23 | `0x9169 0x12 PRINTCLEAR 'A BUST OF NAPOLEON - KILLING EN MASSE BECOMES ALL THE RAGE.'` |
| 0x919A | 0x83FD ON GOTO area1.event_word_204 choice 24 | `0x91A2 0x12 PRINTCLEAR 'THIS ROOM IS DEDICATED TO THE RISE OF MODERN CIVILIZATION.'` |
| 0x91D2 | 0x83FD ON GOTO area1.event_word_204 choice 25 | `0x91D6 0x11 PRINT 'STEAM POWERED LOOM, HERALDING THE BIRTH OF THE WORK FORCE.'` |
| 0x9206 | 0x83FD ON GOTO area1.event_word_204 choice 26 | `0x9206 0x12 PRINTCLEAR "MONEY OF ALL KINDS, FROM DOUBLOONS TO CREDIT CARDS, ARE IN A CASE. THE CAPTION READS, 'THE JONESES MOVE IN.'"` |
| 0x925B | 0x83FD ON GOTO area1.event_word_204 choice 27 | `0x925F 0x11 PRINT 'PRINTING PRESS, ENABLING THE STANDARDIZATION OF KNOWLEDGE AND FREING HUMANITY FROM THE NEED TO REMEMBER.'` |
| 0x92B1 | 0x83FD ON GOTO area1.event_word_204 choice 28 | `0x92B9 0x12 PRINTCLEAR 'A MOVIE THEATER.'` |
|  |  | `0x92C8 0x33 PRINT RETURN` |
|  |  | `0x92C9 0x33 PRINT RETURN` |
|  |  | `0x92CA 0x11 PRINT 'YOUR BOOTS STICK TO THE FLOOR.'` |
| 0x94A4 | 0x83FD ON GOTO area1.event_word_204 choice 29 | `0x94AC 0x12 PRINTCLEAR 'A LARGE DNA HELIX MODELED WITH STICKS AND COLORED BALLS. '` |
|  |  | `0x94F7 0x33 PRINT RETURN` |
|  |  | `0x94F8 0x33 PRINT RETURN` |
| 0x953A | 0x94E4 GOTO 0x953A | `0x9564 0x11 PRINT "CHADE BLUNDERS ABOUT THE ROOM. 'I COULD'VE SWORN MY NOTES WERE IN HERE. MAYBE THEY'RE IN THE COMPUTER ROOM TO THE SOUTHWEST.'"` |
| 0x95C7 | 0x83FD ON GOTO area1.event_word_204 choice 30 | `0x95D7 0x12 PRINTCLEAR 'A HUGE COMPUTER CALLED ENIAC FILLS THE ROOM.'` |
|  |  | `0x9612 0x11 PRINT ' A MICROCHIP A BILLION TIMES MORE POWERFUL SITS ON A TABLE.'` |
| 0x9642 | 0x9605 GOTO 0x9642 | `0x966D 0x12 PRINTCLEAR "CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'"` |
| 0x9851 | 0x83FD ON GOTO area1.event_word_204 choice 31<br>0x8EEC GOTO 0x9851 | `0x9859 0x12 PRINTCLEAR 'A BROOM CLOSET.'` |
| 0x9AB4 | 0x9889 GOTO 0x9AB4 | `0x9AB4 0x12 PRINTCLEAR 'THE WARRIORS ARE QUESTIONING STEFI MERCILESSLY. '` |
| 0x9AFB | 0x83FD ON GOTO area1.event_word_204 choice 33 | `0x9B1A 0x12 PRINTCLEAR 'THE SECRET DOOR THAT CHADE TOLD YOU ABOUT STANDS AJAR. '` |
| 0x9EB6 | 0x83FD ON GOTO area1.event_word_204 choice 36 | `0x9EB6 0x12 PRINTCLEAR 'A GIFT SHOP.'` |
|  |  | `0x9ED6 0x11 PRINT ' MAGAZINES, T-SHIRTS AND CURIOS LAY ABOUT THE ROOM, BROKEN AND SHREDDED.'` |
| 0x9F55 | 0x83FD ON GOTO area1.event_word_204 choice 37 | `0x9F55 0x12 PRINTCLEAR 'EXPLOSIVES OF ALL KINDS, ALL THE BETTER TO KILL YOU WITH.'` |
| 0xA15E | 0x8F53 GOSUB 0xA15E<br>0x8F69 GOSUB 0xA15E<br>0x8F7A GOSUB 0xA15E<br>0x8F88 GOSUB 0xA15E<br>0x8F99 GOSUB 0xA15E<br>0x9056 GOSUB 0xA15E<br>0x91D2 GOSUB 0xA15E | `0xA15E 0x12 PRINTCLEAR 'AN EXHIBIT OF A '` |
| 0xA16E | 0x8FEF GOSUB 0xA16E<br>0x900C GOSUB 0xA16E<br>0x9031 GOSUB 0xA16E<br>0x925B GOSUB 0xA16E | `0xA16E 0x12 PRINTCLEAR 'A DISPLAY FEATURING THE '` |
| 0xA184 | 0x89C4 GOSUB 0xA184<br>0x89EF GOSUB 0xA184 | `0xA1A8 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |

### ECL 35 - GEO 35: Asteroid Base

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8146 | 0x8122 ON GOTO area2.event_scratch0 choice 1 | `0x815F 0x12 PRINTCLEAR 'THE REPAIR CREW IS STILL INSPECTING THE SHIP. YOU CANNOT LAUNCH UNTIL THEY FINISH.'` |
| 0x81A2 | 0x815B GOTO 0x81A2 | `0x81A2 0x12 PRINTCLEAR 'ONLY YOUR SHIP REMAINS. DO YOU LEAVE?'` |
| 0x81CD | 0x8122 ON GOTO area2.event_scratch0 choice 2 | `0x81E9 0x12 PRINTCLEAR 'YOU SEARCH THE EMPTY LAUNCH BAY. SUAREZ IS GONE.'` |
| 0x8212 | 0x81E5 GOTO 0x8212 | `0x8218 0x12 PRINTCLEAR 'THE CREW IN LAUNCH BAY 2 IS '` |
|  |  | `0x823A 0x11 PRINT 'WAITING EXPECTANTLY FOR SOMEONE.'` |
|  |  | `0x8256 0x11 PRINT 'RE-FUELING A LARGE ROCKETSHIP.'` |
| 0x82A2 | 0x8122 ON GOTO area2.event_scratch0 choice 6 | `0x82BA 0x12 PRINTCLEAR 'THE DOOR REQUIRES AN ACCESS CARD YOU DO NOT HAVE.'` |
|  |  | `0x82EA 0x12 PRINTCLEAR 'THE SECURITY CARD OPENS THE DOOR.'` |
| 0x8368 | 0x8122 ON GOTO area2.event_scratch0 choice 9 | `0x8370 0x12 PRINTCLEAR 'THE DOOR IS LOCKED, BUT THERE IS A KEYPAD.'` |
| 0x8393 |  | `0x8393 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ENTER CODE'` |
|  |  | `0x83BE 0x12 PRINTCLEAR 'YOU INPUT THE CODE AND THE DOOR OPENS.'` |
|  |  | `0x83E0 0x12 PRINTCLEAR 'YOU TRY A RANDOM CODE. THE DOOR REMAINS SHUT.'` |
| 0x840D | 0x810D GOTO 0x840D | `0x840D 0x12 PRINTCLEAR 'A HUGE EXPLOSION ROCKS THE BASE! THE DEMOLITION CHARGES HAVE DETONATED!'` |
| 0x8543 | 0x848F ON GOTO area2.event_scratch0 choice 1 | `0x8543 0x12 PRINTCLEAR 'YOU ARE IN THE AIRLOCK BETWEEN LAUNCH BAY '` |
|  |  | `0x856D 0x11 PRINT '1'` |
|  |  | `0x8572 0x11 PRINT '2'` |
|  |  | `0x8576 0x11 PRINT ' AND CERES BASE.'` |
| 0x8586 | 0x848F ON GOTO area2.event_scratch0 choice 3 | `0x858D 0x12 PRINTCLEAR "THIS DOOR READS 'SECURITY STATION.'"` |
| 0x85AC | 0x848F ON GOTO area2.event_scratch0 choice 5 | `0x85D4 0x12 PRINTCLEAR "GUARDS STOP YOU. 'THE COMMAND CENTER IS OFF LIMITS.'"` |
| 0x85FE |  | `0x85FE 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK'` |
| 0x862B | 0x848F ON GOTO area2.event_scratch0 choice 7 | `0x8633 0x12 PRINTCLEAR "'ARMORY.'"` |
| 0x863E | 0x848F ON GOTO area2.event_scratch0 choice 8 | `0x8646 0x12 PRINTCLEAR "A NAME PLATE ON THIS DOOR READS, 'GEN. MAVROUDIS, BASE COMMANDER.'"` |
| 0x867C | 0x848F ON GOTO area2.event_scratch0 choice 9 | `0x8684 0x12 PRINTCLEAR "THIS DOOR IS MARKED 'LASER CONTROL.'"` |
| 0x86A3 | 0x848F ON GOTO area2.event_scratch0 choice 10 | `0x86A3 0x12 PRINTCLEAR 'VARIOUS MAINTAINENCE ITEMS ARE STORED HERE.'` |
| 0x86C8 | 0x848F ON GOTO area2.event_scratch0 choice 11 | `0x86D0 0x12 PRINTCLEAR "'GUARD QUARTERS.'"` |
| 0x86E1 | 0x848F ON GOTO area2.event_scratch0 choice 12 | `0x86FE 0x12 PRINTCLEAR 'YOU ENTER THE COMMAND CENTER.'` |
|  |  | `0x872D 0x11 PRINT " TECHNICIANS CONCENTRATE ON VARIOUS MONITORS. AN IMPOSING FIGURE DOMINATES THE ROOM. HIS NAME TAG READS 'MAVROUDIS.'"` |
| 0x8917 | 0x848F ON GOTO area2.event_scratch0 choice 13 | `0x891F 0x12 PRINTCLEAR "A SIGN ON THE WEST DOOR READS, 'CONFERENCE ROOM.' STENCILED ON THE EAST DOOR IS 'MESS HALL.'"` |
| 0x8968 | 0x848F ON GOTO area2.event_scratch0 choice 14 | `0x8970 0x12 PRINTCLEAR 'THE MESS HALL IS '` |
|  |  | `0x898A 0x11 PRINT 'EMPTY.'` |
|  |  | `0x8994 0x11 PRINT 'NEARLY EMPTY, EXCEPT FOR A LONE GUARD RELAXING. DO YOU ATTACK?'` |
| 0x89E9 | 0x848F ON GOTO area2.event_scratch0 choice 15 | `0x89F1 0x12 PRINTCLEAR 'THIS IS A ILL-EQUIPPED KITCHEN. PROCESSED FOOD SUPPLIES LINE THE WALLS.'` |
| 0x8A2B | 0x848F ON GOTO area2.event_scratch0 choice 16 | `0x8A33 0x12 PRINTCLEAR 'YOU ENTER THE SECURITY AREA'` |
|  |  | `0x8A55 0x11 PRINT '.'` |
|  |  | `0x8A6F 0x11 PRINT '. THE GUARDS APPEAR TO BE WAITING FOR YOU. THEY ATTACK!'` |
| 0x8C29 | 0x848F ON GOTO area2.event_scratch0 choice 17 | `0x8C29 0x12 PRINTCLEAR 'THIS DOOR IS STENCILED '` |
|  |  | `0x8C45 0x11 PRINT "'WOMAN"` |
|  |  | `0x8C4E 0x11 PRINT "'MEN"` |
|  |  | `0x8C54 0x11 PRINT "'S LAVATORY.'"` |
| 0x8C62 | 0x848F ON GOTO area2.event_scratch0 choice 19 | `0x8C6A 0x12 PRINTCLEAR "'CONFERENCE ROOM.'"` |
| 0x8C7C | 0x848F ON GOTO area2.event_scratch0 choice 20 | `0x8C87 0x12 PRINTCLEAR 'THE ARMORY IS POORLY STOCKED. ONLY A FEW RIFLES ARE HERE.'` |
| 0x8D1B | 0x848F ON GOTO area2.event_scratch0 choice 21 | `0x8D23 0x12 PRINTCLEAR "THIS IS THE BASE'S POWER CENTER. HUGE CABLES SNAKE IN AND OUT OF THIS ROOM."` |
| 0x8D60 | 0x848F ON GOTO area2.event_scratch0 choice 22 | `0x8D68 0x12 PRINTCLEAR "'RESTRICTED ACCESS' IS PRINTED ON THE DOOR. YOU HEAR A STEADY HUM."` |
| 0x8D9E | 0x848F ON GOTO area2.event_scratch0 choice 23 | `0x8DA6 0x12 PRINTCLEAR 'THE LARGE CONFERENCE ROOM IS EMPTY, BUT RECENTLY USED.'` |
|  |  | `0x8E04 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x8E08 0x11 PRINT " NOTICES A FALLEN NOTE. IT READS, 'KANE IS READY TO DEAL. ENVOY WILL ARRIVE WITHIN THE HOUR.'"` |
| 0x8E52 | 0x848F ON GOTO area2.event_scratch0 choice 24 | `0x8E5A 0x12 PRINTCLEAR "MAVROUDIS' OFFICE IS IMMACULATE, AND SMELLS STRONGLY OF LEATHER. AGAINST THE EAST WALL IS A COMPUTER."` |
| 0x8EB5 | 0x8ECE GOTO 0x8EB5 | `0x8EB5 0x39 WHO <select player> 'WHO WILL REPROGRAM?'` |
|  |  | `0x8EE1 0x12 PRINTCLEAR 'THE SECURITY PROGRAM HAS BEEN TRIPPED. THE COMPUTER HAS LOCKED ITS FILES, AND THE BASE ALERT HAS BEEN SOUNDED.'` |
| 0x8F4A | 0x8EDD GOTO 0x8F4A | `0x8F58 0x12 PRINTCLEAR 'YOU HAVE LOGGED ON, AND ARE FACING AN ACCESS PROMPT.'` |
| 0x8F8C | 0x8F54 GOTO 0x8F8C | `0x8F8C 0x12 PRINTCLEAR 'WHAT INFORMATION DO YOU ATTEMPT TO ACCESS?'` |
| 0x8FBD |  | `0x8FBD 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'QUIT', 'MAVROUDIS', 'DOOMSDAY LASER'` |
| 0x8FED | 0x8FB9 GOTO 0x8FED | `0x8FED 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'QUIT', 'MAVORUDIS', 'DOOMSDAY LASER', 'KANE'` |
| 0x9025 | 0x8FDE ON GOTO area2.event_scratch0 choice 0<br>0x9013 ON GOTO area2.event_scratch0 choice 0 | `0x9025 0x12 PRINTCLEAR 'YOU LOG OUT.'` |
| 0x903B | 0x8FDE ON GOTO area2.event_scratch0 choice 1<br>0x9013 ON GOTO area2.event_scratch0 choice 1 | `0x903B 0x12 PRINTCLEAR 'GENERAL JERIMIAH MAVROUDIS:'` |
|  |  | `0x9053 0x33 PRINT RETURN` |
|  |  | `0x9054 0x11 PRINT 'PROMOTED FROM MARS SECURITY TO CERES BASE. CURRENTLY REINITIATING DOOMSDAY PROJECT.'` |
| 0x909B | 0x8FDE ON GOTO area2.event_scratch0 choice 2<br>0x9013 ON GOTO area2.event_scratch0 choice 2 | `0x909B 0x12 PRINTCLEAR 'MSG. TO GEN. MAVROUDIS:'` |
|  |  | `0x90B0 0x33 PRINT RETURN` |
|  |  | `0x90B1 0x11 PRINT 'FOR YOUR EYES ONLY:'` |
|  |  | `0x90C3 0x33 PRINT RETURN` |
|  |  | `0x90C4 0x11 PRINT 'COMMENCE REBUILDING OF DOOMSDAY LASER. ADDITIONAL POWER CRYSTALS ARRIVING SOON.'` |
|  |  | `0x9103 0x33 PRINT RETURN` |
|  |  | `0x9104 0x11 PRINT 'HOLZERHEIN.'` |
| 0x9115 | 0x9013 ON GOTO area2.event_scratch0 choice 3 | `0x9115 0x12 PRINTCLEAR 'MSG. TO GEN. MAVROUDIS:'` |
|  |  | `0x912A 0x33 PRINT RETURN` |
|  |  | `0x912B 0x11 PRINT 'I HAVE THE CRYSTALS YOU NEED. I EXPECT TO BE PAID WELL FOR MY CONTRIBUTION.'` |
|  |  | `0x9167 0x33 PRINT RETURN` |
|  |  | `0x9168 0x11 PRINT 'KANE.'` |
| 0x9174 | 0x848F ON GOTO area2.event_scratch0 choice 26 | `0x917C 0x12 PRINTCLEAR "THE GENERAL'S LIVING QUARTERS ARE SPARSELY FURNISHED."` |
| 0x91A8 | 0x848F ON GOTO area2.event_scratch0 choice 27 | `0x91A8 0x12 PRINTCLEAR 'THE HUM OF MACHINERY FILLS THE ROOM. LARGE CONSOLES LINE THE WALLS.'` |
| 0x91DF | 0x848F ON GOTO area2.event_scratch0 choice 28 | `0x91E7 0x12 PRINTCLEAR 'THIS ROOM APPEARS TO BE A DEDICATED COMMUNICATIONS AREA.'` |
| 0x9282 | 0x922D GOTO 0x9282 | `0x9286 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x928A 0x11 PRINT ' NOTICES A RAM HEAVY CRUISER ORBITING THE BASE.'` |
| 0x92B2 | 0x921F GOTO 0x92B2 | `0x92B2 0x12 PRINTCLEAR 'THE SENSORS NOW SHOW DEBRIS. THE RAM HEAVY CRUISER HAS BEEN DESTROYED.'` |
| 0x92EB | 0x848F ON GOTO area2.event_scratch0 choice 30 | `0x92F3 0x12 PRINTCLEAR 'THIS CONFERENCE ROOM IS DOMINATED BY RAM INSIGNIAS BOTH ON THE WALLS AND CARVED INTO THE TABLE.'` |
| 0x933F | 0x848F ON GOTO area2.event_scratch0 choice 31 | `0x9347 0x12 PRINTCLEAR 'THIS ROOM HOLDS BRAND NEW EQUIPMENT. A MASTER CONTROL CONSOLE IS ON THE EAST WALL.'` |
|  |  | `0x9394 0x12 PRINTCLEAR 'MAVROUDIS, SUAREZ AND THE GUARDS ARE HERE, GATHERED AROUND THE CONSOLE.'` |
| 0x944F | 0x848F ON GOTO area2.event_scratch0 choice 32 | `0x9457 0x12 PRINTCLEAR "THIS DOOR READS 'LASER PLATFORM. DO NOT ENTER.'"` |
| 0x947F | 0x848F ON GOTO area2.event_scratch0 choice 33 | `0x9489 0x12 PRINTCLEAR 'THE SMOKING RUINS OF THE CONSOLE ARE ALL THAT REMAIN.'` |
|  |  | `0x94B6 0x12 PRINTCLEAR "A FEW SWITCHES ARE LABELED ON THE CONSOLE. THEY READ 'CAPACITOR CHARGE', 'CAPACITOR DISCHARGE', AND 'COORDINATE SETTING."` |
| 0x9513 |  | `0x9513 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'IGNORE', 'OPERATE SWITCHES', 'SHOOT PANEL'` |
| 0x9573 | 0x9542 GOTO 0x9573 | `0x9573 0x12 PRINTCLEAR 'WHICH SWITCH WOULD YOU LIKE TO TRY?'` |
| 0x9591 |  | `0x9591 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'CHARGE', 'DISCHARGE', 'SET COORDINATES'` |
| 0x95C4 | 0x95B5 ON GOTO area2.event_scratch0 choice 0 | `0x95CB 0x12 PRINTCLEAR 'A LOUD PULSATING HUM SURGES INTO THE ROOM.'` |
|  |  | `0x95F6 0x12 PRINTCLEAR 'THE PULSING DOES NOT CHANGE.'` |
| 0x9612 | 0x95B5 ON GOTO area2.event_scratch0 choice 1 | `0x9619 0x12 PRINTCLEAR 'NOTHING HAPPENS.'` |
|  |  | `0x963A 0x12 PRINTCLEAR 'YOU HEAR A SHARP WHINE, AND THE PULSATING FADES.'` |
|  |  | `0x9666 0x12 PRINTCLEAR 'THE LASER, FOCUSED THROUGH THE CRYSTAL, CREATES A CHILLING VIBRATION. THE SYSTEM HAS DISCHARGED.'` |
|  |  | `0x96BC 0x11 PRINT ' A HALF SECOND LATER, YOU HEAR A DISTANT EXPLOSION.'` |
| 0x96FC | 0x95B5 ON GOTO area2.event_scratch0 choice 2 | `0x96FC 0x12 PRINTCLEAR 'YOU ARE PROMPTED FOR COORDINATES. '` |
|  |  | `0x9739 0x11 PRINT '<string at area2.selected_player_name>'` |
|  |  | `0x973D 0x11 PRINT ' INPUTS THE COORDINATES OF THE ORBITING RAM CRUISER.'` |
|  |  | `0x9767 0x33 PRINT RETURN` |
|  |  | `0x9768 0x11 PRINT "THE CONSOLE STATES, 'TRACKING TARGET.'"` |
| 0x9792 | 0x9723 GOTO 0x9792<br>0x9731 GOTO 0x9792 | `0x9792 0x11 PRINT 'YOU INPUT COORDINATES OF EMPTY SPACE.'` |
| 0x97B1 | 0x960E GOTO 0x97B1<br>0x9629 GOTO 0x97B1<br>0x9662 GOTO 0x97B1<br>0x96B8 GOTO 0x97B1<br>0x978E GOTO 0x97B1 | `0x97B2 0x12 PRINTCLEAR 'TRY ANOTHER?'` |
| 0x97C5 | 0x848F ON GOTO area2.event_scratch0 choice 34 | `0x97CD 0x12 PRINTCLEAR 'A LASER OF UNBELIEVABLE SIZE TOWERS ABOVE YOU -- YET STILL A SMALLER VERSION OF THE DOOMSDAY LASER.'` |
| 0x994F | 0x848F ON GOTO area2.event_scratch0 choice 35 | `0x995D 0x12 PRINTCLEAR 'THE SECURITY MONITORS DISPLAY DIFFERENT SECTIONS OF THE BASE EACH MINUTE.'` |
| 0x9998 | 0x9959 GOTO 0x9998 | `0x99A1 0x12 PRINTCLEAR 'CURRENTLY, THE MONITOR IS DISPLAYING '` |
| 0x99D8 | 0x99C0 ON GOTO area1.event_word_214 choice 0 | `0x99D8 0x11 PRINT 'LAUNCH BAY '` |
|  |  | `0x99EB 0x11 PRINT '1.'` |
|  |  | `0x99F5 0x11 PRINT '2.'` |
|  |  | `0x9A12 0x11 PRINT ' A LARGE ROCKETSHIP IS BEING SERVICED THERE.'` |
| 0x9A3A | 0x99C0 ON GOTO area1.event_word_214 choice 3 | `0x9A3A 0x11 PRINT 'THE MAIN CONFERENCE ROOM.'` |
| 0x9A54 | 0x99C0 ON GOTO area1.event_word_214 choice 4 | `0x9A54 0x11 PRINT "AN AREA WITH DOOR LABLED 'LASER CONTROL.' "` |
|  |  | `0x9A93 0x11 PRINT 'YOU SEE THE GENERAL AND SUAREZ PRESS A KEYCODE FOR ACCESS.'` |
| 0x9B51 | 0x99C0 ON GOTO area1.event_word_214 choice 5 | `0x9B51 0x11 PRINT 'THE COMMAND CENTER.'` |
|  |  | `0x9B86 0x12 PRINTCLEAR 'THE GENERAL IS HAVING A CONVERSATION WITH A MAN IN A RED CAPE.'` |
| 0x9BDC | 0x99F1 GOTO 0x9BDC<br>0x9A04 GOTO 0x9BDC<br>0x9A36 GOTO 0x9BDC<br>0x9A50 GOTO 0x9BDC<br>0x9A81 GOTO 0x9BDC<br>0x9A8F GOTO 0x9BDC<br>0x9B73 GOTO 0x9BDC<br>0x9B81 GOTO 0x9BDC | `0x9BDD 0x12 PRINTCLEAR 'DO YOU CONTINUE TO WATCH?'` |
| 0x9BFA | 0x848F ON GOTO area2.event_scratch0 choice 36 | `0x9C05 0x12 PRINTCLEAR 'THE WALLS ARE LINED WITH BUNKS AND LOCKERS. THERE ARE GUARDS RESTING. THEY LOOK UP AT YOU IN SURPRISE.'` |
| 0x9C55 |  | `0x9C55 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK'` |
| 0x9C77 | 0x9C6F GOTO 0x9C77 | `0x9C9D 0x12 PRINTCLEAR 'YOU HIDE THE BODIES AND CHANGE INTO THEIR UNIFORMS. YOU FIND A SECURITY PASS AS WELL.'` |
| 0x9D15 | 0x848F ON GOTO area2.event_scratch0 choice 37 | `0x9D2B 0x12 PRINTCLEAR "THE GENERAL'S BATHROOM. UNDER THE SINK YOU FIND A WAD OF PAPER CONTAINING SOME NUMBERS. THEY APPEAR TO BE AN ACCESS CODE."` |
| 0x9D93 | 0x8285 GOSUB 0x9D93<br>0x831B GOSUB 0x9D93<br>0x834B GOSUB 0x9D93 | `0x9D93 0x12 PRINTCLEAR 'THIS DOOR IS LOCKED. IT IS DIFFICULT TO PICK IT UNNOTICED. '` |
| 0x9F05 | 0x829D GOSUB 0x9F05<br>0x8333 GOSUB 0x9F05<br>0x8363 GOSUB 0x9F05<br>0x853E GOSUB 0x9F05 | `0x9F35 0x12 PRINTCLEAR "THE GUARD SAYS, 'THIS IS A RESTRICTED AREA. RETURN TO LAUNCH BAY 1.'"` |
|  |  | `0x9F6C 0x12 PRINTCLEAR "THE GUARDS PULL THEIR WEAPONS. 'HALT. PUT YOUR HANDS UP AND COME WITH US.'"` |
| 0x9FA7 |  | `0x9FA7 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK', 'FAST TALK'` |
| 0x9FD2 | 0x9F30 GOTO 0x9FD2 | `0x9FD2 0x12 PRINTCLEAR "A GUARD STATES, 'YOU SHOULD NOT BE HERE.'"` |
| 0x9FF4 |  | `0x9FF4 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LEAVE', 'ATTACK'` |
| 0xA00B | 0x9F25 GOTO 0xA00B | `0xA00B 0x12 PRINTCLEAR "A GUARD COMES CLOSE. 'WHAT IS THE PROBLEM HERE, SOLDIER?'"` |
| 0xA0DF | 0xA0C2 GOTO 0xA0DF | `0xA0DF 0x12 PRINTCLEAR 'THE GUARDS ATTACK!'` |
| 0xA0FC | 0x9FC3 ON GOTO area2.event_scratch0 choice 0 | `0xA107 0x12 PRINTCLEAR 'YOU LEAVE, MAKING THE GUARDS MORE SUSPICIOUS.'` |
| 0xA137 | 0xA103 GOTO 0xA137 | `0xA137 0x12 PRINTCLEAR 'YOU ATTEMPT TO SURRENDER, BUT THE GUARDS ATTACK!'` |
| 0xA168 | 0x9FC3 ON GOTO area2.event_scratch0 choice 2 | `0xA168 0x39 WHO <select player> 'WHO WILL FAST TALK?'` |
|  |  | `0xA19A 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0xA19E 0x11 PRINT ' COMPLAINS OF HIS ABSENT MINDEDNESS. THE GUARDS STILL INSIST YOU LEAVE.'` |
| 0xA1E2 | 0xA196 GOTO 0xA1E2 | `0xA1E2 0x11 PRINT 'THE GUARDS TELL YOU TO MOVE ON.'` |
| 0xA208 | 0x8618 GOTO 0xA208<br>0x9C73 GOTO 0xA208 | `0xA217 0x12 PRINTCLEAR "THE GENERAL SAYS, 'YOU'VE KEPT ME WAITING, SUAREZ. I DISLIKE THAT.'"` |

### ECL 36

Attached still-missing strings:
- 0x8186: owner 0x8168; `branch_target_region` `RISER?`. incoming: 0x8103 GOTO 0x8168
- 0x852E: owner 0x8507; `branch_target_region` `PICK LOCK`. incoming: 0x80C4 GOTO 0x8507
- 0x853C: owner 0x8507; `branch_target_region` `KNOCK`. incoming: 0x80C4 GOTO 0x8507
- 0x913A: owner 0x90B6; `branch_target_region` `DOOR IN FRONT OF YOU`. incoming: 0x87B2 ON GOTO area1.event_word_204 choice 10
- 0x9CF2: owner 0x9C6C; `branch_target_region` `WHO WILL TRY?`. incoming: 0x9A74 GOTO 0x9C6C

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8119 | 0x80F5 GOTO 0x8119 | `0x8119 0x12 PRINTCLEAR 'DO YOU '` |
|  |  | `0x8122 0x11 PRINT '<string at scratch.word_0000>'` |
|  |  | `0x8126 0x11 PRINT ' THE STAIRS?'` |
| 0x8168 | 0x8103 GOTO 0x8168 | `0x81AF 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x81B3 0x11 PRINT ' NOTICES PRESSURE SENSORS COVERING EACH OF THE RISERS. YOU REALIZE THAT SOME OF THEM MUST BE INACTIVE SINCE STEFI CAME THIS WAY.'` |
| 0x8221 | 0x8199 GOTO 0x8221<br>0x81AB GOTO 0x8221 | `0x8221 0x11 PRINT '<string at scratch.word_0000>'` |
|  |  | `0x8225 0x11 PRINT area1.event_word_212` |
|  |  | `0x8230 0x11 PRINT 'ST'` |
|  |  | `0x8236 0x11 PRINT 'ND'` |
|  |  | `0x8242 0x11 PRINT 'RD'` |
|  |  | `0x8248 0x11 PRINT 'TH'` |
|  |  | `0x824D 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x8507 | 0x80C4 GOTO 0x8507 | `0x8512 0x12 PRINTCLEAR "THE DOOR WON'T BUDGE. "` |
| 0x89A3 | 0x8942 GOTO 0x89A3 | `0x89BA 0x12 PRINTCLEAR 'A SCREAM ECHOS THROUGH THE HALL.'` |
| 0x8A76 | 0x87B2 ON GOTO area1.event_word_204 choice 2 | `0x8A76 0x12 PRINTCLEAR 'AN OLD OFFICE.'` |
|  |  | `0x8A98 0x11 PRINT ' THE PAPERS ARE WORM EATEN AND THE GOVERNMENT ISSUE FURNITURE RUSTED.'` |
| 0x8AD1 | 0x87B2 ON GOTO area1.event_word_204 choice 3 | `0x8ADC 0x12 PRINTCLEAR 'THIS ROOM IS FREE FROM DUST. DISHES ARE STACKED NEATLY TO ONE SIDE AND OTHER SIGNS OF RECENT USE ARE ALL ABOUT.'` |
| 0x8B3E | 0x87B2 ON GOTO area1.event_word_204 choice 4 | `0x8B46 0x12 PRINTCLEAR 'A MATTRESS IS LAID OUT IN THE SOUTHWEST CORNER'` |
|  |  | `0x8B76 0x11 PRINT '.'` |
|  |  | `0x8B7D 0x11 PRINT ', THE SHEETS TUCKED IN SMARTLY. '` |
|  |  | `0x8BA2 0x11 PRINT "'MY NOTES ARE OVER THERE,' SAYS STEFI, POINTING TO THE MATTRESS."` |
|  |  | `0x8BD6 0x11 PRINT 'YOU NOTICE AN ODD LUMP AT ONE END OF THE MATTRESS.'` |
| 0x8C0A | 0x87B2 ON GOTO area1.event_word_204 choice 5 | `0x8C23 0x12 PRINTCLEAR 'THE MATTRESS SMELLS OF PERFUME.'` |
| 0x8C51 | 0x8C1F GOTO 0x8C51 | `0x8C51 0x12 PRINTCLEAR "'MY NOTES ARE HERE BENEATH THE MATTRESS.' STEFI PULLS OUT"` |
|  |  | `0x8C7F 0x11 PRINT ' A BUNDLE OF PAPERS TIED WITH A BIT OF WIRE.'` |
| 0x8F8C | 0x87B2 ON GOTO area1.event_word_204 choice 8 | `0x8F94 0x12 PRINTCLEAR 'A BROOM CLOSET.'` |
| 0x8FA4 | 0x87B2 ON GOTO area1.event_word_204 choice 9 | `0x8FC3 0x12 PRINTCLEAR 'THE CENTER OF THE ROOM IS DOMINATED BY A MASSIVE CONSTRUCT WHICH '` |
|  |  | `0x9001 0x11 PRINT "YOU RECOGNIZE AS A MOCK-UP OF THE DEVICE DESCRIBED IN STEFI'S PAPERS, THOUGH ON A MUCH SMALLER SCALE."` |
|  |  | `0x9051 0x11 PRINT 'LOOKS LIKE SOME SORT OF REACTION CHAMBER.'` |
| 0x9292 | 0x87B2 ON GOTO area1.event_word_204 choice 11 | `0x92C2 0x12 PRINTCLEAR 'STEFI LIES ON THE FLOOR WOUNDED. DO YOU HELP HER?'` |
| 0x9369 | 0x929C GOTO 0x9369 | `0x9374 0x12 PRINTCLEAR 'THE FAR DOOR STANDS OPEN. THE CONTROL PANEL FLASHES FRANTICALLY.'` |
|  |  | `0x93B2 0x12 PRINTCLEAR 'YOU BIND HER WOUNDS AS BEST YOU CAN, KNOWING HER INJURIES WILL FORCE YOU TO MOVE SLOWLY.'` |
| 0x9407 | 0x92BE GOTO 0x9407 | `0x9407 0x12 PRINTCLEAR "STEFI LOOKS AT YOU WITH PAINED EYES. 'WE MUST DESTROY THIS COMPUTER. IT RUNS A SIMULATION OF MY FUSION CHAMBER AND RAM MUST NOT GET HOLD OF IT."` |
|  |  | `0x9480 0x11 PRINT " THEN WE CAN GET MY NOTES.'"` |
|  |  | `0x9499 0x11 PRINT "'"` |
| 0x94A6 | 0x87B2 ON GOTO area1.event_word_204 choice 12 | `0x94B1 0x12 PRINTCLEAR 'THE COMPUTER CONTINUES TO WHIRR AND BUZZ. '` |
| 0x97BD | 0x80D4 GOTO 0x97BD | `0x97D3 0x12 PRINTCLEAR 'DO YOU TRY TO LOG IN TO THE COMPUTER?'` |
| 0x98A5 | 0x87B2 ON GOTO area1.event_word_204 choice 14 | `0x98D5 0x11 PRINT " NOTICES A PIECE OF STEFI'S SKIRT ON THE RUBBLE WHERE SHE WAS DRUG TO THE WEST."` |
| 0x9916 | 0x87B2 ON GOTO area1.event_word_204 choice 15 | `0x9949 0x11 PRINT " NOTICES SIGNS OF STEFI'S ABDUCTION TO THE WEST."` |
| 0x9D0D | 0x81A6 GOSUB 0x9D0D<br>0x98CF GOSUB 0x9D0D<br>0x9943 GOSUB 0x9D0D | `0x9D31 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |

### ECL 37

Attached still-missing strings:
- 0x8397: owner 0x834C; `branch_target_region` `GROTESQUES`. incoming: 0x82A6 GOTO 0x834C
- 0x83A3: owner 0x834C; `branch_target_region` `WHITE MONKS`. incoming: 0x82A6 GOTO 0x834C
- 0x876C: owner 0x86F0; `branch_target_region` `DECLINE`. incoming: 0x820B ON GOTO area1.event_word_206 choice 7
- 0x97D7: owner 0x948C; `branch_target_region` `KILL HIM`. incoming: 0x820B ON GOTO area1.event_word_206 choice 13
- 0xA345: owner 0xA287; `branch_target_region` `WHO WILL TRY?`. incoming: 0xA266 GOTO 0xA287

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8105 | 0x8100 GOTO 0x8105 | `0x8105 0x12 PRINTCLEAR '<string at scratch.word_0000>'` |
|  |  | `0x8109 0x11 PRINT 'UP'` |
|  |  | `0x810E 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x8137 | 0x80F5 GOTO 0x8137 | `0x8137 0x12 PRINTCLEAR '<string at scratch.word_0000>'` |
|  |  | `0x813B 0x11 PRINT 'DOWN'` |
|  |  | `0x8141 0x11 PRINT '<string at scratch.word_0208>'` |
| 0x8161 | 0x80C4 GOTO 0x8161 | `0x816F 0x12 PRINTCLEAR 'YOU DO NOT HAVE A KEY.'` |
| 0x818B | 0x816B GOTO 0x818B | `0x818B 0x12 PRINTCLEAR 'THE KEY SLIDES INTO THE LOCK AND THE DOOR OPENS EASILY.'` |
| 0x81BA | 0x80B9 GOTO 0x81BA | `0x81C1 0x12 PRINTCLEAR 'THE DOOR IS SEALED.'` |
|  |  | `0x81D4 0x12 PRINTCLEAR 'RUBBLE HAS JAMMED THE DOOR.'` |
| 0x8404 | 0x83EF ON GOTO area1.event_word_206 choice 1 | `0x8404 0x12 PRINTCLEAR 'CHILDREN SCRABBLE ABOUT, TRYING TO CATCH A RAT.'` |
| 0x842D | 0x83EF ON GOTO area1.event_word_206 choice 2 | `0x842D 0x12 PRINTCLEAR 'A WOMAN RIPS PIPES FROM THE WALL, SEEKING TRAPPED WATER.'` |
| 0x845C | 0x83E1 GOTO 0x845C<br>0x83EF ON GOTO area1.event_word_206 choice 3 | `0x845C 0x12 PRINTCLEAR 'A CLUTTERED APARTMENT ROOM.'` |
| 0x8475 | 0x83EF ON GOTO area1.event_word_206 choice 4 | `0x8475 0x12 PRINTCLEAR 'A RAG CLAD FAMILY SITS AROUND A POT WITH A SMALL FIRE IN IT.'` |
| 0x84A7 | 0x820B ON GOTO area1.event_word_206 choice 5 | `0x84BB 0x12 PRINTCLEAR 'A MAKE-SHIFT CLINIC. AN OLD WOMAN AND HER STAFF TREAT THE ILL. DO YOU TALK TO HER?'` |
| 0x8663 | 0x820B ON GOTO area1.event_word_206 choice 6 | `0x8679 0x12 PRINTCLEAR 'AT THE SPOT ISHA DIRECTED YOU TO, YOU FIND NOTHING.'` |
|  |  | `0x86A3 0x33 PRINT RETURN` |
|  |  | `0x86A4 0x33 PRINT RETURN` |
| 0x8ED0 | 0x8B99 ON GOTO area1.event_word_2AE choice 3 | `0x8ED0 0x12 PRINTCLEAR 'ISHA STEPS BEFORE YOU. '` |
|  |  | `0x8EFD 0x11 PRINT "'YOU GAVE THE WEAPONS TO THAT FOOL, LOA-LOA! YOU BETTER GET THEM BACK!' "` |
|  |  | `0x8F42 0x11 PRINT 'DO YOU GIVE HER THE WEAPONS?'` |
| 0x8FDD | 0x8EEF GOTO 0x8FDD | `0x8FDD 0x11 PRINT "'NO WEAPONS?' "` |
| 0x9163 | 0x9108 GOTO 0x9163<br>0x9116 GOTO 0x9163 | `0x9171 0x12 PRINTCLEAR "A YOUNG WOMAN SPEAKS FURTIVELY WITH SOME STREET PEOPLE. SHE PASSES THEM SOME CREDITS, THEN LOOKS UP. 'I AM ISHA. I HAVE BEEN LOOKING FOR YOU. YOU ARE JUST THE SORT TO HELP ME."` |
| 0x9436 | 0x820B ON GOTO area1.event_word_206 choice 12 | `0x9436 0x12 PRINTCLEAR 'YOU FIND A FAMILY HUDDLED TOGETHER IN A CORNER, DEAD OF STARVATION. THE STENCH DRIVES YOU FROM THE ROOM.'` |
| 0x97F2 | 0x820B ON GOTO area1.event_word_206 choice 14 | `0x97FD 0x12 PRINTCLEAR 'TOO LATE, YOU FEEL THE TUG OF A TRIPWIRE AT YOUR ANKLES.'` |
| 0x9A0F | 0x9900 GOTO 0x9A0F | `0x9A22 0x12 PRINTCLEAR 'WINK COWERS IN THE CORNER, TIED TO A CHAIR. '` |
|  |  | `0x9A50 0x11 PRINT 'HE GUSHES THANKS AND FLATTERY, PROMISING YOU ANYTHING YOU WANT. '` |
|  |  | `0x9A83 0x11 PRINT 'UNTIE HIM?'` |
|  |  | `0x9AA3 0x12 PRINTCLEAR "'IT WAS ISHA AND HER RAM TRASH. NOW ITS CLEAR WHY THE GENNIES SHOWED UP THE SAME TIME SHE DID. SPREADING TERROR, I GUESS THAT'S ALL RAM EVER WANTS."` |
| 0x9CE5 | 0x820B ON GOTO area1.event_word_206 choice 17 | `0x9CFC 0x12 PRINTCLEAR "A CELL FILLED WITH GADGETS. EQUATIONS COVER THE WALLS. 'I KEPT CHADE IN HERE.' WINK SAYS BEHIND YOU. 'ONLY FOR A WHILE, THOUGH. HE ESCAPED WITH HIS DAUGHTER ALMOST TWO WEEKS AGO."` |
| 0x9E7E | 0x9F76 GOTO 0x9E7E | `0x9E7E 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x9E82 0x11 PRINT ' NOTICES A SMALL HOLE IN THE WALL.'` |
| 0xA287 | 0xA266 GOTO 0xA287 | `0xA287 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0xA28B 0x11 PRINT ' NOTICES A TRIPWIRE STRETCHED ACROSS THE RUBBLE. DO YOU TRY TO DISARM THE DEMO CHARGES?'` |

### ECL 38 - GEO 38: Losangelorg Sprawls

Attached still-missing strings:
- 0x893B: owner 0x88BD; `branch_target_region` `SMOKING GUN SLOTS`. incoming: 0x855B ON GOTO area2.event_scratch1 choice 5
- 0x8B85: owner 0x8949; `branch_target_region` `SOMEONE ELSE?`. incoming: 0x855B ON GOTO area2.event_scratch1 choice 6

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x82E3 | 0x8260 GOTO 0x82E3<br>0x8287 GOTO 0x82E3<br>0x82CE GOTO 0x82E3<br>0x832F GOTO 0x82E3<br>0x8395 GOTO 0x82E3<br>0x83A7 GOTO 0x82E3<br>0x83B9 GOTO 0x82E3<br>0x83CB GOTO 0x82E3 | `0x82E3 0x12 PRINTCLEAR 'THE DOOR TO ROOM '` |
|  |  | `0x82F3 0x11 PRINT area1.event_word_204` |
|  |  | `0x82F7 0x11 PRINT '0'` |
|  |  | `0x82FB 0x11 PRINT area1.event_word_208` |
|  |  | `0x82FF 0x11 PRINT " DOESN'T RECOGNIZE YOUR PASSCARD."` |
| 0x8322 | 0x8270 GOTO 0x8322 | `0x8333 0x12 PRINTCLEAR 'ROOM 5403. ON THE DOOR IS A NOTE.'` |
| 0x83BE | 0x82DE GOTO 0x83BE | `0x83DA 0x12 PRINTCLEAR 'THE BARTENDER HAS LOCKED UP.'` |
| 0x83FF | 0x820F GOTO 0x83FF | `0x8407 0x12 PRINTCLEAR 'THIS DOOR ONLY OPENS ON THE FIRST FLOOR.'` |
| 0x8436 | 0x8226 GOTO 0x8436<br>0x823D GOTO 0x8436 | `0x8441 0x12 PRINTCLEAR 'THE TUNNEL NARROWS AHEAD. YOU WILL HAVE GO THROUGH ONE AT A TIME. DO YOU CONTINUE?'` |
| 0x848B | 0x81F8 GOTO 0x848B | `0x8496 0x12 PRINTCLEAR 'YOU ARE ABOUT TO LEAVE. DO YOU CONTINUE?'` |
| 0x84C3 | 0x8492 GOTO 0x84C3 | `0x84CD 0x12 PRINTCLEAR "AS YOU PREPARE TO LEAVE, A PARENT HISSES AT YOU. 'WHAT KIND OF HEROS ARE YOU? LEAVING CHILDREN TO A TERRIBLE FATE, BAH!'"` |
|  |  | `0x852C 0x12 PRINTCLEAR 'DO YOU LEAVE THE RATWURST DEN?'` |
| 0x85AB | 0x855B ON GOTO area2.event_scratch1 choice 2 | `0x85BA 0x12 PRINTCLEAR 'YOU ENTER THE ELEVATOR. DO YOU WISH TO USE IT?'` |
| 0x875E | 0x855B ON GOTO area2.event_scratch1 choice 3 | `0x8766 0x12 PRINTCLEAR 'A PLAQUE ON THE WALL READS,'` |
|  |  | `0x877E 0x33 PRINT RETURN` |
|  |  | `0x877F 0x33 PRINT RETURN` |
|  |  | `0x8780 0x11 PRINT '    -- FLOOR NUMBER '` |
|  |  | `0x8792 0x11 PRINT area1.event_word_204` |
|  |  | `0x8796 0x11 PRINT ' --'` |
|  |  | `0x879C 0x33 PRINT RETURN` |
|  |  | `0x87A8 0x11 PRINT 'ROOMS '` |
|  |  | `0x87B0 0x11 PRINT area1.event_word_204` |
|  |  | `0x87B4 0x11 PRINT '01 - '` |
|  |  | `0x87BB 0x11 PRINT area1.event_word_204` |
|  |  | `0x87BF 0x11 PRINT '04 - RIGHT HALL'` |
| 0x8801 | 0x87A4 GOTO 0x8801 | `0x8801 0x11 PRINT 'TOWER ISLE CASINO COMPLEX --'` |
|  |  | `0x8819 0x33 PRINT RETURN` |
|  |  | `0x881A 0x11 PRINT 'MANAGEMENT NOT RESPONSIBLE FOR DAMAGED, LOST OR STOLEN PROPERTY.'` |
| 0x884F | 0x87D6 GOTO 0x884F | `0x884F 0x11 PRINT 'ROOMS 8505 - 8507 - LEFT HALL'` |
|  |  | `0x8868 0x33 PRINT RETURN` |
|  |  | `0x8869 0x11 PRINT 'SPARKHOUSE CAFE STRAIGHT AHEAD'` |
| 0x8885 | 0x855B ON GOTO area2.event_scratch1 choice 4 | `0x8890 0x12 PRINTCLEAR 'A SIGN OVER THE DOOR READS,'` |
|  |  | `0x88A8 0x33 PRINT RETURN` |
|  |  | `0x88A9 0x33 PRINT RETURN` |
|  |  | `0x88AA 0x11 PRINT 'GREY LADY CARD ROOM'` |
| 0x88BD | 0x855B ON GOTO area2.event_scratch1 choice 5 | `0x88D7 0x12 PRINTCLEAR 'A SIGN OVER THE SOUTH DOOR READS,'` |
|  |  | `0x88F3 0x33 PRINT RETURN` |
|  |  | `0x88F4 0x33 PRINT RETURN` |
|  |  | `0x88F5 0x11 PRINT 'RED RIVER BAR'` |
| 0x8949 | 0x855B ON GOTO area2.event_scratch1 choice 6 | `0x8968 0x12 PRINTCLEAR 'A MAN IN A RAGGED MILITARY UNIFORM SITS AGAINST THE WALL HERE.'` |
| 0x8CBB | 0x9763 GOTO 0x8CBB | `0x8CBB 0x12 PRINTCLEAR 'YOU FLEE THE BATTLE.'` |
| 0x8CDC | 0x855B ON GOTO area2.event_scratch1 choice 8 | `0x8CED 0x12 PRINTCLEAR "YOU ENTER AN EMPTY BARROOM. THE BARTENDER GREETS YOU. 'HI, PULL UP A STOOL. I'LL BUY YOU A DRINK!'"` |
| 0x8E4A | 0x855B ON GOTO area2.event_scratch1 choice 9 | `0x8E5D 0x12 PRINTCLEAR 'A CARD GAME IS BEING PLAYED AT ONE OF THE TABLES. AS YOU ENTER THE ROOM, A PLAYER LOOKS UP.'` |
| 0x9483 | 0x855B ON GOTO area2.event_scratch1 choice 10 | `0x948B 0x12 PRINTCLEAR 'YOU ENTER THE SPARKHOUSE CAFE.'` |
| 0x964B | 0x855B ON GOTO area2.event_scratch1 choice 11 | `0x9668 0x12 PRINTCLEAR "THE WARREN DWELLERS SHOUT DOWN TO YOU. 'YOU DIDN'T FIND OUR CHILDREN...YOU MUST GO BACK!'"` |
| 0x96B0 | 0x9664 GOTO 0x96B0 | `0x96C4 0x12 PRINTCLEAR "THE CHILDREN'S PARENTS SHOUT WITH JOY. 'OH, THANK YOU! WITH GOOD FOLKS LIKE YOU, THERE'S STILL HOPE FOR US!'"` |
| 0x9723 | 0x855B ON GOTO area2.event_scratch1 choice 12 | `0x973A 0x12 PRINTCLEAR 'RATWURST ATTACK!'` |
| 0x977D | 0x9778 GOTO 0x977D | `0x977D 0x12 PRINTCLEAR "THE MAN THANKS YOU. 'YOU SAVED MY LIFE! THOSE RATS HAD ME TRAPPED AND WERE SAVING ME FOR DINNER!"` |
| 0x984B | 0x855B ON GOTO area2.event_scratch1 choice 13 | `0x985F 0x12 PRINTCLEAR "'HELP!' YOU HEAR A SHOUT FROM THE SOUTH."` |
| 0x9882 | 0x855B ON GOTO area2.event_scratch1 choice 14 | `0x9899 0x12 PRINTCLEAR 'RATWURSTS HAVE CORNERED A MAN AT THE END OF THE TUNNEL.'` |
| 0x99AF | 0x855B ON GOTO area2.event_scratch1 choice 16 | `0x99C3 0x12 PRINTCLEAR 'YOU HEAR RUNNING FOOTSTEPS DOWN THE TUNNEL AHEAD.'` |
| 0x9A75 | 0x855B ON GOTO area2.event_scratch1 choice 18 | `0x9A8E 0x12 PRINTCLEAR "YOU FIND THE GANG'S SUPPLIES."` |
| 0x9AC4 | 0x9A7F GOTO 0x9AC4 | `0x9AC4 0x12 PRINTCLEAR 'YOU ARE ATTACKED FROM BEHIND!'` |
| 0x9B0F | 0x855B ON GOTO area2.event_scratch1 choice 19 | `0x9B0F 0x12 PRINTCLEAR 'AUDIO CAPSULES ARE STORED HERE.'` |
| 0x9B2B | 0x855B ON GOTO area2.event_scratch1 choice 20 | `0x9B2B 0x12 PRINTCLEAR 'A SMALL OFFICE.'` |
| 0x9BAE | 0x855B ON GOTO area2.event_scratch1 choice 21 | `0x9BB6 0x12 PRINTCLEAR 'A SMALL AUDIO PRODUCTION ROOM.'` |
| 0x9BD1 | 0x855B ON GOTO area2.event_scratch1 choice 22 | `0x9BFB 0x12 PRINTCLEAR "AS YOU ENTER, THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR FLICKERS OFF."` |
| 0x9C34 | 0x9BE3 GOTO 0x9C34 | `0x9C3F 0x12 PRINTCLEAR "THE 'ON AIR' LIGHT OVER THE SOUTHERN DOOR IS ON."` |
| 0x9C68 | 0x855B ON GOTO area2.event_scratch1 choice 23 | `0x9C98 0x12 PRINTCLEAR 'YOU ENTER THE BROADCAST BOOTH. A DESERT RUNNER SITS AT THE CONTROLS. HE MOTIONS YOU TO SILENCE, FLICKS A SWITCH, AND SPEAKS INTO A MICROPHONE.'` |
| 0x9F2B | 0x9C8B GOTO 0x9F2B<br>0x9F6D GOTO 0x9F2B | `0x9F2B 0x12 PRINTCLEAR "BAD DOG GIVES YOU THE 'THUMBS UP' SIGN AS YOU ENTER THE BOOTH."` |
| 0x9F63 | 0x9C7A GOTO 0x9F63 | `0x9F7A 0x12 PRINTCLEAR "YOU ENTER THE BROADCAST BOOTH. A PURGE MEMBER SITS AT THE CONTROLS. HE SCREEDS VENOMOUSLY INTO THE MIKE.'"` |

### ECL 48

Attached still-missing strings:
- 0x8F66: owner 0x8E9B; `branch_target_region` `HIS SPEECH`. incoming: 0x8054 GOTO 0x8E9B

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x806A | 0x8050 GOTO 0x806A | `0x806A 0x12 PRINTCLEAR 'YOU CLIMB FROM THE LAB ONTO THE SURFACE OF VENUS.'` |
| 0x8797 | 0x8788 ON GOTO area1.event_word_214 choice 0 | `0x8797 0x12 PRINTCLEAR 'THE WIND BEGINS TO PICK UP.'` |
| 0x89FB | 0x868A ON GOTO area2.event_scratch0 choice 4 | `0x8A2A 0x12 PRINTCLEAR ''` |
|  |  | `0x8A3B 0x12 PRINTCLEAR 'YOU ARE SURROUNDED BY A GROUP OF LOWLANDER WARRIORS. THEY ARE ARMED WITH CRYSTAL TIPPED SPEARS, BUT YOU CAN SEE AN OCCASIONAL LASER RIFLE AMONGST THEIR ARMAMENT.'` |
| 0x8B3C | 0x8A2E GOTO 0x8B3C | `0x8B3C 0x11 PRINT 'LOWLANDERS ATTACK!'` |
| 0x8B6A | 0x8A08 GOTO 0x8B6A | `0x8B6A 0x12 PRINTCLEAR 'YOU MEET A PARTY OF LOWLANDERS. THEY LOOK AT YOU WARILY BEFORE MOVING OFF.'` |
| 0x8BAA | 0x868A ON GOTO area2.event_scratch0 choice 6 | `0x8BBA 0x12 PRINTCLEAR 'MERCURIAN FORCES ATTACK.'` |
|  |  | `0x8BDD 0x12 PRINTCLEAR "A VOICE, AMPLIFIED BY A BULLHORN BOOMS OUT AT YOU FROM A GROVE OF TREES. 'SURRENDER LOWLAND PRIMITIVES! YOU FACE THE POWER OF MERCURY! LAY DOWN YOUR GUNS AND SPEARS!"` |
| 0x8CD8 | 0x868A ON GOTO area2.event_scratch0 choice 8 | `0x8CFD 0x12 PRINTCLEAR 'YOU ARE ATTACKED BY TERRAN SOLDIERS. THEY ARE THE SAME FORCES YOU FOUGHT ON MERCURY'` |
|  |  | `0x8D49 0x11 PRINT ' AND AT THE LOWLANDER FARM'` |
|  |  | `0x8D60 0x11 PRINT '!'` |
| 0x8E3F | 0x8E19 GOSUB 0x8E3F | `0x8E3F 0x12 PRINTCLEAR 'YOU TREK THROUGH MOUNTAINS.'` |
| 0x8E58 | 0x8E24 GOSUB 0x8E58 | `0x8E58 0x12 PRINTCLEAR 'YOU CROSS SOME HILLS.'` |
| 0x8E6C | 0x8E2F GOSUB 0x8E6C | `0x8E6C 0x12 PRINTCLEAR "YOU'RE IN A FOREST."` |
| 0x8E7F | 0x8E3A GOSUB 0x8E7F | `0x8E7F 0x12 PRINTCLEAR "YOU'RE SLOGGING THROUGH A SWAMP."` |
| 0x911E | 0x8FAE GOTO 0x911E | `0x911E 0x12 PRINTCLEAR 'YOU FACE THE GATE OF THE LOWLANDER VILLAGE. WILL YOU ENTER THE VILLAGE?'` |
| 0x9169 | 0x85FA GOTO 0x9169 | `0x9178 0x12 PRINTCLEAR 'YOUR SHIP IS HERE. '` |
|  |  | `0x9195 0x11 PRINT "SCOT.DOS' VOICE BARKS OUT OF YOUR HELMET SPEAKERS. 'I THINK YOU'D BETTER GO FIND THAT SCIENTIST. AFTER ALL, THAT'S WHAT WE'RE HERE FOR!"` |
| 0x91FF | 0x9244 GOTO 0x91FF | `0x91FF 0x12 PRINTCLEAR 'DO YOU BOARD YOUR SHIP?'` |
| 0x923A | 0x9191 GOTO 0x923A | `0x9251 0x11 PRINT "SCOT.DOS SPEAKS THROUGH YOUR HELMET SPEAKERS. 'GOOD JOB TEAM."` |
| 0x9309 | 0x8605 GOTO 0x9309 | `0x9311 0x12 PRINTCLEAR 'THE LOWLANDER LAB COMPLEX IS HERE. YOU CAN CLIMB DOWN THROUGH THE DESTROYED ROOF. DO YOU?'` |
| 0x935E | 0x8610 GOTO 0x935E | `0x9369 0x12 PRINTCLEAR 'YOU ARE KNEE DEEP IN A STANDING POOL OF SULFURIC ACID. YOUR ARMOR OFFERS SOME PROTECTION, BUT IT IS SLOWLY CORRODING.'` |
| 0x9429 | 0x9BC0 GOTO 0x9429 | `0x9429 0x12 PRINTCLEAR 'SMOKE RISES FROM A NEARBY CLEARING. DO YOU INVESTIGATE?'` |
| 0x9BD3 | 0x8296 GOTO 0x9BD3 | `0x9BEC 0x12 PRINTCLEAR 'A GLIDER DRIFTS OVERHEAD AND DROPS A SMALL METAL CAPSULE.  THE CAPSULE LANDS OVER A RISE AND OUT OF SIGHT AS THE GLIDER SAILS OFF. DO YOU LOOK FOR THE CAPSULE?'` |
| 0x9FA8 | 0x9BDA GOTO 0x9FA8 | `0x9FBF 0x12 PRINTCLEAR 'YOU HEAR A RUSTLING IN THE NEARBY FOLIAGE. DO YOU INVESTIGATE?'` |

### ECL 49 - GEO 52: Lowlander Mines

Attached still-missing strings:
- 0x8455: owner 0x844D; `branch_target_region` `OPEN LOCK`. incoming: 0x82A0 GOSUB 0x844D; 0x8448 GOSUB 0x844D

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8267 | 0x8156 GOTO 0x8267<br>0x816D GOTO 0x8267 | `0x8285 0x12 PRINTCLEAR 'THESE DOORS ARE LOCKED. '` |
| 0x82A4 | 0x8281 GOTO 0x82A4 | `0x82A4 0x12 PRINTCLEAR 'YOU ENTER A MODERN INDUSTRIAL COMPLEX. THE BUILDINGS HERE ARE MADE OF FINELY FINISHED PLASTICS AND CERAMICS. THE GROUND IS MARKED BY THE PASSAGE OF MANY HEAVY VEHICLES.'` |
| 0x8362 | 0x8227 GOTO 0x8362<br>0x8237 GOTO 0x8362 | `0x837A 0x12 PRINTCLEAR 'RUBBLE BLOCKS THIS DOOR FROM THE OTHER SIDE. LOWLANDERS WORK TO CLEAR THE PASSAGE.'` |
| 0x83C2 | 0x81B9 GOTO 0x83C2 | `0x83D5 0x12 PRINTCLEAR 'THIS SOLID CERAMIC DOOR IS LOCKED. THE WALL IT IS SET IN IS MADE OF A STEEL-STRONG PLASTIC THAT HAS BEEN DISGUISED BEHIND WOVEN PLANT FIBER. '` |
| 0x85B3 | 0x8263 GOTO 0x85B3 | `0x85B3 0x12 PRINTCLEAR 'DO YOU LEAVE?'` |
| 0x85E2 | 0x85D7 GOTO 0x85E2 | `0x85E2 0x12 PRINTCLEAR 'YOU ENTER THE LOWLANDER LAB COMPLEX.'` |
| 0x8603 | 0x81E7 GOTO 0x8603<br>0x81F7 GOTO 0x8603 | `0x8612 0x12 PRINTCLEAR 'YOU WILL HAVE TO CLIMB DOWN THE SHAFT. DO YOU CONTINUE?'` |
| 0x8749 | 0x8207 GOTO 0x8749<br>0x8217 GOTO 0x8749 | `0x8758 0x12 PRINTCLEAR 'YOU WILL HAVE TO CLIMB UP THE SHAFT. DO YOU CONTINUE?'` |
| 0x89E6 | 0x89D4 ON GOTO area2.event_scratch0 choice 0 | `0x89EA 0x11 PRINT "'INTRUDER ALERT! TO ARMSS! TO ARMSS!'"` |
| 0x8A0B | 0x89D4 ON GOTO area2.event_scratch0 choice 1 | `0x8A0B 0x12 PRINTCLEAR "A SPEAKER NEAR YOU CRACKLES INTO LIFE. SCOT.DOS' VOICE ISSUES FORTH."` |
| 0x8AD4 | 0x89D4 ON GOTO area2.event_scratch0 choice 2 | `0x8AD8 0x11 PRINT "'TRACKING INTRUDERSS! QUADRANT 4 PERIMETER ALARM TRIPPED!'"` |
| 0x8B09 | 0x89D4 ON GOTO area2.event_scratch0 choice 3 | `0x8B0D 0x11 PRINT "'BATTLE PLAN 7 DRILL! REPEAT, PLAN 7 DRILL!'"` |
| 0x8B33 | 0x891C ON GOTO area2.event_scratch1 choice 1 | `0x8B3E 0x12 PRINTCLEAR 'THERE IS A DOWN ELEVATOR HERE. DO YOU USE IT?'` |
| 0x8B8E | 0x8B3A GOTO 0x8B8E | `0x8B96 0x12 PRINTCLEAR 'THE ELEVATOR HAS BEEN DAMAGED IN THE EXPLOSION.'` |
| 0x8C7F | 0x891C ON GOTO area2.event_scratch1 choice 2 | `0x8C87 0x12 PRINTCLEAR 'AN ELEVATOR UP. DO YOU GO?'` |
| 0x8CCB | 0x891C ON GOTO area2.event_scratch1 choice 3 | `0x8CDF 0x12 PRINTCLEAR 'THE BLOODY TRAIL LEADS DOWN THE TUNNEL TO THE NORTH.'` |
| 0x8D0B | 0x891C ON GOTO area2.event_scratch1 choice 4 | `0x8D16 0x12 PRINTCLEAR 'TO THE EAST IS THE SECRET DOOR THAT THE LOWLANDERS TOLD YOU ABOUT.'` |
| 0x8DA9 | 0x8D8B ON GOTO area1.event_word_2EC choice 0 | `0x8DA9 0x12 PRINTCLEAR 'IN THIS HUT, A SHIELD MADE OF VENUSIAN DINOSAUR HIDE STANDS IN THE CORNER NEXT TO SOME CRYSTAL TIPPED SPEARS.'` |
| 0x8E02 | 0x8D8B ON GOTO area1.event_word_2EC choice 2 | `0x8E02 0x12 PRINTCLEAR 'A SMALL HIGH-TECH COOKER SITS ON A LASHED BRANCH TABLE. A COLD PAN OF FRIED VEGETABLES SITS NEXT TO IT.'` |
| 0x8EBB | 0x8D8B ON GOTO area1.event_word_2EC choice 4 | `0x8EBB 0x12 PRINTCLEAR 'A PAIR OF BOOTS SIT NEXT TO THE STRAW TICK BED IN THIS HUT. THEY SEEM TO BE MOLDED FROM AN ORGANIC PLASTIC COMPOUND.'` |
| 0x8F19 | 0x8D8B ON GOTO area1.event_word_2EC choice 6 | `0x8F19 0x12 PRINTCLEAR 'A LASER RIFLE IS PROPPED UP IN THE CORNER HERE. DO YOU WANT IT?'` |
| 0x8F62 | 0x8D8B ON GOTO area1.event_word_2EC choice 7 | `0x8F62 0x12 PRINTCLEAR 'YOU FIND AN ARMORED CHEST PLATE. IT IS MADE OF A SUPER-TOUGH CERAMIC MATERIAL. MADE FOR A LOWLANDER, IT FITS NO ONE IN THE TEAM.'` |
| 0x8FC9 | 0x8D8B ON GOTO area1.event_word_2EC choice 1 | `0x8FC9 0x12 PRINTCLEAR 'YOU FIND NOTHING OF INTEREST IN THIS PRIMITIVE HUT.'` |
| 0x8FF7 | 0x8D7D GOTO 0x8FF7 | `0x8FF7 0x12 PRINTCLEAR "YOU'VE ALREADY SEARCHED THIS HUT."` |
| 0x9020 | 0x891C ON GOTO area2.event_scratch1 choice 13 | `0x9033 0x12 PRINTCLEAR 'THE WOODEN WALLS HERE ARE MADE OF MILLED WOOD. THE AREA IS FREE OF PRIMITIVE TRAPPINGS.'` |
| 0x9082 | 0x891C ON GOTO area2.event_scratch1 choice 14 | `0x908E 0x11 PRINT 'VENUSIAN DINOSAUR HIDE SHIELDS.'` |
| 0x90AB | 0x891C ON GOTO area2.event_scratch1 choice 15 | `0x90B7 0x11 PRINT 'CRYSTAL TIPPED SPEARS.'` |
| 0x90CD | 0x891C ON GOTO area2.event_scratch1 choice 16 | `0x90D9 0x11 PRINT 'WOVEN PLANT FIBER HUT WALLS.'` |
| 0x90F3 | 0x908A GOSUB 0x90F3<br>0x90B3 GOSUB 0x90F3<br>0x90D5 GOSUB 0x90F3 | `0x90F3 0x12 PRINTCLEAR 'THIS BUILDING IS FULL OF MANUFACTURING EQUIPMENT. IT SEEMS TO BE USED TO MASS PRODUCE PRIMITIVE-SEEMING '` |
| 0x9145 | 0x891C ON GOTO area2.event_scratch1 choice 17 | `0x914D 0x12 PRINTCLEAR 'YOU ENTER A SMALL WAREHOUSE. BUNDLES OF SPEARS, SHIELDS AND HUT WALL SECTIONS ARE STORED HERE, READY FOR SHIPPING.'` |
| 0x91A8 | 0x891C ON GOTO area2.event_scratch1 choice 18 | `0x91B3 0x12 PRINTCLEAR 'THESE ROOMS ARE FULL OF LOCKERS. MOST CONTAIN LOWLANDER NATIVE GARB. A FEW HOLD MACHINE-WOVEN OVERALLS, TOUGH PLASTIC BOOTS, AND HARD HATS WITH MINING LAMPS.'` |
| 0x9237 | 0x891C ON GOTO area2.event_scratch1 choice 19 | `0x923F 0x11 PRINT "A SIGN READS, 'HEAVY ELEVATOR.' THERE ARE NO CONTROLS HERE."` |
| 0x9271 | 0x891C ON GOTO area2.event_scratch1 choice 20 | `0x9279 0x12 PRINTCLEAR 'A PARTIALLY BUILT DIGGING MACHINE IS HERE. THE HUGE, TRACKED VEHICLE SEEMS TO BE MADE ENTIRELY OF SMALL BOXED PARTS.'` |
| 0x92D5 | 0x891C ON GOTO area2.event_scratch1 choice 21 | `0x92DD 0x12 PRINTCLEAR "THERE IS A DESK HERE COVERED WITH ACID-RESISTANT MEMOS WRITTEN IN A LANGUAGE YOU DON'T UNDERSTAND."` |
| 0x932C | 0x891C ON GOTO area2.event_scratch1 choice 22 | `0x9334 0x12 PRINTCLEAR 'HAND HELD MINING TOOLS ARE STORED ON PLASTIC SHELVES HERE.'` |
| 0x9365 | 0x891C ON GOTO area2.event_scratch1 choice 23 | `0x9370 0x12 PRINTCLEAR 'THESE ARE HIGHLY ADVANCED COMPUTERS. THE MONITOR ON THIS ONE READS:'` |
|  |  | `0x93A6 0x33 PRINT RETURN` |
|  |  | `0x93A7 0x11 PRINT '    - TERMINAL INACTIVE -'` |
|  |  | `0x93BD 0x33 PRINT RETURN` |
|  |  | `0x93BE 0x11 PRINT '- CONTROL ROUTED TO STATION B -'` |
| 0x93E4 | 0x891C ON GOTO area2.event_scratch1 choice 24 | `0x93EC 0x12 PRINTCLEAR 'LAMPS, SPOOLS OF WIRE, TERMINAL BOXES, AND OTHER ELECTRICAL EQUIPMENT ARE STORED HERE.'` |
| 0x9432 | 0x891C ON GOTO area2.event_scratch1 choice 25 | `0x9458 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x945C 0x11 PRINT ' SEES A NEWLY WIRED COMMUNICATIONS CABLE RUNNING ALONG THE WEST WALL.'` |
| 0x949E | 0x891C ON GOTO area2.event_scratch1 choice 26 | `0x94A2 0x11 PRINT 'EAST'` |
|  |  | `0x94AC 0x11 PRINT 'NORTH'` |
|  |  | `0x94B7 0x11 PRINT 'NORTHERN'` |
|  |  | `0x94C4 0x11 PRINT '   - CITYWARD -'` |
|  |  | `0x94D3 0x33 PRINT RETURN` |
|  |  | `0x94D4 0x11 PRINT '- AIR-CONDITIONING -'` |
| 0x952E | 0x891C ON GOTO area2.event_scratch1 choice 27 | `0x952E 0x12 PRINTCLEAR 'PARTS FOR A GIANT VENTILATOR FAN ARE HERE.'` |
| 0x95FC | 0x891C ON GOTO area2.event_scratch1 choice 29 | `0x9600 0x11 PRINT 'NORTH'` |
|  |  | `0x960B 0x11 PRINT 'EAST'` |
|  |  | `0x9615 0x11 PRINT 'EASTERN'` |
|  |  | `0x9622 0x11 PRINT '   - CITYWARD -'` |
|  |  | `0x9631 0x33 PRINT RETURN` |
|  |  | `0x9632 0x11 PRINT '- SUPPLY CONVEYOR -'` |
| 0x9646 | 0x949E GOSUB 0x9646<br>0x95FC GOSUB 0x9646<br>0xA2ED GOSUB 0x9646 | `0x9646 0x12 PRINTCLEAR 'THE TUNNELS SLANT UPWARDS TO THE '` |
| 0x9663 | 0x94A8 GOSUB 0x9663<br>0x9607 GOSUB 0x9663<br>0xA2F8 GOSUB 0x9663 | `0x9663 0x11 PRINT ' AND DOWNWARDS TO THE '` |
| 0x9678 | 0x94B3 GOSUB 0x9678<br>0x9611 GOSUB 0x9678<br>0xA30A GOSUB 0x9678 | `0x9678 0x11 PRINT '. A SIGN OVER THE '` |
| 0x968A | 0x94C0 GOSUB 0x968A<br>0x961E GOSUB 0x968A<br>0xA317 GOSUB 0x968A | `0x968A 0x11 PRINT ' TUNNEL READS:'` |
|  |  | `0x9698 0x33 PRINT RETURN` |
| 0x969A | 0x891C ON GOTO area2.event_scratch1 choice 30 | `0x96A5 0x12 PRINTCLEAR 'YOU COME ACROSS SOME LOWLANDER MINERS. WITH THEIR BACKS TO YOU, THEY ARE STUDYING THE SOUTH WALL.'` |
| 0xA0D0 | 0x891C ON GOTO area2.event_scratch1 choice 34 | `0xA0DB 0x12 PRINTCLEAR 'URSADDERS AMBUSH YOU!'` |
| 0xA1B2 | 0xA133 GOTO 0xA1B2 | `0xA1C5 0x12 PRINTCLEAR 'LLOROK LIES HERE NEAR DEATH. HE NEEDS THE ATTENTION OF A LOWLANDER MEDIC. DO YOU BRING HIM WITH YOU?'` |
| 0xA2ED | 0x891C ON GOTO area2.event_scratch1 choice 38 | `0xA2F1 0x11 PRINT 'NORTH'` |
|  |  | `0xA2FC 0x11 PRINT 'SOUTH AND WEST'` |
|  |  | `0xA30E 0x11 PRINT 'SOUTHERN'` |
|  |  | `0xA31B 0x11 PRINT '   - SURFACE-WARD -'` |
|  |  | `0xA32D 0x33 PRINT RETURN` |
|  |  | `0xA32E 0x11 PRINT '- SUPPLY CONVEYOR, '` |
|  |  | `0xA347 0x11 PRINT 'UP -'` |
|  |  | `0xA34E 0x11 PRINT 'DOWN -'` |
| 0xA380 | 0x89E6 GOSUB 0xA380<br>0x8AD4 GOSUB 0xA380<br>0x8B09 GOSUB 0xA380 | `0xA380 0x12 PRINTCLEAR 'A VOICE BLARES OUT OF A SPEAKER. '` |

### ECL 50 - GEO 51: Venus Laboratory, Level 2

Attached still-missing strings:
- 0x8882: owner 0x882A; `branch_target_region` `HE CONTINUES,`. incoming: 0x826A ON GOTO area2.event_scratch1 choice 15
- 0x8F39: owner 0x8EF2; `branch_target_region` `MOVE CLOSER`. incoming: 0x826A ON GOTO area2.event_scratch1 choice 25

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x80C4 | entry vm_run_1 | `0x80DD 0x12 PRINTCLEAR 'RETURN TO THE MINES?'` |
| 0x81FD | 0x8146 GOTO 0x81FD<br>0x8156 GOTO 0x81FD<br>0x8166 GOTO 0x81FD<br>0x8176 GOTO 0x81FD<br>0x8186 GOTO 0x81FD<br>0x8196 GOTO 0x81FD<br>0x81AE GOTO 0x81FD<br>0x81BE GOTO 0x81FD<br>0x81CE GOTO 0x81FD<br>0x81DE GOTO 0x81FD | `0x8208 0x12 PRINTCLEAR 'YOU USE YOUR PASSKEY TO OPEN THE HYDRAULIC DOOR.'` |
| 0x8231 | 0x8204 GOTO 0x8231 | `0x8231 0x12 PRINTCLEAR "THIS HYDRAULIC DOOR WON'T OPEN."` |
| 0x830F | 0x826A ON GOTO area2.event_scratch1 choice 1 | `0x8317 0x12 PRINTCLEAR 'AN ELEVATOR GOING DOWN. DO YOU USE IT?'` |
| 0x83A3 | 0x826A ON GOTO area2.event_scratch1 choice 2 | `0x83A3 0x12 PRINTCLEAR 'YOU CAN CLIMB OUT OF THE LAB HERE. DO YOU?'` |
| 0x8409 | 0x826A ON GOTO area2.event_scratch1 choice 3 | `0x8411 0x12 PRINTCLEAR 'YOU FIND AN UP ELEVATOR. DO YOU USE IT?'` |
| 0x844F | 0x826A ON GOTO area2.event_scratch1 choice 4 | `0x845D 0x12 PRINTCLEAR 'ENTERING THE LAB COMPLEX, YOU FIND THE SOURCE OF THE EARTHQUAKE. AN EXPLOSION LARGE ENOUGH TO BLOW AWAY THE ROOF HAS EXPOSED THE VENUSIAN SKY.'` |
| 0x84DE | 0x8534 GOTO 0x84DE<br>0x8540 GOTO 0x84DE | `0x84DE 0x12 PRINTCLEAR 'THE BODIES OF '` |
|  |  | `0x84F0 0x11 PRINT ' SOLDIERS LIE HERE. THEY APPEAR TO HAVE BEEN CRUSHED BY ENORMOUS WEIGHTS.'` |
| 0x854C | 0x858F GOTO 0x854C | `0x854C 0x12 PRINTCLEAR 'YOU FIND DEAD LOWLANDER TECHNICIANS. THEIR BODIES ARE HORRIBLY CRUSHED.'` |
| 0x8696 | 0x826A ON GOTO area2.event_scratch1 choice 11 | `0x86A6 0x12 PRINTCLEAR "LEANDER SEES YOU. 'HURRY AND TURN OFF THE FIELD!'"` |
| 0x86D0 | 0x826A ON GOTO area2.event_scratch1 choice 12 | `0x86D8 0x12 PRINTCLEAR 'YOU STEP INTO THE GRAVITY FIELD!'` |
| 0x87C3 | 0x826A ON GOTO area2.event_scratch1 choice 14 | `0x87CB 0x12 PRINTCLEAR 'THE CONTROLS TO THE GRAVITY FIELD ARE HERE. DO YOU TURN IT OFF?'` |
| 0x882A | 0x826A ON GOTO area2.event_scratch1 choice 15 | `0x8840 0x12 PRINTCLEAR "LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'"` |
| 0x88F3 | 0x826A ON GOTO area2.event_scratch1 choice 16 | `0x88F3 0x12 PRINTCLEAR 'THE BODY OF A '` |
|  |  | `0x8905 0x11 PRINT ' SOLDIER LIES HERE. HE HAS BEEN KILLED BY LASER FIRE.'` |
| 0x8932 | 0x826A ON GOTO area2.event_scratch1 choice 17 | `0x894E 0x12 PRINTCLEAR 'YOU HEAR SOUNDS TO THE WEST. LEANDER SPEAKS.'` |
| 0x8BAE | 0x8BCF GOTO 0x8BAE | `0x8BAE 0x12 PRINTCLEAR 'THIS LAB HAS BEEN RANSACKED.'` |
| 0x8BD3 | 0x826A ON GOTO area2.event_scratch1 choice 21 | `0x8BDE 0x12 PRINTCLEAR 'YOU HEAR A COMMOTION FROM THE SOUTH.'` |
|  |  | `0x8C01 0x11 PRINT " LEANDER SAYS, 'WE SSTORE OUR DATA ARCHIVESS IN THERE.'"` |
| 0x8C39 | 0x826A ON GOTO area2.event_scratch1 choice 22 | `0x8C44 0x12 PRINTCLEAR 'YOU ENTER A DATA ARCHIVE. '` |
|  |  | `0x8C6A 0x11 PRINT ' FORCES ARE PUTTING COMPUTER DATA CAPSULES IN SACKS.'` |
| 0x968B | 0x9673 GOTO 0x968B<br>0x967F GOTO 0x968B | `0x968B 0x12 PRINTCLEAR 'VENUSIAN PLANT MATERIALS SIMMER IN LARGE VATS.'` |
| 0x96C6 | 0x96BA GOTO 0x96C6 | `0x96C6 0x12 PRINTCLEAR 'YOU LEAVE THE GRAVITOL FACTORY.'` |
| 0x9702 | 0x96EA GOTO 0x9702<br>0x96F6 GOTO 0x9702 | `0x9702 0x12 PRINTCLEAR 'MEDICINAL PROCESSING EQUIPMENT STANDS INACTIVE HERE.'` |
| 0x972D | 0x826A ON GOTO area2.event_scratch1 choice 38 | `0x9754 0x12 PRINTCLEAR 'YOU ENTER A ROOM FULL OF MEDICINAL PROCESSING EQUIPMENT. '` |
|  |  | `0x9786 0x11 PRINT ' SOLDIERS AIM THEIR GUNS AT LOWLANDERS LINED UP AGAINST THE WALL. '` |
| 0x9A35 | 0x9734 GOTO 0x9A35 | `0x9A40 0x12 PRINTCLEAR 'CRUMPLED AGAINST THE WALL LIE THE BODIES OF LOWLANDER TECHNICIANS. THEY HAVE BEEN SHOT THROUGH THE HEAD.'` |
| 0xA130 | 0x826A ON GOTO area2.event_scratch1 choice 41 | `0xA155 0x12 PRINTCLEAR "'WE CAN USE THIS PASSKEY TO OPEN THE HYDRAULIC DOOR AND AVOID THE INVADERS TO THE EAST!'"` |
| 0xA1BA | 0x826A ON GOTO area2.event_scratch1 choice 45 | `0xA1D4 0x12 PRINTCLEAR 'MERCURIANS CHARGE OUT OF THE ELEVATOR!'` |
| 0xA1F8 | 0x965D GOTO 0xA1F8<br>0xA1A2 GOTO 0xA1F8<br>0xA1AC GOTO 0xA1F8<br>0xA1B6 GOTO 0xA1F8 | `0xA20C 0x12 PRINTCLEAR 'YOU RUN INTO A MERCURIAN PATROL!'` |
| 0xA3A8 | 0x84EC GOSUB 0xA3A8<br>0x8901 GOSUB 0xA3A8<br>0x8C66 GOSUB 0xA3A8<br>0x9782 GOSUB 0xA3A8 | `0xA3B2 0x11 PRINT 'PURGE'` |
|  |  | `0xA3BA 0x11 PRINT 'TERRAN'` |

### ECL 64 - GEO 64: Luna Base

Attached still-missing strings:
- 0x824E: owner 0x8243; `branch_target_region` `COPERNICUS POLICE`. incoming: 0x8119 ON GOTO area2.event_scratch0 choice 5
- 0x8450: owner 0x8350; `branch_target_region` `HE CONTINUES,`. incoming: 0x8119 ON GOTO area2.event_scratch0 choice 7
- 0x9475: owner 0x946A; `branch_target_region` `GIOTTO MINING`. incoming: 0x8119 ON GOTO area2.event_scratch0 choice 33
- 0xA036: owner 0x9856; `branch_target_region` `WHO WILL TRY?`. incoming: 0x8AB7 GOTO 0x9856
- 0xA04E: owner 0x9856; `branch_target_region` `WHICH FILE?`. incoming: 0x8AB7 GOTO 0x9856
- 0xA39E: owner 0xA33C; `branch_target_region` `PREV`. incoming: 0x8D68 GOSUB 0xA33C; 0x916F GOSUB 0xA33C

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x808B | 0x80FB GOTO 0x808B | `0x808B 0x12 PRINTCLEAR 'THE AIRLOCK IS SEALED.'` |
| 0x80A0 | 0x8087 GOTO 0x80A0 | `0x80A5 0x12 PRINTCLEAR 'BLAST THE DOOR?'` |
| 0x819C | 0x8119 ON GOTO area2.event_scratch0 choice 2 | `0x81B0 0x12 PRINTCLEAR "AN OFFICIAL SAYS, 'YOUR SHIP IS IMPOUNDED. REPORT TO LT. JENNER. GO OUT AND DUE EAST.'"` |
| 0x81F6 | 0x8119 ON GOTO area2.event_scratch0 choice 4 | `0x820D 0x12 PRINTCLEAR 'YOU SPOT DR. COLDOR AHEAD.'` |
| 0x8262 | 0x8119 ON GOTO area2.event_scratch0 choice 6 | `0x8275 0x12 PRINTCLEAR "A GREY-SUITED MAN LOOKS UP. 'WHO ARE YOU HERE TO SEE?'"` |
| 0x82A1 |  | `0x82A1 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LT. JENNER', 'POLICE CHIEF'` |
| 0x82C8 | 0x8271 GOTO 0x82C8 | `0x82C8 0x12 PRINTCLEAR "A MAN SHOUTS, 'TERRORISTS!'"` |
| 0x82E4 | 0x82BC ON GOTO area2.event_scratch0 choice 0 | `0x82E4 0x12 PRINTCLEAR "'AH, YES. GO RIGHT AND STRAIGHT.'"` |
| 0x8302 | 0x82BC ON GOTO area2.event_scratch0 choice 1 | `0x8312 0x12 PRINTCLEAR "'HE'S BUSY. YOU'LL HAVE TO TRY LATER.'"` |
| 0x8333 | 0x830E GOTO 0x8333 | `0x8333 0x12 PRINTCLEAR "'THROUGH THE DOOR ON THE LEFT.'"` |
| 0x8350 | 0x8119 ON GOTO area2.event_scratch0 choice 7 | `0x8372 0x12 PRINTCLEAR "A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS."` |
| 0x8495 | 0x8365 GOTO 0x8495 | `0x84B0 0x12 PRINTCLEAR "JENNER LOOKS IRRITATED. 'I CANNOT HELP YOU ANYMORE. FULFILL THE BARGAIN.'"` |
| 0x84EB | 0x849C GOTO 0x84EB | `0x84EB 0x12 PRINTCLEAR "'COLDOR IS IN THE TSAI LABS. DEAL WITH HER HOW YOU WILL.'"` |
| 0x851B | 0x84AC GOTO 0x851B | `0x851B 0x12 PRINTCLEAR "'JUST GET A MEETING WITH THEM AND I WILL RAID IT.'"` |
| 0x8545 | 0x8357 GOTO 0x8545 | `0x8559 0x12 PRINTCLEAR 'JENNER LEAVES AS OTHERS RUSH IN.'` |
| 0x8579 | 0x8119 ON GOTO area2.event_scratch0 choice 8 | `0x8584 0x12 PRINTCLEAR "'YOU'RE IN THE WRONG OFFICE.'"` |
| 0x859E | 0x8580 GOTO 0x859E<br>0x85B9 GOTO 0x859E<br>0x866E GOTO 0x859E | `0x859E 0x12 PRINTCLEAR 'POLICE RUSH YOU.'` |
| 0x85B2 | 0x8119 ON GOTO area2.event_scratch0 choice 9 | `0x85C5 0x12 PRINTCLEAR 'A POLICEMAN STANDS BEFORE YOU. '` |
|  |  | `0x85F0 0x11 PRINT " 'CHIEF'S OFFICE IS TO THE LEFT.'"` |
| 0x860D | 0x85EC GOTO 0x860D | `0x860D 0x11 PRINT "'YOU'RE NOT ALLOWED HERE.' "` |
| 0x8667 | 0x8119 ON GOTO area2.event_scratch0 choice 10 | `0x8694 0x12 PRINTCLEAR "MCKAY LOOKS UP. 'ALL RIGHT, WHAT DO YOU WANT?'"` |
| 0x86BA |  | `0x86BA 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'A CUT', 'DR. COLDOR', 'POWER FOR NEO'` |
| 0x86EB | 0x867C GOTO 0x86EB<br>0x8690 GOTO 0x86EB | `0x86EB 0x12 PRINTCLEAR 'THE OFFICE IS EMPTY.'` |
| 0x8702 | 0x86DC ON GOTO area2.event_scratch0 choice 0 | `0x8702 0x12 PRINTCLEAR "'EXTORTION IS SO CRUDE."` |
| 0x871B | 0x86DC ON GOTO area2.event_scratch0 choice 1 | `0x871B 0x12 PRINTCLEAR "'HER WORK IS ESSENTIAL TO US."` |
| 0x8738 | 0x86DC ON GOTO area2.event_scratch0 choice 2 | `0x8738 0x12 PRINTCLEAR 'WE HAVE DONE SO MUCH ALREADY.'` |
| 0x8751 | 0x8717 GOTO 0x8751<br>0x8734 GOTO 0x8751 | `0x8751 0x11 PRINT " STILL, MEET ME AT KOI'S OFFICES. WE WILL DISCUSS IT.'"` |
| 0x8785 | 0x8119 ON GOTO area2.event_scratch0 choice 11 | `0x87AA 0x12 PRINTCLEAR 'YOU REACH DR. COLDOR AS SHE IS ABOUT TO ENTER A JET CAR. '` |
| 0x89C4 | 0x8119 ON GOTO area2.event_scratch0 choice 12 | `0x89D7 0x12 PRINTCLEAR 'THE STORE CONTAINS ROW AFTER ROW OF LUXURY GOODS AND FOODS.'` |
| 0x8A08 | 0x89D3 GOTO 0x8A08<br>0x8A6B GOTO 0x8A08<br>0x8EF2 GOTO 0x8A08 | `0x8A08 0x12 PRINTCLEAR 'PATRONS PANIC AND SCATTER AT YOUR APPROACH. POLICE ARRIVE.'` |
| 0x8A5C | 0x8119 ON GOTO area2.event_scratch0 choice 14 | `0x8A72 0x12 PRINTCLEAR "THE PROPRIETOR COMES UP. 'MAY I HELP YOU?'"` |
| 0x8AE2 | 0x8119 ON GOTO area2.event_scratch0 choice 17 | `0x8AFD 0x12 PRINTCLEAR "A YOUNG MAN LOOKS UP. 'I'M UDU, THE SENATOR'S ASSISTANT. MAY I HELP YOU?'"` |
| 0x8B37 |  | `0x8B37 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'LOOK AROUND', 'SEE SENATOR', 'NOTHING'` |
| 0x8B6A | 0x8AF1 GOTO 0x8B6A | `0x8B72 0x12 PRINTCLEAR 'PEOPLE FLEE AT YOUR APPROACH. POLICE SOON ARRIVE.'` |
| 0x8B9F | 0x8B5B ON GOTO area2.event_scratch0 choice 0 | `0x8BAD 0x12 PRINTCLEAR 'UDU IS FRIENDLY, BUT ADAMANTLY OPPOSES YOUR ENTRY. '` |
| 0x8BF6 | 0x8BA9 GOTO 0x8BF6 | `0x8BF6 0x12 PRINTCLEAR "WHEN YOU FLASH THE FORGED BADGE, UDU SAYS, 'FEEL FREE TO LOOK AROUND.'"` |
| 0x8C5D | 0x8B5B ON GOTO area2.event_scratch0 choice 1 | `0x8C5D 0x12 PRINTCLEAR "'THE SENATOR IS NOT IN JUST NOW. "` |
|  |  | `0x8C87 0x11 PRINT "YOU WILL HAVE TO TRY LATER.' "` |
| 0x8CBF | 0x8C83 GOTO 0x8CBF | `0x8CBF 0x11 PRINT "YOU MAY WAIT IN HIS OFFICE WHILE I TRY TO REACH HIM.'"` |
| 0x8CEC | 0x8119 ON GOTO area2.event_scratch0 choice 18 | `0x8D07 0x12 PRINTCLEAR 'YOU QUICKLY SEARCH THE OFFICE. '` |
|  |  | `0x8D30 0x11 PRINT 'YOU FIND ILLEGAL STOCK TRANSFERS LINKING THE SENATOR TO TSAI WEAPONRY.'` |
| 0x8D76 | 0x8D2C GOTO 0x8D76 | `0x8D76 0x11 PRINT 'YOU CANNOT FIND ANY INCRIMINATING EVIDENCE.'` |
| 0x8D9A | 0x8D72 GOTO 0x8D9A | `0x8DAE 0x12 PRINTCLEAR 'POLICE ARRIVE.'` |
| 0x8DC1 | 0x8DA2 GOTO 0x8DC1 | `0x8DC1 0x12 PRINTCLEAR "UDU ENTERS. 'I'M SORRY, BUT SENATOR KOI WILL NOT BE IN. LEAVE WHEN YOU WISH.'"` |
| 0x8DFF | 0x8CFB GOTO 0x8DFF | `0x8E07 0x12 PRINTCLEAR "KOI, MCKAY AND TSAI ARE SITTING HERE. KOI STATES, 'SO WHAT CAN WE DO TO KEEP YOU QUIET?'"` |
| 0x8EE3 | 0x8119 ON GOTO area2.event_scratch0 choice 20 | `0x8EF6 0x12 PRINTCLEAR 'THE BAR IS DIM AND HAZY. BLEARY EYED PATRONS SLUMP IN THEIR CHAIRS. DO YOU MINGLE?'` |
| 0x90B1 | 0x90DF GOTO 0x90B1 | `0x90B1 0x12 PRINTCLEAR 'THE HOUSE IS NICELY DECORATED. NO ONE IS HOME.'` |
| 0x90D8 | 0x90AD GOTO 0x90D8 | `0x90E3 0x12 PRINTCLEAR 'POLICE ARE HERE WAITING.'` |
| 0x90FD | 0x8119 ON GOTO area2.event_scratch0 choice 23 | `0x90FD 0x12 PRINTCLEAR 'THE STUDY CONTAINS A REAL MAHOGANY DESK.'` |
|  |  | `0x9139 0x11 PRINT ' YOU FIND A SECRET BANK BOOK, LISTING DOZENS OF PAYMENTS FROM TSAI.'` |
| 0x9184 | 0x8119 ON GOTO area2.event_scratch0 choice 24 | `0x9184 0x12 PRINTCLEAR 'THE ROBO-CHEF LOOKS DISUSED.'` |
| 0x91A1 | 0x8119 ON GOTO area2.event_scratch0 choice 25 | `0x91A1 0x12 PRINTCLEAR 'THE BED IS NEATLY MADE.'` |
| 0x91D8 | 0x8119 ON GOTO area2.event_scratch0 choice 27 | `0x91EB 0x12 PRINTCLEAR "TSAI'S HOUSE IS BUILT IN AN OPEN STYLE FILLED WITH OPULENT ARTWORK."` |
|  |  | `0x9232 0x12 PRINTCLEAR 'BENEATH A STATUE OF ATLAS YOU FIND A PRIVATE DIARY,'` |
| 0x92A7 | 0x93FF GOTO 0x92A7 | `0x92A7 0x12 PRINTCLEAR "AN OPERATOR GREETS YOU, 'GOOD DAY. DO YOU HAVE AUTHORIZATION?'"` |
| 0x93F8 | 0x92A3 GOTO 0x93F8 | `0x9403 0x12 PRINTCLEAR 'POLICE ARE WAITING FOR YOU.'` |
| 0x941F | 0x9298 GOTO 0x941F | `0x941F 0x12 PRINTCLEAR 'THE COMPUTER IS INOPERATIVE.'` |
| 0x9486 | 0x8119 ON GOTO area2.event_scratch0 choice 34 | `0x9499 0x12 PRINTCLEAR "A BURLY MINER STEPS UP. 'WATCHA WANT?'"` |
| 0x94B9 |  | `0x94B9 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'INFORMATION', 'DEMO CHARGES', 'NOTHING'` |
| 0x94EC | 0x94DD ON GOTO area2.event_scratch0 choice 0 | `0x94EC 0x12 PRINTCLEAR "'YOU WON'T GET IT.' HE STOMPS OFF."` |
| 0x950A | 0x94DD ON GOTO area2.event_scratch0 choice 1 | `0x9518 0x12 PRINTCLEAR "'HERE'S ALL WE CAN SPARE.'"` |
| 0x9547 | 0x9514 GOTO 0x9547 | `0x9547 0x12 PRINTCLEAR "'EVERYONE WOULD LIKE 'EM. YOU AIN'T GOT NO AUTHORITY SO BLAST OFF.' HE STOMPS OFF."` |
| 0x958A | 0x8119 ON GOTO area2.event_scratch0 choice 35 | `0x95A5 0x12 PRINTCLEAR 'A HEAVY SECURITY FORCE IS IN THE LOBBY.'` |
| 0x95CB | 0x95A1 GOTO 0x95CB | `0x95CB 0x12 PRINTCLEAR "A SECRETARY SITS BEHIND A HUGE DESK. 'WELCOME TO TSAI WEAPONRY. DO YOU HAVE AN APPOINTMENT?'"` |
| 0x9766 | 0x8119 ON GOTO area2.event_scratch0 choice 38 | `0x9766 0x12 PRINTCLEAR 'A LARGE PRIVATE OFFICE.'` |
|  |  | `0x9783 0x11 PRINT 'GUARDS RUSH IN.'` |
| 0x9797 | 0x8119 ON GOTO area2.event_scratch0 choice 39<br>0x97C2 GOTO 0x9797 | `0x9797 0x12 PRINTCLEAR 'A MEETING ROOM.'` |
|  |  | `0x97AE 0x11 PRINT 'GUARDS RUSH IN.'` |
| 0x9830 | 0x823F GOTO 0x9830<br>0x825E GOTO 0x9830<br>0x89C0 GOTO 0x9830<br>0x8A58 GOTO 0x9830<br>0x8ADE GOTO 0x9830<br>0x8EDF GOTO 0x9830<br>0x909A GOTO 0x9830<br>0x91D4 GOTO 0x9830<br>0x9282 GOTO 0x9830<br>0x9453 GOTO 0x9830<br>0x9482 GOTO 0x9830<br>0x9762 GOTO 0x9830 | `0x9830 0x12 PRINTCLEAR 'A SIGN ABOVE THE DOOR READS:'` |
|  |  | `0x9848 0x33 PRINT RETURN` |
|  |  | `0x9849 0x11 PRINT "'"` |
|  |  | `0x984D 0x11 PRINT '<string at scratch.word_0258>'` |
|  |  | `0x9851 0x11 PRINT "'"` |
| 0x9856 | 0x8AB7 GOTO 0x9856 | `0x9856 0x12 PRINTCLEAR 'THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?'` |
| 0xA320 | 0x86FD GOSUB 0xA320<br>0x9133 GOSUB 0xA320<br>0x919C GOSUB 0xA320<br>0x91B6 GOSUB 0xA320<br>0x922B GOSUB 0xA320 | `0xA320 0x11 PRINT ' A QUICK SEARCH REVEALS NOTHING.'` |
| 0xA33C | 0x8D68 GOSUB 0xA33C<br>0x916F GOSUB 0xA33C | `0xA33C 0x11 PRINT ' YOU HAVE THE EVIDENCE YOU NEED.'` |

### ECL 65 - GEO 65: Tsai Weaponry Labs

Attached still-missing strings:
- 0x8740: owner 0x861B; `branch_target_region` `SHE CONTINUES`. incoming: 0x83DA ON GOTO area2.event_scratch0 choice 0
- 0x9765: owner 0x9734; `branch_target_region` `WHO WILL TRY?`. incoming: 0x8464 GOTO 0x9734; 0x89B2 GOTO 0x9734

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8261 | 0x8251 GOTO 0x8261 | `0x8261 0x12 PRINTCLEAR 'THE DOOR HAS BEEN SEALED BY A SECURITY PROGRAM. '` |
| 0x8385 | 0x8224 GOTO 0x8385 | `0x8385 0x12 PRINTCLEAR 'THIS HEAVY DOOR IS BLAST PROOF. IT DOES NOT OPEN.'` |
| 0x8534 | 0x844B GOTO 0x8534<br>0x8459 GOTO 0x8534 | `0x855E 0x12 PRINTCLEAR 'YOU FIND THE REMAINS OF A SECURITY TEAM OVERCOME BY THE PLANTS.'` |
| 0x87F3 | 0x862D GOTO 0x87F3 | `0x8801 0x12 PRINTCLEAR 'YOU NOTICE A FEW DEMO CHARGES ON THE TABLE.'` |
| 0x8834 | 0x83DA ON GOTO area2.event_scratch0 choice 1 | `0x885C 0x12 PRINTCLEAR 'THE ROOM IS FILLED WITH RACKS OF ADVANCED ELECTRONIC EQUIPMENT.'` |
| 0x88E4 | 0x83DA ON GOTO area2.event_scratch0 choice 2 | `0x8905 0x12 PRINTCLEAR 'YOU FIND THE SECOND HUMMER PROTOTYPE ON A LAB TABLE.'` |
| 0x8940 | 0x8901 GOTO 0x8940 | `0x8940 0x12 PRINTCLEAR 'THIS LAB HAS SEEN RECENT USE AND IS IN TERRIBLE DISARRAY.'` |
| 0x8AC9 | 0x83DA ON GOTO area2.event_scratch0 choice 4 | `0x8ADD 0x12 PRINTCLEAR 'THE SECURITY OFFICE IS ABANDONED. CONTROLS WINK SILENTLY ON THE RIGHT WALL.'` |
| 0x8B1A | 0x83DA ON GOTO area2.event_scratch0 choice 5 | `0x8B25 0x12 PRINTCLEAR 'THIS IS THE SECURITY CONSOLE. THE DOORS CAN BE UNSEALED FROM HERE. DO YOU TRY TO OVERRIDE SECURITY?'` |
| 0x8BFF | 0x83DA ON GOTO area2.event_scratch0 choice 6 | `0x8C13 0x12 PRINTCLEAR 'YOU HAVE ENTERED THE MAIN CONTROL BUNKER. A MECHANICAL VOICE COUNTS DOWN.'` |
| 0x8C4E | 0x83DA ON GOTO area2.event_scratch0 choice 7 | `0x8C62 0x12 PRINTCLEAR 'BANKS OF CONTROLS LIE DORMANT ALONG THE WALLS.'` |
| 0x8C89 | 0x83DA ON GOTO area2.event_scratch0 choice 8 | `0x8C9D 0x12 PRINTCLEAR 'THE RECEPTION AREA IS ABANDONED.'` |
| 0x8CB9 | 0x83DA ON GOTO area2.event_scratch0 choice 9 | `0x8CCD 0x12 PRINTCLEAR 'CHAIRS AND PAPER ARE SCATTERED AROUND THIS MEETING ROOM.'` |
| 0x8CFB | 0x83DA ON GOTO area2.event_scratch0 choice 10 | `0x8D0C 0x12 PRINTCLEAR 'IN THE CENTER OF THE ROOM IS A SMALL SPACE CRAFT. PURGE COMMANDOS ARE LOADING THE LAST OF A STACK OF METAL CANISTERS.'` |
|  |  | `0x8D6E 0x11 PRINT ' OTHERS ARE IN THE RAFTERS, TRYING TO RETRACT THE DOME.'` |
| 0x9283 | 0x83DA ON GOTO area2.event_scratch0 choice 11 | `0x92AC 0x12 PRINTCLEAR 'THESE ARE THE ENVIRONMENTAL CONTROLS. FROM HERE YOU CAN REPROGRAM THE COMPUTER TO REFUSE TO OPEN THE SPACE PORT DOME OR TO SPRAY HERBICIDE THROUGHOUT THE COMPLEX. DO YOU TRY?'` |
| 0x937E | 0x92A8 GOTO 0x937E | `0x938C 0x12 PRINTCLEAR "YOU CAN END COMPUTER CONTROL OF THE PORT'S DOME. DO YOU TRY?"` |
| 0x9464 | 0x929D GOTO 0x9464 | `0x9472 0x12 PRINTCLEAR 'YOU CAN PROGRAM THE COMPUTER TO DOUSE THE COMPLEX WITH HERBICIDE. DO YOU TRY?'` |
| 0x95E0 | 0x83DA ON GOTO area2.event_scratch0 choice 19 | `0x95F4 0x12 PRINTCLEAR 'THE ROOM CONTAINS MANY EXPLOSIVES.'` |
| 0x9734 | 0x8464 GOTO 0x9734<br>0x89B2 GOTO 0x9734 | `0x9734 0x12 PRINTCLEAR 'THE SLUDGY REMAINS OF PLANT GENNIES POOL IN THE CORNERS.'` |

### ECL 66 - GEO 66: RAM Battler, Deimos Level 19-41

Attached still-missing strings:
- 0x8932: owner 0x8629; `branch_target_region` `DECLINE`. incoming: 0x83B9 GOTO 0x8629
- 0x8B57: owner 0x8A10; `branch_target_region` `HE CONTINUES`. incoming: 0x8235 ON GOTO area2.event_scratch0 choice 6
- 0x8B63: owner 0x8A10; `branch_target_region` `HIS OFFER`. incoming: 0x8235 ON GOTO area2.event_scratch0 choice 6
- 0x954B: owner 0x94DF; `branch_target_region` `DECLINE`. incoming: 0x8235 ON GOTO area2.event_scratch0 choice 17
- 0x9C01: owner 0x9B98; `branch_target_region` `WHO TRIES?`. incoming: 0x9B37 ON GOTO area2.event_scratch0 choice 3

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x815B | entry vm_run_1 | `0x8186 0x12 PRINTCLEAR 'THIS REINFORCED DOOR REQUIRES BOTH AN ACCESS CODE AND A RAM SECURITY CARD. TRY TO OVERRIDE THE DOOR?'` |
| 0x8283 | 0x8235 ON GOTO area2.event_scratch0 choice 1 | `0x8298 0x12 PRINTCLEAR 'THIS LADDER LEADS DOWN TO THE COMPUTER LEVEL.'` |
|  |  | `0x82BE 0x33 PRINT RETURN` |
|  |  | `0x82C0 0x33 PRINT RETURN` |
|  |  | `0x82C1 0x11 PRINT 'DO YOU DESCEND? '` |
| 0x82EF | 0x8235 ON GOTO area2.event_scratch0 choice 2 | `0x8304 0x12 PRINTCLEAR "THE COMPUTER BLARES, 'PROBABILITY OF VESSEL DESTRUCTION IS 99%. ADVISE IMMEDIATE EVACUATION.'"` |
|  |  | `0x834F 0x12 PRINTCLEAR "'AIR LOCK'"` |
|  |  | `0x835A 0x33 PRINT RETURN` |
|  |  | `0x835B 0x33 PRINT RETURN` |
|  |  | `0x835C 0x33 PRINT RETURN` |
|  |  | `0x835D 0x11 PRINT 'USE THE ESCAPE POD?'` |
| 0x83C1 | 0x82F6 GOTO 0x83C1 | `0x83C1 0x12 PRINTCLEAR 'A FIREBALL ENGULFS YOU AS THE SHIP EXPLODES.'` |
| 0x83FB | 0x8235 ON GOTO area2.event_scratch0 choice 3 | `0x8405 0x12 PRINTCLEAR 'THIS LADDER LEADS UP TO THE CONTROL LEVEL.'` |
|  |  | `0x8429 0x33 PRINT RETURN` |
|  |  | `0x842B 0x33 PRINT RETURN` |
|  |  | `0x842C 0x11 PRINT 'CLIMB UP? '` |
| 0x84E5 | 0x8235 ON GOTO area2.event_scratch0 choice 4<br>0x828A GOTO 0x84E5 | `0x84EB 0x12 PRINTCLEAR 'THE HEAT MAKES ACCESS TO THE LOWER LEVELS IMPOSSIBLE. YOU ARE FORCED BACK.'` |
| 0x852B | 0x8235 ON GOTO area2.event_scratch0 choice 5 | `0x8535 0x12 PRINTCLEAR 'SPARKS RAIN FROM THIS SHORTED PANEL.'` |
|  |  | `0x855E 0x12 PRINTCLEAR 'THE COMPUTER THROWS SPARKS. A SCREEN DISPLAYS SOARING RADIATION LEVELS. AS YOU WATCH, THE LINE RISES INTO THE CRITICAL AREA OF THE GRAPH.'` |
| 0x8629 | 0x83B9 GOTO 0x8629 | `0x862F 0x12 PRINTCLEAR "AS YOU ENTER THE ESCAPE POD, THE COMPUTER SAYS, 'LOSING ENERGY CONTAINMENT FIELD.'"` |
|  |  | `0x8670 0x33 PRINT RETURN` |
|  |  | `0x8671 0x33 PRINT RETURN` |
|  |  | `0x8672 0x11 PRINT 'THE AIR LOCK BEGINS CYCLING.'` |
| 0x8A10 | 0x8235 ON GOTO area2.event_scratch0 choice 6 | `0x8A13 0x12 PRINTCLEAR "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES."` |
| 0x8EB0 | 0x8235 ON GOTO area2.event_scratch0 choice 7 | `0x8ECA 0x12 PRINTCLEAR 'THERE IS A SHUFFLE ON THE OTHER SIDE OF THE PRISON DOOR. A VOICE WHISPERS, '` |
|  |  | `0x8F11 0x11 PRINT "'YOU'RE IN THE RAM BATTLER, DEIMOS. MY CODE NAME IS OILER. I'M WITH NEO. I NEED YOUR HELP.'"` |
| 0x8F7C | 0x8F0D GOTO 0x8F7C | `0x8F7C 0x11 PRINT "'KANE TOLD US TO EXPECT YOU. WE SMUGGLED IN YOUR WEAPONS. DON'T FORGET THE DEAL."` |
| 0x909C | 0x8235 ON GOTO area2.event_scratch0 choice 8 | `0x90A4 0x12 PRINTCLEAR 'THIS DOOR REQUIRES A RAM SECURITY PASSCARD. '` |
|  |  | `0x90CF 0x11 PRINT 'YOU DO NOT HAVE THE ONE IT REQUIRES.'` |
| 0x9198 | 0x8235 ON GOTO area2.event_scratch0 choice 10 | `0x91A6 0x12 PRINTCLEAR 'THIS AIRSHAFT LEADS DOWNWARD. DESCEND? '` |
| 0x91F1 | 0x8235 ON GOTO area2.event_scratch0 choice 11 | `0x91FF 0x12 PRINTCLEAR 'THIS SHAFT LEADS UPWARD. ASCEND? '` |
| 0x9291 | 0x8235 ON GOTO area2.event_scratch0 choice 12 | `0x9291 0x12 PRINTCLEAR 'YOU HAVE ENTERED AN ELEVATOR. A PANEL LIGHTS UP. '` |
| 0x92B9 |  | `0x92B9 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'PRIMARY REC', 'REC II', 'GUEST QTRS', 'EXIT'` |
| 0x92E6 |  | `0x92FF 0x12 PRINTCLEAR 'THE LIFT HUMS INTO ACTION SMOOTHLY, AND YOU ARRIVE AT YOUR FLOOR.'` |
| 0x9336 | 0x8235 ON GOTO area2.event_scratch0 choice 13 | `0x9340 0x12 PRINTCLEAR 'THIS ROOM IS EMPTY. IT LOOKS LIKE THE '` |
|  |  | `0x9360 0x11 PRINT "WOMEN'S LOCKER ROOM."` |
| 0x937C | 0x8235 ON GOTO area2.event_scratch0 choice 14 | `0x9386 0x12 PRINTCLEAR 'TOWELS ARE LUMPED AROUND IN DAMP PILES. THIS IS THE '` |
|  |  | `0x93B0 0x11 PRINT "MEN'S LOCKER ROOM"` |
| 0x93CB | 0x8235 ON GOTO area2.event_scratch0 choice 15 | `0x93D3 0x12 PRINTCLEAR "A COMPUTERIZED VOICE SAYS, 'THIS ROOM IS OCCUPIED.'"` |
| 0x940B | 0x8235 ON GOTO area2.event_scratch0 choice 16 | `0x9416 0x12 PRINTCLEAR 'YOU INTERRUPT TWO CREW MEMBERS AND THEIR GAME OF '` |
| 0x9444 |  | `0x9456 0x11 PRINT "GET OUT OF HERE!'"` |
|  |  | `0x9478 0x12 PRINTCLEAR 'YOU ARE SHOVED INTO THE HALLWAY.'` |
| 0x9602 | 0x8235 ON GOTO area2.event_scratch0 choice 18 | `0x9602 0x12 PRINTCLEAR 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.'` |
| 0x964D | 0x8235 ON GOTO area2.event_scratch0 choice 19 | `0x9658 0x12 PRINTCLEAR 'THIS ROOM OBVIOUSLY BELONGS TO SOMEONE OF HIGH RANK. A MAN IS SLEEPING ON THE WIDE BED. BESIDE HIM IS A RAM SECURITY CARD.'` |
| 0x96B7 |  | `0x96B7 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'WAKE MAN', 'TAKE CARD', 'LEAVE'` |
|  |  | `0x96D4 0x12 PRINTCLEAR ''` |
|  |  | `0x96F2 0x12 PRINTCLEAR 'YOU GRAB THE CARD, BUT THE MAN SITS UP. '` |
|  |  | `0x971A 0x11 PRINT 'HE BLINKS THE SLEEP OUT OF HIS EYES AND HITS AN ALARM BESIDE HIM.'` |
| 0x979D | 0x8235 ON GOTO area2.event_scratch0 choice 20 | `0x979D 0x12 PRINTCLEAR 'THIS DOOR REQUIRES A HIGH LEVEL RAM SECURITY CARD. TRY TO OPEN IT?'` |
| 0x98B6 | 0x8235 ON GOTO area2.event_scratch0 choice 21 | `0x98C1 0x12 PRINTCLEAR 'THIS DOOR REQUIRES A SECURITY CARD. USE THE CARD? '` |
| 0x9B4F | 0x9B37 ON GOTO area2.event_scratch0 choice 0 | `0x9B4F 0x12 PRINTCLEAR "THE COMPUTER WARNS, 'RADIATION LEVELS EXCEEDING CRITICAL. RECOMMEND IMMEDIATE EVACUATION.'"` |
| 0x9CCE | 0x9B37 ON GOTO area2.event_scratch0 choice 4 | `0x9CCE 0x12 PRINTCLEAR 'CREW MEMBERS IN EXERCISE OUTFITS PASS YOU. '` |
|  |  | `0x9D00 0x11 PRINT 'YOU HEAR ONE SAY, '` |
| 0x9D28 | 0x9B37 ON GOTO area2.event_scratch0 choice 5 | `0x9D30 0x12 PRINTCLEAR 'A DELEGATE WITH RAM BODYGUARDS PASSES YOU QUICKLY. '` |
|  |  | `0x9D61 0x11 PRINT 'A GUARD WINKS AT YOU BEFORE THE GROUP DISAPPEARS FROM SIGHT.'` |
| 0x9F3C | 0x92E6 ON GOSUB area2.event_scratch0 choice 3<br>0x9EF1 GOTO 0x9F3C<br>0x9F0E GOTO 0x9F3C<br>0x9F2B GOTO 0x9F3C | `0x9F42 0x12 PRINTCLEAR ''` |
| 0x9F46 | 0x9444 ON GOSUB area2.event_scratch0 choice 0 | `0x9F46 0x11 PRINT "HANDBALL. ONE SAYS 'ARE YOU DEAF? THE COMPUTER SAID THIS ROOM WAS OCCUPIED. "` |
| 0x9F83 | 0x9444 ON GOSUB area2.event_scratch0 choice 1 | `0x9F83 0x11 PRINT "HALF-SQUARES. 'EXCUSE ME, BUT THIS ROOM IS IN USE. "` |
| 0x9FAE | 0x9444 ON GOSUB area2.event_scratch0 choice 2 | `0x9FAE 0x11 PRINT "SQUASH. ONE THROWS DOWN HIS RACKET. 'WE'RE USING THIS ROOM. "` |
| 0x9FDF | 0x9444 ON GOSUB area2.event_scratch0 choice 3 | `0x9FDF 0x11 PRINT "RACQUETBALL. 'WE STILL HAVE AN HOUR RESERVAD. "` |
| 0xA084 | 0x9D17 ON GOSUB area2.event_scratch0 choice 0 | `0xA084 0x11 PRINT "'DID YOU HEAR WE CAPTURED SOME NEO AGENTS TRYING TO SET A BOMB ON LEVEL 16?'"` |
| 0xA0E2 | 0x9D17 ON GOSUB area2.event_scratch0 choice 1 | `0xA0E2 0x11 PRINT "'I CAN'T WAIT UNTIL THESE ARROGANT DIPLOMATS LEAVE. THEY'RE VERY DEMANDING.'"` |
| 0xA164 | 0x9D17 ON GOSUB area2.event_scratch0 choice 2 | `0xA164 0x11 PRINT "'I HEAR KILLER KANE IS BACK ON RAM'S BLACK LIST.'"` |
| 0xA18D | 0x9DA0 ON GOSUB area2.event_scratch0 choice 0 | `0xA18D 0x11 PRINT "YOU HEAR THE DELEGATE SAY, 'I TELL YOU, I FEAR FOR MY SAFETY ON THIS SHIP.'"` |
| 0xA1CA | 0x9DA0 ON GOSUB area2.event_scratch0 choice 1 | `0xA1CA 0x11 PRINT "THE DELEGATE SAYS TO ONE OF THE GUARDS, 'I JUST DON'T WANT THE SAME 'ACCIDENT' HAPPENING TO ME.'"` |
| 0xA216 | 0x9DA0 ON GOSUB area2.event_scratch0 choice 2 | `0xA216 0x11 PRINT "ONE GUARD MUTTERS UNDER HIS BREATH, 'IF KANE WANTS HIM DEAD, I'M NOT RISKING MY LIFE OVER IT.'"` |

### ECL 80 - GEO 80: Mars Prison, Level 1

Attached still-missing strings:
- 0x9674: owner 0x9608; `branch_target_region` `WILL SOMEONE TRY TO`. incoming: 0x9582 GOTO 0x9608
- 0x97E6: owner 0x9608; `branch_target_region` `CLOSE LINKS`. incoming: 0x9582 GOTO 0x9608
- 0x99D7: owner 0x9608; `branch_target_region` `HELP HIM`. incoming: 0x9582 GOTO 0x9608
- 0xA38E: owner 0xA345; `branch_target_region` `WHO WILL DO IT?`. incoming: 0x84A3 GOSUB 0xA345

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8102 | 0x80AE GOTO 0x8102 | `0x8128 0x12 PRINTCLEAR "FISTS WON'T OPEN THIS DOOR."` |
| 0x8148 | 0x8124 GOTO 0x8148 | `0x8152 0x12 PRINTCLEAR 'YOU BLOW THE DOOR OPEN.'` |
|  |  | `0x8183 0x12 PRINTCLEAR 'SEALED.'` |
| 0x8192 | 0x810E GOTO 0x8192 | `0x8192 0x12 PRINTCLEAR 'THROUGH THE GRILL, YOU SEE A GUARD ROBOT!'` |
| 0x8278 | 0x823D GOTO 0x8278 | `0x827D 0x12 PRINTCLEAR "IT'S BUCK ROGERS!"` |
| 0x8330 | 0x9570 GOTO 0x8330 | `0x833F 0x12 PRINTCLEAR 'THE CONSOLE IS DEAD.'` |
| 0x83AB |  | `0x83BA 0x12 PRINTCLEAR 'YOU HEAR DOG GENNIES!'` |
|  |  | `0x83D9 0x12 PRINTCLEAR 'THE DOGS MOVE OFF.'` |
|  |  | `0x83F3 0x12 PRINTCLEAR 'THE DOGS ATTACK.'` |
| 0x8427 | 0x83AB ON GOTO area1.event_word_234 choice 0<br>0x8457 GOTO 0x8427 | `0x8461 0x12 PRINTCLEAR 'THE MOB OF FELONS QUIETLY FOLLOWING YOU IS '` |
|  |  | `0x8486 0x11 PRINT 'QUITE LARGE.'` |
|  |  | `0x8493 0x11 PRINT 'GROWING.'` |
| 0x849D | 0x83AB ON GOTO area1.event_word_234 choice 2<br>0x843C GOTO 0x849D | `0x84AE 0x12 PRINTCLEAR 'A TOUGH PRISON GANG!'` |
|  |  | `0x84C1 0x12 PRINTCLEAR 'TWO CONVICTS.'` |
| 0x8626 | 0x84D5 GOTO 0x8626 | `0x8651 0x12 PRINTCLEAR 'YOU STOP WHEN THE FELONS ARE THOROUGHLY BEATEN.'` |
| 0x881D | 0x82E5 ON GOTO area1.event_word_206 choice 1 | `0x8856 0x12 PRINTCLEAR 'YOU STAND ON AN ENDLESS SANDY PLAIN.'` |
| 0x8930 | 0x882C GOTO 0x8930 | `0x8939 0x12 PRINTCLEAR 'YOU STUMBLE ACROSS A FIGURE SITTING ON THE SAND.'` |
| 0x8A1B | 0x8837 GOTO 0x8A1B | `0x8A24 0x12 PRINTCLEAR 'YOU STRUGGLE THROUGH THE DEEP SAND.'` |
| 0x8B4A | 0x8842 GOTO 0x8B4A | `0x8B59 0x12 PRINTCLEAR "ALL AT ONCE BUCK STOPS. 'THIS IS FUTILE.'"` |
| 0x90F8 | 0x82E5 ON GOTO area1.event_word_206 choice 2 | `0x90F8 0x12 PRINTCLEAR 'A HOLE HERE LEADS INTO AN ENVIROCELL. CLIMB DOWN?'` |
| 0x9142 | 0x82E5 ON GOTO area1.event_word_206 choice 4 | `0x914A 0x12 PRINTCLEAR "YOU BURST INTO THE PRISON'S SURVEILLANCE ROOM."` |
|  |  | `0x917A 0x11 PRINT ' IT IS EMPTY.'` |
|  |  | `0x9193 0x12 PRINTCLEAR "TECHNICIANS LOOK UP, ASTOUNDED. 'THEY ARE HERE! ALARM!'"` |
| 0x94BD | 0x83AB ON GOTO area1.event_word_234 choice 1 | `0x94BD 0x12 PRINTCLEAR 'THE PRISON AUTOSURGEONS FIND YOU.'` |
| 0x950A | 0x936D GOTO 0x950A | `0x9519 0x12 PRINTCLEAR 'THE HULK IS A LADDER TO THE HATCH ABOVE. GO UP?'` |
| 0x954B | 0x82E5 ON GOTO area1.event_word_206 choice 8 | `0x954B 0x12 PRINTCLEAR 'A HATCH. GO DOWN?'` |
| 0x9566 | 0x82E5 ON GOTO area1.event_word_206 choice 10 | `0x9586 0x12 PRINTCLEAR 'LIGHTS FLASH URGENTLY ON THE CONSOLE.'` |
|  |  | `0x95B9 0x11 PRINT ' THEN A VOICE CALLS,'` |
| 0x9608 | 0x9582 GOTO 0x9608 | `0x9608 0x12 PRINTCLEAR "SCOT SHRIEKS. 'DIGITAL SHARKS - EATING ME ALIVE!"` |
|  |  | `0x9636 0x11 PRINT ' SHUT ALL DATA CELLS!'` |
|  |  | `0x964A 0x11 PRINT ' HELP!'` |
|  |  | `0x9652 0x11 PRINT "'"` |
| 0x9C4B | 0x82E5 ON GOTO area1.event_word_206 choice 11 | `0x9C56 0x12 PRINTCLEAR 'CLIMB ABOARD THE NEO SHIP?'` |
| 0x9CAF | 0x82E5 ON GOTO area1.event_word_206 choice 12 | `0x9CD1 0x12 PRINTCLEAR 'BUCK AND NATBAKKA SLIP INTO THE POWER ROOM, WHILE YOU STAND GUARD.'` |
| 0x9DB5 | 0x82E5 ON GOTO area1.event_word_206 choice 14 | `0x9DB5 0x12 PRINTCLEAR 'WARRIOR BARRACKS'` |
|  |  | `0x9DDB 0x11 PRINT ' WITH WARRIORS!'` |
| 0x9E0C | 0x82E5 ON GOTO area1.event_word_206 choice 15 | `0x9E0C 0x12 PRINTCLEAR 'TECHNICIAN QUARTERS'` |
| 0x9E1E | 0x9DCE GOTO 0x9E1E | `0x9E1E 0x11 PRINT ', HASTILY ABANDONED.'` |
| 0x9E31 | 0x82E5 ON GOTO area1.event_word_206 choice 16 | `0x9E31 0x12 PRINTCLEAR 'THE EXHIBIT ROOM.'` |
|  |  | `0x9E56 0x12 PRINTCLEAR "IN A BIN MARKED 'EVIDENCE,' YOU FIND YOUR WEAPONS!"` |
| 0x9E94 | 0x82E5 ON GOTO area1.event_word_206 choice 17 | `0x9E94 0x12 PRINTCLEAR 'THE INTERROGATION ROOM.'` |
| 0x9F3D | 0x82E5 ON GOTO area1.event_word_206 choice 18 | `0x9F3D 0x12 PRINTCLEAR 'THE SECURE ROOM.'` |
| 0x9F8D | 0x82E5 ON GOTO area1.event_word_206 choice 19 | `0x9F8D 0x12 PRINTCLEAR 'DRAB WORKER BUNKS.'` |
| 0x9F9F | 0x82E5 ON GOTO area1.event_word_206 choice 20 | `0x9F9F 0x12 PRINTCLEAR 'THE COMM ROOM.'` |
|  |  | `0x9FB8 0x11 PRINT ' RAM TROOPS STORM OUT OF THE SOUTH!'` |
| 0xA1F9 | 0x82E5 ON GOTO area1.event_word_206 choice 21 | `0xA1F9 0x12 PRINTCLEAR 'A LANDING PAD.'` |
|  |  | `0xA212 0x11 PRINT ' A SLEEK NEO SHIP SITS IN THE CENTER, ENGINES SMOKING.'` |
| 0xA23F | 0x82E5 ON GOTO area1.event_word_206 choice 22 | `0xA23F 0x12 PRINTCLEAR 'THE POWER ROOM.'` |
| 0xA2A7 | 0x824C GOSUB 0xA2A7<br>0x8278 GOSUB 0xA2A7 | `0xA2A7 0x12 PRINTCLEAR 'A VOICE BOOMS OVER THE INTERCOM!'` |
| 0xA31E | 0x83CD GOSUB 0xA31E<br>0x84CE GOSUB 0xA31E | `0xA31E 0x33 PRINT RETURN` |

### ECL 81 - GEO 81: PURGE Headquarters, Floors Ground-Upper

Attached still-missing strings:
- 0x820C: owner 0x8149; `branch_target_region` `WHO TRIES?`. incoming: 0x8845 GOTO 0x8149
- 0x8463: owner 0x8426; `branch_target_region` `OPEN LOCKS`. incoming: 0x8401 GOTO 0x8426
- 0x9617: owner 0x955B; `branch_target_region` `HE CONTINUES`. incoming: 0x869F ON GOTO area2.event_scratch1 choice 24

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x810F | 0x8023 GOTO 0x810F | `0x8121 0x12 PRINTCLEAR '- GROUND FLOOR -'` |
| 0x8149 | 0x8845 GOTO 0x8149 | `0x8149 0x12 PRINTCLEAR 'YOU ENTER THE LOBBY OF PURGE HEADQUARTERS.'` |
|  |  | `0x8180 0x12 PRINTCLEAR 'A TERRAN WOMAN IN AN OLIVE GREEN UNIFORM LOOKS UP FROM HER DESK. '` |
|  |  | `0x81BF 0x33 PRINT RETURN` |
|  |  | `0x81C0 0x11 PRINT "SHE EYES YOU WARILY. 'DO YOU HAVE BUSINESS WITH US?'"` |
| 0x82C8 | 0x81BB GOTO 0x82C8 | `0x82C8 0x12 PRINTCLEAR "THE RECEPTIONIST TENSES. 'I DON'T KNOW WHO YOU THINK YOU ARE, BUT I KNOW HOW TO DEAL WITH YOU! GUARDS!'"` |
| 0x8406 | 0x836F GOTO 0x8406 | `0x8406 0x12 PRINTCLEAR 'DO YOU LEAVE PURGE HQ?'` |
| 0x8426 | 0x8401 GOTO 0x8426 | `0x8437 0x12 PRINTCLEAR 'THE DOOR IS SEALED. THE LOCK LOOKS TRICKY. '` |
| 0x84A6 | 0x8381 GOTO 0x84A6<br>0x8393 GOTO 0x84A6<br>0x83A5 GOTO 0x84A6 | `0x84BF 0x12 PRINTCLEAR 'YOU FACE A SECURITY DOOR. '` |
| 0x8611 | 0x83BC GOTO 0x8611 | `0x8611 0x12 PRINTCLEAR 'A LADDER GOING UP. DO YOU USE IT?'` |
| 0x8637 | 0x83D3 GOTO 0x8637 | `0x8637 0x12 PRINTCLEAR 'A LADDER GOING DOWN. DO YOU USE IT?'` |
| 0x865F | 0x83EA GOTO 0x865F | `0x865F 0x12 PRINTCLEAR "THE DOOR MARKED 'GENNIE'S ROOM' IS FAKE--SOMEBODY'S IDEA OF A JOKE."` |
| 0x8719 | 0x870B GOTO 0x8719 | `0x8738 0x12 PRINTCLEAR 'ROVING PURGE GUARDS ATTACK!'` |
| 0x8777 | 0x869F ON GOTO area2.event_scratch1 choice 1 | `0x8777 0x12 PRINTCLEAR 'AN ELEVATOR GOING UP. DO YOU USE IT?'` |
| 0x87E0 | 0x869F ON GOTO area2.event_scratch1 choice 3 | `0x87EB 0x12 PRINTCLEAR 'JANITORIAL SUPPLIES ARE STORED IN THIS ROOM.'` |
| 0x8819 | 0x869F ON GOTO area2.event_scratch1 choice 4 | `0x8821 0x12 PRINTCLEAR 'THE DOOR SLIDES SHUT BEHIND YOU.'` |
| 0x8849 | 0x869F ON GOTO area2.event_scratch1 choice 6 | `0x8851 0x12 PRINTCLEAR 'THE EMPLOYEE CAFETERIA. '` |
|  |  | `0x8875 0x11 PRINT 'IT IS EMPTY.'` |
|  |  | `0x8883 0x11 PRINT 'PURGE WORKERS AND GUARDS ARE EATING HERE. DO YOU ATTACK THEM?'` |
| 0x890A | 0x869F ON GOTO area2.event_scratch1 choice 7 | `0x8925 0x12 PRINTCLEAR 'YOU OVERHEAR TWO PURGE MEMBERS,'` |
| 0x8989 | 0x89E3 GOTO 0x8989 | `0x8989 0x12 PRINTCLEAR 'THIS AREA IS PARTITIONED INTO WORK CUBICLES. CLERKS RUSH AROUND, OBLIVIOUS TO YOUR PRESENCE.'` |
| 0x89E7 | 0x869F ON GOTO area2.event_scratch1 choice 10 | `0x89E7 0x12 PRINTCLEAR ''` |
|  |  | `0x89F2 0x11 PRINT "'WOMEN'S ROOM.'"` |
| 0x8A02 | 0x89EA GOSUB 0x8A02<br>0x8A2C GOSUB 0x8A02<br>0x8A4F GOSUB 0x8A02<br>0x9145 GOSUB 0x8A02 | `0x8A02 0x11 PRINT 'THE SIGN OVER THE'` |
| 0x8A13 | 0x89EE GOSUB 0x8A13<br>0x8A3A GOSUB 0x8A13<br>0x8A60 GOSUB 0x8A13<br>0x9153 GOSUB 0x8A13 | `0x8A13 0x11 PRINT ' DOOR READS, '` |
| 0x8A21 | 0x869F ON GOTO area2.event_scratch1 choice 11 | `0x8A29 0x12 PRINTCLEAR ''` |
|  |  | `0x8A30 0x11 PRINT ' SOUTHERN'` |
|  |  | `0x8A3E 0x11 PRINT "'MEN'S ROOM,' AND "` |
|  |  | `0x8A53 0x11 PRINT ' EASTERN DOOR'` |
|  |  | `0x8A64 0x11 PRINT "'GENNIE'S ROOM'"` |
| 0x8A81 | 0x869F ON GOTO area2.event_scratch1 choice 13 | `0x8A94 0x12 PRINTCLEAR "A UNIFORMED MAN SITS AT HIS COMPUTER. HE SPEAKS TO YOU OVER HIS BACK. 'I'M SORRY, COMMANDER SOOTH IS NOT IN RIGHT NOW...' HE TURNS AROUND."` |
| 0x8B56 | 0x869F ON GOTO area2.event_scratch1 choice 14 | `0x8B5E 0x12 PRINTCLEAR "YOU ENTER HANIBL SOOTH'S OFFICE. THE ONLY FURNITURE IS THE DESK ACROSS THE ROOM."` |
| 0x8B9F | 0x869F ON GOTO area2.event_scratch1 choice 15 | `0x8BAD 0x12 PRINTCLEAR 'YOU FIND A LETTER'` |
| 0x8BCD | 0x8BA9 GOTO 0x8BCD | `0x8BCD 0x12 PRINTCLEAR 'OVER THE DESK IS A MONITOR.'` |
|  |  | `0x8BEC 0x11 PRINT ' ITS SCREEN IS BLANK.'` |
| 0x8D28 | 0x869F ON GOTO area2.event_scratch1 choice 16 | `0x8D3B 0x12 PRINTCLEAR 'IN THIS CONFERENCE ROOM, A MEETING IS IN PROGRESS. PURGE MEMBERS SIT AROUND A TABLE. '` |
| 0x8EEB | 0x869F ON GOTO area2.event_scratch1 choice 17 | `0x8EF3 0x12 PRINTCLEAR 'A PRINTING PRESS IS HERE'` |
|  |  | `0x8F12 0x11 PRINT '.'` |
|  |  | `0x8F18 0x11 PRINT ' CHURNING OUT A STACK OF BROCHURES. YOU TAKE A COPY '` |
| 0x8F53 | 0x869F ON GOTO area2.event_scratch1 choice 18 | `0x8F5B 0x12 PRINTCLEAR 'BOXES OF BUTTONS AND STICKERS ARE STORED HERE.'` |
| 0x8F82 | 0x869F ON GOTO area2.event_scratch1 choice 19 | `0x8F8A 0x12 PRINTCLEAR 'A COMBAT TRAINING ROOM WITH A PADDED FLOOR. IT IS EMPTY.'` |
| 0x913A | 0x869F ON GOTO area2.event_scratch1 choice 21 | `0x9142 0x12 PRINTCLEAR ''` |
|  |  | `0x9149 0x11 PRINT ' SOUTHERN'` |
|  |  | `0x9157 0x11 PRINT "'HOLDING CELLS'"` |
| 0x9167 | 0x869F ON GOTO area2.event_scratch1 choice 22<br>0x8FCA GOTO 0x9167 | `0x9167 0x12 PRINTCLEAR 'THIS CELL IS EMPTY.'` |
| 0x917A | 0x869F ON GOTO area2.event_scratch1 choice 23 | `0x9196 0x12 PRINTCLEAR 'YOU ENTER A ROOM FULL OF COMPUTER AND COMMUNICATIONS EQUIPMENT. PURGE MEMBERS RUSH ABOUT, WHILE OTHERS SIT AT CONTROL CONSOLES.'` |
| 0x955B | 0x869F ON GOTO area2.event_scratch1 choice 24 | `0x9585 0x12 PRINTCLEAR "AN EMACIATED MAN IN A TATTERED LAB COAT APPROACHES. IT'S DR. ROMNEY!"` |
| 0x9639 | 0x9581 GOTO 0x9639 | `0x9639 0x12 PRINTCLEAR 'DR. ROMNEY MEETS YOU IN THE HALL.'` |
| 0x96CD | 0x96BF GOTO 0x96CD | `0x96EE 0x12 PRINTCLEAR 'A PURGE FUNCTIONARY'` |
|  |  | `0x9701 0x12 PRINTCLEAR 'AN OFFICE WORKER'` |
|  |  | `0x9710 0x11 PRINT ' PASSES YOU BY.'` |

### ECL 82 - GEO 82: NEO Installation

Attached still-missing strings:
- 0x82E3: owner 0x82AA; `branch_target_region` `WILBUR`. incoming: 0x81CB GOTO 0x82AA
- 0x8D0F: owner 0x8CB5; `prompt_or_menu_region` `ELROY`. incoming: 0x8CD0 GOTO 0x8CB5
- 0x9124: owner 0x90C7; `branch_target_region` `WHO WILL TRY?`. incoming: 0x84B3 ON GOTO area2.event_scratch1 choice 18
- 0x9161: owner 0x90C7; `branch_target_region` `WILBUR`. incoming: 0x84B3 ON GOTO area2.event_scratch1 choice 18
- 0x9329: owner 0x92B7; `branch_target_region` `WHO WILL TRY?`. incoming: 0x921F GOTO 0x92B7

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x822C | 0x812A GOTO 0x822C<br>0x816F GOTO 0x822C | `0x823A 0x12 PRINTCLEAR 'THIS IS A CODE 1 SECURITY DOOR.'` |
| 0x8256 | 0x8141 GOTO 0x8256<br>0x8158 GOTO 0x8256<br>0x8186 GOTO 0x8256 | `0x8264 0x12 PRINTCLEAR 'THIS IS A CODE 3 SECURITY DOOR.'` |
| 0x8280 | 0x819D GOTO 0x8280<br>0x81B4 GOTO 0x8280 | `0x828E 0x12 PRINTCLEAR 'THIS IS A CODE 4 SECURITY DOOR.'` |
| 0x82AA | 0x81CB GOTO 0x82AA | `0x82AA 0x12 PRINTCLEAR 'A GUARD STEPS UP AND ASKS FOR A PASSWORD. WHAT DO YOU SAY?'` |
| 0x8310 | 0x83A8 GOTO 0x8310<br>0x83F1 GOTO 0x8310 | `0x8310 0x12 PRINTCLEAR 'THE GUARD LETS YOU THROUGH.'` |
| 0x833F | 0x8331 GOTO 0x833F | `0x834A 0x12 PRINTCLEAR "A FRANTIC GUARD RUSHES UP. 'THE COMPUTER CAN SHUT AIRLOCK 2, BUT I DON'T KNOW HOW.'"` |
| 0x83B6 | 0x833B GOTO 0x83B6<br>0x83B2 GOTO 0x83B6<br>0x83FB GOTO 0x83B6 | `0x83B6 0x12 PRINTCLEAR 'GUARDS BLOCK THE ENTRANCE.'` |
| 0x83FF | 0x83D9 GOTO 0x83FF | `0x8415 0x12 PRINTCLEAR "A GUARD APPROACHES 'RESCUE THE PEOPLE IN THE DANCE HALL ON LEVEL 3."` |
|  |  | `0x845E 0x11 PRINT "'"` |
|  |  | `0x8464 0x11 PRINT " THEN GO TO THE COMPUTER ON LEVEL 4 AND SHUT AIRLOCK 2. THAT SHOULD HOLD RAM A WHILE.'"` |
| 0x8593 | 0x857B GOTO 0x8593 | `0x8593 0x12 PRINTCLEAR "'"` |
|  |  | `0x8597 0x11 PRINT area1.event_word_20C` |
|  |  | `0x859B 0x11 PRINT "'"` |
| 0x85A9 | 0x8570 GOTO 0x85A9 | `0x85A9 0x12 PRINTCLEAR 'THE BASE ERUPTS IN FLAME!'` |
| 0x867D | 0x84B3 ON GOTO area2.event_scratch1 choice 2 | `0x867D 0x12 PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?'` |
| 0x87DF | 0x84B3 ON GOTO area2.event_scratch1 choice 3 | `0x87FB 0x12 PRINTCLEAR "YOU FIND A BADLY INJURED MAN IN THE CORNER OF THE ROOM. 'PLEASE TAKE MY ARMOR... PUT IT TO GOOD USE.'"` |
| 0x8855 | 0x84B3 ON GOTO area2.event_scratch1 choice 4 | `0x8874 0x12 PRINTCLEAR "A MAN WALKS UP. 'I HEARD ABOUT YOUR CONVERSATION WITH DR. HAMPSHIRE. THIS WEAPON MAY HELP YOUR INQUIRIES.'"` |
| 0x88D2 | 0x84B3 ON GOTO area2.event_scratch1 choice 5 | `0x88E0 0x12 PRINTCLEAR "A VOLUBLE, BESPECKLED MAN GREETS YOU ENTHUSIASTICALLY. 'WHAT DO YOU HAVE WITH YOU. HMM, NON-NEO DESIGN. SEE DR. HAMPSHIRE, HE'S AN EXPERT IN ELECTRONICS.'"` |
| 0x8962 | 0x88DC GOTO 0x8962 | `0x8962 0x12 PRINTCLEAR "'I AM BUSY RIGHT NOW.'"` |
| 0x8978 | 0x84B3 ON GOTO area2.event_scratch1 choice 6 | `0x898B 0x12 PRINTCLEAR 'YOU FIND A SET OF CODE 4 CARDS.'` |
| 0x89AE | 0x84B3 ON GOTO area2.event_scratch1 choice 9 | `0x89BC 0x12 PRINTCLEAR "AN ELDERLY FELLOW RISES AT YOUR APPROACH. 'I AM DR. HAMPSHIRE. LET ME SEE THE DEVICE.'"` |
| 0x8AEB | 0x89B8 GOTO 0x8AEB | `0x8AEB 0x12 PRINTCLEAR "'I ALREADY TOLD YOU EVERYTHING I KNOW.'"` |
| 0x8B0E | 0x84B3 ON GOTO area2.event_scratch1 choice 10 | `0x8B19 0x12 PRINTCLEAR "YOU ENTER A CLUTTERED ROOM. YOU SEE A NAMETAG THAT SAYS 'ZACHARY CEBERT'."` |
| 0x8C22 | 0x84B3 ON GOTO area2.event_scratch1 choice 11 | `0x8C4E 0x12 PRINTCLEAR 'THIS IS THE MENS ROOM. A MAN WALKS UP TO YOU AND SPEAKS..'` |
|  |  | `0x8C7C 0x33 PRINT RETURN` |
|  |  | `0x8C7D 0x11 PRINT "'ARE YOU ZACHARY?'"` |
| 0x8C8E |  | `0x8C8E 0x2B HORIZONTAL MENU area2.event_scratch0 = <selected index from menu> MENU: 'FAST TALK', 'TELL THE TRUTH'` |
| 0x8CB5 | 0x8CD0 GOTO 0x8CB5 | `0x8CB5 0x39 WHO <select player> 'WHO MAKES THE ATTEMPT?'` |
|  |  | `0x8CF4 0x12 PRINTCLEAR "'TELL US THE WORD:'"` |
| 0x8DD1 | 0x8CB1 GOTO 0x8DD1<br>0x8CF0 GOTO 0x8DD1<br>0x8D17 GOTO 0x8DD1 | `0x8DD1 0x12 PRINTCLEAR 'THE MAN IS JOINED BY OTHERS FROM THE STALLS.'` |
| 0x8F70 | 0x84B3 ON GOTO area2.event_scratch1 choice 14 | `0x8F7B 0x12 PRINTCLEAR 'THIS IS THE DANCE HALL.'` |
| 0x8F92 | 0x8F77 GOTO 0x8F92 | `0x8F9D 0x12 PRINTCLEAR "A CROWD OF CIVILIANS IS HUDDLED BEHIND THE PLAYER PIANO. ONE CRIES, 'THANK GOD YOU'VE COME! YOU MUST ESCORT US TO AIRLOCK 1.' THE CROWD FORMS A RAGGED PACK BEHIND YOU."` |
| 0x9029 | 0x84B3 ON GOTO area2.event_scratch1 choice 16 | `0x903F 0x12 PRINTCLEAR 'ZACHARY IS HERE PROTECTED BY A RAM INFILTRATION TEAM.'` |
| 0x90C7 | 0x84B3 ON GOTO area2.event_scratch1 choice 18 | `0x90E8 0x12 PRINTCLEAR 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?'` |
| 0x91E5 | 0x90D1 GOTO 0x91E5 | `0x91F0 0x12 PRINTCLEAR 'THE COMPUTER ASKS FOR A PASSWORD:'` |
| 0x92B7 | 0x921F GOTO 0x92B7 | `0x92B7 0x12 PRINTCLEAR "'PASSWORD IS INCORRECT FOR DESIRED TASK. SECURITY HAS BEEN INFORMED.'"` |
|  |  | `0x92EE 0x33 PRINT RETURN` |
|  |  | `0x92EF 0x12 PRINTCLEAR 'YOU NOTE A SUBROUTINE CONTAINING PASSWORDS. DO YOU TRY TO ACCESS?'` |
| 0x9385 | 0x84B3 ON GOTO area2.event_scratch1 choice 15 | `0x939E 0x12 PRINTCLEAR "MR. FREDRICKSON LOOKS UP. 'IT TOOK SOME TIME FOR YOUR FILES TO BE TRANSFERRED FROM SALVATION. FOR NOW, HERE ARE LEVEL 1 SECURITY PASSES. I'LL GET YOU BETTER ONES WHEN THE PAPERWORK COMES THROUGH."` |
| 0x946A | 0x938F GOTO 0x946A | `0x9478 0x12 PRINTCLEAR "THE DIRECTOR LOOKS UP. 'SECURITY HAS COMPLETED THE NECESSARY FORMS TO GRANT YOU CODE 3 PASSCARDS."` |
| 0x9537 | 0x9474 GOTO 0x9537 | `0x9553 0x12 PRINTCLEAR "THE DIRECTOR LOOKS WORRIED. 'DR. HAMPSHIRE EXPLAINED WHAT YOU DISCOVERED. INVESTIGATE CREWMAN CEBERT SOME MORE. HE MAY BE ONLY THE TIP OF A CONSPIRACY. RETURN IF MORE EVIDENCE TURNS UP. GOOD DAY.'"` |
| 0x95F4 | 0x9541 GOTO 0x95F4 | `0x960A 0x12 PRINTCLEAR "THE DIRECTOR SHUTS OFF HIS VIDPHONE AS YOU ENTER. 'I HEARD YOU HAD NEW INFORMATION. I ALSO AM GETTING UNUSUAL REPORTS FROM EXTERNAL SECURITY. SOMETHING IS ABOUT TO HAPPEN."` |
| 0x9856 | 0x939A GOTO 0x9856<br>0x954F GOTO 0x9856<br>0x95FE GOTO 0x9856 | `0x9856 0x12 PRINTCLEAR "MR. FREDRICKSON GETS UP. 'I'M SORRY, BUT NO NEW WORD ON YOUR PAPERWORK."` |
| 0x9891 | 0x84B3 ON GOTO area2.event_scratch1 choice 19 | `0x98AA 0x12 PRINTCLEAR 'YOU PUT ZACHARY IN THE JAIL.'` |
| 0x98CD | 0x989B GOTO 0x98CD | `0x98CD 0x12 PRINTCLEAR 'AN EMPTY CELL.'` |
| 0x9988 | 0x84B3 ON GOTO area2.event_scratch1 choice 23 | `0x9990 0x12 PRINTCLEAR 'AIRLOCK 1 IS BEFORE YOU.'` |
| 0x99A7 | 0x84B3 ON GOTO area2.event_scratch1 choice 28 | `0x99A7 0x12 PRINTCLEAR 'THIS IS A CREW CABIN.'` |
| 0x99BB | 0x84B3 ON GOTO area2.event_scratch1 choice 31 | `0x99BB 0x12 PRINTCLEAR 'THIS IS THE GUEST QUARTERS.'` |
| 0x99EC | 0x99E8 GOTO 0x99EC<br>0x9A0E GOTO 0x99EC<br>0x9A1C GOTO 0x99EC | `0x99EC 0x12 PRINTCLEAR "A SIGN READS, 'AIRLOCK 2.'"` |
| 0x9A04 | 0x99E4 GOTO 0x9A04 | `0x9A20 0x12 PRINTCLEAR 'RAM FORCES ATTACK!'` |
| 0x9B23 | 0x84B3 ON GOTO area2.event_scratch1 choice 38 | `0x9B2E 0x12 PRINTCLEAR 'THERE IS A LOT OF JUNK HERE. DO YOU WISH TO SEARCH?'` |
| 0x9C15 | 0x84B3 ON GOTO area2.event_scratch1 choice 27 | `0x9C20 0x12 PRINTCLEAR 'YOU SPOT THE SPY THAT ESCAPED! HE AND OTHERS ATTACK!'` |
| 0x9CB3 | 0x9C97 GOTO 0x9CB3 | `0x9CC6 0x12 PRINTCLEAR "A GUARD APPROACHES. 'OUR SENSORS HAVE DETECTED UNUSUAL MAGNETIC READINGS FROM THE BASEMENT. THEY MAY BE INVOLVED IN YOUR INVESTIGATION. PLEASE KEEP THE DIRECTOR INFORMED OF ANY PROGRESS.'"` |
| 0x9D61 | 0x84B3 ON GOTO area2.event_scratch1 choice 7 | `0x9D7D 0x12 PRINTCLEAR "THE WARRIOR QUICKLY PULLS THE COVER FROM THE CONTROLS. 'DARN! I CAN'T BYPASS ALL THE CODES WITH THE DIRECTOR DEAD."` |
| 0x9E5F | 0x9D6B GOTO 0x9E5F<br>0x9D79 GOTO 0x9E5F | `0x9E5F 0x12 PRINTCLEAR "THE SIGN ABOVE THE COMPUTER READS 'SECONDARY COMPUTER CONTROL.'"` |
| 0x9EEA | 0x9E9E GOTO 0x9EEA | `0x9EEA 0x12 PRINTCLEAR 'THIS IS THE EMERGENCY HATCH.'` |
| 0x9F03 | 0x84B3 ON GOTO area2.event_scratch1 choice 33 | `0x9F19 0x12 PRINTCLEAR "THE SECURITY CHIEF GREETS YOU. 'ONE OF MY MEN NOTED SOMEONE SUSPICIOUS ON THE CABIN LEVEL, BUT HE LOST THE MAN. YOU MIGHT WANT TO FOLLOW UP.'"` |

### ECL 84 - GEO 84: Mars Prison, Level 2

Attached still-missing strings:
- 0x8350: owner 0x82F2; `branch_target_region` `WHO TRIES?`. incoming: 0x8070 ON GOTO area2.event_scratch1 choice 3
- 0x8880: owner 0x8811; `branch_target_region` `WHO TRIES?`. incoming: 0x8070 ON GOTO area2.event_scratch1 choice 7; 0x80CE ON GOTO area2.event_scratch1 choice 7
- 0x8BED: owner 0x8921; `branch_target_region` `KILL HIM`. incoming: 0x8070 ON GOTO area2.event_scratch1 choice 9
- 0x9A0B: owner 0x99E0; `branch_target_region` `WHO TRIES?`. incoming: 0x9872 GOTO 0x99E0
- 0x9A8B: owner 0x99E0; `branch_target_region` `SEE FILES`. incoming: 0x9872 GOTO 0x99E0
- 0x9B0F: owner 0x99E0; `branch_target_region` `SEE FILES`. incoming: 0x9872 GOTO 0x99E0
- 0x9B7B: owner 0x99E0; `branch_target_region` `SEE FILES`. incoming: 0x9872 GOTO 0x99E0
- 0x9BE6: owner 0x99E0; `branch_target_region` `SEE FILES`. incoming: 0x9872 GOTO 0x99E0

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8014 | entry ecl_initial_entry | `0x8034 0x12 PRINTCLEAR '- SECOND FLOOR -'` |
|  |  | `0x8043 0x33 PRINT RETURN` |
|  |  | `0x8044 0x11 PRINT '- LABORATORIES -'` |
| 0x813F | 0x8131 GOTO 0x813F | `0x8161 0x12 PRINTCLEAR 'ROVING PURGE GUARDS ATTACK!'` |
| 0x81A0 | 0x8154 GOTO 0x81A0 | `0x81B1 0x12 PRINTCLEAR 'A WANDERING GROUP OF PURGE SCIENTISTS ATTACKS!'` |
| 0x81F0 | 0x8070 ON GOTO area2.event_scratch1 choice 1<br>0x80CE ON GOTO area2.event_scratch1 choice 1 | `0x81F0 0x12 PRINTCLEAR 'AN ELEVATOR GOING DOWN. DO YOU USE IT?'` |
| 0x8272 | 0x8070 ON GOTO area2.event_scratch1 choice 2 | `0x827A 0x12 PRINTCLEAR 'AN EMPTY COMPUTER LAB. '` |
|  |  | `0x82BC 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x82C0 0x11 PRINT ' NOTICES THAT A COMPUTER AT THE SOUTH END OF THE ROOM IS ON.'` |
| 0x82F2 | 0x8070 ON GOTO area2.event_scratch1 choice 3 | `0x830E 0x12 PRINTCLEAR 'THE TERMINAL OF THIS COMPUTER IS ACTIVE. DO YOU TRY TO OPERATE THE COMPUTER?'` |
| 0x839D | 0x830A GOTO 0x839D | `0x839D 0x12 PRINTCLEAR 'THE COMPUTER SCREEN READS:'` |
|  |  | `0x83B4 0x33 PRINT RETURN` |
|  |  | `0x83B5 0x33 PRINT RETURN` |
|  |  | `0x83B6 0x11 PRINT '- RUN CURRENT SEQUENCE? -'` |
|  |  | `0x83CC 0x33 PRINT RETURN` |
|  |  | `0x83CD 0x33 PRINT RETURN` |
|  |  | `0x83CE 0x33 PRINT RETURN` |
| 0x84D1 | 0x82FC GOTO 0x84D1 | `0x84D1 0x12 PRINTCLEAR 'THE COMPUTER IS OFF.'` |
| 0x84E4 | 0x8070 ON GOTO area2.event_scratch1 choice 4<br>0x80CE ON GOTO area2.event_scratch1 choice 4 | `0x84EC 0x12 PRINTCLEAR 'A WEAPONS LABORATORY. '` |
| 0x8778 | 0x8070 ON GOTO area2.event_scratch1 choice 5<br>0x80CE ON GOTO area2.event_scratch1 choice 5 | `0x8783 0x12 PRINTCLEAR "SEARCHING THE LAB, YOU FIND SKETCHES OF A GUN TITLED, 'RAPID-LOADING BOLT GUN.'"` |
| 0x87CC | 0x8070 ON GOTO area2.event_scratch1 choice 6<br>0x80CE ON GOTO area2.event_scratch1 choice 6 | `0x87D4 0x12 PRINTCLEAR 'A WEAPONS LABORATORY. NO ONE IS HERE. SMALL PARTS LIE ON TABLES EVERYWHERE.'` |
| 0x8811 | 0x8070 ON GOTO area2.event_scratch1 choice 7<br>0x80CE ON GOTO area2.event_scratch1 choice 7 | `0x881C 0x12 PRINTCLEAR 'SEARCHING THE LAB, YOU FIND PARTS OF A DISMANTLED LASER RIFLE.'` |
| 0x8905 | 0x8070 ON GOTO area2.event_scratch1 choice 8<br>0x80CE ON GOTO area2.event_scratch1 choice 8 | `0x890D 0x12 PRINTCLEAR 'AN EMPTY PHYSICS LAB.'` |
| 0x8921 | 0x8070 ON GOTO area2.event_scratch1 choice 9 | `0x8929 0x12 PRINTCLEAR 'A CHEMISTRY LAB. '` |
|  |  | `0x8944 0x11 PRINT 'A PURGE SCIENTIST IS WORKING AT THE FAR END OF THE ROOM.'` |
|  |  | `0x8971 0x33 PRINT RETURN` |
| 0x8C77 | 0x8070 ON GOTO area2.event_scratch1 choice 10<br>0x80CE ON GOTO area2.event_scratch1 choice 10 | `0x8C7F 0x12 PRINTCLEAR 'AN EMPTY BOTANY LAB.'` |
| 0x8C92 | 0x8070 ON GOTO area2.event_scratch1 choice 11<br>0x80CE ON GOTO area2.event_scratch1 choice 11 | `0x8C9A 0x12 PRINTCLEAR 'AN EMPTY BIOLOGY LAB.'` |
| 0x8CAE | 0x8070 ON GOTO area2.event_scratch1 choice 12 | `0x8CB6 0x12 PRINTCLEAR 'A MEDIA LAB.'` |
|  |  | `0x8CCD 0x11 PRINT ' PURGE SCIENTISTS ARE GATHERED AROUND A TABLE. '` |
| 0x8E99 | 0x8070 ON GOTO area2.event_scratch1 choice 13<br>0x80CE ON GOTO area2.event_scratch1 choice 13 | `0x8EA1 0x12 PRINTCLEAR 'AUDIO AND VIDEO CAPSULES ARE STORED HERE.'` |
| 0x8EC4 | 0x8070 ON GOTO area2.event_scratch1 choice 14<br>0x80CE ON GOTO area2.event_scratch1 choice 14 | `0x8ECC 0x12 PRINTCLEAR 'A RESTING LOUNGE. NO ONE IS HERE.'` |
| 0x8EE9 | 0x8070 ON GOTO area2.event_scratch1 choice 15<br>0x80CE ON GOTO area2.event_scratch1 choice 15 | `0x8EF1 0x12 PRINTCLEAR 'A MEETING ROOM. A LARGE TABLE SURROUNDED BY CHAIRS IS HERE.'` |
| 0x8F22 | 0x8070 ON GOTO area2.event_scratch1 choice 16<br>0x80CE ON GOTO area2.event_scratch1 choice 16 | `0x8F2A 0x12 PRINTCLEAR 'A COMPUTER LAB. '` |
|  |  | `0x8F66 0x12 PRINTCLEAR '<string at area2.selected_player_name>'` |
|  |  | `0x8F6A 0x11 PRINT ' NOTICES A NOTE PAD SITTING AT THE COMPUTER DESK ACROSS THE ROOM.'` |
| 0x8FA0 | 0x8070 ON GOTO area2.event_scratch1 choice 17<br>0x80CE ON GOTO area2.event_scratch1 choice 17 | `0x8FAB 0x12 PRINTCLEAR 'YOU FIND A NOTE PAD SITTING ON THE COMPUTER DESK'` |
| 0x8FEB | 0x8070 ON GOTO area2.event_scratch1 choice 18<br>0x80CE ON GOTO area2.event_scratch1 choice 18 | `0x8FF3 0x12 PRINTCLEAR 'A BROOM CLOSET.'` |
| 0x9003 | 0x8070 ON GOTO area2.event_scratch1 choice 19<br>0x80CE ON GOTO area2.event_scratch1 choice 19 | `0x9019 0x12 PRINTCLEAR 'AS YOU ENTER THE ROOM, HANIBL SOOTH RISES FROM A CHAIR. HE PULLS A CLUSTER OF ELECTRODES FROM HIS SCALP. A TECHNICIAN ATTENDS HIM.'` |
| 0x9220 | 0x9015 GOTO 0x9220<br>0xA1D8 GOTO 0x9220 | `0x9220 0x12 PRINTCLEAR 'THE BODY OF THE PURGE COMMANDER, HANIBL SOOTH, LIES HERE'` |
|  |  | `0x9257 0x11 PRINT '.'` |
|  |  | `0x925D 0x11 PRINT ', APPARENTLY, DEAD FROM BATTLE WOUNDS.'` |
| 0x92C3 | 0x8070 ON GOTO area2.event_scratch1 choice 20<br>0x80CE ON GOTO area2.event_scratch1 choice 20 | `0x92D9 0x12 PRINTCLEAR "YOU HEAR HANIBL SOOTH'S VOICE TO THE EAST!"` |
| 0x9584 | 0x92D5 GOTO 0x9584 | `0x95A1 0x12 PRINTCLEAR "DR. MALCOLN'S LAB."` |
| 0x95DE | 0x8070 ON GOTO area2.event_scratch1 choice 21<br>0x80CE ON GOTO area2.event_scratch1 choice 21<br>0x969A GOTO 0x95DE | `0x95E9 0x12 PRINTCLEAR 'THE SCREEN OF THIS COMPUTER READS:'` |
|  |  | `0x9606 0x33 PRINT RETURN` |
|  |  | `0x9607 0x33 PRINT RETURN` |
|  |  | `0x9608 0x11 PRINT ' -- ACCESS DENIED --'` |
|  |  | `0x961A 0x33 PRINT RETURN` |
|  |  | `0x961B 0x11 PRINT '--SOOTH.DOP OVERRIDE --'` |
| 0x9631 | 0x95E5 GOTO 0x9631<br>0x968C GOTO 0x9631 | `0x9631 0x12 PRINTCLEAR 'THESE COMPUTERS ARE INACTIVE.'` |
| 0x964B | 0x8070 ON GOTO area2.event_scratch1 choice 22<br>0x80CE ON GOTO area2.event_scratch1 choice 22 | `0x9653 0x12 PRINTCLEAR 'THE SIGN OVER THE DOOR READS:'` |
|  |  | `0x966C 0x33 PRINT RETURN` |
|  |  | `0x966D 0x33 PRINT RETURN` |
|  |  | `0x966E 0x11 PRINT '-- MAIN COMPUTER TRUNK --'` |
| 0x9685 | 0x8070 ON GOTO area2.event_scratch1 choice 23<br>0x80CE ON GOTO area2.event_scratch1 choice 23 | `0x96A2 0x12 PRINTCLEAR 'YOU ENTER THE MAIN COMPUTER TRUNK. THE MONITORS HERE FLICKER WITH MAD ACTIVITY.'` |
|  |  | `0x96E6 0x12 PRINTCLEAR "SOOTH.DOP, HANIBL SOOTH'S DIGITAL PERSONALITY, IS TRYING TO SHUT DOWN THE SYSTEM! YOU HEAR HIS VOICE COMING FROM MANY SMALL COMPUTER SPEAKERS."` |
|  |  | `0x9759 0x12 PRINTCLEAR "'...DAMN MALCOLN! HIS SECURITY SYSTEM IS TOO STRONG!..MUST LEARN MORE ABOUT IT, AND...ARGHH! CURSE THE ICE!.."` |
| 0x982C | 0x8070 ON GOTO area2.event_scratch1 choice 24<br>0x80CE ON GOTO area2.event_scratch1 choice 24 | `0x9833 0x12 PRINTCLEAR 'THE MAIN COMPUTER IS SHUT DOWN.'` |
|  |  | `0x9850 0x12 PRINTCLEAR 'THE TERMINAL HERE IS ACTIVE.'` |
|  |  | `0x9876 0x11 PRINT " SOOTH.DOP'S VOICE ISSUES FROM A SPEAKER."` |
| 0x99E0 | 0x9872 GOTO 0x99E0 | `0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?"` |

### ECL 95

Attached still-missing strings:
- 0x9091: owner 0x8ED8; `branch_target_region` `CHOOSE:`. incoming: 0x8039 GOTO 0x8ED8
- 0x90C3: owner 0x8ED8; `branch_target_region` `HULL:`. incoming: 0x8039 GOTO 0x8ED8
- 0x90D4: owner 0x8ED8; `branch_target_region` `SENSORS:`. incoming: 0x8039 GOTO 0x8ED8
- 0x90E5: owner 0x8ED8; `branch_target_region` `CONTROLS:`. incoming: 0x8039 GOTO 0x8ED8
- 0x9107: owner 0x8ED8; `branch_target_region` `ENGINES:`. incoming: 0x8039 GOTO 0x8ED8
- 0x9153: owner 0x8ED8; `branch_target_region` `HULL`. incoming: 0x8039 GOTO 0x8ED8
- 0x9167: owner 0x8ED8; `branch_target_region` `ENGN`. incoming: 0x8039 GOTO 0x8ED8
- 0x92EF: owner 0x8ED8; `branch_target_region` `MISSILE`. incoming: 0x8039 GOTO 0x8ED8
- 0x946D: owner 0x8ED8; `branch_target_region` `CURRENT FUEL:`. incoming: 0x8039 GOTO 0x8ED8
- 0x949D: owner 0x8ED8; `branch_target_region` `REFUEL`. incoming: 0x8039 GOTO 0x8ED8
- 0x95C0: owner 0x8ED8; `branch_target_region` `MISSILE`. incoming: 0x8039 GOTO 0x8ED8

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8063 | 0x8053 ON GOTO area1.event_word_250 choice 2 | `0x8072 0x12 PRINTCLEAR "'"` |
| 0x8097 | 0x8076 ON GOTO area1.event_word_256 choice 1 | `0x8097 0x11 PRINT "THE VENUSIAN DINOSAUR, STILL FEARED BY THE LOWLANDERS, IS NOW ALMOST CERTAINLY EXTINCT.'"` |
| 0x80E0 | 0x8076 ON GOTO area1.event_word_256 choice 2 | `0x80E0 0x11 PRINT "ON EARTH, TOXIN LEVELS HAVE BECOME SO HIGH THAT LIFE IS CERTAINLY DOOMED WITHIN DECADES.'"` |
| 0x812A | 0x8076 ON GOTO area1.event_word_256 choice 3 | `0x812A 0x11 PRINT "THE HIGHLY ENGINEERED STORMRIDERS ARE, IN TURN, EXPERTS IN GENETICS.'"` |
| 0x8165 | 0x8076 ON GOTO area1.event_word_256 choice 4 | `0x8165 0x11 PRINT "THE BATTLER, WITH ITS 240 WEAPONS AND WEIGHING IN AT 5,000 TONS, IS THE SYSTEM'S MOST FORMIDABLE SHIP.'"` |
| 0x81BA | 0x8076 ON GOTO area1.event_word_256 choice 5 | `0x81BA 0x11 PRINT "STORMRIDERS, ONCE RESTRICTED TO JUPITER, ARE ESTABLISHING COLONIES ON SOME OF THE MORE REMOTE ASTEROIDS.'"` |
| 0x8210 | 0x8076 ON GOTO area1.event_word_256 choice 6 | `0x8210 0x11 PRINT "LUNARIAN SECURITY IS THE STRICTEST IN THE SOLAR SYSTEM. EXPECT A GREAT DEAL OF RED TAPE.'"` |
| 0x825A | 0x8076 ON GOTO area1.event_word_256 choice 7 | `0x825A 0x11 PRINT "RECENT BIOENGINEERING REPORTS SUGGEST THAT TRAVEL TO THE OUTER PLANETS MAY SOON BE AN EVERYDAY OCCURRENCE.'"` |
| 0x82B2 | 0x8076 ON GOTO area1.event_word_256 choice 8 | `0x82B2 0x11 PRINT "THE AMALTHEANS MAINTAIN THE STORMRIDERS AS A SLAVE CLASS. A PROFITABLE, THOUGH DANGEROUS, POLICY.'"` |
| 0x834F | 0x832E ON GOTO area1.event_word_254 choice 1 | `0x834F 0x12 PRINTCLEAR "'VENUS IS A CESSPOOL OF GENNIE MUCK! I'M GOING TO EARTH AND JOIN UP WITH LORD REFUGE. HE'S THE ONLY ONE WHO CAN CLEAN UP THE SOLAR SYSTEM.'"` |
| 0x83BF | 0x832E ON GOTO area1.event_word_254 choice 2 | `0x83BF 0x12 PRINTCLEAR "YOU OVERHEAR SOMEONE SAY, 'YEAH, ME AND KILLER KANE GREW UP TOGETHER IN LOSANGELORG. HE'S A DECENT SORT, REALLY.'"` |
| 0x841B | 0x832E ON GOTO area1.event_word_254 choice 3 | `0x841B 0x12 PRINTCLEAR "THE TINKER NEXT TO YOU SAYS, 'JUST GOT BACK FROM A LOWLANDER VILLAGE ON VENUS. I DON'T THINK THEY'RE HALF AS PRIMITIVE AS THEY LET ON.'"` |
| 0x8488 | 0x832E ON GOTO area1.event_word_254 choice 4 | `0x8488 0x12 PRINTCLEAR "YOU CATCH THE TAIL END OF A CONVERSATION. '...PROUD TO BE A MEMBER. BIOENGINEERED HUMANS ARE A SCOURGE, NOTHING MORE.'"` |
| 0x84E8 | 0x832E ON GOTO area1.event_word_254 choice 5 | `0x84E8 0x12 PRINTCLEAR "'THAT NEW RAM PRISON ON MARS? NO ONE GETS OUT OF THERE.'"` |
| 0x8519 | 0x832E ON GOTO area1.event_word_254 choice 6 | `0x8519 0x12 PRINTCLEAR "'PUT YOUR MONEY IN BIOENGINEERING. THAT'S WHERE THE PROFITS ARE. WHY, JUST LOOK THE STUFF COMING IN FROM JUPITER.'"` |
| 0x8576 | 0x832E ON GOTO area1.event_word_254 choice 7 | `0x8576 0x12 PRINTCLEAR "AN OLD ROCKET JOCK SAYS, 'SEE THIS SCAR? GOT THAT WHEN I SAID MOON-DOGGIE INSTEAD OF DOG DRIVER TO HAIL A TAXI. I TELL YA', LUNARIANS AREN'T TO BE MESSED WITH.'"` |
| 0x85F5 | 0x832E ON GOTO area1.event_word_254 choice 8 | `0x85F5 0x12 PRINTCLEAR "'I TELL YOU, SHIPS WERE BLASTING OFF FROM EARTH EVERY HOUR, ALL HEADING FOR THE OUTER PLANETS. SOMEBODY'S GONNA HAVE THEIR HANDS FULL PRETTY SOON.'"` |
| 0x866B | 0x8316 GOTO 0x866B | `0x867C 0x12 PRINTCLEAR 'LOWLIFES INSULT YOU, THEN ATTACK!'` |
| 0x8717 | 0x8678 GOTO 0x8717 | `0x8717 0x12 PRINTCLEAR 'PIRATES FACE OFF WITH YOU. '` |
| 0x87F8 | 0x87D7 ON GOTO area1.event_word_292 choice 1 | `0x87F8 0x12 PRINTCLEAR 'A WOMAN TELLS YOU ABOUT A GENETICS LAB BEING DESTROYED, THE THIRD IN LESS THAN A WEEK.'` |
| 0x8840 | 0x87D7 ON GOTO area1.event_word_292 choice 2 | `0x8840 0x12 PRINTCLEAR "'JUST BACK FROM EARTH. RUMORS ARE FLYING ABOUT, SAYING EARTH IS GOING TO BE SAVED BY SID REFUGE.'"` |
| 0x8890 | 0x87D7 ON GOTO area1.event_word_292 choice 3 | `0x8890 0x12 PRINTCLEAR 'ON THE TABLE IS A SMALL PAMPHLET DECLAIMING GENNIES, BLAMING THEM FOR EVERYTHING FROM THE DETERIORATION OF MORALS TO A SLOWING OF THE ECONOMY.'` |
| 0x8902 | 0x87D7 ON GOTO area1.event_word_292 choice 4 | `0x8902 0x12 PRINTCLEAR "'I DON'T KNOW WHAT THOSE MERCURIANS ARE UP TO, BUT THEY'RE LOOKING FOR SOMETHING IN A BIG WAY.'"` |
| 0x8951 | 0x87D7 ON GOTO area1.event_word_292 choice 5 | `0x8951 0x12 PRINTCLEAR "'STORMRIDERS?' A WOMAN ASKS. 'ON MARS? YOU MUST'VE TAKEN SOME BAD GRAVITOL.'"` |
| 0x8991 | 0x87D7 ON GOTO area1.event_word_292 choice 6 | `0x8991 0x12 PRINTCLEAR "'SOMETHING IS UP. ALL THE MAJOR PLAYERS ARE ARMED AND ON THE MOVE.'"` |
| 0x89CB | 0x87D7 ON GOTO area1.event_word_292 choice 7 | `0x89CB 0x12 PRINTCLEAR "'I REMEMBER WHEN WILMA DEERING AND KILLER KANE WERE THE HOTTEST ITEM AROUND. DESPITE IT ALL, I THINK THEY STILL LOVE EACH OTHER.'"` |
| 0x8A33 | 0x87D7 ON GOTO area1.event_word_292 choice 8 | `0x8A33 0x12 PRINTCLEAR "A TECH SPEAKS EXCITEDLY. 'I GOT SOMETHING HUGE AND ALIEN ON MY SCANNERS LAST TIME I WAS IN THE BELT. IT COULDN'T HAVE BEEN A BATTLER. MUST BE FROM ANOTHER SYSTEM.'"` |
| 0x8AB5 | 0x87CA GOTO 0x8AB5 | `0x8ACF 0x12 PRINTCLEAR "WILMA DEERING SPOTS YOU AND CALLS YOU TO HER TABLE. 'IT IS GOOD THAT I SAW YOU.'"` |
| 0x8D17 | 0x804F GOTO 0x8D17 | `0x8D23 0x12 PRINTCLEAR 'YOU RUN INTO SCOT.DOS AS YOU SEARCH THE COMPUTER BANKS.'` |
| 0x8ED8 | 0x8039 GOTO 0x8ED8 | `0x8ED8 0x12 PRINTCLEAR 'YOU ARE IN THE MAIN PORT AREA.'` |
|  |  | `0x8EF2 0x33 PRINT RETURN` |
|  |  | `0x8EF3 0x33 PRINT RETURN` |

### ECL 96 - GEO 96: Living Ship

Attached still-missing strings:
- 0xA293: owner 0xA1D3; `branch_target_region` `CONVINCE`. incoming: 0x8CB8 GOSUB 0xA1D3; 0x8D13 GOSUB 0xA1D3
- 0xA310: owner 0xA1D3; `branch_target_region` `WHO WILL TRY?`. incoming: 0x8CB8 GOSUB 0xA1D3; 0x8D13 GOSUB 0xA1D3

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x89A7 | 0x88F2 GOTO 0x89A7 | `0x89A7 0x12 PRINTCLEAR 'THE TECHS NOTICE YOU. '` |
| 0x8C7F | 0x88E4 GOTO 0x8C7F | `0x8C9A 0x12 PRINTCLEAR "'LIARS! YOU SAID YOU WOULD HELP US!"` |
| 0x8CC0 | 0x8C8E GOTO 0x8CC0 | `0x8CC0 0x12 PRINTCLEAR 'THE TECHS ARE STILL WAITING TO SEE WHAT THEIR CAPTAIN SAYS.'` |
| 0x8CF2 | 0x88FD GOTO 0x8CF2 | `0x8CF2 0x12 PRINTCLEAR 'TECHS RUSH TOWARD YOU FROM THE ALCOVES.'` |
| 0x8D5B | 0x8D51 GOTO 0x8D5B | `0x8D6F 0x12 PRINTCLEAR 'ODDLY SHAPED EQUIPMENT IS STORED HERE.'` |
|  |  | `0x8DA9 0x11 PRINT 'MUCH OF IT IS BROKEN.'` |
| 0x8EAB | 0x8D96 GOTO 0x8EAB<br>0x8DA5 GOTO 0x8EAB | `0x8EAB 0x11 PRINT 'EXAMINING IT, YOU SEE IT HOPELESSLY WRECKED.'` |
| 0x8ED1 | 0x8205 ON GOTO area2.event_scratch0 choice 13 | `0x8EE2 0x12 PRINTCLEAR 'YOU HEAR THE SURLY BARK OF PIRATES, THEN THE PLEAS OF A STORMRIDER. DO YOU FOLLOW THEM?'` |
| 0x8F58 | 0x8F43 GOTO 0x8F58 | `0x8F58 0x12 PRINTCLEAR ''` |
| 0x908B | 0x8191 GOTO 0x908B | `0x9093 0x12 PRINTCLEAR 'THE BOARDING TUBE IS SEALED.'` |
| 0x95E9 | 0x95D5 GOTO 0x95E9<br>0x95DF GOTO 0x95E9 | `0x95E9 0x12 PRINTCLEAR "THE NERVE ENDINGS FOR THE SHIP'S PROPULSION SYSTEM ARE RAW AND EXPOSED."` |
| 0x9703 | 0x9629 GOTO 0x9703 | `0x9703 0x11 PRINT 'DO YOU USE A SONIC STUNNER ON THE NERVE?'` |
| 0x9F3C | 0x8205 ON GOTO area2.event_scratch0 choice 23 | `0x9F44 0x12 PRINTCLEAR 'THE ROOM SMELLS OF ANTISEPTIC.'` |
| 0x9F60 | 0x8205 ON GOTO area2.event_scratch0 choice 24 | `0x9F68 0x12 PRINTCLEAR 'MEDICAL SUPPLIES ARE SCATTERED ABOUT THE ROOM.'` |
| 0x9F90 | 0x8205 ON GOTO area2.event_scratch0 choice 25 | `0x9FAC 0x12 PRINTCLEAR 'THE AUTODOC LAYS TOPPLED ON THE FLOOR. DO YOU TRY TO REPAIR IT?'` |
| 0xA000 | 0x9FA8 GOTO 0xA000 | `0xA000 0x12 PRINTCLEAR 'THE AUTODOC ASKS IF YOU NEED TO BE HEALED.'` |
| 0xA04D | 0x9F9A GOTO 0xA04D | `0xA056 0x12 PRINTCLEAR 'THE AUTODOC IS BEYOND REPAIR.'` |
| 0xA083 | 0xA1A3 GOTO 0xA083<br>0xA1B9 GOTO 0xA083<br>0xA1CF GOTO 0xA083 | `0xA08C 0x12 PRINTCLEAR 'CARGO FILLS THIS AREA. MUCH OF IT HAS BEEN RANSACKED. '` |
|  |  | `0xA0CF 0x11 PRINT 'SEARCH THE ROOM?'` |
| 0xA1D3 | 0x8CB8 GOSUB 0xA1D3<br>0x8D13 GOSUB 0xA1D3 | `0xA1D3 0x33 PRINT RETURN` |
|  |  | `0xA1D4 0x33 PRINT RETURN` |
|  |  | `0xA1D5 0x33 PRINT RETURN` |
|  |  | `0xA1D7 0x11 PRINT 'THEY ATTACK!'` |
| 0xA382 | 0xA373 GOTO 0xA382 | `0xA382 0x12 PRINTCLEAR 'THE PASSAGE LEADS '` |
|  |  | `0xA393 0x11 PRINT '<string at scratch.word_0208>'` |
|  |  | `0xA397 0x11 PRINT '. DO YOU CONTINUE?'` |
| 0xA3D9 | 0xA159 GOSUB 0xA3D9 | `0xA3D9 0x11 PRINT 'YOU FIND A STUNNER.'` |

### ECL 97 - GEO 97: Living Ship

Attached still-missing strings:
- 0x8040: owner 0x8014; `branch_target_region` `PE:PE:BPDB`. incoming: entry ecl_initial_entry
- 0x9B49: owner 0x9A92; `branch_target_region` `CONVINCE`. incoming: 0x834A ON GOTO area2.event_scratch0 choice 15
- 0x9BC0: owner 0x9A92; `branch_target_region` `WHO WILL TRY?`. incoming: 0x834A ON GOTO area2.event_scratch0 choice 15

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x84FB | 0x834A ON GOTO area2.event_scratch0 choice 1 | `0x8503 0x12 PRINTCLEAR 'DO YOU WISH TO '` |
|  |  | `0x8520 0x11 PRINT 'ENTER THE LIVING SHIP?'` |
| 0x85A1 | 0x851C GOTO 0x85A1 | `0x85A1 0x11 PRINT 'RETURN TO YOUR SHIP?'` |
| 0x85C2 | 0x834A ON GOTO area2.event_scratch0 choice 2 | `0x85CA 0x12 PRINTCLEAR 'YOU ENTER THE CONTROL ROOM.'` |
|  |  | `0x85F6 0x11 PRINT ' NATBAKKA SITS AT THE BEACON CONTROLS AND STARES INTENTLY AT THE VID-SCREEN. DO YOU APPROACH HER?'` |
| 0x8651 | 0x834A ON GOTO area2.event_scratch0 choice 3 | `0x8659 0x12 PRINTCLEAR 'THESE ARE CREW QUARTERS.'` |
| 0x8670 | 0x834A ON GOTO area2.event_scratch0 choice 4 | `0x8678 0x12 PRINTCLEAR 'THE PLAQUE ON THE WALL READS,'` |
|  |  | `0x8691 0x33 PRINT RETURN` |
|  |  | `0x8692 0x33 PRINT RETURN` |
|  |  | `0x8693 0x11 PRINT '     STORMRIDER QUARTERS.'` |
| 0x86AB | 0x834A ON GOTO area2.event_scratch0 choice 5 | `0x86CA 0x12 PRINTCLEAR "NATBAKKA LOOKS UP FROM THE CONSOLE. 'NOTHING YET... WAIT, HERE IT COMES. STRANGE, IT SEEMS OFF COURSE. LET ME TRY TO GET A VISUAL.'"` |
| 0x8B7E | 0x8B69 ON GOTO area2.event_scratch0 choice 0<br>0x8BA3 GOTO 0x8B7E<br>0x8DFA GOTO 0x8B7E<br>0x8FAB GOTO 0x8B7E | `0x8B7E 0x12 PRINTCLEAR 'CREW QUARTERS. THEY ARE EMPTY.'` |
| 0x8DF0 | 0x8B69 ON GOTO area2.event_scratch0 choice 4 | `0x8DFE 0x12 PRINTCLEAR 'TECHS ARE ASLEEP ON THEIR BUNKS. '` |
| 0x9030 | 0x8F9D GOTO 0x9030 | `0x9030 0x12 PRINTCLEAR 'PIRATES, OR WHAT REMAINS OF THEM AFTER BEING EXPOSED TO THE VACUUM OF SPACE, LAY LIFELESS ON THEIR BUNKS.'` |
| 0x9084 | 0x834A ON GOTO area2.event_scratch0 choice 7 | `0x9084 0x12 PRINTCLEAR "OFFICER'S QUARTERS. THEY ARE EMPTY."` |
|  |  | `0x90AD 0x11 PRINT ' DO YOU SEARCH THEM?'` |
| 0x922F | 0x834A ON GOTO area2.event_scratch0 choice 8 | `0x9250 0x12 PRINTCLEAR "STORMRIDERS ARE GATHERED BEHIND THE FURNITURE. 'THE PIRATES HOLD THE CONTROL ROOM ON THE NEXT LEVEL UP. I THINK THEY ARE MAD. THEY KEEP TALKING OF FREEDOM, BUT FROM WHAT?"` |
| 0x9546 | 0x947B GOTO 0x9546 | `0x9551 0x12 PRINTCLEAR 'DO YOU SEARCH THE BODIES?'` |
| 0x974D | 0x834A ON GOTO area2.event_scratch0 choice 10 | `0x9758 0x12 PRINTCLEAR "YOU FIND NATBAKKA'S BODY BENEATH SOME OF THE WRECKAGE."` |
| 0x978F | 0x834A ON GOTO area2.event_scratch0 choice 11 | `0x97A5 0x12 PRINTCLEAR "YOU STUMBLE ACROSS SOME WRECKAGE FROM THE MAELSTROM RIDER'S ENGINES."` |
| 0x9C6B | 0x82F3 GOSUB 0x9C6B<br>0x8305 GOSUB 0x9C6B | `0x9C6B 0x12 PRINTCLEAR 'THE PASSAGE LEADS UP. DO YOU CONTINUE?'` |
| 0x9C8D | 0x8323 GOSUB 0x9C8D | `0x9C8D 0x12 PRINTCLEAR 'THE PASSAGE LEADS SHARPLY DOWNWARD. DO YOU CONTINUE?'` |

### ECL 98

Attached still-missing strings:
- 0x9FAA: owner 0x9E8F; `branch_target_region` `CONVINCE`. incoming: 0x9E5D GOTO 0x9E8F; 0x9E67 GOTO 0x9E8F; 0x9E71 GOTO 0x9E8F; 0x9E7B GOTO 0x9E8F; 0x9E85 GOTO 0x9E8F
- 0xA021: owner 0x9E8F; `branch_target_region` `WHO WILL TRY?`. incoming: 0x9E5D GOTO 0x9E8F; 0x9E67 GOTO 0x9E8F; 0x9E71 GOTO 0x9E8F; 0x9E7B GOTO 0x9E8F; 0x9E85 GOTO 0x9E8F
- 0xA0A2: owner 0xA071; `branch_target_region` `USE DEVICE`. incoming: 0xA1AB GOTO 0xA071

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x80B4 | 0x80AF GOTO 0x80B4 | `0x80B4 0x12 PRINTCLEAR 'THE PASSAGE LEADS '` |
|  |  | `0x80CC 0x11 PRINT 'UP'` |
|  |  | `0x80D2 0x11 PRINT 'DOWN'` |
|  |  | `0x80D8 0x11 PRINT '. DO YOU GO ON?'` |
| 0x8200 | 0x8D19 GOTO 0x8200<br>0x8F24 GOTO 0x8200<br>0x9005 GOTO 0x8200 | `0x8200 0x12 PRINTCLEAR ''` |
| 0x82F3 | 0x829E GOTO 0x82F3<br>0x82B6 GOTO 0x82F3<br>0x82DC GOTO 0x82F3<br>0x82EF GOTO 0x82F3 | `0x831A 0x12 PRINTCLEAR 'STORMRIDERS COME UP TO YOU'` |
| 0x834C | 0x8331 ON GOTO area1.event_word_3E0 choice 1 | `0x834C 0x11 PRINT ". THEY THANK YOU MANY TIMES FOR ALL YOU'VE DONE. "` |
| 0x84AD | 0x837E GOTO 0x84AD | `0x84AD 0x11 PRINT 'THEY THEN TELL YOU THAT SOME OF THE PIRATES SURVIVED THE VENTING.'` |
| 0x8590 | 0x8331 ON GOTO area1.event_word_3E0 choice 4 | `0x8590 0x11 PRINT ". 'YOU HAVE MADE A VALIANT EFFORT. IT WAS YOUR DOING WHICH GAVE US ALLIES IN THE PIRATES, WHICH MORE THAN COMPENSATES FOR THE DAMAGE THEY DID TO THE SHIP."` |
| 0x8723 | 0x8331 ON GOTO area1.event_word_3E0 choice 2 | `0x8723 0x11 PRINT ". 'WELL, THINGS HAVE TURNED OUT AS WELL AS ONE COULD EXPECT. THE PIRATES SIMPLY DID TOO MUCH DAMAGE."` |
| 0x8CE8 | 0x8CD9 ON GOTO area1.event_word_202 choice 1 | `0x8CE8 0x11 PRINT 'TO CONTROL LIFE SUPPORT SYSTEMS.'` |
| 0x8D0E | 0x8CD9 ON GOTO area1.event_word_202 choice 2 | `0x8D1D 0x12 PRINTCLEAR "THE DEVICE LIGHTS UP AND GIVES YOU A READOUT OF THE SHIP'S STATUS."` |
|  |  | `0x8D9F 0x11 PRINT ' THERE ARE STILL SOME AREAS OF NERVE DAMAGE'` |
|  |  | `0x8DCA 0x11 PRINT 'IN THE BRAIN'` |
|  |  | `0x8DDD 0x11 PRINT ' AND'` |
|  |  | `0x8DEA 0x11 PRINT ' ON THE LOWEST DECK'` |
|  |  | `0x8DFC 0x11 PRINT '.'` |
| 0x8E00 | 0x8D9B GOTO 0x8E00 | `0x8E01 0x12 PRINTCLEAR 'YOU ALSO GET A READOUT OF WHERE THE PIRATES ARE. DO YOU TRY TO OPEN THOSE AREAS TO THE VACUUM OF SPACE?'` |
| 0x8F02 | 0x8EF3 ON GOTO area1.event_word_202 choice 1 | `0x8F02 0x11 PRINT 'AS SENSORS.'` |
| 0x8F19 | 0x8EF3 ON GOTO area1.event_word_202 choice 2 | `0x8F28 0x12 PRINTCLEAR "THE DEVICE GIVES YOU A READOUT OF THE SHIP'S POSITION."` |
|  |  | `0x8F5E 0x11 PRINT ' YOU RECORD IT FOR USE AT THE NAV STATION.'` |
|  |  | `0x8F82 0x11 PRINT " UNFORTUNATELY, THE SHIP'S COURSE IS ALREADY LOCKED IN."` |
| 0x8FD7 | 0x8FC8 ON GOTO area1.event_word_202 choice 1 | `0x8FD7 0x11 PRINT 'FOR COMMUNICATION CONTROLS.'` |
| 0x8FFA | 0x8FC8 ON GOTO area1.event_word_202 choice 2 | `0x9009 0x12 PRINTCLEAR 'THE DEVICE CRACKLES WITH STATIC. THEN, A MESSAGE COMES IN FROM JUPITER.'` |
| 0x9248 | 0x9239 ON GOTO area1.event_word_202 choice 1 | `0x9248 0x11 PRINT 'TO NAVIGATE THE SHIP.'` |
| 0x963B | 0x938B ON GOTO area1.event_word_3E2 choice 5 | `0x963B 0x12 PRINTCLEAR 'WHAT DO YOU DO WITH THE STRANGE EQUIPMENT?'` |
| 0x965E |  | `0x965E 0x2B HORIZONTAL MENU area1.event_word_202 = <selected index from menu> MENU: 'DESTROY', 'HOOK UP', 'NOTHING'` |
| 0x968B | 0x967C ON GOTO area1.event_word_202 choice 0 | `0x9691 0x12 PRINTCLEAR 'YOU DESTROY THE EQUIPMENT.'` |
| 0x97D9 | 0x967C ON GOTO area1.event_word_202 choice 1 | `0x980E 0x12 PRINTCLEAR "THE SHIP LURCHES AS YOU MAKE THE FINAL CONNECTION. A STORMRIDER BURSTS INTO THE ROOM. 'WHAT HAVE YOU DONE? NOW THE ONLY WAY TO CONTROL THE SHIP IS WITH VIOLENCE!"` |
| 0x9972 | 0x97F5 GOTO 0x9972 | `0x9978 0x12 PRINTCLEAR 'YOU FUMBLE WITH THE EQUIPMENT, UNABLE TO MAKE IT WORK.'` |
| 0x9B74 | 0x9BB2 GOTO 0x9B74<br>0x9BC0 GOTO 0x9B74 | `0x9B74 0x11 PRINT "THERE ARE STILL SOME SYSTEMS YOU NEED TO TRY TO RESTORE.'"` |
| 0x9BA4 | 0x9B70 GOTO 0x9BA4 | `0x9BAD 0x12 PRINTCLEAR "'"` |
|  |  | `0x9BCD 0x11 PRINT 'IN THE ROOMS JUST SOUTH OF HERE ARE ALL THE SYSTEMS CONTROLS.'` |
| 0x9CAA | 0x9B0C GOTO 0x9CAA<br>0x9CF6 GOTO 0x9CAA | `0x9CC8 0x12 PRINTCLEAR "'ARE YOU GOING TO FIX THE OTHER ONE NOW?'"` |
| 0x9CEC | 0x9B01 GOTO 0x9CEC | `0x9CFA 0x12 PRINTCLEAR "'IT IS VERY IMPORTANT THAT YOU FIX THE SYNAPSE CONTROLLER IN THE BRAIN HEMISPHERES.'"` |
| 0x9D4E | 0x9D44 GOTO 0x9D4E | `0x9D62 0x12 PRINTCLEAR 'THE STORMRIDER EQUIPMENT IS IN A SHAMBLES.'` |
|  |  | `0x9D91 0x11 PRINT ' DO YOU RECONNECT IT?'` |
| 0x9E8F | 0x9E5D GOTO 0x9E8F<br>0x9E67 GOTO 0x9E8F<br>0x9E71 GOTO 0x9E8F<br>0x9E7B GOTO 0x9E8F<br>0x9E85 GOTO 0x9E8F | `0x9EA3 0x12 PRINTCLEAR 'THE WALLS HERE ARE LIVID AND BULGE WITH AN UNHEALTHY PULSE. DO YOU TRY TO TREAT IT?'` |
| 0xA02F | 0x8CD3 GOSUB 0xA02F<br>0x8EED GOSUB 0xA02F<br>0x8FC2 GOSUB 0xA02F<br>0x9233 GOSUB 0xA02F | `0xA02F 0x12 PRINTCLEAR 'THE WALLS HERE ARE POCK MARKED WITH HOLES. '` |
| 0xA199 | 0x8D03 GOSUB 0xA199<br>0x8F0E GOSUB 0xA199<br>0x8FEF GOSUB 0xA199<br>0x925B GOSUB 0xA199 | `0xA1A4 0x11 PRINT ' NOW '` |
| 0xA1AF | 0xA1FE GOTO 0xA1AF | `0xA1B8 0x12 PRINTCLEAR 'NOTHING HAPPENS. DO YOU TRY ANOTHER HOLE?'` |
| 0xA25B | 0xA22E GOTO 0xA25B | `0xA25B 0x12 PRINTCLEAR 'THE DEVICE FLASHES. THEN A SHUDDER PASSES THROUGH THE SHIP AS THE FLESH SUDDENLY LIGHTS UP AND THEN GOES DEAD.'` |

### ECL 112 - GEO 112: Stormrider University

Attached still-missing strings:
- 0x99D3: owner 0x992F; `branch_target_region` `DEFUSE`. incoming: 0x8228 ON GOTO area2.event_scratch0 choice 27
- 0x9AF6: owner 0x992F; `branch_target_region` `SOMEONE ELSE?`. incoming: 0x8228 ON GOTO area2.event_scratch0 choice 27
- 0x9FCB: owner 0x9EBE; `branch_target_region` `WHO TRIES?`. incoming: 0x9EAC ON GOTO area1.event_word_372 choice 1

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x82F1 | 0x82E2 ON GOTO area2.event_scratch0 choice 0 | `0x82F1 0x12 PRINTCLEAR 'A GROUP OF STUDENTS RUSH BY TALKING ABOUT '` |
| 0x8323 | 0x8314 ON GOTO area2.event_scratch2 choice 0 | `0x8323 0x11 PRINT 'THE BIG GAME.'` |
| 0x8332 | 0x8314 ON GOTO area2.event_scratch2 choice 1 | `0x8332 0x11 PRINT 'PHILOSOPHICAL ISSUES.'` |
| 0x8347 | 0x8314 ON GOTO area2.event_scratch2 choice 2 | `0x8347 0x11 PRINT "DICKENS' 'BLEAK HOUSE.'"` |
| 0x835E | 0x82E2 ON GOTO area2.event_scratch0 choice 1 | `0x835E 0x12 PRINTCLEAR 'A'` |
| 0x8371 | 0x8362 ON GOTO area2.event_scratch2 choice 0 | `0x8371 0x11 PRINT ' SHORTER'` |
| 0x837E | 0x8362 ON GOTO area2.event_scratch2 choice 1 | `0x837E 0x11 PRINT 'N ANGRY LOOKING'` |
| 0x8391 | 0x8362 ON GOTO area2.event_scratch2 choice 2 | `0x8391 0x11 PRINT ' DISTINGUISHED'` |
| 0x839F | 0x837A GOTO 0x839F<br>0x838D GOTO 0x839F | `0x839F 0x11 PRINT ' STORMRIDER REGARDS YOU WITH '` |
|  |  | `0x83BF 0x11 PRINT 'SUSPICION.'` |
|  |  | `0x83CB 0x11 PRINT 'WARMTH.'` |
| 0x8473 | 0x83DC ON GOTO area2.event_scratch0 choice 2 | `0x848C 0x12 PRINTCLEAR 'JOVIAN DRAGONS ATTACK!'` |
| 0x84B4 | 0x83DC ON GOTO area2.event_scratch0 choice 3 | `0x84BF 0x12 PRINTCLEAR "A STORMRIDER RUNS BY. 'SOLDIERS HAVE BROUGHT A BOMB TO THE COMPUTER CORE!'"` |
| 0x84FE | 0x84BB GOTO 0x84FE | `0x850C 0x12 PRINTCLEAR "A STORMRIDER APPROACHES. 'SOLDIERS ARE WRECKING THE LABS!'"` |
| 0x853F | 0x8508 GOTO 0x853F | `0x854D 0x12 PRINTCLEAR "A STUDENT SHOUTS. 'SOLDIERS ARE IN THE CLASSROOM COMPLEX.'"` |
| 0x8580 | 0x8549 GOTO 0x8580 | `0x858E 0x12 PRINTCLEAR "SOMEONE CRIES, 'AMALTHEANS ARE BURNING THE LIBRARY...HELP!'"` |
| 0x85C0 | 0x858A GOTO 0x85C0 | `0x85CB 0x12 PRINTCLEAR "A PROFESSOR YELLS, 'THERE'S STILL SOME IN THE DORMS!'"` |
| 0x85F8 | 0x84FA GOTO 0x85F8<br>0x853B GOTO 0x85F8<br>0x857C GOTO 0x85F8 | `0x85F9 0x12 PRINTCLEAR 'HE RUNS OFF.'` |
| 0x8620 | 0x8228 ON GOTO area2.event_scratch0 choice 1 | `0x8628 0x12 PRINTCLEAR 'THE LANDING PAD. '` |
| 0x869E | 0x8638 ON GOTO area1.event_word_372 choice 2 | `0x869E 0x11 PRINT 'DO YOU LEAVE THE UNIVERSITY?'` |
| 0x88A0 | 0x876D ON GOTO area1.event_word_372 choice 2<br>0x8789 GOTO 0x88A0 | `0x88A3 0x12 PRINTCLEAR 'MAKALI IS HARD AT WORK. SHE IGNORES YOU.'` |
| 0x8944 | 0x8228 ON GOTO area2.event_scratch0 choice 3 | `0x895D 0x12 PRINTCLEAR 'AS YOU EXIT THE LABS, AN EXPLOSION ROCKS THE UNIVERSITY!'` |
| 0x8A71 | 0x8A65 GOTO 0x8A71 | `0x8A71 0x12 PRINTCLEAR 'YOU ENTER A LAB. '` |
| 0x8A93 | 0x8A81 ON GOTO area1.event_word_372 choice 0 | `0x8A93 0x11 PRINT 'STORMRIDERS WORK HERE.'` |
| 0x8B3B | 0x8A81 ON GOTO area1.event_word_372 choice 2 | `0x8B43 0x11 PRINT 'STORMRIDERS WORK TO REPAIR THE DAMAGE.'` |
| 0x8B65 | 0x8228 ON GOTO area2.event_scratch0 choice 9 | `0x8B77 0x12 PRINTCLEAR 'YOU ENTER A DORM ROOM. '` |
| 0x8BB0 | 0x8B9E ON GOTO area2.event_scratch0 choice 0 | `0x8BB0 0x11 PRINT 'A STORMRIDER LOOKS UP FROM HER BOOK, GREETS YOU, AND RETURNS TO HER READING.'` |
| 0x8BEE | 0x8B9E ON GOTO area2.event_scratch0 choice 1 | `0x8BEE 0x11 PRINT 'TWO STUDENTS ARE PLAYING A COMPUTER GAME. THEY ARE TOO ENGROSSED TO NOTICE YOUR ENTRANCE.'` |
| 0x8C36 | 0x8B9E ON GOTO area2.event_scratch0 choice 2 | `0x8C36 0x11 PRINT 'NOBODY IS HERE.'` |
| 0x8C47 | 0x8B8C ON GOTO area1.event_word_372 choice 1<br>0x8C5B ON GOTO area2.event_scratch0 choice 1 | `0x8C47 0x11 PRINT 'IT HAS BEEN WRECKED.'` |
| 0x8C6D | 0x8C5B ON GOTO area2.event_scratch0 choice 0 | `0x8C6D 0x11 PRINT ' A STORMRIDER STUDENT IS CLEANING UP. SHE IS FIXING A DESK SMASHED BY THE AMALTHEANS.'` |
| 0x8CB2 | 0x8C5B ON GOTO area2.event_scratch0 choice 2 | `0x8CB2 0x11 PRINT ' MOST OF THE DAMAGE HAS BEEN REPAIRED.'` |
| 0x8CD4 | 0x8228 ON GOTO area2.event_scratch0 choice 13 | `0x8CD4 0x12 PRINTCLEAR 'YOU ENTER AN ELEVATOR. '` |
|  |  | `0x8CF4 0x11 PRINT 'THE CONTROLS COME TO LIFE.'` |
| 0x8D7B | 0x8CF0 GOTO 0x8D7B | `0x8D7B 0x11 PRINT 'THE CONTROLS ARE SMASHED.'` |
| 0x8E4B | 0x8228 ON GOTO area2.event_scratch0 choice 15 | `0x8E53 0x12 PRINTCLEAR 'YOU ENTER THE CLASSROOM COMPLEX. '` |
| 0x8F76 | 0x8F64 ON GOTO area1.event_word_372 choice 1 | `0x8F76 0x12 PRINTCLEAR 'THE STUDENTS HERE HAVE BEEN MASSACRED. NOT ONE REMAINS ALIVE.'` |
| 0x8FA9 | 0x8F64 ON GOTO area1.event_word_372 choice 2 | `0x8FA9 0x12 PRINTCLEAR 'GRIM STUDENTS ARE REMOVING DEAD CLASSMATES FROM THIS ROOM.'` |
| 0x9422 | 0x8228 ON GOTO area2.event_scratch0 choice 20 | `0x9435 0x12 PRINTCLEAR 'THIS CLASSROOM HAS BEEN MASSIVELY DAMAGED.'` |
| 0x945A | 0x9431 GOTO 0x945A | `0x945A 0x12 PRINTCLEAR 'THIS CLASSROOM IS EMPTY.'` |
| 0x94C6 |  | `0x94D8 0x11 PRINT ' IS IN SESSION. THE PROFESSOR MOTIONS YOU OUT OF THE ROOM.'` |
| 0x950C | 0x94C6 ON GOSUB area2.event_scratch0 choice 0 | `0x950C 0x12 PRINTCLEAR 'A PHYSICS LECTURE'` |
| 0x951D | 0x94C6 ON GOSUB area2.event_scratch0 choice 1 | `0x951D 0x12 PRINTCLEAR 'A LITERARY SEMINAR'` |
| 0x952F | 0x94C6 ON GOSUB area2.event_scratch0 choice 2 | `0x952F 0x12 PRINTCLEAR 'A CLASS IN BOTANICAL GENETICS'` |
| 0x9549 | 0x94C6 ON GOSUB area2.event_scratch0 choice 3 | `0x9549 0x12 PRINTCLEAR 'A ASTROGATION LECTURE'` |
| 0x988D | 0x8228 ON GOTO area2.event_scratch0 choice 25 | `0x9895 0x12 PRINTCLEAR 'YOU ENTER THE COMPUTER CORE. '` |
|  |  | `0x98B6 0x11 PRINT 'IT IS WRECKED BY EXPLOSION.'` |
| 0x992F | 0x8228 ON GOTO area2.event_scratch0 choice 27 | `0x9947 0x12 PRINTCLEAR 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?'` |
| 0x9B4F | 0x9B3D ON GOTO area1.event_word_372 choice 0 | `0x9B4F 0x12 PRINTCLEAR 'YOU ENTER THE SCHOOL LIBRARY. STUDENTS MOVE ABOUT, MAKING USE OF THE IMPRESSIVE COLLECTION OF BOOKS.'` |
| 0x9B9F | 0x9B3D ON GOTO area1.event_word_372 choice 1 | `0x9B9F 0x12 PRINTCLEAR 'YOU ENTER THE BRUTALIZED REMAINS OF THE UNIVERSITY LIBRARY. IT HAS BEEN GUTTED BY FLAMES.'` |
| 0x9C12 | 0x9B3D ON GOTO area1.event_word_372 choice 3 | `0x9C12 0x12 PRINTCLEAR 'YOU ENTER THE FLAME GUTTED LIBRARY. STORMRIDERS SHOVEL THE BURNT REMAINS OF BOOKS INTO TRASH BAGS.'` |
| 0x9C61 | 0x8228 ON GOTO area2.event_scratch0 choice 30 | `0x9C7D 0x12 PRINTCLEAR 'THE AIR HERE IS NOTICEABLE WARMER. HEAT EMANATES FROM THE DOOR AHEAD.'` |
| 0x9CB6 | 0x8228 ON GOTO area2.event_scratch0 choice 31 | `0x9CBE 0x12 PRINTCLEAR 'YOU ENTER THE MAIN SECTION OF THE LIBRARY'` |
| 0x9CF2 | 0x9CE0 ON GOTO area1.event_word_372 choice 0<br>0x9EAC ON GOTO area1.event_word_372 choice 0 | `0x9CF2 0x11 PRINT '. IT IS CROWDED WITH ACADEMIC ACTIVITY.'` |
| 0x9E6F | 0x9CE0 ON GOTO area1.event_word_372 choice 2<br>0x9D1F GOTO 0x9E6F<br>0xA075 GOTO 0x9E6F | `0x9E6F 0x11 PRINT '. IT HAS BEEN GUTTED BY FLAMES.'` |
| 0x9E8C | 0x8228 ON GOTO area2.event_scratch0 choice 32 | `0x9E94 0x12 PRINTCLEAR 'YOU ENTER THE LIBRARY ANNEX'` |
| 0x9EBE | 0x9EAC ON GOTO area1.event_word_372 choice 1 | `0x9ED5 0x11 PRINT ". A SMALL FIRE IS BURNING IN THIS ROOM, AND IT'S BEGINNING TO SPREAD."` |
| 0xA06B | 0x9EAC ON GOTO area1.event_word_372 choice 2<br>0x9EC8 GOTO 0xA06B | `0xA079 0x11 PRINT '. DUE TO YOUR EFFORTS, IT IS INTACT.'` |
| 0xA0C1 | 0x8228 ON GOTO area2.event_scratch0 choice 35 | `0xA0D9 0x12 PRINTCLEAR 'YOU ENTER THE OFFICE OF CONTINUING EDUCATION.'` |
| 0xA119 | 0x8228 ON GOTO area2.event_scratch0 choice 36 | `0xA121 0x12 PRINTCLEAR 'YOU ENTER A STORE.'` |

### ECL 113 - GEO 113: Genetics Foundation Building, Levels 1-4

Attached still-missing strings:
- 0x8600: owner 0x8014; `branch_target_region` `HIS SPEECH`. incoming: entry ecl_initial_entry
- 0x8CCD: owner 0x8C81; `branch_target_region` `YOU GO TO FLOOR`. incoming: 0x8966 ON GOTO area2.event_scratch1 choice 4
- 0x9725: owner 0x9682; `branch_target_region` `WHO TRIES?`. incoming: 0x8966 ON GOTO area2.event_scratch1 choice 18

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x873D | entry vm_run_1 | `0x8799 0x12 PRINTCLEAR 'THIS CELL IS LOCKED TIGHT.'` |
| 0x87B7 | 0x8744 GOTO 0x87B7 | `0x87C5 0x12 PRINTCLEAR 'YOU LEAVE THE BUILDING. TSUBULU HURRIES YOU INTO THE SHUTTLE.'` |
| 0x8820 | 0x87C1 GOTO 0x8820 | `0x8820 0x12 PRINTCLEAR 'YOU LOOK OUT THE AIR LOCK WINDOW. TSUBULU IS NOT THERE!'` |
| 0x886A | 0x875B GOTO 0x886A | `0x8881 0x12 PRINTCLEAR "IT WON'T OPEN."` |
| 0x8890 | 0x8772 GOTO 0x8890 | `0x88A1 0x12 PRINTCLEAR "THE DOOR WON'T OPEN."` |
| 0x8BDA | 0x8A07 ON GOTO area2.event_scratch0 choice 3 | `0x8BDA 0x12 PRINTCLEAR 'SECURITY ALERT!'` |
| 0x8C12 | 0x8966 ON GOTO area2.event_scratch1 choice 1 | `0x8C12 0x12 PRINTCLEAR 'THIS ELEVATOR HAS BEEN DEACTIVATED.'` |
| 0x8C31 | 0x8966 ON GOTO area2.event_scratch1 choice 2 | `0x8C3E 0x12 PRINTCLEAR 'YOU CLIMB DOWN.'` |
| 0x8C58 | 0x8966 ON GOTO area2.event_scratch1 choice 3 | `0x8C65 0x12 PRINTCLEAR 'YOU CLIMB UP.'` |
| 0x8C81 | 0x8966 ON GOTO area2.event_scratch1 choice 4 | `0x8C81 0x12 PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?'` |
| 0x8D4A | 0x8966 ON GOTO area2.event_scratch1 choice 6 | `0x8D58 0x12 PRINTCLEAR 'THERE IS A COMPUTER HERE.'` |
| 0x8DCF | 0x8D54 GOTO 0x8DCF | `0x8DD9 0x12 PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS DEACTIVATED.'` |
|  |  | `0x8E05 0x12 PRINTCLEAR 'THE SECONDARY SECURITY COMPUTER IS HERE. IT HAS BEEN ACTIVATED.'` |
| 0x8F12 | 0x8966 ON GOTO area2.event_scratch1 choice 7 | `0x8F2A 0x12 PRINTCLEAR "'ROBOT CONTROL ROUTED TO SECONDARY CONTROL. INTRUDER ALERT!'"` |
| 0x8F60 | 0x8966 ON GOTO area2.event_scratch1 choice 8 | `0x8F7D 0x12 PRINTCLEAR 'A CIRCLE OF DEACTIVATED ROBOTS IS HERE.'` |
| 0x8FF0 | 0x8966 ON GOTO area2.event_scratch1 choice 9 | `0x9004 0x12 PRINTCLEAR 'YOU ENTER A LARGE KITCHEN.'` |
| 0x921E | 0x8966 ON GOTO area2.event_scratch1 choice 10 | `0x9226 0x12 PRINTCLEAR 'TO THE EAST IS THE ACCESS GRATE THAT THE STORMRIDERS TOLD YOU ABOUT. DO YOU GO THROUGH?'` |
| 0x9298 | 0x8966 ON GOTO area2.event_scratch1 choice 11 | `0x92B2 0x12 PRINTCLEAR 'SOMEONE IS POUNDING ON THE NORTH DOOR FROM THE OTHER SIDE.'` |
| 0x92E3 | 0x8966 ON GOTO area2.event_scratch1 choice 12 | `0x92F7 0x12 PRINTCLEAR 'YOUR EQUIPMENT IS HERE!'` |
|  |  | `0x930D 0x11 PRINT ' YOU QUICKLY REARM.'` |
| 0x94B8 | 0x8966 ON GOTO area2.event_scratch1 choice 14 | `0x94C4 0x11 PRINT 'REMOTE ROBOT CONTROL CENTER'` |
| 0x954D | 0x8966 ON GOTO area2.event_scratch1 choice 16 | `0x955D 0x12 PRINTCLEAR 'A SIGN OVER THE NORTH DOOR READS:'` |
|  |  | `0x9579 0x33 PRINT RETURN` |
|  |  | `0x957A 0x33 PRINT RETURN` |
|  |  | `0x957B 0x11 PRINT '     HIGH SECURITY LAB'` |
|  |  | `0x958F 0x33 PRINT RETURN` |
|  |  | `0x9590 0x11 PRINT '  AUTHORIZED PERSONNEL ONLY'` |
| 0x95A9 | 0x8966 ON GOTO area2.event_scratch1 choice 17 | `0x95BD 0x12 PRINTCLEAR 'YOU ENTER A COMMUNICATION CENTER. A SOLDIER RADIOS FOR HELP.'` |
| 0x9682 | 0x8966 ON GOTO area2.event_scratch1 choice 18 | `0x968A 0x12 PRINTCLEAR 'YOU ENTER A COLD STORAGE ROOM.'` |
| 0x97AF | 0x8966 ON GOTO area2.event_scratch1 choice 19 | `0x97B7 0x12 PRINTCLEAR 'THERE IS LIFE SUSPENSION EQUIPMENT HERE.'` |
| 0x98B4 | 0x8966 ON GOTO area2.event_scratch1 choice 20 | `0x98B8 0x11 PRINT '       QUARANTINE'` |
| 0x9979 | 0x8966 ON GOTO area2.event_scratch1 choice 22 | `0x9979 0x12 PRINTCLEAR 'THE MAIN SECURITY COMPUTER IS HERE. '` |
|  |  | `0x99A1 0x11 PRINT 'IT IS DEACTIVATED.'` |
|  |  | `0x99B4 0x11 PRINT 'DO YOU DEACTIVATE IT?'` |
| 0x9AF0 | 0x9D57 GOTO 0x9AF0 | `0x9AF2 0x12 PRINTCLEAR 'YOU ENTER A GENETICS LAB. THERE ARE GROW TANKS ACROSS THE ROOM.'` |
| 0x9B27 | 0x8966 ON GOTO area2.event_scratch1 choice 25 | `0x9B35 0x12 PRINTCLEAR 'YOU APPROACH THE GROW VAT. IT IS FULL OF FLUID--READY TO USE.'` |
| 0x9D2B | 0x9B31 GOTO 0x9D2B | `0x9D2B 0x12 PRINTCLEAR 'WASPHOPPERS POUR OUT OF THIS GROW VAT.'` |
| 0x9D5B | 0x8966 ON GOTO area2.event_scratch1 choice 27 | `0x9D5B 0x12 PRINTCLEAR 'THIS GROW VAT HAS BEEN DRAINED.'` |
| 0x9EFB | 0x8966 ON GOTO area2.event_scratch1 choice 29 | `0x9F06 0x12 PRINTCLEAR "MARIO QUINN'S BODY LIES HERE."` |
| 0x9F21 | 0x8966 ON GOTO area2.event_scratch1 choice 30 | `0x9F43 0x12 PRINTCLEAR 'A GROUP OF STORMRIDERS MEET YOU. ONE SPEAKS.'` |
| 0xA05E | 0x8966 ON GOTO area2.event_scratch1 choice 31 | `0xA05E 0x12 PRINTCLEAR 'THERE IS A COMPUTER TERMINAL HERE. '` |
|  |  | `0xA086 0x11 PRINT 'CABLES LEAD FROM IT THROUGH THE WEST WALL TO THE MAIN PROCESSOR.'` |
|  |  | `0xA0BD 0x11 PRINT 'IT IS DEACTIVATED.'` |
| 0xA0E4 | 0x8C37 GOSUB 0xA0E4<br>0x8C5E GOSUB 0xA0E4<br>0x8D33 GOSUB 0xA0E4<br>0x8DB4 GOSUB 0xA0E4 | `0xA0E4 0x12 PRINTCLEAR 'THE LADDER HERE LEADS '` |
|  |  | `0xA0FF 0x11 PRINT 'DOWN'` |
|  |  | `0xA106 0x11 PRINT 'UP'` |
|  |  | `0xA10B 0x11 PRINT '. DO YOU USE IT?'` |
| 0xA11B | 0x8F26 GOSUB 0xA11B | `0xA11B 0x12 PRINTCLEAR 'A VOICE ISSUES OVER THE INTERCOM.'` |
| 0xA139 | 0x94C0 GOSUB 0xA139<br>0x98B4 GOSUB 0xA139 | `0xA139 0x12 PRINTCLEAR 'A SIGN OVER THE DOOR READS:'` |
|  |  | `0xA151 0x33 PRINT RETURN` |
|  |  | `0xA152 0x33 PRINT RETURN` |

### ECL 114 - GEO 114: Jupiter Finale

Attached still-missing strings:
- 0xA379: owner 0xA341; `branch_target_region` `WHO WILL DO IT?`. incoming: 0x82B1 GOSUB 0xA341

| Target/Addr | Incoming / Instruction | Extracted text or menu |
|---:|---|---|
| 0x8014 | entry ecl_initial_entry | `0x8064 0x12 PRINTCLEAR 'YOU JUMP OFF THE SHUTTLE ONTO THE OPEN DECK OF THE MINING RIG.'` |
| 0x80B6 | 0x82B5 ON GOTO area1.event_word_210 choice 0 | `0x80BC 0x11 PRINT "PLEASE REPORT TO THE BOSS, IN HER NEST IN THE PROW.'"` |
| 0x80E8 | entry vm_run_1 | `0x811A 0x12 PRINTCLEAR 'SAVAGE WINDS STOP YOU FROM GOING FARTHER AFT ON THE WING.'` |
| 0x8150 | 0x80FE GOTO 0x8150 | `0x8150 0x12 PRINTCLEAR 'THE AIRCAR HATCH'` |
|  |  | `0x8166 0x11 PRINT ' IS SHUT'` |
|  |  | `0x816F 0x11 PRINT '. '` |
|  |  | `0x8183 0x11 PRINT 'GO DOWN INTO THE AIRCAR?'` |
|  |  | `0x8199 0x11 PRINT 'GO BACK ONTO THE RIG?'` |
| 0x821D | 0x8211 GOTO 0x821D | `0x8265 0x12 PRINTCLEAR 'THE LIVING SHIP HOVERS 40 METERS OVERHEAD, BLOTTING OUT THE SKY!'` |
| 0x82B5 |  | `0x82C4 0x11 PRINT "ALERT! ALL DEFENDERS TO THE SHUTTLE DECK!'"` |
| 0x82E9 | 0x82B5 ON GOTO area1.event_word_210 choice 2 | `0x82F4 0x11 PRINT 'HELP US SEARCH THE RIG FOR '` |
|  |  | `0x8313 0x11 PRINT "ENEMIES.'"` |
|  |  | `0x831E 0x11 PRINT "MINES.'"` |
| 0x8329 | 0x82B5 ON GOTO area1.event_word_210 choice 1<br>0x82F0 GOTO 0x8329 | `0x8337 0x11 PRINT 'EMERGENCY! '` |
| 0x8343 | 0x97B8 GOTO 0x8343 | `0x8343 0x11 PRINT "REPORT TO THE AIRCAR HATCH MIDSHIPS.'"` |
| 0x83B9 | 0x821D ON GOTO area1.event_word_206 choice 1 | `0x83B9 0x12 PRINTCLEAR 'A POWER ROOM.'` |
| 0x83D3 | 0x821D ON GOTO area1.event_word_206 choice 2 | `0x83D3 0x12 PRINTCLEAR 'GAS MINING TOOLS.'` |
| 0x83E4 | 0x821D ON GOTO area1.event_word_206 choice 3 | `0x83E4 0x12 PRINTCLEAR 'THIS CELL IS WAIST-DEEP IN CRYSTALIZED GAS COMPOUNDS.'` |
| 0x8410 | 0x821D ON GOTO area1.event_word_206 choice 4 | `0x8410 0x12 PRINTCLEAR 'AUTOMATIC SAFETY NET LAUNCHERS. CHECK THE NETS?'` |
| 0x84CC | 0x83CE GOTO 0x84CC | `0x84CC 0x11 PRINT ' A BOMB BLAST HAS CRIPPLED IT BEYOND REPAIR!'` |
| 0x84F1 | 0x84C4 GOTO 0x84F1 | `0x84F1 0x12 PRINTCLEAR 'YOU FIND AN UNEXPLODED MINE! TRY TO DISARM?'` |
| 0x85ED | 0x85E1 GOTO 0x85ED | `0x860B 0x12 PRINTCLEAR 'THE MATRIX DEVICE HUMS ALONG NICELY.'` |
| 0x862B | 0x85ED ON GOTO area1.event_word_21E choice 0 | `0x862E 0x12 PRINTCLEAR "MAKALI IS HERE. 'WE HAVE UNPACKED THE MATRIX MODULES.'"` |
| 0x87DF | 0x85ED ON GOTO area1.event_word_21E choice 1<br>0x8872 GOTO 0x87DF<br>0x8AA3 GOTO 0x87DF | `0x87DF 0x12 PRINTCLEAR 'THE SCIENTISTS WORK GRIMLY BEHIND A WALL OF ROBOTS.'` |
| 0x8868 | 0x85ED ON GOTO area1.event_word_21E choice 5 | `0x889C 0x12 PRINTCLEAR "'HERE THEY ARE!' THE HATCH BANGS SHUT BEHIND YOU, AND NIKITA DIVES THE AIRCAR AWAY FROM THE RIG."` |
| 0x8A99 | 0x8A67 GOTO 0x8A99 | `0x8AC8 0x12 PRINTCLEAR 'A VALVE HISSES.'` |
| 0x8D39 | 0x821D ON GOTO area1.event_word_206 choice 17 | `0x8D4D 0x12 PRINTCLEAR 'YOU ENTER THE BRAIN OF THE SHIP. RAM TECHS CONTROL IT WITH STUNNERS.'` |
| 0x8FC6 | 0x85ED ON GOTO area1.event_word_21E choice 6 | `0x8FD1 0x12 PRINTCLEAR 'YOU APPROACH THE SCIENTISTS...'` |
| 0x9056 | 0x85ED ON GOTO area1.event_word_21E choice 7 | `0x9064 0x12 PRINTCLEAR "'WE MUSST READY THE MATRIX DEVICE! WE NEED IT TO POWER THE RIG!'"` |
| 0x90B7 | 0x8FCD GOTO 0x90B7 | `0x90BA 0x12 PRINTCLEAR 'MAKALI AND LEANDER TOIL MADLY TO BUILD THE MATRIX DEVICE.'` |
| 0x9733 | 0x821D ON GOTO area1.event_word_206 choice 9 | `0x9733 0x12 PRINTCLEAR 'YOU ENTER A COZY NEST STUFFED WITH CONTROLS. THE RIG BOSS '` |
|  |  | `0x9776 0x11 PRINT 'IS HERE, A RESOURCEFUL WOMAN TINKER NAMED NIKITA.'` |
|  |  | `0x97A2 0x12 PRINTCLEAR "'AFTER YOU TOUR THE RIG, "` |
| 0x97BC | 0x976C GOTO 0x97BC | `0x97E4 0x11 PRINT "CONGRATULATES YOU! 'WELL DONE!'"` |
|  |  | `0x9800 0x11 PRINT 'IS WORRIED.'` |
| 0x987A | 0x97BC ON GOTO area1.event_word_21E choice 5 | `0x987A 0x11 PRINT 'IS NOT HERE.'` |
|  |  | `0x989A 0x11 PRINT ' AN ECG IS!'` |
| 0x98B9 | 0x97BC ON GOTO area1.event_word_21E choice 0 | `0x98B9 0x11 PRINT 'IS TOO BUSY DIRECTING ROBOTS TO TALK TO YOU.'` |
| 0x98DE | 0x97BC ON GOTO area1.event_word_21E choice 4 | `0x98E4 0x11 PRINT 'IS BARELY VISIBLE BEHIND THE PILED BODIES OF RAM ATTACKERS.'` |
| 0x9945 | 0x97BC ON GOTO area1.event_word_21E choice 2 | `0x994F 0x11 PRINT 'SAYS, '` |
|  |  | `0x9958 0x11 PRINT 'REPORTS THAT ALL RAM INVADERS ARE DEAD. '` |
|  |  | `0x9982 0x11 PRINT "'OK TO PATROL OR TAKE A REST.'"` |
| 0x99FA | 0x97BC ON GOTO area1.event_word_21E choice 6 | `0x9A12 0x11 PRINT 'PUSHES A DEAD ECG OFF HER CONTROLS.'` |
|  |  | `0x9A31 0x11 PRINT 'IS REDEPLOYING HER ROBOTS.'` |
|  |  | `0x9A52 0x12 PRINTCLEAR "'BETTER GET OUT ON DECK. RAM MUST KNOW THE ECGS ARE DEAD.'"` |
| 0x9A88 | 0x9A04 GOTO 0x9A88 | `0x9A88 0x11 PRINT "REFERS TO SOME SENSORS. '"` |
|  |  | `0x9AA5 0x11 PRINT "WE STILL HAVE ENEMIES SOMEWHERE ON BOARD.'"` |
|  |  | `0x9AC9 0x11 PRINT "ALL RAM ROBOTS ARE DESTROYED. BETTER CHECK IN WITH LEANDER.'"` |
| 0x9B0A | 0x97BC ON GOTO area1.event_word_21E choice 7 | `0x9B0A 0x11 PRINT "SHOUTS, 'SABOTAGE! WE'RE LOSING LIFT! "` |
|  |  | `0x9B35 0x11 PRINT "ANY MORE BLASTS WILL KILL US ALL!'"` |
| 0x9B77 | 0x9B31 GOTO 0x9B77 | `0x9B77 0x11 PRINT "TELL THE SCIENTISTS TO DO SOMETHING, NOW!'"` |
| 0x9BA1 | 0x821D ON GOTO area1.event_word_206 choice 10 | `0x9BAC 0x12 PRINTCLEAR 'DOORS HISS OPEN.'` |
| 0x9BBC | 0x821D ON GOTO area1.event_word_206 choice 11 | `0x9BBC 0x12 PRINTCLEAR 'A CLINIC. '` |
|  |  | `0x9BC7 0x11 PRINT 'START THE AUTOSURGEONS?'` |
| 0x9C28 |  | `0x9C64 0x12 PRINTCLEAR 'TWO SPEED AHEAD OF THE OTHERS. THEY SEEM FAMILIAR...'` |
| 0x9F0E | 0x9C28 ON GOTO area1.event_word_21E choice 5 | `0x9F19 0x12 PRINTCLEAR 'YOU SEE CREATURES LEAP TO THE RIG DECK!'` |
| 0xA125 | 0x821D ON GOTO area1.event_word_206 choice 15 | `0xA13C 0x12 PRINTCLEAR 'A HEAP OF BURNED ECGS.'` |
|  |  | `0xA182 0x12 PRINTCLEAR 'BEINGS BRED TO KILL!'` |
| 0xA1D4 | 0xA137 GOTO 0xA1D4<br>0xA171 GOTO 0xA1D4 | `0xA1DC 0x12 PRINTCLEAR 'YOU HEAR ECGS NEARBY, BUT THEY AVOID YOU.'` |
| 0xA2CF | 0x979E GOSUB 0xA2CF | `0xA2D9 0x12 PRINTCLEAR 'SHE BRIEFS YOU ON THE SITUATION,'` |
| 0xA305 | 0x84A1 GOSUB 0xA305<br>0x84C8 GOSUB 0xA305 | `0xA305 0x12 PRINTCLEAR 'A POWER POD.'` |
