/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:016c
 * Ghidra name: FUN_0000_016c
 * Linear address: 0x0016C
 * Original GAME.OVR file offset: 372
 * Body addresses: 21
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - credits (anchor), previous candidate, distance 21 byte(s), source offset 393
 */

void __cdecl16far FUN_0000_016c(void)

{
  undefined2 unaff_DS;
  
  FUN_0000_b5b0();
  *(undefined1 *)0x4417 = 1;
  *(undefined1 *)0x50d2 = *(undefined1 *)0x3ddb;
  return;
}


