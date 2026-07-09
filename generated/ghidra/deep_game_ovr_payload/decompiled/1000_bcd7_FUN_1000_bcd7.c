
ulong __stdcall16far FUN_1000_bcd7(undefined4 param_1)

{
  undefined2 unaff_DS;
  ulong uVar1;
  
  if (*(char *)((int)*(undefined4 *)0x441c + 0x36d) == '\0') {
    uVar1 = (ulong)*(uint *)((int)param_1 + 0x39);
  }
  else {
    func_0x0000d612();
    uVar1 = FUN_0000_d62d(0xcc0);
  }
  return uVar1;
}


