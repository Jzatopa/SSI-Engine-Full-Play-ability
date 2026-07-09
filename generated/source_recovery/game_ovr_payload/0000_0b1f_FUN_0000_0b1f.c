/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0b1f
 * Ghidra name: FUN_0000_0b1f
 * Linear address: 0x00B1F
 * Original GAME.OVR file offset: 2855
 * Body addresses: 13
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_0b1f(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = FUN_0000_06f8();
  *(undefined2 *)0x4432 = uVar1;
  return;
}


