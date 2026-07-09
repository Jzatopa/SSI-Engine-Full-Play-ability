
void __stdcall16far
FUN_10b8_0127(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(byte *)(iVar1 + (int)param_3) =
         *(byte *)(iVar1 + (int)param_4) ^ *(byte *)(iVar1 + (int)param_2);
    iVar1 = iVar1 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}


