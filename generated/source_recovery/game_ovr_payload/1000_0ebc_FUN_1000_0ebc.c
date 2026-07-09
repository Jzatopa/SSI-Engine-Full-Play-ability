/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:0ebc
 * Ghidra name: FUN_1000_0ebc
 * Linear address: 0x10EBC
 * Original GAME.OVR file offset: 69316
 * Body addresses: 26
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_1000_0ebc(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  FUN_1000_0e9e(param_1,param_2,param_3,(int)param_4,(int)((ulong)param_4 >> 0x10));
  return;
}


