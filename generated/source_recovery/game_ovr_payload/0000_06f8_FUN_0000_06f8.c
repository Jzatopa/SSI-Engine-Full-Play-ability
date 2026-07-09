/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:06f8
 * Ghidra name: FUN_0000_06f8
 * Linear address: 0x006F8
 * Original GAME.OVR file offset: 1792
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_06f8(void)

{
  undefined2 in_AX;
  int unaff_BP;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x212,unaff_CS,(undefined *)&DAT_0000_fff5 + unaff_BP,unaff_SS,in_AX);
}


