/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2f4c
 * Ghidra name: FUN_0000_2f4c
 * Linear address: 0x02F4C
 * Original GAME.OVR file offset: 12116
 * Body addresses: 52
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_2f4c(void)

{
  undefined2 uVar1;
  uint in_AX;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  uVar2 = in_AX & 0xff00;
  uVar3 = 1;
  FUN_0000_065a();
  uVar1 = *(undefined2 *)0x57fd;
  *(undefined2 *)0x536a = *(undefined2 *)0x57fb;
  *(undefined2 *)0x536c = uVar1;
  FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar3,uVar2);
  return;
}


