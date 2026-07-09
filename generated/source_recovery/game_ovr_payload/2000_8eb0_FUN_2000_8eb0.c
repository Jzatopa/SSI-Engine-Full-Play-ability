/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:8eb0
 * Ghidra name: FUN_2000_8eb0
 * Linear address: 0x28EB0
 * Original GAME.OVR file offset: 167608
 * Body addresses: 156
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_8eb0(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined2 local_6;
  undefined2 uStack_4;
  
  uVar6 = FUN_0000_ce3f();
  uVar3 = (undefined2)((ulong)uVar6 >> 0x10);
  iVar2 = (int)uVar6;
  FUN_0000_e6af(0x3e);
  *(undefined2 *)(iVar2 + 0x2a) = 0;
  *(undefined2 *)(iVar2 + 0x2c) = 0;
  uVar5 = (undefined2)((ulong)param_3 >> 0x10);
  iVar4 = (int)param_3;
  uStack_4 = *(int *)(iVar4 + 0xf9);
  local_6 = *(int *)(iVar4 + 0xf7);
  if (*(int *)(iVar4 + 0xf7) == 0 && uStack_4 == 0) {
    *(int *)(iVar4 + 0xf7) = iVar2;
    *(undefined2 *)(iVar4 + 0xf9) = uVar3;
  }
  else {
    while (*(int *)(local_6 + 0x2a) != 0 || *(int *)(local_6 + 0x2c) != 0) {
      piVar1 = (int *)(local_6 + 0x2a);
      uStack_4 = *(int *)(local_6 + 0x2c);
      local_6 = *piVar1;
    }
    *(int *)(local_6 + 0x2a) = iVar2;
    *(undefined2 *)(local_6 + 0x2c) = uVar3;
  }
  return;
}


