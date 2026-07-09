/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0e7f
 * Ghidra name: FUN_0000_0e7f
 * Linear address: 0x00E7F
 * Original GAME.OVR file offset: 3719
 * Body addresses: 13
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0e7f(void)

{
  undefined1 in_AL;
  char in_CH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + in_CH;
  *(undefined1 *)0x7651 = in_AL;
                    /* WARNING: Subroutine does not return */
  FUN_0000_06d5();
}


