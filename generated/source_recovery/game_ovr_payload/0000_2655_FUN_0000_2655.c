/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2655
 * Ghidra name: FUN_0000_2655
 * Linear address: 0x02655
 * Original GAME.OVR file offset: 9821
 * Body addresses: 12
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_2655(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
                    /* WARNING: Subroutine does not return */
  FUN_0000_06d5();
}


