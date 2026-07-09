/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:e99c
 * Ghidra name: FUN_2000_e99c
 * Linear address: 0x2E99C
 * Original GAME.OVR file offset: 190884
 * Body addresses: 52
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_e99c(undefined2 param_1,char param_2)

{
  undefined1 local_3;
  
  if (param_2 == '\b') {
    local_3 = 0;
  }
  else if (param_2 == 'A') {
    local_3 = 0;
  }
  else if (param_2 == -0x18) {
    local_3 = 0xf;
  }
  else {
    local_3 = 0xf;
  }
  return local_3;
}


