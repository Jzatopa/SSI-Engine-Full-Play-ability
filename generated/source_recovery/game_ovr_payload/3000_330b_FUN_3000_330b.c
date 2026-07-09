/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:330b
 * Ghidra name: FUN_3000_330b
 * Linear address: 0x3330B
 * Original GAME.OVR file offset: 209683
 * Body addresses: 98
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_330b(byte param_1)

{
  undefined2 unaff_DS;
  
  if (*(int *)((uint)param_1 * 8 + 0x68c0) != 0 || *(int *)((uint)param_1 * 8 + 0x68c2) != 0) {
    FUN_0000_453c((uint)param_1 * 8 + 0x68c0);
  }
  if (*(int *)((uint)param_1 * 8 + 0x68c4) != 0 || *(int *)((uint)param_1 * 8 + 0x68c6) != 0) {
    FUN_0000_453c((uint)param_1 * 8 + 0x68c4);
  }
  return;
}


