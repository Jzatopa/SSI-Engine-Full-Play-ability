/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:0c71
 * Ghidra name: FUN_3000_0c71
 * Linear address: 0x30C71
 * Original GAME.OVR file offset: 199801
 * Body addresses: 46
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_3000_0c71(int param_1)

{
  undefined2 local_4;
  
  if (param_1 < 0) {
    local_4 = 0xffff;
  }
  else if (param_1 < 1) {
    local_4 = 0;
  }
  else {
    local_4 = 1;
  }
  return local_4;
}


