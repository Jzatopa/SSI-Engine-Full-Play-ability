/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7105
 * Ghidra name: FUN_0000_7105
 * Linear address: 0x07105
 * Original GAME.OVR file offset: 28941
 * Body addresses: 39
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_7105(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 uVar1;
  
  uVar1 = 0xff;
  func_0x0000d6dc();
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS,uVar1);
}


