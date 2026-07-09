/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:ceb6
 * Ghidra name: FUN_0000_ceb6
 * Linear address: 0x0CEB6
 * Original GAME.OVR file offset: 52926
 * Body addresses: 21
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_ceb6(void)

{
  uint in_AX;
  uint uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  uVar1 = in_AX & 0xff00;
  if (*(char *)(unaff_BP + -3) == '\0') {
    uVar1 = uVar1 + 1;
  }
  *(undefined1 *)(unaff_BP + -1) = (char)uVar1;
  return CONCAT11((char)(uVar1 >> 8),*(undefined1 *)(unaff_BP + -1));
}


