
void __stdcall16far FUN_2000_cecc(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((((*(int *)(param_1 + -0x210) < 4) || (0x15 < *(int *)(param_1 + -0x210))) ||
      (*(int *)(param_1 + -0x20e) < 0x13)) || (0x24 < *(int *)(param_1 + -0x20e))) {
    FUN_2000_c83b(param_1);
    *(undefined1 *)0x8d71 = 0;
    *(undefined1 *)0x7483 = 0;
    *(undefined1 *)(param_1 + -0x212) = 0;
  }
  else {
    *(undefined1 *)0x7483 = 0x21;
    *(undefined1 *)(param_1 + -0x212) = 1;
  }
  *(undefined1 *)0x7458 = 0;
  return;
}


