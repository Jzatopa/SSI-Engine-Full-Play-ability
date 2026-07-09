
undefined2 __stdcall16far FUN_2000_fff4(char param_1,char param_2)

{
  char extraout_AL;
  undefined1 extraout_AH;
  undefined1 uVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  func_0x0003fd91();
  if ((extraout_AL == '\0') && ((*(char *)0x8c30 == '\0' || (*(char *)0x8c30 == 'P')))) {
    local_3 = 0;
    uVar1 = extraout_AH;
  }
  else {
    if (param_2 < '\x10') {
      if (param_2 < '\0') {
        param_2 = '\x0f';
      }
    }
    else {
      param_2 = '\0';
    }
    if ('\x0f' < param_1) {
      param_1 = '\0';
    }
    if (param_1 < '\0') {
      param_1 = '\x0f';
    }
    local_3 = *(undefined1 *)((int)*(undefined4 *)0x7360 + param_1 * 0x10 + (int)param_2 + 0x200);
    uVar1 = (undefined1)((uint)(param_1 * 0x10) >> 8);
  }
  return CONCAT11(uVar1,local_3);
}


