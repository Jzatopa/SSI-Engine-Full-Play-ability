
void __stdcall16far FUN_1000_7e0d(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined2 uVar5;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined1 local_27 [17];
  int local_16;
  undefined2 uStack_14;
  int local_12;
  int iStack_10;
  int local_e;
  int local_c;
  int local_a;
  int iStack_8;
  int local_6;
  int local_4;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  piVar4 = (int *)param_1;
  if (*param_1 == 0 && piVar4[1] == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0,unaff_CS,local_27,unaff_SS);
  }
  uStack_14 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
  local_16 = (int)*(undefined4 *)param_1;
  if (*(int *)(local_16 + 0xf3) != 0 || *(int *)(local_16 + 0xf5) != 0) {
    unaff_CS = 0xcc0;
    FUN_0000_ce54();
  }
  local_a = *(int *)(local_16 + 0xf7);
  iStack_8 = *(int *)(local_16 + 0xf9);
  while (iVar3 = iStack_8, iVar2 = local_a, local_a != 0 || iStack_8 != 0) {
    local_6 = local_a;
    local_4 = iStack_8;
    piVar1 = (int *)(local_a + 0x2a);
    iStack_8 = *(int *)(local_a + 0x2c);
    local_a = *piVar1;
    FUN_0000_ce54(unaff_CS,0x3e,iVar2,iVar3);
    unaff_CS = 0xcc0;
  }
  local_12 = *(int *)(local_16 + 0xfb);
  iStack_10 = *(int *)(local_16 + 0xfd);
  while (iVar3 = iStack_10, iVar2 = local_12, local_12 != 0 || iStack_10 != 0) {
    local_e = local_12;
    local_c = iStack_10;
    piVar1 = (int *)(local_12 + 5);
    iStack_10 = *(int *)(local_12 + 7);
    local_12 = *piVar1;
    FUN_0000_ce54(unaff_CS,9,iVar2,iVar3);
    unaff_CS = 0xcc0;
  }
  FUN_0000_ce54(unaff_CS,0x103,*param_1,piVar4[1]);
  *param_1 = 0;
  piVar4[1] = 0;
  return;
}


