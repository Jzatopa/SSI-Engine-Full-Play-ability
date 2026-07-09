
undefined1 __stdcall16far FUN_0000_635d(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  char cVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  *(undefined1 *)0x7817 = 0;
  while( true ) {
    cVar1 = FUN_0000_6308(param_1,*(undefined1 *)0x7817,param_2,param_3);
    if (cVar1 != '\0') {
      local_3 = 1;
    }
    if (*(char *)0x7817 == '\a') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
  }
  return local_3;
}


