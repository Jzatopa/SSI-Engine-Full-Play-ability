/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:b5f2
 * Ghidra name: FUN_0000_b5f2
 * Linear address: 0x0B5F2
 * Original GAME.OVR file offset: 46586
 * Body addresses: 71
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_b5f2(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 unaff_DS;
  
  uVar1 = 1;
  uVar2 = 1;
  FUN_0000_08c5();
  *(char *)0x74b9 = *(char *)0x74b9 + '\x01';
  FUN_0000_05c1(0x8a,uVar2,uVar1);
  FUN_0000_0945(0x56);
  FUN_0000_0a82();
  iVar3 = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
  uVar4 = (undefined1)((uint)iVar3 >> 8);
  FUN_0000_0e16(0x99,CONCAT11(uVar4,8),CONCAT11(uVar4,0xff),iVar3,
                *(char *)((int)*(undefined4 *)0x71dc + 2) + 3);
  return;
}


