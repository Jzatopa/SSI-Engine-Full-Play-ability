/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:ad9c
 * Ghidra name: FUN_0000_ad9c
 * Linear address: 0x0AD9C
 * Original GAME.OVR file offset: 44452
 * Body addresses: 100
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

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


