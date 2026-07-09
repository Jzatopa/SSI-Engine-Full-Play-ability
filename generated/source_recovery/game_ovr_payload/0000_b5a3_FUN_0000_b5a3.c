/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:b5a3
 * Ghidra name: FUN_0000_b5a3
 * Linear address: 0x0B5A3
 * Original GAME.OVR file offset: 46507
 * Body addresses: 13
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_b5a3(void)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uStack_7;
  undefined2 uStack_5;
  
  uStack_5 = *(int *)0x5801;
  uStack_7 = *(int *)0x57ff;
  while (uStack_7 != 0 || uStack_5 != 0) {
    if ((*(char *)(uStack_7 + 0xd4) == '\v') || (*(char *)(uStack_7 + 0xd4) == '\r')) {
      *(undefined1 *)(uStack_7 + 0xd4) = 1;
    }
    piVar1 = (int *)(uStack_7 + 0xff);
    uStack_5 = *(int *)(uStack_7 + 0x101);
    uStack_7 = *piVar1;
  }
  uVar5 = 1;
  uVar4 = 1;
  FUN_0000_08c5();
  *(char *)0x74b9 = *(char *)0x74b9 + '\x01';
  FUN_0000_05c1(0x8a,uVar4,uVar5);
  FUN_0000_0945(0x56);
  FUN_0000_0a82();
  iVar2 = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
  uVar3 = (undefined1)((uint)iVar2 >> 8);
  FUN_0000_0e16(0x99,CONCAT11(uVar3,8),CONCAT11(uVar3,0xff),iVar2,
                *(char *)((int)*(undefined4 *)0x71dc + 2) + 3);
  return;
}


