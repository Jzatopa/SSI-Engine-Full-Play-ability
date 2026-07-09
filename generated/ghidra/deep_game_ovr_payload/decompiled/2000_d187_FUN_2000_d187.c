
void __stdcall16far FUN_2000_d187(int param_1)

{
  undefined2 unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (((0 < *(int *)(param_1 + -0x20e)) && (*(int *)(param_1 + -0x20e) < 0x27)) &&
     (5 < *(int *)(param_1 + -0x210))) {
    *(char *)0x747e = (char)*(undefined2 *)(param_1 + -0x210) + -5;
    *(undefined1 *)0x8d71 = 0;
    FUN_0000_c05c(0x41,unaff_BP);
  }
  *(undefined1 *)(param_1 + -0x212) = 1;
  return;
}


