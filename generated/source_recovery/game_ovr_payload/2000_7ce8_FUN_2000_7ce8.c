/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:7ce8
 * Ghidra name: FUN_2000_7ce8
 * Linear address: 0x27CE8
 * Original GAME.OVR file offset: 163056
 * Body addresses: 37
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_2000_7ce8(undefined2 param_1,undefined1 param_2)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x72ca = param_2;
  uVar1 = FUN_0000_09ba();
  return uVar1;
}


