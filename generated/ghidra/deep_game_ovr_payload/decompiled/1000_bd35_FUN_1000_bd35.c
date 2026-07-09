
void __stdcall16far
FUN_1000_bd35(undefined4 param_1,undefined2 *param_2,undefined2 *param_3,undefined1 *param_4)

{
  int *piVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined2 *puVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  int local_a;
  int iStack_8;
  
  if (*(int *)0x72be == 0 && *(int *)0x72c0 == 0) {
    *(undefined1 *)0x7457 = 0;
    uVar8 = 0x40d4;
    uVar4 = (undefined2)((ulong)param_1 >> 0x10);
    uVar3 = (undefined2)param_1;
    uVar5 = (undefined2)((ulong)param_2 >> 0x10);
    puVar6 = (undefined2 *)param_2;
    uVar7 = uVar5;
    uVar2 = FUN_0000_0b33();
    *param_4 = uVar2;
    uVar5 = ((undefined2 *)param_2)[1];
    *param_3 = *param_2;
    ((undefined2 *)param_3)[1] = uVar5;
    iStack_8 = *(int *)0x72c0;
    local_a = *(int *)0x72be;
    uVar5 = 0xaf;
    while (local_a != 0 || iStack_8 != 0) {
      FUN_0000_09bf(uVar5,0,0,0,0,local_a,iStack_8,0,0,puVar6,uVar7,uVar3,uVar4,uVar8);
      piVar1 = (int *)(local_a + 0x2a);
      iStack_8 = *(int *)(local_a + 0x2c);
      uVar5 = 0x99;
      local_a = *piVar1;
    }
    return;
  }
  func_0x0000d6dc();
  return;
}


