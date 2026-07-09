/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b02d
 * Ghidra name: FUN_2000_b02d
 * Linear address: 0x2B02D
 * Original GAME.OVR file offset: 176181
 * Body addresses: 52
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_b02d(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 unaff_DS;
  
  FUN_0000_0dee();
  func_0x0000109b(0xdb);
  iVar1 = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
  uVar2 = (undefined1)((uint)iVar1 >> 8);
  FUN_0000_0e16(0xec,CONCAT11(uVar2,8),CONCAT11(uVar2,0xff),iVar1,
                *(char *)((int)*(undefined4 *)0x71dc + 2) + 3);
  return;
}


