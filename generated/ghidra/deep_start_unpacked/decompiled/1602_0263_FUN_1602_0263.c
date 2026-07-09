
void __stdcall16far
FUN_1602_0263(char param_1,byte param_2,char param_3,undefined1 param_4,undefined1 param_5,
             byte param_6,byte param_7)

{
  char cVar1;
  uint uVar2;
  undefined2 unaff_DS;
  byte local_4;
  char local_3;
  
  if (((param_7 < 0x28) && (param_6 < 0x19)) && ((*(uint *)0x686c | *(uint *)0x686e) != 0)) {
    if (param_1 == '\0') {
      local_4 = param_2;
    }
    else {
      uVar2 = FUN_1cc0_1c54(CONCAT11((char)((*(uint *)0x686c | *(uint *)0x686e) >> 8),param_2));
      local_4 = (byte)(((ulong)uVar2 & 0xffff00ff) % 0x40);
    }
    FUN_1cc0_1aaf(8,0x6870,unaff_DS,(int)*(undefined4 *)0x686c + (uint)local_4 * 8,
                  (int)((ulong)*(undefined4 *)0x686c >> 0x10));
    cVar1 = *(char *)0x44c8;
    if (cVar1 == '\0') {
      if (param_3 != '\0') {
        local_3 = '\x01';
        while( true ) {
          FUN_1602_15a6(local_4,param_4,param_5,param_6,param_7);
          param_7 = param_7 + 1;
          if (local_3 == param_3) break;
          local_3 = local_3 + '\x01';
        }
      }
    }
    else if (cVar1 == '\x01') {
      if (param_3 != '\0') {
        local_3 = '\x01';
        while( true ) {
          FUN_1602_1645(local_4,param_4,param_5,param_6,param_7);
          param_7 = param_7 + 1;
          if (local_3 == param_3) break;
          local_3 = local_3 + '\x01';
        }
      }
    }
    else if (cVar1 == '\x02') {
      if (param_3 != '\0') {
        local_3 = '\x01';
        while( true ) {
          FUN_1602_16a5(local_4,param_4,param_5,param_6,param_7);
          param_7 = param_7 + 1;
          if (local_3 == param_3) break;
          local_3 = local_3 + '\x01';
        }
      }
    }
    else if ((cVar1 == '\x03') && (param_3 != '\0')) {
      local_3 = '\x01';
      while( true ) {
        FUN_1602_17b4(local_4,param_4,param_5,param_6,param_7);
        param_7 = param_7 + 1;
        if (local_3 == param_3) break;
        local_3 = local_3 + '\x01';
      }
    }
  }
  return;
}


