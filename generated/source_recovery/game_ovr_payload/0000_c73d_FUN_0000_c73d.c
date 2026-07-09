/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:c73d
 * Ghidra name: FUN_0000_c73d
 * Linear address: 0x0C73D
 * Original GAME.OVR file offset: 51013
 * Body addresses: 35
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_c73d(void)

{
  uint in_AX;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined1 local_20c [522];
  
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0xa03,unaff_CS,local_20c,unaff_SS,in_AX & 0xff00);
}


