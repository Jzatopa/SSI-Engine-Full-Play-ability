/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:3338
 * Ghidra name: FUN_0000_3338
 * Linear address: 0x03338
 * Original GAME.OVR file offset: 13120
 * Body addresses: 39
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_3338(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 unaff_DS;
  
  uVar1 = (uint)*(byte *)0x687a;
  uVar2 = (uint)*(byte *)0x687b;
  uVar3 = (uint)*(byte *)0x687c;
  uVar4 = (uint)*(byte *)0x687d;
  uVar5 = (uint)*(byte *)0x687e;
  func_0x00006e59();
  FUN_0000_073e(0x602,uVar5,uVar4,uVar3,uVar2,uVar1);
  func_0x00000a86(0x6b);
  return;
}


