/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:13ba
 * Ghidra name: FUN_0000_13ba
 * Linear address: 0x013BA
 * Original GAME.OVR file offset: 5058
 * Body addresses: 34
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_13ba(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x4438 == '\x03') {
    FUN_0000_0775();
  }
  else {
    *(undefined1 *)0x443d = 1;
  }
  *(undefined1 *)0x74aa = 0;
  return;
}


