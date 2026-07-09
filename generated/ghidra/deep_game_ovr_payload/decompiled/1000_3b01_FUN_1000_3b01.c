
void __stdcall16far
FUN_1000_3b01(undefined1 *param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 extraout_AL;
  char cVar1;
  byte extraout_AH;
  byte bVar6;
  byte extraout_AH_00;
  byte extraout_AH_01;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  byte extraout_AH_02;
  int iVar7;
  undefined2 uVar8;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  int iVar10;
  undefined1 local_31 [33];
  uint local_10;
  uint uStack_e;
  undefined1 local_b;
  uint local_a;
  undefined2 local_8;
  
  *(undefined1 *)0x7516 = 1;
  *(undefined *)&DAT_0000_7515 = 1;
  *(char *)&DAT_0000_74ba = *(char *)0x74b9 + '\x0f';
  if ((int)param_3 != 0 || param_3._2_2_ != 0) {
    iVar10 = (int)param_4;
    uVar4 = param_4._2_2_;
    iVar2 = (int)param_3;
    iVar7 = param_3._2_2_;
    func_0x00000dd5();
    if ((*(byte *)((int)*(undefined4 *)((int)param_3 + 0xf3) + 0xd) < 2) && (param_2 == '\0')) {
      *(undefined1 *)((int)*(undefined4 *)((int)param_3 + 0xf3) + 7) = extraout_AL;
    }
    local_b = extraout_AL;
    uVar4 = func_0x00000e11(0xdb,(uint)extraout_AH << 8,(int)param_3,param_3._2_2_,iVar10,uVar4,
                            iVar2,iVar7);
    bVar6 = (byte)((uint)uVar4 >> 8);
    if ((char)uVar4 != '\0') {
      func_0x00000e1b(0xdb,CONCAT11(bVar6,1),(uint)bVar6 << 8,
                      CONCAT11(bVar6,*(undefined1 *)((int)*(undefined4 *)((int)param_3 + 0xf3) + 7))
                      ,(int)param_3,param_3._2_2_);
      func_0x00000e1b(0xdb,(uint)extraout_AH_00 << 8,(uint)extraout_AH_00 << 8,
                      CONCAT11(extraout_AH_00,
                               *(undefined1 *)((int)*(undefined4 *)((int)param_3 + 0xf3) + 7)),
                      (int)param_3,param_3._2_2_);
    }
    unaff_CS = 0xdb;
    local_b = func_0x00000dd5(0xdb,(int)param_3,param_3._2_2_,(int)param_4,param_4._2_2_);
    *(undefined1 *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 7) = local_b;
  }
  func_0x000009c9(unaff_CS,(int)param_4,param_4._2_2_);
  uVar4 = CONCAT11(extraout_AH_01,*(undefined1 *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 7));
  uVar5 = CONCAT11(extraout_AH_01,1);
  iVar2 = (uint)extraout_AH_01 << 8;
  iVar10 = (int)param_4;
  func_0x00000e1b(0x99,iVar2,uVar5,uVar4,(int)param_4,param_4._2_2_);
  uVar8 = (undefined2)((ulong)*(undefined4 *)((int)param_4 + 0xf3) >> 0x10);
  iVar7 = (int)*(undefined4 *)((int)param_4 + 0xf3);
  *(int *)(iVar7 + 8) = (int)param_3;
  *(int *)(iVar7 + 10) = param_3._2_2_;
  uVar8 = 0xbdc;
  FUN_0000_c05c(100,iVar2,uVar5,uVar4,iVar10);
  *(undefined1 *)0x72cd = 0;
  local_10 = *(uint *)((int)param_4 + 0xeb);
  uStack_e = *(uint *)((int)param_4 + 0xed);
  uVar3 = local_10 | uStack_e;
  if ((uVar3 != 0) && (bVar9 = *(char *)(local_10 + 0x3d) == '\0', !bVar9)) {
    uVar8 = 0xcc0;
    uVar3 = FUN_0000_d977(0xbdc,0x2232,0xbdc,
                          CONCAT11((char)(uVar3 >> 8),*(undefined1 *)(local_10 + 0x3c)));
    if (!bVar9) {
      uVar3 = FUN_1000_2f46(0xcc0,*(undefined1 *)(local_10 + 0x3c),(int)param_4,param_4._2_2_);
    }
  }
  if (*(char *)0x72cd == '\0') {
    iVar10 = (int)param_4;
    cVar1 = func_0x00000a41(uVar8,(int)param_4,param_4._2_2_);
    if (cVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0x2252,0x99,local_31,unaff_SS,iVar10);
    }
    uVar8 = 0x7e;
    uVar3 = func_0x00000814(0x99,(int)param_4,param_4._2_2_);
    if (1 < (byte)uVar3) {
      uVar4 = FUN_0000_0e20(0x7e,(int)param_4,param_4._2_2_);
      uVar4 = FUN_0000_0e25((int)param_4,param_4._2_2_,uVar4);
      uVar4 = FUN_0000_0e20(0xdb,(int)param_3,param_3._2_2_,uVar4);
      uVar8 = 0xdb;
      iVar10 = (int)param_3;
      iVar2 = param_3._2_2_;
      uVar5 = FUN_0000_0e25((int)param_3,param_3._2_2_,uVar4);
      uVar3 = FUN_1000_43dd(*(undefined2 *)((int)param_4 + 0xeb),
                            *(undefined2 *)((int)param_4 + 0xed),uVar5,iVar10,iVar2,uVar4);
    }
    *param_1 = 1;
    if ((*(char *)((int)param_4 + 0xdb) != '\0') || (*(char *)((int)param_4 + 0xdc) != '\0')) {
      local_a = *(uint *)0x57fb;
      local_8 = *(undefined2 *)0x57fd;
      *(int *)0x57fb = (int)param_4;
      *(undefined2 *)0x57fd = param_4._2_2_;
      FUN_1000_24c1((undefined1 *)param_1,(int)((ulong)param_1 >> 0x10),param_2,(int)param_3,
                    param_3._2_2_,(int)param_4,param_4._2_2_);
      uVar4 = uVar8;
      if ((local_10 != 0 || uStack_e != 0) &&
         (((((undefined *)&DAT_0000_5370)[(uint)*(byte *)(local_10 + 0x2e) * 9] != '\0' &&
           (*(char *)(local_10 + 0x38) = *(char *)(local_10 + 0x38) - *(char *)0x7503,
           *(char *)(local_10 + 0x38) == '\0')) &&
          (((undefined *)&DAT_0000_5376)[(uint)*(byte *)(local_10 + 0x2e) * 9] != '\0')))) {
        uVar4 = 0x99;
        func_0x000009e7(uVar8,local_10,uStack_e,(int)param_4,param_4._2_2_);
      }
      uVar8 = 0x99;
      FUN_0000_0a05(uVar4,(int)param_4,param_4._2_2_);
      *(uint *)0x57fb = local_a;
      *(undefined2 *)0x57fd = local_8;
      uVar3 = local_a;
    }
  }
  cVar1 = func_0x00000e11(uVar8,uVar3 & 0xff00,(int)param_4,param_4._2_2_);
  if (cVar1 != '\0') {
    func_0x00000e1b(0xdb,1,1,*(undefined1 *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 7),
                    (int)param_4,param_4._2_2_);
    func_0x00000e1b(0xdb,(uint)extraout_AH_02 << 8,(uint)extraout_AH_02 << 8,
                    CONCAT11(extraout_AH_02,
                             *(undefined1 *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 7)),
                    (int)param_4,param_4._2_2_);
  }
  return;
}


