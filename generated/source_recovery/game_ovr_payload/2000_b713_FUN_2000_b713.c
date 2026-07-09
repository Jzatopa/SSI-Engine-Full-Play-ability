/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b713
 * Ghidra name: FUN_2000_b713
 * Linear address: 0x2B713
 * Original GAME.OVR file offset: 177947
 * Body addresses: 54
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_b713(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (((*(int *)(iVar2 + 0x1a) < 1) || (*(int *)(iVar2 + 0x1e) < 1)) || (*(int *)(iVar2 + 0x20) < 1)
     ) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


