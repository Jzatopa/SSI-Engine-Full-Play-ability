/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:070c
 * Ghidra name: FUN_0000_070c
 * Linear address: 0x0070C
 * Original GAME.OVR file offset: 1812
 * Body addresses: 4
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_070c(void)

{
  uint in_AX;
  int unaff_BP;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x21d,unaff_CS,(undefined *)&DAT_0000_ffe5 + unaff_BP,unaff_SS,in_AX & 0xff00);
}


