
undefined2 __stdcall16far FUN_2000_fef1(char param_1,char param_2,char param_3)

{
  char extraout_AL;
  undefined1 extraout_AH;
  undefined1 uVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  FUN_2000_fd91(param_2,param_3);
  uVar1 = extraout_AH;
  if ((extraout_AL == '\0') && ((*(char *)0x8c30 == '\0' || (*(char *)0x8c30 == 'P')))) {
    local_3 = 0;
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
    if (param_1 == '\0') {
      local_3 = *(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3) >> 4;
      uVar1 = 0;
    }
    else if (param_1 == '\x02') {
      uVar1 = (undefined1)((uint)(param_2 * 0x10) >> 8);
      local_3 = *(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3) & 0xf;
    }
    else if (param_1 == '\x04') {
      local_3 = *(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3 + 0x100) >> 4;
      uVar1 = 0;
    }
    else if (param_1 == '\x06') {
      uVar1 = (undefined1)((uint)(param_2 * 0x10) >> 8);
      local_3 = *(byte *)((int)*(undefined4 *)0x7360 + param_2 * 0x10 + (int)param_3 + 0x100) & 0xf;
    }
  }
  return CONCAT11(uVar1,local_3);
}


