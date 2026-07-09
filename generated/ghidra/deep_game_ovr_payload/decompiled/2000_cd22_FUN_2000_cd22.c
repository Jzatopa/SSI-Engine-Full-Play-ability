
void __stdcall16far FUN_2000_cd22(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x7458 = 1;
  *(undefined1 *)0x7483 =
       *(undefined1 *)(*(int *)(param_1 + -0x210) * 0xb + *(int *)(param_1 + -0x20e) + 0x3179);
  *(undefined1 *)(param_1 + -0x212) = 1;
  return;
}


