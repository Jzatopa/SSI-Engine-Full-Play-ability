/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0832
 * Ghidra name: FUN_0000_0832
 * Linear address: 0x00832
 * Original GAME.OVR file offset: 2106
 * Body addresses: 46
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_0832(void)

{
  int unaff_BP;
  undefined2 unaff_DI;
  undefined2 unaff_SS;
  
  FUN_0000_49de(unaff_DI);
  FUN_0000_3721(0x21a,*(undefined2 *)(*(int *)(unaff_BP + 6) + -4),
                *(undefined2 *)(*(int *)(unaff_BP + 6) + -2),0);
  FUN_0000_453c(*(int *)(unaff_BP + 6) + -4);
  return;
}


