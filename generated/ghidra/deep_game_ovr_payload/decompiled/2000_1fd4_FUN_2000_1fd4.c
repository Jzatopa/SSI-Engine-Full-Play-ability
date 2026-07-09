
char __stdcall16far FUN_2000_1fd4(undefined4 param_1)

{
  int *piVar1;
  undefined2 uVar2;
  undefined2 local_8;
  undefined2 uStack_6;
  undefined1 local_4;
  
  local_4 = '\0';
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  uStack_6 = *(int *)((int)param_1 + 0xf9);
  local_8 = *(int *)((int)param_1 + 0xf7);
  while (local_8 != 0 || uStack_6 != 0) {
    local_4 = local_4 + '\x01';
    piVar1 = (int *)(local_8 + 0x2a);
    uStack_6 = *(int *)(local_8 + 0x2c);
    local_8 = *piVar1;
  }
  return local_4;
}


