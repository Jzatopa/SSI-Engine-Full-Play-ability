/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:90da
 * Ghidra name: FUN_2000_90da
 * Linear address: 0x290DA
 * Original GAME.OVR file offset: 168162
 * Body addresses: 56
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_90da(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x4438 == '\x05') {
    func_0x00001140();
  }
  else {
    func_0x00006e59();
  }
  return;
}


