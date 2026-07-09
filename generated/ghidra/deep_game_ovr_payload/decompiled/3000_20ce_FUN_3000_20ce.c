
undefined1 __stdcall16far FUN_3000_20ce(char param_1,undefined2 param_2,undefined2 param_3)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_7;
  char local_6;
  byte local_5;
  char local_4;
  undefined1 local_3;
  
  local_3 = 1;
  local_5 = FUN_3000_25e3(param_2,param_3);
  if (((undefined *)&DAT_0000_69f0)[(uint)local_5 * 4] == '\0') {
    return 0;
  }
  local_4 = '\0';
  while( true ) {
    cVar1 = FUN_3000_181b(&local_7,unaff_SS,&local_6,unaff_SS,local_4,
                          ((undefined *)&DAT_0000_69f0)[(uint)local_5 * 4]);
    if (cVar1 != '\0') {
      cVar1 = FUN_3000_209d((int)(char)((undefined *)&DAT_0000_6b58)[local_5] + (int)local_7,
                            (int)(char)((undefined *)&DAT_0000_6b10)[local_5] + (int)local_6);
      if (cVar1 == '\0') {
        local_3 = 0;
        if (param_1 != '\0') {
          return 0;
        }
      }
      else {
        local_3 = 1;
        if (param_1 == '\0') {
          return 1;
        }
      }
    }
    if (local_4 == '\x03') break;
    local_4 = local_4 + '\x01';
  }
  return local_3;
}


