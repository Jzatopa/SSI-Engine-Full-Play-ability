/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2d00
 * Ghidra name: FUN_0000_2d00
 * Linear address: 0x02D00
 * Original GAME.OVR file offset: 11528
 * Body addresses: 42
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_2d00(void)

{
  undefined2 unaff_DS;
  undefined2 uVar1;
  undefined2 uVar2;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  *(undefined1 *)0x443d = 0;
  uVar2 = *(undefined2 *)0x57fd;
  uVar1 = *(undefined2 *)0x57fb;
  FUN_0000_0b1a();
  FUN_0000_0a32(0xaf,uVar1,uVar2);
  *(undefined1 *)0x8c3d = 0;
  *(undefined1 *)0x8c32 = 1;
  return;
}


