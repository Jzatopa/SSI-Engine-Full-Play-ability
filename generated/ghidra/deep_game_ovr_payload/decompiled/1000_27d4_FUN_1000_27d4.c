
void __stdcall16far FUN_1000_27d4(undefined4 param_1)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined2 uVar4;
  undefined1 local_3;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  pcVar1 = (char *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xd);
  *pcVar1 = *pcVar1 + '\x01';
  bVar2 = func_0x00000dd5();
  local_3 = (byte)((ulong)(long)(int)(((uint)bVar2 -
                                      (uint)*(byte *)((int)*(undefined4 *)(iVar3 + 0xf3) + 7)) + 8)
                  % 8);
  if (4 < local_3) {
    local_3 = 8 - local_3;
  }
  *(undefined1 *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xe) =
       (char)((ulong)(long)(int)((uint)*(byte *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xe) +
                                (uint)local_3) % 8);
  return;
}


