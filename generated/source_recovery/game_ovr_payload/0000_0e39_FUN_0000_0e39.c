/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0e39
 * Ghidra name: FUN_0000_0e39
 * Linear address: 0x00E39
 * Original GAME.OVR file offset: 3649
 * Body addresses: 49
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_0e39(void)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool in_ZF;
  
  if ((in_ZF) && (in_AX == *(uint *)0x57fb)) {
    *(undefined1 *)0x3dde = 0;
  }
  uVar1 = in_AX & 0xff00;
  uVar2 = 1;
  FUN_0000_065a();
  FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar2,uVar1);
  *(undefined1 *)0x8c22 = 0;
  *(undefined1 *)0x8c23 = 0;
  return;
}


