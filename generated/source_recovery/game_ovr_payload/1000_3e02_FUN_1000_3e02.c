/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:3e02
 * Ghidra name: FUN_1000_3e02
 * Linear address: 0x13E02
 * Original GAME.OVR file offset: 81418
 * Body addresses: 88
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_1000_3e02(byte param_1,byte param_2)

{
  undefined1 local_3;
  
  if (param_1 < 2) {
    local_3 = 0;
  }
  else if ((uint)param_1 * 3 >> 2 < (uint)param_2) {
    local_3 = 5;
  }
  else if (param_1 >> 1 < param_2) {
    local_3 = 2;
  }
  else {
    local_3 = 0;
  }
  return local_3;
}


