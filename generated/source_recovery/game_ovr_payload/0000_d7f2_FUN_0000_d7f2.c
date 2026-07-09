/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:d7f2
 * Ghidra name: FUN_0000_d7f2
 * Linear address: 0x0D7F2
 * Original GAME.OVR file offset: 55290
 * Body addresses: 19
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_d7f2(void)

{
  uint in_AX;
  uint uVar1;
  
  uVar1 = in_AX & 0xff00;
  func_0x000009f6();
  FUN_0000_6e3e(0x99,uVar1);
  return;
}


