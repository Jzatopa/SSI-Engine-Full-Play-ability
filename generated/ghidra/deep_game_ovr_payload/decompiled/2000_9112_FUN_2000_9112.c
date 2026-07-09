
void __stdcall16far
FUN_2000_9112(char param_1,byte param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar11;
  undefined2 uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  byte extraout_AH;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  undefined2 uVar17;
  undefined *local_d2;
  char local_d0;
  int local_ce;
  int local_cc;
  uint local_c2;
  uint local_c0;
  int local_ba;
  char local_b8;
  byte local_b3;
  byte local_b1;
  int local_ae;
  int local_ac;
  int local_aa;
  int local_a8;
  byte local_97;
  byte local_96 [148];
  
  FUN_0000_e6d2(8);
  FUN_0000_e6d2(0);
  local_b1 = 0;
  local_b3 = 0;
  local_ae = param_6 * 3;
  local_ac = param_5 * 3;
  local_aa = param_4 * 3;
  local_a8 = param_3 * 3;
  FUN_0000_0d9a(0xcc0,&local_ae);
  bVar4 = local_b1;
  do {
    local_b1 = bVar4;
    cVar3 = FUN_0000_0d9f(0xd7,&local_ae);
    local_96[local_b1] = local_97;
    bVar4 = local_b1 + 1;
  } while (cVar3 != '\0');
  bVar4 = local_b1 - 1;
  if ((1 < bVar4) && (1 < (byte)(local_b1 + 1))) {
    uVar5 = param_4 - param_6;
    uVar6 = param_3 - param_5;
    cVar3 = func_0x00000e0c(0xd7,param_5 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3),
                            param_6 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2));
    if ((cVar3 == '\0') ||
       (cVar3 = func_0x00000e0c(0xdb,param_3 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3),
                                param_4 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2)),
       cVar3 == '\0')) {
      if (((int)((uVar5 ^ (int)uVar5 >> 0xf) - ((int)uVar5 >> 0xf)) < 7) &&
         ((int)((uVar6 ^ (int)uVar6 >> 0xf) - ((int)uVar6 >> 0xf)) < 7)) {
        bVar2 = true;
        local_b8 = (char)((int)uVar5 / 2) + (char)param_6;
        local_ba = (int)uVar6 / 2 + param_5;
      }
      else {
        bVar2 = false;
        local_b8 = *(char *)((int)*(undefined4 *)0x71dc + 2) + '\x03';
        local_ba = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
      }
    }
    else {
      bVar2 = true;
      local_b8 = *(char *)((int)*(undefined4 *)0x71dc + 2) + '\x03';
      local_ba = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
    }
    uVar11 = (undefined1)((uint)local_ba >> 8);
    uVar16 = CONCAT11(uVar11,local_b8);
    uVar7 = CONCAT11(uVar11,0xff);
    uVar8 = CONCAT11(uVar11,8);
    uVar12 = 0xdb;
    FUN_0000_0e16(0xdb,uVar8,uVar7,local_ba,uVar16);
    local_b1 = 0;
    local_c0 = 0;
    local_c2 = 0;
    do {
      local_cc = (param_6 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2)) * 3 + local_c0;
      local_ce = (param_5 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3)) * 3 + local_c2;
      bVar1 = false;
      uVar13 = uVar12;
      do {
        cVar3 = ((undefined *)&DAT_0000_26ca)[local_96[local_b1]];
        iVar9 = (int)(char)((undefined *)&DAT_0000_26d3)[local_96[local_b1]];
        local_cc = local_cc + cVar3;
        local_ce = local_ce + iVar9;
        local_b1 = local_b1 + 1;
        if ((((local_cc < 0) || (0x12 < local_cc)) || (local_ce < 0)) || (0x12 < local_ce)) {
          bVar1 = true;
        }
        if ((!bVar1) &&
           (((iVar10 = iVar9, param_1 != '\0' || (iVar10 = 0, local_cc % 3 == 0)) ||
            (iVar10 = 0, local_ce % 3 == 0)))) {
          uVar11 = (undefined1)((uint)iVar10 >> 8);
          uVar12 = *(undefined2 *)0x7509;
          uVar13 = *(undefined2 *)0x7507;
          uVar15 = *(undefined2 *)0x44cc;
          uVar14 = *(undefined2 *)0x44ca;
          FUN_0000_2e9a(uVar14,uVar15,uVar13,uVar12,CONCAT11(uVar11,5),CONCAT11(uVar11,local_b3),
                        local_ce,local_cc,uVar8,uVar7,local_ba,uVar16);
          FUN_0000_39b7();
          FUN_0000_c05c(param_1,uVar14,uVar15,uVar13,uVar12);
          uVar13 = 0x21a;
          FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x44ce,
                        *(undefined2 *)0x44d0,(uint)extraout_AH << 8,(uint)extraout_AH << 8,local_ce
                        ,local_cc);
          local_b3 = local_b3 + 1;
          if (param_2 <= local_b3) {
            local_b3 = 0;
          }
        }
        if ((!bVar1) && (local_b1 < bVar4)) {
          local_c0 = local_c0 + (int)cVar3;
          local_c2 = local_c2 + iVar9;
          if ((local_c0 ^ (int)local_c0 >> 0xf) - ((int)local_c0 >> 0xf) == 3) {
            iVar9 = func_0x00000d95(uVar13,local_c0);
            param_6 = param_6 + iVar9;
            uVar13 = 0xd7;
            func_0x00000d95(0xd7,local_c0);
            local_c0 = 0;
          }
          if ((local_c2 ^ (int)local_c2 >> 0xf) - ((int)local_c2 >> 0xf) == 3) {
            iVar9 = func_0x00000d95(uVar13,local_c2);
            param_5 = param_5 + iVar9;
            uVar13 = 0xd7;
            func_0x00000d95(0xd7,local_c2);
            local_c2 = 0;
          }
        }
      } while ((local_b1 < bVar4) && (!bVar1));
      if (local_b1 < bVar4) {
        local_d0 = '\0';
        local_d2 = (undefined *)0x0;
        local_c2 = 0;
        local_c0 = 0;
        param_6 = param_4;
        param_5 = param_3;
        if ((int)(param_4 + 3) < 0x32) {
          if ((int)param_4 < 3) {
            local_d0 = '\x03' - (char)param_4;
          }
        }
        else {
          local_d0 = (char)param_4 + -0x31;
        }
        if ((int)(param_3 + 3) < 0x19) {
          if ((int)param_3 < 3) {
            local_d2 = (undefined *)(3 - param_3);
          }
        }
        else {
          local_d2 = (undefined *)&DAT_0000_ffe8 + param_3;
        }
        local_b8 = (char)param_4 + local_d0;
        uVar11 = (undefined1)((uint)(local_d2 + param_3) >> 8);
        uVar12 = 0xdb;
        FUN_0000_0e16(uVar13,CONCAT11(uVar11,8),CONCAT11(uVar11,0xff),local_d2 + param_3,
                      CONCAT11(uVar11,local_b8));
        local_cc = (param_4 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2)) * 3;
        local_ce = (param_3 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3)) * 3;
        bVar1 = false;
        local_b1 = bVar4;
        do {
          local_cc = local_cc + -(int)(char)((undefined *)&DAT_0000_26ca)[local_96[local_b1]];
          local_ce = local_ce + -(int)(char)((undefined *)&DAT_0000_26d3)[local_96[local_b1]];
          if (local_cc < 0x13) {
            if (local_cc < 0) {
              param_6 = (uint)*(char *)((int)*(undefined4 *)0x71dc + 2);
            }
          }
          else {
            param_6 = (int)*(char *)((int)*(undefined4 *)0x71dc + 2) + 6;
          }
          if (local_ce < 0x13) {
            if (local_ce < 0) {
              param_5 = (uint)*(char *)((int)*(undefined4 *)0x71dc + 3);
            }
          }
          else {
            param_5 = (int)*(char *)((int)*(undefined4 *)0x71dc + 3) + 6;
          }
          if ((((local_cc < 0) || (0x12 < local_cc)) || (local_ce < 0)) || (0x12 < local_ce)) {
            bVar1 = true;
          }
          if (!bVar1) {
            local_c0 = local_c0 + -(int)(char)((undefined *)&DAT_0000_26ca)[local_96[local_b1]];
            local_c2 = local_c2 + -(int)(char)((undefined *)&DAT_0000_26d3)[local_96[local_b1]];
            if ((local_c0 ^ (int)local_c0 >> 0xf) - ((int)local_c0 >> 0xf) == 3) {
              iVar9 = func_0x00000d95(uVar12,local_c0);
              param_6 = param_6 + iVar9;
              uVar12 = 0xd7;
              func_0x00000d95(0xd7,local_c0);
              local_c0 = 0;
            }
            if ((local_c2 ^ (int)local_c2 >> 0xf) - ((int)local_c2 >> 0xf) == 3) {
              iVar9 = func_0x00000d95(uVar12,local_c2);
              param_5 = param_5 + iVar9;
              uVar12 = 0xd7;
              func_0x00000d95(0xd7,local_c2);
              local_c2 = 0;
            }
            local_b1 = local_b1 - 1;
          }
        } while (!bVar1);
      }
      else {
        bVar2 = true;
        cVar3 = func_0x00000e0c(uVar13,param_3 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3),
                                param_4 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2));
        if (cVar3 == '\0') {
          FUN_0000_0e16(0xdb,8,3,param_3 & 0xff,param_4 & 0xff);
        }
        iVar9 = (param_3 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3)) * 3;
        uVar11 = (undefined1)((uint)iVar9 >> 8);
        uVar13 = *(undefined2 *)0x7509;
        uVar15 = *(undefined2 *)0x7507;
        uVar14 = *(undefined2 *)0x44cc;
        uVar17 = *(undefined2 *)0x44ca;
        uVar16 = 0xdb;
        uVar12 = 0x21a;
        local_ba = -0x684c;
        FUN_0000_2e9a(uVar17,uVar14,uVar15,uVar13,CONCAT11(uVar11,5),CONCAT11(uVar11,local_b3),iVar9
                      ,(param_4 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2)) * 3);
        if (param_1 != '\0') {
          FUN_0000_39b7();
          FUN_0000_c05c(param_1,uVar17,uVar14,uVar15,uVar13);
          uVar16 = *(undefined2 *)0x44d0;
          local_ba = *(int *)0x44ce;
          uVar7 = *(undefined2 *)0x44cc;
          uVar8 = *(undefined2 *)0x44ca;
          uVar12 = 0x21a;
          FUN_0000_2e9a();
        }
      }
    } while (!bVar2);
    FUN_0000_39b7();
  }
  return;
}


