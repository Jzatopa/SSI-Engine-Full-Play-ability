
void __stdcall16far FUN_2000_741b(uint param_1,int param_2,undefined4 param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  if ((*(int *)0x72bc < param_2) || ((*(int *)0x72bc <= param_2 && (*(uint *)0x72ba < param_1)))) {
    param_1 = *(uint *)0x72ba;
    param_2 = *(int *)0x72bc;
  }
  puVar1 = (uint *)0x72ba;
  uVar3 = *puVar1;
  *puVar1 = *puVar1 - param_1;
  *(int *)0x72bc = (*(int *)0x72bc - param_2) - (uint)(uVar3 < param_1);
  uVar4 = (undefined2)((ulong)param_3 >> 0x10);
  puVar1 = (uint *)((int)param_3 + 0x2b);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  piVar2 = (int *)((int)param_3 + 0x2d);
  *piVar2 = *piVar2 + param_2 + (uint)CARRY2(uVar3,param_1);
  return;
}


