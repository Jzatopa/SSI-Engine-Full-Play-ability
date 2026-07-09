/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0981
 * Ghidra name: FUN_0000_0981
 * Linear address: 0x00981
 * Original GAME.OVR file offset: 2441
 * Body addresses: 48
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0981(void)

{
  char cVar1;
  undefined2 unaff_DI;
  
  FUN_0000_453c(unaff_DI);
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


