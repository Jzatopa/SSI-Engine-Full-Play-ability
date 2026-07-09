/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:d677
 * Ghidra name: FUN_1000_d677
 * Linear address: 0x1D677
 * Original GAME.OVR file offset: 120447
 * Body addresses: 36
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

int __stdcall16far FUN_1000_d677(byte param_1,byte param_2)

{
  return (uint)param_1 * 0x100 + (uint)param_2;
}


