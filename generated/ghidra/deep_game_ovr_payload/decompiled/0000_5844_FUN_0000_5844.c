
undefined2 __stdcall16far FUN_0000_5844(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_213 [4];
  undefined1 local_20f [252];
  undefined4 local_113;
  undefined1 local_10f [256];
  undefined1 local_f;
  char local_c;
  uint local_9;
  uint local_7;
  char local_5;
  char local_4;
  undefined1 local_3;
  
  if ((param_4._2_2_ == *(int *)0x534c) && ((int)param_4 == *(int *)0x534a)) {
    local_f = 0;
  }
  else {
    local_f = 1;
  }
  if (param_2 != 0 || param_3 != 0) {
    local_10f[0] = 0;
    local_113._0_2_ = (int)param_4;
    local_113._2_2_ = param_4._2_2_;
    cVar1 = FUN_0000_5742(&stack0xfffe);
    if (cVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(local_10f,unaff_SS,local_213,unaff_SS);
    }
    for (local_4 = '\0';
        ((*(int *)((int)local_113 + local_4 * 2 + 0x22) <=
          *(int *)((int)local_113 + local_4 * 2 + 0x16) ||
         (*(int *)((undefined *)&DAT_0000_ffdb + param_1 + local_4 * 2) != 0)) ||
        (local_4 == '\x04')); local_4 = local_4 + '\x01') {
      if (local_4 == '\x05') {
                    /* WARNING: Subroutine does not return */
        FUN_0000_d6c2(local_10f,unaff_SS,local_20f,unaff_SS);
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(local_10f,unaff_SS,local_213,unaff_SS);
  }
  local_5 = '\a';
  local_7 = 0;
  cVar1 = FUN_0000_5742(&stack0xfffe);
  if (cVar1 != '\0') {
    local_c = -1;
    *(undefined1 *)0x7817 = 0;
    while( true ) {
      iVar4 = (int)param_4 + *(char *)0x7817 * 6;
      local_113 = (byte *)CONCAT22(param_4._2_2_,(byte *)(iVar4 + 0x3c));
      if (((*(byte *)(iVar4 + 0x3e) < *(byte *)(iVar4 + 0x3d)) && (local_4 != '\x04')) &&
         ((int)local_7 < (int)(uint)*(byte *)((uint)(*local_113 & 0x7f) * 0x22 + 0x240b))) {
        local_c = *(char *)0x7817;
        local_7 = (uint)*(byte *)((uint)(*local_113 & 0x7f) * 0x22 + 0x240b);
      }
      if (*(char *)0x7817 == '\a') break;
      *(char *)0x7817 = *(char *)0x7817 + '\x01';
    }
    if (-1 < local_c) {
      local_5 = '\x06';
    }
  }
  if (local_5 == '\a') {
    local_4 = '\0';
    while( true ) {
      uVar2 = *(uint *)((int)param_4 + local_4 * 2 + 0x16);
      if ((uVar2 != *(uint *)((int)param_4 + local_4 * 2 + 0x22)) &&
         (uVar2 = local_4 * 2, *(int *)(param_1 + local_4 * 2 + -0x19) == 0)) {
        iVar4 = -((*(int *)((int)param_4 + local_4 * 2 + 0x16) * 10) /
                 *(int *)((int)param_4 + local_4 * 2 + 0x22));
        local_9 = iVar4 + 10;
        if (*(int *)((int)param_4 + local_4 * 2 + 0x16) == 0) {
          local_9 = iVar4 + 0xf;
        }
        if (*(int *)(param_1 + local_4 * 2 + -0x19) == 0) {
          local_9 = local_9 << 1;
        }
        uVar2 = local_9;
        if ((int)local_7 < (int)local_9) {
          local_7 = local_9;
          uVar2 = CONCAT11((char)(local_9 >> 8),local_4);
          local_5 = local_4;
        }
      }
      if (local_4 == '\x05') break;
      local_4 = local_4 + '\x01';
    }
    if (local_5 == '\a') {
      return CONCAT11((char)(uVar2 >> 8),local_3);
    }
  }
  if (local_5 != '\x06') {
    uVar3 = func_0x0000d6dc();
    return uVar3;
  }
  uVar3 = func_0x0000d6dc();
  return uVar3;
}


