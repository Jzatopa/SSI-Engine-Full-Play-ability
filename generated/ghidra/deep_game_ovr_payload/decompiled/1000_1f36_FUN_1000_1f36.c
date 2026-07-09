
void __stdcall16far FUN_1000_1f36(undefined4 param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  byte extraout_AH;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iVar7;
  undefined2 uVar8;
  uint local_d;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  int local_8;
  undefined2 uStack_6;
  byte local_4;
  byte local_3;
  
  uVar4 = 0x3c;
  uVar6 = 0x99;
  iVar7 = (int)param_1;
  uVar8 = param_1._2_2_;
  bVar1 = func_0x00000a1e();
  if (bVar1 == 0) {
    return;
  }
  local_4 = 1;
  local_3 = bVar1;
  do {
    if (*(char *)((int)param_1 + 0xd5) != '\0') {
      iVar5 = (uint)(byte)((undefined *)&DAT_0000_74ba)[local_4] * 4;
      local_8 = *(int *)((undefined *)&DAT_0000_707f + iVar5);
      uStack_6 = *(undefined2 *)((undefined *)&DAT_0000_7081 + iVar5);
      if (*(char *)((int)*(undefined4 *)(local_8 + 0xf3) + 4) != '\0') {
        cVar2 = func_0x000009ce(uVar6,local_8,uStack_6,uVar4,iVar7,uVar8);
        uVar6 = 0x99;
        if (cVar2 == '\0') {
          cVar2 = func_0x00000a3c(0x99,local_8,uStack_6);
          if (cVar2 == '\0') {
            bVar3 = func_0x00000a23(0x99,(int)param_1,param_1._2_2_,local_8,uStack_6);
            uVar6 = 0x99;
            if (1 < bVar3) goto LAB_1000_209e;
          }
          local_a = FUN_0000_0e20(0x99,(int)param_1,param_1._2_2_);
          local_b = FUN_0000_0e25((int)param_1,param_1._2_2_);
          uVar6 = 0x7e;
          local_d = func_0x00000814(0xdb,local_8,uStack_6);
          local_d = local_d & 0xff;
          if (*(char *)((int)param_1 + 0xd4) != '\x0e') {
            uVar6 = FUN_0000_0e20(0x7e,local_8,uStack_6);
            FUN_0000_0e25(local_8,uStack_6,uVar6);
            uVar6 = 0xd7;
            cVar2 = FUN_0000_0da4(0xdb,&local_d);
            if (cVar2 == '\0') goto LAB_1000_209e;
          }
          uVar6 = FUN_0000_0e20(uVar6,(int)param_1,param_1._2_2_);
          uVar6 = FUN_0000_0e25((int)param_1,param_1._2_2_,uVar6);
          FUN_0000_0e16(0xdb,8,2,uVar6);
          FUN_1000_27d4((int)param_1,param_1._2_2_,local_8,uStack_6);
          FUN_1000_3b01(&local_9,unaff_SS,(uint)extraout_AH << 8,(int)param_1,param_1._2_2_,local_8,
                        uStack_6);
          *(undefined1 *)((int)*(undefined4 *)(local_8 + 0xf3) + 4) = 0;
          uVar6 = 0xdb;
        }
      }
    }
LAB_1000_209e:
    if (local_4 == bVar1) {
      return;
    }
    local_4 = local_4 + 1;
  } while( true );
}


