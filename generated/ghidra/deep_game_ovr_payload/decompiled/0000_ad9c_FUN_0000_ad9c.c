
undefined1 __stdcall16far FUN_0000_ad9c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 1;
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(char *)(iVar2 + 0xd4) == '\v') {
    local_3 = 0;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0xeb);
    iVar2 = *(int *)(iVar2 + 0xed);
    if (((iVar1 != 0 || iVar2 != 0) &&
        (((undefined *)&DAT_0000_5370)[(uint)*(byte *)(iVar1 + 0x2e) * 9] == '\x01')) &&
       (*(char *)(iVar1 + 0x38) == '\0')) {
      local_3 = 0;
    }
  }
  return local_3;
}


