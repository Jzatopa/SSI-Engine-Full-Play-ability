/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:1c44
 * Ghidra name: FUN_1000_1c44
 * Linear address: 0x11C44
 * Original GAME.OVR file offset: 72780
 * Body addresses: 75
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_1000_1c44(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x7511 == '\x02') {
    func_0x0000d6dc();
    return;
  }
  if (*(char *)0x7511 == '\x03') {
    func_0x0000d6dc();
    return;
  }
  func_0x0000d6dc();
  return;
}


