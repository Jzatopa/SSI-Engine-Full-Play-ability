/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:6d0d
 * Ghidra name: FUN_0000_6d0d
 * Linear address: 0x06D0D
 * Original GAME.OVR file offset: 27925
 * Body addresses: 74
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_6d0d(void)

{
  undefined1 uVar1;
  char cVar2;
  int unaff_BP;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    FUN_0000_538f();
    while( true ) {
      ((undefined *)&DAT_0000_fff5)[*(int *)(unaff_BP + 6)] =
           ((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)];
      while( true ) {
        if (*(char *)(unaff_BP + -2) < '\x01') {
          FUN_0000_6d4e();
          return;
        }
        if (((undefined *)&DAT_0000_fffa)[*(int *)(unaff_BP + 6)] != '\0') {
          *(undefined1 *)(*(int *)(unaff_BP + 6) + -0xd) = 1;
          if (-1 < (char)((undefined *)&DAT_0000_fff5)[*(int *)(unaff_BP + 6)]) {
            FUN_0000_4cde();
          }
          while (('\0' < *(char *)(unaff_BP + -3) &&
                 (((undefined *)&DAT_0000_fffa)[*(int *)(unaff_BP + 6)] == '\0'))) {
            *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + -1;
            if (*(char *)(unaff_BP + -4) == '\0') {
              cVar2 = FUN_0000_5844(*(undefined2 *)(unaff_BP + 6),0,0,*(undefined2 *)0x534e);
              if (cVar2 == '\0') {
                *(undefined1 *)(unaff_BP + -3) = 0;
              }
            }
            else {
              uVar1 = FUN_0000_55ee(*(undefined2 *)(unaff_BP + 6),0,0,*(undefined2 *)0x534e);
              *(undefined1 *)(unaff_BP + -5) = uVar1;
              *(undefined1 *)(unaff_BP + -4) = 0;
            }
          }
          if (*(char *)(*(int *)(unaff_BP + 6) + -7) == '\0') {
            *(undefined1 *)(*(int *)(unaff_BP + 6) + -7) = 0;
            return;
          }
                    /* WARNING: Subroutine does not return */
          FUN_0000_d6c2(0x268c,unaff_CS,unaff_BP + -0x32,unaff_SS);
        }
        *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + -1;
        cVar2 = FUN_0000_635d(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)0x534e);
        if (cVar2 == '\0') break;
        uVar1 = func_0x000063ea();
        *(undefined1 *)(unaff_BP + -5) = uVar1;
      }
      uVar1 = FUN_0000_4758(*(undefined2 *)(unaff_BP + 6),1,*(undefined2 *)0x534e);
      ((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)] = uVar1;
      if ((-1 < (char)((undefined *)&DAT_0000_fff5)[*(int *)(unaff_BP + 6)]) &&
         (((undefined *)&DAT_0000_fff5)[*(int *)(unaff_BP + 6)] !=
          ((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)])) {
        FUN_0000_4cde();
      }
      if (-1 < (char)((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)]) break;
      *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + *(char *)(unaff_BP + -2);
      *(undefined1 *)(unaff_BP + -2) = 0;
    }
  } while( true );
}


