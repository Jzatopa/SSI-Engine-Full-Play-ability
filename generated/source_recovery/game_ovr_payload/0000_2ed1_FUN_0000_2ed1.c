/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2ed1
 * Ghidra name: FUN_0000_2ed1
 * Linear address: 0x02ED1
 * Original GAME.OVR file offset: 11993
 * Body addresses: 51
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_2ed1(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x8c3f = 0;
  if (*(char *)0x3dde != '\0') {
    uVar1 = *(undefined2 *)0x536c;
    *(undefined2 *)0x57fb = *(undefined2 *)0x536a;
    *(undefined2 *)0x57fd = uVar1;
    *(undefined1 *)0x3dde = 0;
  }
  func_0x000006da();
  return;
}


