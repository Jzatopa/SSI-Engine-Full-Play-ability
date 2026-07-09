
int __stdcall16far FUN_0000_6770(undefined2 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined4 local_d;
  undefined2 local_9;
  undefined2 local_7;
  undefined2 local_4;
  
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  iVar2 = (int)param_2;
  local_7 = *(int *)(iVar2 + 0x16);
  cVar1 = func_0x00000a91();
  if (cVar1 != '\0') {
    local_7 = local_7 + (*(int *)(iVar2 + 0x1a) + *(int *)(iVar2 + 0x1e) + *(int *)(iVar2 + 0x20)) /
                        3;
  }
  local_9 = 0;
  *(undefined1 *)0x7817 = 0;
  while( true ) {
    iVar3 = iVar2 + *(char *)0x7817 * 6;
    local_d = (byte *)CONCAT22(uVar4,(byte *)(iVar3 + 0x3c));
    if (*local_d != 0) {
      local_9 = local_9 + (uint)*(byte *)((uint)(*local_d & 0x7f) * 0x22 + 0x240b) *
                          (uint)*(byte *)(iVar3 + 0x3e);
    }
    if (*(char *)0x7817 == '\a') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
  }
  if (local_9 == 0) {
    local_4 = 0;
  }
  else {
    local_4 = local_7 + local_9;
  }
  return local_4;
}


