/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:4967
 * Ghidra name: FUN_2000_4967
 * Linear address: 0x24967
 * Original GAME.OVR file offset: 149871
 * Body addresses: 102
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

bool __stdcall16far
FUN_2000_4967(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  byte bVar1;
  
  FUN_0000_0a05();
  bVar1 = FUN_2000_1fd4(param_3,param_4);
  return 0xf < bVar1;
}


