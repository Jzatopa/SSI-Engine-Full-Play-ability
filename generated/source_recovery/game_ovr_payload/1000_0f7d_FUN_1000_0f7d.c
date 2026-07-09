/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:0f7d
 * Ghidra name: FUN_1000_0f7d
 * Linear address: 0x10F7D
 * Original GAME.OVR file offset: 69509
 * Body addresses: 21
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_0f7d(void)

{
  uint in_AX;
  undefined2 unaff_DS;
  
  if (*(char *)0x72c5 == '\x02') {
    FUN_1000_0e7a(in_AX & 0xff00);
  }
  return;
}


