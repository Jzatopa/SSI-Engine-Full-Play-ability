/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:db00
 * Ghidra name: FUN_0000_db00
 * Linear address: 0x0DB00
 * Original GAME.OVR file offset: 56072
 * Body addresses: 34
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_db00(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x3dd2;
  *(undefined2 *)0x4014 = *(undefined2 *)0x3dd0;
  *(undefined2 *)0x4016 = uVar1;
  *(undefined2 *)0x3dd0 = param_1;
  *(undefined2 *)0x3dd2 = param_2;
  return;
}


