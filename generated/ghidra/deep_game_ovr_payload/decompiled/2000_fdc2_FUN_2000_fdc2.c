
undefined2 __stdcall16far FUN_2000_fdc2(char param_1,char param_2,char param_3)

{
  char extraout_AL;
  char extraout_AL_00;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar1;
  undefined2 unaff_DS;
  byte local_4;
  byte local_3;
  
  FUN_2000_fd91(param_2,param_3);
  if ((extraout_AL == '\0') && ((*(char *)0x8c30 == '\0' || (*(char *)0x8c30 == 'P')))) {
    local_3 = 0;
    uVar1 = extraout_AH;
  }
  else {
    if (param_3 < '\x10') {
      if (param_3 < '\0') {
        param_3 = '\x0f';
      }
    }
    else {
      param_3 = '\0';
    }
    if (param_2 < '\x10') {
      if (param_2 < '\0') {
        param_2 = '\x0f';
      }
    }
    else {
      param_2 = '\0';
    }
    local_4 = 1;
    FUN_2000_fef1(CONCAT11(extraout_AH,param_1),CONCAT11(extraout_AH,param_2),
                  CONCAT11(extraout_AH,param_3));
    uVar1 = extraout_AH_00;
    if (extraout_AL_00 != '\0') {
      if (param_1 == '\x06') {
        local_4 = *(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3 + 0x300) >> 6
        ;
        uVar1 = 0;
      }
      else if (param_1 == '\x04') {
        local_4 = (*(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3 + 0x300) &
                  0x30) >> 4;
        uVar1 = 0;
      }
      else if (param_1 == '\x02') {
        local_4 = (*(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3 + 0x300) &
                  0xc) >> 2;
        uVar1 = 0;
      }
      else if (param_1 == '\0') {
        uVar1 = (undefined1)((uint)(param_2 * 0x10) >> 8);
        local_4 = *(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3 + 0x300) & 3;
      }
    }
    local_3 = local_4;
  }
  return CONCAT11(uVar1,local_3);
}


