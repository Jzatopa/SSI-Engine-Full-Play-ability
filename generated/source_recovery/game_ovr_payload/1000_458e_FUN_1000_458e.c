/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:458e
 * Ghidra name: FUN_1000_458e
 * Linear address: 0x1458E
 * Original GAME.OVR file offset: 83350
 * Body addresses: 139
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_1000_458e(void)

{
  int *piVar1;
  undefined2 unaff_DS;
  undefined2 local_a;
  undefined2 uStack_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_4 = 0;
  local_6 = 0;
  uStack_8 = *(int *)0x5801;
  local_a = *(int *)0x57ff;
  while (local_a != 0 || uStack_8 != 0) {
    if (*(char *)(local_a + 0xd6) == '\x01') {
      if (*(char *)(local_a + 0xd5) != '\0') {
        local_6 = local_6 + *(int *)(local_a + 0xe3);
      }
      local_4 = local_4 + *(int *)(local_a + 0x45);
    }
    piVar1 = (int *)(local_a + 0xff);
    uStack_8 = *(int *)(local_a + 0x101);
    local_a = *piVar1;
  }
  if (local_4 != 0) {
    *(char *)0x7505 = (char)(((ulong)local_6 * 0x14 & 0xffff) / (ulong)local_4) * '\x05';
  }
  return;
}


