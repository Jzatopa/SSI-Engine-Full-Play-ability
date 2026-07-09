
/* WARNING: Removing unreachable block (ram,0x000148e7) */
/* WARNING: Removing unreachable block (ram,0x00014773) */

void __stdcall16far
FUN_121a_2410(uint *param_1,undefined4 param_2,byte param_3,uint param_4,uint param_5,uint param_6,
             uint param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iVar8;
  int iVar9;
  byte local_25;
  uint local_22;
  undefined1 local_20 [4];
  int local_1c;
  uint local_1a;
  int local_18;
  int local_16;
  int local_14;
  uint local_12;
  int local_10;
  int local_e;
  int local_c;
  undefined1 local_a [8];
  
  FUN_1cc0_09f6(8,local_a,unaff_SS,(int)param_2,(int)((ulong)param_2 >> 0x10));
  if ((uint *)param_1 != (uint *)0x0 || param_1._2_2_ != 0) {
    uVar6 = (int)param_7 >> 0xf;
    if ((int)param_7 < 0) {
      local_e = (param_7 ^ uVar6) - uVar6;
      local_12 = 0;
    }
    else {
      local_e = 0;
      local_12 = param_7;
    }
    uVar4 = local_12;
    uVar6 = uVar6 + CARRY2(param_7,param_5);
    if (((int)uVar6 < 1) && ((0x7fff < uVar6 || (param_7 + param_5 <= ((uint *)param_1)[1])))) {
      local_10 = 0;
      local_14 = ((uint *)param_1)[1] - (param_7 + param_5);
    }
    else {
      local_10 = (param_7 + param_5) - ((uint *)param_1)[1];
      local_14 = 0;
    }
    uVar6 = (int)param_6 >> 0xf;
    if ((int)param_6 < 0) {
      local_1a = 0;
      local_22 = 0;
      local_18 = param_4 - ((param_6 ^ uVar6) - uVar6);
    }
    else {
      local_22 = param_6;
      local_1a = param_6 * ((uint *)param_1)[1];
      uVar6 = uVar6 + CARRY2(param_6,param_4);
      if (((int)uVar6 < 1) && ((0x7fff < uVar6 || (param_6 + param_4 <= *param_1)))) {
        local_18 = param_4 - 1;
      }
      else {
        local_18 = (*param_1 - 1) - param_6;
      }
    }
    iVar3 = local_18;
    cVar1 = *(char *)0x44c8;
    if (((cVar1 == '\0') || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
      cVar1 = *(char *)0x44c8;
      if (cVar1 == '\0') {
        local_c = 2;
      }
      else if (cVar1 == '\x02') {
        local_c = 4;
      }
      else if (cVar1 == '\x03') {
        local_c = 8;
      }
      local_16 = ((param_5 - local_e) - local_10) * local_c;
      iVar2 = local_12 * local_c;
      local_14 = local_14 * local_c;
      local_1a = local_1a * local_c;
      local_1c = 0;
      local_12 = iVar2;
      while( true ) {
        *(undefined1 *)(local_22 + 0x44e2) = 1;
        local_1a = local_1a + local_12;
        if (local_1a < *(uint *)(local_22 * 2 + 0x46da)) {
          *(int *)(local_22 * 2 + 0x458a) = iVar2;
          *(uint *)(local_22 * 2 + 0x46da) = local_1a;
        }
        cVar1 = *(char *)0x44c8;
        uVar5 = (undefined1)(local_1a >> 8);
        if (cVar1 == '\0') {
          iVar7 = (int)(uint *)param_1 + local_1a + 0x1b;
          iVar8 = local_16;
          iVar9 = param_1._2_2_;
          uVar6 = FUN_121a_005e(local_a,unaff_SS,CONCAT11(uVar5,param_3));
          FUN_1cc0_1ad2(*(undefined1 *)((uVar6 & 0xff) + 0x3842),iVar8,iVar7,iVar9);
        }
        else if (cVar1 == '\x02') {
          FUN_1cc0_1ad2(*(undefined1 *)(param_3 + 0x3846),local_16,
                        (int)(uint *)param_1 + local_1a + 0x1b,param_1._2_2_);
        }
        else if (cVar1 == '\x03') {
          FUN_1cc0_1ad2(CONCAT11(uVar5,param_3),local_16,(int)(uint *)param_1 + local_1a + 0x1b,
                        param_1._2_2_);
        }
        iVar8 = local_1a + local_16;
        if (*(uint *)(local_22 * 2 + 0x482a) < iVar8 - 1U) {
          *(int *)(local_22 * 2 + 0x482a) = iVar8 + -1;
        }
        local_1a = iVar8 + local_14;
        local_22 = local_22 + 1;
        if (local_1c == iVar3) break;
        local_1c = local_1c + 1;
      }
    }
    else if (cVar1 == '\x01') {
      local_16 = (param_5 - local_e) - local_10;
      local_12 = local_12 << 2;
      local_14 = local_14 << 2;
      local_1a = local_1a << 2;
      FUN_1cc0_1ad2(0,4,local_20,unaff_SS);
      local_25 = 0;
      while( true ) {
        if ((*(byte *)(local_25 + 0x22ec) & param_3) != 0) {
          local_20[local_25] = 0xff;
        }
        iVar3 = local_18;
        if (local_25 == 3) break;
        local_25 = local_25 + 1;
      }
      local_1c = 0;
      while( true ) {
        *(undefined1 *)(local_22 + 0x44e2) = 1;
        local_1a = local_1a + local_12;
        if (local_1a < *(uint *)(local_22 * 2 + 0x46da)) {
          *(uint *)(local_22 * 2 + 0x458a) = uVar4;
          *(uint *)(local_22 * 2 + 0x46da) = local_1a;
        }
        cVar1 = (char)local_16;
        if ('\0' < (char)local_16) {
          *(undefined1 *)0x7817 = 1;
          while( true ) {
            FUN_1cc0_1aaf(4,(int)(uint *)param_1 + local_1a + 0x1b,param_1._2_2_,local_20,unaff_SS);
            local_1a = local_1a + 4;
            if (*(char *)0x7817 == cVar1) break;
            *(char *)0x7817 = *(char *)0x7817 + '\x01';
          }
        }
        if (*(uint *)(local_22 * 2 + 0x482a) < local_1a - 1) {
          *(int *)(local_22 * 2 + 0x482a) = local_1a - 1;
        }
        local_1a = local_1a + local_14;
        local_22 = local_22 + 1;
        if (local_1c == iVar3) break;
        local_1c = local_1c + 1;
      }
    }
  }
  return;
}


