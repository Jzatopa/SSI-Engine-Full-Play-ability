/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:0eb8
 * Ghidra name: FUN_3000_0eb8
 * Linear address: 0x30EB8
 * Original GAME.OVR file offset: 200384
 * Body addresses: 421
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_3000_0eb8(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  char local_5;
  char local_4;
  undefined1 local_3;
  
  local_3 = 0;
  local_4 = '\x01';
  local_5 = '\x01';
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 10) < *(int *)(iVar1 + 0xc)) {
    if (*(int *)(iVar1 + 0x10) != *(int *)(iVar1 + 6)) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + *(int *)(iVar1 + 0x14);
      local_5 = (char)*(undefined2 *)(iVar1 + 0x14) + '\x01';
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar1 + 10);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar1 + 10);
      *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + '\x01';
      *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + '\x01';
      if (*(int *)(iVar1 + 0xc) <= *(int *)(iVar1 + 8)) {
        *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) - *(int *)(iVar1 + 0xc);
        *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) - *(int *)(iVar1 + 0xc);
        *(int *)(iVar1 + 0xe) = *(int *)(iVar1 + 0xe) + *(int *)(iVar1 + 0x12);
        local_4 = (char)*(undefined2 *)(iVar1 + 0x12) + '\x01';
        *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + '\x01';
      }
      local_3 = 1;
    }
  }
  else if (*(int *)(iVar1 + 0xe) != *(int *)(iVar1 + 4)) {
    *(int *)(iVar1 + 0xe) = *(int *)(iVar1 + 0xe) + *(int *)(iVar1 + 0x12);
    local_4 = (char)*(undefined2 *)(iVar1 + 0x12) + '\x01';
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar1 + 0xc);
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar1 + 0xc);
    *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + '\x01';
    *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + '\x01';
    if (*(int *)(iVar1 + 10) <= *(int *)(iVar1 + 8)) {
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) - *(int *)(iVar1 + 10);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) - *(int *)(iVar1 + 10);
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + *(int *)(iVar1 + 0x14);
      local_5 = (char)*(undefined2 *)(iVar1 + 0x14) + '\x01';
      *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + '\x01';
    }
    local_3 = 1;
  }
  *(undefined1 *)(iVar1 + 0x17) = ((undefined *)&DAT_0000_22b6)[local_5 * 3 + (int)local_4];
  return CONCAT11(local_5 >> 7,local_3);
}


