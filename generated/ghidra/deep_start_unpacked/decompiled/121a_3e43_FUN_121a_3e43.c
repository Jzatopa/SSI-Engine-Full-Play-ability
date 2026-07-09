
void FUN_121a_3e43(undefined1 param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_4 * 0x140 + param_2);
  param_4 = (param_3 + 1) - param_4;
  do {
    *puVar1 = param_1;
    puVar1 = puVar1 + 0x140;
    param_4 = param_4 + -1;
  } while (param_4 != 0);
  return;
}


