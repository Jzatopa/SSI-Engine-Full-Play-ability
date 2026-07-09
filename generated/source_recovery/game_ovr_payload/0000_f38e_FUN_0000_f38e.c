/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:f38e
 * Ghidra name: FUN_0000_f38e
 * Linear address: 0x0F38E
 * Original GAME.OVR file offset: 62358
 * Body addresses: 49
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_0000_f38e(char param_1,char param_2)

{
  undefined1 local_3;
  
  if (((param_2 < '\0') || ('\n' < param_2)) && ((param_1 < '\0' || ('\x05' < param_1)))) {
    local_3 = 1;
  }
  else {
    local_3 = 0;
  }
  return local_3;
}


