
void FUN_121a_3e17(undefined1 param_1,byte param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)((uint)param_2 * 0x140 + param_4);
  for (param_4 = (param_3 + 1) - param_4; param_4 != 0; param_4 = param_4 + -1) {
    puVar1 = puVar2;
    puVar2 = puVar2 + 1;
    *puVar1 = param_1;
  }
  return;
}


