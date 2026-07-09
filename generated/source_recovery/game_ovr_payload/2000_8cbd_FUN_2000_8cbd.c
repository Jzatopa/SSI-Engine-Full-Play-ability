/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:8cbd
 * Ghidra name: FUN_2000_8cbd
 * Linear address: 0x28CBD
 * Original GAME.OVR file offset: 167109
 * Body addresses: 33
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_8cbd(undefined4 param_1)

{
  undefined2 unaff_DS;
  
  return *(undefined1 *)(*(byte *)((int)param_1 + 0x10) + 0xe05);
}


