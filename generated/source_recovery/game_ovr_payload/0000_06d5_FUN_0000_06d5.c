/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:06d5
 * Ghidra name: FUN_0000_06d5
 * Linear address: 0x006D5
 * Original GAME.OVR file offset: 1757
 * Body addresses: 16
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_06d5(void)

{
  uint in_AX;
  int unaff_BP;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x1f7,unaff_CS,(undefined *)&DAT_0000_ffe5 + unaff_BP,unaff_SS,in_AX & 0xff00);
}


