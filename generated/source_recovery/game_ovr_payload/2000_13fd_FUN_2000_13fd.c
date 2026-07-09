/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:13fd
 * Ghidra name: FUN_2000_13fd
 * Linear address: 0x213FD
 * Original GAME.OVR file offset: 136197
 * Body addresses: 274
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - load_game (save_load), next candidate, distance 1670 byte(s), source offset 134527
 *   - save_game (save_load), previous candidate, distance 275 byte(s), source offset 136472
 */

int __stdcall16far FUN_2000_13fd(void)

{
  int *piVar1;
  undefined2 unaff_DS;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined2 local_c;
  undefined2 uStack_a;
  undefined2 local_8;
  undefined2 uStack_6;
  
  local_12 = 0;
  uStack_6 = *(int *)0x5801;
  local_8 = *(int *)0x57ff;
  while (local_8 != 0 || uStack_6 != 0) {
    local_12 = local_12 + 0x103;
    if (*(int *)(local_8 + 0xf7) == 0 && *(int *)(local_8 + 0xf9) == 0) {
      if (*(int *)(local_8 + 0xb4) != 0 || *(int *)(local_8 + 0xb6) != 0) {
        uStack_a = *(int *)(local_8 + 0xb6);
        local_c = *(int *)(local_8 + 0xb4);
        while (local_c != 0 || uStack_a != 0) {
          local_12 = local_12 + 0x3e;
          piVar1 = (int *)(local_c + 0x2a);
          uStack_a = *(int *)(local_c + 0x2c);
          local_c = *piVar1;
        }
      }
    }
    else {
      uStack_a = *(int *)(local_8 + 0xf9);
      local_c = *(int *)(local_8 + 0xf7);
      while (local_c != 0 || uStack_a != 0) {
        local_12 = local_12 + 0x3e;
        piVar1 = (int *)(local_c + 0x2a);
        uStack_a = *(int *)(local_c + 0x2c);
        local_c = *piVar1;
      }
    }
    if (*(int *)(local_8 + 0xfb) != 0 || *(int *)(local_8 + 0xfd) != 0) {
      uStack_e = *(int *)(local_8 + 0xfd);
      local_10 = *(int *)(local_8 + 0xfb);
      while (local_10 != 0 || uStack_e != 0) {
        local_12 = local_12 + 9;
        piVar1 = (int *)(local_10 + 5);
        uStack_e = *(int *)(local_10 + 7);
        local_10 = *piVar1;
      }
    }
    piVar1 = (int *)(local_8 + 0xff);
    uStack_6 = *(int *)(local_8 + 0x101);
    local_8 = *piVar1;
  }
  return local_12;
}


