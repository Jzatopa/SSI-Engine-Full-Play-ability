
void __stdcall16far FUN_2000_724d(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)*param_3 >> 0x10);
  iVar4 = (int)*param_3;
  puVar1 = (uint *)(iVar4 + 0x2b);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 - param_1;
  piVar2 = (int *)(iVar4 + 0x2d);
  *piVar2 = *piVar2 - (uint)(uVar3 < param_1);
  uVar5 = (undefined2)((ulong)*param_2 >> 0x10);
  iVar4 = (int)*param_2;
  puVar1 = (uint *)(iVar4 + 0x2b);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  piVar2 = (int *)(iVar4 + 0x2d);
  *piVar2 = *piVar2 + (uint)CARRY2(uVar3,param_1);
  return;
}


