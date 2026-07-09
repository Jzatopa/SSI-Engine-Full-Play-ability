/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:fb6d
 * Ghidra name: FUN_2000_fb6d
 * Linear address: 0x2FB6D
 * Original GAME.OVR file offset: 195445
 * Body addresses: 31
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_2000_fb6d(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x7364 = param_4;
  *(undefined1 *)0x7365 = param_3;
  *(undefined1 *)0x7366 = param_2;
  *(undefined1 *)0x7367 = param_1;
  return;
}


