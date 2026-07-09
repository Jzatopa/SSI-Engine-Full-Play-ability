
void __stdcall16far FUN_1000_e105(byte param_1,byte param_2)

{
  undefined1 uVar2;
  uint uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_109 [256];
  undefined1 local_9;
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  byte local_3;
  
  uVar2 = 0;
  ((undefined *)&DAT_0000_7718)[(uint)param_1 * 0x100] = 0;
  local_3 = 0;
  local_8 = 1;
  do {
    if (param_2 <= local_3) {
      if (local_8 == 4) {
        uVar1 = CONCAT11(uVar2,local_5) & 0xff3f;
        local_7 = (byte)uVar1;
        if (local_7 != '\0') {
          local_9 = FUN_1000_d69b(uVar1);
                    /* WARNING: Subroutine does not return */
          FUN_0000_d6c2((undefined *)&DAT_0000_7718 + (uint)param_1 * 0x100,unaff_DS,local_109,
                        unaff_SS);
        }
      }
      return;
    }
    if (local_8 < 4) {
      *(int *)0x4432 = *(int *)0x4432 + 1;
      local_6 = local_5;
      local_5 = *(byte *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x8000);
      uVar2 = (undefined1)((uint)*(int *)0x4432 >> 8);
      local_3 = local_3 + 1;
    }
    if (local_8 == 1) {
      local_7 = local_5 >> 2;
      uVar2 = 0;
    }
    else if (local_8 == 2) {
      local_7 = (byte)(local_6 * '@' + (local_5 >> 2)) >> 2;
      uVar2 = 0;
    }
    else if (local_8 == 3) {
      local_7 = (byte)(local_6 * '\x10' + (local_5 >> 4)) >> 2;
      uVar2 = 0;
    }
    else if (local_8 == 4) {
      local_7 = local_5 & 0x3f;
    }
    if (local_8 < 4) {
      local_8 = local_8 + 1;
    }
    else {
      local_8 = 1;
    }
  } while (local_7 == 0);
  local_9 = FUN_1000_d69b(CONCAT11(uVar2,local_7));
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2((undefined *)&DAT_0000_7718 + (uint)param_1 * 0x100,unaff_DS,local_109,unaff_SS);
}


