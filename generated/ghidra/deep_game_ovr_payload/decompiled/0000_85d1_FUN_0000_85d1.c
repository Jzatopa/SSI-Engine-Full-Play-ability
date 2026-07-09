
void __stdcall16far FUN_0000_85d1(uint param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 uStack_4;
  
  if (*(char *)0x8c26 == '\0') {
    uStack_4 = *(int *)0x5801;
    local_6 = *(int *)0x57ff;
    while (local_6 != 0 || uStack_4 != 0) {
      if (*(char *)(local_6 + 0xd5) != '\0') {
        puVar1 = (uint *)(local_6 + 0x2f);
        uVar3 = *puVar1;
        *puVar1 = *puVar1 + param_1;
        *(int *)(local_6 + 0x31) = *(int *)(local_6 + 0x31) + param_2 + (uint)CARRY2(uVar3,param_1);
      }
      piVar2 = (int *)(local_6 + 0xff);
      uStack_4 = *(int *)(local_6 + 0x101);
      local_6 = *piVar2;
    }
  }
  else {
    uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar4 = (int)*(undefined4 *)0x57fb;
    puVar1 = (uint *)(iVar4 + 0x2f);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 + param_1;
    piVar2 = (int *)(iVar4 + 0x31);
    *piVar2 = *piVar2 + param_2 + (uint)CARRY2(uVar3,param_1);
  }
  return;
}


