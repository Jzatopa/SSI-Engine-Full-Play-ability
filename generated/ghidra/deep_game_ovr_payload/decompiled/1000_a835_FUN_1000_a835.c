
long __stdcall16far FUN_1000_a835(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 local_4;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  local_4 = *(char *)(*(byte *)(iVar1 + 0x12) + 0x3343) + '\x01';
  if (local_4 < '\x01') {
    local_4 = '\x01';
  }
  if (('\x03' < local_4) && (*(char *)(iVar1 + 0x28) != '\x03')) {
    local_4 = '\x03';
  }
  return (ulong)(uint)(int)local_4 * (ulong)(uint)(int)*(char *)(iVar1 + 0x29);
}


