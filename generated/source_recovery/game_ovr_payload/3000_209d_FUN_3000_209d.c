/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:209d
 * Ghidra name: FUN_3000_209d
 * Linear address: 0x3209D
 * Original GAME.OVR file offset: 204965
 * Body addresses: 49
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_3000_209d(char param_1,char param_2)

{
  undefined1 local_3;
  
  if ((((param_2 < '\0') || ('\x06' < param_2)) || (param_1 < '\0')) || ('\x06' < param_1)) {
    local_3 = 0;
  }
  else {
    local_3 = 1;
  }
  return local_3;
}


