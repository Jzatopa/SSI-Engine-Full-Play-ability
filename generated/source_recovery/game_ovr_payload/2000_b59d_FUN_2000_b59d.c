/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b59d
 * Ghidra name: FUN_2000_b59d
 * Linear address: 0x2B59D
 * Original GAME.OVR file offset: 177573
 * Body addresses: 41
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

bool __stdcall16far FUN_2000_b59d(byte param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0000_e1ea(100);
  return uVar1 < param_1;
}


