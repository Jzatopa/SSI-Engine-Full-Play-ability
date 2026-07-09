/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:98be
 * Ghidra name: FUN_2000_98be
 * Linear address: 0x298BE
 * Original GAME.OVR file offset: 170182
 * Body addresses: 738
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_98be(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  int local_b;
  int local_7;
  int iStack_5;
  byte local_3;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  *(undefined2 *)(iVar4 + 0xef) = 0;
  *(undefined2 *)(iVar4 + 0xf1) = 0;
  *(undefined2 *)(iVar4 + 0xeb) = 0;
  *(undefined2 *)(iVar4 + 0xed) = 0;
  local_7 = *(int *)(iVar4 + 0xf7);
  iStack_5 = *(int *)(iVar4 + 0xf9);
  *(undefined2 *)(iVar4 + 0xe8) = 0;
  while (local_7 != 0 || iStack_5 != 0) {
    cVar2 = ((undefined *)&DAT_0000_536e)[(uint)*(byte *)(local_7 + 0x2e) * 9];
    if ((cVar2 != '\x01') || ((*(byte *)(local_7 + 0x34) & 0x80) == 0)) {
      local_b = *(int *)(local_7 + 0x36);
      if ((*(char *)(local_7 + 0x38) != '\0') && ((*(byte *)(local_7 + 0x34) & 0x20) == 0)) {
        local_b = (uint)*(byte *)(local_7 + 0x38) * local_b;
      }
      *(int *)(iVar4 + 0xe8) = *(int *)(iVar4 + 0xe8) + local_b;
    }
    if ((*(byte *)(local_7 + 0x34) & 0x80) != 0) {
      if (cVar2 == '\0') {
        *(int *)(iVar4 + 0xeb) = local_7;
        *(int *)(iVar4 + 0xed) = iStack_5;
      }
      else if (cVar2 == '\x01') {
        *(int *)(iVar4 + 0xef) = local_7;
        *(int *)(iVar4 + 0xf1) = iStack_5;
      }
    }
    piVar1 = (int *)(local_7 + 0x2a);
    iStack_5 = *(int *)(local_7 + 0x2c);
    local_7 = *piVar1;
  }
  local_3 = 1;
  while( true ) {
    *(undefined1 *)(iVar4 + (uint)local_3 + 0xdc) = *(undefined1 *)(iVar4 + (uint)local_3 + 0x3c);
    *(undefined1 *)(iVar4 + (uint)local_3 + 0xde) = *(undefined1 *)(iVar4 + (uint)local_3 + 0x3e);
    *(undefined1 *)(iVar4 + (uint)local_3 + 0xe0) = *(undefined1 *)(iVar4 + (uint)local_3 + 0x40);
    if (local_3 == 2) break;
    local_3 = local_3 + 1;
  }
  *(undefined1 *)(iVar4 + 0xd8) = *(undefined1 *)(iVar4 + 0x33);
  if (*(int *)(iVar4 + 0xeb) == 0 && *(int *)(iVar4 + 0xed) == 0) {
    cVar2 = FUN_2000_8cbd(iVar4,uVar5);
    *(char *)(iVar4 + 0xd8) = *(char *)(iVar4 + 0xd8) + cVar2;
    cVar2 = FUN_2000_8cde(iVar4,uVar5);
    *(char *)(iVar4 + 0xe1) = *(char *)(iVar4 + 0xe1) + cVar2;
  }
  FUN_2000_8517(iVar4,uVar5);
  if (*(char *)(iVar4 + 0xd4) == '\f') {
    *(char *)(iVar4 + 0xd8) = *(char *)(iVar4 + 0xd8) + -2;
  }
  if (((undefined *)&DAT_0000_750f)[*(char *)(iVar4 + 0xd6)] != '\0') {
    *(char *)(iVar4 + 0xd8) = *(char *)(iVar4 + 0xd8) + '\x01';
  }
  *(undefined1 *)(iVar4 + 0x48) = 0;
  *(undefined1 *)(iVar4 + 0xd9) = *(undefined1 *)(iVar4 + 0x37);
  iStack_5 = *(int *)(iVar4 + 0xf9);
  local_7 = *(int *)(iVar4 + 0xf7);
  while (local_7 != 0 || iStack_5 != 0) {
    if ((*(byte *)(local_7 + 0x34) & 0x80) != 0) {
      FUN_2000_9802(local_7,iStack_5,iVar4,uVar5);
    }
    piVar1 = (int *)(local_7 + 0x2a);
    iStack_5 = *(int *)(local_7 + 0x2c);
    local_7 = *piVar1;
  }
  uVar3 = FUN_2000_9ba0(iVar4,uVar5);
  *(undefined1 *)(iVar4 + 0xe5) = (char)((uVar3 & 0xff) >> 1);
  if (*(char *)(iVar4 + 0xd4) == '\n') {
    if (*(char *)(iVar4 + 0x29) < '\x04') {
      *(char *)(iVar4 + 0xd9) = *(char *)(iVar4 + 0xd9) + '\x02';
    }
    else {
      *(char *)(iVar4 + 0xd9) =
           *(char *)(iVar4 + 0xd9) + (char)((uint)(int)*(char *)(iVar4 + 0x29) >> 1);
    }
  }
  *(char *)(iVar4 + 0xda) = *(char *)(iVar4 + 0xd9) + -2;
  cVar2 = FUN_2000_8c7b(iVar4,uVar5);
  *(char *)(iVar4 + 0xd9) = *(char *)(iVar4 + 0xd9) + cVar2;
  return;
}


