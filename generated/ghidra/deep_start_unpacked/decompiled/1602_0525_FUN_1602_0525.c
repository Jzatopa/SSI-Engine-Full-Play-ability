
void __stdcall16far FUN_1602_0525(int param_1)

{
  undefined2 unaff_SS;
  
  while ((*(byte *)(param_1 + -0x103) < *(byte *)(param_1 + -0x101) &&
         (*(char *)(param_1 + (uint)*(byte *)(param_1 + -0x103) + -0x100) == ' '))) {
    *(char *)(param_1 + -0x103) = *(char *)(param_1 + -0x103) + '\x01';
  }
  return;
}


