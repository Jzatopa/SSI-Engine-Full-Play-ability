/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:872f
 * Ghidra name: FUN_0000_872f
 * Linear address: 0x0872F
 * Original GAME.OVR file offset: 34615
 * Body addresses: 985
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_872f(void)

{
  undefined2 in_DX;
  int unaff_BP;
  undefined2 unaff_SS;
  
  *(undefined2 *)(unaff_BP + -2) = in_DX;
  FUN_0000_86f1();
  return;
}


