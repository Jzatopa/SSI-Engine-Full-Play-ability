/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:8334
 * Ghidra name: FUN_0000_8334
 * Linear address: 0x08334
 * Original GAME.OVR file offset: 33596
 * Body addresses: 11
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __cdecl16far FUN_0000_8334(void)

{
  undefined1 uVar1;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  uVar1 = in(in_DX);
  *unaff_DI = uVar1;
  return CONCAT11((char)((uint)(unaff_DI + in_BX + 1) >> 8),*(undefined1 *)(unaff_BP + -1));
}


