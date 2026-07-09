/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:1e10
 * Ghidra name: FUN_0000_1e10
 * Linear address: 0x01E10
 * Original GAME.OVR file offset: 7704
 * Body addresses: 105
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_1e10(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  *(undefined1 *)0x3de2 = 0;
  *(undefined1 *)0x8c39 = 0;
  *(undefined1 *)0x7653 = 8;
  uVar5 = 0x72ba;
  uVar4 = 4;
  FUN_0000_e6d2(0);
  while (*(int *)0x72be != 0 || *(int *)0x72c0 != 0) {
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x72be >> 0x10);
    iVar2 = (int)*(undefined4 *)0x72be;
    uVar1 = *(undefined2 *)(iVar2 + 0x2a);
    uVar3 = *(undefined2 *)(iVar2 + 0x2c);
    FUN_0000_ce54(0xcc0,0x3e,*(undefined2 *)0x72be,*(undefined2 *)0x72c0,uVar4,uVar5);
    *(undefined2 *)0x72be = uVar1;
    *(undefined2 *)0x72c0 = uVar3;
  }
  return;
}


