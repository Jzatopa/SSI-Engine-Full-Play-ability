
void __stdcall16far FUN_2000_c7fa(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x7458 = 0;
  *(undefined1 *)0x7483 =
       *(undefined1 *)
        (param_1 + (uint)*(byte *)(param_1 + (uint)*(byte *)0x7457 * 2 + -0x23e) + -0x200);
  if (*(char *)0x7483 == '\0') {
    *(undefined1 *)0x7483 = 0xd;
  }
  *(undefined1 *)(param_1 + -0x212) = 1;
  return;
}


