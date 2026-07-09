/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:07e8
 * Ghidra name: FUN_0000_07e8
 * Linear address: 0x007E8
 * Original GAME.OVR file offset: 2032
 * Body addresses: 34
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_07e8(undefined2 param_1,int param_2)

{
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined1 local_8 [6];
  
  *(undefined2 *)(param_2 + -4) = 0;
  *(undefined2 *)(param_2 + -2) = 0;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x710,unaff_CS,local_8,unaff_SS);
}


