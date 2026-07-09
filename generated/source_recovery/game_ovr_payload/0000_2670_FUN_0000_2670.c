/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2670
 * Ghidra name: FUN_0000_2670
 * Linear address: 0x02670
 * Original GAME.OVR file offset: 9848
 * Body addresses: 20
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_2670(void)

{
  undefined2 unaff_SS;
  
  if (*(char *)0x57f1 != *(char *)0x57ad) {
    FUN_0000_2655();
    return;
  }
  return;
}


