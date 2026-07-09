/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:a1e5
 * Ghidra name: FUN_2000_a1e5
 * Linear address: 0x2A1E5
 * Original GAME.OVR file offset: 172525
 * Body addresses: 58
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_a1e5(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 1) = 0;
  *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 4) = 0;
  *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 3) = 0;
  return 1;
}


