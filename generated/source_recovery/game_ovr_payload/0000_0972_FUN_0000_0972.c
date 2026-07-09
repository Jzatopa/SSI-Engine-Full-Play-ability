/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0972
 * Ghidra name: FUN_0000_0972
 * Linear address: 0x00972
 * Original GAME.OVR file offset: 2426
 * Body addresses: 13
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0972(void)

{
  char cVar1;
  int unaff_BP;
  
  FUN_0000_3721();
  FUN_0000_453c(unaff_BP + -4);
  cVar1 = FUN_0000_00d2(5);
  if (cVar1 != '\0') {
    FUN_0000_03ab(0x21a);
    FUN_0000_07e8(0x21a);
    FUN_0000_016c();
    FUN_0000_09b1();
    return;
  }
  FUN_0000_03ab(0x21a);
  FUN_0000_07e8(0x21a);
  FUN_0000_016c();
  FUN_0000_09b1();
  return;
}


