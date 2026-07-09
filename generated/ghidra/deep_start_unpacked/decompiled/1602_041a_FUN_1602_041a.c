
void __stdcall16far
FUN_1602_041a(undefined4 param_1,undefined1 param_2,undefined1 param_3,byte param_4,byte param_5)

{
  undefined1 extraout_AH;
  undefined1 uVar1;
  undefined1 extraout_AH_00;
  undefined2 unaff_SS;
  byte local_104;
  byte local_102 [256];
  
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_1b58_0051();
  if ((param_5 < 0x28) && (param_4 < 0x28)) {
    if (local_102[0] != 0) {
      local_104 = 1;
      uVar1 = extraout_AH;
      while( true ) {
        FUN_1602_0263(1,local_102[local_104],CONCAT11(uVar1,1),CONCAT11(uVar1,param_2),
                      CONCAT11(uVar1,param_3),CONCAT11(uVar1,param_4),CONCAT11(uVar1,param_5));
        param_5 = param_5 + 1;
        if (local_104 == local_102[0]) break;
        local_104 = local_104 + 1;
        uVar1 = extraout_AH_00;
      }
    }
    FUN_1b58_0030();
  }
  return;
}


