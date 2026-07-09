
void __stdcall16far
FUN_1602_055f(undefined4 param_1,char param_2,undefined2 param_3,undefined2 param_4,byte param_5,
             byte param_6,byte param_7,byte param_8)

{
  undefined1 extraout_AH;
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 extraout_AH_00;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  undefined1 local_127 [33];
  byte local_106;
  byte local_105;
  char local_104;
  byte local_103;
  byte local_102 [256];
  
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_1b58_0051();
  if ((((param_8 < 0x28) && (param_7 < 0x19)) && (param_6 < 0x28)) && (param_5 < 0x28)) {
    if (((*(byte *)0x6878 < param_8) || (param_6 < *(byte *)0x6878)) ||
       ((*(byte *)0x6879 < param_7 || (param_5 < *(byte *)0x6879)))) {
      *(byte *)0x6878 = param_8;
      *(byte *)0x6879 = param_7;
    }
    if (param_2 != '\0') {
      FUN_1602_10c7(CONCAT11(extraout_AH,param_5),CONCAT11(extraout_AH,param_6),
                    CONCAT11(extraout_AH,param_7),CONCAT11(extraout_AH,param_8));
      *(byte *)0x6878 = param_8;
      *(byte *)0x6879 = param_7;
    }
    local_105 = 1;
    local_103 = local_102[0];
    if (local_102[0] != 0) {
      local_104 = (param_6 - param_8) + '\x01';
LAB_1602_061b:
      for (local_106 = local_105; local_106 < local_103; local_106 = local_106 + 1) {
        uVar4 = 1;
        uVar1 = (uint)local_102[local_106];
        puVar5 = local_127;
        uVar6 = unaff_SS;
        FUN_1cc0_0cc9(0x404,0xfd6,unaff_DS);
        FUN_1cc0_0d77(puVar5,uVar6,uVar1);
        if ((bool)uVar4) break;
      }
      do {
        if (local_103 <= local_106) goto LAB_1602_06a2;
        uVar4 = 1;
        uVar1 = (uint)local_102[local_106];
        puVar5 = local_127;
        uVar6 = unaff_SS;
        FUN_1cc0_0cc9(0x404,0xfd6,unaff_DS);
        FUN_1cc0_0d77(puVar5,uVar6,uVar1);
        if ((!(bool)uVar4) || (local_102[local_106] == 0x20)) goto LAB_1602_06a2;
        local_106 = local_106 + 1;
      } while( true );
    }
    FUN_1b58_0030();
  }
  return;
LAB_1602_06a2:
  if (local_102[local_106] != 0x20) {
    for (; local_106 + 1 < (uint)local_103; local_106 = local_106 + 1) {
      iVar2 = local_106 + 1;
      uVar4 = iVar2 == 0;
      uVar3 = CONCAT11((char)((uint)iVar2 >> 8),local_102[local_106 + 1]);
      puVar5 = local_127;
      uVar6 = unaff_SS;
      FUN_1cc0_0cc9(0x404,0xfd6,unaff_DS);
      FUN_1cc0_0d77(puVar5,uVar6,uVar3);
      if ((bool)uVar4) break;
    }
  }
  if ((int)(uint)param_6 < (int)(((uint)local_106 - (uint)local_105) + (uint)*(byte *)0x6878)) {
    if ((((uint)local_106 - (uint)local_105) + (uint)*(byte *)0x6878 == (uint)param_6) &&
       (local_102[local_106] == 0x20)) {
      local_106 = local_106 - 1;
      FUN_1602_04a9(&stack0xfffe);
    }
    *(byte *)0x6878 = param_8;
    *(char *)0x6879 = *(char *)0x6879 + '\x01';
    FUN_1602_0525(&stack0xfffe);
    if ((param_5 < *(byte *)0x6879) && (local_105 < local_103)) {
      *(byte *)0x6878 = param_8;
      *(byte *)0x6879 = param_7;
      FUN_1602_1243();
      FUN_1836_03cf();
      FUN_1602_10c7(CONCAT11(extraout_AH_00,param_5),CONCAT11(extraout_AH_00,param_6),
                    CONCAT11(extraout_AH_00,param_7),CONCAT11(extraout_AH_00,param_8));
      FUN_1602_04a9(&stack0xfffe);
    }
  }
  else {
    FUN_1602_04a9(&stack0xfffe);
  }
  if (local_103 < local_105) {
    if (param_6 < *(byte *)0x6878) {
      *(byte *)0x6878 = param_8;
      *(char *)0x6879 = *(char *)0x6879 + '\x01';
    }
    FUN_1b58_0030();
    return;
  }
  goto LAB_1602_061b;
}


