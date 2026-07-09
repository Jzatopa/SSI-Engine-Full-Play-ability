/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0ba5
 * Ghidra name: FUN_0000_0ba5
 * Linear address: 0x00BA5
 * Original GAME.OVR file offset: 2989
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0ba5(void)

{
  undefined2 in_DX;
  int unaff_BP;
  undefined2 unaff_SS;
  
  *(undefined2 *)(unaff_BP + -2) = in_DX;
                    /* WARNING: Subroutine does not return */
  FUN_0000_06d5();
}


