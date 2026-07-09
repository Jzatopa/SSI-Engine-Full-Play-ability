/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e281
 * Ghidra name: FUN_0000_e281
 * Linear address: 0x0E281
 * Original GAME.OVR file offset: 57993
 * Body addresses: 116
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

byte __stdcall16far FUN_0000_e281(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = FUN_0000_e1ff();
  bVar2 = FUN_0000_e1ff();
  return bVar1 | bVar2;
}


