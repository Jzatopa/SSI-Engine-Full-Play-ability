
void __stdcall16far FUN_1836_006b(int param_1)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined2 *)(param_1 + -8) = 0;
  *(undefined1 *)(param_1 + -10) = 0;
  while ((cVar1 = FUN_1bdc_02fb(), cVar1 == '\0' && (*(char *)(param_1 + -10) == '\0'))) {
    FUN_1b6f_018d(param_1 + -9,unaff_SS,param_1 + -8,unaff_SS);
    if ((*(byte *)(param_1 + -9) < 8) || (*(int *)(param_1 + -8) != 0)) {
      if (*(byte *)(param_1 + -9) < 8) {
        *(undefined1 *)(param_1 + -2) = *(undefined1 *)(*(byte *)(param_1 + -9) + 0x3838);
      }
      else if (*(int *)(param_1 + -8) == 1) {
        *(undefined1 *)(param_1 + -2) = 0xd;
      }
      else if (*(int *)(param_1 + -8) == 2) {
        *(undefined1 *)(param_1 + -2) = 0x1b;
      }
      *(undefined1 *)(param_1 + -10) = 1;
    }
  }
  return;
}


