/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:08c5
 * Ghidra name: FUN_0000_08c5
 * Linear address: 0x008C5
 * Original GAME.OVR file offset: 2253
 * Body addresses: 78
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_08c5(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  
  FUN_0000_49de(unaff_DI,unaff_DS);
  FUN_0000_3721(0x21a,*(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2),7,0);
  uVar2 = unaff_SS;
  FUN_0000_453c(unaff_BP + -4);
  cVar1 = FUN_0000_00d2(5);
  if (cVar1 != '\0') {
    FUN_0000_03ab(0x21a);
    FUN_0000_07e8(0x21a);
    FUN_0000_016c();
    FUN_0000_09b1();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x790,0x21a,(undefined *)&DAT_0000_fff5 + unaff_BP,unaff_SS,uVar2);
}


