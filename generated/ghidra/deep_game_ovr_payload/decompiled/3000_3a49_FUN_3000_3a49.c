
void __stdcall16far
FUN_3000_3a49(undefined2 param_1,char param_2,uint param_3,char param_4,char param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  byte local_3;
  
  local_3 = 0;
  while (*(uint *)((undefined *)&DAT_0000_26bc + (uint)local_3 * 2) < param_3) {
    local_3 = local_3 + 1;
  }
  if (((param_3 != 0) && (local_3 < 7)) &&
     (*(int *)((uint)local_3 * 4 + 0x6894) != 0 || *(int *)((uint)local_3 * 4 + 0x6896) != 0)) {
    if (param_2 == '\0') {
      uVar1 = *(undefined4 *)((uint)local_3 * 4 + 0x6894);
      uVar5 = (undefined2)((ulong)uVar1 >> 0x10);
      iVar2 = (int)uVar1;
      iVar3 = iVar2 + (param_3 - *(int *)((undefined *)&DAT_0000_26ae + (uint)local_3 * 2)) *
                      *(int *)(iVar2 + 0x12) + 0x1b;
      uVar6 = (undefined2)((ulong)*(undefined4 *)0x68b0 >> 0x10);
      iVar4 = (int)*(undefined4 *)0x68b0 + 0x1b;
      FUN_0000_e6af(*(undefined2 *)(iVar2 + 0x12));
      FUN_0000_3721(0xcc0,*(undefined2 *)0x68b0,*(undefined2 *)0x68b2,(int)param_4,(int)param_5,
                    iVar4,uVar6,iVar3,uVar5);
    }
    else {
      FUN_0000_2d5d();
    }
  }
  return;
}


