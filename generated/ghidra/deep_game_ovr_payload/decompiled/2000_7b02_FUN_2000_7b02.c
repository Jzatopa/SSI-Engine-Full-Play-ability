
undefined1 __stdcall16far FUN_2000_7b02(byte param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  uVar1 = FUN_0000_09ba();
  *(undefined1 *)0x72cf = uVar1;
  if ('\x01' < *(char *)0x72cf) {
    if (*(char *)0x72cf == '\x14') {
      *(undefined1 *)0x72cf = 100;
    }
    FUN_2000_780a(&param_2,unaff_SS,0x10);
    if ((-1 < *(char *)0x72cf) &&
       ((int)(uint)*(byte *)((int)param_2 + 0xd9) < (int)((int)*(char *)0x72cf + (uint)param_1))) {
      local_3 = 1;
    }
  }
  return local_3;
}


