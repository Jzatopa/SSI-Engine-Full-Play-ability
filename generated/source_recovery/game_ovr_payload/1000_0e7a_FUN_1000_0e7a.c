/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:0e7a
 * Ghidra name: FUN_1000_0e7a
 * Linear address: 0x10E7A
 * Original GAME.OVR file offset: 69250
 * Body addresses: 36
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_0e7a(char param_1)

{
  undefined2 unaff_DS;
  
  if ((param_1 == '\0') || (*(char *)0x72c5 == param_1)) {
    *(undefined1 *)0x72c6 = 0;
    *(undefined1 *)0x72c5 = 0;
    *(undefined1 *)0x72cf = 0;
  }
  return;
}


