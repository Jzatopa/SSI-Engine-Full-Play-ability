
void __stdcall16far FUN_0000_bbb6(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(undefined1 *)(iVar2 + 0xd7) = 1;
  uVar5 = (undefined2)((ulong)*(undefined4 *)(iVar2 + 0xf3) >> 0x10);
  iVar3 = (int)*(undefined4 *)(iVar2 + 0xf3);
  if ((*(int *)(iVar3 + 8) != 0 || *(int *)(iVar3 + 10) != 0) &&
     (uVar1 = *(undefined4 *)((int)*(undefined4 *)(iVar2 + 0xf3) + 8),
     *(char *)((int)uVar1 + 0xd6) == *(char *)(iVar2 + 0xd6))) {
    uVar5 = (undefined2)((ulong)*(undefined4 *)(iVar2 + 0xf3) >> 0x10);
    iVar2 = (int)*(undefined4 *)(iVar2 + 0xf3);
    *(undefined2 *)(iVar2 + 8) = 0;
    *(undefined2 *)(iVar2 + 10) = 0;
  }
  return;
}


