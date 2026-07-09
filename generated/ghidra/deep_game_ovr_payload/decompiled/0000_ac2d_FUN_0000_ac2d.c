
void __stdcall16far FUN_0000_ac2d(undefined4 param_1)

{
  int iVar1;
  undefined1 extraout_AH;
  uint uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined4 *puVar6;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 0xd) = 0;
  *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 0xe) = 0;
  *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 4) = 0;
  if ((*(char *)(iVar1 + 0xd4) == '\n') || (*(char *)(iVar1 + 0xd4) == '\f')) {
    *(undefined1 *)(iVar1 + 0xd4) = 1;
  }
  puVar6 = &param_1;
  FUN_0000_0981();
  uVar5 = 0x92;
  func_0x0000094f(0x92,0,0,CONCAT11(extraout_AH,2),(uint)param_1,param_1._2_2_,puVar6);
  if (*(char *)((int)*(undefined4 *)(iVar1 + 0xf3) + 1) < '\x01') {
    return;
  }
  if (*(char *)((int)*(undefined4 *)(iVar1 + 0xf3) + 1) == '\x14') {
    *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 1) = 0x13;
  }
  *(uint *)0x57fb = (uint)param_1;
  *(undefined2 *)0x57fd = param_1._2_2_;
  uVar2 = (uint)param_1;
  if (*(char *)(iVar1 + 0xd6) != '\0') {
    uVar5 = 0xdb;
    uVar2 = func_0x00000e11(0x92,(uint)param_1 & 0xff00,(uint)param_1,param_1._2_2_);
    if ((char)uVar2 == '\0') {
      uVar2 = uVar2 & 0xff00;
      goto LAB_0000_ad01;
    }
  }
  uVar2 = CONCAT11((char)(uVar2 >> 8),1);
LAB_0000_ad01:
  *(undefined1 *)0x7516 = (char)uVar2;
  uVar3 = (undefined1)(uVar2 >> 8);
  func_0x00000e43(uVar5,CONCAT11(uVar3,1),CONCAT11(uVar3,2),(uint)param_1,param_1._2_2_);
  FUN_0000_0a05(0xdb,(uint)param_1,param_1._2_2_);
  *(undefined *)&DAT_0000_7515 = 1;
  func_0x000009c9(0x99,(uint)param_1,param_1._2_2_);
  func_0x000005da(0x99,(uint)param_1,param_1._2_2_);
  uVar5 = 0x92;
  FUN_0000_0981(0x56,&param_1);
  if ('\0' < *(char *)((int)*(undefined4 *)(iVar1 + 0xf3) + 1)) {
    if (*(char *)(iVar1 + 0xd7) == '\0') {
      FUN_0000_ae00((uint)param_1,param_1._2_2_);
    }
    else {
      uVar5 = 0x42;
      FUN_0000_0445(0x92,(uint)param_1,param_1._2_2_);
    }
  }
  uVar4 = FUN_0000_0e20(uVar5,(uint)param_1,param_1._2_2_);
  uVar4 = FUN_0000_0e25((uint)param_1,param_1._2_2_,uVar4);
  func_0x00000df8(0xdb,uVar4);
  return;
}


