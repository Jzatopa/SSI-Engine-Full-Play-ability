
void __stdcall16far
FUN_1000_0f2d(char param_1,undefined2 param_2,undefined2 param_3,undefined4 *param_4)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  if (param_1 == '\0') {
    *(char *)0x72cf = *(char *)0x72cf + -4;
    pcVar1 = (char *)((int)*param_4 + 0xd9);
    *pcVar1 = *pcVar1 + -4;
    pcVar1 = (char *)((int)*param_4 + 0xda);
    *pcVar1 = *pcVar1 + -4;
    *(char *)0x72c4 = *(char *)0x72c4 + -4;
  }
  return;
}


