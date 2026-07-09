
void __cdecl16far FUN_0000_0eb5(void)

{
  undefined1 in_AL;
  char in_CH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_DS;
  
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + in_CH;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c1) = in_AL;
  if (*(byte *)((int)*(undefined4 *)0x441c + 0x2c0) < *(byte *)((int)*(undefined4 *)0x441c + 0x2c1))
  {
    *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c1) =
         *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c0);
  }
  FUN_0000_06f3();
  return;
}


