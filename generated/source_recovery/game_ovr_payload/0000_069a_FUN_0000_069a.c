/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:069a
 * Ghidra name: FUN_0000_069a
 * Linear address: 0x0069A
 * Original GAME.OVR file offset: 1698
 * Body addresses: 24
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_069a(void)

{
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    unaff_DI = unaff_BP + -0xd;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x1e3,unaff_CS,unaff_DI,unaff_SS);
}


