/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:9f75
 * Ghidra name: FUN_2000_9f75
 * Linear address: 0x29F75
 * Original GAME.OVR file offset: 171901
 * Body addresses: 36
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

bool __stdcall16far FUN_2000_9f75(undefined4 param_1)

{
  return *(char *)((int)param_1 + 0xd6) == '\0';
}


