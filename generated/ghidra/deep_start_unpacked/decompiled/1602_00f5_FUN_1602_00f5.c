
void __stdcall16far FUN_1602_00f5(byte param_1)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x44ad = 5;
  *(byte *)0x44ac = param_1;
  FUN_1c3e_000b(0x44ac);
  *(int *)0x44c0 = (uint)param_1 * 0x200 + -0x6000;
  return;
}


