# Gold Box ECL Text Context

This report attaches the Gold Box whole-block strings that are still missing
after substring comparison to nearby decoded ECL rows. It is evidence for
future dialog/menu reconstruction, not runtime text promotion.

## Summary

- Context rows: 123
- Address mapping: `vm_address = 0x8000 + decoded ECL block offset`
- `inline_text_fragment`: 7
- `label_fragment`: 13
- `short_choice_or_label`: 103

## Context Rows

| ECL | Offset | VM address | Kind | Text | Previous decoded row | Next decoded row |
|---:|---:|---:|---|---|---|---|
| 1 | 0x010B | 0x810B | short_choice_or_label | DUEL | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x011E | 0x811E | short_choice_or_label | PREV | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x0165 | 0x8165 | short_choice_or_label | DROPBUCK | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x016D | 0x816D | short_choice_or_label | PREV | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x01A0 | 0x81A0 | short_choice_or_label | SPRITE | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x01A7 | 0x81A7 | short_choice_or_label | BOXPIC | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x01BA | 0x81BA | short_choice_or_label | PREV | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x0297 | 0x8297 | label_fragment | X POSITION: | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x02A9 | 0x82A9 | label_fragment | Y POSITION: | 0x80CA 0x00 EXIT | 0x835A 0x09 SAVE area1.event_word_258 = 0 |
| 1 | 0x03BC | 0x83BC | inline_text_fragment | FIGHT WHICH SHIP TYPE? | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0452 | 0x8452 | short_choice_or_label | SHIP # | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0629 | 0x8629 | short_choice_or_label | SKILL | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0640 | 0x8640 | short_choice_or_label | VIEW | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x068F | 0x868F | short_choice_or_label | PRSKILL | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0700 | 0x8700 | short_choice_or_label | WHICH ONE? | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0750 | 0x8750 | short_choice_or_label | PERSON # | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x07C3 | 0x87C3 | short_choice_or_label | WHICH ONE? | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0814 | 0x8814 | short_choice_or_label | PERSON # | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0887 | 0x8887 | short_choice_or_label | WHICH ONE? | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0933 | 0x8933 | short_choice_or_label | PERSON # | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0A34 | 0x8A34 | short_choice_or_label | BIGPIC | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0A49 | 0x8A49 | short_choice_or_label | WILD | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 1 | 0x0A65 | 0x8A65 | label_fragment | PICTURE: | 0x836C 0x20 NEWECL <load ECL area2.event_scratch1 and exit> |  |
| 17 | 0x09D0 | 0x89D0 | short_choice_or_label | EPHESUS | 0x89CD 0x09 SAVE scratch.word_0000 = abs_0006 | 0x89D9 0x09 SAVE scratch.word_0208 = abs_0004 |
| 17 | 0x18E0 | 0x98E0 | short_choice_or_label | HELP ROMNEY | 0x96DD 0x12 PRINTCLEAR "A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DESPERATELY. 'I AM DR. ROMNEY. PLEASE HELP ME GET TO THE SUN KING. IT IS MOST URGENT.'" | 0x9B80 0x03 COMPARE Values: 0 == abs_C04E |
| 17 | 0x212F | 0xA12F | short_choice_or_label | SOMEONE ELSE? | 0xA0AA 0x12 PRINTCLEAR "THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'" | 0xA176 0x09 SAVE scratch.word_0208 = abs_0005 |
| 18 | 0x083B | 0x883B | short_choice_or_label | BUCK CONTINUES, | 0x82BA 0x00 EXIT | 0x9128 0x09 SAVE area1.LastEclBlockId = 18 |
| 18 | 0x191A | 0x991A | short_choice_or_label | WHO BETS? | 0x9895 0x12 PRINTCLEAR 'AN UNKEMPT LOOKING ROCKET JOCK STEPS UP.' | 0x9B01 0x0E PICTURE block_id: 80 |
| 18 | 0x1D6C | 0x9D6C | short_choice_or_label | HOW MUCH? | 0x9D42 0x12 PRINTCLEAR 'YOU LEAVE THE BAR.' |  |
| 19 | 0x12D6 | 0x92D6 | short_choice_or_label | BLUFF | 0x925F 0x01 GOTO 0x004C | 0x957C 0x04 ADD area1.event_word_204 = 1 + area1.event_word_204 |
| 19 | 0x1874 | 0x9874 | label_fragment | HULL: | 0x9850 0x13 RETURN | 0x9B85 0x09 SAVE area1.event_word_204 = 0 |
| 19 | 0x1893 | 0x9893 | label_fragment | SENSORS: | 0x9850 0x13 RETURN | 0x9B85 0x09 SAVE area1.event_word_204 = 0 |
| 19 | 0x18B4 | 0x98B4 | label_fragment | CONTROLS: | 0x9850 0x13 RETURN | 0x9B85 0x09 SAVE area1.event_word_204 = 0 |
| 19 | 0x18F7 | 0x98F7 | label_fragment | ENGINES: | 0x9850 0x13 RETURN | 0x9B85 0x09 SAVE area1.event_word_204 = 0 |
| 20 | 0x02FB | 0x82FB | short_choice_or_label | DEPOSIT | 0x82F4 0x01 GOTO 0x004C | 0x8464 0x09 SAVE scratch.word_0216 = 0 |
| 20 | 0x033A | 0x833A | short_choice_or_label | WHICH ONE? | 0x82F4 0x01 GOTO 0x004C | 0x8464 0x09 SAVE scratch.word_0216 = 0 |
| 20 | 0x038C | 0x838C | short_choice_or_label | WHICH ONE? | 0x82F4 0x01 GOTO 0x004C | 0x8464 0x09 SAVE scratch.word_0216 = 0 |
| 20 | 0x1653 | 0x9653 | short_choice_or_label | HOW MUCH? | 0x9647 0x13 RETURN | 0x9661 0x03 COMPARE Values: area1.event_word_28E == 0 |
| 20 | 0x18BE | 0x98BE | short_choice_or_label | EETBUGS B+G | 0x98A7 0x13 RETURN | 0x9CE0 0x03 COMPARE Values: 2 == area1.event_word_202 |
| 20 | 0x1AE8 | 0x9AE8 | short_choice_or_label | CONVINCE | 0x98A7 0x13 RETURN | 0x9CE0 0x03 COMPARE Values: 2 == area1.event_word_202 |
| 20 | 0x1B07 | 0x9B07 | short_choice_or_label | WHO WILL TRY? | 0x98A7 0x13 RETURN | 0x9CE0 0x03 COMPARE Values: 2 == area1.event_word_202 |
| 20 | 0x1B3C | 0x9B3C | short_choice_or_label | WHO WILL TRY? | 0x98A7 0x13 RETURN | 0x9CE0 0x03 COMPARE Values: 2 == area1.event_word_202 |
| 33 | 0x0898 | 0x8898 | short_choice_or_label | RESIDENTS | 0x87D5 0x12 PRINTCLEAR 'A LOCKER ROOM MADE INTO A KITCHEN.' | 0x89A7 0x2F AND area2.event_scratch0 = 64 & area1.event_word_2A8 |
| 33 | 0x0C7D | 0x8C7D | short_choice_or_label | HELP LEECHES | 0x8C23 0x00 EXIT | 0x8DB2 0x03 COMPARE Values: 0 == abs_C04E |
| 33 | 0x16C8 | 0x96C8 | short_choice_or_label | DECLINE | 0x9672 0x00 EXIT | 0x973A 0x03 COMPARE Values: 5 == area1.event_word_2AE |
| 33 | 0x183C | 0x983C | short_choice_or_label | FIGHT MONKS | 0x97D2 0x00 EXIT | 0x9A0B 0x03 COMPARE Values: 5 == area1.event_word_2AE |
| 33 | 0x1ADB | 0x9ADB | short_choice_or_label | CHEER | 0x9A3E 0x00 EXIT | 0x9B2C 0x2F AND area2.event_scratch0 = 1 & area1.event_word_2B2 |
| 34 | 0x1726 | 0x9726 | inline_text_fragment | LOOK FOR HIS NOTES | 0x966D 0x12 PRINTCLEAR "CHADE BEGINS SEARCHING THE ROOM, THEN SUDDENLY PULLS UP AND COCKS HIS HEAD TO ONE SIDE AS THOUGH LISTENING. 'WE MUST FIND MY DAUGHTER RIGHT AWAY. FORGET MY NOTES.'" | 0x9851 0x03 COMPARE Values: 0 == abs_C04E |
| 36 | 0x0186 | 0x8186 | short_choice_or_label | RISER? | 0x8183 0x09 SAVE scratch.word_0208 = abs_0006 | 0x818F 0x2F AND area2.event_scratch0 = 1 & area1.event_word_288 |
| 36 | 0x052E | 0x852E | short_choice_or_label | PICK LOCK | 0x8527 0x01 GOTO 0x004C | 0x876D 0x09 SAVE area2.game_area = 1 |
| 36 | 0x053C | 0x853C | short_choice_or_label | KNOCK | 0x8527 0x01 GOTO 0x004C | 0x876D 0x09 SAVE area2.game_area = 1 |
| 36 | 0x113A | 0x913A | inline_text_fragment | DOOR IN FRONT OF YOU | 0x90ED 0x00 EXIT | 0x9212 0x2F AND area2.event_scratch0 = 4 & area1.event_word_2C8 |
| 36 | 0x1CF2 | 0x9CF2 | short_choice_or_label | WHO WILL TRY? | 0x9C73 0x00 EXIT | 0x9D0D 0x09 SAVE area2.event_scratch2 = 1 |
| 37 | 0x0397 | 0x8397 | short_choice_or_label | GROTESQUES | 0x838B 0x00 EXIT | 0x83D6 0x2F AND area2.event_scratch0 = area1.event_word_206 & area1.event_word_2B4 |
| 37 | 0x03A3 | 0x83A3 | short_choice_or_label | WHITE MONKS | 0x838B 0x00 EXIT | 0x83D6 0x2F AND area2.event_scratch0 = area1.event_word_206 & area1.event_word_2B4 |
| 37 | 0x076C | 0x876C | short_choice_or_label | DECLINE | 0x8716 0x00 EXIT | 0x87D8 0x2F AND area2.event_scratch0 = 60 & area1.event_word_2B0 |
| 37 | 0x17D7 | 0x97D7 | short_choice_or_label | KILL HIM | 0x94AF 0x00 EXIT | 0x97F2 0x2F AND area2.event_scratch0 = 4 & area1.event_word_2B6 |
| 37 | 0x2345 | 0xA345 | short_choice_or_label | WHO WILL TRY? | 0xA28B 0x11 PRINT ' NOTICES A TRIPWIRE STRETCHED ACROSS THE RUBBLE. DO YOU TRY TO DISARM THE DEMO CHARGES?' | 0xA3D1 0x2F AND area2.event_scratch0 = 1 & area1.event_word_2B2 |
| 38 | 0x093B | 0x893B | short_choice_or_label | SMOKING GUN SLOTS | 0x88F5 0x11 PRINT 'RED RIVER BAR' | 0x8949 0x03 COMPARE Values: area1.event_word_204 == 13 |
| 38 | 0x0B85 | 0x8B85 | short_choice_or_label | SOMEONE ELSE? | 0x8968 0x12 PRINTCLEAR 'A MAN IN A RAGGED MILITARY UNIFORM SITS AGAINST THE WALL HERE.' | 0x8BB9 0x2F AND area2.event_scratch0 = 1 & area1.event_word_298 |
| 48 | 0x0F66 | 0x8F66 | short_choice_or_label | HIS SPEECH | 0x8EA8 0x00 EXIT | 0x8FA1 0x09 SAVE mapDirection = 3 |
| 49 | 0x0455 | 0x8455 | short_choice_or_label | OPEN LOCK | 0x8451 0x00 EXIT | 0x852B 0x2F AND area2.event_scratch0 = 1 & area1.event_word_2E6 |
| 50 | 0x0882 | 0x8882 | short_choice_or_label | HE CONTINUES, | 0x8840 0x12 PRINTCLEAR "LEANDER MEETS YOU. 'THANKSS FOR TURNING OFF THE FIELD. WE MUSST SSTILL HURRY!'" | 0x88F3 0x12 PRINTCLEAR 'THE BODY OF A ' |
| 50 | 0x0F39 | 0x8F39 | short_choice_or_label | MOVE CLOSER | 0x8F04 0x00 EXIT | 0x916F 0x2F AND area2.event_scratch0 = 128 & area1.event_word_2FE |
| 64 | 0x024E | 0x824E | short_choice_or_label | COPERNICUS POLICE | 0x824B 0x09 SAVE scratch.word_0258 = abs_000D | 0x825E 0x01 GOTO 0x9830 |
| 64 | 0x0450 | 0x8450 | short_choice_or_label | HE CONTINUES, | 0x8372 0x12 PRINTCLEAR "A MAN IN LUNA GREY SHAKES YOUR HANDS. 'WELCOME. SORRY ABOUT YOUR SHIP, BUT THERE ARE A FEW PROBLEMS." | 0x8495 0x03 COMPARE Values: 1 == area1.event_word_214 |
| 64 | 0x1475 | 0x9475 | short_choice_or_label | GIOTTO MINING | 0x9472 0x09 SAVE scratch.word_0258 = abs_000A | 0x9482 0x01 GOTO 0x9830 |
| 64 | 0x2036 | 0xA036 | short_choice_or_label | WHO WILL TRY? | 0x9856 0x12 PRINTCLEAR 'THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?' | 0xA308 0x09 SAVE mapPosX = area1.lastXPos |
| 64 | 0x204E | 0xA04E | short_choice_or_label | WHICH FILE? | 0x9856 0x12 PRINTCLEAR 'THERE IS A VIDEO-PHONE HERE. DO YOU WISH TO USE IT?' | 0xA308 0x09 SAVE mapPosX = area1.lastXPos |
| 64 | 0x239E | 0xA39E | short_choice_or_label | PREV | 0xA357 0x13 RETURN |  |
| 65 | 0x0740 | 0x8740 | short_choice_or_label | SHE CONTINUES | 0x8641 0x00 EXIT | 0x87F3 0x03 COMPARE Values: 1 == area1.event_word_21A |
| 65 | 0x1765 | 0x9765 | short_choice_or_label | WHO WILL TRY? | 0x9761 0x00 EXIT |  |
| 66 | 0x0932 | 0x8932 | short_choice_or_label | DECLINE | 0x8672 0x11 PRINT 'THE AIR LOCK BEGINS CYCLING.' | 0x8A10 0x0E PICTURE block_id: 30 |
| 66 | 0x0B57 | 0x8B57 | short_choice_or_label | HE CONTINUES | 0x8A13 0x12 PRINTCLEAR "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES." | 0x8EB0 0x2F AND area2.event_scratch0 = 32 & area1.event_word_212 |
| 66 | 0x0B63 | 0x8B63 | short_choice_or_label | HIS OFFER | 0x8A13 0x12 PRINTCLEAR "'WELCOME TO THE ROGUE. I AM KILLER KANE. YOU MAY CALL ME MR. KANE. IT IS MOST UNFORTUNATE YOUR SHIP HAD SUCH...DIFFICULTIES." | 0x8EB0 0x2F AND area2.event_scratch0 = 32 & area1.event_word_212 |
| 66 | 0x154B | 0x954B | short_choice_or_label | DECLINE | 0x94E6 0x00 EXIT | 0x9602 0x12 PRINTCLEAR 'THE CONTROL PANEL FOR THIS RESTRICTED ACCESS ELEVATOR REQUIRES A LOW LEVEL RAM SECURITY CARD.' |
| 66 | 0x1C01 | 0x9C01 | short_choice_or_label | WHO TRIES? | 0x9B9F 0x00 EXIT | 0x9CCE 0x12 PRINTCLEAR 'CREW MEMBERS IN EXERCISE OUTFITS PASS YOU. ' |
| 80 | 0x1674 | 0x9674 | inline_text_fragment | WILL SOMEONE TRY TO | 0x9652 0x11 PRINT "'" | 0x9C4B 0x2F AND area2.event_scratch0 = 32 & area1.event_word_20A |
| 80 | 0x17E6 | 0x97E6 | short_choice_or_label | CLOSE LINKS | 0x9652 0x11 PRINT "'" | 0x9C4B 0x2F AND area2.event_scratch0 = 32 & area1.event_word_20A |
| 80 | 0x19D7 | 0x99D7 | short_choice_or_label | HELP HIM | 0x9652 0x11 PRINT "'" | 0x9C4B 0x2F AND area2.event_scratch0 = 32 & area1.event_word_20A |
| 80 | 0x238E | 0xA38E | inline_text_fragment | WHO WILL DO IT? | 0xA373 0x13 RETURN |  |
| 81 | 0x020C | 0x820C | short_choice_or_label | WHO TRIES? | 0x81C0 0x11 PRINT "SHE EYES YOU WARILY. 'DO YOU HAVE BUSINESS WITH US?'" | 0x82C8 0x12 PRINTCLEAR "THE RECEPTIONIST TENSES. 'I DON'T KNOW WHO YOU THINK YOU ARE, BUT I KNOW HOW TO DEAL WITH YOU! GUARDS!'" |
| 81 | 0x0463 | 0x8463 | short_choice_or_label | OPEN LOCKS | 0x845F 0x00 EXIT | 0x84A6 0x14 COMPARE AND Values: 2 == mapDirection && 7 == mapPosX |
| 81 | 0x1617 | 0x9617 | short_choice_or_label | HE CONTINUES | 0x9585 0x12 PRINTCLEAR "AN EMACIATED MAN IN A TATTERED LAB COAT APPROACHES. IT'S DR. ROMNEY!" | 0x9639 0x12 PRINTCLEAR 'DR. ROMNEY MEETS YOU IN THE HALL.' |
| 82 | 0x02E3 | 0x82E3 | short_choice_or_label | WILBUR | 0x82AA 0x12 PRINTCLEAR 'A GUARD STEPS UP AND ASKS FOR A PASSWORD. WHAT DO YOU SAY?' | 0x8310 0x12 PRINTCLEAR 'THE GUARD LETS YOU THROUGH.' |
| 82 | 0x0D0F | 0x8D0F | short_choice_or_label | ELROY | 0x8D0C 0x03 COMPARE Values: 32633 == abs_0004 | 0x8D16 0x17 IF <> <if compare flag is false, skip next op> |
| 82 | 0x1124 | 0x9124 | short_choice_or_label | WHO WILL TRY? | 0x90E8 0x12 PRINTCLEAR 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?' | 0x91E5 0x2F AND area2.event_scratch0 = 32 & area1.event_word_34E |
| 82 | 0x1161 | 0x9161 | short_choice_or_label | WILBUR | 0x90E8 0x12 PRINTCLEAR 'THERE IS A COMPUTER HERE. DO YOU ATTEMPT TO USE IT?' | 0x91E5 0x2F AND area2.event_scratch0 = 32 & area1.event_word_34E |
| 82 | 0x1329 | 0x9329 | short_choice_or_label | WHO WILL TRY? | 0x92EF 0x12 PRINTCLEAR 'YOU NOTE A SUBROUTINE CONTAINING PASSWORDS. DO YOU TRY TO ACCESS?' | 0x9385 0x2F AND area2.event_scratch0 = 64 & area1.event_word_34A |
| 84 | 0x0350 | 0x8350 | short_choice_or_label | WHO TRIES? | 0x830E 0x12 PRINTCLEAR 'THE TERMINAL OF THIS COMPUTER IS ACTIVE. DO YOU TRY TO OPERATE THE COMPUTER?' | 0x839D 0x12 PRINTCLEAR 'THE COMPUTER SCREEN READS:' |
| 84 | 0x0880 | 0x8880 | short_choice_or_label | WHO TRIES? | 0x881C 0x12 PRINTCLEAR 'SEARCHING THE LAB, YOU FIND PARTS OF A DISMANTLED LASER RIFLE.' | 0x8905 0x03 COMPARE Values: mapDirection == 2 |
| 84 | 0x0BED | 0x8BED | short_choice_or_label | KILL HIM | 0x8976 0x00 EXIT | 0x8C77 0x03 COMPARE Values: mapDirection == 0 |
| 84 | 0x1A0B | 0x9A0B | short_choice_or_label | WHO TRIES? | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" | 0xA1D0 0x03 COMPARE Values: mapDirection == 0 |
| 84 | 0x1A8B | 0x9A8B | short_choice_or_label | SEE FILES | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" | 0xA1D0 0x03 COMPARE Values: mapDirection == 0 |
| 84 | 0x1B0F | 0x9B0F | short_choice_or_label | SEE FILES | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" | 0xA1D0 0x03 COMPARE Values: mapDirection == 0 |
| 84 | 0x1B7B | 0x9B7B | short_choice_or_label | SEE FILES | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" | 0xA1D0 0x03 COMPARE Values: mapDirection == 0 |
| 84 | 0x1BE6 | 0x9BE6 | short_choice_or_label | SEE FILES | 0x99E1 0x12 PRINTCLEAR "DO YOU TRY TO RETRIEVE DR. MALCOLN'S NOTES?" | 0xA1D0 0x03 COMPARE Values: mapDirection == 0 |
| 95 | 0x1091 | 0x9091 | label_fragment | CHOOSE: | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x10C3 | 0x90C3 | label_fragment | HULL: | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x10D4 | 0x90D4 | label_fragment | SENSORS: | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x10E5 | 0x90E5 | label_fragment | CONTROLS: | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x1107 | 0x9107 | label_fragment | ENGINES: | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x1153 | 0x9153 | short_choice_or_label | HULL | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x1167 | 0x9167 | short_choice_or_label | ENGN | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x12EF | 0x92EF | short_choice_or_label | MISSILE | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x146D | 0x946D | label_fragment | CURRENT FUEL: | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x149D | 0x949D | short_choice_or_label | REFUEL | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 95 | 0x15C0 | 0x95C0 | short_choice_or_label | MISSILE | 0x8EF5 0x01 GOTO 0x004C | 0x96F5 0x01 GOTO 0x8D0E |
| 96 | 0x2293 | 0xA293 | short_choice_or_label | CONVINCE | 0xA1D7 0x11 PRINT 'THEY ATTACK!' | 0xA353 0x03 COMPARE Values: 3 == area1.event_word_204 |
| 96 | 0x2310 | 0xA310 | short_choice_or_label | WHO WILL TRY? | 0xA1D7 0x11 PRINT 'THEY ATTACK!' | 0xA353 0x03 COMPARE Values: 3 == area1.event_word_204 |
| 97 | 0x0040 | 0x8040 | short_choice_or_label | PE:PE:BPDB | 0x803F 0x09 SAVE scratch.word_0002 = scratch.word_0002 | 0x8046 0x09 SAVE scratch.word_0004 = scratch.word_0004 |
| 97 | 0x1B49 | 0x9B49 | short_choice_or_label | CONVINCE | 0x9AB4 0x00 EXIT | 0x9C6B 0x12 PRINTCLEAR 'THE PASSAGE LEADS UP. DO YOU CONTINUE?' |
| 97 | 0x1BC0 | 0x9BC0 | short_choice_or_label | WHO WILL TRY? | 0x9AB4 0x00 EXIT | 0x9C6B 0x12 PRINTCLEAR 'THE PASSAGE LEADS UP. DO YOU CONTINUE?' |
| 98 | 0x1FAA | 0x9FAA | short_choice_or_label | CONVINCE | 0x9EA3 0x12 PRINTCLEAR 'THE WALLS HERE ARE LIVID AND BULGE WITH AN UNHEALTHY PULSE. DO YOU TRY TO TREAT IT?' | 0xA02F 0x12 PRINTCLEAR 'THE WALLS HERE ARE POCK MARKED WITH HOLES. ' |
| 98 | 0x2021 | 0xA021 | short_choice_or_label | WHO WILL TRY? | 0x9EA3 0x12 PRINTCLEAR 'THE WALLS HERE ARE LIVID AND BULGE WITH AN UNHEALTHY PULSE. DO YOU TRY TO TREAT IT?' | 0xA02F 0x12 PRINTCLEAR 'THE WALLS HERE ARE POCK MARKED WITH HOLES. ' |
| 98 | 0x20A2 | 0xA0A2 | short_choice_or_label | USE DEVICE | 0xA08B 0x01 GOTO 0x004C | 0xA0BB 0x03 COMPARE Values: 0 == 1 |
| 112 | 0x19D3 | 0x99D3 | short_choice_or_label | DEFUSE | 0x9947 0x12 PRINTCLEAR 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?' | 0x9B35 0x03 COMPARE Values: mapDirection == 2 |
| 112 | 0x1AF6 | 0x9AF6 | short_choice_or_label | SOMEONE ELSE? | 0x9947 0x12 PRINTCLEAR 'A TIME BOMB IS ATTACHED TO A COMPUTER CONSOLE. DO YOU TRY TO DISARM IT?' | 0x9B35 0x03 COMPARE Values: mapDirection == 2 |
| 112 | 0x1FCB | 0x9FCB | short_choice_or_label | WHO TRIES? | 0x9ED5 0x11 PRINT ". A SMALL FIRE IS BURNING IN THIS ROOM, AND IT'S BEGINNING TO SPREAD." | 0xA06B 0x2F AND area2.event_scratch0 = 64 & area1.event_word_376 |
| 113 | 0x0600 | 0x8600 | short_choice_or_label | HIS SPEECH | 0x8060 0x00 EXIT | 0x873C 0x00 EXIT |
| 113 | 0x0CCD | 0x8CCD | inline_text_fragment | YOU GO TO FLOOR | 0x8C81 0x12 PRINTCLEAR 'AN ELEVATOR. DO YOU USE IT?' | 0x8D2D 0x09 SAVE area2.event_scratch0 = 1 |
| 113 | 0x1725 | 0x9725 | short_choice_or_label | WHO TRIES? | 0x968A 0x12 PRINTCLEAR 'YOU ENTER A COLD STORAGE ROOM.' | 0x97AF 0x03 COMPARE Values: mapDirection == 1 |
| 114 | 0x2379 | 0xA379 | inline_text_fragment | WHO WILL DO IT? | 0xA348 0x00 EXIT |  |
