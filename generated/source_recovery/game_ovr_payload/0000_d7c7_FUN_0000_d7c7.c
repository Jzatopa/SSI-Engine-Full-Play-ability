/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:d7c7
 * Ghidra name: FUN_0000_d7c7
 * Linear address: 0x0D7C7
 * Original GAME.OVR file offset: 55247
 * Body addresses: 37
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x0000d7d7) overlaps instruction at (ram,0x0000d7d4)
    */

void FUN_0000_d7c7(void)

{
  char in_DH;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  bool in_ZF;
  
  if (in_CF || in_ZF) {
    *(char *)(unaff_SI + 0x25) = *(char *)(unaff_SI + 0x25) + in_DH;
  }
  else {
    unaff_CS = 0x99;
    func_0x000009c9();
    if (*(char *)*(undefined4 *)(unaff_BP + 6) == '\0') {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x168a,unaff_CS,(undefined *)&DAT_0000_ffba + unaff_BP,unaff_SS,
                *(undefined2 *)(unaff_BP + 0xc));
}


