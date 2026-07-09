/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:33a2
 * Ghidra name: FUN_0000_33a2
 * Linear address: 0x033A2
 * Original GAME.OVR file offset: 13226
 * Body addresses: 9
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_33a2(void)

{
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  return;
}


