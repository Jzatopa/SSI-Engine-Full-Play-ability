
void FUN_0000_cb18(undefined2 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 *puVar10;
  undefined1 local_12;
  byte local_11;
  undefined4 local_e;
  byte local_a;
  char local_9;
  byte local_6;
  char local_5;
  char local_4 [2];
  
  *(undefined1 *)0x3de8 = 8;
  *(undefined1 *)0x3de9 = 0;
  *(undefined1 *)0x3dea = 0;
  local_11 = 0;
  local_5 = '\x01';
  local_4[0] = '\0';
  uVar4 = 0xe;
  puVar10 = &param_2;
  uVar9 = 0x92;
  FUN_0000_0981();
  uVar7 = (undefined2)((ulong)param_2 >> 0x10);
  if ((*(char *)((int)param_2 + 0xd6) == '\0') && (*(char *)0x8c26 == '\0')) {
    uVar9 = 0x7e;
    cVar2 = FUN_0000_080a(0x92,(int)param_2,uVar7,puVar10);
    if (cVar2 != '\0') {
      uVar9 = 0x7e;
      FUN_0000_080f(0x7e,(int)param_2,param_2._2_2_);
      uVar1 = *(undefined4 *)((int)param_2 + 0xf3);
      *(undefined1 *)((int)uVar1 + 1) = 0;
    }
  }
  uVar1 = *(undefined4 *)((int)param_2 + 0xf3);
  if (*(char *)((int)uVar1 + 1) == '\0') {
    local_5 = '\0';
  }
  while( true ) {
    if (local_4[0] != '\0') {
      FUN_0000_ceb6(uVar4);
      return;
    }
    if (local_5 == '\0') break;
    uVar1 = *(undefined4 *)((int)param_2 + 0xf3);
    if (*(char *)((int)uVar1 + 0x10) != '\0') {
      while( true ) {
        uVar7 = (undefined2)((ulong)param_2 >> 0x10);
        iVar5 = (int)param_2;
        if (((*(char *)((int)*(undefined4 *)(iVar5 + 0xf3) + 3) == '\0') ||
            (*(char *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1) < '\x01')) ||
           ('\x13' < *(char *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1))) break;
        FUN_0000_c73d(uVar9,iVar5,uVar7);
      }
    }
    uVar7 = (undefined2)((ulong)param_2 >> 0x10);
    iVar5 = (int)param_2;
    if ((*(char *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1) == '\0') ||
       (*(char *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1) == '\x14')) {
      local_5 = '\0';
    }
    else {
      local_4[0] = '\0';
    }
    if ((local_4[0] == '\0') && (local_5 != '\0')) {
      local_11 = local_11 + 1;
      if (0x14 < local_11) {
        local_4[0] = '\x01';
        cVar2 = FUN_0000_cecb(iVar5,uVar7);
        local_5 = cVar2 == '\0';
      }
      *(undefined1 *)0x7514 = 0;
      uVar8 = (undefined2)((ulong)param_2 >> 0x10);
      uVar1 = *(undefined4 *)((int)param_2 + 0xf3);
      uVar7 = (undefined2)((ulong)uVar1 >> 0x10);
      iVar6 = (int)uVar1;
      iVar5 = *(int *)(iVar6 + 8);
      uVar7 = *(undefined2 *)(iVar6 + 10);
      local_e = CONCAT22(uVar7,iVar5);
      if (*(char *)(iVar5 + 0xd5) == '\0') {
        local_e = 0;
      }
      uVar7 = 0x7e;
      local_6 = func_0x00000814(uVar9,(int)param_2,uVar8);
      if ((int)local_e != 0 || local_e._2_2_ != 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_0000_643a(0x7e,(int)local_e,local_e._2_2_,(int)param_2,param_2._2_2_);
      }
      if (*(char *)0x7514 == '\0') {
        if (4 < *(byte *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 3)) {
          local_6 = 1;
        }
        uVar7 = 0x99;
        uVar9 = func_0x00000a1e(0x7e,local_6,(int)param_2,param_2._2_2_);
        local_9 = (char)uVar9;
        if (local_9 == '\0') {
          cVar2 = FUN_0000_d805(0x99,local_4);
          if ((cVar2 == '\0') || (local_4[0] != '\0')) {
            local_4[0] = FUN_0000_cecb((int)param_2,param_2._2_2_);
          }
          else {
            FUN_0000_c73d(0x99,(int)param_2,param_2._2_2_);
          }
        }
        else {
          local_a = FUN_0000_09ba(0x99,uVar9,1);
          iVar5 = (uint)(byte)((undefined *)&DAT_0000_74ba)[local_a] * 4;
          local_e = CONCAT22(*(undefined2 *)((undefined *)&DAT_0000_7081 + iVar5),
                             *(undefined2 *)((undefined *)&DAT_0000_707f + iVar5));
          uVar7 = 0x99;
          bVar3 = func_0x00000a23(0x99,*(undefined2 *)((undefined *)&DAT_0000_707f + iVar5),
                                  *(undefined2 *)((undefined *)&DAT_0000_7081 + iVar5),(int)param_2,
                                  param_2._2_2_);
          if (local_6 < bVar3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_0000_643a(0x99,(int)local_e,local_e._2_2_,(int)param_2,param_2._2_2_);
          }
          *(undefined1 *)0x7514 = 1;
        }
      }
      uVar9 = uVar7;
      if (*(char *)0x7514 != '\0') {
        uVar9 = 0x99;
        cVar2 = func_0x00000a41(uVar7,(int)param_2,param_2._2_2_);
        if (cVar2 == '\0') {
          uVar9 = FUN_0000_0e20(0x99,(int)param_2,param_2._2_2_);
          uVar9 = FUN_0000_0e25((int)param_2,param_2._2_2_,uVar9);
          uVar9 = func_0x00000dd5(0xdb,(int)local_e,local_e._2_2_,(int)param_2,param_2._2_2_,2,uVar9
                                 );
          FUN_0000_0e16(0xdb,uVar9);
          FUN_0000_05ad(0xdb,(int)local_e,local_e._2_2_,(int)param_2,param_2._2_2_);
          uVar9 = 0x56;
          FUN_0000_05b2(0x56,local_4);
        }
        else {
          local_4[0] = FUN_0000_bebd(&local_12,unaff_SS,1,(int)param_2,param_2._2_2_);
        }
        if (local_4[0] == '\0') {
          if (*(char *)((int)local_e + 0xd5) == '\0') {
            local_4[0] = '\x01';
          }
        }
        else {
          local_5 = '\0';
        }
      }
    }
  }
  FUN_0000_ceb6(uVar4);
  return;
}


