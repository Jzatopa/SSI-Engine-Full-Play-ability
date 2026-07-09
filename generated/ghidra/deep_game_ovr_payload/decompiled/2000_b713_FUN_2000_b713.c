
undefined1 __stdcall16far FUN_2000_b713(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (((*(int *)(iVar2 + 0x1a) < 1) || (*(int *)(iVar2 + 0x1e) < 1)) || (*(int *)(iVar2 + 0x20) < 1)
     ) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


