/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:e3cd
 * Ghidra name: FUN_2000_e3cd
 * Linear address: 0x2E3CD
 * Original GAME.OVR file offset: 189397
 * Body addresses: 179
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_e3cd(undefined4 *param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  int local_8;
  undefined4 local_6;
  
  uVar7 = 0x2e;
  uVar6 = FUN_0000_ce3f();
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  *(int *)param_1 = (int)uVar6;
  *(undefined2 *)((int)(undefined4 *)param_1 + 2) = (int)((ulong)uVar6 >> 0x10);
  uVar5 = (undefined2)((ulong)*param_1 >> 0x10);
  iVar2 = (int)*param_1;
  *(undefined2 *)(iVar2 + 0x2a) = 0;
  *(undefined2 *)(iVar2 + 0x2c) = 0;
  *(undefined1 *)((int)*param_1 + 0x29) = 0;
  *(undefined1 *)*param_1 = 0;
  local_6 = (undefined1 *)
            CONCAT22(*(undefined2 *)((int)(undefined4 *)param_1 + 2),*(undefined1 **)param_1);
  if (1 < param_2) {
    local_8 = 2;
    while( true ) {
      uVar6 = FUN_0000_ce3f(0xcc0,0x2e,uVar7);
      uVar4 = (undefined2)((ulong)local_6 >> 0x10);
      puVar3 = (undefined1 *)local_6;
      *(int *)(puVar3 + 0x2a) = (int)uVar6;
      *(int *)(puVar3 + 0x2c) = (int)((ulong)uVar6 >> 0x10);
      puVar1 = *(undefined1 **)(puVar3 + 0x2a);
      uVar4 = *(undefined2 *)(puVar3 + 0x2c);
      local_6 = (undefined1 *)CONCAT22(uVar4,puVar1);
      *(undefined2 *)(puVar1 + 0x2a) = 0;
      *(undefined2 *)(puVar1 + 0x2c) = 0;
      puVar1[0x29] = 0;
      *local_6 = 0;
      if (local_8 == param_2) break;
      local_8 = local_8 + 1;
    }
  }
  return;
}


