/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:8093
 * Ghidra name: FUN_0000_8093
 * Linear address: 0x08093
 * Original GAME.OVR file offset: 32923
 * Body addresses: 50
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_0000_8093(undefined2 param_1,char param_2)

{
  undefined1 local_3;
  
  if (param_2 == '\a') {
    local_3 = 8;
  }
  else if (((param_2 == '\x02') || (param_2 == '\x04')) || (param_2 == '\b')) {
    local_3 = 7;
  }
  else {
    local_3 = 6;
  }
  return local_3;
}


