/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:088a
 * Ghidra name: FUN_0000_088a
 * Linear address: 0x0088A
 * Original GAME.OVR file offset: 2194
 * Body addresses: 29
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_088a(void)

{
  int unaff_BP;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x3ddb = *(undefined1 *)0x50d2;
  *(undefined1 *)0x50d2 = 6;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x790,unaff_CS,(undefined *)&DAT_0000_fff5 + unaff_BP,unaff_SS,unaff_ES);
}


