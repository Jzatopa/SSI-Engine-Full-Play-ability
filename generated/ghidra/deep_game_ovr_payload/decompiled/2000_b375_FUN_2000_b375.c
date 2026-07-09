
undefined2 __stdcall16far FUN_2000_b375(char param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined1 local_3;
  
  iVar2 = (int)param_1;
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  iVar3 = (int)param_2;
  if ((*(char *)(iVar3 + iVar2 + 0x4c) == '\0') || (*(char *)(iVar3 + 0xd5) == '\0')) {
    local_3 = 0;
  }
  else {
    cVar1 = FUN_2000_b332((int)param_1,iVar3,uVar4);
    iVar2 = (uint)*(byte *)(iVar3 + param_1 + 0x4c) + (int)cVar1;
    local_3 = (undefined1)iVar2;
  }
  return CONCAT11((char)((uint)iVar2 >> 8),local_3);
}


