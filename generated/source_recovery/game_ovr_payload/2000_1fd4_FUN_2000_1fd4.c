/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:1fd4
 * Ghidra name: FUN_2000_1fd4
 * Linear address: 0x21FD4
 * Original GAME.OVR file offset: 139228
 * Body addresses: 74
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - character_sheet_labels (character_sheet), previous candidate, distance 75 byte(s), source offset 139303
 */

char __stdcall16far FUN_2000_1fd4(undefined4 param_1)

{
  int *piVar1;
  undefined2 uVar2;
  undefined2 local_8;
  undefined2 uStack_6;
  undefined1 local_4;
  
  local_4 = '\0';
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  uStack_6 = *(int *)((int)param_1 + 0xf9);
  local_8 = *(int *)((int)param_1 + 0xf7);
  while (local_8 != 0 || uStack_6 != 0) {
    local_4 = local_4 + '\x01';
    piVar1 = (int *)(local_8 + 0x2a);
    uStack_6 = *(int *)(local_8 + 0x2c);
    local_8 = *piVar1;
  }
  return local_4;
}


