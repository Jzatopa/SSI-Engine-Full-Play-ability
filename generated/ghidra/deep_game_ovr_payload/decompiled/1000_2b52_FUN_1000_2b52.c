
/* WARNING: Removing unreachable block (ram,0x00012d81) */

void __stdcall16far FUN_1000_2b52(int param_1)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte extraout_AH;
  byte extraout_AH_00;
  byte extraout_AH_01;
  byte extraout_AH_02;
  byte extraout_AH_03;
  byte bVar6;
  byte extraout_AH_04;
  byte extraout_AH_05;
  undefined1 extraout_AH_06;
  int iVar5;
  undefined1 uVar7;
  undefined1 extraout_AH_07;
  undefined2 uVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_0000ffba;
  undefined2 in_stack_0000ffbc;
  undefined2 in_stack_0000ffbe;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 in_stack_0000ffc4;
  undefined2 in_stack_0000ffc6;
  undefined2 in_stack_0000ffc8;
  undefined2 in_stack_0000ffca;
  int in_stack_0000ffcc;
  undefined2 in_stack_0000ffce;
  char local_19;
  char local_18;
  char local_14;
  char local_13;
  char local_4;
  byte local_3;
  
  cVar2 = *(char *)(param_1 + 6);
  if (cVar2 == '\x05') {
    uVar8 = *(undefined2 *)0x233a;
    FUN_0000_7840();
    local_3 = 0x24;
    bVar1 = true;
    bVar6 = extraout_AH;
  }
  else if (cVar2 == '\a') {
    uVar8 = *(undefined2 *)0x2332;
    FUN_0000_7840();
    local_3 = *(byte *)0x26e3;
    bVar1 = false;
    bVar6 = extraout_AH_00;
  }
  else if (cVar2 == '\b') {
    uVar8 = *(undefined2 *)0x2332;
    FUN_0000_7840();
    local_3 = *(byte *)0x26df;
    bVar1 = false;
    bVar6 = extraout_AH_01;
  }
  else if ((cVar2 == '\t') || (cVar2 == '\f')) {
    uVar8 = *(undefined2 *)0x2332;
    FUN_0000_7840();
    local_3 = *(byte *)0x26eb;
    bVar1 = false;
    bVar6 = extraout_AH_02;
  }
  else {
    if (((cVar2 != '\n') && (cVar2 != '\v')) && (cVar2 != '\x06')) {
      return;
    }
    uVar8 = *(undefined2 *)0x2340;
    FUN_0000_7840();
    local_3 = 0x1c;
    bVar1 = true;
    bVar6 = extraout_AH_03;
  }
  if (bVar1) {
    FUN_0000_4f8a(0x784,(uint)bVar6 << 8,(uint)bVar6 << 8,(uint)bVar6 << 8,CONCAT11(bVar6,local_3),
                  uVar8);
    FUN_0000_4f8a(0x21a,CONCAT11(extraout_AH_04,1),CONCAT11(extraout_AH_04,1),
                  (uint)extraout_AH_04 << 8,CONCAT11(extraout_AH_04,local_3));
    in_stack_0000ffce = CONCAT11(extraout_AH_05,2);
    in_stack_0000ffcc = (uint)extraout_AH_05 << 8;
    FUN_0000_4f8a(0x21a,in_stack_0000ffcc,in_stack_0000ffce,CONCAT11(extraout_AH_05,1),
                  CONCAT11(extraout_AH_05,local_3));
    in_stack_0000ffca = CONCAT11(extraout_AH_06,local_3);
    in_stack_0000ffc8 = CONCAT11(extraout_AH_06,1);
    in_stack_0000ffc6 = CONCAT11(extraout_AH_06,3);
    in_stack_0000ffc4 = CONCAT11(extraout_AH_06,1);
    FUN_0000_4f8a(0x21a,in_stack_0000ffc4,in_stack_0000ffc6,in_stack_0000ffc8,in_stack_0000ffca);
  }
  else {
    FUN_0000_4f8a(0x784,0,0,local_3 & 1,(local_3 >> 1) + 0x21,uVar8);
  }
  local_19 = '\0';
  local_18 = '\0';
  if ((int)*(char *)0x72d0 < (int)(uint)*(byte *)(param_1 + -0xee)) {
    local_19 = (*(char *)0x72d0 - *(char *)(param_1 + -0xee)) * '\x03';
  }
  else if ((int)(0x31 - (uint)*(byte *)(param_1 + -0xee)) < (int)*(char *)0x72d0) {
    local_19 = (*(char *)0x72d0 + -0x31 + *(char *)(param_1 + -0xee)) * '\x03';
  }
  if ((int)*(char *)&DAT_0000_72d1 < (int)(uint)*(byte *)(param_1 + -0xee)) {
    local_18 = (*(char *)&DAT_0000_72d1 - *(char *)(param_1 + -0xee)) * '\x03';
  }
  else if ((int)(0x18 - (uint)*(byte *)(param_1 + -0xee)) < (int)*(char *)&DAT_0000_72d1) {
    local_18 = (*(char *)&DAT_0000_72d1 + -0x18 + *(char *)(param_1 + -0xee)) * '\x03';
  }
  iVar5 = (uint)*(byte *)(param_1 + -0xee) * 3 + 1;
  cVar2 = (char)iVar5;
  if (cVar2 != '\0') {
    local_13 = '\x01';
    while( true ) {
      uVar8 = 0xcc0;
      func_0x0000dd51(0x21a);
      local_14 = local_13 * '\x02' + -2;
      while( true ) {
        uVar9 = 0x2d91;
        FUN_0000_e200(in_stack_0000ffc4,in_stack_0000ffc6,in_stack_0000ffc8,in_stack_0000ffca);
        in_stack_0000ffc8 = 0x2d9d;
        FUN_0000_dd3d(in_stack_0000ffcc);
        in_stack_0000ffca = 0x2dab;
        FUN_0000_dd3d(in_stack_0000ffce);
        in_stack_0000ffce = 0xcc0;
        in_stack_0000ffcc = 0x2dc2;
        func_0x0000de63();
        FUN_0000_dd3d(in_stack_0000ffba);
        cVar3 = FUN_0000_dd55(in_stack_0000ffbc);
        in_stack_0000ffba = 0x2df3;
        FUN_0000_de76(in_stack_0000ffbe);
        in_stack_0000ffbc = 0x2e01;
        uVar10 = uVar8;
        FUN_0000_dd3d(uVar9);
        uVar8 = 0xcc0;
        in_stack_0000ffbe = 0x2e06;
        iVar5 = FUN_0000_dd55(uVar10);
        cVar4 = (char)(local_18 + iVar5);
        if (((-10 < (char)(local_19 + cVar3)) && ((char)(local_19 + cVar3) < '\n')) &&
           ((-10 < cVar4 && (cVar4 < '\n')))) {
          if (bVar1) {
            uVar7 = (undefined1)((uint)(local_18 + iVar5) >> 8);
            in_stack_0000ffbe = 0xcc0;
            in_stack_0000ffbc = 0x2e3f;
            local_4 = FUN_0000_09ba(0xcc0,CONCAT11(uVar7,4),CONCAT11(uVar7,1));
            local_4 = local_4 + -1;
          }
          else {
            local_4 = '\0';
          }
          uVar7 = (undefined1)((uint)(cVar4 + 9) >> 8);
          in_stack_0000ffce = CONCAT11(uVar7,local_4);
          in_stack_0000ffcc = CONCAT11(uVar7,1);
          in_stack_0000ffca = *(undefined2 *)0x7509;
          in_stack_0000ffc8 = *(undefined2 *)0x7507;
          in_stack_0000ffc6 = *(undefined2 *)0x44cc;
          in_stack_0000ffc4 = *(undefined2 *)0x44ca;
          uVar8 = 0x21a;
          FUN_0000_2e9a();
        }
        if (local_14 == '\0') break;
        local_14 = local_14 + -1;
      }
      FUN_0000_39b7();
      iVar5 = CONCAT11(extraout_AH_07,cVar2);
      if (local_13 == cVar2) break;
      local_13 = local_13 + '\x01';
    }
  }
  uVar7 = (undefined1)((uint)iVar5 >> 8);
  FUN_0000_0e16(0x21a,CONCAT11(uVar7,8),CONCAT11(uVar7,0xff),
                CONCAT11(uVar7,*(undefined *)&DAT_0000_72d1),CONCAT11(uVar7,*(undefined1 *)0x72d0));
  return;
}


