
void __stdcall16far FUN_2000_d080(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(char *)0x7457 == '\x01') {
    *(undefined1 *)0x7457 = *(undefined1 *)(param_1 + -0x23d);
  }
  else {
    *(char *)0x7457 = *(char *)0x7457 + -1;
  }
  FUN_2000_c618(param_1,*(undefined1 *)0x7457);
  *(undefined1 *)(param_1 + -0x212) = 0;
  return;
}


