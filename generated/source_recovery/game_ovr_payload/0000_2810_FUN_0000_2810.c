/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2810
 * Ghidra name: FUN_0000_2810
 * Linear address: 0x02810
 * Original GAME.OVR file offset: 10264
 * Body addresses: 25
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_2810(void)

{
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_4 [2];
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x1d89,unaff_CS,local_4,unaff_SS);
}


