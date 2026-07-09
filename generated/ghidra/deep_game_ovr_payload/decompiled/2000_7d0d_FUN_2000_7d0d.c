
void __stdcall16far
FUN_2000_7d0d(undefined1 param_1,undefined1 param_2,undefined2 param_3,undefined1 param_4,
             undefined4 param_5)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  int local_a;
  undefined2 uStack_8;
  
  puVar6 = (undefined1 *)FUN_0000_ce3f();
  uVar3 = (undefined2)((ulong)puVar6 >> 0x10);
  puVar2 = (undefined1 *)puVar6;
  uVar5 = (undefined2)((ulong)param_5 >> 0x10);
  iVar4 = (int)param_5;
  if (*(int *)(iVar4 + 0xfb) == 0 && *(int *)(iVar4 + 0xfd) == 0) {
    *(int *)(iVar4 + 0xfb) = (int)puVar2;
    *(undefined2 *)(iVar4 + 0xfd) = uVar3;
  }
  else {
    uStack_8 = *(undefined2 *)(iVar4 + 0xfd);
    local_a = *(int *)(iVar4 + 0xfb);
    while (*(int *)(local_a + 5) != 0 || *(int *)(local_a + 7) != 0) {
      piVar1 = (int *)(local_a + 5);
      uStack_8 = *(undefined2 *)(local_a + 7);
      local_a = *piVar1;
    }
    *(int *)(local_a + 5) = (int)puVar2;
    *(undefined2 *)(local_a + 7) = uVar3;
  }
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined2 *)(puVar2 + 7) = 0;
  *puVar6 = param_4;
  *(undefined2 *)(puVar2 + 1) = param_3;
  puVar2[4] = param_1;
  puVar2[3] = param_2;
  return;
}


