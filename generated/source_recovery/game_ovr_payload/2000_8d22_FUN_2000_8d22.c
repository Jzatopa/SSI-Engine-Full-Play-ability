/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:8d22
 * Ghidra name: FUN_2000_8d22
 * Linear address: 0x28D22
 * Original GAME.OVR file offset: 167210
 * Body addresses: 35
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_8d22(int param_1)

{
  undefined2 unaff_SS;
  
  FUN_0000_ce54();
  *(undefined1 *)(param_1 + -5) = 1;
  return;
}


