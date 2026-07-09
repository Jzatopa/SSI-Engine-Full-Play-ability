/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e892
 * Ghidra name: FUN_0000_e892
 * Linear address: 0x0E892
 * Original GAME.OVR file offset: 59546
 * Body addresses: 91
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

bool __stdcall16far FUN_0000_e892(undefined2 param_1,char param_2,char param_3)

{
  undefined2 unaff_DS;
  bool local_3;
  
  if ((((param_3 < '\0') || ('1' < param_3)) || (param_2 < '\0')) || ('\x18' < param_2)) {
    local_3 = false;
  }
  else {
    local_3 = (int)*(undefined4 *)0x71dc + param_2 * 0x32 + (int)param_3 == 0;
    FUN_0000_d977();
    local_3 = !local_3;
  }
  return local_3;
}


