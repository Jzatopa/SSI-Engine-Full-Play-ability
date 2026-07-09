/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0b3d
 * Ghidra name: FUN_0000_0b3d
 * Linear address: 0x00B3D
 * Original GAME.OVR file offset: 2885
 * Body addresses: 5
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_0b3d(void)

{
  char in_CH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + in_CH;
  return;
}


