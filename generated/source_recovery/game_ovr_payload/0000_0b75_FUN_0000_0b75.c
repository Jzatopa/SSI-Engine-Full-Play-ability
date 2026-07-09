/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0b75
 * Ghidra name: FUN_0000_0b75
 * Linear address: 0x00B75
 * Original GAME.OVR file offset: 2941
 * Body addresses: 23
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0b75(void)

{
  char in_CH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  bool in_SF;
  
  if (in_SF) {
    func_0x0000d6dc();
    return;
  }
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + in_CH;
  return;
}


