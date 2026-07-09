
long __stdcall16far FUN_1000_a892(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined1 local_4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  local_4 = *(char *)(*(byte *)(iVar2 + 0x12) + 0x3343);
  if ((*(char *)(iVar2 + 0x28) != '\x03') && ('\x02' < local_4)) {
    local_4 = '\x02';
  }
  cVar1 = *(char *)(iVar2 + 0x28);
  if (cVar1 == '\x03') {
    local_4 = local_4 + '\n';
  }
  else if ((cVar1 == '\x06') || (cVar1 == '\x04')) {
    local_4 = local_4 + '\b';
  }
  else if ((cVar1 == '\x01') || ((cVar1 == '\x05' || (cVar1 == '\x02')))) {
    local_4 = local_4 + '\x06';
  }
  return (ulong)(uint)(int)local_4 * (ulong)(uint)(int)*(char *)(iVar2 + 0x29);
}


