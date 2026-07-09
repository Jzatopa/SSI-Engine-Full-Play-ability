/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:ea04
 * Ghidra name: FUN_2000_ea04
 * Linear address: 0x2EA04
 * Original GAME.OVR file offset: 190988
 * Body addresses: 62
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_ea04(undefined2 param_1,char param_2)

{
  undefined1 local_3;
  
  if (param_2 == '\v') {
    local_3 = 8;
  }
  else if (param_2 == '\t') {
    local_3 = 6;
  }
  else if (param_2 == -0x25) {
    local_3 = 6;
  }
  else if (param_2 == '\x06') {
    local_3 = 1;
  }
  else {
    local_3 = 6;
  }
  return local_3;
}


