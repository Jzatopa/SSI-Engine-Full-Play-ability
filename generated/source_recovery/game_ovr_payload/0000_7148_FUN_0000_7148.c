/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7148
 * Ghidra name: FUN_0000_7148
 * Linear address: 0x07148
 * Original GAME.OVR file offset: 29008
 * Body addresses: 20
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_7148(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(char *)0x5359 < '\x02') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS);
  }
  return;
}


