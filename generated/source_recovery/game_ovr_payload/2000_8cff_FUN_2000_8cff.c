/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:8cff
 * Ghidra name: FUN_2000_8cff
 * Linear address: 0x28CFF
 * Original GAME.OVR file offset: 167175
 * Body addresses: 35
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_2000_8cff(undefined4 param_1)

{
  undefined2 unaff_DS;
  
  return *(undefined2 *)((uint)*(byte *)((int)param_1 + 0x10) * 2 + 0xe30);
}


