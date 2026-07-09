
void __stdcall16far FUN_2000_d0e6(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(byte *)(param_1 + -0x24b) < *(byte *)0x7457) {
    *(char *)0x7457 = *(char *)0x7457 - *(char *)(param_1 + -0x24b);
    if (*(byte *)(param_1 + -0x24b) < *(byte *)0x7457) {
      *(undefined1 *)0x7457 = *(undefined1 *)(param_1 + -0x24b);
    }
  }
  else {
    *(char *)0x7457 = *(char *)0x7457 + *(char *)(param_1 + -0x24b);
    if (*(byte *)(param_1 + -0x23d) < *(byte *)0x7457) {
      *(undefined1 *)0x7457 = *(undefined1 *)(param_1 + -0x23d);
    }
  }
  FUN_2000_c618(param_1,*(undefined1 *)0x7457);
  *(undefined1 *)(param_1 + -0x212) = 0;
  return;
}


