/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b5c6
 * Ghidra name: FUN_2000_b5c6
 * Linear address: 0x2B5C6
 * Original GAME.OVR file offset: 177614
 * Body addresses: 35
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

uint __stdcall16far FUN_2000_b5c6(uint param_1,uint param_2)

{
  undefined2 local_4;
  
  local_4 = param_2;
  if (param_1 < param_2) {
    local_4 = param_1;
  }
  return local_4;
}


