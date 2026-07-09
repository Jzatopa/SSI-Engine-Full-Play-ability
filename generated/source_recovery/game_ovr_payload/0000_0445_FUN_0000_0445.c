/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0445
 * Ghidra name: FUN_0000_0445
 * Linear address: 0x00445
 * Original GAME.OVR file offset: 1101
 * Body addresses: 2
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0445(void)

{
  uint in_AX;
  int unaff_BP;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x102,unaff_CS,(undefined *)&DAT_0000_fff5 + unaff_BP,unaff_SS,in_AX & 0xff00);
}


