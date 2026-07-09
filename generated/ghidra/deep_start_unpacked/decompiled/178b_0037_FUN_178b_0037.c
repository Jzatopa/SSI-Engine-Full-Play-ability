
void __stdcall16far
FUN_178b_0037(undefined1 param_1,byte param_2,byte param_3,undefined1 param_4,undefined1 param_5)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x44ad = 2;
  *(undefined1 *)0x44af = 0;
  *(undefined1 *)0x44b3 = param_4;
  *(undefined1 *)0x44b2 = param_5;
  FUN_1c3e_000b(0x44ac);
  *(undefined1 *)0x44ad = 9;
  *(undefined1 *)0x44ac = param_1;
  *(undefined1 *)0x44af = 0;
  if (*(char *)0x44c8 == '\0') {
    *(undefined1 *)0x44ae = *(undefined1 *)(param_3 + 0x22cb);
  }
  else {
    *(byte *)0x44ae = param_3;
  }
  *(uint *)0x44b0 = (uint)param_2;
  FUN_1c3e_000b(0x44ac);
  return;
}


