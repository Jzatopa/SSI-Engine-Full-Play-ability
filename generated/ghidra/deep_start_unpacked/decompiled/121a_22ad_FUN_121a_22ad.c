
void __stdcall16far
FUN_121a_22ad(undefined4 *param_1,byte param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_7;
  
  if (*(char *)0x44c8 == '\0') {
    local_7 = 2;
  }
  else if (*(char *)0x44c8 == '\x03') {
    local_7 = 8;
  }
  else {
    local_7 = 4;
  }
  iVar2 = param_5 * param_4 * (uint)local_7;
  iVar1 = iVar2 * param_3;
  uVar4 = FUN_1cc0_023f(iVar1 + 0x1b);
  *(int *)param_1 = (int)uVar4;
  *(undefined2 *)((int)(undefined4 *)param_1 + 2) = (int)((ulong)uVar4 >> 0x10);
  FUN_1cc0_1ad2(iVar1 + 0x1bU & 0xff00,iVar1 + 0x1bU,(int)*param_1,(int)((ulong)*param_1 >> 0x10));
  *(int *)*param_1 = param_5;
  *(int *)((int)*param_1 + 2) = param_4;
  *(int *)((int)*param_1 + 0x12) = iVar2;
  *(int *)((int)*param_1 + 8) = param_3;
  *(int *)((int)*param_1 + 0x14) = iVar1 + 0x1b;
  if (((param_2 & 1) != 0) && (*(char *)0x44c8 != '\x03')) {
    uVar5 = FUN_1cc0_023f(iVar1);
    uVar3 = (undefined2)((ulong)*param_1 >> 0x10);
    iVar2 = (int)*param_1;
    *(uint *)(iVar2 + 0x17) = (uint)uVar5;
    *(undefined2 *)(iVar2 + 0x19) = (int)((ulong)uVar5 >> 0x10);
    uVar4 = *(undefined4 *)((int)*param_1 + 0x17);
    FUN_1cc0_1ad2((uint)uVar5 & 0xff00,iVar1,(int)uVar4,(int)((ulong)uVar4 >> 0x10));
  }
  return;
}


