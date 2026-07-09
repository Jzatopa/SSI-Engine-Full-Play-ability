/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:fd91
 * Ghidra name: FUN_2000_fd91
 * Linear address: 0x2FD91
 * Original GAME.OVR file offset: 195993
 * Body addresses: 49
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_fd91(char param_1,char param_2)

{
  undefined1 local_3;
  
  if ((((param_2 < '\x10') && (-1 < param_2)) && (param_1 < '\x10')) && (-1 < param_1)) {
    local_3 = 1;
  }
  else {
    local_3 = 0;
  }
  return local_3;
}


