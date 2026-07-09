/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:8c30
 * Ghidra name: FUN_2000_8c30
 * Linear address: 0x28C30
 * Original GAME.OVR file offset: 166968
 * Body addresses: 75
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

char __stdcall16far FUN_2000_8c30(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_5;
  undefined1 local_4;
  
  local_5 = '\0';
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    local_4 = 1;
    while( true ) {
      if (*(char *)((int)param_2 + (uint)local_4 + 0xb9) == *(char *)((int)param_1 + 0x2e)) {
        local_5 = local_5 + '\x01';
      }
      if (local_4 == 10) break;
      local_4 = local_4 + 1;
    }
  }
  return local_5;
}


