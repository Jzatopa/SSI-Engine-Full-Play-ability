/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:ce54
 * Ghidra name: FUN_0000_ce54
 * Linear address: 0x0CE54
 * Original GAME.OVR file offset: 52828
 * Body addresses: 98
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_ce54(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined2 uVar5;
  int unaff_BP;
  int iVar6;
  undefined2 uVar7;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    uVar5 = func_0x00000dd5(unaff_CS,*(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP),
                            *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP),
                            *(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),2);
    FUN_0000_0e16(0xdb,uVar5);
    FUN_0000_05ad(0xdb,*(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP),
                  *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP),
                  *(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8));
    FUN_0000_05b2(0x56,unaff_BP + -2);
    while( true ) {
      if (*(char *)(unaff_BP + -2) == '\0') {
        if (*(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0xd5) == '\0')
        {
          *(undefined1 *)(unaff_BP + -2) = 1;
        }
      }
      else {
        *(undefined1 *)(unaff_BP + -3) = 0;
      }
      do {
        do {
          if (*(char *)(unaff_BP + -2) != '\0') {
            FUN_0000_ceb6();
            return;
          }
          if (*(char *)(unaff_BP + -3) == '\0') {
            FUN_0000_ceb6();
            return;
          }
          uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3);
          if (*(char *)((int)uVar1 + 0x10) != '\0') {
            while (((uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3),
                    *(char *)((int)uVar1 + 3) != '\0' &&
                    (uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3),
                    '\0' < *(char *)((int)uVar1 + 1))) &&
                   (uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3),
                   *(char *)((int)uVar1 + 1) < '\x14'))) {
              FUN_0000_c73d();
            }
          }
          uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3);
          if ((*(char *)((int)uVar1 + 1) == '\0') ||
             (uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3),
             *(char *)((int)uVar1 + 1) == '\x14')) {
            *(undefined1 *)(unaff_BP + -3) = 0;
          }
          else {
            *(undefined1 *)(unaff_BP + -2) = 0;
          }
        } while ((*(char *)(unaff_BP + -2) != '\0') || (*(char *)(unaff_BP + -3) == '\0'));
        *(char *)(unaff_BP + -0xf) = *(char *)(unaff_BP + -0xf) + '\x01';
        if (0x14 < *(byte *)(unaff_BP + -0xf)) {
          *(undefined1 *)(unaff_BP + -2) = 1;
          cVar2 = FUN_0000_cecb();
          *(bool *)(unaff_BP + -3) = cVar2 == '\0';
        }
        *(undefined1 *)0x7514 = 0;
        uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3);
        uVar7 = (undefined2)((ulong)uVar1 >> 0x10);
        iVar6 = (int)uVar1;
        uVar5 = *(undefined2 *)(iVar6 + 10);
        *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP) = *(undefined2 *)(iVar6 + 8);
        *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP) = uVar5;
        if (*(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0xd5) == '\0')
        {
          *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP) = 0;
          *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP) = 0;
        }
        uVar3 = func_0x00000814();
        *(undefined1 *)(unaff_BP + -4) = uVar3;
        if (*(int *)((undefined *)&DAT_0000_fff4 + unaff_BP) != 0 ||
            *(int *)((undefined *)&DAT_0000_fff6 + unaff_BP) != 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_0000_643a();
        }
        if (*(char *)0x7514 == '\0') {
          uVar1 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf3);
          if (4 < *(byte *)((int)uVar1 + 3)) {
            *(undefined1 *)(unaff_BP + -4) = 1;
          }
          uVar3 = func_0x00000a1e();
          *(undefined1 *)(unaff_BP + -7) = uVar3;
          if (*(char *)(unaff_BP + -7) == '\0') {
            cVar2 = FUN_0000_d805(0x99,unaff_BP + -2);
            if ((cVar2 == '\0') || (*(char *)(unaff_BP + -2) != '\0')) {
              uVar3 = FUN_0000_cecb();
              *(undefined1 *)(unaff_BP + -2) = uVar3;
            }
            else {
              FUN_0000_c73d();
            }
          }
          else {
            uVar3 = FUN_0000_09ba();
            *(undefined1 *)(unaff_BP + -8) = uVar3;
            iVar6 = (uint)(byte)((undefined *)&DAT_0000_74ba)[*(byte *)(unaff_BP + -8)] * 4;
            uVar5 = *(undefined2 *)((undefined *)&DAT_0000_7081 + iVar6);
            *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP) =
                 *(undefined2 *)((undefined *)&DAT_0000_707f + iVar6);
            *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP) = uVar5;
            bVar4 = func_0x00000a23(0x99,*(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP),
                                    *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP),
                                    *(undefined2 *)(unaff_BP + 6));
            if (*(byte *)(unaff_BP + -4) < bVar4) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_0000_643a();
            }
            *(undefined1 *)0x7514 = 1;
          }
        }
      } while (*(char *)0x7514 == '\0');
      cVar2 = func_0x00000a41();
      if (cVar2 == '\0') break;
      uVar3 = FUN_0000_bebd();
      *(undefined1 *)(unaff_BP + -2) = uVar3;
    }
    FUN_0000_0e20();
    unaff_CS = 0xdb;
    FUN_0000_0e25();
  } while( true );
}


