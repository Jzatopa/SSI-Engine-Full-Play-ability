
void __stdcall16far FUN_1000_a918(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  char local_6;
  byte local_5;
  char local_3;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(char *)(iVar1 + 0x29) < '\n') {
    local_5 = 6;
    if (*(char *)(iVar1 + 0x28) == '\x03') {
      local_5 = 10;
    }
    else if (*(char *)(iVar1 + 0x28) == '\x04') {
      local_5 = 8;
    }
    uVar3 = 1;
    uVar4 = (uint)local_5;
    local_3 = FUN_0000_09ba();
    cVar2 = FUN_0000_09ba(0x99,local_5,1,uVar4,uVar3);
    if (local_3 < cVar2) {
      local_3 = cVar2;
    }
    local_6 = *(char *)(*(byte *)(iVar1 + 0x12) + 0x3343);
    if ((*(char *)(iVar1 + 0x28) != '\x03') && ('\x02' < local_6)) {
      local_6 = '\x02';
    }
    local_3 = local_3 + local_6;
    if (local_3 < '\x01') {
      local_3 = '\x01';
    }
  }
  else {
    cVar2 = *(char *)(iVar1 + 0x28);
    if ((((cVar2 == '\x01') || (cVar2 == '\x04')) || (cVar2 == '\x05')) ||
       ((cVar2 == '\x02' || (cVar2 == '\x06')))) {
      local_3 = '\x02';
    }
    else if (cVar2 == '\x03') {
      local_3 = '\x03';
    }
  }
  *(int *)(iVar1 + 0x45) = *(int *)(iVar1 + 0x45) + (int)local_3;
  *(int *)(iVar1 + 0xe3) = *(int *)(iVar1 + 0xe3) + (int)local_3;
  return;
}


