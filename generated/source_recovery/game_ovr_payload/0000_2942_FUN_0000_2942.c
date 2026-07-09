/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2942
 * Ghidra name: FUN_0000_2942
 * Linear address: 0x02942
 * Original GAME.OVR file offset: 10570
 * Body addresses: 14
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_2942(void)

{
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  FUN_0000_6e3e();
  return;
}


