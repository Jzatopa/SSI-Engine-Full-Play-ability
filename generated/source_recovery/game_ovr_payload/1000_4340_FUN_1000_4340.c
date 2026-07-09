/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:4340
 * Ghidra name: FUN_1000_4340
 * Linear address: 0x14340
 * Original GAME.OVR file offset: 82760
 * Body addresses: 157
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_4340(int param_1)

{
  undefined2 unaff_SS;
  
  if ((bool)(*(byte *)(param_1 + -2) & 1)) {
    if ((*(char *)(param_1 + -2) == '\x03') || (*(char *)(param_1 + -2) == '\x05')) {
      FUN_0000_4f8a();
    }
    else {
      FUN_0000_4f8a();
    }
  }
  else {
    FUN_0000_4f8a();
  }
  return;
}


