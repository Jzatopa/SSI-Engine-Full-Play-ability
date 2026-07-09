/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:d6c3
 * Ghidra name: FUN_1000_d6c3
 * Linear address: 0x1D6C3
 * Original GAME.OVR file offset: 120523
 * Body addresses: 91
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_1000_d6c3(uint param_1)

{
  undefined1 local_3;
  
  local_3 = 4;
  if ((0x4aff < param_1) && (param_1 < 0x4f00)) {
    local_3 = 0;
  }
  if ((0x7bff < param_1) && (param_1 < 0x8000)) {
    local_3 = 1;
  }
  if ((0x79ff < param_1) && (param_1 < 0x7c00)) {
    local_3 = 2;
  }
  if ((0x7fff < param_1) && (param_1 < 0xa401)) {
    local_3 = 3;
  }
  return local_3;
}


