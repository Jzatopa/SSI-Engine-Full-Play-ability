/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:1391
 * Ghidra name: FUN_1000_1391
 * Linear address: 0x11391
 * Original GAME.OVR file offset: 70553
 * Body addresses: 35
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_1391(char param_1)

{
  undefined2 unaff_DS;
  
  if (param_1 == '\0') {
    *(byte *)0x72c9 = *(byte *)0x72c9 >> 1;
    *(byte *)0x72c8 = *(byte *)0x72c8 >> 1;
  }
  return;
}


